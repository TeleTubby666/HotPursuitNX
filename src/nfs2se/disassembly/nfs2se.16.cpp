#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477d21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477d22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477d23  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477d26  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00477d2a  8b158ca34c00           -mov edx, dword ptr [0x4ca38c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00477d30  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00477d32  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00477d34  750a                   -jne 0x477d40
    if (!cpu.flags.zf)
    {
        goto L_0x00477d40;
    }
    // 00477d36  e83d8e0000             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00477d3b  a38ca34c00             -mov dword ptr [0x4ca38c], eax
    app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */) = cpu.eax;
L_0x00477d40:
    // 00477d40  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00477d45  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00477d4a  bab0cc5100             -mov edx, 0x51ccb0
    cpu.edx = 5360816 /*0x51ccb0*/;
    // 00477d4f  e8748e0000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00477d54  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477d58  68807e4700             -push 0x477e80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4685440 /*0x477e80*/;
    cpu.esp -= 4;
    // 00477d5d  8b1d64a34c00           -mov ebx, dword ptr [0x4ca364]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022564) /* 0x4ca364 */);
    // 00477d63  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00477d67  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477d6b  e831da0100             -call 0x4957a1
    cpu.esp -= 4;
    sub_4957a1(app, cpu);
    if (cpu.terminate) return;
    // 00477d70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477d72  7449                   -je 0x477dbd
    if (cpu.flags.zf)
    {
        goto L_0x00477dbd;
    }
    // 00477d74  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00477d76  7540                   -jne 0x477db8
    if (!cpu.flags.zf)
    {
        goto L_0x00477db8;
    }
    // 00477d78  b9807e4700             -mov ecx, 0x477e80
    cpu.ecx = 4685440 /*0x477e80*/;
    // 00477d7d  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00477d82  8b1564a34c00           -mov edx, dword ptr [0x4ca364]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022564) /* 0x4ca364 */);
    // 00477d88  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 00477d8e  b8b0cc5100             -mov eax, 0x51ccb0
    cpu.eax = 5360816 /*0x51ccb0*/;
    // 00477d93  e8efda0100             -call 0x495887
    cpu.esp -= 4;
    sub_495887(app, cpu);
    if (cpu.terminate) return;
    // 00477d98  ff0d64a34c00           -dec dword ptr [0x4ca364]
    (app->getMemory<x86::reg32>(x86::reg32(5022564) /* 0x4ca364 */))--;
L_0x00477d9e:
    // 00477d9e  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00477da3:
    // 00477da3  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00477da8  e8338e0000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00477dad  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477daf  83c408                 +add esp, 8
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
    // 00477db2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477db3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477db4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477db5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00477db8:
    // 00477db8  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00477dbb  ebe1                   -jmp 0x477d9e
    goto L_0x00477d9e;
L_0x00477dbd:
    // 00477dbd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00477dbf  74e2                   -je 0x477da3
    if (cpu.flags.zf)
    {
        goto L_0x00477da3;
    }
    // 00477dc1  8b0d64a34c00           -mov ecx, dword ptr [0x4ca364]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022564) /* 0x4ca364 */);
    // 00477dc7  81f980000000           +cmp ecx, 0x80
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477dcd  73d4                   -jae 0x477da3
    if (!cpu.flags.cf)
    {
        goto L_0x00477da3;
    }
    // 00477dcf  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477dd3  b8b0cc5100             -mov eax, 0x51ccb0
    cpu.eax = 5360816 /*0x51ccb0*/;
    // 00477dd8  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00477ddb  893ccdb4cc5100         -mov dword ptr [ecx*8 + 0x51ccb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5360820) /* 0x51ccb4 */ + cpu.ecx * 8) = cpu.edi;
    // 00477de2  891d64a34c00           -mov dword ptr [0x4ca364], ebx
    app->getMemory<x86::reg32>(x86::reg32(5022564) /* 0x4ca364 */) = cpu.ebx;
    // 00477de8  8914cdb0cc5100         -mov dword ptr [ecx*8 + 0x51ccb0], edx
    app->getMemory<x86::reg32>(x86::reg32(5360816) /* 0x51ccb0 */ + cpu.ecx * 8) = cpu.edx;
    // 00477def  b9807e4700             -mov ecx, 0x477e80
    cpu.ecx = 4685440 /*0x477e80*/;
    // 00477df4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00477df6  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00477dfb  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00477e00  e882da0100             -call 0x495887
    cpu.esp -= 4;
    sub_495887(app, cpu);
    if (cpu.terminate) return;
    // 00477e05  eb9c                   -jmp 0x477da3
    goto L_0x00477da3;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477e10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477e11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477e12  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477e15  8b158ca34c00           -mov edx, dword ptr [0x4ca38c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00477e1b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00477e1d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00477e1f  750a                   -jne 0x477e2b
    if (!cpu.flags.zf)
    {
        goto L_0x00477e2b;
    }
    // 00477e21  e8528d0000             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00477e26  a38ca34c00             -mov dword ptr [0x4ca38c], eax
    app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */) = cpu.eax;
L_0x00477e2b:
    // 00477e2b  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00477e30  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00477e35  bab0cc5100             -mov edx, 0x51ccb0
    cpu.edx = 5360816 /*0x51ccb0*/;
    // 00477e3a  e8898d0000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00477e3f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477e43  68807e4700             -push 0x477e80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4685440 /*0x477e80*/;
    cpu.esp -= 4;
    // 00477e48  8b1d64a34c00           -mov ebx, dword ptr [0x4ca364]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022564) /* 0x4ca364 */);
    // 00477e4e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00477e52  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477e56  e846d90100             -call 0x4957a1
    cpu.esp -= 4;
    sub_4957a1(app, cpu);
    if (cpu.terminate) return;
    // 00477e5b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477e5d  7403                   -je 0x477e62
    if (cpu.flags.zf)
    {
        goto L_0x00477e62;
    }
    // 00477e5f  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00477e62:
    // 00477e62  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00477e67  e8748d0000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00477e6c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477e6e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477e71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e73  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477e80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477e81  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00477e83  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00477e85  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477e87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477e90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477e92  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477e95  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00477e98  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00477e9a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477e9c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477e9e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477ea0  7e0c                   -jle 0x477eae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477eae;
    }
L_0x00477ea2:
    // 00477ea2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00477ea4  ff15acca4c00           -call dword ptr [0x4ccaac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032620) /* 0x4ccaac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477eaa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477eac  7508                   -jne 0x477eb6
    if (!cpu.flags.zf)
    {
        goto L_0x00477eb6;
    }
L_0x00477eae:
    // 00477eae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477eb0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477eb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477eb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477eb5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477eb6:
    // 00477eb6  e849430000             -call 0x47c204
    cpu.esp -= 4;
    sub_47c204(app, cpu);
    if (cpu.terminate) return;
    // 00477ebb  42                     -inc edx
    (cpu.edx)++;
    // 00477ebc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477ebe  7408                   -je 0x477ec8
    if (cpu.flags.zf)
    {
        goto L_0x00477ec8;
    }
    // 00477ec0  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00477ec3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00477ec6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00477ec8:
    // 00477ec8  39da                   +cmp edx, ebx
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
    // 00477eca  7cd6                   -jl 0x477ea2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477ea2;
    }
    // 00477ecc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477ece  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477ed1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ed2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ed3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477ed4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477ed4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477ed5  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00477eda  e8b1ffffff             -call 0x477e90
    cpu.esp -= 4;
    sub_477e90(app, cpu);
    if (cpu.terminate) return;
    // 00477edf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ee0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: c38d4000 */
void Application::sub_477ef4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477ef4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477ef5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00477efa  b8f4a64c00             -mov eax, 0x4ca6f4
    cpu.eax = 5023476 /*0x4ca6f4*/;
    // 00477eff  e828000000             -call 0x477f2c
    cpu.esp -= 4;
    sub_477f2c(app, cpu);
    if (cpu.terminate) return;
    // 00477f04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_477f08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477f08  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477f09  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00477f0e  b82ca74c00             -mov eax, 0x4ca72c
    cpu.eax = 5023532 /*0x4ca72c*/;
    // 00477f13  e814000000             -call 0x477f2c
    cpu.esp -= 4;
    sub_477f2c(app, cpu);
    if (cpu.terminate) return;
    // 00477f18  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_477f1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477f1c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477f1d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00477f22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477f24  e803000000             -call 0x477f2c
    cpu.esp -= 4;
    sub_477f2c(app, cpu);
    if (cpu.terminate) return;
    // 00477f29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_477f2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477f2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477f2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477f2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477f2f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477f30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477f31  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477f33  8b15c8ca4c00           -mov edx, dword ptr [0x4ccac8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032648) /* 0x4ccac8 */);
    // 00477f39  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00477f3e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00477f40  7540                   -jne 0x477f82
    if (!cpu.flags.zf)
    {
        goto L_0x00477f82;
    }
    // 00477f42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477f44  7444                   -je 0x477f8a
    if (cpu.flags.zf)
    {
        goto L_0x00477f8a;
    }
    // 00477f46  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00477f48  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00477f4b  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00477f50  e833090100             -call 0x488888
    cpu.esp -= 4;
    sub_488888(app, cpu);
    if (cpu.terminate) return;
L_0x00477f55:
    // 00477f55  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00477f57:
    // 00477f57  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00477f59  7461                   -je 0x477fbc
    if (cpu.flags.zf)
    {
        goto L_0x00477fbc;
    }
    // 00477f5b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00477f5d  7537                   -jne 0x477f96
    if (!cpu.flags.zf)
    {
        goto L_0x00477f96;
    }
    // 00477f5f  833d38a44c0000         +cmp dword ptr [0x4ca438], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022776) /* 0x4ca438 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477f66  7435                   -je 0x477f9d
    if (cpu.flags.zf)
    {
        goto L_0x00477f9d;
    }
L_0x00477f68:
    // 00477f68  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 00477f6d  8b3538a44c00           -mov esi, dword ptr [0x4ca438]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5022776) /* 0x4ca438 */);
L_0x00477f73:
    // 00477f73  bfbca64c00             -mov edi, 0x4ca6bc
    cpu.edi = 5023420 /*0x4ca6bc*/;
    // 00477f78  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00477f7a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00477f7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f81  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477f82:
    // 00477f82  ff15c8ca4c00           -call dword ptr [0x4ccac8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032648) /* 0x4ccac8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477f88  ebcb                   -jmp 0x477f55
    goto L_0x00477f55;
L_0x00477f8a:
    // 00477f8a  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00477f8f  e8480a0100             -call 0x4889dc
    cpu.esp -= 4;
    sub_4889dc(app, cpu);
    if (cpu.terminate) return;
    // 00477f94  ebc1                   -jmp 0x477f57
    goto L_0x00477f57;
L_0x00477f96:
    // 00477f96  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 00477f9b  ebd6                   -jmp 0x477f73
    goto L_0x00477f73;
L_0x00477f9d:
    // 00477f9d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00477fa2  8b0d3ca44c00           -mov ecx, dword ptr [0x4ca43c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 00477fa8  8b1dd8a34c00           -mov ebx, dword ptr [0x4ca3d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */);
    // 00477fae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477fb0  e85bd00100             -call 0x495010
    cpu.esp -= 4;
    sub_495010(app, cpu);
    if (cpu.terminate) return;
    // 00477fb5  a338a44c00             -mov dword ptr [0x4ca438], eax
    app->getMemory<x86::reg32>(x86::reg32(5022776) /* 0x4ca438 */) = cpu.eax;
    // 00477fba  ebac                   -jmp 0x477f68
    goto L_0x00477f68;
L_0x00477fbc:
    // 00477fbc  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 00477fc1  b8bca64c00             -mov eax, 0x4ca6bc
    cpu.eax = 5023420 /*0x4ca6bc*/;
    // 00477fc6  e8d18c0000             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00477fcb  a010a74c00             -mov al, byte ptr [0x4ca710]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023504) /* 0x4ca710 */);
    // 00477fd0  a2d8a64c00             -mov byte ptr [0x4ca6d8], al
    app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */) = cpu.al;
    // 00477fd5  a011a74c00             -mov al, byte ptr [0x4ca711]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023505) /* 0x4ca711 */);
    // 00477fda  a2d9a64c00             -mov byte ptr [0x4ca6d9], al
    app->getMemory<x86::reg8>(x86::reg32(5023449) /* 0x4ca6d9 */) = cpu.al;
    // 00477fdf  a012a74c00             -mov al, byte ptr [0x4ca712]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023506) /* 0x4ca712 */);
    // 00477fe4  a2daa64c00             -mov byte ptr [0x4ca6da], al
    app->getMemory<x86::reg8>(x86::reg32(5023450) /* 0x4ca6da */) = cpu.al;
    // 00477fe9  a124a74c00             -mov eax, dword ptr [0x4ca724]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023524) /* 0x4ca724 */);
    // 00477fee  a3eca64c00             -mov dword ptr [0x4ca6ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */) = cpu.eax;
    // 00477ff3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00477ff5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ff6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ff7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ff8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ff9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ffa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_477ffc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477ffc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477ffd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477fff  e828ffffff             -call 0x477f2c
    cpu.esp -= 4;
    sub_477f2c(app, cpu);
    if (cpu.terminate) return;
    // 00478004  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478005  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478008  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478009  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047800e  e819ffffff             -call 0x477f2c
    cpu.esp -= 4;
    sub_477f2c(app, cpu);
    if (cpu.terminate) return;
    // 00478013  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478014  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478018(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478018  b8f4a64c00             -mov eax, 0x4ca6f4
    cpu.eax = 5023476 /*0x4ca6f4*/;
    // 0047801d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478020  b82ca74c00             -mov eax, 0x4ca72c
    cpu.eax = 5023532 /*0x4ca72c*/;
    // 00478025  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478030  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478031  8b35d8a34c00           -mov esi, dword ptr [0x4ca3d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */);
    // 00478037  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478038  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047803a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0047803c  e8ffcd0100             -call 0x494e40
    cpu.esp -= 4;
    sub_494e40(app, cpu);
    if (cpu.terminate) return;
    // 00478041  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478043  7402                   -je 0x478047
    if (cpu.flags.zf)
    {
        goto L_0x00478047;
    }
    // 00478045  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00478047:
    // 00478047  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478048  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47804c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047804c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047804d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047804f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478051  8b1dd8a34c00           -mov ebx, dword ptr [0x4ca3d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */);
    // 00478057  e8e4cd0100             -call 0x494e40
    cpu.esp -= 4;
    sub_494e40(app, cpu);
    if (cpu.terminate) return;
    // 0047805c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047805e  7402                   -je 0x478062
    if (cpu.flags.zf)
    {
        goto L_0x00478062;
    }
    // 00478060  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00478062:
    // 00478062  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478063  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478064(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478064  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478065  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00478067  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478069  8b1dd8a34c00           -mov ebx, dword ptr [0x4ca3d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */);
    // 0047806f  e8cccd0100             -call 0x494e40
    cpu.esp -= 4;
    sub_494e40(app, cpu);
    if (cpu.terminate) return;
    // 00478074  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00478076  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478077  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478082  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478083  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478084  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478085  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00478088  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047808a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047808c  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0047808f  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478095  ba709f5200             -mov edx, 0x529f70
    cpu.edx = 5414768 /*0x529f70*/;
    // 0047809a  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047809e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004780a0  bb9f860100             -mov ebx, 0x1869f
    cpu.ebx = 99999 /*0x1869f*/;
    // 004780a5  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004780a8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004780ad  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004780b3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004780b6  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004780ba  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004780bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004780be  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004780c2:
    // 004780c2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004780c5  0fb672fe               -movzx esi, byte ptr [edx - 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */));
    // 004780c9  0fb67afd               -movzx edi, byte ptr [edx - 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */));
    // 004780cd  8a88b8a44c00           -mov cl, byte ptr [eax + 0x4ca4b8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022904) /* 0x4ca4b8 */);
    // 004780d3  0fb66afc               -movzx ebp, byte ptr [edx - 4]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */));
    // 004780d7  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004780d9  742b                   -je 0x478106
    if (cpu.flags.zf)
    {
        goto L_0x00478106;
    }
    // 004780db  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004780df  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004780e1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004780e3  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004780e6  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004780ea  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004780ec  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004780ef  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004780f2  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004780f5  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004780f7  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004780fa  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004780fc  39d9                   +cmp ecx, ebx
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
    // 004780fe  7d06                   -jge 0x478106
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478106;
    }
    // 00478100  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00478102  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00478106:
    // 00478106  40                     -inc eax
    (cpu.eax)++;
    // 00478107  3d00010000             +cmp eax, 0x100
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
    // 0047810c  7cb4                   -jl 0x4780c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004780c2;
    }
    // 0047810e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00478112  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00478115  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478116  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478117  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478118  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478119  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047811a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47811c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047811c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047811d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047811e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478120  8a25d8a64c00           -mov ah, byte ptr [0x4ca6d8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 00478126  80fc08                 +cmp ah, 8
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
    // 00478129  761c                   -jbe 0x478147
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00478147;
    }
    // 0047812b  80fc0f                 +cmp ah, 0xf
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
    // 0047812e  745e                   -je 0x47818e
    if (cpu.flags.zf)
    {
        goto L_0x0047818e;
    }
    // 00478130  80fc10                 +cmp ah, 0x10
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
    // 00478133  0f8483000000           -je 0x4781bc
    if (cpu.flags.zf)
    {
        goto L_0x004781bc;
    }
    // 00478139  80fc18                 +cmp ah, 0x18
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047813c  0f829f000000           -jb 0x4781e1
    if (cpu.flags.cf)
    {
        goto L_0x004781e1;
    }
    // 00478142  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478144  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478145  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478146  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478147:
    // 00478147  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478148  8b0db4a44c00           -mov ecx, dword ptr [0x4ca4b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022900) /* 0x4ca4b4 */);
    // 0047814e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00478150  7427                   -je 0x478179
    if (cpu.flags.zf)
    {
        goto L_0x00478179;
    }
    // 00478152  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478154  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0047815a  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0047815d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047815f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00478162  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00478168  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0047816b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047816e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00478170  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478172  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00478174  8a1c01                 -mov bl, byte ptr [ecx + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
    // 00478177  eb0f                   -jmp 0x478188
    goto L_0x00478188;
