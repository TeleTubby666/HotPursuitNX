#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4aac30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aac30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aac31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aac32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aac33  8b0dd4f74c00           -mov ecx, dword ptr [0x4cf7d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aac39  a1d8f74c00             -mov eax, dword ptr [0x4cf7d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */);
    // 004aac3e  3b05e4f74c00           +cmp eax, dword ptr [0x4cf7e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044196) /* 0x4cf7e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aac44  7304                   -jae 0x4aac4a
    if (!cpu.flags.cf)
    {
        goto L_0x004aac4a;
    }
L_0x004aac46:
    // 004aac46  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004aac48  eb21                   -jmp 0x4aac6b
    goto L_0x004aac6b;
L_0x004aac4a:
    // 004aac4a  8b1dd8f74c00           -mov ebx, dword ptr [0x4cf7d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */);
    // 004aac50  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aac52  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aac54  c1e302                 +shl ebx, 2
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
    // 004aac57  eb09                   -jmp 0x4aac62
    goto L_0x004aac62;
L_0x004aac59:
    // 004aac59  833c0200               +cmp dword ptr [edx + eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aac5d  74e7                   -je 0x4aac46
    if (cpu.flags.zf)
    {
        goto L_0x004aac46;
    }
    // 004aac5f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004aac62:
    // 004aac62  39d8                   +cmp eax, ebx
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
    // 004aac64  7cf3                   -jl 0x4aac59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aac59;
    }
    // 004aac66  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004aac6b:
    // 004aac6b  890dd4f74c00           -mov dword ptr [0x4cf7d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */) = cpu.ecx;
    // 004aac71  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac73  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aac75(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aac75  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aac76  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aac77  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aac78  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aac79  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aac7b  ff15bce34c00           -call dword ptr [0x4ce3bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039036) /* 0x4ce3bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aac81  8b0dd8f74c00           -mov ecx, dword ptr [0x4cf7d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */);
    // 004aac87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aac89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aac8b  c1e102                 +shl ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004aac8e  eb20                   -jmp 0x4aacb0
    goto L_0x004aacb0;
L_0x004aac90:
    // 004aac90  8b15d4f74c00           -mov edx, dword ptr [0x4cf7d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aac96  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aac98  833a00                 +cmp dword ptr [edx], 0
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
    // 004aac9b  750f                   -jne 0x4aacac
    if (!cpu.flags.zf)
    {
        goto L_0x004aacac;
    }
    // 004aac9d  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004aac9f  ff15c0e34c00           -call dword ptr [0x4ce3c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039040) /* 0x4ce3c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aaca5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aaca7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaca8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaca9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aacaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aacab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aacac:
    // 004aacac  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aacaf  43                     -inc ebx
    (cpu.ebx)++;
L_0x004aacb0:
    // 004aacb0  39c8                   +cmp eax, ecx
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
    // 004aacb2  7cdc                   -jl 0x4aac90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aac90;
    }
    // 004aacb4  8b15d8f74c00           -mov edx, dword ptr [0x4cf7d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */);
    // 004aacba  42                     -inc edx
    (cpu.edx)++;
    // 004aacbb  a1d4f74c00             -mov eax, dword ptr [0x4cf7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aacc0  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004aacc3  e8ec660000             -call 0x4b13b4
    cpu.esp -= 4;
    sub_4b13b4(app, cpu);
    if (cpu.terminate) return;
    // 004aacc8  8b15d8f74c00           -mov edx, dword ptr [0x4cf7d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */);
    // 004aacce  a3d4f74c00             -mov dword ptr [0x4cf7d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */) = cpu.eax;
    // 004aacd3  893490                 -mov dword ptr [eax + edx*4], esi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 004aacd6  42                     -inc edx
    (cpu.edx)++;
    // 004aacd7  8915d8f74c00           -mov dword ptr [0x4cf7d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */) = cpu.edx;
    // 004aacdd  ff15c0e34c00           -call dword ptr [0x4ce3c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039040) /* 0x4ce3c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aace3  a1d8f74c00             -mov eax, dword ptr [0x4cf7d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */);
    // 004aace8  48                     -dec eax
    (cpu.eax)--;
    // 004aace9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aacea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaceb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aacec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaced  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aacee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aacee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aacef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aacf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aacf1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aacf2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004aacf4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004aacf6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aacf8  0f8c90000000           -jl 0x4aad8e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aad8e;
    }
    // 004aacfe  ff15bce34c00           -call dword ptr [0x4ce3bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039036) /* 0x4ce3bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aad04  83fa01                 +cmp edx, 1
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
    // 004aad07  7209                   -jb 0x4aad12
    if (cpu.flags.cf)
    {
        goto L_0x004aad12;
    }
    // 004aad09  7610                   -jbe 0x4aad1b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aad1b;
    }
    // 004aad0b  83fa02                 +cmp edx, 2
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
    // 004aad0e  7410                   -je 0x4aad20
    if (cpu.flags.zf)
    {
        goto L_0x004aad20;
    }
    // 004aad10  eb18                   -jmp 0x4aad2a
    goto L_0x004aad2a;
L_0x004aad12:
    // 004aad12  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aad14  7514                   -jne 0x4aad2a
    if (!cpu.flags.zf)
    {
        goto L_0x004aad2a;
    }
    // 004aad16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aad17  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 004aad19  eb08                   -jmp 0x4aad23
    goto L_0x004aad23;
L_0x004aad1b:
    // 004aad1b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aad1c  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 004aad1e  eb03                   -jmp 0x4aad23
    goto L_0x004aad23;
L_0x004aad20:
    // 004aad20  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aad21  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x004aad23:
    // 004aad23  2eff1594754b00         -call dword ptr cs:[0x4b7594]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945300) /* 0x4b7594 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004aad2a:
    // 004aad2a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004aad2c  8b15d8f74c00           -mov edx, dword ptr [0x4cf7d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */);
    // 004aad32  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004aad35  39d6                   +cmp esi, edx
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
    // 004aad37  7d0a                   -jge 0x4aad43
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aad43;
    }
    // 004aad39  a1d4f74c00             -mov eax, dword ptr [0x4cf7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aad3e  893c01                 -mov dword ptr [ecx + eax], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.edi;
    // 004aad41  eb45                   -jmp 0x4aad88
    goto L_0x004aad88;
L_0x004aad43:
    // 004aad43  a1d4f74c00             -mov eax, dword ptr [0x4cf7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aad48  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004aad4b  e864660000             -call 0x4b13b4
    cpu.esp -= 4;
    sub_4b13b4(app, cpu);
    if (cpu.terminate) return;
    // 004aad50  8b1dd8f74c00           -mov ebx, dword ptr [0x4cf7d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */);
    // 004aad56  a3d4f74c00             -mov dword ptr [0x4cf7d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */) = cpu.eax;
    // 004aad5b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aad5d  c1e002                 +shl eax, 2
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
    // 004aad60  eb11                   -jmp 0x4aad73
    goto L_0x004aad73;
L_0x004aad62:
    // 004aad62  8b15d4f74c00           -mov edx, dword ptr [0x4cf7d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aad68  43                     -inc ebx
    (cpu.ebx)++;
    // 004aad69  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004aad70  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004aad73:
    // 004aad73  39c8                   +cmp eax, ecx
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
    // 004aad75  7ceb                   -jl 0x4aad62
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aad62;
    }
    // 004aad77  a1d4f74c00             -mov eax, dword ptr [0x4cf7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aad7c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004aad7e  46                     -inc esi
    (cpu.esi)++;
    // 004aad7f  893c90                 -mov dword ptr [eax + edx*4], edi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.edi;
    // 004aad82  8935d8f74c00           -mov dword ptr [0x4cf7d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */) = cpu.esi;
L_0x004aad88:
    // 004aad88  ff15c0e34c00           -call dword ptr [0x4ce3c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039040) /* 0x4ce3c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004aad8e:
    // 004aad8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aad8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aad90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aad91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aad92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aad93(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aad93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aad94  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aad96  ff15bce34c00           -call dword ptr [0x4ce3bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039036) /* 0x4ce3bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aad9c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aad9e  7e17                   -jle 0x4aadb7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aadb7;
    }
    // 004aada0  3b15d8f74c00           +cmp edx, dword ptr [0x4cf7d8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044184) /* 0x4cf7d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aada6  7d0f                   -jge 0x4aadb7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aadb7;
    }
    // 004aada8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aadaa  8b15d4f74c00           -mov edx, dword ptr [0x4cf7d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aadb0  c7048200000000         -mov dword ptr [edx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = 0 /*0x0*/;
L_0x004aadb7:
    // 004aadb7  ff15c0e34c00           -call dword ptr [0x4ce3c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039040) /* 0x4ce3c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aadbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aadbe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aadbf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aadbf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aadc0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aadc1  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 004aadc3  2eff1514754b00         -call dword ptr cs:[0x4b7514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945172) /* 0x4b7514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aadca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aadcc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aadce  7405                   -je 0x4aadd5
    if (cpu.flags.zf)
    {
        goto L_0x004aadd5;
    }
    // 004aadd0  83f8ff                 +cmp eax, -1
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
    // 004aadd3  7505                   -jne 0x4aadda
    if (!cpu.flags.zf)
    {
        goto L_0x004aadda;
    }
L_0x004aadd5:
    // 004aadd5  e844000000             -call 0x4aae1e
    cpu.esp -= 4;
    sub_4aae1e(app, cpu);
    if (cpu.terminate) return;
L_0x004aadda:
    // 004aadda  e896feffff             -call 0x4aac75
    cpu.esp -= 4;
    sub_4aac75(app, cpu);
    if (cpu.terminate) return;
    // 004aaddf  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 004aade1  2eff1514754b00         -call dword ptr cs:[0x4b7514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945172) /* 0x4b7514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aade8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aadea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aadec  7405                   -je 0x4aadf3
    if (cpu.flags.zf)
    {
        goto L_0x004aadf3;
    }
    // 004aadee  83f8ff                 +cmp eax, -1
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
    // 004aadf1  7505                   -jne 0x4aadf8
    if (!cpu.flags.zf)
    {
        goto L_0x004aadf8;
    }
L_0x004aadf3:
    // 004aadf3  e826000000             -call 0x4aae1e
    cpu.esp -= 4;
    sub_4aae1e(app, cpu);
    if (cpu.terminate) return;
L_0x004aadf8:
    // 004aadf8  e878feffff             -call 0x4aac75
    cpu.esp -= 4;
    sub_4aac75(app, cpu);
    if (cpu.terminate) return;
    // 004aadfd  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 004aadff  2eff1514754b00         -call dword ptr cs:[0x4b7514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945172) /* 0x4b7514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aae06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aae08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aae0a  7405                   -je 0x4aae11
    if (cpu.flags.zf)
    {
        goto L_0x004aae11;
    }
    // 004aae0c  83f8ff                 +cmp eax, -1
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
    // 004aae0f  7505                   -jne 0x4aae16
    if (!cpu.flags.zf)
    {
        goto L_0x004aae16;
    }
L_0x004aae11:
    // 004aae11  e808000000             -call 0x4aae1e
    cpu.esp -= 4;
    sub_4aae1e(app, cpu);
    if (cpu.terminate) return;
L_0x004aae16:
    // 004aae16  e85afeffff             -call 0x4aac75
    cpu.esp -= 4;
    sub_4aac75(app, cpu);
    if (cpu.terminate) return;
    // 004aae1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aae1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aae1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aae1e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aae1e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aae1f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aae20  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004aae22  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004aae24  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004aae26  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004aae28  2eff1554744b00         -call dword ptr cs:[0x4b7454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944980) /* 0x4b7454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aae2f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aae31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aae33  750d                   -jne 0x4aae42
    if (!cpu.flags.zf)
    {
        goto L_0x004aae42;
    }
    // 004aae35  8b15dcf74c00           -mov edx, dword ptr [0x4cf7dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044188) /* 0x4cf7dc */);
    // 004aae3b  42                     -inc edx
    (cpu.edx)++;
    // 004aae3c  8915dcf74c00           -mov dword ptr [0x4cf7dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5044188) /* 0x4cf7dc */) = cpu.edx;
L_0x004aae42:
    // 004aae42  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aae44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aae45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aae46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aae47(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aae47  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004aae49  740e                   -je 0x4aae59
    if (cpu.flags.zf)
    {
        goto L_0x004aae59;
    }
    // 004aae4b  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 004aae51  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 004aae57  eb0c                   -jmp 0x4aae65
    goto L_0x004aae65;
L_0x004aae59:
    // 004aae59  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 004aae5f  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
L_0x004aae65:
    // 004aae65  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004aae67  7403                   -je 0x4aae6c
    if (cpu.flags.zf)
    {
        goto L_0x004aae6c;
    }
    // 004aae69  800b02                 -or byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004aae6c:
    // 004aae6c  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004aae6e  7403                   -je 0x4aae73
    if (cpu.flags.zf)
    {
        goto L_0x004aae73;
    }
    // 004aae70  800b04                 -or byte ptr [ebx], 4
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004aae73:
    // 004aae73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aae74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aae74  83f802                 +cmp eax, 2
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
    // 004aae77  750d                   -jne 0x4aae86
    if (!cpu.flags.zf)
    {
        goto L_0x004aae86;
    }
    // 004aae79  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
L_0x004aae7f:
    // 004aae7f  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 004aae85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aae86:
    // 004aae86  83f801                 +cmp eax, 1
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
    // 004aae89  7508                   -jne 0x4aae93
    if (!cpu.flags.zf)
    {
        goto L_0x004aae93;
    }
    // 004aae8b  c70200000040           -mov dword ptr [edx], 0x40000000
    app->getMemory<x86::reg32>(cpu.edx) = 1073741824 /*0x40000000*/;
    // 004aae91  ebec                   -jmp 0x4aae7f
    goto L_0x004aae7f;
