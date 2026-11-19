#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x90 */
void Application::sub_491018(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491018);
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

/* align: skip 0x90 */
void Application::sub_4910b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004910b4);
    // 004910b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004910b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004910b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004910b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004910b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004910b9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004910ba  81ec44030000           -sub esp, 0x344
    (cpu.esp) -= x86::reg32(x86::sreg32(836 /*0x344*/));
    // 004910c0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004910c2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004910c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004910c6  7505                   -jne 0x4910cd
    if (!cpu.flags.zf)
    {
        goto L_0x004910cd;
    }
    // 004910c8  be00395600             -mov esi, 0x563900
    cpu.esi = 5650688 /*0x563900*/;
L_0x004910cd:
    // 004910cd  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004910d2  e8718effff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004910d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004910d9  ba6c010000             -mov edx, 0x16c
    cpu.edx = 364 /*0x16c*/;
    // 004910de  e835ffffff             -call 0x491018
    cpu.esp -= 4;
    sub_491018(app, cpu);
    if (cpu.terminate) return;
    // 004910e3  8994246c010000         -mov dword ptr [esp + 0x16c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.edx;
    // 004910ea  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004910ed  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004910ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004910f0  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004910f7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004910f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004910fa  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004910fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004910fd  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491100  8aa637040000           -mov ah, byte ptr [esi + 0x437]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
    // 00491106  80fc01                 +cmp ah, 1
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
    // 00491109  0f8340010000           -jae 0x49124f
    if (!cpu.flags.cf)
    {
        goto L_0x0049124f;
    }
    // 0049110f  c6863704000001         -mov byte ptr [esi + 0x437], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 1 /*0x1*/;
L_0x00491116:
    // 00491116  f68424f001000010       +test byte ptr [esp + 0x1f0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(496) /* 0x1f0 */) & 16 /*0x10*/));
    // 0049111e  0f8462010000           -je 0x491286
    if (cpu.flags.zf)
    {
        goto L_0x00491286;
    }
    // 00491124  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00491126:
    // 00491126  888660040000           -mov byte ptr [esi + 0x460], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */) = cpu.al;
    // 0049112c  f684247301000008       +test byte ptr [esp + 0x173], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 8 /*0x8*/));
    // 00491134  0f8453010000           -je 0x49128d
    if (cpu.flags.zf)
    {
        goto L_0x0049128d;
    }
    // 0049113a  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0049113c:
    // 0049113c  8aae5e040000           -mov ch, byte ptr [esi + 0x45e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1118) /* 0x45e */);
    // 00491142  888662040000           -mov byte ptr [esi + 0x462], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1122) /* 0x462 */) = cpu.al;
    // 00491148  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 0049114a  0f8544010000           -jne 0x491294
    if (!cpu.flags.zf)
    {
        goto L_0x00491294;
    }
    // 00491150  80be3604000000         +cmp byte ptr [esi + 0x436], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491157  740e                   -je 0x491167
    if (cpu.flags.zf)
    {
        goto L_0x00491167;
    }
    // 00491159  c6863504000001         -mov byte ptr [esi + 0x435], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
    // 00491160  c6863404000001         -mov byte ptr [esi + 0x434], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1076) /* 0x434 */) = 1 /*0x1*/;
L_0x00491167:
    // 00491167  81fe00395600           +cmp esi, 0x563900
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5650688 /*0x563900*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049116d  7503                   -jne 0x491172
    if (!cpu.flags.zf)
    {
        goto L_0x00491172;
    }
    // 0049116f  80cf02                 -or bh, 2
    cpu.bh |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00491172:
    // 00491172  80be6304000001         +cmp byte ptr [esi + 0x463], 1
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
    // 00491179  762f                   -jbe 0x4911aa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004911aa;
    }
    // 0049117b  80be3504000000         +cmp byte ptr [esi + 0x435], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491182  0f8430010000           -je 0x4912b8
    if (cpu.flags.zf)
    {
        goto L_0x004912b8;
    }
L_0x00491188:
    // 00491188  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049118d:
    // 0049118d  80be6004000000         +cmp byte ptr [esi + 0x460], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491194  0f8532010000           -jne 0x4912cc
    if (!cpu.flags.zf)
    {
        goto L_0x004912cc;
    }
    // 0049119a  80be6204000000         +cmp byte ptr [esi + 0x462], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1122) /* 0x462 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004911a1  0f8425010000           -je 0x4912cc
    if (cpu.flags.zf)
    {
        goto L_0x004912cc;
    }
L_0x004911a7:
    // 004911a7  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004911aa:
    // 004911aa  8b7e24                 -mov edi, dword ptr [esi + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004911ad  8d4630                 -lea eax, [esi + 0x30]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004911b0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004911b2  0f852e010000           -jne 0x4912e6
    if (!cpu.flags.zf)
    {
        goto L_0x004912e6;
    }
    // 004911b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004911b9  8d7e24                 -lea edi, [esi + 0x24]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004911bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004911bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004911be  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004911c0  6a44                   -push 0x44
    app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 004911c2  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004911c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004911c5  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004911c8:
    // 004911c8  66c786300400000000     -mov word ptr [esi + 0x430], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 004911d1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004911d3  66c78632040000ff00     -mov word ptr [esi + 0x432], 0xff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
    // 004911dc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004911de  c6865f04000000         -mov byte ptr [esi + 0x45f], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = 0 /*0x0*/;
    // 004911e5  e866f4ffff             -call 0x490650
    cpu.esp -= 4;
    sub_490650(app, cpu);
    if (cpu.terminate) return;
    // 004911ea  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004911ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004911ee  0f8507010000           -jne 0x4912fb
    if (!cpu.flags.zf)
    {
        goto L_0x004912fb;
    }
    // 004911f4  c6865f04000001         -mov byte ptr [esi + 0x45f], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = 1 /*0x1*/;
L_0x004911fb:
    // 004911fb  c6863704000002         -mov byte ptr [esi + 0x437], 2
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 00491202  8a8637040000           -mov al, byte ptr [esi + 0x437]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
    // 00491208  888663040000           -mov byte ptr [esi + 0x463], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = cpu.al;
    // 0049120e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00491210  7409                   -je 0x49121b
    if (cpu.flags.zf)
    {
        goto L_0x0049121b;
    }
    // 00491212  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00491214  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491216  e8dd0e0000             -call 0x4920f8
    cpu.esp -= 4;
    sub_4920f8(app, cpu);
    if (cpu.terminate) return;
L_0x0049121b:
    // 0049121b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049121d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049121f  e82cf4ffff             -call 0x490650
    cpu.esp -= 4;
    sub_490650(app, cpu);
    if (cpu.terminate) return;
    // 00491224  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00491226:
    // 00491226  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00491228  0f8534010000           -jne 0x491362
    if (!cpu.flags.zf)
    {
        goto L_0x00491362;
    }
    // 0049122e  b828034d00             -mov eax, 0x4d0328
    cpu.eax = 5047080 /*0x4d0328*/;
    // 00491233  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491235  0f850e010000           -jne 0x491349
    if (!cpu.flags.zf)
    {
        goto L_0x00491349;
    }
    // 0049123b  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
    // 00491240  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491242  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 00491248  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491249  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049124a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049124b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049124c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049124d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049124e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049124f:
    // 0049124f  80fc02                 +cmp ah, 2
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
    // 00491252  0f86befeffff           -jbe 0x491116
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00491116;
    }
    // 00491258  b804034d00             -mov eax, 0x4d0304
    cpu.eax = 5047044 /*0x4d0304*/;
    // 0049125d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049125f  751e                   -jne 0x49127f
    if (!cpu.flags.zf)
    {
        goto L_0x0049127f;
    }
L_0x00491261:
    // 00491261  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
    // 00491266  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0049126b  e8f08cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00491270  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491272  81c444030000           +add esp, 0x344
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(836 /*0x344*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491278  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491279  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049127a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049127b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049127c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049127d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049127e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049127f:
    // 0049127f  b8e4014d00             -mov eax, 0x4d01e4
    cpu.eax = 5046756 /*0x4d01e4*/;
    // 00491284  ebdb                   -jmp 0x491261
    goto L_0x00491261;
L_0x00491286:
    // 00491286  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00491288  e999feffff             -jmp 0x491126
    goto L_0x00491126;
L_0x0049128d:
    // 0049128d  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0049128f  e9a8feffff             -jmp 0x49113c
    goto L_0x0049113c;
L_0x00491294:
    // 00491294  c6863604000000         -mov byte ptr [esi + 0x436], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */) = 0 /*0x0*/;
    // 0049129b  c6863504000001         -mov byte ptr [esi + 0x435], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
    // 004912a2  c6863704000002         -mov byte ptr [esi + 0x437], 2
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 004912a9  80cf2a                 +or bh, 0x2a
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(42 /*0x2a*/))));
    // 004912ac  c6866304000001         -mov byte ptr [esi + 0x463], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 004912b3  e9affeffff             -jmp 0x491167
    goto L_0x00491167;
L_0x004912b8:
    // 004912b8  80be3404000000         +cmp byte ptr [esi + 0x434], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1076) /* 0x434 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004912bf  0f85c3feffff           -jne 0x491188
    if (!cpu.flags.zf)
    {
        goto L_0x00491188;
    }
    // 004912c5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004912c7  e9c1feffff             -jmp 0x49118d
    goto L_0x0049118d;
L_0x004912cc:
    // 004912cc  80be5e04000000         +cmp byte ptr [esi + 0x45e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1118) /* 0x45e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004912d3  7408                   -je 0x4912dd
    if (cpu.flags.zf)
    {
        goto L_0x004912dd;
    }
L_0x004912d5:
    // 004912d5  80cf40                 +or bh, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 004912d8  e9cdfeffff             -jmp 0x4911aa
    goto L_0x004911aa;
L_0x004912dd:
    // 004912dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004912df  74f4                   -je 0x4912d5
    if (cpu.flags.zf)
    {
        goto L_0x004912d5;
    }
    // 004912e1  e9c1feffff             -jmp 0x4911a7
    goto L_0x004911a7;
L_0x004912e6:
    // 004912e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004912e7  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004912ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004912ee  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004912f0  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004912f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004912f3  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004912f6  e9cdfeffff             -jmp 0x4911c8
    goto L_0x004911c8;
L_0x004912fb:
    // 004912fb  8d8c24d8020000         -lea ecx, [esp + 0x2d8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 00491302  bd6c000000             -mov ebp, 0x6c
    cpu.ebp = 108 /*0x6c*/;
    // 00491307  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491308  89ac24dc020000         -mov dword ptr [esp + 0x2dc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */) = cpu.ebp;
    // 0049130f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491310  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491312  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491315  f684244203000020       +test byte ptr [esp + 0x342], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(834) /* 0x342 */) & 32 /*0x20*/));
    // 0049131d  7415                   -je 0x491334
    if (cpu.flags.zf)
    {
        goto L_0x00491334;
    }
    // 0049131f  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00491321  88865f040000           -mov byte ptr [esi + 0x45f], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = cpu.al;
    // 00491327  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00491329  0f85ccfeffff           -jne 0x4911fb
    if (!cpu.flags.zf)
    {
        goto L_0x004911fb;
    }
    // 0049132f  e9f2feffff             -jmp 0x491226
    goto L_0x00491226;
L_0x00491334:
    // 00491334  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00491336  88865f040000           -mov byte ptr [esi + 0x45f], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = cpu.al;
    // 0049133c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0049133e  0f85b7feffff           -jne 0x4911fb
    if (!cpu.flags.zf)
    {
        goto L_0x004911fb;
    }
    // 00491344  e9ddfeffff             -jmp 0x491226
    goto L_0x00491226;
L_0x00491349:
    // 00491349  b8e4014d00             -mov eax, 0x4d01e4
    cpu.eax = 5046756 /*0x4d01e4*/;
    // 0049134e  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
    // 00491353  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491355  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 0049135b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049135c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049135d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049135e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049135f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491360  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491361  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491362:
    // 00491362  837e0400               +cmp dword ptr [esi + 4], 0
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
    // 00491366  7413                   -je 0x49137b
    if (cpu.flags.zf)
    {
        goto L_0x0049137b;
    }
    // 00491368  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
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
    // 0049136f  750a                   -jne 0x49137b
    if (!cpu.flags.zf)
    {
        goto L_0x0049137b;
    }
    // 00491371  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00491374  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491375  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00491377  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491378  ff5070                 -call dword ptr [eax + 0x70]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049137b:
    // 0049137b  8d8424d8020000         -lea eax, [esp + 0x2d8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 00491382  b96c000000             -mov ecx, 0x6c
    cpu.ecx = 108 /*0x6c*/;
    // 00491387  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491388  898c24dc020000         -mov dword ptr [esp + 0x2dc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */) = cpu.ecx;
    // 0049138f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491390  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00491392  8d9c24e0020000         -lea ebx, [esp + 0x2e0]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(736) /* 0x2e0 */);
    // 00491399  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049139c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004913a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004913a3  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004913a6  e859f5ffff             -call 0x490904
    cpu.esp -= 4;
    sub_490904(app, cpu);
    if (cpu.terminate) return;
    // 004913ab  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 004913b1  89be44040000           -mov dword ptr [esi + 0x444], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */) = cpu.edi;
    // 004913b7  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004913b9  0f8602010000           -jbe 0x4914c1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004914c1;
    }
    // 004913bf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004913c1  e8660d0000             -call 0x49212c
    cpu.esp -= 4;
    sub_49212c(app, cpu);
    if (cpu.terminate) return;
L_0x004913c6:
    // 004913c6  898648040000           -mov dword ptr [esi + 0x448], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */) = cpu.eax;
L_0x004913cc:
    // 004913cc  83be4404000000         +cmp dword ptr [esi + 0x444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004913d3  745a                   -je 0x49142f
    if (cpu.flags.zf)
    {
        goto L_0x0049142f;
    }
    // 004913d5  c78424d80200006c000000 -mov dword ptr [esp + 0x2d8], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */) = 108 /*0x6c*/;
    // 004913e0  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004913e3  8d8c24d8020000         -lea ecx, [esp + 0x2d8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 004913ea  898424e8020000         -mov dword ptr [esp + 0x2e8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */) = cpu.eax;
    // 004913f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004913f2  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 004913f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004913f9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004913fb  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004913fe  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00491404  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491405  8b942400030000         -mov edx, dword ptr [esp + 0x300]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0049140c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049140e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049140f  8b9c24f0020000         -mov ebx, dword ptr [esp + 0x2f0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(752) /* 0x2f0 */);
    // 00491416  8a8e5c040000           -mov cl, byte ptr [esi + 0x45c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 0049141c  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0049141e  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00491421  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00491424  e87fb40100             -call 0x4ac8a8
    cpu.esp -= 4;
    sub_4ac8a8(app, cpu);
    if (cpu.terminate) return;
    // 00491429  89864c040000           -mov dword ptr [esi + 0x44c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1100) /* 0x44c */) = cpu.eax;
L_0x0049142f:
    // 0049142f  83be4804000000         +cmp dword ptr [esi + 0x448], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491436  0f84f6000000           -je 0x491532
    if (cpu.flags.zf)
    {
        goto L_0x00491532;
    }
    // 0049143c  c78424d80200006c000000 -mov dword ptr [esp + 0x2d8], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */) = 108 /*0x6c*/;
    // 00491447  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049144a  8d9424d8020000         -lea edx, [esp + 0x2d8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 00491451  898424e8020000         -mov dword ptr [esp + 0x2e8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */) = cpu.eax;
    // 00491458  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491459  8b8648040000           -mov eax, dword ptr [esi + 0x448]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0049145f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491460  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491462  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491465  8bbe48040000           -mov edi, dword ptr [esi + 0x448]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0049146b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049146c  8bac2400030000         -mov ebp, dword ptr [esp + 0x300]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00491473  8b9c24ec020000         -mov ebx, dword ptr [esp + 0x2ec]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(748) /* 0x2ec */);
    // 0049147a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049147b  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049147e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491480  6afe                   -push -2
    app->getMemory<x86::reg32>(cpu.esp-4) = -2 /*-0x2*/;
    cpu.esp -= 4;
    // 00491482  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00491485  8a8e5c040000           -mov cl, byte ptr [esi + 0x45c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 0049148b  e818b40100             -call 0x4ac8a8
    cpu.esp -= 4;
    sub_4ac8a8(app, cpu);
    if (cpu.terminate) return;
    // 00491490  898650040000           -mov dword ptr [esi + 0x450], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1104) /* 0x450 */) = cpu.eax;
L_0x00491496:
    // 00491496  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0049149b  e8c08affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004914a0  833dd0b14d0000         +cmp dword ptr [0x4db1d0], 0
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
    // 004914a7  7406                   -je 0x4914af
    if (cpu.flags.zf)
    {
        goto L_0x004914af;
    }
    // 004914a9  ff15d0b14d00           -call dword ptr [0x4db1d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5091792) /* 0x4db1d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004914af:
    // 004914af  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004914b4  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 004914ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004914c1:
    // 004914c1  80be3604000000         +cmp byte ptr [esi + 0x436], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004914c8  0f85fefeffff           -jne 0x4913cc
    if (!cpu.flags.zf)
    {
        goto L_0x004913cc;
    }
    // 004914ce  80be3704000001         +cmp byte ptr [esi + 0x437], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004914d5  0f86f1feffff           -jbe 0x4913cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004913cc;
    }
    // 004914db  80be3504000000         +cmp byte ptr [esi + 0x435], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004914e2  742b                   -je 0x49150f
    if (cpu.flags.zf)
    {
        goto L_0x0049150f;
    }
L_0x004914e4:
    // 004914e4  8b9e48040000           -mov ebx, dword ptr [esi + 0x448]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 004914ea  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004914ec  0f85dafeffff           -jne 0x4913cc
    if (!cpu.flags.zf)
    {
        goto L_0x004913cc;
    }
    // 004914f2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004914f3  6840080000             -push 0x840
    app->getMemory<x86::reg32>(cpu.esp-4) = 2112 /*0x840*/;
    cpu.esp -= 4;
    // 004914f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004914f9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004914fb  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004914fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004914ff  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00491502  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00491505  e8fa090000             -call 0x491f04
    cpu.esp -= 4;
    sub_491f04(app, cpu);
    if (cpu.terminate) return;
    // 0049150a  e9b7feffff             -jmp 0x4913c6
    goto L_0x004913c6;
L_0x0049150f:
    // 0049150f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491511  6840400000             -push 0x4040
    app->getMemory<x86::reg32>(cpu.esp-4) = 16448 /*0x4040*/;
    cpu.esp -= 4;
    // 00491516  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491518  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049151a  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049151d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049151f  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00491522  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00491525  e8da090000             -call 0x491f04
    cpu.esp -= 4;
    sub_491f04(app, cpu);
    if (cpu.terminate) return;
    // 0049152a  898648040000           -mov dword ptr [esi + 0x448], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */) = cpu.eax;
    // 00491530  ebb2                   -jmp 0x4914e4
    goto L_0x004914e4;
L_0x00491532:
    // 00491532  80be3704000001         +cmp byte ptr [esi + 0x437], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491539  0f8657ffffff           -jbe 0x491496
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00491496;
    }
    // 0049153f  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00491542  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00491545  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00491547  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049154a  8a9e5c040000           -mov bl, byte ptr [esi + 0x45c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 00491550  bfb0b24d00             -mov edi, 0x4db2b0
    cpu.edi = 5092016 /*0x4db2b0*/;
    // 00491555  e8c6120000             -call 0x492820
    cpu.esp -= 4;
    sub_492820(app, cpu);
    if (cpu.terminate) return;
    // 0049155a  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0049155f  898650040000           -mov dword ptr [esi + 0x450], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1104) /* 0x450 */) = cpu.eax;
    // 00491565  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00491567  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00491569  e928ffffff             -jmp 0x491496
    goto L_0x00491496;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491570);
    // 00491570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491572  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491573  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491574  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491575  81ec8c040000           -sub esp, 0x48c
    (cpu.esp) -= x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 0049157b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049157d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049157f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00491581  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491583  7505                   -jne 0x49158a
    if (!cpu.flags.zf)
    {
        goto L_0x0049158a;
    }
    // 00491585  bb00395600             -mov ebx, 0x563900
    cpu.ebx = 5650688 /*0x563900*/;
L_0x0049158a:
    // 0049158a  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0049158f  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 00491596  89942400040000         -mov dword ptr [esp + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.edx;
    // 0049159d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049159e  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004915a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004915a1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004915a3  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004915a6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004915a8  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
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
    // 004915af  0f84f0010000           -je 0x4917a5
    if (cpu.flags.zf)
    {
        goto L_0x004917a5;
    }
    // 004915b5  837b1000               +cmp dword ptr [ebx + 0x10], 0
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
    // 004915b9  0f843f010000           -je 0x4916fe
    if (cpu.flags.zf)
    {
        goto L_0x004916fe;
    }
    // 004915bf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004915c1  0f8c45010000           -jl 0x49170c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049170c;
    }
    // 004915c7  3b7308                 +cmp esi, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004915ca  7c02                   -jl 0x4915ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004915ce;
    }
    // 004915cc  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004915ce:
    // 004915ce  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004915d5  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004915d7  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004915da  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004915dd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004915df  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004915e2  89942488040000         -mov dword ptr [esp + 0x488], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */) = cpu.edx;
    // 004915e9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004915eb  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 004915ed  8a5012                 -mov dl, byte ptr [eax + 0x12]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004915f0  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004915f3  89942484040000         -mov dword ptr [esp + 0x484], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = cpu.edx;
    // 004915fa  8984247c040000         -mov dword ptr [esp + 0x47c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.eax;
L_0x00491601:
    // 00491601  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491605  7433                   -je 0x49163a
    if (cpu.flags.zf)
    {
        goto L_0x0049163a;
    }
    // 00491607  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0049160c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049160e  e8098affff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00491613  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00491615  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491616  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0049161b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049161d  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 00491620  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491622  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491624  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491625  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491628  66c783300400000000     -mov word ptr [ebx + 0x430], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 00491631  66c78332040000ff00     -mov word ptr [ebx + 0x432], 0xff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
L_0x0049163a:
    // 0049163a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049163c  8b8c2480040000         -mov ecx, dword ptr [esp + 0x480]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
    // 00491643  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491644  8b8c248c040000         -mov ecx, dword ptr [esp + 0x48c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1164) /* 0x48c */);
    // 0049164b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049164c  8b8c2494040000         -mov ecx, dword ptr [esp + 0x494]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1172) /* 0x494 */);
    // 00491653  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491654  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00491656  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491657  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491659  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049165a  ff5254                 -call dword ptr [edx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049165d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00491662  89842480040000         -mov dword ptr [esp + 0x480], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */) = cpu.eax;
    // 00491669  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 0049166e  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 00491675  89842400040000         -mov dword ptr [esp + 0x400], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.eax;
    // 0049167c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049167d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049167f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491680  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491682  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491685  8b94240c040000         -mov edx, dword ptr [esp + 0x40c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 0049168c  39d5                   +cmp ebp, edx
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
    // 0049168e  0f82a3000000           -jb 0x491737
    if (cpu.flags.cf)
    {
        goto L_0x00491737;
    }
    // 00491694  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00491697:
    // 00491697  8b842488040000         -mov eax, dword ptr [esp + 0x488]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */);
    // 0049169e  8b8c2408040000         -mov ecx, dword ptr [esp + 0x408]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 004916a5  39c8                   +cmp eax, ecx
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
    // 004916a7  0f82a3000000           -jb 0x491750
    if (cpu.flags.cf)
    {
        goto L_0x00491750;
    }
    // 004916ad  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004916b0:
    // 004916b0  83bc248004000000       +cmp dword ptr [esp + 0x480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004916b8  0f85b2000000           -jne 0x491770
    if (!cpu.flags.zf)
    {
        goto L_0x00491770;
    }
    // 004916be  8b842484040000         -mov eax, dword ptr [esp + 0x484]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */);
    // 004916c5  3b842454040000         +cmp eax, dword ptr [esp + 0x454]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004916cc  0f859e000000           -jne 0x491770
    if (!cpu.flags.zf)
    {
        goto L_0x00491770;
    }
    // 004916d2  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x004916d7:
    // 004916d7  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
    // 004916de  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004916e1  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 004916e6  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004916e9  2eff159c634c00         -call dword ptr cs:[0x4c639c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006236) /* 0x4c639c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004916f0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004916f2  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 004916f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004916fe:
    // 004916fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491700  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 00491706  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491707  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491708  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491709  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049170a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049170b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049170c:
    // 0049170c  bd80020000             -mov ebp, 0x280
    cpu.ebp = 640 /*0x280*/;
    // 00491711  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 00491716  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0049171b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049171d  89842488040000         -mov dword ptr [esp + 0x488], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */) = cpu.eax;
    // 00491724  89942484040000         -mov dword ptr [esp + 0x484], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = cpu.edx;
    // 0049172b  898c247c040000         -mov dword ptr [esp + 0x47c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.ecx;
    // 00491732  e9cafeffff             -jmp 0x491601
    goto L_0x00491601;
L_0x00491737:
    // 00491737  896b14                 -mov dword ptr [ebx + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0049173a  8b84240c040000         -mov eax, dword ptr [esp + 0x40c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 00491741  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00491743  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00491745  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0049174b  e947ffffff             -jmp 0x491697
    goto L_0x00491697;
L_0x00491750:
    // 00491750  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00491753  8bac2488040000         -mov ebp, dword ptr [esp + 0x488]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */);
    // 0049175a  8b842408040000         -mov eax, dword ptr [esp + 0x408]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 00491761  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00491763  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00491765  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 0049176b  e940ffffff             -jmp 0x4916b0
    goto L_0x004916b0;
L_0x00491770:
    // 00491770  81bc2480040000e1000000 +cmp dword ptr [esp + 0x480], 0xe1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(225 /*0xe1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049177b  750a                   -jne 0x491787
    if (!cpu.flags.zf)
    {
        goto L_0x00491787;
    }
    // 0049177d  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 00491782  e950ffffff             -jmp 0x4916d7
    goto L_0x004916d7;
L_0x00491787:
    // 00491787  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00491789  0f8548ffffff           -jne 0x4916d7
    if (!cpu.flags.zf)
    {
        goto L_0x004916d7;
    }
    // 0049178f  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00491796  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00491799  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049179b  804c820f80             +or byte ptr [edx + eax*4 + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 004917a0  e932ffffff             -jmp 0x4916d7
    goto L_0x004916d7;
L_0x004917a5:
    // 004917a5  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004917ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004917ad  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004917b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004917b4  2eff15e8634c00         -call dword ptr cs:[0x4c63e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006312) /* 0x4c63e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004917bb  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004917c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004917c3  8bbb54040000           -mov edi, dword ptr [ebx + 0x454]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004917c9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004917ca  2eff15c8634c00         -call dword ptr cs:[0x4c63c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006280) /* 0x4c63c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004917d1  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 004917d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004917d9  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004917df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004917e0  2eff15c8634c00         -call dword ptr cs:[0x4c63c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006280) /* 0x4c63c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004917e7  81bb6404000078ecffff   +cmp dword ptr [ebx + 0x464], 0xffffec78
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004917f1  7d1e                   -jge 0x491811
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491811;
    }
    // 004917f3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004917f5  2eff15f8634c00         -call dword ptr cs:[0x4c63f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006328) /* 0x4c63f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004917fc  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004917ff  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491801  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491803  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00491806  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00491808  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0049180a  8984246c040000         -mov dword ptr [esp + 0x46c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */) = cpu.eax;
L_0x00491811:
    // 00491811  81bb6804000078ecffff   +cmp dword ptr [ebx + 0x468], 0xffffec78
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049181b  7d1e                   -jge 0x49183b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049183b;
    }
    // 0049181d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049181f  2eff15f8634c00         -call dword ptr cs:[0x4c63f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006328) /* 0x4c63f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491826  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00491829  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049182b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049182d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00491830  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00491832  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00491834  89842470040000         -mov dword ptr [esp + 0x470], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */) = cpu.eax;
