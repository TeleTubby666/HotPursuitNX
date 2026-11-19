#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_492258(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492258);
    // 00492258  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492259  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049225d  e8daffffff             -call 0x49223c
    cpu.esp -= 4;
    sub_49223c(app, cpu);
    if (cpu.terminate) return;
    // 00492262  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492263  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492267  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492268  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049226a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049226c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492270  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492272  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492274  8a824cad4d00           -mov al, byte ptr [edx + 0x4dad4c]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5090636) /* 0x4dad4c */);
    // 0049227a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049227b  e89097ffff             -call 0x48ba10
    cpu.esp -= 4;
    sub_48ba10(app, cpu);
    if (cpu.terminate) return;
    // 00492280  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492281  ff15d4c95600           -call dword ptr [0x56c9d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687764) /* 0x56c9d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492287  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492289  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049228b  7506                   -jne 0x492293
    if (!cpu.flags.zf)
    {
        goto L_0x00492293;
    }
    // 0049228d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049228f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492290  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00492293:
    // 00492293  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492294  e857020000             -call 0x4924f0
    cpu.esp -= 4;
    sub_4924f0(app, cpu);
    if (cpu.terminate) return;
    // 00492299  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049229b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049229d  ff15d8c95600           -call dword ptr [0x56c9d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687768) /* 0x56c9d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922a3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922a5  ff15dcc95600           -call dword ptr [0x56c9dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687772) /* 0x56c9dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922ab  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004922ad  ff15e0c95600           -call dword ptr [0x56c9e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687776) /* 0x56c9e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922b3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004922b5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004922b7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922b9  ff1514ca5600           -call dword ptr [0x56ca14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687828) /* 0x56ca14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922bf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922c1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922c3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922c5  ff1560ca5600           -call dword ptr [0x56ca60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687904) /* 0x56ca60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922cb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922cd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922cf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922d1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004922d3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922d5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004922d7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922d9  ff1564ca5600           -call dword ptr [0x56ca64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687908) /* 0x56ca64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922df  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922e1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004922e3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922e5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922e7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004922e9  ff1504ca5600           -call dword ptr [0x56ca04]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687812) /* 0x56ca04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922ef  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922f1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004922f3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922f7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004922f9  ff1508ca5600           -call dword ptr [0x56ca08]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687816) /* 0x56ca08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922ff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492301  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492303  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00492305  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492307  ff150cca5600           -call dword ptr [0x56ca0c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687820) /* 0x56ca0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049230d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049230f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492311  e862030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 00492316  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492318  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0049231a  e859030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 0049231f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492321  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00492323  e850030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 00492328  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049232a  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0049232c  e847030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 00492331  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00492333  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00492335  e83e030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 0049233a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049233c  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0049233e  e835030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 00492343  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492345  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00492347  e82c030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 0049234c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049234e  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00492350  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00492354  e81f030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 00492359  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049235b  7443                   -je 0x4923a0
    if (cpu.flags.zf)
    {
        goto L_0x004923a0;
    }
    // 0049235d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00492362:
    // 00492362  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492363  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00492365  e80e030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 0049236a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049236c  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 0049236e  e805030000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 00492373  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00492375  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00492377  e8fc020000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 0049237c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049237e  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00492380  e8f3020000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 00492385  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 0049238a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049238b  6a65                   -push 0x65
    app->getMemory<x86::reg32>(cpu.esp-4) = 101 /*0x65*/;
    cpu.esp -= 4;
    // 0049238d  e8e6020000             -call 0x492678
    cpu.esp -= 4;
    sub_492678(app, cpu);
    if (cpu.terminate) return;
    // 00492392  800d30ad4d0002         -or byte ptr [0x4dad30], 2
    app->getMemory<x86::reg8>(x86::reg32(5090608) /* 0x4dad30 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00492399  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049239a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049239c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049239d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004923a0:
    // 004923a0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004923a2  ebbe                   -jmp 0x492362
    goto L_0x00492362;
}

/* align: skip  */
void Application::sub_4923a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004923a4);
    // 004923a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004923a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004923a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004923a7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004923a8  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004923ac  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004923b0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004923b2  39ef                   +cmp edi, ebp
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
    // 004923b4  7e63                   -jle 0x492419
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492419;
    }
    // 004923b6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004923b8:
    // 004923b8  e8f3710100             -call 0x4a95b0
    cpu.esp -= 4;
    sub_4a95b0(app, cpu);
    if (cpu.terminate) return;
    // 004923bd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004923bf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004923c1  e8ea710100             -call 0x4a95b0
    cpu.esp -= 4;
    sub_4a95b0(app, cpu);
    if (cpu.terminate) return;
    // 004923c6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004923c8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004923ca  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004923ce  e8dd710100             -call 0x4a95b0
    cpu.esp -= 4;
    sub_4a95b0(app, cpu);
    if (cpu.terminate) return;
    // 004923d3  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004923d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004923d7  8a8269ad4d00           -mov al, byte ptr [edx + 0x4dad69]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5090665) /* 0x4dad69 */);
    // 004923dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004923de  0fb6af65ad4d00         -movzx ebp, byte ptr [edi + 0x4dad65]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5090661) /* 0x4dad65 */));
    // 004923e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004923e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004923e8  8a8359ad4d00           -mov al, byte ptr [ebx + 0x4dad59]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5090649) /* 0x4dad59 */);
    // 004923ee  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004923f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004923f3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004923f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004923f6  ff1568ca5600           -call dword ptr [0x56ca68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687912) /* 0x56ca68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004923fc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004923fe  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492400  ff1574ca5600           -call dword ptr [0x56ca74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687924) /* 0x56ca74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492406  2b0518cb5600           -sub eax, dword ptr [0x56cb18]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5688088) /* 0x56cb18 */)));
    // 0049240c  39f8                   +cmp eax, edi
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
    // 0049240e  770d                   -ja 0x49241d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049241d;
    }
L_0x00492410:
    // 00492410  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492412  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492413  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492414  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492415  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492416  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00492419:
    // 00492419  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049241b  eb9b                   -jmp 0x4923b8
    goto L_0x004923b8;
L_0x0049241d:
    // 0049241d  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 00492422  e80cfd0000             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 00492427  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492429  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049242b  74e3                   -je 0x492410
    if (cpu.flags.zf)
    {
        goto L_0x00492410;
    }
    // 0049242d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049242f  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492433  8a9359ad4d00           -mov dl, byte ptr [ebx + 0x4dad59]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5090649) /* 0x4dad59 */);
    // 00492439  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049243b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049243d  8a9b59ad4d00           -mov bl, byte ptr [ebx + 0x4dad59]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5090649) /* 0x4dad59 */);
    // 00492443  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492449  896808                 -mov dword ptr [eax + 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0049244c  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00492450  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00492453  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492455  8a9a69ad4d00           -mov bl, byte ptr [edx + 0x4dad69]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5090665) /* 0x4dad69 */);
    // 0049245b  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00492462  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00492465  8b1d18cb5600           -mov ebx, dword ptr [0x56cb18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5688088) /* 0x56cb18 */);
    // 0049246b  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0049246e  8b1d44ad4d00           -mov ebx, dword ptr [0x4dad44]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090628) /* 0x4dad44 */);
    // 00492474  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00492477  8b1d18cb5600           -mov ebx, dword ptr [0x56cb18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5688088) /* 0x56cb18 */);
    // 0049247d  c7401803000000         -mov dword ptr [eax + 0x18], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 3 /*0x3*/;
    // 00492484  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492486  a344ad4d00             -mov dword ptr [0x4dad44], eax
    app->getMemory<x86::reg32>(x86::reg32(5090628) /* 0x4dad44 */) = cpu.eax;
    // 0049248b  891d18cb5600           -mov dword ptr [0x56cb18], ebx
    app->getMemory<x86::reg32>(x86::reg32(5688088) /* 0x56cb18 */) = cpu.ebx;
    // 00492491  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492493  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492494  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492495  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492496  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492497  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49249c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049249c);
    // 0049249c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049249d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049249e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004924a2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004924a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004924a8  750f                   -jne 0x4924b9
    if (!cpu.flags.zf)
    {
        goto L_0x004924b9;
    }
    // 004924aa  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004924ae  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004924b0  752a                   -jne 0x4924dc
    if (!cpu.flags.zf)
    {
        goto L_0x004924dc;
    }
    // 004924b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004924b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924b6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004924b9:
    // 004924b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004924ba  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004924bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004924be  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004924c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004924c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004924c4  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004924c7  ff156cca5600           -call dword ptr [0x56ca6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687916) /* 0x56ca6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004924cd  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004924d1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004924d3  7507                   -jne 0x4924dc
    if (!cpu.flags.zf)
    {
        goto L_0x004924dc;
    }
    // 004924d5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004924d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924d9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004924dc:
    // 004924dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004924dd  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004924df  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004924e1  ff15e4c95600           -call dword ptr [0x56c9e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687780) /* 0x56c9e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004924e7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004924e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924eb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4924f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004924f0);
    // 004924f0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004924f2  ff1570ca5600           -call dword ptr [0x56ca70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687920) /* 0x56ca70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004924f8  8b1544ad4d00           -mov edx, dword ptr [0x4dad44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090628) /* 0x4dad44 */);
    // 004924fe  a318cb5600             -mov dword ptr [0x56cb18], eax
    app->getMemory<x86::reg32>(x86::reg32(5688088) /* 0x56cb18 */) = cpu.eax;
    // 00492503  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492505  7419                   -je 0x492520
    if (cpu.flags.zf)
    {
        goto L_0x00492520;
    }
L_0x00492507:
    // 00492507  a144ad4d00             -mov eax, dword ptr [0x4dad44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090628) /* 0x4dad44 */);
    // 0049250c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049250f  e8a44b0100             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 00492514  891544ad4d00           -mov dword ptr [0x4dad44], edx
    app->getMemory<x86::reg32>(x86::reg32(5090628) /* 0x4dad44 */) = cpu.edx;
    // 0049251a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049251c  75e9                   -jne 0x492507
    if (!cpu.flags.zf)
    {
        goto L_0x00492507;
    }
    // 0049251e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00492520:
    // 00492520  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492525  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492528(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492528);
    // 00492528  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492529  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049252a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049252b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049252f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492531  7514                   -jne 0x492547
    if (!cpu.flags.zf)
    {
        goto L_0x00492547;
    }
    // 00492533  833d74ad4d0000         +cmp dword ptr [0x4dad74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090676) /* 0x4dad74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049253a  7552                   -jne 0x49258e
    if (!cpu.flags.zf)
    {
        goto L_0x0049258e;
    }
L_0x0049253c:
    // 0049253c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492541  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492542  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492543  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492544  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00492547:
    // 00492547  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492548  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0049254b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049254c  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049254f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492550  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492552  ff1578ca5600           -call dword ptr [0x56ca78]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687928) /* 0x56ca78 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492558  833d74ad4d0001         +cmp dword ptr [0x4dad74], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090676) /* 0x4dad74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049255f  74db                   -je 0x49253c
    if (cpu.flags.zf)
    {
        goto L_0x0049253c;
    }
    // 00492561  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492563  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492565  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492567  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492569  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0049256b  ff1504ca5600           -call dword ptr [0x56ca04]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687812) /* 0x56ca04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492571  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492573  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492575  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492577  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492579  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0049257b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00492580  ff1508ca5600           -call dword ptr [0x56ca08]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687816) /* 0x56ca08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492586  892d74ad4d00           -mov dword ptr [0x4dad74], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090676) /* 0x4dad74 */) = cpu.ebp;
    // 0049258c  ebae                   -jmp 0x49253c
    goto L_0x0049253c;
L_0x0049258e:
    // 0049258e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049258f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00492591  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492592  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492593  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492595  ff1504ca5600           -call dword ptr [0x56ca04]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687812) /* 0x56ca04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049259b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049259d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0049259f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004925a1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004925a3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004925a5  ff1508ca5600           -call dword ptr [0x56ca08]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687816) /* 0x56ca08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004925ab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004925ad  890d74ad4d00           -mov dword ptr [0x4dad74], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090676) /* 0x4dad74 */) = cpu.ecx;
    // 004925b3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004925b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004925b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004925ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004925bb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4925c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004925c0);
    // 004925c0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004925c4  48                     -dec eax
    (cpu.eax)--;
    // 004925c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004925c6  a33cad4d00             -mov dword ptr [0x4dad3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090620) /* 0x4dad3c */) = cpu.eax;
    // 004925cb  ff15e8c95600           -call dword ptr [0x56c9e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687784) /* 0x56c9e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004925d1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004925d6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4925dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004925dc);
    // 004925dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004925de  66a138ad4d00           -mov ax, word ptr [0x4dad38]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5090616) /* 0x4dad38 */);
    // 004925e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004925e5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004925e7  8b1534ad4d00           -mov edx, dword ptr [0x4dad34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090612) /* 0x4dad34 */);
    // 004925ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004925ee  ff15ecc95600           -call dword ptr [0x56c9ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687788) /* 0x56c9ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004925f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4925f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004925f4);
    goto L_entry_0x004925f4;
    // 004925dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004925de  66a138ad4d00           -mov ax, word ptr [0x4dad38]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5090616) /* 0x4dad38 */);
    // 004925e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004925e5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004925e7  8b1534ad4d00           -mov edx, dword ptr [0x4dad34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090612) /* 0x4dad34 */);
    // 004925ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004925ee  ff15ecc95600           -call dword ptr [0x56c9ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687788) /* 0x56c9ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x004925f4:
    // 004925f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4925f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004925f8);
    // 004925f8  8b1540ad4d00           -mov edx, dword ptr [0x4dad40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090624) /* 0x4dad40 */);
    // 004925fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004925ff  ff15f0c95600           -call dword ptr [0x56c9f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687792) /* 0x56c9f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492605  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492608(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492608);
    // 00492608  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492609  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049260d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049260f  83f801                 +cmp eax, 1
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
    // 00492612  7227                   -jb 0x49263b
    if (cpu.flags.cf)
    {
        goto L_0x0049263b;
    }
    // 00492614  762d                   -jbe 0x492643
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00492643;
    }
    // 00492616  83f802                 +cmp eax, 2
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
    // 00492619  7520                   -jne 0x49263b
    if (!cpu.flags.zf)
    {
        goto L_0x0049263b;
    }
    // 0049261b  ff15f4c95600           -call dword ptr [0x56c9f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687796) /* 0x56c9f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492621  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492623  c1eb0c                 -shr ebx, 0xc
    cpu.ebx >>= 12 /*0xc*/ % 32;
    // 00492626  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 0049262b  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00492631  29d8                   +sub eax, ebx
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
    // 00492633  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00492635:
    // 00492635  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00492637  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492638  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049263b:
    // 0049263b  ff15f8c95600           -call dword ptr [0x56c9f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687800) /* 0x56c9f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492641  ebf2                   -jmp 0x492635
    goto L_0x00492635;
L_0x00492643:
    // 00492643  ff15fcc95600           -call dword ptr [0x56c9fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687804) /* 0x56c9fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492649  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049264b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049264d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049264e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492654(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492654);
    // 00492654  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492655  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492656  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049265a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049265b  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049265f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492660  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492664  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492665  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492669  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049266a  ff1500ca5600           -call dword ptr [0x56ca00]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687808) /* 0x56ca00 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492670  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492671  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492672  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492678(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492678);
    // 00492678  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492679  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049267a  83ec48                 -sub esp, 0x48
    (cpu.esp) -= x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0049267d  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00492681  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492683  83fa09                 +cmp edx, 9
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
    // 00492686  7325                   -jae 0x4926ad
    if (!cpu.flags.cf)
    {
        goto L_0x004926ad;
    }
    // 00492688  83fa04                 +cmp edx, 4
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
    // 0049268b  0f83e8000000           -jae 0x492779
    if (!cpu.flags.cf)
    {
        goto L_0x00492779;
    }
    // 00492691  83fa02                 +cmp edx, 2
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
    // 00492694  0f834f010000           -jae 0x4927e9
    if (!cpu.flags.cf)
    {
        goto L_0x004927e9;
    }
    // 0049269a  83fa01                 +cmp edx, 1
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
    // 0049269d  0f8460010000           -je 0x492803
    if (cpu.flags.zf)
    {
        goto L_0x00492803;
    }
L_0x004926a3:
    // 004926a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004926a5:
    // 004926a5  83c448                 +add esp, 0x48
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
    // 004926a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004926a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004926aa  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004926ad:
    // 004926ad  76f4                   -jbe 0x4926a3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004926a3;
    }
    // 004926af  83fa0f                 +cmp edx, 0xf
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
    // 004926b2  732d                   -jae 0x4926e1
    if (!cpu.flags.cf)
    {
        goto L_0x004926e1;
    }
    // 004926b4  83fa0d                 +cmp edx, 0xd
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
    // 004926b7  0f8390000000           -jae 0x49274d
    if (!cpu.flags.cf)
    {
        goto L_0x0049274d;
    }
    // 004926bd  83fa0a                 +cmp edx, 0xa
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
    // 004926c0  75e1                   -jne 0x4926a3
    if (!cpu.flags.zf)
    {
        goto L_0x004926a3;
    }
    // 004926c2  8b742458               -mov esi, dword ptr [esp + 0x58]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004926c6  83fe01                 +cmp esi, 1
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
    // 004926c9  0f8396010000           -jae 0x492865
    if (!cpu.flags.cf)
    {
        goto L_0x00492865;
    }
    // 004926cf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004926d1  0f84c7010000           -je 0x49289e
    if (cpu.flags.zf)
    {
        goto L_0x0049289e;
    }
    // 004926d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004926d9  83c448                 +add esp, 0x48
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
    // 004926dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004926dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004926de  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004926e1:
    // 004926e1  7724                   -ja 0x492707
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00492707;
    }
    // 004926e3  837c245800             +cmp dword ptr [esp + 0x58], 0
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
    // 004926e8  7505                   -jne 0x4926ef
    if (!cpu.flags.zf)
    {
        goto L_0x004926ef;
    }
    // 004926ea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004926ef:
    // 004926ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004926f0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004926f2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004926f4  ff157cca5600           -call dword ptr [0x56ca7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687932) /* 0x56ca7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004926fa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004926ff  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00492702  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492703  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492704  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492707:
    // 00492707  83fa66                 +cmp edx, 0x66
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
    // 0049270a  731c                   -jae 0x492728
    if (!cpu.flags.cf)
    {
        goto L_0x00492728;
    }
    // 0049270c  83fa65                 +cmp edx, 0x65
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
    // 0049270f  7592                   -jne 0x4926a3
    if (!cpu.flags.zf)
    {
        goto L_0x004926a3;
    }
    // 00492711  ff742458               -push dword ptr [esp + 0x58]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    // 00492715  ff1558ca5600           -call dword ptr [0x56ca58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687896) /* 0x56ca58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049271b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492720  83c448                 +add esp, 0x48
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
    // 00492723  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492724  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492725  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492728:
    // 00492728  0f86fe010000           -jbe 0x49292c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049292c;
    }
    // 0049272e  83fa67                 +cmp edx, 0x67
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
    // 00492731  0f856cffffff           -jne 0x4926a3
    if (!cpu.flags.zf)
    {
        goto L_0x004926a3;
    }
    // 00492737  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049273b  a340ad4d00             -mov dword ptr [0x4dad40], eax
    app->getMemory<x86::reg32>(x86::reg32(5090624) /* 0x4dad40 */) = cpu.eax;
    // 00492740  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492745  83c448                 +add esp, 0x48
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
    // 00492748  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492749  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049274a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049274d:
    // 0049274d  0f87ad010000           -ja 0x492900
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00492900;
    }
    // 00492753  837c245800             +cmp dword ptr [esp + 0x58], 0
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
    // 00492758  0f84ba010000           -je 0x492918
    if (cpu.flags.zf)
    {
        goto L_0x00492918;
    }
    // 0049275e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00492760  ff1534ca5600           -call dword ptr [0x56ca34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687860) /* 0x56ca34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492766  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492768  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492769  ff1538ca5600           -call dword ptr [0x56ca38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687864) /* 0x56ca38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049276f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492771  83c448                 +add esp, 0x48
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
    // 00492774  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492775  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492776  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492779:
    // 00492779  0f866b010000           -jbe 0x4928ea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004928ea;
    }
    // 0049277f  83fa07                 +cmp edx, 7
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
    // 00492782  7329                   -jae 0x4927ad
    if (!cpu.flags.cf)
    {
        goto L_0x004927ad;
    }
    // 00492784  83fa06                 +cmp edx, 6
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
    // 00492787  0f8516ffffff           -jne 0x4926a3
    if (!cpu.flags.zf)
    {
        goto L_0x004926a3;
    }
    // 0049278d  837c245800             +cmp dword ptr [esp + 0x58], 0
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
    // 00492792  7405                   -je 0x492799
    if (cpu.flags.zf)
    {
        goto L_0x00492799;
    }
    // 00492794  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00492799:
    // 00492799  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049279a  ff1518ca5600           -call dword ptr [0x56ca18]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687832) /* 0x56ca18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004927a0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004927a5  83c448                 +add esp, 0x48
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
    // 004927a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927aa  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004927ad:
    // 004927ad  0f86f0feffff           -jbe 0x4926a3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004926a3;
    }
    // 004927b3  8b5c2458               -mov ebx, dword ptr [esp + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004927b7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004927b9  7475                   -je 0x492830
    if (cpu.flags.zf)
    {
        goto L_0x00492830;
    }
    // 004927bb  83fb01                 +cmp ebx, 1
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
    // 004927be  0f8488000000           -je 0x49284c
    if (cpu.flags.zf)
    {
        goto L_0x0049284c;
    }
    // 004927c4  83fb02                 +cmp ebx, 2
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
    // 004927c7  0f85d8feffff           -jne 0x4926a5
    if (!cpu.flags.zf)
    {
        goto L_0x004926a5;
    }
    // 004927cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004927ce  ff151cca5600           -call dword ptr [0x56ca1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687836) /* 0x56ca1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004927d4  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004927d6  ff1520ca5600           -call dword ptr [0x56ca20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687840) /* 0x56ca20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004927dc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004927e1  83c448                 +add esp, 0x48
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
    // 004927e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927e6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004927e9:
    // 004927e9  772a                   -ja 0x492815
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00492815;
    }
    // 004927eb  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004927ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004927f0  ff1510ca5600           -call dword ptr [0x56ca10]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687824) /* 0x56ca10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004927f6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004927fb  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004927fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492800  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492803:
    // 00492803  8b5c2458               -mov ebx, dword ptr [esp + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00492807  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492808  e81bfdffff             -call 0x492528
    cpu.esp -= 4;
    sub_492528(app, cpu);
    if (cpu.terminate) return;
    // 0049280d  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00492810  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492811  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492812  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492815:
    // 00492815  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00492819  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049281a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049281b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049281d  ff1514ca5600           -call dword ptr [0x56ca14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687828) /* 0x56ca14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492823  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492828  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0049282b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049282c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049282d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492830:
    // 00492830  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492831  ff151cca5600           -call dword ptr [0x56ca1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687836) /* 0x56ca1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492837  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00492839  ff1520ca5600           -call dword ptr [0x56ca20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687840) /* 0x56ca20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049283f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492844  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00492847  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492848  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492849  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049284c:
    // 0049284c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049284d  ff151cca5600           -call dword ptr [0x56ca1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687836) /* 0x56ca1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492853  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00492855  ff1520ca5600           -call dword ptr [0x56ca20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687840) /* 0x56ca20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049285b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049285d  83c448                 +add esp, 0x48
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
    // 00492860  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492861  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492862  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492865:
    // 00492865  7653                   -jbe 0x4928ba
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004928ba;
    }
    // 00492867  83fe02                 +cmp esi, 2
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
    // 0049286a  0f8533feffff           -jne 0x4926a3
    if (!cpu.flags.zf)
    {
        goto L_0x004926a3;
    }
    // 00492870  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492871  ff1524ca5600           -call dword ptr [0x56ca24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687844) /* 0x56ca24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492877  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00492879  ff1528ca5600           -call dword ptr [0x56ca28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687848) /* 0x56ca28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049287f  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 00492884  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492886  a338ad4d00             -mov dword ptr [0x4dad38], eax
    app->getMemory<x86::reg32>(x86::reg32(5090616) /* 0x4dad38 */) = cpu.eax;
    // 0049288b  ff152cca5600           -call dword ptr [0x56ca2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687852) /* 0x56ca2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492891  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492896  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00492899  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049289a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049289b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049289e:
    // 0049289e  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004928a0  ff1528ca5600           -call dword ptr [0x56ca28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687848) /* 0x56ca28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004928a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004928a7  ff152cca5600           -call dword ptr [0x56ca2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687852) /* 0x56ca2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004928ad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004928b2  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004928b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928b7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004928ba:
    // 004928ba  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004928bc  ff1524ca5600           -call dword ptr [0x56ca24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687844) /* 0x56ca24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004928c2  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004928c4  ff1528ca5600           -call dword ptr [0x56ca28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687848) /* 0x56ca28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004928ca  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004928cf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004928d1  891538ad4d00           -mov dword ptr [0x4dad38], edx
    app->getMemory<x86::reg32>(x86::reg32(5090616) /* 0x4dad38 */) = cpu.edx;
    // 004928d7  ff152cca5600           -call dword ptr [0x56ca2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687852) /* 0x56ca2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004928dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004928e2  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004928e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928e7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004928ea:
    // 004928ea  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004928ee  a334ad4d00             -mov dword ptr [0x4dad34], eax
    app->getMemory<x86::reg32>(x86::reg32(5090612) /* 0x4dad34 */) = cpu.eax;
    // 004928f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004928f8  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004928fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928fd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492900:
    // 00492900  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00492904  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492905  ff1530ca5600           -call dword ptr [0x56ca30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687856) /* 0x56ca30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049290b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492910  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00492913  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492914  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492915  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492918:
    // 00492918  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492919  ff1534ca5600           -call dword ptr [0x56ca34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687860) /* 0x56ca34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049291f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492924  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00492927  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492928  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492929  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049292c:
    // 0049292c  d9442458               -fld dword ptr [esp + 0x58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(88) /* 0x58 */)));
    // 00492930  e86b20ffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 00492935  db5c2440               -fistp dword ptr [esp + 0x40]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00492939  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049293d  6689442444             -mov word ptr [esp + 0x44], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ax;
    // 00492942  8b442442               -mov eax, dword ptr [esp + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(66) /* 0x42 */);
    // 00492946  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00492949  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049294a  ff155cca5600           -call dword ptr [0x56ca5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687900) /* 0x56ca5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492950  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492955  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00492958  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492959  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049295a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492960);
    // 00492960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492961  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00492964  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492966  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492967  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492969  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049296a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049296b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049296c  8b0d3cad4d00           -mov ecx, dword ptr [0x4dad3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090620) /* 0x4dad3c */);
    // 00492972  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492973  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 00492978  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049297a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049297e  ff153cca5600           -call dword ptr [0x56ca3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687868) /* 0x56ca3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492984  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492986  7507                   -jne 0x49298f
    if (!cpu.flags.zf)
    {
        goto L_0x0049298f;
    }