L_0x00478179:
    // 00478179  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047817b  8d05709f5200           -lea eax, [0x529f70]
    cpu.eax = x86::reg32(x86::reg32(5414768) /* 0x529f70 */);
    // 00478181  e8fafeffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00478186  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00478188:
    // 00478188  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478189  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047818b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047818c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047818d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047818e:
    // 0047818e  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00478190  7425                   -je 0x4781b7
    if (cpu.flags.zf)
    {
        goto L_0x004781b7;
    }
    // 00478192  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478194  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0047819a  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0047819d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047819f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004781a2  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004781a8  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004781ab  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004781ae  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004781b0  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x004781b7:
    // 004781b7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004781b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004781ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004781bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004781bc:
    // 004781bc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004781be  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004781c4  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004781c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004781c9  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004781cc  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004781d2  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004781d5  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004781d8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004781da  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004781dc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004781de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004781df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004781e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004781e1:
    // 004781e1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004781e3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004781e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004781e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004781e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4781f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004781f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004781f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004781f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004781f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004781f4  8b0dd4a64c00           -mov ecx, dword ptr [0x4ca6d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 004781fa  8b15cca64c00           -mov edx, dword ptr [0x4ca6cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 00478200  8b1dc8a64c00           -mov ebx, dword ptr [0x4ca6c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 00478206  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478207  a1d0a64c00             -mov eax, dword ptr [0x4ca6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 0047820c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047820e  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478210  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00478212  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478214  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478216  e8c56b0000             -call 0x47ede0
    cpu.esp -= 4;
    sub_47ede0(app, cpu);
    if (cpu.terminate) return;
    // 0047821b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047821c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047821d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047821e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047821f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478220  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478221  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478223  3b05e8d15100           +cmp eax, dword ptr [0x51d1e8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362152) /* 0x51d1e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478229  7428                   -je 0x478253
    if (cpu.flags.zf)
    {
        goto L_0x00478253;
    }
    // 0047822b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047822c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047822d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047822e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00478230  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478232  6bd600                 -imul edx, esi, 0
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
L_0x00478235:
    // 00478235  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00478237  40                     -inc eax
    (cpu.eax)++;
    // 00478238  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0047823b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047823d  8888e3d05100           -mov byte ptr [eax + 0x51d0e3], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5361891) /* 0x51d0e3 */) = cpu.cl;
    // 00478243  3d00010000             +cmp eax, 0x100
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
    // 00478248  7ceb                   -jl 0x478235
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478235;
    }
    // 0047824a  8935e8d15100           -mov dword ptr [0x51d1e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5362152) /* 0x51d1e8 */) = cpu.esi;
    // 00478250  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478251  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478252  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00478253:
    // 00478253  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478254  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478258(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478258  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478259  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047825b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047825d  8a9be4d05100           -mov bl, byte ptr [ebx + 0x51d0e4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5361892) /* 0x51d0e4 */);
    // 00478263  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00478265  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478267  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047826a  8a9be4d05100           -mov bl, byte ptr [ebx + 0x51d0e4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5361892) /* 0x51d0e4 */);
    // 00478270  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00478273  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478275  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00478278  8a9be4d05100           -mov bl, byte ptr [ebx + 0x51d0e4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5361892) /* 0x51d0e4 */);
    // 0047827e  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00478281  8a4003                 -mov al, byte ptr [eax + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00478284  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478289  8a80e4d05100           -mov al, byte ptr [eax + 0x51d0e4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5361892) /* 0x51d0e4 */);
    // 0047828f  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00478292  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478293  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478294(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478294  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478295  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00478298  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047829a  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047829c  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0047829f  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004782a2  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004782a5  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004782a8  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004782aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004782ac  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004782af  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004782b2  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004782b5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004782b8  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004782bb  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004782be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004782c0  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004782c3  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004782c6  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004782c9  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004782cc  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004782cf  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 004782d2  8a4003                 -mov al, byte ptr [eax + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004782d5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004782da  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004782dd  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004782e0  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004782e3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004782e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004782e7  90                     -nop 
    ;
    // 004782e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4782ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004782ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004782ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004782ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004782ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004782f0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004782f3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004782f5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004782f7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x004782f9:
    // 004782f9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004782fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004782fd  e856ffffff             -call 0x478258
    cpu.esp -= 4;
    sub_478258(app, cpu);
    if (cpu.terminate) return;
    // 00478302  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00478304  8a742402               -mov dh, byte ptr [esp + 2]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00478308  8a642403               -mov ah, byte ptr [esp + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 0047830c  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 0047830f  28e0                   -sub al, ah
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.ah));
    // 00478311  8a542401               -mov dl, byte ptr [esp + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00478315  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 00478319  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047831b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478320  e87bdd0100             -call 0x4960a0
    cpu.esp -= 4;
    sub_4960a0(app, cpu);
    if (cpu.terminate) return;
    // 00478325  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00478327  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 0047832a  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478330  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00478334  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00478338  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047833c  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0047833f  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478345  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478349  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0047834d  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 00478351  8a7c2408               -mov bh, byte ptr [esp + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478355  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00478357  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047835c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00478360  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478362  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478366  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047836a  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047836d  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00478370  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00478374  0fb6ee                 -movzx ebp, dh
    cpu.ebp = x86::reg32(cpu.dh);
    // 00478377  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0047837b  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0047837f  0fb6ef                 -movzx ebp, bh
    cpu.ebp = x86::reg32(cpu.bh);
    // 00478382  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00478385  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00478388  8a742408               -mov dh, byte ptr [esp + 8]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047838c  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00478390  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 00478393  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00478397  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0047839b  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004783a0  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004783a3  8a542408               -mov dl, byte ptr [esp + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004783a7  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004783aa  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004783b0  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004783b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004783b4  88f0                   -mov al, dh
    cpu.al = cpu.dh;
    // 004783b6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004783b9  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004783bf  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004783c2  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004783c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004783c6  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004783c8  46                     -inc esi
    (cpu.esi)++;
    // 004783c9  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004783cb  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004783ce  e849fdffff             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 004783d3  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004783d6  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004783d7  0f851cffffff           -jne 0x4782f9
    if (!cpu.flags.zf)
    {
        goto L_0x004782f9;
    }
    // 004783dd  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004783e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004783e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004783e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004783e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004783e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4783e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004783e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004783e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004783ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004783eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004783ec  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004783ef  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004783f1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004783f3  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x004783f5:
    // 004783f5  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004783f7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004783f9  e85afeffff             -call 0x478258
    cpu.esp -= 4;
    sub_478258(app, cpu);
    if (cpu.terminate) return;
    // 004783fe  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00478401  81fb00000010           +cmp ebx, 0x10000000
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
    // 00478407  7273                   -jb 0x47847c
    if (cpu.flags.cf)
    {
        goto L_0x0047847c;
    }
    // 00478409  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0047840f  7348                   -jae 0x478459
    if (!cpu.flags.cf)
    {
        goto L_0x00478459;
    }
    // 00478411  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00478414  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478416  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0047841b  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0047841e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00478420  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00478426  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00478429  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047842b  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047842e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00478430  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00478432  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00478435  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047843b  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0047843d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00478440  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478442  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478444  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00478447  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047844d  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047844f  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00478452  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00478457  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00478459:
    // 00478459  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047845b  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00478461  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00478464  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478466  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00478469  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0047846f  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00478472  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478475  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478477  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478479  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0047847c:
    // 0047847c  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047847f  83c704                 +add edi, 4
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
    // 00478482  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478483  0f856cffffff           -jne 0x4783f5
    if (!cpu.flags.zf)
    {
        goto L_0x004783f5;
    }
    // 00478489  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047848c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047848d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047848e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047848f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478490  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478494(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478494  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478495  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478496  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478497  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478498  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047849b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047849d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047849f  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x004784a1:
    // 004784a1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004784a3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004784a5  e8aefdffff             -call 0x478258
    cpu.esp -= 4;
    sub_478258(app, cpu);
    if (cpu.terminate) return;
    // 004784aa  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004784ad  81fb00000010           +cmp ebx, 0x10000000
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
    // 004784b3  726b                   -jb 0x478520
    if (cpu.flags.cf)
    {
        goto L_0x00478520;
    }
    // 004784b5  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004784bb  7340                   -jae 0x4784fd
    if (!cpu.flags.cf)
    {
        goto L_0x004784fd;
    }
    // 004784bd  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004784c0  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004784c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004784c4  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004784c7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004784ca  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004784cc  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004784d2  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004784d5  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004784da  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004784dd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004784df  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004784e1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004784e4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004784e6  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004784e9  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004784eb  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004784ee  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004784f4  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004784f9  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004784fb  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004784fd:
    // 004784fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004784ff  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00478505  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00478508  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047850a  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0047850d  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00478513  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00478516  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478519  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047851b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047851d  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00478520:
    // 00478520  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00478523  83c704                 +add edi, 4
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
    // 00478526  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478527  0f8574ffffff           -jne 0x4784a1
    if (!cpu.flags.zf)
    {
        goto L_0x004784a1;
    }
    // 0047852d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00478530  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478531  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478532  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478533  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478534  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478538  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478539  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047853a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047853b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047853e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478540  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x00478542:
    // 00478542  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00478544  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478546  e80dfdffff             -call 0x478258
    cpu.esp -= 4;
    sub_478258(app, cpu);
    if (cpu.terminate) return;
    // 0047854b  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 0047854d  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00478550  8a642403               -mov ah, byte ptr [esp + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 00478554  88542410               -mov byte ptr [esp + 0x10], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 00478558  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047855a  28e0                   -sub al, ah
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.ah));
    // 0047855c  88542414               -mov byte ptr [esp + 0x14], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dl;
    // 00478560  8a6102                 -mov ah, byte ptr [ecx + 2]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00478563  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478565  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00478567  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047856c  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047856f  0fb67c2402             -movzx edi, byte ptr [esp + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */));
    // 00478574  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00478577  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478579  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0047857d  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00478581  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00478585  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478587  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047858b  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047858e  0fb67c2401             -movzx edi, byte ptr [esp + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */));
    // 00478593  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00478596  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478598  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0047859c  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004785a0  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004785a4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004785a6  8a542414               -mov dl, byte ptr [esp + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004785aa  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004785ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004785af  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004785b2  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 004785b5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004785b7  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004785ba  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004785be  8861ff                 -mov byte ptr [ecx - 1], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 004785c1  8a64240c               -mov ah, byte ptr [esp + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004785c5  8861fe                 -mov byte ptr [ecx - 2], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ah;
    // 004785c8  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004785cb  8841fd                 -mov byte ptr [ecx - 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 004785ce  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004785cf  0f856dffffff           -jne 0x478542
    if (!cpu.flags.zf)
    {
        goto L_0x00478542;
    }
    // 004785d5  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004785d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4785dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004785dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004785dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004785de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004785df  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004785e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004785e4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x004785e6:
    // 004785e6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004785e8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004785ea  e869fcffff             -call 0x478258
    cpu.esp -= 4;
    sub_478258(app, cpu);
    if (cpu.terminate) return;
    // 004785ef  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 004785f1  2a642403               -sub ah, byte ptr [esp + 3]
    (cpu.ah) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */)));
    // 004785f5  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004785f8  88542410               -mov byte ptr [esp + 0x10], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004785fc  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004785fe  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00478601  88542414               -mov byte ptr [esp + 0x14], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dl;
    // 00478605  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478607  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00478609  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 0047860b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478610  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00478613  0fb67c2402             -movzx edi, byte ptr [esp + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */));
    // 00478618  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047861b  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047861d  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00478621  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00478625  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00478629  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047862b  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047862f  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00478632  0fb67c2401             -movzx edi, byte ptr [esp + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */));
    // 00478637  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047863a  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047863c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00478640  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00478644  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00478648  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047864a  8a542414               -mov dl, byte ptr [esp + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047864e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00478651  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478653  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00478656  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00478659  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047865c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047865e  c641ffff               -mov byte ptr [ecx - 1], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = 255 /*0xff*/;
    // 00478662  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478666  8861fe                 -mov byte ptr [ecx - 2], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ah;
    // 00478669  8a64240c               -mov ah, byte ptr [esp + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047866d  8861fd                 -mov byte ptr [ecx - 3], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-3) /* -0x3 */) = cpu.ah;
    // 00478670  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478673  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 00478676  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478677  0f8569ffffff           -jne 0x4785e6
    if (!cpu.flags.zf)
    {
        goto L_0x004785e6;
    }
    // 0047867d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00478680  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478681  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478682  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478683  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478684(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478684  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478685  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478686  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478687  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478688  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047868a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047868c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0047868e:
    // 0047868e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478690  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00478693  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047869a  8b1de4d15100           -mov ebx, dword ptr [0x51d1e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5362148) /* 0x51d1e4 */);
    // 004786a0  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 004786a3  45                     -inc ebp
    (cpu.ebp)++;
    // 004786a4  81fb00000010           +cmp ebx, 0x10000000
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
    // 004786aa  726b                   -jb 0x478717
    if (cpu.flags.cf)
    {
        goto L_0x00478717;
    }
    // 004786ac  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004786b2  7340                   -jae 0x4786f4
    if (!cpu.flags.cf)
    {
        goto L_0x004786f4;
    }
    // 004786b4  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004786b7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004786b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004786bb  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004786be  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004786c1  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004786c3  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004786c9  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004786cc  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004786d1  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004786d4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004786d6  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004786d8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004786db  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004786dd  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004786e0  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004786e2  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004786e5  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004786eb  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004786f0  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004786f2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004786f4:
    // 004786f4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004786f6  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004786fc  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004786ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478701  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00478704  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0047870a  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0047870d  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478710  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478712  01d3                   +add ebx, edx
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
    // 00478714  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00478717:
    // 00478717  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047871a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047871b  0f856dffffff           -jne 0x47868e
    if (!cpu.flags.zf)
    {
        goto L_0x0047868e;
    }
    // 00478721  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478722  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478723  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478724  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478725  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478728(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478728  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478729  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047872a  81ec08040000           -sub esp, 0x408
    (cpu.esp) -= x86::reg32(x86::sreg32(1032 /*0x408*/));
    // 00478730  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00478732  89942400040000         -mov dword ptr [esp + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.edx;
    // 00478739  899c2404040000         -mov dword ptr [esp + 0x404], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */) = cpu.ebx;
    // 00478740  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00478742  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00478744  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00478747  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 0047874d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047874f  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 00478754  8915d0a54c00           -mov dword ptr [0x4ca5d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5023184) /* 0x4ca5d0 */) = cpu.edx;
    // 0047875a  890dd8a54c00           -mov dword ptr [0x4ca5d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023192) /* 0x4ca5d8 */) = cpu.ecx;
    // 00478760  83f808                 +cmp eax, 8
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
    // 00478763  0f8593000000           -jne 0x4787fc
    if (!cpu.flags.zf)
    {
        goto L_0x004787fc;
    }
    // 00478769  803dd8a64c0010         +cmp byte ptr [0x4ca6d8], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478770  0f8586000000           -jne 0x4787fc
    if (!cpu.flags.zf)
    {
        goto L_0x004787fc;
    }
    // 00478776  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478777  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047877b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047877d  e886e10100             -call 0x496908
    cpu.esp -= 4;
    sub_496908(app, cpu);
    if (cpu.terminate) return;
    // 00478782  a3e4d15100             -mov dword ptr [0x51d1e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5362148) /* 0x51d1e4 */) = cpu.eax;
    // 00478787  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047878d  7d33                   -jge 0x4787c2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004787c2;
    }
    // 0047878f  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00478793  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00478795:
    // 00478795  8b15e4d15100           -mov edx, dword ptr [0x51d1e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362148) /* 0x51d1e4 */);
    // 0047879b  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004787a2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004787a4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004787a6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004787a8  41                     -inc ecx
    (cpu.ecx)++;
    // 004787a9  e8e6faffff             -call 0x478294
    cpu.esp -= 4;
    sub_478294(app, cpu);
    if (cpu.terminate) return;
    // 004787ae  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004787b1  81f900010000           +cmp ecx, 0x100
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004787b7  7cdc                   -jl 0x478795
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478795;
    }
    // 004787b9  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004787bd  a3e4d15100             -mov dword ptr [0x51d1e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5362148) /* 0x51d1e4 */) = cpu.eax;