L_0x004aae93:
    // 004aae93  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 004aae99  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 004aae9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aaea1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aaea3  83e070                 -and eax, 0x70
    cpu.eax &= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004aaea6  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004aaea9  83f820                 +cmp eax, 0x20
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
    // 004aaeac  7210                   -jb 0x4aaebe
    if (cpu.flags.cf)
    {
        goto L_0x004aaebe;
    }
    // 004aaeae  7638                   -jbe 0x4aaee8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aaee8;
    }
    // 004aaeb0  83f830                 +cmp eax, 0x30
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaeb3  7241                   -jb 0x4aaef6
    if (cpu.flags.cf)
    {
        goto L_0x004aaef6;
    }
    // 004aaeb5  7629                   -jbe 0x4aaee0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aaee0;
    }
    // 004aaeb7  83f840                 +cmp eax, 0x40
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
    // 004aaeba  7434                   -je 0x4aaef0
    if (cpu.flags.zf)
    {
        goto L_0x004aaef0;
    }
    // 004aaebc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaebd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaebe:
    // 004aaebe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aaec0  7607                   -jbe 0x4aaec9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aaec9;
    }
    // 004aaec2  83f810                 +cmp eax, 0x10
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
    // 004aaec5  7411                   -je 0x4aaed8
    if (cpu.flags.zf)
    {
        goto L_0x004aaed8;
    }
    // 004aaec7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaec8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaec9:
    // 004aaec9  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 004aaecf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aaed1  7523                   -jne 0x4aaef6
    if (!cpu.flags.zf)
    {
        goto L_0x004aaef6;
    }
    // 004aaed3  800a02                 -or byte ptr [edx], 2
    app->getMemory<x86::reg8>(cpu.edx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004aaed6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaed7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaed8:
    // 004aaed8  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004aaede  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaedf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaee0:
    // 004aaee0  c70202000000           -mov dword ptr [edx], 2
    app->getMemory<x86::reg32>(cpu.edx) = 2 /*0x2*/;
    // 004aaee6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaee7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaee8:
    // 004aaee8  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 004aaeee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaeef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaef0:
    // 004aaef0  c70203000000           -mov dword ptr [edx], 3
    app->getMemory<x86::reg32>(cpu.edx) = 3 /*0x3*/;
L_0x004aaef6:
    // 004aaef6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaef7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaef8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaef8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aaef9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aaefa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aaefb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aaefd  3b05e4f74c00           +cmp eax, dword ptr [0x4cf7e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044196) /* 0x4cf7e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaf03  7206                   -jb 0x4aaf0b
    if (cpu.flags.cf)
    {
        goto L_0x004aaf0b;
    }
    // 004aaf05  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aaf07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaf0b:
    // 004aaf0b  83f803                 +cmp eax, 3
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
    // 004aaf0e  7d31                   -jge 0x4aaf41
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aaf41;
    }
    // 004aaf10  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aaf12  a138f84c00             -mov eax, dword ptr [0x4cf838]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044280) /* 0x4cf838 */);
    // 004aaf17  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004aaf1a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaf1c  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004aaf1f  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 004aaf22  751d                   -jne 0x4aaf41
    if (!cpu.flags.zf)
    {
        goto L_0x004aaf41;
    }
    // 004aaf24  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 004aaf26  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004aaf29  886801                 -mov byte ptr [eax + 1], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 004aaf2c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aaf2e  e83b000000             -call 0x4aaf6e
    cpu.esp -= 4;
    sub_4aaf6e(app, cpu);
    if (cpu.terminate) return;
    // 004aaf33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aaf35  740a                   -je 0x4aaf41
    if (cpu.flags.zf)
    {
        goto L_0x004aaf41;
    }
    // 004aaf37  a138f84c00             -mov eax, dword ptr [0x4cf838]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044280) /* 0x4cf838 */);
    // 004aaf3c  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004aaf41:
    // 004aaf41  a138f84c00             -mov eax, dword ptr [0x4cf838]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044280) /* 0x4cf838 */);
    // 004aaf46  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004aaf49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaf4d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaf4d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aaf4e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aaf51  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aaf53  740e                   -je 0x4aaf63
    if (cpu.flags.zf)
    {
        goto L_0x004aaf63;
    }
    // 004aaf55  8b1d38f84c00           -mov ebx, dword ptr [0x4cf838]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5044280) /* 0x4cf838 */);
    // 004aaf5b  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004aaf5e  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 004aaf61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaf63:
    // 004aaf63  8b1d38f84c00           -mov ebx, dword ptr [0x4cf838]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5044280) /* 0x4cf838 */);
    // 004aaf69  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 004aaf6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaf6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaf6e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aaf6f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aaf70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aaf71  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aaf73  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aaf79  833dd4e34c0000         +cmp dword ptr [0x4ce3d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5039060) /* 0x4ce3d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaf80  741d                   -je 0x4aaf9f
    if (cpu.flags.zf)
    {
        goto L_0x004aaf9f;
    }
    // 004aaf82  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aaf84  ff15d4e34c00           -call dword ptr [0x4ce3d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039060) /* 0x4ce3d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aaf8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aaf8c  7411                   -je 0x4aaf9f
    if (cpu.flags.zf)
    {
        goto L_0x004aaf9f;
    }
L_0x004aaf8e:
    // 004aaf8e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aaf90  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aaf96  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004aaf9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaf9f:
    // 004aaf9f  a1d4f74c00             -mov eax, dword ptr [0x4cf7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aafa4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aafa6  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004aafa9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004aafaa  2eff15e4744b00         -call dword ptr cs:[0x4b74e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945124) /* 0x4b74e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aafb1  83f802                 +cmp eax, 2
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
    // 004aafb4  74d8                   -je 0x4aaf8e
    if (cpu.flags.zf)
    {
        goto L_0x004aaf8e;
    }
    // 004aafb6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aafb8  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aafbe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aafc0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aafc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aafc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aafc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aafc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aafc4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aafc5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aafc6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aafc7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aafc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aafcb  7c08                   -jl 0x4aafd5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aafd5;
    }
    // 004aafcd  3b05e4f74c00           +cmp eax, dword ptr [0x4cf7e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044196) /* 0x4cf7e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aafd3  7613                   -jbe 0x4aafe8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aafe8;
    }
L_0x004aafd5:
    // 004aafd5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004aafda  e821f1feff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 004aafdf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004aafe4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aafe5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aafe6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aafe7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aafe8:
    // 004aafe8  8b15d4f74c00           -mov edx, dword ptr [0x4cf7d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004aafee  8b1482                 -mov edx, dword ptr [edx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004aaff1  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aaff7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004aaff9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004aaffb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004aaffd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aaffe  2eff158c754b00         -call dword ptr cs:[0x4b758c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945292) /* 0x4b758c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab005  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab007  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab009  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab00f  83faff                 +cmp edx, -1
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
    // 004ab012  7505                   -jne 0x4ab019
    if (!cpu.flags.zf)
    {
        goto L_0x004ab019;
    }
    // 004ab014  e8e9effeff             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
L_0x004ab019:
    // 004ab019  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab01b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab01c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab01d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab01e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab01f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab01f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab022  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab023  8b15c48d5400           -mov edx, dword ptr [0x548dc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5541316) /* 0x548dc4 */);
    // 004ab029  83fa40                 +cmp edx, 0x40
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
    // 004ab02c  7d1c                   -jge 0x4ab04a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ab04a;
    }
    // 004ab02e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab030  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ab033  bbc88d5400             -mov ebx, 0x548dc8
    cpu.ebx = 5541320 /*0x548dc8*/;
    // 004ab038  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab03a  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004ab03d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004ab040  890dc48d5400           -mov dword ptr [0x548dc4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5541316) /* 0x548dc4 */) = cpu.ecx;
    // 004ab046  01c3                   +add ebx, eax
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
    // 004ab048  eb24                   -jmp 0x4ab06e
    goto L_0x004ab06e;
L_0x004ab04a:
    // 004ab04a  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004ab04f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ab054  e8d5630000             -call 0x4b142e
    cpu.esp -= 4;
    sub_4b142e(app, cpu);
    if (cpu.terminate) return;
    // 004ab059  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab05b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab05d  750f                   -jne 0x4ab06e
    if (!cpu.flags.zf)
    {
        goto L_0x004ab06e;
    }
    // 004ab05f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ab064  b878174c00             -mov eax, 0x4c1778
    cpu.eax = 4986744 /*0x4c1778*/;
    // 004ab069  e8830f0000             -call 0x4abff1
    cpu.esp -= 4;
    sub_4abff1(app, cpu);
    if (cpu.terminate) return;
L_0x004ab06e:
    // 004ab06e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab070  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab071  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab072  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab073  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab074(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab074  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab075  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab076  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab077  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab079  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004ab07d  740a                   -je 0x4ab089
    if (cpu.flags.zf)
    {
        goto L_0x004ab089;
    }
    // 004ab07f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab082  2eff156c744b00         -call dword ptr cs:[0x4b746c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945004) /* 0x4b746c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ab089:
    // 004ab089  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ab090  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004ab097  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004ab09e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab09f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab0a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab0a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab0a2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0a2  b8648c5400             -mov eax, 0x548c64
    cpu.eax = 5540964 /*0x548c64*/;
    // 004ab0a7  e97d000000             -jmp 0x4ab129
    return sub_4ab129(app, cpu);
}

/* align: skip  */
void Application::sub_4ab0ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0ac  b8648c5400             -mov eax, 0x548c64
    cpu.eax = 5540964 /*0x548c64*/;
    // 004ab0b1  e9d9000000             -jmp 0x4ab18f
    return sub_4ab18f(app, cpu);
}

/* align: skip  */
void Application::sub_4ab0b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0b6  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004ab0b9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004ab0bc  05848c5400             +add eax, 0x548c84
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5540996 /*0x548c84*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab0c1  eb66                   -jmp 0x4ab129
    return sub_4ab129(app, cpu);
}

/* align: skip  */
void Application::sub_4ab0c3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0c3  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004ab0c6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004ab0c9  05848c5400             +add eax, 0x548c84
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5540996 /*0x548c84*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab0ce  e9bc000000             -jmp 0x4ab18f
    return sub_4ab18f(app, cpu);
}

/* align: skip  */
void Application::sub_4ab0d3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0d3  e99dfbffff             -jmp 0x4aac75
    return sub_4aac75(app, cpu);
}

/* align: skip  */
void Application::sub_4ab0d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab0d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab0db  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004ab0de  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004ab0e1  05848c5400             -add eax, 0x548c84
    (cpu.eax) += x86::reg32(x86::sreg32(5540996 /*0x548c84*/));
    // 004ab0e6  e889ffffff             -call 0x4ab074
    cpu.esp -= 4;
    sub_4ab074(app, cpu);
    if (cpu.terminate) return;
    // 004ab0eb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab0ed  e8a1fcffff             -call 0x4aad93
    cpu.esp -= 4;
    sub_4aad93(app, cpu);
    if (cpu.terminate) return;
    // 004ab0f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab0f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab0f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0f4  b8848d5400             -mov eax, 0x548d84
    cpu.eax = 5541252 /*0x548d84*/;
    // 004ab0f9  eb2e                   -jmp 0x4ab129
    return sub_4ab129(app, cpu);
}

/* align: skip  */
void Application::sub_4ab0fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0fb  b8848d5400             -mov eax, 0x548d84
    cpu.eax = 5541252 /*0x548d84*/;
    // 004ab100  e98a000000             -jmp 0x4ab18f
    return sub_4ab18f(app, cpu);
}

/* align: skip  */
void Application::sub_4ab105(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab105  b8748c5400             -mov eax, 0x548c74
    cpu.eax = 5540980 /*0x548c74*/;
    // 004ab10a  eb1d                   -jmp 0x4ab129
    return sub_4ab129(app, cpu);
}

/* align: skip  */
void Application::sub_4ab10c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab10c  b8748c5400             -mov eax, 0x548c74
    cpu.eax = 5540980 /*0x548c74*/;
    // 004ab111  e979000000             -jmp 0x4ab18f
    return sub_4ab18f(app, cpu);
}

/* align: skip  */
void Application::sub_4ab116(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab116  b8a48d5400             -mov eax, 0x548da4
    cpu.eax = 5541284 /*0x548da4*/;
    // 004ab11b  eb0c                   -jmp 0x4ab129
    return sub_4ab129(app, cpu);
}

/* align: skip  */
void Application::sub_4ab11d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab11d  b8a48d5400             -mov eax, 0x548da4
    cpu.eax = 5541284 /*0x548da4*/;
    // 004ab122  eb6b                   -jmp 0x4ab18f
    return sub_4ab18f(app, cpu);
}