L_0x00492988:
    // 00492988  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049298a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049298d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049298e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049298f:
    // 0049298f  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00492994  e89af70000             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 00492999  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049299b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049299d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049299f  74e7                   -je 0x492988
    if (cpu.flags.zf)
    {
        goto L_0x00492988;
    }
    // 004929a1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004929a5  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004929a7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004929ab  c742080a000000         -mov dword ptr [edx + 8], 0xa
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 10 /*0xa*/;
    // 004929b2  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004929b5  a13cad4d00             -mov eax, dword ptr [0x4dad3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090620) /* 0x4dad3c */);
    // 004929ba  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004929bd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004929bf  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004929c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004929c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4929c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004929c4);
    // 004929c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004929c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004929c6  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004929ca  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004929cf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004929d1  7507                   -jne 0x4929da
    if (!cpu.flags.zf)
    {
        goto L_0x004929da;
    }
    // 004929d3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004929d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004929d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004929d7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004929da:
    // 004929da  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004929dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004929de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004929df  ff1540ca5600           -call dword ptr [0x56ca40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687872) /* 0x56ca40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004929e5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004929e7  e8cc460100             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004929ec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004929ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004929ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004929f0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4929f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004929f4);
    // 004929f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004929f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004929f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004929f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004929f8  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004929fc  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492a00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492a01  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00492a04  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492a05  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492a09  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492a0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492a0b  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492a0f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492a10  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492a14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492a15  8b2d3cad4d00           -mov ebp, dword ptr [0x4dad3c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090620) /* 0x4dad3c */);
    // 00492a1b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492a1c  ff1548ca5600           -call dword ptr [0x56ca48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687880) /* 0x56ca48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492a22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a26  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492a2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492a2c);
    // 00492a2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492a2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492a2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492a2f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492a30  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00492a34  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492a38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492a39  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00492a3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492a3d  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492a41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492a42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492a43  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492a45  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492a49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492a4a  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492a4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492a4f  8b2d3cad4d00           -mov ebp, dword ptr [0x4dad3c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090620) /* 0x4dad3c */);
    // 00492a55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492a56  ff1544ca5600           -call dword ptr [0x56ca44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687876) /* 0x56ca44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492a5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a60  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_492a64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492a64);
    // 00492a64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492a65  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00492a6b  8b9424f8000000         -mov edx, dword ptr [esp + 0xf8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 00492a72  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00492a79  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492a7c  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492a82  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492a85  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492a8b  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492a8d  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492a93  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492a96  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492a9c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492a9e  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492aa0  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492aa3  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00492aa6  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492aa9  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00492aac  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492aae  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492ab0  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00492ab3  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492aba  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00492abd  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00492ac0  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492ac7  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492aca  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492acd  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00492ad0  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00492ad3  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492ada  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492add  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00492ae0  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492ae7  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492aea  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492aed  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492af0  8b9424fc000000         -mov edx, dword ptr [esp + 0xfc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 00492af7  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00492afb  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492afe  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492b04  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492b07  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492b0d  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492b0f  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492b15  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492b18  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492b1e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492b20  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492b22  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492b25  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00492b28  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492b2b  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00492b2e  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492b30  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492b32  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00492b35  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492b3c  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00492b3f  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00492b42  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492b49  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492b4c  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492b4f  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00492b52  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00492b55  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492b5c  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492b5f  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00492b62  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492b69  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492b6c  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492b6f  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492b72  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00492b79  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492b7b  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492b7e  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492b84  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492b87  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492b8d  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492b8f  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492b95  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492b98  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492b9e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492ba0  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492ba2  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492ba5  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00492ba8  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492bab  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00492bae  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492bb0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492bb2  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00492bb5  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492bbc  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00492bbf  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00492bc2  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492bc9  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492bcc  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492bcf  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00492bd2  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00492bd5  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492bdc  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492bdf  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00492be2  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492be9  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492bec  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492bef  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492bf2  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00492bf9  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492bfd  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492c00  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492c06  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492c09  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492c0f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492c11  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492c17  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492c1a  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492c20  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492c22  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492c24  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492c27  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00492c2a  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492c2d  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00492c30  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492c32  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492c34  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00492c37  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492c3e  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00492c41  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00492c44  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492c4b  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492c4e  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492c51  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00492c54  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00492c57  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492c5e  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492c61  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00492c64  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492c6b  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492c6e  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492c71  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492c74  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492c76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492c77  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00492c7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492c7c  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00492c83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492c84  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492c8a  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492c8e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492c8f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00492c93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492c94  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00492c9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492c9c  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492ca2  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00492ca8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492ca9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_492cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492cac);
    // 00492cac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492cad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492cae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492caf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492cb0  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00492cb6  8bac2404010000         -mov ebp, dword ptr [esp + 0x104]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00492cbd  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00492cc4  8bb4240c010000         -mov esi, dword ptr [esp + 0x10c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00492ccb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00492ccd  0f8e45020000           -jle 0x492f18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492f18;
    }
L_0x00492cd3:
    // 00492cd3  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00492cd6  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00492cd9  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492cdd  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492cdf  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492ce2  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492ce8  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492ceb  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492cf1  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492cf3  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492cf9  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492cfc  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492d02  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492d04  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d06  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d09  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00492d0c  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492d0f  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00492d12  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492d14  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492d16  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00492d19  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492d20  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00492d23  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00492d26  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492d2d  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492d30  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d33  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00492d36  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00492d39  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492d40  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492d43  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00492d46  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492d4d  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492d50  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d53  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d56  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00492d59  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00492d5c  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00492d60  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492d62  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492d65  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492d6b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492d6e  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492d74  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492d76  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492d7c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492d7f  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492d85  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492d87  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d89  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d8c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00492d8f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492d92  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00492d95  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492d97  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492d99  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00492d9c  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492da3  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00492da6  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00492da9  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492db0  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492db3  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492db6  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00492db9  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00492dbc  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492dc3  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492dc6  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00492dc9  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492dd0  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492dd3  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492dd6  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492dd9  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00492ddc  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00492ddf  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00492de6  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492de8  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492deb  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492df1  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492df4  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492dfa  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492dfc  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492e02  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492e05  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492e0b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492e0d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492e0f  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492e12  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00492e15  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492e18  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00492e1b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492e1d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492e1f  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00492e22  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492e29  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00492e2c  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00492e2f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492e36  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492e39  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492e3c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00492e3f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00492e42  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492e49  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492e4c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00492e4f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492e56  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492e59  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492e5c  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492e5f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00492e61  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00492e64  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492e66  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492e68  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492e6b  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492e71  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492e74  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492e7a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492e7c  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492e82  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492e85  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492e8b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492e8d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492e8f  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492e92  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00492e95  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492e98  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00492e9b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492e9d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492e9f  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00492ea2  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492ea9  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00492eac  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00492eaf  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492eb6  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492eb9  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492ebc  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00492ebf  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00492ec2  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492ec9  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492ecc  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00492ecf  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492ed6  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492ed9  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492edc  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492edf  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00492ee3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492ee4  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00492ee8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492ee9  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492eed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492eee  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492ef4  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00492efb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492efc  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00492f00  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492f01  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492f05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492f06  83c610                 +add esi, 0x10
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
    // 00492f09  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492f0f  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00492f10  0f85bdfdffff           -jne 0x492cd3
    if (!cpu.flags.zf)
    {
        goto L_0x00492cd3;
    }
    // 00492f16  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00492f18:
    // 00492f18  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00492f1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f22  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492f28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492f28);
    // 00492f28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492f29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492f2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492f2b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492f2c  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00492f32  8bac2404010000         -mov ebp, dword ptr [esp + 0x104]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00492f39  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00492f40  8bb4240c010000         -mov esi, dword ptr [esp + 0x10c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00492f47  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00492f49  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00492f4c  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492f50  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492f52  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492f55  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492f5b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492f5e  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492f64  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492f66  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492f6c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492f6f  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492f75  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492f77  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492f79  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492f7c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00492f7f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492f82  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00492f85  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492f87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492f89  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00492f8c  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492f93  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00492f96  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00492f99  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492fa0  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492fa3  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492fa6  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00492fa9  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00492fac  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492fb3  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492fb6  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00492fb9  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00492fc0  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492fc3  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492fc6  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492fc9  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00492fcc  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00492fcf  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00492fd3  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492fd5  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492fd8  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00492fdb  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00492fe1  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00492fe4  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00492fea  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00492fec  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492ff2  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00492ff5  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00492ffb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492ffd  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492fff  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493002  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493005  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493008  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0049300b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049300d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049300f  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493012  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493019  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049301c  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049301f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493026  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493029  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049302c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049302f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493032  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493039  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049303c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049303f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493046  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493049  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049304c  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049304f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00493051  0f8e3e010000           -jle 0x493195
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493195;
    }
L_0x00493057:
    // 00493057  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00493059  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049305c  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00493063  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00493065  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493068  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 0049306e  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493071  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493077  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493079  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049307f  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493082  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493088  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049308a  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049308c  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049308f  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493092  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493095  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493098  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049309a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049309c  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049309f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004930a6  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004930a9  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004930ac  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004930b3  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004930b6  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004930b9  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004930bc  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004930bf  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004930c6  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004930c9  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004930cc  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004930d3  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004930d6  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004930d9  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004930dc  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004930df  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004930e2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004930e4  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004930e6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004930e9  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004930ef  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004930f2  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004930f8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004930fa  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493100  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493103  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493109  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049310b  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049310d  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493110  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493113  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493116  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493119  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049311b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049311d  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493120  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493127  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049312a  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049312d  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493134  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493137  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049313a  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049313d  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493140  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493147  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049314a  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049314d  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493154  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493157  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049315a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049315d  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00493164  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493165  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00493169  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049316a  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049316e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049316f  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493175  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0049317c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049317d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493181  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493182  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00493189  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049318a  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493190  83fd02                 +cmp ebp, 2
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
    // 00493193  7d0d                   -jge 0x4931a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004931a2;
    }
L_0x00493195:
    // 00493195  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 0049319b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049319c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049319d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049319e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049319f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004931a2:
    // 004931a2  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004931a5  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004931a8  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004931ac  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004931ae  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004931b1  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004931b7  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004931ba  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004931c0  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004931c2  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004931c8  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004931cb  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004931d1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004931d3  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004931d5  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004931d8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004931db  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004931de  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004931e1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004931e3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004931e5  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004931e8  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004931ef  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004931f2  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004931f5  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004931fc  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004931ff  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493202  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493205  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493208  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049320f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493212  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493215  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049321c  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049321f  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493222  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493225  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00493228  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049322b  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049322f  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00493231  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493234  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 0049323a  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049323d  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493243  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493245  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049324b  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049324e  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493254  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493256  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493258  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049325b  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049325e  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493261  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493264  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493266  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493268  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049326b  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493272  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493275  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493278  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049327f  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493282  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493285  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493288  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049328b  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493292  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493295  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493298  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049329f  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004932a2  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004932a5  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004932a8  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004932ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004932ad  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004932b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004932b2  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 004932b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004932ba  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004932c0  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004932c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004932c5  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004932c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004932ca  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004932ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004932cf  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004932d2  83ed02                 -sub ebp, 2
    (cpu.ebp) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004932d5  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004932db  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004932dd  0f8f74fdffff           -jg 0x493057
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00493057;
    }
    // 004932e3  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004932e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004932ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004932eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004932ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004932ed  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4932f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004932f0);
    // 004932f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004932f1  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 004932f7  8b9424bc000000         -mov edx, dword ptr [esp + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 004932fe  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00493302  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493305  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 0049330b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049330e  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493314  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493316  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049331c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049331f  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493325  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493327  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493329  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049332c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049332f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493332  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493335  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493337  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493339  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049333c  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493343  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493346  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493349  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493350  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493353  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493356  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493359  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049335c  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493363  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493366  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493369  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493370  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493373  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493376  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493379  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00493380  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493382  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493385  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 0049338b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049338e  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493394  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493396  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049339c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049339f  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004933a5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004933a7  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004933a9  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004933ac  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004933af  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004933b2  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004933b5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004933b7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004933b9  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004933bc  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004933c3  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004933c6  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004933c9  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004933d0  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004933d3  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004933d6  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004933d9  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004933dc  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004933e3  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004933e6  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004933e9  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004933f0  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004933f3  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004933f6  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004933f9  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00493400  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493404  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493407  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 0049340d  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493410  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493416  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493418  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049341e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493421  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493427  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493429  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049342b  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049342e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493431  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493434  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493437  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493439  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049343b  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049343e  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493445  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493448  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049344b  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493452  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493455  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493458  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049345b  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049345e  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493465  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493468  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049346b  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493472  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493475  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493478  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049347b  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049347f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493480  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493484  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493485  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0049348c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049348d  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493493  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00493499  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049349a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4934a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004934a0);
    // 004934a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004934a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004934a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004934a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004934a4  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 004934aa  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004934b1  8bac24cc000000         -mov ebp, dword ptr [esp + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 004934b8  8bb424d0000000         -mov esi, dword ptr [esp + 0xd0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 004934bf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004934c1  0f8ea9010000           -jle 0x493670
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493670;
    }
L_0x004934c7:
    // 004934c7  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004934ca  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004934cd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004934cf  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004934d1  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004934d4  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004934da  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004934dd  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004934e3  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004934e5  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004934eb  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004934ee  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004934f4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004934f6  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004934f8  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004934fb  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004934fe  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493501  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493504  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493506  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493508  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049350b  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493512  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493515  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493518  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049351f  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493522  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493525  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493528  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049352b  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493532  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493535  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493538  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049353f  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493542  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493545  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493548  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049354b  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049354e  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493552  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493554  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493557  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 0049355d  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493560  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493566  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493568  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049356e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493571  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493577  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493579  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049357b  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049357e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493581  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493584  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493587  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493589  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049358b  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049358e  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493595  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493598  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049359b  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004935a2  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004935a5  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004935a8  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004935ab  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004935ae  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004935b5  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004935b8  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004935bb  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004935c2  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004935c5  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004935c8  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004935cb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004935cd  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004935d0  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004935d4  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004935d6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004935d9  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004935df  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004935e2  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004935e8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004935ea  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004935f0  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004935f3  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004935f9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004935fb  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004935fd  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493600  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493603  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493606  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493609  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049360b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049360d  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493610  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493617  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049361a  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049361d  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493624  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493627  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049362a  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049362d  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493630  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493637  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049363a  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049363d  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493644  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493647  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049364a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049364d  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493651  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493652  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493656  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493657  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0049365e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049365f  83c60c                 +add esi, 0xc
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
    // 00493662  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493668  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00493669  0f8558feffff           -jne 0x4934c7
    if (!cpu.flags.zf)
    {
        goto L_0x004934c7;
    }
    // 0049366f  90                     -nop 
    ;
L_0x00493670:
    // 00493670  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00493676  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493677  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493678  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493679  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049367a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493680);
    // 00493680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493681  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493682  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493683  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493684  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0049368a  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00493691  8bac24cc000000         -mov ebp, dword ptr [esp + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00493698  8bb424d0000000         -mov esi, dword ptr [esp + 0xd0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 0049369f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004936a1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004936a4  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004936a8  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004936aa  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004936ad  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004936b3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004936b6  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004936bc  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004936be  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004936c4  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004936c7  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004936cd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004936cf  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004936d1  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004936d4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004936d7  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004936da  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004936dd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004936df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004936e1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004936e4  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004936eb  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004936ee  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004936f1  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004936f8  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004936fb  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004936fe  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493701  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493704  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049370b  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049370e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493711  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493718  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049371b  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049371e  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493721  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00493724  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00493727  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049372b  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049372d  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00493730  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493733  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493739  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049373c  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493742  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493744  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049374a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049374d  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493753  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493755  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493757  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049375a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049375d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493760  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493763  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493765  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493767  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049376a  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493771  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493774  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493777  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049377e  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493781  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493784  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493787  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049378a  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493791  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493794  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493797  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049379e  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004937a1  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004937a4  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004937a7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004937a9  0f8e98000000           -jle 0x493847
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493847;
    }
L_0x004937af:
    // 004937af  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004937b1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004937b4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004937b6  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004937b8  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004937bb  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004937c1  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004937c4  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004937ca  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004937cc  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004937d2  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004937d5  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004937db  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004937dd  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004937df  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004937e2  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004937e5  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004937e8  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004937eb  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004937ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004937ef  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004937f2  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004937f9  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004937fc  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004937ff  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493806  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493809  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049380c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049380f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493812  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493819  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049381c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049381f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493826  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493829  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049382c  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049382f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493831  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493832  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00493836  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493837  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049383b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049383c  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493842  83ff02                 +cmp edi, 2
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
    // 00493845  7d0d                   -jge 0x493854
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493854;
    }
L_0x00493847:
    // 00493847  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0049384d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049384e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049384f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493850  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493851  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00493854:
    // 00493854  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00493857  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049385a  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049385e  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493860  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493863  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493869  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049386c  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493872  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493874  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049387a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049387d  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493883  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493885  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493887  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049388a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049388d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493890  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493893  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493895  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493897  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049389a  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004938a1  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004938a4  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004938a7  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004938ae  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004938b1  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004938b4  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004938b7  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004938ba  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004938c1  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004938c4  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004938c7  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004938ce  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004938d1  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004938d4  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004938d7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004938d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004938da  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004938de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004938df  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004938e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004938e7  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004938ed  83ff03                 +cmp edi, 3
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
    // 004938f0  0f8c51ffffff           -jl 0x493847
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493847;
    }
    // 004938f6  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004938f9  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004938fc  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00493900  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493902  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493905  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 0049390b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049390e  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493914  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493916  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049391c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049391f  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493925  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493927  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493929  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049392c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049392f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493932  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493935  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493937  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493939  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049393c  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493943  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493946  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493949  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493950  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493953  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493956  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493959  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049395c  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493963  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493966  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493969  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493970  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493973  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493976  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493979  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049397d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049397e  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00493982  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493983  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493987  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493988  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049398e  83ff04                 +cmp edi, 4
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
    // 00493991  0f8cb0feffff           -jl 0x493847
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493847;
    }
    // 00493997  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049399a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049399d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049399f  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004939a1  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004939a4  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004939aa  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004939ad  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004939b3  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004939b5  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004939bb  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004939be  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004939c4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004939c6  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004939c8  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004939cb  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004939ce  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004939d1  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004939d4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004939d6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004939d8  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004939db  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004939e2  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004939e5  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004939e8  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004939ef  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004939f2  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004939f5  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004939f8  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004939fb  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493a02  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493a05  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493a08  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493a0f  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493a12  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493a15  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493a18  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00493a1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493a1d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493a21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493a22  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00493a26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493a27  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493a2d  83ff05                 +cmp edi, 5
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
    // 00493a30  0f8c11feffff           -jl 0x493847
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493847;
    }
    // 00493a36  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00493a39  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00493a3c  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493a40  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493a42  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493a45  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493a4b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493a4e  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493a54  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493a56  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493a5c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493a5f  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493a65  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493a67  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493a69  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493a6c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493a6f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493a72  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493a75  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493a77  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493a79  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493a7c  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493a83  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493a86  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493a89  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493a90  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493a93  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493a96  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493a99  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493a9c  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493aa3  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493aa6  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493aa9  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493ab0  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493ab3  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493ab6  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493ab9  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493abd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493abe  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493ac2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493ac3  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00493aca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493acb  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493ad1  83ff06                 +cmp edi, 6
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
    // 00493ad4  0f8c6dfdffff           -jl 0x493847
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493847;
    }
    // 00493ada  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00493add  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00493ae0  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00493ae4  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493ae6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493ae9  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493aef  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493af2  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493af8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493afa  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493b00  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493b03  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493b09  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493b0b  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493b0d  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493b10  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493b13  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493b16  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493b19  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493b1b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493b1d  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493b20  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493b27  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493b2a  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493b2d  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493b34  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493b37  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493b3a  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493b3d  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493b40  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493b47  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493b4a  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493b4d  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493b54  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493b57  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493b5a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493b5d  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493b61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493b62  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00493b66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493b67  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493b6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493b6c  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00493b6f  83ef06                 -sub edi, 6
    (cpu.edi) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00493b72  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493b78  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00493b7a  0f8f2ffcffff           -jg 0x4937af
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004937af;
    }
    // 00493b80  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00493b86  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b8a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493b90);
    // 00493b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493b91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493b92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493b93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493b94  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00493b9a  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00493ba1  8bac24cc000000         -mov ebp, dword ptr [esp + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00493ba8  8bb424d0000000         -mov esi, dword ptr [esp + 0xd0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00493baf  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00493bb1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00493bb4  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00493bb8  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493bba  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493bbd  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493bc3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493bc6  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493bcc  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493bce  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493bd4  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493bd7  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493bdd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493bdf  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493be1  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493be4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493be7  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493bea  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493bed  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493bef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493bf1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493bf4  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493bfb  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493bfe  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493c01  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493c08  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493c0b  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493c0e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493c11  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493c14  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493c1b  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493c1e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493c21  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493c28  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493c2b  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493c2e  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493c31  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00493c34  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00493c37  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493c3b  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493c3d  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00493c40  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493c43  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493c49  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493c4c  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493c52  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493c54  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493c5a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493c5d  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493c63  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493c65  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493c67  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493c6a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493c6d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493c70  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493c73  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493c75  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493c77  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493c7a  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493c81  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493c84  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493c87  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493c8e  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493c91  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493c94  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493c97  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493c9a  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493ca1  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493ca4  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493ca7  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493cae  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493cb1  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493cb4  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493cb7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00493cb9  0f8e9b000000           -jle 0x493d5a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493d5a;
    }
L_0x00493cbf:
    // 00493cbf  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00493cc1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00493cc4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493cc6  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493cc8  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493ccb  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493cd1  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493cd4  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493cda  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493cdc  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493ce2  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493ce5  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493ceb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493ced  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493cef  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493cf2  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493cf5  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493cf8  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493cfb  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493cfd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493cff  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493d02  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493d09  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493d0c  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493d0f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493d16  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493d19  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493d1c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493d1f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493d22  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493d29  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493d2c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493d2f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493d36  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493d39  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493d3c  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493d3f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493d41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493d42  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00493d46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493d47  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00493d4e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493d4f  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493d55  83ff02                 +cmp edi, 2
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
    // 00493d58  7d0d                   -jge 0x493d67
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493d67;
    }
L_0x00493d5a:
    // 00493d5a  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00493d60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d64  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00493d67:
    // 00493d67  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00493d6a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00493d6d  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493d71  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493d73  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493d76  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493d7c  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493d7f  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493d85  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493d87  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493d8d  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493d90  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493d96  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493d98  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493d9a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493d9d  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493da0  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493da3  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493da6  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493da8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493daa  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493dad  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493db4  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493db7  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493dba  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493dc1  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493dc4  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493dc7  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493dca  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493dcd  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493dd4  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493dd7  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493dda  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493de1  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493de4  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493de7  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493dea  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493dee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493def  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493df3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493df4  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00493dfb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493dfc  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00493dff  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00493e02  ff154cca5600           -call dword ptr [0x56ca4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493e08  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00493e0a  0f8faffeffff           -jg 0x493cbf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00493cbf;
    }
    // 00493e10  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00493e16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e17  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e1a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493e20);
    // 00493e20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493e21  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00493e24  8b942484000000         -mov edx, dword ptr [esp + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00493e2b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493e2d  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493e30  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493e36  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493e39  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493e3f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493e41  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493e47  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493e4a  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493e50  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493e52  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493e54  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493e57  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493e5a  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493e5d  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493e60  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493e62  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493e64  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493e67  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493e6e  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493e71  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493e74  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493e7b  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493e7e  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493e81  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493e84  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493e87  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493e8e  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493e91  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493e94  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493e9b  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493e9e  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493ea1  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493ea4  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00493eab  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493eaf  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493eb2  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493eb8  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493ebb  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493ec1  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493ec3  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493ec9  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493ecc  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493ed2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493ed4  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493ed6  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493ed9  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493edc  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493edf  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493ee2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493ee4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493ee6  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493ee9  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493ef0  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493ef3  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493ef6  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493efd  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493f00  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493f03  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493f06  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493f09  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493f10  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493f13  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493f16  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493f1d  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493f20  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493f23  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493f26  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493f28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493f29  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00493f2d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493f2e  ff1550ca5600           -call dword ptr [0x56ca50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687888) /* 0x56ca50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493f34  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00493f37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f38  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_493f3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493f3c);
    // 00493f3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493f3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493f3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493f3f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493f40  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00493f43  8bbc248c000000         -mov edi, dword ptr [esp + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00493f4a  8bac2490000000         -mov ebp, dword ptr [esp + 0x90]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00493f51  8bb42494000000         -mov esi, dword ptr [esp + 0x94]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00493f58  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00493f5a  0f8e20010000           -jle 0x494080
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494080;
    }
L_0x00493f60:
    // 00493f60  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00493f63  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00493f66  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493f6a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493f6c  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493f6f  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493f75  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493f78  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493f7e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00493f80  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493f86  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00493f89  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00493f8f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00493f91  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493f93  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493f96  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493f99  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00493f9c  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00493f9f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00493fa1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493fa3  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00493fa6  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493fad  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493fb0  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00493fb3  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493fba  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00493fbd  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493fc0  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00493fc3  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00493fc6  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493fcd  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493fd0  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00493fd3  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00493fda  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493fdd  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493fe0  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00493fe3  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00493fe5  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00493fe8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493fea  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493fec  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00493fef  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00493ff5  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00493ff8  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00493ffe  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00494000  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00494006  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00494009  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049400f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00494011  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494013  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494016  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00494019  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049401c  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0049401f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00494021  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494023  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00494026  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049402d  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00494030  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00494033  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049403a  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049403d  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494040  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00494043  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00494046  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049404d  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00494050  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00494053  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049405a  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049405d  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494060  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494063  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00494067  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494068  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049406c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049406d  83c608                 +add esi, 8
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
    // 00494070  ff1550ca5600           -call dword ptr [0x56ca50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687888) /* 0x56ca50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00494076  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00494077  0f85e3feffff           -jne 0x493f60
    if (!cpu.flags.zf)
    {
        goto L_0x00493f60;
    }
    // 0049407d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00494080:
    // 00494080  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00494083  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494084  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494085  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494086  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494087  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49408c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049408c);
    // 0049408c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049408d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049408e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049408f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494090  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00494093  8bbc248c000000         -mov edi, dword ptr [esp + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0049409a  8bac2490000000         -mov ebp, dword ptr [esp + 0x90]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004940a1  8bb42494000000         -mov esi, dword ptr [esp + 0x94]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 004940a8  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004940aa  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004940ad  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004940b1  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004940b3  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004940b6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004940b9  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004940bf  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004940c2  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004940c8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004940ca  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004940d0  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004940d3  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004940d9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004940db  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004940dd  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004940e0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004940e3  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004940e6  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004940e9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004940eb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004940ed  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004940f0  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004940f7  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004940fa  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004940fd  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494104  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00494107  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049410a  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049410d  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00494110  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494117  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049411a  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049411d  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494124  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00494127  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049412a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049412d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049412f  0f8e93000000           -jle 0x4941c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004941c8;
    }
L_0x00494135:
    // 00494135  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00494137  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049413a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049413c  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049413e  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00494141  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00494147  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049414a  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 00494150  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00494152  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00494158  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049415b  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00494161  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00494163  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494165  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494168  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049416b  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049416e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00494171  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00494173  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494175  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00494178  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049417f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00494182  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00494185  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049418c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049418f  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494192  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00494195  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00494198  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049419f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004941a2  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004941a5  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004941ac  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004941af  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004941b2  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004941b5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004941b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004941b8  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004941bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004941bd  ff1550ca5600           -call dword ptr [0x56ca50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687888) /* 0x56ca50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004941c3  83ff02                 +cmp edi, 2
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
    // 004941c6  7d0a                   -jge 0x4941d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004941d2;
    }
L_0x004941c8:
    // 004941c8  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 004941cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004941cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004941cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004941ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004941cf  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004941d2:
    // 004941d2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004941d5  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004941d8  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004941dc  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004941de  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004941e1  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004941e7  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004941ea  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004941f0  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004941f2  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004941f8  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004941fb  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00494201  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00494203  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494205  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494208  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049420b  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049420e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00494211  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00494213  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494215  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00494218  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049421f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00494222  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00494225  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049422c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049422f  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494232  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00494235  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00494238  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049423f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00494242  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00494245  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 0049424c  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049424f  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494252  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494255  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00494259  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049425a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049425e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049425f  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494262  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00494265  ff1550ca5600           -call dword ptr [0x56ca50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687888) /* 0x56ca50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049426b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049426d  0f8fc2feffff           -jg 0x494135
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494135;
    }
    // 00494273  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00494276  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494277  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494278  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494279  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049427a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494280);
    // 00494280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494281  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00494284  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00494288  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049428a  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0049428d  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00494293  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00494296  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 0049429c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049429e  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004942a4  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004942a7  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 004942ad  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004942af  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004942b1  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004942b4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004942b7  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004942ba  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004942bd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004942bf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004942c1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004942c4  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004942cb  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004942ce  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004942d1  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004942d8  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004942db  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004942de  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004942e1  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004942e4  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004942eb  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004942ee  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004942f1  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004942f8  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004942fb  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004942fe  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494301  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494303  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494304  ff1554ca5600           -call dword ptr [0x56ca54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687892) /* 0x56ca54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049430a  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0049430d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049430e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494314(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494314);
    // 00494314  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494315  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494316  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494317  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494318  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0049431b  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049431f  8b6c2454               -mov ebp, dword ptr [esp + 0x54]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00494323  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00494327  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00494329  0f8e91000000           -jle 0x4943c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004943c0;
    }