L_0x004787c2:
    // 004787c2  bb84864700             -mov ebx, 0x478684
    cpu.ebx = 4687492 /*0x478684*/;
    // 004787c7  be7b000000             -mov esi, 0x7b
    cpu.esi = 123 /*0x7b*/;
    // 004787cc  891dd0a54c00           -mov dword ptr [0x4ca5d0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023184) /* 0x4ca5d0 */) = cpu.ebx;
    // 004787d2  8935d8a54c00           -mov dword ptr [0x4ca5d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5023192) /* 0x4ca5d8 */) = cpu.esi;
    // 004787d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004787d9:
    // 004787d9  b9b8a54c00             -mov ecx, 0x4ca5b8
    cpu.ecx = 5023160 /*0x4ca5b8*/;
    // 004787de  8b9c2404040000         -mov ebx, dword ptr [esp + 0x404]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */);
    // 004787e5  8b942400040000         -mov edx, dword ptr [esp + 0x400]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 004787ec  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004787ee  e8e9e80100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 004787f3  81c408040000           +add esp, 0x408
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1032 /*0x408*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004787f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004787fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004787fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004787fc:
    // 004787fc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004787fe  e81dfaffff             -call 0x478220
    cpu.esp -= 4;
    sub_478220(app, cpu);
    if (cpu.terminate) return;
    // 00478803  ebd4                   -jmp 0x4787d9
    goto L_0x004787d9;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478808(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478808  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478809  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047880a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047880b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047880d  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00478810  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00478813  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00478816  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00478819  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0047881c  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0047881f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00478821  e802ffffff             -call 0x478728
    cpu.esp -= 4;
    sub_478728(app, cpu);
    if (cpu.terminate) return;
    // 00478826  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478827  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478828  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478829  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47882c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047882c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047882d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00478830  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00478833  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00478835  8b7006                 -mov esi, dword ptr [eax + 6]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00478838  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0047883b  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047883d  e8e6feffff             -call 0x478728
    cpu.esp -= 4;
    sub_478728(app, cpu);
    if (cpu.terminate) return;
    // 00478842  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478843  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478852  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478853  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478854  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478856  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00478859  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047885b  7527                   -jne 0x478884
    if (!cpu.flags.zf)
    {
        goto L_0x00478884;
    }
L_0x0047885d:
    // 0047885d  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00478860  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00478862  7407                   -je 0x47886b
    if (cpu.flags.zf)
    {
        goto L_0x0047886b;
    }
    // 00478864  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478866  e8f1ed0100             -call 0x49765c
    cpu.esp -= 4;
    sub_49765c(app, cpu);
    if (cpu.terminate) return;
L_0x0047886b:
    // 0047886b  8b7130                 -mov esi, dword ptr [ecx + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0047886e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00478870  751e                   -jne 0x478890
    if (!cpu.flags.zf)
    {
        goto L_0x00478890;
    }
    // 00478872  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478874  c7016b4e4957           -mov dword ptr [ecx], 0x57494e6b
    app->getMemory<x86::reg32>(cpu.ecx) = 1464421995 /*0x57494e6b*/;
    // 0047887a  e80d1e0000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0047887f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478880  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478881  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478882  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478883  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478884:
    // 00478884  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00478889  e8ea040100             -call 0x488d78
    cpu.esp -= 4;
    sub_488d78(app, cpu);
    if (cpu.terminate) return;
    // 0047888e  ebcd                   -jmp 0x47885d
    goto L_0x0047885d;
L_0x00478890:
    // 00478890  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478892  e8c5ed0100             -call 0x49765c
    cpu.esp -= 4;
    sub_49765c(app, cpu);
    if (cpu.terminate) return;
    // 00478897  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478899  c7016b4e4957           -mov dword ptr [ecx], 0x57494e6b
    app->getMemory<x86::reg32>(cpu.ecx) = 1464421995 /*0x57494e6b*/;
    // 0047889f  e8e81d0000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 004788a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4788b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004788b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004788b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004788b3  7c49                   -jl 0x4788fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004788fe;
    }
L_0x004788b5:
    // 004788b5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004788b7  7c49                   -jl 0x478902
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478902;
    }
L_0x004788b9:
    // 004788b9  8b35c0a64c00           -mov esi, dword ptr [0x4ca6c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023424) /* 0x4ca6c0 */);
    // 004788bf  39f0                   +cmp eax, esi
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
    // 004788c1  7e02                   -jle 0x4788c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004788c5;
    }
    // 004788c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004788c5:
    // 004788c5  39f3                   +cmp ebx, esi
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
    // 004788c7  7e02                   -jle 0x4788cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004788cb;
    }
    // 004788c9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x004788cb:
    // 004788cb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004788cd  7c37                   -jl 0x478906
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478906;
    }
L_0x004788cf:
    // 004788cf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004788d1  7c37                   -jl 0x47890a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047890a;
    }
L_0x004788d3:
    // 004788d3  8b35c4a64c00           -mov esi, dword ptr [0x4ca6c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023428) /* 0x4ca6c4 */);
    // 004788d9  39f2                   +cmp edx, esi
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
    // 004788db  7e02                   -jle 0x4788df
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004788df;
    }
    // 004788dd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004788df:
    // 004788df  39f1                   +cmp ecx, esi
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
    // 004788e1  7e02                   -jle 0x4788e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004788e5;
    }
    // 004788e3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004788e5:
    // 004788e5  a3c8a64c00             -mov dword ptr [0x4ca6c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */) = cpu.eax;
    // 004788ea  891dd0a64c00           -mov dword ptr [0x4ca6d0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */) = cpu.ebx;
    // 004788f0  8915cca64c00           -mov dword ptr [0x4ca6cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */) = cpu.edx;
    // 004788f6  890dd4a64c00           -mov dword ptr [0x4ca6d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */) = cpu.ecx;
    // 004788fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004788fe:
    // 004788fe  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478900  ebb3                   -jmp 0x4788b5
    goto L_0x004788b5;
L_0x00478902:
    // 00478902  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00478904  ebb3                   -jmp 0x4788b9
    goto L_0x004788b9;
L_0x00478906:
    // 00478906  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00478908  ebc5                   -jmp 0x4788cf
    goto L_0x004788cf;
L_0x0047890a:
    // 0047890a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047890c  ebc5                   -jmp 0x4788d3
    goto L_0x004788d3;
}

/* align: skip 0x00 0x00 */
void Application::sub_478910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478910  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478911  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478912  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478913  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478914  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478916  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00478918  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047891a  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047891d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047891f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00478921  7e10                   -jle 0x478933
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478933;
    }
L_0x00478923:
    // 00478923  3b5810                 +cmp ebx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478926  7416                   -je 0x47893e
    if (cpu.flags.zf)
    {
        goto L_0x0047893e;
    }
    // 00478928  42                     -inc edx
    (cpu.edx)++;
    // 00478929  8b6908                 -mov ebp, dword ptr [ecx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047892c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047892f  39ea                   +cmp edx, ebp
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
    // 00478931  7cf0                   -jl 0x478923
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478923;
    }
L_0x00478933:
    // 00478933  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00478935  7511                   -jne 0x478948
    if (!cpu.flags.zf)
    {
        goto L_0x00478948;
    }
    // 00478937  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478939  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047893a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047893b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047893c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047893d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047893e:
    // 0047893e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00478941  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00478943  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478944  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478945  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478946  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478947  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478948:
    // 00478948  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047894a  e8e1220000             -call 0x47ac30
    cpu.esp -= 4;
    sub_47ac30(app, cpu);
    if (cpu.terminate) return;
    // 0047894f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478951  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478952  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478953  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478954  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478955  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478958(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478958  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478959  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047895b  e8b0ffffff             -call 0x478910
    cpu.esp -= 4;
    sub_478910(app, cpu);
    if (cpu.terminate) return;
    // 00478960  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478961  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478964(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478964  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478965  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047896a  e8a1ffffff             -call 0x478910
    cpu.esp -= 4;
    sub_478910(app, cpu);
    if (cpu.terminate) return;
    // 0047896f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478970  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478980  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478984(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478984  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478985  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478986  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478987  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478988  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047898b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047898d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047898f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00478991:
    // 00478991  80790300               +cmp byte ptr [ecx + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478995  750f                   -jne 0x4789a6
    if (!cpu.flags.zf)
    {
        goto L_0x004789a6;
    }
    // 00478997  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047899a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047899b  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047899c  75f3                   -jne 0x478991
    if (!cpu.flags.zf)
    {
        goto L_0x00478991;
    }
    // 0047899e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004789a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004789a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004789a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004789a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004789a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004789a6:
    // 004789a6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004789a8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004789ad  e8eed60100             -call 0x4960a0
    cpu.esp -= 4;
    sub_4960a0(app, cpu);
    if (cpu.terminate) return;
    // 004789b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004789b4  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 004789b9  0f84a8000000           -je 0x478a67
    if (cpu.flags.zf)
    {
        goto L_0x00478a67;
    }
    // 004789bf  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 004789c1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004789c3  8a5903                 -mov bl, byte ptr [ecx + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 004789c6  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 004789c9  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004789cc  28de                   -sub dh, bl
    (cpu.dh) -= x86::reg8(x86::sreg8(cpu.bl));
    // 004789ce  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004789d3  8a5902                 -mov bl, byte ptr [ecx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004789d6  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004789dc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004789df  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004789e1  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004789e4  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004789e7  887c240c               -mov byte ptr [esp + 0xc], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bh;
    // 004789eb  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 004789ee  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 004789f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004789f4  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 004789f6  88742404               -mov byte ptr [esp + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dh;
    // 004789fa  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004789fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004789ff  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00478a02  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00478a06  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00478a09  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00478a0c  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00478a0f  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00478a13  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478a19  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00478a1b  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00478a20  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00478a23  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00478a26  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00478a28  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478a2e  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00478a30  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00478a35  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00478a38  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00478a3b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00478a3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478a40  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00478a43  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00478a47  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00478a49  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 00478a4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478a4f  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00478a51  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478a53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478a55  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00478a58  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00478a5a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478a5c  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00478a5f  8a54240c               -mov dl, byte ptr [esp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00478a63  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478a65  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00478a67:
    // 00478a67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478a69  e8aef6ffff             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00478a6e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00478a70  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478a73  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00478a74  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478a75  0f8516ffffff           -jne 0x478991
    if (!cpu.flags.zf)
    {
        goto L_0x00478991;
    }
    // 00478a7b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00478a7e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a82  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478a84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478a84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478a85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478a86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478a87  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478a88  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478a8a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00478a8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00478a8e:
    // 00478a8e  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00478a90  81fb00000010           +cmp ebx, 0x10000000
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
    // 00478a96  7273                   -jb 0x478b0b
    if (cpu.flags.cf)
    {
        goto L_0x00478b0b;
    }
    // 00478a98  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00478a9e  7348                   -jae 0x478ae8
    if (!cpu.flags.cf)
    {
        goto L_0x00478ae8;
    }
    // 00478aa0  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00478aa3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478aa5  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 00478aaa  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 00478aad  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00478aaf  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00478ab5  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00478ab8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478aba  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478abd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00478abf  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00478ac1  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00478ac4  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478aca  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00478acc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00478acf  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478ad1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478ad3  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00478ad6  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478adc  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478ade  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00478ae1  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00478ae6  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00478ae8:
    // 00478ae8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478aea  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00478af0  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00478af3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478af5  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00478af8  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00478afe  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00478b01  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478b04  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478b06  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478b08  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00478b0b:
    // 00478b0b  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00478b0e  83c704                 +add edi, 4
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
    // 00478b11  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478b12  0f8576ffffff           -jne 0x478a8e
    if (!cpu.flags.zf)
    {
        goto L_0x00478a8e;
    }
    // 00478b18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478b20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478b21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478b22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478b23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478b24  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478b26  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00478b28  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00478b2a:
    // 00478b2a  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00478b2c  81fb00000010           +cmp ebx, 0x10000000
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
    // 00478b32  726b                   -jb 0x478b9f
    if (cpu.flags.cf)
    {
        goto L_0x00478b9f;
    }
    // 00478b34  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00478b3a  7340                   -jae 0x478b7c
    if (!cpu.flags.cf)
    {
        goto L_0x00478b7c;
    }
    // 00478b3c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00478b3f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00478b41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478b43  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00478b46  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00478b49  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00478b4b  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00478b51  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00478b54  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00478b59  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00478b5c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478b5e  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00478b60  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00478b63  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478b65  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00478b68  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478b6a  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00478b6d  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478b73  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00478b78  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00478b7a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00478b7c:
    // 00478b7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478b7e  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00478b84  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00478b87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478b89  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00478b8c  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00478b92  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00478b95  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478b98  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478b9a  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478b9c  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00478b9f:
    // 00478b9f  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00478ba2  83c704                 +add edi, 4
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
    // 00478ba5  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478ba6  7582                   -jne 0x478b2a
    if (!cpu.flags.zf)
    {
        goto L_0x00478b2a;
    }
    // 00478ba8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ba9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478baa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478bb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478bb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478bb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478bb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478bb4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00478bb7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00478bb9:
    // 00478bb9  80780300               +cmp byte ptr [eax + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478bbd  7511                   -jne 0x478bd0
    if (!cpu.flags.zf)
    {
        goto L_0x00478bd0;
    }