/* align: skip  */
void Application::sub_4ab124(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab124  b8b48d5400             -mov eax, 0x548db4
    cpu.eax = 5541300 /*0x548db4*/;
    // 004ab129  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab12a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab12b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab12c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab12d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab12f  2eff15c8744b00         -call dword ptr cs:[0x4b74c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945096) /* 0x4b74c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab136  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ab139  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab13b  39d0                   +cmp eax, edx
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
    // 004ab13d  7443                   -je 0x4ab182
    if (cpu.flags.zf)
    {
        goto L_0x004ab182;
    }
    // 004ab13f  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab143  7530                   -jne 0x4ab175
    if (!cpu.flags.zf)
    {
        goto L_0x004ab175;
    }
    // 004ab145  b8948d5400             -mov eax, 0x548d94
    cpu.eax = 5541268 /*0x548d94*/;
    // 004ab14a  e8daffffff             -call 0x4ab129
    cpu.esp -= 4;
    sub_4ab129(app, cpu);
    if (cpu.terminate) return;
    // 004ab14f  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab153  7516                   -jne 0x4ab16b
    if (!cpu.flags.zf)
    {
        goto L_0x004ab16b;
    }
    // 004ab155  e8c6feffff             -call 0x4ab020
    cpu.esp -= 4;
    sub_4ab020(app, cpu);
    if (cpu.terminate) return;
    // 004ab15a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab15b  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ab15d  2eff1538754b00         -call dword ptr cs:[0x4b7538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945208) /* 0x4b7538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab164  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x004ab16b:
    // 004ab16b  b8948d5400             -mov eax, 0x548d94
    cpu.eax = 5541268 /*0x548d94*/;
    // 004ab170  e81a000000             -call 0x4ab18f
    cpu.esp -= 4;
    sub_4ab18f(app, cpu);
    if (cpu.terminate) return;
L_0x004ab175:
    // 004ab175  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ab177  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab178  2eff1578744b00         -call dword ptr cs:[0x4b7478]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945016) /* 0x4b7478 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab17f  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004ab182:
    // 004ab182  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 004ab185  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab186  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab187  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab188  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab189  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab129(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ab129;
    // 004ab124  b8b48d5400             -mov eax, 0x548db4
    cpu.eax = 5541300 /*0x548db4*/;
L_entry_0x004ab129:
    // 004ab129  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab12a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab12b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab12c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab12d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab12f  2eff15c8744b00         -call dword ptr cs:[0x4b74c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945096) /* 0x4b74c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab136  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ab139  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab13b  39d0                   +cmp eax, edx
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
    // 004ab13d  7443                   -je 0x4ab182
    if (cpu.flags.zf)
    {
        goto L_0x004ab182;
    }
    // 004ab13f  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab143  7530                   -jne 0x4ab175
    if (!cpu.flags.zf)
    {
        goto L_0x004ab175;
    }
    // 004ab145  b8948d5400             -mov eax, 0x548d94
    cpu.eax = 5541268 /*0x548d94*/;
    // 004ab14a  e8daffffff             -call 0x4ab129
    cpu.esp -= 4;
    sub_4ab129(app, cpu);
    if (cpu.terminate) return;
    // 004ab14f  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab153  7516                   -jne 0x4ab16b
    if (!cpu.flags.zf)
    {
        goto L_0x004ab16b;
    }
    // 004ab155  e8c6feffff             -call 0x4ab020
    cpu.esp -= 4;
    sub_4ab020(app, cpu);
    if (cpu.terminate) return;
    // 004ab15a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab15b  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ab15d  2eff1538754b00         -call dword ptr cs:[0x4b7538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945208) /* 0x4b7538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab164  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x004ab16b:
    // 004ab16b  b8948d5400             -mov eax, 0x548d94
    cpu.eax = 5541268 /*0x548d94*/;
    // 004ab170  e81a000000             -call 0x4ab18f
    cpu.esp -= 4;
    sub_4ab18f(app, cpu);
    if (cpu.terminate) return;
L_0x004ab175:
    // 004ab175  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ab177  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab178  2eff1578744b00         -call dword ptr cs:[0x4b7478]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945016) /* 0x4b7478 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab17f  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004ab182:
    // 004ab182  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 004ab185  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab186  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab187  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab188  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab189  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab18a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab18a  b8b48d5400             -mov eax, 0x548db4
    cpu.eax = 5541300 /*0x548db4*/;
    // 004ab18f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab190  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab191  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab192  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab193  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ab196  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ab198  7617                   -jbe 0x4ab1b1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab1b1;
    }
    // 004ab19a  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004ab19d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004ab1a0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab1a2  750d                   -jne 0x4ab1b1
    if (!cpu.flags.zf)
    {
        goto L_0x004ab1b1;
    }
    // 004ab1a4  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab1a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab1a7  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004ab1aa  2eff153c754b00         -call dword ptr cs:[0x4b753c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945212) /* 0x4b753c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ab1b1:
    // 004ab1b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab18f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ab18f;
    // 004ab18a  b8b48d5400             -mov eax, 0x548db4
    cpu.eax = 5541300 /*0x548db4*/;
L_entry_0x004ab18f:
    // 004ab18f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab190  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab191  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab192  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab193  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ab196  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ab198  7617                   -jbe 0x4ab1b1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab1b1;
    }
    // 004ab19a  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004ab19d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004ab1a0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab1a2  750d                   -jne 0x4ab1b1
    if (!cpu.flags.zf)
    {
        goto L_0x004ab1b1;
    }
    // 004ab1a4  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab1a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab1a7  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004ab1aa  2eff153c754b00         -call dword ptr cs:[0x4b753c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945212) /* 0x4b753c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ab1b1:
    // 004ab1b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab1b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab1b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab1b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab1b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab1b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab1ba  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab1c1  8b1584e34c00           -mov edx, dword ptr [0x4ce384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab1c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab1c8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab1ca  2eff15b0754b00         -call dword ptr cs:[0x4b75b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945328) /* 0x4b75b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab1d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab1d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab1d5  7507                   -jne 0x4ab1de
    if (!cpu.flags.zf)
    {
        goto L_0x004ab1de;
    }
    // 004ab1d7  e86a620000             -call 0x4b1446
    cpu.esp -= 4;
    sub_4b1446(app, cpu);
    if (cpu.terminate) return;
    // 004ab1dc  eb0b                   -jmp 0x4ab1e9
    goto L_0x004ab1e9;
L_0x004ab1de:
    // 004ab1de  80785300               +cmp byte ptr [eax + 0x53], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(83) /* 0x53 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab1e2  7407                   -je 0x4ab1eb
    if (cpu.flags.zf)
    {
        goto L_0x004ab1eb;
    }
    // 004ab1e4  e896620000             -call 0x4b147f
    cpu.esp -= 4;
    sub_4b147f(app, cpu);
    if (cpu.terminate) return;
L_0x004ab1e9:
    // 004ab1e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004ab1eb:
    // 004ab1eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab1ec  2eff1590754b00         -call dword ptr cs:[0x4b7590]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945296) /* 0x4b7590 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab1f3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab1f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab1fa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab1fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab1fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab1fc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab1fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab200  7526                   -jne 0x4ab228
    if (!cpu.flags.zf)
    {
        goto L_0x004ab228;
    }
    // 004ab202  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ab207  8b156cf84c00           -mov edx, dword ptr [0x4cf86c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044332) /* 0x4cf86c */);
    // 004ab20d  e81c620000             -call 0x4b142e
    cpu.esp -= 4;
    sub_4b142e(app, cpu);
    if (cpu.terminate) return;
    // 004ab212  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab214  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab216  7410                   -je 0x4ab228
    if (cpu.flags.zf)
    {
        goto L_0x004ab228;
    }
    // 004ab218  8b1d6cf84c00           -mov ebx, dword ptr [0x4cf86c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5044332) /* 0x4cf86c */);
    // 004ab21e  c6405201               -mov byte ptr [eax + 0x52], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 004ab222  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x004ab228:
    // 004ab228  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab22a  e81b640000             -call 0x4b164a
    cpu.esp -= 4;
    sub_4b164a(app, cpu);
    if (cpu.terminate) return;
    // 004ab22f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab231  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab232  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab233  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab234  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab235  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab236  2eff15a8754b00         -call dword ptr cs:[0x4b75a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945320) /* 0x4b75a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab23d  668b1549ce4c00         -mov dx, word ptr [0x4cce49]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5033545) /* 0x4cce49 */);
    // 004ab244  a384e34c00             -mov dword ptr [0x4ce384], eax
    app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */) = cpu.eax;
    // 004ab249  6681fa0080             +cmp dx, 0x8000
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ab24e  7227                   -jb 0x4ab277
    if (cpu.flags.cf)
    {
        goto L_0x004ab277;
    }
    // 004ab250  803d47ce4c0004         +cmp byte ptr [0x4cce47], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033543) /* 0x4cce47 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab257  731e                   -jae 0x4ab277
    if (!cpu.flags.cf)
    {
        goto L_0x004ab277;
    }
L_0x004ab259:
    // 004ab259  8b1584e34c00           -mov edx, dword ptr [0x4ce384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab25f  83faff                 +cmp edx, -1
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
    // 004ab262  7413                   -je 0x4ab277
    if (cpu.flags.zf)
    {
        goto L_0x004ab277;
    }
    // 004ab264  83fa02                 +cmp edx, 2
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
    // 004ab267  770e                   -ja 0x4ab277
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab277;
    }
    // 004ab269  2eff15a8754b00         -call dword ptr cs:[0x4b75a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945320) /* 0x4b75a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab270  a384e34c00             -mov dword ptr [0x4ce384], eax
    app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */) = cpu.eax;
    // 004ab275  ebe2                   -jmp 0x4ab259
    goto L_0x004ab259;
L_0x004ab277:
    // 004ab277  833d84e34c00ff         +cmp dword ptr [0x4ce384], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab27e  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004ab281  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab286  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab287  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab288  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab289(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab289  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab28a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab28b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab28c  833d84e34c00ff         +cmp dword ptr [0x4ce384], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab293  7506                   -jne 0x4ab29b
    if (!cpu.flags.zf)
    {
        goto L_0x004ab29b;
    }
L_0x004ab295:
    // 004ab295  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab297  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab298  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab299  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab29a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab29b:
    // 004ab29b  e85affffff             -call 0x4ab1fa
    cpu.esp -= 4;
    sub_4ab1fa(app, cpu);
    if (cpu.terminate) return;
    // 004ab2a0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab2a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab2a4  742e                   -je 0x4ab2d4
    if (cpu.flags.zf)
    {
        goto L_0x004ab2d4;
    }
    // 004ab2a6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab2a8  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004ab2ae  e8a0620000             -call 0x4b1553
    cpu.esp -= 4;
    sub_4b1553(app, cpu);
    if (cpu.terminate) return;
    // 004ab2b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab2b5  7509                   -jne 0x4ab2c0
    if (!cpu.flags.zf)
    {
        goto L_0x004ab2c0;
    }
    // 004ab2b7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab2b9  e8eb3dffff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004ab2be  ebd5                   -jmp 0x4ab295
    goto L_0x004ab295;
L_0x004ab2c0:
    // 004ab2c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab2c1  8b1d84e34c00           -mov ebx, dword ptr [0x4ce384]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab2c7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab2c8  2eff15b4754b00         -call dword ptr cs:[0x4b75b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945332) /* 0x4b75b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab2cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ab2d4:
    // 004ab2d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab2d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab2d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab2d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab2d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab2d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab2d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab2da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab2db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab2dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab2dd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab2df  8b1584e34c00           -mov edx, dword ptr [0x4ce384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab2e5  83faff                 +cmp edx, -1
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
    // 004ab2e8  743d                   -je 0x4ab327
    if (cpu.flags.zf)
    {
        goto L_0x004ab327;
    }
    // 004ab2ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab2eb  2eff15b0754b00         -call dword ptr cs:[0x4b75b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945328) /* 0x4b75b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab2f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab2f4  7431                   -je 0x4ab327
    if (cpu.flags.zf)
    {
        goto L_0x004ab327;
    }
    // 004ab2f6  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 004ab2fc  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004ab302  e8ad620000             -call 0x4b15b4
    cpu.esp -= 4;
    sub_4b15b4(app, cpu);
    if (cpu.terminate) return;
    // 004ab307  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ab309  8b3d84e34c00           -mov edi, dword ptr [0x4ce384]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab30f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab310  2eff15b4754b00         -call dword ptr cs:[0x4b75b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945332) /* 0x4b75b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab317  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ab319  740c                   -je 0x4ab327
    if (cpu.flags.zf)
    {
        goto L_0x004ab327;
    }
    // 004ab31b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab31d  7408                   -je 0x4ab327
    if (cpu.flags.zf)
    {
        goto L_0x004ab327;
    }
    // 004ab31f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab320  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ab327:
    // 004ab327  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab328  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab329  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab32a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab32b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab32c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab327(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ab327;
    // 004ab2d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab2d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab2da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab2db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab2dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab2dd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab2df  8b1584e34c00           -mov edx, dword ptr [0x4ce384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab2e5  83faff                 +cmp edx, -1
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
    // 004ab2e8  743d                   -je 0x4ab327
    if (cpu.flags.zf)
    {
        goto L_0x004ab327;
    }
    // 004ab2ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab2eb  2eff15b0754b00         -call dword ptr cs:[0x4b75b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945328) /* 0x4b75b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab2f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab2f4  7431                   -je 0x4ab327
    if (cpu.flags.zf)
    {
        goto L_0x004ab327;
    }
    // 004ab2f6  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 004ab2fc  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004ab302  e8ad620000             -call 0x4b15b4
    cpu.esp -= 4;
    sub_4b15b4(app, cpu);
    if (cpu.terminate) return;
    // 004ab307  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ab309  8b3d84e34c00           -mov edi, dword ptr [0x4ce384]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab30f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab310  2eff15b4754b00         -call dword ptr cs:[0x4b75b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945332) /* 0x4b75b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab317  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ab319  740c                   -je 0x4ab327
    if (cpu.flags.zf)
    {
        goto L_0x004ab327;
    }
    // 004ab31b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab31d  7408                   -je 0x4ab327
    if (cpu.flags.zf)
    {
        goto L_0x004ab327;
    }
    // 004ab31f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab320  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ab327:
L_entry_0x004ab327:
    // 004ab327  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab328  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab329  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab32a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab32b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab32c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab32d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab32d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ab332  e8a1ffffff             -call 0x4ab2d8
    cpu.esp -= 4;
    sub_4ab2d8(app, cpu);
    if (cpu.terminate) return;
    // 004ab337  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab338  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab339  8b1584e34c00           -mov edx, dword ptr [0x4ce384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab33f  83faff                 +cmp edx, -1
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
    // 004ab342  7412                   -je 0x4ab356
    if (cpu.flags.zf)
    {
        goto L_0x004ab356;
    }
    // 004ab344  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab345  2eff15ac754b00         -call dword ptr cs:[0x4b75ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945324) /* 0x4b75ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab34c  c70584e34c00ffffffff   -mov dword ptr [0x4ce384], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */) = 4294967295 /*0xffffffff*/;