L_0x0049432f:
    // 0049432f  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00494331  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00494334  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494336  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00494338  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0049433b  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 00494341  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00494344  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 0049434a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049434c  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00494352  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00494355  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 0049435b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049435d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049435f  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494362  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00494365  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00494368  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0049436b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049436d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049436f  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00494372  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494379  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049437c  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049437f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494386  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00494389  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049438c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049438f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00494392  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494399  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049439c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049439f  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 004943a6  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004943a9  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004943ac  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004943af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004943b0  83c704                 +add edi, 4
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
    // 004943b3  ff1554ca5600           -call dword ptr [0x56ca54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687892) /* 0x56ca54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004943b9  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004943ba  0f856fffffff           -jne 0x49432f
    if (!cpu.flags.zf)
    {
        goto L_0x0049432f;
    }
L_0x004943c0:
    // 004943c0  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004943c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004943c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004943c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004943c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004943c7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4943cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004943cc);
    // 004943cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004943cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004943ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004943cf  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004943d2  8b7c244c               -mov edi, dword ptr [esp + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004943d6  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004943da  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004943dc  0f8e8e000000           -jle 0x494470
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494470;
    }
L_0x004943e2:
    // 004943e2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004943e4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004943e6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004943e9  d80d7cad4d00           -fmul dword ptr [0x4dad7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090684) /* 0x4dad7c */));
    // 004943ef  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004943f2  d80d78ad4d00           -fmul dword ptr [0x4dad78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5090680) /* 0x4dad78 */));
    // 004943f8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004943fa  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00494400  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00494403  d80580ad4d00           -fadd dword ptr [0x4dad80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5090688) /* 0x4dad80 */));
    // 00494409  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049440b  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049440d  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494410  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00494413  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00494416  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00494419  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049441b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049441d  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00494420  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494427  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049442a  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049442d  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494434  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00494437  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049443a  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049443d  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00494440  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494447  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049444a  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049444d  8b0c9dc0c55600         -mov ecx, dword ptr [ebx*4 + 0x56c5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686720) /* 0x56c5c0 */ + cpu.ebx * 4);
    // 00494454  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00494457  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049445a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049445d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049445e  83c620                 +add esi, 0x20
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
    // 00494461  ff1554ca5600           -call dword ptr [0x56ca54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687892) /* 0x56ca54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00494467  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00494468  0f8574ffffff           -jne 0x4943e2
    if (!cpu.flags.zf)
    {
        goto L_0x004943e2;
    }
    // 0049446e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00494470:
    // 00494470  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00494473  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494474  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494475  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494476  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_494480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494480);
    // 00494480  43                     -inc ebx
    (cpu.ebx)++;
    // 00494481  d1fb                   +sar ebx, 1
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
    // 00494483  90                     -nop 
    ;
    // 00494484  e97756ffff             -jmp 0x489b00
    return sub_489b00(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49448c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049448c);
    // 0049448c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049448d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049448e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049448f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494491  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00494493  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00494495  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494497  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494499  7e2d                   -jle 0x4944c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004944c8;
    }
    // 0049449b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0049449d:
    // 0049449d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049449f  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004944a1  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004944a3  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004944a5  7425                   -je 0x4944cc
    if (cpu.flags.zf)
    {
        goto L_0x004944cc;
    }
    // 004944a7  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004944a9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004944ab  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004944ae  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 004944b0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004944b2  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004944b4  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
L_0x004944b7:
    // 004944b7  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004944b9  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 004944bb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004944bd  42                     -inc edx
    (cpu.edx)++;
    // 004944be  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004944c0  40                     -inc eax
    (cpu.eax)++;
    // 004944c1  881c31                 -mov byte ptr [ecx + esi], bl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.bl;
    // 004944c4  39f8                   +cmp eax, edi
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
    // 004944c6  7cd5                   -jl 0x49449d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049449d;
    }
L_0x004944c8:
    // 004944c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004944c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004944ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004944cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004944cc:
    // 004944cc  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004944ce  80e3f0                 -and bl, 0xf0
    cpu.bl &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004944d1  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004944d3  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004944d9  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004944dc  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004944e2  ebd3                   -jmp 0x4944b7
    goto L_0x004944b7;
}

/* align: skip  */
void Application::sub_4944e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004944e4);
    // 004944e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004944e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004944e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004944e7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004944e9  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004944eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004944ed  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004944ef  7e1e                   -jle 0x49450f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049450f;
    }
L_0x004944f1:
    // 004944f1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004944f3  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004944f5  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004944f7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004944f9  7418                   -je 0x494513
    if (cpu.flags.zf)
    {
        goto L_0x00494513;
    }
    // 004944fb  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004944fd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494503  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00494506  42                     -inc edx
    (cpu.edx)++;
    // 00494507  40                     -inc eax
    (cpu.eax)++;
    // 00494508  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049450b  39f0                   +cmp eax, esi
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
    // 0049450d  7ce2                   -jl 0x4944f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004944f1;
    }
L_0x0049450f:
    // 0049450f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494510  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494511  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494512  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494513:
    // 00494513  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00494515  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00494518  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049451e  42                     -inc edx
    (cpu.edx)++;
    // 0049451f  40                     -inc eax
    (cpu.eax)++;
    // 00494520  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00494523  39f0                   +cmp eax, esi
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
    // 00494525  7cca                   -jl 0x4944f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004944f1;
    }
    // 00494527  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494528  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494529  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049452a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49452c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049452c);
    // 0049452c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049452d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049452e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049452f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494530  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00494533  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494535  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00494537  8b1d7c8a4d00           -mov ebx, dword ptr [0x4d8a7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081724) /* 0x4d8a7c */);
    // 0049453d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049453f  7563                   -jne 0x4945a4
    if (!cpu.flags.zf)
    {
        goto L_0x004945a4;
    }
    // 00494541  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00494543  7e57                   -jle 0x49459c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049459c;
    }
L_0x00494545:
    // 00494545  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00494548  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049454d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049454f  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00494552  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494555  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00494559  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049455b  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 0049455e  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00494561  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494564  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00494568  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049456c  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494570  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 00494573  c1e50a                 -shl ebp, 0xa
    cpu.ebp <<= 10 /*0xa*/ % 32;
    // 00494576  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049457c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049457f  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00494581  42                     -inc edx
    (cpu.edx)++;
    // 00494582  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00494584  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00494587  e850c5feff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0049458c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00494590  43                     -inc ebx
    (cpu.ebx)++;
    // 00494591  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494595  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00494598  39f3                   +cmp ebx, esi
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
    // 0049459a  7ca9                   -jl 0x494545
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494545;
    }
L_0x0049459c:
    // 0049459c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049459f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004945a4:
    // 004945a4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004945a6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004945a8  7ef2                   -jle 0x49459c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049459c;
    }
L_0x004945aa:
    // 004945aa  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004945ad  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004945b2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004945b4  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 004945b7  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004945ba  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004945bd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004945bf  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 004945c2  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004945c5  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004945c8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004945cc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004945cf  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 004945d1  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 004945d4  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 004945d7  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 004945d9  0b442404               -or eax, dword ptr [esp + 4]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004945dd  8b3d7c8a4d00           -mov edi, dword ptr [0x4d8a7c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081724) /* 0x4d8a7c */);
    // 004945e3  42                     -inc edx
    (cpu.edx)++;
    // 004945e4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004945e7  8a0407                 -mov al, byte ptr [edi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
    // 004945ea  43                     -inc ebx
    (cpu.ebx)++;
    // 004945eb  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004945ee  39f3                   +cmp ebx, esi
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
    // 004945f0  7cb8                   -jl 0x4945aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004945aa;
    }
    // 004945f2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004945f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4945fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004945fc);
    // 004945fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004945fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004945fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004945ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494600  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00494602  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00494604  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00494606  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00494608  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049460a  7e1b                   -jle 0x494627
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494627;
    }
L_0x0049460c:
    // 0049460c  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049460e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494610  81fb00000040           +cmp ebx, 0x40000000
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
    // 00494616  7314                   -jae 0x49462c
    if (!cpu.flags.cf)
    {
        goto L_0x0049462c;
    }
L_0x00494618:
    // 00494618  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049461b  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049461e  47                     -inc edi
    (cpu.edi)++;
    // 0049461f  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 00494623  39ef                   +cmp edi, ebp
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
    // 00494625  7ce5                   -jl 0x49460c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049460c;
    }
L_0x00494627:
    // 00494627  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494628  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494629  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049462a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049462b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049462c:
    // 0049462c  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0049462e  7425                   -je 0x494655
    if (cpu.flags.zf)
    {
        goto L_0x00494655;
    }
    // 00494630  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494632  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00494638  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0049463b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049463d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00494640  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00494646  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00494649  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049464c  01c3                   +add ebx, eax
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
    // 0049464e  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00494655:
    // 00494655  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494657  ebbf                   -jmp 0x494618
    goto L_0x00494618;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49465c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049465c);
    // 0049465c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049465d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049465e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049465f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494660  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494662  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00494664  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00494666  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00494668  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049466a  7e3c                   -jle 0x4946a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004946a8;
    }
L_0x0049466c:
    // 0049466c  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049466e  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00494670  7425                   -je 0x494697
    if (cpu.flags.zf)
    {
        goto L_0x00494697;
    }
    // 00494672  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494674  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0049467a  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0049467d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049467f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00494682  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00494688  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0049468b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049468e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494690  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00494697:
    // 00494697  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049469a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049469d  47                     -inc edi
    (cpu.edi)++;
    // 0049469e  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004946a2  39ef                   +cmp edi, ebp
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
    // 004946a4  7cc6                   -jl 0x49466c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049466c;
    }
    // 004946a6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004946a8:
    // 004946a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4946b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004946b0);
    // 004946b0  01db                   +add ebx, ebx
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
    // 004946b2  e94954ffff             -jmp 0x489b00
    return sub_489b00(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4946b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004946b8);
    // 004946b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004946b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004946ba  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004946bc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004946be  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004946c0  7e12                   -jle 0x4946d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004946d4;
    }
L_0x004946c2:
    // 004946c2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004946c5  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004946c8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004946cb  41                     -inc ecx
    (cpu.ecx)++;
    // 004946cc  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004946d0  39f1                   +cmp ecx, esi
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
    // 004946d2  7cee                   -jl 0x4946c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004946c2;
    }
L_0x004946d4:
    // 004946d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4946d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004946d8);
    // 004946d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004946d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004946da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004946db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004946dc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004946de  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004946e0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004946e2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004946e4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004946e6  7e1b                   -jle 0x494703
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494703;
    }
L_0x004946e8:
    // 004946e8  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004946ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004946ec  81fb00000040           +cmp ebx, 0x40000000
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
    // 004946f2  7314                   -jae 0x494708
    if (!cpu.flags.cf)
    {
        goto L_0x00494708;
    }
L_0x004946f4:
    // 004946f4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004946f7  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004946fa  47                     -inc edi
    (cpu.edi)++;
    // 004946fb  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004946ff  39ef                   +cmp edi, ebp
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
    // 00494701  7ce5                   -jl 0x4946e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004946e8;
    }
L_0x00494703:
    // 00494703  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494704  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494705  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494706  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494707  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494708:
    // 00494708  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049470a  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00494710  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00494713  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494715  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00494718  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0049471e  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00494721  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494724  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494726  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494728  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049472a  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 0049472d  75c5                   -jne 0x4946f4
    if (!cpu.flags.zf)
    {
        goto L_0x004946f4;
    }
    // 0049472f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494734  ebbe                   -jmp 0x4946f4
    goto L_0x004946f4;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_494738(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494738);
    // 00494738  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494739  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049473a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049473b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049473c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049473e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00494740  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00494742  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00494744  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494746  7e34                   -jle 0x49477c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049477c;
    }
L_0x00494748:
    // 00494748  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049474a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049474c  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00494752  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00494755  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494757  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0049475a  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00494760  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00494763  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494766  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494768  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049476a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049476d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494770  47                     -inc edi
    (cpu.edi)++;
    // 00494771  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00494775  39ef                   +cmp edi, ebp
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
    // 00494777  7ccf                   -jl 0x494748
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494748;
    }
    // 00494779  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049477c:
    // 0049477c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049477d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049477e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049477f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494780  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494784(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494784);
    // 00494784  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494785  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494786  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494787  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049478a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049478e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00494790  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494792  7e4c                   -jle 0x4947e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004947e0;
    }
L_0x00494794:
    // 00494794  0fb67003               -movzx esi, byte ptr [eax + 3]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 00494798  0fb67801               -movzx edi, byte ptr [eax + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 0049479c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049479e  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 004947a1  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004947a4  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 004947a7  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 004947aa  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004947ae  c1e60c                 -shl esi, 0xc
    cpu.esi <<= 12 /*0xc*/ % 32;
    // 004947b1  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004947b4  0fb638                 -movzx edi, byte ptr [eax]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 004947b7  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004947b9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004947bd  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 004947c0  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004947c3  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004947c6  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004947c8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004947cb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004947ce  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004947d0  41                     -inc ecx
    (cpu.ecx)++;
    // 004947d1  668932                 -mov word ptr [edx], si
    app->getMemory<x86::reg16>(cpu.edx) = cpu.si;
    // 004947d4  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004947d8  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004947db  39f1                   +cmp ecx, esi
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
    // 004947dd  7cb5                   -jl 0x494794
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494794;
    }
    // 004947df  90                     -nop 
    ;
L_0x004947e0:
    // 004947e0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004947e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004947e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004947e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004947e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4947e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004947e8);
    // 004947e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004947e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004947ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004947eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004947ec  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004947ef  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004947f1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004947f3  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004947f6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004947f8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004947fa  7e3c                   -jle 0x494838
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494838;
    }
L_0x004947fc:
    // 004947fc  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004947fe  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494801  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494803  81e1000000ff           -and ecx, 0xff000000
    cpu.ecx &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00494809  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049480b  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00494811  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00494814  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494816  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00494819  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0049481f  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00494822  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494825  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494827  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494829  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049482b  45                     -inc ebp
    (cpu.ebp)++;
    // 0049482c  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0049482e  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494831  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494834  39cd                   +cmp ebp, ecx
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
    // 00494836  7cc4                   -jl 0x4947fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004947fc;
    }
L_0x00494838:
    // 00494838  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049483b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049483c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049483d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049483e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049483f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494840);
    // 00494840  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494841  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494842  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494843  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494844  8b2d90ad4d00           -mov ebp, dword ptr [0x4dad90]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */);
    // 0049484a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049484c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049484e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00494850  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494852  7e28                   -jle 0x49487c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049487c;
    }
L_0x00494854:
    // 00494854  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494856  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00494858  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0049485f  8d042b                 -lea eax, [ebx + ebp]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 00494862  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00494865  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00494868  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049486b  41                     -inc ecx
    (cpu.ecx)++;
    // 0049486c  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0049486f  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00494872  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00494874  46                     -inc esi
    (cpu.esi)++;
    // 00494875  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 00494878  39fe                   +cmp esi, edi
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
    // 0049487a  7cd8                   -jl 0x494854
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494854;
    }
L_0x0049487c:
    // 0049487c  892d90ad4d00           -mov dword ptr [0x4dad90], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */) = cpu.ebp;
    // 00494882  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494883  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494884  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494885  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494886  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_494888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494888);
    // 00494888  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494889  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049488a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049488b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049488e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494890  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00494892  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494894  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00494896  7e50                   -jle 0x4948e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004948e8;
    }
L_0x00494898:
    // 00494898  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0049489b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004948a0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004948a2  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 004948a5  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004948a8  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004948ab  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004948ae  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004948b1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004948b3  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004948b6  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 004948b9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004948bc  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004948bf  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004948c3  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004948c6  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004948ca  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004948ce  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 004948d1  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004948d5  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004948d8  8842fe                 -mov byte ptr [edx - 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.al;
    // 004948db  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004948de  43                     -inc ebx
    (cpu.ebx)++;
    // 004948df  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004948e2  39fb                   +cmp ebx, edi
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
    // 004948e4  7cb2                   -jl 0x494898
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494898;
    }
    // 004948e6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004948e8:
    // 004948e8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004948eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4948f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004948f0);
    // 004948f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004948f1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004948f3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004948fa  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004948fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004948fe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494900  e8fb51ffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 00494905  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494906  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_494908(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494908);
    // 00494908  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494909  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049490a  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049490d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049490f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00494911  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494913  7e3b                   -jle 0x494950
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494950;
    }
L_0x00494915:
    // 00494915  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494917  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049491a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049491d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049491f  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00494922  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00494926  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494928  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049492a  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049492e  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00494931  8a5c2408               -mov bl, byte ptr [esp + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494935  885afd                 -mov byte ptr [edx - 3], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 00494938  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049493c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049493f  885afe                 -mov byte ptr [edx - 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bl;
    // 00494942  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 00494945  41                     -inc ecx
    (cpu.ecx)++;
    // 00494946  885aff                 -mov byte ptr [edx - 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 00494949  39f1                   +cmp ecx, esi
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
    // 0049494b  7cc8                   -jl 0x494915
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494915;
    }
    // 0049494d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00494950:
    // 00494950  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00494953  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494954  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494955  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_494958(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494958);
    // 00494958  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494959  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049495a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049495b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049495c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049495f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494961  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00494964  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00494967  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494969  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049496b  7e48                   -jle 0x4949b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004949b5;
    }
L_0x0049496d:
    // 0049496d  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00494970  8b2d88ad4d00           -mov ebp, dword ptr [0x4dad88]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090696) /* 0x4dad88 */);
    // 00494976  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049497b  39e8                   +cmp eax, ebp
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
    // 0049497d  743e                   -je 0x4949bd
    if (cpu.flags.zf)
    {
        goto L_0x004949bd;
    }
    // 0049497f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00494981  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00494983  c1ff0a                 -sar edi, 0xa
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (10 /*0xa*/ % 32));
    // 00494986  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00494989  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049498c  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049498f  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494992  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 00494995  c1e60b                 -shl esi, 0xb
    cpu.esi <<= 11 /*0xb*/ % 32;
    // 00494998  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049499e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004949a1  09fe                   -or esi, edi
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edi));
    // 004949a3  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004949a5  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x004949a7:
    // 004949a7  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004949aa  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004949ad  43                     -inc ebx
    (cpu.ebx)++;
    // 004949ae  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004949b1  39fb                   +cmp ebx, edi
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
    // 004949b3  7cb8                   -jl 0x49496d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049496d;
    }
L_0x004949b5:
    // 004949b5  83c404                 +add esp, 4
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
    // 004949b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004949b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004949ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004949bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004949bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004949bd:
    // 004949bd  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004949c3  ebe2                   -jmp 0x4949a7
    goto L_0x004949a7;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4949c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004949c8);
    // 004949c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004949c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004949ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004949cb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004949cc  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004949cf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004949d1  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004949d5  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004949d9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004949db  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004949dd  7e50                   -jle 0x494a2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494a2f;
    }
L_0x004949df:
    // 004949df  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004949e2  8b2d88ad4d00           -mov ebp, dword ptr [0x4dad88]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090696) /* 0x4dad88 */);
    // 004949e8  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004949ed  39e8                   +cmp eax, ebp
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
    // 004949ef  7446                   -je 0x494a37
    if (cpu.flags.zf)
    {
        goto L_0x00494a37;
    }
    // 004949f1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004949f3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004949f5  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 004949f8  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004949fb  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 004949fe  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00494a01  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494a04  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00494a07  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494a09  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00494a0c  c1e013                 -shl eax, 0x13
    cpu.eax <<= 19 /*0x13*/ % 32;
    // 00494a0f  c1e60a                 -shl esi, 0xa
    cpu.esi <<= 10 /*0xa*/ % 32;
    // 00494a12  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00494a17  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00494a19  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00494a1c  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00494a1e  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x00494a20:
    // 00494a20  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00494a24  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00494a27  43                     -inc ebx
    (cpu.ebx)++;
    // 00494a28  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494a2b  39fb                   +cmp ebx, edi
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
    // 00494a2d  7cb0                   -jl 0x4949df
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004949df;
    }
L_0x00494a2f:
    // 00494a2f  83c408                 +add esp, 8
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
    // 00494a32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494a37:
    // 00494a37  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00494a3d  ebe1                   -jmp 0x494a20
    goto L_0x00494a20;
}

/* align: skip 0x90 */
void Application::sub_494a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494a40);
    // 00494a40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494a41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494a42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494a43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494a44  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494a47  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00494a49  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00494a4b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00494a4e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00494a50  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00494a54  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494a56  7e68                   -jle 0x494ac0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494ac0;
    }
L_0x00494a58:
    // 00494a58  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 00494a5b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00494a60  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494a62  c1f90c                 -sar ecx, 0xc
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (12 /*0xc*/ % 32));
    // 00494a65  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00494a68  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00494a6a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494a6c  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 00494a6f  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00494a72  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00494a75  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00494a77  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00494a79  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00494a7c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00494a7f  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00494a81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494a83  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494a86  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 00494a89  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00494a8c  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00494a8f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00494a92  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00494a94  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00494a97  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 00494a9a  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494a9c  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00494a9e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00494aa0  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00494aa3  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 00494aa6  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00494aa8  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00494aaa  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00494aac  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00494ab0  8956fc                 -mov dword ptr [esi - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00494ab3  40                     -inc eax
    (cpu.eax)++;
    // 00494ab4  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494ab7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00494abb  39d0                   +cmp eax, edx
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
    // 00494abd  7c99                   -jl 0x494a58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494a58;
    }
    // 00494abf  90                     -nop 
    ;
L_0x00494ac0:
    // 00494ac0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494ac3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ac4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ac5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ac6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ac7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494ac8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494ac8);
    // 00494ac8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494ac9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494aca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494acb  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00494ace  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00494ad0  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00494ad4  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494ad8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494ada  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00494adc  7e56                   -jle 0x494b34
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494b34;
    }
L_0x00494ade:
    // 00494ade  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00494ae1  0fb67803               -movzx edi, byte ptr [eax + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 00494ae5  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00494aeb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00494aed  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 00494af0  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494af3  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00494af6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00494af8  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00494afb  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00494afe  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494b01  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00494b05  8d34d500000000         -lea esi, [edx*8]
    cpu.esi = x86::reg32(cpu.edx * 8);
    // 00494b0c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494b0f  c1e718                 -shl edi, 0x18
    cpu.edi <<= 24 /*0x18*/ % 32;
    // 00494b12  c1e213                 -shl edx, 0x13
    cpu.edx <<= 19 /*0x13*/ % 32;
    // 00494b15  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00494b17  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00494b1b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494b1e  c1e70a                 -shl edi, 0xa
    cpu.edi <<= 10 /*0xa*/ % 32;
    // 00494b21  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494b24  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00494b26  43                     -inc ebx
    (cpu.ebx)++;
    // 00494b27  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00494b29  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494b2d  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00494b30  39f3                   +cmp ebx, esi
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
    // 00494b32  7caa                   -jl 0x494ade
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494ade;
    }
L_0x00494b34:
    // 00494b34  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00494b37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_494b3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494b3c);
    // 00494b3c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494b3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494b3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494b3f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494b40  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494b43  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00494b46  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00494b48  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494b4a  7e34                   -jle 0x494b80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494b80;
    }
L_0x00494b4c:
    // 00494b4c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494b4e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494b51  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00494b54  0fb67001               -movzx esi, byte ptr [eax + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 00494b58  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00494b5a  0fb628                 -movzx ebp, byte ptr [eax]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 00494b5d  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 00494b60  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494b62  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00494b68  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00494b6b  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00494b6e  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00494b70  41                     -inc ecx
    (cpu.ecx)++;
    // 00494b71  09eb                   -or ebx, ebp
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00494b73  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00494b76  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00494b79  39f1                   +cmp ecx, esi
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
    // 00494b7b  7ccf                   -jl 0x494b4c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494b4c;
    }
    // 00494b7d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00494b80:
    // 00494b80  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494b83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494b88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494b88);
    // 00494b88  c1e302                 +shl ebx, 2
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
    // 00494b8b  e9704fffff             -jmp 0x489b00
    return sub_489b00(app, cpu);
}

/* align: skip  */
void Application::sub_494b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494b90);
    // 00494b90  83f80f                 +cmp eax, 0xf
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
    // 00494b93  7312                   -jae 0x494ba7
    if (!cpu.flags.cf)
    {
        goto L_0x00494ba7;
    }
    // 00494b95  83f804                 +cmp eax, 4
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
    // 00494b98  722c                   -jb 0x494bc6
    if (cpu.flags.cf)
    {
        goto L_0x00494bc6;
    }
    // 00494b9a  762a                   -jbe 0x494bc6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494b9c  83f808                 +cmp eax, 8
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
    // 00494b9f  7525                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494ba1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494ba6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494ba7:
    // 00494ba7  7620                   -jbe 0x494bc9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bc9;
    }
    // 00494ba9  83f818                 +cmp eax, 0x18
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
    // 00494bac  730b                   -jae 0x494bb9
    if (!cpu.flags.cf)
    {
        goto L_0x00494bb9;
    }
    // 00494bae  83f810                 +cmp eax, 0x10
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
    // 00494bb1  7513                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494bb3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00494bb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bb9:
    // 00494bb9  7614                   -jbe 0x494bcf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bcf;
    }
    // 00494bbb  83f820                 +cmp eax, 0x20
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
    // 00494bbe  7506                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494bc0  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00494bc5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bc6:
    // 00494bc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494bc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bc9:
    // 00494bc9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00494bce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bcf:
    // 00494bcf  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00494bd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494bc9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494bc9);
    goto L_entry_0x00494bc9;
    // 00494b90  83f80f                 +cmp eax, 0xf
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
    // 00494b93  7312                   -jae 0x494ba7
    if (!cpu.flags.cf)
    {
        goto L_0x00494ba7;
    }
    // 00494b95  83f804                 +cmp eax, 4
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
    // 00494b98  722c                   -jb 0x494bc6
    if (cpu.flags.cf)
    {
        goto L_0x00494bc6;
    }
    // 00494b9a  762a                   -jbe 0x494bc6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494b9c  83f808                 +cmp eax, 8
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
    // 00494b9f  7525                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494ba1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494ba6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494ba7:
    // 00494ba7  7620                   -jbe 0x494bc9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bc9;
    }
    // 00494ba9  83f818                 +cmp eax, 0x18
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
    // 00494bac  730b                   -jae 0x494bb9
    if (!cpu.flags.cf)
    {
        goto L_0x00494bb9;
    }
    // 00494bae  83f810                 +cmp eax, 0x10
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
    // 00494bb1  7513                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494bb3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00494bb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bb9:
    // 00494bb9  7614                   -jbe 0x494bcf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bcf;
    }
    // 00494bbb  83f820                 +cmp eax, 0x20
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
    // 00494bbe  7506                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494bc0  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00494bc5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bc6:
    // 00494bc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494bc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bc9:
L_entry_0x00494bc9:
    // 00494bc9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00494bce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bcf:
    // 00494bcf  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00494bd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494bc0);
    goto L_entry_0x00494bc0;
    // 00494b90  83f80f                 +cmp eax, 0xf
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
    // 00494b93  7312                   -jae 0x494ba7
    if (!cpu.flags.cf)
    {
        goto L_0x00494ba7;
    }
    // 00494b95  83f804                 +cmp eax, 4
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
    // 00494b98  722c                   -jb 0x494bc6
    if (cpu.flags.cf)
    {
        goto L_0x00494bc6;
    }
    // 00494b9a  762a                   -jbe 0x494bc6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494b9c  83f808                 +cmp eax, 8
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
    // 00494b9f  7525                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494ba1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494ba6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494ba7:
    // 00494ba7  7620                   -jbe 0x494bc9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bc9;
    }
    // 00494ba9  83f818                 +cmp eax, 0x18
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
    // 00494bac  730b                   -jae 0x494bb9
    if (!cpu.flags.cf)
    {
        goto L_0x00494bb9;
    }
    // 00494bae  83f810                 +cmp eax, 0x10
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
    // 00494bb1  7513                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494bb3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00494bb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bb9:
    // 00494bb9  7614                   -jbe 0x494bcf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bcf;
    }
    // 00494bbb  83f820                 +cmp eax, 0x20
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
    // 00494bbe  7506                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
L_entry_0x00494bc0:
    // 00494bc0  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00494bc5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bc6:
    // 00494bc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494bc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bc9:
    // 00494bc9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00494bce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bcf:
    // 00494bcf  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00494bd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494bb3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494bb3);
    goto L_entry_0x00494bb3;
    // 00494b90  83f80f                 +cmp eax, 0xf
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
    // 00494b93  7312                   -jae 0x494ba7
    if (!cpu.flags.cf)
    {
        goto L_0x00494ba7;
    }
    // 00494b95  83f804                 +cmp eax, 4
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
    // 00494b98  722c                   -jb 0x494bc6
    if (cpu.flags.cf)
    {
        goto L_0x00494bc6;
    }
    // 00494b9a  762a                   -jbe 0x494bc6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494b9c  83f808                 +cmp eax, 8
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
    // 00494b9f  7525                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494ba1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494ba6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494ba7:
    // 00494ba7  7620                   -jbe 0x494bc9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bc9;
    }
    // 00494ba9  83f818                 +cmp eax, 0x18
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
    // 00494bac  730b                   -jae 0x494bb9
    if (!cpu.flags.cf)
    {
        goto L_0x00494bb9;
    }
    // 00494bae  83f810                 +cmp eax, 0x10
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
    // 00494bb1  7513                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
L_entry_0x00494bb3:
    // 00494bb3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00494bb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bb9:
    // 00494bb9  7614                   -jbe 0x494bcf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494bcf;
    }
    // 00494bbb  83f820                 +cmp eax, 0x20
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
    // 00494bbe  7506                   -jne 0x494bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00494bc6;
    }
    // 00494bc0  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00494bc5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bc6:
    // 00494bc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494bc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bc9:
    // 00494bc9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00494bce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bcf:
    // 00494bcf  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00494bd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494bd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494bd8);
    // 00494bd8  83f878                 +cmp eax, 0x78
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
    // 00494bdb  730f                   -jae 0x494bec
    if (!cpu.flags.cf)
    {
        goto L_0x00494bec;
    }
    // 00494bdd  83f842                 +cmp eax, 0x42
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
    // 00494be0  7335                   -jae 0x494c17
    if (!cpu.flags.cf)
    {
        goto L_0x00494c17;
    }
    // 00494be2  83f840                 +cmp eax, 0x40
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
    // 00494be5  7248                   -jb 0x494c2f
    if (cpu.flags.cf)
    {
        goto L_0x00494c2f;
    }
    // 00494be7  7716                   -ja 0x494bff
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00494bff;
    }
L_0x00494be9:
    // 00494be9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00494beb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494bec:
    // 00494bec  76c5                   -jbe 0x494bb3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_494bb3(app, cpu);
    }
    // 00494bee  83f87d                 +cmp eax, 0x7d
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
    // 00494bf1  7312                   -jae 0x494c05
    if (!cpu.flags.cf)
    {
        goto L_0x00494c05;
    }
    // 00494bf3  83f87a                 +cmp eax, 0x7a
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
    // 00494bf6  7237                   -jb 0x494c2f
    if (cpu.flags.cf)
    {
        goto L_0x00494c2f;
    }
    // 00494bf8  76ef                   -jbe 0x494be9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494be9;
    }
    // 00494bfa  83f87b                 +cmp eax, 0x7b
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
    // 00494bfd  7530                   -jne 0x494c2f
    if (!cpu.flags.zf)
    {
        goto L_0x00494c2f;
    }
L_0x00494bff:
    // 00494bff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494c04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494c05:
    // 00494c05  76b9                   -jbe 0x494bc0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_494bc0(app, cpu);
    }
    // 00494c07  83f87e                 +cmp eax, 0x7e
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
    // 00494c0a  76bd                   -jbe 0x494bc9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_494bc9(app, cpu);
    }
    // 00494c0c  83f87f                 +cmp eax, 0x7f
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
    // 00494c0f  751e                   -jne 0x494c2f
    if (!cpu.flags.zf)
    {
        goto L_0x00494c2f;
    }
L_0x00494c11:
    // 00494c11  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00494c16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494c17:
    // 00494c17  7610                   -jbe 0x494c29
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494c29;
    }
    // 00494c19  83f843                 +cmp eax, 0x43
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
    // 00494c1c  76f3                   -jbe 0x494c11
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00494c11;
    }
    // 00494c1e  83f86d                 +cmp eax, 0x6d
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
    // 00494c21  750c                   -jne 0x494c2f
    if (!cpu.flags.zf)
    {
        goto L_0x00494c2f;
    }
    // 00494c23  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00494c28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494c29:
    // 00494c29  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00494c2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494c2f:
    // 00494c2f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00494c34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494c38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494c38);
    // 00494c38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494c39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494c3a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494c3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494c3c  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00494c42  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00494c44  e847480000             -call 0x499490
    cpu.esp -= 4;
    sub_499490(app, cpu);
    if (cpu.terminate) return;
    // 00494c49  bfa0ea5600             -mov edi, 0x56eaa0
    cpu.edi = 5696160 /*0x56eaa0*/;
    // 00494c4e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494c50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494c52  7448                   -je 0x494c9c
    if (cpu.flags.zf)
    {
        goto L_0x00494c9c;
    }
    // 00494c54  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00494c56  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494c5c  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00494c5f  83fe2a                 +cmp esi, 0x2a
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
    // 00494c62  7445                   -je 0x494ca9
    if (cpu.flags.zf)
    {
        goto L_0x00494ca9;
    }
    // 00494c64  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00494c67  c781fc03000000000000   -mov dword ptr [ecx + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00494c71  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00494c73  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00494c75  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494c7b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00494c7e  83fa24                 +cmp edx, 0x24
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
    // 00494c81  742a                   -je 0x494cad
    if (cpu.flags.zf)
    {
        goto L_0x00494cad;
    }
    // 00494c83  83fa29                 +cmp edx, 0x29
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
    // 00494c86  7432                   -je 0x494cba
    if (cpu.flags.zf)
    {
        goto L_0x00494cba;
    }
    // 00494c88  83fa2d                 +cmp edx, 0x2d
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
    // 00494c8b  7438                   -je 0x494cc5
    if (cpu.flags.zf)
    {
        goto L_0x00494cc5;
    }
    // 00494c8d  83fa2c                 +cmp edx, 0x2c
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
    // 00494c90  743e                   -je 0x494cd0
    if (cpu.flags.zf)
    {
        goto L_0x00494cd0;
    }
    // 00494c92  83fa22                 +cmp edx, 0x22
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
    // 00494c95  7444                   -je 0x494cdb
    if (cpu.flags.zf)
    {
        goto L_0x00494cdb;
    }
    // 00494c97  83fa23                 +cmp edx, 0x23
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
    // 00494c9a  744c                   -je 0x494ce8
    if (cpu.flags.zf)
    {
        goto L_0x00494ce8;
    }
L_0x00494c9c:
    // 00494c9c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494c9e  81c400020000           +add esp, 0x200
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
    // 00494ca4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ca5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ca6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ca7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ca8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494ca9:
    // 00494ca9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00494cab  ebef                   -jmp 0x494c9c
    goto L_0x00494c9c;
L_0x00494cad:
    // 00494cad  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494caf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494cb1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494cb3  e8bc4a0100             -call 0x4a9774
    cpu.esp -= 4;
    sub_4a9774(app, cpu);
    if (cpu.terminate) return;
    // 00494cb8  ebe2                   -jmp 0x494c9c
    goto L_0x00494c9c;
L_0x00494cba:
    // 00494cba  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494cbc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494cbe  e805fdffff             -call 0x4949c8
    cpu.esp -= 4;
    sub_4949c8(app, cpu);
    if (cpu.terminate) return;
    // 00494cc3  ebd7                   -jmp 0x494c9c
    goto L_0x00494c9c;
L_0x00494cc5:
    // 00494cc5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494cc7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494cc9  e88afcffff             -call 0x494958
    cpu.esp -= 4;
    sub_494958(app, cpu);
    if (cpu.terminate) return;
    // 00494cce  ebcc                   -jmp 0x494c9c
    goto L_0x00494c9c;
L_0x00494cd0:
    // 00494cd0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494cd2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494cd4  e8effdffff             -call 0x494ac8
    cpu.esp -= 4;
    sub_494ac8(app, cpu);
    if (cpu.terminate) return;
    // 00494cd9  ebc1                   -jmp 0x494c9c
    goto L_0x00494c9c;
L_0x00494cdb:
    // 00494cdb  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494cdd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494cdf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494ce1  e89a490100             -call 0x4a9680
    cpu.esp -= 4;
    sub_4a9680(app, cpu);
    if (cpu.terminate) return;
    // 00494ce6  ebb4                   -jmp 0x494c9c
    goto L_0x00494c9c;
L_0x00494ce8:
    // 00494ce8  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00494ced  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00494cef  e86cda0000             -call 0x4a2760
    cpu.esp -= 4;
    sub_4a2760(app, cpu);
    if (cpu.terminate) return;
    // 00494cf4  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00494cf9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494cfb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494cfd  e856fcffff             -call 0x494958
    cpu.esp -= 4;
    sub_494958(app, cpu);
    if (cpu.terminate) return;
    // 00494d02  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494d04  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00494d0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_494d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494d10);
    // 00494d10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494d11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494d12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494d13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494d14  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00494d1a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00494d1c  e86f470000             -call 0x499490
    cpu.esp -= 4;
    sub_499490(app, cpu);
    if (cpu.terminate) return;
    // 00494d21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494d23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494d25  0f84b4000000           -je 0x494ddf
    if (cpu.flags.zf)
    {
        goto L_0x00494ddf;
    }
    // 00494d2b  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00494d2d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494d33  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00494d36  83fb29                 +cmp ebx, 0x29
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
    // 00494d39  7444                   -je 0x494d7f
    if (cpu.flags.zf)
    {
        goto L_0x00494d7f;
    }
    // 00494d3b  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00494d3e  66c781fe0100000000     -mov word ptr [ecx + 0x1fe], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(510) /* 0x1fe */) = 0 /*0x0*/;
    // 00494d47  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00494d49  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00494d4b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494d51  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00494d54  83fa24                 +cmp edx, 0x24
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
    // 00494d57  742a                   -je 0x494d83
    if (cpu.flags.zf)
    {
        goto L_0x00494d83;
    }
    // 00494d59  83fa2c                 +cmp edx, 0x2c
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
    // 00494d5c  743d                   -je 0x494d9b
    if (cpu.flags.zf)
    {
        goto L_0x00494d9b;
    }
    // 00494d5e  83fa2d                 +cmp edx, 0x2d
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
    // 00494d61  7443                   -je 0x494da6
    if (cpu.flags.zf)
    {
        goto L_0x00494da6;
    }
    // 00494d63  83fa2a                 +cmp edx, 0x2a
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
    // 00494d66  7428                   -je 0x494d90
    if (cpu.flags.zf)
    {
        goto L_0x00494d90;
    }
    // 00494d68  83fa22                 +cmp edx, 0x22
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
    // 00494d6b  7444                   -je 0x494db1
    if (cpu.flags.zf)
    {
        goto L_0x00494db1;
    }
    // 00494d6d  83fa23                 +cmp edx, 0x23
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
    // 00494d70  7457                   -je 0x494dc9
    if (cpu.flags.zf)
    {
        goto L_0x00494dc9;
    }
L_0x00494d72:
    // 00494d72  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494d74  81c400040000           +add esp, 0x400
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
    // 00494d7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494d7f:
    // 00494d7f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00494d81  ebef                   -jmp 0x494d72
    goto L_0x00494d72;
L_0x00494d83:
    // 00494d83  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00494d85  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494d87  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494d89  e8e6490100             -call 0x4a9774
    cpu.esp -= 4;
    sub_4a9774(app, cpu);
    if (cpu.terminate) return;
    // 00494d8e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00494d90:
    // 00494d90  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494d92  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494d94  e83ff9ffff             -call 0x4946d8
    cpu.esp -= 4;
    sub_4946d8(app, cpu);
    if (cpu.terminate) return;
    // 00494d99  ebd7                   -jmp 0x494d72
    goto L_0x00494d72;
L_0x00494d9b:
    // 00494d9b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494d9d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494d9f  e814f9ffff             -call 0x4946b8
    cpu.esp -= 4;
    sub_4946b8(app, cpu);
    if (cpu.terminate) return;
    // 00494da4  ebcc                   -jmp 0x494d72
    goto L_0x00494d72;
L_0x00494da6:
    // 00494da6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494da8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494daa  e8a9fbffff             -call 0x494958
    cpu.esp -= 4;
    sub_494958(app, cpu);
    if (cpu.terminate) return;
    // 00494daf  ebc1                   -jmp 0x494d72
    goto L_0x00494d72;
L_0x00494db1:
    // 00494db1  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00494db3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494db5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494db7  e8c4480100             -call 0x4a9680
    cpu.esp -= 4;
    sub_4a9680(app, cpu);
    if (cpu.terminate) return;
    // 00494dbc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494dbe  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494dc0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494dc2  e811f9ffff             -call 0x4946d8
    cpu.esp -= 4;
    sub_4946d8(app, cpu);
    if (cpu.terminate) return;
    // 00494dc7  eba9                   -jmp 0x494d72
    goto L_0x00494d72;
L_0x00494dc9:
    // 00494dc9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494dcb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494dcd  e88ed90000             -call 0x4a2760
    cpu.esp -= 4;
    sub_4a2760(app, cpu);
    if (cpu.terminate) return;
    // 00494dd2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494dd4  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00494dda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ddb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ddc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ddd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494dde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494ddf:
    // 00494ddf  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00494de4  b8a0ea5600             -mov eax, 0x56eaa0
    cpu.eax = 5696160 /*0x56eaa0*/;
    // 00494de9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494deb  e8e8f8ffff             -call 0x4946d8
    cpu.esp -= 4;
    sub_4946d8(app, cpu);
    if (cpu.terminate) return;
    // 00494df0  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00494df2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494df4  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00494dfa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494dfb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494dfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494dfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494dfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_494e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494e00);
    // 00494e00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494e01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494e02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494e03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494e04  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00494e0a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00494e0c  e87f460000             -call 0x499490
    cpu.esp -= 4;
    sub_499490(app, cpu);
    if (cpu.terminate) return;
    // 00494e11  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494e13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494e15  0f84e1000000           -je 0x494efc
    if (cpu.flags.zf)
    {
        goto L_0x00494efc;
    }
    // 00494e1b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00494e1d  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494e23  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00494e26  83f92c                 +cmp ecx, 0x2c
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
    // 00494e29  7445                   -je 0x494e70
    if (cpu.flags.zf)
    {
        goto L_0x00494e70;
    }
    // 00494e2b  8b4a02                 -mov ecx, dword ptr [edx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00494e2e  c786fc03000000000000   -mov dword ptr [esi + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00494e38  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00494e3a  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00494e3c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494e42  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00494e45  83fa24                 +cmp edx, 0x24
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
    // 00494e48  742a                   -je 0x494e74
    if (cpu.flags.zf)
    {
        goto L_0x00494e74;
    }
    // 00494e4a  83fa29                 +cmp edx, 0x29
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
    // 00494e4d  743d                   -je 0x494e8c
    if (cpu.flags.zf)
    {
        goto L_0x00494e8c;
    }
    // 00494e4f  83fa2d                 +cmp edx, 0x2d
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
    // 00494e52  744e                   -je 0x494ea2
    if (cpu.flags.zf)
    {
        goto L_0x00494ea2;
    }
    // 00494e54  83fa2a                 +cmp edx, 0x2a
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
    // 00494e57  7454                   -je 0x494ead
    if (cpu.flags.zf)
    {
        goto L_0x00494ead;
    }
    // 00494e59  83fa22                 +cmp edx, 0x22
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
    // 00494e5c  745a                   -je 0x494eb8
    if (cpu.flags.zf)
    {
        goto L_0x00494eb8;
    }
    // 00494e5e  83fa23                 +cmp edx, 0x23
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
    // 00494e61  746d                   -je 0x494ed0
    if (cpu.flags.zf)
    {
        goto L_0x00494ed0;
    }
L_0x00494e63:
    // 00494e63  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494e65  81c400040000           +add esp, 0x400
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
    // 00494e6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e6f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494e70:
    // 00494e70  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00494e72  ebef                   -jmp 0x494e63
    goto L_0x00494e63;
L_0x00494e74:
    // 00494e74  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00494e76  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494e78  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494e7a  e8f5480100             -call 0x4a9774
    cpu.esp -= 4;
    sub_4a9774(app, cpu);
    if (cpu.terminate) return;
    // 00494e7f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494e81  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494e83  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494e85  e85ef9ffff             -call 0x4947e8
    cpu.esp -= 4;
    sub_4947e8(app, cpu);
    if (cpu.terminate) return;
    // 00494e8a  ebd7                   -jmp 0x494e63
    goto L_0x00494e63;
L_0x00494e8c:
    // 00494e8c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00494e8e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494e90  e833fbffff             -call 0x4949c8
    cpu.esp -= 4;
    sub_4949c8(app, cpu);
    if (cpu.terminate) return;
    // 00494e95  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494e97  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494e99  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494e9b  e848f9ffff             -call 0x4947e8
    cpu.esp -= 4;
    sub_4947e8(app, cpu);
    if (cpu.terminate) return;
    // 00494ea0  ebc1                   -jmp 0x494e63
    goto L_0x00494e63;
L_0x00494ea2:
    // 00494ea2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00494ea4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494ea6  e8adfaffff             -call 0x494958
    cpu.esp -= 4;
    sub_494958(app, cpu);
    if (cpu.terminate) return;
    // 00494eab  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00494ead:
    // 00494ead  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494eaf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494eb1  e832f9ffff             -call 0x4947e8
    cpu.esp -= 4;
    sub_4947e8(app, cpu);
    if (cpu.terminate) return;
    // 00494eb6  ebab                   -jmp 0x494e63
    goto L_0x00494e63;
L_0x00494eb8:
    // 00494eb8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00494eba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494ebc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494ebe  e8bd470100             -call 0x4a9680
    cpu.esp -= 4;
    sub_4a9680(app, cpu);
    if (cpu.terminate) return;
    // 00494ec3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494ec5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494ec7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494ec9  e81af9ffff             -call 0x4947e8
    cpu.esp -= 4;
    sub_4947e8(app, cpu);
    if (cpu.terminate) return;
    // 00494ece  eb93                   -jmp 0x494e63
    goto L_0x00494e63;
L_0x00494ed0:
    // 00494ed0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494ed2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494ed4  e887d80000             -call 0x4a2760
    cpu.esp -= 4;
    sub_4a2760(app, cpu);
    if (cpu.terminate) return;
    // 00494ed9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00494edb  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494edd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494edf  e8e4faffff             -call 0x4949c8
    cpu.esp -= 4;
    sub_4949c8(app, cpu);
    if (cpu.terminate) return;
    // 00494ee4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494ee6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494ee8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494eea  e8f9f8ffff             -call 0x4947e8
    cpu.esp -= 4;
    sub_4947e8(app, cpu);
    if (cpu.terminate) return;
    // 00494eef  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494ef1  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00494ef7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ef8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ef9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494efa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494efb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494efc:
    // 00494efc  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00494f01  b8a0ea5600             -mov eax, 0x56eaa0
    cpu.eax = 5696160 /*0x56eaa0*/;
    // 00494f06  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494f08  e8dbf8ffff             -call 0x4947e8
    cpu.esp -= 4;
    sub_4947e8(app, cpu);
    if (cpu.terminate) return;
    // 00494f0d  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00494f0f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494f11  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00494f17  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494f18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494f19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494f1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494f1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494f1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00494f1c);
    // 00494f1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494f1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494f1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494f1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494f20  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494f23  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00494f25  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00494f29  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00494f2b  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494f31  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494f33  e8a0fcffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 00494f38  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 00494f3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494f41  e892fcffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 00494f46  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494f48  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494f4a  8a8194af4d00           -mov al, byte ptr [ecx + 0x4daf94]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5091220) /* 0x4daf94 */);
    // 00494f50  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00494f52  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00494f55  39c2                   +cmp edx, eax
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
    // 00494f57  754d                   -jne 0x494fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00494fa6;
    }
    // 00494f59  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00494f5e  7550                   -jne 0x494fb0
    if (!cpu.flags.zf)
    {
        goto L_0x00494fb0;
    }
    // 00494f60  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494f62  e871fcffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 00494f67  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 00494f6e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494f70  e863fcffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 00494f75  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00494f77  8b2c8594ae4d00         -mov ebp, dword ptr [eax*4 + 0x4dae94]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090964) /* 0x4dae94 */ + cpu.eax * 4);
L_0x00494f7e:
    // 00494f7e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494f80  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00494f82  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00494f85  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 00494f8b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494f8d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494f8f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00494f91  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00494f94  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 00494f9a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00494f9c  83f908                 +cmp ecx, 8
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
    // 00494f9f  7f05                   -jg 0x494fa6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494fa6;
    }
    // 00494fa1  83f808                 +cmp eax, 8
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
    // 00494fa4  7f2a                   -jg 0x494fd0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494fd0;
    }
L_0x00494fa6:
    // 00494fa6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494fa8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494fab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494fac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494fad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494fae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494faf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494fb0:
    // 00494fb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494fb2  e821fcffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 00494fb7  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 00494fbe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494fc0  e813fcffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 00494fc5  01c8                   +add eax, ecx
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
    // 00494fc7  8b2c8594ad4d00         -mov ebp, dword ptr [eax*4 + 0x4dad94]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090708) /* 0x4dad94 */ + cpu.eax * 4);
    // 00494fce  ebae                   -jmp 0x494f7e
    goto L_0x00494f7e;
L_0x00494fd0:
    // 00494fd0  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 00494fd5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494fd7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00494fdc  e857fcffff             -call 0x494c38
    cpu.esp -= 4;
    sub_494c38(app, cpu);
    if (cpu.terminate) return;
    // 00494fe1  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00494fe5  a390ad4d00             -mov dword ptr [0x4dad90], eax
    app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */) = cpu.eax;
    // 00494fea  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 00494fec  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00494fee  7432                   -je 0x495022
    if (cpu.flags.zf)
    {
        goto L_0x00495022;
    }
    // 00494ff0  83fe0f                 +cmp esi, 0xf
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
    // 00494ff3  7419                   -je 0x49500e
    if (cpu.flags.zf)
    {
        goto L_0x0049500e;
    }
    // 00494ff5  83fe10                 +cmp esi, 0x10
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
    // 00494ff8  75ac                   -jne 0x494fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00494fa6;
    }
    // 00494ffa  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 00494fff  e8d4f6ffff             -call 0x4946d8
    cpu.esp -= 4;
    sub_4946d8(app, cpu);
    if (cpu.terminate) return;
    // 00495004  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00495006  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00495009  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049500a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049500b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049500c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049500d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049500e:
    // 0049500e  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 00495013  e8e4f5ffff             -call 0x4945fc
    cpu.esp -= 4;
    sub_4945fc(app, cpu);
    if (cpu.terminate) return;
    // 00495018  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049501a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049501d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049501e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049501f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495020  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495021  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495022:
    // 00495022  83fe0f                 +cmp esi, 0xf
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
    // 00495025  741d                   -je 0x495044
    if (cpu.flags.zf)
    {
        goto L_0x00495044;
    }
    // 00495027  83fe10                 +cmp esi, 0x10
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
    // 0049502a  0f8576ffffff           -jne 0x494fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00494fa6;
    }
    // 00495030  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 00495035  e8fef6ffff             -call 0x494738
    cpu.esp -= 4;
    sub_494738(app, cpu);
    if (cpu.terminate) return;
    // 0049503a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049503c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049503f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495040  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495041  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495042  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495043  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495044:
    // 00495044  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 00495049  e80ef6ffff             -call 0x49465c
    cpu.esp -= 4;
    sub_49465c(app, cpu);
    if (cpu.terminate) return;
    // 0049504e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00495050  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00495053  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495054  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495055  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495056  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495057  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495058(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495058);
    // 00495058  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495059  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049505a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049505b  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0049505e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00495060  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00495064  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 00495068  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0049506c  e81f440000             -call 0x499490
    cpu.esp -= 4;
    sub_499490(app, cpu);
    if (cpu.terminate) return;
    // 00495071  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00495076  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495078  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049507c  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00495080  894c2438               -mov dword ptr [esp + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ecx;
L_0x00495084:
    // 00495084  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 00495089  0f8580020000           -jne 0x49530f
    if (!cpu.flags.zf)
    {
        goto L_0x0049530f;
    }
    // 0049508f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00495091  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495096  e83dfbffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 0049509b  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 004950a2  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004950a6  e82dfbffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 004950ab  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004950ad  8b048594ae4d00         -mov eax, dword ptr [eax*4 + 0x4dae94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090964) /* 0x4dae94 */ + cpu.eax * 4);
L_0x004950b4:
    // 004950b4  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004950b8  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004950ba  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004950bf  e814fbffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 004950c4  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 004950cb  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004950cf  e804fbffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 004950d4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004950d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004950d8  8a8294af4d00           -mov al, byte ptr [edx + 0x4daf94]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5091220) /* 0x4daf94 */);
    // 004950de  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004950e2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004950e4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004950e6  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004950e9  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 004950ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004950f1  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004950f5  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004950f9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004950fb  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004950fe  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 00495104  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00495106  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0049510a  40                     -inc eax
    (cpu.eax)++;
    // 0049510b  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049510d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049510f  8b4702                 -mov eax, dword ptr [edi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00495112  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00495115  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00495119  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049511c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049511f  89442454               -mov dword ptr [esp + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00495123  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495125  e836010100             -call 0x4a5260
    cpu.esp -= 4;
    sub_4a5260(app, cpu);
    if (cpu.terminate) return;
    // 0049512a  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0049512e  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00495132  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00495135  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00495138  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0049513a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049513c  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 0049513f  83f908                 +cmp ecx, 8
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
    // 00495142  0f8f73000000           -jg 0x4951bb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004951bb;
    }
    // 00495148  83fb08                 +cmp ebx, 8
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
    // 0049514b  7e6e                   -jle 0x4951bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004951bb;
    }
    // 0049514d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00495152  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00495156  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 00495158  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049515a  0f84d9010000           -je 0x495339
    if (cpu.flags.zf)
    {
        goto L_0x00495339;
    }
    // 00495160  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495162  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00495164  7e1e                   -jle 0x495184
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495184;
    }
    // 00495166  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00495168:
    // 00495168  0fb6b0acb34d00         -movzx esi, byte ptr [eax + 0x4db3ac]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */));
    // 0049516f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495172  8b34b5a0ea5600         -mov esi, dword ptr [esi*4 + 0x56eaa0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5696160) /* 0x56eaa0 */ + cpu.esi * 4);
    // 00495179  40                     -inc eax
    (cpu.eax)++;
    // 0049517a  89b118cb5600           -mov dword ptr [ecx + 0x56cb18], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5688088) /* 0x56cb18 */) = cpu.esi;
    // 00495180  39d8                   +cmp eax, ebx
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
    // 00495182  7ce4                   -jl 0x495168
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495168;
    }
