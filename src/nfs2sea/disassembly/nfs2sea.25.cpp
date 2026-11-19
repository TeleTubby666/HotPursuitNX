#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x8b 0xc0 */
void Application::sub_49d990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d990);
    // 0049d990  e823000000             -call 0x49d9b8
    cpu.esp -= 4;
    sub_49d9b8(app, cpu);
    if (cpu.terminate) return;
    // 0049d995  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d997  7402                   -je 0x49d99b
    if (cpu.flags.zf)
    {
        goto L_0x0049d99b;
    }
    // 0049d999  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0049d99b:
    // 0049d99b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d99c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d99c);
    // 0049d99c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d99d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049d9a2  e811000000             -call 0x49d9b8
    cpu.esp -= 4;
    sub_49d9b8(app, cpu);
    if (cpu.terminate) return;
    // 0049d9a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d9ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d9ac);
    // 0049d9ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d9ad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d9af  e804000000             -call 0x49d9b8
    cpu.esp -= 4;
    sub_49d9b8(app, cpu);
    if (cpu.terminate) return;
    // 0049d9b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d9b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d9b8);
    // 0049d9b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d9b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d9ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d9bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d9bc  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049d9bf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d9c1  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049d9c5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049d9c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d9c9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049d9cd  e8526c0000             -call 0x4a4624
    cpu.esp -= 4;
    sub_4a4624(app, cpu);
    if (cpu.terminate) return;
    // 0049d9d2  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049d9d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d9d8  7419                   -je 0x49d9f3
    if (cpu.flags.zf)
    {
        goto L_0x0049d9f3;
    }
L_0x0049d9da:
    // 0049d9da  833d50dd4d0000         +cmp dword ptr [0x4ddd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102928) /* 0x4ddd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d9e1  0f85a1000000           -jne 0x49da88
    if (!cpu.flags.zf)
    {
        goto L_0x0049da88;
    }
    // 0049d9e7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049d9eb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049d9ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d9f3:
    // 0049d9f3  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049d9f7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049d9f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d9fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d9fc  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049da00  e84f9efeff             -call 0x487854
    cpu.esp -= 4;
    sub_487854(app, cpu);
    if (cpu.terminate) return;
    // 0049da05  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049da07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049da09  74cf                   -je 0x49d9da
    if (cpu.flags.zf)
    {
        goto L_0x0049d9da;
    }
    // 0049da0b  e8940f0000             -call 0x49e9a4
    cpu.esp -= 4;
    sub_49e9a4(app, cpu);
    if (cpu.terminate) return;
    // 0049da10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049da12  7540                   -jne 0x49da54
    if (!cpu.flags.zf)
    {
        goto L_0x0049da54;
    }
    // 0049da14  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049da16  7432                   -je 0x49da4a
    if (cpu.flags.zf)
    {
        goto L_0x0049da4a;
    }
    // 0049da18  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0049da1d  742b                   -je 0x49da4a
    if (cpu.flags.zf)
    {
        goto L_0x0049da4a;
    }
    // 0049da1f  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049da23  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049da27  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049da29  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049da2b  e8a46afeff             -call 0x4844d4
    cpu.esp -= 4;
    sub_4844d4(app, cpu);
    if (cpu.terminate) return;
    // 0049da30  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049da34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049da36  7412                   -je 0x49da4a
    if (cpu.flags.zf)
    {
        goto L_0x0049da4a;
    }
    // 0049da38  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049da3c  e88f6afeff             -call 0x4844d0
    cpu.esp -= 4;
    sub_4844d0(app, cpu);
    if (cpu.terminate) return;
    // 0049da41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049da43  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049da45  e836cffeff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
L_0x0049da4a:
    // 0049da4a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049da4d  e8fe9efeff             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 0049da52  eb86                   -jmp 0x49d9da
    goto L_0x0049d9da;
L_0x0049da54:
    // 0049da54  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049da58  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049da5a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049da5c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049da5e  e8716afeff             -call 0x4844d4
    cpu.esp -= 4;
    sub_4844d4(app, cpu);
    if (cpu.terminate) return;
    // 0049da63  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049da67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049da69  74df                   -je 0x49da4a
    if (cpu.flags.zf)
    {
        goto L_0x0049da4a;
    }
    // 0049da6b  e8606afeff             -call 0x4844d0
    cpu.esp -= 4;
    sub_4844d0(app, cpu);
    if (cpu.terminate) return;
    // 0049da70  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049da72  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049da74  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049da76  e8750e0000             -call 0x49e8f0
    cpu.esp -= 4;
    sub_49e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0049da7b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049da7e  e8cd9efeff             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 0049da83  e952ffffff             -jmp 0x49d9da
    goto L_0x0049d9da;
L_0x0049da88:
    // 0049da88  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049da8c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049da90  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049da92  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049da94  ff1550dd4d00           -call dword ptr [0x4ddd50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102928) /* 0x4ddd50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049da9a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049da9e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049daa2  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049daa5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daa6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daa7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daa8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daa9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49dab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049dab0);
    // 0049dab0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dab1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049dab3  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049daba  7410                   -je 0x49dacc
    if (cpu.flags.zf)
    {
        goto L_0x0049dacc;
    }
    // 0049dabc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049dabe  7c05                   -jl 0x49dac5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dac5;
    }
    // 0049dac0  83fa7f                 +cmp edx, 0x7f
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
    // 0049dac3  7e0e                   -jle 0x49dad3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049dad3;
    }
L_0x0049dac5:
    // 0049dac5  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049daca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dacb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dacc:
    // 0049dacc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049dad1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dad2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dad3:
    // 0049dad3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dad4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dad5  e886780000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 0049dada  bbb0bf5900             -mov ebx, 0x59bfb0
    cpu.ebx = 5881776 /*0x59bfb0*/;
    // 0049dadf  88150dc65900           -mov byte ptr [0x59c60d], dl
    app->getMemory<x86::reg8>(x86::reg32(5883405) /* 0x59c60d */) = cpu.dl;
    // 0049dae5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049dae7:
    // 0049dae7  807b0c01               +cmp byte ptr [ebx + 0xc], 1
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
    // 0049daeb  7519                   -jne 0x49db06
    if (!cpu.flags.zf)
    {
        goto L_0x0049db06;
    }
    // 0049daed  833b00                 +cmp dword ptr [ebx], 0
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
    // 0049daf0  7c14                   -jl 0x49db06
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049db06;
    }
    // 0049daf2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049daf4  e8f7b00000             -call 0x4a8bf0
    cpu.esp -= 4;
    sub_4a8bf0(app, cpu);
    if (cpu.terminate) return;
    // 0049daf9  8b532e                 -mov edx, dword ptr [ebx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(46) /* 0x2e */);
    // 0049dafc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049dafe  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049db01  e89eb9feff             -call 0x4894a4
    cpu.esp -= 4;
    sub_4894a4(app, cpu);
    if (cpu.terminate) return;
L_0x0049db06:
    // 0049db06  41                     -inc ecx
    (cpu.ecx)++;
    // 0049db07  83c360                 -add ebx, 0x60
    (cpu.ebx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049db0a  83f910                 +cmp ecx, 0x10
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
    // 0049db0d  7cd8                   -jl 0x49dae7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dae7;
    }
    // 0049db0f  e860780000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049db14  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049db16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db18  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49db20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049db20);
    // 0049db20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049db21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049db23:
    // 0049db23  8b82b0bf5900           -mov eax, dword ptr [edx + 0x59bfb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5881776) /* 0x59bfb0 */);
    // 0049db29  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049db2c  e80fbdfeff             -call 0x489840
    cpu.esp -= 4;
    sub_489840(app, cpu);
    if (cpu.terminate) return;
    // 0049db31  81fa00060000           +cmp edx, 0x600
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
    // 0049db37  75ea                   -jne 0x49db23
    if (!cpu.flags.zf)
    {
        goto L_0x0049db23;
    }
    // 0049db39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49db40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049db40);
    // 0049db40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049db41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049db42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049db43  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049db45  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049db47  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049db49  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049db4b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049db4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049db51  7c05                   -jl 0x49db58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049db58;
    }
    // 0049db53  83f801                 +cmp eax, 1
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
    // 0049db56  7c0b                   -jl 0x49db63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049db63;
    }
L_0x0049db58:
    // 0049db58  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0049db5d:
    // 0049db5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db60  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049db63:
    // 0049db63  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0049db66  05a0bf5900             -add eax, 0x59bfa0
    (cpu.eax) += x86::reg32(x86::sreg32(5881760 /*0x59bfa0*/));
    // 0049db6b  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0049db6d  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049db70  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049db72  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049db75  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049db77  e8a8affeff             -call 0x488b24
    cpu.esp -= 4;
    sub_488b24(app, cpu);
    if (cpu.terminate) return;
    // 0049db7c  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049db83  7419                   -je 0x49db9e
    if (cpu.flags.zf)
    {
        goto L_0x0049db9e;
    }
    // 0049db85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049db87  7cd4                   -jl 0x49db5d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049db5d;
    }
L_0x0049db89:
    // 0049db89  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049db8b  7502                   -jne 0x49db8f
    if (!cpu.flags.zf)
    {
        goto L_0x0049db8f;
    }
    // 0049db8d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0049db8f:
    // 0049db8f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049db91  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049db93  e810000000             -call 0x49dba8
    cpu.esp -= 4;
    sub_49dba8(app, cpu);
    if (cpu.terminate) return;
    // 0049db98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db9b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049db9e:
    // 0049db9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049dba0  7de7                   -jge 0x49db89
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049db89;
    }
    // 0049dba2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dba3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dba4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dba5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49dba8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049dba8);
    // 0049dba8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dba9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049dbab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049dbad  7c0e                   -jl 0x49dbbd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dbbd;
    }
    // 0049dbaf  83f801                 +cmp eax, 1
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
    // 0049dbb2  7d09                   -jge 0x49dbbd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dbbd;
    }
    // 0049dbb4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049dbb6  7c05                   -jl 0x49dbbd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dbbd;
    }
    // 0049dbb8  83fa7f                 +cmp edx, 0x7f
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
    // 0049dbbb  7e07                   -jle 0x49dbc4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049dbc4;
    }
L_0x0049dbbd:
    // 0049dbbd  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0049dbc2:
    // 0049dbc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dbc3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dbc4:
    // 0049dbc4  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0049dbc7  8990a4bf5900           -mov dword ptr [eax + 0x59bfa4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881764) /* 0x59bfa4 */) = cpu.edx;
    // 0049dbcd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049dbcf  e85caffeff             -call 0x488b30
    cpu.esp -= 4;
    sub_488b30(app, cpu);
    if (cpu.terminate) return;
    // 0049dbd4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049dbd6  7cea                   -jl 0x49dbc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dbc2;
    }
    // 0049dbd8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dbd9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dbda  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dbdb  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0049dbdd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049dbdf:
    // 0049dbdf  6bc160                 -imul eax, ecx, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 0049dbe2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049dbe4  8b9ee6bf5900           -mov ebx, dword ptr [esi + 0x59bfe6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5881830) /* 0x59bfe6 */);
    // 0049dbea  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049dbed  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0049dbf0  8b80b0bf5900           -mov eax, dword ptr [eax + 0x59bfb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881776) /* 0x59bfb0 */);
    // 0049dbf6  41                     -inc ecx
    (cpu.ecx)++;
    // 0049dbf7  e8e42f0100             -call 0x4b0be0
    cpu.esp -= 4;
    sub_4b0be0(app, cpu);
    if (cpu.terminate) return;
    // 0049dbfc  83f910                 +cmp ecx, 0x10
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
    // 0049dbff  7cde                   -jl 0x49dbdf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dbdf;
    }
    // 0049dc01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dc03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49dc10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049dc10);
    // 0049dc10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dc11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dc12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dc13  66833d48d44d0000       +cmp word ptr [0x4dd448], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5100616) /* 0x4dd448 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049dc1b  0f8cc3000000           -jl 0x49dce4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dce4;
    }
    // 0049dc21  0fbf05b8d34d00         -movsx eax, word ptr [0x4dd3b8]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */)));
    // 0049dc28  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049dc2b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049dc2d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049dc30  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049dc32  8b1554d44d00           -mov edx, dword ptr [0x4dd454]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100628) /* 0x4dd454 */);
    // 0049dc38  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049dc3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049dc3c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049dc3e  a150d44d00             -mov eax, dword ptr [0x4dd450]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100624) /* 0x4dd450 */);
    // 0049dc43  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0049dc46  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049dc4b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049dc4e  0fbf1548d44d00         -movsx edx, word ptr [0x4dd448]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5100616) /* 0x4dd448 */)));
    // 0049dc55  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049dc57  8b15c0d34d00           -mov edx, dword ptr [0x4dd3c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100480) /* 0x4dd3c0 */);
    // 0049dc5d  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0049dc60  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049dc62  66a3b8d34d00           -mov word ptr [0x4dd3b8], ax
    app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */) = cpu.ax;
    // 0049dc68  a14cd44d00             -mov eax, dword ptr [0x4dd44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100620) /* 0x4dd44c */);
    // 0049dc6d  a348d44d00             -mov dword ptr [0x4dd448], eax
    app->getMemory<x86::reg32>(x86::reg32(5100616) /* 0x4dd448 */) = cpu.eax;
    // 0049dc72  66c7054cd44d00ffff     -mov word ptr [0x4dd44c], 0xffff
    app->getMemory<x86::reg16>(x86::reg32(5100620) /* 0x4dd44c */) = 65535 /*0xffff*/;
    // 0049dc7b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dc7d  66890d4ed44d00         -mov word ptr [0x4dd44e], cx
    app->getMemory<x86::reg16>(x86::reg32(5100622) /* 0x4dd44e */) = cpu.cx;
L_0x0049dc84:
    // 0049dc84  ff05bcd34d00           -inc dword ptr [0x4dd3bc]
    (app->getMemory<x86::reg32>(x86::reg32(5100476) /* 0x4dd3bc */))++;
    // 0049dc8a  0fbf05b8d34d00         -movsx eax, word ptr [0x4dd3b8]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */)));
    // 0049dc91  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049dc94  8b15c4d34d00           -mov edx, dword ptr [0x4dd3c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100484) /* 0x4dd3c4 */);
    // 0049dc9a  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049dc9f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049dca1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049dca3  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049dca5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049dca7  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049dcae  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049dcb0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049dcb2  b8c8d34d00             -mov eax, 0x4dd3c8
    cpu.eax = 5100488 /*0x4dd3c8*/;
    // 0049dcb7  e8307dffff             -call 0x4959ec
    cpu.esp -= 4;
    sub_4959ec(app, cpu);
    if (cpu.terminate) return;
    // 0049dcbc  0fbf05b8d34d00         -movsx eax, word ptr [0x4dd3b8]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */)));
    // 0049dcc3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049dcc6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049dcc8  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049dccb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049dccd  8b1554d44d00           -mov edx, dword ptr [0x4dd454]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100628) /* 0x4dd454 */);
    // 0049dcd3  807c020100             +cmp byte ptr [edx + eax + 1], 0
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
    // 0049dcd8  0f869a000000           -jbe 0x49dd78
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049dd78;
    }
L_0x0049dcde:
    // 0049dcde  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dce0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dce1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dce2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dce3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dce4:
    // 0049dce4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049dce6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049dce8:
    // 0049dce8  0fbf0db8d34d00         -movsx ecx, word ptr [0x4dd3b8]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */)));
    // 0049dcef  6bc91c                 -imul ecx, ecx, 0x1c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0049dcf2  8b1d54d44d00           -mov ebx, dword ptr [0x4dd454]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5100628) /* 0x4dd454 */);
    // 0049dcf8  8a4c1901               -mov cl, byte ptr [ecx + ebx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.ebx * 1);
    // 0049dcfc  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049dd02  39ca                   +cmp edx, ecx
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
    // 0049dd04  0f8d7affffff           -jge 0x49dc84
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dc84;
    }
    // 0049dd0a  0fbf0db8d34d00         -movsx ecx, word ptr [0x4dd3b8]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */)));
    // 0049dd11  6bc91c                 -imul ecx, ecx, 0x1c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0049dd14  8b1d54d44d00           -mov ebx, dword ptr [0x4dd454]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5100628) /* 0x4dd454 */);
    // 0049dd1a  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dd1c  8a1dbad34d00           -mov bl, byte ptr [0x4dd3ba]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5100474) /* 0x4dd3ba */);
    // 0049dd22  3a5c0104               +cmp bl, byte ptr [ecx + eax + 4]
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
    // 0049dd26  7d06                   -jge 0x49dd2e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dd2e;
    }
L_0x0049dd28:
    // 0049dd28  83c003                 +add eax, 3
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
    // 0049dd2b  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049dd2c  ebba                   -jmp 0x49dce8
    goto L_0x0049dce8;
L_0x0049dd2e:
    // 0049dd2e  0fbf1db8d34d00         -movsx ebx, word ptr [0x4dd3b8]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */)));
    // 0049dd35  6bdb1c                 -imul ebx, ebx, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0049dd38  8b0d54d44d00           -mov ecx, dword ptr [0x4dd454]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100628) /* 0x4dd454 */);
    // 0049dd3e  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dd40  8a1dbad34d00           -mov bl, byte ptr [0x4dd3ba]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5100474) /* 0x4dd3ba */);
    // 0049dd46  3a5c0105               +cmp bl, byte ptr [ecx + eax + 5]
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
    // 0049dd4a  7fdc                   -jg 0x49dd28
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049dd28;
    }
    // 0049dd4c  0fbf15b8d34d00         -movsx edx, word ptr [0x4dd3b8]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */)));
    // 0049dd53  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049dd56  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049dd58  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0049dd5b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dd5d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049dd5f  8b1554d44d00           -mov edx, dword ptr [0x4dd454]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100628) /* 0x4dd454 */);
    // 0049dd65  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dd67  8a440206               -mov al, byte ptr [edx + eax + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */ + cpu.eax * 1);
    // 0049dd6b  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 0049dd6d  66a3b8d34d00           -mov word ptr [0x4dd3b8], ax
    app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */) = cpu.ax;
    // 0049dd73  e90cffffff             -jmp 0x49dc84
    goto L_0x0049dc84;
L_0x0049dd78:
    // 0049dd78  66833d48d44d0000       +cmp word ptr [0x4dd448], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5100616) /* 0x4dd448 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049dd80  0f8d58ffffff           -jge 0x49dcde
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dcde;
    }
    // 0049dd86  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dd88  890d80da4d00           -mov dword ptr [0x4dda80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102208) /* 0x4dda80 */) = cpu.ecx;
    // 0049dd8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dd90  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49dd94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049dd94);
    // 0049dd94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dd95  e8f682ffff             -call 0x496090
    cpu.esp -= 4;
    sub_496090(app, cpu);
    if (cpu.terminate) return;
    // 0049dd9a  3b05bcd34d00           +cmp eax, dword ptr [0x4dd3bc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5100476) /* 0x4dd3bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dda0  7d02                   -jge 0x49dda4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dda4;
    }
L_0x0049dda2:
    // 0049dda2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dda3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dda4:
    // 0049dda4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049dda6  668b15b6d34d00         -mov dx, word ptr [0x4dd3b6]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5100470) /* 0x4dd3b6 */);
    // 0049ddad  e8767effff             -call 0x495c28
    cpu.esp -= 4;
    sub_495c28(app, cpu);
    if (cpu.terminate) return;
    // 0049ddb2  39d0                   +cmp eax, edx
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
    // 0049ddb4  7dec                   -jge 0x49dda2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dda2;
    }
    // 0049ddb6  e855feffff             -call 0x49dc10
    cpu.esp -= 4;
    sub_49dc10(app, cpu);
    if (cpu.terminate) return;
    // 0049ddbb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddbc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49ddc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ddc0);
    // 0049ddc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ddc2  7506                   -jne 0x49ddca
    if (!cpu.flags.zf)
    {
        goto L_0x0049ddca;
    }
    // 0049ddc4  66a1b4d34d00           -mov ax, word ptr [0x4dd3b4]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5100468) /* 0x4dd3b4 */);
L_0x0049ddca:
    // 0049ddca  66a3b6d34d00           -mov word ptr [0x4dd3b6], ax
    app->getMemory<x86::reg16>(x86::reg32(5100470) /* 0x4dd3b6 */) = cpu.ax;
    // 0049ddd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49ddd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ddd4);
    // 0049ddd4  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049dddb  7422                   -je 0x49ddff
    if (cpu.flags.zf)
    {
        goto L_0x0049ddff;
    }
    // 0049dddd  833d50d44d0000         +cmp dword ptr [0x4dd450], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100624) /* 0x4dd450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dde4  751f                   -jne 0x49de05
    if (!cpu.flags.zf)
    {
        goto L_0x0049de05;
    }
    // 0049dde6  a350d44d00             -mov dword ptr [0x4dd450], eax
    app->getMemory<x86::reg32>(x86::reg32(5100624) /* 0x4dd450 */) = cpu.eax;
    // 0049ddeb  813850464478           +cmp dword ptr [eax], 0x78444650
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
    // 0049ddf1  7518                   -jne 0x49de0b
    if (!cpu.flags.zf)
    {
        goto L_0x0049de0b;
    }
    // 0049ddf3  80780400               +cmp byte ptr [eax + 4], 0
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
    // 0049ddf7  7418                   -je 0x49de11
    if (cpu.flags.zf)
    {
        goto L_0x0049de11;
    }
    // 0049ddf9  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 0049ddfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ddff:
    // 0049ddff  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049de04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049de05:
    // 0049de05  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049de0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049de0b:
    // 0049de0b  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0049de10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049de11:
    // 0049de11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049de12  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049de13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049de14  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049de17  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049de19  891554d44d00           -mov dword ptr [0x4dd454], edx
    app->getMemory<x86::reg32>(x86::reg32(5100628) /* 0x4dd454 */) = cpu.edx;
    // 0049de1f  8a4806                 -mov cl, byte ptr [eax + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0049de22  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0049de25  8d14cd00000000         -lea edx, [ecx*8]
    cpu.edx = x86::reg32(cpu.ecx * 8);
    // 0049de2c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049de2e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049de30  8b1554d44d00           -mov edx, dword ptr [0x4dd454]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100628) /* 0x4dd454 */);
    // 0049de36  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049de38  8915c0d34d00           -mov dword ptr [0x4dd3c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5100480) /* 0x4dd3c0 */) = cpu.edx;
    // 0049de3e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049de40  8a500b                 -mov dl, byte ptr [eax + 0xb]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 0049de43  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0049de46  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049de4b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049de4e  8b15c0d34d00           -mov edx, dword ptr [0x4dd3c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100480) /* 0x4dd3c0 */);
    // 0049de54  bbecdf4900             -mov ebx, 0x49dfec
    cpu.ebx = 4841452 /*0x49dfec*/;
    // 0049de59  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049de5b  891da0da4d00           -mov dword ptr [0x4ddaa0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5102240) /* 0x4ddaa0 */) = cpu.ebx;
    // 0049de61  8915c4d34d00           -mov dword ptr [0x4dd3c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5100484) /* 0x4dd3c4 */) = cpu.edx;
    // 0049de67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049de69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049de6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049de6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049de6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49de70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049de70);
    // 0049de70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049de71  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049de74  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049de76  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049de7d  0f84bc000000           -je 0x49df3f
    if (cpu.flags.zf)
    {
        goto L_0x0049df3f;
    }
    // 0049de83  a358d44d00             -mov dword ptr [0x4dd458], eax
    app->getMemory<x86::reg32>(x86::reg32(5100632) /* 0x4dd458 */) = cpu.eax;
    // 0049de88  66891db4d34d00         -mov word ptr [0x4dd3b4], bx
    app->getMemory<x86::reg16>(x86::reg32(5100468) /* 0x4dd3b4 */) = cpu.bx;
    // 0049de8f  66891db6d34d00         -mov word ptr [0x4dd3b6], bx
    app->getMemory<x86::reg16>(x86::reg32(5100470) /* 0x4dd3b6 */) = cpu.bx;
    // 0049de96  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0049de9b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049de9d:
    // 0049de9d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049dea0  66899044d44d00         -mov word ptr [eax + 0x4dd444], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5100612) /* 0x4dd444 */) = cpu.dx;
    // 0049dea7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dea9  66899846d44d00         -mov word ptr [eax + 0x4dd446], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5100614) /* 0x4dd446 */) = cpu.bx;
    // 0049deb0  83f808                 +cmp eax, 8
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
    // 0049deb3  75e8                   -jne 0x49de9d
    if (!cpu.flags.zf)
    {
        goto L_0x0049de9d;
    }
    // 0049deb5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049deb6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049deb7  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0049deb9  8835bad34d00           -mov byte ptr [0x4dd3ba], dh
    app->getMemory<x86::reg8>(x86::reg32(5100474) /* 0x4dd3ba */) = cpu.dh;
    // 0049debf  a150d44d00             -mov eax, dword ptr [0x4dd450]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100624) /* 0x4dd450 */);
    // 0049dec4  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0049dec7  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049dec9  66a3b8d34d00           -mov word ptr [0x4dd3b8], ax
    app->getMemory<x86::reg16>(x86::reg32(5100472) /* 0x4dd3b8 */) = cpu.ax;
    // 0049decf  e8bc81ffff             -call 0x496090
    cpu.esp -= 4;
    sub_496090(app, cpu);
    if (cpu.terminate) return;
    // 0049ded4  a3bcd34d00             -mov dword ptr [0x4dd3bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5100476) /* 0x4dd3bc */) = cpu.eax;
    // 0049ded9  bfc8d34d00             -mov edi, 0x4dd3c8
    cpu.edi = 5100488 /*0x4dd3c8*/;
    // 0049dede  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049dee0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049dee1:
    // 0049dee1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049dee3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049dee5  3c00                   +cmp al, 0
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
    // 0049dee7  7410                   -je 0x49def9
    if (cpu.flags.zf)
    {
        goto L_0x0049def9;
    }
    // 0049dee9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049deec  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049deef  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049def2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049def5  3c00                   +cmp al, 0
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
    // 0049def7  75e8                   -jne 0x49dee1
    if (!cpu.flags.zf)
    {
        goto L_0x0049dee1;
    }