L_0x004ab356:
    // 004ab356  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab357  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab358  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab337(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ab337;
    // 004ab32d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ab332  e8a1ffffff             -call 0x4ab2d8
    cpu.esp -= 4;
    sub_4ab2d8(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004ab337:
    // 004ab337  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab338  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab339  8b1584e34c00           -mov edx, dword ptr [0x4ce384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab33f  83faff                 +cmp edx, -1
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
    // 004ab342  7412                   -je 0x4ab356
    if (cpu.flags.zf)
    {
        goto L_0x004ab356;
    }
    // 004ab344  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab345  2eff15ac754b00         -call dword ptr cs:[0x4b75ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945324) /* 0x4b75ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab34c  c70584e34c00ffffffff   -mov dword ptr [0x4ce384], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */) = 4294967295 /*0xffffffff*/;
L_0x004ab356:
    // 004ab356  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab357  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab358  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab359(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab359  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab35a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab35b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab35c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab35d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab35e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab35f  bab6b04a00             -mov edx, 0x4ab0b6
    cpu.edx = 4894902 /*0x4ab0b6*/;
    // 004ab364  bbc3b04a00             -mov ebx, 0x4ab0c3
    cpu.ebx = 4894915 /*0x4ab0c3*/;
    // 004ab369  b9d3b04a00             -mov ecx, 0x4ab0d3
    cpu.ecx = 4894931 /*0x4ab0d3*/;
    // 004ab36e  bed8b04a00             -mov esi, 0x4ab0d8
    cpu.esi = 4894936 /*0x4ab0d8*/;
    // 004ab373  bfa2b04a00             -mov edi, 0x4ab0a2
    cpu.edi = 4894882 /*0x4ab0a2*/;
    // 004ab378  bdacb04a00             -mov ebp, 0x4ab0ac
    cpu.ebp = 4894892 /*0x4ab0ac*/;
    // 004ab37d  b816b14a00             -mov eax, 0x4ab116
    cpu.eax = 4894998 /*0x4ab116*/;
    // 004ab382  89158ce34c00           -mov dword ptr [0x4ce38c], edx
    app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */) = cpu.edx;
    // 004ab388  891d90e34c00           -mov dword ptr [0x4ce390], ebx
    app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */) = cpu.ebx;
    // 004ab38e  890d94e34c00           -mov dword ptr [0x4ce394], ecx
    app->getMemory<x86::reg32>(x86::reg32(5038996) /* 0x4ce394 */) = cpu.ecx;
    // 004ab394  893598e34c00           -mov dword ptr [0x4ce398], esi
    app->getMemory<x86::reg32>(x86::reg32(5039000) /* 0x4ce398 */) = cpu.esi;
    // 004ab39a  893d9ce34c00           -mov dword ptr [0x4ce39c], edi
    app->getMemory<x86::reg32>(x86::reg32(5039004) /* 0x4ce39c */) = cpu.edi;
    // 004ab3a0  892da0e34c00           -mov dword ptr [0x4ce3a0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5039008) /* 0x4ce3a0 */) = cpu.ebp;
    // 004ab3a6  a3b4e34c00             -mov dword ptr [0x4ce3b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5039028) /* 0x4ce3b4 */) = cpu.eax;
    // 004ab3ab  ba1db14a00             -mov edx, 0x4ab11d
    cpu.edx = 4895005 /*0x4ab11d*/;
    // 004ab3b0  bb29b14a00             -mov ebx, 0x4ab129
    cpu.ebx = 4895017 /*0x4ab129*/;
    // 004ab3b5  b98fb14a00             -mov ecx, 0x4ab18f
    cpu.ecx = 4895119 /*0x4ab18f*/;
    // 004ab3ba  be74b04a00             -mov esi, 0x4ab074
    cpu.esi = 4894836 /*0x4ab074*/;
    // 004ab3bf  bff4b04a00             -mov edi, 0x4ab0f4
    cpu.edi = 4894964 /*0x4ab0f4*/;
    // 004ab3c4  bd05b14a00             -mov ebp, 0x4ab105
    cpu.ebp = 4894981 /*0x4ab105*/;
    // 004ab3c9  b8fbb04a00             -mov eax, 0x4ab0fb
    cpu.eax = 4894971 /*0x4ab0fb*/;
    // 004ab3ce  8915b8e34c00           -mov dword ptr [0x4ce3b8], edx
    app->getMemory<x86::reg32>(x86::reg32(5039032) /* 0x4ce3b8 */) = cpu.edx;
    // 004ab3d4  891d3cf84c00           -mov dword ptr [0x4cf83c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5044284) /* 0x4cf83c */) = cpu.ebx;
    // 004ab3da  890d40f84c00           -mov dword ptr [0x4cf840], ecx
    app->getMemory<x86::reg32>(x86::reg32(5044288) /* 0x4cf840 */) = cpu.ecx;
    // 004ab3e0  893544f84c00           -mov dword ptr [0x4cf844], esi
    app->getMemory<x86::reg32>(x86::reg32(5044292) /* 0x4cf844 */) = cpu.esi;
    // 004ab3e6  893da4e34c00           -mov dword ptr [0x4ce3a4], edi
    app->getMemory<x86::reg32>(x86::reg32(5039012) /* 0x4ce3a4 */) = cpu.edi;
    // 004ab3ec  892da8e34c00           -mov dword ptr [0x4ce3a8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5039016) /* 0x4ce3a8 */) = cpu.ebp;
    // 004ab3f2  a3ace34c00             -mov dword ptr [0x4ce3ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5039020) /* 0x4ce3ac */) = cpu.eax;
    // 004ab3f7  ba0cb14a00             -mov edx, 0x4ab10c
    cpu.edx = 4894988 /*0x4ab10c*/;
    // 004ab3fc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004ab401  be8ab14a00             -mov esi, 0x4ab18a
    cpu.esi = 4895114 /*0x4ab18a*/;
    // 004ab406  8915b0e34c00           -mov dword ptr [0x4ce3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5039024) /* 0x4ce3b0 */) = cpu.edx;
    // 004ab40c  e80ffcffff             -call 0x4ab020
    cpu.esp -= 4;
    sub_4ab020(app, cpu);
    if (cpu.terminate) return;
    // 004ab411  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab412  bf2db34a00             -mov edi, 0x4ab32d
    cpu.edi = 4895533 /*0x4ab32d*/;
    // 004ab417  a3948d5400             -mov dword ptr [0x548d94], eax
    app->getMemory<x86::reg32>(x86::reg32(5541268) /* 0x548d94 */) = cpu.eax;
    // 004ab41c  2eff1538754b00         -call dword ptr cs:[0x4b7538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945208) /* 0x4b7538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab423  b924b14a00             -mov ecx, 0x4ab124
    cpu.ecx = 4895012 /*0x4ab124*/;
    // 004ab428  8b15d04f5400           -mov edx, dword ptr [0x544fd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525456) /* 0x544fd0 */);
    // 004ab42e  891d988d5400           -mov dword ptr [0x548d98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5541272) /* 0x548d98 */) = cpu.ebx;
    // 004ab434  8935c0e34c00           -mov dword ptr [0x4ce3c0], esi
    app->getMemory<x86::reg32>(x86::reg32(5039040) /* 0x4ce3c0 */) = cpu.esi;
    // 004ab43a  893dc4e34c00           -mov dword ptr [0x4ce3c4], edi
    app->getMemory<x86::reg32>(x86::reg32(5039044) /* 0x4ce3c4 */) = cpu.edi;
    // 004ab440  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 004ab446  890dbce34c00           -mov dword ptr [0x4ce3bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5039036) /* 0x4ce3bc */) = cpu.ecx;
    // 004ab44c  e802610000             -call 0x4b1553
    cpu.esp -= 4;
    sub_4b1553(app, cpu);
    if (cpu.terminate) return;
    // 004ab451  8b2dd04f5400           -mov ebp, dword ptr [0x544fd0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5525456) /* 0x544fd0 */);
    // 004ab457  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab458  a184e34c00             -mov eax, dword ptr [0x4ce384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
    // 004ab45d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab45e  2eff15b4754b00         -call dword ptr cs:[0x4b75b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945332) /* 0x4b75b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab465  c70588e34c00b6b14a00   -mov dword ptr [0x4ce388], 0x4ab1b6
    app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */) = 4895158 /*0x4ab1b6*/;
    // 004ab46f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab470  e9b2feffff             -jmp 0x4ab327
    return sub_4ab327(app, cpu);
}