L_0x00495184:
    // 00495184  c70590ad4d001ccb5600   -mov dword ptr [0x4dad90], 0x56cb1c
    app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */) = 5688092 /*0x56cb1c*/;
L_0x0049518e:
    // 0049518e  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 00495193  0f84d5010000           -je 0x49536e
    if (cpu.flags.zf)
    {
        goto L_0x0049536e;
    }
    // 00495199  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049519d  83f80f                 +cmp eax, 0xf
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
    // 004951a0  0f85ab010000           -jne 0x495351
    if (!cpu.flags.zf)
    {
        goto L_0x00495351;
    }
    // 004951a6  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 004951ab  a190ad4d00             -mov eax, dword ptr [0x4dad90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */);
    // 004951b0  e847f4ffff             -call 0x4945fc
    cpu.esp -= 4;
    sub_4945fc(app, cpu);
    if (cpu.terminate) return;
L_0x004951b5:
    // 004951b5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004951b7  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
L_0x004951bb:
    // 004951bb  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004951bf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004951c0  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004951c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004951c5  6848eb4c00             -push 0x4ceb48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040968 /*0x4ceb48*/;
    cpu.esp -= 4;
    // 004951ca  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004951ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004951cf  e89df7feff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 004951d4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004951d7  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004951db  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004951de  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004951e0  8b1d048a4d00           -mov ebx, dword ptr [0x4d8a04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 004951e6  8d5614                 -lea edx, [esi + 0x14]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004951e9  e81ad7feff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 004951ee  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004951f3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004951f5  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004951f9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004951fb  ba50485343             -mov edx, 0x43534850
    cpu.edx = 1129531472 /*0x43534850*/;
    // 00495200  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00495203  e818d30000             -call 0x4a2520
    cpu.esp -= 4;
    sub_4a2520(app, cpu);
    if (cpu.terminate) return;
    // 00495208  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049520c  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 0049520f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495214  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00495216  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00495218  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049521c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049521e  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00495220  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495226  66894104               -mov word ptr [ecx + 4], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0049522a  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049522e  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00495230  66894106               -mov word ptr [ecx + 6], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00495234  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00495238  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0049523c  668b470a               -mov ax, word ptr [edi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 00495240  668b510c               -mov dx, word ptr [ecx + 0xc]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00495244  6689410a               -mov word ptr [ecx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00495248  81e200f0ffff           -and edx, 0xfffff000
    cpu.edx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0049524e  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00495251  6689510c               -mov word ptr [ecx + 0xc], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 00495255  25ff0f0000             -and eax, 0xfff
    cpu.eax &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 0049525a  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049525d  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00495260  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00495262  8971fc                 -mov dword ptr [ecx - 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00495265  668b59fe               -mov bx, word ptr [ecx - 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 00495269  8d7710                 -lea esi, [edi + 0x10]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049526c  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00495272  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00495275  668959fe               -mov word ptr [ecx - 2], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00495279  250000ff0f             -and eax, 0xfff0000
    cpu.eax &= x86::reg32(x86::sreg32(268369920 /*0xfff0000*/));
    // 0049527e  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00495281  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00495283  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00495285  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00495289  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0049528c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049528e  7e1d                   -jle 0x4952ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004952ad;
    }
L_0x00495290:
    // 00495290  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00495294  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495296  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495298  ff54244c               -call dword ptr [esp + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049529c  47                     -inc edi
    (cpu.edi)++;
    // 0049529d  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004952a1  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004952a5  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004952a7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004952a9  39d7                   +cmp edi, edx
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
    // 004952ab  7ce3                   -jl 0x495290
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495290;
    }
L_0x004952ad:
    // 004952ad  0faf6c2454             -imul ebp, dword ptr [esp + 0x54]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */))));
    // 004952b2  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004952b6  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004952b8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004952bd  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004952c0  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004952c4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004952c6  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004952c8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004952ca  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004952d1  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004952d3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004952d5  7407                   -je 0x4952de
    if (cpu.flags.zf)
    {
        goto L_0x004952de;
    }
    // 004952d7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004952d9  e88edafeff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
L_0x004952de:
    // 004952de  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004952e2  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004952e6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004952e8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004952ea  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004952ee  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004952f3  39f0                   +cmp eax, esi
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
    // 004952f5  740f                   -je 0x495306
    if (cpu.flags.zf)
    {
        goto L_0x00495306;
    }
    // 004952f7  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004952fb  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004952fc  896c2438               -mov dword ptr [esp + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 00495300  0f857efdffff           -jne 0x495084
    if (!cpu.flags.zf)
    {
        goto L_0x00495084;
    }
L_0x00495306:
    // 00495306  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495308  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0049530b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049530c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049530d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049530e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049530f:
    // 0049530f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00495311  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495316  e8bdf8ffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 0049531b  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00495322  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00495326  e8adf8ffff             -call 0x494bd8
    cpu.esp -= 4;
    sub_494bd8(app, cpu);
    if (cpu.terminate) return;
    // 0049532b  01d0                   +add eax, edx
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
    // 0049532d  8b048594ad4d00         -mov eax, dword ptr [eax*4 + 0x4dad94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090708) /* 0x4dad94 */ + cpu.eax * 4);
    // 00495334  e97bfdffff             -jmp 0x4950b4
    goto L_0x004950b4;
L_0x00495339:
    // 00495339  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 0049533e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00495342  e8f1f8ffff             -call 0x494c38
    cpu.esp -= 4;
    sub_494c38(app, cpu);
    if (cpu.terminate) return;
    // 00495347  a390ad4d00             -mov dword ptr [0x4dad90], eax
    app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */) = cpu.eax;
    // 0049534c  e93dfeffff             -jmp 0x49518e
    goto L_0x0049518e;
L_0x00495351:
    // 00495351  83f810                 +cmp eax, 0x10
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
    // 00495354  0f855bfeffff           -jne 0x4951b5
    if (!cpu.flags.zf)
    {
        goto L_0x004951b5;
    }
    // 0049535a  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 0049535f  a190ad4d00             -mov eax, dword ptr [0x4dad90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */);
    // 00495364  e86ff3ffff             -call 0x4946d8
    cpu.esp -= 4;
    sub_4946d8(app, cpu);
    if (cpu.terminate) return;
    // 00495369  e947feffff             -jmp 0x4951b5
    goto L_0x004951b5;
L_0x0049536e:
    // 0049536e  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00495372  83f90f                 +cmp ecx, 0xf
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
    // 00495375  741d                   -je 0x495394
    if (cpu.flags.zf)
    {
        goto L_0x00495394;
    }
    // 00495377  83f910                 +cmp ecx, 0x10
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
    // 0049537a  0f8535feffff           -jne 0x4951b5
    if (!cpu.flags.zf)
    {
        goto L_0x004951b5;
    }
    // 00495380  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 00495385  a190ad4d00             -mov eax, dword ptr [0x4dad90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */);
    // 0049538a  e8a9f3ffff             -call 0x494738
    cpu.esp -= 4;
    sub_494738(app, cpu);
    if (cpu.terminate) return;
    // 0049538f  e921feffff             -jmp 0x4951b5
    goto L_0x004951b5;
L_0x00495394:
    // 00495394  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 00495399  a190ad4d00             -mov eax, dword ptr [0x4dad90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */);
    // 0049539e  e8b9f2ffff             -call 0x49465c
    cpu.esp -= 4;
    sub_49465c(app, cpu);
    if (cpu.terminate) return;
    // 004953a3  e90dfeffff             -jmp 0x4951b5
    goto L_0x004951b5;
}

/* align: skip  */
void Application::sub_4953a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004953a8);
    // 004953a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004953a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004953aa  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004953af  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004953b1  e8a2fcffff             -call 0x495058
    cpu.esp -= 4;
    sub_495058(app, cpu);
    if (cpu.terminate) return;
    // 004953b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4953bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004953bc);
    // 004953bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004953bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004953be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004953bf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004953c1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004953c3  e878330100             -call 0x4a8740
    cpu.esp -= 4;
    sub_4a8740(app, cpu);
    if (cpu.terminate) return;
    // 004953c8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004953cd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004953cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004953d1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004953d3  e880fcffff             -call 0x495058
    cpu.esp -= 4;
    sub_495058(app, cpu);
    if (cpu.terminate) return;
    // 004953d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4953e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004953e0);
    // 004953e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004953e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004953e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004953e3  81ec24020000           -sub esp, 0x224
    (cpu.esp) -= x86::reg32(x86::sreg32(548 /*0x224*/));
    // 004953e9  8bb42434020000         -mov esi, dword ptr [esp + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(564) /* 0x234 */);
    // 004953f0  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 004953f7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004953f9  899c240c020000         -mov dword ptr [esp + 0x20c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.ebx;
    // 00495400  898c2420020000         -mov dword ptr [esp + 0x220], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ecx;
    // 00495407  8bbc2410020000         -mov edi, dword ptr [esp + 0x210]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0049540e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495410  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00495413  8994241c020000         -mov dword ptr [esp + 0x21c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = cpu.edx;
    // 0049541a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049541d  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00495420  89842408020000         -mov dword ptr [esp + 0x208], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */) = cpu.eax;
    // 00495427  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0049542a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049542c  0f84bd000000           -je 0x4954ef
    if (cpu.flags.zf)
    {
        goto L_0x004954ef;
    }
    // 00495432  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495434  0f84b5000000           -je 0x4954ef
    if (cpu.flags.zf)
    {
        goto L_0x004954ef;
    }
    // 0049543a  a1c4894d00             -mov eax, dword ptr [0x4d89c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081540) /* 0x4d89c4 */);
    // 0049543f  89942404020000         -mov dword ptr [esp + 0x204], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.edx;
    // 00495446  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495448  7418                   -je 0x495462
    if (cpu.flags.zf)
    {
        goto L_0x00495462;
    }
    // 0049544a  833dc8894d0000         +cmp dword ptr [0x4d89c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081544) /* 0x4d89c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495451  0f84a4000000           -je 0x4954fb
    if (cpu.flags.zf)
    {
        goto L_0x004954fb;
    }
    // 00495457  c784241c020000004e4a00 -mov dword ptr [esp + 0x21c], 0x4a4e00
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4869632 /*0x4a4e00*/;
L_0x00495462:
    // 00495462  8b942410020000         -mov edx, dword ptr [esp + 0x210]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 00495469  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049546b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049546d  a079904d00             -mov al, byte ptr [0x4d9079]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083257) /* 0x4d9079 */);
    // 00495472  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495478  39c2                   +cmp edx, eax
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
    // 0049547a  744c                   -je 0x4954c8
    if (cpu.flags.zf)
    {
        goto L_0x004954c8;
    }
    // 0049547c  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 00495483  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00495485  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00495488  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 0049548e  83f808                 +cmp eax, 8
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
    // 00495491  0f8574000000           -jne 0x49550b
    if (!cpu.flags.zf)
    {
        goto L_0x0049550b;
    }
    // 00495497  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049549e  756b                   -jne 0x49550b
    if (!cpu.flags.zf)
    {
        goto L_0x0049550b;
    }
    // 004954a0  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004954a2  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 004954a9  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 004954ae  e85df8ffff             -call 0x494d10
    cpu.esp -= 4;
    sub_494d10(app, cpu);
    if (cpu.terminate) return;
    // 004954b3  ba1ccb5600             -mov edx, 0x56cb1c
    cpu.edx = 5688092 /*0x56cb1c*/;
    // 004954b8  e84346ffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004954bd  c784241c020000be4c4a00 -mov dword ptr [esp + 0x21c], 0x4a4cbe
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4869310 /*0x4a4cbe*/;
L_0x004954c8:
    // 004954c8  3b2d70904d00           +cmp ebp, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004954ce  7c63                   -jl 0x495533
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495533;
    }
L_0x004954d0:
    // 004954d0  8b942404020000         -mov edx, dword ptr [esp + 0x204]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 004954d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004954d9  7407                   -je 0x4954e2
    if (cpu.flags.zf)
    {
        goto L_0x004954e2;
    }
    // 004954db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004954dd  e88ad8feff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
L_0x004954e2:
    // 004954e2  833dc8894d0000         +cmp dword ptr [0x4d89c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081544) /* 0x4d89c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004954e9  0f8582020000           -jne 0x495771
    if (!cpu.flags.zf)
    {
        goto L_0x00495771;
    }
L_0x004954ef:
    // 004954ef  81c424020000           +add esp, 0x224
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
    // 004954f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954f8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004954fb:
    // 004954fb  c784241c020000da504a00 -mov dword ptr [esp + 0x21c], 0x4a50da
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4870362 /*0x4a50da*/;
    // 00495506  e957ffffff             -jmp 0x495462
    goto L_0x00495462;
L_0x0049550b:
    // 0049550b  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 00495512  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495514  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495516  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00495518  8a1579904d00           -mov dl, byte ptr [0x4d9079]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5083257) /* 0x4d9079 */);
    // 0049551e  e835fbffff             -call 0x495058
    cpu.esp -= 4;
    sub_495058(app, cpu);
    if (cpu.terminate) return;
    // 00495523  89842404020000         -mov dword ptr [esp + 0x204], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.eax;
    // 0049552a  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 00495531  eb95                   -jmp 0x4954c8
    goto L_0x004954c8;
L_0x00495533:
    // 00495533  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0049553a  3b0574904d00           +cmp eax, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495540  7d8e                   -jge 0x4954d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004954d0;
    }
    // 00495542  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00495549  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049554b  0f8ee9010000           -jle 0x49573a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049573a;
    }
    // 00495551  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00495553:
    // 00495553  8b1568904d00           -mov edx, dword ptr [0x4d9068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 00495559  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049555b  39d0                   +cmp eax, edx
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
    // 0049555d  0f8e6dffffff           -jle 0x4954d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004954d0;
    }
    // 00495563  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495565  0f8ed8010000           -jle 0x495743
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495743;
    }
    // 0049556b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049556d:
    // 0049556d  8b8c240c020000         -mov ecx, dword ptr [esp + 0x20c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 00495574  8b1d6c904d00           -mov ebx, dword ptr [0x4d906c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 0049557a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049557c  39d8                   +cmp eax, ebx
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
    // 0049557e  0f8e4cffffff           -jle 0x4954d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004954d0;
    }
    // 00495584  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0049558b  8b942408020000         -mov edx, dword ptr [esp + 0x208]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 00495592  8b8c2420020000         -mov ecx, dword ptr [esp + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00495599  e8c2fc0000             -call 0x4a5260
    cpu.esp -= 4;
    sub_4a5260(app, cpu);
    if (cpu.terminate) return;
    // 0049559e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004955a1  89842414020000         -mov dword ptr [esp + 0x214], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */) = cpu.eax;
    // 004955a8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004955aa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004955ad  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004955af  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004955b2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004955b4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004955b6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004955b8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004955bb  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004955bd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004955bf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004955c2  89842418020000         -mov dword ptr [esp + 0x218], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */) = cpu.eax;
    // 004955c9  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004955cb  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004955cd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004955cf  0f8c77010000           -jl 0x49574c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049574c;
    }
    // 004955d5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004955d7:
    // 004955d7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004955d9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004955db  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004955de  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004955e0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004955e2  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004955e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004955eb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004955ed  0f8c62010000           -jl 0x495755
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495755;
    }
L_0x004955f3:
    // 004955f3  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004955fa  8b1d6c904d00           -mov ebx, dword ptr [0x4d906c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 00495600  39d8                   +cmp eax, ebx
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
    // 00495602  7d23                   -jge 0x495627
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495627;
    }
    // 00495604  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495606  2b84240c020000         -sub eax, dword ptr [esp + 0x20c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */)));
    // 0049560d  8b9c2418020000         -mov ebx, dword ptr [esp + 0x218]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 00495614  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00495617  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00495619  a16c904d00             -mov eax, dword ptr [0x4d906c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 0049561e  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00495620  8984240c020000         -mov dword ptr [esp + 0x20c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.eax;
L_0x00495627:
    // 00495627  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0049562e  8b1d74904d00           -mov ebx, dword ptr [0x4d9074]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 00495634  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00495636  39d8                   +cmp eax, ebx
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
    // 00495638  7e0b                   -jle 0x495645
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495645;
    }
    // 0049563a  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 00495641  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00495643  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00495645:
    // 00495645  8b1d68904d00           -mov ebx, dword ptr [0x4d9068]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 0049564b  39dd                   +cmp ebp, ebx
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
    // 0049564d  7d14                   -jge 0x495663
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495663;
    }
    // 0049564f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495651  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00495653  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00495655  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00495658  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049565a  29842420020000         -sub dword ptr [esp + 0x220], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00495661  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00495663:
    // 00495663  8b842420020000         -mov eax, dword ptr [esp + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0049566a  8b1d70904d00           -mov ebx, dword ptr [0x4d9070]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 00495670  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00495672  39d8                   +cmp eax, ebx
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
    // 00495674  7e0b                   -jle 0x495681
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495681;
    }
    // 00495676  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495678  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049567a  89842420020000         -mov dword ptr [esp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.eax;
L_0x00495681:
    // 00495681  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 00495688  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049568b  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 00495692  8b9c2400020000         -mov ebx, dword ptr [esp + 0x200]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00495699  a188904d00             -mov eax, dword ptr [0x4d9088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0049569e  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 004956a1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004956a3  a18c904d00             -mov eax, dword ptr [0x4d908c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004956a8  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004956aa  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004956ac  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004956ae  8b84241c020000         -mov eax, dword ptr [esp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */);
    // 004956b5  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004956b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004956b9  750b                   -jne 0x4956c6
    if (!cpu.flags.zf)
    {
        goto L_0x004956c6;
    }
    // 004956bb  c784241c020000254b4a00 -mov dword ptr [esp + 0x21c], 0x4a4b25
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4868901 /*0x4a4b25*/;
L_0x004956c6:
    // 004956c6  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004956c8  8b842420020000         -mov eax, dword ptr [esp + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004956cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004956d0  8b9c240c020000         -mov ebx, dword ptr [esp + 0x20c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004956d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004956d8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004956da  b8a42b5b00             -mov eax, 0x5b2ba4
    cpu.eax = 5974948 /*0x5b2ba4*/;
    // 004956df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004956e1  e8dafb0000             -call 0x4a52c0
    cpu.esp -= 4;
    sub_4a52c0(app, cpu);
    if (cpu.terminate) return;
    // 004956e6  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 004956ed  baa42b5b00             -mov edx, 0x5b2ba4
    cpu.edx = 5974948 /*0x5b2ba4*/;
    // 004956f2  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004956f5  e852f10000             -call 0x4a484c
    cpu.esp -= 4;
    sub_4a484c(app, cpu);
    if (cpu.terminate) return;
L_0x004956fa:
    // 004956fa  4e                     -dec esi
    (cpu.esi)--;
    // 004956fb  83feff                 +cmp esi, -1
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
    // 004956fe  0f84ccfdffff           -je 0x4954d0
    if (cpu.flags.zf)
    {
        goto L_0x004954d0;
    }
    // 00495704  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495706  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0049570d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00495710  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00495713  8b8c2420020000         -mov ecx, dword ptr [esp + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0049571a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049571b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049571c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049571d  ff942428020000         -call dword ptr [esp + 0x228]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(552) /* 0x228 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495724  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00495727  8b1d84904d00           -mov ebx, dword ptr [0x4d9084]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083268) /* 0x4d9084 */);
    // 0049572d  8b842418020000         -mov eax, dword ptr [esp + 0x218]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 00495734  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00495736  01c7                   +add edi, eax
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
    // 00495738  ebc0                   -jmp 0x4956fa
    goto L_0x004956fa;
L_0x0049573a:
    // 0049573a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049573c  f7d8                   +neg eax
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
    // 0049573e  e910feffff             -jmp 0x495553
    goto L_0x00495553;
L_0x00495743:
    // 00495743  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495745  f7d8                   +neg eax
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
    // 00495747  e921feffff             -jmp 0x49556d
    goto L_0x0049556d;
L_0x0049574c:
    // 0049574c  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0049574e  01c7                   +add edi, eax
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
    // 00495750  e982feffff             -jmp 0x4955d7
    goto L_0x004955d7;
L_0x00495755:
    // 00495755  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495757  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00495759  89842420020000         -mov dword ptr [esp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.eax;
    // 00495760  8b842408020000         -mov eax, dword ptr [esp + 0x208]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 00495767  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049576a  01c2                   +add edx, eax
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
    // 0049576c  e982feffff             -jmp 0x4955f3
    goto L_0x004955f3;
L_0x00495771:
    // 00495771  0f77                   -emms 
    cpu.mmx.init();
    // 00495773  81c424020000           -add esp, 0x224
    (cpu.esp) += x86::reg32(x86::sreg32(548 /*0x224*/));
    // 00495779  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049577a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049577b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049577c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_495780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495780);
    // 00495780  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495781  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495782  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495783  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00495786  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495788  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049578a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049578d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049578f  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00495792  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00495795  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495797  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049579b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049579e  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004957a2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004957a4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004957a7  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004957a9  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004957ac  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004957b0  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004957b3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004957b6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004957b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004957ba  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004957bd  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004957bf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004957c1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004957c3  7d50                   -jge 0x495815
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495815;
    }
    // 004957c5  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004957c8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004957cc  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004957cf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004957d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004957d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004957d5  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004957d7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004957da  c1e810                 +shr eax, 0x10
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
    // 004957dd  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004957df  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004957e1:
    // 004957e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004957e3  7c46                   -jl 0x49582b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049582b;
    }
    // 004957e5  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004957e8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004957ea  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004957ed  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004957f0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004957f2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004957f5  c1e810                 +shr eax, 0x10
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
    // 004957f8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004957fa  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004957fc:
    // 004957fc  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00495800  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00495802  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495803  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00495805  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495807  e8d4fbffff             -call 0x4953e0
    cpu.esp -= 4;
    sub_4953e0(app, cpu);
    if (cpu.terminate) return;
    // 0049580c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049580f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495810  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495811  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495812  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00495815:
    // 00495815  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00495818  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049581a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049581d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049581f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00495822  c1e810                 +shr eax, 0x10
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
    // 00495825  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00495827  29c5                   +sub ebp, eax
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
    // 00495829  ebb6                   -jmp 0x4957e1
    goto L_0x004957e1;
L_0x0049582b:
    // 0049582b  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049582e  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00495831  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00495834  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00495837  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00495839  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049583b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049583e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00495840  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00495843  c1e810                 +shr eax, 0x10
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
    // 00495846  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00495848  01c3                   +add ebx, eax
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
    // 0049584a  ebb0                   -jmp 0x4957fc
    goto L_0x004957fc;
}