L_0x0049def9:
    // 0049def9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049defa  ff05bcd34d00           -inc dword ptr [0x4dd3bc]
    (app->getMemory<x86::reg32>(x86::reg32(5100476) /* 0x4dd3bc */))++;
    // 0049df00  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049df04  e87774feff             -call 0x485380
    cpu.esp -= 4;
    sub_485380(app, cpu);
    if (cpu.terminate) return;
    // 0049df09  a158d44d00             -mov eax, dword ptr [0x4dd458]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100632) /* 0x4dd458 */);
    // 0049df0e  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049df12  e8b979ffff             -call 0x4958d0
    cpu.esp -= 4;
    sub_4958d0(app, cpu);
    if (cpu.terminate) return;
    // 0049df17  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049df19  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049df1b  bbc0dd4900             -mov ebx, 0x49ddc0
    cpu.ebx = 4840896 /*0x49ddc0*/;
    // 0049df20  e8c77affff             -call 0x4959ec
    cpu.esp -= 4;
    sub_4959ec(app, cpu);
    if (cpu.terminate) return;
    // 0049df25  b994dd4900             -mov ecx, 0x49dd94
    cpu.ecx = 4840852 /*0x49dd94*/;
    // 0049df2a  891de0cf4d00           -mov dword ptr [0x4dcfe0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */) = cpu.ebx;
    // 0049df30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049df32  890d80da4d00           -mov dword ptr [0x4dda80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102208) /* 0x4dda80 */) = cpu.ecx;
    // 0049df38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049df39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049df3a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049df3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049df3e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049df3f:
    // 0049df3f  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049df44  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049df47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049df48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49df4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049df4c);
    // 0049df4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049df4e  7c05                   -jl 0x49df55
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049df55;
    }
    // 0049df50  83f87f                 +cmp eax, 0x7f
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
    // 0049df53  7e06                   -jle 0x49df5b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049df5b;
    }
L_0x0049df55:
    // 0049df55  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049df5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049df5b:
    // 0049df5b  a2bad34d00             -mov byte ptr [0x4dd3ba], al
    app->getMemory<x86::reg8>(x86::reg32(5100474) /* 0x4dd3ba */) = cpu.al;
    // 0049df60  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049df62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49df64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049df64);
    // 0049df64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049df65  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049df6c  7437                   -je 0x49dfa5
    if (cpu.flags.zf)
    {
        goto L_0x0049dfa5;
    }
    // 0049df6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049df70  7c3a                   -jl 0x49dfac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dfac;
    }
    // 0049df72  8b0d50d44d00           -mov ecx, dword ptr [0x4dd450]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100624) /* 0x4dd450 */);
    // 0049df78  8a4907                 -mov cl, byte ptr [ecx + 7]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0049df7b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049df81  39c8                   +cmp eax, ecx
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
    // 0049df83  7d27                   -jge 0x49dfac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dfac;
    }
    // 0049df85  83fa01                 +cmp edx, 1
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
    // 0049df88  7429                   -je 0x49dfb3
    if (cpu.flags.zf)
    {
        goto L_0x0049dfb3;
    }
    // 0049df8a  66833d4ad44d0001       +cmp word ptr [0x4dd44a], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5100618) /* 0x4dd44a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049df92  7544                   -jne 0x49dfd8
    if (!cpu.flags.zf)
    {
        goto L_0x0049dfd8;
    }
    // 0049df94  66a34cd44d00           -mov word ptr [0x4dd44c], ax
    app->getMemory<x86::reg16>(x86::reg32(5100620) /* 0x4dd44c */) = cpu.ax;
    // 0049df9a  6689154ed44d00         -mov word ptr [0x4dd44e], dx
    app->getMemory<x86::reg16>(x86::reg32(5100622) /* 0x4dd44e */) = cpu.dx;
    // 0049dfa1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dfa3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dfa4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dfa5:
    // 0049dfa5  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049dfaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dfab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dfac:
    // 0049dfac  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049dfb1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dfb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dfb3:
    // 0049dfb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dfb4  66a348d44d00           -mov word ptr [0x4dd448], ax
    app->getMemory<x86::reg16>(x86::reg32(5100616) /* 0x4dd448 */) = cpu.ax;
    // 0049dfba  6689154ad44d00         -mov word ptr [0x4dd44a], dx
    app->getMemory<x86::reg16>(x86::reg32(5100618) /* 0x4dd44a */) = cpu.dx;
    // 0049dfc1  66c7054cd44d00ffff     -mov word ptr [0x4dd44c], 0xffff
    app->getMemory<x86::reg16>(x86::reg32(5100620) /* 0x4dd44c */) = 65535 /*0xffff*/;
    // 0049dfca  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049dfcc  6689354ed44d00         -mov word ptr [0x4dd44e], si
    app->getMemory<x86::reg16>(x86::reg32(5100622) /* 0x4dd44e */) = cpu.si;
    // 0049dfd3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dfd4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dfd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dfd7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dfd8:
    // 0049dfd8  66a348d44d00           -mov word ptr [0x4dd448], ax
    app->getMemory<x86::reg16>(x86::reg32(5100616) /* 0x4dd448 */) = cpu.ax;
    // 0049dfde  6689154ad44d00         -mov word ptr [0x4dd44a], dx
    app->getMemory<x86::reg16>(x86::reg32(5100618) /* 0x4dd44a */) = cpu.dx;
    // 0049dfe5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dfe7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dfe8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49dfec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049dfec);
    // 0049dfec  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049dff3  7506                   -jne 0x49dffb
    if (!cpu.flags.zf)
    {
        goto L_0x0049dffb;
    }
    // 0049dff5  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049dffa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dffb:
    // 0049dffb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dffc  e88f79ffff             -call 0x495990
    cpu.esp -= 4;
    sub_495990(app, cpu);
    if (cpu.terminate) return;
    // 0049e001  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e003  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e005  891580da4d00           -mov dword ptr [0x4dda80], edx
    app->getMemory<x86::reg32>(x86::reg32(5102208) /* 0x4dda80 */) = cpu.edx;
    // 0049e00b  891550d44d00           -mov dword ptr [0x4dd450], edx
    app->getMemory<x86::reg32>(x86::reg32(5100624) /* 0x4dd450 */) = cpu.edx;
    // 0049e011  8915e0cf4d00           -mov dword ptr [0x4dcfe0], edx
    app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */) = cpu.edx;
    // 0049e017  8915a0da4d00           -mov dword ptr [0x4ddaa0], edx
    app->getMemory<x86::reg32>(x86::reg32(5102240) /* 0x4ddaa0 */) = cpu.edx;
    // 0049e01d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e01e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49e020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e020);
    // 0049e020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e022  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e023  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e024  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e027  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049e02a  e83d770000             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 0049e02f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e031  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e033  7c5a                   -jl 0x49e08f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e08f;
    }
    // 0049e035  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0049e03c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e03e  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049e041  81c2b0bf5900           -add edx, 0x59bfb0
    (cpu.edx) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 0049e047  0fb6723b               -movzx esi, byte ptr [edx + 0x3b]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 0049e04b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049e04d  0f8466000000           -je 0x49e0b9
    if (cpu.flags.zf)
    {
        goto L_0x0049e0b9;
    }
    // 0049e053  b9b0bf5900             -mov ecx, 0x59bfb0
    cpu.ecx = 5881776 /*0x59bfb0*/;
    // 0049e058  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e05b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049e05d:
    // 0049e05d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e05f  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0049e062  39f2                   +cmp edx, esi
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
    // 0049e064  7514                   -jne 0x49e07a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e07a;
    }
    // 0049e066  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 0049e06a  750e                   -jne 0x49e07a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e07a;
    }
    // 0049e06c  833900                 +cmp dword ptr [ecx], 0
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
    // 0049e06f  7c09                   -jl 0x49e07a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e07a;
    }
    // 0049e071  31f2                   -xor edx, esi
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e073  8a5133                 -mov dl, byte ptr [ecx + 0x33]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */);
    // 0049e076  39ea                   +cmp edx, ebp
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
    // 0049e078  751c                   -jne 0x49e096
    if (!cpu.flags.zf)
    {
        goto L_0x0049e096;
    }
L_0x0049e07a:
    // 0049e07a  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e07b  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049e07e  83fb10                 +cmp ebx, 0x10
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
    // 0049e081  7cda                   -jl 0x49e05d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e05d;
    }
L_0x0049e083:
    // 0049e083  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049e085:
    // 0049e085  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e087  83c404                 +add esp, 4
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
    // 0049e08a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e08b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e08c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e08d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e08e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e08f:
    // 0049e08f  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 0049e094  ebef                   -jmp 0x49e085
    goto L_0x0049e085;
L_0x0049e096:
    // 0049e096  6683794200             +cmp word ptr [ecx + 0x42], 0
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
    // 0049e09b  74dd                   -je 0x49e07a
    if (cpu.flags.zf)
    {
        goto L_0x0049e07a;
    }
    // 0049e09d  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0049e0a0  884133                 -mov byte ptr [ecx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 0049e0a3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e0a5  e8862c0100             -call 0x4b0d30
    cpu.esp -= 4;
    sub_4b0d30(app, cpu);
    if (cpu.terminate) return;
    // 0049e0aa  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e0ad  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e0af  c1fa10                 +sar edx, 0x10
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
    // 0049e0b2  e8d9b5feff             -call 0x489690
    cpu.esp -= 4;
    sub_489690(app, cpu);
    if (cpu.terminate) return;
    // 0049e0b7  ebc1                   -jmp 0x49e07a
    goto L_0x0049e07a;
L_0x0049e0b9:
    // 0049e0b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e0bb  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e0be  8a4233                 -mov al, byte ptr [edx + 0x33]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(51) /* 0x33 */);
    // 0049e0c1  39d8                   +cmp eax, ebx
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
    // 0049e0c3  74be                   -je 0x49e083
    if (cpu.flags.zf)
    {
        goto L_0x0049e083;
    }
    // 0049e0c5  66837a4200             +cmp word ptr [edx + 0x42], 0
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
    // 0049e0ca  74b7                   -je 0x49e083
    if (cpu.flags.zf)
    {
        goto L_0x0049e083;
    }
    // 0049e0cc  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0049e0cf  884233                 -mov byte ptr [edx + 0x33], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 0049e0d2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e0d4  e8572c0100             -call 0x4b0d30
    cpu.esp -= 4;
    sub_4b0d30(app, cpu);
    if (cpu.terminate) return;
    // 0049e0d9  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049e0dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e0de  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049e0e1  e8aab5feff             -call 0x489690
    cpu.esp -= 4;
    sub_489690(app, cpu);
    if (cpu.terminate) return;
    // 0049e0e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e0e8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e0ea  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e0ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e0f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e0f4);
    // 0049e0f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e0f5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e0f7  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049e0fe  7410                   -je 0x49e110
    if (cpu.flags.zf)
    {
        goto L_0x0049e110;
    }
    // 0049e100  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e102  7c05                   -jl 0x49e109
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e109;
    }
    // 0049e104  83fa7f                 +cmp edx, 0x7f
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
    // 0049e107  7e0e                   -jle 0x49e117
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e117;
    }
L_0x0049e109:
    // 0049e109  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049e10e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e10f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e110:
    // 0049e110  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049e115  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e116  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e117:
    // 0049e117  e844720000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 0049e11c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e11e  e8fdfeffff             -call 0x49e020
    cpu.esp -= 4;
    sub_49e020(app, cpu);
    if (cpu.terminate) return;
    // 0049e123  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e125  e84a720000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049e12a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e12c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e12d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_49e130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e130);
    // 0049e130  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e131  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e132  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e133  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e136  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e138  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049e13a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049e13c  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 0049e142  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e144  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0049e146  750c                   -jne 0x49e154
    if (!cpu.flags.zf)
    {
        goto L_0x0049e154;
    }
    // 0049e148  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049e14d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e150  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e151  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e152  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e153  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e154:
    // 0049e154  e807720000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 0049e159  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049e15f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e161  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049e167  e800760000             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 0049e16c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e16e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e170  7c60                   -jl 0x49e1d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e1d2;
    }
    // 0049e172  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e173  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049e176  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e178  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049e17b  05b0bf5900             -add eax, 0x59bfb0
    (cpu.eax) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 0049e180  8a403b                 -mov al, byte ptr [eax + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 0049e183  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049e188  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049e18c  7455                   -je 0x49e1e3
    if (cpu.flags.zf)
    {
        goto L_0x0049e1e3;
    }
    // 0049e18e  beb0bf5900             -mov esi, 0x59bfb0
    cpu.esi = 5881776 /*0x59bfb0*/;
    // 0049e193  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049e195:
    // 0049e195  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e197  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e19b  8a463b                 -mov al, byte ptr [esi + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(59) /* 0x3b */);
    // 0049e19e  39d8                   +cmp eax, ebx
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
    // 0049e1a0  7518                   -jne 0x49e1ba
    if (!cpu.flags.zf)
    {
        goto L_0x0049e1ba;
    }
    // 0049e1a2  807e0c01               +cmp byte ptr [esi + 0xc], 1
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
    // 0049e1a6  7512                   -jne 0x49e1ba
    if (!cpu.flags.zf)
    {
        goto L_0x0049e1ba;
    }
    // 0049e1a8  833e00                 +cmp dword ptr [esi], 0
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
    // 0049e1ab  7c0d                   -jl 0x49e1ba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e1ba;
    }
    // 0049e1ad  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049e1af  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049e1b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e1b3  e84cb2feff             -call 0x489404
    cpu.esp -= 4;
    sub_489404(app, cpu);
    if (cpu.terminate) return;
    // 0049e1b8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049e1ba:
    // 0049e1ba  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e1bb  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049e1be  83f910                 +cmp ecx, 0x10
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
    // 0049e1c1  7cd2                   -jl 0x49e195
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e195;
    }
    // 0049e1c3  e8ac710000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049e1c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e1ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e1ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e1d2:
    // 0049e1d2  e89d710000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049e1d7  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049e1dc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e1df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e1e3:
    // 0049e1e3  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049e1e5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049e1e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e1e9  e816b2feff             -call 0x489404
    cpu.esp -= 4;
    sub_489404(app, cpu);
    if (cpu.terminate) return;
    // 0049e1ee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e1f0  e87f710000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049e1f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e1f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1f8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e1fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49e200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e200);
    // 0049e200  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e201  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e202  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e205  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e207  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049e20b  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049e212  7416                   -je 0x49e22a
    if (cpu.flags.zf)
    {
        goto L_0x0049e22a;
    }
    // 0049e214  83fa7f                 +cmp edx, 0x7f
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
    // 0049e217  7f04                   -jg 0x49e21d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049e21d;
    }
    // 0049e219  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e21b  7d14                   -jge 0x49e231
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e231;
    }
L_0x0049e21d:
    // 0049e21d  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x0049e222:
    // 0049e222  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e224  83c408                 +add esp, 8
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
    // 0049e227  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e228  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e229  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e22a:
    // 0049e22a  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 0049e22f  ebf1                   -jmp 0x49e222
    goto L_0x0049e222;
L_0x0049e231:
    // 0049e231  e82a710000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 0049e236  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e238  e82f750000             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 0049e23d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e23f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e241  0f8ca2000000           -jl 0x49e2e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e2e9;
    }
    // 0049e247  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e248  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e249  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e24a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049e24d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e24f  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049e252  05b0bf5900             -add eax, 0x59bfb0
    (cpu.eax) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 0049e257  0fb6783b               -movzx edi, byte ptr [eax + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */));
    // 0049e25b  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049e25e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049e260  0f849d000000           -je 0x49e303
    if (cpu.flags.zf)
    {
        goto L_0x0049e303;
    }
    // 0049e266  b9b0bf5900             -mov ecx, 0x59bfb0
    cpu.ecx = 5881776 /*0x59bfb0*/;
    // 0049e26b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049e26f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e271  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0049e273:
    // 0049e273  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e275  8a413b                 -mov al, byte ptr [ecx + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0049e278  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049e27a  39f8                   +cmp eax, edi
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
    // 0049e27c  7550                   -jne 0x49e2ce
    if (!cpu.flags.zf)
    {
        goto L_0x0049e2ce;
    }
    // 0049e27e  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 0049e282  754a                   -jne 0x49e2ce
    if (!cpu.flags.zf)
    {
        goto L_0x0049e2ce;
    }
    // 0049e284  3b29                   +cmp ebp, dword ptr [ecx]
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
    // 0049e286  7f46                   -jg 0x49e2ce
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049e2ce;
    }
    // 0049e288  8a6137                 -mov ah, byte ptr [ecx + 0x37]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */);
    // 0049e28b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e28f  80fc01                 +cmp ah, 1
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
    // 0049e292  7410                   -je 0x49e2a4
    if (cpu.flags.zf)
    {
        goto L_0x0049e2a4;
    }
    // 0049e294  8b5134                 -mov edx, dword ptr [ecx + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0049e297  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e29b  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049e29e  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049e2a1  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x0049e2a4:
    // 0049e2a4  8b462f                 -mov eax, dword ptr [esi + 0x2f]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(47) /* 0x2f */);
    // 0049e2a7  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049e2aa  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e2ac  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049e2af  83fa7f                 +cmp edx, 0x7f
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
    // 0049e2b2  7e47                   -jle 0x49e2fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e2fb;
    }
    // 0049e2b4  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
L_0x0049e2b9:
    // 0049e2b9  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0049e2bc  39c5                   +cmp ebp, eax
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
    // 0049e2be  7404                   -je 0x49e2c4
    if (cpu.flags.zf)
    {
        goto L_0x0049e2c4;
    }
    // 0049e2c0  0fbe1402               -movsx edx, byte ptr [edx + eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1)));
L_0x0049e2c4:
    // 0049e2c4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e2c6  88560f                 -mov byte ptr [esi + 0xf], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 0049e2c9  e886b0feff             -call 0x489354
    cpu.esp -= 4;
    sub_489354(app, cpu);
    if (cpu.terminate) return;
L_0x0049e2ce:
    // 0049e2ce  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e2cf  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049e2d2  83fb10                 +cmp ebx, 0x10
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
    // 0049e2d5  7c9c                   -jl 0x49e273
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e273;
    }
    // 0049e2d7  e898700000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049e2dc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e2de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e2e3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e2e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e2e9:
    // 0049e2e9  e886700000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049e2ee  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 0049e2f3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e2f5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e2f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e2fb:
    // 0049e2fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e2fd  7dba                   -jge 0x49e2b9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e2b9;
    }
    // 0049e2ff  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049e301  ebb6                   -jmp 0x49e2b9
    goto L_0x0049e2b9;
L_0x0049e303:
    // 0049e303  80783701               +cmp byte ptr [eax + 0x37], 1
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
    // 0049e307  7410                   -je 0x49e319
    if (cpu.flags.zf)
    {
        goto L_0x0049e319;
    }
    // 0049e309  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049e30c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0049e30f  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049e312  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049e315  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x0049e319:
    // 0049e319  8b502f                 -mov edx, dword ptr [eax + 0x2f]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(47) /* 0x2f */);
    // 0049e31c  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e320  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049e323  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049e325  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049e328  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049e32c  83fa7f                 +cmp edx, 0x7f
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
    // 0049e32f  7e41                   -jle 0x49e372
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e372;
    }
    // 0049e331  c74424107f000000       -mov dword ptr [esp + 0x10], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 127 /*0x7f*/;
L_0x0049e339:
    // 0049e339  8b7050                 -mov esi, dword ptr [eax + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0049e33c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049e33e  740e                   -je 0x49e34e
    if (cpu.flags.zf)
    {
        goto L_0x0049e34e;
    }
    // 0049e340  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e344  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0049e347  0fbe12                 -movsx edx, byte ptr [edx]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx)));
    // 0049e34a  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x0049e34e:
    // 0049e34e  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e352  88500f                 -mov byte ptr [eax + 0xf], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 0049e355  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e359  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e35b  e8f4affeff             -call 0x489354
    cpu.esp -= 4;
    sub_489354(app, cpu);
    if (cpu.terminate) return;
    // 0049e360  e80f700000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049e365  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e367  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e368  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e369  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e36a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e36c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e36f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e370  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e371  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e372:
    // 0049e372  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e374  7dc3                   -jge 0x49e339
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e339;
    }
    // 0049e376  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049e378  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049e37c  ebbb                   -jmp 0x49e339
    goto L_0x0049e339;
}

/* align: skip 0x00 0x00 */
void Application::sub_49e380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e380);
    // 0049e380  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e381  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049e386  e811000000             -call 0x49e39c
    cpu.esp -= 4;
    sub_49e39c(app, cpu);
    if (cpu.terminate) return;
    // 0049e38b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e38c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49e390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e390);
    // 0049e390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e391  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e393  e804000000             -call 0x49e39c
    cpu.esp -= 4;
    sub_49e39c(app, cpu);
    if (cpu.terminate) return;
    // 0049e398  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e399  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e39c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e39c);
    // 0049e39c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e39d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e39e  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049e3a1  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e3a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e3a6  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e3aa  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e3ae  e8b592feff             -call 0x487668
    cpu.esp -= 4;
    sub_487668(app, cpu);
    if (cpu.terminate) return;
    // 0049e3b3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e3b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e3b8  750a                   -jne 0x49e3c4
    if (!cpu.flags.zf)
    {
        goto L_0x0049e3c4;
    }
    // 0049e3ba  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e3be  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049e3c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e3c4:
    // 0049e3c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e3c6  e88595feff             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 0049e3cb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e3cf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049e3d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49e3e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e3e0);
    // 0049e3e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e3e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e3e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e3e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e3e4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e3e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e3e8  7f07                   -jg 0x49e3f1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049e3f1;
    }
    // 0049e3ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049e3ec:
    // 0049e3ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e3f1:
    // 0049e3f1  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049e3f4  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0049e3f9  b84c0f4d00             -mov eax, 0x4d0f4c
    cpu.eax = 5050188 /*0x4d0f4c*/;
    // 0049e3fe  e89560feff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 0049e403  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e405  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e407  74e3                   -je 0x49e3ec
    if (cpu.flags.zf)
    {
        goto L_0x0049e3ec;
    }
    // 0049e409  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0049e40e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e410  b8680f4d00             -mov eax, 0x4d0f68
    cpu.eax = 5050216 /*0x4d0f68*/;
    // 0049e415  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e418  e863c5feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0049e41d  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0049e422  b8700f4d00             -mov eax, 0x4d0f70
    cpu.eax = 5050224 /*0x4d0f70*/;
    // 0049e427  8d1431                 -lea edx, [ecx + esi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 0049e42a  8971fc                 -mov dword ptr [ecx - 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0049e42d  e84ec5feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0049e432  8b155cd44d00           -mov edx, dword ptr [0x4dd45c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100636) /* 0x4dd45c */);
    // 0049e438  42                     -inc edx
    (cpu.edx)++;
    // 0049e439  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e43b  89155cd44d00           -mov dword ptr [0x4dd45c], edx
    app->getMemory<x86::reg32>(x86::reg32(5100636) /* 0x4dd45c */) = cpu.edx;
    // 0049e441  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e442  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e443  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e444  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e445  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e448);
    // 0049e448  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e449  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e44a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e44b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e44c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e44d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e44e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e450  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049e455  bf680f4d00             -mov edi, 0x4d0f68
    cpu.edi = 5050216 /*0x4d0f68*/;
    // 0049e45a  8d70f8                 -lea esi, [eax - 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 0049e45d  8b58fc                 -mov ebx, dword ptr [eax - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0049e460  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e462  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 0049e464  7405                   -je 0x49e46b
    if (cpu.flags.zf)
    {
        goto L_0x0049e46b;
    }
    // 0049e466  19c0                   +sbb eax, eax
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
    // 0049e468  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0049e46b:
    // 0049e46b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e46d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e46f  7557                   -jne 0x49e4c8
    if (!cpu.flags.zf)
    {
        goto L_0x0049e4c8;
    }
    // 0049e471  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e473  7e53                   -jle 0x49e4c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e4c8;
    }
    // 0049e475  81fb00000002           +cmp ebx, 0x2000000
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
    // 0049e47b  7d4b                   -jge 0x49e4c8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e4c8;
    }
    // 0049e47d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049e482  bf700f4d00             -mov edi, 0x4d0f70
    cpu.edi = 5050224 /*0x4d0f70*/;
    // 0049e487  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0049e48a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e48c  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 0049e48e  7405                   -je 0x49e495
    if (cpu.flags.zf)
    {
        goto L_0x0049e495;
    }
    // 0049e490  19c0                   +sbb eax, eax
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
    // 0049e492  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0049e495:
    // 0049e495  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e497  752f                   -jne 0x49e4c8
    if (!cpu.flags.zf)
    {
        goto L_0x0049e4c8;
    }
    // 0049e499  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x0049e49e:
    // 0049e49e  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0049e4a3  8d4af8                 -lea ecx, [edx - 8]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0049e4a6  b8780f4d00             -mov eax, 0x4d0f78
    cpu.eax = 5050232 /*0x4d0f78*/;
    // 0049e4ab  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049e4ad  e8cec4feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0049e4b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e4b4  e84364feff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0049e4b9  ff0d5cd44d00           -dec dword ptr [0x4dd45c]
    (app->getMemory<x86::reg32>(x86::reg32(5100636) /* 0x4dd45c */))--;
    // 0049e4bf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049e4c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e4c8:
    // 0049e4c8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049e4ca  75d2                   -jne 0x49e49e
    if (!cpu.flags.zf)
    {
        goto L_0x0049e49e;
    }
    // 0049e4cc  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049e4d1  bf780f4d00             -mov edi, 0x4d0f78
    cpu.edi = 5050232 /*0x4d0f78*/;
    // 0049e4d6  8d72f8                 -lea esi, [edx - 8]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0049e4d9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e4db  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 0049e4dd  7405                   -je 0x49e4e4
    if (cpu.flags.zf)
    {
        goto L_0x0049e4e4;
    }
    // 0049e4df  19c0                   +sbb eax, eax
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
    // 0049e4e1  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0049e4e4:
    // 0049e4e4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049e4e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e4ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49e4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e4f0);
    // 0049e4f0  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049e4f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e4f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e4f4);
    // 0049e4f4  3b5008                 +cmp edx, dword ptr [eax + 8]
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
    // 0049e4f7  7305                   -jae 0x49e4fe
    if (!cpu.flags.cf)
    {
        goto L_0x0049e4fe;
    }
    // 0049e4f9  0344d014               -add eax, dword ptr [eax + edx*8 + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */ + cpu.edx * 8)));
    // 0049e4fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e4fe:
    // 0049e4fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e500  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e501(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e501);
    // 0049e501  3b5008                 +cmp edx, dword ptr [eax + 8]
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
    // 0049e504  7307                   -jae 0x49e50d
    if (!cpu.flags.cf)
    {
        goto L_0x0049e50d;
    }
    // 0049e506  8b44d010               -mov eax, dword ptr [eax + edx*8 + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */ + cpu.edx * 8);
    // 0049e50a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049e50c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e50d:
    // 0049e50d  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0049e513  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49e520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e520);
    // 0049e520  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e521  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e523  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e525  7504                   -jne 0x49e52b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e52b;
    }
