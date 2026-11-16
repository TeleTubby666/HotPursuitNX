#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481083  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481084  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481085  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00481088  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 0048108d  e8fe010000             -call 0x481290
    cpu.esp -= 4;
    sub_481290(app, cpu);
    if (cpu.terminate) return;
    // 00481092  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481094  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481096  e8718d0000             -call 0x489e0c
    cpu.esp -= 4;
    sub_489e0c(app, cpu);
    if (cpu.terminate) return;
    // 0048109b  a314ab4d00             -mov dword ptr [0x4dab14], eax
    app->getMemory<x86::reg32>(x86::reg32(5090068) /* 0x4dab14 */) = cpu.eax;
    // 004810a0  e8b78d0000             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004810a5  a114ab4d00             -mov eax, dword ptr [0x4dab14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090068) /* 0x4dab14 */);
    // 004810aa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004810ac  e8378e0000             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 004810b1  8a255d3d5600           -mov ah, byte ptr [0x563d5d]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5651805) /* 0x563d5d */);
    // 004810b7  891d543d5600           -mov dword ptr [0x563d54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */) = cpu.ebx;
    // 004810bd  891518ab4d00           -mov dword ptr [0x4dab18], edx
    app->getMemory<x86::reg32>(x86::reg32(5090072) /* 0x4dab18 */) = cpu.edx;
    // 004810c3  891514ab4d00           -mov dword ptr [0x4dab14], edx
    app->getMemory<x86::reg32>(x86::reg32(5090068) /* 0x4dab14 */) = cpu.edx;
    // 004810c9  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004810cb  0f845a010000           -je 0x48122b
    if (cpu.flags.zf)
    {
        goto L_0x0048122b;
    }
    // 004810d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004810d2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004810d4  2eff1528644c00         -call dword ptr cs:[0x4c6428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006376) /* 0x4c6428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004810db  891d643d5600           -mov dword ptr [0x563d64], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651812) /* 0x563d64 */) = cpu.ebx;
    // 004810e1  891d683d5600           -mov dword ptr [0x563d68], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651816) /* 0x563d68 */) = cpu.ebx;
L_0x004810e7:
    // 004810e7  6878f64c00             -push 0x4cf678
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043832 /*0x4cf678*/;
    cpu.esp -= 4;
    // 004810ec  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004810ee  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 004810f3  e888df0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 004810f8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004810fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004810fc  2eff151c644c00         -call dword ptr cs:[0x4c641c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006364) /* 0x4c641c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481103  3b35543d5600           +cmp esi, dword ptr [0x563d54]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481109  0f85ff000000           -jne 0x48120e
    if (!cpu.flags.zf)
    {
        goto L_0x0048120e;
    }
L_0x0048110f:
    // 0048110f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481111  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481113  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481115  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00481119  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048111a  2eff15f4634c00         -call dword ptr cs:[0x4c63f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006324) /* 0x4c63f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481121  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481123  0f8433010000           -je 0x48125c
    if (cpu.flags.zf)
    {
        goto L_0x0048125c;
    }
    // 00481129  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 0048112e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048112f  6898f64c00             -push 0x4cf698
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043864 /*0x4cf698*/;
    cpu.esp -= 4;
    // 00481134  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00481136  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 0048113b  e840df0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481140  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481143  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 00481148  e8fb8d0000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048114d  833dd835560000         +cmp dword ptr [0x5635d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5649880) /* 0x5635d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481154  751b                   -jne 0x481171
    if (!cpu.flags.zf)
    {
        goto L_0x00481171;
    }
    // 00481156  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048115a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048115e  e81d0c0000             -call 0x481d80
    cpu.esp -= 4;
    sub_481d80(app, cpu);
    if (cpu.terminate) return;
    // 00481163  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481165  750a                   -jne 0x481171
    if (!cpu.flags.zf)
    {
        goto L_0x00481171;
    }
    // 00481167  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481169  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048116a  2eff1540644c00         -call dword ptr cs:[0x4c6440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006400) /* 0x4c6440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00481171:
    // 00481171  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481173  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481174  2eff15d8634c00         -call dword ptr cs:[0x4c63d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006296) /* 0x4c63d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048117b  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 00481180  e8db8d0000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00481185  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 0048118a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048118b  68a8f64c00             -push 0x4cf6a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043880 /*0x4cf6a8*/;
    cpu.esp -= 4;
    // 00481190  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00481192  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481197  e8e4de0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 0048119c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0048119f:
    // 0048119f  833d18ab4d0000         +cmp dword ptr [0x4dab18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090072) /* 0x4dab18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004811a6  745a                   -je 0x481202
    if (cpu.flags.zf)
    {
        goto L_0x00481202;
    }
    // 004811a8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004811aa  8b3d00395600           -mov edi, dword ptr [0x563900]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5650688) /* 0x563900 */);
    // 004811b0  891d18ab4d00           -mov dword ptr [0x4dab18], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090072) /* 0x4dab18 */) = cpu.ebx;
    // 004811b6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004811b8  7427                   -je 0x4811e1
    if (cpu.flags.zf)
    {
        goto L_0x004811e1;
    }
    // 004811ba  833d1039560000         +cmp dword ptr [0x563910], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004811c1  741e                   -je 0x4811e1
    if (cpu.flags.zf)
    {
        goto L_0x004811e1;
    }
    // 004811c3  68d0f64c00             -push 0x4cf6d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043920 /*0x4cf6d0*/;
    cpu.esp -= 4;
    // 004811c8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004811ca  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 004811cf  e8acde0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 004811d4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004811d7  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004811dc  e883070100             -call 0x491964
    cpu.esp -= 4;
    sub_491964(app, cpu);
    if (cpu.terminate) return;
L_0x004811e1:
    // 004811e1  68ecf64c00             -push 0x4cf6ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043948 /*0x4cf6ec*/;
    cpu.esp -= 4;
    // 004811e6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004811e8  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 004811ed  e88ede0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 004811f2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004811f5  a1543d5600             -mov eax, dword ptr [0x563d54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 004811fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004811fb  2eff15d4634c00         -call dword ptr cs:[0x4c63d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006292) /* 0x4c63d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00481202:
    // 00481202  3b35543d5600           +cmp esi, dword ptr [0x563d54]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481208  0f8401ffffff           -je 0x48110f
    if (cpu.flags.zf)
    {
        goto L_0x0048110f;
    }
L_0x0048120e:
    // 0048120e  68fcf64c00             -push 0x4cf6fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043964 /*0x4cf6fc*/;
    cpu.esp -= 4;
    // 00481213  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481215  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 0048121a  e861de0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 0048121f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481222  83c42c                 +add esp, 0x2c
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
    // 00481225  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481226  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481227  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481228  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481229  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048122a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048122b:
    // 0048122b  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048122f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481231  2eff15e8634c00         -call dword ptr cs:[0x4c63e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006312) /* 0x4c63e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481238  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048123c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048123d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048123e  2eff15c8634c00         -call dword ptr cs:[0x4c63c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006280) /* 0x4c63c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481245  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00481249  a3643d5600             -mov dword ptr [0x563d64], eax
    app->getMemory<x86::reg32>(x86::reg32(5651812) /* 0x563d64 */) = cpu.eax;
    // 0048124e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00481252  a3683d5600             -mov dword ptr [0x563d68], eax
    app->getMemory<x86::reg32>(x86::reg32(5651816) /* 0x563d68 */) = cpu.eax;
    // 00481257  e98bfeffff             -jmp 0x4810e7
    goto L_0x004810e7;
L_0x0048125c:
    // 0048125c  68b8f64c00             -push 0x4cf6b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043896 /*0x4cf6b8*/;
    cpu.esp -= 4;
    // 00481261  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481263  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481268  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0048126d  e80ede0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481272  83c40c                 +add esp, 0xc
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
    // 00481275  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048127a  b8a0214800             -mov eax, 0x4821a0
    cpu.eax = 4727200 /*0x4821a0*/;
    // 0048127f  e84c2b0000             -call 0x483dd0
    cpu.esp -= 4;
    sub_483dd0(app, cpu);
    if (cpu.terminate) return;
    // 00481284  e916ffffff             -jmp 0x48119f
    goto L_0x0048119f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481291  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481292  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481293  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481294  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481295  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481296  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481299  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048129b  8aa05d040000           -mov ah, byte ptr [eax + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
    // 004812a1  8b3534ab4d00           -mov esi, dword ptr [0x4dab34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090100) /* 0x4dab34 */);
    // 004812a7  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004812a9  0f8520010000           -jne 0x4813cf
    if (!cpu.flags.zf)
    {
        goto L_0x004813cf;
    }
    // 004812af  8a1588ab4d00           -mov dl, byte ptr [0x4dab88]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004812b5  81ce0000ca00           -or esi, 0xca0000
    cpu.esi |= x86::reg32(x86::sreg32(13238272 /*0xca0000*/));
    // 004812bb  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004812be  0f8445010000           -je 0x481409
    if (cpu.flags.zf)
    {
        goto L_0x00481409;
    }
    // 004812c4  81ce00000500           -or esi, 0x50000
    cpu.esi |= x86::reg32(x86::sreg32(327680 /*0x50000*/));
L_0x004812ca:
    // 004812ca  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004812d1  0f843d010000           -je 0x481414
    if (cpu.flags.zf)
    {
        goto L_0x00481414;
    }
    // 004812d7  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 004812dd  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004812e1  8b8364040000           -mov eax, dword ptr [ebx + 0x464]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 004812e7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004812ea:
    // 004812ea  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004812ee  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004812f1  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004812f3  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004812f7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004812fa  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004812fd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004812ff  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481301  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481302  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00481306  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048130a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048130b  2eff15b4634c00         -call dword ptr cs:[0x4c63b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006260) /* 0x4c63b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481312  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00481315  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0048131b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048131f  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 00481325  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481329  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048132c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00481330  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481332  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00481334  b900000400             -mov ecx, 0x40000
    cpu.ecx = 262144 /*0x40000*/;
L_0x00481339:
    // 00481339  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048133a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048133b  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 00481341  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481342  8bab64040000           -mov ebp, dword ptr [ebx + 0x464]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 00481348  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481349  682cf64c00             -push 0x4cf62c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043756 /*0x4cf62c*/;
    cpu.esp -= 4;
    // 0048134e  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00481350  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481355  e826dd0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 0048135a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048135d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048135f  a1703d5600             -mov eax, dword ptr [0x563d70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651824) /* 0x563d70 */);
    // 00481364  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481365  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481367  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481369  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048136a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048136b  8b9368040000           -mov edx, dword ptr [ebx + 0x468]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 00481371  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481372  8bbb64040000           -mov edi, dword ptr [ebx + 0x464]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 00481378  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481379  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048137a  8b2d44ab4d00           -mov ebp, dword ptr [0x4dab44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090116) /* 0x4dab44 */);
    // 00481380  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481381  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481382  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481383  2eff15cc634c00         -call dword ptr cs:[0x4c63cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006284) /* 0x4c63cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048138a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048138c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048138e  7409                   -je 0x481399
    if (cpu.flags.zf)
    {
        goto L_0x00481399;
    }
    // 00481390  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481392  2eff1534644c00         -call dword ptr cs:[0x4c6434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006388) /* 0x4c6434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00481399:
    // 00481399  ff1538375600           -call dword ptr [0x563738]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650232) /* 0x563738 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048139f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004813a1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004813a3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004813a5  ff1568375600           -call dword ptr [0x563768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650280) /* 0x563768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004813ab  685cf64c00             -push 0x4cf65c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043804 /*0x4cf65c*/;
    cpu.esp -= 4;
    // 004813b0  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004813b2  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 004813b7  e8c4dc0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 004813bc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004813bf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004813c1  7562                   -jne 0x481425
    if (!cpu.flags.zf)
    {
        goto L_0x00481425;
    }
L_0x004813c3:
    // 004813c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004813c5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004813c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004813c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004813ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004813cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004813cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004813cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004813ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004813cf:
    // 004813cf  c7836404000000000000   -mov dword ptr [ebx + 0x464], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = 0 /*0x0*/;
    // 004813d9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004813db  c7836804000000000000   -mov dword ptr [ebx + 0x468], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = 0 /*0x0*/;
    // 004813e5  2eff15f8634c00         -call dword ptr cs:[0x4c63f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006328) /* 0x4c63f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004813ec  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004813ee  81ce00000080           +or esi, 0x80000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/))));
    // 004813f4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004813f6  2eff15f8634c00         -call dword ptr cs:[0x4c63f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006328) /* 0x4c63f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004813fd  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00481402  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481404  e930ffffff             -jmp 0x481339
    goto L_0x00481339;
L_0x00481409:
    // 00481409  81ce00008000           +or esi, 0x800000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(8388608 /*0x800000*/))));
    // 0048140f  e9b6feffff             -jmp 0x4812ca
    goto L_0x004812ca;
L_0x00481414:
    // 00481414  b900e0ffff             -mov ecx, 0xffffe000
    cpu.ecx = 4294959104 /*0xffffe000*/;
    // 00481419  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048141c  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00481420  e9c5feffff             -jmp 0x4812ea
    goto L_0x004812ea;
L_0x00481425:
    // 00481425  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481427  2eff1520644c00         -call dword ptr cs:[0x4c6420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006368) /* 0x4c6420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048142e  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00481435  7409                   -je 0x481440
    if (cpu.flags.zf)
    {
        goto L_0x00481440;
    }
    // 00481437  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481439  2eff1534644c00         -call dword ptr cs:[0x4c6434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006388) /* 0x4c6434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00481440:
    // 00481440  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481442  8b0d40ab4d00           -mov ecx, dword ptr [0x4dab40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090112) /* 0x4dab40 */);
    // 00481448  8915f0b24d00           -mov dword ptr [0x4db2f0], edx
    app->getMemory<x86::reg32>(x86::reg32(5092080) /* 0x4db2f0 */) = cpu.edx;
    // 0048144e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481450  0f856dffffff           -jne 0x4813c3
    if (!cpu.flags.zf)
    {
        goto L_0x004813c3;
    }
    // 00481456  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481458  e8a3fb0100             -call 0x4a1000
    cpu.esp -= 4;
    sub_4a1000(app, cpu);
    if (cpu.terminate) return;
    // 0048145d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481462  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481464  e897fb0100             -call 0x4a1000
    cpu.esp -= 4;
    sub_4a1000(app, cpu);
    if (cpu.terminate) return;
    // 00481469  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0048146e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481470  e88bfb0100             -call 0x4a1000
    cpu.esp -= 4;
    sub_4a1000(app, cpu);
    if (cpu.terminate) return;
    // 00481475  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481477  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048147a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048147b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048147c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048147d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048147e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048147f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481480  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481490  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481491  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481492  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481493  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481494  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00481498  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048149c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048149e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004814a0  754b                   -jne 0x4814ed
    if (!cpu.flags.zf)
    {
        goto L_0x004814ed;
    }
    // 004814a2  833d24ab4d0000         +cmp dword ptr [0x4dab24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090084) /* 0x4dab24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004814a9  7442                   -je 0x4814ed
    if (cpu.flags.zf)
    {
        goto L_0x004814ed;
    }
    // 004814ab  833d743d560000         +cmp dword ptr [0x563d74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5651828) /* 0x563d74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004814b2  7439                   -je 0x4814ed
    if (cpu.flags.zf)
    {
        goto L_0x004814ed;
    }
    // 004814b4  833d2cab4d0000         +cmp dword ptr [0x4dab2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090092) /* 0x4dab2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004814bb  744f                   -je 0x48150c
    if (cpu.flags.zf)
    {
        goto L_0x0048150c;
    }
    // 004814bd  f644241f20             +test byte ptr [esp + 0x1f], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(31) /* 0x1f */) & 32 /*0x20*/));
    // 004814c2  7448                   -je 0x48150c
    if (cpu.flags.zf)
    {
        goto L_0x0048150c;
    }
    // 004814c4  bd38000000             -mov ebp, 0x38
    cpu.ebp = 56 /*0x38*/;
    // 004814c9  83fe09                 +cmp esi, 9
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004814cc  7530                   -jne 0x4814fe
    if (!cpu.flags.zf)
    {
        goto L_0x004814fe;
    }
    // 004814ce  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004814d3  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
L_0x004814d8:
    // 004814d8  833d30ab4d0000         +cmp dword ptr [0x4dab30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090096) /* 0x4dab30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004814df  740c                   -je 0x4814ed
    if (cpu.flags.zf)
    {
        goto L_0x004814ed;
    }
    // 004814e1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004814e3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004814e5  ff1530ab4d00           -call dword ptr [0x4dab30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090096) /* 0x4dab30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004814eb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004814ed:
    // 004814ed  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004814ef  0f846b000000           -je 0x481560
    if (cpu.flags.zf)
    {
        goto L_0x00481560;
    }
    // 004814f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004814f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814fb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004814fe:
    // 004814fe  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481501  7536                   -jne 0x481539
    if (!cpu.flags.zf)
    {
        goto L_0x00481539;
    }
    // 00481503  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00481508  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048150a  ebcc                   -jmp 0x4814d8
    goto L_0x004814d8;
L_0x0048150c:
    // 0048150c  83fe5b                 +cmp esi, 0x5b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048150f  750b                   -jne 0x48151c
    if (!cpu.flags.zf)
    {
        goto L_0x0048151c;
    }
L_0x00481511:
    // 00481511  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00481516  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00481518  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0048151a  ebbc                   -jmp 0x4814d8
    goto L_0x004814d8;
L_0x0048151c:
    // 0048151c  83fe5c                 +cmp esi, 0x5c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(92 /*0x5c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048151f  74f0                   -je 0x481511
    if (cpu.flags.zf)
    {
        goto L_0x00481511;
    }
    // 00481521  83fe5d                 +cmp esi, 0x5d
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481524  74eb                   -je 0x481511
    if (cpu.flags.zf)
    {
        goto L_0x00481511;
    }
    // 00481526  83fe2c                 +cmp esi, 0x2c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481529  74e6                   -je 0x481511
    if (cpu.flags.zf)
    {
        goto L_0x00481511;
    }
    // 0048152b  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0048152d  2eff15e4634c00         -call dword ptr cs:[0x4c63e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006308) /* 0x4c63e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481534  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00481537  7c11                   -jl 0x48154a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048154a;
    }
L_0x00481539:
    // 00481539  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048153b  759b                   -jne 0x4814d8
    if (!cpu.flags.zf)
    {
        goto L_0x004814d8;
    }
    // 0048153d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048153f  741f                   -je 0x481560
    if (cpu.flags.zf)
    {
        goto L_0x00481560;
    }
    // 00481541  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481543  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481544  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481545  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481546  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481547  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0048154a:
    // 0048154a  bd1d000000             -mov ebp, 0x1d
    cpu.ebp = 29 /*0x1d*/;
    // 0048154f  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481552  75e5                   -jne 0x481539
    if (!cpu.flags.zf)
    {
        goto L_0x00481539;
    }
    // 00481554  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00481559  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048155b  e978ffffff             -jmp 0x4814d8
    goto L_0x004814d8;