/* align: skip  */
void Application::sub_49584c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049584c);
    // 0049584c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049584d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049584e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049584f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00495851  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00495854  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00495857  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0049585a  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0049585d  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00495860  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00495863  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00495865  e876fbffff             -call 0x4953e0
    cpu.esp -= 4;
    sub_4953e0(app, cpu);
    if (cpu.terminate) return;
    // 0049586a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049586b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049586c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495870);
    // 00495870  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495871  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495872  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00495874  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00495876  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049587a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049587c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049587d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049587f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495881  e85afbffff             -call 0x4953e0
    cpu.esp -= 4;
    sub_4953e0(app, cpu);
    if (cpu.terminate) return;
    // 00495886  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495887  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495888  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49588c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049588c);
    // 0049588c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049588d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049588e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00495890  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00495892  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00495896  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495898  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495899  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049589b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049589d  e8defeffff             -call 0x495780
    cpu.esp -= 4;
    sub_495780(app, cpu);
    if (cpu.terminate) return;
    // 004958a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004958a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004958a4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4958a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004958a8);
    // 004958a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004958a9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004958ab  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004958ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004958af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004958b1  e896ffffff             -call 0x49584c
    cpu.esp -= 4;
    sub_49584c(app, cpu);
    if (cpu.terminate) return;
    // 004958b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004958b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4958b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004958b8);
    // 004958b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004958b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004958ba  891dd4af4d00           -mov dword ptr [0x4dafd4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */) = cpu.ebx;
    // 004958c0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004958c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004958c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x004958c4:
    // 004958c4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004958c6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004958c8  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 004958ca  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004958cc  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 004958cf  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004958d4  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004958d7  8b2c9da8c35600         -mov ebp, dword ptr [ebx*4 + 0x56c3a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5686184) /* 0x56c3a8 */ + cpu.ebx * 4);
    // 004958de  8b3cbda8bf5600         -mov edi, dword ptr [edi*4 + 0x56bfa8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5685160) /* 0x56bfa8 */ + cpu.edi * 4);
    // 004958e5  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004958e8  8b0485a8c15600         -mov eax, dword ptr [eax*4 + 0x56c1a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5685672) /* 0x56c1a8 */ + cpu.eax * 4);
    // 004958ef  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004958f1  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004958f3  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004958f5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004958f7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004958f9  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 004958fc  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 00495902  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 00495905  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049590b  8b0485e0ba5600         -mov eax, dword ptr [eax*4 + 0x56bae0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5683936) /* 0x56bae0 */ + cpu.eax * 4);
    // 00495912  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 00495915  8b0c8dc8b65600         -mov ecx, dword ptr [ecx*4 + 0x56b6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5682888) /* 0x56b6c8 */ + cpu.ecx * 4);
    // 0049591c  8b3cbd40b15600         -mov edi, dword ptr [edi*4 + 0x56b140]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5681472) /* 0x56b140 */ + cpu.edi * 4);
    // 00495923  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495925  8b1c9da8bf5600         -mov ebx, dword ptr [ebx*4 + 0x56bfa8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5685160) /* 0x56bfa8 */ + cpu.ebx * 4);
    // 0049592c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049592e  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00495930  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00495932  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495934  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495936  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 0049593c  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0049593f  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00495945  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 00495948  8b0dd4af4d00           -mov ecx, dword ptr [0x4dafd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */);
    // 0049594e  8b0485e0ba5600         -mov eax, dword ptr [eax*4 + 0x56bae0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5683936) /* 0x56bae0 */ + cpu.eax * 4);
    // 00495955  8b3cbd40b15600         -mov edi, dword ptr [edi*4 + 0x56b140]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5681472) /* 0x56b140 */ + cpu.edi * 4);
    // 0049595c  8b1c9dc8b65600         -mov ebx, dword ptr [ebx*4 + 0x56b6c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5682888) /* 0x56b6c8 */ + cpu.ebx * 4);
    // 00495963  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00495965  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00495967  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049596d  250000ffff             -and eax, 0xffff0000
    cpu.eax &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00495972  09e8                   +or eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00495974  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495975  890dd4af4d00           -mov dword ptr [0x4dafd4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */) = cpu.ecx;
    // 0049597b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049597d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495980  0f853effffff           -jne 0x4958c4
    if (!cpu.flags.zf)
    {
        goto L_0x004958c4;
    }
    // 00495986  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495987  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495988  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495989  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049598a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49598b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049598b);
    // 0049598b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049598c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049598d  891dd4af4d00           -mov dword ptr [0x4dafd4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */) = cpu.ebx;
    // 00495993  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495995  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495996  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00495997:
    // 00495997  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00495999  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049599b  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0049599d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049599f  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 004959a2  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004959a7  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004959aa  8b2c9da8c35600         -mov ebp, dword ptr [ebx*4 + 0x56c3a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5686184) /* 0x56c3a8 */ + cpu.ebx * 4);
    // 004959b1  8b3cbda8bf5600         -mov edi, dword ptr [edi*4 + 0x56bfa8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5685160) /* 0x56bfa8 */ + cpu.edi * 4);
    // 004959b8  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004959bb  8b0485a8c15600         -mov eax, dword ptr [eax*4 + 0x56c1a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5685672) /* 0x56c1a8 */ + cpu.eax * 4);
    // 004959c2  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004959c4  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004959c6  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004959c8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004959ca  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004959cc  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 004959cf  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 004959d5  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 004959d8  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004959de  8b0485e0ba5600         -mov eax, dword ptr [eax*4 + 0x56bae0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5683936) /* 0x56bae0 */ + cpu.eax * 4);
    // 004959e5  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 004959e8  8b0c8dc8b65600         -mov ecx, dword ptr [ecx*4 + 0x56b6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5682888) /* 0x56b6c8 */ + cpu.ecx * 4);
    // 004959ef  8b3cbd40b15600         -mov edi, dword ptr [edi*4 + 0x56b140]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5681472) /* 0x56b140 */ + cpu.edi * 4);
    // 004959f6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004959f8  8b1c9da8bf5600         -mov ebx, dword ptr [ebx*4 + 0x56bfa8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5685160) /* 0x56bfa8 */ + cpu.ebx * 4);
    // 004959ff  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00495a01  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00495a03  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00495a05  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495a07  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495a09  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 00495a0f  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 00495a12  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00495a18  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 00495a1b  8b0dd4af4d00           -mov ecx, dword ptr [0x4dafd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */);
    // 00495a21  8b0485e0ba5600         -mov eax, dword ptr [eax*4 + 0x56bae0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5683936) /* 0x56bae0 */ + cpu.eax * 4);
    // 00495a28  8b3cbd40b15600         -mov edi, dword ptr [edi*4 + 0x56b140]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5681472) /* 0x56b140 */ + cpu.edi * 4);
    // 00495a2f  8b1c9dc8b65600         -mov ebx, dword ptr [ebx*4 + 0x56b6c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5682888) /* 0x56b6c8 */ + cpu.ebx * 4);
    // 00495a36  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00495a38  01d8                   +add eax, ebx
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
    // 00495a3a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495a3b  890dd4af4d00           -mov dword ptr [0x4dafd4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */) = cpu.ecx;
    // 00495a41  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00495a44  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00495a47  0f854affffff           -jne 0x495997
    if (!cpu.flags.zf)
    {
        goto L_0x00495997;
    }
    // 00495a4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495a52(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495a52);
    // 00495a52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495a53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495a54  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495a56  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00495a58  890dd4af4d00           -mov dword ptr [0x4dafd4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */) = cpu.ecx;
    // 00495a5e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00495a5f:
    // 00495a5f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00495a61  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00495a63  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495a65  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495a68  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 00495a6a  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495a6d  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 00495a72  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495a74  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495a76  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00495a78  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 00495a7b  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00495a7d  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 00495a80  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495a86  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 00495a89  8b1495a8c35600         -mov edx, dword ptr [edx*4 + 0x56c3a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5686184) /* 0x56c3a8 */ + cpu.edx * 4);
    // 00495a90  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495a96  8b0c8da8c15600         -mov ecx, dword ptr [ecx*4 + 0x56c1a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5685672) /* 0x56c1a8 */ + cpu.ecx * 4);
    // 00495a9d  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495a9f  8b0485a8bf5600         -mov eax, dword ptr [eax*4 + 0x56bfa8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5685160) /* 0x56bfa8 */ + cpu.eax * 4);
    // 00495aa6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495aa8  8b2cada8bf5600         -mov ebp, dword ptr [ebp*4 + 0x56bfa8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5685160) /* 0x56bfa8 */ + cpu.ebp * 4);
    // 00495aaf  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495ab1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495ab3  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 00495ab6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ab8  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 00495abb  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00495ac0  8b1495e0ba5600         -mov edx, dword ptr [edx*4 + 0x56bae0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5683936) /* 0x56bae0 */ + cpu.edx * 4);
    // 00495ac7  81e1ff010000           -and ecx, 0x1ff
    cpu.ecx &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00495acd  8b048540b15600         -mov eax, dword ptr [eax*4 + 0x56b140]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681472) /* 0x56b140 */ + cpu.eax * 4);
    // 00495ad4  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00495ad7  8b0c8dc8b65600         -mov ecx, dword ptr [ecx*4 + 0x56b6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5682888) /* 0x56b6c8 */ + cpu.ecx * 4);
    // 00495ade  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495ae0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495ae2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00495ae4  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 00495ae7  8943f8                 -mov dword ptr [ebx - 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00495aea  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00495aec  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00495af2  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00495af5  8b1495e0ba5600         -mov edx, dword ptr [edx*4 + 0x56bae0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5683936) /* 0x56bae0 */ + cpu.edx * 4);
    // 00495afc  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00495b01  8b2cad40b15600         -mov ebp, dword ptr [ebp*4 + 0x56b140]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5681472) /* 0x56b140 */ + cpu.ebp * 4);
    // 00495b08  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00495b0a  8b0dd4af4d00           -mov ecx, dword ptr [0x4dafd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */);
    // 00495b10  8b0485c8b65600         -mov eax, dword ptr [eax*4 + 0x56b6c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5682888) /* 0x56b6c8 */ + cpu.eax * 4);
    // 00495b17  01d0                   +add eax, edx
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
    // 00495b19  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495b1a  890dd4af4d00           -mov dword ptr [0x4dafd4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */) = cpu.ecx;
    // 00495b20  90                     -nop 
    ;
    // 00495b21  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00495b24  0f8535ffffff           -jne 0x495a5f
    if (!cpu.flags.zf)
    {
        goto L_0x00495a5f;
    }
    // 00495b2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b2d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495b2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495b2e);
    // 00495b2e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495b2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495b30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495b31  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00495b32:
    // 00495b32  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00495b34  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495b37  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00495b39  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00495b3b  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00495b3e  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 00495b44  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 00495b47  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 00495b4d  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 00495b53  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495b55  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00495b57  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495b5a  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00495b5c  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00495b5f  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 00495b61  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 00495b67  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00495b69  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 00495b6f  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 00495b72  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495b74  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 00495b7a  897afc                 -mov dword ptr [edx - 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00495b7d  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00495b7f  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495b80  8972f8                 -mov dword ptr [edx - 8], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 00495b83  75ad                   -jne 0x495b32
    if (!cpu.flags.zf)
    {
        goto L_0x00495b32;
    }
    // 00495b85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495b8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495b8a);
    // 00495b8a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495b8b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495b8c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495b8d  890dd4af4d00           -mov dword ptr [0x4dafd4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */) = cpu.ecx;
    // 00495b93  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00495b95  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00495b97  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00495b99  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495b9c  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 00495b9e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495ba1  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 00495ba7  893dd8af4d00           -mov dword ptr [0x4dafd8], edi
    app->getMemory<x86::reg32>(x86::reg32(5091288) /* 0x4dafd8 */) = cpu.edi;
L_0x00495bad:
    // 00495bad  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00495baf  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00495bb1  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00495bb3  8b35d8af4d00           -mov esi, dword ptr [0x4dafd8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091288) /* 0x4dafd8 */);
    // 00495bb9  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 00495bbb  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00495bbe  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 00495bc4  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00495bc6  893dd8af4d00           -mov dword ptr [0x4dafd8], edi
    app->getMemory<x86::reg32>(x86::reg32(5091288) /* 0x4dafd8 */) = cpu.edi;
    // 00495bcc  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00495bce  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00495bd1  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 00495bd7  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 00495bda  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 00495be0  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 00495be6  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495be8  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00495bea  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495bed  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00495bef  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495bf2  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 00495bf4  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 00495bfa  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00495bfc  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 00495c02  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 00495c05  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495c07  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 00495c0d  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00495c10  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00495c12  8b0dd4af4d00           -mov ecx, dword ptr [0x4dafd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */);
    // 00495c18  8973f8                 -mov dword ptr [ebx - 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 00495c1b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495c1c  890dd4af4d00           -mov dword ptr [0x4dafd4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091284) /* 0x4dafd4 */) = cpu.ecx;
    // 00495c22  7589                   -jne 0x495bad
    if (!cpu.flags.zf)
    {
        goto L_0x00495bad;
    }
    // 00495c24  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c25  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c26  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495c28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495c28);
    // 00495c28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495c29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495c2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495c2b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495c2c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495c2e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00495c30  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495c32  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495c34  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495c36  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495c38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00495c3a:
    // 00495c3a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00495c3c  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00495c3f  8a4e02                 -mov cl, byte ptr [esi + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00495c42  8a5603                 -mov dl, byte ptr [esi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00495c45  8a80dcaf4d00           -mov al, byte ptr [eax + 0x4dafdc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5091292) /* 0x4dafdc */);
    // 00495c4b  8a9bdcaf4d00           -mov bl, byte ptr [ebx + 0x4dafdc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5091292) /* 0x4dafdc */);
    // 00495c51  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00495c54  8a89dcaf4d00           -mov cl, byte ptr [ecx + 0x4dafdc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5091292) /* 0x4dafdc */);
    // 00495c5a  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00495c5d  8a92dcaf4d00           -mov dl, byte ptr [edx + 0x4dafdc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5091292) /* 0x4dafdc */);
    // 00495c63  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495c65  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00495c67  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00495c6a  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00495c6d  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495c6f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495c71  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00495c73  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495c75  8a4efc                 -mov cl, byte ptr [esi - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00495c78  8a56fd                 -mov dl, byte ptr [esi - 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */);
    // 00495c7b  8a46fe                 -mov al, byte ptr [esi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 00495c7e  8a5eff                 -mov bl, byte ptr [esi - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00495c81  8a89dcaf4d00           -mov cl, byte ptr [ecx + 0x4dafdc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5091292) /* 0x4dafdc */);
    // 00495c87  8a92dcaf4d00           -mov dl, byte ptr [edx + 0x4dafdc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5091292) /* 0x4dafdc */);
    // 00495c8d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00495c90  8a80dcaf4d00           -mov al, byte ptr [eax + 0x4dafdc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5091292) /* 0x4dafdc */);
    // 00495c96  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00495c99  8a9bdcaf4d00           -mov bl, byte ptr [ebx + 0x4dafdc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5091292) /* 0x4dafdc */);
    // 00495c9f  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00495ca1  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495ca3  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00495ca6  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00495ca9  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00495cab  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495cad  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00495cb0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495cb2  83ed02                 +sub ebp, 2
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
    // 00495cb5  7f83                   -jg 0x495c3a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495c3a;
    }
    // 00495cb7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495cb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495cb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495cba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495cbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495cbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495cbc);
    // 00495cbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495cbd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495cbe  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495cc1  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00495cc5  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00495cc7  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00495ccb  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00495cce  b822c94d00             -mov eax, 0x4dc922
    cpu.eax = 5097762 /*0x4dc922*/;
    // 00495cd3  e89c3b0100             -call 0x4a9874
    cpu.esp -= 4;
    sub_4a9874(app, cpu);
    if (cpu.terminate) return;
    // 00495cd8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495cdb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495cdc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495cdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_495ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495ce0);
    // 00495ce0  e95a380100             -jmp 0x4a953f
    return sub_4a953f(app, cpu);
}

/* align: skip  */
void Application::sub_495ce5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495ce5);
    // 00495ce5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495ce7  e8b51a0000             -call 0x4977a1
    cpu.esp -= 4;
    sub_4977a1(app, cpu);
    if (cpu.terminate) return;
    // 00495cec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00495cee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00495cf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495cf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495cf2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00495cf4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495cf5  ff1514155600           -call dword ptr [0x561514]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641492) /* 0x561514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495cfb  ff1530155600           -call dword ptr [0x561530]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641520) /* 0x561530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495d01  a320cf5600             -mov dword ptr [0x56cf20], eax
    app->getMemory<x86::reg32>(x86::reg32(5689120) /* 0x56cf20 */) = cpu.eax;
    // 00495d06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495d08  7419                   -je 0x495d23
    if (cpu.flags.zf)
    {
        goto L_0x00495d23;
    }
    // 00495d0a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00495d0c  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00495d0f  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495d12  891d24cf5600           -mov dword ptr [0x56cf24], ebx
    app->getMemory<x86::reg32>(x86::reg32(5689124) /* 0x56cf24 */) = cpu.ebx;
    // 00495d18  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00495d1b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00495d20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495d23:
    // 00495d23  a324cf5600             -mov dword ptr [0x56cf24], eax
    app->getMemory<x86::reg32>(x86::reg32(5689124) /* 0x56cf24 */) = cpu.eax;
    // 00495d28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495cf0);
    goto L_entry_0x00495cf0;
    // 00495ce5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495ce7  e8b51a0000             -call 0x4977a1
    cpu.esp -= 4;
    sub_4977a1(app, cpu);
    if (cpu.terminate) return;
    // 00495cec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00495cee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x00495cf0:
    // 00495cf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495cf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495cf2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00495cf4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495cf5  ff1514155600           -call dword ptr [0x561514]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641492) /* 0x561514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495cfb  ff1530155600           -call dword ptr [0x561530]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641520) /* 0x561530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495d01  a320cf5600             -mov dword ptr [0x56cf20], eax
    app->getMemory<x86::reg32>(x86::reg32(5689120) /* 0x56cf20 */) = cpu.eax;
    // 00495d06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495d08  7419                   -je 0x495d23
    if (cpu.flags.zf)
    {
        goto L_0x00495d23;
    }
    // 00495d0a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00495d0c  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00495d0f  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495d12  891d24cf5600           -mov dword ptr [0x56cf24], ebx
    app->getMemory<x86::reg32>(x86::reg32(5689124) /* 0x56cf24 */) = cpu.ebx;
    // 00495d18  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00495d1b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00495d20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495d23:
    // 00495d23  a324cf5600             -mov dword ptr [0x56cf24], eax
    app->getMemory<x86::reg32>(x86::reg32(5689124) /* 0x56cf24 */) = cpu.eax;
    // 00495d28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495d2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495d2c);
    // 00495d2c  833d24cf560000         +cmp dword ptr [0x56cf24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689124) /* 0x56cf24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d33  0f84c3020000           -je 0x495ffc
    if (cpu.flags.zf)
    {
        return sub_495ffc(app, cpu);
    }
    // 00495d39  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495d3a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495d3b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495d3c  8b0d20cf5600           -mov ecx, dword ptr [0x56cf20]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5689120) /* 0x56cf20 */);
    // 00495d42  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495d43  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495d45  ff15ec145600           -call dword ptr [0x5614ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641452) /* 0x5614ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495d4b  891d20cf5600           -mov dword ptr [0x56cf20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5689120) /* 0x56cf20 */) = cpu.ebx;
    // 00495d51  891d24cf5600           -mov dword ptr [0x56cf24], ebx
    app->getMemory<x86::reg32>(x86::reg32(5689124) /* 0x56cf24 */) = cpu.ebx;
    // 00495d57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d59  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495d5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495d5c);
    // 00495d5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495d5d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495d5e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d5f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00495d61  833d20cf560000         +cmp dword ptr [0x56cf20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689120) /* 0x56cf20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d68  7533                   -jne 0x495d9d
    if (!cpu.flags.zf)
    {
        goto L_0x00495d9d;
    }
L_0x00495d6a:
    // 00495d6a  833d0c1b560000         +cmp dword ptr [0x561b0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643020) /* 0x561b0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d71  740a                   -je 0x495d7d
    if (cpu.flags.zf)
    {
        goto L_0x00495d7d;
    }
    // 00495d73  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 00495d78  e81f6fffff             -call 0x48cc9c
    cpu.esp -= 4;
    sub_48cc9c(app, cpu);
    if (cpu.terminate) return;
L_0x00495d7d:
    // 00495d7d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00495d7f  7413                   -je 0x495d94
    if (cpu.flags.zf)
    {
        goto L_0x00495d94;
    }
    // 00495d81  8a631e                 -mov ah, byte ptr [ebx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00495d84  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00495d86  7405                   -je 0x495d8d
    if (cpu.flags.zf)
    {
        goto L_0x00495d8d;
    }
    // 00495d88  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495d8b  7517                   -jne 0x495da4
    if (!cpu.flags.zf)
    {
        goto L_0x00495da4;
    }
L_0x00495d8d:
    // 00495d8d  8b7334                 -mov esi, dword ptr [ebx + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 00495d90  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495d92  751f                   -jne 0x495db3
    if (!cpu.flags.zf)
    {
        goto L_0x00495db3;
    }
L_0x00495d94:
    // 00495d94  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00495d99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495d9d:
    // 00495d9d  e88affffff             -call 0x495d2c
    cpu.esp -= 4;
    sub_495d2c(app, cpu);
    if (cpu.terminate) return;
    // 00495da2  ebc6                   -jmp 0x495d6a
    goto L_0x00495d6a;
L_0x00495da4:
    // 00495da4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495da6  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00495da8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495daa  e841ffffff             -call 0x495cf0
    cpu.esp -= 4;
    sub_495cf0(app, cpu);
    if (cpu.terminate) return;
    // 00495daf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495db0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495db1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495db2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495db3:
    // 00495db3  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 00495db8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00495dba  e8896dffff             -call 0x48cb48
    cpu.esp -= 4;
    sub_48cb48(app, cpu);
    if (cpu.terminate) return;
    // 00495dbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dc0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dc1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dc2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495dc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495dc4);
    // 00495dc4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495dc5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495dc6  ff151c155600           -call dword ptr [0x56151c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641500) /* 0x56151c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495dcc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495dd0);
    // 00495dd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495dd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495dd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495dd3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495dd4  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00495dd7  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00495ddb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00495ddd  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00495ddf  3dff000000             +cmp eax, 0xff
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
    // 00495de4  740c                   -je 0x495df2
    if (cpu.flags.zf)
    {
        goto L_0x00495df2;
    }
    // 00495de6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495de8  7545                   -jne 0x495e2f
    if (!cpu.flags.zf)
    {
        goto L_0x00495e2f;
    }
L_0x00495dea:
    // 00495dea  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495ded  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495def  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495df0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495df1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495df2:
    // 00495df2  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00495df6  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00495dfa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495dfb  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00495dff  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00495e03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495e04  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00495e08  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495e0a  e80173ffff             -call 0x48d110
    cpu.esp -= 4;
    sub_48d110(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495e10  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00495e14  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00495e18  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495e19  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00495e1d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00495e21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495e22  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00495e26  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495e28  e8a3250100             -call 0x4a83d0
    cpu.esp -= 4;
    sub_4a83d0(app, cpu);
    if (cpu.terminate) return;
    // 00495e2d  ebbb                   -jmp 0x495dea
    goto L_0x00495dea;
L_0x00495e2f:
    // 00495e2f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495e30  ff1514155600           -call dword ptr [0x561514]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641492) /* 0x561514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495e36  ff1530155600           -call dword ptr [0x561530]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641520) /* 0x561530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495e3c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00495e3e  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00495e41  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495e44  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495e45  895328                 -mov dword ptr [ebx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00495e48  ff15ec145600           -call dword ptr [0x5614ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641452) /* 0x5614ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495e4e  c703444e4957           -mov dword ptr [ebx], 0x57494e44
    app->getMemory<x86::reg32>(cpu.ebx) = 1464421956 /*0x57494e44*/;
    // 00495e54  a198894d00             -mov eax, dword ptr [0x4d8998]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */);
    // 00495e59  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00495e60  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00495e63  a19c894d00             -mov eax, dword ptr [0x4d899c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */);
    // 00495e68  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00495e6b  a198894d00             -mov eax, dword ptr [0x4d8998]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */);
    // 00495e70  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00495e73  a19c894d00             -mov eax, dword ptr [0x4d899c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */);
    // 00495e78  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00495e7b  a0a0894d00             -mov al, byte ptr [0x4d89a0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 00495e80  88431c                 -mov byte ptr [ebx + 0x1c], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.al;
    // 00495e83  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00495e87  88431e                 -mov byte ptr [ebx + 0x1e], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.al;
    // 00495e8a  a1a0894d00             -mov eax, dword ptr [0x4d89a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 00495e8f  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00495e96  e8a5280100             -call 0x4a8740
    cpu.esp -= 4;
    sub_4a8740(app, cpu);
    if (cpu.terminate) return;
    // 00495e9b  88431d                 -mov byte ptr [ebx + 0x1d], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 00495e9e  8b0d9c894d00           -mov ecx, dword ptr [0x4d899c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */);
    // 00495ea4  8b5328                 -mov edx, dword ptr [ebx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00495ea7  897b34                 -mov dword ptr [ebx + 0x34], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 00495eaa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495eac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495eae  e801020000             -call 0x4960b4
    cpu.esp -= 4;
    sub_4960b4(app, cpu);
    if (cpu.terminate) return;
    // 00495eb3  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00495eb8  8b0d98894d00           -mov ecx, dword ptr [0x4d8998]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */);
    // 00495ebe  8b15a0894d00           -mov edx, dword ptr [0x4d89a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 00495ec4  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00495ec7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495ec9  e8e6010000             -call 0x4960b4
    cpu.esp -= 4;
    sub_4960b4(app, cpu);
    if (cpu.terminate) return;
    // 00495ece  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00495ed1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00495ed4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ed5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ed6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ed7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ed8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_495ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495ee0);
    // 00495ee0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495ee2  7505                   -jne 0x495ee9
    if (!cpu.flags.zf)
    {
        goto L_0x00495ee9;
    }
    // 00495ee4  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
L_0x00495ee9:
    // 00495ee9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495eeb  7505                   -jne 0x495ef2
    if (!cpu.flags.zf)
    {
        goto L_0x00495ef2;
    }
    // 00495eed  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
L_0x00495ef2:
    // 00495ef2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00495ef4  7505                   -jne 0x495efb
    if (!cpu.flags.zf)
    {
        goto L_0x00495efb;
    }
    // 00495ef6  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x00495efb:
    // 00495efb  891da0894d00           -mov dword ptr [0x4d89a0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */) = cpu.ebx;
    // 00495f01  8b1db0894d00           -mov ebx, dword ptr [0x4d89b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081520) /* 0x4d89b0 */);
    // 00495f07  a398894d00             -mov dword ptr [0x4d8998], eax
    app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */) = cpu.eax;
    // 00495f0c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495f0e  a3b8894d00             -mov dword ptr [0x4d89b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5081528) /* 0x4d89b8 */) = cpu.eax;
    // 00495f13  a1b4894d00             -mov eax, dword ptr [0x4d89b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081524) /* 0x4d89b4 */);
    // 00495f18  89159c894d00           -mov dword ptr [0x4d899c], edx
    app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */) = cpu.edx;
    // 00495f1e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00495f20  8915bc894d00           -mov dword ptr [0x4d89bc], edx
    app->getMemory<x86::reg32>(x86::reg32(5081532) /* 0x4d89bc */) = cpu.edx;
    // 00495f26  833d78894d0000         +cmp dword ptr [0x4d8978], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495f2d  0f84fd000000           -je 0x496030
    if (cpu.flags.zf)
    {
        return sub_496030(app, cpu);
    }
    // 00495f33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495f34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495f34);
    // 00495f34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495f35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495f36  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495f37  ff1530155600           -call dword ptr [0x561530]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641520) /* 0x561530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495f3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495f3f  a320cf5600             -mov dword ptr [0x56cf20], eax
    app->getMemory<x86::reg32>(x86::reg32(5689120) /* 0x56cf20 */) = cpu.eax;
    // 00495f44  891524cf5600           -mov dword ptr [0x56cf24], edx
    app->getMemory<x86::reg32>(x86::reg32(5689124) /* 0x56cf24 */) = cpu.edx;
    // 00495f4a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00495f4c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495f4f  a384904d00             -mov dword ptr [0x4d9084], eax
    app->getMemory<x86::reg32>(x86::reg32(5083268) /* 0x4d9084 */) = cpu.eax;
    // 00495f54  a198894d00             -mov eax, dword ptr [0x4d8998]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */);
    // 00495f59  a360904d00             -mov dword ptr [0x4d9060], eax
    app->getMemory<x86::reg32>(x86::reg32(5083232) /* 0x4d9060 */) = cpu.eax;
    // 00495f5e  a19c894d00             -mov eax, dword ptr [0x4d899c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */);
    // 00495f63  b9444e4957             -mov ecx, 0x57494e44
    cpu.ecx = 1464421956 /*0x57494e44*/;
    // 00495f68  a364904d00             -mov dword ptr [0x4d9064], eax
    app->getMemory<x86::reg32>(x86::reg32(5083236) /* 0x4d9064 */) = cpu.eax;
    // 00495f6d  a198894d00             -mov eax, dword ptr [0x4d8998]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */);
    // 00495f72  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495f74  a370904d00             -mov dword ptr [0x4d9070], eax
    app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */) = cpu.eax;
    // 00495f79  a19c894d00             -mov eax, dword ptr [0x4d899c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */);
    // 00495f7e  890d5c904d00           -mov dword ptr [0x4d905c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083228) /* 0x4d905c */) = cpu.ecx;
    // 00495f84  a374904d00             -mov dword ptr [0x4d9074], eax
    app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */) = cpu.eax;
    // 00495f89  a0a0894d00             -mov al, byte ptr [0x4d89a0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 00495f8e  891d68904d00           -mov dword ptr [0x4d9068], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */) = cpu.ebx;
    // 00495f94  a278904d00             -mov byte ptr [0x4d9078], al
    app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */) = cpu.al;
    // 00495f99  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 00495f9b  891d6c904d00           -mov dword ptr [0x4d906c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */) = cpu.ebx;
    // 00495fa1  88257a904d00           -mov byte ptr [0x4d907a], ah
    app->getMemory<x86::reg8>(x86::reg32(5083258) /* 0x4d907a */) = cpu.ah;
    // 00495fa7  a1a0894d00             -mov eax, dword ptr [0x4d89a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 00495fac  89157c904d00           -mov dword ptr [0x4d907c], edx
    app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */) = cpu.edx;
    // 00495fb2  e889270100             -call 0x4a8740
    cpu.esp -= 4;
    sub_4a8740(app, cpu);
    if (cpu.terminate) return;
    // 00495fb7  8b0d9c894d00           -mov ecx, dword ptr [0x4d899c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */);
    // 00495fbd  8b1584904d00           -mov edx, dword ptr [0x4d9084]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083268) /* 0x4d9084 */);
    // 00495fc3  a279904d00             -mov byte ptr [0x4d9079], al
    app->getMemory<x86::reg8>(x86::reg32(5083257) /* 0x4d9079 */) = cpu.al;
    // 00495fc8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495fca  891d90904d00           -mov dword ptr [0x4d9090], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083280) /* 0x4d9090 */) = cpu.ebx;
    // 00495fd0  e8df000000             -call 0x4960b4
    cpu.esp -= 4;
    sub_4960b4(app, cpu);
    if (cpu.terminate) return;
    // 00495fd5  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00495fda  8b0d98894d00           -mov ecx, dword ptr [0x4d8998]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */);
    // 00495fe0  8b15a0894d00           -mov edx, dword ptr [0x4d89a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 00495fe6  a388904d00             -mov dword ptr [0x4d9088], eax
    app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */) = cpu.eax;
    // 00495feb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495fed  e8c2000000             -call 0x4960b4
    cpu.esp -= 4;
    sub_4960b4(app, cpu);
    if (cpu.terminate) return;
    // 00495ff2  a38c904d00             -mov dword ptr [0x4d908c], eax
    app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */) = cpu.eax;
    // 00495ff7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ff8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ff9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ffa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495ffc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495ffc);
    // 00495ffc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495ffd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495ffe  8b1520cf5600           -mov edx, dword ptr [0x56cf20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5689120) /* 0x56cf20 */);
    // 00496004  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496005  ff15ec145600           -call dword ptr [0x5614ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641452) /* 0x5614ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049600b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049600d  a188904d00             -mov eax, dword ptr [0x4d9088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 00496012  890d20cf5600           -mov dword ptr [0x56cf20], ecx
    app->getMemory<x86::reg32>(x86::reg32(5689120) /* 0x56cf20 */) = cpu.ecx;
    // 00496018  e86f010000             -call 0x49618c
    cpu.esp -= 4;
    sub_49618c(app, cpu);
    if (cpu.terminate) return;
    // 0049601d  a18c904d00             -mov eax, dword ptr [0x4d908c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 00496022  e865010000             -call 0x49618c
    cpu.esp -= 4;
    sub_49618c(app, cpu);
    if (cpu.terminate) return;
    // 00496027  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496028  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496029  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_496030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00496030);
    // 00496030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496031  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496032  833d60b04d0000         +cmp dword ptr [0x4db060], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496039  742c                   -je 0x496067
    if (cpu.flags.zf)
    {
        goto L_0x00496067;
    }