L_0x0049e527:
    // 0049e527  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e529  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e52a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e52b:
    // 0049e52b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e52d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049e530  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 0049e536  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e538  74ed                   -je 0x49e527
    if (cpu.flags.zf)
    {
        goto L_0x0049e527;
    }
L_0x0049e53a:
    // 0049e53a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e53c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e541  83f822                 +cmp eax, 0x22
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e544  7438                   -je 0x49e57e
    if (cpu.flags.zf)
    {
        goto L_0x0049e57e;
    }
    // 0049e546  83f824                 +cmp eax, 0x24
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e549  7433                   -je 0x49e57e
    if (cpu.flags.zf)
    {
        goto L_0x0049e57e;
    }
    // 0049e54b  83f823                 +cmp eax, 0x23
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e54e  742e                   -je 0x49e57e
    if (cpu.flags.zf)
    {
        goto L_0x0049e57e;
    }
    // 0049e550  83f829                 +cmp eax, 0x29
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e553  7429                   -je 0x49e57e
    if (cpu.flags.zf)
    {
        goto L_0x0049e57e;
    }
    // 0049e555  83f82a                 +cmp eax, 0x2a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e558  7424                   -je 0x49e57e
    if (cpu.flags.zf)
    {
        goto L_0x0049e57e;
    }
    // 0049e55a  83f82c                 +cmp eax, 0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e55d  741f                   -je 0x49e57e
    if (cpu.flags.zf)
    {
        goto L_0x0049e57e;
    }
    // 0049e55f  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e562  741a                   -je 0x49e57e
    if (cpu.flags.zf)
    {
        goto L_0x0049e57e;
    }
    // 0049e564  83f82e                 +cmp eax, 0x2e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e567  7415                   -je 0x49e57e
    if (cpu.flags.zf)
    {
        goto L_0x0049e57e;
    }
    // 0049e569  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e56b  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0049e56e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e570  7402                   -je 0x49e574
    if (cpu.flags.zf)
    {
        goto L_0x0049e574;
    }
    // 0049e572  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0049e574:
    // 0049e574  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e576  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e578  75c0                   -jne 0x49e53a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e53a;
    }
    // 0049e57a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e57c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e57d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e57e:
    // 0049e57e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e580  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e581  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e584);
    // 0049e584  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e585  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e587  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e589  7504                   -jne 0x49e58f
    if (!cpu.flags.zf)
    {
        goto L_0x0049e58f;
    }
L_0x0049e58b:
    // 0049e58b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e58d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e58e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e58f:
    // 0049e58f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e591  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049e594  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 0049e59a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e59c  74ed                   -je 0x49e58b
    if (cpu.flags.zf)
    {
        goto L_0x0049e58b;
    }
L_0x0049e59e:
    // 0049e59e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e5a0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e5a5  83f87c                 +cmp eax, 0x7c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(124 /*0x7c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e5a8  7415                   -je 0x49e5bf
    if (cpu.flags.zf)
    {
        goto L_0x0049e5bf;
    }
    // 0049e5aa  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e5ac  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0049e5af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e5b1  7402                   -je 0x49e5b5
    if (cpu.flags.zf)
    {
        goto L_0x0049e5b5;
    }
    // 0049e5b3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0049e5b5:
    // 0049e5b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e5b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e5b9  75e3                   -jne 0x49e59e
    if (!cpu.flags.zf)
    {
        goto L_0x0049e59e;
    }
    // 0049e5bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e5bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e5bf:
    // 0049e5bf  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049e5c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e5c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e5c4);
    // 0049e5c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e5c5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e5c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e5c9  7504                   -jne 0x49e5cf
    if (!cpu.flags.zf)
    {
        goto L_0x0049e5cf;
    }
L_0x0049e5cb:
    // 0049e5cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e5cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e5cf:
    // 0049e5cf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e5d1  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049e5d4  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 0049e5da  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e5dc  74ed                   -je 0x49e5cb
    if (cpu.flags.zf)
    {
        goto L_0x0049e5cb;
    }
L_0x0049e5de:
    // 0049e5de  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e5e0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e5e5  83f86f                 +cmp eax, 0x6f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e5e8  7415                   -je 0x49e5ff
    if (cpu.flags.zf)
    {
        goto L_0x0049e5ff;
    }
    // 0049e5ea  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e5ec  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0049e5ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e5f1  7402                   -je 0x49e5f5
    if (cpu.flags.zf)
    {
        goto L_0x0049e5f5;
    }
    // 0049e5f3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0049e5f5:
    // 0049e5f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e5f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e5f9  75e3                   -jne 0x49e5de
    if (!cpu.flags.zf)
    {
        goto L_0x0049e5de;
    }
    // 0049e5fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e5fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e5ff:
    // 0049e5ff  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049e602  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e603  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49e630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e630);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0049e630  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e631  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e632  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e635  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e637  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e639  7c1f                   -jl 0x49e65a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e65a;
    }
L_0x0049e63b:
    // 0049e63b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e63d  7c24                   -jl 0x49e663
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e663;
    }
L_0x0049e63f:
    // 0049e63f  39d0                   +cmp eax, edx
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
    // 0049e641  7527                   -jne 0x49e66a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e66a;
    }
    // 0049e643  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 0049e648  83f907                 +cmp ecx, 7
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
    // 0049e64b  7707                   -ja 0x49e654
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049e654;
    }
    // 0049e64d  ff248d10e64900         -jmp dword ptr [ecx*4 + 0x49e610]
    cpu.ip = app->getMemory<x86::reg32>(4843024 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0049e654:
L_0x0049e654:
    // 0049e654  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e657  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e658  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e659  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e65a:
    // 0049e65a  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0049e65f  f7da                   +neg edx
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
    // 0049e661  ebd8                   -jmp 0x49e63b
    goto L_0x0049e63b;
L_0x0049e663:
    // 0049e663  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0049e666  f7d8                   +neg eax
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
    // 0049e668  ebd5                   -jmp 0x49e63f
    goto L_0x0049e63f;
L_0x0049e66a:
    // 0049e66a  39c2                   +cmp edx, eax
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
    // 0049e66c  7d09                   -jge 0x49e677
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e677;
    }
    // 0049e66e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e670  80c901                 -or cl, 1
    cpu.cl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049e673  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e675  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0049e677:
    // 0049e677  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e678  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e679  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e67d  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0049e682  e8912b0100             -call 0x4b1218
    cpu.esp -= 4;
    sub_4b1218(app, cpu);
    if (cpu.terminate) return;
    // 0049e687  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e68b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e68c  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e691  e8fe270100             -call 0x4b0e94
    cpu.esp -= 4;
    sub_4b0e94(app, cpu);
    if (cpu.terminate) return;
    // 0049e696  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e698  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0049e69b  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0049e6a2  c1ee08                 -shr esi, 8
    cpu.esi >>= 8 /*0x8*/ % 32;
    // 0049e6a5  8b827cfd4d00           -mov eax, dword ptr [edx + 0x4dfd7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5111164) /* 0x4dfd7c */);
    // 0049e6ab  8b9280fd4d00           -mov edx, dword ptr [edx + 0x4dfd80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5111168) /* 0x4dfd80 */);
    // 0049e6b1  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049e6b7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e6b9  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049e6bc  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0049e6bf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049e6c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6c2  83f907                 +cmp ecx, 7
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
    // 0049e6c5  778d                   -ja 0x49e654
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049e654;
    }
    // 0049e6c7  ff248d10e64900         -jmp dword ptr [ecx*4 + 0x49e610]
    cpu.ip = app->getMemory<x86::reg32>(4843024 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0049e6ce:
    // 0049e6ce  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
  [[fallthrough]];
  case 0x0049e6d0:
    // 0049e6d0  0500400000             -add eax, 0x4000
    (cpu.eax) += x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 0049e6d5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e6d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6da  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049e6db:
    // 0049e6db  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049e6dd  0500800000             -add eax, 0x8000
    (cpu.eax) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049e6e2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e6e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6e7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049e6e8:
    // 0049e6e8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049e6ea  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e6ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6ef  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049e6f0:
    // 0049e6f0  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 0049e6f5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e6f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6fa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049e6fb:
    // 0049e6fb  050080ffff             -add eax, 0xffff8000
    (cpu.eax) += x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
    // 0049e700  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e703  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e704  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e705  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049e706:
    // 0049e706  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049e708  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 0049e70d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e710  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e711  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e712  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49e720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e720);
    // 0049e720  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e721  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e722  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e725  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e727  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e729  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049e72b  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e72f  e88cebffff             -call 0x49d2c0
    cpu.esp -= 4;
    sub_49d2c0(app, cpu);
    if (cpu.terminate) return;
    // 0049e734  c70100000100           -mov dword ptr [ecx], 0x10000
    app->getMemory<x86::reg32>(cpu.ecx) = 65536 /*0x10000*/;
    // 0049e73a  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049e741  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0049e748  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0049e74f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e752  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049e755  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e759  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0049e760  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049e763  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e767  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e769  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0049e76c  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049e76e  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049e771  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e774  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049e777  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e77a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e77b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e77c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49e780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e780);
    // 0049e780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e782  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e785  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e787  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e789  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049e78b  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e78f  e82cebffff             -call 0x49d2c0
    cpu.esp -= 4;
    sub_49d2c0(app, cpu);
    if (cpu.terminate) return;
    // 0049e794  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e797  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049e79e  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049e7a0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e7a4  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0049e7ab  c7411000000100         -mov dword ptr [ecx + 0x10], 0x10000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = 65536 /*0x10000*/;
    // 0049e7b2  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0049e7b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e7bb  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049e7be  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049e7c0  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049e7c3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e7c7  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0049e7ce  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049e7d1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e7d4  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049e7d7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e7da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7db  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49e7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e7e0);
    // 0049e7e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e7e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e7e2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e7e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e7e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e7e9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049e7eb  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e7ef  e8cceaffff             -call 0x49d2c0
    cpu.esp -= 4;
    sub_49d2c0(app, cpu);
    if (cpu.terminate) return;
    // 0049e7f4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e7f7  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049e7f9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e7fd  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0049e804  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049e807  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e80b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e80d  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049e810  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049e812  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049e815  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e818  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0049e81f  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0049e826  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0049e82d  c7412000000100         -mov dword ptr [ecx + 0x20], 0x10000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 65536 /*0x10000*/;
    // 0049e834  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049e837  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e83a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e83b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e83c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49e840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e840);
    // 0049e840  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e841  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e842  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e843  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e844  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0049e847  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049e84b  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049e84f  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049e853  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e855  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049e859  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0049e85d  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0049e860:
    // 0049e860  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049e864  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049e868  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049e86c  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x0049e86f:
    // 0049e86f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049e871  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049e873  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049e875  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049e878  c1e810                 +shr eax, 0x10
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
    // 0049e87b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049e87d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e87f  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049e882  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049e885  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049e887  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049e88a  c1e810                 +shr eax, 0x10
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
    // 0049e88d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049e88f  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0049e892  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e894  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049e897  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e89a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049e89c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049e89f  c1e810                 +shr eax, 0x10
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
    // 0049e8a2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049e8a4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e8a6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e8a9  895c3cfc               -mov dword ptr [esp + edi - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1) = cpu.ebx;
    // 0049e8ad  39e9                   +cmp ecx, ebp
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
    // 0049e8af  75be                   -jne 0x49e86f
    if (!cpu.flags.zf)
    {
        goto L_0x0049e86f;
    }
    // 0049e8b1  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049e8b5  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049e8b9  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049e8bc  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e8bf  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0049e8c3  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0049e8c7  83fb09                 +cmp ebx, 9
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
    // 0049e8ca  7c94                   -jl 0x49e860
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e860;
    }
    // 0049e8cc  bb24000000             -mov ebx, 0x24
    cpu.ebx = 36 /*0x24*/;
    // 0049e8d1  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049e8d5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049e8d7  e8a4c0feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0049e8dc  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0049e8df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e8e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e8e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e8e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e8e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49e8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e8f0);
    // 0049e8f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e8f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e8f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e8f3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049e8f5  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049e8fa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e8fc  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e8ff  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e901  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049e903  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e905  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049e90c  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049e90e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e910  8a6701                 -mov ah, byte ptr [edi + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0049e913  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e915  80fcfb                 +cmp ah, 0xfb
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
    // 0049e918  7518                   -jne 0x49e932
    if (!cpu.flags.zf)
    {
        goto L_0x0049e932;
    }
L_0x0049e91a:
    // 0049e91a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e91c  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049e91e  3c32                   +cmp al, 0x32
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
    // 0049e920  7317                   -jae 0x49e939
    if (!cpu.flags.cf)
    {
        goto L_0x0049e939;
    }
    // 0049e922  3c10                   +cmp al, 0x10
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
    // 0049e924  7206                   -jb 0x49e92c
    if (cpu.flags.cf)
    {
        goto L_0x0049e92c;
    }
    // 0049e926  763c                   -jbe 0x49e964
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e964;
    }
    // 0049e928  3c30                   +cmp al, 0x30
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
    // 0049e92a  7417                   -je 0x49e943
    if (cpu.flags.zf)
    {
        goto L_0x0049e943;
    }
L_0x0049e92c:
    // 0049e92c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e92e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e92f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e930  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e931  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e932:
    // 0049e932  80fc32                 +cmp ah, 0x32
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
    // 0049e935  74e3                   -je 0x49e91a
    if (cpu.flags.zf)
    {
        goto L_0x0049e91a;
    }
    // 0049e937  ebf3                   -jmp 0x49e92c
    goto L_0x0049e92c;
L_0x0049e939:
    // 0049e939  7608                   -jbe 0x49e943
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e943;
    }
    // 0049e93b  3c46                   +cmp al, 0x46
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
    // 0049e93d  7314                   -jae 0x49e953
    if (!cpu.flags.cf)
    {
        goto L_0x0049e953;
    }
    // 0049e93f  3c34                   +cmp al, 0x34
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
    // 0049e941  75e9                   -jne 0x49e92c
    if (!cpu.flags.zf)
    {
        goto L_0x0049e92c;
    }
L_0x0049e943:
    // 0049e943  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049e948  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e94a  e881290100             -call 0x4b12d0
    cpu.esp -= 4;
    sub_4b12d0(app, cpu);
    if (cpu.terminate) return;
    // 0049e94f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e951  ebd9                   -jmp 0x49e92c
    goto L_0x0049e92c;
L_0x0049e953:
    // 0049e953  7623                   -jbe 0x49e978
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e978;
    }
    // 0049e955  3c4a                   +cmp al, 0x4a
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
    // 0049e957  75d3                   -jne 0x49e92c
    if (!cpu.flags.zf)
    {
        goto L_0x0049e92c;
    }
    // 0049e959  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e95b  e8303d0100             -call 0x4b2690
    cpu.esp -= 4;
    sub_4b2690(app, cpu);
    if (cpu.terminate) return;
    // 0049e960  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049e962  ebc8                   -jmp 0x49e92c
    goto L_0x0049e92c;
L_0x0049e964:
    // 0049e964  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049e969  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e96b  e8b43e0100             -call 0x4b2824
    cpu.esp -= 4;
    sub_4b2824(app, cpu);
    if (cpu.terminate) return;
    // 0049e970  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e972  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e974  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e975  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e976  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e977  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e978:
    // 0049e978  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e97a  e859400100             -call 0x4b29d8
    cpu.esp -= 4;
    sub_4b29d8(app, cpu);
    if (cpu.terminate) return;
    // 0049e97f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e981  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e983  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e984  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e985  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e986  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49e988(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e988);
    // 0049e988  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e989  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049e98e  e85dffffff             -call 0x49e8f0
    cpu.esp -= 4;
    sub_49e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0049e993  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e994  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49e998(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e998);
    // 0049e998  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e999  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e99b  e850ffffff             -call 0x49e8f0
    cpu.esp -= 4;
    sub_49e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0049e9a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e9a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e9a4);
    // 0049e9a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e9a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e9a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e9a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e9a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e9aa  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049e9af  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e9b1  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e9b4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e9b6  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049e9b8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e9ba  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049e9c1  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049e9c3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e9c5  8a6201                 -mov ah, byte ptr [edx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049e9c8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e9ca  80fcfb                 +cmp ah, 0xfb
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
    // 0049e9cd  7519                   -jne 0x49e9e8
    if (!cpu.flags.zf)
    {
        goto L_0x0049e9e8;
    }
L_0x0049e9cf:
    // 0049e9cf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e9d1  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049e9d3  3c34                   +cmp al, 0x34
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
    // 0049e9d5  7318                   -jae 0x49e9ef
    if (!cpu.flags.cf)
    {
        goto L_0x0049e9ef;
    }
    // 0049e9d7  3c30                   +cmp al, 0x30
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
    // 0049e9d9  7324                   -jae 0x49e9ff
    if (!cpu.flags.cf)
    {
        goto L_0x0049e9ff;
    }
    // 0049e9db  3c10                   +cmp al, 0x10
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
    // 0049e9dd  7502                   -jne 0x49e9e1
    if (!cpu.flags.zf)
    {
        goto L_0x0049e9e1;
    }
L_0x0049e9df:
    // 0049e9df  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x0049e9e1:
    // 0049e9e1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e9e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e9e8:
    // 0049e9e8  80fc32                 +cmp ah, 0x32
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
    // 0049e9eb  74e2                   -je 0x49e9cf
    if (cpu.flags.zf)
    {
        goto L_0x0049e9cf;
    }
    // 0049e9ed  ebf2                   -jmp 0x49e9e1
    goto L_0x0049e9e1;
L_0x0049e9ef:
    // 0049e9ef  76ee                   -jbe 0x49e9df
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e9df;
    }
    // 0049e9f1  3c4a                   +cmp al, 0x4a
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
    // 0049e9f3  7306                   -jae 0x49e9fb
    if (!cpu.flags.cf)
    {
        goto L_0x0049e9fb;
    }
    // 0049e9f5  3c46                   +cmp al, 0x46
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
    // 0049e9f7  74e6                   -je 0x49e9df
    if (cpu.flags.zf)
    {
        goto L_0x0049e9df;
    }
    // 0049e9f9  ebe6                   -jmp 0x49e9e1
    goto L_0x0049e9e1;
L_0x0049e9fb:
    // 0049e9fb  76e2                   -jbe 0x49e9df
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e9df;
    }
    // 0049e9fd  ebe2                   -jmp 0x49e9e1
    goto L_0x0049e9e1;
L_0x0049e9ff:
    // 0049e9ff  76de                   -jbe 0x49e9df
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e9df;
    }
    // 0049ea01  3c32                   +cmp al, 0x32
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
    // 0049ea03  74da                   -je 0x49e9df
    if (cpu.flags.zf)
    {
        goto L_0x0049e9df;
    }
    // 0049ea05  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ea07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_49ea20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ea20);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0049ea20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ea21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ea22  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ea24  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0049ea27  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049ea2a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ea2f  83f903                 +cmp ecx, 3
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
    // 0049ea32  7720                   -ja 0x49ea54
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ea54;
    }
    // 0049ea34  ff248d10ea4900         -jmp dword ptr [ecx*4 + 0x49ea10]
    cpu.ip = app->getMemory<x86::reg32>(4844048 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0049ea3b:
    // 0049ea3b  8b0c85b4b64d00         -mov ecx, dword ptr [eax*4 + 0x4db6b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049ea42  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049ea44  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049ea49  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ea4b  8b0495b4b64d00         -mov eax, dword ptr [edx*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.edx * 4);
    // 0049ea52  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0049ea54:
    // 0049ea54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea56  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049ea57:
    // 0049ea57  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 0049ea5c  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ea5e  8b0c8db4b64d00         -mov ecx, dword ptr [ecx*4 + 0x4db6b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.ecx * 4);
    // 0049ea65  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049ea67  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049ea6e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049ea70  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049ea72  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 0049ea74  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 0049ea76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea78  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049ea79:
    // 0049ea79  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ea7a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ea7b  8b0c85b4b64d00         -mov ecx, dword ptr [eax*4 + 0x4db6b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049ea82  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049ea84  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049ea86  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0049ea88  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0049ea8a  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049ea8f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ea91  8b0495b4b64d00         -mov eax, dword ptr [edx*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.edx * 4);
    // 0049ea98  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049ea9a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049ea9c  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 0049ea9e  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0049eaa0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eaa1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eaa2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eaa3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eaa4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049eaa5:
    // 0049eaa5  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 0049eaaa  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049eaac  8b0c8db4b64d00         -mov ecx, dword ptr [ecx*4 + 0x4db6b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.ecx * 4);
    // 0049eab3  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049eab5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049eab7  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049eab9  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049eac0  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049eac2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eac3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eac4  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49eac8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049eac8);
    // 0049eac8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049eac9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049eaca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049eacb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049eacc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049eace  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049ead0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049ead2  f72f                   -imul dword ptr [edi]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi))));
    // 0049ead4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049ead6  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049ead9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049eadb  f76f0c                 -imul dword ptr [edi + 0xc]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 0049eade  01c5                   +add ebp, eax
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
    // 0049eae0  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049eae3  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049eae5  f76f18                 -imul dword ptr [edi + 0x18]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */))));
    // 0049eae8  01e8                   +add eax, ebp
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
    // 0049eaea  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049eaec  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0049eaf0  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049eaf2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049eaf4  f76f04                 -imul dword ptr [edi + 4]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 0049eaf7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049eaf9  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049eafc  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049eafe  f76f10                 -imul dword ptr [edi + 0x10]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */))));
    // 0049eb01  01c5                   +add ebp, eax
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
    // 0049eb03  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049eb06  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049eb08  f76f1c                 -imul dword ptr [edi + 0x1c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))));
    // 0049eb0b  01e8                   +add eax, ebp
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
    // 0049eb0d  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049eb0f  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0049eb13  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049eb16  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049eb18  f76f08                 -imul dword ptr [edi + 8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 0049eb1b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049eb1d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049eb20  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049eb22  f76f14                 -imul dword ptr [edi + 0x14]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */))));
    // 0049eb25  01c5                   +add ebp, eax
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
    // 0049eb27  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049eb2a  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049eb2c  f76f20                 -imul dword ptr [edi + 0x20]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */))));
    // 0049eb2f  01e8                   +add eax, ebp
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
    // 0049eb31  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049eb33  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0049eb37  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049eb3a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49eb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049eb40);
    // 0049eb40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049eb41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049eb42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049eb43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049eb44  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049eb46  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049eb48  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049eb4a  8d7024                 -lea esi, [eax + 0x24]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x0049eb4d:
    // 0049eb4d  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049eb50  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049eb52  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049eb54  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049eb57  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049eb59  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049eb5c  8953fc                 -mov dword ptr [ebx - 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0049eb5f  39f0                   +cmp eax, esi
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
    // 0049eb61  75ea                   -jne 0x49eb4d
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb4d;
    }
    // 0049eb63  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049eb65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49eb6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049eb6c);
    // 0049eb6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049eb6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049eb6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049eb6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049eb70  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049eb72  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049eb74  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049eb76  8d7024                 -lea esi, [eax + 0x24]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x0049eb79:
    // 0049eb79  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049eb7c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049eb7e  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049eb80  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049eb83  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049eb85  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049eb88  8953fc                 -mov dword ptr [ebx - 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0049eb8b  39f0                   +cmp eax, esi
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
    // 0049eb8d  75ea                   -jne 0x49eb79
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb79;
    }
    // 0049eb8f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049eb91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49eb98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049eb98);
    // 0049eb98  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049eb99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049eb9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049eb9b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049eb9c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049eb9e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049eba0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049eba2  8d7824                 -lea edi, [eax + 0x24]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x0049eba5:
    // 0049eba5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049eba7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049eba9  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ebac  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ebae  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ebb1  c1e810                 +shr eax, 0x10
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
    // 0049ebb4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ebb6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ebb9  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049ebbc  39f9                   +cmp ecx, edi
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
    // 0049ebbe  75e5                   -jne 0x49eba5
    if (!cpu.flags.zf)
    {
        goto L_0x0049eba5;
    }
    // 0049ebc0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ebc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ebc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ebc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ebc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ebc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49ebc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ebc8);
    // 0049ebc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ebc9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ebca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ebcb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ebcc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ebcd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ebce  81ecbc000000           -sub esp, 0xbc
    (cpu.esp) -= x86::reg32(x86::sreg32(188 /*0xbc*/));
    // 0049ebd4  898424b8000000         -mov dword ptr [esp + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 0049ebdb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ebdd  899424b4000000         -mov dword ptr [esp + 0xb4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.edx;