L_0x00481560:
    // 00481560  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00481564  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481565  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481566  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048156a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048156b  8b3d28ab4d00           -mov edi, dword ptr [0x4dab28]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090088) /* 0x4dab28 */);
    // 00481571  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481572  2eff15bc634c00         -call dword ptr cs:[0x4c63bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006268) /* 0x4c63bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481579  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048157b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048157d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048157e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048157f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481580  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481581  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481591  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481592  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481593  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481594  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481596  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481599  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0048159c  b900395600             -mov ecx, 0x563900
    cpu.ecx = 5650688 /*0x563900*/;
    // 004815a1  68d0234800             -push 0x4823d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4727760 /*0x4823d0*/;
    cpu.esp -= 4;
    // 004815a6  bab0315600             -mov edx, 0x5631b0
    cpu.edx = 5648816 /*0x5631b0*/;
    // 004815ab  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004815ae  8b1d10ab4d00           -mov ebx, dword ptr [0x4dab10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090064) /* 0x4dab10 */);
    // 004815b4  8975f0                 -mov dword ptr [ebp - 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.esi;
    // 004815b7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004815b9  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004815bc  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004815c1  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 004815c4  e8cdf10100             -call 0x4a0796
    cpu.esp -= 4;
    sub_4a0796(app, cpu);
    if (cpu.terminate) return;
    // 004815c9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004815cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004815cd  0f8486000000           -je 0x481659
    if (cpu.flags.zf)
    {
        goto L_0x00481659;
    }
    // 004815d3  b83d000000             -mov eax, 0x3d
    cpu.eax = 61 /*0x3d*/;
L_0x004815d8:
    // 004815d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004815d9  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004815dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004815dd  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004815e0  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004815e3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004815e4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004815e6  0f8477000000           -je 0x481663
    if (cpu.flags.zf)
    {
        goto L_0x00481663;
    }
    // 004815ec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004815f1:
    // 004815f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004815f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004815f3  680cf64c00             -push 0x4cf60c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043724 /*0x4cf60c*/;
    cpu.esp -= 4;
    // 004815f8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004815fa  746b                   -je 0x481667
    if (cpu.flags.zf)
    {
        goto L_0x00481667;
    }
    // 004815fc  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x00481601:
    // 00481601  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481602  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481607  e874da0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 0048160c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048160f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481611  741a                   -je 0x48162d
    if (cpu.flags.zf)
    {
        goto L_0x0048162d;
    }
    // 00481613  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00481616  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481617  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0048161a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048161b  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048161e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048161f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481620  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00481623  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481624  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00481627  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481628  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048162b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0048162d:
    // 0048162d  6828f64c00             -push 0x4cf628
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043752 /*0x4cf628*/;
    cpu.esp -= 4;
    // 00481632  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481634  7438                   -je 0x48166e
    if (cpu.flags.zf)
    {
        goto L_0x0048166e;
    }
    // 00481636  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0048163b:
    // 0048163b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048163c  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481641  e83ada0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481646  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481649  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048164b  7428                   -je 0x481675
    if (cpu.flags.zf)
    {
        goto L_0x00481675;
    }
    // 0048164d  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00481650  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00481652  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481653  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481654  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481655  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481656  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00481659:
    // 00481659  b83b000000             -mov eax, 0x3b
    cpu.eax = 59 /*0x3b*/;
    // 0048165e  e975ffffff             -jmp 0x4815d8
    goto L_0x004815d8;
L_0x00481663:
    // 00481663  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00481665  eb8a                   -jmp 0x4815f1
    goto L_0x004815f1;
L_0x00481667:
    // 00481667  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0048166c  eb93                   -jmp 0x481601
    goto L_0x00481601;
L_0x0048166e:
    // 0048166e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00481673  ebc6                   -jmp 0x48163b
    goto L_0x0048163b;
L_0x00481675:
    // 00481675  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00481678  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481679  8b7d1c                 -mov edi, dword ptr [ebp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048167c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048167d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048167e  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00481681  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481682  2eff15d0634c00         -call dword ptr cs:[0x4c63d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006288) /* 0x4c63d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481689  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0048168b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048168c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048168d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048168e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048168f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4816a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004816a0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004816a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004816a6  741d                   -je 0x4816c5
    if (cpu.flags.zf)
    {
        goto L_0x004816c5;
    }
    // 004816a8  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004816ac  3b9054040000           +cmp edx, dword ptr [eax + 0x454]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004816b2  7511                   -jne 0x4816c5
    if (!cpu.flags.zf)
    {
        goto L_0x004816c5;
    }
    // 004816b4  80b85d04000000         +cmp byte ptr [eax + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004816bb  7408                   -je 0x4816c5
    if (cpu.flags.zf)
    {
        goto L_0x004816c5;
    }
    // 004816bd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004816c2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004816c5:
    // 004816c5  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004816ca  e879880000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004816cf  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004816d4  e887880000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004816d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004816db  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4816e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004816e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004816e1  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004816e4  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004816e8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004816ea  7409                   -je 0x4816f5
    if (cpu.flags.zf)
    {
        goto L_0x004816f5;
    }
    // 004816ec  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004816f3  750c                   -jne 0x481701
    if (!cpu.flags.zf)
    {
        goto L_0x00481701;
    }
L_0x004816f5:
    // 004816f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004816fa  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004816fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004816fe  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481701:
    // 00481701  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481702  6800f64c00             -push 0x4cf600
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043712 /*0x4cf600*/;
    cpu.esp -= 4;
    // 00481707  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481709  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 0048170e  e86dd90100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481713  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481716  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0048171b  e828880000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00481720  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481724  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481725  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048172b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048172c  2eff15b8634c00         -call dword ptr cs:[0x4c63b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006264) /* 0x4c63b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481733  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481737  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481738  8bb354040000           -mov esi, dword ptr [ebx + 0x454]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048173e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048173f  2eff15dc634c00         -call dword ptr cs:[0x4c63dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006300) /* 0x4c63dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481746  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0048174b  e810880000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00481750  833dd0b14d0000         +cmp dword ptr [0x4db1d0], 0
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
    // 00481757  7406                   -je 0x48175f
    if (cpu.flags.zf)
    {
        goto L_0x0048175f;
    }
    // 00481759  ff15d0b14d00           -call dword ptr [0x4db1d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5091792) /* 0x4db1d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048175f:
    // 0048175f  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00481763  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 00481769  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048176a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048176f  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00481772  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481773  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481780  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00481784  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00481788  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0048178d  7505                   -jne 0x481794
    if (!cpu.flags.zf)
    {
        goto L_0x00481794;
    }
    // 0048178f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481791  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481794:
    // 00481794  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481795  68f4f54c00             -push 0x4cf5f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043700 /*0x4cf5f4*/;
    cpu.esp -= 4;
    // 0048179a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048179c  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 004817a1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004817a3  e8d8d80100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 004817a8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004817ab  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004817ae  7405                   -je 0x4817b5
    if (cpu.flags.zf)
    {
        goto L_0x004817b5;
    }
    // 004817b0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004817b5:
    // 004817b5  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004817b8  7403                   -je 0x4817bd
    if (cpu.flags.zf)
    {
        goto L_0x004817bd;
    }
    // 004817ba  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004817bd:
    // 004817bd  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 004817c0  7403                   -je 0x4817c5
    if (cpu.flags.zf)
    {
        goto L_0x004817c5;
    }
    // 004817c2  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004817c5:
    // 004817c5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004817c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004817c9  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004817cc  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 004817cf  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004817d5  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004817db  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004817dd  e892f50100             -call 0x4a0d74
    cpu.esp -= 4;
    sub_4a0d74(app, cpu);
    if (cpu.terminate) return;
    // 004817e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004817e5  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4817f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004817f0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004817f4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004817f8  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004817fd  7505                   -jne 0x481804
    if (!cpu.flags.zf)
    {
        goto L_0x00481804;
    }
    // 004817ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481801  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481804:
    // 00481804  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481805  68e8f54c00             -push 0x4cf5e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043688 /*0x4cf5e8*/;
    cpu.esp -= 4;
    // 0048180a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048180c  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481811  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481813  e868d80100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481818  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048181b  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0048181e  7405                   -je 0x481825
    if (cpu.flags.zf)
    {
        goto L_0x00481825;
    }
    // 00481820  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00481825:
    // 00481825  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00481828  7403                   -je 0x48182d
    if (cpu.flags.zf)
    {
        goto L_0x0048182d;
    }
    // 0048182a  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0048182d:
    // 0048182d  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 00481830  7403                   -je 0x481835
    if (cpu.flags.zf)
    {
        goto L_0x00481835;
    }
    // 00481832  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00481835:
    // 00481835  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00481837  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481839  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0048183c  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 0048183f  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00481845  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048184a  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00481850  e81ff50100             -call 0x4a0d74
    cpu.esp -= 4;
    sub_4a0d74(app, cpu);
    if (cpu.terminate) return;
    // 00481855  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481856  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481858  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481860  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00481865  743a                   -je 0x4818a1
    if (cpu.flags.zf)
    {
        goto L_0x004818a1;
    }
    // 00481867  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048186b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0048186e  8b0d40ab4d00           -mov ecx, dword ptr [0x4dab40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090112) /* 0x4dab40 */);
    // 00481874  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00481877  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481879  740a                   -je 0x481885
    if (cpu.flags.zf)
    {
        goto L_0x00481885;
    }
    // 0048187b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048187d  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 00481880  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00481885:
    // 00481885  68dcf54c00             -push 0x4cf5dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043676 /*0x4cf5dc*/;
    cpu.esp -= 4;
    // 0048188a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048188c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0048188e  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481893  8890f4b24d00           -mov byte ptr [eax + 0x4db2f4], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092084) /* 0x4db2f4 */) = cpu.dl;
    // 00481899  e8e2d70100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 0048189e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004818a1:
    // 004818a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004818a3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4818b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004818b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004818b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004818b3  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004818b7  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 004818bc  0f84b1000000           -je 0x481973
    if (cpu.flags.zf)
    {
        goto L_0x00481973;
    }
    // 004818c2  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004818c4  8b0dd0355600           -mov ecx, dword ptr [0x5635d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5649872) /* 0x5635d0 */);
    // 004818ca  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004818d0  39ce                   +cmp esi, ecx
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
    // 004818d2  7e02                   -jle 0x4818d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004818d6;
    }
    // 004818d4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x004818d6:
    // 004818d6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004818d8  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004818db  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004818de  8b1d40ab4d00           -mov ebx, dword ptr [0x4dab40]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090112) /* 0x4dab40 */);
    // 004818e4  a3dc355600             -mov dword ptr [0x5635dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5649884) /* 0x5635dc */) = cpu.eax;
    // 004818e9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004818eb  740e                   -je 0x4818fb
    if (cpu.flags.zf)
    {
        goto L_0x004818fb;
    }
    // 004818ed  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004818ef  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004818f1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004818f6  a3dc355600             -mov dword ptr [0x5635dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5649884) /* 0x5635dc */) = cpu.eax;
L_0x004818fb:
    // 004818fb  a1dc355600             -mov eax, dword ptr [0x5635dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5649884) /* 0x5635dc */);
    // 00481900  c680f4b24d0001         -mov byte ptr [eax + 0x4db2f4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092084) /* 0x4db2f4 */) = 1 /*0x1*/;
    // 00481907  833decb24d0000         +cmp dword ptr [0x4db2ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092076) /* 0x4db2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048190e  7424                   -je 0x481934
    if (cpu.flags.zf)
    {
        goto L_0x00481934;
    }
    // 00481910  3b053cab4d00           +cmp eax, dword ptr [0x4dab3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090108) /* 0x4dab3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481916  751c                   -jne 0x481934
    if (!cpu.flags.zf)
    {
        goto L_0x00481934;
    }
    // 00481918  803d2cb34d0000         +cmp byte ptr [0x4db32c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092140) /* 0x4db32c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048191f  7413                   -je 0x481934
    if (cpu.flags.zf)
    {
        goto L_0x00481934;
    }
    // 00481921  6888f54c00             -push 0x4cf588
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043592 /*0x4cf588*/;
    cpu.esp -= 4;
    // 00481926  2eff1554654c00         -call dword ptr cs:[0x4c6554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006676) /* 0x4c6554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048192d  2eff156c644c00         -call dword ptr cs:[0x4c646c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006444) /* 0x4c646c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00481934:
    // 00481934  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 00481937  8b1dd8355600           -mov ebx, dword ptr [0x5635d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5649880) /* 0x5635d8 */);
    // 0048193d  83e701                 -and edi, 1
    cpu.edi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00481940  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481942  743a                   -je 0x48197e
    if (cpu.flags.zf)
    {
        goto L_0x0048197e;
    }
    // 00481944  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00481946  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00481948:
    // 00481948  4e                     -dec esi
    (cpu.esi)--;
    // 00481949  83feff                 +cmp esi, -1
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
    // 0048194c  7411                   -je 0x48195f
    if (cpu.flags.zf)
    {
        goto L_0x0048195f;
    }
    // 0048194e  8b15dc355600           -mov edx, dword ptr [0x5635dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5649884) /* 0x5635dc */);
    // 00481954  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00481956  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00481958  e883070000             -call 0x4820e0
    cpu.esp -= 4;
    sub_4820e0(app, cpu);
    if (cpu.terminate) return;
    // 0048195d  ebe9                   -jmp 0x481948
    goto L_0x00481948;
L_0x0048195f:
    // 0048195f  6898f54c00             -push 0x4cf598
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043608 /*0x4cf598*/;
    cpu.esp -= 4;
L_0x00481964:
    // 00481964  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481966  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 0048196b  e810d70100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481970  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00481973:
    // 00481973  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481978  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481979  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048197a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048197b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0048197e:
    // 0048197e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00481982  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00481986  e8f5030000             -call 0x481d80
    cpu.esp -= 4;
    sub_481d80(app, cpu);
    if (cpu.terminate) return;
    // 0048198b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048198d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048198f  7417                   -je 0x4819a8
    if (cpu.flags.zf)
    {
        goto L_0x004819a8;
    }
L_0x00481991:
    // 00481991  4e                     -dec esi
    (cpu.esi)--;
    // 00481992  83feff                 +cmp esi, -1
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
    // 00481995  742d                   -je 0x4819c4
    if (cpu.flags.zf)
    {
        goto L_0x004819c4;
    }
    // 00481997  8b15dc355600           -mov edx, dword ptr [0x5635dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5649884) /* 0x5635dc */);
    // 0048199d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048199f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004819a1  e83a070000             -call 0x4820e0
    cpu.esp -= 4;
    sub_4820e0(app, cpu);
    if (cpu.terminate) return;
    // 004819a6  ebe9                   -jmp 0x481991
    goto L_0x00481991;
L_0x004819a8:
    // 004819a8  68c8f54c00             -push 0x4cf5c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043656 /*0x4cf5c8*/;
    cpu.esp -= 4;
    // 004819ad  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004819af  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 004819b4  e8c7d60100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 004819b9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004819bc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004819be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819c1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004819c4:
    // 004819c4  68acf54c00             -push 0x4cf5ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043628 /*0x4cf5ac*/;
    cpu.esp -= 4;
    // 004819c9  eb99                   -jmp 0x481964
    goto L_0x00481964;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4819d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004819d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004819d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004819d2  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004819d6  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004819da  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004819df  744f                   -je 0x481a30
    if (cpu.flags.zf)
    {
        goto L_0x00481a30;
    }
    // 004819e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004819e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004819e3  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004819e5  8b1dd0355600           -mov ebx, dword ptr [0x5635d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5649872) /* 0x5635d0 */);
    // 004819eb  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004819f1  39d9                   +cmp ecx, ebx
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
    // 004819f3  7f21                   -jg 0x481a16
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00481a16;
    }
L_0x004819f5:
    // 004819f5  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004819f7  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 004819fa  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004819fd  83e601                 -and esi, 1
    cpu.esi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00481a00  83e77f                 -and edi, 0x7f
    cpu.edi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x00481a03:
    // 00481a03  49                     -dec ecx
    (cpu.ecx)--;
    // 00481a04  83f9ff                 +cmp ecx, -1
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
    // 00481a07  7411                   -je 0x481a1a
    if (cpu.flags.zf)
    {
        goto L_0x00481a1a;
    }
    // 00481a09  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00481a0b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00481a0d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00481a0f  e8cc060000             -call 0x4820e0
    cpu.esp -= 4;
    sub_4820e0(app, cpu);
    if (cpu.terminate) return;
    // 00481a14  ebed                   -jmp 0x481a03
    goto L_0x00481a03;
L_0x00481a16:
    // 00481a16  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00481a18  ebdb                   -jmp 0x4819f5
    goto L_0x004819f5;
L_0x00481a1a:
    // 00481a1a  687cf54c00             -push 0x4cf57c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043580 /*0x4cf57c*/;
    cpu.esp -= 4;
    // 00481a1f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481a21  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481a26  e855d60100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481a2b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481a2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481a30:
    // 00481a30  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481a35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a37  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481a40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481a41  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481a44  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00481a48  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481a4a  7509                   -jne 0x481a55
    if (!cpu.flags.zf)
    {
        goto L_0x00481a55;
    }
L_0x00481a4c:
    // 00481a4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481a4e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481a51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a52  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481a55:
    // 00481a55  686cf54c00             -push 0x4cf56c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043564 /*0x4cf56c*/;
    cpu.esp -= 4;
    // 00481a5a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481a5c  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481a61  e81ad60100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481a66  8aa35d040000           -mov ah, byte ptr [ebx + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
    // 00481a6c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481a6f  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00481a71  75d9                   -jne 0x481a4c
    if (!cpu.flags.zf)
    {
        goto L_0x00481a4c;
    }
    // 00481a73  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481a75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481a76  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00481a7c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481a7d  2eff15e8634c00         -call dword ptr cs:[0x4c63e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006312) /* 0x4c63e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481a84  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481a86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481a87  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00481a8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481a8e  2eff15c8634c00         -call dword ptr cs:[0x4c63c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006280) /* 0x4c63c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481a95  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00481a98  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 00481a9e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481aa2  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 00481aa8  833dd0b14d0000         +cmp dword ptr [0x4db1d0], 0
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
    // 00481aaf  749b                   -je 0x481a4c
    if (cpu.flags.zf)
    {
        goto L_0x00481a4c;
    }
    // 00481ab1  ff15d0b14d00           -call dword ptr [0x4db1d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5091792) /* 0x4db1d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481ab7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481ab9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481abc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481abd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_481ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481ac0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481ac4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00481ac8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481ac9  6840f54c00             -push 0x4cf540
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043520 /*0x4cf540*/;
    cpu.esp -= 4;
    // 00481ace  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481ad0  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481ad5  e8a6d50100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481ada  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481add  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481adf  7409                   -je 0x481aea
    if (cpu.flags.zf)
    {
        goto L_0x00481aea;
    }
    // 00481ae1  80ba5d04000000         +cmp byte ptr [edx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00481ae8  750f                   -jne 0x481af9
    if (!cpu.flags.zf)
    {
        goto L_0x00481af9;
    }