L_0x0049183b:
    // 0049183b  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 00491842  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00491845  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00491847  89842474040000         -mov dword ptr [esp + 0x474], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */) = cpu.eax;
    // 0049184e  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 00491855  034318                 -add eax, dword ptr [ebx + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 00491858  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049185a  8984247c040000         -mov dword ptr [esp + 0x47c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.eax;
    // 00491861  6af0                   -push -0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = -16 /*-0x10*/;
    cpu.esp -= 4;
    // 00491863  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00491869  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049186a  2eff15fc634c00         -call dword ptr cs:[0x4c63fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006332) /* 0x4c63fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491871  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491872  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 00491879  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049187a  2eff15b4634c00         -call dword ptr cs:[0x4c63b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006260) /* 0x4c63b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491881  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 00491888  8b942470040000         -mov edx, dword ptr [esp + 0x470]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0049188f  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 00491891  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00491893  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0049189a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049189b  8b84247c040000         -mov eax, dword ptr [esp + 0x47c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */);
    // 004918a2  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004918a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004918a6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004918a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004918a9  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004918af  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004918b0  2eff152c644c00         -call dword ptr cs:[0x4c642c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006380) /* 0x4c642c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004918b7  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004918be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004918bf  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004918c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004918c6  2eff15e8634c00         -call dword ptr cs:[0x4c63e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006312) /* 0x4c63e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004918cd  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004918d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004918d5  8bbb54040000           -mov edi, dword ptr [ebx + 0x454]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004918db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918dc  2eff15c8634c00         -call dword ptr cs:[0x4c63c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006280) /* 0x4c63c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004918e3  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 004918ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004918eb  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004918f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004918f2  2eff15c8634c00         -call dword ptr cs:[0x4c63c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006280) /* 0x4c63c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004918f9  8b842474040000         -mov eax, dword ptr [esp + 0x474]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 00491900  8b94246c040000         -mov edx, dword ptr [esp + 0x46c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 00491907  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00491909  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049190c  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 00491913  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0049191a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049191c  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049191f  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 00491926  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0049192c  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 00491933  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 00491939  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049193b  7520                   -jne 0x49195d
    if (!cpu.flags.zf)
    {
        goto L_0x0049195d;
    }
    // 0049193d  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
L_0x00491944:
    // 00491944  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00491947  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0049194c  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0049194f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491951  81c48c040000           +add esp, 0x48c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1164 /*0x48c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491957  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491958  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491959  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049195a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049195b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049195c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049195d:
    // 0049195d  a184ab4d00             -mov eax, dword ptr [0x4dab84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 00491962  ebe0                   -jmp 0x491944
    goto L_0x00491944;
}

/* align: skip  */
void Application::sub_491964(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491964);
    // 00491964  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491965  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491967  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491969  7505                   -jne 0x491970
    if (!cpu.flags.zf)
    {
        goto L_0x00491970;
    }
    // 0049196b  bb00395600             -mov ebx, 0x563900
    cpu.ebx = 5650688 /*0x563900*/;
L_0x00491970:
    // 00491970  833b00                 +cmp dword ptr [ebx], 0
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
    // 00491973  7450                   -je 0x4919c5
    if (cpu.flags.zf)
    {
        goto L_0x004919c5;
    }
    // 00491975  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491976  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491977  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0049197c  e8c785ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00491981  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491983  e890f6ffff             -call 0x491018
    cpu.esp -= 4;
    sub_491018(app, cpu);
    if (cpu.terminate) return;
    // 00491988  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049198a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049198b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049198d  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491990  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00491993  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00491995  7407                   -je 0x49199e
    if (cpu.flags.zf)
    {
        goto L_0x0049199e;
    }
    // 00491997  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00491999  e85e2fffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x0049199e:
    // 0049199e  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004919a5  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004919ac  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004919b3  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004919b8  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004919be  e89d85ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004919c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004919c5:
    // 004919c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4919c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004919c8);
    // 004919c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004919c9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004919ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004919cc  7505                   -jne 0x4919d3
    if (!cpu.flags.zf)
    {
        goto L_0x004919d3;
    }
    // 004919ce  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
L_0x004919d3:
    // 004919d3  8b9054040000           -mov edx, dword ptr [eax + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */);
    // 004919d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004919da  2eff1528644c00         -call dword ptr cs:[0x4c6428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006376) /* 0x4c6428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004919e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4919e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004919e4);
    // 004919e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004919e5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004919e6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004919eb  7505                   -jne 0x4919f2
    if (!cpu.flags.zf)
    {
        goto L_0x004919f2;
    }
    // 004919ed  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
L_0x004919f2:
    // 004919f2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004919f4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004919f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004919f7  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004919f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004919fa  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004919fd  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 00491a01  7509                   -jne 0x491a0c
    if (!cpu.flags.zf)
    {
        goto L_0x00491a0c;
    }
    // 00491a03  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00491a06  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491a09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a0b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491a0c:
    // 00491a0c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00491a11  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491a14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491a18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491a18);
    // 00491a18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491a19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491a1a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491a1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491a1e  7505                   -jne 0x491a25
    if (!cpu.flags.zf)
    {
        goto L_0x00491a25;
    }
    // 00491a20  b900395600             -mov ecx, 0x563900
    cpu.ecx = 5650688 /*0x563900*/;
L_0x00491a25:
    // 00491a25  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00491a27  e830030000             -call 0x491d5c
    cpu.esp -= 4;
    sub_491d5c(app, cpu);
    if (cpu.terminate) return;
    // 00491a2c  8b9944040000           -mov ebx, dword ptr [ecx + 0x444]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 00491a32  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00491a34  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491a36  7420                   -je 0x491a58
    if (cpu.flags.zf)
    {
        goto L_0x00491a58;
    }
    // 00491a38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00491a3d:
    // 00491a3d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491a3e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491a40  8b9144040000           -mov edx, dword ptr [ecx + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 00491a46  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491a47  ff532c                 -call dword ptr [ebx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491a4a  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 00491a4e  750c                   -jne 0x491a5c
    if (!cpu.flags.zf)
    {
        goto L_0x00491a5c;
    }
    // 00491a50  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491a55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491a58:
    // 00491a58  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00491a5a  ebe1                   -jmp 0x491a3d
    goto L_0x00491a3d;
L_0x00491a5c:
    // 00491a5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491a5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_491a64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491a64);
    // 00491a64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491a65  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491a66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491a68  7505                   -jne 0x491a6f
    if (!cpu.flags.zf)
    {
        goto L_0x00491a6f;
    }
    // 00491a6a  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
L_0x00491a6f:
    // 00491a6f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00491a71  8b8044040000           -mov eax, dword ptr [eax + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
    // 00491a77  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491a78  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491a7a  ff5248                 -call dword ptr [edx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491a7d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00491a82  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491a87  7408                   -je 0x491a91
    if (cpu.flags.zf)
    {
        goto L_0x00491a91;
    }
    // 00491a89  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491a8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491a91:
    // 00491a91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491a93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491a98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491a98);
    // 00491a98  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491a99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491a9a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491a9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491a9f  7505                   -jne 0x491aa6
    if (!cpu.flags.zf)
    {
        goto L_0x00491aa6;
    }
    // 00491aa1  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
L_0x00491aa6:
    // 00491aa6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00491aa8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00491aaa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491aab  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491aad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491aae  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491ab1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00491ab4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491ab7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ab8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ab9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491abc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491abc);
    // 00491abc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491abd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491abf  7505                   -jne 0x491ac6
    if (!cpu.flags.zf)
    {
        goto L_0x00491ac6;
    }
    // 00491ac1  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
L_0x00491ac6:
    // 00491ac6  83fa02                 +cmp edx, 2
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
    // 00491ac9  7512                   -jne 0x491add
    if (!cpu.flags.zf)
    {
        goto L_0x00491add;
    }
    // 00491acb  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00491ad0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491ad2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00491ad4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491ad5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491ad7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491ad8  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491adb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491adc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491add:
    // 00491add  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00491ae2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491ae4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00491ae6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491ae7  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491ae9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491aea  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491aed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491aee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491af0);
    // 00491af0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491af1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491af3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491af5  7505                   -jne 0x491afc
    if (!cpu.flags.zf)
    {
        goto L_0x00491afc;
    }
    // 00491af7  bb00395600             -mov ebx, 0x563900
    cpu.ebx = 5650688 /*0x563900*/;
L_0x00491afc:
    // 00491afc  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491b00  0f8476000000           -je 0x491b7c
    if (cpu.flags.zf)
    {
        goto L_0x00491b7c;
    }
    // 00491b06  837b1c08               +cmp dword ptr [ebx + 0x1c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491b0a  7f70                   -jg 0x491b7c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491b7c;
    }
    // 00491b0c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491b0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491b0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491b0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491b10  8b832e040000           -mov eax, dword ptr [ebx + 0x42e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1070) /* 0x42e */);
    // 00491b16  8b9330040000           -mov edx, dword ptr [ebx + 0x430]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1072) /* 0x430 */);
    // 00491b1c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00491b1f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00491b22  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00491b24  42                     -inc edx
    (cpu.edx)++;
    // 00491b25  3d00010000             +cmp eax, 0x100
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
    // 00491b2a  7d3a                   -jge 0x491b66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491b66;
    }
    // 00491b2c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491b2e  7e36                   -jle 0x491b66
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491b66;
    }
    // 00491b30  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00491b37  8d4b30                 -lea ecx, [ebx + 0x30]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 00491b3a  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00491b3c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491b3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491b3e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491b3f  8b4b24                 -mov ecx, dword ptr [ebx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 00491b42  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491b44  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00491b46  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491b47  ff5718                 -call dword ptr [edi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491b4a  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
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
    // 00491b51  7513                   -jne 0x491b66
    if (!cpu.flags.zf)
    {
        goto L_0x00491b66;
    }
    // 00491b53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491b54  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00491b59  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491b5b  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 00491b5e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491b60  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00491b62  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491b63  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00491b66:
    // 00491b66  66c783300400000001     -mov word ptr [ebx + 0x430], 0x100
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 00491b6f  66c78332040000ffff     -mov word ptr [ebx + 0x432], 0xffff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 00491b78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00491b7c:
    // 00491b7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491b80);
    // 00491b80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491b81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491b82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491b83  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00491b89  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491b8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491b8d  7505                   -jne 0x491b94
    if (!cpu.flags.zf)
    {
        goto L_0x00491b94;
    }
    // 00491b8f  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
L_0x00491b94:
    // 00491b94  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00491b97  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491b99  7454                   -je 0x491bef
    if (cpu.flags.zf)
    {
        goto L_0x00491bef;
    }
    // 00491b9b  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00491b9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491b9e  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00491ba3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491ba5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491ba7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491ba9  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491bab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491bac  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491baf  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00491bb1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00491bb3:
    // 00491bb3  0fb63484               -movzx esi, byte ptr [esp + eax*4]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 4));
    // 00491bb7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491bb9  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 00491bbc  8a5c8401               -mov bl, byte ptr [esp + eax*4 + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 4);
    // 00491bc0  81ce000000ff           -or esi, 0xff000000
    cpu.esi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00491bc6  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00491bc9  8a548402               -mov dl, byte ptr [esp + eax*4 + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 4);
    // 00491bcd  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491bcf  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491bd5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491bd8  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00491bda  40                     -inc eax
    (cpu.eax)++;
    // 00491bdb  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00491bde  3d00010000             +cmp eax, 0x100
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
    // 00491be3  7cce                   -jl 0x491bb3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491bb3;
    }
    // 00491be5  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00491beb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491bef:
    // 00491bef  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 00491bf4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491bf6  e82184ffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00491bfb  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00491c01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_491c08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491c08);
    // 00491c08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491c09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491c0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491c0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491c0c  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00491c0f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00491c11  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00491c13  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00491c15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491c17  7505                   -jne 0x491c1e
    if (!cpu.flags.zf)
    {
        goto L_0x00491c1e;
    }
    // 00491c19  be00395600             -mov esi, 0x563900
    cpu.esi = 5650688 /*0x563900*/;
L_0x00491c1e:
    // 00491c1e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00491c20  7408                   -je 0x491c2a
    if (cpu.flags.zf)
    {
        goto L_0x00491c2a;
    }
    // 00491c22  3bbe3c040000           +cmp edi, dword ptr [esi + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491c28  7429                   -je 0x491c53
    if (cpu.flags.zf)
    {
        goto L_0x00491c53;
    }
L_0x00491c2a:
    // 00491c2a  83be3c04000000         +cmp dword ptr [esi + 0x43c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491c31  7407                   -je 0x491c3a
    if (cpu.flags.zf)
    {
        goto L_0x00491c3a;
    }
    // 00491c33  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491c35  e822010000             -call 0x491d5c
    cpu.esp -= 4;
    sub_491d5c(app, cpu);
    if (cpu.terminate) return;
L_0x00491c3a:
    // 00491c3a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00491c3c  751c                   -jne 0x491c5a
    if (!cpu.flags.zf)
    {
        goto L_0x00491c5a;
    }
L_0x00491c3e:
    // 00491c3e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00491c40  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491c45  892ddcab4d00           -mov dword ptr [0x4dabdc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090268) /* 0x4dabdc */) = cpu.ebp;
L_0x00491c4b:
    // 00491c4b  83c46c                 +add esp, 0x6c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491c4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491c53:
    // 00491c53  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491c58  ebf1                   -jmp 0x491c4b
    goto L_0x00491c4b;
L_0x00491c5a:
    // 00491c5a  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 00491c5f  e8e482ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00491c64  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
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
    // 00491c6b  756c                   -jne 0x491cd9
    if (!cpu.flags.zf)
    {
        goto L_0x00491cd9;
    }
L_0x00491c6d:
    // 00491c6d  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00491c6f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00491c71  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491c73  e8c0eaffff             -call 0x490738
    cpu.esp -= 4;
    sub_490738(app, cpu);
    if (cpu.terminate) return;
    // 00491c78  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00491c7a:
    // 00491c7a  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491c81  a334bf4d00             -mov dword ptr [0x4dbf34], eax
    app->getMemory<x86::reg32>(x86::reg32(5095220) /* 0x4dbf34 */) = cpu.eax;
    // 00491c86  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491c88  745f                   -je 0x491ce9
    if (cpu.flags.zf)
    {
        goto L_0x00491ce9;
    }
    // 00491c8a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00491c8f  8b1530bf4d00           -mov edx, dword ptr [0x4dbf30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5095216) /* 0x4dbf30 */);
    // 00491c95  a328bf4d00             -mov dword ptr [0x4dbf28], eax
    app->getMemory<x86::reg32>(x86::reg32(5095208) /* 0x4dbf28 */) = cpu.eax;
    // 00491c9a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491c9c  7408                   -je 0x491ca6
    if (cpu.flags.zf)
    {
        goto L_0x00491ca6;
    }
    // 00491c9e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491ca0  890d30bf4d00           -mov dword ptr [0x4dbf30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5095216) /* 0x4dbf30 */) = cpu.ecx;
L_0x00491ca6:
    // 00491ca6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00491cab  c7864004000000000000   -mov dword ptr [esi + 0x440], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 00491cb5  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 00491cba  c7863c04000000000000   -mov dword ptr [esi + 0x43c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 00491cc4  e89782ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00491cc9  891ddcab4d00           -mov dword ptr [0x4dabdc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090268) /* 0x4dabdc */) = cpu.ebx;
    // 00491ccf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491cd1  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00491cd4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491cd5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491cd6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491cd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491cd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491cd9:
    // 00491cd9  e82a23ffff             -call 0x484008
    cpu.esp -= 4;
    sub_484008(app, cpu);
    if (cpu.terminate) return;
    // 00491cde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491ce0  758b                   -jne 0x491c6d
    if (!cpu.flags.zf)
    {
        goto L_0x00491c6d;
    }
    // 00491ce2  bbadcbea00             -mov ebx, 0xeacbad
    cpu.ebx = 15387565 /*0xeacbad*/;
    // 00491ce7  eb91                   -jmp 0x491c7a
    goto L_0x00491c7a;
L_0x00491ce9:
    // 00491ce9  833d30bf4d0000         +cmp dword ptr [0x4dbf30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095216) /* 0x4dbf30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491cf0  750a                   -jne 0x491cfc
    if (!cpu.flags.zf)
    {
        goto L_0x00491cfc;
    }
    // 00491cf2  c70530bf4d0001000000   -mov dword ptr [0x4dbf30], 1
    app->getMemory<x86::reg32>(x86::reg32(5095216) /* 0x4dbf30 */) = 1 /*0x1*/;
L_0x00491cfc:
    // 00491cfc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00491d00  898640040000           -mov dword ptr [esi + 0x440], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.eax;
    // 00491d06  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 00491d0c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00491d0e  0f842affffff           -je 0x491c3e
    if (cpu.flags.zf)
    {
        goto L_0x00491c3e;
    }
    // 00491d14  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00491d18  8a8e5d040000           -mov cl, byte ptr [esi + 0x45d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 00491d1e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00491d22  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00491d24  7529                   -jne 0x491d4f
    if (!cpu.flags.zf)
    {
        goto L_0x00491d4f;
    }
    // 00491d26  3bbe44040000           +cmp edi, dword ptr [esi + 0x444]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491d2c  7521                   -jne 0x491d4f
    if (!cpu.flags.zf)
    {
        goto L_0x00491d4f;
    }
    // 00491d2e  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00491d32  8b9e64040000           -mov ebx, dword ptr [esi + 0x464]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1124) /* 0x464 */);
    // 00491d38  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00491d3b  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00491d3e  8b8668040000           -mov eax, dword ptr [esi + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1128) /* 0x468 */);
    // 00491d44  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00491d47  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00491d4b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491d4d  01fb                   +add ebx, edi
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00491d4f:
    // 00491d4f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00491d51  e8deab0100             -call 0x4ac934
    cpu.esp -= 4;
    sub_4ac934(app, cpu);
    if (cpu.terminate) return;
    // 00491d56  e9e3feffff             -jmp 0x491c3e
    goto L_0x00491c3e;
}

/* align: skip 0x90 */
void Application::sub_491d5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491d5c);
    // 00491d5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491d5d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491d5e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491d5f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491d61  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491d63  7505                   -jne 0x491d6a
    if (!cpu.flags.zf)
    {
        goto L_0x00491d6a;
    }
    // 00491d65  bb00395600             -mov ebx, 0x563900
    cpu.ebx = 5650688 /*0x563900*/;
L_0x00491d6a:
    // 00491d6a  8b933c040000           -mov edx, dword ptr [ebx + 0x43c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */);
    // 00491d70  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491d72  750c                   -jne 0x491d80
    if (!cpu.flags.zf)
    {
        goto L_0x00491d80;
    }
    // 00491d74  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00491d76  8935dcab4d00           -mov dword ptr [0x4dabdc], esi
    app->getMemory<x86::reg32>(x86::reg32(5090268) /* 0x4dabdc */) = cpu.esi;
    // 00491d7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491d80:
    // 00491d80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491d81  8b8b40040000           -mov ecx, dword ptr [ebx + 0x440]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */);
    // 00491d87  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491d88  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491d8a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491d8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491d8d  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491d93  c7833c04000000000000   -mov dword ptr [ebx + 0x43c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 00491d9d  c7834004000000000000   -mov dword ptr [ebx + 0x440], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 00491da7  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491dae  8b1d34bf4d00           -mov ebx, dword ptr [0x4dbf34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5095220) /* 0x4dbf34 */);
    // 00491db4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491db6  8b1d2cbf4d00           -mov ebx, dword ptr [0x4dbf2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5095212) /* 0x4dbf2c */);
    // 00491dbc  a328bf4d00             -mov dword ptr [0x4dbf28], eax
    app->getMemory<x86::reg32>(x86::reg32(5095208) /* 0x4dbf28 */) = cpu.eax;
    // 00491dc1  39d8                   +cmp eax, ebx
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
    // 00491dc3  7e05                   -jle 0x491dca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491dca;
    }
    // 00491dc5  a32cbf4d00             -mov dword ptr [0x4dbf2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5095212) /* 0x4dbf2c */) = cpu.eax;
L_0x00491dca:
    // 00491dca  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 00491dcf  e88c81ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00491dd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491dd5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00491dd7  8935dcab4d00           -mov dword ptr [0x4dabdc], esi
    app->getMemory<x86::reg32>(x86::reg32(5090268) /* 0x4dabdc */) = cpu.esi;
    // 00491ddd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491dde  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ddf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491de0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_491de4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491de4);
    // 00491de4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491de5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491de6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491de7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491de8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491de9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491dea  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00491ded  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00491def  8b903c040000           -mov edx, dword ptr [eax + 0x43c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */);
    // 00491df5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491df7  750f                   -jne 0x491e08
    if (!cpu.flags.zf)
    {
        goto L_0x00491e08;
    }
    // 00491df9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491dfe  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00491e01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e06  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e07  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491e08:
    // 00491e08  8b8e40040000           -mov ecx, dword ptr [esi + 0x440]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */);
    // 00491e0e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491e0f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00491e11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491e12  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00491e14  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e1a  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e21  8b1d34bf4d00           -mov ebx, dword ptr [0x4dbf34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5095220) /* 0x4dbf34 */);
    // 00491e27  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491e29  8b1d2cbf4d00           -mov ebx, dword ptr [0x4dbf2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5095212) /* 0x4dbf2c */);
    // 00491e2f  a328bf4d00             -mov dword ptr [0x4dbf28], eax
    app->getMemory<x86::reg32>(x86::reg32(5095208) /* 0x4dbf28 */) = cpu.eax;
    // 00491e34  39d8                   +cmp eax, ebx
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
    // 00491e36  7e05                   -jle 0x491e3d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491e3d;
    }
    // 00491e38  a32cbf4d00             -mov dword ptr [0x4dbf2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5095212) /* 0x4dbf2c */) = cpu.eax;
L_0x00491e3d:
    // 00491e3d  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 00491e42  e81981ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00491e47  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 00491e4c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00491e4e  e8f580ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00491e53  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e5a  a334bf4d00             -mov dword ptr [0x4dbf34], eax
    app->getMemory<x86::reg32>(x86::reg32(5095220) /* 0x4dbf34 */) = cpu.eax;
    // 00491e5f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00491e61  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491e63  e8d0e8ffff             -call 0x490738
    cpu.esp -= 4;
    sub_490738(app, cpu);
    if (cpu.terminate) return;
    // 00491e68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491e6a  7516                   -jne 0x491e82
    if (!cpu.flags.zf)
    {
        goto L_0x00491e82;
    }
    // 00491e6c  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00491e70  3bae40040000           +cmp ebp, dword ptr [esi + 0x440]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491e76  743e                   -je 0x491eb6
    if (cpu.flags.zf)
    {
        goto L_0x00491eb6;
    }
    // 00491e78  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491e79  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00491e7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491e7c  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00491e82:
    // 00491e82  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491e84  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 00491e89  898e40040000           -mov dword ptr [esi + 0x440], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.ecx;
    // 00491e8f  890d28bf4d00           -mov dword ptr [0x4dbf28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5095208) /* 0x4dbf28 */) = cpu.ecx;
    // 00491e95  898e3c040000           -mov dword ptr [esi + 0x43c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.ecx;
    // 00491e9b  e8c080ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00491ea0  a1e4ab4d00             -mov eax, dword ptr [0x4dabe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090276) /* 0x4dabe4 */);
    // 00491ea5  e8fe06ffff             -call 0x4825a8
    cpu.esp -= 4;
    sub_4825a8(app, cpu);
    if (cpu.terminate) return;
    // 00491eaa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491eac  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00491eaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eb2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eb5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491eb6:
    // 00491eb6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491ebb  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 00491ec1  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00491ec4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ec5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ec6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ec7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ec8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ec9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491ecc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491ecc);
    // 00491ecc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491ecd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491ece  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491ecf  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00491ed2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491ed4  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00491ed6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491ed8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491eda  e859e8ffff             -call 0x490738
    cpu.esp -= 4;
    sub_490738(app, cpu);
    if (cpu.terminate) return;
    // 00491edf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491ee1  7507                   -jne 0x491eea
    if (!cpu.flags.zf)
    {
        goto L_0x00491eea;
    }
    // 00491ee3  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00491ee6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ee7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ee8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ee9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491eea:
    // 00491eea  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00491eee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491eef  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00491ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491ef2  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491ef8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491efd  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00491f00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491f04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00491f04);
    // 00491f04  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491f05  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491f06  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491f07  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00491f0a  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00491f11  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00491f13  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00491f15  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00491f17  8b9c2494000000         -mov ebx, dword ptr [esp + 0x94]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00491f1e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00491f20  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491f22  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00491f26  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00491f2a  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 00491f2f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00491f31  e8e680ffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00491f36  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 00491f3b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00491f40  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00491f43  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00491f47  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00491f49  7e10                   -jle 0x491f5b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491f5b;
    }
    // 00491f4b  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 00491f50  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00491f54  80cb18                 -or bl, 0x18
    cpu.bl |= x86::reg8(x86::sreg8(24 /*0x18*/));
    // 00491f57  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00491f5b:
    // 00491f5b  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00491f5e  7443                   -je 0x491fa3
    if (cpu.flags.zf)
    {
        goto L_0x00491fa3;
    }
L_0x00491f60:
    // 00491f60  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491f62  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00491f66  895c246c               -mov dword ptr [esp + 0x6c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 00491f6a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491f6b  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00491f6f  8b9c2480000000         -mov ebx, dword ptr [esp + 0x80]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00491f76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491f77  8bac2484000000         -mov ebp, dword ptr [esp + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00491f7e  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00491f80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491f81  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491f84  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00491f89  0f8548010000           -jne 0x4920d7
    if (!cpu.flags.zf)
    {
        goto L_0x004920d7;
    }
    // 00491f8f  837c247400             +cmp dword ptr [esp + 0x74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491f94  755c                   -jne 0x491ff2
    if (!cpu.flags.zf)
    {
        goto L_0x00491ff2;
    }
    // 00491f96  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00491f9a  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00491f9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491fa0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00491fa3:
    // 00491fa3  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00491fa6  75b8                   -jne 0x491f60
    if (!cpu.flags.zf)
    {
        goto L_0x00491f60;
    }
    // 00491fa8  8a642404               -mov ah, byte ptr [esp + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491fac  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00491fb3  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00491fb7  80cc06                 -or ah, 6
    cpu.ah |= x86::reg8(x86::sreg8(6 /*0x6*/));
    // 00491fba  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00491fbe  88642404               -mov byte ptr [esp + 4], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 00491fc2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491fc4  7f9a                   -jg 0x491f60
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491f60;
    }
    // 00491fc6  7598                   -jne 0x491f60
    if (!cpu.flags.zf)
    {
        goto L_0x00491f60;
    }
    // 00491fc8  8a542405               -mov dl, byte ptr [esp + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 00491fcc  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 00491fd1  8d6c2448               -lea ebp, [esp + 0x48]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00491fd5  80ca10                 +or dl, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00491fd8  897c2448               -mov dword ptr [esp + 0x48], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edi;
    // 00491fdc  88542405               -mov byte ptr [esp + 5], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00491fe0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491fe1  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00491fe7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491fe8  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00491fea  ff5754                 -call dword ptr [edi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491fed  e96effffff             -jmp 0x491f60
    goto L_0x00491f60;
L_0x00491ff2:
    // 00491ff2  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 00491ff7  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00491ff9  e84a7fffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00491ffe  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00492002  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492004  e82fe7ffff             -call 0x490738
    cpu.esp -= 4;
    sub_490738(app, cpu);
    if (cpu.terminate) return;
    // 00492009  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049200b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049200d  7516                   -jne 0x492025
    if (!cpu.flags.zf)
    {
        goto L_0x00492025;
    }
    // 0049200f  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492013  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00492017  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492018  8b7c2478               -mov edi, dword ptr [esp + 0x78]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049201c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049201e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049201f  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00492025:
    // 00492025  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0049202a  e8317fffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049202f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492031  0f8585000000           -jne 0x4920bc
    if (!cpu.flags.zf)
    {
        goto L_0x004920bc;
    }