L_0x0049ebe4:
    // 0049ebe4  8d542448               -lea edx, [esp + 0x48]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049ebe8  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0049ebef  8d9c2490000000         -lea ebx, [esp + 0x90]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0049ebf6  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0049ebfb  e890ecffff             -call 0x49d890
    cpu.esp -= 4;
    sub_49d890(app, cpu);
    if (cpu.terminate) return;
    // 0049ec00  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0049ec07  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049ec0b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049ec0d  e82efcffff             -call 0x49e840
    cpu.esp -= 4;
    sub_49e840(app, cpu);
    if (cpu.terminate) return;
    // 0049ec12  8d5c246c               -lea ebx, [esp + 0x6c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0049ec16  ba60d44d00             -mov edx, 0x4dd460
    cpu.edx = 5100640 /*0x4dd460*/;
    // 0049ec1b  8d842490000000         -lea eax, [esp + 0x90]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0049ec22  be60d44d00             -mov esi, 0x4dd460
    cpu.esi = 5100640 /*0x4dd460*/;
    // 0049ec27  e840ffffff             -call 0x49eb6c
    cpu.esp -= 4;
    sub_49eb6c(app, cpu);
    if (cpu.terminate) return;
    // 0049ec2c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ec2e  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0049ec33  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ec37  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049ec39  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 0049ec3e  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0049ec40:
    // 0049ec40  8d5c2448               -lea ebx, [esp + 0x48]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049ec44  8d54246c               -lea edx, [esp + 0x6c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0049ec48  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049ec4a  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0049ec4f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049ec51  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049ec55  e8e6fbffff             -call 0x49e840
    cpu.esp -= 4;
    sub_49e840(app, cpu);
    if (cpu.terminate) return;
    // 0049ec5a  8d9c2490000000         -lea ebx, [esp + 0x90]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0049ec61  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049ec63  8b9584d44d00           -mov edx, dword ptr [ebp + 0x4dd484]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5100676) /* 0x4dd484 */);
    // 0049ec69  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ec6b  e828ffffff             -call 0x49eb98
    cpu.esp -= 4;
    sub_49eb98(app, cpu);
    if (cpu.terminate) return;
    // 0049ec70  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ec74  8d942490000000         -lea edx, [esp + 0x90]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0049ec7b  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ec7f  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ec82  e8b9feffff             -call 0x49eb40
    cpu.esp -= 4;
    sub_49eb40(app, cpu);
    if (cpu.terminate) return;
    // 0049ec87  83fd10                 +cmp ebp, 0x10
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
    // 0049ec8a  75b4                   -jne 0x49ec40
    if (!cpu.flags.zf)
    {
        goto L_0x0049ec40;
    }
    // 0049ec8c  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0049ec91  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049ec95  8bb424b8000000         -mov esi, dword ptr [esp + 0xb8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0049ec9c  8b9c24b8000000         -mov ebx, dword ptr [esp + 0xb8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0049eca3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049eca5  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049eca9  8b8c24b4000000         -mov ecx, dword ptr [esp + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0049ecb0  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049ecb4  41                     -inc ecx
    (cpu.ecx)++;
    // 0049ecb5  e886fbffff             -call 0x49e840
    cpu.esp -= 4;
    sub_49e840(app, cpu);
    if (cpu.terminate) return;
    // 0049ecba  898c24b4000000         -mov dword ptr [esp + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 0049ecc1  83f904                 +cmp ecx, 4
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
    // 0049ecc4  0f8c1affffff           -jl 0x49ebe4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ebe4;
    }
    // 0049ecca  81c4bc000000           -add esp, 0xbc
    (cpu.esp) += x86::reg32(x86::sreg32(188 /*0xbc*/));
    // 0049ecd0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecd1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecd2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecd3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecd5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49ecd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ecd8);
    // 0049ecd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ecd9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ecda  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ecdb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ecdc  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049ecdf  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049ece1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049ece3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ece5  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0049eceb  c0e507                 +shl ch, 7
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
    // 0049ecee  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ecf0  00ed                   +add ch, ch
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
    // 0049ecf2  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049ecf4  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ecf6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ecfb  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ecfd  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049ed04  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ed06  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ed08  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049ed0c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ed0e  c0e407                 +shl ah, 7
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
    // 0049ed11  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ed13  00e4                   +add ah, ah
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
    // 0049ed15  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049ed17  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ed19  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ed1e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ed20  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049ed27  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ed29  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ed2b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ed2d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049ed2f  7518                   -jne 0x49ed49
    if (!cpu.flags.zf)
    {
        goto L_0x0049ed49;
    }
    // 0049ed31  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0049ed36  be60d44d00             -mov esi, 0x4dd460
    cpu.esi = 5100640 /*0x4dd460*/;
    // 0049ed3b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049ed3d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ed3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ed41  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049ed44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ed49:
    // 0049ed49  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049ed4b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ed4d  e82e3e0100             -call 0x4b2b80
    cpu.esp -= 4;
    sub_4b2b80(app, cpu);
    if (cpu.terminate) return;
    // 0049ed52  bd00000100             -mov ebp, 0x10000
    cpu.ebp = 65536 /*0x10000*/;
    // 0049ed57  2b6c2414               -sub ebp, dword ptr [esp + 0x14]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0049ed5b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ed5e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ed60  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ed62  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ed65  c1e810                 +shr eax, 0x10
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
    // 0049ed68  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ed6a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ed6e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ed70  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ed72  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ed74  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ed77  c1e810                 +shr eax, 0x10
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
    // 0049ed7a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ed7c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049ed80  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049ed82  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ed84  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ed86  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ed89  c1e810                 +shr eax, 0x10
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
    // 0049ed8c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ed8e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ed91  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049ed93  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ed95  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ed97  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ed9a  c1e810                 +shr eax, 0x10
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
    // 0049ed9d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ed9f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049eda3  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049eda7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049eda9  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049edab  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049edae  c1e810                 +shr eax, 0x10
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
    // 0049edb1  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049edb3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049edb7  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049edbb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049edbd  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049edbf  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049edc2  c1e810                 +shr eax, 0x10
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
    // 0049edc5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049edc7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049edca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049edcc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049edce  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049edd0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049edd3  c1e810                 +shr eax, 0x10
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
    // 0049edd6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049edd8  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049eddc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049edde  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0049ede0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ede2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ede6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ede8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049edeb  c1e810                 +shr eax, 0x10
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
    // 0049edee  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049edf0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049edf2  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049edf5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049edf9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049edfb  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049edff  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ee01  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ee04  c1e810                 +shr eax, 0x10
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
    // 0049ee07  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ee09  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ee0b  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049ee0e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ee11  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ee13  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ee15  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ee18  c1e810                 +shr eax, 0x10
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
    // 0049ee1b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ee1d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ee1f  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049ee22  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ee26  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ee28  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ee2a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ee2d  c1e810                 +shr eax, 0x10
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
    // 0049ee30  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ee32  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049ee36  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ee38  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049ee3b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ee3d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049ee41  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ee43  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ee46  c1e810                 +shr eax, 0x10
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
    // 0049ee49  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ee4b  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049ee4f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ee51  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0049ee54  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ee56  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ee59  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ee5b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ee5e  c1e810                 +shr eax, 0x10
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
    // 0049ee61  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ee63  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0049ee66  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049ee69  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ee6b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ee6f  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049ee73  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ee75  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ee78  c1e810                 +shr eax, 0x10
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
    // 0049ee7b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ee7d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ee7f  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0049ee82  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049ee86  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ee88  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ee8a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ee8d  c1e810                 +shr eax, 0x10
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
    // 0049ee90  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ee92  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049ee96  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ee98  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049ee9b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ee9d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049eea0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eea1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eea2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eea3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eea4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49eea5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049eea5);
    // 0049eea5  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049eeab  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049eeae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49eeaf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049eeaf);
    // 0049eeaf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049eeb0  e8f0ffffff             -call 0x49eea5
    cpu.esp -= 4;
    sub_49eea5(app, cpu);
    if (cpu.terminate) return;
    // 0049eeb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049eeb7  7418                   -je 0x49eed1
    if (cpu.flags.zf)
    {
        goto L_0x0049eed1;
    }
    // 0049eeb9  69106d4ec641           -imul edx, dword ptr [eax], 0x41c64e6d
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))) * x86::sreg64(x86::sreg32(1103515245 /*0x41c64e6d*/)));
    // 0049eebf  81c239300000           -add edx, 0x3039
    (cpu.edx) += x86::reg32(x86::sreg32(12345 /*0x3039*/));
    // 0049eec5  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049eec7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049eec9  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049eecc  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
L_0x0049eed1:
    // 0049eed1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eed2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49eed3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049eed3);
    // 0049eed3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049eed4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049eed6  e8caffffff             -call 0x49eea5
    cpu.esp -= 4;
    sub_49eea5(app, cpu);
    if (cpu.terminate) return;
    // 0049eedb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049eedd  7402                   -je 0x49eee1
    if (cpu.flags.zf)
    {
        goto L_0x0049eee1;
    }
    // 0049eedf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0049eee1:
    // 0049eee1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eee2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49eee3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049eee3);
    // 0049eee3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049eee4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049eee5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049eee6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049eee7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049eee8  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049eeea  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0049eef0  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 0049eef6  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049eef8  8b35900d5700           -mov esi, dword ptr [0x570d90]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705104) /* 0x570d90 */);
    // 0049eefe  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049ef03  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ef05  740d                   -je 0x49ef14
    if (cpu.flags.zf)
    {
        goto L_0x0049ef14;
    }
    // 0049ef07  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049ef09  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049ef0e  893d900d5700           -mov dword ptr [0x570d90], edi
    app->getMemory<x86::reg32>(x86::reg32(5705104) /* 0x570d90 */) = cpu.edi;
L_0x0049ef14:
    // 0049ef14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ef15  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ef16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ef17  6874104d00             -push 0x4d1074
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050484 /*0x4d1074*/;
    cpu.esp -= 4;
    // 0049ef1c  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 0049ef21  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0049ef24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ef25  e8983d0100             -call 0x4b2cc2
    cpu.esp -= 4;
    sub_4b2cc2(app, cpu);
    if (cpu.terminate) return;
    // 0049ef2a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049ef2d  803d84014e0000         +cmp byte ptr [0x4e0184], 0
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
    // 0049ef34  0f84f8000000           -je 0x49f032
    if (cpu.flags.zf)
    {
        goto L_0x0049f032;
    }
    // 0049ef3a  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0049ef3d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049ef3e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049ef40  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049ef42  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ef44  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ef45  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ef47  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049ef49  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049ef4b  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ef4c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049ef4d  8d5117                 -lea edx, [ecx + 0x17]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 0049ef50  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0049ef53  e8953d0100             -call 0x4b2ced
    cpu.esp -= 4;
    sub_4b2ced(app, cpu);
    if (cpu.terminate) return;
    // 0049ef58  39c2                   +cmp edx, eax
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
    // 0049ef5a  733c                   -jae 0x49ef98
    if (!cpu.flags.cf)
    {
        goto L_0x0049ef98;
    }
    // 0049ef5c  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0049ef5f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049ef60  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049ef62  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049ef64  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ef66  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ef67  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ef69  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049ef6b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049ef6d  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ef6e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049ef6f  8d4117                 -lea eax, [ecx + 0x17]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 0049ef72  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0049ef74  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ef75  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0049ef78  e8bf3d0100             -call 0x4b2d3c
    cpu.esp -= 4;
    sub_4b2d3c(app, cpu);
    if (cpu.terminate) return;
    // 0049ef7d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049ef7e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049ef80  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049ef82  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ef84  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ef85  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ef87  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049ef89  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049ef8b  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ef8c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049ef8d  8d4117                 -lea eax, [ecx + 0x17]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 0049ef90  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0049ef92  29c4                   +sub esp, eax
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
    // 0049ef94  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0049ef96  eb02                   -jmp 0x49ef9a
    goto L_0x0049ef9a;
L_0x0049ef98:
    // 0049ef98  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049ef9a:
    // 0049ef9a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049ef9c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049ef9e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049efa0  be8c104d00             -mov esi, 0x4d108c
    cpu.esi = 5050508 /*0x4d108c*/;
    // 0049efa5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049efa6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049efa7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049efa8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049efa9  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 0049efab  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049efac  8d75fe                 -lea esi, [ebp - 2]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0049efaf  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049efb1  894d7e                 -mov dword ptr [ebp + 0x7e], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.ecx;
    // 0049efb4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049efb5  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 0049efb6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049efb7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049efb8  2bc9                   +sub ecx, ecx
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
    // 0049efba  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049efbb  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0049efbd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049efbf  4f                     -dec edi
    (cpu.edi)--;
L_0x0049efc0:
    // 0049efc0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049efc2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049efc4  3c00                   +cmp al, 0
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
    // 0049efc6  7410                   -je 0x49efd8
    if (cpu.flags.zf)
    {
        goto L_0x0049efd8;
    }
    // 0049efc8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049efcb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049efce  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049efd1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049efd4  3c00                   +cmp al, 0
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
    // 0049efd6  75e8                   -jne 0x49efc0
    if (!cpu.flags.zf)
    {
        goto L_0x0049efc0;
    }
L_0x0049efd8:
    // 0049efd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efd9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049efda  e80e3d0100             -call 0x4b2ced
    cpu.esp -= 4;
    sub_4b2ced(app, cpu);
    if (cpu.terminate) return;
    // 0049efdf  83f814                 +cmp eax, 0x14
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
    // 0049efe2  7612                   -jbe 0x49eff6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049eff6;
    }
    // 0049efe4  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0049efe6  e8513d0100             -call 0x4b2d3c
    cpu.esp -= 4;
    sub_4b2d3c(app, cpu);
    if (cpu.terminate) return;
    // 0049efeb  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0049eff0  29c4                   +sub esp, eax
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
    // 0049eff2  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0049eff4  eb02                   -jmp 0x49eff8
    goto L_0x0049eff8;
L_0x0049eff6:
    // 0049eff6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049eff8:
    // 0049eff8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049eff9  689f104d00             -push 0x4d109f
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050527 /*0x4d109f*/;
    cpu.esp -= 4;
    // 0049effe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049efff  e8fd74feff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0049f004  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049f007  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f008  2eff1554654c00         -call dword ptr cs:[0x4c6554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006676) /* 0x4c6554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f00f  803d84014e0000         +cmp byte ptr [0x4e0184], 0
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
    // 0049f016  7436                   -je 0x49f04e
    if (cpu.flags.zf)
    {
        goto L_0x0049f04e;
    }
    // 0049f018  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049f01a  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0049f01f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f020  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0049f023  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f024  cc                     -int3 
    NFS2_ASSERT(false);
    // 0049f025  eb06                   -jmp 0x49f02d
    goto L_0x0049f02d;
    // 0049f027  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f028  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f029  49                     -dec ecx
    (cpu.ecx)--;
    // 0049f02a  44                     -inc esp
    (cpu.esp)++;
    // 0049f02b  45                     -inc ebp
    (cpu.ebp)++;
    // 0049f02c  4f                     -dec edi
    (cpu.edi)--;
L_0x0049f02d:
    // 0049f02d  83c408                 +add esp, 8
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
    // 0049f030  eb1c                   -jmp 0x49f04e
    goto L_0x0049f04e;
L_0x0049f032:
    // 0049f032  6800200000             -push 0x2000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8192 /*0x2000*/;
    cpu.esp -= 4;
    // 0049f037  68b0104d00             -push 0x4d10b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050544 /*0x4d10b0*/;
    cpu.esp -= 4;
    // 0049f03c  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0049f03f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f040  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f042  2eff1504644c00         -call dword ptr cs:[0x4c6404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006340) /* 0x4c6404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f049  e8223d0100             -call 0x4b2d70
    cpu.esp -= 4;
    sub_4b2d70(app, cpu);
    if (cpu.terminate) return;
L_0x0049f04e:
    // 0049f04e  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 0049f054  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f055  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049f056  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f057  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f058  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f059  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f05a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f05a);
    // 0049f05a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f05b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f05d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f05f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049f061  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049f063  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f065  750f                   -jne 0x49f076
    if (!cpu.flags.zf)
    {
        goto L_0x0049f076;
    }
    // 0049f067  c705900d570001000000   -mov dword ptr [0x570d90], 1
    app->getMemory<x86::reg32>(x86::reg32(5705104) /* 0x570d90 */) = 1 /*0x1*/;
    // 0049f071  e86dfeffff             -call 0x49eee3
    cpu.esp -= 4;
    sub_49eee3(app, cpu);
    if (cpu.terminate) return;
L_0x0049f076:
    // 0049f076  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f077  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49f080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f080);
    // 0049f080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f083  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0049f089  8b842414040000         -mov eax, dword ptr [esp + 0x414]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 0049f090  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f092  7415                   -je 0x49f0a9
    if (cpu.flags.zf)
    {
        goto L_0x0049f0a9;
    }
    // 0049f094  8b942418040000         -mov edx, dword ptr [esp + 0x418]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 0049f09b  3b10                   +cmp edx, dword ptr [eax]
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
    // 0049f09d  7e0a                   -jle 0x49f0a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f0a9;
    }
L_0x0049f09f:
    // 0049f09f  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0049f0a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f0a9:
    // 0049f0a9  8d842420040000         -lea eax, [esp + 0x420]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1056) /* 0x420 */);
    // 0049f0b0  8d9c2400040000         -lea ebx, [esp + 0x400]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 0049f0b7  8b94241c040000         -mov edx, dword ptr [esp + 0x41c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 0049f0be  89842400040000         -mov dword ptr [esp + 0x400], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.eax;
    // 0049f0c5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049f0c7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f0c9  e8b64f0000             -call 0x4a4084
    cpu.esp -= 4;
    sub_4a4084(app, cpu);
    if (cpu.terminate) return;
    // 0049f0ce  a1b4d54d00             -mov eax, dword ptr [0x4dd5b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100980) /* 0x4dd5b4 */);
    // 0049f0d3  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 0049f0da  83f802                 +cmp eax, 2
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
    // 0049f0dd  7319                   -jae 0x49f0f8
    if (!cpu.flags.cf)
    {
        goto L_0x0049f0f8;
    }
    // 0049f0df  83f801                 +cmp eax, 1
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
    // 0049f0e2  75bb                   -jne 0x49f09f
    if (!cpu.flags.zf)
    {
        goto L_0x0049f09f;
    }
    // 0049f0e4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049f0e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f0e7  2eff1554654c00         -call dword ptr cs:[0x4c6554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006676) /* 0x4c6554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f0ee  81c404040000           +add esp, 0x404
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
    // 0049f0f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f0f8:
    // 0049f0f8  761a                   -jbe 0x49f114
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049f114;
    }
    // 0049f0fa  83f803                 +cmp eax, 3
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
    // 0049f0fd  75a0                   -jne 0x49f09f
    if (!cpu.flags.zf)
    {
        goto L_0x0049f09f;
    }
    // 0049f0ff  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049f101  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f102  e819fbfeff             -call 0x48ec20
    cpu.esp -= 4;
    sub_48ec20(app, cpu);
    if (cpu.terminate) return;
    // 0049f107  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f10a  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0049f110  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f111  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f112  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f113  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f114:
    // 0049f114  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049f116  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f117  e860bcffff             -call 0x49ad7c
    cpu.esp -= 4;
    sub_49ad7c(app, cpu);
    if (cpu.terminate) return;
    // 0049f11c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f11f  b85eeb4d00             -mov eax, 0x4deb5e
    cpu.eax = 5106526 /*0x4deb5e*/;
    // 0049f124  e85f3c0100             -call 0x4b2d88
    cpu.esp -= 4;
    sub_4b2d88(app, cpu);
    if (cpu.terminate) return;
    // 0049f129  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0049f12f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f130  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f131  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f132  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f133(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f133);
    // 0049f133  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f134  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0049f136:
    // 0049f136  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049f138  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0049f13a  3c41                   +cmp al, 0x41
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
    // 0049f13c  7206                   -jb 0x49f144
    if (cpu.flags.cf)
    {
        goto L_0x0049f144;
    }
    // 0049f13e  3c5a                   +cmp al, 0x5a
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
    // 0049f140  7702                   -ja 0x49f144
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f144;
    }
    // 0049f142  0420                   -add al, 0x20
    (cpu.al) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0049f144:
    // 0049f144  80fc41                 +cmp ah, 0x41
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
    // 0049f147  7208                   -jb 0x49f151
    if (cpu.flags.cf)
    {
        goto L_0x0049f151;
    }
    // 0049f149  80fc5a                 +cmp ah, 0x5a
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
    // 0049f14c  7703                   -ja 0x49f151
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f151;
    }
    // 0049f14e  80c420                 -add ah, 0x20
    (cpu.ah) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0049f151:
    // 0049f151  38e0                   +cmp al, ah
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
    // 0049f153  7508                   -jne 0x49f15d
    if (!cpu.flags.zf)
    {
        goto L_0x0049f15d;
    }
    // 0049f155  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0049f157  7404                   -je 0x49f15d
    if (cpu.flags.zf)
    {
        goto L_0x0049f15d;
    }
    // 0049f159  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049f15a  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049f15b  ebd9                   -jmp 0x49f136
    goto L_0x0049f136;
L_0x0049f15d:
    // 0049f15d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f15f  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049f161  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 0049f163  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049f168  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f16a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f16c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f16d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_49f170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f170);
    // 0049f170  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f171  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f172  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f173  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f176  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049f17a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049f17d  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049f181  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0049f186  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f188  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0049f18a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049f18e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f193  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049f198  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049f19a  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049f19e  a3a80d5700             -mov dword ptr [0x570da8], eax
    app->getMemory<x86::reg32>(x86::reg32(5705128) /* 0x570da8 */) = cpu.eax;
    // 0049f1a3  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049f1a5  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049f1a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f1ae  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f1b0  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049f1b2  a3ac0d5700             -mov dword ptr [0x570dac], eax
    app->getMemory<x86::reg32>(x86::reg32(5705132) /* 0x570dac */) = cpu.eax;
    // 0049f1b7  a1a80d5700             -mov eax, dword ptr [0x570da8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705128) /* 0x570da8 */);
    // 0049f1bc  a3ec0d5700             -mov dword ptr [0x570dec], eax
    app->getMemory<x86::reg32>(x86::reg32(5705196) /* 0x570dec */) = cpu.eax;
    // 0049f1c1  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049f1c4  8b15a80d5700           -mov edx, dword ptr [0x570da8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705128) /* 0x570da8 */);
    // 0049f1ca  891da40d5700           -mov dword ptr [0x570da4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705124) /* 0x570da4 */) = cpu.ebx;
    // 0049f1d0  a3f00d5700             -mov dword ptr [0x570df0], eax
    app->getMemory<x86::reg32>(x86::reg32(5705200) /* 0x570df0 */) = cpu.eax;
    // 0049f1d5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f1d9  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049f1dd  e872070000             -call 0x49f954
    cpu.esp -= 4;
    sub_49f954(app, cpu);
    if (cpu.terminate) return;
    // 0049f1e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f1e4  8b1da40d5700           -mov ebx, dword ptr [0x570da4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705124) /* 0x570da4 */);
    // 0049f1ea  8915a00d5700           -mov dword ptr [0x570da0], edx
    app->getMemory<x86::reg32>(x86::reg32(5705120) /* 0x570da0 */) = cpu.edx;
    // 0049f1f0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f1f2  7e23                   -jle 0x49f217
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f217;
    }
L_0x0049f1f4:
    // 0049f1f4  a1a00d5700             -mov eax, dword ptr [0x570da0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705120) /* 0x570da0 */);
    // 0049f1f9  80b864ac4d0000         +cmp byte ptr [eax + 0x4dac64], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5090404) /* 0x4dac64 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049f200  7524                   -jne 0x49f226
    if (!cpu.flags.zf)
    {
        goto L_0x0049f226;
    }
L_0x0049f202:
    // 0049f202  8b35a00d5700           -mov esi, dword ptr [0x570da0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705120) /* 0x570da0 */);
    // 0049f208  46                     -inc esi
    (cpu.esi)++;
    // 0049f209  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049f20d  8935a00d5700           -mov dword ptr [0x570da0], esi
    app->getMemory<x86::reg32>(x86::reg32(5705120) /* 0x570da0 */) = cpu.esi;
    // 0049f213  39fe                   +cmp esi, edi
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
    // 0049f215  7cdd                   -jl 0x49f1f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f1f4;
    }