L_0x00481aea:
    // 00481aea  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00481aee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481af0  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00481af6  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481af9:
    // 00481af9  6854f54c00             -push 0x4cf554
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043540 /*0x4cf554*/;
    cpu.esp -= 4;
    // 00481afe  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481b00  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481b05  e876d50100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481b0a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481b0d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481b0f  681cab4d00             -push 0x4dab1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090076 /*0x4dab1c*/;
    cpu.esp -= 4;
    // 00481b14  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481b16  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00481b18  2eff153c644c00         -call dword ptr cs:[0x4c643c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006396) /* 0x4c643c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481b1f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481b21  6820ab4d00             -push 0x4dab20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090080 /*0x4dab20*/;
    cpu.esp -= 4;
    // 00481b26  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481b28  6a54                   -push 0x54
    app->getMemory<x86::reg32>(cpu.esp-4) = 84 /*0x54*/;
    cpu.esp -= 4;
    // 00481b2a  2eff153c644c00         -call dword ptr cs:[0x4c643c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006396) /* 0x4c643c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481b31  833d1cab4d0000         +cmp dword ptr [0x4dab1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090076) /* 0x4dab1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481b38  740f                   -je 0x481b49
    if (cpu.flags.zf)
    {
        goto L_0x00481b49;
    }
    // 00481b3a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481b3c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481b3e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481b40  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00481b42  2eff153c644c00         -call dword ptr cs:[0x4c643c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006396) /* 0x4c643c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00481b49:
    // 00481b49  833d20ab4d0000         +cmp dword ptr [0x4dab20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090080) /* 0x4dab20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481b50  7498                   -je 0x481aea
    if (cpu.flags.zf)
    {
        goto L_0x00481aea;
    }
    // 00481b52  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481b54  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481b56  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481b58  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 00481b5a  2eff153c644c00         -call dword ptr cs:[0x4c643c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006396) /* 0x4c643c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481b61  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00481b65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481b67  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00481b6d  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_481b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481b70  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00481b74  3d60f00000             +cmp eax, 0xf060
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61536 /*0xf060*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481b79  7424                   -je 0x481b9f
    if (cpu.flags.zf)
    {
        goto L_0x00481b9f;
    }
    // 00481b7b  3d20f00000             +cmp eax, 0xf020
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61472 /*0xf020*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481b80  741d                   -je 0x481b9f
    if (cpu.flags.zf)
    {
        goto L_0x00481b9f;
    }
    // 00481b82  3d30f00000             +cmp eax, 0xf030
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61488 /*0xf030*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481b87  7416                   -je 0x481b9f
    if (cpu.flags.zf)
    {
        goto L_0x00481b9f;
    }
    // 00481b89  3d20f10000             +cmp eax, 0xf120
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61728 /*0xf120*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481b8e  740f                   -je 0x481b9f
    if (cpu.flags.zf)
    {
        goto L_0x00481b9f;
    }
    // 00481b90  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481b94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481b96  8a825d040000           -mov al, byte ptr [edx + 0x45d]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
    // 00481b9c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481b9f:
    // 00481b9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481ba1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481bb0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481bb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481bb6  7505                   -jne 0x481bbd
    if (!cpu.flags.zf)
    {
        goto L_0x00481bbd;
    }
    // 00481bb8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481bba  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481bbd:
    // 00481bbd  682cf54c00             -push 0x4cf52c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043500 /*0x4cf52c*/;
    cpu.esp -= 4;
    // 00481bc2  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481bc4  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481bc9  c7805404000000000000   -mov dword ptr [eax + 0x454], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */) = 0 /*0x0*/;
    // 00481bd3  e8a8d40100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481bd8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481bdb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481bdd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_481be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481be0  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00481be5  7508                   -jne 0x481bef
    if (!cpu.flags.zf)
    {
        goto L_0x00481bef;
    }
    // 00481be7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481bec  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481bef:
    // 00481bef  681cf54c00             -push 0x4cf51c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043484 /*0x4cf51c*/;
    cpu.esp -= 4;
    // 00481bf4  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481bf6  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481bfb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00481c00  e87bd40100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481c05  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481c08  890d18ab4d00           -mov dword ptr [0x4dab18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090072) /* 0x4dab18 */) = cpu.ecx;
    // 00481c0e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481c13  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c20  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00481c25  7508                   -jne 0x481c2f
    if (!cpu.flags.zf)
    {
        goto L_0x00481c2f;
    }
    // 00481c27  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481c2c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481c2f:
    // 00481c2f  6810f54c00             -push 0x4cf510
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043472 /*0x4cf510*/;
    cpu.esp -= 4;
    // 00481c34  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481c36  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481c3b  e840d40100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481c40  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481c43  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481c45  2eff150c644c00         -call dword ptr cs:[0x4c640c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006348) /* 0x4c640c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481c4c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481c51  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c60  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481c64  3b15543d5600           +cmp edx, dword ptr [0x563d54]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481c6a  7405                   -je 0x481c71
    if (cpu.flags.zf)
    {
        goto L_0x00481c71;
    }
    // 00481c6c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481c6e  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481c71:
    // 00481c71  6800f54c00             -push 0x4cf500
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043456 /*0x4cf500*/;
    cpu.esp -= 4;
    // 00481c76  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481c78  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481c7d  e8fed30100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481c82  8b0dd4355600           -mov ecx, dword ptr [0x5635d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5649876) /* 0x5635d4 */);
    // 00481c88  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481c8b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481c8d  7408                   -je 0x481c97
    if (cpu.flags.zf)
    {
        goto L_0x00481c97;
    }
    // 00481c8f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481c91  ff15d4355600           -call dword ptr [0x5635d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5649876) /* 0x5635d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00481c97:
    // 00481c97  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481c99  2eff1534644c00         -call dword ptr cs:[0x4c6434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006388) /* 0x4c6434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481ca0  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 00481ca5  b8f4b24d00             -mov eax, 0x4db2f4
    cpu.eax = 5092084 /*0x4db2f4*/;
    // 00481caa  e86d830000             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00481caf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481cb1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481cc0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481cc4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481cc6  7465                   -je 0x481d2d
    if (cpu.flags.zf)
    {
        goto L_0x00481d2d;
    }
    // 00481cc8  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481ccc  3b0d543d5600           +cmp ecx, dword ptr [0x563d54]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481cd2  7559                   -jne 0x481d2d
    if (!cpu.flags.zf)
    {
        goto L_0x00481d2d;
    }
    // 00481cd4  833dd435560000         +cmp dword ptr [0x5635d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5649876) /* 0x5635d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481cdb  7555                   -jne 0x481d32
    if (!cpu.flags.zf)
    {
        goto L_0x00481d32;
    }
L_0x00481cdd:
    // 00481cdd  80ba5d04000000         +cmp byte ptr [edx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00481ce4  7409                   -je 0x481cef
    if (cpu.flags.zf)
    {
        goto L_0x00481cef;
    }
    // 00481ce6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481ce8  2eff1534644c00         -call dword ptr cs:[0x4c6434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006388) /* 0x4c6434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00481cef:
    // 00481cef  833d743d560000         +cmp dword ptr [0x563d74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5651828) /* 0x563d74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481cf6  7521                   -jne 0x481d19
    if (!cpu.flags.zf)
    {
        goto L_0x00481d19;
    }
    // 00481cf8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481cf9  68e0f44c00             -push 0x4cf4e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043424 /*0x4cf4e0*/;
    cpu.esp -= 4;
    // 00481cfe  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00481d00  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481d05  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00481d0a  e871d30100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481d0f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481d12  893d743d5600           -mov dword ptr [0x563d74], edi
    app->getMemory<x86::reg32>(x86::reg32(5651828) /* 0x563d74 */) = cpu.edi;
    // 00481d18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481d19:
    // 00481d19  68f0f44c00             -push 0x4cf4f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043440 /*0x4cf4f0*/;
    cpu.esp -= 4;
    // 00481d1e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481d20  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481d25  e856d30100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481d2a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00481d2d:
    // 00481d2d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00481d2f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481d32:
    // 00481d32  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481d37  ff15d4355600           -call dword ptr [0x5635d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5649876) /* 0x5635d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481d3d  eb9e                   -jmp 0x481cdd
    goto L_0x00481cdd;
}

/* align: skip 0x00 */
void Application::sub_481d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481d40  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00481d44  a3743d5600             -mov dword ptr [0x563d74], eax
    app->getMemory<x86::reg32>(x86::reg32(5651828) /* 0x563d74 */) = cpu.eax;
    // 00481d49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481d4b  741f                   -je 0x481d6c
    if (cpu.flags.zf)
    {
        goto L_0x00481d6c;
    }
    // 00481d4d  b8b8f44c00             -mov eax, 0x4cf4b8
    cpu.eax = 5043384 /*0x4cf4b8*/;
L_0x00481d52:
    // 00481d52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481d53  68ccf44c00             -push 0x4cf4cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043404 /*0x4cf4cc*/;
    cpu.esp -= 4;
    // 00481d58  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481d5a  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 00481d5f  e81cd30100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00481d64  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481d67  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00481d69  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00481d6c:
    // 00481d6c  b8c0f44c00             -mov eax, 0x4cf4c0
    cpu.eax = 5043392 /*0x4cf4c0*/;
    // 00481d71  ebdf                   -jmp 0x481d52
    goto L_0x00481d52;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481d80  3d04010000             +cmp eax, 0x104
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481d85  752d                   -jne 0x481db4
    if (!cpu.flags.zf)
    {
        goto L_0x00481db4;
    }
L_0x00481d87:
    // 00481d87  83fa65                 +cmp edx, 0x65
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
    // 00481d8a  7334                   -jae 0x481dc0
    if (!cpu.flags.cf)
    {
        goto L_0x00481dc0;
    }
    // 00481d8c  83fa28                 +cmp edx, 0x28
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481d8f  0f83c9000000           -jae 0x481e5e
    if (!cpu.flags.cf)
    {
        goto L_0x00481e5e;
    }
    // 00481d95  83fa24                 +cmp edx, 0x24
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
    // 00481d98  0f8311010000           -jae 0x481eaf
    if (!cpu.flags.cf)
    {
        goto L_0x00481eaf;
    }
    // 00481d9e  83fa22                 +cmp edx, 0x22
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
    // 00481da1  0f8319010000           -jae 0x481ec0
    if (!cpu.flags.cf)
    {
        goto L_0x00481ec0;
    }
    // 00481da7  83fa21                 +cmp edx, 0x21
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481daa  750f                   -jne 0x481dbb
    if (!cpu.flags.zf)
    {
        goto L_0x00481dbb;
    }
    // 00481dac  ba00490000             -mov edx, 0x4900
    cpu.edx = 18688 /*0x4900*/;
    // 00481db1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481db3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481db4:
    // 00481db4  3d00010000             +cmp eax, 0x100
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
    // 00481db9  74cc                   -je 0x481d87
    if (cpu.flags.zf)
    {
        goto L_0x00481d87;
    }
L_0x00481dbb:
    // 00481dbb  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00481dbd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481dbf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481dc0:
    // 00481dc0  0f864c010000           -jbe 0x481f12
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481f12;
    }
    // 00481dc6  83fa73                 +cmp edx, 0x73
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481dc9  731c                   -jae 0x481de7
    if (!cpu.flags.cf)
    {
        goto L_0x00481de7;
    }
    // 00481dcb  83fa69                 +cmp edx, 0x69
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481dce  7364                   -jae 0x481e34
    if (!cpu.flags.cf)
    {
        goto L_0x00481e34;
    }
    // 00481dd0  83fa67                 +cmp edx, 0x67
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
    // 00481dd3  0f8241010000           -jb 0x481f1a
    if (cpu.flags.cf)
    {
        goto L_0x00481f1a;
    }
    // 00481dd9  0f8743010000           -ja 0x481f22
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00481f22;
    }
    // 00481ddf  ba51000000             -mov edx, 0x51
    cpu.edx = 81 /*0x51*/;
    // 00481de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481de6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481de7:
    // 00481de7  0f864d010000           -jbe 0x481f3a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481f3a;
    }
    // 00481ded  83fa77                 +cmp edx, 0x77
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481df0  7317                   -jae 0x481e09
    if (!cpu.flags.cf)
    {
        goto L_0x00481e09;
    }
    // 00481df2  83fa75                 +cmp edx, 0x75
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481df5  0f8247010000           -jb 0x481f42
    if (cpu.flags.cf)
    {
        goto L_0x00481f42;
    }
    // 00481dfb  0f8749010000           -ja 0x481f4a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00481f4a;
    }
    // 00481e01  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 00481e06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481e09:
    // 00481e09  0f8643010000           -jbe 0x481f52
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481f52;
    }
    // 00481e0f  83fa79                 +cmp edx, 0x79
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(121 /*0x79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e12  0f8242010000           -jb 0x481f5a
    if (cpu.flags.cf)
    {
        goto L_0x00481f5a;
    }
    // 00481e18  0f8644010000           -jbe 0x481f62
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481f62;
    }
    // 00481e1e  83fa7a                 +cmp edx, 0x7a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e21  0f8643010000           -jbe 0x481f6a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481f6a;
    }
    // 00481e27  83fa7b                 +cmp edx, 0x7b
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
    // 00481e2a  758f                   -jne 0x481dbb
    if (!cpu.flags.zf)
    {
        goto L_0x00481dbb;
    }
    // 00481e2c  ba00880000             -mov edx, 0x8800
    cpu.edx = 34816 /*0x8800*/;
    // 00481e31  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481e34:
    // 00481e34  0f86f0000000           -jbe 0x481f2a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481f2a;
    }
    // 00481e3a  83fa71                 +cmp edx, 0x71
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(113 /*0x71*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e3d  7311                   -jae 0x481e50
    if (!cpu.flags.cf)
    {
        goto L_0x00481e50;
    }
    // 00481e3f  83fa70                 +cmp edx, 0x70
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e42  0f8573ffffff           -jne 0x481dbb
    if (!cpu.flags.zf)
    {
        goto L_0x00481dbb;
    }
    // 00481e48  ba003b0000             -mov edx, 0x3b00
    cpu.edx = 15104 /*0x3b00*/;
    // 00481e4d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481e50:
    // 00481e50  0f87dc000000           -ja 0x481f32
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00481f32;
    }
    // 00481e56  ba003c0000             -mov edx, 0x3c00
    cpu.edx = 15360 /*0x3c00*/;
    // 00481e5b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481e5e:
    // 00481e5e  0f8686000000           -jbe 0x481eea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481eea;
    }
    // 00481e64  83fa61                 +cmp edx, 0x61
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e67  7316                   -jae 0x481e7f
    if (!cpu.flags.cf)
    {
        goto L_0x00481e7f;
    }
    // 00481e69  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e6c  732e                   -jae 0x481e9c
    if (!cpu.flags.cf)
    {
        goto L_0x00481e9c;
    }
    // 00481e6e  83fa2d                 +cmp edx, 0x2d
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
    // 00481e71  0f8544ffffff           -jne 0x481dbb
    if (!cpu.flags.zf)
    {
        goto L_0x00481dbb;
    }
    // 00481e77  ba00520000             -mov edx, 0x5200
    cpu.edx = 20992 /*0x5200*/;
    // 00481e7c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481e7f:
    // 00481e7f  0f8675000000           -jbe 0x481efa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481efa;
    }
    // 00481e85  83fa63                 +cmp edx, 0x63
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e88  0f8274000000           -jb 0x481f02
    if (cpu.flags.cf)
    {
        goto L_0x00481f02;
    }
    // 00481e8e  0f8776000000           -ja 0x481f0a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00481f0a;
    }
    // 00481e94  ba47000000             -mov edx, 0x47
    cpu.edx = 71 /*0x47*/;
    // 00481e99  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481e9c:
    // 00481e9c  7654                   -jbe 0x481ef2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481ef2;
    }
    // 00481e9e  83fa60                 +cmp edx, 0x60
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481ea1  0f8514ffffff           -jne 0x481dbb
    if (!cpu.flags.zf)
    {
        goto L_0x00481dbb;
    }
    // 00481ea7  ba00520000             -mov edx, 0x5200
    cpu.edx = 20992 /*0x5200*/;
    // 00481eac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481eae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481eaf:
    // 00481eaf  7621                   -jbe 0x481ed2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481ed2;
    }
    // 00481eb1  83fa26                 +cmp edx, 0x26
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481eb4  7224                   -jb 0x481eda
    if (cpu.flags.cf)
    {
        goto L_0x00481eda;
    }
    // 00481eb6  772a                   -ja 0x481ee2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00481ee2;
    }
    // 00481eb8  ba00480000             -mov edx, 0x4800
    cpu.edx = 18432 /*0x4800*/;
    // 00481ebd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ebf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481ec0:
    // 00481ec0  7708                   -ja 0x481eca
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00481eca;
    }
    // 00481ec2  ba00510000             -mov edx, 0x5100
    cpu.edx = 20736 /*0x5100*/;
    // 00481ec7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ec9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481eca:
    // 00481eca  ba004f0000             -mov edx, 0x4f00
    cpu.edx = 20224 /*0x4f00*/;
    // 00481ecf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ed1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481ed2:
    // 00481ed2  ba00470000             -mov edx, 0x4700
    cpu.edx = 18176 /*0x4700*/;
    // 00481ed7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ed9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481eda:
    // 00481eda  ba004b0000             -mov edx, 0x4b00
    cpu.edx = 19200 /*0x4b00*/;
    // 00481edf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ee1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481ee2:
    // 00481ee2  ba004d0000             -mov edx, 0x4d00
    cpu.edx = 19712 /*0x4d00*/;
    // 00481ee7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ee9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481eea:
    // 00481eea  ba00500000             -mov edx, 0x5000
    cpu.edx = 20480 /*0x5000*/;
    // 00481eef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ef1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481ef2:
    // 00481ef2  ba00530000             -mov edx, 0x5300
    cpu.edx = 21248 /*0x5300*/;
    // 00481ef7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ef9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481efa:
    // 00481efa  ba5a000000             -mov edx, 0x5a
    cpu.edx = 90 /*0x5a*/;
    // 00481eff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f02:
    // 00481f02  ba58000000             -mov edx, 0x58
    cpu.edx = 88 /*0x58*/;
    // 00481f07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f0a:
    // 00481f0a  ba41000000             -mov edx, 0x41
    cpu.edx = 65 /*0x41*/;
    // 00481f0f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f12:
    // 00481f12  ba004c0000             -mov edx, 0x4c00
    cpu.edx = 19456 /*0x4c00*/;
    // 00481f17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f1a:
    // 00481f1a  ba44000000             -mov edx, 0x44
    cpu.edx = 68 /*0x44*/;
    // 00481f1f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f22:
    // 00481f22  ba57000000             -mov edx, 0x57
    cpu.edx = 87 /*0x57*/;
    // 00481f27  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f2a:
    // 00481f2a  ba45000000             -mov edx, 0x45
    cpu.edx = 69 /*0x45*/;
    // 00481f2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f32:
    // 00481f32  ba003d0000             -mov edx, 0x3d00
    cpu.edx = 15616 /*0x3d00*/;
    // 00481f37  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f3a:
    // 00481f3a  ba003e0000             -mov edx, 0x3e00
    cpu.edx = 15872 /*0x3e00*/;
    // 00481f3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f42:
    // 00481f42  ba003f0000             -mov edx, 0x3f00
    cpu.edx = 16128 /*0x3f00*/;
    // 00481f47  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f4a:
    // 00481f4a  ba00410000             -mov edx, 0x4100
    cpu.edx = 16640 /*0x4100*/;
    // 00481f4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f52:
    // 00481f52  ba00420000             -mov edx, 0x4200
    cpu.edx = 16896 /*0x4200*/;
    // 00481f57  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f5a:
    // 00481f5a  ba00430000             -mov edx, 0x4300
    cpu.edx = 17152 /*0x4300*/;
    // 00481f5f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f62:
    // 00481f62  ba00440000             -mov edx, 0x4400
    cpu.edx = 17408 /*0x4400*/;
    // 00481f67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f6a:
    // 00481f6a  ba00870000             -mov edx, 0x8700
    cpu.edx = 34560 /*0x8700*/;
    // 00481f6f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481f81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481f82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481f83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481f84  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481f87  8b35c4355600           -mov esi, dword ptr [0x5635c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 00481f8d  a1c8355600             -mov eax, dword ptr [0x5635c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5649864) /* 0x5635c8 */);
    // 00481f92  e8b17f0000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00481f97  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481f99  8b35c4355600           -mov esi, dword ptr [0x5635c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 00481f9f  8b15cc355600           -mov edx, dword ptr [0x5635cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5649868) /* 0x5635cc */);
    // 00481fa5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481fa7  39d6                   +cmp esi, edx
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
    // 00481fa9  7455                   -je 0x482000
    if (cpu.flags.zf)
    {
        goto L_0x00482000;
    }