L_0x00478bbf:
    // 00478bbf  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00478bc2  83c203                 +add edx, 3
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478bc5  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478bc6  75f1                   -jne 0x478bb9
    if (!cpu.flags.zf)
    {
        goto L_0x00478bb9;
    }
    // 00478bc8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00478bcb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478bd0:
    // 00478bd0  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00478bd3  b3ff                   -mov bl, 0xff
    cpu.bl = 255 /*0xff*/;
    // 00478bd5  8a6a02                 -mov ch, byte ptr [edx + 2]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00478bd8  8a7803                 -mov bh, byte ptr [eax + 3]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00478bdb  886c2410               -mov byte ptr [esp + 0x10], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ch;
    // 00478bdf  28fb                   -sub bl, bh
    (cpu.bl) -= x86::reg8(x86::sreg8(cpu.bh));
    // 00478be1  0fb6742410             -movzx esi, byte ptr [esp + 0x10]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00478be6  885c240c               -mov byte ptr [esp + 0xc], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 00478bea  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00478bed  0fb674240c             -movzx esi, byte ptr [esp + 0xc]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00478bf2  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00478bf5  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00478bf8  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00478bfb  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00478bfe  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 00478c00  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00478c03  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 00478c06  8a6a01                 -mov ch, byte ptr [edx + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00478c09  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00478c0c  886c2408               -mov byte ptr [esp + 8], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ch;
    // 00478c10  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00478c13  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00478c18  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00478c1b  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 00478c1d  886c2404               -mov byte ptr [esp + 4], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ch;
    // 00478c21  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00478c24  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 00478c27  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00478c2d  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00478c2f  0fb66c2404             -movzx ebp, byte ptr [esp + 4]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 00478c34  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00478c37  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 00478c3a  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00478c3d  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00478c40  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 00478c43  01f5                   +add ebp, esi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478c45  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00478c48  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00478c4b  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 00478c4e  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00478c51  883a                   -mov byte ptr [edx], bh
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
    // 00478c53  e967ffffff             -jmp 0x478bbf
    goto L_0x00478bbf;
}

/* align: skip  */
void Application::sub_478c58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478c58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478c59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478c5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478c5b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478c5c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00478c5f  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x00478c61:
    // 00478c61  80780300               +cmp byte ptr [eax + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478c65  7511                   -jne 0x478c78
    if (!cpu.flags.zf)
    {
        goto L_0x00478c78;
    }
L_0x00478c67:
    // 00478c67  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00478c6a  83c204                 +add edx, 4
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
    // 00478c6d  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478c6e  75f1                   -jne 0x478c61
    if (!cpu.flags.zf)
    {
        goto L_0x00478c61;
    }
    // 00478c70  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00478c73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c74  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c77  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478c78:
    // 00478c78  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00478c7b  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00478c7e  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 00478c82  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 00478c84  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
    // 00478c88  807a0300               +cmp byte ptr [edx + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478c8c  0f84a1000000           -je 0x478d33
    if (cpu.flags.zf)
    {
        goto L_0x00478d33;
    }
    // 00478c92  b7ff                   -mov bh, 0xff
    cpu.bh = 255 /*0xff*/;
    // 00478c94  2a7803                 -sub bh, byte ptr [eax + 3]
    (cpu.bh) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */)));
    // 00478c97  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00478c9a  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 00478c9c  887c2408               -mov byte ptr [esp + 8], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.bh;
    // 00478ca0  886c240c               -mov byte ptr [esp + 0xc], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ch;
    // 00478ca4  0fb6f9                 -movzx edi, cl
    cpu.edi = x86::reg32(cpu.cl);
    // 00478ca7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478ca9  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478cad  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00478cb0  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00478cb3  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 00478cb6  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 00478cb9  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00478cbb  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00478cbf  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00478cc3  0fb6ff                 -movzx edi, bh
    cpu.edi = x86::reg32(cpu.bh);
    // 00478cc6  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00478cc9  0fb66c2414             -movzx ebp, byte ptr [esp + 0x14]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00478cce  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 00478cd1  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00478cd3  0fb67c240c             -movzx edi, byte ptr [esp + 0xc]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00478cd8  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00478cdb  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 00478cde  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00478ce2  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00478ce5  0fb67c2410             -movzx edi, byte ptr [esp + 0x10]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00478cea  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00478ced  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00478cef  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00478cf2  0fb67a03               -movzx edi, byte ptr [edx + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */));
    // 00478cf6  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 00478cfb  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00478cfd  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00478d00  8a7c2404               -mov bh, byte ptr [esp + 4]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00478d04  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
    // 00478d09  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00478d0c  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 00478d10  29cf                   +sub edi, ecx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478d12  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 00478d15  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00478d17  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
L_0x00478d1b:
    // 00478d1b  884a03                 -mov byte ptr [edx + 3], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 00478d1e  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00478d21  8a5c2414               -mov bl, byte ptr [esp + 0x14]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00478d25  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00478d28  8a5c2410               -mov bl, byte ptr [esp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00478d2c  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00478d2e  e934ffffff             -jmp 0x478c67
    goto L_0x00478c67;
L_0x00478d33:
    // 00478d33  8a4803                 -mov cl, byte ptr [eax + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00478d36  ebe3                   -jmp 0x478d1b
    goto L_0x00478d1b;
}

/* align: skip  */
void Application::sub_478d38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478d38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478d39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478d3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478d3b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478d3c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00478d3e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00478d40  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00478d42:
    // 00478d42  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478d44  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00478d47  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00478d4e  8b1decd15100           -mov ebx, dword ptr [0x51d1ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5362156) /* 0x51d1ec */);
    // 00478d54  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00478d57  45                     -inc ebp
    (cpu.ebp)++;
    // 00478d58  81fb00000010           +cmp ebx, 0x10000000
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
    // 00478d5e  7250                   -jb 0x478db0
    if (cpu.flags.cf)
    {
        goto L_0x00478db0;
    }
    // 00478d60  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00478d66  7345                   -jae 0x478dad
    if (!cpu.flags.cf)
    {
        goto L_0x00478dad;
    }
    // 00478d68  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478d6a  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00478d6d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00478d6f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478d71  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00478d74  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00478d77  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00478d79  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00478d7f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00478d82  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00478d87  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00478d8a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478d8c  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00478d8e  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00478d91  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478d93  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00478d96  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00478d9c  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 00478d9f  25e0070000             -and eax, 0x7e0
    cpu.eax &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00478da4  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478da6  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478da9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478dab  01cb                   +add ebx, ecx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00478dad:
    // 00478dad  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00478db0:
    // 00478db0  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00478db3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478db4  758c                   -jne 0x478d42
    if (!cpu.flags.zf)
    {
        goto L_0x00478d42;
    }
    // 00478db6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478db7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478db8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478db9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478dba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478dbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478dbc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478dbd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478dbe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478dbf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478dc0  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00478dc6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478dc8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00478dca  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00478dcc  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00478dcf  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00478dd5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478dd7  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 00478ddc  8915f4a54c00           -mov dword ptr [0x4ca5f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5023220) /* 0x4ca5f4 */) = cpu.edx;
    // 00478de2  890dfca54c00           -mov dword ptr [0x4ca5fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023228) /* 0x4ca5fc */) = cpu.ecx;
    // 00478de8  83f808                 +cmp eax, 8
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
    // 00478deb  752c                   -jne 0x478e19
    if (!cpu.flags.zf)
    {
        goto L_0x00478e19;
    }
    // 00478ded  803dd8a64c0010         +cmp byte ptr [0x4ca6d8], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478df4  7523                   -jne 0x478e19
    if (!cpu.flags.zf)
    {
        goto L_0x00478e19;
    }
    // 00478df6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00478df8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478dfa  bd388d4700             -mov ebp, 0x478d38
    cpu.ebp = 4689208 /*0x478d38*/;
    // 00478dff  e8ccdc0100             -call 0x496ad0
    cpu.esp -= 4;
    sub_496ad0(app, cpu);
    if (cpu.terminate) return;
    // 00478e04  a3ecd15100             -mov dword ptr [0x51d1ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5362156) /* 0x51d1ec */) = cpu.eax;
    // 00478e09  b87b000000             -mov eax, 0x7b
    cpu.eax = 123 /*0x7b*/;
    // 00478e0e  892df4a54c00           -mov dword ptr [0x4ca5f4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023220) /* 0x4ca5f4 */) = cpu.ebp;
    // 00478e14  a3fca54c00             -mov dword ptr [0x4ca5fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5023228) /* 0x4ca5fc */) = cpu.eax;
L_0x00478e19:
    // 00478e19  b9dca54c00             -mov ecx, 0x4ca5dc
    cpu.ecx = 5023196 /*0x4ca5dc*/;
    // 00478e1e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00478e20  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478e22  e8b5e20100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 00478e27  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00478e2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478e34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478e35  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478e36  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00478e39  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00478e3c  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00478e3f  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00478e42  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00478e45  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00478e48  e86fffffff             -call 0x478dbc
    cpu.esp -= 4;
    sub_478dbc(app, cpu);
    if (cpu.terminate) return;
    // 00478e4d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478e51  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00478e54  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00478e57  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478e59  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00478e5c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00478e5f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478e61  e856ffffff             -call 0x478dbc
    cpu.esp -= 4;
    sub_478dbc(app, cpu);
    if (cpu.terminate) return;
    // 00478e66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478e68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e68  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00478e6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478e6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e6e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00478e70  030564d25100           -add eax, dword ptr [0x51d264]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */)));
    // 00478e76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478e77(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e77  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478e78  8b1504a64c00           -mov edx, dword ptr [0x4ca604]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023236) /* 0x4ca604 */);
    // 00478e7e  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00478e83  a304a64c00             -mov dword ptr [0x4ca604], eax
    app->getMemory<x86::reg32>(x86::reg32(5023236) /* 0x4ca604 */) = cpu.eax;
    // 00478e88  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00478e8a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478e8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e8c  c70564d2510000000000   -mov dword ptr [0x51d264], 0
    app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */) = 0 /*0x0*/;
    // 00478e96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478e97(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e97  030564d25100           -add eax, dword ptr [0x51d264]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */)));
    // 00478e9d  a300a64c00             -mov dword ptr [0x4ca600], eax
    app->getMemory<x86::reg32>(x86::reg32(5023232) /* 0x4ca600 */) = cpu.eax;
    // 00478ea2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478ea3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00478ea3:
    // 00478ea3  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00478ea8  2b0500a64c00           +sub eax, dword ptr [0x4ca600]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023232) /* 0x4ca600 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 00478eae  78f3                   -js 0x478ea3
    if (cpu.flags.sf)
    {
        goto L_0x00478ea3;
    }
    // 00478eb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478eb1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478eb1  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00478eb6  2b0500a64c00           +sub eax, dword ptr [0x4ca600]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023232) /* 0x4ca600 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478ebc  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00478ebe  40                     -inc eax
    (cpu.eax)++;
    // 00478ebf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478ec0  030564d25100           -add eax, dword ptr [0x51d264]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */)));
    // 00478ec6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
L_0x00478ec7:
    // 00478ec7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478ec9  e8720d0000             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00478ece  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00478ed3  2b0424                 +sub eax, dword ptr [esp]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478ed6  78ef                   -js 0x478ec7
    if (cpu.flags.sf)
    {
        goto L_0x00478ec7;
    }
    // 00478ed8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00478edb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_478ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478ee0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478ee1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478ee2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478ee3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00478ee6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00478ee8  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00478eeb  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00478eee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478ef0  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00478ef4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00478ef7  e820f0ffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00478efc  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00478eff  39c3                   +cmp ebx, eax
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
    // 00478f01  0f8c69000000           -jl 0x478f70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478f70;
    }
L_0x00478f07:
    // 00478f07  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00478f0a  39c1                   +cmp ecx, eax
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
    // 00478f0c  7d0e                   -jge 0x478f1c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478f1c;
    }
    // 00478f0e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478f10  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00478f13  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00478f16  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00478f18  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00478f1a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00478f1c:
    // 00478f1c  8d0433                 -lea eax, [ebx + esi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 00478f1f  3b4214                 +cmp eax, dword ptr [edx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478f22  7e05                   -jle 0x478f29
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478f29;
    }
    // 00478f24  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00478f27  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00478f29:
    // 00478f29  8d0439                 -lea eax, [ecx + edi]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 00478f2c  3b4218                 +cmp eax, dword ptr [edx + 0x18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478f2f  7e05                   -jle 0x478f36
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478f36;
    }
    // 00478f31  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00478f34  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00478f36:
    // 00478f36  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00478f38  7e2d                   -jle 0x478f67
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478f67;
    }
    // 00478f3a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00478f3c  7e29                   -jle 0x478f67
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478f67;
    }
    // 00478f3e  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00478f42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478f44  7405                   -je 0x478f4b
    if (cpu.flags.zf)
    {
        goto L_0x00478f4b;
    }
    // 00478f46  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x00478f4b:
    // 00478f4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478f4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478f4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478f4e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478f4f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478f50  8b4a34                 -mov ecx, dword ptr [edx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 00478f53  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478f54  8b4534                 -mov eax, dword ptr [ebp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 00478f57  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00478f5b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478f5c  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00478f60  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00478f62  e8c1000100             -call 0x489028
    cpu.esp -= 4;
    sub_489028(app, cpu);
    if (cpu.terminate) return;