L_0x0049f217:
    // 0049f217  891da40d5700           -mov dword ptr [0x570da4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705124) /* 0x570da4 */) = cpu.ebx;
    // 0049f21d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f220  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f221  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f222  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f223  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049f226:
    // 0049f226  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049f229  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f22c  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f22e  0fb67702               -movzx esi, byte ptr [edi + 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */));
    // 0049f232  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049f236  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f238  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049f23a  0fb66f01               -movzx ebp, byte ptr [edi + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */));
    // 0049f23e  a3d80d5700             -mov dword ptr [0x570dd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5705176) /* 0x570dd8 */) = cpu.eax;
    // 0049f243  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049f245  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049f247  0fb63f                 -movzx edi, byte ptr [edi]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0049f24a  a3c80d5700             -mov dword ptr [0x570dc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5705160) /* 0x570dc8 */) = cpu.eax;
    // 0049f24f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049f251  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049f253  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049f255  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049f258  a3cc0d5700             -mov dword ptr [0x570dcc], eax
    app->getMemory<x86::reg32>(x86::reg32(5705164) /* 0x570dcc */) = cpu.eax;
    // 0049f25d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049f25f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f261  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0049f263  8b0dd80d5700           -mov ecx, dword ptr [0x570dd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705176) /* 0x570dd8 */);
    // 0049f269  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049f26c  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0049f26f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049f271  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049f274  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f276  8b15c80d5700           -mov edx, dword ptr [0x570dc8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705160) /* 0x570dc8 */);
    // 0049f27c  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049f27f  890ddc0d5700           -mov dword ptr [0x570ddc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */) = cpu.ecx;
    // 0049f285  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049f287  0fafeb                 -imul ebp, ebx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049f28a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f28c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f28e  8b15cc0d5700           -mov edx, dword ptr [0x570dcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705164) /* 0x570dcc */);
    // 0049f294  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049f297  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049f299  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049f29b  0faffb                 -imul edi, ebx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049f29e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f2a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f2a2  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049f2a5  8915d40d5700           -mov dword ptr [0x570dd4], edx
    app->getMemory<x86::reg32>(x86::reg32(5705172) /* 0x570dd4 */) = cpu.edx;
    // 0049f2ab  8b15dc0d5700           -mov edx, dword ptr [0x570ddc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */);
    // 0049f2b1  0fafd2                 -imul edx, edx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049f2b4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f2b6  a1d40d5700             -mov eax, dword ptr [0x570dd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705172) /* 0x570dd4 */);
    // 0049f2bb  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049f2be  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f2c0  a1d80d5700             -mov eax, dword ptr [0x570dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705176) /* 0x570dd8 */);
    // 0049f2c5  8915d40d5700           -mov dword ptr [0x570dd4], edx
    app->getMemory<x86::reg32>(x86::reg32(5705172) /* 0x570dd4 */) = cpu.edx;
    // 0049f2cb  8b15ac0d5700           -mov edx, dword ptr [0x570dac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705132) /* 0x570dac */);
    // 0049f2d1  40                     -inc eax
    (cpu.eax)++;
    // 0049f2d2  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049f2d5  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f2d7  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f2d9  a3b00d5700             -mov dword ptr [0x570db0], eax
    app->getMemory<x86::reg32>(x86::reg32(5705136) /* 0x570db0 */) = cpu.eax;
    // 0049f2de  a1c80d5700             -mov eax, dword ptr [0x570dc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705160) /* 0x570dc8 */);
    // 0049f2e3  40                     -inc eax
    (cpu.eax)++;
    // 0049f2e4  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049f2e7  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049f2e9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f2eb  a3b80d5700             -mov dword ptr [0x570db8], eax
    app->getMemory<x86::reg32>(x86::reg32(5705144) /* 0x570db8 */) = cpu.eax;
    // 0049f2f0  a1cc0d5700             -mov eax, dword ptr [0x570dcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705164) /* 0x570dcc */);
    // 0049f2f5  40                     -inc eax
    (cpu.eax)++;
    // 0049f2f6  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049f2f9  8b35d80d5700           -mov esi, dword ptr [0x570dd8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705176) /* 0x570dd8 */);
    // 0049f2ff  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f301  0faf35f00d5700         -imul esi, dword ptr [0x570df0]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705200) /* 0x570df0 */))));
    // 0049f308  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f30a  a3b40d5700             -mov dword ptr [0x570db4], eax
    app->getMemory<x86::reg32>(x86::reg32(5705140) /* 0x570db4 */) = cpu.eax;
    // 0049f30f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f313  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0049f31a  8b15ec0d5700           -mov edx, dword ptr [0x570dec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705196) /* 0x570dec */);
    // 0049f320  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f322  a1c80d5700             -mov eax, dword ptr [0x570dc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705160) /* 0x570dc8 */);
    // 0049f327  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049f32a  890de80d5700           -mov dword ptr [0x570de8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */) = cpu.ecx;
    // 0049f330  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049f334  891da40d5700           -mov dword ptr [0x570da4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705124) /* 0x570da4 */) = cpu.ebx;
    // 0049f33a  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f33c  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 0049f343  8b15cc0d5700           -mov edx, dword ptr [0x570dcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705164) /* 0x570dcc */);
    // 0049f349  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049f34b  8b3dcc0d5700           -mov edi, dword ptr [0x570dcc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705164) /* 0x570dcc */);
    // 0049f351  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049f353  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0049f356  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f358  01fd                   +add ebp, edi
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
    // 0049f35a  8915c40d5700           -mov dword ptr [0x570dc4], edx
    app->getMemory<x86::reg32>(x86::reg32(5705156) /* 0x570dc4 */) = cpu.edx;
    // 0049f360  892dc00d5700           -mov dword ptr [0x570dc0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705152) /* 0x570dc0 */) = cpu.ebp;
    // 0049f366  e80d000000             -call 0x49f378
    cpu.esp -= 4;
    sub_49f378(app, cpu);
    if (cpu.terminate) return;
    // 0049f36b  8b1da40d5700           -mov ebx, dword ptr [0x570da4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705124) /* 0x570da4 */);
    // 0049f371  e98cfeffff             -jmp 0x49f202
    goto L_0x0049f202;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49f378(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f378);
    // 0049f378  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f379  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f37a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f37b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f37c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f37d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f37e  8b1dac0d5700           -mov ebx, dword ptr [0x570dac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705132) /* 0x570dac */);
    // 0049f384  8b0dd80d5700           -mov ecx, dword ptr [0x570dd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705176) /* 0x570dd8 */);
    // 0049f38a  a1d40d5700             -mov eax, dword ptr [0x570dd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705172) /* 0x570dd4 */);
    // 0049f38f  8b35b00d5700           -mov esi, dword ptr [0x570db0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705136) /* 0x570db0 */);
    // 0049f395  8b3da80d5700           -mov edi, dword ptr [0x570da8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705128) /* 0x570da8 */);
    // 0049f39b  a3dc0d5700             -mov dword ptr [0x570ddc], eax
    app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */) = cpu.eax;
    // 0049f3a0  a1c00d5700             -mov eax, dword ptr [0x570dc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705152) /* 0x570dc0 */);
    // 0049f3a5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f3a7  a3bc0d5700             -mov dword ptr [0x570dbc], eax
    app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */) = cpu.eax;
    // 0049f3ac  a1c40d5700             -mov eax, dword ptr [0x570dc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705156) /* 0x570dc4 */);
    // 0049f3b1  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f3b3  a3e00d5700             -mov dword ptr [0x570de0], eax
    app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */) = cpu.eax;
    // 0049f3b8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f3bd  39f9                   +cmp ecx, edi
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
    // 0049f3bf  0f8cc0000000           -jl 0x49f485
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f485;
    }
L_0x0049f3c5:
    // 0049f3c5  8b35b00d5700           -mov esi, dword ptr [0x570db0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705136) /* 0x570db0 */);
    // 0049f3cb  a1d40d5700             -mov eax, dword ptr [0x570dd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705172) /* 0x570dd4 */);
    // 0049f3d0  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f3d2  8b3df00d5700           -mov edi, dword ptr [0x570df0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705200) /* 0x570df0 */);
    // 0049f3d8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f3da  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0049f3dd  a3dc0d5700             -mov dword ptr [0x570ddc], eax
    app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */) = cpu.eax;
    // 0049f3e2  a1c00d5700             -mov eax, dword ptr [0x570dc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705152) /* 0x570dc0 */);
    // 0049f3e7  8b0dd80d5700           -mov ecx, dword ptr [0x570dd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705176) /* 0x570dd8 */);
    // 0049f3ed  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f3ef  8b2df00d5700           -mov ebp, dword ptr [0x570df0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705200) /* 0x570df0 */);
    // 0049f3f5  a3bc0d5700             -mov dword ptr [0x570dbc], eax
    app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */) = cpu.eax;
    // 0049f3fa  a1c40d5700             -mov eax, dword ptr [0x570dc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705156) /* 0x570dc4 */);
    // 0049f3ff  49                     -dec ecx
    (cpu.ecx)--;
    // 0049f400  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049f402  8935f40d5700           -mov dword ptr [0x570df4], esi
    app->getMemory<x86::reg32>(x86::reg32(5705204) /* 0x570df4 */) = cpu.esi;
    // 0049f408  a3e00d5700             -mov dword ptr [0x570de0], eax
    app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */) = cpu.eax;
    // 0049f40d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f412  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f414  7c60                   -jl 0x49f476
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f476;
    }
L_0x0049f416:
    // 0049f416  e8f5000000             -call 0x49f510
    cpu.esp -= 4;
    sub_49f510(app, cpu);
    if (cpu.terminate) return;
    // 0049f41b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f41d  0f84dd000000           -je 0x49f500
    if (cpu.flags.zf)
    {
        goto L_0x0049f500;
    }
    // 0049f423  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0049f428:
    // 0049f428  a1f00d5700             -mov eax, dword ptr [0x570df0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705200) /* 0x570df0 */);
    // 0049f42d  8b35bc0d5700           -mov esi, dword ptr [0x570dbc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */);
    // 0049f433  8b3de00d5700           -mov edi, dword ptr [0x570de0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */);
    // 0049f439  8b2ddc0d5700           -mov ebp, dword ptr [0x570ddc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */);
    // 0049f43f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f442  49                     -dec ecx
    (cpu.ecx)--;
    // 0049f443  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f445  a1f00d5700             -mov eax, dword ptr [0x570df0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705200) /* 0x570df0 */);
    // 0049f44a  8935bc0d5700           -mov dword ptr [0x570dbc], esi
    app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */) = cpu.esi;
    // 0049f450  8b35f40d5700           -mov esi, dword ptr [0x570df4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705204) /* 0x570df4 */);
    // 0049f456  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f458  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f45a  893de00d5700           -mov dword ptr [0x570de0], edi
    app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */) = cpu.edi;
    // 0049f460  8935f40d5700           -mov dword ptr [0x570df4], esi
    app->getMemory<x86::reg32>(x86::reg32(5705204) /* 0x570df4 */) = cpu.esi;
    // 0049f466  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f468  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f46a  892ddc0d5700           -mov dword ptr [0x570ddc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */) = cpu.ebp;
    // 0049f470  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f472  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f474  7da0                   -jge 0x49f416
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f416;
    }
L_0x0049f476:
    // 0049f476  8b35f40d5700           -mov esi, dword ptr [0x570df4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705204) /* 0x570df4 */);
    // 0049f47c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f47e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f47f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f480  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f481  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f482  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f483  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f484  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f485:
    // 0049f485  8935f40d5700           -mov dword ptr [0x570df4], esi
    app->getMemory<x86::reg32>(x86::reg32(5705204) /* 0x570df4 */) = cpu.esi;
L_0x0049f48b:
    // 0049f48b  e880000000             -call 0x49f510
    cpu.esp -= 4;
    sub_49f510(app, cpu);
    if (cpu.terminate) return;
    // 0049f490  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f492  745c                   -je 0x49f4f0
    if (cpu.flags.zf)
    {
        goto L_0x0049f4f0;
    }
    // 0049f494  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049f499  8b35f40d5700           -mov esi, dword ptr [0x570df4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705204) /* 0x570df4 */);
L_0x0049f49f:
    // 0049f49f  a1f00d5700             -mov eax, dword ptr [0x570df0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705200) /* 0x570df0 */);
    // 0049f4a4  8b2dbc0d5700           -mov ebp, dword ptr [0x570dbc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */);
    // 0049f4aa  8b3de00d5700           -mov edi, dword ptr [0x570de0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */);
    // 0049f4b0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f4b3  41                     -inc ecx
    (cpu.ecx)++;
    // 0049f4b4  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f4b6  a1f00d5700             -mov eax, dword ptr [0x570df0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705200) /* 0x570df0 */);
    // 0049f4bb  892dbc0d5700           -mov dword ptr [0x570dbc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */) = cpu.ebp;
    // 0049f4c1  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f4c3  8b2ddc0d5700           -mov ebp, dword ptr [0x570ddc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */);
    // 0049f4c9  893de00d5700           -mov dword ptr [0x570de0], edi
    app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */) = cpu.edi;
    // 0049f4cf  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049f4d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f4d3  8b3da80d5700           -mov edi, dword ptr [0x570da8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705128) /* 0x570da8 */);
    // 0049f4d9  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f4db  892ddc0d5700           -mov dword ptr [0x570ddc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */) = cpu.ebp;
    // 0049f4e1  8935f40d5700           -mov dword ptr [0x570df4], esi
    app->getMemory<x86::reg32>(x86::reg32(5705204) /* 0x570df4 */) = cpu.esi;
    // 0049f4e7  39f9                   +cmp ecx, edi
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
    // 0049f4e9  7ca0                   -jl 0x49f48b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f48b;
    }
    // 0049f4eb  e9d5feffff             -jmp 0x49f3c5
    goto L_0x0049f3c5;
L_0x0049f4f0:
    // 0049f4f0  8b35f40d5700           -mov esi, dword ptr [0x570df4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705204) /* 0x570df4 */);
    // 0049f4f6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f4f8  0f85c7feffff           -jne 0x49f3c5
    if (!cpu.flags.zf)
    {
        goto L_0x0049f3c5;
    }
    // 0049f4fe  eb9f                   -jmp 0x49f49f
    goto L_0x0049f49f;
L_0x0049f500:
    // 0049f500  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f502  0f856effffff           -jne 0x49f476
    if (!cpu.flags.zf)
    {
        goto L_0x0049f476;
    }
    // 0049f508  e91bffffff             -jmp 0x49f428
    goto L_0x0049f428;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49f510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f510);
    // 0049f510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f512  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f513  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f514  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f515  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f516  8b35ac0d5700           -mov esi, dword ptr [0x570dac]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705132) /* 0x570dac */);
    // 0049f51c  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049f51e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f520  0f855d020000           -jne 0x49f783
    if (!cpu.flags.zf)
    {
        goto L_0x0049f783;
    }
L_0x0049f526:
    // 0049f526  8b0df80d5700           -mov ecx, dword ptr [0x570df8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705208) /* 0x570df8 */);
    // 0049f52c  a1dc0d5700             -mov eax, dword ptr [0x570ddc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */);
    // 0049f531  8b1d040e5700           -mov ebx, dword ptr [0x570e04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705220) /* 0x570e04 */);
    // 0049f537  a3e80d5700             -mov dword ptr [0x570de8], eax
    app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */) = cpu.eax;
    // 0049f53c  a30c0e5700             -mov dword ptr [0x570e0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5705228) /* 0x570e0c */) = cpu.eax;
    // 0049f541  a1bc0d5700             -mov eax, dword ptr [0x570dbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */);
    // 0049f546  8b3d000e5700           -mov edi, dword ptr [0x570e00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705216) /* 0x570e00 */);
    // 0049f54c  a3d00d5700             -mov dword ptr [0x570dd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */) = cpu.eax;
    // 0049f551  a3100e5700             -mov dword ptr [0x570e10], eax
    app->getMemory<x86::reg32>(x86::reg32(5705232) /* 0x570e10 */) = cpu.eax;
    // 0049f556  a1e00d5700             -mov eax, dword ptr [0x570de0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */);
    // 0049f55b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f55d  a3e40d5700             -mov dword ptr [0x570de4], eax
    app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */) = cpu.eax;
    // 0049f562  a3140e5700             -mov dword ptr [0x570e14], eax
    app->getMemory<x86::reg32>(x86::reg32(5705236) /* 0x570e14 */) = cpu.eax;
    // 0049f567  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f56c  39f9                   +cmp ecx, edi
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
    // 0049f56e  0f8fce000000           -jg 0x49f642
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f642;
    }
    // 0049f574  891d080e5700           -mov dword ptr [0x570e08], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705224) /* 0x570e08 */) = cpu.ebx;
L_0x0049f57a:
    // 0049f57a  e84d020000             -call 0x49f7cc
    cpu.esp -= 4;
    sub_49f7cc(app, cpu);
    if (cpu.terminate) return;
    // 0049f57f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f581  0f8428020000           -je 0x49f7af
    if (cpu.flags.zf)
    {
        goto L_0x0049f7af;
    }
    // 0049f587  8b1d080e5700           -mov ebx, dword ptr [0x570e08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705224) /* 0x570e08 */);
    // 0049f58d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f58f  7537                   -jne 0x49f5c8
    if (!cpu.flags.zf)
    {
        goto L_0x0049f5c8;
    }
    // 0049f591  3b0df80d5700           +cmp ecx, dword ptr [0x570df8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705208) /* 0x570df8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f597  7e2a                   -jle 0x49f5c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f5c3;
    }
    // 0049f599  a1100e5700             -mov eax, dword ptr [0x570e10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705232) /* 0x570e10 */);
    // 0049f59e  a3bc0d5700             -mov dword ptr [0x570dbc], eax
    app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */) = cpu.eax;
    // 0049f5a3  a1140e5700             -mov eax, dword ptr [0x570e14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705236) /* 0x570e14 */);
    // 0049f5a8  890df80d5700           -mov dword ptr [0x570df8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705208) /* 0x570df8 */) = cpu.ecx;
    // 0049f5ae  a3e00d5700             -mov dword ptr [0x570de0], eax
    app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */) = cpu.eax;
    // 0049f5b3  a10c0e5700             -mov eax, dword ptr [0x570e0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705228) /* 0x570e0c */);
    // 0049f5b8  891d040e5700           -mov dword ptr [0x570e04], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705220) /* 0x570e04 */) = cpu.ebx;
    // 0049f5be  a3dc0d5700             -mov dword ptr [0x570ddc], eax
    app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */) = cpu.eax;
L_0x0049f5c3:
    // 0049f5c3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0049f5c8:
    // 0049f5c8  a1ec0d5700             -mov eax, dword ptr [0x570dec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705196) /* 0x570dec */);
    // 0049f5cd  8b2dd00d5700           -mov ebp, dword ptr [0x570dd0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */);
    // 0049f5d3  8b3d100e5700           -mov edi, dword ptr [0x570e10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705232) /* 0x570e10 */);
    // 0049f5d9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f5dc  41                     -inc ecx
    (cpu.ecx)++;
    // 0049f5dd  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f5df  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f5e1  a1ec0d5700             -mov eax, dword ptr [0x570dec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705196) /* 0x570dec */);
    // 0049f5e6  892dd00d5700           -mov dword ptr [0x570dd0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */) = cpu.ebp;
    // 0049f5ec  893d100e5700           -mov dword ptr [0x570e10], edi
    app->getMemory<x86::reg32>(x86::reg32(5705232) /* 0x570e10 */) = cpu.edi;
    // 0049f5f2  8b2de40d5700           -mov ebp, dword ptr [0x570de4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */);
    // 0049f5f8  8b3d140e5700           -mov edi, dword ptr [0x570e14]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705236) /* 0x570e14 */);
    // 0049f5fe  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f600  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f602  892de40d5700           -mov dword ptr [0x570de4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */) = cpu.ebp;
    // 0049f608  893d140e5700           -mov dword ptr [0x570e14], edi
    app->getMemory<x86::reg32>(x86::reg32(5705236) /* 0x570e14 */) = cpu.edi;
    // 0049f60e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f610  8b2de80d5700           -mov ebp, dword ptr [0x570de8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */);
    // 0049f616  8b3d0c0e5700           -mov edi, dword ptr [0x570e0c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705228) /* 0x570e0c */);
    // 0049f61c  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f61e  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f620  892de80d5700           -mov dword ptr [0x570de8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */) = cpu.ebp;
    // 0049f626  893d0c0e5700           -mov dword ptr [0x570e0c], edi
    app->getMemory<x86::reg32>(x86::reg32(5705228) /* 0x570e0c */) = cpu.edi;
    // 0049f62c  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049f62e  8b2d000e5700           -mov ebp, dword ptr [0x570e00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705216) /* 0x570e00 */);
    // 0049f634  891d080e5700           -mov dword ptr [0x570e08], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705224) /* 0x570e08 */) = cpu.ebx;
    // 0049f63a  39e9                   +cmp ecx, ebp
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
    // 0049f63c  0f8e38ffffff           -jle 0x49f57a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f57a;
    }
L_0x0049f642:
    // 0049f642  8b0df80d5700           -mov ecx, dword ptr [0x570df8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705208) /* 0x570df8 */);
    // 0049f648  8b1d040e5700           -mov ebx, dword ptr [0x570e04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705220) /* 0x570e04 */);
    // 0049f64e  a1dc0d5700             -mov eax, dword ptr [0x570ddc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */);
    // 0049f653  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f655  8b3dec0d5700           -mov edi, dword ptr [0x570dec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705196) /* 0x570dec */);
    // 0049f65b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f65d  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0049f660  a3e80d5700             -mov dword ptr [0x570de8], eax
    app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */) = cpu.eax;
    // 0049f665  a30c0e5700             -mov dword ptr [0x570e0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5705228) /* 0x570e0c */) = cpu.eax;
    // 0049f66a  a1bc0d5700             -mov eax, dword ptr [0x570dbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */);
    // 0049f66f  8b2dfc0d5700           -mov ebp, dword ptr [0x570dfc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705212) /* 0x570dfc */);
    // 0049f675  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f677  8b3dec0d5700           -mov edi, dword ptr [0x570dec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705196) /* 0x570dec */);
    // 0049f67d  a3d00d5700             -mov dword ptr [0x570dd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */) = cpu.eax;
    // 0049f682  a3100e5700             -mov dword ptr [0x570e10], eax
    app->getMemory<x86::reg32>(x86::reg32(5705232) /* 0x570e10 */) = cpu.eax;
    // 0049f687  a1e00d5700             -mov eax, dword ptr [0x570de0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */);
    // 0049f68c  49                     -dec ecx
    (cpu.ecx)--;
    // 0049f68d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f68f  891d080e5700           -mov dword ptr [0x570e08], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705224) /* 0x570e08 */) = cpu.ebx;
    // 0049f695  a3e40d5700             -mov dword ptr [0x570de4], eax
    app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */) = cpu.eax;
    // 0049f69a  a3140e5700             -mov dword ptr [0x570e14], eax
    app->getMemory<x86::reg32>(x86::reg32(5705236) /* 0x570e14 */) = cpu.eax;
    // 0049f69f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f6a4  39e9                   +cmp ecx, ebp
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
    // 0049f6a6  0f8cc8000000           -jl 0x49f774
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f774;
    }
L_0x0049f6ac:
    // 0049f6ac  e81b010000             -call 0x49f7cc
    cpu.esp -= 4;
    sub_49f7cc(app, cpu);
    if (cpu.terminate) return;
    // 0049f6b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f6b3  0f8409010000           -je 0x49f7c2
    if (cpu.flags.zf)
    {
        goto L_0x0049f7c2;
    }
    // 0049f6b9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f6bb  7535                   -jne 0x49f6f2
    if (!cpu.flags.zf)
    {
        goto L_0x0049f6f2;
    }
    // 0049f6bd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049f6c2  a1100e5700             -mov eax, dword ptr [0x570e10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705232) /* 0x570e10 */);
    // 0049f6c7  8b1d080e5700           -mov ebx, dword ptr [0x570e08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705224) /* 0x570e08 */);
    // 0049f6cd  a3bc0d5700             -mov dword ptr [0x570dbc], eax
    app->getMemory<x86::reg32>(x86::reg32(5705148) /* 0x570dbc */) = cpu.eax;
    // 0049f6d2  a1140e5700             -mov eax, dword ptr [0x570e14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705236) /* 0x570e14 */);
    // 0049f6d7  890df80d5700           -mov dword ptr [0x570df8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705208) /* 0x570df8 */) = cpu.ecx;
    // 0049f6dd  a3e00d5700             -mov dword ptr [0x570de0], eax
    app->getMemory<x86::reg32>(x86::reg32(5705184) /* 0x570de0 */) = cpu.eax;
    // 0049f6e2  a10c0e5700             -mov eax, dword ptr [0x570e0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705228) /* 0x570e0c */);
    // 0049f6e7  891d040e5700           -mov dword ptr [0x570e04], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705220) /* 0x570e04 */) = cpu.ebx;
    // 0049f6ed  a3dc0d5700             -mov dword ptr [0x570ddc], eax
    app->getMemory<x86::reg32>(x86::reg32(5705180) /* 0x570ddc */) = cpu.eax;