L_0x00492037:
    // 00492037  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0049203c  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00492040  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00492043  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00492045  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492047  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492048  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049204c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049204d  ff5358                 -call dword ptr [ebx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492050  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00492055  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00492059  895c2448               -mov dword ptr [esp + 0x48], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ebx;
    // 0049205d  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049205f  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00492063  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492064  8b742478               -mov esi, dword ptr [esp + 0x78]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00492068  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492069  ff5354                 -call dword ptr [ebx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049206c  837c245408             +cmp dword ptr [esp + 0x54], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492071  7777                   -ja 0x4920ea
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004920ea;
    }
    // 00492073  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00492078  8b9c2498000000         -mov ebx, dword ptr [esp + 0x98]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0049207f  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 00492083  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 00492087  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492089  740f                   -je 0x49209a
    if (cpu.flags.zf)
    {
        goto L_0x0049209a;
    }
    // 0049208b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049208c  8b7c2478               -mov edi, dword ptr [esp + 0x78]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00492090  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00492094  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492095  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492097  ff507c                 -call dword ptr [eax + 0x7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049209a:
    // 0049209a  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0049209e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004920a0  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004920a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004920a5  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004920a7  8b6c247c               -mov ebp, dword ptr [esp + 0x7c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004920ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004920ac  ff5374                 -call dword ptr [ebx + 0x74]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(116) /* 0x74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004920af  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004920b3  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004920b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920b9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004920bc:
    // 004920bc  80be5f04000000         +cmp byte ptr [esi + 0x45f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004920c3  0f856effffff           -jne 0x492037
    if (!cpu.flags.zf)
    {
        goto L_0x00492037;
    }
    // 004920c9  8b6c2474               -mov ebp, dword ptr [esp + 0x74]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004920cd  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004920d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004920d2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004920d4  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004920d7:
    // 004920d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004920d9  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 004920dd  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004920e1  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004920e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920e7  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004920ea:
    // 004920ea  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004920ec  896c246c               -mov dword ptr [esp + 0x6c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebp;
    // 004920f0  896c2470               -mov dword ptr [esp + 0x70], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 004920f4  eba4                   -jmp 0x49209a
    goto L_0x0049209a;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4920f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004920f8);
    // 004920f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004920f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004920fb  7505                   -jne 0x492102
    if (!cpu.flags.zf)
    {
        goto L_0x00492102;
    }
    // 004920fd  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
L_0x00492102:
    // 00492102  3b903c040000           +cmp edx, dword ptr [eax + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492108  7408                   -je 0x492112
    if (cpu.flags.zf)
    {
        goto L_0x00492112;
    }
    // 0049210a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049210b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049210d  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492110  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492111  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492112:
    // 00492112  e845fcffff             -call 0x491d5c
    cpu.esp -= 4;
    sub_491d5c(app, cpu);
    if (cpu.terminate) return;
    // 00492117  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492118  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049211a  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049211d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049211e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_492120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492120);
    // 00492120  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492121  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492122  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492123  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00492125  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492128  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492129  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049212a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49212c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049212c);
    // 0049212c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049212d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049212e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492131  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00492133  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00492136  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00492138  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049213d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049213e  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492142  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00492146  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492147  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00492149  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049214a  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049214d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00492150  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492153  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492154  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492155  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492158(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492158);
    // 00492158  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492159  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049215a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049215d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049215f  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00492162  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00492164  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00492169  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049216a  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049216e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00492172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492173  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00492175  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492176  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492179  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049217c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049217f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492180  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492181  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492184(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492184);
    // 00492184  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492185  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492186  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492189  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049218b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049218e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00492190  b900000200             -mov ecx, 0x20000
    cpu.ecx = 131072 /*0x20000*/;
    // 00492195  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492196  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049219a  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049219e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049219f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004921a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004921a2  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004921a5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004921a8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004921ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4921b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004921b0);
    // 004921b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004921b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004921b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004921b3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004921b5:
    // 004921b5  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004921b7  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004921b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004921ba  ff5034                 -call dword ptr [eax + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004921bd  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004921c2  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004921c7  74ec                   -je 0x4921b5
    if (cpu.flags.zf)
    {
        goto L_0x004921b5;
    }
    // 004921c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4921d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004921d0);
    // 004921d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004921d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004921d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004921d3  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004921d6  8bac2480000000         -mov ebp, dword ptr [esp + 0x80]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004921dd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004921df  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004921e1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004921e3  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004921e5  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 004921ea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004921eb  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004921ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004921f0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004921f2  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004921f5  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004921f9  0f8575000000           -jne 0x492274
    if (!cpu.flags.zf)
    {
        goto L_0x00492274;
    }
    // 004921ff  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00492201  7406                   -je 0x492209
    if (cpu.flags.zf)
    {
        goto L_0x00492209;
    }
    // 00492203  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492207  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00492209:
    // 00492209  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049220b  7406                   -je 0x492213
    if (cpu.flags.zf)
    {
        goto L_0x00492213;
    }
    // 0049220d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492211  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00492213:
    // 00492213  8b74247c               -mov esi, dword ptr [esp + 0x7c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00492217  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00492219  7406                   -je 0x492221
    if (cpu.flags.zf)
    {
        goto L_0x00492221;
    }
    // 0049221b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049221f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00492221:
    // 00492221  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00492223  7407                   -je 0x49222c
    if (cpu.flags.zf)
    {
        goto L_0x0049222c;
    }
    // 00492225  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492229  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x0049222c:
    // 0049222c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049222e  740f                   -je 0x49223f
    if (cpu.flags.zf)
    {
        goto L_0x0049223f;
    }
    // 00492230  837c245410             +cmp dword ptr [esp + 0x54], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492235  7411                   -je 0x492248
    if (cpu.flags.zf)
    {
        goto L_0x00492248;
    }
    // 00492237  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492239  8a442454               -mov al, byte ptr [esp + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049223d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0049223f:
    // 0049223f  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00492242  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492243  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492244  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492245  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492248:
    // 00492248  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049224c  e893e6ffff             -call 0x4908e4
    cpu.esp -= 4;
    sub_4908e4(app, cpu);
    if (cpu.terminate) return;
    // 00492251  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492253  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00492257  e888e6ffff             -call 0x4908e4
    cpu.esp -= 4;
    sub_4908e4(app, cpu);
    if (cpu.terminate) return;
    // 0049225c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049225e  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00492262  e87de6ffff             -call 0x4908e4
    cpu.esp -= 4;
    sub_4908e4(app, cpu);
    if (cpu.terminate) return;
    // 00492267  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492269  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 0049226b  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049226e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049226f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492270  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492271  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492274:
    // 00492274  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00492276  7406                   -je 0x49227e
    if (cpu.flags.zf)
    {
        goto L_0x0049227e;
    }
    // 00492278  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0049227e:
    // 0049227e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00492280  7406                   -je 0x492288
    if (cpu.flags.zf)
    {
        goto L_0x00492288;
    }
    // 00492282  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x00492288:
    // 00492288  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049228a  7406                   -je 0x492292
    if (cpu.flags.zf)
    {
        goto L_0x00492292;
    }
    // 0049228c  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
L_0x00492292:
    // 00492292  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00492296  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00492298  7406                   -je 0x4922a0
    if (cpu.flags.zf)
    {
        goto L_0x004922a0;
    }
    // 0049229a  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x004922a0:
    // 004922a0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004922a2  749b                   -je 0x49223f
    if (cpu.flags.zf)
    {
        goto L_0x0049223f;
    }
    // 004922a4  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 004922ab  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004922ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922b1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4922b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004922b4);
    // 004922b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004922b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004922b6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004922b9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004922bb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004922bc  6808284e00             -push 0x4e2808
    app->getMemory<x86::reg32>(cpu.esp-4) = 5122056 /*0x4e2808*/;
    cpu.esp -= 4;
    // 004922c1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004922c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004922c4  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922c6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004922c9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004922cb  7506                   -jne 0x4922d3
    if (!cpu.flags.zf)
    {
        goto L_0x004922d3;
    }
    // 004922cd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004922d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004922d3:
    // 004922d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004922d4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004922d6  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004922d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004922d9  ff9094000000           -call dword ptr [eax + 0x94]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922df  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004922e3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004922e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004922e8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004922ea  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004922ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922ee  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004922f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4922f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004922f4);
    // 004922f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004922f5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004922f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004922f9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004922fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004922fc  6808284e00             -push 0x4e2808
    app->getMemory<x86::reg32>(cpu.esp-4) = 5122056 /*0x4e2808*/;
    cpu.esp -= 4;
    // 00492301  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00492303  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492304  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492306  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00492309  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049230b  7506                   -jne 0x492313
    if (!cpu.flags.zf)
    {
        goto L_0x00492313;
    }
    // 0049230d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492310  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492311  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492312  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492313:
    // 00492313  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492314  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492316  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00492318  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492319  ff9098000000           -call dword ptr [eax + 0x98]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049231f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00492323  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00492327  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492328  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049232a  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049232d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049232e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492331  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492332  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492333  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_492334(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492334);
    // 00492334  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492335  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492336  83ec74                 -sub esp, 0x74
    (cpu.esp) -= x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00492339  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049233b  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 00492340  8b842484000000         -mov eax, dword ptr [esp + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00492347  895c2468               -mov dword ptr [esp + 0x68], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 0049234b  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0049234f  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00492353  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00492355  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0049235c  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 00492360  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00492362  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00492366  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 0049236a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049236c  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0049236f  e828e5ffff             -call 0x49089c
    cpu.esp -= 4;
    sub_49089c(app, cpu);
    if (cpu.terminate) return;
    // 00492374  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492376  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492377  6800040001             -push 0x1000400
    app->getMemory<x86::reg32>(cpu.esp-4) = 16778240 /*0x1000400*/;
    cpu.esp -= 4;
    // 0049237c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049237e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492380  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00492384  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492385  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00492387  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492388  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049238b  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0049238f  750d                   -jne 0x49239e
    if (!cpu.flags.zf)
    {
        goto L_0x0049239e;
    }
    // 00492391  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492396  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00492399  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049239a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049239b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049239e:
    // 0049239e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004923a0  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 004923a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004923a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004923a5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4923a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004923a8);
    // 004923a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004923a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004923aa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004923ab  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004923b1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004923b3  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004923b5  898c2484000000         -mov dword ptr [esp + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 004923bc  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004923c3  8bac249c000000         -mov ebp, dword ptr [esp + 0x9c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 004923ca  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 004923ce  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004923d0  8bbc2484000000         -mov edi, dword ptr [esp + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004923d7  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 004923db  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004923dd  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004923e4  897c246c               -mov dword ptr [esp + 0x6c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edi;
    // 004923e8  89542478               -mov dword ptr [esp + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 004923ec  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004923f3  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004923fa  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004923fe  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00492405  896c2470               -mov dword ptr [esp + 0x70], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 00492409  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049240b  8bac24ac000000         -mov ebp, dword ptr [esp + 0xac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00492412  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 00492419  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00492420  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492422  bb00000001             -mov ebx, 0x1000000
    cpu.ebx = 16777216 /*0x1000000*/;
    // 00492427  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0049242b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049242d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049242f  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00492432  898c2488000000         -mov dword ptr [esp + 0x88], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ecx;
    // 00492439  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049243c  0f859f000000           -jne 0x4924e1
    if (!cpu.flags.zf)
    {
        goto L_0x004924e1;
    }
    // 00492442  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
L_0x00492447:
    // 00492447  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00492449  7403                   -je 0x49244e
    if (cpu.flags.zf)
    {
        goto L_0x0049244e;
    }
    // 0049244b  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0049244e:
    // 0049244e  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00492450  7403                   -je 0x492455
    if (cpu.flags.zf)
    {
        goto L_0x00492455;
    }
    // 00492452  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00492455:
    // 00492455  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00492457  7403                   -je 0x49245c
    if (cpu.flags.zf)
    {
        goto L_0x0049245c;
    }
    // 00492459  80cf80                 -or bh, 0x80
    cpu.bh |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0049245c:
    // 0049245c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049245e  7424                   -je 0x492484
    if (cpu.flags.zf)
    {
        goto L_0x00492484;
    }
    // 00492460  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00492465  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492467  e8b07bffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0049246c  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00492471  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00492474  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00492477  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492479  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049247d  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
L_0x00492484:
    // 00492484  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00492488  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049248a  e80de4ffff             -call 0x49089c
    cpu.esp -= 4;
    sub_49089c(app, cpu);
    if (cpu.terminate) return;
    // 0049248f  8d542474               -lea edx, [esp + 0x74]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00492493  8b8424a0000000         -mov eax, dword ptr [esp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0049249a  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 004924a1  e8f6e3ffff             -call 0x49089c
    cpu.esp -= 4;
    sub_49089c(app, cpu);
    if (cpu.terminate) return;
    // 004924a6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004924a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004924a8  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004924ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004924ad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004924ae  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004924b5  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004924bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004924bd  8b9c24b4000000         -mov ebx, dword ptr [esp + 0xb4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004924c4  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004924c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004924c7  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004924ca  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004924ce  7531                   -jne 0x492501
    if (!cpu.flags.zf)
    {
        goto L_0x00492501;
    }
    // 004924d0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004924d5  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004924db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924de  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x004924e1:
    // 004924e1  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004924e3  740a                   -je 0x4924ef
    if (cpu.flags.zf)
    {
        goto L_0x004924ef;
    }
    // 004924e5  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004924ea  e958ffffff             -jmp 0x492447
    goto L_0x00492447;
L_0x004924ef:
    // 004924ef  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004924f1  0f8450ffffff           -je 0x492447
    if (cpu.flags.zf)
    {
        goto L_0x00492447;
    }
    // 004924f7  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 004924fc  e946ffffff             -jmp 0x492447
    goto L_0x00492447;
L_0x00492501:
    // 00492501  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492503  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00492509  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049250a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049250b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049250c  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_492510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492510);
    // 00492510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492511  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492512  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492513  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00492516  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049251a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049251e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00492520  be10064900             -mov esi, 0x490610
    cpu.esi = 4785680 /*0x490610*/;
    // 00492525  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492529  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049252a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049252b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049252c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049252d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049252f  7502                   -jne 0x492533
    if (!cpu.flags.zf)
    {
        goto L_0x00492533;
    }
    // 00492531  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00492533:
    // 00492533  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492537  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492539  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049253e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00492541  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492542  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492543  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492544  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_492548(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492548);
    // 00492548  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492549  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049254a  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049254e  8b5354                 -mov edx, dword ptr [ebx + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 00492551  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492555  83fa10                 +cmp edx, 0x10
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
    // 00492558  744a                   -je 0x4925a4
    if (cpu.flags.zf)
    {
        goto L_0x004925a4;
    }
    // 0049255a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049255c  8a4354                 -mov al, byte ptr [ebx + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
L_0x0049255f:
    // 0049255f  83f810                 +cmp eax, 0x10
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
    // 00492562  7360                   -jae 0x4925c4
    if (!cpu.flags.cf)
    {
        goto L_0x004925c4;
    }
    // 00492564  83f808                 +cmp eax, 8
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
    // 00492567  0f8380000000           -jae 0x4925ed
    if (!cpu.flags.cf)
    {
        goto L_0x004925ed;
    }
L_0x0049256d:
    // 0049256d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049256f  7429                   -je 0x49259a
    if (cpu.flags.zf)
    {
        goto L_0x0049259a;
    }
    // 00492571  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492575  0f8495000000           -je 0x492610
    if (cpu.flags.zf)
    {
        goto L_0x00492610;
    }
    // 0049257b  a158455600             -mov eax, dword ptr [0x564558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653848) /* 0x564558 */);
    // 00492580  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492583  0f8d87000000           -jge 0x492610
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492610;
    }
    // 00492589  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049258b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049258d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049258f  e870e3ffff             -call 0x490904
    cpu.esp -= 4;
    sub_490904(app, cpu);
    if (cpu.terminate) return;
L_0x00492594:
    // 00492594  ff0558455600           -inc dword ptr [0x564558]
    (app->getMemory<x86::reg32>(x86::reg32(5653848) /* 0x564558 */))++;
L_0x0049259a:
    // 0049259a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049259f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004925a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004925a1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004925a4:
    // 004925a4  8b4358                 -mov eax, dword ptr [ebx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 004925a7  e838e3ffff             -call 0x4908e4
    cpu.esp -= 4;
    sub_4908e4(app, cpu);
    if (cpu.terminate) return;
    // 004925ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004925ae  8b435c                 -mov eax, dword ptr [ebx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 004925b1  e82ee3ffff             -call 0x4908e4
    cpu.esp -= 4;
    sub_4908e4(app, cpu);
    if (cpu.terminate) return;
    // 004925b6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004925b8  8b4360                 -mov eax, dword ptr [ebx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 004925bb  e824e3ffff             -call 0x4908e4
    cpu.esp -= 4;
    sub_4908e4(app, cpu);
    if (cpu.terminate) return;
    // 004925c0  01d0                   +add eax, edx
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
    // 004925c2  eb9b                   -jmp 0x49255f
    goto L_0x0049255f;
L_0x004925c4:
    // 004925c4  7709                   -ja 0x4925cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004925cf;
    }
    // 004925c6  800d5045560004         +or byte ptr [0x564550], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5653840) /* 0x564550 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004925cd  eb9e                   -jmp 0x49256d
    goto L_0x0049256d;
L_0x004925cf:
    // 004925cf  83f818                 +cmp eax, 0x18
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
    // 004925d2  7299                   -jb 0x49256d
    if (cpu.flags.cf)
    {
        goto L_0x0049256d;
    }
    // 004925d4  7709                   -ja 0x4925df
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004925df;
    }
    // 004925d6  800d5045560008         +or byte ptr [0x564550], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5653840) /* 0x564550 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004925dd  eb8e                   -jmp 0x49256d
    goto L_0x0049256d;
L_0x004925df:
    // 004925df  83f820                 +cmp eax, 0x20
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
    // 004925e2  7589                   -jne 0x49256d
    if (!cpu.flags.zf)
    {
        goto L_0x0049256d;
    }
    // 004925e4  800d5045560010         +or byte ptr [0x564550], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5653840) /* 0x564550 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004925eb  eb80                   -jmp 0x49256d
    goto L_0x0049256d;
L_0x004925ed:
    // 004925ed  770c                   -ja 0x4925fb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004925fb;
    }
    // 004925ef  800d5045560001         +or byte ptr [0x564550], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5653840) /* 0x564550 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004925f6  e972ffffff             -jmp 0x49256d
    goto L_0x0049256d;
L_0x004925fb:
    // 004925fb  83f80f                 +cmp eax, 0xf
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
    // 004925fe  0f8569ffffff           -jne 0x49256d
    if (!cpu.flags.zf)
    {
        goto L_0x0049256d;
    }
    // 00492604  800d5045560002         +or byte ptr [0x564550], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5653840) /* 0x564550 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0049260b  e95dffffff             -jmp 0x49256d
    goto L_0x0049256d;
L_0x00492610:
    // 00492610  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492614  0f847affffff           -je 0x492594
    if (cpu.flags.zf)
    {
        goto L_0x00492594;
    }
    // 0049261a  a158455600             -mov eax, dword ptr [0x564558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653848) /* 0x564558 */);
    // 0049261f  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492622  0f8c6cffffff           -jl 0x492594
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492594;
    }
    // 00492628  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049262a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049262b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049262c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_49262f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049262f);
    // 0049262f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492630  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00492632  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492633  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 00492635  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00492638  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 0049263a  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049263d  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 0049263f  e88ca40100             -call 0x4acad0
    cpu.esp -= 4;
    sub_4acad0(app, cpu);
    if (cpu.terminate) return;
    // 00492644  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492645  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492646  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_492650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492650);
    // 00492650  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492651  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492652  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492653  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00492656  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049265a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049265c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00492660  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492662  7444                   -je 0x4926a8
    if (cpu.flags.zf)
    {
        goto L_0x004926a8;
    }
L_0x00492664:
    // 00492664  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00492668  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049266a  7547                   -jne 0x4926b3
    if (!cpu.flags.zf)
    {
        goto L_0x004926b3;
    }
    // 0049266c  c744241c08000000       -mov dword ptr [esp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
L_0x00492674:
    // 00492674  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x00492678:
    // 00492678  a114d34d00             -mov eax, dword ptr [0x4dd314]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */);
    // 0049267d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049267f  741e                   -je 0x49269f
    if (cpu.flags.zf)
    {
        goto L_0x0049269f;
    }
    // 00492681  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492685  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492687  7c14                   -jl 0x49269d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049269d;
    }
    // 00492689  81fa00400000           +cmp edx, 0x4000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049268f  7f0c                   -jg 0x49269d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049269d;
    }
    // 00492691  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00492693  7c08                   -jl 0x49269d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049269d;
    }
    // 00492695  81ff00200000           +cmp edi, 0x2000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049269b  7e22                   -jle 0x4926bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004926bf;
    }
L_0x0049269d:
    // 0049269d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049269f:
    // 0049269f  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004926a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004926a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004926a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004926a5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004926a8:
    // 004926a8  a184ab4d00             -mov eax, dword ptr [0x4dab84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 004926ad  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004926b1  ebb1                   -jmp 0x492664
    goto L_0x00492664;
L_0x004926b3:
    // 004926b3  83fb0f                 +cmp ebx, 0xf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004926b6  75bc                   -jne 0x492674
    if (!cpu.flags.zf)
    {
        goto L_0x00492674;
    }
    // 004926b8  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 004926bd  ebb9                   -jmp 0x492678
    goto L_0x00492678;
L_0x004926bf:
    // 004926bf  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004926c3  e8b8a40100             -call 0x4acb80
    cpu.esp -= 4;
    sub_4acb80(app, cpu);
    if (cpu.terminate) return;
    // 004926c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004926ca  74d3                   -je 0x49269f
    if (cpu.flags.zf)
    {
        goto L_0x0049269f;
    }
    // 004926cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004926ce  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004926d1  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004926d4  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004926d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004926d8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004926db  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004926dd  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004926e0  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004926e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004926e5  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004926e8  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004926ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004926ed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004926ee  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004926f2  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004926f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004926f7  68dc044d00             -push 0x4d04dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047516 /*0x4d04dc*/;
    cpu.esp -= 4;
    // 004926fc  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492700  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492701  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492703  e8f93dffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00492708  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049270b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049270d  83c248                 -add edx, 0x48
    (cpu.edx) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00492710  e8771dffff             -call 0x48448c
    cpu.esp -= 4;
    sub_48448c(app, cpu);
    if (cpu.terminate) return;
    // 00492715  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00492719  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049271b  7521                   -jne 0x49273e
    if (!cpu.flags.zf)
    {
        goto L_0x0049273e;
    }
    // 0049271d  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 00492722  0f8475ffffff           -je 0x49269d
    if (cpu.flags.zf)
    {
        goto L_0x0049269d;
    }
    // 00492728  ff05f4ab4d00           -inc dword ptr [0x4dabf4]
    (app->getMemory<x86::reg32>(x86::reg32(5090292) /* 0x4dabf4 */))++;
    // 0049272e  e80924ffff             -call 0x484b3c
    cpu.esp -= 4;
    sub_484b3c(app, cpu);
    if (cpu.terminate) return;
    // 00492733  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492735  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00492738  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492739  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049273a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049273b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049273e:
    // 0049273e  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00492740  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00492742  0f8455ffffff           -je 0x49269d
    if (cpu.flags.zf)
    {
        goto L_0x0049269d;
    }
    // 00492748  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 0049274d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049274f  e8c878ffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00492754  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00492758  8d5638                 -lea edx, [esi + 0x38]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0049275b  e820a40100             -call 0x4acb80
    cpu.esp -= 4;
    sub_4acb80(app, cpu);
    if (cpu.terminate) return;
    // 00492760  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00492763  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492768  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049276a  66897a06               -mov word ptr [edx + 6], di
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = cpu.di;
    // 0049276e  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00492770  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492774  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00492776  66894204               -mov word ptr [edx + 4], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0049277a  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 00492780  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00492783  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492787  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0049278a  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049278d  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492791  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00492794  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00492797  8a44241c               -mov al, byte ptr [esp + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049279b  88461c                 -mov byte ptr [esi + 0x1c], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.al;
    // 0049279e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004927a0  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004927a2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004927a4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004927a9  895620                 -mov dword ptr [esi + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004927ac  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004927b0  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 004927b3  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004927b8  e8b7890000             -call 0x49b174
    cpu.esp -= 4;
    sub_49b174(app, cpu);
    if (cpu.terminate) return;
    // 004927bd  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004927c1  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004927c6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004927c8  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004927cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004927cd  e8a2890000             -call 0x49b174
    cpu.esp -= 4;
    sub_49b174(app, cpu);
    if (cpu.terminate) return;
    // 004927d2  8b5e2c                 -mov ebx, dword ptr [esi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004927d5  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004927d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004927da  0f84bdfeffff           -je 0x49269d
    if (cpu.flags.zf)
    {
        goto L_0x0049269d;
    }
    // 004927e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004927e2  0f84b5feffff           -je 0x49269d
    if (cpu.flags.zf)
    {
        goto L_0x0049269d;
    }
    // 004927e8  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004927ec  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004927ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927f2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4927f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004927f8);
    // 004927f8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004927fa  e851feffff             -call 0x492650
    cpu.esp -= 4;
    sub_492650(app, cpu);
    if (cpu.terminate) return;
    // 004927ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_492800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492800);
    // 00492800  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00492802  e849feffff             -call 0x492650
    cpu.esp -= 4;
    sub_492650(app, cpu);
    if (cpu.terminate) return;
    // 00492807  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_492808(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492808);
    // 00492808  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492809  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049280d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049280e  e83dfeffff             -call 0x492650
    cpu.esp -= 4;
    sub_492650(app, cpu);
    if (cpu.terminate) return;
    // 00492813  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492815  7402                   -je 0x492819
    if (cpu.flags.zf)
    {
        goto L_0x00492819;
    }
    // 00492817  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00492819:
    // 00492819  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049281a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492820);
    // 00492820  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00492822  e829feffff             -call 0x492650
    cpu.esp -= 4;
    sub_492650(app, cpu);
    if (cpu.terminate) return;
    // 00492827  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492829  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49282c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049282c);
    // 0049282c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049282e  e81dfeffff             -call 0x492650
    cpu.esp -= 4;
    sub_492650(app, cpu);
    if (cpu.terminate) return;
    // 00492833  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492835  7402                   -je 0x492839
    if (cpu.flags.zf)
    {
        goto L_0x00492839;
    }
    // 00492837  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00492839:
    // 00492839  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_492840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492840);
    // 00492840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492842  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492843  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492844  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492846  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0049284d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049284f:
    // 0049284f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00492851  8d4b20                 -lea ecx, [ebx + 0x20]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(32) /* 0x20 */);
L_0x00492854:
    // 00492854  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492857  8b15ec294e00           -mov edx, dword ptr [0x4e29ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5122540) /* 0x4e29ec */);
    // 0049285d  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00492860  39c8                   +cmp eax, ecx
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
    // 00492862  75f0                   -jne 0x492854
    if (!cpu.flags.zf)
    {
        goto L_0x00492854;
    }
    // 00492864  46                     -inc esi
    (cpu.esi)++;
    // 00492865  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492867  83fe08                 +cmp esi, 8
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
    // 0049286a  7ce3                   -jl 0x49284f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049284f;
    }
    // 0049286c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049286d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049286e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049286f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492870  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492874(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492874);
    // 00492874  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492875  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492876  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492877  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492878  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049287b  b880ffffff             -mov eax, 0xffffff80
    cpu.eax = 4294967168 /*0xffffff80*/;
    // 00492880  b9c0ffffff             -mov ecx, 0xffffffc0
    cpu.ecx = 4294967232 /*0xffffffc0*/;
    // 00492885  be3f000000             -mov esi, 0x3f
    cpu.esi = 63 /*0x3f*/;
L_0x0049288a:
    // 0049288a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049288c  83f8c0                 +cmp eax, -0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-64 /*-0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049288f  0f8d2e010000           -jge 0x4929c3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004929c3;
    }
    // 00492895  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x00492897:
    // 00492897  88d3                   -mov bl, dl
    cpu.bl = cpu.dl;
    // 00492899  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049289b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004928a1  80c340                 -add bl, 0x40
    (cpu.bl) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004928a4  40                     -inc eax
    (cpu.eax)++;
    // 004928a5  889a5cd05600           -mov byte ptr [edx + 0x56d05c], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5689436) /* 0x56d05c */) = cpu.bl;
    // 004928ab  83f87f                 +cmp eax, 0x7f
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
    // 004928ae  7cda                   -jl 0x49288a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049288a;
    }
    // 004928b0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004928b2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004928b4:
    // 004928b4  668b8338bf4d00         -mov ax, word ptr [ebx + 0x4dbf38]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5095224) /* 0x4dbf38 */);
    // 004928bb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004928bd  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004928c2  ba0d000000             -mov edx, 0xd
    cpu.edx = 13 /*0xd*/;
    // 004928c7  668b4c2402             -mov cx, word ptr [esp + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004928cc  668b833cbf4d00         -mov ax, word ptr [ebx + 0x4dbf3c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5095228) /* 0x4dbf3c */);
    // 004928d3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004928d5  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 004928d9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004928db  8b8344bf4d00           -mov eax, dword ptr [ebx + 0x4dbf44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5095236) /* 0x4dbf44 */);
    // 004928e1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004928e6  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004928e9  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004928eb  83fe17                 +cmp esi, 0x17
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(23 /*0x17*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004928ee  7507                   -jne 0x4928f7
    if (!cpu.flags.zf)
    {
        goto L_0x004928f7;
    }
    // 004928f0  66c74424022100         -mov word ptr [esp + 2], 0x21
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = 33 /*0x21*/;
L_0x004928f7:
    // 004928f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004928f9  7e1e                   -jle 0x492919
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492919;
    }
    // 004928fb  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00492902  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00492905  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492907  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00492909  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x0049290c:
    // 0049290c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049290f  898858475600           -mov dword ptr [eax + 0x564758], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5654360) /* 0x564758 */) = cpu.ecx;
    // 00492915  39d0                   +cmp eax, edx
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
    // 00492917  7cf3                   -jl 0x49290c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049290c;
    }