L_0x0049603b:
    // 0049603b  8b155cb04d00           -mov edx, dword ptr [0x4db05c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091420) /* 0x4db05c */);
    // 00496041  a160b04d00             -mov eax, dword ptr [0x4db060]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */);
    // 00496046  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00496049  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0049604c  8b155cb04d00           -mov edx, dword ptr [0x4db05c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091420) /* 0x4db05c */);
    // 00496052  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00496059  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049605c  891d28cf5600           -mov dword ptr [0x56cf28], ebx
    app->getMemory<x86::reg32>(x86::reg32(5689128) /* 0x56cf28 */) = cpu.ebx;
    // 00496062  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00496064  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496065  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496066  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496067:
    // 00496067  b8c8eb4c00             -mov eax, 0x4cebc8
    cpu.eax = 5041096 /*0x4cebc8*/;
    // 0049606c  8b155cb04d00           -mov edx, dword ptr [0x4db05c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091420) /* 0x4db05c */);
    // 00496072  8b1d048a4d00           -mov ebx, dword ptr [0x4d8a04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 00496078  c1e202                 +shl edx, 2
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
    // 0049607b  e888c8feff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 00496080  a360b04d00             -mov dword ptr [0x4db060], eax
    app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */) = cpu.eax;
    // 00496085  ebb4                   -jmp 0x49603b
    goto L_0x0049603b;
}

/* align: skip 0x90 */
void Application::sub_496088(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00496088);
    // 00496088  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496089  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049608a  8b1560b04d00           -mov edx, dword ptr [0x4db060]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */);
    // 00496090  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496092  750b                   -jne 0x49609f
    if (!cpu.flags.zf)
    {
        goto L_0x0049609f;
    }
    // 00496094  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496096  890d60b04d00           -mov dword ptr [0x4db060], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */) = cpu.ecx;
    // 0049609c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049609d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049609e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049609f:
    // 0049609f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004960a1  e8c6ccfeff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004960a6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004960a8  890d60b04d00           -mov dword ptr [0x4db060], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */) = cpu.ecx;
    // 004960ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004960af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004960b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4960b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004960b4);
    // 004960b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004960b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004960b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004960b7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004960ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004960bc  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004960bf  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004960c3  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004960c5  a160b04d00             -mov eax, dword ptr [0x4db060]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */);
    // 004960ca  8b1528cf5600           -mov edx, dword ptr [0x56cf28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5689128) /* 0x56cf28 */);
    // 004960d0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004960d2  39d0                   +cmp eax, edx
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
    // 004960d4  7335                   -jae 0x49610b
    if (!cpu.flags.cf)
    {
        goto L_0x0049610b;
    }
    // 004960d6  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004960da  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004960dd  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004960df  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004960e1:
    // 004960e1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004960e3  39f9                   +cmp ecx, edi
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
    // 004960e5  7c14                   -jl 0x4960fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004960fb;
    }
    // 004960e7  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004960eb  0f8674000000           -jbe 0x496165
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496165;
    }
    // 004960f1  3b7008                 +cmp esi, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004960f4  7505                   -jne 0x4960fb
    if (!cpu.flags.zf)
    {
        goto L_0x004960fb;
    }
    // 004960f6  3b500c                 +cmp edx, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004960f9  745e                   -je 0x496159
    if (cpu.flags.zf)
    {
        goto L_0x00496159;
    }
L_0x004960fb:
    // 004960fb  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004960fe  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496101  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00496103  3b0528cf5600           +cmp eax, dword ptr [0x56cf28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5689128) /* 0x56cf28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496109  72d6                   -jb 0x4960e1
    if (cpu.flags.cf)
    {
        goto L_0x004960e1;
    }
L_0x0049610b:
    // 0049610b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049610d  0f846f000000           -je 0x496182
    if (cpu.flags.zf)
    {
        goto L_0x00496182;
    }
    // 00496113  8d5708                 -lea edx, [edi + 8]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00496116  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00496118  39d0                   +cmp eax, edx
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
    // 0049611a  7d51                   -jge 0x49616d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049616d;
    }
    // 0049611c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0049611e:
    // 0049611e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496121  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00496124  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496126  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 0049612c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049612f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00496131  7e1d                   -jle 0x496150
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496150;
    }
    // 00496133  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00496135:
    // 00496135  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496139  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049613b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049613e  40                     -inc eax
    (cpu.eax)++;
    // 0049613f  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 00496141  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496144  896afc                 -mov dword ptr [edx - 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00496147  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00496149  39f8                   +cmp eax, edi
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
    // 0049614b  7ce8                   -jl 0x496135
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496135;
    }
    // 0049614d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00496150:
    // 00496150  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00496152:
    // 00496152  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496155  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496156  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496157  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496158  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496159:
    // 00496159  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049615c  83c008                 +add eax, 8
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
    // 0049615f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00496160  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00496163  ebed                   -jmp 0x496152
    goto L_0x00496152;
L_0x00496165:
    // 00496165  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496167  7592                   -jne 0x4960fb
    if (!cpu.flags.zf)
    {
        goto L_0x004960fb;
    }
    // 00496169  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049616b  eb8e                   -jmp 0x4960fb
    goto L_0x004960fb;
L_0x0049616d:
    // 0049616d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049616f  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00496171  c744bb0c00000000       -mov dword ptr [ebx + edi*4 + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.edi * 4) = 0 /*0x0*/;
    // 00496179  83ea02                 +sub edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049617c  8954bb08               -mov dword ptr [ebx + edi*4 + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edi * 4) = cpu.edx;
    // 00496180  eb9c                   -jmp 0x49611e
    goto L_0x0049611e;
L_0x00496182:
    // 00496182  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496184  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496187  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496188  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496189  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049618a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49618c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049618c);
    // 0049618c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049618d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049618e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049618f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496190  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496191  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496193  8d48f8                 -lea ecx, [eax - 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00496196  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00496199  4a                     -dec edx
    (cpu.edx)--;
    // 0049619a  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049619d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049619f  7606                   -jbe 0x4961a7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004961a7;
    }
L_0x004961a1:
    // 004961a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004961a7:
    // 004961a7  a160b04d00             -mov eax, dword ptr [0x4db060]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */);
    // 004961ac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004961ae  39c8                   +cmp eax, ecx
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
    // 004961b0  7312                   -jae 0x4961c4
    if (!cpu.flags.cf)
    {
        goto L_0x004961c4;
    }
L_0x004961b2:
    // 004961b2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004961b4  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004961b7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004961ba  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004961bc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004961be  39c8                   +cmp eax, ecx
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
    // 004961c0  72f0                   -jb 0x4961b2
    if (cpu.flags.cf)
    {
        goto L_0x004961b2;
    }
    // 004961c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004961c4:
    // 004961c4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004961c6  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004961c9  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004961cc  8b3528cf5600           -mov esi, dword ptr [0x56cf28]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5689128) /* 0x56cf28 */);
    // 004961d2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004961d4  39f2                   +cmp edx, esi
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
    // 004961d6  7306                   -jae 0x4961de
    if (!cpu.flags.cf)
    {
        goto L_0x004961de;
    }
    // 004961d8  837a0400               +cmp dword ptr [edx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004961dc  761b                   -jbe 0x4961f9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004961f9;
    }
L_0x004961de:
    // 004961de  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004961e0  74bf                   -je 0x4961a1
    if (cpu.flags.zf)
    {
        goto L_0x004961a1;
    }
    // 004961e2  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 004961e6  77b9                   -ja 0x4961a1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004961a1;
    }
    // 004961e8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004961ea  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004961ec  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004961ef  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004961f1  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 004961f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004961f9:
    // 004961f9  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004961fb  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 004961fd  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00496200  01d5                   +add ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496202  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 00496204  ebd8                   -jmp 0x4961de
    goto L_0x004961de;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_496208(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00496208);
    // 00496208  a360b04d00             -mov dword ptr [0x4db060], eax
    app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */) = cpu.eax;
    // 0049620d  89155cb04d00           -mov dword ptr [0x4db05c], edx
    app->getMemory<x86::reg32>(x86::reg32(5091420) /* 0x4db05c */) = cpu.edx;
    // 00496213  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_496220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00496220);
    // 00496220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496223  8a1578904d00           -mov dl, byte ptr [0x4d9078]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 00496229  80fa0f                 +cmp dl, 0xf
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
    // 0049622c  0f8288000000           -jb 0x4962ba
    if (cpu.flags.cf)
    {
        goto L_0x004962ba;
    }
    // 00496232  7737                   -ja 0x49626b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049626b;
    }
    // 00496234  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 00496237  0f8475000000           -je 0x4962b2
    if (cpu.flags.zf)
    {
        goto L_0x004962b2;
    }
    // 0049623d  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
L_0x00496242:
    // 00496242  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00496244  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496246  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00496249  c1fb0a                 -sar ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (10 /*0xa*/ % 32));
    // 0049624c  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0049624f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496252  83e31f                 -and ebx, 0x1f
    cpu.ebx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496255  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496258  c1e313                 -shl ebx, 0x13
    cpu.ebx <<= 19 /*0x13*/ % 32;
    // 0049625b  c1e10b                 -shl ecx, 0xb
    cpu.ecx <<= 11 /*0xb*/ % 32;
    // 0049625e  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00496260  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496263  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496265  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x00496267:
    // 00496267  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496268  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496269  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049626a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049626b:
    // 0049626b  80fa18                 +cmp dl, 0x18
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049626e  7337                   -jae 0x4962a7
    if (!cpu.flags.cf)
    {
        goto L_0x004962a7;
    }
    // 00496270  80fa10                 +cmp dl, 0x10
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
    // 00496273  7545                   -jne 0x4962ba
    if (!cpu.flags.zf)
    {
        goto L_0x004962ba;
    }
    // 00496275  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496277  743d                   -je 0x4962b6
    if (cpu.flags.zf)
    {
        goto L_0x004962b6;
    }
    // 00496279  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
L_0x0049627e:
    // 0049627e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496280  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00496282  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00496285  c1f90b                 -sar ecx, 0xb
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (11 /*0xb*/ % 32));
    // 00496288  c1fb05                 -sar ebx, 5
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (5 /*0x5*/ % 32));
    // 0049628b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049628e  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496291  83e33f                 -and ebx, 0x3f
    cpu.ebx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00496294  c1e113                 -shl ecx, 0x13
    cpu.ecx <<= 19 /*0x13*/ % 32;
    // 00496297  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 0049629a  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049629c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049629f  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004962a1  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004962a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004962a7:
    // 004962a7  76be                   -jbe 0x496267
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496267;
    }
    // 004962a9  80fa20                 +cmp dl, 0x20
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
    // 004962ac  750c                   -jne 0x4962ba
    if (!cpu.flags.zf)
    {
        goto L_0x004962ba;
    }
    // 004962ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004962b2:
    // 004962b2  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004962b4  eb8c                   -jmp 0x496242
    goto L_0x00496242;
L_0x004962b6:
    // 004962b6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004962b8  ebc4                   -jmp 0x49627e
    goto L_0x0049627e;
L_0x004962ba:
    // 004962ba  8b0485a0ea5600         -mov eax, dword ptr [eax*4 + 0x56eaa0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696160) /* 0x56eaa0 */ + cpu.eax * 4);
    // 004962c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4962d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004962d0);
    // 004962d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004962d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004962d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004962d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004962d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004962d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004962d6  ba580a4e00             -mov edx, 0x4e0a58
    cpu.edx = 5114456 /*0x4e0a58*/;
    // 004962db  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004962dd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004962df:
    // 004962df  83bf70b04d0000         +cmp dword ptr [edi + 0x4db070], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5091440) /* 0x4db070 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004962e6  743a                   -je 0x496322
    if (cpu.flags.zf)
    {
        goto L_0x00496322;
    }
L_0x004962e8:
    // 004962e8  43                     -inc ebx
    (cpu.ebx)++;
    // 004962e9  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004962ec  83fb0a                 +cmp ebx, 0xa
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
    // 004962ef  7cee                   -jl 0x4962df
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004962df;
    }
    // 004962f1  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004962f4  2d580a4e00             -sub eax, 0x4e0a58
    (cpu.eax) -= x86::reg32(x86::sreg32(5114456 /*0x4e0a58*/));
    // 004962f9  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004962fc  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004962ff  a398b04d00             -mov dword ptr [0x4db098], eax
    app->getMemory<x86::reg32>(x86::reg32(5091480) /* 0x4db098 */) = cpu.eax;
    // 00496304  b84fcf5600             -mov eax, 0x56cf4f
    cpu.eax = 5689167 /*0x56cf4f*/;
    // 00496309  24e0                   -and al, 0xe0
    cpu.al &= x86::reg8(x86::sreg8(224 /*0xe0*/));
    // 0049630b  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00496311  a364b04d00             -mov dword ptr [0x4db064], eax
    app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */) = cpu.eax;
    // 00496316  e845460100             -call 0x4aa960
    cpu.esp -= 4;
    sub_4aa960(app, cpu);
    if (cpu.terminate) return;
    // 0049631b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049631c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049631d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049631e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049631f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496320  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496321  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496322:
    // 00496322  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00496328  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049632b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00496330  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496332  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00496334  2d580a4e00             -sub eax, 0x4e0a58
    (cpu.eax) -= x86::reg32(x86::sreg32(5114456 /*0x4e0a58*/));
    // 00496339  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049633b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0049633e  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00496341  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00496344  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00496347  898770b04d00           -mov dword ptr [edi + 0x4db070], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5091440) /* 0x4db070 */) = cpu.eax;
    // 0049634d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049634f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496351  7e95                   -jle 0x4962e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004962e8;
    }
    // 00496353  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
L_0x00496355:
    // 00496355  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00496357  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049635a  d3e5                   -shl ebp, cl
    cpu.ebp <<= cpu.cl % 32;
    // 0049635c  40                     -inc eax
    (cpu.eax)++;
    // 0049635d  896afc                 -mov dword ptr [edx - 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00496360  39f0                   +cmp eax, esi
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
    // 00496362  7d84                   -jge 0x4962e8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004962e8;
    }
    // 00496364  ebef                   -jmp 0x496355
    goto L_0x00496355;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_496368(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00496368);
    // 00496368  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496369  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049636a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049636b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049636c  8b2d58d95600           -mov ebp, dword ptr [0x56d958]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5691736) /* 0x56d958 */);
    // 00496372  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00496374  8b0d5cd95600           -mov ecx, dword ptr [0x56d95c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5691740) /* 0x56d95c */);
    // 0049637a  42                     -inc edx
    (cpu.edx)++;
    // 0049637b  39c8                   +cmp eax, ecx
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
    // 0049637d  751c                   -jne 0x49639b
    if (!cpu.flags.zf)
    {
        goto L_0x0049639b;
    }
    // 0049637f  39ea                   +cmp edx, ebp
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
    // 00496381  7e0d                   -jle 0x496390
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496390;
    }
    // 00496383  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00496385  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00496388  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049638a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049638c  39e8                   +cmp eax, ebp
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
    // 0049638e  7c26                   -jl 0x4963b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004963b6;
    }
L_0x00496390:
    // 00496390  892d58d95600           -mov dword ptr [0x56d958], ebp
    app->getMemory<x86::reg32>(x86::reg32(5691736) /* 0x56d958 */) = cpu.ebp;
    // 00496396  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496397  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496398  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496399  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049639a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049639b:
    // 0049639b  891d5cd95600           -mov dword ptr [0x56d95c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5691740) /* 0x56d95c */) = cpu.ebx;
    // 004963a1  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004963a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004963a5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004963a7  39e8                   +cmp eax, ebp
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
    // 004963a9  7c0b                   -jl 0x4963b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004963b6;
    }
    // 004963ab  892d58d95600           -mov dword ptr [0x56d958], ebp
    app->getMemory<x86::reg32>(x86::reg32(5691736) /* 0x56d958 */) = cpu.ebp;
    // 004963b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004963b6:
    // 004963b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004963b7  8b1598b04d00           -mov edx, dword ptr [0x4db098]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091480) /* 0x4db098 */);
    // 004963bd  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 004963c4  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004963c7  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004963c9  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004963cc  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004963ce  81c2580a4e00           -add edx, 0x4e0a58
    (cpu.edx) += x86::reg32(x86::sreg32(5114456 /*0x4e0a58*/));
    // 004963d4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004963d6  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004963d8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004963da  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004963dc  892d58d95600           -mov dword ptr [0x56d958], ebp
    app->getMemory<x86::reg32>(x86::reg32(5691736) /* 0x56d958 */) = cpu.ebp;
L_0x004963e2:
    // 004963e2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004963e4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004963e6  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004963e9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004963eb  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004963ee  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004963f0  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004963f3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004963f5  8d5b10                 -lea ebx, [ebx + 0x10]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004963f8  83e904                 +sub ecx, 4
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
    // 004963fb  7fe5                   -jg 0x4963e2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004963e2;
    }
    // 004963fd  8b2d58d95600           -mov ebp, dword ptr [0x56d958]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5691736) /* 0x56d958 */);
    // 00496403  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496404  892d58d95600           -mov dword ptr [0x56d958], ebp
    app->getMemory<x86::reg32>(x86::reg32(5691736) /* 0x56d958 */) = cpu.ebp;
    // 0049640a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049640b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049640c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049640d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049640e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_496410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00496410);
    // 00496410  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496411  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496412  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496413  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496416  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00496418  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049641a  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049641e  a17c904d00             -mov eax, dword ptr [0x4d907c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */);
    // 00496423  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00496425  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00496428  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049642b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049642d  8b0d84904d00           -mov ecx, dword ptr [0x4d9084]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083268) /* 0x4d9084 */);
    // 00496433  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496435  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00496437  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00496439  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0049643f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496441  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00496444  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496446  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496449  0310                   -add edx, dword ptr [eax]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 0049644b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049644d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049644f  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 00496455  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00496457  8a2578904d00           -mov ah, byte ptr [0x4d9078]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 0049645d  83ee10                 -sub esi, 0x10
    (cpu.esi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496460  80fc10                 +cmp ah, 0x10
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
    // 00496463  7733                   -ja 0x496498
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00496498;
    }
    // 00496465  80fc08                 +cmp ah, 8
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
    // 00496468  7602                   -jbe 0x49646c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049646c;
    }
    // 0049646a  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
L_0x0049646c:
    // 0049646c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049646e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496472  e839450100             -call 0x4aa9b0
    cpu.esp -= 4;
    sub_4aa9b0(app, cpu);
    if (cpu.terminate) return;
    // 00496477  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496478  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496479  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 0049647e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049647f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00496481  8b0d400a4e00           -mov ecx, dword ptr [0x4e0a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 00496487  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496488  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049648a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049648c  e85f470100             -call 0x4aabf0
    cpu.esp -= 4;
    sub_4aabf0(app, cpu);
    if (cpu.terminate) return;
    // 00496491  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496494  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496495  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496496  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496497  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496498:
    // 00496498  c1fa02                 +sar edx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0049649b  ebcf                   -jmp 0x49646c
    goto L_0x0049646c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4964a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004964a0);
    // 004964a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004964a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004964a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004964a3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004964a6  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004964aa  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004964ac  8d1ccd00000000         -lea ebx, [ecx*8]
    cpu.ebx = x86::reg32(cpu.ecx * 8);
    // 004964b3  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004964b6  8d1ced00000000         -lea ebx, [ebp*8]
    cpu.ebx = x86::reg32(cpu.ebp * 8);
    // 004964bd  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004964c1  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004964c4  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004964c8  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004964cb  3b5f04                 +cmp ebx, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004964ce  7e06                   -jle 0x4964d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004964d6;
    }
    // 004964d0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004964d2  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004964d4  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x004964d6:
    // 004964d6  c1e503                 -shl ebp, 3
    cpu.ebp <<= 3 /*0x3*/ % 32;
    // 004964d9  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004964dc  8d3c2a                 -lea edi, [edx + ebp]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 004964df  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004964e1  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004964e5  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004964e8  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004964eb  29d9                   +sub ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004964ed  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004964f0  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004964f3  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004964f6  7509                   -jne 0x496501
    if (!cpu.flags.zf)
    {
        goto L_0x00496501;
    }
    // 004964f8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004964fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964fe  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00496501:
    // 00496501  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00496503  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00496506  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00496509  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049650b  2b1a                   -sub ebx, dword ptr [edx]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049650d  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00496510  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00496514  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00496518  d80c8d90445b00         -fmul dword ptr [ecx*4 + 0x5b4490]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5981328) /* 0x5b4490 */ + cpu.ecx * 4));
    // 0049651f  d9056cb04d00           -fld dword ptr [0x4db06c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5091436) /* 0x4db06c */)));
    // 00496525  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00496527  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00496529  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049652b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049652d  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00496530  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496534  8b1c2e                 -mov ebx, dword ptr [esi + ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 1);
    // 00496537  8b3c32                 -mov edi, dword ptr [edx + esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1);
    // 0049653a  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049653c  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00496540  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00496544  d80c8d90445b00         -fmul dword ptr [ecx*4 + 0x5b4490]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5981328) /* 0x5b4490 */ + cpu.ecx * 4));
    // 0049654b  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049654e  8b5c2e04               -mov ebx, dword ptr [esi + ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00496552  8b6c3204               -mov ebp, dword ptr [edx + esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00496556  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00496558  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049655c  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00496560  d80c8d90445b00         -fmul dword ptr [ecx*4 + 0x5b4490]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5981328) /* 0x5b4490 */ + cpu.ecx * 4));
    // 00496567  d95814                 -fstp dword ptr [eax + 0x14]
    app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049656a  db0432                 -fild dword ptr [edx + esi]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1))));
    // 0049656d  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049656f  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496571  db443204               -fild dword ptr [edx + esi + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1))));
    // 00496575  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00496577  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049657a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049657d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049657e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049657f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496580  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_496584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00496584);
    // 00496584  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496585  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496586  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496587  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049658a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049658e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00496590  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00496594  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00496598  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0049659f  a188904d00             -mov eax, dword ptr [0x4d9088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004965a4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004965a6  8b157c904d00           -mov edx, dword ptr [0x4d907c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */);
    // 004965ac  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004965ae  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004965b0  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004965b4  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004965bb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004965bd  8b3d64b04d00           -mov edi, dword ptr [0x4db064]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 004965c3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004965c6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004965c8  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004965cb  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004965d2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004965d4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004965d7  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004965d9  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004965dc  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004965e0:
    // 004965e0  837f2400               +cmp dword ptr [edi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004965e4  0f8ead000000           -jle 0x496697
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496697;
    }
    // 004965ea  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x004965ee:
    // 004965ee  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004965f1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004965f3  0f8ee2000000           -jle 0x4966db
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004966db;
    }
    // 004965f9  8b4724                 -mov eax, dword ptr [edi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 004965fc  39c8                   +cmp eax, ecx
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
    // 004965fe  0f8d0e010000           -jge 0x496712
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496712;
    }
L_0x00496604:
    // 00496604  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00496607  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00496609  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049660d  895724                 -mov dword ptr [edi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00496610  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00496614  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00496617  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496619  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049661b  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0049661f  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00496622  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x00496624:
    // 00496624  74ba                   -je 0x4965e0
    if (cpu.flags.zf)
    {
        goto L_0x004965e0;
    }
    // 00496626  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00496629  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049662c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049662e  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00496634  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496636  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496639  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049663b  0f8fd8000000           -jg 0x496719
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00496719;
    }
    // 00496641  0f8c29010000           -jl 0x496770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496770;
    }
L_0x00496647:
    // 00496647  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0049664a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049664e  a184904d00             -mov eax, dword ptr [0x4d9084]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083268) /* 0x4d9084 */);
    // 00496653  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00496656  dc06                   -fadd qword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi));
    // 00496658  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049665a  dd1e                   -fstp qword ptr [esi]
    app->getMemory<double>(cpu.esi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049665c  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049665f  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 00496662  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496664  dc4608                 -fadd qword ptr [esi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 00496667  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049666a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049666e  dd5e08                 -fstp qword ptr [esi + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496671  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 00496674  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00496677  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049667a  dc07                   -fadd qword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi));
    // 0049667c  01c3                   +add ebx, eax
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
    // 0049667e  dd1f                   +fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496680  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00496683  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00496687  d94714                 +fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 0049668a  dc4708                 +fadd qword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0049668d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049668e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00496692  dd5f08                 +fstp qword ptr [edi + 8]
    app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496695  eb8d                   -jmp 0x496624
    goto L_0x00496624;
L_0x00496697:
    // 00496697  4d                     -dec ebp
    (cpu.ebp)--;
    // 00496698  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049669a  7c22                   -jl 0x4966be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004966be;
    }
    // 0049669c  83ef28                 -sub edi, 0x28
    (cpu.edi) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0049669f:
    // 0049669f  3b6c241c               +cmp ebp, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004966a3  742a                   -je 0x4966cf
    if (cpu.flags.zf)
    {
        goto L_0x004966cf;
    }
    // 004966a5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004966a9  3b4720                 +cmp eax, dword ptr [edi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004966ac  0f8e2effffff           -jle 0x4965e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004965e0;
    }
    // 004966b2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004966b7  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004966ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004966be:
    // 004966be  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004966c2  6bc528                 -imul eax, ebp, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 004966c5  8b3d64b04d00           -mov edi, dword ptr [0x4db064]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 004966cb  01c7                   +add edi, eax
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
    // 004966cd  ebd0                   -jmp 0x49669f
    goto L_0x0049669f;
L_0x004966cf:
    // 004966cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004966d4  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004966d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004966db:
    // 004966db  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004966df  40                     -inc eax
    (cpu.eax)++;
    // 004966e0  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004966e4  39d0                   +cmp eax, edx
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
    // 004966e6  7c25                   -jl 0x49670d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049670d;
    }
    // 004966e8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004966ea  8b3564b04d00           -mov esi, dword ptr [0x4db064]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 004966f0  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x004966f4:
    // 004966f4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004966f8  3b4620                 +cmp eax, dword ptr [esi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004966fb  0f8eedfeffff           -jle 0x4965ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004965ee;
    }
    // 00496701  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00496706  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00496709  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049670a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049670b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049670c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049670d:
    // 0049670d  83c628                 +add esi, 0x28
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496710  ebe2                   -jmp 0x4966f4
    goto L_0x004966f4;
L_0x00496712:
    // 00496712  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00496714  e9ebfeffff             -jmp 0x496604
    goto L_0x00496604;