L_0x0049f6f2:
    // 0049f6f2  a1ec0d5700             -mov eax, dword ptr [0x570dec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705196) /* 0x570dec */);
    // 0049f6f7  8b1dd00d5700           -mov ebx, dword ptr [0x570dd0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */);
    // 0049f6fd  8b3d100e5700           -mov edi, dword ptr [0x570e10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705232) /* 0x570e10 */);
    // 0049f703  8b2de40d5700           -mov ebp, dword ptr [0x570de4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */);
    // 0049f709  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f70c  49                     -dec ecx
    (cpu.ecx)--;
    // 0049f70d  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f70f  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f711  a1ec0d5700             -mov eax, dword ptr [0x570dec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705196) /* 0x570dec */);
    // 0049f716  891dd00d5700           -mov dword ptr [0x570dd0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */) = cpu.ebx;
    // 0049f71c  893d100e5700           -mov dword ptr [0x570e10], edi
    app->getMemory<x86::reg32>(x86::reg32(5705232) /* 0x570e10 */) = cpu.edi;
    // 0049f722  8b1d140e5700           -mov ebx, dword ptr [0x570e14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705236) /* 0x570e14 */);
    // 0049f728  8b3de80d5700           -mov edi, dword ptr [0x570de8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */);
    // 0049f72e  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f730  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f732  891d140e5700           -mov dword ptr [0x570e14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705236) /* 0x570e14 */) = cpu.ebx;
    // 0049f738  8b1d080e5700           -mov ebx, dword ptr [0x570e08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705224) /* 0x570e08 */);
    // 0049f73e  892de40d5700           -mov dword ptr [0x570de4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */) = cpu.ebp;
    // 0049f744  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f746  8b2d0c0e5700           -mov ebp, dword ptr [0x570e0c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705228) /* 0x570e0c */);
    // 0049f74c  891d080e5700           -mov dword ptr [0x570e08], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705224) /* 0x570e08 */) = cpu.ebx;
    // 0049f752  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049f754  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f756  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f758  893de80d5700           -mov dword ptr [0x570de8], edi
    app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */) = cpu.edi;
    // 0049f75e  892d0c0e5700           -mov dword ptr [0x570e0c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705228) /* 0x570e0c */) = cpu.ebp;
    // 0049f764  8b3dfc0d5700           -mov edi, dword ptr [0x570dfc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705212) /* 0x570dfc */);
    // 0049f76a  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f76c  39f9                   +cmp ecx, edi
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
    // 0049f76e  0f8d38ffffff           -jge 0x49f6ac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f6ac;
    }
L_0x0049f774:
    // 0049f774  8b1d080e5700           -mov ebx, dword ptr [0x570e08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705224) /* 0x570e08 */);
    // 0049f77a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f77c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f77d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f77e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f77f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f780  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f781  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f782  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f783:
    // 0049f783  a1c80d5700             -mov eax, dword ptr [0x570dc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705160) /* 0x570dc8 */);
    // 0049f788  a3f80d5700             -mov dword ptr [0x570df8], eax
    app->getMemory<x86::reg32>(x86::reg32(5705208) /* 0x570df8 */) = cpu.eax;
    // 0049f78d  a1a80d5700             -mov eax, dword ptr [0x570da8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705128) /* 0x570da8 */);
    // 0049f792  48                     -dec eax
    (cpu.eax)--;
    // 0049f793  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049f795  a3000e5700             -mov dword ptr [0x570e00], eax
    app->getMemory<x86::reg32>(x86::reg32(5705216) /* 0x570e00 */) = cpu.eax;
    // 0049f79a  a1b80d5700             -mov eax, dword ptr [0x570db8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705144) /* 0x570db8 */);
    // 0049f79f  890dfc0d5700           -mov dword ptr [0x570dfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705212) /* 0x570dfc */) = cpu.ecx;
    // 0049f7a5  a3040e5700             -mov dword ptr [0x570e04], eax
    app->getMemory<x86::reg32>(x86::reg32(5705220) /* 0x570e04 */) = cpu.eax;
    // 0049f7aa  e977fdffff             -jmp 0x49f526
    goto L_0x0049f526;
L_0x0049f7af:
    // 0049f7af  8b1d080e5700           -mov ebx, dword ptr [0x570e08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705224) /* 0x570e08 */);
    // 0049f7b5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f7b7  0f8585feffff           -jne 0x49f642
    if (!cpu.flags.zf)
    {
        goto L_0x0049f642;
    }
    // 0049f7bd  e906feffff             -jmp 0x49f5c8
    goto L_0x0049f5c8;
L_0x0049f7c2:
    // 0049f7c2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f7c4  75ae                   -jne 0x49f774
    if (!cpu.flags.zf)
    {
        goto L_0x0049f774;
    }
    // 0049f7c6  e927ffffff             -jmp 0x49f6f2
    goto L_0x0049f6f2;
}

/* align: skip 0x90 */
void Application::sub_49f7cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f7cc);
    // 0049f7cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f7cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f7ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f7cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f7d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f7d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f7d2  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f7d5  8b15a00d5700           -mov edx, dword ptr [0x570da0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705120) /* 0x570da0 */);
    // 0049f7db  8b2dac0d5700           -mov ebp, dword ptr [0x570dac]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705132) /* 0x570dac */);
    // 0049f7e1  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049f7e5  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049f7e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f7e9  0f8582000000           -jne 0x49f871
    if (!cpu.flags.zf)
    {
        goto L_0x0049f871;
    }
L_0x0049f7ef:
    // 0049f7ef  8b0d180e5700           -mov ecx, dword ptr [0x570e18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705240) /* 0x570e18 */);
    // 0049f7f5  8b15e80d5700           -mov edx, dword ptr [0x570de8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */);
    // 0049f7fb  8b35240e5700           -mov esi, dword ptr [0x570e24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705252) /* 0x570e24 */);
    // 0049f801  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f803  a1d00d5700             -mov eax, dword ptr [0x570dd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */);
    // 0049f808  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049f80b  8b1d200e5700           -mov ebx, dword ptr [0x570e20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705248) /* 0x570e20 */);
    // 0049f811  8b3de40d5700           -mov edi, dword ptr [0x570de4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */);
    // 0049f817  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049f81b  39d9                   +cmp ecx, ebx
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
    // 0049f81d  7f34                   -jg 0x49f853
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f853;
    }
L_0x0049f81f:
    // 0049f81f  3b10                   +cmp edx, dword ptr [eax]
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
    // 0049f821  0f8376000000           -jae 0x49f89d
    if (!cpu.flags.cf)
    {
        goto L_0x0049f89d;
    }
    // 0049f827  3b0d180e5700           +cmp ecx, dword ptr [0x570e18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705240) /* 0x570e18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f82d  7e1d                   -jle 0x49f84c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f84c;
    }
    // 0049f82f  890d180e5700           -mov dword ptr [0x570e18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705240) /* 0x570e18 */) = cpu.ecx;
    // 0049f835  a3d00d5700             -mov dword ptr [0x570dd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */) = cpu.eax;
    // 0049f83a  893de40d5700           -mov dword ptr [0x570de4], edi
    app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */) = cpu.edi;
    // 0049f840  8915e80d5700           -mov dword ptr [0x570de8], edx
    app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */) = cpu.edx;
    // 0049f846  8935240e5700           -mov dword ptr [0x570e24], esi
    app->getMemory<x86::reg32>(x86::reg32(5705252) /* 0x570e24 */) = cpu.esi;
L_0x0049f84c:
    // 0049f84c  c7042401000000         -mov dword ptr [esp], 1
    app->getMemory<x86::reg32>(cpu.esp) = 1 /*0x1*/;
L_0x0049f853:
    // 0049f853  3b4c240c               +cmp ecx, dword ptr [esp + 0xc]
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
    // 0049f857  7f5b                   -jg 0x49f8b4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f8b4;
    }
    // 0049f859  3b10                   +cmp edx, dword ptr [eax]
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
    // 0049f85b  7357                   -jae 0x49f8b4
    if (!cpu.flags.cf)
    {
        goto L_0x0049f8b4;
    }
    // 0049f85d  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f861  41                     -inc ecx
    (cpu.ecx)++;
    // 0049f862  47                     -inc edi
    (cpu.edi)++;
    // 0049f863  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049f865  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f868  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049f86a  885fff                 -mov byte ptr [edi - 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0049f86d  01ee                   +add esi, ebp
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
    // 0049f86f  ebe2                   -jmp 0x49f853
    goto L_0x0049f853;
L_0x0049f871:
    // 0049f871  a1cc0d5700             -mov eax, dword ptr [0x570dcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705164) /* 0x570dcc */);
    // 0049f876  a3180e5700             -mov dword ptr [0x570e18], eax
    app->getMemory<x86::reg32>(x86::reg32(5705240) /* 0x570e18 */) = cpu.eax;
    // 0049f87b  a1a80d5700             -mov eax, dword ptr [0x570da8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705128) /* 0x570da8 */);
    // 0049f880  48                     -dec eax
    (cpu.eax)--;
    // 0049f881  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049f883  a3200e5700             -mov dword ptr [0x570e20], eax
    app->getMemory<x86::reg32>(x86::reg32(5705248) /* 0x570e20 */) = cpu.eax;
    // 0049f888  a1b40d5700             -mov eax, dword ptr [0x570db4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705140) /* 0x570db4 */);
    // 0049f88d  890d1c0e5700           -mov dword ptr [0x570e1c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705244) /* 0x570e1c */) = cpu.ecx;
    // 0049f893  a3240e5700             -mov dword ptr [0x570e24], eax
    app->getMemory<x86::reg32>(x86::reg32(5705252) /* 0x570e24 */) = cpu.eax;
    // 0049f898  e952ffffff             -jmp 0x49f7ef
    goto L_0x0049f7ef;
L_0x0049f89d:
    // 0049f89d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049f8a1  41                     -inc ecx
    (cpu.ecx)++;
    // 0049f8a2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f8a5  47                     -inc edi
    (cpu.edi)++;
    // 0049f8a6  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049f8a8  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049f8aa  39d9                   +cmp ecx, ebx
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
    // 0049f8ac  0f8e6dffffff           -jle 0x49f81f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f81f;
    }
    // 0049f8b2  eb9f                   -jmp 0x49f853
    goto L_0x0049f853;
L_0x0049f8b4:
    // 0049f8b4  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049f8b7  a11c0e5700             -mov eax, dword ptr [0x570e1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705244) /* 0x570e1c */);
    // 0049f8bc  8b35180e5700           -mov esi, dword ptr [0x570e18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705240) /* 0x570e18 */);
    // 0049f8c2  8b0d240e5700           -mov ecx, dword ptr [0x570e24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705252) /* 0x570e24 */);
    // 0049f8c8  8b15d00d5700           -mov edx, dword ptr [0x570dd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */);
    // 0049f8ce  8b3de40d5700           -mov edi, dword ptr [0x570de4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */);
    // 0049f8d4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049f8d8  4e                     -dec esi
    (cpu.esi)--;
    // 0049f8d9  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f8dc  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049f8de  a1e80d5700             -mov eax, dword ptr [0x570de8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */);
    // 0049f8e3  4f                     -dec edi
    (cpu.edi)--;
    // 0049f8e4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f8e6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049f8e8  7506                   -jne 0x49f8f0
    if (!cpu.flags.zf)
    {
        goto L_0x0049f8f0;
    }
L_0x0049f8ea:
    // 0049f8ea  3b742408               +cmp esi, dword ptr [esp + 8]
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
    // 0049f8ee  7d1e                   -jge 0x49f90e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f90e;
    }
L_0x0049f8f0:
    // 0049f8f0  3b742408               +cmp esi, dword ptr [esp + 8]
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
    // 0049f8f4  7c4e                   -jl 0x49f944
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f944;
    }
    // 0049f8f6  3b02                   +cmp eax, dword ptr [edx]
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
    // 0049f8f8  734a                   -jae 0x49f944
    if (!cpu.flags.cf)
    {
        goto L_0x0049f944;
    }
    // 0049f8fa  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f8fe  4e                     -dec esi
    (cpu.esi)--;
    // 0049f8ff  4f                     -dec edi
    (cpu.edi)--;
    // 0049f900  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049f902  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049f904  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f907  29c8                   +sub eax, ecx
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
    // 0049f909  885f01                 -mov byte ptr [edi + 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0049f90c  ebe2                   -jmp 0x49f8f0
    goto L_0x0049f8f0;
L_0x0049f90e:
    // 0049f90e  3b02                   +cmp eax, dword ptr [edx]
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
    // 0049f910  720b                   -jb 0x49f91d
    if (cpu.flags.cf)
    {
        goto L_0x0049f91d;
    }
    // 0049f912  4e                     -dec esi
    (cpu.esi)--;
    // 0049f913  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f916  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049f918  4f                     -dec edi
    (cpu.edi)--;
    // 0049f919  29c8                   +sub eax, ecx
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
    // 0049f91b  ebcd                   -jmp 0x49f8ea
    goto L_0x0049f8ea;
L_0x0049f91d:
    // 0049f91d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049f922  8935180e5700           -mov dword ptr [0x570e18], esi
    app->getMemory<x86::reg32>(x86::reg32(5705240) /* 0x570e18 */) = cpu.esi;
    // 0049f928  8915d00d5700           -mov dword ptr [0x570dd0], edx
    app->getMemory<x86::reg32>(x86::reg32(5705168) /* 0x570dd0 */) = cpu.edx;
    // 0049f92e  893de40d5700           -mov dword ptr [0x570de4], edi
    app->getMemory<x86::reg32>(x86::reg32(5705188) /* 0x570de4 */) = cpu.edi;
    // 0049f934  a3e80d5700             -mov dword ptr [0x570de8], eax
    app->getMemory<x86::reg32>(x86::reg32(5705192) /* 0x570de8 */) = cpu.eax;
    // 0049f939  890d240e5700           -mov dword ptr [0x570e24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705252) /* 0x570e24 */) = cpu.ecx;
    // 0049f93f  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049f942  ebac                   -jmp 0x49f8f0
    goto L_0x0049f8f0;
L_0x0049f944:
    // 0049f944  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049f947  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f94a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f94b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f94c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f94d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f94e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f94f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f950  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49f954(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f954);
    // 0049f954  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f955  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f957  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f959  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049f95c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049f95f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049f961  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f963  7e0f                   -jle 0x49f974
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f974;
    }
L_0x0049f965:
    // 0049f965  48                     -dec eax
    (cpu.eax)--;
    // 0049f966  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0049f96c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f96f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f971  7ff2                   -jg 0x49f965
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f965;
    }
    // 0049f973  90                     -nop 
    ;
L_0x0049f974:
    // 0049f974  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f975  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49f978(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f978);
    // 0049f978  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f979  8b1560ac4d00           -mov edx, dword ptr [0x4dac60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090400) /* 0x4dac60 */);
    // 0049f97f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f981  7502                   -jne 0x49f985
    if (!cpu.flags.zf)
    {
        goto L_0x0049f985;
    }
    // 0049f983  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f984  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f985:
    // 0049f985  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f986  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f988  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f98a  e86d4ffeff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0049f98f  890d60ac4d00           -mov dword ptr [0x4dac60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090400) /* 0x4dac60 */) = cpu.ecx;
    // 0049f995  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f996  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f997  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f998(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f998);
    // 0049f998  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f999  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f99a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f99b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f99c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f99d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f99e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049f9a0  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
    // 0049f9a5  b8c4104d00             -mov eax, 0x4d10c4
    cpu.eax = 5050564 /*0x4d10c4*/;
    // 0049f9aa  8b1de8ab4d00           -mov ebx, dword ptr [0x4dabe8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 0049f9b0  e8fb4afeff             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 0049f9b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f9b7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049f9b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f9bb  7509                   -jne 0x49f9c6
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9c6;
    }
    // 0049f9bd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049f9bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f9c6:
    // 0049f9c6  ba00000200             -mov edx, 0x20000
    cpu.edx = 131072 /*0x20000*/;
    // 0049f9cb  b8d0104d00             -mov eax, 0x4d10d0
    cpu.eax = 5050576 /*0x4d10d0*/;
    // 0049f9d0  8b1de8ab4d00           -mov ebx, dword ptr [0x4dabe8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 0049f9d6  e8d54afeff             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 0049f9db  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f9dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f9df  750b                   -jne 0x49f9ec
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9ec;
    }
    // 0049f9e1  31cf                   -xor edi, ecx
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f9e3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049f9e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f9ec:
    // 0049f9ec  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0049f9f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f9f2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049f9f4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f9f6  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049f9fb  e870f7ffff             -call 0x49f170
    cpu.esp -= 4;
    sub_49f170(app, cpu);
    if (cpu.terminate) return;
    // 0049fa00  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049fa02  e8f54efeff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0049fa07  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049fa09  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49fa10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fa10);
    // 0049fa10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fa11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fa12  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049fa18  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049fa1a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fa1c  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049fa21  e89ae00000             -call 0x4adac0
    cpu.esp -= 4;
    sub_4adac0(app, cpu);
    if (cpu.terminate) return;
    // 0049fa26  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049fa28  e86bffffff             -call 0x49f998
    cpu.esp -= 4;
    sub_49f998(app, cpu);
    if (cpu.terminate) return;
    // 0049fa2d  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049fa33  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49fa38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fa38);
    // 0049fa38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fa39  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fa3a  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049fa40  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049fa42  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fa44  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049fa49  e866e10000             -call 0x4adbb4
    cpu.esp -= 4;
    sub_4adbb4(app, cpu);
    if (cpu.terminate) return;
    // 0049fa4e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049fa50  e843ffffff             -call 0x49f998
    cpu.esp -= 4;
    sub_49f998(app, cpu);
    if (cpu.terminate) return;
    // 0049fa55  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049fa5b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49fa60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fa60);
    // 0049fa60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fa61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fa62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fa63  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049fa69  e80affffff             -call 0x49f978
    cpu.esp -= 4;
    sub_49f978(app, cpu);
    if (cpu.terminate) return;
    // 0049fa6e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049fa70  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049fa75  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fa77  e89c090000             -call 0x4a0418
    cpu.esp -= 4;
    sub_4a0418(app, cpu);
    if (cpu.terminate) return;
    // 0049fa7c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049fa7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049fa80  e813ffffff             -call 0x49f998
    cpu.esp -= 4;
    sub_49f998(app, cpu);
    if (cpu.terminate) return;
    // 0049fa85  a360ac4d00             -mov dword ptr [0x4dac60], eax
    app->getMemory<x86::reg32>(x86::reg32(5090400) /* 0x4dac60 */) = cpu.eax;
    // 0049fa8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fa8c  7405                   -je 0x49fa93
    if (cpu.flags.zf)
    {
        goto L_0x0049fa93;
    }
    // 0049fa8e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0049fa93:
    // 0049fa93  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049fa95  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049fa9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49faa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049faa0);
    // 0049faa0  e9f3320100             -jmp 0x4b2d98
    return sub_4b2d98(app, cpu);
}

/* align: skip  */
/* data blob: 03104000574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939352e20416c6c207269676874732072657365727665642e */
void Application::sub_49fb14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fb14);
    // 0049fb14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fb15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fb16  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x0049fb17:
    // 0049fb17  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049fb19  fec2                   -inc dl
    (cpu.dl)++;
    // 0049fb1b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049fb21  f68264ef4d0002         +test byte ptr [edx + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 0049fb28  7403                   -je 0x49fb2d
    if (cpu.flags.zf)
    {
        goto L_0x0049fb2d;
    }
    // 0049fb2a  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049fb2b  ebea                   -jmp 0x49fb17
    goto L_0x0049fb17;
L_0x0049fb2d:
    // 0049fb2d  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049fb2f  80f92b                 +cmp cl, 0x2b
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
    // 0049fb32  7405                   -je 0x49fb39
    if (cpu.flags.zf)
    {
        goto L_0x0049fb39;
    }
    // 0049fb34  80f92d                 +cmp cl, 0x2d
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
    // 0049fb37  7501                   -jne 0x49fb3a
    if (!cpu.flags.zf)
    {
        goto L_0x0049fb3a;
    }
L_0x0049fb39:
    // 0049fb39  40                     -inc eax
    (cpu.eax)++;
L_0x0049fb3a:
    // 0049fb3a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049fb3c:
    // 0049fb3c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049fb3e  fec2                   -inc dl
    (cpu.dl)++;
    // 0049fb40  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049fb46  f68264ef4d0020         +test byte ptr [edx + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 0049fb4d  740f                   -je 0x49fb5e
    if (cpu.flags.zf)
    {
        goto L_0x0049fb5e;
    }
    // 0049fb4f  6bdb0a                 -imul ebx, ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0049fb52  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fb54  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049fb56  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fb58  40                     -inc eax
    (cpu.eax)++;
    // 0049fb59  83eb30                 +sub ebx, 0x30
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
    // 0049fb5c  ebde                   -jmp 0x49fb3c
    goto L_0x0049fb3c;
L_0x0049fb5e:
    // 0049fb5e  80f92d                 +cmp cl, 0x2d
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
    // 0049fb61  7502                   -jne 0x49fb65
    if (!cpu.flags.zf)
    {
        goto L_0x0049fb65;
    }
    // 0049fb63  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x0049fb65:
    // 0049fb65  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049fb67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49fb70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fb70);
    // 0049fb70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fb71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fb72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fb73  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fb74  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fb76  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049fb78  8915380e5700           -mov dword ptr [0x570e38], edx
    app->getMemory<x86::reg32>(x86::reg32(5705272) /* 0x570e38 */) = cpu.edx;
    // 0049fb7e  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0049fb85  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049fb88  e80f04ffff             -call 0x48ff9c
    cpu.esp -= 4;
    sub_48ff9c(app, cpu);
    if (cpu.terminate) return;
    // 0049fb8d  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049fb90  e8c7fffeff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 0049fb95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fb97  7508                   -jne 0x49fba1
    if (!cpu.flags.zf)
    {
        goto L_0x0049fba1;
    }
    // 0049fb99  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0049fb9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fba0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fba1:
    // 0049fba1  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0049fba4  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0049fba7  8b5e40                 -mov ebx, dword ptr [esi + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0049fbaa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fbab  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049fbae  8b563c                 -mov edx, dword ptr [esi + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 0049fbb1  e80606ffff             -call 0x4901bc
    cpu.esp -= 4;
    sub_4901bc(app, cpu);
    if (cpu.terminate) return;
    // 0049fbb6  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049fbb9  e84201ffff             -call 0x48fd00
    cpu.esp -= 4;
    sub_48fd00(app, cpu);
    if (cpu.terminate) return;
    // 0049fbbe  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049fbc1  e85a01ffff             -call 0x48fd20
    cpu.esp -= 4;
    sub_48fd20(app, cpu);
    if (cpu.terminate) return;
    // 0049fbc6  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049fbc9  e8c2f9feff             -call 0x48f590
    cpu.esp -= 4;
    sub_48f590(app, cpu);
    if (cpu.terminate) return;
    // 0049fbce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fbd0  750f                   -jne 0x49fbe1
    if (!cpu.flags.zf)
    {
        goto L_0x0049fbe1;
    }
    // 0049fbd2  c7463001000000         -mov dword ptr [esi + 0x30], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 0049fbd9  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0049fbdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbdd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbde  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbdf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbe0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fbe1:
    // 0049fbe1  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049fbe4  e85701ffff             -call 0x48fd40
    cpu.esp -= 4;
    sub_48fd40(app, cpu);
    if (cpu.terminate) return;
    // 0049fbe9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fbeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49fbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fbf0);
    // 0049fbf0  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0049fbf7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049fbfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49fc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc00);
    // 0049fc00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fc01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fc02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fc03  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fc05  8b1d380e5700           -mov ebx, dword ptr [0x570e38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705272) /* 0x570e38 */);
    // 0049fc0b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fc0d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049fc0f  7507                   -jne 0x49fc18
    if (!cpu.flags.zf)
    {
        goto L_0x0049fc18;
    }
L_0x0049fc11:
    // 0049fc11  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0049fc14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fc18:
    // 0049fc18  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049fc1b  e8e806ffff             -call 0x490308
    cpu.esp -= 4;
    sub_490308(app, cpu);
    if (cpu.terminate) return;
    // 0049fc20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fc22  74ed                   -je 0x49fc11
    if (cpu.flags.zf)
    {
        goto L_0x0049fc11;
    }
    // 0049fc24  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fc26  ff15380e5700           -call dword ptr [0x570e38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5705272) /* 0x570e38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fc2c  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0049fc2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49fc34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc34);
    // 0049fc34  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049fc37  e92007ffff             -jmp 0x49035c
    return sub_49035c(app, cpu);
}

/* align: skip  */
void Application::sub_49fc3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc3c);
    // 0049fc3c  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049fc3f  e9c406ffff             -jmp 0x490308
    return sub_490308(app, cpu);
}