L_0x00492919:
    // 00492919  46                     -inc esi
    (cpu.esi)++;
    // 0049291a  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049291d  83fe60                 +cmp esi, 0x60
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492920  7c92                   -jl 0x4928b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004928b4;
    }
    // 00492922  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492923  be20000000             -mov esi, 0x20
    cpu.esi = 32 /*0x20*/;
    // 00492928  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049292a  6689742406             -mov word ptr [esp + 6], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.si;
    // 0049292f  66897c2404             -mov word ptr [esp + 4], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.di;
    // 00492934  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492936  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049293a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049293b:
    // 0049293b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049293e  899058475600           -mov dword ptr [eax + 0x564758], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5654360) /* 0x564758 */) = cpu.edx;
    // 00492944  3d80000000             +cmp eax, 0x80
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
    // 00492949  75f0                   -jne 0x49293b
    if (!cpu.flags.zf)
    {
        goto L_0x0049293b;
    }
    // 0049294b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049294d:
    // 0049294d  668b8338c54d00         -mov ax, word ptr [ebx + 0x4dc538]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5096760) /* 0x4dc538 */);
    // 00492954  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00492956  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 0049295b  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 00492960  668b4c2402             -mov cx, word ptr [esp + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00492965  668b833cc54d00         -mov ax, word ptr [ebx + 0x4dc53c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5096764) /* 0x4dc53c */);
    // 0049296c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049296e  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 00492972  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00492974  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00492979  8b8344c54d00           -mov eax, dword ptr [ebx + 0x4dc544]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5096772) /* 0x4dc544 */);
    // 0049297f  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00492981  c1e807                 -shr eax, 7
    cpu.eax >>= 7 /*0x7*/ % 32;
    // 00492984  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492986  7e1e                   -jle 0x4929a6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004929a6;
    }
    // 00492988  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049298b  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00492992  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00492995  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492997  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00492999:
    // 00492999  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049299c  898858c75600           -mov dword ptr [eax + 0x56c758], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5687128) /* 0x56c758 */) = cpu.ecx;
    // 004929a2  39d0                   +cmp eax, edx
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
    // 004929a4  7cf3                   -jl 0x492999
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492999;
    }
L_0x004929a6:
    // 004929a6  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004929a9  81fb00080000           +cmp ebx, 0x800
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929af  759c                   -jne 0x49294d
    if (!cpu.flags.zf)
    {
        goto L_0x0049294d;
    }
    // 004929b1  c7055cd5560001000000   -mov dword ptr [0x56d55c], 1
    app->getMemory<x86::reg32>(x86::reg32(5690716) /* 0x56d55c */) = 1 /*0x1*/;
    // 004929bb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004929be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004929bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004929c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004929c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004929c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004929c3:
    // 004929c3  83f83f                 +cmp eax, 0x3f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929c6  0f8ecbfeffff           -jle 0x492897
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492897;
    }
    // 004929cc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004929ce  e9c4feffff             -jmp 0x492897
    goto L_0x00492897;
}

/* align: skip 0x90 */
void Application::sub_4929d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004929d4);
    // 004929d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004929d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004929d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004929d7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004929d9  a1ec2a4e00             -mov eax, dword ptr [0x4e2aec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5122796) /* 0x4e2aec */);
    // 004929de  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004929e3  a35ccf5600             -mov dword ptr [0x56cf5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5689180) /* 0x56cf5c */) = cpu.eax;
L_0x004929e8:
    // 004929e8  8b8138cd4d00           -mov eax, dword ptr [ecx + 0x4dcd38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098808) /* 0x4dcd38 */);
    // 004929ee  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004929f1  8b91ec2a4e00           -mov edx, dword ptr [ecx + 0x4e2aec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5122796) /* 0x4e2aec */);
    // 004929f7  c1e00c                 -shl eax, 0xc
    cpu.eax <<= 12 /*0xc*/ % 32;
    // 004929fa  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004929fd  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004929ff  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00492a02  c1e810                 +shr eax, 0x10
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
    // 00492a05  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00492a07  898158cf5600           -mov dword ptr [ecx + 0x56cf58], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5689176) /* 0x56cf58 */) = cpu.eax;
    // 00492a0d  81f900010000           +cmp ecx, 0x100
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
    // 00492a13  75d3                   -jne 0x4929e8
    if (!cpu.flags.zf)
    {
        goto L_0x004929e8;
    }
    // 00492a15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492a1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492a1c);
    // 00492a1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492a1d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00492a1f  833d5cd5560000         +cmp dword ptr [0x56d55c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690716) /* 0x56d55c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492a26  7409                   -je 0x492a31
    if (cpu.flags.zf)
    {
        goto L_0x00492a31;
    }
    // 00492a28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492a2a  e8b5a50100             -call 0x4acfe4
    cpu.esp -= 4;
    sub_4acfe4(app, cpu);
    if (cpu.terminate) return;
    // 00492a2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492a31:
    // 00492a31  e83efeffff             -call 0x492874
    cpu.esp -= 4;
    sub_492874(app, cpu);
    if (cpu.terminate) return;
    // 00492a36  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492a38  e8a7a50100             -call 0x4acfe4
    cpu.esp -= 4;
    sub_4acfe4(app, cpu);
    if (cpu.terminate) return;
    // 00492a3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492a3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_492a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492a40);
    // 00492a40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492a41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492a42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492a43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492a44  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492a47  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00492a49  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00492a4b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00492a4e  833d5cd5560000         +cmp dword ptr [0x56d55c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690716) /* 0x56d55c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492a55  0f842d020000           -je 0x492c88
    if (cpu.flags.zf)
    {
        goto L_0x00492c88;
    }
L_0x00492a5b:
    // 00492a5b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00492a5d  e892a60100             -call 0x4ad0f4
    cpu.esp -= 4;
    sub_4ad0f4(app, cpu);
    if (cpu.terminate) return;
    // 00492a62  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00492a64  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492a66  83f802                 +cmp eax, 2
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
    // 00492a69  0f8523020000           -jne 0x492c92
    if (!cpu.flags.zf)
    {
        goto L_0x00492c92;
    }
    // 00492a6f  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00492a74  b85c455600             -mov eax, 0x56455c
    cpu.eax = 5653852 /*0x56455c*/;
    // 00492a79  e8c2fdffff             -call 0x492840
    cpu.esp -= 4;
    sub_492840(app, cpu);
    if (cpu.terminate) return;
L_0x00492a7e:
    // 00492a7e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492a80  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00492a83  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492a85  e86aa60100             -call 0x4ad0f4
    cpu.esp -= 4;
    sub_4ad0f4(app, cpu);
    if (cpu.terminate) return;
    // 00492a8a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492a8c  83f802                 +cmp eax, 2
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
    // 00492a8f  0f8511020000           -jne 0x492ca6
    if (!cpu.flags.zf)
    {
        goto L_0x00492ca6;
    }
    // 00492a95  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00492a9a  b85c465600             -mov eax, 0x56465c
    cpu.eax = 5654108 /*0x56465c*/;
    // 00492a9f  e89cfdffff             -call 0x492840
    cpu.esp -= 4;
    sub_492840(app, cpu);
    if (cpu.terminate) return;
L_0x00492aa4:
    // 00492aa4  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492aa6  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00492aa9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492aab  e844a60100             -call 0x4ad0f4
    cpu.esp -= 4;
    sub_4ad0f4(app, cpu);
    if (cpu.terminate) return;
    // 00492ab0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492ab2  83f802                 +cmp eax, 2
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
    // 00492ab5  0f85ff010000           -jne 0x492cba
    if (!cpu.flags.zf)
    {
        goto L_0x00492cba;
    }
    // 00492abb  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00492ac0  b85cd15600             -mov eax, 0x56d15c
    cpu.eax = 5689692 /*0x56d15c*/;
    // 00492ac5  e876fdffff             -call 0x492840
    cpu.esp -= 4;
    sub_492840(app, cpu);
    if (cpu.terminate) return;
L_0x00492aca:
    // 00492aca  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492acc  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00492acf  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492ad1  e81ea60100             -call 0x4ad0f4
    cpu.esp -= 4;
    sub_4ad0f4(app, cpu);
    if (cpu.terminate) return;
    // 00492ad6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492ad8  83f802                 +cmp eax, 2
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
    // 00492adb  0f85ed010000           -jne 0x492cce
    if (!cpu.flags.zf)
    {
        goto L_0x00492cce;
    }
    // 00492ae1  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00492ae6  b87cd15600             -mov eax, 0x56d17c
    cpu.eax = 5689724 /*0x56d17c*/;
    // 00492aeb  e850fdffff             -call 0x492840
    cpu.esp -= 4;
    sub_492840(app, cpu);
    if (cpu.terminate) return;
L_0x00492af0:
    // 00492af0  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492af2  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00492af5  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492af7  e8f8a50100             -call 0x4ad0f4
    cpu.esp -= 4;
    sub_4ad0f4(app, cpu);
    if (cpu.terminate) return;
    // 00492afc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492afe  83f802                 +cmp eax, 2
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
    // 00492b01  0f85db010000           -jne 0x492ce2
    if (!cpu.flags.zf)
    {
        goto L_0x00492ce2;
    }
    // 00492b07  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00492b0c  b85cd35600             -mov eax, 0x56d35c
    cpu.eax = 5690204 /*0x56d35c*/;
    // 00492b11  e82afdffff             -call 0x492840
    cpu.esp -= 4;
    sub_492840(app, cpu);
    if (cpu.terminate) return;
L_0x00492b16:
    // 00492b16  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492b18  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00492b1b  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492b1d  e8d2a50100             -call 0x4ad0f4
    cpu.esp -= 4;
    sub_4ad0f4(app, cpu);
    if (cpu.terminate) return;
    // 00492b22  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492b24  83f802                 +cmp eax, 2
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
    // 00492b27  0f85c9010000           -jne 0x492cf6
    if (!cpu.flags.zf)
    {
        goto L_0x00492cf6;
    }
    // 00492b2d  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00492b32  b87cd35600             -mov eax, 0x56d37c
    cpu.eax = 5690236 /*0x56d37c*/;
    // 00492b37  e804fdffff             -call 0x492840
    cpu.esp -= 4;
    sub_492840(app, cpu);
    if (cpu.terminate) return;
L_0x00492b3c:
    // 00492b3c  ba5c455600             -mov edx, 0x56455c
    cpu.edx = 5653852 /*0x56455c*/;
    // 00492b41  b85cd15600             -mov eax, 0x56d15c
    cpu.eax = 5689692 /*0x56d15c*/;
    // 00492b46  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492b48  e839a60100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492b4d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00492b50  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492b52  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00492b55  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00492b57  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00492b59  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492b5b  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 00492b62  ba5c455600             -mov edx, 0x56455c
    cpu.edx = 5653852 /*0x56455c*/;
    // 00492b67  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492b69  b89cd15600             -mov eax, 0x56d19c
    cpu.eax = 5689756 /*0x56d19c*/;
    // 00492b6e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492b70  e811a60100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492b75  ba7c455600             -mov edx, 0x56457c
    cpu.edx = 5653884 /*0x56457c*/;
    // 00492b7a  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492b7c  b8dcd15600             -mov eax, 0x56d1dc
    cpu.eax = 5689820 /*0x56d1dc*/;
    // 00492b81  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492b83  e8fea50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492b88  ba7c455600             -mov edx, 0x56457c
    cpu.edx = 5653884 /*0x56457c*/;
    // 00492b8d  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492b8f  b81cd25600             -mov eax, 0x56d21c
    cpu.eax = 5689884 /*0x56d21c*/;
    // 00492b94  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492b96  e8eba50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492b9b  ba9c455600             -mov edx, 0x56459c
    cpu.edx = 5653916 /*0x56459c*/;
    // 00492ba0  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492ba2  b85cd25600             -mov eax, 0x56d25c
    cpu.eax = 5689948 /*0x56d25c*/;
    // 00492ba7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492ba9  e8d8a50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492bae  ba9c455600             -mov edx, 0x56459c
    cpu.edx = 5653916 /*0x56459c*/;
    // 00492bb3  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492bb5  b89cd25600             -mov eax, 0x56d29c
    cpu.eax = 5690012 /*0x56d29c*/;
    // 00492bba  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492bbc  e8c5a50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492bc1  babc455600             -mov edx, 0x5645bc
    cpu.edx = 5653948 /*0x5645bc*/;
    // 00492bc6  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492bc8  b8dcd25600             -mov eax, 0x56d2dc
    cpu.eax = 5690076 /*0x56d2dc*/;
    // 00492bcd  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492bcf  e8b2a50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492bd4  babc455600             -mov edx, 0x5645bc
    cpu.edx = 5653948 /*0x5645bc*/;
    // 00492bd9  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492bdb  b81cd35600             -mov eax, 0x56d31c
    cpu.eax = 5690140 /*0x56d31c*/;
    // 00492be0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492be2  e89fa50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492be7  badc455600             -mov edx, 0x5645dc
    cpu.edx = 5653980 /*0x5645dc*/;
    // 00492bec  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492bee  b85cd35600             -mov eax, 0x56d35c
    cpu.eax = 5690204 /*0x56d35c*/;
    // 00492bf3  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492bf5  e88ca50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492bfa  badc455600             -mov edx, 0x5645dc
    cpu.edx = 5653980 /*0x5645dc*/;
    // 00492bff  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492c01  b89cd35600             -mov eax, 0x56d39c
    cpu.eax = 5690268 /*0x56d39c*/;
    // 00492c06  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492c08  e879a50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492c0d  bafc455600             -mov edx, 0x5645fc
    cpu.edx = 5654012 /*0x5645fc*/;
    // 00492c12  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492c14  b8dcd35600             -mov eax, 0x56d3dc
    cpu.eax = 5690332 /*0x56d3dc*/;
    // 00492c19  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492c1b  e866a50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492c20  bafc455600             -mov edx, 0x5645fc
    cpu.edx = 5654012 /*0x5645fc*/;
    // 00492c25  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492c27  b81cd45600             -mov eax, 0x56d41c
    cpu.eax = 5690396 /*0x56d41c*/;
    // 00492c2c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492c2e  e853a50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492c33  ba1c465600             -mov edx, 0x56461c
    cpu.edx = 5654044 /*0x56461c*/;
    // 00492c38  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492c3a  b85cd45600             -mov eax, 0x56d45c
    cpu.eax = 5690460 /*0x56d45c*/;
    // 00492c3f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492c41  e840a50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492c46  ba1c465600             -mov edx, 0x56461c
    cpu.edx = 5654044 /*0x56461c*/;
    // 00492c4b  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492c4d  b89cd45600             -mov eax, 0x56d49c
    cpu.eax = 5690524 /*0x56d49c*/;
    // 00492c52  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492c54  e82da50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492c59  ba3c465600             -mov edx, 0x56463c
    cpu.edx = 5654076 /*0x56463c*/;
    // 00492c5e  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492c60  b8dcd45600             -mov eax, 0x56d4dc
    cpu.eax = 5690588 /*0x56d4dc*/;
    // 00492c65  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492c67  e81aa50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492c6c  ba3c465600             -mov edx, 0x56463c
    cpu.edx = 5654076 /*0x56463c*/;
    // 00492c71  b81cd55600             -mov eax, 0x56d51c
    cpu.eax = 5690652 /*0x56d51c*/;
    // 00492c76  8d1c39                 -lea ebx, [ecx + edi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 00492c79  e808a50100             -call 0x4ad186
    cpu.esp -= 4;
    sub_4ad186(app, cpu);
    if (cpu.terminate) return;
    // 00492c7e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492c80  83c404                 +add esp, 4
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
    // 00492c83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492c84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492c85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492c86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492c87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492c88:
    // 00492c88  e8e7fbffff             -call 0x492874
    cpu.esp -= 4;
    sub_492874(app, cpu);
    if (cpu.terminate) return;
    // 00492c8d  e9c9fdffff             -jmp 0x492a5b
    goto L_0x00492a5b;
L_0x00492c92:
    // 00492c92  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00492c97  b85c455600             -mov eax, 0x56455c
    cpu.eax = 5653852 /*0x56455c*/;
    // 00492c9c  e8b8a10100             -call 0x4ace59
    cpu.esp -= 4;
    sub_4ace59(app, cpu);
    if (cpu.terminate) return;
    // 00492ca1  e9d8fdffff             -jmp 0x492a7e
    goto L_0x00492a7e;
L_0x00492ca6:
    // 00492ca6  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00492cab  b85c465600             -mov eax, 0x56465c
    cpu.eax = 5654108 /*0x56465c*/;
    // 00492cb0  e8a4a10100             -call 0x4ace59
    cpu.esp -= 4;
    sub_4ace59(app, cpu);
    if (cpu.terminate) return;
    // 00492cb5  e9eafdffff             -jmp 0x492aa4
    goto L_0x00492aa4;
L_0x00492cba:
    // 00492cba  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00492cbf  b85cd15600             -mov eax, 0x56d15c
    cpu.eax = 5689692 /*0x56d15c*/;
    // 00492cc4  e890a10100             -call 0x4ace59
    cpu.esp -= 4;
    sub_4ace59(app, cpu);
    if (cpu.terminate) return;
    // 00492cc9  e9fcfdffff             -jmp 0x492aca
    goto L_0x00492aca;
L_0x00492cce:
    // 00492cce  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00492cd3  b87cd15600             -mov eax, 0x56d17c
    cpu.eax = 5689724 /*0x56d17c*/;
    // 00492cd8  e87ca10100             -call 0x4ace59
    cpu.esp -= 4;
    sub_4ace59(app, cpu);
    if (cpu.terminate) return;
    // 00492cdd  e90efeffff             -jmp 0x492af0
    goto L_0x00492af0;
L_0x00492ce2:
    // 00492ce2  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00492ce7  b85cd35600             -mov eax, 0x56d35c
    cpu.eax = 5690204 /*0x56d35c*/;
    // 00492cec  e868a10100             -call 0x4ace59
    cpu.esp -= 4;
    sub_4ace59(app, cpu);
    if (cpu.terminate) return;
    // 00492cf1  e920feffff             -jmp 0x492b16
    goto L_0x00492b16;
L_0x00492cf6:
    // 00492cf6  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00492cfb  b87cd35600             -mov eax, 0x56d37c
    cpu.eax = 5690236 /*0x56d37c*/;
    // 00492d00  e854a10100             -call 0x4ace59
    cpu.esp -= 4;
    sub_4ace59(app, cpu);
    if (cpu.terminate) return;
    // 00492d05  e932feffff             -jmp 0x492b3c
    goto L_0x00492b3c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_492d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492d10);
    // 00492d10  83ec04                 +sub esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00492d13  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00492d15  d85c2408               +fcomp dword ptr [esp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 00492d19  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00492d1b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00492d1c  771b                   -ja 0x492d39
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00492d39;
    }
    // 00492d1e  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00492d22  dc05a8054d00           -fadd qword ptr [0x4d05a8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5047720) /* 0x4d05a8 */));
    // 00492d28  e80338ffff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00492d2d  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00492d30  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00492d33  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492d36  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00492d39:
    // 00492d39  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00492d3d  dc05a0054d00           -fadd qword ptr [0x4d05a0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5047712) /* 0x4d05a0 */));
    // 00492d43  e8e837ffff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00492d48  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00492d4b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00492d4e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492d51  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_492d54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492d54);
    // 00492d54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492d55  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492d56  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492d57  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492d58  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492d59  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492d5a  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00492d5d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00492d61  b9c0ffffff             -mov ecx, 0xffffffc0
    cpu.ecx = 4294967232 /*0xffffffc0*/;
    // 00492d66  bb71000000             -mov ebx, 0x71
    cpu.ebx = 113 /*0x71*/;
    // 00492d6b  bf00180200             -mov edi, 0x21800
    cpu.edi = 137216 /*0x21800*/;
    // 00492d70  be0000802c             -mov esi, 0x2c800000
    cpu.esi = 746586112 /*0x2c800000*/;
    // 00492d75  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00492d77:
    // 00492d77  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492d7b  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00492d7e  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00492d82  dc05d0054d00           -fadd qword ptr [0x4d05d0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5047760) /* 0x4d05d0 */));
    // 00492d88  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00492d8a  dd1424                 -fst qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    // 00492d8d  dc0db0054d00           -fmul qword ptr [0x4d05b0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5047728) /* 0x4d05b0 */));
    // 00492d93  8982c8e35600           -mov dword ptr [edx + 0x56e3c8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5694408) /* 0x56e3c8 */) = cpu.eax;
    // 00492d99  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492d9c  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d9f  e86cffffff             -call 0x492d10
    cpu.esp -= 4;
    sub_492d10(app, cpu);
    if (cpu.terminate) return;
    // 00492da4  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00492da7  dc0db8054d00           -fmul qword ptr [0x4d05b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5047736) /* 0x4d05b8 */));
    // 00492dad  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492db0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00492db2  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492db5  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00492dbb  e850ffffff             -call 0x492d10
    cpu.esp -= 4;
    sub_492d10(app, cpu);
    if (cpu.terminate) return;
    // 00492dc0  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00492dc3  c1e50b                 -shl ebp, 0xb
    cpu.ebp <<= 11 /*0xb*/ % 32;
    // 00492dc6  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00492dcb  dc0dc0054d00           -fmul qword ptr [0x4d05c0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5047744) /* 0x4d05c0 */));
    // 00492dd1  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492dd3  8982c8e55600           -mov dword ptr [edx + 0x56e5c8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5694920) /* 0x56e5c8 */) = cpu.eax;
    // 00492dd9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492ddc  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492ddf  e82cffffff             -call 0x492d10
    cpu.esp -= 4;
    sub_492d10(app, cpu);
    if (cpu.terminate) return;
    // 00492de4  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00492de7  dc0dc8054d00           -fmul qword ptr [0x4d05c8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5047752) /* 0x4d05c8 */));
    // 00492ded  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492df0  81c700080000           -add edi, 0x800
    (cpu.edi) += x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 00492df6  81c600008000           -add esi, 0x800000
    (cpu.esi) += x86::reg32(x86::sreg32(8388608 /*0x800000*/));
    // 00492dfc  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00492e00  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492e03  41                     -inc ecx
    (cpu.ecx)++;
    // 00492e04  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492e07  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492e0b  e800ffffff             -call 0x492d10
    cpu.esp -= 4;
    sub_492d10(app, cpu);
    if (cpu.terminate) return;
    // 00492e10  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00492e16  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00492e1b  c1e00b                 -shl eax, 0xb
    cpu.eax <<= 11 /*0xb*/ % 32;
    // 00492e1e  c1e517                 -shl ebp, 0x17
    cpu.ebp <<= 23 /*0x17*/ % 32;
    // 00492e21  43                     -inc ebx
    (cpu.ebx)++;
    // 00492e22  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492e24  8982c4e75600           -mov dword ptr [edx + 0x56e7c4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5695428) /* 0x56e7c4 */) = cpu.eax;
    // 00492e2a  83f940                 +cmp ecx, 0x40
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492e2d  0f8c44ffffff           -jl 0x492d77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492d77;
    }
    // 00492e33  ba67ffffff             -mov edx, 0xffffff67
    cpu.edx = 4294967143 /*0xffffff67*/;
    // 00492e38  b99cfdffff             -mov ecx, 0xfffffd9c
    cpu.ecx = 4294966684 /*0xfffffd9c*/;
    // 00492e3d  be1f000000             -mov esi, 0x1f
    cpu.esi = 31 /*0x1f*/;
    // 00492e42  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492e46  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00492e48:
    // 00492e48  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00492e4b  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 00492e50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492e52  0f8c08010000           -jl 0x492f60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492f60;
    }
    // 00492e58  3dff000000             +cmp eax, 0xff
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
    // 00492e5d  7e05                   -jle 0x492e64
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492e64;
    }
    // 00492e5f  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00492e64:
    // 00492e64  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492e66  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492e69  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00492e6c  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 00492e6f  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492e72  7e02                   -jle 0x492e76
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492e76;
    }
    // 00492e74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00492e76:
    // 00492e76  83fd0f                 +cmp ebp, 0xf
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492e79  0f85e8000000           -jne 0x492f67
    if (!cpu.flags.zf)
    {
        goto L_0x00492f67;
    }
    // 00492e7f  c1e31a                 -shl ebx, 0x1a
    cpu.ebx <<= 26 /*0x1a*/ % 32;
    // 00492e82  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
L_0x00492e85:
    // 00492e85  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00492e87  898164e15600           -mov dword ptr [ecx + 0x56e164], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5693796) /* 0x56e164 */) = cpu.eax;
    // 00492e8d  42                     -inc edx
    (cpu.edx)++;
    // 00492e8e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492e91  81fa99000000           +cmp edx, 0x99
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153 /*0x99*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492e97  7caf                   -jl 0x492e48
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492e48;
    }
    // 00492e99  ba7dffffff             -mov edx, 0xffffff7d
    cpu.edx = 4294967165 /*0xffffff7d*/;
    // 00492e9e  b9f4fdffff             -mov ecx, 0xfffffdf4
    cpu.ecx = 4294966772 /*0xfffffdf4*/;
    // 00492ea3  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 00492ea8  bf3f000000             -mov edi, 0x3f
    cpu.edi = 63 /*0x3f*/;
    // 00492ead  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00492eaf:
    // 00492eaf  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00492eb2  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 00492eb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492eb9  0f8cb3000000           -jl 0x492f72
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492f72;
    }
    // 00492ebf  3dff000000             +cmp eax, 0xff
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
    // 00492ec4  7e02                   -jle 0x492ec8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492ec8;
    }
    // 00492ec6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00492ec8:
    // 00492ec8  837c24080f             +cmp dword ptr [esp + 8], 0xf
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ecd  0f85a6000000           -jne 0x492f79
    if (!cpu.flags.zf)
    {
        goto L_0x00492f79;
    }
    // 00492ed3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492ed5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492ed8  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00492edb  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 00492ede  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ee1  7e05                   -jle 0x492ee8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492ee8;
    }
    // 00492ee3  b81f000000             -mov eax, 0x1f
    cpu.eax = 31 /*0x1f*/;
L_0x00492ee8:
    // 00492ee8  c1e315                 -shl ebx, 0x15
    cpu.ebx <<= 21 /*0x15*/ % 32;
    // 00492eeb  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00492eee  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492ef1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00492ef3  42                     -inc edx
    (cpu.edx)++;
    // 00492ef4  8981f0dc5600           -mov dword ptr [ecx + 0x56dcf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5692656) /* 0x56dcf0 */) = cpu.eax;
    // 00492efa  81fa83000000           +cmp edx, 0x83
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492f00  7cad                   -jl 0x492eaf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492eaf;
    }
    // 00492f02  ba4fffffff             -mov edx, 0xffffff4f
    cpu.edx = 4294967119 /*0xffffff4f*/;
    // 00492f07  b93cfdffff             -mov ecx, 0xfffffd3c
    cpu.ecx = 4294966588 /*0xfffffd3c*/;
    // 00492f0c  bd1f000000             -mov ebp, 0x1f
    cpu.ebp = 31 /*0x1f*/;
    // 00492f11  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
    // 00492f16  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00492f18:
    // 00492f18  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00492f1b  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 00492f20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492f22  7c70                   -jl 0x492f94
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492f94;
    }
    // 00492f24  3dff000000             +cmp eax, 0xff
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
    // 00492f29  7e02                   -jle 0x492f2d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492f2d;
    }
    // 00492f2b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00492f2d:
    // 00492f2d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492f2f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492f32  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00492f35  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 00492f38  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492f3b  7e02                   -jle 0x492f3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492f3f;
    }
    // 00492f3d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00492f3f:
    // 00492f3f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00492f42  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492f45  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00492f47  42                     -inc edx
    (cpu.edx)++;
    // 00492f48  898120d85600           -mov dword ptr [ecx + 0x56d820], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5691424) /* 0x56d820 */) = cpu.eax;
    // 00492f4e  81fab1000000           +cmp edx, 0xb1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(177 /*0xb1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492f54  7cc2                   -jl 0x492f18
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492f18;
    }
    // 00492f56  83c410                 +add esp, 0x10
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
    // 00492f59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f5c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492f5f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492f60:
    // 00492f60  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492f62  e9fdfeffff             -jmp 0x492e64
    goto L_0x00492e64;