L_0x00496719:
    // 00496719  d9048590445b00         -fld dword ptr [eax*4 + 0x5b4490]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5981328) /* 0x5b4490 */ + cpu.eax * 4)));
    // 00496720  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 00496722  dc26                   -fsub qword ptr [esi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi));
    // 00496724  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00496726  d9056cb04d00           -fld dword ptr [0x4db06c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5091436) /* 0x4db06c */)));
    // 0049672c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049672e  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00496730  dd1d400a4e00           -fstp qword ptr [0x4e0a40]
    app->getMemory<double>(x86::reg32(5114432) /* 0x4e0a40 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496736  dd4708                 -fld qword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00496739  dc6608                 -fsub qword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0049673c  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049673e  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496742  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 00496748  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049674a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049674d  dd1d480a4e00           -fstp qword ptr [0x4e0a48]
    app->getMemory<double>(x86::reg32(5114440) /* 0x4e0a48 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496753  031c8a                 +add ebx, dword ptr [edx + ecx*4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496756  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00496758  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049675b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049675f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496761  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00496765  ff159cb04d00           -call dword ptr [0x4db09c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5091484) /* 0x4db09c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049676b  e9d7feffff             -jmp 0x496647
    goto L_0x00496647;
L_0x00496770:
    // 00496770  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00496773  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00496776  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00496778  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0049677e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496780  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496783  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496785  83f801                 +cmp eax, 1
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
    // 00496788  7d05                   -jge 0x49678f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049678f;
    }
    // 0049678a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0049678f:
    // 0049678f  d9048d90445b00         -fld dword ptr [ecx*4 + 0x5b4490]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5981328) /* 0x5b4490 */ + cpu.ecx * 4)));
    // 00496796  dd06                   -fld qword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi)));
    // 00496798  dc27                   -fsub qword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi));
    // 0049679a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049679c  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004967a2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004967a4  d9056cb04d00           -fld dword ptr [0x4db06c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5091436) /* 0x4db06c */)));
    // 004967aa  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004967ac  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004967ae  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004967b2  dd1d400a4e00           -fstp qword ptr [0x4e0a40]
    app->getMemory<double>(x86::reg32(5114432) /* 0x4e0a40 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004967b8  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 004967bb  dc6708                 -fsub qword ptr [edi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 004967be  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004967c1  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004967c3  031c82                 +add ebx, dword ptr [edx + eax*4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004967c6  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004967c9  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004967cb  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004967cd  dd1d480a4e00           +fstp qword ptr [0x4e0a48]
    app->getMemory<double>(x86::reg32(5114440) /* 0x4e0a48 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004967d3  ff159cb04d00           -call dword ptr [0x4db09c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5091484) /* 0x4db09c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004967d9  e969feffff             -jmp 0x496647
    goto L_0x00496647;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4967e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004967e0);
    // 004967e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004967e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004967e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004967e3  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004967e6  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004967ea  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004967ec  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004967f0  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004967f4  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004967fb  a188904d00             -mov eax, dword ptr [0x4d9088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 00496800  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496802  8b157c904d00           -mov edx, dword ptr [0x4d907c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */);
    // 00496808  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049680a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049680c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049680e  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00496812  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00496819  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049681b  8b3d64b04d00           -mov edi, dword ptr [0x4db064]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 00496821  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496824  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 00496827  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049682e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00496830  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496833  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496835  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00496838  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0049683c:
    // 0049683c  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 00496840  0f8efe000000           -jle 0x496944
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496944;
    }
    // 00496846  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0049684a:
    // 0049684a  8b4f24                 -mov ecx, dword ptr [edi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0049684d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049684f  0f8433010000           -je 0x496988
    if (cpu.flags.zf)
    {
        goto L_0x00496988;
    }
    // 00496855  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00496858  39d9                   +cmp ecx, ebx
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
    // 0049685a  0f8d5d010000           -jge 0x4969bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004969bd;
    }
    // 00496860  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00496862:
    // 00496862  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00496865  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00496867  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049686b  895724                 -mov dword ptr [edi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049686e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00496872  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00496875  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496877  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00496879  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0049687d  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00496880  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x00496882:
    // 00496882  74b8                   -je 0x49683c
    if (cpu.flags.zf)
    {
        goto L_0x0049683c;
    }
    // 00496884  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00496887  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049688a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049688c  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00496892  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496894  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496897  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496899  0f8e25010000           -jle 0x4969c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004969c4;
    }
    // 0049689f  d9048590445b00         -fld dword ptr [eax*4 + 0x5b4490]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5981328) /* 0x5b4490 */ + cpu.eax * 4)));
    // 004968a6  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 004968a8  dc26                   -fsub qword ptr [esi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi));
    // 004968aa  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004968ac  d9056cb04d00           -fld dword ptr [0x4db06c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5091436) /* 0x4db06c */)));
    // 004968b2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004968b4  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004968b6  dd1d400a4e00           -fstp qword ptr [0x4e0a40]
    app->getMemory<double>(x86::reg32(5114432) /* 0x4e0a40 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004968bc  dd4708                 -fld qword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004968bf  dc6608                 -fsub qword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004968c2  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004968c4  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004968c8  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004968ce  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004968d0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004968d3  dd1d480a4e00           -fstp qword ptr [0x4e0a48]
    app->getMemory<double>(x86::reg32(5114440) /* 0x4e0a48 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004968d9  031c8a                 -add ebx, dword ptr [edx + ecx*4]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4)));
    // 004968dc  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004968de  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004968e1  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004968e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004968e7  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x004968eb:
    // 004968eb  ff159cb04d00           -call dword ptr [0x4db09c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5091484) /* 0x4db09c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004968f1:
    // 004968f1  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004968f4  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004968f8  a184904d00             -mov eax, dword ptr [0x4d9084]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083268) /* 0x4d9084 */);
    // 004968fd  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00496900  dc06                   -fadd qword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi));
    // 00496902  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496904  dd1e                   -fstp qword ptr [esi]
    app->getMemory<double>(cpu.esi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496906  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00496909  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 0049690c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049690e  dc4608                 -fadd qword ptr [esi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 00496911  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00496914  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00496918  dd5e08                 -fstp qword ptr [esi + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049691b  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 0049691e  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00496921  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00496924  dc07                   -fadd qword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi));
    // 00496926  01c3                   +add ebx, eax
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
    // 00496928  dd1f                   +fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049692a  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049692d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00496931  d94714                 +fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 00496934  dc4708                 +fadd qword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 00496937  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00496938  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049693c  dd5f08                 +fstp qword ptr [edi + 8]
    app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049693f  e93effffff             -jmp 0x496882
    goto L_0x00496882;
L_0x00496944:
    // 00496944  4d                     -dec ebp
    (cpu.ebp)--;
    // 00496945  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00496947  7c22                   -jl 0x49696b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049696b;
    }
    // 00496949  83ee28                 -sub esi, 0x28
    (cpu.esi) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0049694c:
    // 0049694c  3b6c241c               +cmp ebp, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496950  742a                   -je 0x49697c
    if (cpu.flags.zf)
    {
        goto L_0x0049697c;
    }
    // 00496952  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00496956  3b4620                 +cmp eax, dword ptr [esi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496959  0f8eddfeffff           -jle 0x49683c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049683c;
    }
    // 0049695f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00496964  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00496967  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496968  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496969  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049696a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049696b:
    // 0049696b  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049696f  6bc528                 -imul eax, ebp, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 00496972  8b3564b04d00           -mov esi, dword ptr [0x4db064]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 00496978  01c6                   +add esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049697a  ebd0                   -jmp 0x49694c
    goto L_0x0049694c;
L_0x0049697c:
    // 0049697c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00496981  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00496984  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496985  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496986  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496987  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496988:
    // 00496988  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049698c  40                     -inc eax
    (cpu.eax)++;
    // 0049698d  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00496991  39d0                   +cmp eax, edx
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
    // 00496993  7c23                   -jl 0x4969b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004969b8;
    }
    // 00496995  8b3d64b04d00           -mov edi, dword ptr [0x4db064]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 0049699b  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x0049699f:
    // 0049699f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004969a3  3b4720                 +cmp eax, dword ptr [edi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004969a6  0f8e9efeffff           -jle 0x49684a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049684a;
    }
    // 004969ac  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004969b1  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004969b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004969b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004969b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004969b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004969b8:
    // 004969b8  83c728                 +add edi, 0x28
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004969bb  ebe2                   -jmp 0x49699f
    goto L_0x0049699f;
L_0x004969bd:
    // 004969bd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004969bf  e99efeffff             -jmp 0x496862
    goto L_0x00496862;
L_0x004969c4:
    // 004969c4  0f8d27ffffff           -jge 0x4968f1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004968f1;
    }
    // 004969ca  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004969cd  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004969d0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004969d2  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 004969d8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004969da  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004969dd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004969df  83f801                 +cmp eax, 1
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
    // 004969e2  7d05                   -jge 0x4969e9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004969e9;
    }
    // 004969e4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004969e9:
    // 004969e9  d9048d90445b00         -fld dword ptr [ecx*4 + 0x5b4490]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5981328) /* 0x5b4490 */ + cpu.ecx * 4)));
    // 004969f0  dd06                   -fld qword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi)));
    // 004969f2  dc27                   -fsub qword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi));
    // 004969f4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004969f6  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004969fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004969fe  d9056cb04d00           -fld dword ptr [0x4db06c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5091436) /* 0x4db06c */)));
    // 00496a04  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00496a06  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00496a08  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496a0c  dd1d400a4e00           -fstp qword ptr [0x4e0a40]
    app->getMemory<double>(x86::reg32(5114432) /* 0x4e0a40 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496a12  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00496a15  dc6708                 -fsub qword ptr [edi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 00496a18  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496a1b  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00496a1d  031c82                 +add ebx, dword ptr [edx + eax*4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496a20  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00496a23  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00496a25  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00496a27  dd1d480a4e00           +fstp qword ptr [0x4e0a48]
    app->getMemory<double>(x86::reg32(5114440) /* 0x4e0a48 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496a2d  e9b9feffff             -jmp 0x4968eb
    goto L_0x004968eb;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_496a34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00496a34);
    // 00496a34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496a35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496a36  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496a37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496a38  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496a39  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496a3a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496a3c  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 00496a41  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00496a44  e817e80000             -call 0x4a5260
    cpu.esp -= 4;
    sub_4a5260(app, cpu);
    if (cpu.terminate) return;
    // 00496a49  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00496a4c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496a4e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00496a50  0fbdc0                 -bsr eax, eax
    if (cpu.eax == 0)
    {
        cpu.flags.zf = 1;
    }
    else
    {
        cpu.flags.zf = 0;
        cpu.eax = x86::reg32(31 - __builtin_clz(cpu.eax));
    }
    // 00496a53  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00496a55  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00496a5c  892d540a4e00           -mov dword ptr [0x4e0a54], ebp
    app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */) = cpu.ebp;
    // 00496a62  39c6                   +cmp esi, eax
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
    // 00496a64  7e19                   -jle 0x496a7f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496a7f;
    }
L_0x00496a66:
    // 00496a66  833d540a4e0000         +cmp dword ptr [0x4e0a54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a6d  7c27                   -jl 0x496a96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496a96;
    }
    // 00496a6f  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496a72  890d500a4e00           -mov dword ptr [0x4e0a50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */) = cpu.ecx;
    // 00496a78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496a7f:
    // 00496a7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496a81  0fbcc0                 -bsf eax, eax
    if (cpu.eax == 0)
    {
        cpu.flags.zf = 1;
    }
    else
    {
        cpu.flags.zf = 0;
        cpu.eax = x86::reg32(__builtin_ctz(cpu.eax));
    }
    // 00496a84  39c3                   +cmp ebx, eax
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
    // 00496a86  75de                   -jne 0x496a66
    if (!cpu.flags.zf)
    {
        goto L_0x00496a66;
    }
    // 00496a88  8b048570b04d00         -mov eax, dword ptr [eax*4 + 0x4db070]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091440) /* 0x4db070 */ + cpu.eax * 4);
    // 00496a8f  a3540a4e00             -mov dword ptr [0x4e0a54], eax
    app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */) = cpu.eax;
    // 00496a94  ebd0                   -jmp 0x496a66
    goto L_0x00496a66;
L_0x00496a96:
    // 00496a96  a198b04d00             -mov eax, dword ptr [0x4db098]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091480) /* 0x4db098 */);
    // 00496a9b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496a9d  a3540a4e00             -mov dword ptr [0x4e0a54], eax
    app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */) = cpu.eax;
    // 00496aa2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496aa4  e8bff8ffff             -call 0x496368
    cpu.esp -= 4;
    sub_496368(app, cpu);
    if (cpu.terminate) return;
    // 00496aa9  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496aac  890d500a4e00           -mov dword ptr [0x4e0a50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */) = cpu.ecx;
    // 00496ab2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496ab3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496ab4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496ab5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496ab6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496ab7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496ab8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_496abc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00496abc);
    // 00496abc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496abd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496abe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496abf  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00496ac2  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00496ac6  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00496aca  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00496ace  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00496ad2  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00496ad6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496ad8  8b3564b04d00           -mov esi, dword ptr [0x4db064]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 00496ade  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00496ae2  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00496ae6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496ae8  0f8498020000           -je 0x496d86
    if (cpu.flags.zf)
    {
        goto L_0x00496d86;
    }
L_0x00496aee:
    // 00496aee  8b0495a0b04d00         -mov eax, dword ptr [edx*4 + 0x4db0a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091488) /* 0x4db0a0 */ + cpu.edx * 4);
    // 00496af5  a39cb04d00             -mov dword ptr [0x4db09c], eax
    app->getMemory<x86::reg32>(x86::reg32(5091484) /* 0x4db09c */) = cpu.eax;
    // 00496afa  8a2578904d00           -mov ah, byte ptr [0x4d9078]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 00496b00  80fc0f                 +cmp ah, 0xf
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
    // 00496b03  0f8587020000           -jne 0x496d90
    if (!cpu.flags.zf)
    {
        goto L_0x00496d90;
    }
L_0x00496b09:
    // 00496b09  8b0495c0b04d00         -mov eax, dword ptr [edx*4 + 0x4db0c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091520) /* 0x4db0c0 */ + cpu.edx * 4);
    // 00496b10  a39cb04d00             -mov dword ptr [0x4db09c], eax
    app->getMemory<x86::reg32>(x86::reg32(5091484) /* 0x4db09c */) = cpu.eax;
L_0x00496b15:
    // 00496b15  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496b19  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496b1d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00496b22  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00496b24  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496b28  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00496b2c  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00496b30  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 00496b34  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00496b37  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496b39  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00496b3b  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00496b3f  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00496b43  39d1                   +cmp ecx, edx
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
    // 00496b45  7e3a                   -jle 0x496b81
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496b81;
    }
    // 00496b47  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496b4b  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00496b4e:
    // 00496b4e  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00496b51  39f7                   +cmp edi, esi
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
    // 00496b53  0f8e45020000           -jle 0x496d9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496d9e;
    }
    // 00496b59  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00496b5b  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x00496b5f:
    // 00496b5f  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496b63  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00496b65  39f3                   +cmp ebx, esi
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
    // 00496b67  0f8d40020000           -jge 0x496dad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496dad;
    }
    // 00496b6d  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 00496b71  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x00496b75:
    // 00496b75  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496b79  42                     -inc edx
    (cpu.edx)++;
    // 00496b7a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496b7d  39da                   +cmp edx, ebx
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
    // 00496b7f  7ccd                   -jl 0x496b4e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496b4e;
    }
L_0x00496b81:
    // 00496b81  3b3d74904d00           +cmp edi, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b87  0f8d37020000           -jge 0x496dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496dc4;
    }
    // 00496b8d  3b2d6c904d00           +cmp ebp, dword ptr [0x4d906c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b93  0f8c2b020000           -jl 0x496dc4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496dc4;
    }
    // 00496b99  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496b9d  3b0570904d00           +cmp eax, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496ba3  0f8d1b020000           -jge 0x496dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496dc4;
    }
    // 00496ba9  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00496bad  3b0568904d00           +cmp eax, dword ptr [0x4d9068]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496bb3  0f8c0b020000           -jl 0x496dc4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496dc4;
    }
    // 00496bb9  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00496bbd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496bbf  7554                   -jne 0x496c15
    if (!cpu.flags.zf)
    {
        goto L_0x00496c15;
    }
    // 00496bc1  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496bc5  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00496bc8  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496bcb  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00496bcf  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00496bd3:
    // 00496bd3  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00496bd7  3b44241c               +cmp eax, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496bdb  7d38                   -jge 0x496c15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496c15;
    }
    // 00496bdd  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00496be1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496be5  8d5e08                 -lea ebx, [esi + 8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00496be8  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496bea  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00496bee  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00496bf1  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00496bf4  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00496bf6  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00496bf9  2b4608                 -sub eax, dword ptr [esi + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00496bfc  2b5e0c                 -sub ebx, dword ptr [esi + 0xc]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 00496bff  2b4e08                 -sub ecx, dword ptr [esi + 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00496c02  2b560c                 -sub edx, dword ptr [esi + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 00496c05  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00496c08  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00496c0b  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00496c0d  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 00496c11  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496c13  74be                   -je 0x496bd3
    if (cpu.flags.zf)
    {
        goto L_0x00496bd3;
    }
L_0x00496c15:
    // 00496c15  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496c19  3b0568904d00           +cmp eax, dword ptr [0x4d9068]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496c1f  0f8caa010000           -jl 0x496dcf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496dcf;
    }
L_0x00496c25:
    // 00496c25  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00496c29  3b0570904d00           +cmp eax, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496c2f  0f8dc1010000           -jge 0x496df6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496df6;
    }
L_0x00496c35:
    // 00496c35  3b3d6c904d00           +cmp edi, dword ptr [0x4d906c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496c3b  0f8cdc010000           -jl 0x496e1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496e1d;
    }
L_0x00496c41:
    // 00496c41  3b2d74904d00           +cmp ebp, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496c47  0f8df7010000           -jge 0x496e44
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496e44;
    }
    // 00496c4d  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496c52  746c                   -je 0x496cc0
    if (cpu.flags.zf)
    {
        goto L_0x00496cc0;
    }
L_0x00496c54:
    // 00496c54  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496c58  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496c5c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496c5e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00496c63  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00496c67  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00496c6b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00496c6f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496c71  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00496c74  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00496c78  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00496c7c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496c80  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00496c82  39d0                   +cmp eax, edx
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
    // 00496c84  7e3a                   -jle 0x496cc0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496cc0;
    }
    // 00496c86  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496c8a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00496c8d:
    // 00496c8d  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00496c90  39df                   +cmp edi, ebx
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
    // 00496c92  0f8ed5010000           -jle 0x496e6d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496e6d;
    }
    // 00496c98  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00496c9a  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x00496c9e:
    // 00496c9e  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496ca2  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00496ca4  39cb                   +cmp ebx, ecx
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
    // 00496ca6  0f8dd0010000           -jge 0x496e7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496e7c;
    }
    // 00496cac  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 00496cb0  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x00496cb4:
    // 00496cb4  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496cb8  42                     -inc edx
    (cpu.edx)++;
    // 00496cb9  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496cbc  39ca                   +cmp edx, ecx
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
    // 00496cbe  7ccd                   -jl 0x496c8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496c8d;
    }
L_0x00496cc0:
    // 00496cc0  39ef                   +cmp edi, ebp
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
    // 00496cc2  0f8dcb010000           -jge 0x496e93
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496e93;
    }
    // 00496cc8  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496ccc  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496cd0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00496cd2  48                     -dec eax
    (cpu.eax)--;
    // 00496cd3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496cd5  7e29                   -jle 0x496d00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496d00;
    }
    // 00496cd7  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00496cd9:
    // 00496cd9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496cdd  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496ce1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496ce2  a164b04d00             -mov eax, dword ptr [0x4db064]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 00496ce7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00496ce9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00496ceb  e8b0f7ffff             -call 0x4964a0
    cpu.esp -= 4;
    sub_4964a0(app, cpu);
    if (cpu.terminate) return;
    // 00496cf0  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496cf4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496cf6  46                     -inc esi
    (cpu.esi)++;
    // 00496cf7  83c528                 -add ebp, 0x28
    (cpu.ebp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00496cfa  39ce                   +cmp esi, ecx
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
    // 00496cfc  7cdb                   -jl 0x496cd9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496cd9;
    }
    // 00496cfe  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00496d00:
    // 00496d00  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00496d04  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00496d07  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496d0b  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00496d0f  39d8                   +cmp eax, ebx
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
    // 00496d11  7c06                   -jl 0x496d19
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496d19;
    }
    // 00496d13  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00496d15  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
L_0x00496d19:
    // 00496d19  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496d1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496d1f  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00496d21  a079904d00             -mov al, byte ptr [0x4d9079]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083257) /* 0x4d9079 */);
    // 00496d26  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496d2c  39c2                   +cmp edx, eax
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
    // 00496d2e  7415                   -je 0x496d45
    if (cpu.flags.zf)
    {
        goto L_0x00496d45;
    }
    // 00496d30  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00496d32  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00496d34  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496d38  e86be6ffff             -call 0x4953a8
    cpu.esp -= 4;
    sub_4953a8(app, cpu);
    if (cpu.terminate) return;
    // 00496d3d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00496d41  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00496d45:
    // 00496d45  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496d49  e8e6fcffff             -call 0x496a34
    cpu.esp -= 4;
    sub_496a34(app, cpu);
    if (cpu.terminate) return;
    // 00496d4e  837c244c00             +cmp dword ptr [esp + 0x4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496d53  0f8c16020000           -jl 0x496f6f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496f6f;
    }
    // 00496d59  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496d5d  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00496d61  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496d63  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496d65  e81af8ffff             -call 0x496584
    cpu.esp -= 4;
    sub_496584(app, cpu);
    if (cpu.terminate) return;
L_0x00496d6a:
    // 00496d6a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496d6c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00496d70  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00496d72  7407                   -je 0x496d7b
    if (cpu.flags.zf)
    {
        goto L_0x00496d7b;
    }
    // 00496d74  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00496d76  e8f1bffeff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
L_0x00496d7b:
    // 00496d7b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496d7d  83c43c                 +add esp, 0x3c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496d80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d83  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00496d86:
    // 00496d86  e845f5ffff             -call 0x4962d0
    cpu.esp -= 4;
    sub_4962d0(app, cpu);
    if (cpu.terminate) return;
    // 00496d8b  e95efdffff             -jmp 0x496aee
    goto L_0x00496aee;
L_0x00496d90:
    // 00496d90  80fc10                 +cmp ah, 0x10
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
    // 00496d93  0f8470fdffff           -je 0x496b09
    if (cpu.flags.zf)
    {
        goto L_0x00496b09;
    }
    // 00496d99  e977fdffff             -jmp 0x496b15
    goto L_0x00496b15;
L_0x00496d9e:
    // 00496d9e  39f5                   +cmp ebp, esi
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
    // 00496da0  0f8db9fdffff           -jge 0x496b5f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496b5f;
    }
    // 00496da6  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00496da8  e9b2fdffff             -jmp 0x496b5f
    goto L_0x00496b5f;
L_0x00496dad:
    // 00496dad  3b5c2438               +cmp ebx, dword ptr [esp + 0x38]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496db1  0f8ebefdffff           -jle 0x496b75
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496b75;
    }
    // 00496db7  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 00496dbb  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00496dbf  e9b1fdffff             -jmp 0x496b75
    goto L_0x00496b75;
L_0x00496dc4:
    // 00496dc4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496dc6  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00496dc9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496dca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496dcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496dcc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00496dcf:
    // 00496dcf  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496dd3  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496dd7  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496ddb  e8f8480100             -call 0x4ab6d8
    cpu.esp -= 4;
    sub_4ab6d8(app, cpu);
    if (cpu.terminate) return;
    // 00496de0  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00496de4  83f803                 +cmp eax, 3
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
    // 00496de7  7cdb                   -jl 0x496dc4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496dc4;
    }
    // 00496de9  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00496df1  e92ffeffff             -jmp 0x496c25
    goto L_0x00496c25;
L_0x00496df6:
    // 00496df6  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496dfa  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496dfe  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496e02  e8394a0100             -call 0x4ab840
    cpu.esp -= 4;
    sub_4ab840(app, cpu);
    if (cpu.terminate) return;
    // 00496e07  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00496e0b  83f803                 +cmp eax, 3
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
    // 00496e0e  7cb4                   -jl 0x496dc4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496dc4;
    }
    // 00496e10  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00496e18  e918feffff             -jmp 0x496c35
    goto L_0x00496c35;
L_0x00496e1d:
    // 00496e1d  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496e21  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496e25  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496e29  e86a4b0100             -call 0x4ab998
    cpu.esp -= 4;
    sub_4ab998(app, cpu);
    if (cpu.terminate) return;
    // 00496e2e  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00496e32  83f803                 +cmp eax, 3
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
    // 00496e35  7c8d                   -jl 0x496dc4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496dc4;
    }
    // 00496e37  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00496e3f  e9fdfdffff             -jmp 0x496c41
    goto L_0x00496c41;
L_0x00496e44:
    // 00496e44  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496e48  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496e4c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496e50  e8a34c0100             -call 0x4abaf8
    cpu.esp -= 4;
    sub_4abaf8(app, cpu);
    if (cpu.terminate) return;
    // 00496e55  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00496e59  83f803                 +cmp eax, 3
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
    // 00496e5c  0f8df2fdffff           -jge 0x496c54
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496c54;
    }
L_0x00496e62:
    // 00496e62  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496e64  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00496e67  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496e68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496e69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496e6a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00496e6d:
    // 00496e6d  39dd                   +cmp ebp, ebx
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
    // 00496e6f  0f8d29feffff           -jge 0x496c9e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496c9e;
    }
    // 00496e75  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00496e77  e922feffff             -jmp 0x496c9e
    goto L_0x00496c9e;
L_0x00496e7c:
    // 00496e7c  3b5c2438               +cmp ebx, dword ptr [esp + 0x38]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496e80  0f8e2efeffff           -jle 0x496cb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496cb4;
    }
    // 00496e86  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 00496e8a  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00496e8e  e921feffff             -jmp 0x496cb4
    goto L_0x00496cb4;
L_0x00496e93:
    // 00496e93  75cd                   -jne 0x496e62
    if (!cpu.flags.zf)
    {
        goto L_0x00496e62;
    }
    // 00496e95  837c244c00             +cmp dword ptr [esp + 0x4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496e9a  0f8cc1000000           -jl 0x496f61
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496f61;
    }
    // 00496ea0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00496ea2:
    // 00496ea2  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00496ea6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496eaa  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 00496ead  8b3564b04d00           -mov esi, dword ptr [0x4db064]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 00496eb3  db0403                 -fild dword ptr [ebx + eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1))));
    // 00496eb6  d9056cb04d00           -fld dword ptr [0x4db06c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5091436) /* 0x4db06c */)));
    // 00496ebc  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00496ec3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00496ec5  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00496ec7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496ec9  dd1cc6                 -fstp qword ptr [esi + eax*8]
    app->getMemory<double>(cpu.esi + cpu.eax * 8) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496ecc  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00496ed0  db4304                 -fild dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 00496ed3  c744c62401000000       -mov dword ptr [esi + eax*8 + 0x24], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 8) = 1 /*0x1*/;
    // 00496edb  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496edf  897cc620               -mov dword ptr [esi + eax*8 + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */ + cpu.eax * 8) = cpu.edi;
    // 00496ee3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00496ee5  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00496ee8  dd5cc608               -fstp qword ptr [esi + eax*8 + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496eec  895cc618               -mov dword ptr [esi + eax*8 + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.eax * 8) = cpu.ebx;
    // 00496ef0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496ef2  7577                   -jne 0x496f6b
    if (!cpu.flags.zf)
    {
        goto L_0x00496f6b;
    }
    // 00496ef4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00496ef9:
    // 00496ef9  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00496efd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496f01  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 00496f04  db0403                 -fild dword ptr [ebx + eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1))));
    // 00496f07  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00496f0e  d9056cb04d00           -fld dword ptr [0x4db06c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5091436) /* 0x4db06c */)));
    // 00496f14  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496f16  a164b04d00             -mov eax, dword ptr [0x4db064]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091428) /* 0x4db064 */);
    // 00496f1b  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00496f1e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00496f20  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00496f22  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496f24  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496f26  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496f2a  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00496f2e  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00496f30  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00496f33  db4304                 -fild dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 00496f36  c7402401000000         -mov dword ptr [eax + 0x24], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 00496f3d  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00496f40  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00496f45  897820                 -mov dword ptr [eax + 0x20], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 00496f48  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00496f4a  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 00496f4e  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496f51  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00496f56  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00496f58  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00496f5c  e9b8fdffff             -jmp 0x496d19
    goto L_0x00496d19;
L_0x00496f61:
    // 00496f61  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00496f66  e937ffffff             -jmp 0x496ea2
    goto L_0x00496ea2;
L_0x00496f6b:
    // 00496f6b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00496f6d  eb8a                   -jmp 0x496ef9
    goto L_0x00496ef9;
L_0x00496f6f:
    // 00496f6f  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496f73  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00496f77  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496f79  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496f7b  e860f8ffff             -call 0x4967e0
    cpu.esp -= 4;
    sub_4967e0(app, cpu);
    if (cpu.terminate) return;
    // 00496f80  e9e5fdffff             -jmp 0x496d6a
    goto L_0x00496d6a;
}

}