L_0x00481fab:
    // 00481fab  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481fad  7551                   -jne 0x482000
    if (!cpu.flags.zf)
    {
        goto L_0x00482000;
    }
    // 00481faf  8935c4355600           -mov dword ptr [0x5635c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */) = cpu.esi;
    // 00481fb5  8b04b530315600         -mov eax, dword ptr [esi*4 + 0x563130]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5648688) /* 0x563130 */ + cpu.esi * 4);
    // 00481fbc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481fbe  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481fc0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00481fc3  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00481fc6  8a5c2401               -mov bl, byte ptr [esp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00481fca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481fcc  750e                   -jne 0x481fdc
    if (!cpu.flags.zf)
    {
        goto L_0x00481fdc;
    }
    // 00481fce  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481fd0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481fd2  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00481fd5  e8a64d0000             -call 0x486d80
    cpu.esp -= 4;
    sub_486d80(app, cpu);
    if (cpu.terminate) return;
    // 00481fda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00481fdc:
    // 00481fdc  8b35c4355600           -mov esi, dword ptr [0x5635c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 00481fe2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481fe4  7512                   -jne 0x481ff8
    if (!cpu.flags.zf)
    {
        goto L_0x00481ff8;
    }
    // 00481fe6  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00481fe9  8b35d0355600           -mov esi, dword ptr [0x5635d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649872) /* 0x5635d0 */);
    // 00481fef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ff1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00481ff4  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00481ff6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x00481ff8:
    // 00481ff8  3b35cc355600           +cmp esi, dword ptr [0x5635cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5649868) /* 0x5635cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481ffe  75ab                   -jne 0x481fab
    if (!cpu.flags.zf)
    {
        goto L_0x00481fab;
    }
L_0x00482000:
    // 00482000  a1c8355600             -mov eax, dword ptr [0x5635c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5649864) /* 0x5635c8 */);
    // 00482005  8935c4355600           -mov dword ptr [0x5635c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */) = cpu.esi;
    // 0048200b  e8507f0000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00482010  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482012  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00482015  8b35c4355600           -mov esi, dword ptr [0x5635c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 0048201b  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048201d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482020  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482021  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482022  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482023  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482024  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482033  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482034  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482035  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482038  8b35c4355600           -mov esi, dword ptr [0x5635c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 0048203e  a1c8355600             -mov eax, dword ptr [0x5635c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5649864) /* 0x5635c8 */);
    // 00482043  e8007f0000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00482048  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048204a  8b35c4355600           -mov esi, dword ptr [0x5635c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 00482050  8b15cc355600           -mov edx, dword ptr [0x5635cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5649868) /* 0x5635cc */);
    // 00482056  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482058  39d6                   +cmp esi, edx
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
    // 0048205a  7453                   -je 0x4820af
    if (cpu.flags.zf)
    {
        goto L_0x004820af;
    }
L_0x0048205c:
    // 0048205c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048205e  754f                   -jne 0x4820af
    if (!cpu.flags.zf)
    {
        goto L_0x004820af;
    }
    // 00482060  8935c4355600           -mov dword ptr [0x5635c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */) = cpu.esi;
    // 00482066  8b04b530315600         -mov eax, dword ptr [esi*4 + 0x563130]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5648688) /* 0x563130 */ + cpu.esi * 4);
    // 0048206d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048206f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482071  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00482074  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00482077  8a5c2401               -mov bl, byte ptr [esp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0048207b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048207d  750e                   -jne 0x48208d
    if (!cpu.flags.zf)
    {
        goto L_0x0048208d;
    }
    // 0048207f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482081  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482083  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00482086  e8f54c0000             -call 0x486d80
    cpu.esp -= 4;
    sub_486d80(app, cpu);
    if (cpu.terminate) return;
    // 0048208b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048208d:
    // 0048208d  8b35c4355600           -mov esi, dword ptr [0x5635c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 00482093  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00482096  8b35d0355600           -mov esi, dword ptr [0x5635d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649872) /* 0x5635d0 */);
    // 0048209c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048209e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004820a1  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004820a3  8b3dcc355600           -mov edi, dword ptr [0x5635cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5649868) /* 0x5635cc */);
    // 004820a9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004820ab  39fa                   +cmp edx, edi
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
    // 004820ad  75ad                   -jne 0x48205c
    if (!cpu.flags.zf)
    {
        goto L_0x0048205c;
    }
L_0x004820af:
    // 004820af  a1c8355600             -mov eax, dword ptr [0x5635c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5649864) /* 0x5635c8 */);
    // 004820b4  8935c4355600           -mov dword ptr [0x5635c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */) = cpu.esi;
    // 004820ba  e8a17e0000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004820bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004820c1  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004820c4  8b35c4355600           -mov esi, dword ptr [0x5635c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 004820ca  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004820cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004820cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004820d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004820d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004820d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004820d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004820d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4820e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004820e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004820e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004820e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004820e4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004820e6  a1c8355600             -mov eax, dword ptr [0x5635c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5649864) /* 0x5635c8 */);
    // 004820eb  8b15cc355600           -mov edx, dword ptr [0x5635cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5649868) /* 0x5635cc */);
    // 004820f1  e8527e0000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004820f6  6689349532315600       -mov word ptr [edx*4 + 0x563132], si
    app->getMemory<x86::reg16>(x86::reg32(5648690) /* 0x563132 */ + cpu.edx * 4) = cpu.si;
    // 004820fe  880c9531315600         -mov byte ptr [edx*4 + 0x563131], cl
    app->getMemory<x86::reg8>(x86::reg32(5648689) /* 0x563131 */ + cpu.edx * 4) = cpu.cl;
    // 00482105  881c9530315600         -mov byte ptr [edx*4 + 0x563130], bl
    app->getMemory<x86::reg8>(x86::reg32(5648688) /* 0x563130 */ + cpu.edx * 4) = cpu.bl;
    // 0048210c  8b15cc355600           -mov edx, dword ptr [0x5635cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5649868) /* 0x5635cc */);
    // 00482112  42                     -inc edx
    (cpu.edx)++;
    // 00482113  8b0dd0355600           -mov ecx, dword ptr [0x5635d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5649872) /* 0x5635d0 */);
    // 00482119  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048211b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048211e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00482120  a1c4355600             -mov eax, dword ptr [0x5635c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 00482125  8915cc355600           -mov dword ptr [0x5635cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5649868) /* 0x5635cc */) = cpu.edx;
    // 0048212b  39d0                   +cmp eax, edx
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
    // 0048212d  7514                   -jne 0x482143
    if (!cpu.flags.zf)
    {
        goto L_0x00482143;
    }
    // 0048212f  8b15c4355600           -mov edx, dword ptr [0x5635c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */);
    // 00482135  42                     -inc edx
    (cpu.edx)++;
    // 00482136  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482138  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048213b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048213d  8915c4355600           -mov dword ptr [0x5635c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5649860) /* 0x5635c4 */) = cpu.edx;
L_0x00482143:
    // 00482143  a1c8355600             -mov eax, dword ptr [0x5635c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5649864) /* 0x5635c8 */);
    // 00482148  e8137e0000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048214d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048214e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048214f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482150  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482151  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482152  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00482155  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482157  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048215a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048215c  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00482160  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482161  8b9054040000           -mov edx, dword ptr [eax + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */);
    // 00482167  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482168  2eff15c8634c00         -call dword ptr cs:[0x4c63c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006280) /* 0x4c63c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048216f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482171  7420                   -je 0x482193
    if (cpu.flags.zf)
    {
        goto L_0x00482193;
    }
    // 00482173  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482177  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482178  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048217c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x0048217d:
    // 0048217d  2eff1524644c00         -call dword ptr cs:[0x4c6424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006372) /* 0x4c6424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482184  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482186  2eff1520644c00         -call dword ptr cs:[0x4c6420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006368) /* 0x4c6420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048218d  83c408                 +add esp, 8
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
    // 00482190  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482191  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482192  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482193:
    // 00482193  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482194  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482195  ebe6                   -jmp 0x48217d
    goto L_0x0048217d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4821a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004821a0  689cf44c00             -push 0x4cf49c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043356 /*0x4cf49c*/;
    cpu.esp -= 4;
    // 004821a5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004821a7  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 004821ac  e8cfce0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 004821b1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004821b4  e803030000             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004821b9  b8a0214800             -mov eax, 0x4821a0
    cpu.eax = 4727200 /*0x4821a0*/;
    // 004821be  e8a11c0000             -call 0x483e64
    cpu.esp -= 4;
    sub_483e64(app, cpu);
    if (cpu.terminate) return;
    // 004821c3  e8dd8b0100             -call 0x49ada5
    cpu.esp -= 4;
    sub_49ada5(app, cpu);
    if (cpu.terminate) return;
    // 004821c8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004821ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4821d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004821d0  a3d4355600             -mov dword ptr [0x5635d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5649876) /* 0x5635d4 */) = cpu.eax;
    // 004821d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4821e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004821e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004821e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004821e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004821e3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004821e5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004821e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004821e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004821e9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004821ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004821eb  685cf44c00             -push 0x4cf45c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043292 /*0x4cf45c*/;
    cpu.esp -= 4;
    // 004821f0  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004821f2  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 004821f7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004821f9  e882ce0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 004821fe  8b2d543d5600           -mov ebp, dword ptr [0x563d54]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 00482204  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00482207  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00482209  7456                   -je 0x482261
    if (cpu.flags.zf)
    {
        goto L_0x00482261;
    }
    // 0048220b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048220d  7545                   -jne 0x482254
    if (!cpu.flags.zf)
    {
        goto L_0x00482254;
    }
    // 0048220f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482210  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482211  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482212  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482213  2eff1508644c00         -call dword ptr cs:[0x4c6408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006344) /* 0x4c6408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048221a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048221c  7509                   -jne 0x482227
    if (!cpu.flags.zf)
    {
        goto L_0x00482227;
    }
    // 0048221e  2eff15f0644c00         -call dword ptr cs:[0x4c64f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006576) /* 0x4c64f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00482225:
    // 00482225  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00482227:
    // 00482227  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482229  741c                   -je 0x482247
    if (cpu.flags.zf)
    {
        goto L_0x00482247;
    }
    // 0048222b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048222d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00482232  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482233  6884f44c00             -push 0x4cf484
    app->getMemory<x86::reg32>(cpu.esp-4) = 5043332 /*0x4cf484*/;
    cpu.esp -= 4;
    // 00482238  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0048223a  680cab4d00             -push 0x4dab0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5090060 /*0x4dab0c*/;
    cpu.esp -= 4;
    // 0048223f  e83cce0100             -call 0x49f080
    cpu.esp -= 4;
    sub_49f080(app, cpu);
    if (cpu.terminate) return;
    // 00482244  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00482247:
    // 00482247  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482249  7516                   -jne 0x482261
    if (!cpu.flags.zf)
    {
        goto L_0x00482261;
    }
    // 0048224b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482250  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482251  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482252  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482253  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482254:
    // 00482254  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482255  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482256  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482257  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482258  2eff1518644c00         -call dword ptr cs:[0x4c6418]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006360) /* 0x4c6418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048225f  ebc4                   -jmp 0x482225
    goto L_0x00482225;
L_0x00482261:
    // 00482261  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482263  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482264  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482265  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482266  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482271  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482272  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482273  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00482276  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048227a  8b1538ab4d00           -mov edx, dword ptr [0x4dab38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 00482280  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00482282  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482284  750a                   -jne 0x482290
    if (!cpu.flags.zf)
    {
        goto L_0x00482290;
    }
    // 00482286  e86d7c0000             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048228b  a338ab4d00             -mov dword ptr [0x4dab38], eax
    app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */) = cpu.eax;
L_0x00482290:
    // 00482290  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00482295  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 0048229a  bab0315600             -mov edx, 0x5631b0
    cpu.edx = 5648816 /*0x5631b0*/;
    // 0048229f  e8a47c0000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004822a4  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004822a8  68d0234800             -push 0x4823d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4727760 /*0x4823d0*/;
    cpu.esp -= 4;
    // 004822ad  8b1d10ab4d00           -mov ebx, dword ptr [0x4dab10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090064) /* 0x4dab10 */);
    // 004822b3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004822b7  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004822bb  e8d6e40100             -call 0x4a0796
    cpu.esp -= 4;
    sub_4a0796(app, cpu);
    if (cpu.terminate) return;
    // 004822c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004822c2  7449                   -je 0x48230d
    if (cpu.flags.zf)
    {
        goto L_0x0048230d;
    }
    // 004822c4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004822c6  7540                   -jne 0x482308
    if (!cpu.flags.zf)
    {
        goto L_0x00482308;
    }
    // 004822c8  b9d0234800             -mov ecx, 0x4823d0
    cpu.ecx = 4727760 /*0x4823d0*/;
    // 004822cd  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004822d2  8b1510ab4d00           -mov edx, dword ptr [0x4dab10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090064) /* 0x4dab10 */);
    // 004822d8  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 004822de  b8b0315600             -mov eax, 0x5631b0
    cpu.eax = 5648816 /*0x5631b0*/;
    // 004822e3  e894e50100             -call 0x4a087c
    cpu.esp -= 4;
    sub_4a087c(app, cpu);
    if (cpu.terminate) return;
    // 004822e8  ff0d10ab4d00           -dec dword ptr [0x4dab10]
    (app->getMemory<x86::reg32>(x86::reg32(5090064) /* 0x4dab10 */))--;
L_0x004822ee:
    // 004822ee  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004822f3:
    // 004822f3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004822f8  e8637c0000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004822fd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004822ff  83c408                 +add esp, 8
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
    // 00482302  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482303  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482304  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482305  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00482308:
    // 00482308  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0048230b  ebe1                   -jmp 0x4822ee
    goto L_0x004822ee;
L_0x0048230d:
    // 0048230d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048230f  74e2                   -je 0x4822f3
    if (cpu.flags.zf)
    {
        goto L_0x004822f3;
    }
    // 00482311  8b0d10ab4d00           -mov ecx, dword ptr [0x4dab10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090064) /* 0x4dab10 */);
    // 00482317  81f980000000           +cmp ecx, 0x80
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
    // 0048231d  73d4                   -jae 0x4822f3
    if (!cpu.flags.cf)
    {
        goto L_0x004822f3;
    }
    // 0048231f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00482323  b8b0315600             -mov eax, 0x5631b0
    cpu.eax = 5648816 /*0x5631b0*/;
    // 00482328  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0048232b  893ccdb4315600         -mov dword ptr [ecx*8 + 0x5631b4], edi
    app->getMemory<x86::reg32>(x86::reg32(5648820) /* 0x5631b4 */ + cpu.ecx * 8) = cpu.edi;
    // 00482332  891d10ab4d00           -mov dword ptr [0x4dab10], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090064) /* 0x4dab10 */) = cpu.ebx;
    // 00482338  8914cdb0315600         -mov dword ptr [ecx*8 + 0x5631b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5648816) /* 0x5631b0 */ + cpu.ecx * 8) = cpu.edx;
    // 0048233f  b9d0234800             -mov ecx, 0x4823d0
    cpu.ecx = 4727760 /*0x4823d0*/;
    // 00482344  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00482346  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0048234b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00482350  e827e50100             -call 0x4a087c
    cpu.esp -= 4;
    sub_4a087c(app, cpu);
    if (cpu.terminate) return;
    // 00482355  eb9c                   -jmp 0x4822f3
    goto L_0x004822f3;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482361  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482362  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00482365  8b1538ab4d00           -mov edx, dword ptr [0x4dab38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 0048236b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048236d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048236f  750a                   -jne 0x48237b
    if (!cpu.flags.zf)
    {
        goto L_0x0048237b;
    }
    // 00482371  e8827b0000             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00482376  a338ab4d00             -mov dword ptr [0x4dab38], eax
    app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */) = cpu.eax;
L_0x0048237b:
    // 0048237b  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00482380  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 00482385  bab0315600             -mov edx, 0x5631b0
    cpu.edx = 5648816 /*0x5631b0*/;
    // 0048238a  e8b97b0000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048238f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00482393  68d0234800             -push 0x4823d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4727760 /*0x4823d0*/;
    cpu.esp -= 4;
    // 00482398  8b1d10ab4d00           -mov ebx, dword ptr [0x4dab10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090064) /* 0x4dab10 */);
    // 0048239e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004823a2  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004823a6  e8ebe30100             -call 0x4a0796
    cpu.esp -= 4;
    sub_4a0796(app, cpu);
    if (cpu.terminate) return;
    // 004823ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004823ad  7403                   -je 0x4823b2
    if (cpu.flags.zf)
    {
        goto L_0x004823b2;
    }
    // 004823af  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004823b2:
    // 004823b2  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004823b7  e8a47b0000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004823bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004823be  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004823c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823c3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4823d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004823d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004823d1  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004823d3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004823d5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004823d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4823e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004823e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004823e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004823e2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004823e5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004823e8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004823ea  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004823ec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004823ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004823f0  7e0c                   -jle 0x4823fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004823fe;
    }
L_0x004823f2:
    // 004823f2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004823f4  ff1588d74d00           -call dword ptr [0x4dd788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5101448) /* 0x4dd788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004823fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004823fc  7508                   -jne 0x482406
    if (!cpu.flags.zf)
    {
        goto L_0x00482406;
    }