/* align: skip  */
void Application::sub_49fc44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc44);
    // 0049fc44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fc45  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fc47  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049fc49  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049fc4b  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0049fc4e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fc50  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049fc52  e82108ffff             -call 0x490478
    cpu.esp -= 4;
    sub_490478(app, cpu);
    if (cpu.terminate) return;
    // 0049fc57  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fc59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fc5b  7c04                   -jl 0x49fc61
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049fc61;
    }
    // 0049fc5d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fc5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fc61:
    // 0049fc61  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049fc63  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fc65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49fc68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc68);
    // 0049fc68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fc69  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fc6b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fc6d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049fc6f  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0049fc72  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049fc74  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049fc76  e88d03ffff             -call 0x490008
    cpu.esp -= 4;
    sub_490008(app, cpu);
    if (cpu.terminate) return;
    // 0049fc7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49fc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc80);
    // 0049fc80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fc81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fc82  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fc84  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049fc86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fc88  745b                   -je 0x49fce5
    if (cpu.flags.zf)
    {
        goto L_0x0049fce5;
    }
    // 0049fc8a  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0049fc8e  7516                   -jne 0x49fca6
    if (!cpu.flags.zf)
    {
        goto L_0x0049fca6;
    }
    // 0049fc90  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0049fc96  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fc98  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049fc9b  c1e204                 +shl edx, 4
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
    // 0049fc9e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049fca0  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0049fca3  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x0049fca6:
    // 0049fca6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fca7  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 0049fcab  7515                   -jne 0x49fcc2
    if (!cpu.flags.zf)
    {
        goto L_0x0049fcc2;
    }
    // 0049fcad  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0049fcb3  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0049fcb8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fcba  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049fcbd  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049fcbf  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0049fcc2:
    // 0049fcc2  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 0049fcc6  7515                   -jne 0x49fcdd
    if (!cpu.flags.zf)
    {
        goto L_0x0049fcdd;
    }
    // 0049fcc8  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0049fcce  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0049fcd3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fcd5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049fcd8  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049fcda  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0049fcdd:
    // 0049fcdd  c7460803000000         -mov dword ptr [esi + 8], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 0049fce4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049fce5:
    // 0049fce5  bac84b4d00             -mov edx, 0x4d4bc8
    cpu.edx = 5065672 /*0x4d4bc8*/;
    // 0049fcea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fceb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049fced  bbb8d54d00             -mov ebx, 0x4dd5b8
    cpu.ebx = 5100984 /*0x4dd5b8*/;
    // 0049fcf2  e891a4feff             -call 0x48a188
    cpu.esp -= 4;
    sub_48a188(app, cpu);
    if (cpu.terminate) return;
    // 0049fcf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fcf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fcf9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49fd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fd00);
    // 0049fd00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fd01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fd02  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049fd04  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049fd06  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049fd0d  7405                   -je 0x49fd14
    if (cpu.flags.zf)
    {
        goto L_0x0049fd14;
    }
    // 0049fd0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fd11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fd14:
    // 0049fd14  e8dfa1feff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0049fd19  a300c65900             -mov dword ptr [0x59c600], eax
    app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */) = cpu.eax;
    // 0049fd1e  e8c5000000             -call 0x49fde8
    cpu.esp -= 4;
    sub_49fde8(app, cpu);
    if (cpu.terminate) return;
    // 0049fd23  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049fd25  e802010000             -call 0x49fe2c
    cpu.esp -= 4;
    sub_49fe2c(app, cpu);
    if (cpu.terminate) return;
    // 0049fd2a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049fd2c  e8038efeff             -call 0x488b34
    cpu.esp -= 4;
    sub_488b34(app, cpu);
    if (cpu.terminate) return;
    // 0049fd31  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fd33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fd35  7c0d                   -jl 0x49fd44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049fd44;
    }
    // 0049fd37  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0049fd39  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fd3b  881574da4d00           -mov byte ptr [0x4dda74], dl
    app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */) = cpu.dl;
    // 0049fd41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fd44:
    // 0049fd44  e85b8efeff             -call 0x488ba4
    cpu.esp -= 4;
    sub_488ba4(app, cpu);
    if (cpu.terminate) return;
    // 0049fd49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049fd4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49fd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fd50);
    // 0049fd50  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049fd57  7506                   -jne 0x49fd5f
    if (!cpu.flags.zf)
    {
        goto L_0x0049fd5f;
    }
    // 0049fd59  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049fd5e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fd5f:
    // 0049fd5f  e8bcddffff             -call 0x49db20
    cpu.esp -= 4;
    sub_49db20(app, cpu);
    if (cpu.terminate) return;
    // 0049fd64  833d94da4d0000         +cmp dword ptr [0x4dda94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102228) /* 0x4dda94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd6b  7406                   -je 0x49fd73
    if (cpu.flags.zf)
    {
        goto L_0x0049fd73;
    }
    // 0049fd6d  ff1594da4d00           -call dword ptr [0x4dda94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102228) /* 0x4dda94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049fd73:
    // 0049fd73  833d98da4d0000         +cmp dword ptr [0x4dda98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102232) /* 0x4dda98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd7a  7406                   -je 0x49fd82
    if (cpu.flags.zf)
    {
        goto L_0x0049fd82;
    }
    // 0049fd7c  ff1598da4d00           -call dword ptr [0x4dda98]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102232) /* 0x4dda98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049fd82:
    // 0049fd82  833d9cda4d0000         +cmp dword ptr [0x4dda9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102236) /* 0x4dda9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd89  7406                   -je 0x49fd91
    if (cpu.flags.zf)
    {
        goto L_0x0049fd91;
    }
    // 0049fd8b  ff159cda4d00           -call dword ptr [0x4dda9c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102236) /* 0x4dda9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049fd91:
    // 0049fd91  833d8cda4d0000         +cmp dword ptr [0x4dda8c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102220) /* 0x4dda8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd98  740b                   -je 0x49fda5
    if (cpu.flags.zf)
    {
        goto L_0x0049fda5;
    }
    // 0049fd9a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049fd9f  ff158cda4d00           -call dword ptr [0x4dda8c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102220) /* 0x4dda8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049fda5:
    // 0049fda5  833da0da4d0000         +cmp dword ptr [0x4ddaa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102240) /* 0x4ddaa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fdac  7406                   -je 0x49fdb4
    if (cpu.flags.zf)
    {
        goto L_0x0049fdb4;
    }
    // 0049fdae  ff15a0da4d00           -call dword ptr [0x4ddaa0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102240) /* 0x4ddaa0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049fdb4:
    // 0049fdb4  833d90da4d0000         +cmp dword ptr [0x4dda90], 0
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
    // 0049fdbb  7406                   -je 0x49fdc3
    if (cpu.flags.zf)
    {
        goto L_0x0049fdc3;
    }
    // 0049fdbd  ff1590da4d00           -call dword ptr [0x4dda90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102224) /* 0x4dda90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049fdc3:
    // 0049fdc3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fdc4  e8db8dfeff             -call 0x488ba4
    cpu.esp -= 4;
    sub_488ba4(app, cpu);
    if (cpu.terminate) return;
    // 0049fdc9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fdcb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fdcd  7c0a                   -jl 0x49fdd9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049fdd9;
    }
    // 0049fdcf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fdd0  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0049fdd2  881d74da4d00           -mov byte ptr [0x4dda74], bl
    app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */) = cpu.bl;
    // 0049fdd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049fdd9:
    // 0049fdd9  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 0049fdde  e891a1feff             -call 0x489f74
    cpu.esp -= 4;
    sub_489f74(app, cpu);
    if (cpu.terminate) return;
    // 0049fde3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fde5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fde6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49fde8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fde8);
    // 0049fde8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fde9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049fdeb:
    // 0049fdeb  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049fdee  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0049fdf0  88905cbf5900           -mov byte ptr [eax + 0x59bf5c], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5881692) /* 0x59bf5c */) = cpu.dl;
    // 0049fdf6  3d00060000             +cmp eax, 0x600
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
    // 0049fdfb  75ee                   -jne 0x49fdeb
    if (!cpu.flags.zf)
    {
        goto L_0x0049fdeb;
    }
    // 0049fdfd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049fdff:
    // 0049fdff  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049fe02  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fe04  8990a8c55900           -mov dword ptr [eax + 0x59c5a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5883304) /* 0x59c5a8 */) = cpu.edx;
    // 0049fe0a  8990acc55900           -mov dword ptr [eax + 0x59c5ac], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5883308) /* 0x59c5ac */) = cpu.edx;
    // 0049fe10  83f850                 +cmp eax, 0x50
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
    // 0049fe13  75ea                   -jne 0x49fdff
    if (!cpu.flags.zf)
    {
        goto L_0x0049fdff;
    }
    // 0049fe15  891508c65900           -mov dword ptr [0x59c608], edx
    app->getMemory<x86::reg32>(x86::reg32(5883400) /* 0x59c608 */) = cpu.edx;
    // 0049fe1b  891504c65900           -mov dword ptr [0x59c604], edx
    app->getMemory<x86::reg32>(x86::reg32(5883396) /* 0x59c604 */) = cpu.edx;
    // 0049fe21  c6050dc659007f         -mov byte ptr [0x59c60d], 0x7f
    app->getMemory<x86::reg8>(x86::reg32(5883405) /* 0x59c60d */) = 127 /*0x7f*/;
    // 0049fe28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49fe2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fe2c);
    // 0049fe2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fe2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fe2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fe2f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049fe31  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fe33  e8048afeff             -call 0x48883c
    cpu.esp -= 4;
    sub_48883c(app, cpu);
    if (cpu.terminate) return;
    // 0049fe38  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fe3a  83fbff                 +cmp ebx, -1
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
    // 0049fe3d  754c                   -jne 0x49fe8b
    if (!cpu.flags.zf)
    {
        goto L_0x0049fe8b;
    }
L_0x0049fe3f:
    // 0049fe3f  21d0                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fe41  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fe43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fe45  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fe47  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049fe4d  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0049fe53  81e60000ff00           -and esi, 0xff0000
    cpu.esi &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0049fe59  83fbff                 +cmp ebx, -1
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
    // 0049fe5c  7502                   -jne 0x49fe60
    if (!cpu.flags.zf)
    {
        goto L_0x0049fe60;
    }
    // 0049fe5e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049fe60:
    // 0049fe60  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049fe62  742b                   -je 0x49fe8f
    if (cpu.flags.zf)
    {
        goto L_0x0049fe8f;
    }
    // 0049fe64  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049fe66  7427                   -je 0x49fe8f
    if (cpu.flags.zf)
    {
        goto L_0x0049fe8f;
    }
    // 0049fe68  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0049fe6b  7428                   -je 0x49fe95
    if (cpu.flags.zf)
    {
        goto L_0x0049fe95;
    }
    // 0049fe6d  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x0049fe72:
    // 0049fe72  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 0049fe75  743d                   -je 0x49feb4
    if (cpu.flags.zf)
    {
        goto L_0x0049feb4;
    }
    // 0049fe77  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0049fe7a:
    // 0049fe7a  f7c600000200           +test esi, 0x20000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 131072 /*0x20000*/));
    // 0049fe80  7405                   -je 0x49fe87
    if (cpu.flags.zf)
    {
        goto L_0x0049fe87;
    }
    // 0049fe82  0d00000200             +or eax, 0x20000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(131072 /*0x20000*/))));
L_0x0049fe87:
    // 0049fe87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe8a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fe8b:
    // 0049fe8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049fe8d  ebb0                   -jmp 0x49fe3f
    goto L_0x0049fe3f;
L_0x0049fe8f:
    // 0049fe8f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fe91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fe95:
    // 0049fe95  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0049fe98  7407                   -je 0x49fea1
    if (cpu.flags.zf)
    {
        goto L_0x0049fea1;
    }
    // 0049fe9a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049fe9f  ebd1                   -jmp 0x49fe72
    goto L_0x0049fe72;
L_0x0049fea1:
    // 0049fea1  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0049fea4  7407                   -je 0x49fead
    if (cpu.flags.zf)
    {
        goto L_0x0049fead;
    }
    // 0049fea6  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049feab  ebc5                   -jmp 0x49fe72
    goto L_0x0049fe72;
L_0x0049fead:
    // 0049fead  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049feb2  ebbe                   -jmp 0x49fe72
    goto L_0x0049fe72;
L_0x0049feb4:
    // 0049feb4  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0049feb7  7405                   -je 0x49febe
    if (cpu.flags.zf)
    {
        goto L_0x0049febe;
    }
    // 0049feb9  80cc10                 +or ah, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0049febc  ebbc                   -jmp 0x49fe7a
    goto L_0x0049fe7a;
L_0x0049febe:
    // 0049febe  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 0049fec1  7405                   -je 0x49fec8
    if (cpu.flags.zf)
    {
        goto L_0x0049fec8;
    }
    // 0049fec3  80cc04                 +or ah, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0049fec6  ebb2                   -jmp 0x49fe7a
    goto L_0x0049fe7a;
L_0x0049fec8:
    // 0049fec8  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0049fecb  7405                   -je 0x49fed2
    if (cpu.flags.zf)
    {
        goto L_0x0049fed2;
    }
    // 0049fecd  80cc20                 +or ah, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049fed0  eba8                   -jmp 0x49fe7a
    goto L_0x0049fe7a;
L_0x0049fed2:
    // 0049fed2  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 0049fed5  7405                   -je 0x49fedc
    if (cpu.flags.zf)
    {
        goto L_0x0049fedc;
    }
    // 0049fed7  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0049feda  eb9e                   -jmp 0x49fe7a
    goto L_0x0049fe7a;
L_0x0049fedc:
    // 0049fedc  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0049fedf  eb99                   -jmp 0x49fe7a
    goto L_0x0049fe7a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49fef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fef0);
    // 0049fef0  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049fef7  7506                   -jne 0x49feff
    if (!cpu.flags.zf)
    {
        goto L_0x0049feff;
    }
    // 0049fef9  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049fefe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049feff:
    // 0049feff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ff00  a16cce4d00             -mov eax, dword ptr [0x4dce6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 0049ff05  e8c6300100             -call 0x4b2fd0
    cpu.esp -= 4;
    sub_4b2fd0(app, cpu);
    if (cpu.terminate) return;
    // 0049ff0a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ff0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ff0e  7c04                   -jl 0x49ff14
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ff14;
    }
    // 0049ff10  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ff12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ff14:
    // 0049ff14  0fbe15dece4d00         -movsx edx, byte ptr [0x4dcede]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099230) /* 0x4dcede */)));
    // 0049ff1b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ff1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ff1f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ff1f);
    // 0049ff1f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ff20  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ff21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ff22  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049ff25  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ff26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ff27  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049ff29  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049ff2b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ff2e  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ff34  f6410c02               +test byte ptr [ecx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 0049ff38  751e                   -jne 0x49ff58
    if (!cpu.flags.zf)
    {
        goto L_0x0049ff58;
    }
    // 0049ff3a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049ff3f  e86c670000             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 0049ff44  80490c20               -or byte ptr [ecx + 0xc], 0x20
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049ff48  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ff4b  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ff51  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ff53  e9c6010000             -jmp 0x4a011e
    goto L_0x004a011e;
L_0x0049ff58:
    // 0049ff58  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ff5b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049ff5d  7510                   -jne 0x49ff6f
    if (!cpu.flags.zf)
    {
        goto L_0x0049ff6f;
    }
    // 0049ff5f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ff62  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ff68  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ff6a  e9af010000             -jmp 0x4a011e
    goto L_0x004a011e;
L_0x0049ff6f:
    // 0049ff6f  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049ff72  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0049ff76  7507                   -jne 0x49ff7f
    if (!cpu.flags.zf)
    {
        goto L_0x0049ff7f;
    }
    // 0049ff78  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ff7a  e88c020100             -call 0x4b020b
    cpu.esp -= 4;
    sub_4b020b(app, cpu);
    if (cpu.terminate) return;
L_0x0049ff7f:
    // 0049ff7f  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0049ff82  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0049ff85  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ff87  83e030                 -and eax, 0x30
    cpu.eax &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049ff8a  80e2cf                 -and dl, 0xcf
    cpu.dl &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 0049ff8d  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049ff91  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049ff95  88550c                 -mov byte ptr [ebp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 0049ff98  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 0049ff9b  0f84e1000000           -je 0x4a0082
    if (cpu.flags.zf)
    {
        goto L_0x004a0082;
    }
    // 0049ffa1  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0049ffa5:
    // 0049ffa5  837d0400               +cmp dword ptr [ebp + 4], 0
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
    // 0049ffa9  7544                   -jne 0x49ffef
    if (!cpu.flags.zf)
    {
        goto L_0x0049ffef;
    }
    // 0049ffab  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049ffaf  3b4514                 +cmp eax, dword ptr [ebp + 0x14]
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
    // 0049ffb2  723b                   -jb 0x49ffef
    if (cpu.flags.cf)
    {
        goto L_0x0049ffef;
    }
    // 0049ffb4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ffb6  30c3                   -xor bl, al
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.al));
    // 0049ffb8  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049ffbb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049ffbd  7502                   -jne 0x49ffc1
    if (!cpu.flags.zf)
    {
        goto L_0x0049ffc1;
    }
    // 0049ffbf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0049ffc1:
    // 0049ffc1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ffc5  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049ffc8  e84e300100             -call 0x4b301b
    cpu.esp -= 4;
    sub_4b301b(app, cpu);
    if (cpu.terminate) return;
    // 0049ffcd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ffcf  83f8ff                 +cmp eax, -1
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
    // 0049ffd2  7415                   -je 0x49ffe9
    if (cpu.flags.zf)
    {
        goto L_0x0049ffe9;
    }
    // 0049ffd4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ffd6  0f8573000000           -jne 0x4a004f
    if (!cpu.flags.zf)
    {
        goto L_0x004a004f;
    }
    // 0049ffdc  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ffe2  c740040c000000         -mov dword ptr [eax + 4], 0xc
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 12 /*0xc*/;
L_0x0049ffe9:
    // 0049ffe9  804d0c20               +or byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049ffed  eb60                   -jmp 0x4a004f
    goto L_0x004a004f;
L_0x0049ffef:
    // 0049ffef  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049fff2  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049fff5  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049fff9  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049fffb  39fa                   +cmp edx, edi
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
    // 0049fffd  7602                   -jbe 0x4a0001
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0001;
    }
    // 0049ffff  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x004a0001:
    // 004a0001  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0005  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a0007  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a000a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a000b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a000d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a000f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0010  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0012  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a0015  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0017  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a0019  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a001c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004a001e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a001f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a0020  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004a0023  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a0026  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0028  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a002b  895d04                 -mov dword ptr [ebp + 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a002e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0030  8a7d0d                 -mov bh, byte ptr [ebp + 0xd]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 004a0033  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004a0036  80cf10                 -or bh, 0x10
    cpu.bh |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004a0039  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004a003c  887d0d                 -mov byte ptr [ebp + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 004a003f  39c8                   +cmp eax, ecx
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
    // 004a0041  7405                   -je 0x4a0048
    if (cpu.flags.zf)
    {
        goto L_0x004a0048;
    }
    // 004a0043  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004a0046  7407                   -je 0x4a004f
    if (cpu.flags.zf)
    {
        goto L_0x004a004f;
    }
L_0x004a0048:
    // 004a0048  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a004a  e840b20000             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
L_0x004a004f:
    // 004a004f  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0053  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a0057  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a005b  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a005d  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a005f  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a0063  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004a0067  29d0                   +sub eax, edx
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
    // 004a0069  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a006d  0f847f000000           -je 0x4a00f2
    if (cpu.flags.zf)
    {
        goto L_0x004a00f2;
    }
    // 004a0073  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 004a0077  0f8428ffffff           -je 0x49ffa5
    if (cpu.flags.zf)
    {
        goto L_0x0049ffa5;
    }
    // 004a007d  e970000000             -jmp 0x4a00f2
    goto L_0x004a00f2;
L_0x004a0082:
    // 004a0082  8a5d0d                 -mov bl, byte ptr [ebp + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 004a0085  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004a0088  7414                   -je 0x4a009e
    if (cpu.flags.zf)
    {
        goto L_0x004a009e;
    }
    // 004a008a  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004a008c  80e7fa                 -and bh, 0xfa
    cpu.bh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004a008f  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 004a0091  887d0d                 -mov byte ptr [ebp + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 004a0094  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a0096  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a009b  88450d                 -mov byte ptr [ebp + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x004a009e:
    // 004a009e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a00a1  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a00a5  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a00a8  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004a00af:
    // 004a00af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a00b1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a00b3  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a00b5  e82b300100             -call 0x4b30e5
    cpu.esp -= 4;
    sub_4b30e5(app, cpu);
    if (cpu.terminate) return;
    // 004a00ba  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a00bd  43                     -inc ebx
    (cpu.ebx)++;
    // 004a00be  f6c230                 +test dl, 0x30
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 48 /*0x30*/));
    // 004a00c1  750d                   -jne 0x4a00d0
    if (!cpu.flags.zf)
    {
        goto L_0x004a00d0;
    }
    // 004a00c3  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a00c7  40                     -inc eax
    (cpu.eax)++;
    // 004a00c8  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a00cc  39c7                   +cmp edi, eax
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
    // 004a00ce  75df                   -jne 0x4a00af
    if (!cpu.flags.zf)
    {
        goto L_0x004a00af;
    }
L_0x004a00d0:
    // 004a00d0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a00d3  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004a00d6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a00d8  7418                   -je 0x4a00f2
    if (cpu.flags.zf)
    {
        goto L_0x004a00f2;
    }
    // 004a00da  8a750d                 -mov dh, byte ptr [ebp + 0xd]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 004a00dd  80e6fa                 -and dh, 0xfa
    cpu.dh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004a00e0  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 004a00e2  88750d                 -mov byte ptr [ebp + 0xd], dh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.dh;
    // 004a00e5  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004a00e8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a00ea  885d0d                 -mov byte ptr [ebp + 0xd], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 004a00ed  e89db10000             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
L_0x004a00f2:
    // 004a00f2  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 004a00f6  7406                   -je 0x4a00fe
    if (cpu.flags.zf)
    {
        goto L_0x004a00fe;
    }
    // 004a00f8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a00fa  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004a00fe:
    // 004a00fe  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0102  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0105  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a0108  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a010a  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a010c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a010f  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a0112  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0118  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a011c  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004a011e:
    // 004a011e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a0121  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0122  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0123  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0124  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a0126(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0126);
    // 004a0126  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a0128  f605a0014e0001         +test byte ptr [0x4e01a0], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5112224) /* 0x4e01a0 */) & 1 /*0x1*/));
    // 004a012f  7504                   -jne 0x4a0135
    if (!cpu.flags.zf)
    {
        goto L_0x004a0135;
    }
    // 004a0131  d9f3                   +fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a0133  eb05                   -jmp 0x4a013a
    goto L_0x004a013a;
L_0x004a0135:
    // 004a0135  e88a300100             -call 0x4b31c4
    cpu.esp -= 4;
    sub_4b31c4(app, cpu);
    if (cpu.terminate) return;
L_0x004a013a:
    // 004a013a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a013b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a013b);
    // 004a013b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a013d  f605a0014e0001         +test byte ptr [0x4e01a0], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5112224) /* 0x4e01a0 */) & 1 /*0x1*/));
    // 004a0144  7504                   -jne 0x4a014a
    if (!cpu.flags.zf)
    {
        goto L_0x004a014a;
    }
    // 004a0146  d9f3                   +fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a0148  eb05                   -jmp 0x4a014f
    goto L_0x004a014f;
L_0x004a014a:
    // 004a014a  e875300100             -call 0x4b31c4
    cpu.esp -= 4;
    sub_4b31c4(app, cpu);
    if (cpu.terminate) return;
L_0x004a014f:
    // 004a014f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0150);
    // 004a0150  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004a0154  e8cdffffff             -call 0x4a0126
    cpu.esp -= 4;
    sub_4a0126(app, cpu);
    if (cpu.terminate) return;
    // 004a0159  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4a015c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a015c);
    // 004a015c  dd44240c               -fld qword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004a0160  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004a0164  e8d2ffffff             -call 0x4a013b
    cpu.esp -= 4;
    sub_4a013b(app, cpu);
    if (cpu.terminate) return;
    // 004a0169  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4a0170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0170);
    // 004a0170  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0171  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0172  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0173  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0174  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a017a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a017c  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 004a0180  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a0182  ff05d8ab4d00           -inc dword ptr [0x4dabd8]
    (app->getMemory<x86::reg32>(x86::reg32(5090264) /* 0x4dabd8 */))++;
    // 004a0188  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a018a  7505                   -jne 0x4a0191
    if (!cpu.flags.zf)
    {
        goto L_0x004a0191;
    }
    // 004a018c  bd00395600             -mov ebp, 0x563900
    cpu.ebp = 5650688 /*0x563900*/;
L_0x004a0191:
    // 004a0191  833d5cab4d0007         +cmp dword ptr [0x4dab5c], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0198  0f8525010000           -jne 0x4a02c3
    if (!cpu.flags.zf)
    {
        goto L_0x004a02c3;
    }
    // 004a019e  837d1c08               +cmp dword ptr [ebp + 0x1c], 8
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
    // 004a01a2  0f8f1b010000           -jg 0x4a02c3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a02c3;
    }
    // 004a01a8  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004a01ac  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a01ae  48                     -dec eax
    (cpu.eax)--;
    // 004a01af  8bbd3c040000           -mov edi, dword ptr [ebp + 0x43c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1084) /* 0x43c */);
    // 004a01b5  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 004a01b9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a01bb  0f840d010000           -je 0x4a02ce
    if (cpu.flags.zf)
    {
        goto L_0x004a02ce;
    }
    // 004a01c1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a01c6:
    // 004a01c6  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 004a01ca  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004a01ce  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 004a01d1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a01d4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a01d6  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004a01d9  05600e5700             -add eax, 0x570e60
    (cpu.eax) += x86::reg32(x86::sreg32(5705312 /*0x570e60*/));
    // 004a01de  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a01e0  7e2a                   -jle 0x4a020c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a020c;
    }
    // 004a01e2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004a01e4:
    // 004a01e4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a01e6  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a01e9  0fb67802               -movzx edi, byte ptr [eax + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */));
    // 004a01ed  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a01f0  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a01f2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a01f4  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a01f6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a01f9  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004a01fc  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a01ff  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 004a0201  41                     -inc ecx
    (cpu.ecx)++;
    // 004a0202  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004a0205  39f1                   +cmp ecx, esi
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
    // 004a0207  7cdb                   -jl 0x4a01e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a01e4;
    }
    // 004a0209  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a020c:
    // 004a020c  8b852e040000           -mov eax, dword ptr [ebp + 0x42e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1070) /* 0x42e */);
    // 004a0212  8b54247c               -mov edx, dword ptr [esp + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004a0216  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a0219  39d0                   +cmp eax, edx
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
    // 004a021b  7e0b                   -jle 0x4a0228
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0228;
    }
    // 004a021d  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004a0221  66898530040000         -mov word ptr [ebp + 0x430], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1072) /* 0x430 */) = cpu.ax;