L_0x00492f67:
    // 00492f67  c1e31b                 -shl ebx, 0x1b
    cpu.ebx <<= 27 /*0x1b*/ % 32;
    // 00492f6a  c1e00b                 +shl eax, 0xb
    {
        x86::reg8 tmp = 11 /*0xb*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00492f6d  e913ffffff             -jmp 0x492e85
    goto L_0x00492e85;
L_0x00492f72:
    // 00492f72  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492f74  e94fffffff             -jmp 0x492ec8
    goto L_0x00492ec8;
L_0x00492f79:
    // 00492f79  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492f7b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00492f7e  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00492f81  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
    // 00492f84  83f83f                 +cmp eax, 0x3f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492f87  0f8e5bffffff           -jle 0x492ee8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492ee8;
    }
    // 00492f8d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492f8f  e954ffffff             -jmp 0x492ee8
    goto L_0x00492ee8;
L_0x00492f94:
    // 00492f94  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492f96  eb95                   -jmp 0x492f2d
    goto L_0x00492f2d;
}

/* align: skip  */
void Application::sub_492f98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00492f98);
    // 00492f98  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492f99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492f9a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492f9b  81ec480a0000           -sub esp, 0xa48
    (cpu.esp) -= x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 00492fa1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492fa3  899424100a0000         -mov dword ptr [esp + 0xa10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.edx;
    // 00492faa  899c240c0a0000         -mov dword ptr [esp + 0xa0c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebx;
    // 00492fb1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00492fb3  8b94245c0a0000         -mov edx, dword ptr [esp + 0xa5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 00492fba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492fbc  0f85e8010000           -jne 0x4931aa
    if (!cpu.flags.zf)
    {
        goto L_0x004931aa;
    }
    // 00492fc2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x00492fc7:
    // 00492fc7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00492fc9  8a155cb24d00           -mov dl, byte ptr [0x4db25c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 00492fcf  83fa0f                 +cmp edx, 0xf
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
    // 00492fd2  7409                   -je 0x492fdd
    if (cpu.flags.zf)
    {
        goto L_0x00492fdd;
    }
    // 00492fd4  83fa10                 +cmp edx, 0x10
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
    // 00492fd7  0f85f7010000           -jne 0x4931d4
    if (!cpu.flags.zf)
    {
        goto L_0x004931d4;
    }
L_0x00492fdd:
    // 00492fdd  3b15c8e95600           +cmp edx, dword ptr [0x56e9c8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492fe3  740d                   -je 0x492ff2
    if (cpu.flags.zf)
    {
        goto L_0x00492ff2;
    }
    // 00492fe5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00492fe7  e868fdffff             -call 0x492d54
    cpu.esp -= 4;
    sub_492d54(app, cpu);
    if (cpu.terminate) return;
    // 00492fec  8915c8e95600           -mov dword ptr [0x56e9c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */) = cpu.edx;
L_0x00492ff2:
    // 00492ff2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492ff4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492ff6  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 00492ffc  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00492fff  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 00493005  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 00493008  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 0049300e  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00493011  6683e6fe               -and si, 0xfffe
    cpu.si &= x86::reg16(x86::sreg16(65534 /*0xfffe*/));
    // 00493015  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00493017  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00493019  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049301b  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0049301e  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00493021  8b8424580a0000         -mov eax, dword ptr [esp + 0xa58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2648) /* 0xa58 */);
    // 00493028  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049302b  899424080a0000         -mov dword ptr [esp + 0xa08], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edx;
    // 00493032  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00493039  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049303b  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
    // 00493042  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00493044  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493046  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00493049  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049304b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0049304d  8b154cb24d00           -mov edx, dword ptr [0x4db24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 00493053  898424040a0000         -mov dword ptr [esp + 0xa04], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */) = cpu.eax;
    // 0049305a  39d6                   +cmp esi, edx
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
    // 0049305c  7d22                   -jge 0x493080
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493080;
    }
    // 0049305e  8d1c09                 -lea ebx, [ecx + ecx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 00493061  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493063  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00493066  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00493068  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049306a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049306c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049306f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00493071  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00493074  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00493077  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00493079  0184240c0a0000         -add dword ptr [esp + 0xa0c], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00493080:
    // 00493080  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 00493087  8b3d54b24d00           -mov edi, dword ptr [0x4db254]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 0049308d  39f8                   +cmp eax, edi
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
    // 0049308f  7e07                   -jle 0x493098
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493098;
    }
    // 00493091  89bc24080a0000         -mov dword ptr [esp + 0xa08], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edi;
L_0x00493098:
    // 00493098  8b8424100a0000         -mov eax, dword ptr [esp + 0xa10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0049309f  8b2d50b24d00           -mov ebp, dword ptr [0x4db250]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004930a5  39e8                   +cmp eax, ebp
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
    // 004930a7  7d47                   -jge 0x4930f0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004930f0;
    }
    // 004930a9  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004930b0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004930b2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004930b4  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004930b7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004930b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004930bb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004930be  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004930c0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004930c2  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004930c5  0faf8424040a0000       -imul eax, dword ptr [esp + 0xa04]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */))));
    // 004930cd  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004930d4  8bac240c0a0000         -mov ebp, dword ptr [esp + 0xa0c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004930db  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004930de  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004930e0  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004930e2  899c24100a0000         -mov dword ptr [esp + 0xa10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.ebx;
    // 004930e9  89ac240c0a0000         -mov dword ptr [esp + 0xa0c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebp;
L_0x004930f0:
    // 004930f0  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004930f7  8b1558b24d00           -mov edx, dword ptr [0x4db258]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004930fd  39d0                   +cmp eax, edx
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
    // 004930ff  7e07                   -jle 0x493108
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493108;
    }
    // 00493101  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
L_0x00493108:
    // 00493108  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0049310f  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00493111  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493113  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493115  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00493118  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049311a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049311c  83f802                 +cmp eax, 2
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
    // 0049311f  0f8c77000000           -jl 0x49319c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049319c;
    }
    // 00493125  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0049312c  8b8c245c0a0000         -mov ecx, dword ptr [esp + 0xa5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 00493133  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00493136  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493138  0f85a7000000           -jne 0x4931e5
    if (!cpu.flags.zf)
    {
        goto L_0x004931e5;
    }
    // 0049313e  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00493145  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0049314c  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 00493153  39dd                   +cmp ebp, ebx
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
    // 00493155  7d45                   -jge 0x49319c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049319c;
    }
    // 00493157  898424200a0000         -mov dword ptr [esp + 0xa20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */) = cpu.eax;
L_0x0049315e:
    // 0049315e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00493160  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493162  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 00493168  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0049316b  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 00493171  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 00493174  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 0049317a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049317c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049317e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493180  45                     -inc ebp
    (cpu.ebp)++;
    // 00493181  e8f2770000             -call 0x49a978
    cpu.esp -= 4;
    sub_49a978(app, cpu);
    if (cpu.terminate) return;
    // 00493186  8b8424200a0000         -mov eax, dword ptr [esp + 0xa20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */);
    // 0049318d  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 00493194  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493196  39d5                   +cmp ebp, edx
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
    // 00493198  7cc4                   -jl 0x49315e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049315e;
    }
    // 0049319a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049319c:
    // 0049319c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049319e  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004931a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931a7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004931aa:
    // 004931aa  83fa01                 +cmp edx, 1
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
    // 004931ad  750a                   -jne 0x4931b9
    if (!cpu.flags.zf)
    {
        goto L_0x004931b9;
    }
L_0x004931af:
    // 004931af  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004931b4  e90efeffff             -jmp 0x492fc7
    goto L_0x00492fc7;
L_0x004931b9:
    // 004931b9  83fa02                 +cmp edx, 2
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
    // 004931bc  74f1                   -je 0x4931af
    if (cpu.flags.zf)
    {
        goto L_0x004931af;
    }
    // 004931be  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004931c1  74ec                   -je 0x4931af
    if (cpu.flags.zf)
    {
        goto L_0x004931af;
    }
    // 004931c3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004931c8  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004931ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931d1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004931d4:
    // 004931d4  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004931d9  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004931df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931e2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004931e5:
    // 004931e5  83f903                 +cmp ecx, 3
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
    // 004931e8  0f8578010000           -jne 0x493366
    if (!cpu.flags.zf)
    {
        goto L_0x00493366;
    }
    // 004931ee  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004931f5  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004931fc  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 00493203  39dd                   +cmp ebp, ebx
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
    // 00493205  7d71                   -jge 0x493278
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493278;
    }
    // 00493207  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00493209  4a                     -dec edx
    (cpu.edx)--;
    // 0049320a  899424180a0000         -mov dword ptr [esp + 0xa18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */) = cpu.edx;
    // 00493211  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 00493214  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00493217  898424140a0000         -mov dword ptr [esp + 0xa14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */) = cpu.eax;
    // 0049321e  899424280a0000         -mov dword ptr [esp + 0xa28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */) = cpu.edx;
L_0x00493225:
    // 00493225  8b9c24180a0000         -mov ebx, dword ptr [esp + 0xa18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */);
    // 0049322c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049322e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493230  e8b9790000             -call 0x49abee
    cpu.esp -= 4;
    sub_49abee(app, cpu);
    if (cpu.terminate) return;
    // 00493235  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00493237  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493239  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 0049323f  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00493242  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 00493248  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0049324b  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 00493251  8b9c24280a0000         -mov ebx, dword ptr [esp + 0xa28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */);
    // 00493258  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049325a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049325c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049325f  e814770000             -call 0x49a978
    cpu.esp -= 4;
    sub_49a978(app, cpu);
    if (cpu.terminate) return;
    // 00493264  8b8424140a0000         -mov eax, dword ptr [esp + 0xa14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */);
    // 0049326b  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 00493272  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493274  39d5                   +cmp ebp, edx
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
    // 00493276  7cad                   -jl 0x493225
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493225;
    }
L_0x00493278:
    // 00493278  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0049327f  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 00493286  8b8c24100a0000         -mov ecx, dword ptr [esp + 0xa10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0049328d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049328f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493291  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00493294  3d00580200             +cmp eax, 0x25800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153600 /*0x25800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493299  0f8fae000000           -jg 0x49334d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049334d;
    }
L_0x0049329f:
    // 0049329f  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004932a6  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004932a9  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004932b0  899424340a0000         -mov dword ptr [esp + 0xa34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */) = cpu.edx;
    // 004932b7  8b9424040a0000         -mov edx, dword ptr [esp + 0xa04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 004932be  45                     -inc ebp
    (cpu.ebp)++;
    // 004932bf  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004932c2  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004932c4  899424240a0000         -mov dword ptr [esp + 0xa24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */) = cpu.edx;
    // 004932cb  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004932d2  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004932d5  4a                     -dec edx
    (cpu.edx)--;
    // 004932d6  89bc24300a0000         -mov dword ptr [esp + 0xa30], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */) = cpu.edi;
    // 004932dd  899424380a0000         -mov dword ptr [esp + 0xa38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2616) /* 0xa38 */) = cpu.edx;
    // 004932e4  39d5                   +cmp ebp, edx
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
    // 004932e6  0f8db0feffff           -jge 0x49319c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049319c;
    }
L_0x004932ec:
    // 004932ec  8bbc24240a0000         -mov edi, dword ptr [esp + 0xa24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 004932f3  8b8c24340a0000         -mov ecx, dword ptr [esp + 0xa34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */);
    // 004932fa  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004932fc  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004932fe  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00493300  e845790000             -call 0x49ac4a
    cpu.esp -= 4;
    sub_49ac4a(app, cpu);
    if (cpu.terminate) return;
    // 00493305  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00493307  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493309  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 0049330f  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00493312  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 00493318  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0049331b  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 00493321  8b9c24300a0000         -mov ebx, dword ptr [esp + 0xa30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */);
    // 00493328  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049332a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049332c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049332f  e844760000             -call 0x49a978
    cpu.esp -= 4;
    sub_49a978(app, cpu);
    if (cpu.terminate) return;
    // 00493334  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493336  3bac24380a0000         +cmp ebp, dword ptr [esp + 0xa38]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2616) /* 0xa38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049333d  7cad                   -jl 0x4932ec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004932ec;
    }
    // 0049333f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493341  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 00493347  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493348  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493349  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049334a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049334d:
    // 0049334d  e8760cffff             -call 0x483fc8
    cpu.esp -= 4;
    sub_483fc8(app, cpu);
    if (cpu.terminate) return;
    // 00493352  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493354  0f8545ffffff           -jne 0x49329f
    if (!cpu.flags.zf)
    {
        goto L_0x0049329f;
    }
    // 0049335a  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 00493360  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493361  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493362  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493363  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00493366:
    // 00493366  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0049336d  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 00493374  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0049337b  39dd                   +cmp ebp, ebx
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
    // 0049337d  7d45                   -jge 0x4933c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004933c4;
    }
    // 0049337f  8984241c0a0000         -mov dword ptr [esp + 0xa1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */) = cpu.eax;
L_0x00493386:
    // 00493386  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00493388  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049338a  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 00493390  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00493393  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 00493399  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0049339c  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004933a2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004933a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004933a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004933a8  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004933ab  e89b760000             -call 0x49aa4b
    cpu.esp -= 4;
    sub_49aa4b(app, cpu);
    if (cpu.terminate) return;
    // 004933b0  8b84241c0a0000         -mov eax, dword ptr [esp + 0xa1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */);
    // 004933b7  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004933be  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004933c0  39d5                   +cmp ebp, edx
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
    // 004933c2  7cc2                   -jl 0x493386
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493386;
    }
L_0x004933c4:
    // 004933c4  83bc245c0a000002       +cmp dword ptr [esp + 0xa5c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004933cc  0f85cafdffff           -jne 0x49319c
    if (!cpu.flags.zf)
    {
        goto L_0x0049319c;
    }
    // 004933d2  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 004933d9  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004933e0  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004933e7  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004933e9  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004933eb  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004933ee  3d00580200             +cmp eax, 0x25800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153600 /*0x25800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004933f3  0f8fab000000           -jg 0x4934a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004934a4;
    }
L_0x004933f9:
    // 004933f9  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 00493400  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 00493407  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0049340e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00493411  8984242c0a0000         -mov dword ptr [esp + 0xa2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */) = cpu.eax;
    // 00493418  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0049341f  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00493426  48                     -dec eax
    (cpu.eax)--;
    // 00493427  45                     -inc ebp
    (cpu.ebp)++;
    // 00493428  8984243c0a0000         -mov dword ptr [esp + 0xa3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */) = cpu.eax;
    // 0049342f  39c5                   +cmp ebp, eax
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
    // 00493431  0f8d65fdffff           -jge 0x49319c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049319c;
    }
L_0x00493437:
    // 00493437  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00493439  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049343b  8b8c242c0a0000         -mov ecx, dword ptr [esp + 0xa2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */);
    // 00493442  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 00493448  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0049344b  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 00493451  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 00493454  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 0049345a  8b9424400a0000         -mov edx, dword ptr [esp + 0xa40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 00493461  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00493463  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00493466  8b8424400a0000         -mov eax, dword ptr [esp + 0xa40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 0049346d  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049346f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00493471  899424000a0000         -mov dword ptr [esp + 0xa00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */) = cpu.edx;
    // 00493478  e895760000             -call 0x49ab12
    cpu.esp -= 4;
    sub_49ab12(app, cpu);
    if (cpu.terminate) return;
    // 0049347d  8b8424000a0000         -mov eax, dword ptr [esp + 0xa00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */);
    // 00493484  8b9c243c0a0000         -mov ebx, dword ptr [esp + 0xa3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */);
    // 0049348b  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 00493492  39dd                   +cmp ebp, ebx
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
    // 00493494  7ca1                   -jl 0x493437
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493437;
    }
    // 00493496  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493498  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0049349e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049349f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934a1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004934a4:
    // 004934a4  e81f0bffff             -call 0x483fc8
    cpu.esp -= 4;
    sub_483fc8(app, cpu);
    if (cpu.terminate) return;
    // 004934a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004934ab  0f8548ffffff           -jne 0x4933f9
    if (!cpu.flags.zf)
    {
        goto L_0x004933f9;
    }
    // 004934b1  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004934b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934ba  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4934c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004934c0);
    // 004934c0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004934c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4934c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004934c4);
    // 004934c4  a338ce4d00             -mov dword ptr [0x4dce38], eax
    app->getMemory<x86::reg32>(x86::reg32(5099064) /* 0x4dce38 */) = cpu.eax;
    // 004934c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4934cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004934cc);
    // 004934cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004934cd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004934cf  8b1538ce4d00           -mov edx, dword ptr [0x4dce38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099064) /* 0x4dce38 */);
    // 004934d5  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
    // 004934da  a34cce4d00             -mov dword ptr [0x4dce4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */) = cpu.eax;
    // 004934df  05c0000000             -add eax, 0xc0
    (cpu.eax) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004934e4  e80f210000             -call 0x4955f8
    cpu.esp -= 4;
    sub_4955f8(app, cpu);
    if (cpu.terminate) return;
    // 004934e9  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004934ef  89463c                 -mov dword ptr [esi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004934f2  8b8688000000           -mov eax, dword ptr [esi + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004934f8  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004934fb  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 00493501  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00493507  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493509  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049350c  894e2c                 -mov dword ptr [esi + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0049350f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00493512  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00493515  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00493518  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049351b  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049351e  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00493521  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00493524  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00493527  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0049352e  895e40                 -mov dword ptr [esi + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 00493531  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00493538  c7467000000000         -mov dword ptr [esi + 0x70], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 0049353f  c7467800000000         -mov dword ptr [esi + 0x78], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 00493546  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00493549  89467c                 -mov dword ptr [esi + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 0049354c  c7462007000000         -mov dword ptr [esi + 0x20], 7
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00493553  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0049355a  c7463800000000         -mov dword ptr [esi + 0x38], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 00493561  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00493564  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00493567  c786bc00000000000000   -mov dword ptr [esi + 0xbc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 00493571  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00493577  8986b8000000           -mov dword ptr [esi + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 0049357d  c7463000000000         -mov dword ptr [esi + 0x30], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00493584  e88368ffff             -call 0x489e0c
    cpu.esp -= 4;
    sub_489e0c(app, cpu);
    if (cpu.terminate) return;
    // 00493589  8986a4000000           -mov dword ptr [esi + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0049358f  e86469ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00493594  8986ac000000           -mov dword ptr [esi + 0xac], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0049359a  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0049359f  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 004935a5  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004935aa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004935ab  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004935ad  b8783f4900             -mov eax, 0x493f78
    cpu.eax = 4800376 /*0x493f78*/;
    // 004935b2  e82965ffff             -call 0x489ae0
    cpu.esp -= 4;
    sub_489ae0(app, cpu);
    if (cpu.terminate) return;
    // 004935b7  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 004935bd  e89a68ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004935c2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004935c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004935c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4935c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004935c8);
    // 004935c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004935c9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004935cb  e8fcfeffff             -call 0x4934cc
    cpu.esp -= 4;
    sub_4934cc(app, cpu);
    if (cpu.terminate) return;
    // 004935d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004935d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4935d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004935d4);
    // 004935d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004935d5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004935da  e8edfeffff             -call 0x4934cc
    cpu.esp -= 4;
    sub_4934cc(app, cpu);
    if (cpu.terminate) return;
    // 004935df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004935e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4935e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004935e4);
    // 004935e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004935e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004935e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004935e7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004935ea  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004935ee  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004935f0  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004935f2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004935f4  66a9ff0f               +test ax, 0xfff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 4095 /*0xfff*/));
    // 004935f8  740c                   -je 0x493606
    if (cpu.flags.zf)
    {
        goto L_0x00493606;
    }
    // 004935fa  8db800100000           -lea edi, [eax + 0x1000]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4096) /* 0x1000 */);
    // 00493600  81e700f0ff7f           -and edi, 0x7ffff000
    cpu.edi &= x86::reg32(x86::sreg32(2147479552 /*0x7ffff000*/));
L_0x00493606:
    // 00493606  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0049360b  b850064d00             -mov eax, 0x4d0650
    cpu.eax = 5047888 /*0x4d0650*/;
    // 00493610  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00493612  e8990effff             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 00493617  8b1538ce4d00           -mov edx, dword ptr [0x4dce38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099064) /* 0x4dce38 */);
    // 0049361d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00493620  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00493627  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493629  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049362c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049362e  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00493635  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00493637  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0049363a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049363c  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 00493642  b878064d00             -mov eax, 0x4d0678
    cpu.eax = 5047928 /*0x4d0678*/;
    // 00493647  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0049364d  e8720effff             -call 0x4844c4
    cpu.esp -= 4;
    sub_4844c4(app, cpu);
    if (cpu.terminate) return;
    // 00493652  8b1538ce4d00           -mov edx, dword ptr [0x4dce38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099064) /* 0x4dce38 */);
    // 00493658  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049365a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00493661  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493663  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493666  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493668  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0049366f  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00493672  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 00493678  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049367a  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00493680  e89769ffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00493685  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00493688  898688000000           -mov dword ptr [esi + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0049368e  89be84000000           -mov dword ptr [esi + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 00493694  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 00493699  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049369b  e8f0910000             -call 0x49c890
    cpu.esp -= 4;
    sub_49c890(app, cpu);
    if (cpu.terminate) return;
    // 004936a0  8b3d38ce4d00           -mov edi, dword ptr [0x4dce38]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099064) /* 0x4dce38 */);
    // 004936a6  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 004936ad  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004936af  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004936b2  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004936b4  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004936b7  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004936ba  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 004936bf  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 004936c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004936c7  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004936cd  e8be910000             -call 0x49c890
    cpu.esp -= 4;
    sub_49c890(app, cpu);
    if (cpu.terminate) return;
    // 004936d2  8b3d38ce4d00           -mov edi, dword ptr [0x4dce38]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099064) /* 0x4dce38 */);
    // 004936d8  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 004936df  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004936e1  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004936e4  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004936e6  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004936e9  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004936eb  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004936ee  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004936f2  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 004936f8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004936fa  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00493700  e8c7fdffff             -call 0x4934cc
    cpu.esp -= 4;
    sub_4934cc(app, cpu);
    if (cpu.terminate) return;
    // 00493705  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00493708  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493709  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049370a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049370b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49370c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049370c);
    // 0049370c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049370d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049370f  e8d0feffff             -call 0x4935e4
    cpu.esp -= 4;
    sub_4935e4(app, cpu);
    if (cpu.terminate) return;
    // 00493714  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493715  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493718);
    // 00493718  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493719  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049371e  e8c1feffff             -call 0x4935e4
    cpu.esp -= 4;
    sub_4935e4(app, cpu);
    if (cpu.terminate) return;
    // 00493723  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493724  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493728(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493728);
    // 00493728  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493729  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049372a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049372b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049372c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049372d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00493730  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493732  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00493734  e8e7fffeff             -call 0x483720
    cpu.esp -= 4;
    sub_483720(app, cpu);
    if (cpu.terminate) return;
    // 00493739  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049373d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049373f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00493743  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00493747  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049374b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049374c  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493750  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493752  e8c99c0100             -call 0x4ad420
    cpu.esp -= 4;
    sub_4ad420(app, cpu);
    if (cpu.terminate) return;
    // 00493757  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00493759  0f8590000000           -jne 0x4937ef
    if (!cpu.flags.zf)
    {
        goto L_0x004937ef;
    }
    // 0049375f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00493762  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00493766  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049376a  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049376e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493772  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00493776:
    // 00493776  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049377a  2d00200000             -sub eax, 0x2000
    (cpu.eax) -= x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 0049377f  662500e0               -and ax, 0xe000
    cpu.ax &= x86::reg16(x86::sreg16(57344 /*0xe000*/));
    // 00493783  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00493787  3d00000400             +cmp eax, 0x40000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(262144 /*0x40000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049378c  0f8f7a000000           -jg 0x49380c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049380c;
    }
L_0x00493792:
    // 00493792  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 00493797  b8e4064d00             -mov eax, 0x4d06e4
    cpu.eax = 5048036 /*0x4d06e4*/;
    // 0049379c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049379e  e8f50cffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004937a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004937a5  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 004937aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004937ac  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004937b0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004937b3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004937b5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004937b7:
    // 004937b7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004937ba  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004937bc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004937be  e8e99c0100             -call 0x4ad4ac
    cpu.esp -= 4;
    sub_4ad4ac(app, cpu);
    if (cpu.terminate) return;
    // 004937c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004937c5  74f0                   -je 0x4937b7
    if (cpu.flags.zf)
    {
        goto L_0x004937b7;
    }
    // 004937c7  e8fbfbfeff             -call 0x4833c7
    cpu.esp -= 4;
    sub_4833c7(app, cpu);
    if (cpu.terminate) return;
    // 004937cc  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004937d0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004937d2  7e4f                   -jle 0x493823
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493823;
    }
    // 004937d4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004937d6:
    // 004937d6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004937d9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004937db  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004937dd  e8ca9c0100             -call 0x4ad4ac
    cpu.esp -= 4;
    sub_4ad4ac(app, cpu);
    if (cpu.terminate) return;
    // 004937e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004937e4  7533                   -jne 0x493819
    if (!cpu.flags.zf)
    {
        goto L_0x00493819;
    }
    // 004937e6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004937e8  e8c306ffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 004937ed  ebe7                   -jmp 0x4937d6
    goto L_0x004937d6;
L_0x004937ef:
    // 004937ef  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004937f3  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004937f7  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004937fb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004937fc  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493800  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493802  e8199c0100             -call 0x4ad420
    cpu.esp -= 4;
    sub_4ad420(app, cpu);
    if (cpu.terminate) return;
    // 00493807  e96affffff             -jmp 0x493776
    goto L_0x00493776;
L_0x0049380c:
    // 0049380c  c744240800000400       -mov dword ptr [esp + 8], 0x40000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 262144 /*0x40000*/;
    // 00493814  e979ffffff             -jmp 0x493792
    goto L_0x00493792;
L_0x00493819:
    // 00493819  81ef00200000           -sub edi, 0x2000
    (cpu.edi) -= x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 0049381f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00493821  7fb3                   -jg 0x4937d6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004937d6;
    }
L_0x00493823:
    // 00493823  e89ffbfeff             -call 0x4833c7
    cpu.esp -= 4;
    sub_4833c7(app, cpu);
    if (cpu.terminate) return;
    // 00493828  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049382a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0049382c:
    // 0049382c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493830  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00493832  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00493834  e8739c0100             -call 0x4ad4ac
    cpu.esp -= 4;
    sub_4ad4ac(app, cpu);
    if (cpu.terminate) return;
    // 00493839  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049383b  7509                   -jne 0x493846
    if (!cpu.flags.zf)
    {
        goto L_0x00493846;
    }
    // 0049383d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049383f  e86c06ffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00493844  ebe6                   -jmp 0x49382c
    goto L_0x0049382c;
L_0x00493846:
    // 00493846  e87cfbfeff             -call 0x4833c7
    cpu.esp -= 4;
    sub_4833c7(app, cpu);
    if (cpu.terminate) return;
    // 0049384b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049384d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00493850  e8f79b0100             -call 0x4ad44c
    cpu.esp -= 4;
    sub_4ad44c(app, cpu);
    if (cpu.terminate) return;
    // 00493855  837c241c00             +cmp dword ptr [esp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049385a  7409                   -je 0x493865
    if (cpu.flags.zf)
    {
        goto L_0x00493865;
    }
    // 0049385c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493860  e8e79b0100             -call 0x4ad44c
    cpu.esp -= 4;
    sub_4ad44c(app, cpu);
    if (cpu.terminate) return;
L_0x00493865:
    // 00493865  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493867  e89010ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0049386c  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00493873  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 00493876  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493878  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049387b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049387f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493881  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00493884  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00493886  a3cce95600             -mov dword ptr [0x56e9cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */) = cpu.eax;
    // 0049388b  83f801                 +cmp eax, 1
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
    // 0049388e  7d0a                   -jge 0x49389a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049389a;
    }
    // 00493890  c705cce9560001000000   -mov dword ptr [0x56e9cc], 1
    app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */) = 1 /*0x1*/;