L_0x004823fe:
    // 004823fe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482400  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482403  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482404  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482405  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482406:
    // 00482406  e819430000             -call 0x486724
    cpu.esp -= 4;
    sub_486724(app, cpu);
    if (cpu.terminate) return;
    // 0048240b  42                     -inc edx
    (cpu.edx)++;
    // 0048240c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048240e  7408                   -je 0x482418
    if (cpu.flags.zf)
    {
        goto L_0x00482418;
    }
    // 00482410  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00482413  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00482416  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00482418:
    // 00482418  39da                   +cmp edx, ebx
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
    // 0048241a  7cd6                   -jl 0x4823f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004823f2;
    }
    // 0048241c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048241e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482421  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482422  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482423  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482424(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482424  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482425  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0048242a  e8b1ffffff             -call 0x4823e0
    cpu.esp -= 4;
    sub_4823e0(app, cpu);
    if (cpu.terminate) return;
    // 0048242f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482430  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482440  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482441  8b3584ab4d00           -mov esi, dword ptr [0x4dab84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 00482447  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482448  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048244a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048244c  e8ff010100             -call 0x492650
    cpu.esp -= 4;
    sub_492650(app, cpu);
    if (cpu.terminate) return;
    // 00482451  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482453  7402                   -je 0x482457
    if (cpu.flags.zf)
    {
        goto L_0x00482457;
    }
    // 00482455  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00482457:
    // 00482457  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482458  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48245c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048245c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048245d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048245f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482461  8b1d84ab4d00           -mov ebx, dword ptr [0x4dab84]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 00482467  e8e4010100             -call 0x492650
    cpu.esp -= 4;
    sub_492650(app, cpu);
    if (cpu.terminate) return;
    // 0048246c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048246e  7402                   -je 0x482472
    if (cpu.flags.zf)
    {
        goto L_0x00482472;
    }
    // 00482470  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00482472:
    // 00482472  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482473  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482474(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482474  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482475  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00482477  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482479  8b1d84ab4d00           -mov ebx, dword ptr [0x4dab84]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0048247f  e8cc010100             -call 0x492650
    cpu.esp -= 4;
    sub_492650(app, cpu);
    if (cpu.terminate) return;
    // 00482484  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00482486  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482487  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482490  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482494(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482494  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482495  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048249a  b878b24d00             -mov eax, 0x4db278
    cpu.eax = 5091960 /*0x4db278*/;
    // 0048249f  e828000000             -call 0x4824cc
    cpu.esp -= 4;
    sub_4824cc(app, cpu);
    if (cpu.terminate) return;
    // 004824a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004824a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4824a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004824a8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004824a9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004824ae  b8b0b24d00             -mov eax, 0x4db2b0
    cpu.eax = 5092016 /*0x4db2b0*/;
    // 004824b3  e814000000             -call 0x4824cc
    cpu.esp -= 4;
    sub_4824cc(app, cpu);
    if (cpu.terminate) return;
    // 004824b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004824b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4824bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004824bc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004824bd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004824c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004824c4  e803000000             -call 0x4824cc
    cpu.esp -= 4;
    sub_4824cc(app, cpu);
    if (cpu.terminate) return;
    // 004824c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004824ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4824cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004824cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004824cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004824ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004824cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004824d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004824d1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004824d3  8b15a4d74d00           -mov edx, dword ptr [0x4dd7a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101476) /* 0x4dd7a4 */);
    // 004824d9  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004824de  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004824e0  7540                   -jne 0x482522
    if (!cpu.flags.zf)
    {
        goto L_0x00482522;
    }
    // 004824e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004824e4  7444                   -je 0x48252a
    if (cpu.flags.zf)
    {
        goto L_0x0048252a;
    }
    // 004824e6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004824e8  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004824eb  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004824f0  e813f70000             -call 0x491c08
    cpu.esp -= 4;
    sub_491c08(app, cpu);
    if (cpu.terminate) return;
L_0x004824f5:
    // 004824f5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004824f7:
    // 004824f7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004824f9  7461                   -je 0x48255c
    if (cpu.flags.zf)
    {
        goto L_0x0048255c;
    }
    // 004824fb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004824fd  7537                   -jne 0x482536
    if (!cpu.flags.zf)
    {
        goto L_0x00482536;
    }
    // 004824ff  833de4ab4d0000         +cmp dword ptr [0x4dabe4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090276) /* 0x4dabe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482506  7435                   -je 0x48253d
    if (cpu.flags.zf)
    {
        goto L_0x0048253d;
    }
L_0x00482508:
    // 00482508  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0048250d  8b35e4ab4d00           -mov esi, dword ptr [0x4dabe4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090276) /* 0x4dabe4 */);
L_0x00482513:
    // 00482513  bf40b24d00             -mov edi, 0x4db240
    cpu.edi = 5091904 /*0x4db240*/;
    // 00482518  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048251a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048251c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048251d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048251e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048251f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482520  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482521  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482522:
    // 00482522  ff15a4d74d00           -call dword ptr [0x4dd7a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5101476) /* 0x4dd7a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482528  ebcb                   -jmp 0x4824f5
    goto L_0x004824f5;
L_0x0048252a:
    // 0048252a  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 0048252f  e828f80000             -call 0x491d5c
    cpu.esp -= 4;
    sub_491d5c(app, cpu);
    if (cpu.terminate) return;
    // 00482534  ebc1                   -jmp 0x4824f7
    goto L_0x004824f7;
L_0x00482536:
    // 00482536  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0048253b  ebd6                   -jmp 0x482513
    goto L_0x00482513;
L_0x0048253d:
    // 0048253d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00482542  8b0de8ab4d00           -mov ecx, dword ptr [0x4dabe8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 00482548  8b1d84ab4d00           -mov ebx, dword ptr [0x4dab84]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0048254e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482550  e8cb020100             -call 0x492820
    cpu.esp -= 4;
    sub_492820(app, cpu);
    if (cpu.terminate) return;
    // 00482555  a3e4ab4d00             -mov dword ptr [0x4dabe4], eax
    app->getMemory<x86::reg32>(x86::reg32(5090276) /* 0x4dabe4 */) = cpu.eax;
    // 0048255a  ebac                   -jmp 0x482508
    goto L_0x00482508;
L_0x0048255c:
    // 0048255c  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 00482561  b840b24d00             -mov eax, 0x4db240
    cpu.eax = 5091904 /*0x4db240*/;
    // 00482566  e8b17a0000             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048256b  a094b24d00             -mov al, byte ptr [0x4db294]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091988) /* 0x4db294 */);
    // 00482570  a25cb24d00             -mov byte ptr [0x4db25c], al
    app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */) = cpu.al;
    // 00482575  a095b24d00             -mov al, byte ptr [0x4db295]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091989) /* 0x4db295 */);
    // 0048257a  a25db24d00             -mov byte ptr [0x4db25d], al
    app->getMemory<x86::reg8>(x86::reg32(5091933) /* 0x4db25d */) = cpu.al;
    // 0048257f  a096b24d00             -mov al, byte ptr [0x4db296]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091990) /* 0x4db296 */);
    // 00482584  a25eb24d00             -mov byte ptr [0x4db25e], al
    app->getMemory<x86::reg8>(x86::reg32(5091934) /* 0x4db25e */) = cpu.al;
    // 00482589  a1a8b24d00             -mov eax, dword ptr [0x4db2a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092008) /* 0x4db2a8 */);
    // 0048258e  a370b24d00             -mov dword ptr [0x4db270], eax
    app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */) = cpu.eax;
    // 00482593  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00482595  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482596  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482597  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482598  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482599  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048259a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48259c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048259c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048259d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048259f  e828ffffff             -call 0x4824cc
    cpu.esp -= 4;
    sub_4824cc(app, cpu);
    if (cpu.terminate) return;
    // 004825a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4825a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004825a8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004825a9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004825ae  e819ffffff             -call 0x4824cc
    cpu.esp -= 4;
    sub_4824cc(app, cpu);
    if (cpu.terminate) return;
    // 004825b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4825b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004825b8  b878b24d00             -mov eax, 0x4db278
    cpu.eax = 5091960 /*0x4db278*/;
    // 004825bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4825c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004825c0  b8b0b24d00             -mov eax, 0x4db2b0
    cpu.eax = 5092016 /*0x4db2b0*/;
    // 004825c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4825d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004825d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004825d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004825d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004825d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004825d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004825d5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004825d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004825da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004825dc  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004825df  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004825e5  ba600e5700             -mov edx, 0x570e60
    cpu.edx = 5705312 /*0x570e60*/;
    // 004825ea  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004825ee  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004825f0  bb9f860100             -mov ebx, 0x1869f
    cpu.ebx = 99999 /*0x1869f*/;
    // 004825f5  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004825f8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004825fd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482603  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00482606  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048260a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048260c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048260e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x00482612:
    // 00482612  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482615  0fb672fe               -movzx esi, byte ptr [edx - 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */));
    // 00482619  0fb67afd               -movzx edi, byte ptr [edx - 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */));
    // 0048261d  8a8864ac4d00           -mov cl, byte ptr [eax + 0x4dac64]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5090404) /* 0x4dac64 */);
    // 00482623  0fb66afc               -movzx ebp, byte ptr [edx - 4]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */));
    // 00482627  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00482629  742b                   -je 0x482656
    if (cpu.flags.zf)
    {
        goto L_0x00482656;
    }
    // 0048262b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048262f  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00482631  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00482633  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00482636  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048263a  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048263c  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048263f  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00482642  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00482645  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00482647  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048264a  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048264c  39d9                   +cmp ecx, ebx
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
    // 0048264e  7d06                   -jge 0x482656
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00482656;
    }
    // 00482650  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00482652  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00482656:
    // 00482656  40                     -inc eax
    (cpu.eax)++;
    // 00482657  3d00010000             +cmp eax, 0x100
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
    // 0048265c  7cb4                   -jl 0x482612
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482612;
    }
    // 0048265e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00482662  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00482665  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482666  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482667  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482668  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482669  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048266a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48266c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048266c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048266d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048266e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482670  8a255cb24d00           -mov ah, byte ptr [0x4db25c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 00482676  80fc08                 +cmp ah, 8
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
    // 00482679  761c                   -jbe 0x482697
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482697;
    }
    // 0048267b  80fc0f                 +cmp ah, 0xf
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
    // 0048267e  745e                   -je 0x4826de
    if (cpu.flags.zf)
    {
        goto L_0x004826de;
    }
    // 00482680  80fc10                 +cmp ah, 0x10
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
    // 00482683  0f8483000000           -je 0x48270c
    if (cpu.flags.zf)
    {
        goto L_0x0048270c;
    }
    // 00482689  80fc18                 +cmp ah, 0x18
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
    // 0048268c  0f829f000000           -jb 0x482731
    if (cpu.flags.cf)
    {
        goto L_0x00482731;
    }
    // 00482692  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482694  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482695  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482696  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482697:
    // 00482697  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482698  8b0d60ac4d00           -mov ecx, dword ptr [0x4dac60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090400) /* 0x4dac60 */);
    // 0048269e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004826a0  7427                   -je 0x4826c9
    if (cpu.flags.zf)
    {
        goto L_0x004826c9;
    }
    // 004826a2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004826a4  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004826aa  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004826ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004826af  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004826b2  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004826b8  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004826bb  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004826be  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004826c0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004826c2  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004826c4  8a1c01                 -mov bl, byte ptr [ecx + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
    // 004826c7  eb0f                   -jmp 0x4826d8
    goto L_0x004826d8;
L_0x004826c9:
    // 004826c9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004826cb  8d05600e5700           -lea eax, [0x570e60]
    cpu.eax = x86::reg32(x86::reg32(5705312) /* 0x570e60 */);
    // 004826d1  e8fafeffff             -call 0x4825d0
    cpu.esp -= 4;
    sub_4825d0(app, cpu);
    if (cpu.terminate) return;
    // 004826d6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004826d8:
    // 004826d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826d9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004826db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004826de:
    // 004826de  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004826e0  7425                   -je 0x482707
    if (cpu.flags.zf)
    {
        goto L_0x00482707;
    }
    // 004826e2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004826e4  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004826ea  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004826ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004826ef  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004826f2  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004826f8  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004826fb  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004826fe  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482700  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00482707:
    // 00482707  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482709  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048270a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048270b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048270c:
    // 0048270c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048270e  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00482714  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00482717  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482719  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0048271c  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00482722  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00482725  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00482728  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048272a  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048272c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048272e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048272f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482730  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482731:
    // 00482731  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482733  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482735  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482736  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482737  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482740  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482741  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482742  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482743  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482744  8b0d58b24d00           -mov ecx, dword ptr [0x4db258]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 0048274a  8b1550b24d00           -mov edx, dword ptr [0x4db250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 00482750  8b1d4cb24d00           -mov ebx, dword ptr [0x4db24c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 00482756  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482757  a154b24d00             -mov eax, dword ptr [0x4db254]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 0048275c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048275e  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482760  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00482762  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482764  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482766  e8b55e0000             -call 0x488620
    cpu.esp -= 4;
    sub_488620(app, cpu);
    if (cpu.terminate) return;
    // 0048276b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048276c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048276d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048276e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048276f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482770  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482771  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482773  3b05e8365600           +cmp eax, dword ptr [0x5636e8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650152) /* 0x5636e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482779  7428                   -je 0x4827a3
    if (cpu.flags.zf)
    {
        goto L_0x004827a3;
    }
    // 0048277b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048277c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048277d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048277e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00482780  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482782  6bd600                 -imul edx, esi, 0
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
L_0x00482785:
    // 00482785  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00482787  40                     -inc eax
    (cpu.eax)++;
    // 00482788  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0048278b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048278d  8888e3355600           -mov byte ptr [eax + 0x5635e3], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5649891) /* 0x5635e3 */) = cpu.cl;
    // 00482793  3d00010000             +cmp eax, 0x100
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
    // 00482798  7ceb                   -jl 0x482785
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482785;
    }
    // 0048279a  8935e8365600           -mov dword ptr [0x5636e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5650152) /* 0x5636e8 */) = cpu.esi;
    // 004827a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004827a3:
    // 004827a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4827a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004827a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004827a9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004827ab  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004827ad  8a9be4355600           -mov bl, byte ptr [ebx + 0x5635e4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5649892) /* 0x5635e4 */);
    // 004827b3  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004827b5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004827b7  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004827ba  8a9be4355600           -mov bl, byte ptr [ebx + 0x5635e4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5649892) /* 0x5635e4 */);
    // 004827c0  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004827c3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004827c5  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004827c8  8a9be4355600           -mov bl, byte ptr [ebx + 0x5635e4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5649892) /* 0x5635e4 */);
    // 004827ce  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004827d1  8a4003                 -mov al, byte ptr [eax + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004827d4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004827d9  8a80e4355600           -mov al, byte ptr [eax + 0x5635e4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5649892) /* 0x5635e4 */);
    // 004827df  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004827e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4827e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004827e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004827e5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004827e8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004827ea  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004827ec  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004827ef  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004827f2  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004827f5  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004827f8  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004827fa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004827fc  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004827ff  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00482802  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00482805  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00482808  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0048280b  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0048280e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482810  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00482813  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00482816  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00482819  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048281c  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0048281f  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 00482822  8a4003                 -mov al, byte ptr [eax + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00482825  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048282a  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048282d  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00482830  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00482833  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482836  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482837  90                     -nop 
    ;
    // 00482838  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48283c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048283c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048283d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048283e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048283f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482840  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00482843  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482845  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482847  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00482849:
    // 00482849  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048284b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048284d  e856ffffff             -call 0x4827a8
    cpu.esp -= 4;
    sub_4827a8(app, cpu);
    if (cpu.terminate) return;
    // 00482852  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00482854  8a742402               -mov dh, byte ptr [esp + 2]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00482858  8a642403               -mov ah, byte ptr [esp + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 0048285c  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 0048285f  28e0                   -sub al, ah
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.ah));
    // 00482861  8a542401               -mov dl, byte ptr [esp + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00482865  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 00482869  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048286b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482870  e86b8a0100             -call 0x49b2e0
    cpu.esp -= 4;
    sub_49b2e0(app, cpu);
    if (cpu.terminate) return;
    // 00482875  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00482877  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 0048287a  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482880  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00482884  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00482888  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048288c  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0048288f  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482895  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482899  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0048289d  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 004828a1  8a7c2408               -mov bh, byte ptr [esp + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004828a5  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 004828a7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004828ac  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004828b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004828b2  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004828b6  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004828ba  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004828bd  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 004828c0  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004828c4  0fb6ee                 -movzx ebp, dh
    cpu.ebp = x86::reg32(cpu.dh);
    // 004828c7  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004828cb  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004828cf  0fb6ef                 -movzx ebp, bh
    cpu.ebp = x86::reg32(cpu.bh);
    // 004828d2  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004828d5  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 004828d8  8a742408               -mov dh, byte ptr [esp + 8]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004828dc  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004828e0  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 004828e3  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004828e7  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004828eb  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004828f0  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004828f3  8a542408               -mov dl, byte ptr [esp + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004828f7  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004828fa  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482900  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482902  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482904  88f0                   -mov al, dh
    cpu.al = cpu.dh;
    // 00482906  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00482909  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048290f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00482912  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00482914  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482916  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00482918  46                     -inc esi
    (cpu.esi)++;
    // 00482919  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0048291b  83c104                 +add ecx, 4
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
    // 0048291e  e849fdffff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 00482923  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00482926  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482927  0f851cffffff           -jne 0x482849
    if (!cpu.flags.zf)
    {
        goto L_0x00482849;
    }
    // 0048292d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00482930  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482931  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482932  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482933  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482934  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482938(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482938  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482939  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048293a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048293b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048293c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048293f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482941  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482943  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00482945:
    // 00482945  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00482947  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482949  e85afeffff             -call 0x4827a8
    cpu.esp -= 4;
    sub_4827a8(app, cpu);
    if (cpu.terminate) return;
    // 0048294e  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00482951  81fb00000010           +cmp ebx, 0x10000000
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
    // 00482957  7273                   -jb 0x4829cc
    if (cpu.flags.cf)
    {
        goto L_0x004829cc;
    }
    // 00482959  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0048295f  7348                   -jae 0x4829a9
    if (!cpu.flags.cf)
    {
        goto L_0x004829a9;
    }
    // 00482961  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00482964  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482966  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0048296b  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0048296e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00482970  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00482976  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00482979  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048297b  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0048297e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00482980  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00482982  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00482985  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048298b  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0048298d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00482990  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482992  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482994  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00482997  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048299d  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048299f  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004829a2  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004829a7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004829a9:
    // 004829a9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004829ab  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004829b1  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004829b4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004829b6  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004829b9  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004829bf  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004829c2  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004829c5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004829c7  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004829c9  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004829cc:
    // 004829cc  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004829cf  83c704                 +add edi, 4
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
    // 004829d2  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004829d3  0f856cffffff           -jne 0x482945
    if (!cpu.flags.zf)
    {
        goto L_0x00482945;
    }
    // 004829d9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004829dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4829e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004829e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004829e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004829e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004829e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004829e8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004829eb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004829ed  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004829ef  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x004829f1:
    // 004829f1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004829f3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004829f5  e8aefdffff             -call 0x4827a8
    cpu.esp -= 4;
    sub_4827a8(app, cpu);
    if (cpu.terminate) return;
    // 004829fa  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004829fd  81fb00000010           +cmp ebx, 0x10000000
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
    // 00482a03  726b                   -jb 0x482a70
    if (cpu.flags.cf)
    {
        goto L_0x00482a70;
    }
    // 00482a05  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00482a0b  7340                   -jae 0x482a4d
    if (!cpu.flags.cf)
    {
        goto L_0x00482a4d;
    }
    // 00482a0d  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00482a10  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00482a12  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482a14  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482a17  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00482a1a  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00482a1c  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00482a22  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00482a25  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00482a2a  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00482a2d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482a2f  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00482a31  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00482a34  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482a36  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00482a39  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482a3b  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00482a3e  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482a44  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00482a49  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00482a4b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00482a4d:
    // 00482a4d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482a4f  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00482a55  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00482a58  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482a5a  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00482a5d  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00482a63  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00482a66  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00482a69  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482a6b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482a6d  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00482a70:
    // 00482a70  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00482a73  83c704                 +add edi, 4
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
    // 00482a76  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482a77  0f8574ffffff           -jne 0x4829f1
    if (!cpu.flags.zf)
    {
        goto L_0x004829f1;
    }
    // 00482a7d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482a80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482a88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482a88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482a89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482a8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482a8b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482a8e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482a90  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x00482a92:
    // 00482a92  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00482a94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482a96  e80dfdffff             -call 0x4827a8
    cpu.esp -= 4;
    sub_4827a8(app, cpu);
    if (cpu.terminate) return;
    // 00482a9b  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00482a9d  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00482aa0  8a642403               -mov ah, byte ptr [esp + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 00482aa4  88542410               -mov byte ptr [esp + 0x10], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 00482aa8  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00482aaa  28e0                   -sub al, ah
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.ah));
    // 00482aac  88542414               -mov byte ptr [esp + 0x14], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dl;
    // 00482ab0  8a6102                 -mov ah, byte ptr [ecx + 2]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00482ab3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482ab5  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00482ab7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482abc  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00482abf  0fb67c2402             -movzx edi, byte ptr [esp + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */));
    // 00482ac4  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00482ac7  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482ac9  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00482acd  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482ad1  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00482ad5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482ad7  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00482adb  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00482ade  0fb67c2401             -movzx edi, byte ptr [esp + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */));
    // 00482ae3  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00482ae6  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482ae8  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00482aec  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482af0  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00482af4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482af6  8a542414               -mov dl, byte ptr [esp + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00482afa  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00482afd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482aff  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00482b02  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00482b05  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482b07  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00482b0a  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482b0e  8861ff                 -mov byte ptr [ecx - 1], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 00482b11  8a64240c               -mov ah, byte ptr [esp + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00482b15  8861fe                 -mov byte ptr [ecx - 2], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ah;
    // 00482b18  83c604                 +add esi, 4
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
    // 00482b1b  8841fd                 -mov byte ptr [ecx - 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 00482b1e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482b1f  0f856dffffff           -jne 0x482a92
    if (!cpu.flags.zf)
    {
        goto L_0x00482a92;
    }
    // 00482b25  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482b28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482b2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482b2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482b2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482b2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482b2f  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482b32  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482b34  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x00482b36:
    // 00482b36  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00482b38  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482b3a  e869fcffff             -call 0x4827a8
    cpu.esp -= 4;
    sub_4827a8(app, cpu);
    if (cpu.terminate) return;
    // 00482b3f  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 00482b41  2a642403               -sub ah, byte ptr [esp + 3]
    (cpu.ah) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */)));
    // 00482b45  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00482b48  88542410               -mov byte ptr [esp + 0x10], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 00482b4c  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00482b4e  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00482b51  88542414               -mov byte ptr [esp + 0x14], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dl;
    // 00482b55  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482b57  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00482b59  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00482b5b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482b60  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00482b63  0fb67c2402             -movzx edi, byte ptr [esp + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */));
    // 00482b68  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00482b6b  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482b6d  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00482b71  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482b75  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00482b79  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482b7b  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00482b7f  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00482b82  0fb67c2401             -movzx edi, byte ptr [esp + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */));
    // 00482b87  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00482b8a  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482b8c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00482b90  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482b94  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00482b98  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482b9a  8a542414               -mov dl, byte ptr [esp + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00482b9e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00482ba1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482ba3  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00482ba6  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00482ba9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482bac  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482bae  c641ffff               -mov byte ptr [ecx - 1], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = 255 /*0xff*/;
    // 00482bb2  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482bb6  8861fe                 -mov byte ptr [ecx - 2], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ah;
    // 00482bb9  8a64240c               -mov ah, byte ptr [esp + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00482bbd  8861fd                 -mov byte ptr [ecx - 3], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-3) /* -0x3 */) = cpu.ah;
    // 00482bc0  83c604                 +add esi, 4
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
    // 00482bc3  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 00482bc6  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482bc7  0f8569ffffff           -jne 0x482b36
    if (!cpu.flags.zf)
    {
        goto L_0x00482b36;
    }
    // 00482bcd  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482bd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482bd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482bd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482bd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482bd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482bd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482bd5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482bd6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482bd7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482bd8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00482bda  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482bdc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00482bde:
    // 00482bde  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482be0  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00482be3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00482bea  8b1de4365600           -mov ebx, dword ptr [0x5636e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5650148) /* 0x5636e4 */);
    // 00482bf0  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00482bf3  45                     -inc ebp
    (cpu.ebp)++;
    // 00482bf4  81fb00000010           +cmp ebx, 0x10000000
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
    // 00482bfa  726b                   -jb 0x482c67
    if (cpu.flags.cf)
    {
        goto L_0x00482c67;
    }
    // 00482bfc  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00482c02  7340                   -jae 0x482c44
    if (!cpu.flags.cf)
    {
        goto L_0x00482c44;
    }
    // 00482c04  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00482c07  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00482c09  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482c0b  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482c0e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00482c11  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00482c13  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00482c19  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00482c1c  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00482c21  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00482c24  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482c26  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00482c28  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00482c2b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482c2d  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00482c30  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482c32  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00482c35  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482c3b  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00482c40  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00482c42  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00482c44:
    // 00482c44  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482c46  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00482c4c  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00482c4f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482c51  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00482c54  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00482c5a  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00482c5d  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00482c60  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482c62  01d3                   +add ebx, edx
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
    // 00482c64  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00482c67:
    // 00482c67  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00482c6a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482c6b  0f856dffffff           -jne 0x482bde
    if (!cpu.flags.zf)
    {
        goto L_0x00482bde;
    }
    // 00482c71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482c78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482c78  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482c79  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482c7a  81ec08040000           -sub esp, 0x408
    (cpu.esp) -= x86::reg32(x86::sreg32(1032 /*0x408*/));
    // 00482c80  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00482c82  89942400040000         -mov dword ptr [esp + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.edx;
    // 00482c89  899c2404040000         -mov dword ptr [esp + 0x404], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */) = cpu.ebx;
    // 00482c90  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00482c92  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00482c94  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00482c97  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 00482c9d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482c9f  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 00482ca4  89157cad4d00           -mov dword ptr [0x4dad7c], edx
    app->getMemory<x86::reg32>(x86::reg32(5090684) /* 0x4dad7c */) = cpu.edx;
    // 00482caa  890d84ad4d00           -mov dword ptr [0x4dad84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090692) /* 0x4dad84 */) = cpu.ecx;
    // 00482cb0  83f808                 +cmp eax, 8
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
    // 00482cb3  0f8593000000           -jne 0x482d4c
    if (!cpu.flags.zf)
    {
        goto L_0x00482d4c;
    }
    // 00482cb9  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
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
    // 00482cc0  0f8586000000           -jne 0x482d4c
    if (!cpu.flags.zf)
    {
        goto L_0x00482d4c;
    }
    // 00482cc6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482cc7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482ccb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00482ccd  e826700100             -call 0x499cf8
    cpu.esp -= 4;
    sub_499cf8(app, cpu);
    if (cpu.terminate) return;
    // 00482cd2  a3e4365600             -mov dword ptr [0x5636e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5650148) /* 0x5636e4 */) = cpu.eax;
    // 00482cd7  81ffff000000           +cmp edi, 0xff
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
    // 00482cdd  7d33                   -jge 0x482d12
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00482d12;
    }
    // 00482cdf  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482ce3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00482ce5:
    // 00482ce5  8b15e4365600           -mov edx, dword ptr [0x5636e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650148) /* 0x5636e4 */);
    // 00482ceb  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00482cf2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00482cf4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482cf6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00482cf8  41                     -inc ecx
    (cpu.ecx)++;
    // 00482cf9  e8e6faffff             -call 0x4827e4
    cpu.esp -= 4;
    sub_4827e4(app, cpu);
    if (cpu.terminate) return;
    // 00482cfe  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482d01  81f900010000           +cmp ecx, 0x100
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
    // 00482d07  7cdc                   -jl 0x482ce5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482ce5;
    }
    // 00482d09  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482d0d  a3e4365600             -mov dword ptr [0x5636e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5650148) /* 0x5636e4 */) = cpu.eax;