L_0x00478f67:
    // 00478f67  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00478f6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f6d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00478f70:
    // 00478f70  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478f72  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00478f76  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00478f79  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00478f7b  01de                   +add esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478f7d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478f7f  eb86                   -jmp 0x478f07
    goto L_0x00478f07;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478f84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478f84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478f85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478f86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478f87  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00478f8a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478f8c  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00478f8e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00478f90  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00478f92  8b4d04                 -mov ecx, dword ptr [ebp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00478f95  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478f97  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00478f9a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00478f9e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00478fa1  e876efffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00478fa6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00478fa8  7c2d                   -jl 0x478fd7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478fd7;
    }
L_0x00478faa:
    // 00478faa  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00478fac  7c3b                   -jl 0x478fe9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478fe9;
    }
L_0x00478fae:
    // 00478fae  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 00478fb1  3b4704                 +cmp eax, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478fb4  7e05                   -jle 0x478fbb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478fbb;
    }
    // 00478fb6  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00478fb9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00478fbb:
    // 00478fbb  8d0433                 -lea eax, [ebx + esi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 00478fbe  3b4708                 +cmp eax, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478fc1  7e05                   -jle 0x478fc8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478fc8;
    }
    // 00478fc3  8b7708                 -mov esi, dword ptr [edi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00478fc6  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00478fc8:
    // 00478fc8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00478fca  7e04                   -jle 0x478fd0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478fd0;
    }
    // 00478fcc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00478fce  7f29                   -jg 0x478ff9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00478ff9;
    }
L_0x00478fd0:
    // 00478fd0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00478fd3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478fd4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478fd5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478fd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478fd7:
    // 00478fd7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00478fdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478fdd  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478fdf  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00478fe1  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00478fe3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00478fe7  ebc1                   -jmp 0x478faa
    goto L_0x00478faa;
L_0x00478fe9:
    // 00478fe9  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00478fec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478fee  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00478ff0  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00478ff2  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00478ff4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00478ff7  ebb5                   -jmp 0x478fae
    goto L_0x00478fae;
L_0x00478ff9:
    // 00478ff9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478ffb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478ffc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478ffd  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00479001  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479002  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00479006  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479007  8b4534                 -mov eax, dword ptr [ebp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 0047900a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047900b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047900c  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0047900f  e814000100             -call 0x489028
    cpu.esp -= 4;
    sub_489028(app, cpu);
    if (cpu.terminate) return;
    // 00479014  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479017  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479018  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479019  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047901a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47901c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047901c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047901d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047901e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047901f  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00479023  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479025  e8f2eeffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0047902a  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047902d  39ea                   +cmp edx, ebp
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
    // 0047902f  7d06                   -jge 0x479037
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479037;
    }
    // 00479031  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00479033  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00479035  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
L_0x00479037:
    // 00479037  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047903a  39eb                   +cmp ebx, ebp
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
    // 0047903c  7d06                   -jge 0x479044
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479044;
    }
    // 0047903e  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00479040  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00479042  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
L_0x00479044:
    // 00479044  8b6e14                 -mov ebp, dword ptr [esi + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00479047  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0047904a  39e8                   +cmp eax, ebp
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
    // 0047904c  7e04                   -jle 0x479052
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00479052;
    }
    // 0047904e  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00479050  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00479052:
    // 00479052  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00479055  8d043b                 -lea eax, [ebx + edi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edi * 1);
    // 00479058  39e8                   +cmp eax, ebp
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
    // 0047905a  7e04                   -jle 0x479060
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00479060;
    }
    // 0047905c  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047905e  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00479060:
    // 00479060  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00479062  7e04                   -jle 0x479068
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00479068;
    }
    // 00479064  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00479066  7f06                   -jg 0x47906e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047906e;
    }
L_0x00479068:
    // 00479068  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479069  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047906a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047906b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0047906e:
    // 0047906e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00479072  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479073  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479074  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 00479077  e838ff0000             -call 0x488fb4
    cpu.esp -= 4;
    sub_488fb4(app, cpu);
    if (cpu.terminate) return;
    // 0047907c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047907d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047907e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047907f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479084(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479084  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479085  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479086  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479087  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047908a  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047908e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00479091  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00479093  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00479095  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00479097  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00479099  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047909c  c1e810                 +shr eax, 0x10
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
    // 0047909f  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004790a1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004790a5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004790a7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004790ab  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004790ad  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004790af  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004790b2  c1e810                 +shr eax, 0x10
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
    // 004790b5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004790b7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004790b9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004790bb  e85ceeffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 004790c0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004790c2  7e47                   -jle 0x47910b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047910b;
    }
    // 004790c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004790c6  7e43                   -jle 0x47910b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047910b;
    }
    // 004790c8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004790ca  7e3f                   -jle 0x47910b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047910b;
    }
    // 004790cc  837c241800             +cmp dword ptr [esp + 0x18], 0
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
    // 004790d1  7e38                   -jle 0x47910b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047910b;
    }
    // 004790d3  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004790d8  743a                   -je 0x479114
    if (cpu.flags.zf)
    {
        goto L_0x00479114;
    }
    // 004790da  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
L_0x004790df:
    // 004790df  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004790e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004790e1  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004790e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004790e6  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004790ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004790eb  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004790ef  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004790f3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004790f4  8b7834                 -mov edi, dword ptr [eax + 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004790f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004790f8  8b6c2430               -mov ebp, dword ptr [esp + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004790fc  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00479100  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479101  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00479103  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00479106  e81dff0000             -call 0x489028
    cpu.esp -= 4;
    sub_489028(app, cpu);
    if (cpu.terminate) return;
L_0x0047910b:
    // 0047910b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047910e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047910f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479110  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479111  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00479114:
    // 00479114  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00479116  ebc7                   -jmp 0x4790df
    goto L_0x004790df;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00479160  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479161  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479162  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479163  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479165  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00479167  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479169  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047916b  7411                   -je 0x47917e
    if (cpu.flags.zf)
    {
        goto L_0x0047917e;
    }
    // 0047916d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047916f:
    // 0047916f  48                     -dec eax
    (cpu.eax)--;
    // 00479170  83f8ff                 +cmp eax, -1
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
    // 00479173  7409                   -je 0x47917e
    if (cpu.flags.zf)
    {
        goto L_0x0047917e;
    }
    // 00479175  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00479176  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00479178  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00479179  8857ff                 -mov byte ptr [edi - 1], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0047917c  ebf1                   -jmp 0x47916f
    goto L_0x0047916f;
L_0x0047917e:
    // 0047917e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00479180  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00479182  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00479184  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00479187  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00479189  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047918b  c1fd06                 -sar ebp, 6
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (6 /*0x6*/ % 32));
    // 0047918e  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00479191  83e303                 -and ebx, 3
    cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00479194  83fe0f                 +cmp esi, 0xf
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
    // 00479197  0f87c6000000           -ja 0x479263
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00479263;
    }
    // 0047919d  ff24b520914700         -jmp dword ptr [esi*4 + 0x479120]
    cpu.ip = app->getMemory<x86::reg32>(4690208 + cpu.esi * 4); goto dynamic_jump;
  case 0x004791a4:
L_0x004791a4:
    // 004791a4  4d                     -dec ebp
    (cpu.ebp)--;
    // 004791a5  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004791a8  0f84b5000000           -je 0x479263
    if (cpu.flags.zf)
    {
        goto L_0x00479263;
    }
    // 004791ae  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791b1  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004791b3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791b6  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004791b9:
    // 004791b9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791bc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004791be  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791c1  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004791c4:
    // 004791c4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791c7  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004791c9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791cc  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004791cf:
    // 004791cf  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791d2  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004791d4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791d7  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004791da:
    // 004791da  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791dd  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004791df  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791e2  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004791e5:
    // 004791e5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791e8  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004791ea  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791ed  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004791f0:
    // 004791f0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791f3  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004791f5  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791f8  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004791fb:
    // 004791fb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791fe  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479200  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479203  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00479206:
    // 00479206  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479209  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047920b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047920e  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00479211:
    // 00479211  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479214  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479216  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479219  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x0047921c:
    // 0047921c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047921f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479221  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479224  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00479227:
    // 00479227  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047922a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0047922c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047922f  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00479232:
    // 00479232  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479235  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00479237  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047923a  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x0047923d:
    // 0047923d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479240  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00479242  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479245  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00479248:
    // 00479248  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047924b  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0047924d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479250  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00479253:
    // 00479253  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479256  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00479258  83c204                 +add edx, 4
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
    // 0047925b  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0047925e  e941ffffff             -jmp 0x4791a4
    goto L_0x004791a4;
L_0x00479263:
    // 00479263  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00479265:
    // 00479265  4b                     -dec ebx
    (cpu.ebx)--;
    // 00479266  83fbff                 +cmp ebx, -1
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
    // 00479269  740d                   -je 0x479278
    if (cpu.flags.zf)
    {
        goto L_0x00479278;
    }
    // 0047926b  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0047926e  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 00479271  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00479273  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00479274  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 00479276  ebed                   -jmp 0x479265
    goto L_0x00479265;
L_0x00479278:
    // 00479278  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479279  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047927a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047927b  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_47927c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047927c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047927d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047927e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479280  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00479282  83fb04                 +cmp ebx, 4
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
    // 00479285  7d13                   -jge 0x47929a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047929a;
    }
L_0x00479287:
    // 00479287  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00479289  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047928b:
    // 0047928b  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047928c  83fbff                 +cmp ebx, -1
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
    // 0047928f  742a                   -je 0x4792bb
    if (cpu.flags.zf)
    {
        goto L_0x004792bb;
    }
    // 00479291  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00479292  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00479295  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00479296  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00479298  ebf1                   -jmp 0x47928b
    goto L_0x0047928b;
L_0x0047929a:
    // 0047929a  39c2                   +cmp edx, eax
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
    // 0047929c  7607                   -jbe 0x4792a5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004792a5;
    }
    // 0047929e  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004792a1  39ca                   +cmp edx, ecx
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
    // 004792a3  72e2                   -jb 0x479287
    if (cpu.flags.cf)
    {
        goto L_0x00479287;
    }
L_0x004792a5:
    // 004792a5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004792a7  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004792ac  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004792af  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004792b1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004792b3  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004792b6  e8a5feffff             -call 0x479160
    cpu.esp -= 4;
    sub_479160(app, cpu);
    if (cpu.terminate) return;