L_0x0049389a:
    // 0049389a  b80000e803             -mov eax, 0x3e80000
    cpu.eax = 65536000 /*0x3e80000*/;
    // 0049389f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004938a1  8b0dcce95600           -mov ecx, dword ptr [0x56e9cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */);
    // 004938a7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004938aa  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004938ac  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004938b0  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 004938b7  a3d0e95600             -mov dword ptr [0x56e9d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */) = cpu.eax;
    // 004938bc  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004938be  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004938c2  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004938c4  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004938c7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004938ca  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004938cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004938ce  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004938d1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004938d3  a33cce4d00             -mov dword ptr [0x4dce3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5099068) /* 0x4dce3c */) = cpu.eax;
    // 004938d8  3dda000000             +cmp eax, 0xda
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(218 /*0xda*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004938dd  7f25                   -jg 0x493904
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00493904;
    }
    // 004938df  3da3000000             +cmp eax, 0xa3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(163 /*0xa3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004938e4  7c2a                   -jl 0x493910
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493910;
    }
L_0x004938e6:
    // 004938e6  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004938ed  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004938ef  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004938f1  a340ce4d00             -mov dword ptr [0x4dce40], eax
    app->getMemory<x86::reg32>(x86::reg32(5099072) /* 0x4dce40 */) = cpu.eax;
    // 004938f6  a1d0e95600             -mov eax, dword ptr [0x56e9d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */);
    // 004938fb  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004938fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004938ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493900  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493901  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493902  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493903  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493904:
    // 00493904  c7053cce4d00da000000   -mov dword ptr [0x4dce3c], 0xda
    app->getMemory<x86::reg32>(x86::reg32(5099068) /* 0x4dce3c */) = 218 /*0xda*/;
    // 0049390e  ebd6                   -jmp 0x4938e6
    goto L_0x004938e6;
L_0x00493910:
    // 00493910  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00493915  890db0d34d00           -mov dword ptr [0x4dd3b0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5100464) /* 0x4dd3b0 */) = cpu.ecx;
    // 0049391b  890d3cce4d00           -mov dword ptr [0x4dce3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5099068) /* 0x4dce3c */) = cpu.ecx;
    // 00493921  ebc3                   -jmp 0x4938e6
    goto L_0x004938e6;
}

/* align: skip 0x90 */
void Application::sub_493924(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493924);
    // 00493924  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493925  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493926  bada000000             -mov edx, 0xda
    cpu.edx = 218 /*0xda*/;
    // 0049392b  b92c010000             -mov ecx, 0x12c
    cpu.ecx = 300 /*0x12c*/;
    // 00493930  89153cce4d00           -mov dword ptr [0x4dce3c], edx
    app->getMemory<x86::reg32>(x86::reg32(5099068) /* 0x4dce3c */) = cpu.edx;
    // 00493936  890d40ce4d00           -mov dword ptr [0x4dce40], ecx
    app->getMemory<x86::reg32>(x86::reg32(5099072) /* 0x4dce40 */) = cpu.ecx;
    // 0049393c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049393d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049393e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493940);
    // 00493940  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493941  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493942  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00493944  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049394a  39d0                   +cmp eax, edx
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
    // 0049394c  7403                   -je 0x493951
    if (cpu.flags.zf)
    {
        goto L_0x00493951;
    }
    // 0049394e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049394f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493950  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493951:
    // 00493951  c7422408000000         -mov dword ptr [edx + 0x24], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 8 /*0x8*/;
    // 00493958  8b92a8000000           -mov edx, dword ptr [edx + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 0049395e  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00493963  e8b864ffff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00493968  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 0049396e  e8e964ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00493973  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 00493979  e86a65ffff             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 0049397e  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00493984  e8eb65ffff             -call 0x489f74
    cpu.esp -= 4;
    sub_489f74(app, cpu);
    if (cpu.terminate) return;
    // 00493989  c781ac00000000000000   -mov dword ptr [ecx + 0xac], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 00493993  8d818c000000           -lea eax, [ecx + 0x8c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 00493999  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049399b  e8d061ffff             -call 0x489b70
    cpu.esp -= 4;
    sub_489b70(app, cpu);
    if (cpu.terminate) return;
    // 004939a0  890d4cce4d00           -mov dword ptr [0x4dce4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */) = cpu.ecx;
    // 004939a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004939a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004939a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4939ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004939ac);
    // 004939ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004939ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004939ae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004939af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004939b1  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004939b7  39c8                   +cmp eax, ecx
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
    // 004939b9  7440                   -je 0x4939fb
    if (cpu.flags.zf)
    {
        goto L_0x004939fb;
    }
    // 004939bb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004939bd  83797000               +cmp dword ptr [ecx + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004939c1  740e                   -je 0x4939d1
    if (cpu.flags.zf)
    {
        goto L_0x004939d1;
    }
L_0x004939c3:
    // 004939c3  3b5070                 +cmp edx, dword ptr [eax + 0x70]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004939c6  7409                   -je 0x4939d1
    if (cpu.flags.zf)
    {
        goto L_0x004939d1;
    }
    // 004939c8  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004939cb  83787000               +cmp dword ptr [eax + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004939cf  75f2                   -jne 0x4939c3
    if (!cpu.flags.zf)
    {
        goto L_0x004939c3;
    }
L_0x004939d1:
    // 004939d1  8b4a70                 -mov ecx, dword ptr [edx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 004939d4  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 004939d7  8b8288000000           -mov eax, dword ptr [edx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 004939dd  e81a0fffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004939e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004939e4  e8130fffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004939e9  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004939eb  892d50ce4d00           -mov dword ptr [0x4dce50], ebp
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.ebp;
    // 004939f1  892d4cce4d00           -mov dword ptr [0x4dce4c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */) = cpu.ebp;
    // 004939f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004939f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004939f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004939fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004939fb:
    // 004939fb  e840ffffff             -call 0x493940
    cpu.esp -= 4;
    sub_493940(app, cpu);
    if (cpu.terminate) return;
L_0x00493a00:
    // 00493a00  8b4970                 -mov ecx, dword ptr [ecx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 00493a03  8b8288000000           -mov eax, dword ptr [edx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 00493a09  e8ee0effff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00493a0e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493a10  e8e70effff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00493a15  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00493a17  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493a19  75e5                   -jne 0x493a00
    if (!cpu.flags.zf)
    {
        goto L_0x00493a00;
    }
    // 00493a1b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493a1d  892d50ce4d00           -mov dword ptr [0x4dce50], ebp
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.ebp;
    // 00493a23  892d4cce4d00           -mov dword ptr [0x4dce4c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */) = cpu.ebp;
    // 00493a29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a2a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493a30);
    // 00493a30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493a31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493a32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493a33  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493a35  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00493a37  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00493a39  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00493a3d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00493a43  e80065ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00493a48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493a4a  e8c51c0000             -call 0x495714
    cpu.esp -= 4;
    sub_495714(app, cpu);
    if (cpu.terminate) return;
    // 00493a4f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00493a51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493a53  746a                   -je 0x493abf
    if (cpu.flags.zf)
    {
        goto L_0x00493abf;
    }
    // 00493a55  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00493a5a  e87d2affff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 00493a5f  c6818e00000000         -mov byte ptr [ecx + 0x8e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
    // 00493a66  89b994000000           -mov dword ptr [ecx + 0x94], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 00493a6c  89a990000000           -mov dword ptr [ecx + 0x90], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.ebp;
    // 00493a72  837e7c00               +cmp dword ptr [esi + 0x7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493a76  7456                   -je 0x493ace
    if (cpu.flags.zf)
    {
        goto L_0x00493ace;
    }
    // 00493a78  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00493a7b  898898000000           -mov dword ptr [eax + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 00493a81  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
L_0x00493a84:
    // 00493a84  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 00493a89  740d                   -je 0x493a98
    if (cpu.flags.zf)
    {
        goto L_0x00493a98;
    }
    // 00493a8b  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 00493a8f  7507                   -jne 0x493a98
    if (!cpu.flags.zf)
    {
        goto L_0x00493a98;
    }
    // 00493a91  c746240f000000         -mov dword ptr [esi + 0x24], 0xf
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 15 /*0xf*/;
L_0x00493a98:
    // 00493a98  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00493a9e  e8bd64ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00493aa3  8b96a8000000           -mov edx, dword ptr [esi + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 00493aa9  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00493aaf  e86c63ffff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00493ab4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00493ab9:
    // 00493ab9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493aba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493abb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493abc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00493abf:
    // 00493abf  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00493ac5  e89664ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00493aca  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00493acc  ebeb                   -jmp 0x493ab9
    goto L_0x00493ab9;
L_0x00493ace:
    // 00493ace  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 00493ad1  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00493ad4  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00493ad7  ebab                   -jmp 0x493a84
    goto L_0x00493a84;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493adc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493adc);
    // 00493adc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493add  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493ade  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493adf  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493ae2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493ae4  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00493ae6  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00493ae8  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00493aeb  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00493aef  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00493af5  e84e64ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00493afa  837e7800               +cmp dword ptr [esi + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493afe  7418                   -je 0x493b18
    if (cpu.flags.zf)
    {
        goto L_0x00493b18;
    }
L_0x00493b00:
    // 00493b00  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00493b03  8b9098000000           -mov edx, dword ptr [eax + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 00493b09  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 00493b0c  e8231b0000             -call 0x495634
    cpu.esp -= 4;
    sub_495634(app, cpu);
    if (cpu.terminate) return;
    // 00493b11  837e7800               +cmp dword ptr [esi + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b15  75e9                   -jne 0x493b00
    if (!cpu.flags.zf)
    {
        goto L_0x00493b00;
    }
    // 00493b17  90                     -nop 
    ;
L_0x00493b18:
    // 00493b18  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493b1a  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00493b1f  e8f01b0000             -call 0x495714
    cpu.esp -= 4;
    sub_495714(app, cpu);
    if (cpu.terminate) return;
    // 00493b24  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00493b26  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00493b28  e8af29ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 00493b2d  c6818e00000000         -mov byte ptr [ecx + 0x8e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
    // 00493b34  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00493b37  89b994000000           -mov dword ptr [ecx + 0x94], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 00493b3d  898190000000           -mov dword ptr [ecx + 0x90], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00493b43  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 00493b46  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00493b49  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00493b4c  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b50  740d                   -je 0x493b5f
    if (cpu.flags.zf)
    {
        goto L_0x00493b5f;
    }
    // 00493b52  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 00493b56  7507                   -jne 0x493b5f
    if (!cpu.flags.zf)
    {
        goto L_0x00493b5f;
    }
    // 00493b58  c746240f000000         -mov dword ptr [esi + 0x24], 0xf
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 15 /*0xf*/;
L_0x00493b5f:
    // 00493b5f  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00493b65  e8f663ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00493b6a  8b96a8000000           -mov edx, dword ptr [esi + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 00493b70  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00493b76  e8a562ffff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00493b7b  83ff0b                 +cmp edi, 0xb
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b7e  7418                   -je 0x493b98
    if (cpu.flags.zf)
    {
        goto L_0x00493b98;
    }
    // 00493b80  83ff0d                 +cmp edi, 0xd
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b83  7413                   -je 0x493b98
    if (cpu.flags.zf)
    {
        goto L_0x00493b98;
    }
    // 00493b85  83ff14                 +cmp edi, 0x14
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b88  740e                   -je 0x493b98
    if (cpu.flags.zf)
    {
        goto L_0x00493b98;
    }
    // 00493b8a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00493b8f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493b92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b95  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00493b98:
    // 00493b98  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 00493b9e  e8b962ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00493ba3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00493ba8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493bab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bae  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493bb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493bb4);
    // 00493bb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493bb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493bb6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493bb8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00493bbd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493bbf  e818ffffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493bc4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bc5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493bc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493bc8);
    // 00493bc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493bc9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493bca  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493bcc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00493bd1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493bd3  e804ffffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493bd8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bd9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493bdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493bdc);
    // 00493bdc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493bdd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493bde  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493be0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493be2  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00493be7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493be9  e842feffff             -call 0x493a30
    cpu.esp -= 4;
    sub_493a30(app, cpu);
    if (cpu.terminate) return;
    // 00493bee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493bf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493bf4);
    // 00493bf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493bf5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493bf6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493bf8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493bfa  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00493bff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c01  e82afeffff             -call 0x493a30
    cpu.esp -= 4;
    sub_493a30(app, cpu);
    if (cpu.terminate) return;
    // 00493c06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493c0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493c0c);
    // 00493c0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493c0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c0e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493c10  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 00493c15  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c17  e8c0feffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493c1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493c20);
    // 00493c20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493c21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c22  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493c24  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 00493c29  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c2b  e8acfeffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493c30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493c34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493c34);
    // 00493c34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493c35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c36  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493c38  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 00493c3d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c3f  e898feffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493c44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493c48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493c48);
    // 00493c48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493c49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c4a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493c4c  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 00493c51  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c53  e884feffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493c58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493c5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493c5c);
    // 00493c5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493c5d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c5e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493c60  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493c62  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 00493c67  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c69  e8c2fdffff             -call 0x493a30
    cpu.esp -= 4;
    sub_493a30(app, cpu);
    if (cpu.terminate) return;
    // 00493c6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493c74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493c74);
    // 00493c74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493c75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c76  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493c78  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493c7a  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 00493c7f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c81  e8aafdffff             -call 0x493a30
    cpu.esp -= 4;
    sub_493a30(app, cpu);
    if (cpu.terminate) return;
    // 00493c86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493c8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493c8c);
    // 00493c8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493c8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c8e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493c90  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00493c95  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c97  e840feffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493c9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493ca0);
    // 00493ca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493ca1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493ca2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493ca4  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00493ca9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493cab  e82cfeffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493cb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493cb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493cb4);
    // 00493cb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493cb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493cb6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493cb8  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00493cbd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493cbf  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00493cc1  ba0c074d00             -mov edx, 0x4d070c
    cpu.edx = 5048076 /*0x4d070c*/;
    // 00493cc6  e865fdffff             -call 0x493a30
    cpu.esp -= 4;
    sub_493a30(app, cpu);
    if (cpu.terminate) return;
    // 00493ccb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ccc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ccd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493cd0);
    // 00493cd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493cd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493cd2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493cd4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00493cd9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493cdb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00493cdd  ba0c074d00             -mov edx, 0x4d070c
    cpu.edx = 5048076 /*0x4d070c*/;
    // 00493ce2  e849fdffff             -call 0x493a30
    cpu.esp -= 4;
    sub_493a30(app, cpu);
    if (cpu.terminate) return;
    // 00493ce7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ce8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ce9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493cec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493cec);
    // 00493cec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493ced  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493cee  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493cf0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00493cf5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493cf7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00493cf9  ba0c074d00             -mov edx, 0x4d070c
    cpu.edx = 5048076 /*0x4d070c*/;
    // 00493cfe  e82dfdffff             -call 0x493a30
    cpu.esp -= 4;
    sub_493a30(app, cpu);
    if (cpu.terminate) return;
    // 00493d03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493d08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493d08);
    // 00493d08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493d09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493d0a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493d0c  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00493d11  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493d13  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00493d15  ba0c074d00             -mov edx, 0x4d070c
    cpu.edx = 5048076 /*0x4d070c*/;
    // 00493d1a  e811fdffff             -call 0x493a30
    cpu.esp -= 4;
    sub_493a30(app, cpu);
    if (cpu.terminate) return;
    // 00493d1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d20  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493d24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493d24);
    // 00493d24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493d25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493d26  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00493d28  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 00493d2d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00493d2f  ba0c074d00             -mov edx, 0x4d070c
    cpu.edx = 5048076 /*0x4d070c*/;
    // 00493d34  e8a3fdffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493d39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493d3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493d3c);
    // 00493d3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493d3d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493d3e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493d40  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 00493d45  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00493d47  ba0c074d00             -mov edx, 0x4d070c
    cpu.edx = 5048076 /*0x4d070c*/;
    // 00493d4c  e88bfdffff             -call 0x493adc
    cpu.esp -= 4;
    sub_493adc(app, cpu);
    if (cpu.terminate) return;
    // 00493d51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493d54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493d54);
    // 00493d54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493d55  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493d56  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493d57  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00493d59  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493d5b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00493d61  e8e261ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00493d66  837a7800               +cmp dword ptr [edx + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493d6a  7418                   -je 0x493d84
    if (cpu.flags.zf)
    {
        goto L_0x00493d84;
    }
L_0x00493d6c:
    // 00493d6c  41                     -inc ecx
    (cpu.ecx)++;
    // 00493d6d  8b4278                 -mov eax, dword ptr [edx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 00493d70  8b9898000000           -mov ebx, dword ptr [eax + 0x98]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 00493d76  895a78                 -mov dword ptr [edx + 0x78], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = cpu.ebx;
    // 00493d79  e8b6180000             -call 0x495634
    cpu.esp -= 4;
    sub_495634(app, cpu);
    if (cpu.terminate) return;
    // 00493d7e  837a7800               +cmp dword ptr [edx + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493d82  75e8                   -jne 0x493d6c
    if (!cpu.flags.zf)
    {
        goto L_0x00493d6c;
    }
L_0x00493d84:
    // 00493d84  8b4278                 -mov eax, dword ptr [edx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 00493d87  89427c                 -mov dword ptr [edx + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 00493d8a  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00493d90  e8cb61ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00493d95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493d97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493d9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493d9c);
    // 00493d9c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493d9d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493d9e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00493da0  8bb084000000           -mov esi, dword ptr [eax + 0x84]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 00493da6  89703c                 -mov dword ptr [eax + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 00493da9  8bb088000000           -mov esi, dword ptr [eax + 0x88]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 00493daf  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00493db2  8bb088000000           -mov esi, dword ptr [eax + 0x88]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 00493db8  8bb884000000           -mov edi, dword ptr [eax + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 00493dbe  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00493dc0  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00493dc3  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493dc6  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00493dc9  8b7018                 -mov esi, dword ptr [eax + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00493dcc  897014                 -mov dword ptr [eax + 0x14], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00493dcf  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00493dd2  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00493dd5  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00493dd8  897010                 -mov dword ptr [eax + 0x10], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00493ddb  c780bc00000000000000   -mov dword ptr [eax + 0xbc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 00493de5  8bb0bc000000           -mov esi, dword ptr [eax + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 00493deb  89b0b8000000           -mov dword ptr [eax + 0xb8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.esi;
    // 00493df1  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00493df8  c7404000000000         -mov dword ptr [eax + 0x40], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00493dff  c7405c00000000         -mov dword ptr [eax + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 00493e06  c7405401000000         -mov dword ptr [eax + 0x54], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 1 /*0x1*/;
    // 00493e0d  89586c                 -mov dword ptr [eax + 0x6c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 00493e10  895068                 -mov dword ptr [eax + 0x68], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 00493e13  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00493e19  8b9aac000000           -mov ebx, dword ptr [edx + 0xac]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00493e1f  8998ac000000           -mov dword ptr [eax + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 00493e25  8b9aa8000000           -mov ebx, dword ptr [edx + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 00493e2b  8998a8000000           -mov dword ptr [eax + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 00493e31  8db88c000000           -lea edi, [eax + 0x8c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 00493e37  8db28c000000           -lea esi, [edx + 0x8c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(140) /* 0x8c */);
    // 00493e3d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00493e3e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00493e3f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00493e40  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00493e41  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00493e42  8b9aa4000000           -mov ebx, dword ptr [edx + 0xa4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 00493e48  8998a4000000           -mov dword ptr [eax + 0xa4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = cpu.ebx;
    // 00493e4e  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00493e54  e8ef60ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00493e59  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00493e5e  83787000               +cmp dword ptr [eax + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493e62  740c                   -je 0x493e70
    if (cpu.flags.zf)
    {
        goto L_0x00493e70;
    }
L_0x00493e64:
    // 00493e64  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00493e67  83787000               +cmp dword ptr [eax + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493e6b  75f7                   -jne 0x493e64
    if (!cpu.flags.zf)
    {
        goto L_0x00493e64;
    }
    // 00493e6d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00493e70:
    // 00493e70  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 00493e73  c7417000000000         -mov dword ptr [ecx + 0x70], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 00493e7a  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00493e7f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00493e85  e8d660ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00493e8a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493e8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493e90);
    // 00493e90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493e91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493e92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493e93  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493e96  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00493e99  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00493e9b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00493e9d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00493e9f  66f7c3ff0f             +test bx, 0xfff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & 4095 /*0xfff*/));
    // 00493ea4  740c                   -je 0x493eb2
    if (cpu.flags.zf)
    {
        goto L_0x00493eb2;
    }
    // 00493ea6  8d8b00100000           -lea ecx, [ebx + 0x1000]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(4096) /* 0x1000 */);
    // 00493eac  81e100f0ff7f           -and ecx, 0x7ffff000
    cpu.ecx &= x86::reg32(x86::sreg32(2147479552 /*0x7ffff000*/));
L_0x00493eb2:
    // 00493eb2  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00493eb7  b850064d00             -mov eax, 0x4d0650
    cpu.eax = 5047888 /*0x4d0650*/;
    // 00493ebc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00493ebe  e8ed05ffff             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 00493ec3  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 00493ec8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00493eca  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00493ecc  b810074d00             -mov eax, 0x4d0710
    cpu.eax = 5048080 /*0x4d0710*/;
    // 00493ed1  e8c205ffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00493ed6  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 00493edb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493edd  e83a61ffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00493ee2  89be88000000           -mov dword ptr [esi + 0x88], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.edi;
    // 00493ee8  898e84000000           -mov dword ptr [esi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 00493eee  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 00493ef3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00493ef5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493ef7  e894890000             -call 0x49c890
    cpu.esp -= 4;
    sub_49c890(app, cpu);
    if (cpu.terminate) return;
    // 00493efc  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 00493f01  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 00493f06  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493f08  b9c0000000             -mov ecx, 0xc0
    cpu.ecx = 192 /*0xc0*/;
    // 00493f0d  e87e890000             -call 0x49c890
    cpu.esp -= 4;
    sub_49c890(app, cpu);
    if (cpu.terminate) return;
    // 00493f12  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00493f15  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00493f17  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493f19  e87efeffff             -call 0x493d9c
    cpu.esp -= 4;
    sub_493d9c(app, cpu);
    if (cpu.terminate) return;
    // 00493f1e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493f21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493f78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00493f78);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00493f78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493f79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493f7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493f7b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493f7c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493f7d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493f7e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493f81  e8865effff             -call 0x489e0c
    cpu.esp -= 4;
    sub_489e0c(app, cpu);
    if (cpu.terminate) return;
    // 00493f86  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00493f8c  8982a8000000           -mov dword ptr [edx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 00493f92  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 00493f98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493f9a  e8815effff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00493f9f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00493fa4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
  [[fallthrough]];
  case 0x00493fa6:
L_0x00493fa6:
    // 00493fa6  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00493fab  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00493fb1  e8925fffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00493fb6  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00493fbb  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00493fbe  83fa08                 +cmp edx, 8
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
    // 00493fc1  0f848f000000           -je 0x494056
    if (cpu.flags.zf)
    {
        goto L_0x00494056;
    }
    // 00493fc7  8378240f               +cmp dword ptr [eax + 0x24], 0xf
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493fcb  7507                   -jne 0x493fd4
    if (!cpu.flags.zf)
    {
        goto L_0x00493fd4;
    }
    // 00493fcd  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x00493fd4:
    // 00493fd4  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00493fd9  896824                 -mov dword ptr [eax + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 00493fdc  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00493fe2  e8795fffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00493fe7  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00493fec  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00493fef  4a                     -dec edx
    (cpu.edx)--;
    // 00493ff0  83fa13                 +cmp edx, 0x13
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
    // 00493ff3  77b1                   -ja 0x493fa6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 00493ff5  ff2495283f4900         -jmp dword ptr [edx*4 + 0x493f28]
    cpu.ip = app->getMemory<x86::reg32>(4800296 + cpu.edx * 4); goto dynamic_jump;
  case 0x00493ffc:
    // 00493ffc  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494001  3b681c                 +cmp ebp, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494004  7408                   -je 0x49400e
    if (cpu.flags.zf)
    {
        goto L_0x0049400e;
    }
    // 00494006  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494009  e83e940100             -call 0x4ad44c
    cpu.esp -= 4;
    sub_4ad44c(app, cpu);
    if (cpu.terminate) return;
L_0x0049400e:
    // 0049400e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494010  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494011  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494016  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 00494019  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0049401c  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049401f  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00494025  e8f6930100             -call 0x4ad420
    cpu.esp -= 4;
    sub_4ad420(app, cpu);
    if (cpu.terminate) return;
    // 0049402a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049402c  0f8539010000           -jne 0x49416b
    if (!cpu.flags.zf)
    {
        goto L_0x0049416b;
    }
L_0x00494032:
    // 00494032  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494037  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0049403d  e8f2150000             -call 0x495634
    cpu.esp -= 4;
    sub_495634(app, cpu);
    if (cpu.terminate) return;
    // 00494042  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494047  89681c                 -mov dword ptr [eax + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0049404a  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00494051  e950ffffff             -jmp 0x493fa6
    goto L_0x00493fa6;
L_0x00494056:
    // 00494056  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00494059  e976ffffff             -jmp 0x493fd4
    goto L_0x00493fd4;
  case 0x0049405e:
    // 0049405e  e8a9120000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 00494063  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494068  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049406b  752e                   -jne 0x49409b
    if (!cpu.flags.zf)
    {
        goto L_0x0049409b;
    }
    // 0049406d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494070  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494072  e8095afcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494077  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049407c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494082  e8d55dffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494087  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049408c  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049408f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494091  e8ea59fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494096  e90bffffff             -jmp 0x493fa6
    goto L_0x00493fa6;
L_0x0049409b:
    // 0049409b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004940a1  e8a25effff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004940a6  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004940ac  8b4178                 -mov eax, dword ptr [ecx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 004940af  8b5178                 -mov edx, dword ptr [ecx + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 004940b2  8b9298000000           -mov edx, dword ptr [edx + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */);
    // 004940b8  895178                 -mov dword ptr [ecx + 0x78], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 004940bb  898180000000           -mov dword ptr [ecx + 0x80], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 004940c1  8b5978                 -mov ebx, dword ptr [ecx + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 004940c4  39dd                   +cmp ebp, ebx
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
    // 004940c6  7503                   -jne 0x4940cb
    if (!cpu.flags.zf)
    {
        goto L_0x004940cb;
    }
    // 004940c8  89597c                 -mov dword ptr [ecx + 0x7c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.ebx;
L_0x004940cb:
    // 004940cb  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004940d1  8b8894000000           -mov ecx, dword ptr [eax + 0x94]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 004940d7  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004940da  8b4a50                 -mov ecx, dword ptr [edx + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 004940dd  8bb090000000           -mov esi, dword ptr [eax + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */);
    // 004940e3  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004940e5  894a60                 -mov dword ptr [edx + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 004940e8  8b9094000000           -mov edx, dword ptr [eax + 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 004940ee  83fa0d                 +cmp edx, 0xd
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
    // 004940f1  7515                   -jne 0x494108
    if (!cpu.flags.zf)
    {
        goto L_0x00494108;
    }
L_0x004940f3:
    // 004940f3  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004940f8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004940fe  e85d5effff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00494103  e99efeffff             -jmp 0x493fa6
    goto L_0x00493fa6;
L_0x00494108:
    // 00494108  83fa14                 +cmp edx, 0x14
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049410b  74e6                   -je 0x4940f3
    if (cpu.flags.zf)
    {
        goto L_0x004940f3;
    }
    // 0049410d  39d7                   +cmp edi, edx
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
    // 0049410f  74e2                   -je 0x4940f3
    if (cpu.flags.zf)
    {
        goto L_0x004940f3;
    }
    // 00494111  83fa11                 +cmp edx, 0x11
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494114  74dd                   -je 0x4940f3
    if (cpu.flags.zf)
    {
        goto L_0x004940f3;
    }
    // 00494116  83fa12                 +cmp edx, 0x12
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494119  74d8                   -je 0x4940f3
    if (cpu.flags.zf)
    {
        goto L_0x004940f3;
    }
    // 0049411b  83fa13                 +cmp edx, 0x13
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
    // 0049411e  74d3                   -je 0x4940f3
    if (cpu.flags.zf)
    {
        goto L_0x004940f3;
    }
    // 00494120  e80f150000             -call 0x495634
    cpu.esp -= 4;
    sub_495634(app, cpu);
    if (cpu.terminate) return;
    // 00494125  ebcc                   -jmp 0x4940f3
    goto L_0x004940f3;
  case 0x00494127:
    // 00494127  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 0049412b  7534                   -jne 0x494161
    if (!cpu.flags.zf)
    {
        goto L_0x00494161;
    }