L_0x004a0228:
    // 004a0228  8b8530040000           -mov eax, dword ptr [ebp + 0x430]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1072) /* 0x430 */);
    // 004a022e  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004a0232  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a0235  39c8                   +cmp eax, ecx
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
    // 004a0237  7d0b                   -jge 0x4a0244
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0244;
    }
    // 004a0239  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004a023d  66898532040000         -mov word ptr [ebp + 0x432], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1074) /* 0x432 */) = cpu.ax;
L_0x004a0244:
    // 004a0244  837c247000             +cmp dword ptr [esp + 0x70], 0
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
    // 004a0249  740c                   -je 0x4a0257
    if (cpu.flags.zf)
    {
        goto L_0x004a0257;
    }
    // 004a024b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a024d  e8de3d0000             -call 0x4a4030
    cpu.esp -= 4;
    sub_4a4030(app, cpu);
    if (cpu.terminate) return;
    // 004a0252  e86522feff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
L_0x004a0257:
    // 004a0257  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a0259  e89218ffff             -call 0x491af0
    cpu.esp -= 4;
    sub_491af0(app, cpu);
    if (cpu.terminate) return;
    // 004a025e  80bd5d04000000         +cmp byte ptr [ebp + 0x45d], 0
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
    // 004a0265  7555                   -jne 0x4a02bc
    if (!cpu.flags.zf)
    {
        goto L_0x004a02bc;
    }
    // 004a0267  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004a026b  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 004a026e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a0271  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0273  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a0275  05600e5700             -add eax, 0x570e60
    (cpu.eax) += x86::reg32(x86::sreg32(5705312 /*0x570e60*/));
    // 004a027a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a027c  7e3e                   -jle 0x4a02bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a02bc;
    }
L_0x004a027e:
    // 004a027e  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a0280  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004a0283  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a0285  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a0288  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a028e  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 004a0292  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004a0296  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004a0299  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a029b  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004a029e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a02a4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a02a7  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 004a02ab  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a02ae  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004a02b2  41                     -inc ecx
    (cpu.ecx)++;
    // 004a02b3  8858fc                 -mov byte ptr [eax - 4], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.bl;
    // 004a02b6  39f1                   +cmp ecx, esi
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
    // 004a02b8  7cc4                   -jl 0x4a027e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a027e;
    }
    // 004a02ba  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a02bc:
    // 004a02bc  837c247000             +cmp dword ptr [esp + 0x70], 0
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
    // 004a02c1  7512                   -jne 0x4a02d5
    if (!cpu.flags.zf)
    {
        goto L_0x004a02d5;
    }
L_0x004a02c3:
    // 004a02c3  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a02c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a02ce:
    // 004a02ce  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a02d0  e9f1feffff             -jmp 0x4a01c6
    goto L_0x004a01c6;
L_0x004a02d5:
    // 004a02d5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a02d7  e8783d0000             -call 0x4a4054
    cpu.esp -= 4;
    sub_4a4054(app, cpu);
    if (cpu.terminate) return;
    // 004a02dc  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a02e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a02e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a02e8);
    // 004a02e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a02e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a02ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a02ec  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a02ee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a02f0  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 004a02f7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a02f9  81c2600e5700           -add edx, 0x570e60
    (cpu.edx) += x86::reg32(x86::sreg32(5705312 /*0x570e60*/));
    // 004a02ff  e829680000             -call 0x4a6b2d
    cpu.esp -= 4;
    sub_4a6b2d(app, cpu);
    if (cpu.terminate) return;
    // 004a0304  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0309  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a030b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a030d  e85efeffff             -call 0x4a0170
    cpu.esp -= 4;
    sub_4a0170(app, cpu);
    if (cpu.terminate) return;
    // 004a0312  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0313  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0314  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0318(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0318);
    // 004a0318  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0319  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a031a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a031b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a031c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a031f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a0323  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a0326  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a0329  05600e5700             -add eax, 0x570e60
    (cpu.eax) += x86::reg32(x86::sreg32(5705312 /*0x570e60*/));
L_0x004a032e:
    // 004a032e  4a                     -dec edx
    (cpu.edx)--;
    // 004a032f  83faff                 +cmp edx, -1
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
    // 004a0332  745d                   -je 0x4a0391
    if (cpu.flags.zf)
    {
        goto L_0x004a0391;
    }
    // 004a0334  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0336  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a0338  8d2c8d00000000         -lea ebp, [ecx*4]
    cpu.ebp = x86::reg32(cpu.ecx * 4);
    // 004a033f  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 004a0342  09cd                   -or ebp, ecx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0344  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a0348  0fb67301               -movzx esi, byte ptr [ebx + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */));
    // 004a034c  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0350  0fb67b02               -movzx edi, byte ptr [ebx + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */));
    // 004a0354  884802                 -mov byte ptr [eax + 2], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 004a0357  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 004a035e  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 004a0361  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a0363  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a0367  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a036b  884801                 -mov byte ptr [eax + 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004a036e  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 004a0375  43                     -inc ebx
    (cpu.ebx)++;
    // 004a0376  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 004a0379  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a037c  09f9                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a037e  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a037f  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a0383  c640ffff               -mov byte ptr [eax - 1], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = 255 /*0xff*/;
    // 004a0387  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a038b  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a038c  8848fc                 -mov byte ptr [eax - 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.cl;
    // 004a038f  eb9d                   -jmp 0x4a032e
    goto L_0x004a032e;
L_0x004a0391:
    // 004a0391  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0394  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0398  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a039d  e8cefdffff             -call 0x4a0170
    cpu.esp -= 4;
    sub_4a0170(app, cpu);
    if (cpu.terminate) return;
    // 004a03a2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a03a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a03ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a03ac);
    // 004a03ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a03ad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a03ae  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a03b0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a03b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a03b4  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 004a03bb  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 004a03c2  81c2600e5700           -add edx, 0x570e60
    (cpu.edx) += x86::reg32(x86::sreg32(5705312 /*0x570e60*/));
    // 004a03c8  e8b3a5feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a03cd  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a03d2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a03d4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a03d6  e895fdffff             -call 0x4a0170
    cpu.esp -= 4;
    sub_4a0170(app, cpu);
    if (cpu.terminate) return;
    // 004a03db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a03e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a03e0);
    // 004a03e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a03e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a03e2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a03e4  b9600e5700             -mov ecx, 0x570e60
    cpu.ecx = 5705312 /*0x570e60*/;
    // 004a03e9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a03ec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a03ee  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a03f0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a03f2  7e20                   -jle 0x4a0414
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0414;
    }
    // 004a03f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004a03f6:
    // 004a03f6  43                     -inc ebx
    (cpu.ebx)++;
    // 004a03f7  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a03fa  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004a03fd  43                     -inc ebx
    (cpu.ebx)++;
    // 004a03fe  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a0401  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0404  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004a0407  43                     -inc ebx
    (cpu.ebx)++;
    // 004a0408  8a48fc                 -mov cl, byte ptr [eax - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004a040b  42                     -inc edx
    (cpu.edx)++;
    // 004a040c  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004a040f  39f2                   +cmp edx, esi
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
    // 004a0411  7ce3                   -jl 0x4a03f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a03f6;
    }
    // 004a0413  90                     -nop 
    ;
L_0x004a0414:
    // 004a0414  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0415  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0416  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0418(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0418);
    // 004a0418  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0419  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a041a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a041c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a041e  b9600e5700             -mov ecx, 0x570e60
    cpu.ecx = 5705312 /*0x570e60*/;
    // 004a0423  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a0426  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a0428  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a042a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a042c  7e12                   -jle 0x4a0440
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0440;
    }
L_0x004a042e:
    // 004a042e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0431  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a0433  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0436  40                     -inc eax
    (cpu.eax)++;
    // 004a0437  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004a043a  39f0                   +cmp eax, esi
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
    // 004a043c  7cf0                   -jl 0x4a042e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a042e;
    }
    // 004a043e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a0440:
    // 004a0440  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0441  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0442  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0444(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0444);
    // 004a0444  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0445  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0446  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0449  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a044b  b9600e5700             -mov ecx, 0x570e60
    cpu.ecx = 5705312 /*0x570e60*/;
    // 004a0450  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a0453  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0455  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a0457  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0459  7e41                   -jle 0x4a049c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a049c;
    }
    // 004a045b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004a045d:
    // 004a045d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a045f  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a0462  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 004a0465  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0468  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004a046b  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a046d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a046f  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a0472  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 004a0475  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0478  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004a047b  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004a047e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0480  43                     -inc ebx
    (cpu.ebx)++;
    // 004a0481  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a0483  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0486  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 004a0489  43                     -inc ebx
    (cpu.ebx)++;
    // 004a048a  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a048d  43                     -inc ebx
    (cpu.ebx)++;
    // 004a048e  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004a0491  42                     -inc edx
    (cpu.edx)++;
    // 004a0492  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004a0495  39f2                   +cmp edx, esi
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
    // 004a0497  7cc4                   -jl 0x4a045d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a045d;
    }
    // 004a0499  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a049c:
    // 004a049c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a049f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a04b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a04b0);
    // 004a04b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a04b1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a04b3  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004a04b5  39d0                   +cmp eax, edx
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
    // 004a04b7  7e0b                   -jle 0x4a04c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a04c4;
    }
    // 004a04b9  39c8                   +cmp eax, ecx
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
    // 004a04bb  7c0e                   -jl 0x4a04cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a04cb;
    }
    // 004a04bd  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004a04c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a04c4:
    // 004a04c4  b800ffffff             -mov eax, 0xffffff00
    cpu.eax = 4294967040 /*0xffffff00*/;
    // 004a04c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a04cb:
    // 004a04cb  c1e00e                 -shl eax, 0xe
    cpu.eax <<= 14 /*0xe*/ % 32;
    // 004a04ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a04d0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a04d3  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a04d5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a04d8  e803000000             -call 0x4a04e0
    cpu.esp -= 4;
    sub_4a04e0(app, cpu);
    if (cpu.terminate) return;
    // 004a04dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a04e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a04e0);
    // 004a04e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a04e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a04e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a04e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a04e5  7c25                   -jl 0x4a050c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a050c;
    }
    // 004a04e7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a04e9:
    // 004a04e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a04eb  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 004a04ee  3d00fa0000             +cmp eax, 0xfa00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64000 /*0xfa00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a04f3  7f20                   -jg 0x4a0515
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a0515;
    }
    // 004a04f5  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a04f7  7401                   -je 0x4a04fa
    if (cpu.flags.zf)
    {
        goto L_0x004a04fa;
    }
    // 004a04f9  42                     -inc edx
    (cpu.edx)++;
L_0x004a04fa:
    // 004a04fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a04fc  8a82a4014e00           -mov al, byte ptr [edx + 0x4e01a4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5112228) /* 0x4e01a4 */);
    // 004a0502  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0504  7402                   -je 0x4a0508
    if (cpu.flags.zf)
    {
        goto L_0x004a0508;
    }
    // 004a0506  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004a0508:
    // 004a0508  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0509  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a050a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a050b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a050c:
    // 004a050c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a0511  f7d8                   +neg eax
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
    // 004a0513  ebd4                   -jmp 0x4a04e9
    goto L_0x004a04e9;
L_0x004a0515:
    // 004a0515  3d00000100             +cmp eax, 0x10000
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
    // 004a051a  7c0f                   -jl 0x4a052b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a052b;
    }
    // 004a051c  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004a0521  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0523  74e3                   -je 0x4a0508
    if (cpu.flags.zf)
    {
        goto L_0x004a0508;
    }
    // 004a0525  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004a0527  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0528  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0529  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a052a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a052b:
    // 004a052b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a052d  83e17f                 -and ecx, 0x7f
    cpu.ecx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004a0530  81faff010000           +cmp edx, 0x1ff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(511 /*0x1ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0536  7520                   -jne 0x4a0558
    if (!cpu.flags.zf)
    {
        goto L_0x004a0558;
    }
    // 004a0538  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a053a  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004a053f  a0a3034e00             -mov al, byte ptr [0x4e03a3]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5112739) /* 0x4e03a3 */);
    // 004a0544  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0546  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a0549  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 004a054c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a054e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0550  74b6                   -je 0x4a0508
    if (cpu.flags.zf)
    {
        goto L_0x004a0508;
    }
    // 004a0552  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004a0554  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0555  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0556  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0557  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0558:
    // 004a0558  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0559  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a055b  0fb6b2a5014e00         -movzx esi, byte ptr [edx + 0x4e01a5]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5112229) /* 0x4e01a5 */));
    // 004a0562  8a82a4014e00           -mov al, byte ptr [edx + 0x4e01a4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5112228) /* 0x4e01a4 */);
    // 004a0568  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a056a  0fafce                 -imul ecx, esi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a056d  c1f907                 -sar ecx, 7
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (7 /*0x7*/ % 32));
    // 004a0570  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0572  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0573  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0575  7491                   -je 0x4a0508
    if (cpu.flags.zf)
    {
        goto L_0x004a0508;
    }
    // 004a0577  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004a0579  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a057a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a057b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a057c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0580);
    // 004a0580  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0581  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004a0586  e855ffffff             -call 0x4a04e0
    cpu.esp -= 4;
    sub_4a04e0(app, cpu);
    if (cpu.terminate) return;
    // 004a058b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a058d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a058f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0590  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a05a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a05a0);
    // 004a05a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a05a1  8b0d0cac4d00           -mov ecx, dword ptr [0x4dac0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090316) /* 0x4dac0c */);
    // 004a05a7  a314ac4d00             -mov dword ptr [0x4dac14], eax
    app->getMemory<x86::reg32>(x86::reg32(5090324) /* 0x4dac14 */) = cpu.eax;
    // 004a05ac  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a05ae  a31cac4d00             -mov dword ptr [0x4dac1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090332) /* 0x4dac1c */) = cpu.eax;
    // 004a05b3  a110ac4d00             -mov eax, dword ptr [0x4dac10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090320) /* 0x4dac10 */);
    // 004a05b8  891518ac4d00           -mov dword ptr [0x4dac18], edx
    app->getMemory<x86::reg32>(x86::reg32(5090328) /* 0x4dac18 */) = cpu.edx;
    // 004a05be  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a05c0  891520ac4d00           -mov dword ptr [0x4dac20], edx
    app->getMemory<x86::reg32>(x86::reg32(5090336) /* 0x4dac20 */) = cpu.edx;
    // 004a05c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a05c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a05c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a05c8);
    // 004a05c8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a05c9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a05ca  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a05cc  891534ac4d00           -mov dword ptr [0x4dac34], edx
    app->getMemory<x86::reg32>(x86::reg32(5090356) /* 0x4dac34 */) = cpu.edx;
    // 004a05d2  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 004a05d4  8b1514ac4d00           -mov edx, dword ptr [0x4dac14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090324) /* 0x4dac14 */);
    // 004a05da  a330ac4d00             -mov dword ptr [0x4dac30], eax
    app->getMemory<x86::reg32>(x86::reg32(5090352) /* 0x4dac30 */) = cpu.eax;
    // 004a05df  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a05e1  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004a05e3  89151cac4d00           -mov dword ptr [0x4dac1c], edx
    app->getMemory<x86::reg32>(x86::reg32(5090332) /* 0x4dac1c */) = cpu.edx;
    // 004a05e9  8b1518ac4d00           -mov edx, dword ptr [0x4dac18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090328) /* 0x4dac18 */);
    // 004a05ef  891d0cac4d00           -mov dword ptr [0x4dac0c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090316) /* 0x4dac0c */) = cpu.ebx;
    // 004a05f5  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a05f7  890d10ac4d00           -mov dword ptr [0x4dac10], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090320) /* 0x4dac10 */) = cpu.ecx;
    // 004a05fd  891520ac4d00           -mov dword ptr [0x4dac20], edx
    app->getMemory<x86::reg32>(x86::reg32(5090336) /* 0x4dac20 */) = cpu.edx;
    // 004a0603  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004a0609  c0e507                 +shl ch, 7
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
    // 004a060c  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a060e  00ed                   +add ch, ch
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
    // 004a0610  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004a0612  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0614  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a0619  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a061b  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 004a0622  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0624  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0626  8b1d0cac4d00           -mov ebx, dword ptr [0x4dac0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090316) /* 0x4dac0c */);
    // 004a062c  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a062f  a130ac4d00             -mov eax, dword ptr [0x4dac30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090352) /* 0x4dac30 */);
    // 004a0634  c0e407                 +shl ah, 7
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
    // 004a0637  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a0639  00e4                   +add ah, ah
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
    // 004a063b  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004a063d  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a063f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a0644  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0646  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 004a064d  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a064f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0651  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0653  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0655  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0657  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a065a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a065c  a324ac4d00             -mov dword ptr [0x4dac24], eax
    app->getMemory<x86::reg32>(x86::reg32(5090340) /* 0x4dac24 */) = cpu.eax;
    // 004a0661  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0663  746a                   -je 0x4a06cf
    if (cpu.flags.zf)
    {
        goto L_0x004a06cf;
    }
    // 004a0665  a134ac4d00             -mov eax, dword ptr [0x4dac34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090356) /* 0x4dac34 */);
    // 004a066a  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004a0670  c0e507                 +shl ch, 7
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
    // 004a0673  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a0675  00ed                   +add ch, ch
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
    // 004a0677  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004a0679  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a067b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a0680  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0682  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 004a0689  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a068b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a068d  8b1510ac4d00           -mov edx, dword ptr [0x4dac10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090320) /* 0x4dac10 */);
    // 004a0693  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0695  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a0698  a134ac4d00             -mov eax, dword ptr [0x4dac34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090356) /* 0x4dac34 */);
    // 004a069d  c0e407                 +shl ah, 7
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
    // 004a06a0  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a06a2  00e4                   +add ah, ah
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
    // 004a06a4  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004a06a6  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a06a8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a06ad  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a06af  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 004a06b6  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a06b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a06ba  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 004a06bc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a06be  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a06c0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a06c2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a06c5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a06c7  a328ac4d00             -mov dword ptr [0x4dac28], eax
    app->getMemory<x86::reg32>(x86::reg32(5090344) /* 0x4dac28 */) = cpu.eax;
    // 004a06cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a06cf:
    // 004a06cf  8b1538ac4d00           -mov edx, dword ptr [0x4dac38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */);
    // 004a06d5  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a06d7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a06da  c1e810                 +shr eax, 0x10
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
    // 004a06dd  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a06df  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a06e1  8b1510ac4d00           -mov edx, dword ptr [0x4dac10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090320) /* 0x4dac10 */);
    // 004a06e7  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 004a06e9  a328ac4d00             -mov dword ptr [0x4dac28], eax
    app->getMemory<x86::reg32>(x86::reg32(5090344) /* 0x4dac28 */) = cpu.eax;
    // 004a06ee  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a06f0  892d28ac4d00           -mov dword ptr [0x4dac28], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090344) /* 0x4dac28 */) = cpu.ebp;
    // 004a06f6  e8e5d0ffff             -call 0x49d7e0
    cpu.esp -= 4;
    sub_49d7e0(app, cpu);
    if (cpu.terminate) return;
    // 004a06fb  a334ac4d00             -mov dword ptr [0x4dac34], eax
    app->getMemory<x86::reg32>(x86::reg32(5090356) /* 0x4dac34 */) = cpu.eax;
    // 004a0700  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0701  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0702  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0704(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0704);
    // 004a0704  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0705  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0706  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a0708  c1e20a                 -shl edx, 0xa
    cpu.edx <<= 10 /*0xa*/ % 32;
    // 004a070b  be68010000             -mov esi, 0x168
    cpu.esi = 360 /*0x168*/;
    // 004a0710  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0712  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0715  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0717  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a0719  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a071b  c1e20a                 -shl edx, 0xa
    cpu.edx <<= 10 /*0xa*/ % 32;
    // 004a071e  bf68010000             -mov edi, 0x168
    cpu.edi = 360 /*0x168*/;
    // 004a0723  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0725  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0728  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a072a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a072c  e897feffff             -call 0x4a05c8
    cpu.esp -= 4;
    sub_4a05c8(app, cpu);
    if (cpu.terminate) return;
    // 004a0731  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0732  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0733  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0734(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0734);
    // 004a0734  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0735  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004a0739  7e46                   -jle 0x4a0781
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0781;
    }
    // 004a073b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a073c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a073d  8b0d24ac4d00           -mov ecx, dword ptr [0x4dac24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090340) /* 0x4dac24 */);
    // 004a0743  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a0745  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a0748  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a074b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a074d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0750  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0752  8b151cac4d00           -mov edx, dword ptr [0x4dac1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090332) /* 0x4dac1c */);
    // 004a0758  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a075a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a075c  8b2d28ac4d00           -mov ebp, dword ptr [0x4dac28]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090344) /* 0x4dac28 */);
    // 004a0762  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a0765  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a0768  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a076b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a076d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0770  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0772  8b1520ac4d00           -mov edx, dword ptr [0x4dac20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090336) /* 0x4dac20 */);
    // 004a0778  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a077a  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a077d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a077e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a077f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0780  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0781:
    // 004a0781  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 004a0788  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a078b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a078d  800d2cac4d0001         -or byte ptr [0x4dac2c], 1
    app->getMemory<x86::reg8>(x86::reg32(5090348) /* 0x4dac2c */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a0794  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0795  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0796(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0796);
    // 004a0796  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0797  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0798  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a0799  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004a079b  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004a079d  c8080000               -enter 8, 0
    {
        cpu.esp -= 4;
        app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
        cpu.ebp = cpu.esp;
        cpu.esp -= 8;
    }
    // 004a07a1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a07a3  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a07a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a07a7  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004a07aa  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004a07ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a07af  744f                   -je 0x4a0800
    if (cpu.flags.zf)
    {
        goto L_0x004a0800;
    }
    // 004a07b1  48                     -dec eax
    (cpu.eax)--;
    // 004a07b2  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a07b5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a07b7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a07b9  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x004a07bc:
    // 004a07bc  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a07bf  732c                   -jae 0x4a07ed
    if (!cpu.flags.cf)
    {
        goto L_0x004a07ed;
    }
    // 004a07c1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a07c4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a07c6  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a07c8  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a07ca  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004a07cc  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a07cf  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a07d2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a07d4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a07d6  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a07d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a07db  7504                   -jne 0x4a07e1
    if (!cpu.flags.zf)
    {
        goto L_0x004a07e1;
    }
    // 004a07dd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a07df  eb1f                   -jmp 0x4a0800
    goto L_0x004a0800;
L_0x004a07e1:
    // 004a07e1  7d05                   -jge 0x4a07e8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a07e8;
    }
    // 004a07e3  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a07e6  ebd4                   -jmp 0x4a07bc
    goto L_0x004a07bc;
L_0x004a07e8:
    // 004a07e8  8d1c31                 -lea ebx, [ecx + esi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 004a07eb  ebcf                   -jmp 0x4a07bc
    goto L_0x004a07bc;
L_0x004a07ed:
    // 004a07ed  750f                   -jne 0x4a07fe
    if (!cpu.flags.zf)
    {
        goto L_0x004a07fe;
    }
    // 004a07ef  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a07f1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a07f3  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a07f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a07f8  7504                   -jne 0x4a07fe
    if (!cpu.flags.zf)
    {
        goto L_0x004a07fe;
    }
    // 004a07fa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a07fc  eb02                   -jmp 0x4a0800
    goto L_0x004a0800;
L_0x004a07fe:
    // 004a07fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a0800:
    // 004a0800  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0801  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a0803  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a0805  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a0806  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0807  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0808  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4a080b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a080b);
    // 004a080b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a080c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a080d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a080e  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004a0810  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004a0812  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a0814  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a0816  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0818  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a081a  7e1c                   -jle 0x4a0838
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0838;
    }
    // 004a081c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a081e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0820  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0822  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0824  7e0e                   -jle 0x4a0834
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0834;
    }
    // 004a0826  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0828  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a082a  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a082c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a082e  7f1c                   -jg 0x4a084c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a084c;
    }
L_0x004a0830:
    // 004a0830  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0832  eb1a                   -jmp 0x4a084e
    goto L_0x004a084e;
L_0x004a0834:
    // 004a0834  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0836  eb16                   -jmp 0x4a084e
    goto L_0x004a084e;
L_0x004a0838:
    // 004a0838  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a083a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a083c  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a083e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0840  7df2                   -jge 0x4a0834
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0834;
    }
    // 004a0842  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0844  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0846  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0848  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a084a  7fe4                   -jg 0x4a0830
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a0830;
    }
L_0x004a084c:
    // 004a084c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a084e:
    // 004a084e  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a0850  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a0852  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a0853  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0854  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0855  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