L_0x004792bb:
    // 004792bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4792c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004792c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004792c1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004792c3  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 004792c5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004792c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004792c9  e8aeffffff             -call 0x47927c
    cpu.esp -= 4;
    sub_47927c(app, cpu);
    if (cpu.terminate) return;
    // 004792ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4792d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004792d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004792d1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004792d3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004792d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004792d7  e8a0ffffff             -call 0x47927c
    cpu.esp -= 4;
    sub_47927c(app, cpu);
    if (cpu.terminate) return;
    // 004792dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4792e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004792e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004792e1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004792e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004792e5  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004792e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004792e9  e88effffff             -call 0x47927c
    cpu.esp -= 4;
    sub_47927c(app, cpu);
    if (cpu.terminate) return;
    // 004792ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4792f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004792f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004792f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004792f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004792f4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004792f6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004792f8  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004792fb  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004792fd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004792ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00479301  e876ffffff             -call 0x47927c
    cpu.esp -= 4;
    sub_47927c(app, cpu);
    if (cpu.terminate) return;
    // 00479306  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479307  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479308  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47930c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047930c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047930d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047930f  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00479312  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479314  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479316  e861ffffff             -call 0x47927c
    cpu.esp -= 4;
    sub_47927c(app, cpu);
    if (cpu.terminate) return;
    // 0047931b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047931c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479321  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479322  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479323  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479324  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479326  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00479328  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047932a  b908a64c00             -mov ecx, 0x4ca608
    cpu.ecx = 5023240 /*0x4ca608*/;
    // 0047932f  e8a8dd0100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 00479334  6681660c00f0           -and word ptr [esi + 0xc], 0xf000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg16(x86::sreg16(61440 /*0xf000*/));
    // 0047933a  81e7ff0f0000           -and edi, 0xfff
    cpu.edi &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00479340  097e0c                 -or dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.edi));
    // 00479343  668b5e0e               -mov bx, word ptr [esi + 0xe]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 00479347  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0047934d  81e5ff0f0000           -and ebp, 0xfff
    cpu.ebp &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00479353  66895e0e               -mov word ptr [esi + 0xe], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.bx;
    // 00479357  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 0047935a  096e0c                 -or dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047935d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047935e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047935f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479360  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479361  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479364(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479364  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479365  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479366  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00479369  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047936c  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047936f  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00479372  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00479375  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00479378  e8a3ffffff             -call 0x479320
    cpu.esp -= 4;
    sub_479320(app, cpu);
    if (cpu.terminate) return;
    // 0047937d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047937e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047937f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479380  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479381  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479384  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00479387  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479389  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047938c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047938f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479391  e88affffff             -call 0x479320
    cpu.esp -= 4;
    sub_479320(app, cpu);
    if (cpu.terminate) return;
    // 00479396  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479397  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479398(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479398  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479399  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047939a  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047939d  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004793a0  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004793a3  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004793a6  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004793a9  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004793ac  e86fffffff             -call 0x479320
    cpu.esp -= 4;
    sub_479320(app, cpu);
    if (cpu.terminate) return;
    // 004793b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4793b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004793b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004793b5  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004793b8  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004793bb  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004793bd  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004793c0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004793c3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004793c5  e856ffffff             -call 0x479320
    cpu.esp -= 4;
    sub_479320(app, cpu);
    if (cpu.terminate) return;
    // 004793ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4793d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004793d0  d1fb                   +sar ebx, 1
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
    // 004793d2  e90de30100             -jmp 0x4976e4
    return sub_4976e4(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4793d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004793d8  01db                   +add ebx, ebx
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
    // 004793da  e905e30100             -jmp 0x4976e4
    return sub_4976e4(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4793e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004793e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004793e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004793e3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004793ea  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004793ec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004793ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004793f0  e8efe20100             -call 0x4976e4
    cpu.esp -= 4;
    sub_4976e4(app, cpu);
    if (cpu.terminate) return;
    // 004793f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4793f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004793f8  c1e302                 +shl ebx, 2
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
    // 004793fb  e9e4e20100             -jmp 0x4976e4
    return sub_4976e4(app, cpu);
}

/* align: skip  */
void Application::sub_479400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479400  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479401  b92ca64c00             -mov ecx, 0x4ca62c
    cpu.ecx = 5023276 /*0x4ca62c*/;
    // 00479406  e8d1dc0100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 0047940b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047940c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479411  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479412  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479413  b92ca64c00             -mov ecx, 0x4ca62c
    cpu.ecx = 5023276 /*0x4ca62c*/;
    // 00479418  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047941b  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047941e  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00479421  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00479424  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00479427  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0047942a  e8addc0100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 0047942f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479430  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479431  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479432  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_479434(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479434  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479435  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479438  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047943b  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047943d  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00479440  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00479443  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479445  b92ca64c00             -mov ecx, 0x4ca62c
    cpu.ecx = 5023276 /*0x4ca62c*/;
    // 0047944a  e88ddc0100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 0047944f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479450  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479454(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479454  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479455  b92ca64c00             -mov ecx, 0x4ca62c
    cpu.ecx = 5023276 /*0x4ca62c*/;
    // 0047945a  e87ddc0100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 0047945f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479460  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479464(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479464  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479465  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479466  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479467  b92ca64c00             -mov ecx, 0x4ca62c
    cpu.ecx = 5023276 /*0x4ca62c*/;
    // 0047946c  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047946f  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00479472  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00479475  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00479478  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0047947b  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0047947e  e859dc0100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 00479483  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479484  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479485  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479486  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_479488(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479488  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479489  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047948c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047948f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479491  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00479494  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00479497  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479499  b92ca64c00             -mov ecx, 0x4ca62c
    cpu.ecx = 5023276 /*0x4ca62c*/;
    // 0047949e  e839dc0100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 004794a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004794a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4794b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004794b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004794b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004794b2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004794b4  39d0                   +cmp eax, edx
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
    // 004794b6  746c                   -je 0x479524
    if (cpu.flags.zf)
    {
        goto L_0x00479524;
    }
L_0x004794b8:
    // 004794b8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004794ba  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004794bc  39c1                   +cmp ecx, eax
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
    // 004794be  7569                   -jne 0x479529
    if (!cpu.flags.zf)
    {
        goto L_0x00479529;
    }
    // 004794c0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004794c2  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 004794c7  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004794c9  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 004794ce  7554                   -jne 0x479524
    if (!cpu.flags.zf)
    {
        goto L_0x00479524;
    }
    // 004794d0  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004794d3  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004794d6  39c1                   +cmp ecx, eax
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
    // 004794d8  754f                   -jne 0x479529
    if (!cpu.flags.zf)
    {
        goto L_0x00479529;
    }
    // 004794da  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004794dc  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 004794e1  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004794e3  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 004794e8  753a                   -jne 0x479524
    if (!cpu.flags.zf)
    {
        goto L_0x00479524;
    }
    // 004794ea  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004794ed  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004794f0  39c1                   +cmp ecx, eax
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
    // 004794f2  7535                   -jne 0x479529
    if (!cpu.flags.zf)
    {
        goto L_0x00479529;
    }
    // 004794f4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004794f6  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 004794fb  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004794fd  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00479502  7520                   -jne 0x479524
    if (!cpu.flags.zf)
    {
        goto L_0x00479524;
    }
    // 00479504  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00479507  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047950a  39c1                   +cmp ecx, eax
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
    // 0047950c  751b                   -jne 0x479529
    if (!cpu.flags.zf)
    {
        goto L_0x00479529;
    }
    // 0047950e  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00479511  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00479514  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00479516  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 0047951b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047951d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00479522  7494                   -je 0x4794b8
    if (cpu.flags.zf)
    {
        goto L_0x004794b8;
    }
L_0x00479524:
    // 00479524  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00479526  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479527  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479528  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479529:
    // 00479529  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047952b  751d                   -jne 0x47954a
    if (!cpu.flags.zf)
    {
        goto L_0x0047954a;
    }
    // 0047952d  3c00                   +cmp al, 0
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
    // 0047952f  74f3                   -je 0x479524
    if (cpu.flags.zf)
    {
        goto L_0x00479524;
    }
    // 00479531  38ec                   +cmp ah, ch
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479533  7515                   -jne 0x47954a
    if (!cpu.flags.zf)
    {
        goto L_0x0047954a;
    }
    // 00479535  80fc00                 +cmp ah, 0
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479538  74ea                   -je 0x479524
    if (cpu.flags.zf)
    {
        goto L_0x00479524;
    }
    // 0047953a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0047953d  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00479540  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479542  7506                   -jne 0x47954a
    if (!cpu.flags.zf)
    {
        goto L_0x0047954a;
    }
    // 00479544  3c00                   +cmp al, 0
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
    // 00479546  74dc                   -je 0x479524
    if (cpu.flags.zf)
    {
        goto L_0x00479524;
    }
    // 00479548  38ec                   +cmp ah, ch
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x0047954a:
    // 0047954a  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0047954c  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0047954e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047954f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479550  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479562  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479563  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479564  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479565  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479566  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047956d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047956f  e818750000             -call 0x480a8c
    cpu.esp -= 4;
    sub_480a8c(app, cpu);
    if (cpu.terminate) return;
    // 00479574  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479576  a348d25100             -mov dword ptr [0x51d248], eax
    app->getMemory<x86::reg32>(x86::reg32(5362248) /* 0x51d248 */) = cpu.eax;
    // 0047957b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047957d:
    // 0047957d  a148d25100             -mov eax, dword ptr [0x51d248]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362248) /* 0x51d248 */);
    // 00479582  e855750000             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 00479587  3b3d40d25100           +cmp edi, dword ptr [0x51d240]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362240) /* 0x51d240 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047958d  7463                   -je 0x4795f2
    if (cpu.flags.zf)
    {
        goto L_0x004795f2;
    }
    // 0047958f  ff0564d25100           -inc dword ptr [0x51d264]
    (app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */))++;
    // 00479595  ff0560d25100           -inc dword ptr [0x51d260]
    (app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */))++;
    // 0047959b  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004795a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004795a4  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004795a6  69d2a9040000           -imul edx, edx, 0x4a9
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(1193 /*0x4a9*/)));
    // 004795ac  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004795ae  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004795b0  81fbffff0000           +cmp ebx, 0xffff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004795b6  7e11                   -jle 0x4795c9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004795c9;
    }
    // 004795b8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004795ba  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004795bd  010544d25100           -add dword ptr [0x51d244], eax
    (app->getMemory<x86::reg32>(x86::reg32(5362244) /* 0x51d244 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004795c3  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x004795c9:
    // 004795c9  8b2df0d15100           -mov ebp, dword ptr [0x51d1f0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5362160) /* 0x51d1f0 */);
    // 004795cf  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004795d1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004795d3  39ef                   +cmp edi, ebp
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
    // 004795d5  74a6                   -je 0x47957d
    if (cpu.flags.zf)
    {
        goto L_0x0047957d;
    }
L_0x004795d7:
    // 004795d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004795d9  41                     -inc ecx
    (cpu.ecx)++;
    // 004795da  ff90f0d15100           -call dword ptr [eax + 0x51d1f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362160) /* 0x51d1f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004795e0  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004795e3  83f908                 +cmp ecx, 8
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
    // 004795e6  7395                   -jae 0x47957d
    if (!cpu.flags.cf)
    {
        goto L_0x0047957d;
    }
    // 004795e8  3bbaf0d15100           +cmp edi, dword ptr [edx + 0x51d1f0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5362160) /* 0x51d1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004795ee  75e7                   -jne 0x4795d7
    if (!cpu.flags.zf)
    {
        goto L_0x004795d7;
    }
    // 004795f0  eb8b                   -jmp 0x47957d
    goto L_0x0047957d;
L_0x004795f2:
    // 004795f2  a148d25100             -mov eax, dword ptr [0x51d248]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362248) /* 0x51d248 */);
    // 004795f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004795f9  e86a750000             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 004795fe  891548d25100           -mov dword ptr [0x51d248], edx
    app->getMemory<x86::reg32>(x86::reg32(5362248) /* 0x51d248 */) = cpu.edx;
    // 00479604  891520a44c00           -mov dword ptr [0x4ca420], edx
    app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */) = cpu.edx;
    // 0047960a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047960b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047960c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047960d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047960e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047960f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479610  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479614(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479614  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479615  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479616  e871740000             -call 0x480a8c
    cpu.esp -= 4;
    sub_480a8c(app, cpu);
    if (cpu.terminate) return;
    // 0047961b  8b151cd25100           -mov edx, dword ptr [0x51d21c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362204) /* 0x51d21c */);
    // 00479621  a33cd25100             -mov dword ptr [0x51d23c], eax
    app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */) = cpu.eax;
    // 00479626  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479628  741a                   -je 0x479644
    if (cpu.flags.zf)
    {
        goto L_0x00479644;
    }
L_0x0047962a:
    // 0047962a  ff151cd25100           -call dword ptr [0x51d21c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5362204) /* 0x51d21c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479630  a13cd25100             -mov eax, dword ptr [0x51d23c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */);
    // 00479635  e8a2740000             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0047963a  833d1cd2510000         +cmp dword ptr [0x51d21c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362204) /* 0x51d21c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479641  75e7                   -jne 0x47962a
    if (!cpu.flags.zf)
    {
        goto L_0x0047962a;
    }
    // 00479643  90                     -nop 
    ;
L_0x00479644:
    // 00479644  a13cd25100             -mov eax, dword ptr [0x51d23c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */);
    // 00479649  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047964b  e818750000             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 00479650  891d3cd25100           -mov dword ptr [0x51d23c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */) = cpu.ebx;
    // 00479656  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479657  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479658  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47965c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047965c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047965d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047965e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047965f  a31cd25100             -mov dword ptr [0x51d21c], eax
    app->getMemory<x86::reg32>(x86::reg32(5362204) /* 0x51d21c */) = cpu.eax;
    // 00479664  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479666  740a                   -je 0x479672
    if (cpu.flags.zf)
    {
        goto L_0x00479672;
    }
    // 00479668  8b153cd25100           -mov edx, dword ptr [0x51d23c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */);
    // 0047966e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479670  741a                   -je 0x47968c
    if (cpu.flags.zf)
    {
        goto L_0x0047968c;
    }
L_0x00479672:
    // 00479672  833d1cd2510000         +cmp dword ptr [0x51d21c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362204) /* 0x51d21c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479679  750d                   -jne 0x479688
    if (!cpu.flags.zf)
    {
        goto L_0x00479688;
    }
    // 0047967b  8b1d3cd25100           -mov ebx, dword ptr [0x51d23c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */);
    // 00479681  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479683  753e                   -jne 0x4796c3
    if (!cpu.flags.zf)
    {
        goto L_0x004796c3;
    }
    // 00479685  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00479688:
    // 00479688  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479689  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047968a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047968b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047968c:
    // 0047968c  6820d25100             -push 0x51d220
    app->getMemory<x86::reg32>(cpu.esp-4) = 5362208 /*0x51d220*/;
    cpu.esp -= 4;
    // 00479691  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00479696  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047969b  b814964700             -mov eax, 0x479614
    cpu.eax = 4691476 /*0x479614*/;
    // 004796a0  e8bb700000             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 004796a5  833d3cd2510000         +cmp dword ptr [0x51d23c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004796ac  75da                   -jne 0x479688
    if (!cpu.flags.zf)
    {
        goto L_0x00479688;
    }
    // 004796ae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004796b0:
    // 004796b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004796b2  e865710000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 004796b7  3b153cd25100           +cmp edx, dword ptr [0x51d23c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004796bd  74f1                   -je 0x4796b0
    if (cpu.flags.zf)
    {
        goto L_0x004796b0;
    }
    // 004796bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004796c3:
    // 004796c3  b820d25100             -mov eax, 0x51d220
    cpu.eax = 5362208 /*0x51d220*/;
    // 004796c8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004796ca  e8d1730000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 004796cf  833d3cd2510000         +cmp dword ptr [0x51d23c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004796d6  74b0                   -je 0x479688
    if (cpu.flags.zf)
    {
        goto L_0x00479688;
    }
    // 004796d8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004796da:
    // 004796da  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004796dc  e83b710000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 004796e1  3b153cd25100           +cmp edx, dword ptr [0x51d23c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004796e7  75f1                   -jne 0x4796da
    if (!cpu.flags.zf)
    {
        goto L_0x004796da;
    }
    // 004796e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4796f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004796f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004796f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004796f3:
    // 004796f3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004796f6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004796f8  8990ecd15100           -mov dword ptr [eax + 0x51d1ec], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362156) /* 0x51d1ec */) = cpu.edx;
    // 004796fe  83f820                 +cmp eax, 0x20
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
    // 00479701  75f0                   -jne 0x4796f3
    if (!cpu.flags.zf)
    {
        goto L_0x004796f3;
    }
    // 00479703  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479704  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479708(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479708  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479709  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047970a  a110d25100             -mov eax, dword ptr [0x51d210]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362192) /* 0x51d210 */);
    // 0047970f  8b1538d25100           -mov edx, dword ptr [0x51d238]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362232) /* 0x51d238 */);
    // 00479715  8b0d18d25100           -mov ecx, dword ptr [0x51d218]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5362200) /* 0x51d218 */);
    // 0047971b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047971d  8b1d40d25100           -mov ebx, dword ptr [0x51d240]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5362240) /* 0x51d240 */);
    // 00479723  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479725  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479728  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047972e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00479730  891538d25100           -mov dword ptr [0x51d238], edx
    app->getMemory<x86::reg32>(x86::reg32(5362232) /* 0x51d238 */) = cpu.edx;
    // 00479736  890d18d25100           -mov dword ptr [0x51d218], ecx
    app->getMemory<x86::reg32>(x86::reg32(5362200) /* 0x51d218 */) = cpu.ecx;
    // 0047973c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047973e  753f                   -jne 0x47977f
    if (!cpu.flags.zf)
    {
        goto L_0x0047977f;
    }
L_0x00479740:
    // 00479740  8b0d3cd25100           -mov ecx, dword ptr [0x51d23c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5362236) /* 0x51d23c */);
    // 00479746  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00479748  740c                   -je 0x479756
    if (cpu.flags.zf)
    {
        goto L_0x00479756;
    }
    // 0047974a  b820d25100             -mov eax, 0x51d220
    cpu.eax = 5362208 /*0x51d220*/;
    // 0047974f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00479751  e84a730000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
L_0x00479756:
    // 00479756  8b1d48d25100           -mov ebx, dword ptr [0x51d248]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5362248) /* 0x51d248 */);
    // 0047975c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047975e  7415                   -je 0x479775
    if (cpu.flags.zf)
    {
        goto L_0x00479775;
    }
    // 00479760  833d50a64c0000         +cmp dword ptr [0x4ca650], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023312) /* 0x4ca650 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479767  750c                   -jne 0x479775
    if (!cpu.flags.zf)
    {
        goto L_0x00479775;
    }
    // 00479769  b84cd25100             -mov eax, 0x51d24c
    cpu.eax = 5362252 /*0x51d24c*/;
    // 0047976e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00479770  e82b730000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