/* align: skip  */
void Application::sub_4ab475(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab475  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab476  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab477  b8648c5400             -mov eax, 0x548c64
    cpu.eax = 5540964 /*0x548c64*/;
    // 004ab47c  ba848c5400             -mov edx, 0x548c84
    cpu.edx = 5540996 /*0x548c84*/;
    // 004ab481  ff1544f84c00           -call dword ptr [0x4cf844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044292) /* 0x4cf844 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab487  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x004ab48d:
    // 004ab48d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab48f  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ab492  ff1544f84c00           -call dword ptr [0x4cf844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044292) /* 0x4cf844 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab498  39da                   +cmp edx, ebx
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
    // 004ab49a  75f1                   -jne 0x4ab48d
    if (!cpu.flags.zf)
    {
        goto L_0x004ab48d;
    }
    // 004ab49c  b8b48d5400             -mov eax, 0x548db4
    cpu.eax = 5541300 /*0x548db4*/;
    // 004ab4a1  ff1544f84c00           -call dword ptr [0x4cf844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044292) /* 0x4cf844 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab4a7  e8c6610000             -call 0x4b1672
    cpu.esp -= 4;
    sub_4b1672(app, cpu);
    if (cpu.terminate) return;
    // 004ab4ac  b8848d5400             -mov eax, 0x548d84
    cpu.eax = 5541252 /*0x548d84*/;
    // 004ab4b1  ff1544f84c00           -call dword ptr [0x4cf844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044292) /* 0x4cf844 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab4b7  b8748c5400             -mov eax, 0x548c74
    cpu.eax = 5540980 /*0x548c74*/;
    // 004ab4bc  ff1544f84c00           -call dword ptr [0x4cf844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044292) /* 0x4cf844 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab4c2  b8a48d5400             -mov eax, 0x548da4
    cpu.eax = 5541284 /*0x548da4*/;
    // 004ab4c7  ff1544f84c00           -call dword ptr [0x4cf844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044292) /* 0x4cf844 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab4cd  b8948d5400             -mov eax, 0x548d94
    cpu.eax = 5541268 /*0x548d94*/;
    // 004ab4d2  ff1544f84c00           -call dword ptr [0x4cf844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044292) /* 0x4cf844 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab4d8  e85afeffff             -call 0x4ab337
    cpu.esp -= 4;
    sub_4ab337(app, cpu);
    if (cpu.terminate) return;
    // 004ab4dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::strdup(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab4e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab4e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab4e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab4e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab4e4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab4e6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ab4e8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ab4e9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004ab4eb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004ab4ed  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab4ef  49                     -dec ecx
    (cpu.ecx)--;
    // 004ab4f0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ab4f2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004ab4f4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ab4f6  49                     -dec ecx
    (cpu.ecx)--;
    // 004ab4f7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ab4f8  41                     -inc ecx
    (cpu.ecx)++;
    // 004ab4f9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab4fb  e813ebfeff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004ab500  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab502  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab504  7418                   -je 0x4ab51e
    if (cpu.flags.zf)
    {
        goto L_0x004ab51e;
    }
    // 004ab506  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ab508  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ab509  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004ab50b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004ab50d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab50e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab510  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004ab513  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ab515  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004ab517  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004ab51a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004ab51c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab51d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004ab51e:
    // 004ab51e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab520  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab521  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab522  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab523  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab524  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab525(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab525  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab526  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab527  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab528  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab529  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ab52b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ab52d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ab52f  2eff1528754b00         -call dword ptr cs:[0x4b7528]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945192) /* 0x4b7528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab536  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ab539  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ab53e  663d0080               +cmp ax, 0x8000
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ab542  730f                   -jae 0x4ab553
    if (!cpu.flags.cf)
    {
        goto L_0x004ab553;
    }
    // 004ab544  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab545  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab546  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab547  2eff1500754b00         -call dword ptr cs:[0x4b7500]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945152) /* 0x4b7500 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab54e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab54f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab550  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab551  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab552  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab553:
    // 004ab553  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 004ab558  e8b6eafeff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004ab55d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab55f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab561  744d                   -je 0x4ab5b0
    if (cpu.flags.zf)
    {
        goto L_0x004ab5b0;
    }
    // 004ab563  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 004ab568  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab569  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab56a  2eff15fc744b00         -call dword ptr cs:[0x4b74fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945148) /* 0x4b74fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab571  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab573  750e                   -jne 0x4ab583
    if (!cpu.flags.zf)
    {
        goto L_0x004ab583;
    }
    // 004ab575  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab577  e82d3bffff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
L_0x004ab57c:
    // 004ab57c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab57e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab57f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab580  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab581  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab582  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab583:
    // 004ab583  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab584  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab585  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004ab587  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab588  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ab58a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ab58c  2eff154c754b00         -call dword ptr cs:[0x4b754c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945228) /* 0x4b754c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab593  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ab595  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab597  e80d3bffff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004ab59c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ab59e  74dc                   -je 0x4ab57c
    if (cpu.flags.zf)
    {
        goto L_0x004ab57c;
    }
    // 004ab5a0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ab5a2  66c74446fe0000         -mov word ptr [esi + eax*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.eax * 2) = 0 /*0x0*/;
    // 004ab5a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab5ab  e889610000             -call 0x4b1739
    cpu.esp -= 4;
    sub_4b1739(app, cpu);
    if (cpu.terminate) return;
L_0x004ab5b0:
    // 004ab5b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab5b5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab5b5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab5b6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab5b7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab5b8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab5ba  e87a610000             -call 0x4b1739
    cpu.esp -= 4;
    sub_4b1739(app, cpu);
    if (cpu.terminate) return;
    // 004ab5bf  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab5c2  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab5c4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab5c6  e848eafeff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004ab5cb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab5cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab5cf  7405                   -je 0x4ab5d6
    if (cpu.flags.zf)
    {
        goto L_0x004ab5d6;
    }
    // 004ab5d1  e876610000             -call 0x4b174c
    cpu.esp -= 4;
    sub_4b174c(app, cpu);
    if (cpu.terminate) return;
L_0x004ab5d6:
    // 004ab5d6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab5d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab5dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab5dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab5dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab5de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab5df  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004ab5e2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab5e4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ab5e6  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 004ab5e8  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab5ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab5ed  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ab5f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab5f2  2eff15c8754b00         -call dword ptr cs:[0x4b75c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945352) /* 0x4b75c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab5f9  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ab5fc  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004ab600  668b0d49ce4c00         -mov cx, word ptr [0x4cce49]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5033545) /* 0x4cce49 */);
    // 004ab607  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab60b  6681f90080             +cmp cx, 0x8000
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ab610  7307                   -jae 0x4ab619
    if (!cpu.flags.cf)
    {
        goto L_0x004ab619;
    }
    // 004ab612  0500300000             +add eax, 0x3000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12288 /*0x3000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab617  eb17                   -jmp 0x4ab630
    goto L_0x004ab630;
L_0x004ab619:
    // 004ab619  7210                   -jb 0x4ab62b
    if (cpu.flags.cf)
    {
        goto L_0x004ab62b;
    }
    // 004ab61b  803d47ce4c0004         +cmp byte ptr [0x4cce47], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033543) /* 0x4cce47 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab622  7307                   -jae 0x4ab62b
    if (!cpu.flags.cf)
    {
        goto L_0x004ab62b;
    }
    // 004ab624  0500200100             +add eax, 0x12000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(73728 /*0x12000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab629  eb05                   -jmp 0x4ab630
    goto L_0x004ab630;
L_0x004ab62b:
    // 004ab62b  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x004ab630:
    // 004ab630  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab632  7402                   -je 0x4ab636
    if (cpu.flags.zf)
    {
        goto L_0x004ab636;
    }
    // 004ab634  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004ab636:
    // 004ab636  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ab638  7402                   -je 0x4ab63c
    if (cpu.flags.zf)
    {
        goto L_0x004ab63c;
    }
    // 004ab63a  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x004ab63c:
    // 004ab63c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004ab63f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab640  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab641  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab642  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab643(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab643  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab644  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab645  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab646  689c174c00             -push 0x4c179c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4986780 /*0x4c179c*/;
    cpu.esp -= 4;
    // 004ab64b  2eff1540754b00         -call dword ptr cs:[0x4b7540]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945216) /* 0x4b7540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab652  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab654  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab656  7417                   -je 0x4ab66f
    if (cpu.flags.zf)
    {
        goto L_0x004ab66f;
    }
    // 004ab658  68a7174c00             -push 0x4c17a7
    app->getMemory<x86::reg32>(cpu.esp-4) = 4986791 /*0x4c17a7*/;
    cpu.esp -= 4;
    // 004ab65d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab65e  2eff1510754b00         -call dword ptr cs:[0x4b7510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945168) /* 0x4b7510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab665  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab667  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab669  7404                   -je 0x4ab66f
    if (cpu.flags.zf)
    {
        goto L_0x004ab66f;
    }
    // 004ab66b  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab66d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004ab66f:
    // 004ab66f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab671  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004ab674  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab679  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab67a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab67b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab67c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab67d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab67d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab67e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab67f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab680  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ab682  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ab684:
    // 004ab684  803800                 +cmp byte ptr [eax], 0
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
    // 004ab687  7403                   -je 0x4ab68c
    if (cpu.flags.zf)
    {
        goto L_0x004ab68c;
    }
    // 004ab689  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ab68a  ebf8                   -jmp 0x4ab684
    goto L_0x004ab684;
L_0x004ab68c:
    // 004ab68c  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x004ab68f:
    // 004ab68f  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004ab691  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004ab693  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004ab695  7412                   -je 0x4ab6a9
    if (cpu.flags.zf)
    {
        goto L_0x004ab6a9;
    }
    // 004ab697  80f930                 +cmp cl, 0x30
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab69a  7508                   -jne 0x4ab6a4
    if (!cpu.flags.zf)
    {
        goto L_0x004ab6a4;
    }
    // 004ab69c  807a0178               +cmp byte ptr [edx + 1], 0x78
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab6a0  7502                   -jne 0x4ab6a4
    if (!cpu.flags.zf)
    {
        goto L_0x004ab6a4;
    }
    // 004ab6a2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x004ab6a4:
    // 004ab6a4  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ab6a5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ab6a6  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ab6a7  ebe6                   -jmp 0x4ab68f
    goto L_0x004ab68f;
L_0x004ab6a9:
    // 004ab6a9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab6ab  7419                   -je 0x4ab6c6
    if (cpu.flags.zf)
    {
        goto L_0x004ab6c6;
    }
    // 004ab6ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004ab6af:
    // 004ab6af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab6b1  7413                   -je 0x4ab6c6
    if (cpu.flags.zf)
    {
        goto L_0x004ab6c6;
    }
    // 004ab6b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab6b5  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004ab6b8  8a9250f84c00           -mov dl, byte ptr [edx + 0x4cf850]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5044304) /* 0x4cf850 */);
    // 004ab6be  c1e804                 +shr eax, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004ab6c1  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004ab6c3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ab6c4  ebe9                   -jmp 0x4ab6af
    goto L_0x004ab6af;
L_0x004ab6c6:
    // 004ab6c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab6ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab6ca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab6cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab6cc  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004ab6d2  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004ab6d9  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ab6db  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004ab6de  e860ffffff             -call 0x4ab643
    cpu.esp -= 4;
    sub_4ab643(app, cpu);
    if (cpu.terminate) return;
    // 004ab6e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab6e5  750a                   -jne 0x4ab6f1
    if (!cpu.flags.zf)
    {
        goto L_0x004ab6f1;
    }
    // 004ab6e7  e822610000             -call 0x4b180e
    cpu.esp -= 4;
    sub_4b180e(app, cpu);
    if (cpu.terminate) return;
    // 004ab6ec  83f8ff                 +cmp eax, -1
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
    // 004ab6ef  7507                   -jne 0x4ab6f8
    if (!cpu.flags.zf)
    {
        goto L_0x004ab6f8;
    }
L_0x004ab6f1:
    // 004ab6f1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ab6f3  e97e010000             -jmp 0x4ab876
    goto L_0x004ab876;
L_0x004ab6f8:
    // 004ab6f8  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004ab6fa  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004ab6fd  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab6ff  3d900000c0             +cmp eax, 0xc0000090
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225616 /*0xc0000090*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab704  724d                   -jb 0x4ab753
    if (cpu.flags.cf)
    {
        goto L_0x004ab753;
    }
    // 004ab706  0f86b5000000           -jbe 0x4ab7c1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab7c1;
    }
    // 004ab70c  3d930000c0             +cmp eax, 0xc0000093
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225619 /*0xc0000093*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab711  7233                   -jb 0x4ab746
    if (cpu.flags.cf)
    {
        goto L_0x004ab746;
    }
    // 004ab713  0f86a1000000           -jbe 0x4ab7ba
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab7ba;
    }
    // 004ab719  3d960000c0             +cmp eax, 0xc0000096
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225622 /*0xc0000096*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab71e  7216                   -jb 0x4ab736
    if (cpu.flags.cf)
    {
        goto L_0x004ab736;
    }
    // 004ab720  0f86d8000000           -jbe 0x4ab7fe
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab7fe;
    }
    // 004ab726  3dfd0000c0             +cmp eax, 0xc00000fd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225725 /*0xc00000fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab72b  0f84e5000000           -je 0x4ab816
    if (cpu.flags.zf)
    {
        goto L_0x004ab816;
    }
    // 004ab731  e9ea000000             -jmp 0x4ab820
    goto L_0x004ab820;
L_0x004ab736:
    // 004ab736  3d940000c0             +cmp eax, 0xc0000094
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225620 /*0xc0000094*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab73b  0f84cb000000           -je 0x4ab80c
    if (cpu.flags.zf)
    {
        goto L_0x004ab80c;
    }
    // 004ab741  e9da000000             -jmp 0x4ab820
    goto L_0x004ab820;
L_0x004ab746:
    // 004ab746  3d910000c0             +cmp eax, 0xc0000091
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225617 /*0xc0000091*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab74b  0f8662000000           -jbe 0x4ab7b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab7b3;
    }
    // 004ab751  eb2f                   -jmp 0x4ab782
    goto L_0x004ab782;
L_0x004ab753:
    // 004ab753  3d8d0000c0             +cmp eax, 0xc000008d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225613 /*0xc000008d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab758  720b                   -jb 0x4ab765
    if (cpu.flags.cf)
    {
        goto L_0x004ab765;
    }
    // 004ab75a  7642                   -jbe 0x4ab79e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab79e;
    }
    // 004ab75c  3d8e0000c0             +cmp eax, 0xc000008e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225614 /*0xc000008e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab761  7642                   -jbe 0x4ab7a5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab7a5;
    }
    // 004ab763  eb47                   -jmp 0x4ab7ac
    goto L_0x004ab7ac;
L_0x004ab765:
    // 004ab765  3d050000c0             +cmp eax, 0xc0000005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225477 /*0xc0000005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab76a  0f82b0000000           -jb 0x4ab820
    if (cpu.flags.cf)
    {
        goto L_0x004ab820;
    }
    // 004ab770  7656                   -jbe 0x4ab7c8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab7c8;
    }
    // 004ab772  3d1d0000c0             +cmp eax, 0xc000001d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225501 /*0xc000001d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab777  0f8488000000           -je 0x4ab805
    if (cpu.flags.zf)
    {
        goto L_0x004ab805;
    }
    // 004ab77d  e99e000000             -jmp 0x4ab820
    goto L_0x004ab820;
L_0x004ab782:
    // 004ab782  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 004ab786  740f                   -je 0x4ab797
    if (cpu.flags.zf)
    {
        goto L_0x004ab797;
    }
    // 004ab788  bab7174c00             -mov edx, 0x4c17b7
    cpu.edx = 4986807 /*0x4c17b7*/;
L_0x004ab78d:
    // 004ab78d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ab78f  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004ab792  e9a1000000             -jmp 0x4ab838
    goto L_0x004ab838;
L_0x004ab797:
    // 004ab797  ba08184c00             -mov edx, 0x4c1808
    cpu.edx = 4986888 /*0x4c1808*/;
    // 004ab79c  ebef                   -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab79e:
    // 004ab79e  ba5a184c00             -mov edx, 0x4c185a
    cpu.edx = 4986970 /*0x4c185a*/;
    // 004ab7a3  ebe8                   -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab7a5:
    // 004ab7a5  baad184c00             -mov edx, 0x4c18ad
    cpu.edx = 4987053 /*0x4c18ad*/;
    // 004ab7aa  ebe1                   -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab7ac:
    // 004ab7ac  ba00194c00             -mov edx, 0x4c1900
    cpu.edx = 4987136 /*0x4c1900*/;
    // 004ab7b1  ebda                   -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab7b3:
    // 004ab7b3  ba51194c00             -mov edx, 0x4c1951
    cpu.edx = 4987217 /*0x4c1951*/;
    // 004ab7b8  ebd3                   -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab7ba:
    // 004ab7ba  ba9d194c00             -mov edx, 0x4c199d
    cpu.edx = 4987293 /*0x4c199d*/;
    // 004ab7bf  ebcc                   -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab7c1:
    // 004ab7c1  baea194c00             -mov edx, 0x4c19ea
    cpu.edx = 4987370 /*0x4c19ea*/;
    // 004ab7c6  ebc5                   -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab7c8:
    // 004ab7c8  ba3f1a4c00             -mov edx, 0x4c1a3f
    cpu.edx = 4987455 /*0x4c1a3f*/;
    // 004ab7cd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ab7cf  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004ab7d2  e8a6feffff             -call 0x4ab67d
    cpu.esp -= 4;
    sub_4ab67d(app, cpu);
    if (cpu.terminate) return;
    // 004ab7d7  ba701a4c00             -mov edx, 0x4c1a70
    cpu.edx = 4987504 /*0x4c1a70*/;
    // 004ab7dc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ab7de  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004ab7e1  e897feffff             -call 0x4ab67d
    cpu.esp -= 4;
    sub_4ab67d(app, cpu);
    if (cpu.terminate) return;
    // 004ab7e6  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab7ea  750b                   -jne 0x4ab7f7
    if (!cpu.flags.zf)
    {
        goto L_0x004ab7f7;
    }
    // 004ab7ec  ba981a4c00             -mov edx, 0x4c1a98
    cpu.edx = 4987544 /*0x4c1a98*/;
L_0x004ab7f1:
    // 004ab7f1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ab7f3  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004ab7f5  eb41                   -jmp 0x4ab838
    goto L_0x004ab838;
L_0x004ab7f7:
    // 004ab7f7  ba9f1a4c00             -mov edx, 0x4c1a9f
    cpu.edx = 4987551 /*0x4c1a9f*/;
    // 004ab7fc  ebf3                   -jmp 0x4ab7f1
    goto L_0x004ab7f1;
L_0x004ab7fe:
    // 004ab7fe  baa91a4c00             -mov edx, 0x4c1aa9
    cpu.edx = 4987561 /*0x4c1aa9*/;
    // 004ab803  eb88                   -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab805:
    // 004ab805  bae71a4c00             -mov edx, 0x4c1ae7
    cpu.edx = 4987623 /*0x4c1ae7*/;
    // 004ab80a  eb81                   -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab80c:
    // 004ab80c  ba231b4c00             -mov edx, 0x4c1b23
    cpu.edx = 4987683 /*0x4c1b23*/;
    // 004ab811  e977ffffff             -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab816:
    // 004ab816  ba651b4c00             -mov edx, 0x4c1b65
    cpu.edx = 4987749 /*0x4c1b65*/;
    // 004ab81b  e96dffffff             -jmp 0x4ab78d
    goto L_0x004ab78d;
L_0x004ab820:
    // 004ab820  ba9e1b4c00             -mov edx, 0x4c1b9e
    cpu.edx = 4987806 /*0x4c1b9e*/;
    // 004ab825  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ab827  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab829  e84ffeffff             -call 0x4ab67d
    cpu.esp -= 4;
    sub_4ab67d(app, cpu);
    if (cpu.terminate) return;
    // 004ab82e  bacf1b4c00             -mov edx, 0x4c1bcf
    cpu.edx = 4987855 /*0x4c1bcf*/;
    // 004ab833  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ab835  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x004ab838:
    // 004ab838  e840feffff             -call 0x4ab67d
    cpu.esp -= 4;
    sub_4ab67d(app, cpu);
    if (cpu.terminate) return;
    // 004ab83d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ab83f  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004ab846  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab847  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ab84b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ab84c  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004ab84e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004ab850  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab852  49                     -dec ecx
    (cpu.ecx)--;
    // 004ab853  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ab855  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004ab857  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ab859  49                     -dec ecx
    (cpu.ecx)--;
    // 004ab85a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ab85b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab85c  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ab860  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab861  a1d4f74c00             -mov eax, dword ptr [0x4cf7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004ab866  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab869  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab86a  2eff15dc754b00         -call dword ptr cs:[0x4b75dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945372) /* 0x4b75dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab871  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ab876:
    // 004ab876  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004ab87c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab87d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab87e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4ab881(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab881  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004ab883  e9b84a00f3             -jmp 0xf34b0340
    return sub_f34b0340(app, cpu);
}