L_0x0049412d:
    // 0049412d  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494132  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00494139  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0049413f  e8a45dffff             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 00494144  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049414a  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 00494150  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494152  e8c95cffff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00494157  83c404                 +add esp, 4
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
    // 0049415a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049415b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049415c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049415d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049415e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049415f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494160  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494161:
    // 00494161  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494164  e8e3920100             -call 0x4ad44c
    cpu.esp -= 4;
    sub_4ad44c(app, cpu);
    if (cpu.terminate) return;
    // 00494169  ebc2                   -jmp 0x49412d
    goto L_0x0049412d;
L_0x0049416b:
    // 0049416b  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494170  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00494176  e8b9140000             -call 0x495634
    cpu.esp -= 4;
    sub_495634(app, cpu);
    if (cpu.terminate) return;
    // 0049417b  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494180  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494186  e8bd5dffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049418b  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494191  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00494194  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494197  7e67                   -jle 0x494200
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494200;
    }
    // 00494199  89b9a0000000           -mov dword ptr [ecx + 0xa0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edi;
L_0x0049419f:
    // 0049419f  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004941a2  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004941a7  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004941aa  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 004941ad  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004941b0  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004941b3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004941b5  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004941b8  3b7820                 +cmp edi, dword ptr [eax + 0x20]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004941bb  7567                   -jne 0x494224
    if (!cpu.flags.zf)
    {
        goto L_0x00494224;
    }
L_0x004941bd:
    // 004941bd  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004941c2  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004941c5  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004941c8  89a8b8000000           -mov dword ptr [eax + 0xb8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
L_0x004941ce:
    // 004941ce  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004941d3  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004941d6  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004941d9  83782013               +cmp dword ptr [eax + 0x20], 0x13
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004941dd  754d                   -jne 0x49422c
    if (!cpu.flags.zf)
    {
        goto L_0x0049422c;
    }
L_0x004941df:
    // 004941df  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004941e4  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x004941eb:
    // 004941eb  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004941f0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004941f6  e8655dffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004941fb  e9a6fdffff             -jmp 0x493fa6
    goto L_0x00493fa6;
L_0x00494200:
    // 00494200  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00494203  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00494206  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494209  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049420c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049420e  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00494214  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494216  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0049421c  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0049421f  e97bffffff             -jmp 0x49419f
    goto L_0x0049419f;
L_0x00494224:
    // 00494224  83782012               +cmp dword ptr [eax + 0x20], 0x12
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494228  7493                   -je 0x4941bd
    if (cpu.flags.zf)
    {
        goto L_0x004941bd;
    }
    // 0049422a  eba2                   -jmp 0x4941ce
    goto L_0x004941ce;
L_0x0049422c:
    // 0049422c  83782012               +cmp dword ptr [eax + 0x20], 0x12
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494230  74ad                   -je 0x4941df
    if (cpu.flags.zf)
    {
        goto L_0x004941df;
    }
    // 00494232  c7402010000000         -mov dword ptr [eax + 0x20], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 16 /*0x10*/;
    // 00494239  ebb0                   -jmp 0x4941eb
    goto L_0x004941eb;
  case 0x0049423b:
    // 0049423b  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494240  3b681c                 +cmp ebp, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494243  7408                   -je 0x49424d
    if (cpu.flags.zf)
    {
        goto L_0x0049424d;
    }
    // 00494245  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494248  e8ff910100             -call 0x4ad44c
    cpu.esp -= 4;
    sub_4ad44c(app, cpu);
    if (cpu.terminate) return;
L_0x0049424d:
    // 0049424d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049424f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494250  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494255  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 00494258  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0049425b  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049425e  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00494264  e8b7910100             -call 0x4ad420
    cpu.esp -= 4;
    sub_4ad420(app, cpu);
    if (cpu.terminate) return;
    // 00494269  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049426b  0f84c1fdffff           -je 0x494032
    if (cpu.flags.zf)
    {
        goto L_0x00494032;
    }
    // 00494271  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494276  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0049427c  e8b3130000             -call 0x495634
    cpu.esp -= 4;
    sub_495634(app, cpu);
    if (cpu.terminate) return;
    // 00494281  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494286  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0049428c  e8b75cffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494291  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494297  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049429a  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049429d  0f8eb8010000           -jle 0x49445b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049445b;
    }
    // 004942a3  89b9a0000000           -mov dword ptr [ecx + 0xa0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edi;
L_0x004942a9:
    // 004942a9  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004942ac  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004942b1  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004942b4  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 004942b7  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004942ba  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004942bd  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004942bf  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004942c2  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004942c8  e8935cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x004942cd:
    // 004942cd  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004942d2  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
    // 004942d7  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004942dd  e8665cffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004942e2  3b2d50ce4d00           +cmp ebp, dword ptr [0x4dce50]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004942e8  743b                   -je 0x494325
    if (cpu.flags.zf)
    {
        goto L_0x00494325;
    }
L_0x004942ea:
    // 004942ea  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004942ef  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004942f2  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004942f5  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004942f8  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004942fb  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004942fe  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00494301  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00494304  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00494307  89a8bc000000           -mov dword ptr [eax + 0xbc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.ebp;
    // 0049430d  8b90bc000000           -mov edx, dword ptr [eax + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 00494313  8990b8000000           -mov dword ptr [eax + 0xb8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.edx;
    // 00494319  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0049431c  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
    // 00494321  39c5                   +cmp ebp, eax
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
    // 00494323  75c5                   -jne 0x4942ea
    if (!cpu.flags.zf)
    {
        goto L_0x004942ea;
    }
L_0x00494325:
    // 00494325  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049432a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494330  e82b5cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00494335  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049433a  83782014               +cmp dword ptr [eax + 0x20], 0x14
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049433e  0f843b010000           -je 0x49447f
    if (cpu.flags.zf)
    {
        goto L_0x0049447f;
    }
    // 00494344  c7402002000000         -mov dword ptr [eax + 0x20], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 0049434b  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 00494351  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494353  e8c85affff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x00494358:
    // 00494358  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049435d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494363  e8e05bffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494368  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049436d  83782002               +cmp dword ptr [eax + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494371  0f8521010000           -jne 0x494498
    if (!cpu.flags.zf)
    {
        goto L_0x00494498;
    }
    // 00494377  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049437a  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049437d  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494380  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00494383  89a8b8000000           -mov dword ptr [eax + 0xb8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
L_0x00494389:
    // 00494389  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049438e  8b5060                 -mov edx, dword ptr [eax + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 00494391  89505c                 -mov dword ptr [eax + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 00494394  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0049439a  e8c15bffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049439f  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004943a4  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004943a7  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004943aa  e82d910100             -call 0x4ad4dc
    cpu.esp -= 4;
    sub_4ad4dc(app, cpu);
    if (cpu.terminate) return;
    // 004943af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004943b1  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004943b6  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004943bc  e8875bffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004943c1  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004943c6  8b485c                 -mov ecx, dword ptr [eax + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004943c9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004943cb  8988b0000000           -mov dword ptr [eax + 0xb0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = cpu.ecx;
    // 004943d1  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004943d4  8b88b0000000           -mov ecx, dword ptr [eax + 0xb0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 004943da  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004943dc  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004943df  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004943e5  e8765bffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004943ea  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004943f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004943f2  e8150f0000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 004943f7  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004943fa  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004943fd  3b4240                 +cmp eax, dword ptr [edx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494400  0f8f4e010000           -jg 0x494554
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494554;
    }
L_0x00494406:
    // 00494406  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049440c  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049440f  0f858e000000           -jne 0x4944a3
    if (!cpu.flags.zf)
    {
        goto L_0x004944a3;
    }
    // 00494415  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494417  e8f00e0000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 0049441c  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049441f  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00494422  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00494424  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494426  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049442b  e8500f0000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00494430  39c2                   +cmp edx, eax
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
    // 00494432  746f                   -je 0x4944a3
    if (cpu.flags.zf)
    {
        goto L_0x004944a3;
    }
    // 00494434  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494439  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0049443f  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494442  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494444  e83756fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494449  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049444e  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494454  e8035affff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494459  ebab                   -jmp 0x494406
    goto L_0x00494406;
L_0x0049445b:
    // 0049445b  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0049445e  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00494461  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494464  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00494467  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00494469  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0049446f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494471  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 00494477  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0049447a  e92afeffff             -jmp 0x4942a9
    goto L_0x004942a9;
L_0x0049447f:
    // 0049447f  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00494486  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0049448c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049448e  e88d59ffff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00494493  e90efbffff             -jmp 0x493fa6
    goto L_0x00493fa6;
L_0x00494498:
    // 00494498  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049449b  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049449e  e9e6feffff             -jmp 0x494389
    goto L_0x00494389;
L_0x004944a3:
    // 004944a3  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004944a8  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004944ae  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004944b1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004944b3  e8c855fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 004944b8  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004944bd  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004944c0  0f85e0faffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
L_0x004944c6:
    // 004944c6  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004944cb  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004944ce  7531                   -jne 0x494501
    if (!cpu.flags.zf)
    {
        goto L_0x00494501;
    }
    // 004944d0  e8eb0e0000             -call 0x4953c0
    cpu.esp -= 4;
    sub_4953c0(app, cpu);
    if (cpu.terminate) return;
    // 004944d5  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004944d8  7f27                   -jg 0x494501
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494501;
    }
    // 004944da  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004944df  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004944e5  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004944e8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004944ea  e89155fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 004944ef  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004944f4  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004944fa  e85d59ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004944ff  ebc5                   -jmp 0x4944c6
    goto L_0x004944c6;
L_0x00494501:
    // 00494501  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494506  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0049450c  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049450f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494511  e86a55fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494516  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049451b  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049451e  0f8582faffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 00494524  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0049452a  e8195affff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049452f  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494534  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494537  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0049453d  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494540  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00494543  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494546  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00494549  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0049454f  e80c5affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x00494554:
    // 00494554  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049455a  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049455d  7533                   -jne 0x494592
    if (!cpu.flags.zf)
    {
        goto L_0x00494592;
    }
    // 0049455f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494561  e81a0e0000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00494566  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494569  7f27                   -jg 0x494592
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494592;
    }
    // 0049456b  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494570  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494576  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494579  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049457b  e80055fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494580  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494585  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0049458b  e8cc58ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494590  ebc2                   -jmp 0x494554
    goto L_0x00494554;
L_0x00494592:
    // 00494592  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494597  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0049459d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004945a0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004945a2  e8d954fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 004945a7  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004945ac  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004945af  0f85f1f9ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
L_0x004945b5:
    // 004945b5  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004945ba  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004945c0  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004945c3  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004945c6  e8e18e0100             -call 0x4ad4ac
    cpu.esp -= 4;
    sub_4ad4ac(app, cpu);
    if (cpu.terminate) return;
    // 004945cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004945cd  7509                   -jne 0x4945d8
    if (!cpu.flags.zf)
    {
        goto L_0x004945d8;
    }
    // 004945cf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004945d1  e8c655ffff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 004945d6  ebdd                   -jmp 0x4945b5
    goto L_0x004945b5;
L_0x004945d8:
    // 004945d8  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004945dd  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004945e3  e86059ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004945e8  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004945ed  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004945f0  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004945f3  3ba8b0000000           +cmp ebp, dword ptr [eax + 0xb0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004945f9  7416                   -je 0x494611
    if (cpu.flags.zf)
    {
        goto L_0x00494611;
    }
    // 004945fb  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004945fe  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494601  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494604  8b80b0000000           -mov eax, dword ptr [eax + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 0049460a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049460c  e86f63ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
L_0x00494611:
    // 00494611  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494616  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00494619  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049461c  c7402003000000         -mov dword ptr [eax + 0x20], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 00494623  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494629  e83259ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0049462e:
    // 0049462e  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494634  837a4c08               +cmp dword ptr [edx + 0x4c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494638  0f83ed010000           -jae 0x49482b
    if (!cpu.flags.cf)
    {
        goto L_0x0049482b;
    }
    // 0049463e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494640  e8c70c0000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 00494645  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00494648  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049464b  3b4240                 +cmp eax, dword ptr [edx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049464e  0f8f21010000           -jg 0x494775
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494775;
    }
L_0x00494654:
    // 00494654  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049465a  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049465d  7546                   -jne 0x4946a5
    if (!cpu.flags.zf)
    {
        goto L_0x004946a5;
    }
    // 0049465f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494661  e8a60c0000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 00494666  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00494669  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049466c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049466e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494670  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494675  e8060d0000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 0049467a  39c2                   +cmp edx, eax
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
    // 0049467c  7427                   -je 0x4946a5
    if (cpu.flags.zf)
    {
        goto L_0x004946a5;
    }
    // 0049467e  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494683  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494689  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049468c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049468e  e8ed53fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494693  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494698  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0049469e  e8b957ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004946a3  ebaf                   -jmp 0x494654
    goto L_0x00494654;
L_0x004946a5:
    // 004946a5  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004946aa  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004946b0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004946b3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004946b5  e8c653fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 004946ba  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004946bf  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946c2  0f85def8ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
L_0x004946c8:
    // 004946c8  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004946ce  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946d1  7536                   -jne 0x494709
    if (!cpu.flags.zf)
    {
        goto L_0x00494709;
    }
    // 004946d3  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004946d8  e8e30c0000             -call 0x4953c0
    cpu.esp -= 4;
    sub_4953c0(app, cpu);
    if (cpu.terminate) return;
    // 004946dd  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946e0  7f27                   -jg 0x494709
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494709;
    }
    // 004946e2  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004946e7  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004946ed  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004946f0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004946f2  e88953fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 004946f7  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004946fc  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494702  e85557ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494707  ebbf                   -jmp 0x4946c8
    goto L_0x004946c8;
L_0x00494709:
    // 00494709  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049470e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00494714  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494717  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494719  e86253fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 0049471e  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494723  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494726  0f857af8ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 0049472c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494732  e81158ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494737  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049473c  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0049473f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494742  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494745  e83662ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0049474a  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049474f  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494752  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 00494758  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049475b  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049475e  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494761  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00494764  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00494767  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049476a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494770  e8eb57ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x00494775:
    // 00494775  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049477b  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049477e  7533                   -jne 0x4947b3
    if (!cpu.flags.zf)
    {
        goto L_0x004947b3;
    }
    // 00494780  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494782  e8f90b0000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00494787  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049478a  7f27                   -jg 0x4947b3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004947b3;
    }
    // 0049478c  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494791  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494797  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049479a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049479c  e8df52fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 004947a1  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004947a6  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004947ac  e8ab56ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004947b1  ebc2                   -jmp 0x494775
    goto L_0x00494775;
L_0x004947b3:
    // 004947b3  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004947b8  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004947be  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004947c1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004947c3  e8b852fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 004947c8  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004947cd  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004947d0  0f85d0f7ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
L_0x004947d6:
    // 004947d6  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004947db  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004947e1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004947e4  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004947e7  e8c08c0100             -call 0x4ad4ac
    cpu.esp -= 4;
    sub_4ad4ac(app, cpu);
    if (cpu.terminate) return;
    // 004947ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004947ee  7509                   -jne 0x4947f9
    if (!cpu.flags.zf)
    {
        goto L_0x004947f9;
    }
    // 004947f0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004947f2  e8a553ffff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 004947f7  ebdd                   -jmp 0x4947d6
    goto L_0x004947d6;
L_0x004947f9:
    // 004947f9  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004947fe  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494804  e83f57ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494809  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049480e  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00494811  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494814  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00494817  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049481a  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0049481d  01504c                 -add dword ptr [eax + 0x4c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494820  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494826  e83557ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x0049482b:
    // 0049482b  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494830  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494833  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00494838  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049483a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049483c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049483e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00494845  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00494847  3d6c454353             +cmp eax, 0x5343456c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1396917612 /*0x5343456c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049484c  7516                   -jne 0x494864
    if (!cpu.flags.zf)
    {
        goto L_0x00494864;
    }
    // 0049484e  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494853  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494856  740c                   -je 0x494864
    if (cpu.flags.zf)
    {
        goto L_0x00494864;
    }
    // 00494858  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0049485f  e942f7ffff             -jmp 0x493fa6
    goto L_0x00493fa6;
L_0x00494864:
    // 00494864  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494869  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0049486f  e8d456ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494874  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494879  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049487c  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049487f  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00494882  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00494885  8b484c                 -mov ecx, dword ptr [eax + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00494888  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049488a  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 0049488d  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00494890  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
    // 00494895  39c5                   +cmp ebp, eax
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
    // 00494897  742f                   -je 0x4948c8
    if (cpu.flags.zf)
    {
        goto L_0x004948c8;
    }
L_0x00494899:
    // 00494899  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049489e  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004948a1  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004948a6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004948a8  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004948aa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004948ac  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004948b3  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004948b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004948b7  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004948bc  23506c                 -and edx, dword ptr [eax + 0x6c]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */)));
    // 004948bf  3b5068                 +cmp edx, dword ptr [eax + 0x68]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004948c2  0f85a3000000           -jne 0x49496b
    if (!cpu.flags.zf)
    {
        goto L_0x0049496b;
    }
L_0x004948c8:
    // 004948c8  3b2d50ce4d00           +cmp ebp, dword ptr [0x4dce50]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004948ce  750a                   -jne 0x4948da
    if (!cpu.flags.zf)
    {
        goto L_0x004948da;
    }
    // 004948d0  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004948d5  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
L_0x004948da:
    // 004948da  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004948df  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004948e5  e87656ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004948ea  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004948f0  83794808               +cmp dword ptr [ecx + 0x48], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004948f4  0f8386000000           -jae 0x494980
    if (!cpu.flags.cf)
    {
        goto L_0x00494980;
    }
L_0x004948fa:
    // 004948fa  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004948ff  3b682c                 +cmp ebp, dword ptr [eax + 0x2c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494902  0f8594000000           -jne 0x49499c
    if (!cpu.flags.zf)
    {
        goto L_0x0049499c;
    }
    // 00494908  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0049490e  e83556ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494913  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494918  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
L_0x0049491d:
    // 0049491d  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494922  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494925  8b4868                 -mov ecx, dword ptr [eax + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 00494928  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049492a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049492d  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 00494934  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494938  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049493b  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049493e  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00494941  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
    // 00494946  39c5                   +cmp ebp, eax
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
    // 00494948  75d3                   -jne 0x49491d
    if (!cpu.flags.zf)
    {
        goto L_0x0049491d;
    }
    // 0049494a  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049494f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494955  e80656ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049495a  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049495f  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00494966  e93bf6ffff             -jmp 0x493fa6
    goto L_0x00493fa6;
L_0x0049496b:
    // 0049496b  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0049496e  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
    // 00494973  39c5                   +cmp ebp, eax
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
    // 00494975  0f851effffff           -jne 0x494899
    if (!cpu.flags.zf)
    {
        goto L_0x00494899;
    }
    // 0049497b  e948ffffff             -jmp 0x4948c8
    goto L_0x004948c8;
L_0x00494980:
    // 00494980  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494986  8b423c                 -mov eax, dword ptr [edx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 00494989  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 0049498c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049498f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00494991  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00494993  3b4148                 +cmp eax, dword ptr [ecx + 0x48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494996  0f8c5effffff           -jl 0x4948fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004948fa;
    }
L_0x0049499c:
    // 0049499c  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004949a1  8b1d4cce4d00           -mov ebx, dword ptr [0x4dce4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004949a7  39d8                   +cmp eax, ebx
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
    // 004949a9  0f848e030000           -je 0x494d3d
    if (cpu.flags.zf)
    {
        goto L_0x00494d3d;
    }
    // 004949af  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004949b1  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004949b4  034340                 -add eax, dword ptr [ebx + 0x40]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */)));
    // 004949b7  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004949bd  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004949c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004949c2  e845090000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 004949c7  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004949ca  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004949cd  39c8                   +cmp eax, ecx
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
    // 004949cf  0f877a010000           -ja 0x494b4f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00494b4f;
    }
L_0x004949d5:
    // 004949d5  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004949da  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004949dd  754a                   -jne 0x494a29
    if (!cpu.flags.zf)
    {
        goto L_0x00494a29;
    }
    // 004949df  8b0d50ce4d00           -mov ecx, dword ptr [0x4dce50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004949e5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004949e7  e820090000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 004949ec  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004949ef  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004949f2  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004949f7  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004949f9  e882090000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 004949fe  39c2                   +cmp edx, eax
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
    // 00494a00  7427                   -je 0x494a29
    if (cpu.flags.zf)
    {
        goto L_0x00494a29;
    }
    // 00494a02  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494a07  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494a0d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494a10  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494a12  e86950fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494a17  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494a1c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494a22  e83554ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494a27  ebac                   -jmp 0x4949d5
    goto L_0x004949d5;
L_0x00494a29:
    // 00494a29  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494a2e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00494a34  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494a37  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494a39  e84250fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494a3e  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494a43  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494a46  0f855af5ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
L_0x00494a4c:
    // 00494a4c  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494a51  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494a54  7536                   -jne 0x494a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00494a8c;
    }
    // 00494a56  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494a5b  e820090000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00494a60  83f808                 +cmp eax, 8
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
    // 00494a63  7727                   -ja 0x494a8c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00494a8c;
    }
    // 00494a65  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494a6a  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494a70  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494a73  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494a75  e80650fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494a7a  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494a7f  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494a85  e8d253ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494a8a  ebc0                   -jmp 0x494a4c
    goto L_0x00494a4c;
L_0x00494a8c:
    // 00494a8c  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494a91  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00494a97  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494a9a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494a9c  e8df4ffcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494aa1  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494aa6  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494aa9  0f85f7f4ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
L_0x00494aaf:
    // 00494aaf  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494ab4  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494ab7  753e                   -jne 0x494af7
    if (!cpu.flags.zf)
    {
        goto L_0x00494af7;
    }
    // 00494ab9  8b4848                 -mov ecx, dword ptr [eax + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00494abc  034840                 -add ecx, dword ptr [eax + 0x40]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */)));
    // 00494abf  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494ac4  8d5108                 -lea edx, [ecx + 8]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00494ac7  e8f4080000             -call 0x4953c0
    cpu.esp -= 4;
    sub_4953c0(app, cpu);
    if (cpu.terminate) return;
    // 00494acc  39d0                   +cmp eax, edx
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
    // 00494ace  7727                   -ja 0x494af7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00494af7;
    }
    // 00494ad0  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494ad5  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494adb  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494ade  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494ae0  e89b4ffcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494ae5  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494aea  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494af0  e86753ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494af5  ebb8                   -jmp 0x494aaf
    goto L_0x00494aaf;
L_0x00494af7:
    // 00494af7  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494afc  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00494b02  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494b05  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494b07  e8744ffcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494b0c  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494b11  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b14  0f858cf4ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 00494b1a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494b20  e82354ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494b25  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494b2a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494b2d  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 00494b33  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494b36  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00494b39  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494b3c  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00494b3f  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494b44  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494b4a  e81154ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x00494b4f:
    // 00494b4f  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494b54  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b57  0f8f17010000           -jg 0x494c74
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494c74;
    }
L_0x00494b5d:
    // 00494b5d  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494b63  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b66  7536                   -jne 0x494b9e
    if (!cpu.flags.zf)
    {
        goto L_0x00494b9e;
    }
    // 00494b68  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494b6d  e80e080000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00494b72  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b75  7f27                   -jg 0x494b9e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494b9e;
    }
    // 00494b77  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494b7c  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494b82  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494b85  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494b87  e8f44efcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494b8c  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494b91  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494b97  e8c052ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494b9c  ebbf                   -jmp 0x494b5d
    goto L_0x00494b5d;
L_0x00494b9e:
    // 00494b9e  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494ba3  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00494ba9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494bac  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494bae  e8cd4efcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494bb3  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494bb8  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494bbb  0f85e5f3ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 00494bc1  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494bc7  e87c53ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494bcc  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494bd1  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00494bd4  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494bda  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00494bdd  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494be0  e89b5dffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 00494be5  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494beb  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494bf0  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00494bf3  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00494bf6  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00494bf8  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00494bfb  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494bfe  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00494c01  89684c                 -mov dword ptr [eax + 0x4c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ebp;
L_0x00494c04:
    // 00494c04  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494c0a  e85153ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x00494c0f:
    // 00494c0f  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494c14  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c17  0f8c50010000           -jl 0x494d6d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494d6d;
    }
L_0x00494c1d:
    // 00494c1d  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494c22  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c25  0f8d1f030000           -jge 0x494f4a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494f4a;
    }
L_0x00494c2b:
    // 00494c2b  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494c31  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c34  0f858b020000           -jne 0x494ec5
    if (!cpu.flags.zf)
    {
        goto L_0x00494ec5;
    }
    // 00494c3a  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494c3f  e83c070000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00494c44  3b4240                 +cmp eax, dword ptr [edx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c47  0f8f78020000           -jg 0x494ec5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494ec5;
    }
    // 00494c4d  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494c52  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494c58  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494c5b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494c5d  e81e4efcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494c62  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494c67  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494c6d  e8ea51ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494c72  ebb7                   -jmp 0x494c2b
    goto L_0x00494c2b;
L_0x00494c74:
    // 00494c74  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494c7a  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c7d  7536                   -jne 0x494cb5
    if (!cpu.flags.zf)
    {
        goto L_0x00494cb5;
    }
    // 00494c7f  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494c84  e8f7060000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00494c89  3b4248                 +cmp eax, dword ptr [edx + 0x48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c8c  7f27                   -jg 0x494cb5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494cb5;
    }
    // 00494c8e  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494c93  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494c99  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494c9c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494c9e  e8dd4dfcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494ca3  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494ca8  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494cae  e8a951ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494cb3  ebbf                   -jmp 0x494c74
    goto L_0x00494c74;
L_0x00494cb5:
    // 00494cb5  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494cba  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00494cc0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494cc3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494cc5  e8b64dfcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494cca  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494ccf  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494cd2  0f85cef2ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 00494cd8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494cde  e86552ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494ce3  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494ce8  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00494ceb  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494cf1  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00494cf4  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494cf7  e8845cffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 00494cfc  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494d02  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494d07  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00494d0a  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00494d0d  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00494d0f  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00494d12  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00494d15  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00494d17  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 00494d1a  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00494d1d  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494d20  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494d23  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00494d26  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00494d28  e8535cffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 00494d2d  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494d32  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00494d35  29500c                 +sub dword ptr [eax + 0xc], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494d38  e9c7feffff             -jmp 0x494c04
    goto L_0x00494c04;
L_0x00494d3d:
    // 00494d3d  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00494d40  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00494d45  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00494d47  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00494d49  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00494d4b  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00494d52  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00494d54  3d6c454353             +cmp eax, 0x5343456c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1396917612 /*0x5343456c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494d59  7509                   -jne 0x494d64
    if (!cpu.flags.zf)
    {
        goto L_0x00494d64;
    }
    // 00494d5b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494d5d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00494d5f  e9abfeffff             -jmp 0x494c0f
    goto L_0x00494c0f;
L_0x00494d64:
    // 00494d64  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494d66  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00494d68  e9a2feffff             -jmp 0x494c0f
    goto L_0x00494c0f;
L_0x00494d6d:
    // 00494d6d  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00494d70  035040                 -add edx, dword ptr [eax + 0x40]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */)));
    // 00494d73  8d4a08                 -lea ecx, [edx + 8]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00494d76  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494d7c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494d7e  e889050000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 00494d83  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00494d86  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00494d89  39c8                   +cmp eax, ecx
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
    // 00494d8b  0f878cfeffff           -ja 0x494c1d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00494c1d;
    }
L_0x00494d91:
    // 00494d91  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494d96  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494d99  754a                   -jne 0x494de5
    if (!cpu.flags.zf)
    {
        goto L_0x00494de5;
    }
    // 00494d9b  8b0d50ce4d00           -mov ecx, dword ptr [0x4dce50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494da1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494da3  e864050000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 00494da8  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00494dab  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00494dae  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494db3  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494db5  e8c6050000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00494dba  39c2                   +cmp edx, eax
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
    // 00494dbc  7427                   -je 0x494de5
    if (cpu.flags.zf)
    {
        goto L_0x00494de5;
    }
    // 00494dbe  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494dc3  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494dc9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494dcc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494dce  e8ad4cfcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494dd3  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494dd8  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494dde  e87950ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494de3  ebac                   -jmp 0x494d91
    goto L_0x00494d91;
L_0x00494de5:
    // 00494de5  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494dea  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00494df0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494df3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494df5  e8864cfcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494dfa  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494dff  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e02  0f859ef1ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