L_0x00482d12:
    // 00482d12  bbd42b4800             -mov ebx, 0x482bd4
    cpu.ebx = 4729812 /*0x482bd4*/;
    // 00482d17  be7b000000             -mov esi, 0x7b
    cpu.esi = 123 /*0x7b*/;
    // 00482d1c  891d7cad4d00           -mov dword ptr [0x4dad7c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090684) /* 0x4dad7c */) = cpu.ebx;
    // 00482d22  893584ad4d00           -mov dword ptr [0x4dad84], esi
    app->getMemory<x86::reg32>(x86::reg32(5090692) /* 0x4dad84 */) = cpu.esi;
    // 00482d28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482d29:
    // 00482d29  b964ad4d00             -mov ecx, 0x4dad64
    cpu.ecx = 5090660 /*0x4dad64*/;
    // 00482d2e  8b9c2404040000         -mov ebx, dword ptr [esp + 0x404]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */);
    // 00482d35  8b942400040000         -mov edx, dword ptr [esp + 0x400]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 00482d3c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00482d3e  e879e30100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 00482d43  81c408040000           +add esp, 0x408
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
    // 00482d49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482d4c:
    // 00482d4c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482d4e  e81dfaffff             -call 0x482770
    cpu.esp -= 4;
    sub_482770(app, cpu);
    if (cpu.terminate) return;
    // 00482d53  ebd4                   -jmp 0x482d29
    goto L_0x00482d29;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482d58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482d58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482d59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482d5a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482d5b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00482d5d  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00482d60  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00482d63  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00482d66  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00482d69  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00482d6c  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00482d6f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00482d71  e802ffffff             -call 0x482c78
    cpu.esp -= 4;
    sub_482c78(app, cpu);
    if (cpu.terminate) return;
    // 00482d76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482d7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482d7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482d7d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00482d80  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00482d83  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00482d85  8b7006                 -mov esi, dword ptr [eax + 6]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00482d88  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00482d8b  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00482d8d  e8e6feffff             -call 0x482c78
    cpu.esp -= 4;
    sub_482c78(app, cpu);
    if (cpu.terminate) return;
    // 00482d92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482da0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482da1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482da2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482da3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482da4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482da6  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00482da9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482dab  7527                   -jne 0x482dd4
    if (!cpu.flags.zf)
    {
        goto L_0x00482dd4;
    }
L_0x00482dad:
    // 00482dad  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00482db0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482db2  7407                   -je 0x482dbb
    if (cpu.flags.zf)
    {
        goto L_0x00482dbb;
    }
    // 00482db4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482db6  e891840100             -call 0x49b24c
    cpu.esp -= 4;
    sub_49b24c(app, cpu);
    if (cpu.terminate) return;
L_0x00482dbb:
    // 00482dbb  8b7130                 -mov esi, dword ptr [ecx + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 00482dbe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482dc0  751e                   -jne 0x482de0
    if (!cpu.flags.zf)
    {
        goto L_0x00482de0;
    }
    // 00482dc2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482dc4  c7016b4e4957           -mov dword ptr [ecx], 0x57494e6b
    app->getMemory<x86::reg32>(cpu.ecx) = 1464421995 /*0x57494e6b*/;
    // 00482dca  e82d1b0000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00482dcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482dd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482dd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482dd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482dd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482dd4:
    // 00482dd4  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 00482dd9  e81af30000             -call 0x4920f8
    cpu.esp -= 4;
    sub_4920f8(app, cpu);
    if (cpu.terminate) return;
    // 00482dde  ebcd                   -jmp 0x482dad
    goto L_0x00482dad;
L_0x00482de0:
    // 00482de0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482de2  e865840100             -call 0x49b24c
    cpu.esp -= 4;
    sub_49b24c(app, cpu);
    if (cpu.terminate) return;
    // 00482de7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482de9  c7016b4e4957           -mov dword ptr [ecx], 0x57494e6b
    app->getMemory<x86::reg32>(cpu.ecx) = 1464421995 /*0x57494e6b*/;
    // 00482def  e8081b0000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00482df4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482df5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482df6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482df8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482e00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482e01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482e03  7c49                   -jl 0x482e4e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482e4e;
    }
L_0x00482e05:
    // 00482e05  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482e07  7c49                   -jl 0x482e52
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482e52;
    }
L_0x00482e09:
    // 00482e09  8b3544b24d00           -mov esi, dword ptr [0x4db244]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091908) /* 0x4db244 */);
    // 00482e0f  39f0                   +cmp eax, esi
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
    // 00482e11  7e02                   -jle 0x482e15
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482e15;
    }
    // 00482e13  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00482e15:
    // 00482e15  39f3                   +cmp ebx, esi
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
    // 00482e17  7e02                   -jle 0x482e1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482e1b;
    }
    // 00482e19  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x00482e1b:
    // 00482e1b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482e1d  7c37                   -jl 0x482e56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482e56;
    }
L_0x00482e1f:
    // 00482e1f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482e21  7c37                   -jl 0x482e5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482e5a;
    }
L_0x00482e23:
    // 00482e23  8b3548b24d00           -mov esi, dword ptr [0x4db248]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091912) /* 0x4db248 */);
    // 00482e29  39f2                   +cmp edx, esi
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
    // 00482e2b  7e02                   -jle 0x482e2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482e2f;
    }
    // 00482e2d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x00482e2f:
    // 00482e2f  39f1                   +cmp ecx, esi
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
    // 00482e31  7e02                   -jle 0x482e35
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482e35;
    }
    // 00482e33  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00482e35:
    // 00482e35  a34cb24d00             -mov dword ptr [0x4db24c], eax
    app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */) = cpu.eax;
    // 00482e3a  891d54b24d00           -mov dword ptr [0x4db254], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */) = cpu.ebx;
    // 00482e40  891550b24d00           -mov dword ptr [0x4db250], edx
    app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */) = cpu.edx;
    // 00482e46  890d58b24d00           -mov dword ptr [0x4db258], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */) = cpu.ecx;
    // 00482e4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482e4e:
    // 00482e4e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482e50  ebb3                   -jmp 0x482e05
    goto L_0x00482e05;
L_0x00482e52:
    // 00482e52  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00482e54  ebb3                   -jmp 0x482e09
    goto L_0x00482e09;
L_0x00482e56:
    // 00482e56  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00482e58  ebc5                   -jmp 0x482e1f
    goto L_0x00482e1f;
L_0x00482e5a:
    // 00482e5a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00482e5c  ebc5                   -jmp 0x482e23
    goto L_0x00482e23;
}

/* align: skip 0x00 0x00 */
void Application::sub_482e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482e60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482e61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482e62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482e63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482e64  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482e66  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00482e68  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00482e6a  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00482e6d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482e6f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00482e71  7e10                   -jle 0x482e83
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482e83;
    }
L_0x00482e73:
    // 00482e73  3b5810                 +cmp ebx, dword ptr [eax + 0x10]
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
    // 00482e76  7416                   -je 0x482e8e
    if (cpu.flags.zf)
    {
        goto L_0x00482e8e;
    }
    // 00482e78  42                     -inc edx
    (cpu.edx)++;
    // 00482e79  8b6908                 -mov ebp, dword ptr [ecx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00482e7c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00482e7f  39ea                   +cmp edx, ebp
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
    // 00482e81  7cf0                   -jl 0x482e73
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482e73;
    }
L_0x00482e83:
    // 00482e83  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482e85  7511                   -jne 0x482e98
    if (!cpu.flags.zf)
    {
        goto L_0x00482e98;
    }
    // 00482e87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482e89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482e8e:
    // 00482e8e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00482e91  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00482e93  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482e98:
    // 00482e98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482e9a  e801200000             -call 0x484ea0
    cpu.esp -= 4;
    sub_484ea0(app, cpu);
    if (cpu.terminate) return;
    // 00482e9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482ea1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ea2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ea3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ea4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ea5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482ea8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482ea8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482ea9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482eab  e8b0ffffff             -call 0x482e60
    cpu.esp -= 4;
    sub_482e60(app, cpu);
    if (cpu.terminate) return;
    // 00482eb0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482eb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482eb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482eb5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00482eba  e8a1ffffff             -call 0x482e60
    cpu.esp -= 4;
    sub_482e60(app, cpu);
    if (cpu.terminate) return;
    // 00482ebf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ec0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482ed0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482ed4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482ed4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482ed5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482ed6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482ed7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482ed8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00482edb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482edd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482edf  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00482ee1:
    // 00482ee1  80790300               +cmp byte ptr [ecx + 3], 0
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
    // 00482ee5  750f                   -jne 0x482ef6
    if (!cpu.flags.zf)
    {
        goto L_0x00482ef6;
    }
    // 00482ee7  83c104                 +add ecx, 4
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
    // 00482eea  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00482eeb  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482eec  75f3                   -jne 0x482ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00482ee1;
    }
    // 00482eee  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00482ef1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ef2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ef3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ef4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ef5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482ef6:
    // 00482ef6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00482ef8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482efd  e8de830100             -call 0x49b2e0
    cpu.esp -= 4;
    sub_49b2e0(app, cpu);
    if (cpu.terminate) return;
    // 00482f02  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482f04  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 00482f09  0f84a8000000           -je 0x482fb7
    if (cpu.flags.zf)
    {
        goto L_0x00482fb7;
    }
    // 00482f0f  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 00482f11  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00482f13  8a5903                 -mov bl, byte ptr [ecx + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 00482f16  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 00482f19  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00482f1c  28de                   -sub dh, bl
    (cpu.dh) -= x86::reg8(x86::sreg8(cpu.bl));
    // 00482f1e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482f23  8a5902                 -mov bl, byte ptr [ecx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00482f26  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482f2c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00482f2f  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00482f31  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00482f34  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00482f37  887c240c               -mov byte ptr [esp + 0xc], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bh;
    // 00482f3b  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 00482f3e  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 00482f42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482f44  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 00482f46  88742404               -mov byte ptr [esp + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dh;
    // 00482f4a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00482f4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482f4f  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00482f52  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482f56  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00482f59  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00482f5c  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00482f5f  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00482f63  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482f69  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00482f6b  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00482f70  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00482f73  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00482f76  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00482f78  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00482f7e  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00482f80  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00482f85  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00482f88  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00482f8b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00482f8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482f90  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00482f93  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00482f97  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00482f99  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 00482f9d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482f9f  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00482fa1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482fa3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482fa5  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00482fa8  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00482faa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482fac  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00482faf  8a54240c               -mov dl, byte ptr [esp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00482fb3  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482fb5  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00482fb7:
    // 00482fb7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482fb9  e8aef6ffff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 00482fbe  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00482fc0  83c104                 +add ecx, 4
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
    // 00482fc3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00482fc4  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482fc5  0f8516ffffff           -jne 0x482ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00482ee1;
    }
    // 00482fcb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00482fce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482fcf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482fd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482fd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482fd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482fd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482fd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482fd5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482fd6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482fd7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482fd8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482fda  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482fdc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00482fde:
    // 00482fde  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00482fe0  81fb00000010           +cmp ebx, 0x10000000
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
    // 00482fe6  7273                   -jb 0x48305b
    if (cpu.flags.cf)
    {
        goto L_0x0048305b;
    }
    // 00482fe8  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00482fee  7348                   -jae 0x483038
    if (!cpu.flags.cf)
    {
        goto L_0x00483038;
    }
    // 00482ff0  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00482ff3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482ff5  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 00482ffa  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 00482ffd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00482fff  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00483005  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00483008  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048300a  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0048300d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048300f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00483011  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00483014  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048301a  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0048301c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048301f  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00483021  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483023  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00483026  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048302c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048302e  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00483031  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00483036  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00483038:
    // 00483038  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048303a  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00483040  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00483043  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483045  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00483048  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0048304e  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00483051  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00483054  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00483056  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00483058  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0048305b:
    // 0048305b  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0048305e  83c704                 +add edi, 4
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
    // 00483061  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483062  0f8576ffffff           -jne 0x482fde
    if (!cpu.flags.zf)
    {
        goto L_0x00482fde;
    }
    // 00483068  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483069  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048306a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048306b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048306c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483070  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483071  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483072  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483073  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483074  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00483076  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00483078  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0048307a:
    // 0048307a  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0048307c  81fb00000010           +cmp ebx, 0x10000000
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
    // 00483082  726b                   -jb 0x4830ef
    if (cpu.flags.cf)
    {
        goto L_0x004830ef;
    }
    // 00483084  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0048308a  7340                   -jae 0x4830cc
    if (!cpu.flags.cf)
    {
        goto L_0x004830cc;
    }
    // 0048308c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0048308f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00483091  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483093  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00483096  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00483099  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0048309b  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004830a1  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004830a4  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004830a9  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004830ac  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004830ae  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004830b0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004830b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004830b5  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004830b8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004830ba  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004830bd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004830c3  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004830c8  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004830ca  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004830cc:
    // 004830cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004830ce  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004830d4  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004830d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004830d9  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004830dc  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004830e2  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004830e5  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004830e8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004830ea  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004830ec  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004830ef:
    // 004830ef  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004830f2  83c704                 +add edi, 4
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
    // 004830f5  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004830f6  7582                   -jne 0x48307a
    if (!cpu.flags.zf)
    {
        goto L_0x0048307a;
    }
    // 004830f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483100  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483101  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483102  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483103  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483104  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00483107  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00483109:
    // 00483109  80780300               +cmp byte ptr [eax + 3], 0
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
    // 0048310d  7511                   -jne 0x483120
    if (!cpu.flags.zf)
    {
        goto L_0x00483120;
    }