/* align: skip  */
void Application::sub_4ab888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004ab888  b84a00fdb8             -mov eax, 0xb8fd004a
    cpu.eax = 3103588426 /*0xb8fd004a*/;
    // 004ab88d  4a                     -dec edx
    (cpu.edx)--;
    // 004ab88e  001b                   -add byte ptr [ebx], bl
    (app->getMemory<x86::reg8>(cpu.ebx)) += x86::reg8(x86::sreg8(cpu.bl));
    // 004ab890  b94a0007b9             -mov ecx, 0xb907004a
    cpu.ecx = 3104243786 /*0xb907004a*/;
    // 004ab895  4a                     -dec edx
    (cpu.edx)--;
    // 004ab896  00cf                   -add bh, cl
    (cpu.bh) += x86::reg8(x86::sreg8(cpu.cl));
    // 004ab898  b84a0011b9             -mov eax, 0xb911004a
    cpu.eax = 3104899146 /*0xb911004a*/;
    // 004ab89d  4a                     -dec edx
    (cpu.edx)--;
    // 004ab89e  005356                 -add byte ptr [ebx + 0x56], dl
    (app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(86) /* 0x56 */)) += x86::reg8(x86::sreg8(cpu.dl));
    // 004ab8a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab8a2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab8a5  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab8a9  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab8ad  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 004ab8b1  0f85a0010000           -jne 0x4aba57
    if (!cpu.flags.zf)
    {
        goto L_0x004aba57;
    }
    // 004ab8b7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ab8b9  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 004ab8be  83f806                 +cmp eax, 6
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
    // 004ab8c1  0f8723010000           -ja 0x4ab9ea
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab9ea;
    }
    // 004ab8c7  2eff248583b84a00       -jmp dword ptr cs:[eax*4 + 0x4ab883]
    cpu.ip = app->getMemory<x86::reg32>(4896899 + cpu.eax * 4); goto dynamic_jump;
  case 0x004ab8cf:
    // 004ab8cf  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 004ab8d3  740a                   -je 0x4ab8df
    if (cpu.flags.zf)
    {
        goto L_0x004ab8df;
    }
    // 004ab8d5  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 004ab8da  e9ce000000             -jmp 0x4ab9ad
    goto L_0x004ab9ad;
L_0x004ab8df:
    // 004ab8df  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 004ab8e4  e9c4000000             -jmp 0x4ab9ad
    goto L_0x004ab9ad;
  case 0x004ab8e9:
    // 004ab8e9  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 004ab8ee  e9ba000000             -jmp 0x4ab9ad
    goto L_0x004ab9ad;
  case 0x004ab8f3:
L_0x004ab8f3:
    // 004ab8f3  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 004ab8f8  e9b0000000             -jmp 0x4ab9ad
    goto L_0x004ab9ad;
  case 0x004ab8fd:
    // 004ab8fd  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 004ab902  e9a6000000             -jmp 0x4ab9ad
    goto L_0x004ab9ad;
  case 0x004ab907:
    // 004ab907  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 004ab90c  e99c000000             -jmp 0x4ab9ad
    goto L_0x004ab9ad;
  case 0x004ab911:
    // 004ab911  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 004ab916  e992000000             -jmp 0x4ab9ad
    goto L_0x004ab9ad;
  case 0x004ab91b:
    // 004ab91b  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004ab91e  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004ab921  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 004ab926  6681fad9fa             +cmp dx, 0xfad9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(64217 /*0xfad9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ab92b  750a                   -jne 0x4ab937
    if (!cpu.flags.zf)
    {
        goto L_0x004ab937;
    }
    // 004ab92d  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 004ab932  e976000000             -jmp 0x4ab9ad
    goto L_0x004ab9ad;
L_0x004ab937:
    // 004ab937  6681fad9f1             +cmp dx, 0xf1d9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61913 /*0xf1d9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ab93c  750a                   -jne 0x4ab948
    if (!cpu.flags.zf)
    {
        goto L_0x004ab948;
    }
    // 004ab93e  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 004ab943  e965000000             -jmp 0x4ab9ad
    goto L_0x004ab9ad;
L_0x004ab948:
    // 004ab948  7507                   -jne 0x4ab951
    if (!cpu.flags.zf)
    {
        goto L_0x004ab951;
    }
    // 004ab94a  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 004ab94f  eb5c                   -jmp 0x4ab9ad
    goto L_0x004ab9ad;
L_0x004ab951:
    // 004ab951  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004ab953  80fedb                 +cmp dh, 0xdb
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(219 /*0xdb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab956  7405                   -je 0x4ab95d
    if (cpu.flags.zf)
    {
        goto L_0x004ab95d;
    }
    // 004ab958  80fedf                 +cmp dh, 0xdf
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(223 /*0xdf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab95b  7510                   -jne 0x4ab96d
    if (!cpu.flags.zf)
    {
        goto L_0x004ab96d;
    }
L_0x004ab95d:
    // 004ab95d  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab960  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004ab963  80fa10                 +cmp dl, 0x10
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
    // 004ab966  7505                   -jne 0x4ab96d
    if (!cpu.flags.zf)
    {
        goto L_0x004ab96d;
    }
    // 004ab968  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x004ab96d:
    // 004ab96d  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 004ab970  7536                   -jne 0x4ab9a8
    if (!cpu.flags.zf)
    {
        goto L_0x004ab9a8;
    }
    // 004ab972  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab975  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004ab977  3c30                   +cmp al, 0x30
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
    // 004ab979  752d                   -jne 0x4ab9a8
    if (!cpu.flags.zf)
    {
        goto L_0x004ab9a8;
    }
    // 004ab97b  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 004ab97e  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ab983  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ab986  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab988  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 004ab98c  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 004ab98f  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 004ab992  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ab998  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab99a  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004ab99c  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ab99f  83fa01                 +cmp edx, 1
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
    // 004ab9a2  0f844bffffff           -je 0x4ab8f3
    if (cpu.flags.zf)
    {
        goto L_0x004ab8f3;
    }
L_0x004ab9a8:
    // 004ab9a8  83fbff                 +cmp ebx, -1
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
    // 004ab9ab  743d                   -je 0x4ab9ea
    if (cpu.flags.zf)
    {
        goto L_0x004ab9ea;
    }
L_0x004ab9ad:
    // 004ab9ad  c605d893540001         -mov byte ptr [0x5493d8], 1
    app->getMemory<x86::reg8>(x86::reg32(5542872) /* 0x5493d8 */) = 1 /*0x1*/;
    // 004ab9b4  e8605e0000             -call 0x4b1819
    cpu.esp -= 4;
    sub_4b1819(app, cpu);
    if (cpu.terminate) return;
    // 004ab9b9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab9bb  e826600000             -call 0x4b19e6
    cpu.esp -= 4;
    sub_4b19e6(app, cpu);
    if (cpu.terminate) return;
    // 004ab9c0  83f8ff                 +cmp eax, -1
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
    // 004ab9c3  0f846f000000           -je 0x4aba38
    if (cpu.flags.zf)
    {
        goto L_0x004aba38;
    }
    // 004ab9c9  803dd893540000         +cmp byte ptr [0x5493d8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5542872) /* 0x5493d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab9d0  0f8462000000           -je 0x4aba38
    if (cpu.flags.zf)
    {
        goto L_0x004aba38;
    }
    // 004ab9d6  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 004ab9da  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004ab9dc  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004ab9df  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ab9e1  66895f20               -mov word ptr [edi + 0x20], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 004ab9e5  e972000000             -jmp 0x4aba5c
    goto L_0x004aba5c;
L_0x004ab9ea:
    // 004ab9ea  833d4cf84c0000         +cmp dword ptr [0x4cf84c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5044300) /* 0x4cf84c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab9f1  7445                   -je 0x4aba38
    if (cpu.flags.zf)
    {
        goto L_0x004aba38;
    }
    // 004ab9f3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004ab9f8:
    // 004ab9f8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab9fa  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004ab9fc  ff1548f84c00           -call dword ptr [0x4cf848]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044296) /* 0x4cf848 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aba02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aba04  742c                   -je 0x4aba32
    if (cpu.flags.zf)
    {
        goto L_0x004aba32;
    }
    // 004aba06  83f801                 +cmp eax, 1
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
    // 004aba09  742d                   -je 0x4aba38
    if (cpu.flags.zf)
    {
        goto L_0x004aba38;
    }
    // 004aba0b  83f802                 +cmp eax, 2
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
    // 004aba0e  7428                   -je 0x4aba38
    if (cpu.flags.zf)
    {
        goto L_0x004aba38;
    }
    // 004aba10  83f803                 +cmp eax, 3
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
    // 004aba13  7423                   -je 0x4aba38
    if (cpu.flags.zf)
    {
        goto L_0x004aba38;
    }
    // 004aba15  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004aba17  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aba19  8815d8935400           -mov byte ptr [0x5493d8], dl
    app->getMemory<x86::reg8>(x86::reg32(5542872) /* 0x5493d8 */) = cpu.dl;
    // 004aba1f  ff154cf84c00           -call dword ptr [0x4cf84c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044300) /* 0x4cf84c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aba25  803dd893540000         +cmp byte ptr [0x5493d8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5542872) /* 0x5493d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aba2c  7404                   -je 0x4aba32
    if (cpu.flags.zf)
    {
        goto L_0x004aba32;
    }
    // 004aba2e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004aba30  eb2a                   -jmp 0x4aba5c
    goto L_0x004aba5c;
L_0x004aba32:
    // 004aba32  43                     -inc ebx
    (cpu.ebx)++;
    // 004aba33  83fb0c                 +cmp ebx, 0xc
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
    // 004aba36  7ec0                   -jle 0x4ab9f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab9f8;
    }
L_0x004aba38:
    // 004aba38  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004aba3a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004aba3b  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004aba3f  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004aba43  2eff15b8754b00         -call dword ptr cs:[0x4b75b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945336) /* 0x4b75b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aba4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aba4c  7409                   -je 0x4aba57
    if (cpu.flags.zf)
    {
        goto L_0x004aba57;
    }
    // 004aba4e  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004aba50  2eff1580744b00         -call dword ptr cs:[0x4b7480]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945024) /* 0x4b7480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004aba57:
    // 004aba57  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004aba5c:
    // 004aba5c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aba5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aba60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aba61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aba62  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4aba63(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aba63  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aba64  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aba65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aba67  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aba6d  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004aba70  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aba72  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 004aba75  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aba77  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aba7d  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004aba80  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004aba82  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aba88  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004aba8b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aba8d  c740049fb84a00         -mov dword ptr [eax + 4], 0x4ab89f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 4896927 /*0x4ab89f*/;
    // 004aba94  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aba9a  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004aba9d  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 004abaa0  68cab64a00             -push 0x4ab6ca
    app->getMemory<x86::reg32>(cpu.esp-4) = 4896458 /*0x4ab6ca*/;
    cpu.esp -= 4;
    // 004abaa5  2eff159c754b00         -call dword ptr cs:[0x4b759c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945308) /* 0x4b759c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abaac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abaad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abaae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abaaf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abaaf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abab0  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abab6  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004abab9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ababb  7407                   -je 0x4abac4
    if (cpu.flags.zf)
    {
        goto L_0x004abac4;
    }
    // 004ababd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ababf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abac1  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x004abac4:
    // 004abac4  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abaca  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 004abad1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abad2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abad3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abad3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004abad8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abad9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abada  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abadb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004abadd  ff159ce34c00           -call dword ptr [0x4ce39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039004) /* 0x4ce39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abae3  8b15c44f5400           -mov edx, dword ptr [0x544fc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */);
    // 004abae9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004abaeb  eb16                   -jmp 0x4abb03
    goto L_0x004abb03;
L_0x004abaed:
    // 004abaed  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004abaf0  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 004abaf3  740c                   -je 0x4abb01
    if (cpu.flags.zf)
    {
        goto L_0x004abb01;
    }
    // 004abaf5  43                     -inc ebx
    (cpu.ebx)++;
    // 004abaf6  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004abafa  7405                   -je 0x4abb01
    if (cpu.flags.zf)
    {
        goto L_0x004abb01;
    }
    // 004abafc  e83f33ffff             -call 0x49ee40
    cpu.esp -= 4;
    sub_49ee40(app, cpu);
    if (cpu.terminate) return;
L_0x004abb01:
    // 004abb01  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004abb03:
    // 004abb03  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004abb05  75e6                   -jne 0x4abaed
    if (!cpu.flags.zf)
    {
        goto L_0x004abaed;
    }
    // 004abb07  ff15a0e34c00           -call dword ptr [0x4ce3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039008) /* 0x4ce3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abb0d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abb0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abad8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004abad8;
    // 004abad3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_entry_0x004abad8:
    // 004abad8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abad9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abada  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abadb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004abadd  ff159ce34c00           -call dword ptr [0x4ce39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039004) /* 0x4ce39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abae3  8b15c44f5400           -mov edx, dword ptr [0x544fc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */);
    // 004abae9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004abaeb  eb16                   -jmp 0x4abb03
    goto L_0x004abb03;
L_0x004abaed:
    // 004abaed  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004abaf0  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 004abaf3  740c                   -je 0x4abb01
    if (cpu.flags.zf)
    {
        goto L_0x004abb01;
    }
    // 004abaf5  43                     -inc ebx
    (cpu.ebx)++;
    // 004abaf6  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004abafa  7405                   -je 0x4abb01
    if (cpu.flags.zf)
    {
        goto L_0x004abb01;
    }
    // 004abafc  e83f33ffff             -call 0x49ee40
    cpu.esp -= 4;
    sub_49ee40(app, cpu);
    if (cpu.terminate) return;