L_0x00494e08:
    // 00494e08  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494e0e  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e11  7536                   -jne 0x494e49
    if (!cpu.flags.zf)
    {
        goto L_0x00494e49;
    }
    // 00494e13  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494e18  e8a3050000             -call 0x4953c0
    cpu.esp -= 4;
    sub_4953c0(app, cpu);
    if (cpu.terminate) return;
    // 00494e1d  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e20  7f27                   -jg 0x494e49
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494e49;
    }
    // 00494e22  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494e27  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00494e2d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494e30  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494e32  e8494cfcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494e37  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494e3c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00494e42  e81550ffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00494e47  ebbf                   -jmp 0x494e08
    goto L_0x00494e08;
L_0x00494e49:
    // 00494e49  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494e4e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00494e54  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494e57  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494e59  e8224cfcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494e5e  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494e63  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e66  0f853af1ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 00494e6c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494e72  e8d150ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494e77  8b1d4cce4d00           -mov ebx, dword ptr [0x4dce4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494e7d  8b5b4c                 -mov ebx, dword ptr [ebx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */);
    // 00494e80  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494e85  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494e88  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494e8b  e8f05affff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 00494e90  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494e95  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00494e98  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 00494e9e  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494ea4  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494ea7  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 00494eaa  01d9                   +add ecx, ebx
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
    // 00494eac  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00494eaf  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494eb2  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00494eb5  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00494ebb  e8a050ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00494ec0  e958fdffff             -jmp 0x494c1d
    goto L_0x00494c1d;
L_0x00494ec5:
    // 00494ec5  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494eca  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00494ed0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494ed3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494ed5  e8a64bfcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00494eda  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494edf  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494ee2  7566                   -jne 0x494f4a
    if (!cpu.flags.zf)
    {
        goto L_0x00494f4a;
    }
L_0x00494ee4:
    // 00494ee4  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494ee9  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 00494eef  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494ef5  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00494ef8  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494efb  e8ac850100             -call 0x4ad4ac
    cpu.esp -= 4;
    sub_4ad4ac(app, cpu);
    if (cpu.terminate) return;
    // 00494f00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494f02  7509                   -jne 0x494f0d
    if (!cpu.flags.zf)
    {
        goto L_0x00494f0d;
    }
    // 00494f04  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494f06  e8914cffff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00494f0b  ebd7                   -jmp 0x494ee4
    goto L_0x00494ee4;
L_0x00494f0d:
    // 00494f0d  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494f12  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494f18  e82b50ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494f1d  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494f22  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00494f25  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494f28  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494f2e  8b4840                 -mov ecx, dword ptr [eax + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00494f31  014a0c                 -add dword ptr [edx + 0xc], ecx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00494f34  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00494f37  295044                 +sub dword ptr [eax + 0x44], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494f3a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494f40  e81b50ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00494f45  e9d3fcffff             -jmp 0x494c1d
    goto L_0x00494c1d;
L_0x00494f4a:
    // 00494f4a  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494f4f  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494f52  0f854ef0ffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 00494f58  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00494f5e  e8e54fffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00494f63  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00494f65  0f85bc000000           -jne 0x495027
    if (!cpu.flags.zf)
    {
        goto L_0x00495027;
    }
    // 00494f6b  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494f71  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494f76  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00494f79  014810                 -add dword ptr [eax + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00494f7c  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00494f7f  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494f82  0188b8000000           -add dword ptr [eax + 0xb8], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00494f88  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00494f8e  e8cd4fffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00494f93  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00494f98  8b354cce4d00           -mov esi, dword ptr [0x4dce4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494f9e  39f0                   +cmp eax, esi
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
    // 00494fa0  0f849d020000           -je 0x495243
    if (cpu.flags.zf)
    {
        goto L_0x00495243;
    }
    // 00494fa6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494fa8  3b6e4c                 +cmp ebp, dword ptr [esi + 0x4c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494fab  0f852a020000           -jne 0x4951db
    if (!cpu.flags.zf)
    {
        goto L_0x004951db;
    }
    // 00494fb1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494fb3  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00494fb6  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00494fb9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494fbb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494fbd  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00494fbf  e848030000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 00494fc4  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00494fc7  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00494fca  39c8                   +cmp eax, ecx
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
    // 00494fcc  0f8f45010000           -jg 0x495117
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495117;
    }
L_0x00494fd2:
    // 00494fd2  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494fd8  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494fdb  0f857a000000           -jne 0x49505b
    if (!cpu.flags.zf)
    {
        goto L_0x0049505b;
    }
    // 00494fe1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494fe3  e824030000             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 00494fe8  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00494feb  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00494fee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494ff0  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00494ff5  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00494ff7  e884030000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00494ffc  39c2                   +cmp edx, eax
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
    // 00494ffe  745b                   -je 0x49505b
    if (cpu.flags.zf)
    {
        goto L_0x0049505b;
    }
    // 00495000  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495005  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0049500b  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049500e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00495010  e86b4afcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00495015  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049501a  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00495020  e8374effff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00495025  ebab                   -jmp 0x494fd2
    goto L_0x00494fd2;
L_0x00495027:
    // 00495027  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049502d  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00495032  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00495035  014810                 -add dword ptr [eax + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495038  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0049503b  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049503e  0188b8000000           +add dword ptr [eax + 0xb8], ecx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495044  c7422007000000         -mov dword ptr [edx + 0x20], 7
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0049504b  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00495051  e80a4fffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00495056  e94befffff             -jmp 0x493fa6
    goto L_0x00493fa6;
L_0x0049505b:
    // 0049505b  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495060  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00495066  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00495069  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049506b  e8104afcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00495070  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495075  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495078  0f8528efffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
L_0x0049507e:
    // 0049507e  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495083  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495086  753c                   -jne 0x4950c4
    if (!cpu.flags.zf)
    {
        goto L_0x004950c4;
    }
    // 00495088  8b0d50ce4d00           -mov ecx, dword ptr [0x4dce50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 0049508e  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00495091  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 00495094  e827030000             -call 0x4953c0
    cpu.esp -= 4;
    sub_4953c0(app, cpu);
    if (cpu.terminate) return;
    // 00495099  39d0                   +cmp eax, edx
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
    // 0049509b  7f27                   -jg 0x4950c4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004950c4;
    }
    // 0049509d  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004950a2  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004950a8  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004950ab  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004950ad  e8ce49fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 004950b2  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004950b7  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004950bd  e89a4dffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004950c2  ebba                   -jmp 0x49507e
    goto L_0x0049507e;
L_0x004950c4:
    // 004950c4  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004950c9  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004950cf  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004950d2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004950d4  e8a749fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 004950d9  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004950de  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004950e1  0f85bfeeffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 004950e7  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004950ed  e8564effff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004950f2  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004950f7  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004950fa  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 00495100  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495103  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00495106  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00495109  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049510c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00495112  e8494effff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x00495117:
    // 00495117  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049511c  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049511f  753c                   -jne 0x49515d
    if (!cpu.flags.zf)
    {
        goto L_0x0049515d;
    }
    // 00495121  8b0d50ce4d00           -mov ecx, dword ptr [0x4dce50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00495127  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049512a  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 0049512d  e84e020000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00495132  39d0                   +cmp eax, edx
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
    // 00495134  7f27                   -jg 0x49515d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049515d;
    }
    // 00495136  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049513b  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00495141  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00495144  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00495146  e83549fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 0049514b  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495150  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00495156  e8014dffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 0049515b  ebba                   -jmp 0x495117
    goto L_0x00495117;
L_0x0049515d:
    // 0049515d  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495162  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00495168  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049516b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049516d  e80e49fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00495172  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495177  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049517a  0f8526eeffff           -jne 0x493fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00493fa6;
    }
    // 00495180  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00495186  e8bd4dffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049518b  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00495191  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00495194  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00495197  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495199  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049519b  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004951a0  89484c                 -mov dword ptr [eax + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ecx;
    // 004951a3  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004951a6  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004951a9  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004951ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004951ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004951b0  e8cb57ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004951b5  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004951ba  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004951bd  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004951c0  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004951c5  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004951c8  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004951cb  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004951cd  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004951d0:
    // 004951d0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004951d6  e8854dffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x004951db:
    // 004951db  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004951e0  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004951e3  2b504c                 -sub edx, dword ptr [eax + 0x4c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)));
    // 004951e6  3b5054                 +cmp edx, dword ptr [eax + 0x54]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004951e9  0f8cb7edffff           -jl 0x493fa6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493fa6;
    }
    // 004951ef  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004951f2  0f85ec000000           -jne 0x4952e4
    if (!cpu.flags.zf)
    {
        goto L_0x004952e4;
    }
    // 004951f8  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
L_0x004951fd:
    // 004951fd  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495202  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495205  7564                   -jne 0x49526b
    if (!cpu.flags.zf)
    {
        goto L_0x0049526b;
    }
    // 00495207  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 0049520d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049520f  e86c010000             -call 0x495380
    cpu.esp -= 4;
    sub_495380(app, cpu);
    if (cpu.terminate) return;
    // 00495214  03424c                 -add eax, dword ptr [edx + 0x4c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
    // 00495217  83f808                 +cmp eax, 8
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
    // 0049521a  774f                   -ja 0x49526b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049526b;
    }
    // 0049521c  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495221  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00495227  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049522a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049522c  e84f48fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00495231  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495236  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0049523c  e81b4cffff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00495241  ebba                   -jmp 0x4951fd
    goto L_0x004951fd;
L_0x00495243:
    // 00495243  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00495249  e8fa4cffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049524e  8b1550ce4d00           -mov edx, dword ptr [0x4dce50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 00495254  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00495257  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049525a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049525c  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495261  29ca                   +sub edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495263  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 00495266  e965ffffff             -jmp 0x4951d0
    goto L_0x004951d0;
L_0x0049526b:
    // 0049526b  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495270  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00495276  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00495279  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049527b  e80048fcff             -call 0x459a80
    cpu.esp -= 4;
    sub_459a80(app, cpu);
    if (cpu.terminate) return;
    // 00495280  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495285  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00495288  39dd                   +cmp ebp, ebx
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
    // 0049528a  7469                   -je 0x4952f5
    if (cpu.flags.zf)
    {
        goto L_0x004952f5;
    }
L_0x0049528c:
    // 0049528c  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495291  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00495297  e8ac4cffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049529c  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004952a1  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
L_0x004952a6:
    // 004952a6  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004952ab  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004952ae  c702fdffffff           -mov dword ptr [edx], 0xfffffffd
    app->getMemory<x86::reg32>(cpu.edx) = 4294967293 /*0xfffffffd*/;
    // 004952b4  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004952b7  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 004952be  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004952c2  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004952c5  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004952c8  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004952cb  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
    // 004952d0  39c5                   +cmp ebp, eax
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
    // 004952d2  75d2                   -jne 0x4952a6
    if (!cpu.flags.zf)
    {
        goto L_0x004952a6;
    }
    // 004952d4  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004952d9  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004952df  e87c4cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x004952e4:
    // 004952e4  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004952e9  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 004952f0  e9b1ecffff             -jmp 0x493fa6
    goto L_0x00493fa6;
L_0x004952f5:
    // 004952f5  a150ce4d00             -mov eax, dword ptr [0x4dce50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */);
    // 004952fa  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004952fd  a350ce4d00             -mov dword ptr [0x4dce50], eax
    app->getMemory<x86::reg32>(x86::reg32(5099088) /* 0x4dce50 */) = cpu.eax;
    // 00495302  39c3                   +cmp ebx, eax
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
    // 00495304  0f85f3feffff           -jne 0x4951fd
    if (!cpu.flags.zf)
    {
        goto L_0x004951fd;
    }
    // 0049530a  eb80                   -jmp 0x49528c
    goto L_0x0049528c;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_49530c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049530c);
    // 0049530c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049530d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049530f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00495315  e82e4cffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049531a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049531d  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 00495320  7430                   -je 0x495352
    if (cpu.flags.zf)
    {
        goto L_0x00495352;
    }
L_0x00495322:
    // 00495322  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00495325  3b4210                 +cmp eax, dword ptr [edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495328  7428                   -je 0x495352
    if (cpu.flags.zf)
    {
        goto L_0x00495352;
    }
    // 0049532a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049532d  8338fe                 +cmp dword ptr [eax], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495330  752d                   -jne 0x49535f
    if (!cpu.flags.zf)
    {
        goto L_0x0049535f;
    }
    // 00495332  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00495335  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495338  83e808                 -sub eax, 8
    (cpu.eax) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049533b  2982bc000000           -sub dword ptr [edx + 0xbc], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(188) /* 0xbc */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00495341  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00495344  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495347  014218                 -add dword ptr [edx + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049534a:
    // 0049534a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049534d  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 00495350  75d0                   -jne 0x495322
    if (!cpu.flags.zf)
    {
        goto L_0x00495322;
    }
L_0x00495352:
    // 00495352  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00495358  e8034cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049535d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049535e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049535f:
    // 0049535f  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00495362  8338ff                 +cmp dword ptr [eax], -1
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
    // 00495365  75eb                   -jne 0x495352
    if (!cpu.flags.zf)
    {
        goto L_0x00495352;
    }
    // 00495367  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049536a  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 0049536d  7506                   -jne 0x495375
    if (!cpu.flags.zf)
    {
        goto L_0x00495375;
    }
    // 0049536f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495372  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00495375:
    // 00495375  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495378  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049537b  ebcd                   -jmp 0x49534a
    goto L_0x0049534a;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495380);
    // 00495380  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495381  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495383  e884ffffff             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 00495388  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049538b  3b420c                 +cmp eax, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049538e  7210                   -jb 0x4953a0
    if (cpu.flags.cf)
    {
        goto L_0x004953a0;
    }
    // 00495390  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00495393  3b420c                 +cmp eax, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495396  7510                   -jne 0x4953a8
    if (!cpu.flags.zf)
    {
        goto L_0x004953a8;
    }
    // 00495398  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049539b  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 0049539e  7508                   -jne 0x4953a8
    if (!cpu.flags.zf)
    {
        goto L_0x004953a8;
    }
L_0x004953a0:
    // 004953a0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004953a3  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004953a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004953a8:
    // 004953a8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004953ab  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004953ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4953b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004953b0);
    // 004953b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004953b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004953b3  e854ffffff             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 004953b8  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004953bb  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004953be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4953c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004953c0);
    // 004953c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004953c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004953c3  e844ffffff             -call 0x49530c
    cpu.esp -= 4;
    sub_49530c(app, cpu);
    if (cpu.terminate) return;
    // 004953c8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004953cb  3b420c                 +cmp eax, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004953ce  7708                   -ja 0x4953d8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004953d8;
    }
    // 004953d0  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004953d3  2b4204                 -sub eax, dword ptr [edx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004953d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004953d8:
    // 004953d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004953da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4953dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004953dc);
    // 004953dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004953dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004953de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004953df  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004953e0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004953e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004953e4  7437                   -je 0x49541d
    if (cpu.flags.zf)
    {
        goto L_0x0049541d;
    }
    // 004953e6  83787800               +cmp dword ptr [eax + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004953ea  7413                   -je 0x4953ff
    if (cpu.flags.zf)
    {
        goto L_0x004953ff;
    }
    // 004953ec  8b4078                 -mov eax, dword ptr [eax + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 004953ef  8b8094000000           -mov eax, dword ptr [eax + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 004953f5  83f80d                 +cmp eax, 0xd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004953f8  7328                   -jae 0x495422
    if (!cpu.flags.cf)
    {
        goto L_0x00495422;
    }
    // 004953fa  83f80b                 +cmp eax, 0xb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004953fd  7431                   -je 0x495430
    if (cpu.flags.zf)
    {
        goto L_0x00495430;
    }
L_0x004953ff:
    // 004953ff  83792002               +cmp dword ptr [ecx + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495403  742b                   -je 0x495430
    if (cpu.flags.zf)
    {
        goto L_0x00495430;
    }
    // 00495405  83792001               +cmp dword ptr [ecx + 0x20], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495409  7425                   -je 0x495430
    if (cpu.flags.zf)
    {
        goto L_0x00495430;
    }
    // 0049540b  8379200e               +cmp dword ptr [ecx + 0x20], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049540f  7426                   -je 0x495437
    if (cpu.flags.zf)
    {
        goto L_0x00495437;
    }
    // 00495411  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00495414  8b6914                 -mov ebp, dword ptr [ecx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00495417  39e8                   +cmp eax, ebp
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
    // 00495419  7526                   -jne 0x495441
    if (!cpu.flags.zf)
    {
        goto L_0x00495441;
    }
    // 0049541b  31e8                   +xor eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebp))));
L_0x0049541d:
    // 0049541d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049541e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049541f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495420  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495421  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495422:
    // 00495422  760c                   -jbe 0x495430
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495430;
    }
    // 00495424  83f814                 +cmp eax, 0x14
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
    // 00495427  72d6                   -jb 0x4953ff
    if (cpu.flags.cf)
    {
        goto L_0x004953ff;
    }
    // 00495429  7605                   -jbe 0x495430
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495430;
    }
    // 0049542b  83f817                 +cmp eax, 0x17
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(23 /*0x17*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049542e  75cf                   -jne 0x4953ff
    if (!cpu.flags.zf)
    {
        goto L_0x004953ff;
    }
L_0x00495430:
    // 00495430  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495432  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495433  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495434  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495435  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495436  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495437:
    // 00495437  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0049543c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049543d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049543e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049543f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495440  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495441:
    // 00495441  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00495447  e8fc4affff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049544c  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0049544f  8338ff                 +cmp dword ptr [eax], -1
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
    // 00495452  750e                   -jne 0x495462
    if (!cpu.flags.zf)
    {
        goto L_0x00495462;
    }
    // 00495454  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00495457  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049545a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049545d  3b4114                 +cmp eax, dword ptr [ecx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495460  7466                   -je 0x4954c8
    if (cpu.flags.zf)
    {
        goto L_0x004954c8;
    }
L_0x00495462:
    // 00495462  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00495465  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495468  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049546b  3b5114                 +cmp edx, dword ptr [ecx + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049546e  736a                   -jae 0x4954da
    if (!cpu.flags.cf)
    {
        goto L_0x004954da;
    }
    // 00495470  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00495473  2b5914                 -sub ebx, dword ptr [ecx + 0x14]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 00495476  39c3                   +cmp ebx, eax
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
    // 00495478  7c4e                   -jl 0x4954c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004954c8;
    }
L_0x0049547a:
    // 0049547a  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0049547d  8d50f8                 -lea edx, [eax - 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00495480  2991b8000000           -sub dword ptr [ecx + 0xb8], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(184) /* 0xb8 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00495486  0191bc000000           -add dword ptr [ecx + 0xbc], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049548c  014114                 -add dword ptr [ecx + 0x14], eax
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049548f  833bfd                 +cmp dword ptr [ebx], -3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495492  7522                   -jne 0x4954b6
    if (!cpu.flags.zf)
    {
        goto L_0x004954b6;
    }
    // 00495494  3b5918                 +cmp ebx, dword ptr [ecx + 0x18]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495497  755d                   -jne 0x4954f6
    if (!cpu.flags.zf)
    {
        goto L_0x004954f6;
    }
    // 00495499  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0049549c  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0049549f:
    // 0049549f  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004954a4  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004954a9  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004954ae  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004954b1  e86a49ffff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
L_0x004954b6:
    // 004954b6  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004954bc  e89f4affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004954c1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004954c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004954c8:
    // 004954c8  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004954ce  e88d4affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004954d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004954d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004954da:
    // 004954da  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004954dd  2b5914                 -sub ebx, dword ptr [ecx + 0x14]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004954e0  39c3                   +cmp ebx, eax
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
    // 004954e2  7d96                   -jge 0x49547a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049547a;
    }
    // 004954e4  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004954ea  e8714affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004954ef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004954f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004954f6:
    // 004954f6  c703feffffff           -mov dword ptr [ebx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.ebx) = 4294967294 /*0xfffffffe*/;
    // 004954fc  eba1                   -jmp 0x49549f
    goto L_0x0049549f;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_495500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495500);
    // 00495500  058c000000             +add eax, 0x8c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495505  c702feffffff           -mov dword ptr [edx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.edx) = 4294967294 /*0xfffffffe*/;
    // 0049550b  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049550e  e90d49ffff             -jmp 0x489e20
    return sub_489e20(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_495514(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495514);
    // 00495514  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495516  7406                   -je 0x49551e
    if (cpu.flags.zf)
    {
        goto L_0x0049551e;
    }
    // 00495518  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
L_0x0049551e:
    // 0049551e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495520);
    // 00495520  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495522  7406                   -je 0x49552a
    if (cpu.flags.zf)
    {
        goto L_0x0049552a;
    }
    // 00495524  8b80bc000000           -mov eax, dword ptr [eax + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
L_0x0049552a:
    // 0049552a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49552c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049552c);
    // 0049552c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049552d  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495533  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495535  7412                   -je 0x495549
    if (cpu.flags.zf)
    {
        goto L_0x00495549;
    }
    // 00495537  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495539  837a2007               +cmp dword ptr [edx + 0x20], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049553d  7506                   -jne 0x495545
    if (!cpu.flags.zf)
    {
        goto L_0x00495545;
    }
    // 0049553f  837a7800               +cmp dword ptr [edx + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495543  7404                   -je 0x495549
    if (cpu.flags.zf)
    {
        goto L_0x00495549;
    }
L_0x00495545:
    // 00495545  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495547  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495549:
    // 00495549  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049554e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049554f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495550);
    // 00495550  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495551  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495557  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0049555d  e8e649ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00495562  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00495564:
    // 00495564  8982b4000000           -mov dword ptr [edx + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0049556a  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0049556d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049556f  75f3                   -jne 0x495564
    if (!cpu.flags.zf)
    {
        goto L_0x00495564;
    }
    // 00495571  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495576  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0049557c  e8df49ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00495581  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495582  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495584);
    // 00495584  8b80b4000000           -mov eax, dword ptr [eax + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */);
    // 0049558a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49558c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049558c);
    // 0049558c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049558d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049558f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495591  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495593  83f8ff                 +cmp eax, -1
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
    // 00495596  7408                   -je 0x4955a0
    if (cpu.flags.zf)
    {
        goto L_0x004955a0;
    }
    // 00495598  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049559a  740d                   -je 0x4955a9
    if (cpu.flags.zf)
    {
        goto L_0x004955a9;
    }
L_0x0049559c:
    // 0049559c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049559e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049559f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004955a0:
    // 004955a0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004955a5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004955a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004955a9:
    // 004955a9  e87effffff             -call 0x49552c
    cpu.esp -= 4;
    sub_49552c(app, cpu);
    if (cpu.terminate) return;
    // 004955ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004955b0  74ea                   -je 0x49559c
    if (cpu.flags.zf)
    {
        goto L_0x0049559c;
    }
    // 004955b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004955b4  e85bffffff             -call 0x495514
    cpu.esp -= 4;
    sub_495514(app, cpu);
    if (cpu.terminate) return;
    // 004955b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004955bb  75df                   -jne 0x49559c
    if (!cpu.flags.zf)
    {
        goto L_0x0049559c;
    }
    // 004955bd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004955c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004955c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4955c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004955c8);
    // 004955c8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004955c9  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004955cf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004955d1  7502                   -jne 0x4955d5
    if (!cpu.flags.zf)
    {
        goto L_0x004955d5;
    }
    // 004955d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004955d5:
    // 004955d5  c7423001000000         -mov dword ptr [edx + 0x30], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 004955dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4955e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004955e0);
    // 004955e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004955e1  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004955e7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004955e9  7502                   -jne 0x4955ed
    if (!cpu.flags.zf)
    {
        goto L_0x004955ed;
    }
    // 004955eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004955ed:
    // 004955ed  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004955f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4955f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004955f8);
    // 004955f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004955f9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004955fb  8b154cce4d00           -mov edx, dword ptr [0x4dce4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495601  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495603  742a                   -je 0x49562f
    if (cpu.flags.zf)
    {
        goto L_0x0049562f;
    }
    // 00495605  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495606  894274                 -mov dword ptr [edx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 00495609  49                     -dec ecx
    (cpu.ecx)--;
    // 0049560a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049560c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049560e  7e14                   -jle 0x495624
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495624;
    }
L_0x00495610:
    // 00495610  8d989c000000           -lea ebx, [eax + 0x9c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 00495616  42                     -inc edx
    (cpu.edx)++;
    // 00495617  899898000000           -mov dword ptr [eax + 0x98], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.ebx;
    // 0049561d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049561f  39ca                   +cmp edx, ecx
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
    // 00495621  7ced                   -jl 0x495610
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495610;
    }
    // 00495623  90                     -nop 
    ;
L_0x00495624:
    // 00495624  c7809800000000000000   -mov dword ptr [eax + 0x98], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 0049562e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049562f:
    // 0049562f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495630  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495634(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495634);
    // 00495634  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495635  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495636  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495638  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049563e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00495640  7503                   -jne 0x495645
    if (!cpu.flags.zf)
    {
        goto L_0x00495645;
    }
    // 00495642  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495643  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495644  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495645:
    // 00495645  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0049564b  e8f848ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00495650  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495655  8b4874                 -mov ecx, dword ptr [eax + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00495658  898a98000000           -mov dword ptr [edx + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0049565e  895074                 -mov dword ptr [eax + 0x74], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00495661  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00495667  e8f448ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049566c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049566d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049566e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495670);
    // 00495670  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495671  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495672  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495674  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049567a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049567c  7505                   -jne 0x495683
    if (!cpu.flags.zf)
    {
        goto L_0x00495683;
    }
L_0x0049567e:
    // 0049567e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495680  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495681  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495682  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495683:
    // 00495683  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00495689  e8ba48ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049568e  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495693  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00495696  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495698  740d                   -je 0x4956a7
    if (cpu.flags.zf)
    {
        goto L_0x004956a7;
    }
L_0x0049569a:
    // 0049569a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049569c  7409                   -je 0x4956a7
    if (cpu.flags.zf)
    {
        goto L_0x004956a7;
    }
    // 0049569e  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004956a4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004956a5  75f3                   -jne 0x49569a
    if (!cpu.flags.zf)
    {
        goto L_0x0049569a;
    }
L_0x004956a7:
    // 004956a7  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004956ac  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004956b2  e8a948ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004956b7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004956b9  75c3                   -jne 0x49567e
    if (!cpu.flags.zf)
    {
        goto L_0x0049567e;
    }
    // 004956bb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004956c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4956c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004956c4);
    // 004956c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004956c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004956c6  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004956cc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004956ce  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004956d0  7505                   -jne 0x4956d7
    if (!cpu.flags.zf)
    {
        goto L_0x004956d7;
    }
    // 004956d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004956d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004956d7:
    // 004956d7  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004956dd  e86648ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004956e2  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 004956e7  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004956ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004956ec  740e                   -je 0x4956fc
    if (cpu.flags.zf)
    {
        goto L_0x004956fc;
    }
L_0x004956ee:
    // 004956ee  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004956f4  42                     -inc edx
    (cpu.edx)++;
    // 004956f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004956f7  75f5                   -jne 0x4956ee
    if (!cpu.flags.zf)
    {
        goto L_0x004956ee;
    }
    // 004956f9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004956fc:
    // 004956fc  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495701  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00495707  e85448ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049570c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049570e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049570f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495710  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495714(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00495714);
    // 00495714  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495715  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495716  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495718  8b0d4cce4d00           -mov ecx, dword ptr [0x4dce4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 0049571e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00495720  7505                   -jne 0x495727
    if (!cpu.flags.zf)
    {
        goto L_0x00495727;
    }
    // 00495722  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495724  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495725  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495726  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495727:
    // 00495727  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0049572d  e81648ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00495732  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495737  83787400               +cmp dword ptr [eax + 0x74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049573b  7504                   -jne 0x495741
    if (!cpu.flags.zf)
    {
        goto L_0x00495741;
    }
    // 0049573d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049573f  742e                   -je 0x49576f
    if (cpu.flags.zf)
    {
        goto L_0x0049576f;
    }
L_0x00495741:
    // 00495741  a14cce4d00             -mov eax, dword ptr [0x4dce4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099084) /* 0x4dce4c */);
    // 00495746  8b5074                 -mov edx, dword ptr [eax + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00495749  8b4874                 -mov ecx, dword ptr [eax + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0049574c  8b8998000000           -mov ecx, dword ptr [ecx + 0x98]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00495752  894874                 -mov dword ptr [eax + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 00495755  c7829800000000000000   -mov dword ptr [edx + 0x98], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 0049575f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00495765  e8f647ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049576a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049576c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049576d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049576e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049576f:
    // 0049576f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00495775  e8e647ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049577a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049577c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049577d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049577e  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