L_0x0048310f:
    // 0048310f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483112  83c203                 +add edx, 3
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
    // 00483115  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483116  75f1                   -jne 0x483109
    if (!cpu.flags.zf)
    {
        goto L_0x00483109;
    }
    // 00483118  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048311b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048311c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048311d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048311e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048311f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483120:
    // 00483120  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00483123  b3ff                   -mov bl, 0xff
    cpu.bl = 255 /*0xff*/;
    // 00483125  8a6a02                 -mov ch, byte ptr [edx + 2]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00483128  8a7803                 -mov bh, byte ptr [eax + 3]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0048312b  886c2410               -mov byte ptr [esp + 0x10], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ch;
    // 0048312f  28fb                   -sub bl, bh
    (cpu.bl) -= x86::reg8(x86::sreg8(cpu.bh));
    // 00483131  0fb6742410             -movzx esi, byte ptr [esp + 0x10]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00483136  885c240c               -mov byte ptr [esp + 0xc], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 0048313a  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0048313d  0fb674240c             -movzx esi, byte ptr [esp + 0xc]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00483142  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00483145  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00483148  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048314b  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0048314e  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 00483150  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00483153  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 00483156  8a6a01                 -mov ch, byte ptr [edx + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00483159  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0048315c  886c2408               -mov byte ptr [esp + 8], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ch;
    // 00483160  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00483163  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00483168  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0048316b  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 0048316d  886c2404               -mov byte ptr [esp + 4], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ch;
    // 00483171  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00483174  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 00483177  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048317d  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048317f  0fb66c2404             -movzx ebp, byte ptr [esp + 4]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 00483184  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00483187  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 0048318a  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0048318d  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00483190  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 00483193  01f5                   +add ebp, esi
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
    // 00483195  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00483198  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0048319b  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 0048319e  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004831a1  883a                   -mov byte ptr [edx], bh
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
    // 004831a3  e967ffffff             -jmp 0x48310f
    goto L_0x0048310f;
}

/* align: skip  */
void Application::sub_4831a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004831a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004831a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004831aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004831ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004831ac  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004831af  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x004831b1:
    // 004831b1  80780300               +cmp byte ptr [eax + 3], 0
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
    // 004831b5  7511                   -jne 0x4831c8
    if (!cpu.flags.zf)
    {
        goto L_0x004831c8;
    }
L_0x004831b7:
    // 004831b7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004831ba  83c204                 +add edx, 4
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
    // 004831bd  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004831be  75f1                   -jne 0x4831b1
    if (!cpu.flags.zf)
    {
        goto L_0x004831b1;
    }
    // 004831c0  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004831c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004831c8:
    // 004831c8  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004831cb  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004831ce  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 004831d2  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004831d4  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
    // 004831d8  807a0300               +cmp byte ptr [edx + 3], 0
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
    // 004831dc  0f84a1000000           -je 0x483283
    if (cpu.flags.zf)
    {
        goto L_0x00483283;
    }
    // 004831e2  b7ff                   -mov bh, 0xff
    cpu.bh = 255 /*0xff*/;
    // 004831e4  2a7803                 -sub bh, byte ptr [eax + 3]
    (cpu.bh) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */)));
    // 004831e7  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004831ea  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 004831ec  887c2408               -mov byte ptr [esp + 8], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.bh;
    // 004831f0  886c240c               -mov byte ptr [esp + 0xc], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ch;
    // 004831f4  0fb6f9                 -movzx edi, cl
    cpu.edi = x86::reg32(cpu.cl);
    // 004831f7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004831f9  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004831fd  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00483200  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00483203  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 00483206  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 00483209  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048320b  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0048320f  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483213  0fb6ff                 -movzx edi, bh
    cpu.edi = x86::reg32(cpu.bh);
    // 00483216  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00483219  0fb66c2414             -movzx ebp, byte ptr [esp + 0x14]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0048321e  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 00483221  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00483223  0fb67c240c             -movzx edi, byte ptr [esp + 0xc]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00483228  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048322b  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 0048322e  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00483232  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00483235  0fb67c2410             -movzx edi, byte ptr [esp + 0x10]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0048323a  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0048323d  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048323f  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00483242  0fb67a03               -movzx edi, byte ptr [edx + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */));
    // 00483246  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0048324b  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048324d  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00483250  8a7c2404               -mov bh, byte ptr [esp + 4]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483254  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
    // 00483259  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0048325c  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 00483260  29cf                   +sub edi, ecx
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
    // 00483262  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 00483265  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00483267  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
L_0x0048326b:
    // 0048326b  884a03                 -mov byte ptr [edx + 3], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 0048326e  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00483271  8a5c2414               -mov bl, byte ptr [esp + 0x14]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00483275  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00483278  8a5c2410               -mov bl, byte ptr [esp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048327c  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0048327e  e934ffffff             -jmp 0x4831b7
    goto L_0x004831b7;
L_0x00483283:
    // 00483283  8a4803                 -mov cl, byte ptr [eax + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00483286  ebe3                   -jmp 0x48326b
    goto L_0x0048326b;
}

/* align: skip  */
void Application::sub_483288(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483288  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483289  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048328a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048328b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048328c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048328e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00483290  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00483292:
    // 00483292  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483294  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00483297  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048329e  8b1dec365600           -mov ebx, dword ptr [0x5636ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5650156) /* 0x5636ec */);
    // 004832a4  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 004832a7  45                     -inc ebp
    (cpu.ebp)++;
    // 004832a8  81fb00000010           +cmp ebx, 0x10000000
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
    // 004832ae  7250                   -jb 0x483300
    if (cpu.flags.cf)
    {
        goto L_0x00483300;
    }
    // 004832b0  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004832b6  7345                   -jae 0x4832fd
    if (!cpu.flags.cf)
    {
        goto L_0x004832fd;
    }
    // 004832b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004832ba  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004832bd  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004832bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004832c1  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004832c4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004832c7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004832c9  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004832cf  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004832d2  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004832d7  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004832da  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004832dc  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004832de  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004832e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004832e3  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004832e6  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004832ec  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004832ef  25e0070000             -and eax, 0x7e0
    cpu.eax &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004832f4  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004832f6  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004832f9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004832fb  01cb                   +add ebx, ecx
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
L_0x004832fd:
    // 004832fd  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00483300:
    // 00483300  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00483303  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483304  758c                   -jne 0x483292
    if (!cpu.flags.zf)
    {
        goto L_0x00483292;
    }
    // 00483306  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483307  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483308  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483309  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048330a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48330c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048330c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048330d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048330e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048330f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483310  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00483316  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483318  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048331a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048331c  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048331f  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 00483325  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483327  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 0048332c  8915a0ad4d00           -mov dword ptr [0x4dada0], edx
    app->getMemory<x86::reg32>(x86::reg32(5090720) /* 0x4dada0 */) = cpu.edx;
    // 00483332  890da8ad4d00           -mov dword ptr [0x4dada8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090728) /* 0x4dada8 */) = cpu.ecx;
    // 00483338  83f808                 +cmp eax, 8
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
    // 0048333b  752c                   -jne 0x483369
    if (!cpu.flags.zf)
    {
        goto L_0x00483369;
    }
    // 0048333d  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
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
    // 00483344  7523                   -jne 0x483369
    if (!cpu.flags.zf)
    {
        goto L_0x00483369;
    }
    // 00483346  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00483348  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048334a  bd88324800             -mov ebp, 0x483288
    cpu.ebp = 4731528 /*0x483288*/;
    // 0048334f  e86c6b0100             -call 0x499ec0
    cpu.esp -= 4;
    sub_499ec0(app, cpu);
    if (cpu.terminate) return;
    // 00483354  a3ec365600             -mov dword ptr [0x5636ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5650156) /* 0x5636ec */) = cpu.eax;
    // 00483359  b87b000000             -mov eax, 0x7b
    cpu.eax = 123 /*0x7b*/;
    // 0048335e  892da0ad4d00           -mov dword ptr [0x4dada0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090720) /* 0x4dada0 */) = cpu.ebp;
    // 00483364  a3a8ad4d00             -mov dword ptr [0x4dada8], eax
    app->getMemory<x86::reg32>(x86::reg32(5090728) /* 0x4dada8 */) = cpu.eax;
L_0x00483369:
    // 00483369  b988ad4d00             -mov ecx, 0x4dad88
    cpu.ecx = 5090696 /*0x4dad88*/;
    // 0048336e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00483370  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483372  e845dd0100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 00483377  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048337d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048337e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048337f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483380  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483381  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483384(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483384  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483385  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483386  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00483389  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048338c  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0048338f  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00483392  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00483395  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00483398  e86fffffff             -call 0x48330c
    cpu.esp -= 4;
    sub_48330c(app, cpu);
    if (cpu.terminate) return;
    // 0048339d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048339e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048339f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4833a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004833a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004833a1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004833a4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004833a7  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004833a9  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004833ac  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004833af  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004833b1  e856ffffff             -call 0x48330c
    cpu.esp -= 4;
    sub_48330c(app, cpu);
    if (cpu.terminate) return;
    // 004833b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004833b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4833b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004833b8  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 004833bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4833be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004833be  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004833c0  0305f4375600           -add eax, dword ptr [0x5637f4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */)));
    // 004833c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4833c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004833c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004833c8  8b15b0ad4d00           -mov edx, dword ptr [0x4dadb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090736) /* 0x4dadb0 */);
    // 004833ce  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 004833d3  a3b0ad4d00             -mov dword ptr [0x4dadb0], eax
    app->getMemory<x86::reg32>(x86::reg32(5090736) /* 0x4dadb0 */) = cpu.eax;
    // 004833d8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004833da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004833db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4833dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004833dc  c705f437560000000000   -mov dword ptr [0x5637f4], 0
    app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */) = 0 /*0x0*/;
    // 004833e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4833e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004833e7  0305f4375600           -add eax, dword ptr [0x5637f4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */)));
    // 004833ed  a3acad4d00             -mov dword ptr [0x4dadac], eax
    app->getMemory<x86::reg32>(x86::reg32(5090732) /* 0x4dadac */) = cpu.eax;
    // 004833f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4833f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004833f3:
    // 004833f3  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 004833f8  2b05acad4d00           +sub eax, dword ptr [0x4dadac]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090732) /* 0x4dadac */)));
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
    // 004833fe  78f3                   -js 0x4833f3
    if (cpu.flags.sf)
    {
        goto L_0x004833f3;
    }
    // 00483400  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483401(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483401  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00483406  2b05acad4d00           +sub eax, dword ptr [0x4dadac]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090732) /* 0x4dadac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048340c  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0048340e  40                     -inc eax
    (cpu.eax)++;
    // 0048340f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483410  0305f4375600           -add eax, dword ptr [0x5637f4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */)));
    // 00483416  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
L_0x00483417:
    // 00483417  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483419  e8920a0000             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 0048341e  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00483423  2b0424                 +sub eax, dword ptr [esp]
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
    // 00483426  78ef                   -js 0x483417
    if (cpu.flags.sf)
    {
        goto L_0x00483417;
    }
    // 00483428  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048342b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_483430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483430  d1fb                   +sar ebx, 1
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
    // 00483432  e99de00100             -jmp 0x4a14d4
    return sub_4a14d4(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_483438(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483438  01db                   +add ebx, ebx
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
    // 0048343a  e995e00100             -jmp 0x4a14d4
    return sub_4a14d4(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_483440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483441  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483443  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048344a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048344c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048344e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483450  e87fe00100             -call 0x4a14d4
    cpu.esp -= 4;
    sub_4a14d4(app, cpu);
    if (cpu.terminate) return;
    // 00483455  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483456  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483458(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483458  c1e302                 +shl ebx, 2
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
    // 0048345b  e974e00100             -jmp 0x4a14d4
    return sub_4a14d4(app, cpu);
}

/* align: skip  */
void Application::sub_483460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483460  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483461  b9b4ad4d00             -mov ecx, 0x4dadb4
    cpu.ecx = 5090740 /*0x4dadb4*/;
    // 00483466  e851dc0100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 0048346b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048346c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483473  b9b4ad4d00             -mov ecx, 0x4dadb4
    cpu.ecx = 5090740 /*0x4dadb4*/;
    // 00483478  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048347b  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048347e  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00483481  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00483484  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00483487  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0048348a  e82ddc0100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 0048348f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483490  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483491  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483492  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483494(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483494  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483495  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00483498  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048349b  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048349d  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004834a0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004834a3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004834a5  b9b4ad4d00             -mov ecx, 0x4dadb4
    cpu.ecx = 5090740 /*0x4dadb4*/;
    // 004834aa  e80ddc0100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 004834af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4834b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004834b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004834b5  b9b4ad4d00             -mov ecx, 0x4dadb4
    cpu.ecx = 5090740 /*0x4dadb4*/;
    // 004834ba  e8fddb0100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 004834bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4834c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004834c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004834c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004834c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004834c7  b9b4ad4d00             -mov ecx, 0x4dadb4
    cpu.ecx = 5090740 /*0x4dadb4*/;
    // 004834cc  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004834cf  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004834d2  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004834d5  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004834d8  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004834db  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004834de  e8d9db0100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 004834e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4834e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004834e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004834e9  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004834ec  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004834ef  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004834f1  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004834f4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004834f7  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004834f9  b9b4ad4d00             -mov ecx, 0x4dadb4
    cpu.ecx = 5090740 /*0x4dadb4*/;
    // 004834fe  e8b9db0100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 00483503  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483504  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_483510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483510  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483511  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483514  0f8de1010000           -jge 0x4836fb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004836fb;
    }
    // 0048351a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048351c  0f8cd9010000           -jl 0x4836fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004836fb;
    }