L_0x004abb01:
    // 004abb01  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004abb03:
    // 004abb03  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004abb05  75e6                   -jne 0x4abaed
    if (!cpu.flags.zf)
    {
        goto L_0x004abaed;
    }
    // 004abb07  ff15a0e34c00           -call dword ptr [0x4ce3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039008) /* 0x4ce3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abb0d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abb0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abb13(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abb13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abb14  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abb15  8b1d30ce4c00           -mov ebx, dword ptr [0x4cce30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5033520) /* 0x4cce30 */);
    // 004abb1b  e879610000             -call 0x4b1c99
    cpu.esp -= 4;
    sub_4b1c99(app, cpu);
    if (cpu.terminate) return;
    // 004abb20  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004abb22  83f8ff                 +cmp eax, -1
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
    // 004abb25  7409                   -je 0x4abb30
    if (cpu.flags.zf)
    {
        goto L_0x004abb30;
    }
    // 004abb27  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004abb29  7505                   -jne 0x4abb30
    if (!cpu.flags.zf)
    {
        goto L_0x004abb30;
    }
    // 004abb2b  e8e5610000             -call 0x4b1d15
    cpu.esp -= 4;
    sub_4b1d15(app, cpu);
    if (cpu.terminate) return;
L_0x004abb30:
    // 004abb30  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004abb32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abb35(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abb35  8a80e1935400           -mov al, byte ptr [eax + 0x5493e1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5542881) /* 0x5493e1 */);
    // 004abb3b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004abb3d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004abb42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abb43(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abb43  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004abb45  e92f620000             -jmp 0x4b1d79
    return sub_4b1d79(app, cpu);
}

/* align: skip  */
void Application::sub_4abb4a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abb4a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abb4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abb4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abb4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abb4e  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004abb50  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abb53  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004abb55  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004abb57  7507                   -jne 0x4abb60
    if (!cpu.flags.zf)
    {
        goto L_0x004abb60;
    }
L_0x004abb59:
    // 004abb59  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004abb5b  e977000000             -jmp 0x4abbd7
    goto L_0x004abbd7;
L_0x004abb60:
    // 004abb60  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004abb62  0f866a000000           -jbe 0x4abbd2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004abbd2;
    }
    // 004abb68  803a00                 +cmp byte ptr [edx], 0
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
    // 004abb6b  750b                   -jne 0x4abb78
    if (!cpu.flags.zf)
    {
        goto L_0x004abb78;
    }
    // 004abb6d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004abb6f  74e8                   -je 0x4abb59
    if (cpu.flags.zf)
    {
        goto L_0x004abb59;
    }
    // 004abb71  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 004abb76  ebe1                   -jmp 0x4abb59
    goto L_0x004abb59;
L_0x004abb78:
    // 004abb78  833ddc93540000         +cmp dword ptr [0x5493dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abb7f  7419                   -je 0x4abb9a
    if (cpu.flags.zf)
    {
        goto L_0x004abb9a;
    }
    // 004abb81  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abb83  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004abb85  8a80e1935400           -mov al, byte ptr [eax + 0x5493e1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5542881) /* 0x5493e1 */);
    // 004abb8b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004abb8d  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004abb92  7406                   -je 0x4abb9a
    if (cpu.flags.zf)
    {
        goto L_0x004abb9a;
    }
    // 004abb94  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 004abb98  7438                   -je 0x4abbd2
    if (cpu.flags.zf)
    {
        goto L_0x004abbd2;
    }
L_0x004abb9a:
    // 004abb9a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004abb9c  e824630000             -call 0x4b1ec5
    cpu.esp -= 4;
    sub_4b1ec5(app, cpu);
    if (cpu.terminate) return;
    // 004abba1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004abba3  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004abba6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004abba8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abba9  39c3                   +cmp ebx, eax
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
    // 004abbab  7302                   -jae 0x4abbaf
    if (!cpu.flags.cf)
    {
        goto L_0x004abbaf;
    }
    // 004abbad  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004abbaf:
    // 004abbaf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abbb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abbb1  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004abbb3  a188fb4c00             -mov eax, dword ptr [0x4cfb88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5045128) /* 0x4cfb88 */);
    // 004abbb8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abbb9  2eff154c754b00         -call dword ptr cs:[0x4b754c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945228) /* 0x4b754c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abbc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abbc2  740e                   -je 0x4abbd2
    if (cpu.flags.zf)
    {
        goto L_0x004abbd2;
    }
    // 004abbc4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004abbc6  7406                   -je 0x4abbce
    if (cpu.flags.zf)
    {
        goto L_0x004abbce;
    }
    // 004abbc8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004abbcb  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004abbce:
    // 004abbce  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004abbd0  eb05                   -jmp 0x4abbd7
    goto L_0x004abbd7;
L_0x004abbd2:
    // 004abbd2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004abbd7:
    // 004abbd7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004abbd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abbda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abbdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abbdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abbdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abbde(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abbde  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abbdf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004abbe4  b8f81b4c00             -mov eax, 0x4c1bf8
    cpu.eax = 4987896 /*0x4c1bf8*/;
    // 004abbe9  e803040000             -call 0x4abff1
    cpu.esp -= 4;
    sub_4abff1(app, cpu);
    if (cpu.terminate) return;
    // 004abbee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abbef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abbf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abbf1  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 004abbf7  743f                   -je 0x4abc38
    if (cpu.flags.zf)
    {
        goto L_0x004abc38;
    }
    // 004abbf9  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004abbfb  01c0                   +add eax, eax
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
    // 004abbfd  11d2                   +adc edx, edx
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
    // 004abbff  d1db                   -rcr ebx, 1
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
    // 004abc01  0500000020             +add eax, 0x20000000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(536870912 /*0x20000000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004abc06  83d200                 +adc edx, 0
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
    // 004abc09  7424                   -je 0x4abc2f
    if (cpu.flags.zf)
    {
        goto L_0x004abc2f;
    }
    // 004abc0b  81fa0000e08f           +cmp edx, 0x8fe00000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2413821952 /*0x8fe00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abc11  731c                   -jae 0x4abc2f
    if (!cpu.flags.cf)
    {
        goto L_0x004abc2f;
    }
    // 004abc13  81fa00002070           +cmp edx, 0x70200000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1881145344 /*0x70200000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abc19  721d                   -jb 0x4abc38
    if (cpu.flags.cf)
    {
        goto L_0x004abc38;
    }
    // 004abc1b  81ea00000070           -sub edx, 0x70000000
    (cpu.edx) -= x86::reg32(x86::sreg32(1879048192 /*0x70000000*/));
    // 004abc21  01c0                   +add eax, eax
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
    // 004abc23  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004abc25  01c0                   +add eax, eax
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
    // 004abc27  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004abc29  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004abc2b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004abc2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abc2f:
    // 004abc2f  b80000807f             -mov eax, 0x7f800000
    cpu.eax = 2139095040 /*0x7f800000*/;
    // 004abc34  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004abc36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abc38:
    // 004abc38  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004abc3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abc3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abc3c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004abc3e  7507                   -jne 0x4abc47
    if (!cpu.flags.zf)
    {
        goto L_0x004abc47;
    }
    // 004abc40  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004abc42  7503                   -jne 0x4abc47
    if (!cpu.flags.zf)
    {
        goto L_0x004abc47;
    }
    // 004abc44  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004abc46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abc47:
    // 004abc47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abc48  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abc49  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004abc4b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004abc4d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc4e  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004abc50  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004abc52  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc53  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004abc55  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004abc57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abc58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abc58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abc59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abc5a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004abc5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abc5d  2eff15dc744b00         -call dword ptr cs:[0x4b74dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945116) /* 0x4b74dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abc64  83f8ff                 +cmp eax, -1
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
    // 004abc67  7508                   -jne 0x4abc71
    if (!cpu.flags.zf)
    {
        goto L_0x004abc71;
    }
    // 004abc69  e894e3feff             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
    // 004abc6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abc71:
    // 004abc71  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004abc74  7411                   -je 0x4abc87
    if (cpu.flags.zf)
    {
        goto L_0x004abc87;
    }
    // 004abc76  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004abc78  740d                   -je 0x4abc87
    if (cpu.flags.zf)
    {
        goto L_0x004abc87;
    }
    // 004abc7a  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004abc7f  e82de3feff             -call 0x499fb1
    cpu.esp -= 4;
    sub_499fb1(app, cpu);
    if (cpu.terminate) return;
    // 004abc84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abc87:
    // 004abc87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abc89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abc8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abc8c  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abc92  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abc95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abc96(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abc96  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abc9c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004abc9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abca0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abca1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abca2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abca3  2eff1548754b00         -call dword ptr cs:[0x4b7548]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945224) /* 0x4b7548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abcaa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abcac  7507                   -jne 0x4abcb5
    if (!cpu.flags.zf)
    {
        goto L_0x004abcb5;
    }
    // 004abcae  e84fe3feff             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
    // 004abcb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abcb4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abcb5:
    // 004abcb5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abcb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abcb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abcb9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abcb9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abcba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abcbb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abcbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abcbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abcbe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abcbf  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004abcc1  8b35cc935400           -mov esi, dword ptr [0x5493cc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */);
    // 004abcc7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004abcc9  743f                   -je 0x4abd0a
    if (cpu.flags.zf)
    {
        goto L_0x004abd0a;
    }
    // 004abccb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abccd  743b                   -je 0x4abd0a
    if (cpu.flags.zf)
    {
        goto L_0x004abd0a;
    }
    // 004abccf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004abcd1  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004abcd2  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004abcd4  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004abcd6  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004abcd8  49                     -dec ecx
    (cpu.ecx)--;
    // 004abcd9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004abcdb  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004abcdd  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004abcdf  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004abce0  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004abce1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004abce3  eb1f                   -jmp 0x4abd04
    goto L_0x004abd04;
L_0x004abce5:
    // 004abce5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004abce7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004abce9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004abceb  e800620000             -call 0x4b1ef0
    cpu.esp -= 4;
    sub_4b1ef0(app, cpu);
    if (cpu.terminate) return;
    // 004abcf0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abcf2  750d                   -jne 0x4abd01
    if (!cpu.flags.zf)
    {
        goto L_0x004abd01;
    }
    // 004abcf4  803c393d               +cmp byte ptr [ecx + edi], 0x3d
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
    // 004abcf8  7507                   -jne 0x4abd01
    if (!cpu.flags.zf)
    {
        goto L_0x004abd01;
    }
    // 004abcfa  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004abcfd  01c8                   +add eax, ecx
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
    // 004abcff  eb0b                   -jmp 0x4abd0c
    goto L_0x004abd0c;
L_0x004abd01:
    // 004abd01  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004abd04:
    // 004abd04  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004abd06  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004abd08  75db                   -jne 0x4abce5
    if (!cpu.flags.zf)
    {
        goto L_0x004abce5;
    }
L_0x004abd0a:
    // 004abd0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004abd0c:
    // 004abd0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abd13(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abd13  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abd14  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abd15  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abd16  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abd19  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004abd1b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004abd1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abd1f  7522                   -jne 0x4abd43
    if (!cpu.flags.zf)
    {
        goto L_0x004abd43;
    }
    // 004abd21  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004abd26  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abd28  e8e6e2feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004abd2d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004abd2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abd31  750e                   -jne 0x4abd41
    if (!cpu.flags.zf)
    {
        goto L_0x004abd41;
    }
    // 004abd33  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
L_0x004abd38:
    // 004abd38  e8c3e3feff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
L_0x004abd3d:
    // 004abd3d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004abd3f  eb5c                   -jmp 0x4abd9d
    goto L_0x004abd9d;
L_0x004abd41:
    // 004abd41  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004abd43:
    // 004abd43  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004abd45  7405                   -je 0x4abd4c
    if (cpu.flags.zf)
    {
        goto L_0x004abd4c;
    }
    // 004abd47  803900                 +cmp byte ptr [ecx], 0
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
    // 004abd4a  750b                   -jne 0x4abd57
    if (!cpu.flags.zf)
    {
        goto L_0x004abd57;
    }
L_0x004abd4c:
    // 004abd4c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004abd4e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abd50  e8d007fdff             -call 0x47c525
    cpu.esp -= 4;
    sub_47c525(app, cpu);
    if (cpu.terminate) return;
    // 004abd55  eb46                   -jmp 0x4abd9d
    goto L_0x004abd9d;
L_0x004abd57:
    // 004abd57  ba1c1c4c00             -mov edx, 0x4c1c1c
    cpu.edx = 4987932 /*0x4c1c1c*/;
    // 004abd5c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004abd5e  e8803cfeff             -call 0x48f9e3
    cpu.esp -= 4;
    sub_48f9e3(app, cpu);
    if (cpu.terminate) return;
    // 004abd63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abd65  751c                   -jne 0x4abd83
    if (!cpu.flags.zf)
    {
        goto L_0x004abd83;
    }
    // 004abd67  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abd6a  730e                   -jae 0x4abd7a
    if (!cpu.flags.cf)
    {
        goto L_0x004abd7a;
    }
    // 004abd6c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004abd6e  e83633ffff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004abd73  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004abd78  ebbe                   -jmp 0x4abd38
    goto L_0x004abd38;
L_0x004abd7a:
    // 004abd7a  a11c1c4c00             -mov eax, dword ptr [0x4c1c1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4987932) /* 0x4c1c1c */);
    // 004abd7f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004abd81  eb18                   -jmp 0x4abd9b
    goto L_0x004abd9b;
L_0x004abd83:
    // 004abd83  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004abd85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abd86  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abd87  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abd88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abd89  2eff15e8744b00         -call dword ptr cs:[0x4b74e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945128) /* 0x4b74e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abd90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abd92  7507                   -jne 0x4abd9b
    if (!cpu.flags.zf)
    {
        goto L_0x004abd9b;
    }
    // 004abd94  e869e2feff             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
    // 004abd99  eba2                   -jmp 0x4abd3d
    goto L_0x004abd3d;
L_0x004abd9b:
    // 004abd9b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004abd9d:
    // 004abd9d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abda0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abda1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abda2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abda3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abda4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abda4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abda5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abda6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abda7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abda8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004abdaa  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004abdac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abdae  7c08                   -jl 0x4abdb8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004abdb8;
    }
    // 004abdb0  3b05e4f74c00           +cmp eax, dword ptr [0x4cf7e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044196) /* 0x4cf7e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abdb6  7614                   -jbe 0x4abdcc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004abdcc;
    }