L_0x00479775:
    // 00479775  e8c6e20100             -call 0x497a40
    cpu.esp -= 4;
    sub_497a40(app, cpu);
    if (cpu.terminate) return;
    // 0047977a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047977b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047977c  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x0047977f:
    // 0047977f  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479786  8b1518d25100           -mov edx, dword ptr [0x51d218]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362200) /* 0x51d218 */);
    // 0047978c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047978e  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00479791  83f801                 +cmp eax, 1
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
    // 00479794  7d28                   -jge 0x4797be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004797be;
    }
    // 00479796  3d18fcffff             +cmp eax, 0xfffffc18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966296 /*0xfffffc18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047979b  7d1c                   -jge 0x4797b9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004797b9;
    }
    // 0047979d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047979e  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004797a5  8b355ca64c00           -mov esi, dword ptr [0x4ca65c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023324) /* 0x4ca65c */);
    // 004797ab  40                     -inc eax
    (cpu.eax)++;
    // 004797ac  46                     -inc esi
    (cpu.esi)++;
    // 004797ad  a318d25100             -mov dword ptr [0x51d218], eax
    app->getMemory<x86::reg32>(x86::reg32(5362200) /* 0x51d218 */) = cpu.eax;
    // 004797b2  89355ca64c00           -mov dword ptr [0x4ca65c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023324) /* 0x4ca65c */) = cpu.esi;
    // 004797b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004797b9:
    // 004797b9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004797be:
    // 004797be  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004797c0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004797c2  6808974700             -push 0x479708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4691720 /*0x479708*/;
    cpu.esp -= 4;
    // 004797c7  8b3d14d25100           -mov edi, dword ptr [0x51d214]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5362196) /* 0x51d214 */);
    // 004797cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004797ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797cf  2eff15f8754b00         -call dword ptr cs:[0x4b75f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945400) /* 0x4b75f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004797d6  a334d25100             -mov dword ptr [0x51d234], eax
    app->getMemory<x86::reg32>(x86::reg32(5362228) /* 0x51d234 */) = cpu.eax;
    // 004797db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004797dd  0f855dffffff           -jne 0x479740
    if (!cpu.flags.zf)
    {
        goto L_0x00479740;
    }
    // 004797e3  8b1514d25100           -mov edx, dword ptr [0x51d214]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362196) /* 0x51d214 */);
    // 004797e9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004797ea  a320a44c00             -mov dword ptr [0x4ca420], eax
    app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */) = cpu.eax;
    // 004797ef  a340d25100             -mov dword ptr [0x51d240], eax
    app->getMemory<x86::reg32>(x86::reg32(5362240) /* 0x51d240 */) = cpu.eax;
    // 004797f4  2eff15ec754b00         -call dword ptr cs:[0x4b75ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945388) /* 0x4b75ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004797fb  e940ffffff             -jmp 0x479740
    goto L_0x00479740;
}

/* align: skip  */
void Application::sub_479800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479802  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479803  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479804  8b3550a64c00           -mov esi, dword ptr [0x4ca650]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023312) /* 0x4ca650 */);
    // 0047980a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047980c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00479811  46                     -inc esi
    (cpu.esi)++;
    // 00479812  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479814  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479816:
    // 00479816  83b8f0d1510000         +cmp dword ptr [eax + 0x51d1f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362160) /* 0x51d1f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047981d  7504                   -jne 0x479823
    if (!cpu.flags.zf)
    {
        goto L_0x00479823;
    }
    // 0047981f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00479821  7c29                   -jl 0x47984c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047984c;
    }
L_0x00479823:
    // 00479823  3b98f0d15100           +cmp ebx, dword ptr [eax + 0x51d1f0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362160) /* 0x51d1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479829  7415                   -je 0x479840
    if (cpu.flags.zf)
    {
        goto L_0x00479840;
    }
L_0x0047982b:
    // 0047982b  42                     -inc edx
    (cpu.edx)++;
    // 0047982c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047982f  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479832  7ce2                   -jl 0x479816
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479816;
    }
    // 00479834  83f9ff                 +cmp ecx, -1
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
    // 00479837  7407                   -je 0x479840
    if (cpu.flags.zf)
    {
        goto L_0x00479840;
    }
    // 00479839  891c8df0d15100         -mov dword ptr [ecx*4 + 0x51d1f0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5362160) /* 0x51d1f0 */ + cpu.ecx * 4) = cpu.ebx;
L_0x00479840:
    // 00479840  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00479841  893550a64c00           -mov dword ptr [0x4ca650], esi
    app->getMemory<x86::reg32>(x86::reg32(5023312) /* 0x4ca650 */) = cpu.esi;
    // 00479847  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479848  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479849  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047984a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047984b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047984c:
    // 0047984c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047984e  ebdb                   -jmp 0x47982b
    goto L_0x0047982b;
}

/* align: skip  */
void Application::sub_479850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479852  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479853  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479854  8b1d50a64c00           -mov ebx, dword ptr [0x4ca650]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023312) /* 0x4ca650 */);
    // 0047985a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047985c  8b35f0d15100           -mov esi, dword ptr [0x51d1f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5362160) /* 0x51d1f0 */);
    // 00479862  43                     -inc ebx
    (cpu.ebx)++;
    // 00479863  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479865  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479867  39f1                   +cmp ecx, esi
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
    // 00479869  7411                   -je 0x47987c
    if (cpu.flags.zf)
    {
        goto L_0x0047987c;
    }
L_0x0047986b:
    // 0047986b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047986e  42                     -inc edx
    (cpu.edx)++;
    // 0047986f  83f820                 +cmp eax, 0x20
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
    // 00479872  7d08                   -jge 0x47987c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047987c;
    }
    // 00479874  3b88f0d15100           +cmp ecx, dword ptr [eax + 0x51d1f0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362160) /* 0x51d1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047987a  75ef                   -jne 0x47986b
    if (!cpu.flags.zf)
    {
        goto L_0x0047986b;
    }
L_0x0047987c:
    // 0047987c  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047987f  7d32                   -jge 0x4798b3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004798b3;
    }
    // 00479881  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00479888  3b88f0d15100           +cmp ecx, dword ptr [eax + 0x51d1f0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362160) /* 0x51d1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047988e  7523                   -jne 0x4798b3
    if (!cpu.flags.zf)
    {
        goto L_0x004798b3;
    }
    // 00479890  83fa07                 +cmp edx, 7
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
    // 00479893  7d17                   -jge 0x4798ac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004798ac;
    }
L_0x00479895:
    // 00479895  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479898  8b90f0d15100           -mov edx, dword ptr [eax + 0x51d1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362160) /* 0x51d1f0 */);
    // 0047989e  8990ecd15100           -mov dword ptr [eax + 0x51d1ec], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362156) /* 0x51d1ec */) = cpu.edx;
    // 004798a4  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004798a7  7cec                   -jl 0x479895
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479895;
    }
    // 004798a9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004798ac:
    // 004798ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004798ae  a30cd25100             -mov dword ptr [0x51d20c], eax
    app->getMemory<x86::reg32>(x86::reg32(5362188) /* 0x51d20c */) = cpu.eax;
L_0x004798b3:
    // 004798b3  4b                     -dec ebx
    (cpu.ebx)--;
    // 004798b4  891d50a64c00           -mov dword ptr [0x4ca650], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023312) /* 0x4ca650 */) = cpu.ebx;
    // 004798ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4798c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004798c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004798c2  8b0df0d15100           -mov ecx, dword ptr [0x51d1f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5362160) /* 0x51d1f0 */);
    // 004798c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004798ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004798cc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004798ce  7412                   -je 0x4798e2
    if (cpu.flags.zf)
    {
        goto L_0x004798e2;
    }
L_0x004798d0:
    // 004798d0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004798d3  42                     -inc edx
    (cpu.edx)++;
    // 004798d4  83f820                 +cmp eax, 0x20
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
    // 004798d7  7d09                   -jge 0x4798e2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004798e2;
    }
    // 004798d9  83b8f0d1510000         +cmp dword ptr [eax + 0x51d1f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362160) /* 0x51d1f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004798e0  75ee                   -jne 0x4798d0
    if (!cpu.flags.zf)
    {
        goto L_0x004798d0;
    }
L_0x004798e2:
    // 004798e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004798e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4798e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004798e8  ff0550a64c00           -inc dword ptr [0x4ca650]
    (app->getMemory<x86::reg32>(x86::reg32(5023312) /* 0x4ca650 */))++;
    // 004798ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4798f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004798f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004798f1  8b1550a64c00           -mov edx, dword ptr [0x4ca650]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023312) /* 0x4ca650 */);
    // 004798f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004798f9  7502                   -jne 0x4798fd
    if (!cpu.flags.zf)
    {
        goto L_0x004798fd;
    }
    // 004798fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004798fd:
    // 004798fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798fe  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00479901  890d50a64c00           -mov dword ptr [0x4ca650], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023312) /* 0x4ca650 */) = cpu.ecx;
    // 00479907  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479908  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479909  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47990c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047990c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047990d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047990e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047990f  833d40d2510000         +cmp dword ptr [0x51d240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362240) /* 0x51d240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479916  7448                   -je 0x479960
    if (cpu.flags.zf)
    {
        goto L_0x00479960;
    }
    // 00479918  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479919  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047991b  8b3534d25100           -mov esi, dword ptr [0x51d234]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5362228) /* 0x51d234 */);
    // 00479921  890d20a44c00           -mov dword ptr [0x4ca420], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */) = cpu.ecx;
    // 00479927  890d40d25100           -mov dword ptr [0x51d240], ecx
    app->getMemory<x86::reg32>(x86::reg32(5362240) /* 0x51d240 */) = cpu.ecx;
    // 0047992d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047992f  7553                   -jne 0x479984
    if (!cpu.flags.zf)
    {
        goto L_0x00479984;
    }
L_0x00479931:
    // 00479931  8b2d14d25100           -mov ebp, dword ptr [0x51d214]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5362196) /* 0x51d214 */);
    // 00479937  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479938  2eff15ec754b00         -call dword ptr cs:[0x4b75ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945388) /* 0x4b75ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047993f  a148d25100             -mov eax, dword ptr [0x51d248]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362248) /* 0x51d248 */);
    // 00479944  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479946  7546                   -jne 0x47998e
    if (!cpu.flags.zf)
    {
        goto L_0x0047998e;
    }
L_0x00479948:
    // 00479948  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047994d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047994e:
    // 0047994e  833d34d2510000         +cmp dword ptr [0x51d234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362228) /* 0x51d234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479955  7409                   -je 0x479960
    if (cpu.flags.zf)
    {
        goto L_0x00479960;
    }
    // 00479957  833d48d2510000         +cmp dword ptr [0x51d248], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362248) /* 0x51d248 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047995e  753c                   -jne 0x47999c
    if (!cpu.flags.zf)
    {
        goto L_0x0047999c;
    }
L_0x00479960:
    // 00479960  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00479962  893538d25100           -mov dword ptr [0x51d238], esi
    app->getMemory<x86::reg32>(x86::reg32(5362232) /* 0x51d238 */) = cpu.esi;
    // 00479968  893550a64c00           -mov dword ptr [0x4ca650], esi
    app->getMemory<x86::reg32>(x86::reg32(5023312) /* 0x4ca650 */) = cpu.esi;
    // 0047996e  893514d25100           -mov dword ptr [0x51d214], esi
    app->getMemory<x86::reg32>(x86::reg32(5362196) /* 0x51d214 */) = cpu.esi;
    // 00479974  893534d25100           -mov dword ptr [0x51d234], esi
    app->getMemory<x86::reg32>(x86::reg32(5362228) /* 0x51d234 */) = cpu.esi;
    // 0047997a  89355ca44c00           -mov dword ptr [0x4ca45c], esi
    app->getMemory<x86::reg32>(x86::reg32(5022812) /* 0x4ca45c */) = cpu.esi;
    // 00479980  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479981  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479982  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479983  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479984:
    // 00479984  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479985  2eff15f4754b00         -call dword ptr cs:[0x4b75f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945396) /* 0x4b75f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047998c  eba3                   -jmp 0x479931
    goto L_0x00479931;
L_0x0047998e:
    // 0047998e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479990  b84cd25100             -mov eax, 0x51d24c
    cpu.eax = 5362252 /*0x51d24c*/;
    // 00479995  e806710000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 0047999a  ebac                   -jmp 0x479948
    goto L_0x00479948;
L_0x0047999c:
    // 0047999c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047999e  e8796e0000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 004799a3  eba9                   -jmp 0x47994e
    goto L_0x0047994e;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4799a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004799a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004799a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004799aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004799ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004799ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004799ad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004799ae  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004799b1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004799b3  e854ffffff             -call 0x47990c
    cpu.esp -= 4;
    sub_47990c(app, cpu);
    if (cpu.terminate) return;
    // 004799b8  83fe01                 +cmp esi, 1
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
    // 004799bb  7d70                   -jge 0x479a2d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479a2d;
    }
L_0x004799bd:
    // 004799bd  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
L_0x004799c2:
    // 004799c2  b80000e803             -mov eax, 0x3e80000
    cpu.eax = 65536000 /*0x3e80000*/;
    // 004799c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004799c9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004799cc  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004799ce  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004799d0  a310d25100             -mov dword ptr [0x51d210], eax
    app->getMemory<x86::reg32>(x86::reg32(5362192) /* 0x51d210 */) = cpu.eax;
    // 004799d5  891538d25100           -mov dword ptr [0x51d238], edx
    app->getMemory<x86::reg32>(x86::reg32(5362232) /* 0x51d238 */) = cpu.edx;
    // 004799db  891564d25100           -mov dword ptr [0x51d264], edx
    app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */) = cpu.edx;
    // 004799e1  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004799e3  891544d25100           -mov dword ptr [0x51d244], edx
    app->getMemory<x86::reg32>(x86::reg32(5362244) /* 0x51d244 */) = cpu.edx;
    // 004799e9  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004799ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004799ee  2eff15f0754b00         -call dword ptr cs:[0x4b75f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945392) /* 0x4b75f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004799f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004799f7  753e                   -jne 0x479a37
    if (!cpu.flags.zf)
    {
        goto L_0x00479a37;
    }
    // 004799f9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004799fe  8b1510d25100           -mov edx, dword ptr [0x51d210]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362192) /* 0x51d210 */);
    // 00479a04  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00479a07  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00479a0b  893d14d25100           -mov dword ptr [0x51d214], edi
    app->getMemory<x86::reg32>(x86::reg32(5362196) /* 0x51d214 */) = cpu.edi;
    // 00479a11  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479a17  732e                   -jae 0x479a47
    if (!cpu.flags.cf)
    {
        goto L_0x00479a47;
    }
L_0x00479a19:
    // 00479a19  a320a44c00             -mov dword ptr [0x4ca420], eax
    app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */) = cpu.eax;
    // 00479a1e  a340d25100             -mov dword ptr [0x51d240], eax
    app->getMemory<x86::reg32>(x86::reg32(5362240) /* 0x51d240 */) = cpu.eax;
L_0x00479a23:
    // 00479a23  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479a26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479a2d:
    // 00479a2d  81fe10270000           +cmp esi, 0x2710
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10000 /*0x2710*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479a33  7f88                   -jg 0x4799bd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004799bd;
    }
    // 00479a35  eb8b                   -jmp 0x4799c2
    goto L_0x004799c2;
L_0x00479a37:
    // 00479a37  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00479a39  893d20a44c00           -mov dword ptr [0x4ca420], edi
    app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */) = cpu.edi;
    // 00479a3f  893d40d25100           -mov dword ptr [0x51d240], edi
    app->getMemory<x86::reg32>(x86::reg32(5362240) /* 0x51d240 */) = cpu.edi;
    // 00479a45  ebdc                   -jmp 0x479a23
    goto L_0x00479a23;