L_0x00483522:
    // 00483522  a3acb14d00             -mov dword ptr [0x4db1ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5091756) /* 0x4db1ac */) = cpu.eax;
    // 00483527  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483529  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048352c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048352e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00483531  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00483533  8b1485d8ad4d00         -mov edx, dword ptr [eax*4 + 0x4dadd8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090776) /* 0x4dadd8 */ + cpu.eax * 4);
    // 0048353a  891558375600           -mov dword ptr [0x563758], edx
    app->getMemory<x86::reg32>(x86::reg32(5650264) /* 0x563758 */) = cpu.edx;
    // 00483540  8b1485dcad4d00         -mov edx, dword ptr [eax*4 + 0x4daddc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090780) /* 0x4daddc */ + cpu.eax * 4);
    // 00483547  891564375600           -mov dword ptr [0x563764], edx
    app->getMemory<x86::reg32>(x86::reg32(5650276) /* 0x563764 */) = cpu.edx;
    // 0048354d  8b1485e0ad4d00         -mov edx, dword ptr [eax*4 + 0x4dade0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090784) /* 0x4dade0 */ + cpu.eax * 4);
    // 00483554  891538375600           -mov dword ptr [0x563738], edx
    app->getMemory<x86::reg32>(x86::reg32(5650232) /* 0x563738 */) = cpu.edx;
    // 0048355a  8b1485e4ad4d00         -mov edx, dword ptr [eax*4 + 0x4dade4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090788) /* 0x4dade4 */ + cpu.eax * 4);
    // 00483561  89153c375600           -mov dword ptr [0x56373c], edx
    app->getMemory<x86::reg32>(x86::reg32(5650236) /* 0x56373c */) = cpu.edx;
    // 00483567  8b1485e8ad4d00         -mov edx, dword ptr [eax*4 + 0x4dade8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090792) /* 0x4dade8 */ + cpu.eax * 4);
    // 0048356e  891550375600           -mov dword ptr [0x563750], edx
    app->getMemory<x86::reg32>(x86::reg32(5650256) /* 0x563750 */) = cpu.edx;
    // 00483574  8b1485ecad4d00         -mov edx, dword ptr [eax*4 + 0x4dadec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090796) /* 0x4dadec */ + cpu.eax * 4);
    // 0048357b  891568375600           -mov dword ptr [0x563768], edx
    app->getMemory<x86::reg32>(x86::reg32(5650280) /* 0x563768 */) = cpu.edx;
    // 00483581  8b1485f0ad4d00         -mov edx, dword ptr [eax*4 + 0x4dadf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090800) /* 0x4dadf0 */ + cpu.eax * 4);
    // 00483588  891570375600           -mov dword ptr [0x563770], edx
    app->getMemory<x86::reg32>(x86::reg32(5650288) /* 0x563770 */) = cpu.edx;
    // 0048358e  8b1485f4ad4d00         -mov edx, dword ptr [eax*4 + 0x4dadf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090804) /* 0x4dadf4 */ + cpu.eax * 4);
    // 00483595  89156c375600           -mov dword ptr [0x56376c], edx
    app->getMemory<x86::reg32>(x86::reg32(5650284) /* 0x56376c */) = cpu.edx;
    // 0048359b  8b1485f8ad4d00         -mov edx, dword ptr [eax*4 + 0x4dadf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090808) /* 0x4dadf8 */ + cpu.eax * 4);
    // 004835a2  891530375600           -mov dword ptr [0x563730], edx
    app->getMemory<x86::reg32>(x86::reg32(5650224) /* 0x563730 */) = cpu.edx;
    // 004835a8  8b1485fcad4d00         -mov edx, dword ptr [eax*4 + 0x4dadfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090812) /* 0x4dadfc */ + cpu.eax * 4);
    // 004835af  891544375600           -mov dword ptr [0x563744], edx
    app->getMemory<x86::reg32>(x86::reg32(5650244) /* 0x563744 */) = cpu.edx;
    // 004835b5  8b148500ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090816) /* 0x4dae00 */ + cpu.eax * 4);
    // 004835bc  891578375600           -mov dword ptr [0x563778], edx
    app->getMemory<x86::reg32>(x86::reg32(5650296) /* 0x563778 */) = cpu.edx;
    // 004835c2  8b148504ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090820) /* 0x4dae04 */ + cpu.eax * 4);
    // 004835c9  89155c375600           -mov dword ptr [0x56375c], edx
    app->getMemory<x86::reg32>(x86::reg32(5650268) /* 0x56375c */) = cpu.edx;
    // 004835cf  8b148508ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090824) /* 0x4dae08 */ + cpu.eax * 4);
    // 004835d6  89154c375600           -mov dword ptr [0x56374c], edx
    app->getMemory<x86::reg32>(x86::reg32(5650252) /* 0x56374c */) = cpu.edx;
    // 004835dc  8b14850cae4d00         -mov edx, dword ptr [eax*4 + 0x4dae0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090828) /* 0x4dae0c */ + cpu.eax * 4);
    // 004835e3  891548375600           -mov dword ptr [0x563748], edx
    app->getMemory<x86::reg32>(x86::reg32(5650248) /* 0x563748 */) = cpu.edx;
    // 004835e9  8b148510ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090832) /* 0x4dae10 */ + cpu.eax * 4);
    // 004835f0  891554375600           -mov dword ptr [0x563754], edx
    app->getMemory<x86::reg32>(x86::reg32(5650260) /* 0x563754 */) = cpu.edx;
    // 004835f6  8b148514ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090836) /* 0x4dae14 */ + cpu.eax * 4);
    // 004835fd  891534375600           -mov dword ptr [0x563734], edx
    app->getMemory<x86::reg32>(x86::reg32(5650228) /* 0x563734 */) = cpu.edx;
    // 00483603  8b148518ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090840) /* 0x4dae18 */ + cpu.eax * 4);
    // 0048360a  891574375600           -mov dword ptr [0x563774], edx
    app->getMemory<x86::reg32>(x86::reg32(5650292) /* 0x563774 */) = cpu.edx;
    // 00483610  8b14851cae4d00         -mov edx, dword ptr [eax*4 + 0x4dae1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090844) /* 0x4dae1c */ + cpu.eax * 4);
    // 00483617  891540375600           -mov dword ptr [0x563740], edx
    app->getMemory<x86::reg32>(x86::reg32(5650240) /* 0x563740 */) = cpu.edx;
    // 0048361d  8b148520ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090848) /* 0x4dae20 */ + cpu.eax * 4);
    // 00483624  891560375600           -mov dword ptr [0x563760], edx
    app->getMemory<x86::reg32>(x86::reg32(5650272) /* 0x563760 */) = cpu.edx;
    // 0048362a  8b148524ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090852) /* 0x4dae24 */ + cpu.eax * 4);
    // 00483631  89151c375600           -mov dword ptr [0x56371c], edx
    app->getMemory<x86::reg32>(x86::reg32(5650204) /* 0x56371c */) = cpu.edx;
    // 00483637  8b148528ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090856) /* 0x4dae28 */ + cpu.eax * 4);
    // 0048363e  8915f8365600           -mov dword ptr [0x5636f8], edx
    app->getMemory<x86::reg32>(x86::reg32(5650168) /* 0x5636f8 */) = cpu.edx;
    // 00483644  8b14852cae4d00         -mov edx, dword ptr [eax*4 + 0x4dae2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090860) /* 0x4dae2c */ + cpu.eax * 4);
    // 0048364b  8915f0365600           -mov dword ptr [0x5636f0], edx
    app->getMemory<x86::reg32>(x86::reg32(5650160) /* 0x5636f0 */) = cpu.edx;
    // 00483651  8b148530ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090864) /* 0x4dae30 */ + cpu.eax * 4);
    // 00483658  891518375600           -mov dword ptr [0x563718], edx
    app->getMemory<x86::reg32>(x86::reg32(5650200) /* 0x563718 */) = cpu.edx;
    // 0048365e  8b148534ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090868) /* 0x4dae34 */ + cpu.eax * 4);
    // 00483665  891508375600           -mov dword ptr [0x563708], edx
    app->getMemory<x86::reg32>(x86::reg32(5650184) /* 0x563708 */) = cpu.edx;
    // 0048366b  8b148538ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090872) /* 0x4dae38 */ + cpu.eax * 4);
    // 00483672  891510375600           -mov dword ptr [0x563710], edx
    app->getMemory<x86::reg32>(x86::reg32(5650192) /* 0x563710 */) = cpu.edx;
    // 00483678  8b14853cae4d00         -mov edx, dword ptr [eax*4 + 0x4dae3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090876) /* 0x4dae3c */ + cpu.eax * 4);
    // 0048367f  89152c375600           -mov dword ptr [0x56372c], edx
    app->getMemory<x86::reg32>(x86::reg32(5650220) /* 0x56372c */) = cpu.edx;
    // 00483685  8b148540ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090880) /* 0x4dae40 */ + cpu.eax * 4);
    // 0048368c  891500375600           -mov dword ptr [0x563700], edx
    app->getMemory<x86::reg32>(x86::reg32(5650176) /* 0x563700 */) = cpu.edx;
    // 00483692  8b148544ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090884) /* 0x4dae44 */ + cpu.eax * 4);
    // 00483699  8915f4365600           -mov dword ptr [0x5636f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5650164) /* 0x5636f4 */) = cpu.edx;
    // 0048369f  8b148548ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090888) /* 0x4dae48 */ + cpu.eax * 4);
    // 004836a6  891520375600           -mov dword ptr [0x563720], edx
    app->getMemory<x86::reg32>(x86::reg32(5650208) /* 0x563720 */) = cpu.edx;
    // 004836ac  8b14854cae4d00         -mov edx, dword ptr [eax*4 + 0x4dae4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090892) /* 0x4dae4c */ + cpu.eax * 4);
    // 004836b3  891504375600           -mov dword ptr [0x563704], edx
    app->getMemory<x86::reg32>(x86::reg32(5650180) /* 0x563704 */) = cpu.edx;
    // 004836b9  8b148550ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090896) /* 0x4dae50 */ + cpu.eax * 4);
    // 004836c0  891524375600           -mov dword ptr [0x563724], edx
    app->getMemory<x86::reg32>(x86::reg32(5650212) /* 0x563724 */) = cpu.edx;
    // 004836c6  8b148554ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090900) /* 0x4dae54 */ + cpu.eax * 4);
    // 004836cd  891514375600           -mov dword ptr [0x563714], edx
    app->getMemory<x86::reg32>(x86::reg32(5650196) /* 0x563714 */) = cpu.edx;
    // 004836d3  8b148558ae4d00         -mov edx, dword ptr [eax*4 + 0x4dae58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090904) /* 0x4dae58 */ + cpu.eax * 4);
    // 004836da  891528375600           -mov dword ptr [0x563728], edx
    app->getMemory<x86::reg32>(x86::reg32(5650216) /* 0x563728 */) = cpu.edx;
    // 004836e0  8b14855cae4d00         -mov edx, dword ptr [eax*4 + 0x4dae5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090908) /* 0x4dae5c */ + cpu.eax * 4);
    // 004836e7  8b048560ae4d00         -mov eax, dword ptr [eax*4 + 0x4dae60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090912) /* 0x4dae60 */ + cpu.eax * 4);
    // 004836ee  89150c375600           -mov dword ptr [0x56370c], edx
    app->getMemory<x86::reg32>(x86::reg32(5650188) /* 0x56370c */) = cpu.edx;
    // 004836f4  a3fc365600             -mov dword ptr [0x5636fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5650172) /* 0x5636fc */) = cpu.eax;
    // 004836f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004836fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004836fb:
    // 004836fb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004836fd  e920feffff             -jmp 0x483522
    goto L_0x00483522;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483704(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483704  a1acb14d00             -mov eax, dword ptr [0x4db1ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091756) /* 0x4db1ac */);
    // 00483709  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48370c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048370c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00483711  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_483720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483720  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483721  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483722  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00483724  39d0                   +cmp eax, edx
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
    // 00483726  746c                   -je 0x483794
    if (cpu.flags.zf)
    {
        goto L_0x00483794;
    }
L_0x00483728:
    // 00483728  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048372a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048372c  39c1                   +cmp ecx, eax
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
    // 0048372e  7569                   -jne 0x483799
    if (!cpu.flags.zf)
    {
        goto L_0x00483799;
    }
    // 00483730  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00483732  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00483737  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483739  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 0048373e  7554                   -jne 0x483794
    if (!cpu.flags.zf)
    {
        goto L_0x00483794;
    }
    // 00483740  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00483743  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00483746  39c1                   +cmp ecx, eax
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
    // 00483748  754f                   -jne 0x483799
    if (!cpu.flags.zf)
    {
        goto L_0x00483799;
    }
    // 0048374a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048374c  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00483751  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483753  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00483758  753a                   -jne 0x483794
    if (!cpu.flags.zf)
    {
        goto L_0x00483794;
    }
    // 0048375a  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048375d  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00483760  39c1                   +cmp ecx, eax
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
    // 00483762  7535                   -jne 0x483799
    if (!cpu.flags.zf)
    {
        goto L_0x00483799;
    }
    // 00483764  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00483766  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 0048376b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048376d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00483772  7520                   -jne 0x483794
    if (!cpu.flags.zf)
    {
        goto L_0x00483794;
    }
    // 00483774  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00483777  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048377a  39c1                   +cmp ecx, eax
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
    // 0048377c  751b                   -jne 0x483799
    if (!cpu.flags.zf)
    {
        goto L_0x00483799;
    }
    // 0048377e  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00483781  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00483784  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00483786  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 0048378b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048378d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00483792  7494                   -je 0x483728
    if (cpu.flags.zf)
    {
        goto L_0x00483728;
    }
L_0x00483794:
    // 00483794  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00483796  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483797  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483798  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483799:
    // 00483799  38c8                   +cmp al, cl
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
    // 0048379b  751d                   -jne 0x4837ba
    if (!cpu.flags.zf)
    {
        goto L_0x004837ba;
    }
    // 0048379d  3c00                   +cmp al, 0
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
    // 0048379f  74f3                   -je 0x483794
    if (cpu.flags.zf)
    {
        goto L_0x00483794;
    }
    // 004837a1  38ec                   +cmp ah, ch
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
    // 004837a3  7515                   -jne 0x4837ba
    if (!cpu.flags.zf)
    {
        goto L_0x004837ba;
    }
    // 004837a5  80fc00                 +cmp ah, 0
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
    // 004837a8  74ea                   -je 0x483794
    if (cpu.flags.zf)
    {
        goto L_0x00483794;
    }
    // 004837aa  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004837ad  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004837b0  38c8                   +cmp al, cl
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
    // 004837b2  7506                   -jne 0x4837ba
    if (!cpu.flags.zf)
    {
        goto L_0x004837ba;
    }
    // 004837b4  3c00                   +cmp al, 0
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
    // 004837b6  74dc                   -je 0x483794
    if (cpu.flags.zf)
    {
        goto L_0x00483794;
    }
    // 004837b8  38ec                   +cmp ah, ch
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
L_0x004837ba:
    // 004837ba  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004837bc  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004837be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4837d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004837d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004837d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004837d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004837d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004837d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004837d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004837d6  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004837dd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004837df  e828660000             -call 0x489e0c
    cpu.esp -= 4;
    sub_489e0c(app, cpu);
    if (cpu.terminate) return;
    // 004837e4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004837e6  a3d8375600             -mov dword ptr [0x5637d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5650392) /* 0x5637d8 */) = cpu.eax;
    // 004837eb  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004837ed:
    // 004837ed  a1d8375600             -mov eax, dword ptr [0x5637d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650392) /* 0x5637d8 */);
    // 004837f2  e865660000             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004837f7  3b3dd0375600           +cmp edi, dword ptr [0x5637d0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650384) /* 0x5637d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004837fd  7463                   -je 0x483862
    if (cpu.flags.zf)
    {
        goto L_0x00483862;
    }
    // 004837ff  ff05f4375600           -inc dword ptr [0x5637f4]
    (app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */))++;
    // 00483805  ff05f0375600           -inc dword ptr [0x5637f0]
    (app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */))++;
    // 0048380b  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483812  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483814  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00483816  69d2a9040000           -imul edx, edx, 0x4a9
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(1193 /*0x4a9*/)));
    // 0048381c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048381e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483820  81fbffff0000           +cmp ebx, 0xffff
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
    // 00483826  7e11                   -jle 0x483839
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483839;
    }
    // 00483828  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048382a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048382d  0105d4375600           -add dword ptr [0x5637d4], eax
    (app->getMemory<x86::reg32>(x86::reg32(5650388) /* 0x5637d4 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00483833  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x00483839:
    // 00483839  8b2d80375600           -mov ebp, dword ptr [0x563780]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5650304) /* 0x563780 */);
    // 0048383f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00483841  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00483843  39ef                   +cmp edi, ebp
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
    // 00483845  74a6                   -je 0x4837ed
    if (cpu.flags.zf)
    {
        goto L_0x004837ed;
    }
L_0x00483847:
    // 00483847  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483849  41                     -inc ecx
    (cpu.ecx)++;
    // 0048384a  ff9080375600           -call dword ptr [eax + 0x563780]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650304) /* 0x563780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483850  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483853  83f908                 +cmp ecx, 8
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
    // 00483856  7395                   -jae 0x4837ed
    if (!cpu.flags.cf)
    {
        goto L_0x004837ed;
    }
    // 00483858  3bba80375600           +cmp edi, dword ptr [edx + 0x563780]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5650304) /* 0x563780 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048385e  75e7                   -jne 0x483847
    if (!cpu.flags.zf)
    {
        goto L_0x00483847;
    }
    // 00483860  eb8b                   -jmp 0x4837ed
    goto L_0x004837ed;
L_0x00483862:
    // 00483862  a1d8375600             -mov eax, dword ptr [0x5637d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650392) /* 0x5637d8 */);
    // 00483867  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483869  e87a660000             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 0048386e  8915d8375600           -mov dword ptr [0x5637d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5650392) /* 0x5637d8 */) = cpu.edx;
    // 00483874  8915ccab4d00           -mov dword ptr [0x4dabcc], edx
    app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */) = cpu.edx;
    // 0048387a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048387b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048387c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048387d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048387e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048387f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483880  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483884(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483884  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483885  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483886  e881650000             -call 0x489e0c
    cpu.esp -= 4;
    sub_489e0c(app, cpu);
    if (cpu.terminate) return;
    // 0048388b  8b15ac375600           -mov edx, dword ptr [0x5637ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650348) /* 0x5637ac */);
    // 00483891  a3cc375600             -mov dword ptr [0x5637cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */) = cpu.eax;
    // 00483896  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483898  741a                   -je 0x4838b4
    if (cpu.flags.zf)
    {
        goto L_0x004838b4;
    }
L_0x0048389a:
    // 0048389a  ff15ac375600           -call dword ptr [0x5637ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650348) /* 0x5637ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004838a0  a1cc375600             -mov eax, dword ptr [0x5637cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */);
    // 004838a5  e8b2650000             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004838aa  833dac37560000         +cmp dword ptr [0x5637ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650348) /* 0x5637ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004838b1  75e7                   -jne 0x48389a
    if (!cpu.flags.zf)
    {
        goto L_0x0048389a;
    }
    // 004838b3  90                     -nop 
    ;
L_0x004838b4:
    // 004838b4  a1cc375600             -mov eax, dword ptr [0x5637cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */);
    // 004838b9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004838bb  e828660000             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 004838c0  891dcc375600           -mov dword ptr [0x5637cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */) = cpu.ebx;
    // 004838c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4838cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004838cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004838cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004838ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004838cf  a3ac375600             -mov dword ptr [0x5637ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5650348) /* 0x5637ac */) = cpu.eax;
    // 004838d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004838d6  740a                   -je 0x4838e2
    if (cpu.flags.zf)
    {
        goto L_0x004838e2;
    }
    // 004838d8  8b15cc375600           -mov edx, dword ptr [0x5637cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */);
    // 004838de  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004838e0  741a                   -je 0x4838fc
    if (cpu.flags.zf)
    {
        goto L_0x004838fc;
    }
L_0x004838e2:
    // 004838e2  833dac37560000         +cmp dword ptr [0x5637ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650348) /* 0x5637ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004838e9  750d                   -jne 0x4838f8
    if (!cpu.flags.zf)
    {
        goto L_0x004838f8;
    }
    // 004838eb  8b1dcc375600           -mov ebx, dword ptr [0x5637cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */);
    // 004838f1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004838f3  753e                   -jne 0x483933
    if (!cpu.flags.zf)
    {
        goto L_0x00483933;
    }
    // 004838f5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004838f8:
    // 004838f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004838fc:
    // 004838fc  68b0375600             -push 0x5637b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5650352 /*0x5637b0*/;
    cpu.esp -= 4;
    // 00483901  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00483906  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048390b  b884384800             -mov eax, 0x483884
    cpu.eax = 4733060 /*0x483884*/;
    // 00483910  e8cb610000             -call 0x489ae0
    cpu.esp -= 4;
    sub_489ae0(app, cpu);
    if (cpu.terminate) return;
    // 00483915  833dcc37560000         +cmp dword ptr [0x5637cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048391c  75da                   -jne 0x4838f8
    if (!cpu.flags.zf)
    {
        goto L_0x004838f8;
    }
    // 0048391e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00483920:
    // 00483920  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483922  e875620000             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00483927  3b15cc375600           +cmp edx, dword ptr [0x5637cc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048392d  74f1                   -je 0x483920
    if (cpu.flags.zf)
    {
        goto L_0x00483920;
    }
    // 0048392f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483930  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483931  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483932  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483933:
    // 00483933  b8b0375600             -mov eax, 0x5637b0
    cpu.eax = 5650352 /*0x5637b0*/;
    // 00483938  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048393a  e8e1640000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 0048393f  833dcc37560000         +cmp dword ptr [0x5637cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483946  74b0                   -je 0x4838f8
    if (cpu.flags.zf)
    {
        goto L_0x004838f8;
    }
    // 00483948  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048394a:
    // 0048394a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048394c  e84b620000             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00483951  3b15cc375600           +cmp edx, dword ptr [0x5637cc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483957  75f1                   -jne 0x48394a
    if (!cpu.flags.zf)
    {
        goto L_0x0048394a;
    }
    // 00483959  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048395a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048395b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048395c  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