L_0x004abdb8:
    // 004abdb8  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004abdbd  e83ee3feff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 004abdc2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004abdc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdc8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdc9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdcb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abdcc:
    // 004abdcc  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abdd2  a1d4f74c00             -mov eax, dword ptr [0x4cf7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004abdd7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004abdd9  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004abddc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abddd  2eff1594744b00         -call dword ptr cs:[0x4b7494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945044) /* 0x4b7494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abde4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abde6  750a                   -jne 0x4abdf2
    if (!cpu.flags.zf)
    {
        goto L_0x004abdf2;
    }
    // 004abde8  e815e2feff             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
    // 004abded  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x004abdf2:
    // 004abdf2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abdf4  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abdfa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abdfc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdfd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdfe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abe00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abe01(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abe01  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abe02  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004abe04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abe05  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abe06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abe07  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004abe0a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004abe0c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004abe0e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abe10  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 004abe13  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004abe16  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004abe19  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004abe1c  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 004abe1e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004abe23  83f847                 +cmp eax, 0x47
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abe26  7523                   -jne 0x4abe4b
    if (!cpu.flags.zf)
    {
        goto L_0x004abe4b;
    }
    // 004abe28  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004abe2a  7505                   -jne 0x4abe31
    if (!cpu.flags.zf)
    {
        goto L_0x004abe31;
    }
    // 004abe2c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004abe31:
    // 004abe31  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 004abe38  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004abe3b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abe40  83ef02                 +sub edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004abe43  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 004abe46  897dc0                 -mov dword ptr [ebp - 0x40], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 004abe49  eb1f                   -jmp 0x4abe6a
    goto L_0x004abe6a;
L_0x004abe4b:
    // 004abe4b  83f845                 +cmp eax, 0x45
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abe4e  750d                   -jne 0x4abe5d
    if (!cpu.flags.zf)
    {
        goto L_0x004abe5d;
    }
    // 004abe50  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004abe55  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 004abe58  897db8                 -mov dword ptr [ebp - 0x48], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 004abe5b  eb0d                   -jmp 0x4abe6a
    goto L_0x004abe6a;
L_0x004abe5d:
    // 004abe5d  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004abe62  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abe64  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 004abe67  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x004abe6a:
    // 004abe6a  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 004abe6e  7404                   -je 0x4abe74
    if (cpu.flags.zf)
    {
        goto L_0x004abe74;
    }
    // 004abe70  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x004abe74:
    // 004abe74  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004abe76  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004abe79  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004abe7b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004abe7d  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004abe80  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004abe83  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004abe86  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004abe89  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004abe8c  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004abe8f  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 004abe91  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004abe93  83fbff                 +cmp ebx, -1
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
    // 004abe96  7505                   -jne 0x4abe9d
    if (!cpu.flags.zf)
    {
        goto L_0x004abe9d;
    }
    // 004abe98  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x004abe9d:
    // 004abe9d  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004abea0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abea2  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 004abea5  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 004abea8  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004abeab  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004abeae  e8e7610000             -call 0x4b209a
    cpu.esp -= 4;
    sub_4b209a(app, cpu);
    if (cpu.terminate) return;
    // 004abeb3  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004abeb6  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004abeb9  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004abebc  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004abebf  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004abec2  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004abec5  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004abec8  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004abecb  837dc800               +cmp dword ptr [ebp - 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abecf  7d0f                   -jge 0x4abee0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004abee0;
    }
    // 004abed1  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004abed4  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004abed7  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004abeda  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 004abede  eb29                   -jmp 0x4abf09
    goto L_0x004abf09;
L_0x004abee0:
    // 004abee0  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004abee3  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004abee6  740f                   -je 0x4abef7
    if (cpu.flags.zf)
    {
        goto L_0x004abef7;
    }
    // 004abee8  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004abeeb  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004abeee  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004abef1  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 004abef5  eb12                   -jmp 0x4abf09
    goto L_0x004abf09;
L_0x004abef7:
    // 004abef7  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004abefa  740d                   -je 0x4abf09
    if (cpu.flags.zf)
    {
        goto L_0x004abf09;
    }
    // 004abefc  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004abeff  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004abf02  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004abf05  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x004abf09:
    // 004abf09  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004abf0b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abf0d  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004abf10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf13  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abf15(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abf15  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abf16  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004abf18  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abf1a  e8c56c0000             -call 0x4b2be4
    cpu.esp -= 4;
    sub_4b2be4(app, cpu);
    if (cpu.terminate) return;
    // 004abf1f  dd1b                   -fstp qword ptr [ebx]
    app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004abf21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4abf30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abf30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abf31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abf32  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004abf35  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004abf38  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004abf3a  e8316d0000             -call 0x4b2c70
    cpu.esp -= 4;
    sub_4b2c70(app, cpu);
    if (cpu.terminate) return;
    // 004abf3f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004abf41  e82a6d0000             -call 0x4b2c70
    cpu.esp -= 4;
    sub_4b2c70(app, cpu);
    if (cpu.terminate) return;
    // 004abf46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abf49(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abf49  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abf4a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abf4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abf4c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004abf4e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004abf50  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004abf53  3b5a04                 +cmp ebx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abf56  730c                   -jae 0x4abf64
    if (!cpu.flags.cf)
    {
        goto L_0x004abf64;
    }
    // 004abf58  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004abf5a  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004abf5d  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004abf5f  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004abf61  ff4010                 -inc dword ptr [eax + 0x10]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
L_0x004abf64:
    // 004abf64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abf68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abf68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abf69  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004abf6c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004abf6e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004abf70  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004abf72  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004abf74  48                     -dec eax
    (cpu.eax)--;
    // 004abf75  b949bf4a00             -mov ecx, 0x4abf49
    cpu.ecx = 4898633 /*0x4abf49*/;
    // 004abf7a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004abf7e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004abf80  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004abf83  e88f9fffff             -call 0x4a5f17
    cpu.esp -= 4;
    sub_4a5f17(app, cpu);
    if (cpu.terminate) return;
    // 004abf88  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 004abf8c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004abf8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abf91(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abf91  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abf92  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abf93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abf94  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abf97  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004abf9b  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004abf9d  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004abfa1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004abfa5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004abfa8  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004abfac  e8b7ffffff             -call 0x4abf68
    cpu.esp -= 4;
    sub_4abf68(app, cpu);
    if (cpu.terminate) return;
    // 004abfb1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abfb4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfb6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abfb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abfb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abfb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abfba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abfbb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abfbc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abfbf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004abfc1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004abfc3  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004abfc5  eb01                   -jmp 0x4abfc8
    goto L_0x004abfc8;
L_0x004abfc7:
    // 004abfc7  43                     -inc ebx
    (cpu.ebx)++;
L_0x004abfc8:
    // 004abfc8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004abfca  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004abfcc  40                     -inc eax
    (cpu.eax)++;
    // 004abfcd  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004abfcf  75f6                   -jne 0x4abfc7
    if (!cpu.flags.zf)
    {
        goto L_0x004abfc7;
    }
    // 004abfd1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004abfd3  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004abfd7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abfd8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abfd9  a1d4f74c00             -mov eax, dword ptr [0x4cf7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 004abfde  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abfdf  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004abfe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abfe3  2eff15dc754b00         -call dword ptr cs:[0x4b75dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945372) /* 0x4b75dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abfea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abfec  e93d1bffff             -jmp 0x49db2e
    return sub_49db2e(app, cpu);
}

/* align: skip  */
void Application::sub_4abff1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abff1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abff2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abff3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004abff5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004abff7  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004abff9  e8b969ffff             -call 0x4a29b7
    cpu.esp -= 4;
    sub_4a29b7(app, cpu);
    if (cpu.terminate) return;
    // 004abffe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac000  7509                   -jne 0x4ac00b
    if (!cpu.flags.zf)
    {
        goto L_0x004ac00b;
    }
    // 004ac002  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004ac004  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ac006  e8adffffff             -call 0x4abfb8
    cpu.esp -= 4;
    sub_4abfb8(app, cpu);
    if (cpu.terminate) return;
L_0x004ac00b:
    // 004ac00b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac00c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac00d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac00e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac00e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac00f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac010  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ac012  8b1528ce4c00           -mov edx, dword ptr [0x4cce28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033512) /* 0x4cce28 */);
    // 004ac018  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ac01b  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004ac01e  e8ba69ffff             -call 0x4a29dd
    cpu.esp -= 4;
    sub_4a29dd(app, cpu);
    if (cpu.terminate) return;
    // 004ac023  39c2                   +cmp edx, eax
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
    // 004ac025  7316                   -jae 0x4ac03d
    if (!cpu.flags.cf)
    {
        goto L_0x004ac03d;
    }
    // 004ac027  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac028  e8ff69ffff             -call 0x4a2a2c
    cpu.esp -= 4;
    sub_4a2a2c(app, cpu);
    if (cpu.terminate) return;
    // 004ac02d  a128ce4c00             -mov eax, dword ptr [0x4cce28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033512) /* 0x4cce28 */);
    // 004ac032  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ac035  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004ac037  29c4                   +sub esp, eax
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
    // 004ac039  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ac03b  eb02                   -jmp 0x4ac03f
    goto L_0x004ac03f;
L_0x004ac03d:
    // 004ac03d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ac03f:
    // 004ac03f  8b1528ce4c00           -mov edx, dword ptr [0x4cce28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033512) /* 0x4cce28 */);
    // 004ac045  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac047  a32cce4c00             -mov dword ptr [0x4cce2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5033516) /* 0x4cce2c */) = cpu.eax;
    // 004ac04c  e8c76c0000             -call 0x4b2d18
    cpu.esp -= 4;
    sub_4b2d18(app, cpu);
    if (cpu.terminate) return;
    // 004ac051  8b15e8945400           -mov edx, dword ptr [0x5494e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5543144) /* 0x5494e8 */);
    // 004ac057  a1e4945400             -mov eax, dword ptr [0x5494e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5543140) /* 0x5494e4 */);
    // 004ac05c  e87f4bfaff             -call 0x450be0
    cpu.esp -= 4;
    sub_450be0(app, cpu);
    if (cpu.terminate) return;
    // 004ac061  e83f44feff             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 004ac066  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ac068  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac069  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac06a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4ac06c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac06c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac06d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac06d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac06f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac072  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac078  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac07a  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac07d  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac080  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac086  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac088  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac089(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac089  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac08b  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac08d  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004ac093  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac096  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac09b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac09d  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac0a0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac0a3  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac0a9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac0ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac0ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac0ac  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac0ae  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac0b0  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac0b6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac0b9  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac0be  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac0c0  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac0c3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ac0c5  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac0c8  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac0ce  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ac0d1  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac0d7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac0d9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac0db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac0dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac0dc  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac0de  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac0e3  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac0e6  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ac0e8  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac0ee  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac0f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac0f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac0f1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac0f3  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ac0f6  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac0fc  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac0ff  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac104  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac106  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac109  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ac10b  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ac10d  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac113  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ac116  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac11c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac11e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac120  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac121(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac121  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ac124  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac129  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac12c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ac12e  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ac130  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004ac136  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004ac139  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac13f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac141  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac143  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac144(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac144  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ac147  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac14c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac14f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ac151  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ac154  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac15a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac15c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac15e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac15f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac15f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac161  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac164  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac16a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac16c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac16f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac172  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac178  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac17a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac17b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac17b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac17d  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac17f  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004ac185  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac188  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac18d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac18f  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac192  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac195  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac19b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac19d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac1a0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac1a3  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac1a9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac1ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac1ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac1ac  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac1ae  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac1b0  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac1b6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac1b9  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac1be  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac1c0  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac1c3  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac1c6  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac1cc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac1ce  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac1d1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac1d4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac1da  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac1dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac1dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac1dd  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac1df  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac1e4  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac1e7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ac1e9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac1ec  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac1f2  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ac1f5  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac1fb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac1fd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac1ff  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac202  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac205  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac20b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac20d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac20e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac20e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac210  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ac213  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac219  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac21c  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac221  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac223  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac226  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ac228  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac22e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac230  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004ac234  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac237  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac23d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac23f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac240  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ac243  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac248  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac24b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ac24d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ac24f  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac255  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ac258  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac25e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac260  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac262  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004ac266  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac269  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac26f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac271  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac272(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac272  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ac275  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac27a  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac27d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ac27f  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ac281  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004ac287  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004ac28a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac290  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac292  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac294  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004ac298  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac29b  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac2a1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac2a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac2a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac2a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac2a6  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac2a8  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004ac2ae  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac2b1  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac2b6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac2b8  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac2bb  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac2be  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac2c4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac2c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac2c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac2c7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac2c9  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac2cb  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac2d1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac2d4  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac2d9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac2db  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac2de  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac2e1  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac2e7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac2e9  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac2ec  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac2ef  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac2f5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac2f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac2f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac2f8  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac2fa  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac2ff  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac302  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac305  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac30b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac30d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac310  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac313  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac319  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac31b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac31c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac31c  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ac31e  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac323  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac326  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac329  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac32f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac331  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac334  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac337  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac33d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac33f  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004ac343  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac346  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac34c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac34e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac34f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac34f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac351  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ac354  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac35a  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac35d  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac362  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac364  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac367  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ac369  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac36c  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ac372  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ac375  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac37b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac37d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac37f  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac382  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac385  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac38b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac38d  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004ac391  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac394  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac39a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac39c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac39d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac39d  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ac3a0  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac3a5  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac3a8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ac3aa  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac3b0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac3b2  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ac3b5  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac3b8  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac3be  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac3c0  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004ac3c4  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ac3c7  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ac3cd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac3cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac3d0  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ac3d3  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac3d8  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac3db  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ac3dd  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ac3e3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac3e5  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004ac3e9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ac3ec  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ac3f2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac3f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