L_0x00479a47:
    // 00479a47  684cd25100             -push 0x51d24c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5362252 /*0x51d24c*/;
    cpu.esp -= 4;
    // 00479a4c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00479a51  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00479a56  b860954700             -mov eax, 0x479560
    cpu.eax = 4691296 /*0x479560*/;
    // 00479a5b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479a5d  e8fe6c0000             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 00479a62  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479a64  74b3                   -je 0x479a19
    if (cpu.flags.zf)
    {
        goto L_0x00479a19;
    }
    // 00479a66  8b0d14d25100           -mov ecx, dword ptr [0x51d214]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5362196) /* 0x51d214 */);
    // 00479a6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479a6d  2eff15e8754b00         -call dword ptr cs:[0x4b75e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945384) /* 0x4b75e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479a74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479a76  755e                   -jne 0x479ad6
    if (!cpu.flags.zf)
    {
        goto L_0x00479ad6;
    }
    // 00479a78  b80c994700             -mov eax, 0x47990c
    cpu.eax = 4692236 /*0x47990c*/;
    // 00479a7d  e85a6c0100             -call 0x4906dc
    cpu.esp -= 4;
    sub_4906dc(app, cpu);
    if (cpu.terminate) return;
    // 00479a82  893520a44c00           -mov dword ptr [0x4ca420], esi
    app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */) = cpu.esi;
    // 00479a88  893540d25100           -mov dword ptr [0x51d240], esi
    app->getMemory<x86::reg32>(x86::reg32(5362240) /* 0x51d240 */) = cpu.esi;
    // 00479a8e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479a90  756c                   -jne 0x479afe
    if (!cpu.flags.zf)
    {
        goto L_0x00479afe;
    }
L_0x00479a92:
    // 00479a92  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00479a97  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479a99  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479aa0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479aa2  b810270000             -mov eax, 0x2710
    cpu.eax = 10000 /*0x2710*/;
    // 00479aa7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479aa9  8b3d20a44c00           -mov edi, dword ptr [0x4ca420]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00479aaf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00479ab2  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00479ab4  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00479ab6:
    // 00479ab6  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479abd  39f0                   +cmp eax, esi
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
    // 00479abf  7362                   -jae 0x479b23
    if (!cpu.flags.cf)
    {
        goto L_0x00479b23;
    }
    // 00479ac1  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00479ac6  39c3                   +cmp ebx, eax
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
    // 00479ac8  7559                   -jne 0x479b23
    if (!cpu.flags.zf)
    {
        goto L_0x00479b23;
    }
    // 00479aca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479acf  e8486d0000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00479ad4  ebe0                   -jmp 0x479ab6
    goto L_0x00479ab6;
L_0x00479ad6:
    // 00479ad6  b84cd25100             -mov eax, 0x51d24c
    cpu.eax = 5362252 /*0x51d24c*/;
    // 00479adb  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00479add  8b1548d25100           -mov edx, dword ptr [0x51d248]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362248) /* 0x51d248 */);
    // 00479ae3  892d20a44c00           -mov dword ptr [0x4ca420], ebp
    app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */) = cpu.ebp;
    // 00479ae9  892d40d25100           -mov dword ptr [0x51d240], ebp
    app->getMemory<x86::reg32>(x86::reg32(5362240) /* 0x51d240 */) = cpu.ebp;
    // 00479aef  e8ac6f0000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 00479af4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479af7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479af8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479af9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479afa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479afb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479afc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479afd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479afe:
    // 00479afe  8b1d34d25100           -mov ebx, dword ptr [0x51d234]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5362228) /* 0x51d234 */);
    // 00479b04  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479b06  758a                   -jne 0x479a92
    if (!cpu.flags.zf)
    {
        goto L_0x00479a92;
    }
    // 00479b08  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479b0f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479b11  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479b12  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479b13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479b14  a318d25100             -mov dword ptr [0x51d218], eax
    app->getMemory<x86::reg32>(x86::reg32(5362200) /* 0x51d218 */) = cpu.eax;
    // 00479b19  e8eafbffff             -call 0x479708
    cpu.esp -= 4;
    sub_479708(app, cpu);
    if (cpu.terminate) return;
    // 00479b1e  e96fffffff             -jmp 0x479a92
    goto L_0x00479a92;
L_0x00479b23:
    // 00479b23  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00479b28  39c3                   +cmp ebx, eax
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
    // 00479b2a  7505                   -jne 0x479b31
    if (!cpu.flags.zf)
    {
        goto L_0x00479b31;
    }
    // 00479b2c  e8dbfdffff             -call 0x47990c
    cpu.esp -= 4;
    sub_47990c(app, cpu);
    if (cpu.terminate) return;
L_0x00479b31:
    // 00479b31  833d20a44c0000         +cmp dword ptr [0x4ca420], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479b38  0f84e5feffff           -je 0x479a23
    if (cpu.flags.zf)
    {
        goto L_0x00479a23;
    }
    // 00479b3e  c7055ca44c00f0964700   -mov dword ptr [0x4ca45c], 0x4796f0
    app->getMemory<x86::reg32>(x86::reg32(5022812) /* 0x4ca45c */) = 4691696 /*0x4796f0*/;
    // 00479b48  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479b4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479b60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479b61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479b62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479b63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479b64  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479b67  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479b69  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00479b6c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00479b6e  8b1d60a64c00           -mov ebx, dword ptr [0x4ca660]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023328) /* 0x4ca660 */);
    // 00479b74  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00479b79  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00479b7c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479b7e  891560a64c00           -mov dword ptr [0x4ca660], edx
    app->getMemory<x86::reg32>(x86::reg32(5023328) /* 0x4ca660 */) = cpu.edx;
    // 00479b84  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00479b86:
    // 00479b86  8baa68d25100           -mov ebp, dword ptr [edx + 0x51d268]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5362280) /* 0x51d268 */);
    // 00479b8c  39ee                   +cmp esi, ebp
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
    // 00479b8e  751e                   -jne 0x479bae
    if (!cpu.flags.zf)
    {
        goto L_0x00479bae;
    }
L_0x00479b90:
    // 00479b90  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00479b92:
    // 00479b92  40                     -inc eax
    (cpu.eax)++;
    // 00479b93  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00479b96  83f810                 +cmp eax, 0x10
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
    // 00479b99  7ceb                   -jl 0x479b86
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479b86;
    }
    // 00479b9b  83f9ff                 +cmp ecx, -1
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
    // 00479b9e  751e                   -jne 0x479bbe
    if (!cpu.flags.zf)
    {
        goto L_0x00479bbe;
    }
    // 00479ba0  ff0d60a64c00           -dec dword ptr [0x4ca660]
    (app->getMemory<x86::reg32>(x86::reg32(5023328) /* 0x4ca660 */))--;
    // 00479ba6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479ba9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479baa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479bae:
    // 00479bae  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00479bb0  75e0                   -jne 0x479b92
    if (!cpu.flags.zf)
    {
        goto L_0x00479b92;
    }
    // 00479bb2  83f9ff                 +cmp ecx, -1
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
    // 00479bb5  75db                   -jne 0x479b92
    if (!cpu.flags.zf)
    {
        goto L_0x00479b92;
    }
    // 00479bb7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479bb9  74d5                   -je 0x479b90
    if (cpu.flags.zf)
    {
        goto L_0x00479b90;
    }
    // 00479bbb  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00479bbc  ebd4                   -jmp 0x479b92
    goto L_0x00479b92;
L_0x00479bbe:
    // 00479bbe  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00479bc1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00479bc4  89b168d25100           -mov dword ptr [ecx + 0x51d268], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362280) /* 0x51d268 */) = cpu.esi;
    // 00479bca  89816cd25100           -mov dword ptr [ecx + 0x51d26c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362284) /* 0x51d26c */) = cpu.eax;
    // 00479bd0  033d60d25100           -add edi, dword ptr [0x51d260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */)));
    // 00479bd6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479bd8  89b970d25100           -mov dword ptr [ecx + 0x51d270], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362288) /* 0x51d270 */) = cpu.edi;
    // 00479bde  899174d25100           -mov dword ptr [ecx + 0x51d274], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362292) /* 0x51d274 */) = cpu.edx;
    // 00479be4  ff0d60a64c00           -dec dword ptr [0x4ca660]
    (app->getMemory<x86::reg32>(x86::reg32(5023328) /* 0x4ca660 */))--;
    // 00479bea  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479bed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bf0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bf1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479bf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479bf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479bf5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479bf6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479bf7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479bf8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479bfa  8b1d68d25100           -mov ebx, dword ptr [0x51d268]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5362280) /* 0x51d268 */);
    // 00479c00  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479c02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479c04  39d9                   +cmp ecx, ebx
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
    // 00479c06  7413                   -je 0x479c1b
    if (cpu.flags.zf)
    {
        goto L_0x00479c1b;
    }
L_0x00479c08:
    // 00479c08  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00479c0b  42                     -inc edx
    (cpu.edx)++;
    // 00479c0c  3d00010000             +cmp eax, 0x100
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
    // 00479c11  7d08                   -jge 0x479c1b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479c1b;
    }
    // 00479c13  3b8868d25100           +cmp ecx, dword ptr [eax + 0x51d268]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5362280) /* 0x51d268 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479c19  75ed                   -jne 0x479c08
    if (!cpu.flags.zf)
    {
        goto L_0x00479c08;
    }
L_0x00479c1b:
    // 00479c1b  83fa10                 +cmp edx, 0x10
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
    // 00479c1e  7d0b                   -jge 0x479c2b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479c2b;
    }
    // 00479c20  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00479c23  3b8a68d25100           +cmp ecx, dword ptr [edx + 0x51d268]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5362280) /* 0x51d268 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479c29  7405                   -je 0x479c30
    if (cpu.flags.zf)
    {
        goto L_0x00479c30;
    }
L_0x00479c2b:
    // 00479c2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479c30:
    // 00479c30  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00479c32  89aa68d25100           -mov dword ptr [edx + 0x51d268], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5362280) /* 0x51d268 */) = cpu.ebp;
    // 00479c38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479c40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479c41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479c42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479c43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479c44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479c45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479c46  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00479c48  a164a64c00             -mov eax, dword ptr [0x4ca664]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023332) /* 0x4ca664 */);
    // 00479c4d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00479c4f  3b0560d25100           +cmp eax, dword ptr [0x51d260]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 00479c55  0f8470000000           -je 0x479ccb
    if (cpu.flags.zf)
    {
        goto L_0x00479ccb;
    }
    // 00479c5b  a160d25100             -mov eax, dword ptr [0x51d260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */);
    // 00479c60  a364a64c00             -mov dword ptr [0x4ca664], eax
    app->getMemory<x86::reg32>(x86::reg32(5023332) /* 0x4ca664 */) = cpu.eax;
    // 00479c65  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00479c67:
    // 00479c67  8b9968d25100           -mov ebx, dword ptr [ecx + 0x51d268]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362280) /* 0x51d268 */);
    // 00479c6d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479c6f  744f                   -je 0x479cc0
    if (cpu.flags.zf)
    {
        goto L_0x00479cc0;
    }
    // 00479c71  a160d25100             -mov eax, dword ptr [0x51d260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */);
    // 00479c76  3b8170d25100           +cmp eax, dword ptr [ecx + 0x51d270]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362288) /* 0x51d270 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479c7c  7c42                   -jl 0x479cc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479cc0;
    }
    // 00479c7e  83b974d2510000         +cmp dword ptr [ecx + 0x51d274], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362292) /* 0x51d274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479c85  7539                   -jne 0x479cc0
    if (!cpu.flags.zf)
    {
        goto L_0x00479cc0;
    }
    // 00479c87  c78174d2510001000000   -mov dword ptr [ecx + 0x51d274], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362292) /* 0x51d274 */) = 1 /*0x1*/;
    // 00479c91  8b1560d25100           -mov edx, dword ptr [0x51d260]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */);
    // 00479c97  8ba970d25100           -mov ebp, dword ptr [ecx + 0x51d270]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362288) /* 0x51d270 */);
    // 00479c9d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00479c9f  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00479ca1  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479ca3  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00479ca5  a160d25100             -mov eax, dword ptr [0x51d260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */);
    // 00479caa  8b916cd25100           -mov edx, dword ptr [ecx + 0x51d26c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362284) /* 0x51d26c */);
    // 00479cb0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479cb2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00479cb4  899974d25100           -mov dword ptr [ecx + 0x51d274], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362292) /* 0x51d274 */) = cpu.ebx;
    // 00479cba  898170d25100           -mov dword ptr [ecx + 0x51d270], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5362288) /* 0x51d270 */) = cpu.eax;
L_0x00479cc0:
    // 00479cc0  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00479cc3  81f900010000           +cmp ecx, 0x100
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479cc9  759c                   -jne 0x479c67
    if (!cpu.flags.zf)
    {
        goto L_0x00479c67;
    }
L_0x00479ccb:
    // 00479ccb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00479ccd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479cce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ccf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479cd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479cd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479cd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479cd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479cd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479cd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479cd5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479cd6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479cd8  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00479cdd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479cdf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00479ce1:
    // 00479ce1  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00479ce6  39c8                   +cmp eax, ecx
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
    // 00479ce8  7d04                   -jge 0x479cee
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479cee;
    }
    // 00479cea  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479cec  7405                   -je 0x479cf3
    if (cpu.flags.zf)
    {
        goto L_0x00479cf3;
    }
L_0x00479cee:
    // 00479cee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479cf0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479cf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479cf2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479cf3:
    // 00479cf3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00479cf5  e846ffffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00479cfa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479cfc  ebe3                   -jmp 0x479ce1
    goto L_0x00479ce1;
}

/* align: skip 0x00 0x00 */
void Application::sub_479d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479d00  ff0568a64c00           -inc dword ptr [0x4ca668]
    (app->getMemory<x86::reg32>(x86::reg32(5023336) /* 0x4ca668 */))++;
    // 00479d06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_479d08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479d08  833dacd7510000         +cmp dword ptr [0x51d7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5363628) /* 0x51d7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479d0f  7509                   -jne 0x479d1a
    if (!cpu.flags.zf)
    {
        goto L_0x00479d1a;
    }
    // 00479d11  833d6ca64c0000         +cmp dword ptr [0x4ca66c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023340) /* 0x4ca66c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479d18  7406                   -je 0x479d20
    if (cpu.flags.zf)
    {
        goto L_0x00479d20;
    }
L_0x00479d1a:
    // 00479d1a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479d1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479d20:
    // 00479d20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479d22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00479d20;
    // 00479d08  833dacd7510000         +cmp dword ptr [0x51d7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5363628) /* 0x51d7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479d0f  7509                   -jne 0x479d1a
    if (!cpu.flags.zf)
    {
        goto L_0x00479d1a;
    }
    // 00479d11  833d6ca64c0000         +cmp dword ptr [0x4ca66c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023340) /* 0x4ca66c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479d18  7406                   -je 0x479d20
    if (cpu.flags.zf)
    {
        goto L_0x00479d20;
    }
L_0x00479d1a:
    // 00479d1a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479d1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479d20:
L_entry_0x00479d20:
    // 00479d20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479d22  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
