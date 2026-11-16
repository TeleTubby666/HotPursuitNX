#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_48a474(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a474  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a475  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a476  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a477  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a479  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0048a47b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048a47d  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048a481  80610cfc               -and byte ptr [ecx + 0xc], 0xfc
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0048a485  09590c                 -or dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a488  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048a48d  e848f30100             -call 0x4a97da
    cpu.esp -= 4;
    sub_4a97da(app, cpu);
    if (cpu.terminate) return;
    // 0048a492  3c72                   +cmp al, 0x72
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
    // 0048a494  7522                   -jne 0x48a4b8
    if (!cpu.flags.zf)
    {
        goto L_0x0048a4b8;
    }
    // 0048a496  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a498  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0048a49b  7405                   -je 0x48a4a2
    if (cpu.flags.zf)
    {
        goto L_0x0048a4a2;
    }
    // 0048a49d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0048a4a2:
    // 0048a4a2  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0048a4a5  7405                   -je 0x48a4ac
    if (cpu.flags.zf)
    {
        goto L_0x0048a4ac;
    }
    // 0048a4a7  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0048a4aa  eb03                   -jmp 0x48a4af
    goto L_0x0048a4af;
L_0x0048a4ac:
    // 0048a4ac  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x0048a4af:
    // 0048a4af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048a4b1  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048a4b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a4b6  eb30                   -jmp 0x48a4e8
    goto L_0x0048a4e8;
L_0x0048a4b8:
    // 0048a4b8  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0048a4bb  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0048a4be  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048a4c3  83c021                 -add eax, 0x21
    (cpu.eax) += x86::reg32(x86::sreg32(33 /*0x21*/));
    // 0048a4c6  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 0048a4c9  7404                   -je 0x48a4cf
    if (cpu.flags.zf)
    {
        goto L_0x0048a4cf;
    }
    // 0048a4cb  0c10                   +or al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048a4cd  eb02                   -jmp 0x48a4d1
    goto L_0x0048a4d1;
L_0x0048a4cf:
    // 0048a4cf  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x0048a4d1:
    // 0048a4d1  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0048a4d4  7405                   -je 0x48a4db
    if (cpu.flags.zf)
    {
        goto L_0x0048a4db;
    }
    // 0048a4d6  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0048a4d9  eb03                   -jmp 0x48a4de
    goto L_0x0048a4de;
L_0x0048a4db:
    // 0048a4db  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0048a4de:
    // 0048a4de  6880010000             -push 0x180
    app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 0048a4e3  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048a4e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0048a4e8:
    // 0048a4e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a4e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a4ea  e81df30100             -call 0x4a980c
    cpu.esp -= 4;
    sub_4a980c(app, cpu);
    if (cpu.terminate) return;
    // 0048a4ef  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048a4f2  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048a4f5  837910ff               +cmp dword ptr [ecx + 0x10], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a4f9  750b                   -jne 0x48a506
    if (!cpu.flags.zf)
    {
        goto L_0x0048a506;
    }
    // 0048a4fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a4fd  e8f5f50100             -call 0x4a9af7
    cpu.esp -= 4;
    sub_4a9af7(app, cpu);
    if (cpu.terminate) return;
    // 0048a502  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a504  eb4e                   -jmp 0x48a554
    goto L_0x0048a554;
L_0x0048a506:
    // 0048a506  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048a50d  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a510  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0048a517  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048a51e  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a521  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048a524  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a527  c7401500000000         -mov dword ptr [eax + 0x15], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 0048a52e  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a531  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048a538  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 0048a53b  740e                   -je 0x48a54b
    if (cpu.flags.zf)
    {
        goto L_0x0048a54b;
    }
    // 0048a53d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048a542  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a544  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a546  e858f60100             -call 0x4a9ba3
    cpu.esp -= 4;
    sub_4a9ba3(app, cpu);
    if (cpu.terminate) return;
L_0x0048a54b:
    // 0048a54b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a54d  e861f70100             -call 0x4a9cb3
    cpu.esp -= 4;
    sub_4a9cb3(app, cpu);
    if (cpu.terminate) return;
    // 0048a552  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0048a554:
    // 0048a554  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a555  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a556  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a557  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_48a55a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a55a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a55b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a55c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a55d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a560  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a562  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a564  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048a566  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048a568  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a56a  e8eafdffff             -call 0x48a359
    cpu.esp -= 4;
    sub_48a359(app, cpu);
    if (cpu.terminate) return;
    // 0048a56f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a571  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a573  7422                   -je 0x48a597
    if (cpu.flags.zf)
    {
        goto L_0x0048a597;
    }
    // 0048a575  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a577  e8c0f40100             -call 0x4a9a3c
    cpu.esp -= 4;
    sub_4a9a3c(app, cpu);
    if (cpu.terminate) return;
    // 0048a57c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a57e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a580  7413                   -je 0x48a595
    if (cpu.flags.zf)
    {
        goto L_0x0048a595;
    }
    // 0048a582  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a583  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a585  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a586  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a588  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0048a58a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a58e  e8e1feffff             -call 0x48a474
    cpu.esp -= 4;
    sub_48a474(app, cpu);
    if (cpu.terminate) return;
    // 0048a593  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0048a595:
    // 0048a595  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0048a597:
    // 0048a597  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a59a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a59b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a59c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a59d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a59e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a59e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a59f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a5a1  e8b4ffffff             -call 0x48a55a
    cpu.esp -= 4;
    sub_48a55a(app, cpu);
    if (cpu.terminate) return;
    // 0048a5a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a5a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a5a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a5a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a5aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a5ab  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a5ad  ff156ced4d00           -call dword ptr [0x4ded6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107052) /* 0x4ded6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a5b3  a1a4675b00             -mov eax, dword ptr [0x5b67a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */);
L_0x0048a5b8:
    // 0048a5b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a5ba  7429                   -je 0x48a5e5
    if (cpu.flags.zf)
    {
        goto L_0x0048a5e5;
    }
    // 0048a5bc  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048a5bf  39d3                   +cmp ebx, edx
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
    // 0048a5c1  751e                   -jne 0x48a5e1
    if (!cpu.flags.zf)
    {
        goto L_0x0048a5e1;
    }
    // 0048a5c3  f6420c03               +test byte ptr [edx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 0048a5c7  740c                   -je 0x48a5d5
    if (cpu.flags.zf)
    {
        goto L_0x0048a5d5;
    }
    // 0048a5c9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048a5ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a5d0  e8ec020000             -call 0x48a8c1
    cpu.esp -= 4;
    sub_48a8c1(app, cpu);
    if (cpu.terminate) return;
L_0x0048a5d5:
    // 0048a5d5  ff1570ed4d00           -call dword ptr [0x4ded70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107056) /* 0x4ded70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a5db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a5dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a5e1:
    // 0048a5e1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048a5e3  ebd3                   -jmp 0x48a5b8
    goto L_0x0048a5b8;
L_0x0048a5e5:
    // 0048a5e5  baa8675b00             -mov edx, 0x5b67a8
    cpu.edx = 5990312 /*0x5b67a8*/;
L_0x0048a5ea:
    // 0048a5ea  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048a5ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a5ee  741c                   -je 0x48a60c
    if (cpu.flags.zf)
    {
        goto L_0x0048a60c;
    }
    // 0048a5f0  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a5f3  7513                   -jne 0x48a608
    if (!cpu.flags.zf)
    {
        goto L_0x0048a608;
    }
    // 0048a5f5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048a5f7  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048a5f9  8b15a4675b00           -mov edx, dword ptr [0x5b67a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */);
    // 0048a5ff  a3a4675b00             -mov dword ptr [0x5b67a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */) = cpu.eax;
    // 0048a604  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0048a606  ebcd                   -jmp 0x48a5d5
    goto L_0x0048a5d5;
L_0x0048a608:
    // 0048a608  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a60a  ebde                   -jmp 0x48a5ea
    goto L_0x0048a5ea;
L_0x0048a60c:
    // 0048a60c  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0048a611  e89ac00100             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 0048a616  ff1570ed4d00           -call dword ptr [0x4ded70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107056) /* 0x4ded70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a61c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a61e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a61f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a620  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a621  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a622(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a622  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a623  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a624  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a625  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a626  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a629  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048a62b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a62d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048a62f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a631  e823fdffff             -call 0x48a359
    cpu.esp -= 4;
    sub_48a359(app, cpu);
    if (cpu.terminate) return;
    // 0048a636  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a638  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a63a  7455                   -je 0x48a691
    if (cpu.flags.zf)
    {
        goto L_0x0048a691;
    }
    // 0048a63c  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048a63f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a641  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a647  833da8ed4d0000         +cmp dword ptr [0x4deda8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107112) /* 0x4deda8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a64e  7408                   -je 0x48a658
    if (cpu.flags.zf)
    {
        goto L_0x0048a658;
    }
    // 0048a650  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a652  ff15a8ed4d00           -call dword ptr [0x4deda8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107112) /* 0x4deda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048a658:
    // 0048a658  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a65a  e849ffffff             -call 0x48a5a8
    cpu.esp -= 4;
    sub_48a5a8(app, cpu);
    if (cpu.terminate) return;
    // 0048a65f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a661  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a663  7422                   -je 0x48a687
    if (cpu.flags.zf)
    {
        goto L_0x0048a687;
    }
    // 0048a665  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a666  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048a669  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a66b  81e300400000           -and ebx, 0x4000
    cpu.ebx &= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 0048a671  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048a673  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048a676  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048a678  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a67a  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0048a67c  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a680  e8effdffff             -call 0x48a474
    cpu.esp -= 4;
    sub_48a474(app, cpu);
    if (cpu.terminate) return;
    // 0048a685  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048a687:
    // 0048a687  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a689  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a68f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0048a691:
    // 0048a691  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a694  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a695  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a696  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a697  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a698  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a699(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a699  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a69a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a69b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a69c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a69d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a6a0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a6a2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a6a4  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048a6a7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048a6a9  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a6af  8a630c                 -mov ah, byte ptr [ebx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048a6b2  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048a6b5  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 0048a6b8  83e730                 -and edi, 0x30
    cpu.edi &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048a6bb  88630c                 -mov byte ptr [ebx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x0048a6be:
    // 0048a6be  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a6bf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048a6c1  7e19                   -jle 0x48a6dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048a6dc;
    }
    // 0048a6c3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a6c5  e8f5f80100             -call 0x4a9fbf
    cpu.esp -= 4;
    sub_4a9fbf(app, cpu);
    if (cpu.terminate) return;
    // 0048a6ca  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048a6cd  83f8ff                 +cmp eax, -1
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
    // 0048a6d0  740a                   -je 0x48a6dc
    if (cpu.flags.zf)
    {
        goto L_0x0048a6dc;
    }
    // 0048a6d2  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0048a6d5  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0048a6d7  42                     -inc edx
    (cpu.edx)++;
    // 0048a6d8  3c0a                   +cmp al, 0xa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a6da  75e2                   -jne 0x48a6be
    if (!cpu.flags.zf)
    {
        goto L_0x0048a6be;
    }
L_0x0048a6dc:
    // 0048a6dc  833c24ff               +cmp dword ptr [esp], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a6e0  750e                   -jne 0x48a6f0
    if (!cpu.flags.zf)
    {
        goto L_0x0048a6f0;
    }
    // 0048a6e2  39f2                   +cmp edx, esi
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
    // 0048a6e4  7406                   -je 0x48a6ec
    if (cpu.flags.zf)
    {
        goto L_0x0048a6ec;
    }
    // 0048a6e6  f6430c20               +test byte ptr [ebx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 0048a6ea  7404                   -je 0x48a6f0
    if (cpu.flags.zf)
    {
        goto L_0x0048a6f0;
    }
L_0x0048a6ec:
    // 0048a6ec  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0048a6ee  eb03                   -jmp 0x48a6f3
    goto L_0x0048a6f3;
L_0x0048a6f0:
    // 0048a6f0  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x0048a6f3:
    // 0048a6f3  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048a6f6  09fd                   -or ebp, edi
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.edi));
    // 0048a6f8  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048a6fb  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048a6fe  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a704  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a706  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a709  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a70a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a70b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a70c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a70d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a70e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a70e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a70f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a710  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a712  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048a715  e8a5f80100             -call 0x4a9fbf
    cpu.esp -= 4;
    sub_4a9fbf(app, cpu);
    if (cpu.terminate) return;
    // 0048a71a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a71c  83f8ff                 +cmp eax, -1
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
    // 0048a71f  7504                   -jne 0x48a725
    if (!cpu.flags.zf)
    {
        goto L_0x0048a725;
    }
    // 0048a721  804a1002               -or byte ptr [edx + 0x10], 2
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0048a725:
    // 0048a725  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a727  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a728  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a729  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a72a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a72a  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048a72d  e935fa0100             -jmp 0x4aa167
    return sub_4aa167(app, cpu);
}

/* align: skip  */
void Application::sub_48a732(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a732  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a733  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a734  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a735  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048a738  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a73a  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048a73d  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a743  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a746  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048a749  83fe01                 +cmp esi, 1
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
    // 0048a74c  7418                   -je 0x48a766
    if (cpu.flags.zf)
    {
        goto L_0x0048a766;
    }
    // 0048a74e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048a750  740d                   -je 0x48a75f
    if (cpu.flags.zf)
    {
        goto L_0x0048a75f;
    }
    // 0048a752  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048a755  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a75b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a75d  eb30                   -jmp 0x48a78f
    goto L_0x0048a78f;
L_0x0048a75f:
    // 0048a75f  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x0048a766:
    // 0048a766  bd0ea74800             -mov ebp, 0x48a70e
    cpu.ebp = 4761358 /*0x48a70e*/;
    // 0048a76b  b82aa74800             -mov eax, 0x48a72a
    cpu.eax = 4761386 /*0x48a72a*/;
    // 0048a770  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048a774  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048a778  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a77a  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0048a77d  e8aefa0100             -call 0x4aa230
    cpu.esp -= 4;
    sub_4aa230(app, cpu);
    if (cpu.terminate) return;
    // 0048a782  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a784  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048a787  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a78d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0048a78f:
    // 0048a78f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048a792  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a793  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a794  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a795  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a796(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a796  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a797  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a798  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a79b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048a79f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048a7a1  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048a7a5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048a7a8  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048a7ac  e881ffffff             -call 0x48a732
    cpu.esp -= 4;
    sub_48a732(app, cpu);
    if (cpu.terminate) return;
    // 0048a7b1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a7b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a7b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a7b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a7b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a7b9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a7bb  ff156ced4d00           -call dword ptr [0x4ded6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107052) /* 0x4ded6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a7c1  a1a4675b00             -mov eax, dword ptr [0x5b67a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */);
L_0x0048a7c6:
    // 0048a7c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a7c8  750e                   -jne 0x48a7d8
    if (!cpu.flags.zf)
    {
        goto L_0x0048a7d8;
    }
    // 0048a7ca  ff1570ed4d00           -call dword ptr [0x4ded70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107056) /* 0x4ded70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a7d0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048a7d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a7d8:
    // 0048a7d8  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a7db  7404                   -je 0x48a7e1
    if (cpu.flags.zf)
    {
        goto L_0x0048a7e1;
    }
    // 0048a7dd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048a7df  ebe5                   -jmp 0x48a7c6
    goto L_0x0048a7c6;
L_0x0048a7e1:
    // 0048a7e1  ff1570ed4d00           -call dword ptr [0x4ded70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107056) /* 0x4ded70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a7e7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048a7ec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a7ee  e803000000             -call 0x48a7f6
    cpu.esp -= 4;
    sub_48a7f6(app, cpu);
    if (cpu.terminate) return;
    // 0048a7f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a7f6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a7f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a7f7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a7f9  e8c3000000             -call 0x48a8c1
    cpu.esp -= 4;
    sub_48a8c1(app, cpu);
    if (cpu.terminate) return;
    // 0048a7fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a800  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a802  e8f0f20100             -call 0x4a9af7
    cpu.esp -= 4;
    sub_4a9af7(app, cpu);
    if (cpu.terminate) return;
    // 0048a807  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a809  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a80a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a80b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a80b  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048a80e  83f839                 +cmp eax, 0x39
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a811  7e03                   -jle 0x48a816
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048a816;
    }
    // 0048a813  83c027                 -add eax, 0x27
    (cpu.eax) += x86::reg32(x86::sreg32(39 /*0x27*/));
L_0x0048a816:
    // 0048a816  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a817(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a817  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a818  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a819  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a81a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a81b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a81c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a81f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a821  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048a824  e89d080200             -call 0x4ab0c6
    cpu.esp -= 4;
    sub_4ab0c6(app, cpu);
    if (cpu.terminate) return;
    // 0048a829  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a82b  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0048a82e  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0048a830  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a832  e890090200             -call 0x4ab1c7
    cpu.esp -= 4;
    sub_4ab1c7(app, cpu);
    if (cpu.terminate) return;
    // 0048a837  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a839  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048a83a:
    // 0048a83a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048a83c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048a83e  3c00                   +cmp al, 0
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
    // 0048a840  7410                   -je 0x48a852
    if (cpu.flags.zf)
    {
        goto L_0x0048a852;
    }
    // 0048a842  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048a845  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a848  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048a84b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a84e  3c00                   +cmp al, 0
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
    // 0048a850  75e8                   -jne 0x48a83a
    if (!cpu.flags.zf)
    {
        goto L_0x0048a83a;
    }
L_0x0048a852:
    // 0048a852  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a853  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048a854  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048a856  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048a858  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a85a  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a85b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a85d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a85f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048a861  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a862  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048a863  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048a865  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048a868  c60174                 -mov byte ptr [ecx], 0x74
    app->getMemory<x86::reg8>(cpu.ecx) = 116 /*0x74*/;
    // 0048a86b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0048a86d:
    // 0048a86d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a86f  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048a872  e894ffffff             -call 0x48a80b
    cpu.esp -= 4;
    sub_48a80b(app, cpu);
    if (cpu.terminate) return;
    // 0048a877  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0048a879  4a                     -dec edx
    (cpu.edx)--;
    // 0048a87a  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 0048a87d  39f2                   +cmp edx, esi
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
    // 0048a87f  75ec                   -jne 0x48a86d
    if (!cpu.flags.zf)
    {
        goto L_0x0048a86d;
    }
    // 0048a881  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a884  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0048a887  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048a88a  c641055f               -mov byte ptr [ecx + 5], 0x5f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 0048a88e  e878ffffff             -call 0x48a80b
    cpu.esp -= 4;
    sub_48a80b(app, cpu);
    if (cpu.terminate) return;
    // 0048a893  884106                 -mov byte ptr [ecx + 6], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 0048a896  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a899  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048a89c  e86affffff             -call 0x48a80b
    cpu.esp -= 4;
    sub_48a80b(app, cpu);
    if (cpu.terminate) return;
    // 0048a8a1  c641082e               -mov byte ptr [ecx + 8], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 0048a8a5  c6410974               -mov byte ptr [ecx + 9], 0x74
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 0048a8a9  c6410a6d               -mov byte ptr [ecx + 0xa], 0x6d
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 0048a8ad  c6410b70               -mov byte ptr [ecx + 0xb], 0x70
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 0048a8b1  c6410c00               -mov byte ptr [ecx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048a8b5  884107                 -mov byte ptr [ecx + 7], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0048a8b8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a8bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a8bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0048a8bb;
    // 0048a817  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a818  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a819  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a81a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a81b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a81c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a81f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a821  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048a824  e89d080200             -call 0x4ab0c6
    cpu.esp -= 4;
    sub_4ab0c6(app, cpu);
    if (cpu.terminate) return;
    // 0048a829  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a82b  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0048a82e  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0048a830  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a832  e890090200             -call 0x4ab1c7
    cpu.esp -= 4;
    sub_4ab1c7(app, cpu);
    if (cpu.terminate) return;
    // 0048a837  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a839  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048a83a:
    // 0048a83a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048a83c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048a83e  3c00                   +cmp al, 0
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
    // 0048a840  7410                   -je 0x48a852
    if (cpu.flags.zf)
    {
        goto L_0x0048a852;
    }
    // 0048a842  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048a845  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a848  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048a84b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a84e  3c00                   +cmp al, 0
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
    // 0048a850  75e8                   -jne 0x48a83a
    if (!cpu.flags.zf)
    {
        goto L_0x0048a83a;
    }
L_0x0048a852:
    // 0048a852  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a853  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048a854  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048a856  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048a858  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a85a  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a85b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a85d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a85f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048a861  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a862  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048a863  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048a865  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048a868  c60174                 -mov byte ptr [ecx], 0x74
    app->getMemory<x86::reg8>(cpu.ecx) = 116 /*0x74*/;
    // 0048a86b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0048a86d:
    // 0048a86d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a86f  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048a872  e894ffffff             -call 0x48a80b
    cpu.esp -= 4;
    sub_48a80b(app, cpu);
    if (cpu.terminate) return;
    // 0048a877  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0048a879  4a                     -dec edx
    (cpu.edx)--;
    // 0048a87a  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 0048a87d  39f2                   +cmp edx, esi
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
    // 0048a87f  75ec                   -jne 0x48a86d
    if (!cpu.flags.zf)
    {
        goto L_0x0048a86d;
    }
    // 0048a881  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a884  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0048a887  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048a88a  c641055f               -mov byte ptr [ecx + 5], 0x5f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 0048a88e  e878ffffff             -call 0x48a80b
    cpu.esp -= 4;
    sub_48a80b(app, cpu);
    if (cpu.terminate) return;
    // 0048a893  884106                 -mov byte ptr [ecx + 6], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 0048a896  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a899  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048a89c  e86affffff             -call 0x48a80b
    cpu.esp -= 4;
    sub_48a80b(app, cpu);
    if (cpu.terminate) return;
    // 0048a8a1  c641082e               -mov byte ptr [ecx + 8], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 0048a8a5  c6410974               -mov byte ptr [ecx + 9], 0x74
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 0048a8a9  c6410a6d               -mov byte ptr [ecx + 0xa], 0x6d
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 0048a8ad  c6410b70               -mov byte ptr [ecx + 0xb], 0x70
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 0048a8b1  c6410c00               -mov byte ptr [ecx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048a8b5  884107                 -mov byte ptr [ecx + 7], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0048a8b8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_entry_0x0048a8bb:
    // 0048a8bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a8c1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a8c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a8c2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a8c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a8c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a8c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a8c6  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 0048a8cc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a8ce  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048a8d0  83780c00               +cmp dword ptr [eax + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a8d4  750a                   -jne 0x48a8e0
    if (!cpu.flags.zf)
    {
        goto L_0x0048a8e0;
    }
    // 0048a8d6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048a8db  e993000000             -jmp 0x48a973
    goto L_0x0048a973;
L_0x0048a8e0:
    // 0048a8e0  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0048a8e3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048a8e5  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 0048a8e8  7409                   -je 0x48a8f3
    if (cpu.flags.zf)
    {
        goto L_0x0048a8f3;
    }
    // 0048a8ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a8ec  e89e090200             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
    // 0048a8f1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0048a8f3:
    // 0048a8f3  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048a8f6  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a8fc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a8fe  e89b0a0200             -call 0x4ab39e
    cpu.esp -= 4;
    sub_4ab39e(app, cpu);
    if (cpu.terminate) return;
    // 0048a903  83f8ff                 +cmp eax, -1
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
    // 0048a906  740e                   -je 0x48a916
    if (cpu.flags.zf)
    {
        goto L_0x0048a916;
    }
    // 0048a908  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a90a  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048a90d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a90f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a911  e8e10a0200             -call 0x4ab3f7
    cpu.esp -= 4;
    sub_4ab3f7(app, cpu);
    if (cpu.terminate) return;
L_0x0048a916:
    // 0048a916  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048a918  740a                   -je 0x48a924
    if (cpu.flags.zf)
    {
        goto L_0x0048a924;
    }
    // 0048a91a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048a91d  e8490b0200             -call 0x4ab46b
    cpu.esp -= 4;
    sub_4ab46b(app, cpu);
    if (cpu.terminate) return;
    // 0048a922  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048a924:
    // 0048a924  f6410c08               +test byte ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 0048a928  7415                   -je 0x48a93f
    if (cpu.flags.zf)
    {
        goto L_0x0048a93f;
    }
    // 0048a92a  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a92d  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048a930  e8c30b0200             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 0048a935  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a938  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x0048a93f:
    // 0048a93f  f6410d08               +test byte ptr [ecx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 0048a943  7416                   -je 0x48a95b
    if (cpu.flags.zf)
    {
        goto L_0x0048a95b;
    }
    // 0048a945  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a948  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a94a  8a5014                 -mov dl, byte ptr [eax + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048a94d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a94f  e8c3feffff             -call 0x48a817
    cpu.esp -= 4;
    sub_48a817(app, cpu);
    if (cpu.terminate) return;
    // 0048a954  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a956  e8a10c0200             -call 0x4ab5fc
    cpu.esp -= 4;
    sub_4ab5fc(app, cpu);
    if (cpu.terminate) return;
L_0x0048a95b:
    // 0048a95b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048a95e  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a964  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048a966  7409                   -je 0x48a971
    if (cpu.flags.zf)
    {
        goto L_0x0048a971;
    }
    // 0048a968  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048a96b  ff1568ed4d00           -call dword ptr [0x4ded68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107048) /* 0x4ded68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048a971:
    // 0048a971  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0048a973:
    // 0048a973  81c414010000           +add esp, 0x114
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(276 /*0x114*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a979  e93dffffff             -jmp 0x48a8bb
    return sub_48a8bb(app, cpu);
}

/* align: skip 0x00 0x00 */
void Application::sub_48a980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a981  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a983  39c2                   +cmp edx, eax
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
    // 0048a985  771d                   -ja 0x48a9a4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048a9a4;
    }
L_0x0048a987:
    // 0048a987  833dacab4d0000         +cmp dword ptr [0x4dabac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a98e  752f                   -jne 0x48a9bf
    if (!cpu.flags.zf)
    {
        goto L_0x0048a9bf;
    }
    // 0048a990  833da4ab4d0000         +cmp dword ptr [0x4daba4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a997  7433                   -je 0x48a9cc
    if (cpu.flags.zf)
    {
        goto L_0x0048a9cc;
    }
    // 0048a999  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a99b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a99d  e87b0c0200             -call 0x4ab61d
    cpu.esp -= 4;
    sub_4ab61d(app, cpu);
    if (cpu.terminate) return;
L_0x0048a9a2:
    // 0048a9a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a9a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a9a4:
    // 0048a9a4  8d1418                 -lea edx, [eax + ebx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0048a9a7  39d1                   +cmp ecx, edx
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
    // 0048a9a9  73dc                   -jae 0x48a987
    if (!cpu.flags.cf)
    {
        goto L_0x0048a987;
    }
    // 0048a9ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a9ad  8d1419                 -lea edx, [ecx + ebx]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebx * 1);
L_0x0048a9b0:
    // 0048a9b0  4b                     -dec ebx
    (cpu.ebx)--;
    // 0048a9b1  83fbff                 +cmp ebx, -1
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
    // 0048a9b4  74ec                   -je 0x48a9a2
    if (cpu.flags.zf)
    {
        goto L_0x0048a9a2;
    }
    // 0048a9b6  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048a9b7  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0048a9ba  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048a9bb  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 0048a9bd  ebf1                   -jmp 0x48a9b0
    goto L_0x0048a9b0;
L_0x0048a9bf:
    // 0048a9bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a9c1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a9c3  e8310d0200             -call 0x4ab6f9
    cpu.esp -= 4;
    sub_4ab6f9(app, cpu);
    if (cpu.terminate) return;
    // 0048a9c8  0f77                   -emms 
    cpu.mmx.init();
    // 0048a9ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a9cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a9cc:
    // 0048a9cc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a9ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a9d0  e8006b0100             -call 0x4a14d5
    cpu.esp -= 4;
    sub_4a14d5(app, cpu);
    if (cpu.terminate) return;
    // 0048a9d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a9d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48a9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a9e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a9e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a9e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a9e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a9e4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048a9e7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a9e9  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0048a9ee  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 0048a9f3  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0048a9f8  6689542404             -mov word ptr [esp + 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0048a9fd  e8a6a80300             -call 0x4c52a8
    cpu.esp -= 4;
    sub_4c52a8(app, cpu);
    if (cpu.terminate) return;
    // 0048aa02  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048aa07  668944240c             -mov word ptr [esp + 0xc], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 0048aa0c  8d442402               -lea eax, [esp + 2]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 0048aa10  e811f6ffff             -call 0x48a026
    cpu.esp -= 4;
    sub_48a026(app, cpu);
    if (cpu.terminate) return;
    // 0048aa15  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0048aa1a  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0048aa1f  8d442406               -lea eax, [esp + 6]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 0048aa23  e8fef5ffff             -call 0x48a026
    cpu.esp -= 4;
    sub_48a026(app, cpu);
    if (cpu.terminate) return;
    // 0048aa28  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048aa2d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048aa32  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048aa36  e819160000             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048aa3b  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048aa40  babe080000             -mov edx, 0x8be
    cpu.edx = 2238 /*0x8be*/;
    // 0048aa45  8d442412               -lea eax, [esp + 0x12]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(18) /* 0x12 */);
    // 0048aa49  e806160000             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048aa4e  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0048aa53  e8f0f4ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048aa58  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 0048aa5a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048aa5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048aa5f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048aa61  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0048aa63  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048aa67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048aa68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048aa69  e828a80300             -call 0x4c5296
    cpu.esp -= 4;
    sub_4c5296(app, cpu);
    if (cpu.terminate) return;
    // 0048aa6e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048aa70  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0048aa75  e8e6f4ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048aa7a  83feff                 +cmp esi, -1
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
    // 0048aa7d  740d                   -je 0x48aa8c
    if (cpu.flags.zf)
    {
        goto L_0x0048aa8c;
    }
    // 0048aa7f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048aa84  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048aa87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa88  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048aa8c:
    // 0048aa8c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048aa8e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048aa91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48aa98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048aa98  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048aa99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048aa9a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048aa9b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048aa9e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048aaa1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048aaa3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048aaa5  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 0048aaaa  668b720c               -mov si, word ptr [edx + 0xc]
    cpu.si = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048aaae  e8f5a70300             -call 0x4c52a8
    cpu.esp -= 4;
    sub_4c52a8(app, cpu);
    if (cpu.terminate) return;
    // 0048aab3  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048aab8  39c6                   +cmp esi, eax
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
    // 0048aaba  7409                   -je 0x48aac5
    if (cpu.flags.zf)
    {
        goto L_0x0048aac5;
    }
L_0x0048aabc:
    // 0048aabc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048aabe  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048aac1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aac2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aac3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aac4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048aac5:
    // 0048aac5  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048aaca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048aacc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048aace  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048aad0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048aad2  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048aad9  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048aadb  83f802                 +cmp eax, 2
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
    // 0048aade  75dc                   -jne 0x48aabc
    if (!cpu.flags.zf)
    {
        goto L_0x0048aabc;
    }
    // 0048aae0  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048aae2  c1ef06                 -shr edi, 6
    cpu.edi >>= 6 /*0x6*/ % 32;
    // 0048aae5  8d3403                 -lea esi, [ebx + eax]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0048aae8  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0048aaec  8d7e32                 -lea edi, [esi + 0x32]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(50) /* 0x32 */);
    // 0048aaef  8d2c06                 -lea ebp, [esi + eax]
    cpu.ebp = x86::reg32(cpu.esi + cpu.eax * 1);
L_0x0048aaf2:
    // 0048aaf2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048aaf6  4a                     -dec edx
    (cpu.edx)--;
    // 0048aaf7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048aafb  83faff                 +cmp edx, -1
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
    // 0048aafe  750c                   -jne 0x48ab0c
    if (!cpu.flags.zf)
    {
        goto L_0x0048ab0c;
    }
    // 0048ab00  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048ab05  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ab08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab0b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ab0c:
    // 0048ab0c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048ab11  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ab13  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ab15  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048ab17  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048ab19  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048ab20  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ab22  3dbe080000             +cmp eax, 0x8be
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2238 /*0x8be*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ab27  740b                   -je 0x48ab34
    if (cpu.flags.zf)
    {
        goto L_0x0048ab34;
    }
    // 0048ab29  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048ab2c  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048ab2f  83c640                 +add esi, 0x40
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ab32  ebbe                   -jmp 0x48aaf2
    goto L_0x0048aaf2;
L_0x0048ab34:
    // 0048ab34  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ab37  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048ab39  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048ab3b  e8c02ff9ff             -call 0x41db00
    cpu.esp -= 4;
    sub_41db00(app, cpu);
    if (cpu.terminate) return;
    // 0048ab40  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048ab43  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048ab46  83c640                 +add esi, 0x40
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ab49  eba7                   -jmp 0x48aaf2
    goto L_0x0048aaf2;
}

/* align: skip 0x90 */
void Application::sub_48ab4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ab4c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ab4d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ab4e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ab50  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0048ab55  e8eef3ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048ab5a  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 0048ab5c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ab5d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ab5f  6a42                   -push 0x42
    app->getMemory<x86::reg32>(cpu.esp-4) = 66 /*0x42*/;
    cpu.esp -= 4;
    // 0048ab61  68e2425600             -push 0x5642e2
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653218 /*0x5642e2*/;
    cpu.esp -= 4;
    // 0048ab66  8b15cc425600           -mov edx, dword ptr [0x5642cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653196) /* 0x5642cc */);
    // 0048ab6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ab6d  e824a70300             -call 0x4c5296
    cpu.esp -= 4;
    sub_4c5296(app, cpu);
    if (cpu.terminate) return;
    // 0048ab72  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0048ab77  e8e4f3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048ab7c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ab80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ab80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ab81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ab82  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048ab84  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048ab89  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ab8b  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048ab8d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048ab8f  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048ab96  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ab98  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048ab9d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ab9f  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0048aba2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048aba4  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048aba6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048aba8  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048abaf  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048abb1  83fa01                 +cmp edx, 1
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
    // 0048abb4  7516                   -jne 0x48abcc
    if (!cpu.flags.zf)
    {
        goto L_0x0048abcc;
    }
    // 0048abb6  3dbe080000             +cmp eax, 0x8be
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2238 /*0x8be*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048abbb  7407                   -je 0x48abc4
    if (cpu.flags.zf)
    {
        goto L_0x0048abc4;
    }
    // 0048abbd  3dffff0000             +cmp eax, 0xffff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048abc2  7508                   -jne 0x48abcc
    if (!cpu.flags.zf)
    {
        goto L_0x0048abcc;
    }
L_0x0048abc4:
    // 0048abc4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048abc9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048abca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048abcb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048abcc:
    // 0048abcc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048abce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048abcf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048abd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48abd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048abd4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048abd5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048abd6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048abd7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048abd8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048abd9  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048abdc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048abde  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 0048abe3  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048abe5  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0048abe7  e8daa60300             -call 0x4c52c6
    cpu.esp -= 4;
    sub_4c52c6(app, cpu);
    if (cpu.terminate) return;
    // 0048abec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048abee  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048abf0  83f8ff                 +cmp eax, -1
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
    // 0048abf3  7510                   -jne 0x48ac05
    if (!cpu.flags.zf)
    {
        goto L_0x0048ac05;
    }
    // 0048abf5  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x0048abfa:
    // 0048abfa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048abfc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048abff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ac05:
    // 0048ac05  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0048ac07  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ac0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ac0c  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0048ac0e  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0048ac13  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048ac18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ac19  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048ac1d  e892a60300             -call 0x4c52b4
    cpu.esp -= 4;
    sub_4c52b4(app, cpu);
    if (cpu.terminate) return;
    // 0048ac22  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0048ac24  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ac28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ac29  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 0048ac2e  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0048ac33  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ac34  e87ba60300             -call 0x4c52b4
    cpu.esp -= 4;
    sub_4c52b4(app, cpu);
    if (cpu.terminate) return;
    // 0048ac39  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 0048ac3e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ac40  e8d7f3ffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048ac45  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 0048ac4a  66c7060600             -mov word ptr [esi], 6
    app->getMemory<x86::reg16>(cpu.esi) = 6 /*0x6*/;
    // 0048ac4f  e854a60300             -call 0x4c52a8
    cpu.esp -= 4;
    sub_4c52a8(app, cpu);
    if (cpu.terminate) return;
    // 0048ac54  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 0048ac56  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ac57  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ac58  6689460c               -mov word ptr [esi + 0xc], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 0048ac5c  e841a60300             -call 0x4c52a2
    cpu.esp -= 4;
    sub_4c52a2(app, cpu);
    if (cpu.terminate) return;
    // 0048ac61  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ac63  7524                   -jne 0x48ac89
    if (!cpu.flags.zf)
    {
        goto L_0x0048ac89;
    }
    // 0048ac65  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ac69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ac6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ac6b  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0048ac70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ac71  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0048ac75  e822a60300             -call 0x4c529c
    cpu.esp -= 4;
    sub_4c529c(app, cpu);
    if (cpu.terminate) return;
    // 0048ac7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ac7c  750b                   -jne 0x48ac89
    if (!cpu.flags.zf)
    {
        goto L_0x0048ac89;
    }
    // 0048ac7e  837c24040e             +cmp dword ptr [esp + 4], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ac83  0f8471ffffff           -je 0x48abfa
    if (cpu.flags.zf)
    {
        goto L_0x0048abfa;
    }
L_0x0048ac89:
    // 0048ac89  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ac8a  e831a60300             -call 0x4c52c0
    cpu.esp -= 4;
    sub_4c52c0(app, cpu);
    if (cpu.terminate) return;
    // 0048ac8f  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0048ac94  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ac96  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ac99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48aca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048aca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048aca1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048aca2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048aca3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048aca4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048aca5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048aca6  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 0048acac  e8ff900100             -call 0x4a3db0
    cpu.esp -= 4;
    sub_4a3db0(app, cpu);
    if (cpu.terminate) return;
    // 0048acb1  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0048acb6  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 0048acbb  8d5804                 -lea ebx, [eax + 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048acbe  6689942418030000       -mov word ptr [esp + 0x318], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.dx;
    // 0048acc6  e8dda50300             -call 0x4c52a8
    cpu.esp -= 4;
    sub_4c52a8(app, cpu);
    if (cpu.terminate) return;
    // 0048accb  8d942414030000         -lea edx, [esp + 0x314]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 0048acd2  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0048acd3  e8682ff9ff             -call 0x41dc40
    cpu.esp -= 4;
    sub_41dc40(app, cpu);
    if (cpu.terminate) return;
    // 0048acd8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048acdd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048acdf  8915c8425600           -mov dword ptr [0x5642c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */) = cpu.edx;
    // 0048ace5  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 0048acea  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048acec:
    // 0048acec  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048acf1  a1cc425600             -mov eax, dword ptr [0x5642cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653196) /* 0x5642cc */);
    // 0048acf6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048acf8  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 0048acff  89842404020000         -mov dword ptr [esp + 0x204], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.eax;
    // 0048ad06  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048ad09  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 0048ad0e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ad10  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048ad12  89842424030000         -mov dword ptr [esp + 0x324], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.eax;
    // 0048ad19  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048ad1b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ad1d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048ad20  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048ad22  69c2e8030000           -imul eax, edx, 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 0048ad28  89842428030000         -mov dword ptr [esp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 0048ad2f  8d842424030000         -lea eax, [esp + 0x324]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 0048ad36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ad37  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ad38  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ad39  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0048ad40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ad41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ad42  e83da50300             -call 0x4c5284
    cpu.esp -= 4;
    sub_4c5284(app, cpu);
    if (cpu.terminate) return;
    // 0048ad47  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ad49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ad4b  0f84bc000000           -je 0x48ae0d
    if (cpu.flags.zf)
    {
        goto L_0x0048ae0d;
    }
    // 0048ad51  83f8ff                 +cmp eax, -1
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
    // 0048ad54  0f84b3000000           -je 0x48ae0d
    if (cpu.flags.zf)
    {
        goto L_0x0048ae0d;
    }
    // 0048ad5a  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0048ad5f  89ac242c030000         -mov dword ptr [esp + 0x32c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = cpu.ebp;
    // 0048ad66  e8ddf1ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048ad6b  8d84242c030000         -lea eax, [esp + 0x32c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(812) /* 0x32c */);
    // 0048ad72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ad73  8d842408030000         -lea eax, [esp + 0x308]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 0048ad7a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ad7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ad7c  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 0048ad81  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048ad85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ad86  a1cc425600             -mov eax, dword ptr [0x5642cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653196) /* 0x5642cc */);
    // 0048ad8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ad8c  e847a50300             -call 0x4c52d8
    cpu.esp -= 4;
    sub_4c52d8(app, cpu);
    if (cpu.terminate) return;
    // 0048ad91  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ad93  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 0048ad98  e8c3f1ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048ad9d  83fa04                 +cmp edx, 4
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
    // 0048ada0  7517                   -jne 0x48adb9
    if (!cpu.flags.zf)
    {
        goto L_0x0048adb9;
    }
    // 0048ada2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048ada4  e8d7fdffff             -call 0x48ab80
    cpu.esp -= 4;
    sub_48ab80(app, cpu);
    if (cpu.terminate) return;
    // 0048ada9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048adab  740c                   -je 0x48adb9
    if (cpu.flags.zf)
    {
        goto L_0x0048adb9;
    }
    // 0048adad  8d842404030000         -lea eax, [esp + 0x304]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0048adb4  e893fdffff             -call 0x48ab4c
    cpu.esp -= 4;
    sub_48ab4c(app, cpu);
    if (cpu.terminate) return;
L_0x0048adb9:
    // 0048adb9  3b3dc8425600           +cmp edi, dword ptr [0x5642c8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048adbf  7425                   -je 0x48ade6
    if (cpu.flags.zf)
    {
        goto L_0x0048ade6;
    }
    // 0048adc1  e8ea8f0100             -call 0x4a3db0
    cpu.esp -= 4;
    sub_4a3db0(app, cpu);
    if (cpu.terminate) return;
    // 0048adc6  39c3                   +cmp ebx, eax
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
    // 0048adc8  731c                   -jae 0x48ade6
    if (!cpu.flags.cf)
    {
        goto L_0x0048ade6;
    }
    // 0048adca  8d842414030000         -lea eax, [esp + 0x314]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 0048add1  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0048add6  e871fdffff             -call 0x48ab4c
    cpu.esp -= 4;
    sub_48ab4c(app, cpu);
    if (cpu.terminate) return;
    // 0048addb  e8d08f0100             -call 0x4a3db0
    cpu.esp -= 4;
    sub_4a3db0(app, cpu);
    if (cpu.terminate) return;
    // 0048ade0  8d9860ea0000           -lea ebx, [eax + 0xea60]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(60000) /* 0xea60 */);
L_0x0048ade6:
    // 0048ade6  3b3dc8425600           +cmp edi, dword ptr [0x5642c8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048adec  0f85fafeffff           -jne 0x48acec
    if (!cpu.flags.zf)
    {
        goto L_0x0048acec;
    }
L_0x0048adf2:
    // 0048adf2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048adf4  7526                   -jne 0x48ae1c
    if (!cpu.flags.zf)
    {
        goto L_0x0048ae1c;
    }
L_0x0048adf6:
    // 0048adf6  c705c442560001000000   -mov dword ptr [0x5642c4], 1
    app->getMemory<x86::reg32>(x86::reg32(5653188) /* 0x5642c4 */) = 1 /*0x1*/;
    // 0048ae00  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 0048ae06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae07  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae08  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ae0d:
    // 0048ae0d  83faff                 +cmp edx, -1
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
    // 0048ae10  75a7                   -jne 0x48adb9
    if (!cpu.flags.zf)
    {
        goto L_0x0048adb9;
    }
    // 0048ae12  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0048ae14  891dc8425600           -mov dword ptr [0x5642c8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */) = cpu.ebx;
    // 0048ae1a  ebd6                   -jmp 0x48adf2
    goto L_0x0048adf2;
L_0x0048ae1c:
    // 0048ae1c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048ae21  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048ae26  b822435600             -mov eax, 0x564322
    cpu.eax = 5653282 /*0x564322*/;
    // 0048ae2b  e824120000             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048ae30  8d842414030000         -lea eax, [esp + 0x314]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 0048ae37  e810fdffff             -call 0x48ab4c
    cpu.esp -= 4;
    sub_48ab4c(app, cpu);
    if (cpu.terminate) return;
    // 0048ae3c  ebb8                   -jmp 0x48adf6
    goto L_0x0048adf6;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ae40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ae40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ae41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ae42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ae43  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048ae45  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048ae47  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048ae49  833dc842560000         +cmp dword ptr [0x5642c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ae50  7409                   -je 0x48ae5b
    if (cpu.flags.zf)
    {
        goto L_0x0048ae5b;
    }
L_0x0048ae52:
    // 0048ae52  a1c8425600             -mov eax, dword ptr [0x5642c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */);
    // 0048ae57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ae5b:
    // 0048ae5b  b8d4425600             -mov eax, 0x5642d4
    cpu.eax = 5653204 /*0x5642d4*/;
    // 0048ae60  e86ffdffff             -call 0x48abd4
    cpu.esp -= 4;
    sub_48abd4(app, cpu);
    if (cpu.terminate) return;
    // 0048ae65  a3cc425600             -mov dword ptr [0x5642cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653196) /* 0x5642cc */) = cpu.eax;
    // 0048ae6a  83f8ff                 +cmp eax, -1
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
    // 0048ae6d  74e3                   -je 0x48ae52
    if (cpu.flags.zf)
    {
        goto L_0x0048ae52;
    }
    // 0048ae6f  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048ae74  b8e2425600             -mov eax, 0x5642e2
    cpu.eax = 5653218 /*0x5642e2*/;
    // 0048ae79  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048ae7b  893dd0425600           -mov dword ptr [0x5642d0], edi
    app->getMemory<x86::reg32>(x86::reg32(5653200) /* 0x5642d0 */) = cpu.edi;
    // 0048ae81  e8ce110000             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048ae86  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048ae8b  babe080000             -mov edx, 0x8be
    cpu.edx = 2238 /*0x8be*/;
    // 0048ae90  b8e4425600             -mov eax, 0x5642e4
    cpu.eax = 5653220 /*0x5642e4*/;
    // 0048ae95  e8ba110000             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048ae9a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048ae9f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048aea4  b822435600             -mov eax, 0x564322
    cpu.eax = 5653282 /*0x564322*/;
    // 0048aea9  e8a6110000             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048aeae  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 0048aeb3  b8e6425600             -mov eax, 0x5642e6
    cpu.eax = 5653222 /*0x5642e6*/;
    // 0048aeb8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048aeba  bf16435600             -mov edi, 0x564316
    cpu.edi = 5653270 /*0x564316*/;
    // 0048aebf  e818b6ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048aec4  68b0425600             -push 0x5642b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653168 /*0x5642b0*/;
    cpu.esp -= 4;
    // 0048aec9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048aece  b8a0ac4800             -mov eax, 0x48aca0
    cpu.eax = 4762784 /*0x48aca0*/;
    // 0048aed3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048aed5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048aed6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048aed7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048aed8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048aeda  890dc4425600           -mov dword ptr [0x5642c4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653188) /* 0x5642c4 */) = cpu.ecx;
    // 0048aee0  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0048aee5  e8f6ebffff             -call 0x489ae0
    cpu.esp -= 4;
    sub_489ae0(app, cpu);
    if (cpu.terminate) return;
    // 0048aeea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048aeec  7422                   -je 0x48af10
    if (cpu.flags.zf)
    {
        goto L_0x0048af10;
    }
    // 0048aeee  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0048aef3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048aef5:
    // 0048aef5  8b1dc8425600           -mov ebx, dword ptr [0x5642c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */);
    // 0048aefb  39d9                   +cmp ecx, ebx
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
    // 0048aefd  7511                   -jne 0x48af10
    if (!cpu.flags.zf)
    {
        goto L_0x0048af10;
    }
    // 0048aeff  3b1dc4425600           +cmp ebx, dword ptr [0x5642c4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653188) /* 0x5642c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048af05  7509                   -jne 0x48af10
    if (!cpu.flags.zf)
    {
        goto L_0x0048af10;
    }
    // 0048af07  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048af09  e88eecffff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 0048af0e  ebe5                   -jmp 0x48aef5
    goto L_0x0048aef5;
L_0x0048af10:
    // 0048af10  833dc442560000         +cmp dword ptr [0x5642c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653188) /* 0x5642c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048af17  0f8435ffffff           -je 0x48ae52
    if (cpu.flags.zf)
    {
        goto L_0x0048ae52;
    }
    // 0048af1d  a1cc425600             -mov eax, dword ptr [0x5642cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653196) /* 0x5642cc */);
    // 0048af22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048af23  e898a30300             -call 0x4c52c0
    cpu.esp -= 4;
    sub_4c52c0(app, cpu);
    if (cpu.terminate) return;
    // 0048af28  a1c8425600             -mov eax, dword ptr [0x5642c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */);
    // 0048af2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48af34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048af34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048af35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048af36  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048af37  833dc842560000         +cmp dword ptr [0x5642c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048af3e  7509                   -jne 0x48af49
    if (!cpu.flags.zf)
    {
        goto L_0x0048af49;
    }
L_0x0048af40:
    // 0048af40  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048af45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048af49:
    // 0048af49  8b1dcc425600           -mov ebx, dword ptr [0x5642cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653196) /* 0x5642cc */);
    // 0048af4f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048af51  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048af52  890dc8425600           -mov dword ptr [0x5642c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653192) /* 0x5642c8 */) = cpu.ecx;
    // 0048af58  e863a30300             -call 0x4c52c0
    cpu.esp -= 4;
    sub_4c52c0(app, cpu);
    if (cpu.terminate) return;
    // 0048af5d  833dc442560000         +cmp dword ptr [0x5642c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653188) /* 0x5642c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048af64  75da                   -jne 0x48af40
    if (!cpu.flags.zf)
    {
        goto L_0x0048af40;
    }
L_0x0048af66:
    // 0048af66  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048af6b  e82cecffff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 0048af70  833dc442560000         +cmp dword ptr [0x5642c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653188) /* 0x5642c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048af77  74ed                   -je 0x48af66
    if (cpu.flags.zf)
    {
        goto L_0x0048af66;
    }
    // 0048af79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048af7e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48af90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048af90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048af91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048af92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048af93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048af94  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048af96  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048af98  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048af9a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048af9c  39d0                   +cmp eax, edx
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
    // 0048af9e  7540                   -jne 0x48afe0
    if (!cpu.flags.zf)
    {
        goto L_0x0048afe0;
    }
    // 0048afa0  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048afa2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048afa4  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048afa8  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048afac  39d0                   +cmp eax, edx
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
    // 0048afae  7530                   -jne 0x48afe0
    if (!cpu.flags.zf)
    {
        goto L_0x0048afe0;
    }
    // 0048afb0  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048afb2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048afb4  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0048afb8  668b5706               -mov dx, word ptr [edi + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0048afbc  39d0                   +cmp eax, edx
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
    // 0048afbe  7520                   -jne 0x48afe0
    if (!cpu.flags.zf)
    {
        goto L_0x0048afe0;
    }
    // 0048afc0  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048afc2  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048afc5  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048afc7  8a7f08                 -mov bh, byte ptr [edi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048afca  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048afcc  38fb                   +cmp bl, bh
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
    // 0048afce  7510                   -jne 0x48afe0
    if (!cpu.flags.zf)
    {
        goto L_0x0048afe0;
    }
L_0x0048afd0:
    // 0048afd0  42                     -inc edx
    (cpu.edx)++;
    // 0048afd1  40                     -inc eax
    (cpu.eax)++;
    // 0048afd2  41                     -inc ecx
    (cpu.ecx)++;
    // 0048afd3  83f808                 +cmp eax, 8
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
    // 0048afd6  7d0f                   -jge 0x48afe7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048afe7;
    }
    // 0048afd8  8a5908                 -mov bl, byte ptr [ecx + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048afdb  3a5a08                 +cmp bl, byte ptr [edx + 8]
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
    // 0048afde  74f0                   -je 0x48afd0
    if (cpu.flags.zf)
    {
        goto L_0x0048afd0;
    }
L_0x0048afe0:
    // 0048afe0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048afe2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afe3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afe4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afe5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afe6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048afe7:
    // 0048afe7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048afec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aff0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48aff4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048aff4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048aff5  833de0ba4d0000         +cmp dword ptr [0x4dbae0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094112) /* 0x4dbae0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048affc  742b                   -je 0x48b029
    if (cpu.flags.zf)
    {
        goto L_0x0048b029;
    }
L_0x0048affe:
    // 0048affe  b864435600             -mov eax, 0x564364
    cpu.eax = 5653348 /*0x564364*/;
    // 0048b003  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b005  e86a0d0000             -call 0x48bd74
    cpu.esp -= 4;
    sub_48bd74(app, cpu);
    if (cpu.terminate) return;
    // 0048b00a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b00c  7407                   -je 0x48b015
    if (cpu.flags.zf)
    {
        goto L_0x0048b015;
    }
    // 0048b00e  e8e9010000             -call 0x48b1fc
    cpu.esp -= 4;
    sub_48b1fc(app, cpu);
    if (cpu.terminate) return;
    // 0048b013  ebe9                   -jmp 0x48affe
    goto L_0x0048affe;
L_0x0048b015:
    // 0048b015  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b016  b864435600             -mov eax, 0x564364
    cpu.eax = 5653348 /*0x564364*/;
    // 0048b01b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b01d  e84a0a0000             -call 0x48ba6c
    cpu.esp -= 4;
    sub_48ba6c(app, cpu);
    if (cpu.terminate) return;
    // 0048b022  890de0ba4d00           -mov dword ptr [0x4dbae0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094112) /* 0x4dbae0 */) = cpu.ecx;
    // 0048b028  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048b029:
    // 0048b029  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b02a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b02c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b02c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b02d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b02e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b02f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048b032  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048b036  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048b039  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048b03d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048b03f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048b044  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b046  8b0ddcba4d00           -mov ecx, dword ptr [0x4dbadc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094108) /* 0x4dbadc */);
    // 0048b04c  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048b050  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b052  7e43                   -jle 0x48b097
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b097;
    }
    // 0048b054  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048b056:
    // 0048b056  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b058  743d                   -je 0x48b097
    if (cpu.flags.zf)
    {
        goto L_0x0048b097;
    }
    // 0048b05a  8b9624435600           -mov edx, dword ptr [esi + 0x564324]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5653284) /* 0x564324 */);
    // 0048b060  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048b063  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b065  7537                   -jne 0x48b09e
    if (!cpu.flags.zf)
    {
        goto L_0x0048b09e;
    }
    // 0048b067  83ff20                 +cmp edi, 0x20
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
    // 0048b06a  7715                   -ja 0x48b081
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048b081;
    }
    // 0048b06c  8b8644435600           -mov eax, dword ptr [esi + 0x564344]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5653316) /* 0x564344 */);
    // 0048b072  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b075  bbfa000000             -mov ebx, 0xfa
    cpu.ebx = 250 /*0xfa*/;
    // 0048b07a  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0048b07d  ff542408               -call dword ptr [esp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b081:
    // 0048b081  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048b085  8b2ddcba4d00           -mov ebp, dword ptr [0x4dbadc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5094108) /* 0x4dbadc */);
    // 0048b08b  43                     -inc ebx
    (cpu.ebx)++;
    // 0048b08c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b08f  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048b093  39eb                   +cmp ebx, ebp
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
    // 0048b095  7cbf                   -jl 0x48b056
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b056;
    }
L_0x0048b097:
    // 0048b097  83c410                 +add esp, 0x10
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
    // 0048b09a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b09b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b09c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b09d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b09e:
    // 0048b09e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b0a2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048b0a6  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048b0a8  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048b0aa  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048b0ad  ff5504                 -call dword ptr [ebp + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b0b0  ebcf                   -jmp 0x48b081
    goto L_0x0048b081;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b0b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b0b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b0b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b0b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b0b7  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048b0ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b0bc  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048b0c0  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048b0c3  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048b0c7  8b15e0ba4d00           -mov edx, dword ptr [0x4dbae0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094112) /* 0x4dbae0 */);
    // 0048b0cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b0cf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b0d1  0f84a4000000           -je 0x48b17b
    if (cpu.flags.zf)
    {
        goto L_0x0048b17b;
    }
L_0x0048b0d7:
    // 0048b0d7  b864435600             -mov eax, 0x564364
    cpu.eax = 5653348 /*0x564364*/;
    // 0048b0dc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048b0de  e86d0b0000             -call 0x48bc50
    cpu.esp -= 4;
    sub_48bc50(app, cpu);
    if (cpu.terminate) return;
    // 0048b0e3  83f8ff                 +cmp eax, -1
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
    // 0048b0e6  7407                   -je 0x48b0ef
    if (cpu.flags.zf)
    {
        goto L_0x0048b0ef;
    }
    // 0048b0e8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b0ea  e80d010000             -call 0x48b1fc
    cpu.esp -= 4;
    sub_48b1fc(app, cpu);
    if (cpu.terminate) return;
L_0x0048b0ef:
    // 0048b0ef  baac000000             -mov edx, 0xac
    cpu.edx = 172 /*0xac*/;
    // 0048b0f4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b0f6  e821efffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048b0fb  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048b0fd  a1dcba4d00             -mov eax, dword ptr [0x4dbadc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094108) /* 0x4dbadc */);
    // 0048b102  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048b106  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b108  7e62                   -jle 0x48b16c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b16c;
    }
    // 0048b10a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048b10c:
    // 0048b10c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b10e  755c                   -jne 0x48b16c
    if (!cpu.flags.zf)
    {
        goto L_0x0048b16c;
    }
    // 0048b110  8b8744435600           -mov eax, dword ptr [edi + 0x564344]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5653316) /* 0x564344 */);
    // 0048b116  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048b119  8b8724435600           -mov eax, dword ptr [edi + 0x564324]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5653284) /* 0x564324 */);
    // 0048b11f  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048b122  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b126  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048b129  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048b12c  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0048b130  0f848d000000           -je 0x48b1c3
    if (cpu.flags.zf)
    {
        goto L_0x0048b1c3;
    }
L_0x0048b136:
    // 0048b136  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048b13a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048b13e  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048b142  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b143  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048b147  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048b14a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b14b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b14d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048b151  ff5508                 -call dword ptr [ebp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b154  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048b156:
    // 0048b156  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048b15a  8b1ddcba4d00           -mov ebx, dword ptr [0x4dbadc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094108) /* 0x4dbadc */);
    // 0048b160  42                     -inc edx
    (cpu.edx)++;
    // 0048b161  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b164  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048b168  39da                   +cmp edx, ebx
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
    // 0048b16a  7ca0                   -jl 0x48b10c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b10c;
    }
L_0x0048b16c:
    // 0048b16c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b16e  7572                   -jne 0x48b1e2
    if (!cpu.flags.zf)
    {
        goto L_0x0048b1e2;
    }
    // 0048b170  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b172  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048b175  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b176  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b177  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b178  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0048b17b:
    // 0048b17b  b864435600             -mov eax, 0x564364
    cpu.eax = 5653348 /*0x564364*/;
    // 0048b180  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b182  e8a5080000             -call 0x48ba2c
    cpu.esp -= 4;
    sub_48ba2c(app, cpu);
    if (cpu.terminate) return;
    // 0048b187  b8f4af4800             -mov eax, 0x48aff4
    cpu.eax = 4763636 /*0x48aff4*/;
    // 0048b18c  e80ffc0000             -call 0x49ada0
    cpu.esp -= 4;
    sub_49ada0(app, cpu);
    if (cpu.terminate) return;
    // 0048b191  833dd4ba4d0000         +cmp dword ptr [0x4dbad4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094100) /* 0x4dbad4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b198  751a                   -jne 0x48b1b4
    if (!cpu.flags.zf)
    {
        goto L_0x0048b1b4;
    }
    // 0048b19a  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048b1a0  83c209                 -add edx, 9
    (cpu.edx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0048b1a3  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0048b1a8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b1aa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048b1ad  f7ff                   +idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048b1af  a3d4ba4d00             -mov dword ptr [0x4dbad4], eax
    app->getMemory<x86::reg32>(x86::reg32(5094100) /* 0x4dbad4 */) = cpu.eax;
L_0x0048b1b4:
    // 0048b1b4  c705e0ba4d0001000000   -mov dword ptr [0x4dbae0], 1
    app->getMemory<x86::reg32>(x86::reg32(5094112) /* 0x4dbae0 */) = 1 /*0x1*/;
    // 0048b1be  e914ffffff             -jmp 0x48b0d7
    goto L_0x0048b0d7;
L_0x0048b1c3:
    // 0048b1c3  8b8744435600           -mov eax, dword ptr [edi + 0x564344]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5653316) /* 0x564344 */);
    // 0048b1c9  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048b1cd  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b1d0  e8bbfdffff             -call 0x48af90
    cpu.esp -= 4;
    sub_48af90(app, cpu);
    if (cpu.terminate) return;
    // 0048b1d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b1d7  0f8559ffffff           -jne 0x48b136
    if (!cpu.flags.zf)
    {
        goto L_0x0048b136;
    }
    // 0048b1dd  e974ffffff             -jmp 0x48b156
    goto L_0x0048b156;
L_0x0048b1e2:
    // 0048b1e2  b864435600             -mov eax, 0x564364
    cpu.eax = 5653348 /*0x564364*/;
    // 0048b1e7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048b1e9  e892080000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 0048b1ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b1f0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048b1f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b1f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b1f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b1f6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b1fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b1fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b1fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b1fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b1ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b201  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b203  b864435600             -mov eax, 0x564364
    cpu.eax = 5653348 /*0x564364*/;
    // 0048b208  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b20a  e8410a0000             -call 0x48bc50
    cpu.esp -= 4;
    sub_48bc50(app, cpu);
    if (cpu.terminate) return;
    // 0048b20f  83f8ff                 +cmp eax, -1
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
    // 0048b212  7506                   -jne 0x48b21a
    if (!cpu.flags.zf)
    {
        goto L_0x0048b21a;
    }
    // 0048b214  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b216  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b217  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b218  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b219  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b21a:
    // 0048b21a  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048b21d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b21f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048b221  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b224  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048b226  b864435600             -mov eax, 0x564364
    cpu.eax = 5653348 /*0x564364*/;
    // 0048b22b  e8e8090000             -call 0x48bc18
    cpu.esp -= 4;
    sub_48bc18(app, cpu);
    if (cpu.terminate) return;
    // 0048b230  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b232  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b233  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b234  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b235  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b238(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b238  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b239  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b23c  ff5610                 -call dword ptr [esi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b23f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b240  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b244(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b244  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b245  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b248  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b24b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b24c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b251  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b254  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b257  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b258  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b25c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b25c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b25d  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b260  ff561c                 -call dword ptr [esi + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b263  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b264  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b268(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b268  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b269  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b26c  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b26f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b270  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b274(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b274  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b275  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b278  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b27b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b27c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b280  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b281  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b284  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b287  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b288  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b28c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b28c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b28d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b28e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b290  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b292  b864435600             -mov eax, 0x564364
    cpu.eax = 5653348 /*0x564364*/;
    // 0048b297  e8b4090000             -call 0x48bc50
    cpu.esp -= 4;
    sub_48bc50(app, cpu);
    if (cpu.terminate) return;
    // 0048b29c  83f8ff                 +cmp eax, -1
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
    // 0048b29f  7508                   -jne 0x48b2a9
    if (!cpu.flags.zf)
    {
        goto L_0x0048b2a9;
    }
    // 0048b2a1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048b2a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b2a9:
    // 0048b2a9  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048b2ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b2ae  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b2b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b2b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b2b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b2b5  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b2b8  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b2bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b2c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b2c1  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b2c4  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b2c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b2cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b2cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b2cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b2ce  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048b2d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b2d2  740a                   -je 0x48b2de
    if (cpu.flags.zf)
    {
        goto L_0x0048b2de;
    }
    // 0048b2d4  c7404400000000         -mov dword ptr [eax + 0x44], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0048b2db  894848                 -mov dword ptr [eax + 0x48], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.ecx;
L_0x0048b2de:
    // 0048b2de  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048b2e0  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048b2e3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048b2e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b2e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b2e9  ff5738                 -call dword ptr [edi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b2ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b2f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b2f1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048b2f4  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048b2f7  ff513c                 -call dword ptr [ecx + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b2fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b2fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b2fc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b2fd  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048b300  837e3800               +cmp dword ptr [esi + 0x38], 0
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
    // 0048b304  7504                   -jne 0x48b30a
    if (!cpu.flags.zf)
    {
        goto L_0x0048b30a;
    }
    // 0048b306  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b308  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b309  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b30a:
    // 0048b30a  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048b30d  ff5638                 -call dword ptr [esi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b310  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b311  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b314(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b314  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b315  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048b318  837a2400               +cmp dword ptr [edx + 0x24], 0
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
    // 0048b31c  7504                   -jne 0x48b322
    if (!cpu.flags.zf)
    {
        goto L_0x0048b322;
    }
    // 0048b31e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b320  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b321  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b322:
    // 0048b322  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048b325  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b328  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b329  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48b330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b330  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b331  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b332  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b334  833de8ba4d0000         +cmp dword ptr [0x4dbae8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094120) /* 0x4dbae8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b33b  7424                   -je 0x48b361
    if (cpu.flags.zf)
    {
        goto L_0x0048b361;
    }
L_0x0048b33d:
    // 0048b33d  833de4ba4d0000         +cmp dword ptr [0x4dbae4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094116) /* 0x4dbae4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b344  750a                   -jne 0x48b350
    if (!cpu.flags.zf)
    {
        goto L_0x0048b350;
    }
    // 0048b346  e8adebffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048b34b  a3e4ba4d00             -mov dword ptr [0x4dbae4], eax
    app->getMemory<x86::reg32>(x86::reg32(5094116) /* 0x4dbae4 */) = cpu.eax;
L_0x0048b350:
    // 0048b350  833de8ba4d0000         +cmp dword ptr [0x4dbae8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094120) /* 0x4dbae8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b357  7453                   -je 0x48b3ac
    if (cpu.flags.zf)
    {
        goto L_0x0048b3ac;
    }
    // 0048b359  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048b35e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b35f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b360  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b361:
    // 0048b361  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b362  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b363  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b364  be3cfe4c00             -mov esi, 0x4cfe3c
    cpu.esi = 5045820 /*0x4cfe3c*/;
    // 0048b369  bf62000000             -mov edi, 0x62
    cpu.edi = 98 /*0x62*/;
    // 0048b36e  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0048b371  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048b373  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048b375  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048b378  8935d8b14d00           -mov dword ptr [0x4db1d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.esi;
    // 0048b37e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b380  b84cfe4c00             -mov eax, 0x4cfe4c
    cpu.eax = 5045836 /*0x4cfe4c*/;
    // 0048b385  893ddcb14d00           -mov dword ptr [0x4db1dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.edi;
    // 0048b38b  e80891ffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 0048b390  a3e8ba4d00             -mov dword ptr [0x4dbae8], eax
    app->getMemory<x86::reg32>(x86::reg32(5094120) /* 0x4dbae8 */) = cpu.eax;
    // 0048b395  890d80435600           -mov dword ptr [0x564380], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653376) /* 0x564380 */) = cpu.ecx;
    // 0048b39b  892d88435600           -mov dword ptr [0x564388], ebp
    app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */) = cpu.ebp;
    // 0048b3a1  892d84435600           -mov dword ptr [0x564384], ebp
    app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */) = cpu.ebp;
    // 0048b3a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3aa  eb91                   -jmp 0x48b33d
    goto L_0x0048b33d;
L_0x0048b3ac:
    // 0048b3ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b3ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b3b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b3b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b3b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b3b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b3b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b3b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b3b9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b3ba  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048b3bc  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 0048b3c2  833de8ba4d0000         +cmp dword ptr [0x4dbae8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094120) /* 0x4dbae8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b3c9  0f8460020000           -je 0x48b62f
    if (cpu.flags.zf)
    {
        goto L_0x0048b62f;
    }
    // 0048b3cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b3d1  0f8458020000           -je 0x48b62f
    if (cpu.flags.zf)
    {
        goto L_0x0048b62f;
    }
    // 0048b3d7  e88c040200             -call 0x4ab868
    cpu.esp -= 4;
    sub_4ab868(app, cpu);
    if (cpu.terminate) return;
L_0x0048b3dc:
    // 0048b3dc  8b15e8ba4d00           -mov edx, dword ptr [0x4dbae8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094120) /* 0x4dbae8 */);
    // 0048b3e2  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0048b3e5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b3e7  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0048b3ea  890de8ba4d00           -mov dword ptr [0x4dbae8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094120) /* 0x4dbae8 */) = cpu.ecx;
    // 0048b3f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b3f2  0f84ff020000           -je 0x48b6f7
    if (cpu.flags.zf)
    {
        goto L_0x0048b6f7;
    }
    // 0048b3f8  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 0048b3fd  8b1d80435600           -mov ebx, dword ptr [0x564380]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653376) /* 0x564380 */);
    // 0048b403  39d8                   +cmp eax, ebx
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
    // 0048b405  0f8d2b020000           -jge 0x48b636
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048b636;
    }
L_0x0048b40b:
    // 0048b40b  a388435600             -mov dword ptr [0x564388], eax
    app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */) = cpu.eax;
L_0x0048b410:
    // 0048b410  8b3588435600           -mov esi, dword ptr [0x564388]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 0048b416  4e                     -dec esi
    (cpu.esi)--;
    // 0048b417  893588435600           -mov dword ptr [0x564388], esi
    app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */) = cpu.esi;
    // 0048b41d  83feff                 +cmp esi, -1
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
    // 0048b420  0f84c9020000           -je 0x48b6ef
    if (cpu.flags.zf)
    {
        goto L_0x0048b6ef;
    }
    // 0048b426  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0048b429  8b3584435600           -mov esi, dword ptr [0x564384]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 0048b42f  8b1584435600           -mov edx, dword ptr [0x564384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 0048b435  8b0d80435600           -mov ecx, dword ptr [0x564380]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653376) /* 0x564380 */);
    // 0048b43b  c1e606                 -shl esi, 6
    cpu.esi <<= 6 /*0x6*/ % 32;
    // 0048b43e  42                     -inc edx
    (cpu.edx)++;
    // 0048b43f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b441  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b443  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048b446  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048b448  8a6609                 -mov ah, byte ptr [esi + 9]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0048b44b  891584435600           -mov dword ptr [0x564384], edx
    app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */) = cpu.edx;
    // 0048b451  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0048b453  0f84ee010000           -je 0x48b647
    if (cpu.flags.zf)
    {
        goto L_0x0048b647;
    }
    // 0048b459  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b45b  8a4609                 -mov al, byte ptr [esi + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0048b45e  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0048b461  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b462  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 0048b465  0f84d2010000           -je 0x48b63d
    if (cpu.flags.zf)
    {
        goto L_0x0048b63d;
    }
    // 0048b46b  b858fe4c00             -mov eax, 0x4cfe58
    cpu.eax = 5045848 /*0x4cfe58*/;
L_0x0048b470:
    // 0048b470  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b471  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048b473  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b474  6868fe4c00             -push 0x4cfe68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045864 /*0x4cfe68*/;
    cpu.esp -= 4;
    // 0048b479  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b47f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b480  e87cb0ffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0048b485  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0048b488:
    // 0048b488  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b48e  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b494  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b496  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b497  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b499  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048b49b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048b49d  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b49e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b4a1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048b4a3  e824050200             -call 0x4ab9cc
    cpu.esp -= 4;
    sub_4ab9cc(app, cpu);
    if (cpu.terminate) return;
    // 0048b4a8  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048b4ad  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048b4b0  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048b4b3  e89c0b0000             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048b4b8  8a5df8                 -mov bl, byte ptr [ebp - 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048b4bb  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b4be  0f83b2010000           -jae 0x48b676
    if (!cpu.flags.cf)
    {
        goto L_0x0048b676;
    }
L_0x0048b4c4:
    // 0048b4c4  c645f85f               -mov byte ptr [ebp - 8], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 95 /*0x5f*/;
L_0x0048b4c8:
    // 0048b4c8  8a6df9                 -mov ch, byte ptr [ebp - 7]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 0048b4cb  80fd20                 +cmp ch, 0x20
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b4ce  0f83b0010000           -jae 0x48b684
    if (!cpu.flags.cf)
    {
        goto L_0x0048b684;
    }
L_0x0048b4d4:
    // 0048b4d4  c645f95f               -mov byte ptr [ebp - 7], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */) = 95 /*0x5f*/;
L_0x0048b4d8:
    // 0048b4d8  8a55fa                 -mov dl, byte ptr [ebp - 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0048b4db  80fa20                 +cmp dl, 0x20
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
    // 0048b4de  0f83ae010000           -jae 0x48b692
    if (!cpu.flags.cf)
    {
        goto L_0x0048b692;
    }
L_0x0048b4e4:
    // 0048b4e4  c645fa5f               -mov byte ptr [ebp - 6], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = 95 /*0x5f*/;
L_0x0048b4e8:
    // 0048b4e8  8a7dfb                 -mov bh, byte ptr [ebp - 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 0048b4eb  80ff20                 +cmp bh, 0x20
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b4ee  0f83ac010000           -jae 0x48b6a0
    if (!cpu.flags.cf)
    {
        goto L_0x0048b6a0;
    }
L_0x0048b4f4:
    // 0048b4f4  c645fb5f               -mov byte ptr [ebp - 5], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) = 95 /*0x5f*/;
L_0x0048b4f8:
    // 0048b4f8  f6460a02               +test byte ptr [esi + 0xa], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 2 /*0x2*/));
    // 0048b4fc  0f84ac010000           -je 0x48b6ae
    if (cpu.flags.zf)
    {
        goto L_0x0048b6ae;
    }
    // 0048b502  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b504  8a45fb                 -mov al, byte ptr [ebp - 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 0048b507  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b508  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b50a  8a45fa                 -mov al, byte ptr [ebp - 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0048b50d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b50e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b510  8a45f9                 -mov al, byte ptr [ebp - 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 0048b513  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b514  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b516  8a45f8                 -mov al, byte ptr [ebp - 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048b519  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b51a  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048b51d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b51e  6888fe4c00             -push 0x4cfe88
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045896 /*0x4cfe88*/;
    cpu.esp -= 4;
    // 0048b523  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b529  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b52a  e8d2afffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0048b52f  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x0048b532:
    // 0048b532  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b538  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b53e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b540  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b541  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b543  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048b545  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048b547  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b548  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b54b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048b54d  e87a040200             -call 0x4ab9cc
    cpu.esp -= 4;
    sub_4ab9cc(app, cpu);
    if (cpu.terminate) return;
    // 0048b552  f6460a01               +test byte ptr [esi + 0xa], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 1 /*0x1*/));
    // 0048b556  7473                   -je 0x48b5cb
    if (cpu.flags.zf)
    {
        goto L_0x0048b5cb;
    }
    // 0048b558  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b55a  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0048b55f  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048b562  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b564  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b566  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b568  7e09                   -jle 0x48b573
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b573;
    }
    // 0048b56a  83fa35                 +cmp edx, 0x35
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b56d  0f8d5b010000           -jge 0x48b6ce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048b6ce;
    }
L_0x0048b573:
    // 0048b573  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b575  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0048b57a  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048b57d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b57f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b581  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b583  0f8e3e010000           -jle 0x48b6c7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b6c7;
    }
L_0x0048b589:
    // 0048b589  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048b58b:
    // 0048b58b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b58d  8d560b                 -lea edx, [esi + 0xb]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 0048b590  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048b593  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048b595  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b597  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b59d  e83aafffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048b5a2  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0048b5a4  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b5aa  889429f4feffff         -mov byte ptr [ecx + ebp - 0x10c], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-268) /* -0x10c */ + cpu.ebp * 1) = cpu.dl;
    // 0048b5b1  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b5b3  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b5b4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b5b6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048b5b8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048b5ba  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b5bb  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b5c1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b5c4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048b5c6  e801040200             -call 0x4ab9cc
    cpu.esp -= 4;
    sub_4ab9cc(app, cpu);
    if (cpu.terminate) return;
L_0x0048b5cb:
    // 0048b5cb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048b5d0  baa8fe4c00             -mov edx, 0x4cfea8
    cpu.edx = 5045928 /*0x4cfea8*/;
    // 0048b5d5  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b5d8  e8ef030200             -call 0x4ab9cc
    cpu.esp -= 4;
    sub_4ab9cc(app, cpu);
    if (cpu.terminate) return;
    // 0048b5dd  f6460a04               +test byte ptr [esi + 0xa], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 4 /*0x4*/));
    // 0048b5e1  0f84f1000000           -je 0x48b6d8
    if (cpu.flags.zf)
    {
        goto L_0x0048b6d8;
    }
    // 0048b5e7  8d4e0b                 -lea ecx, [esi + 0xb]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 0048b5ea  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
L_0x0048b5ef:
    // 0048b5ef  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048b5f2  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 0048b5f4  fecc                   -dec ah
    (cpu.ah)--;
    // 0048b5f6  886608                 -mov byte ptr [esi + 8], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ah;
    // 0048b5f9  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0048b5fb  0f84d7000000           -je 0x48b6d8
    if (cpu.flags.zf)
    {
        goto L_0x0048b6d8;
    }
    // 0048b601  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0048b603  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b605  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0048b607  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b608  68acfe4c00             -push 0x4cfeac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045932 /*0x4cfeac*/;
    cpu.esp -= 4;
    // 0048b60d  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b613  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b614  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048b616  e8e6aeffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0048b61b  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b621  83c40c                 +add esp, 0xc
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
    // 0048b624  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b627  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048b628  e89f030200             -call 0x4ab9cc
    cpu.esp -= 4;
    sub_4ab9cc(app, cpu);
    if (cpu.terminate) return;
    // 0048b62d  ebc0                   -jmp 0x48b5ef
    goto L_0x0048b5ef;
L_0x0048b62f:
    // 0048b62f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b631  e9a6fdffff             -jmp 0x48b3dc
    goto L_0x0048b3dc;
L_0x0048b636:
    // 0048b636  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b638  e9cefdffff             -jmp 0x48b40b
    goto L_0x0048b40b;
L_0x0048b63d:
    // 0048b63d  b860fe4c00             -mov eax, 0x4cfe60
    cpu.eax = 5045856 /*0x4cfe60*/;
    // 0048b642  e929feffff             -jmp 0x48b470
    goto L_0x0048b470;
L_0x0048b647:
    // 0048b647  f6460a08               +test byte ptr [esi + 0xa], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 8 /*0x8*/));
    // 0048b64b  7422                   -je 0x48b66f
    if (cpu.flags.zf)
    {
        goto L_0x0048b66f;
    }
    // 0048b64d  b858fe4c00             -mov eax, 0x4cfe58
    cpu.eax = 5045848 /*0x4cfe58*/;
L_0x0048b652:
    // 0048b652  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b653  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048b655  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b656  6878fe4c00             -push 0x4cfe78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045880 /*0x4cfe78*/;
    cpu.esp -= 4;
    // 0048b65b  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b661  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b662  e89aaeffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0048b667  83c410                 +add esp, 0x10
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
    // 0048b66a  e919feffff             -jmp 0x48b488
    goto L_0x0048b488;
L_0x0048b66f:
    // 0048b66f  b860fe4c00             -mov eax, 0x4cfe60
    cpu.eax = 5045856 /*0x4cfe60*/;
    // 0048b674  ebdc                   -jmp 0x48b652
    goto L_0x0048b652;
L_0x0048b676:
    // 0048b676  80fb7f                 +cmp bl, 0x7f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b679  0f8745feffff           -ja 0x48b4c4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048b4c4;
    }
    // 0048b67f  e944feffff             -jmp 0x48b4c8
    goto L_0x0048b4c8;
L_0x0048b684:
    // 0048b684  80fd7f                 +cmp ch, 0x7f
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b687  0f8747feffff           -ja 0x48b4d4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048b4d4;
    }
    // 0048b68d  e946feffff             -jmp 0x48b4d8
    goto L_0x0048b4d8;
L_0x0048b692:
    // 0048b692  80fa7f                 +cmp dl, 0x7f
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b695  0f8749feffff           -ja 0x48b4e4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048b4e4;
    }
    // 0048b69b  e948feffff             -jmp 0x48b4e8
    goto L_0x0048b4e8;
L_0x0048b6a0:
    // 0048b6a0  80ff7f                 +cmp bh, 0x7f
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b6a3  0f874bfeffff           -ja 0x48b4f4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048b4f4;
    }
    // 0048b6a9  e94afeffff             -jmp 0x48b4f8
    goto L_0x0048b4f8;
L_0x0048b6ae:
    // 0048b6ae  6898fe4c00             -push 0x4cfe98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045912 /*0x4cfe98*/;
    cpu.esp -= 4;
    // 0048b6b3  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048b6b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b6ba  e842aeffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0048b6bf  83c408                 +add esp, 8
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
    // 0048b6c2  e96bfeffff             -jmp 0x48b532
    goto L_0x0048b532;
L_0x0048b6c7:
    // 0048b6c7  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048b6c9  e9bbfeffff             -jmp 0x48b589
    goto L_0x0048b589;
L_0x0048b6ce:
    // 0048b6ce  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 0048b6d3  e9b3feffff             -jmp 0x48b58b
    goto L_0x0048b58b;
L_0x0048b6d8:
    // 0048b6d8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048b6dd  bab4fe4c00             -mov edx, 0x4cfeb4
    cpu.edx = 5045940 /*0x4cfeb4*/;
    // 0048b6e2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b6e5  e8e2020200             -call 0x4ab9cc
    cpu.esp -= 4;
    sub_4ab9cc(app, cpu);
    if (cpu.terminate) return;
    // 0048b6ea  e921fdffff             -jmp 0x48b410
    goto L_0x0048b410;
L_0x0048b6ef:
    // 0048b6ef  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b6f2  e8d5010200             -call 0x4ab8cc
    cpu.esp -= 4;
    sub_4ab8cc(app, cpu);
    if (cpu.terminate) return;
L_0x0048b6f7:
    // 0048b6f7  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0048b6fa  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048b6fc  7407                   -je 0x48b705
    if (cpu.flags.zf)
    {
        goto L_0x0048b705;
    }
    // 0048b6fe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b700  e8f791ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x0048b705:
    // 0048b705  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b709  740e                   -je 0x48b719
    if (cpu.flags.zf)
    {
        goto L_0x0048b719;
    }
    // 0048b70b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048b710  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0048b712  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b713  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b714  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b715  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b716  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b717  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b718  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b719:
    // 0048b719  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b71b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0048b71d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b71e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b71f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b720  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b721  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b722  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b723  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b724(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b724  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b725  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b726  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b727  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048b729  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048b72c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0048b72f  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0048b732  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 0048b735  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0048b738  a1e4ba4d00             -mov eax, dword ptr [0x4dbae4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094116) /* 0x4dbae4 */);
    // 0048b73d  e806e8ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048b742  833de8ba4d0000         +cmp dword ptr [0x4dbae8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094120) /* 0x4dbae8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b749  0f847d010000           -je 0x48b8cc
    if (cpu.flags.zf)
    {
        goto L_0x0048b8cc;
    }
    // 0048b74f  8b1584435600           -mov edx, dword ptr [0x564384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 0048b755  8b0d88435600           -mov ecx, dword ptr [0x564388]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 0048b75b  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b75d  8b1d80435600           -mov ebx, dword ptr [0x564380]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653376) /* 0x564380 */);
    // 0048b763  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b765  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048b768  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048b76a  8b35e8ba4d00           -mov esi, dword ptr [0x4dbae8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5094120) /* 0x4dbae8 */);
    // 0048b770  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0048b773  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b775  39d9                   +cmp ecx, ebx
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
    // 0048b777  0f856f010000           -jne 0x48b8ec
    if (!cpu.flags.zf)
    {
        goto L_0x0048b8ec;
    }
    // 0048b77d  8b1584435600           -mov edx, dword ptr [0x564384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 0048b783  42                     -inc edx
    (cpu.edx)++;
    // 0048b784  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b786  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048b789  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048b78b  891584435600           -mov dword ptr [0x564384], edx
    app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */) = cpu.edx;
L_0x0048b791:
    // 0048b791  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b794  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b796  0f8467010000           -je 0x48b903
    if (cpu.flags.zf)
    {
        goto L_0x0048b903;
    }
    // 0048b79c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048b79e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b7a0  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b7a1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b7a3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048b7a5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048b7a7  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b7a8  83f935                 +cmp ecx, 0x35
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b7ab  0f8348010000           -jae 0x48b8f9
    if (!cpu.flags.cf)
    {
        goto L_0x0048b8f9;
    }
    // 0048b7b1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048b7b3  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b7b5  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b7b6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b7b8  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048b7ba  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048b7bc  49                     -dec ecx
    (cpu.ecx)--;
L_0x0048b7bd:
    // 0048b7bd  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b7c1  0f8443010000           -je 0x48b90a
    if (cpu.flags.zf)
    {
        goto L_0x0048b90a;
    }
    // 0048b7c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b7c9  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0048b7ce  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0048b7d0  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b7d2  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0048b7d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b7d7  39fa                   +cmp edx, edi
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
    // 0048b7d9  7e02                   -jle 0x48b7dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b7dd;
    }
    // 0048b7db  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0048b7dd:
    // 0048b7dd  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
L_0x0048b7e0:
    // 0048b7e0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048b7e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b7e5  7405                   -je 0x48b7ec
    if (cpu.flags.zf)
    {
        goto L_0x0048b7ec;
    }
    // 0048b7e7  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x0048b7ec:
    // 0048b7ec  88460a                 -mov byte ptr [esi + 0xa], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.al;
    // 0048b7ef  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 0048b7f4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0048b7f6  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048b7f9  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0048b7fc  884609                 -mov byte ptr [esi + 9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 0048b7ff  8d460b                 -lea eax, [esi + 0xb]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 0048b802  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b804  742a                   -je 0x48b830
    if (cpu.flags.zf)
    {
        goto L_0x0048b830;
    }
    // 0048b806  807e0800               +cmp byte ptr [esi + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b80a  7424                   -je 0x48b830
    if (cpu.flags.zf)
    {
        goto L_0x0048b830;
    }
    // 0048b80c  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0048b80f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0048b811  80ce04                 -or dh, 4
    cpu.dh |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0048b814  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048b817  88760a                 -mov byte ptr [esi + 0xa], dh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dh;
    // 0048b81a  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0048b81d  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 0048b81f  760f                   -jbe 0x48b830
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048b830;
    }
L_0x0048b821:
    // 0048b821  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 0048b823  42                     -inc edx
    (cpu.edx)++;
    // 0048b824  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
    // 0048b826  fec3                   -inc bl
    (cpu.bl)++;
    // 0048b828  8a6e08                 -mov ch, byte ptr [esi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048b82b  40                     -inc eax
    (cpu.eax)++;
    // 0048b82c  38eb                   +cmp bl, ch
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b82e  72f1                   -jb 0x48b821
    if (cpu.flags.cf)
    {
        goto L_0x0048b821;
    }
L_0x0048b830:
    // 0048b830  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b834  7425                   -je 0x48b85b
    if (cpu.flags.zf)
    {
        goto L_0x0048b85b;
    }
    // 0048b836  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0048b838  7421                   -je 0x48b85b
    if (cpu.flags.zf)
    {
        goto L_0x0048b85b;
    }
    // 0048b83a  8a560a                 -mov dl, byte ptr [esi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0048b83d  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0048b840  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0048b842  88560a                 -mov byte ptr [esi + 0xa], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dl;
    // 0048b845  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b848  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0048b84a  760c                   -jbe 0x48b858
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048b858;
    }
L_0x0048b84c:
    // 0048b84c  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 0048b84e  42                     -inc edx
    (cpu.edx)++;
    // 0048b84f  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
    // 0048b851  fec3                   -inc bl
    (cpu.bl)++;
    // 0048b853  40                     -inc eax
    (cpu.eax)++;
    // 0048b854  38cb                   +cmp bl, cl
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
    // 0048b856  72f4                   -jb 0x48b84c
    if (cpu.flags.cf)
    {
        goto L_0x0048b84c;
    }
L_0x0048b858:
    // 0048b858  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x0048b85b:
    // 0048b85b  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048b85e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048b860  0f84ad000000           -je 0x48b913
    if (cpu.flags.zf)
    {
        goto L_0x0048b913;
    }
    // 0048b866  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0048b869  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048b86b  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0048b86e  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048b871  88760a                 -mov byte ptr [esi + 0xa], dh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dh;
L_0x0048b874:
    // 0048b874  833decba4d0000         +cmp dword ptr [0x4dbaec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094124) /* 0x4dbaec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b87b  744f                   -je 0x48b8cc
    if (cpu.flags.zf)
    {
        goto L_0x0048b8cc;
    }
    // 0048b87d  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0048b880  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048b883  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b884  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b886  0f848f000000           -je 0x48b91b
    if (cpu.flags.zf)
    {
        goto L_0x0048b91b;
    }
    // 0048b88c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0048b88e:
    // 0048b88e  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048b891  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b892  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048b894  0f848b000000           -je 0x48b925
    if (cpu.flags.zf)
    {
        goto L_0x0048b925;
    }
    // 0048b89a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
L_0x0048b89c:
    // 0048b89c  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048b89f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b8a0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048b8a2  0f8484000000           -je 0x48b92c
    if (cpu.flags.zf)
    {
        goto L_0x0048b92c;
    }
    // 0048b8a8  b858fe4c00             -mov eax, 0x4cfe58
    cpu.eax = 5045848 /*0x4cfe58*/;
L_0x0048b8ad:
    // 0048b8ad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b8ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b8b0  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048b8b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b8b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b8b6  a0f0ba4d00             -mov al, byte ptr [0x4dbaf0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5094128) /* 0x4dbaf0 */);
    // 0048b8bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b8bc  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048b8be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b8bf  68bcfe4c00             -push 0x4cfebc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045948 /*0x4cfebc*/;
    cpu.esp -= 4;
    // 0048b8c4  e857330000             -call 0x48ec20
    cpu.esp -= 4;
    sub_48ec20(app, cpu);
    if (cpu.terminate) return;
    // 0048b8c9  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0048b8cc:
    // 0048b8cc  a1e4ba4d00             -mov eax, dword ptr [0x4dbae4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094116) /* 0x4dbae4 */);
    // 0048b8d1  e88ae6ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048b8d6  833de8ba4d0000         +cmp dword ptr [0x4dbae8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094120) /* 0x4dbae8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b8dd  7457                   -je 0x48b936
    if (cpu.flags.zf)
    {
        goto L_0x0048b936;
    }
    // 0048b8df  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048b8e4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0048b8e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b8e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b8e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b8e9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048b8ec:
    // 0048b8ec  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0048b8ef  a388435600             -mov dword ptr [0x564388], eax
    app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */) = cpu.eax;
    // 0048b8f4  e998feffff             -jmp 0x48b791
    goto L_0x0048b791;
L_0x0048b8f9:
    // 0048b8f9  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 0048b8fe  e9bafeffff             -jmp 0x48b7bd
    goto L_0x0048b7bd;
L_0x0048b903:
    // 0048b903  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 0048b905  e9b3feffff             -jmp 0x48b7bd
    goto L_0x0048b7bd;
L_0x0048b90a:
    // 0048b90a  c6460800               -mov byte ptr [esi + 8], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048b90e  e9cdfeffff             -jmp 0x48b7e0
    goto L_0x0048b7e0;
L_0x0048b913:
    // 0048b913  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0048b916  e959ffffff             -jmp 0x48b874
    goto L_0x0048b874;
L_0x0048b91b:
    // 0048b91b  b8b8fe4c00             -mov eax, 0x4cfeb8
    cpu.eax = 5045944 /*0x4cfeb8*/;
    // 0048b920  e969ffffff             -jmp 0x48b88e
    goto L_0x0048b88e;
L_0x0048b925:
    // 0048b925  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b927  e970ffffff             -jmp 0x48b89c
    goto L_0x0048b89c;
L_0x0048b92c:
    // 0048b92c  b860fe4c00             -mov eax, 0x4cfe60
    cpu.eax = 5045856 /*0x4cfe60*/;
    // 0048b931  e977ffffff             -jmp 0x48b8ad
    goto L_0x0048b8ad;
L_0x0048b936:
    // 0048b936  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b938  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0048b93a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b93b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b93c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b93d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_48b940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b940  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0048b941:
    // 0048b941  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048b943  7504                   -jne 0x48b949
    if (!cpu.flags.zf)
    {
        goto L_0x0048b949;
    }
L_0x0048b945:
    // 0048b945  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b947  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b948  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b949:
    // 0048b949  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0048b94b  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 0048b94d  38e9                   +cmp cl, ch
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b94f  740e                   -je 0x48b95f
    if (cpu.flags.zf)
    {
        goto L_0x0048b95f;
    }
    // 0048b951  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b953  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b955  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 0048b957  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 0048b959  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b95b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b95d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b95e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b95f:
    // 0048b95f  803800                 +cmp byte ptr [eax], 0
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
    // 0048b962  74e1                   -je 0x48b945
    if (cpu.flags.zf)
    {
        goto L_0x0048b945;
    }
    // 0048b964  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048b965  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048b966  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048b967  ebd8                   -jmp 0x48b941
    goto L_0x0048b941;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48b970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b970  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b974(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b974  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b976  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b978  740c                   -je 0x48b986
    if (cpu.flags.zf)
    {
        goto L_0x0048b986;
    }
L_0x0048b97a:
    // 0048b97a  4a                     -dec edx
    (cpu.edx)--;
    // 0048b97b  83faff                 +cmp edx, -1
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
    // 0048b97e  7406                   -je 0x48b986
    if (cpu.flags.zf)
    {
        goto L_0x0048b986;
    }
    // 0048b980  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b982  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b984  75f4                   -jne 0x48b97a
    if (!cpu.flags.zf)
    {
        goto L_0x0048b97a;
    }
L_0x0048b986:
    // 0048b986  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b988(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b988  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b989  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b98a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b98b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b98c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b98d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b98f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b991  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b993  7441                   -je 0x48b9d6
    if (cpu.flags.zf)
    {
        goto L_0x0048b9d6;
    }
    // 0048b995  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b997  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048b999  763b                   -jbe 0x48b9d6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048b9d6;
    }
    // 0048b99b  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048b99e  39fa                   +cmp edx, edi
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
    // 0048b9a0  743c                   -je 0x48b9de
    if (cpu.flags.zf)
    {
        goto L_0x0048b9de;
    }
    // 0048b9a2  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 0048b9a4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048b9a6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048b9a8  740b                   -je 0x48b9b5
    if (cpu.flags.zf)
    {
        goto L_0x0048b9b5;
    }
L_0x0048b9aa:
    // 0048b9aa  3b10                   +cmp edx, dword ptr [eax]
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
    // 0048b9ac  7407                   -je 0x48b9b5
    if (cpu.flags.zf)
    {
        goto L_0x0048b9b5;
    }
    // 0048b9ae  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b9b0  833800                 +cmp dword ptr [eax], 0
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
    // 0048b9b3  75f5                   -jne 0x48b9aa
    if (!cpu.flags.zf)
    {
        goto L_0x0048b9aa;
    }
L_0x0048b9b5:
    // 0048b9b5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b9b7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048b9b9  7417                   -je 0x48b9d2
    if (cpu.flags.zf)
    {
        goto L_0x0048b9d2;
    }
    // 0048b9bb  39f2                   +cmp edx, esi
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
    // 0048b9bd  7513                   -jne 0x48b9d2
    if (!cpu.flags.zf)
    {
        goto L_0x0048b9d2;
    }
    // 0048b9bf  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048b9c4  2919                   -sub dword ptr [ecx], ebx
    (app->getMemory<x86::reg32>(cpu.ecx)) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b9c6  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0048b9c8  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0048b9ca  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b9cd  7503                   -jne 0x48b9d2
    if (!cpu.flags.zf)
    {
        goto L_0x0048b9d2;
    }
    // 0048b9cf  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0048b9d2:
    // 0048b9d2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048b9d4  7544                   -jne 0x48ba1a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba1a;
    }
L_0x0048b9d6:
    // 0048b9d6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b9d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b9de:
    // 0048b9de  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048b9e3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b9e5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b9e7  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048b9ea  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0048b9ec  39f7                   +cmp edi, esi
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
    // 0048b9ee  7519                   -jne 0x48ba09
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba09;
    }
    // 0048b9f0  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048b9f7  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048b9fa  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048b9fd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048b9ff  7519                   -jne 0x48ba1a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba1a;
    }
    // 0048ba01  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ba03  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ba09:
    // 0048ba09  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048ba0b  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048ba0e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048ba10  7508                   -jne 0x48ba1a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba1a;
    }
    // 0048ba12  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ba14  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba15  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ba1a:
    // 0048ba1a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0048ba20  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0048ba24  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ba26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ba2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ba2d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ba2f  e8c4e4ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048ba34  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0048ba3a  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048ba41  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048ba48  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048ba4f  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048ba52  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ba54  7408                   -je 0x48ba5e
    if (cpu.flags.zf)
    {
        goto L_0x0048ba5e;
    }
    // 0048ba56  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048ba59  895914                 -mov dword ptr [ecx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0048ba5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ba5e:
    // 0048ba5e  ba70b94800             -mov edx, 0x48b970
    cpu.edx = 4766064 /*0x48b970*/;
    // 0048ba63  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048ba66  895914                 -mov dword ptr [ecx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0048ba69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ba6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ba6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ba6f  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048ba72  e8fde4ffff             -call 0x489f74
    cpu.esp -= 4;
    sub_489f74(app, cpu);
    if (cpu.terminate) return;
    // 0048ba77  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048ba7e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ba80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ba81  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ba83  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048ba86  e8bde4ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048ba8b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ba8d  741b                   -je 0x48baaa
    if (cpu.flags.zf)
    {
        goto L_0x0048baaa;
    }
    // 0048ba8f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ba90  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048ba93  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0048ba95  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048ba97  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048ba9a  43                     -inc ebx
    (cpu.ebx)++;
    // 0048ba9b  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0048ba9d  833a00                 +cmp dword ptr [edx], 0
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
    // 0048baa0  7503                   -jne 0x48baa5
    if (!cpu.flags.zf)
    {
        goto L_0x0048baa5;
    }
    // 0048baa2  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0048baa5:
    // 0048baa5  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0048baa9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048baaa:
    // 0048baaa  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048baad  e8aee4ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bab2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bab3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48bab4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bab4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bab5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048bab7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048baba  e889e4ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048babf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bac1  741e                   -je 0x48bae1
    if (cpu.flags.zf)
    {
        goto L_0x0048bae1;
    }
    // 0048bac3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bac4  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048bac7  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0048bacd  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048bacf  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048bad2  43                     -inc ebx
    (cpu.ebx)++;
    // 0048bad3  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0048bad5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bad7  7512                   -jne 0x48baeb
    if (!cpu.flags.zf)
    {
        goto L_0x0048baeb;
    }
    // 0048bad9  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048badc  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0048bae0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048bae1:
    // 0048bae1  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bae4  e877e4ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bae9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048baea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048baeb:
    // 0048baeb  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0048baed  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0048baf1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048baf2  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048baf5  e866e4ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bafa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bafb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48bafc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bafc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bafd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bafe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bb00  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bb03  e840e4ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bb08  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048bb0b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bb0d  741a                   -je 0x48bb29
    if (cpu.flags.zf)
    {
        goto L_0x0048bb29;
    }
    // 0048bb0f  3b4a0c                 +cmp ecx, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bb12  7526                   -jne 0x48bb3a
    if (!cpu.flags.zf)
    {
        goto L_0x0048bb3a;
    }
    // 0048bb14  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048bb1b  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
L_0x0048bb1e:
    // 0048bb1e  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048bb21  ff0a                   -dec dword ptr [edx]
    (app->getMemory<x86::reg32>(cpu.edx))--;
    // 0048bb23  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x0048bb29:
    // 0048bb29  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0048bb2d  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048bb30  e82be4ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bb35  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bb37  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bb3a:
    // 0048bb3a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048bb3c  ebe0                   -jmp 0x48bb1e
    goto L_0x0048bb1e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48bb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bb40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bb41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bb42  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bb44  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bb47  e8fce3ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bb4c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048bb4f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bb51  742f                   -je 0x48bb82
    if (cpu.flags.zf)
    {
        goto L_0x0048bb82;
    }
    // 0048bb53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bb54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bb55  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048bb57  4b                     -dec ebx
    (cpu.ebx)--;
    // 0048bb58  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048bb5b  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0048bb5d  39f1                   +cmp ecx, esi
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
    // 0048bb5f  7432                   -je 0x48bb93
    if (cpu.flags.zf)
    {
        goto L_0x0048bb93;
    }
    // 0048bb61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bb62  89720c                 -mov dword ptr [edx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x0048bb65:
    // 0048bb65  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048bb68  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bb6a  39f9                   +cmp ecx, edi
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
    // 0048bb6c  7405                   -je 0x48bb73
    if (cpu.flags.zf)
    {
        goto L_0x0048bb73;
    }
    // 0048bb6e  897a0c                 -mov dword ptr [edx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048bb71  ebf2                   -jmp 0x48bb65
    goto L_0x0048bb65;
L_0x0048bb73:
    // 0048bb73  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0048bb79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048bb7a:
    // 0048bb7a  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0048bb80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048bb82:
    // 0048bb82  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0048bb86  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048bb89  e8d2e3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bb8e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bb90  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bb93:
    // 0048bb93  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048bb9a  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048bb9d  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048bba0  ebd8                   -jmp 0x48bb7a
    goto L_0x0048bb7a;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48bba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bba4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bba5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bba6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048bba8  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048bbaa  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bbad  e896e3ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bbb2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bbb4  750b                   -jne 0x48bbc1
    if (!cpu.flags.zf)
    {
        goto L_0x0048bbc1;
    }
    // 0048bbb6  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048bbb9  e8a2e3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bbbe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bbc1:
    // 0048bbc1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bbc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bbc3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bbc4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048bbc6  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048bbc9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048bbcb  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bbce  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048bbd0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048bbd2  42                     -inc edx
    (cpu.edx)++;
    // 0048bbd3  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048bbd6  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0048bbd8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bbda  7414                   -je 0x48bbf0
    if (cpu.flags.zf)
    {
        goto L_0x0048bbf0;
    }
L_0x0048bbdc:
    // 0048bbdc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bbde  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048bbe1  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bbe4  39f8                   +cmp eax, edi
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
    // 0048bbe6  7308                   -jae 0x48bbf0
    if (!cpu.flags.cf)
    {
        goto L_0x0048bbf0;
    }
    // 0048bbe8  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048bbea  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048bbec  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bbee  75ec                   -jne 0x48bbdc
    if (!cpu.flags.zf)
    {
        goto L_0x0048bbdc;
    }
L_0x0048bbf0:
    // 0048bbf0  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0048bbf3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048bbf5  751c                   -jne 0x48bc13
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc13;
    }
    // 0048bbf7  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x0048bbfa:
    // 0048bbfa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bbfc  7503                   -jne 0x48bc01
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc01;
    }
    // 0048bbfe  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
L_0x0048bc01:
    // 0048bc01  804b0401               +or byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0048bc05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc07  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc08  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048bc0b  e850e3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bc10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc13:
    // 0048bc13  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 0048bc15  ebe3                   -jmp 0x48bbfa
    goto L_0x0048bbfa;
}

/* align: skip 0x90 */
void Application::sub_48bc18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bc18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bc19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bc1a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048bc1c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bc1f  e824e3ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bc24  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bc26  750d                   -jne 0x48bc35
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc35;
    }
    // 0048bc28  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bc2b  e830e3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bc30  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bc32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc35:
    // 0048bc35  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bc37  e84cfdffff             -call 0x48b988
    cpu.esp -= 4;
    sub_48b988(app, cpu);
    if (cpu.terminate) return;
    // 0048bc3c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048bc3e  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bc41  e81ae3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bc46  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bc48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48bc4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bc4c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bc4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48bc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bc50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bc51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bc52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bc53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bc54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bc55  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048bc58  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048bc5a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048bc5c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bc5f  e8e4e2ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bc64  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048bc66  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bc68  742b                   -je 0x48bc95
    if (cpu.flags.zf)
    {
        goto L_0x0048bc95;
    }
    // 0048bc6a  8b7710                 -mov esi, dword ptr [edi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0048bc6d  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048bc70  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048bc72  7539                   -jne 0x48bcad
    if (!cpu.flags.zf)
    {
        goto L_0x0048bcad;
    }
    // 0048bc74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048bc76:
    // 0048bc76  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048bc79  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bc7b  7414                   -je 0x48bc91
    if (cpu.flags.zf)
    {
        goto L_0x0048bc91;
    }
L_0x0048bc7d:
    // 0048bc7d  39e9                   +cmp ecx, ebp
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
    // 0048bc7f  7410                   -je 0x48bc91
    if (cpu.flags.zf)
    {
        goto L_0x0048bc91;
    }
    // 0048bc81  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048bc83  7431                   -je 0x48bcb6
    if (cpu.flags.zf)
    {
        goto L_0x0048bcb6;
    }
    // 0048bc85  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bc87  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0048bc8a  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bc8c  3b0424                 +cmp eax, dword ptr [esp]
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
    // 0048bc8f  7625                   -jbe 0x48bcb6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048bcb6;
    }
L_0x0048bc91:
    // 0048bc91  39e9                   +cmp ecx, ebp
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
    // 0048bc93  7405                   -je 0x48bc9a
    if (cpu.flags.zf)
    {
        goto L_0x0048bc9a;
    }
L_0x0048bc95:
    // 0048bc95  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x0048bc9a:
    // 0048bc9a  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048bc9d  e8bee2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bca2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bca4  83c404                 +add esp, 4
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
    // 0048bca7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bca8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bca9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bcad:
    // 0048bcad  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048bcaf  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0048bcb2  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bcb4  ebc0                   -jmp 0x48bc76
    goto L_0x0048bc76;
L_0x0048bcb6:
    // 0048bcb6  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048bcb8  43                     -inc ebx
    (cpu.ebx)++;
    // 0048bcb9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bcbb  75c0                   -jne 0x48bc7d
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc7d;
    }
    // 0048bcbd  ebd2                   -jmp 0x48bc91
    goto L_0x0048bc91;
}

/* align: skip 0x90 */
void Application::sub_48bcc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bcc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bcc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bcc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bcc3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048bcc5  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bcc8  e87be2ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bccd  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048bcd0  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048bcd5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048bcd7  750e                   -jne 0x48bce7
    if (!cpu.flags.zf)
    {
        goto L_0x0048bce7;
    }
    // 0048bcd9  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bcdc  e87fe2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bce1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bce3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bce4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bce5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bce6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bce7:
    // 0048bce7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bce9  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048bcec  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bcef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bcf1  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bcf4  e867e2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bcf9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bcfb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48bd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bd00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bd01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bd02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bd03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048bd05  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bd08  e83be2ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bd0d  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048bd10  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048bd12  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048bd14  750e                   -jne 0x48bd24
    if (!cpu.flags.zf)
    {
        goto L_0x0048bd24;
    }
    // 0048bd16  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bd19  e842e2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bd1e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bd20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bd24:
    // 0048bd24  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bd26  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048bd29  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bd2c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bd2e  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bd31  e82ae2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bd36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bd38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48bd3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bd3c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bd3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bd3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bd3f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048bd41  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048bd43  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bd46  e8fde1ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bd4b  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048bd4e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bd50  7414                   -je 0x48bd66
    if (cpu.flags.zf)
    {
        goto L_0x0048bd66;
    }
L_0x0048bd52:
    // 0048bd52  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048bd54  7410                   -je 0x48bd66
    if (cpu.flags.zf)
    {
        goto L_0x0048bd66;
    }
    // 0048bd56  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048bd58  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bd5a  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bd5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bd5e  7506                   -jne 0x48bd66
    if (!cpu.flags.zf)
    {
        goto L_0x0048bd66;
    }
    // 0048bd60  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048bd62  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bd64  75ec                   -jne 0x48bd52
    if (!cpu.flags.zf)
    {
        goto L_0x0048bd52;
    }
L_0x0048bd66:
    // 0048bd66  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048bd69  e8f2e1ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bd6e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bd70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48bd74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bd74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bd75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bd76  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048bd78  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bd7b  e8c8e1ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bd80  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048bd83  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048bd85  741f                   -je 0x48bda6
    if (cpu.flags.zf)
    {
        goto L_0x0048bda6;
    }
    // 0048bd87  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bd89  770f                   -ja 0x48bd9a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048bd9a;
    }
    // 0048bd8b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0048bd8d:
    // 0048bd8d  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bd90  e8cbe1ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bd95  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bd97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bd9a:
    // 0048bd9a  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048bd9b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bd9d  e8d2fbffff             -call 0x48b974
    cpu.esp -= 4;
    sub_48b974(app, cpu);
    if (cpu.terminate) return;
    // 0048bda2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bda4  ebe7                   -jmp 0x48bd8d
    goto L_0x0048bd8d;
L_0x0048bda6:
    // 0048bda6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048bda8  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bdab  e8b0e1ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bdb0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bdb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48bdb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bdb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bdb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bdba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bdbb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048bdbd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048bdbf  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bdc2  e881e1ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bdc7  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048bdca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bdcc  7412                   -je 0x48bde0
    if (cpu.flags.zf)
    {
        goto L_0x0048bde0;
    }
L_0x0048bdce:
    // 0048bdce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bdd0  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048bdd3  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bdd6  39f0                   +cmp eax, esi
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
    // 0048bdd8  7306                   -jae 0x48bde0
    if (!cpu.flags.cf)
    {
        goto L_0x0048bde0;
    }
    // 0048bdda  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048bddc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bdde  75ee                   -jne 0x48bdce
    if (!cpu.flags.zf)
    {
        goto L_0x0048bdce;
    }
L_0x0048bde0:
    // 0048bde0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bde2  750e                   -jne 0x48bdf2
    if (!cpu.flags.zf)
    {
        goto L_0x0048bdf2;
    }
L_0x0048bde4:
    // 0048bde4  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048bde7  e874e1ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bdec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bdee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdf0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdf1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bdf2:
    // 0048bdf2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bdf4  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048bdf7  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bdfa  39f0                   +cmp eax, esi
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
    // 0048bdfc  74e6                   -je 0x48bde4
    if (cpu.flags.zf)
    {
        goto L_0x0048bde4;
    }
    // 0048bdfe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048be00  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048be03  e858e1ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048be08  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048be0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be0c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48be10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048be10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048be11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048be12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048be13  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048be15  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048be17  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048be1a  e829e1ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048be1f  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048be22  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048be24  7414                   -je 0x48be3a
    if (cpu.flags.zf)
    {
        goto L_0x0048be3a;
    }
L_0x0048be26:
    // 0048be26  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048be28  7410                   -je 0x48be3a
    if (cpu.flags.zf)
    {
        goto L_0x0048be3a;
    }
    // 0048be2a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048be2c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048be2e  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048be30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048be32  7506                   -jne 0x48be3a
    if (!cpu.flags.zf)
    {
        goto L_0x0048be3a;
    }
    // 0048be34  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048be36  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048be38  75ec                   -jne 0x48be26
    if (!cpu.flags.zf)
    {
        goto L_0x0048be26;
    }
L_0x0048be3a:
    // 0048be3a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048be3c  750e                   -jne 0x48be4c
    if (!cpu.flags.zf)
    {
        goto L_0x0048be4c;
    }
L_0x0048be3e:
    // 0048be3e  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048be41  e81ae1ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048be46  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048be48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048be4c:
    // 0048be4c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048be4e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048be50  e833fbffff             -call 0x48b988
    cpu.esp -= 4;
    sub_48b988(app, cpu);
    if (cpu.terminate) return;
    // 0048be55  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048be57  75e5                   -jne 0x48be3e
    if (!cpu.flags.zf)
    {
        goto L_0x0048be3e;
    }
    // 0048be59  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048be5b  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048be5e  e8fde0ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048be63  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048be65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48be6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048be6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048be6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048be6e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048be70  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048be72  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048be75  e8cee0ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048be7a  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048be7d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048be7f  7433                   -je 0x48beb4
    if (cpu.flags.zf)
    {
        goto L_0x0048beb4;
    }
    // 0048be81  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048be83  7713                   -ja 0x48be98
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048be98;
    }
    // 0048be85  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0048be87:
    // 0048be87  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048be89  751c                   -jne 0x48bea7
    if (!cpu.flags.zf)
    {
        goto L_0x0048bea7;
    }
L_0x0048be8b:
    // 0048be8b  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048be8e  e8cde0ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048be93  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048be95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048be98:
    // 0048be98  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0048be9b  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048be9e  e8d1faffff             -call 0x48b974
    cpu.esp -= 4;
    sub_48b974(app, cpu);
    if (cpu.terminate) return;
    // 0048bea3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048bea5  ebe0                   -jmp 0x48be87
    goto L_0x0048be87;
L_0x0048bea7:
    // 0048bea7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048bea9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048beab  e8d8faffff             -call 0x48b988
    cpu.esp -= 4;
    sub_48b988(app, cpu);
    if (cpu.terminate) return;
    // 0048beb0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048beb2  75d7                   -jne 0x48be8b
    if (!cpu.flags.zf)
    {
        goto L_0x0048be8b;
    }
L_0x0048beb4:
    // 0048beb4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048beb6  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048beb9  e8a2e0ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bebe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bec0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bec1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bec2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48bec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bec4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bec5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bec6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048bec8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048beca  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048becd  e876e0ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bed2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048bed4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048bed6  e899faffff             -call 0x48b974
    cpu.esp -= 4;
    sub_48b974(app, cpu);
    if (cpu.terminate) return;
    // 0048bedb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048bedd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bedf  750d                   -jne 0x48beee
    if (!cpu.flags.zf)
    {
        goto L_0x0048beee;
    }
L_0x0048bee1:
    // 0048bee1  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bee4  e877e0ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bee9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048beeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048beec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048beed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048beee:
    // 0048beee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bef0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bef2  e891faffff             -call 0x48b988
    cpu.esp -= 4;
    sub_48b988(app, cpu);
    if (cpu.terminate) return;
    // 0048bef7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bef9  75e6                   -jne 0x48bee1
    if (!cpu.flags.zf)
    {
        goto L_0x0048bee1;
    }
    // 0048befb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048befd  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048bf00  e85be0ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bf05  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bf07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48bf0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bf0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bf0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bf0e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bf0f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048bf11  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048bf13  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bf16  e82de0ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bf1b  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048bf1e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bf20  7412                   -je 0x48bf34
    if (cpu.flags.zf)
    {
        goto L_0x0048bf34;
    }
L_0x0048bf22:
    // 0048bf22  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bf24  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048bf27  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bf2a  39f0                   +cmp eax, esi
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
    // 0048bf2c  7306                   -jae 0x48bf34
    if (!cpu.flags.cf)
    {
        goto L_0x0048bf34;
    }
    // 0048bf2e  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048bf30  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bf32  75ee                   -jne 0x48bf22
    if (!cpu.flags.zf)
    {
        goto L_0x0048bf22;
    }
L_0x0048bf34:
    // 0048bf34  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bf36  7510                   -jne 0x48bf48
    if (!cpu.flags.zf)
    {
        goto L_0x0048bf48;
    }
L_0x0048bf38:
    // 0048bf38  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048bf3a:
    // 0048bf3a  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048bf3d  e81ee0ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bf42  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bf44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bf48:
    // 0048bf48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bf4a  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048bf4d  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bf50  39f0                   +cmp eax, esi
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
    // 0048bf52  75e4                   -jne 0x48bf38
    if (!cpu.flags.zf)
    {
        goto L_0x0048bf38;
    }
    // 0048bf54  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048bf56  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bf58  e82bfaffff             -call 0x48b988
    cpu.esp -= 4;
    sub_48b988(app, cpu);
    if (cpu.terminate) return;
    // 0048bf5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bf5f  75d9                   -jne 0x48bf3a
    if (!cpu.flags.zf)
    {
        goto L_0x0048bf3a;
    }
    // 0048bf61  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bf63  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048bf66  e8f5dfffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bf6b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bf6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48bf74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bf74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bf75  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bf76  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bf77  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bf78  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048bf7b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048bf7d  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048bf7f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048bf81  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048bf84  e8bfdfffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bf89  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048bf8c  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0048bf8f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048bf92  806604fe               -and byte ptr [esi + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048bf96  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048bf99  e8c2dfffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bf9e  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048bfa1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048bfa3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bfa5  7422                   -je 0x48bfc9
    if (cpu.flags.zf)
    {
        goto L_0x0048bfc9;
    }
L_0x0048bfa7:
    // 0048bfa7  8a5604                 -mov dl, byte ptr [esi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048bfaa  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0048bfad  751a                   -jne 0x48bfc9
    if (!cpu.flags.zf)
    {
        goto L_0x0048bfc9;
    }
    // 0048bfaf  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0048bfb2  750f                   -jne 0x48bfc3
    if (!cpu.flags.zf)
    {
        goto L_0x0048bfc3;
    }
    // 0048bfb4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048bfb6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bfb8  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bfba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bfbc  7504                   -jne 0x48bfc2
    if (!cpu.flags.zf)
    {
        goto L_0x0048bfc2;
    }
    // 0048bfbe  804e0401               -or byte ptr [esi + 4], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0048bfc2:
    // 0048bfc2  43                     -inc ebx
    (cpu.ebx)++;
L_0x0048bfc3:
    // 0048bfc3  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048bfc5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bfc7  75de                   -jne 0x48bfa7
    if (!cpu.flags.zf)
    {
        goto L_0x0048bfa7;
    }
L_0x0048bfc9:
    // 0048bfc9  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048bfcc  e877dfffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048bfd1  f6460401               +test byte ptr [esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0048bfd5  741d                   -je 0x48bff4
    if (cpu.flags.zf)
    {
        goto L_0x0048bff4;
    }
L_0x0048bfd7:
    // 0048bfd7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048bfda  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048bfdd  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bfdf  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048bfe2  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048bfe5  e876dfffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048bfea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bfec  83c404                 +add esp, 4
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
    // 0048bfef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bff0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bff1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bff2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bff3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bff4:
    // 0048bff4  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0048bff9  ebdc                   -jmp 0x48bfd7
    goto L_0x0048bfd7;
}

/* align: skip 0x90 */
void Application::sub_48bffc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bffc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bffd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048bfff  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048c002  e841dfffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048c007  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c009  e866ffffff             -call 0x48bf74
    cpu.esp -= 4;
    sub_48bf74(app, cpu);
    if (cpu.terminate) return;
    // 0048c00e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c010  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048c013  e848dfffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048c018  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c01a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c01b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c01c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c01c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048c01f  e924dfffff             -jmp 0x489f48
    return sub_489f48(app, cpu);
}

/* align: skip  */
void Application::sub_48c024(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c024  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048c027  e934dfffff             -jmp 0x489f60
    return sub_489f60(app, cpu);
}

/* align: skip  */
void Application::sub_48c02c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c02c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c02d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048c02f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c031  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048c033  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048c035  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048c03c  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048c03e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c03f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c040  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c041  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048c043  8b4408fc               -mov eax, dword ptr [eax + ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 1);
    // 0048c047  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048c049  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048c050  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048c052  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c053  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c054(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c054  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c055  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048c057  8d4408ff               -lea eax, [eax + ecx - 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0048c05b  83e901                 +sub ecx, 1
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
    // 0048c05e  7c0d                   -jl 0x48c06d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c06d;
    }
L_0x0048c060:
    // 0048c060  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0048c062  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0048c065  83e901                 +sub ecx, 1
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
    // 0048c068  8d40ff                 -lea eax, [eax - 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0048c06b  7df3                   -jge 0x48c060
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048c060;
    }
L_0x0048c06d:
    // 0048c06d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c06e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c06f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c06f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c070  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048c072  83e901                 +sub ecx, 1
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
    // 0048c075  7c0d                   -jl 0x48c084
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c084;
    }
L_0x0048c077:
    // 0048c077  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0048c079  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0048c07c  83e901                 +sub ecx, 1
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
    // 0048c07f  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048c082  7df3                   -jge 0x48c077
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048c077;
    }
L_0x0048c084:
    // 0048c084  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c085  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48c090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c090  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c092  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c094  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c096  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c098  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c09a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c09c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c09e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c100  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c102  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c104  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c106  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c108  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c10a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c10c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c10e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c110  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c112  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c114  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c116  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c118  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c11a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c11c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c11e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c120  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c122  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c124  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c126  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c128  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c12a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c12c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c12e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c130  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c132  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c134  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c136  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c138  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c13a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c13c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c13e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c140  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c142  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c144  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c146  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c148  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c14a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c14c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c14e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c150  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c152  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c154  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c156  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c158  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c15a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c15c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c15e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c160  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c162  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c164  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c166  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c168  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c16a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c16c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c16e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c170  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c172  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c174  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c176  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c178  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c17a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c17c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c17e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c180  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c182  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c184  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c186  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c188  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c18a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c18c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c18e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c190  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c192  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c194  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c196  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c198  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c19a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c19c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c19e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c200  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c202  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c204  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c206  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c208  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c20a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c20c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c20e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c210  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c212  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c214  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c216  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c218  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c21a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c21c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c21e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c220  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c222  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c224  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c226  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c228  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c22a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c22c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c22e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c230  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c232  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c234  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c236  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c238  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c23a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c23c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c23e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c240  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c242  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c244  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c246  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c248  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c24a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c24c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c24e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c250  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c252  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c254  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c256  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c258  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c25a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c25c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c25e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c260  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c262  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c264  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c266  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c268  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c26a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c26c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c26e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c271  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c273  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0048c276  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c277  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c279  8a480e                 -mov cl, byte ptr [eax + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 0048c27c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c27d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c27f  8a480d                 -mov cl, byte ptr [eax + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0048c282  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c283  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c285  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048c288  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c289  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c28b  8a480b                 -mov cl, byte ptr [eax + 0xb]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 0048c28e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c28f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c291  8a480a                 -mov cl, byte ptr [eax + 0xa]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0048c294  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c295  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c297  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 0048c29a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c29b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c29d  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048c2a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2a1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c2a3  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0048c2a7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2a8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c2aa  668b4804               -mov cx, word ptr [eax + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048c2ae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2af  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c2b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2b2  68e4fe4c00             -push 0x4cfee4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045988 /*0x4cfee4*/;
    cpu.esp -= 4;
    // 0048c2b7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c2b8  e844a2ffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0048c2bd  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0048c2c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c2c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0048c270;
    // 0048c090  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c092  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c094  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c096  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c098  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c09a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c09c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c09e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c0fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c100  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c102  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c104  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c106  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c108  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c10a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c10c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c10e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c110  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c112  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c114  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c116  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c118  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c11a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c11c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c11e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c120  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c122  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c124  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c126  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c128  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c12a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c12c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c12e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c130  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c132  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c134  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c136  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c138  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c13a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c13c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c13e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c140  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c142  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c144  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c146  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c148  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c14a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c14c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c14e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c150  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c152  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c154  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c156  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c158  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c15a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c15c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c15e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c160  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c162  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c164  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c166  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c168  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c16a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c16c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c16e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c170  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c172  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c174  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c176  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c178  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c17a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c17c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c17e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c180  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c182  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c184  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c186  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c188  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c18a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c18c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c18e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c190  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c192  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c194  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c196  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c198  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c19a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c19c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c19e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c1fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c200  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c202  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c204  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c206  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c208  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c20a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c20c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c20e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c210  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c212  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c214  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c216  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c218  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c21a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c21c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c21e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c220  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c222  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c224  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c226  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c228  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c22a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c22c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c22e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c230  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c232  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c234  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c236  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c238  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c23a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c23c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c23e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c240  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c242  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c244  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c246  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c248  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c24a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c24c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c24e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c250  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c252  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c254  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c256  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c258  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c25a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c25c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c25e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c260  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c262  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c264  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c266  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c268  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c26a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c26c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048c26e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x0048c270:
    // 0048c270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c271  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c273  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0048c276  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c277  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c279  8a480e                 -mov cl, byte ptr [eax + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 0048c27c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c27d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c27f  8a480d                 -mov cl, byte ptr [eax + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0048c282  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c283  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c285  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048c288  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c289  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c28b  8a480b                 -mov cl, byte ptr [eax + 0xb]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 0048c28e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c28f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c291  8a480a                 -mov cl, byte ptr [eax + 0xa]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0048c294  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c295  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c297  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 0048c29a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c29b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c29d  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048c2a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2a1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c2a3  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0048c2a7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2a8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c2aa  668b4804               -mov cx, word ptr [eax + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048c2ae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2af  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c2b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2b2  68e4fe4c00             -push 0x4cfee4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045988 /*0x4cfee4*/;
    cpu.esp -= 4;
    // 0048c2b7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c2b8  e844a2ffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0048c2bd  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0048c2c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c2c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48c2c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c2c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c2c5  8b15f0375600           -mov edx, dword ptr [0x5637f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */);
    // 0048c2cb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048c2cd  a3f8ba4d00             -mov dword ptr [0x4dbaf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5094136) /* 0x4dbaf8 */) = cpu.eax;
    // 0048c2d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c2d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c2d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c2d4  a1f0375600             -mov eax, dword ptr [0x5637f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */);
    // 0048c2d9  2b05f8ba4d00           -sub eax, dword ptr [0x4dbaf8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5094136) /* 0x4dbaf8 */)));
    // 0048c2df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c2e1  7c06                   -jl 0x48c2e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c2e9;
    }
    // 0048c2e3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048c2e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c2e9:
    // 0048c2e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c2eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c2ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c2ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c2ee  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c2f0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c2f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c2f4  740e                   -je 0x48c304
    if (cpu.flags.zf)
    {
        goto L_0x0048c304;
    }
L_0x0048c2f6:
    // 0048c2f6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c2f8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048c2fa  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048c2fc  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c2fe  42                     -inc edx
    (cpu.edx)++;
    // 0048c2ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c301  75f3                   -jne 0x48c2f6
    if (!cpu.flags.zf)
    {
        goto L_0x0048c2f6;
    }
    // 0048c303  90                     -nop 
    ;
L_0x0048c304:
    // 0048c304  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c306  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c307  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c308  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48c30c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c30c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c30d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c30e  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0048c314  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c316  899424ac000000         -mov dword ptr [esp + 0xac], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.edx;
    // 0048c31d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048c31f  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048c322  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048c324  750a                   -jne 0x48c330
    if (!cpu.flags.zf)
    {
        goto L_0x0048c330;
    }
    // 0048c326  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0048c32a  0f851e010000           -jne 0x48c44e
    if (!cpu.flags.zf)
    {
        goto L_0x0048c44e;
    }
L_0x0048c330:
    // 0048c330  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c331  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c332  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048c337  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048c33b  e814fdffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c340  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048c345  8d442450               -lea eax, [esp + 0x50]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0048c349  8b5174                 -mov edx, dword ptr [ecx + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */);
    // 0048c34c  e803fdffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c351  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048c356  8d442454               -lea eax, [esp + 0x54]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0048c35a  8b5178                 -mov edx, dword ptr [ecx + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0048c35d  e8f2fcffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c362  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048c367  8d442458               -lea eax, [esp + 0x58]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0048c36b  8b517c                 -mov edx, dword ptr [ecx + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 0048c36e  e8e1fcffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c373  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048c378  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0048c37c  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0048c382  be636564ea             -mov esi, 0xea646563
    cpu.esi = 3932448099 /*0xea646563*/;
    // 0048c387  e8c8fcffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c38c  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048c391  8d442460               -lea eax, [esp + 0x60]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048c395  8b9184000000           -mov edx, dword ptr [ecx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0048c39b  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048c39f  e8b0fcffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c3a4  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048c3a9  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048c3ad  8b5150                 -mov edx, dword ptr [ecx + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 0048c3b0  89b424b8000000         -mov dword ptr [esp + 0xb8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.esi;
    // 0048c3b7  e898fcffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c3bc  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0048c3c1  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048c3c4  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048c3c8  8d5154                 -lea edx, [ecx + 0x54]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 0048c3cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c3cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c3cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c3ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c3cf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c3d0  e807a1ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048c3d5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048c3d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048c3d9:
    // 0048c3d9  40                     -inc eax
    (cpu.eax)++;
    // 0048c3da  8a9a94000000           -mov bl, byte ptr [edx + 0x94]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(148) /* 0x94 */);
    // 0048c3e0  42                     -inc edx
    (cpu.edx)++;
    // 0048c3e1  885c0427               -mov byte ptr [esp + eax + 0x27], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(39) /* 0x27 */ + cpu.eax * 1) = cpu.bl;
    // 0048c3e5  83f808                 +cmp eax, 8
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
    // 0048c3e8  7cef                   -jl 0x48c3d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c3d9;
    }
    // 0048c3ea  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048c3ef  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048c3f3  8b958c000000           -mov edx, dword ptr [ebp + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 0048c3f9  e856fcffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c3fe  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048c403  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c405  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048c409  668b9590000000         -mov dx, word ptr [ebp + 0x90]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 0048c410  e83ffcffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c415  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048c41a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c41c  8d442426               -lea eax, [esp + 0x26]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(38) /* 0x26 */);
    // 0048c420  668b9592000000         -mov dx, word ptr [ebp + 0x92]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(146) /* 0x92 */);
    // 0048c427  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048c42b  e824fcffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c430  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 0048c435  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 0048c43c  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048c43f  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048c446  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048c449  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c44c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c44d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048c44e:
    // 0048c44e  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0048c454  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c455  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c456  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48c458(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c458  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c459  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c45a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c45b  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048c45e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048c460  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048c464  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048c468  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048c46c  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048c473  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048c476  a1f4ba4d00             -mov eax, dword ptr [0x4dbaf4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094132) /* 0x4dbaf4 */);
    // 0048c47b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0048c480  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0048c482  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c484  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048c486  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048c48b  a3f4ba4d00             -mov dword ptr [0x4dbaf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5094132) /* 0x4dbaf4 */) = cpu.eax;
    // 0048c490  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c492  e8bdfbffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048c497  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048c49a  83784400               +cmp dword ptr [eax + 0x44], 0
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
    // 0048c49e  7540                   -jne 0x48c4e0
    if (!cpu.flags.zf)
    {
        goto L_0x0048c4e0;
    }
L_0x0048c4a0:
    // 0048c4a0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048c4a4  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048c4a7  a1f0375600             -mov eax, dword ptr [0x5637f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */);
    // 0048c4ac  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048c4b0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c4b2  a3f8ba4d00             -mov dword ptr [0x4dbaf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5094136) /* 0x4dbaf8 */) = cpu.eax;
    // 0048c4b7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048c4bb  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0048c4bf  750f                   -jne 0x48c4d0
    if (!cpu.flags.zf)
    {
        goto L_0x0048c4d0;
    }
    // 0048c4c1  8d471c                 -lea eax, [edi + 0x1c]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0048c4c4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0048c4c7:
    // 0048c4c7  e808feffff             -call 0x48c2d4
    cpu.esp -= 4;
    sub_48c2d4(app, cpu);
    if (cpu.terminate) return;
    // 0048c4cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c4ce  741d                   -je 0x48c4ed
    if (cpu.flags.zf)
    {
        goto L_0x0048c4ed;
    }
L_0x0048c4d0:
    // 0048c4d0  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048c4d7  83c410                 +add esp, 0x10
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
    // 0048c4da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c4db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c4dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c4dd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048c4e0:
    // 0048c4e0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048c4e2  8d571c                 -lea edx, [edi + 0x1c]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0048c4e5  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0048c4e8  ff5544                 -call dword ptr [ebp + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c4eb  ebb3                   -jmp 0x48c4a0
    goto L_0x0048c4a0;
L_0x0048c4ed:
    // 0048c4ed  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048c4f1  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048c4f5  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048c4f9  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048c4fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c4fd  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048c501  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0048c504  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c507  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c509  7406                   -je 0x48c511
    if (cpu.flags.zf)
    {
        goto L_0x0048c511;
    }
    // 0048c50b  8b35d4ba4d00           -mov esi, dword ptr [0x4dbad4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5094100) /* 0x4dbad4 */);
L_0x0048c511:
    // 0048c511  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c513  e82c7affff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048c518  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c51a  7cb4                   -jl 0x48c4d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c4d0;
    }
    // 0048c51c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048c520  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0048c524  74a1                   -je 0x48c4c7
    if (cpu.flags.zf)
    {
        goto L_0x0048c4c7;
    }
    // 0048c526  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048c52d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048c530  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c531  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c532  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c533  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48c538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c538  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c539  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c53a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c53b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c53c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c53d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c540  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048c542  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048c544  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c546  8db088000000           -lea esi, [eax + 0x88]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(136) /* 0x88 */);
L_0x0048c54c:
    // 0048c54c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048c54f  8b8784000000           -mov eax, dword ptr [edi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 0048c555  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048c558  48                     -dec eax
    (cpu.eax)--;
    // 0048c559  39c8                   +cmp eax, ecx
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
    // 0048c55b  7645                   -jbe 0x48c5a2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048c5a2;
    }
    // 0048c55d  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0048c560  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048c565  8b5f50                 -mov ebx, dword ptr [edi + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 0048c568  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048c56a  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 0048c56c  7509                   -jne 0x48c577
    if (!cpu.flags.zf)
    {
        goto L_0x0048c577;
    }
L_0x0048c56e:
    // 0048c56e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048c571  42                     -inc edx
    (cpu.edx)++;
    // 0048c572  83c664                 +add esi, 0x64
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
    // 0048c575  ebd5                   -jmp 0x48c54c
    goto L_0x0048c54c;
L_0x0048c577:
    // 0048c577  6b0c2464               -imul ecx, dword ptr [esp], 0x64
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 0048c57b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048c57d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048c57f  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048c582  e869edffff             -call 0x48b2f0
    cpu.esp -= 4;
    sub_48b2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048c587  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c589  74e3                   -je 0x48c56e
    if (cpu.flags.zf)
    {
        goto L_0x0048c56e;
    }
    // 0048c58b  a1ccba4d00             -mov eax, dword ptr [0x4dbacc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */);
    // 0048c590  898439e4000000         -mov dword ptr [ecx + edi + 0xe4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */ + cpu.edi * 1) = cpu.eax;
    // 0048c597  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c599  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c59c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c59d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c59e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c59f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c5a2:
    // 0048c5a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c5a4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c5a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48c5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c5b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c5b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c5b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c5b3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048c5b5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048c5b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048c5b9:
    // 0048c5b9  8b9384000000           -mov edx, dword ptr [ebx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(132) /* 0x84 */);
    // 0048c5bf  4a                     -dec edx
    (cpu.edx)--;
    // 0048c5c0  39d0                   +cmp eax, edx
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
    // 0048c5c2  7356                   -jae 0x48c61a
    if (!cpu.flags.cf)
    {
        goto L_0x0048c61a;
    }
    // 0048c5c4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048c5c9  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0048c5cb  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048c5cd  8b4b50                 -mov ecx, dword ptr [ebx + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */);
    // 0048c5d0  85ca                   +test edx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.ecx));
    // 0048c5d2  7403                   -je 0x48c5d7
    if (cpu.flags.zf)
    {
        goto L_0x0048c5d7;
    }
    // 0048c5d4  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048c5d5  ebe2                   -jmp 0x48c5b9
    goto L_0x0048c5b9;
L_0x0048c5d7:
    // 0048c5d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c5d8  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048c5da  09d7                   -or edi, edx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c5dc  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048c5e3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c5e5  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048c5e8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048c5ea  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048c5ed  897b50                 -mov dword ptr [ebx + 0x50], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 0048c5f0  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048c5f2  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 0048c5f7  8dbb88000000           -lea edi, [ebx + 0x88]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(136) /* 0x88 */);
    // 0048c5fd  8b15ccba4d00           -mov edx, dword ptr [0x4dbacc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */);
    // 0048c603  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c605  8993e4000000           -mov dword ptr [ebx + 0xe4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(228) /* 0xe4 */) = cpu.edx;
    // 0048c60b  8983e8000000           -mov dword ptr [ebx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 0048c611  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c613  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c614  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c616  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c617  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c618  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c619  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c61a:
    // 0048c61a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c61c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c61e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c61f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c620  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c621  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48c624(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c624  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c625  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c626  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c627  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c628  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c629  81ecc8000000           -sub esp, 0xc8
    (cpu.esp) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0048c62f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048c631  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048c634  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048c636  898424c4000000         -mov dword ptr [esp + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.eax;
L_0x0048c63d:
    // 0048c63d  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 0048c642  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0048c647  8b8424c4000000         -mov eax, dword ptr [esp + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048c64e  899424c0000000         -mov dword ptr [esp + 0xc0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.edx;
    // 0048c655  8d9424ac000000         -lea edx, [esp + 0xac]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048c65c  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048c65e  e81de3ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048c663  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 0048c668  8d9c24c4000000         -lea ebx, [esp + 0xc4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048c66f  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048c672  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048c679  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048c67c  ff5554                 -call dword ptr [ebp + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c67f  83bc24c000000000       +cmp dword ptr [esp + 0xc0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c687  7516                   -jne 0x48c69f
    if (!cpu.flags.zf)
    {
        goto L_0x0048c69f;
    }
L_0x0048c689:
    // 0048c689  83bc24c000000000       +cmp dword ptr [esp + 0xc0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c691  75aa                   -jne 0x48c63d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c63d;
    }
    // 0048c693  81c4c8000000           +add esp, 0xc8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c699  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c69a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c69b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c69c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c69d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c69e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c69f:
    // 0048c69f  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048c6a1  8b9c24c0000000         -mov ebx, dword ptr [esp + 0xc0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0048c6a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c6a9  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048c6b0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048c6b2  e805000000             -call 0x48c6bc
    cpu.esp -= 4;
    sub_48c6bc(app, cpu);
    if (cpu.terminate) return;
    // 0048c6b7  ebd0                   -jmp 0x48c689
    goto L_0x0048c689;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48c6bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c6bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c6bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c6be  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c6bf  81eccc000000           -sub esp, 0xcc
    (cpu.esp) -= x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048c6c5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048c6c7  899424c4000000         -mov dword ptr [esp + 0xc4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.edx;
    // 0048c6ce  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048c6d0  898c24c8000000         -mov dword ptr [esp + 0xc8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */) = cpu.ecx;
    // 0048c6d7  8b6810                 -mov ebp, dword ptr [eax + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048c6da  81fb216f6eea           +cmp ebx, 0xea6e6f21
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
    // 0048c6e0  7337                   -jae 0x48c719
    if (!cpu.flags.cf)
    {
        goto L_0x0048c719;
    }
    // 0048c6e2  81fb657962ea           +cmp ebx, 0xea627965
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932322149 /*0xea627965*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c6e8  0f83de010000           -jae 0x48c8cc
    if (!cpu.flags.cf)
    {
        goto L_0x0048c8cc;
    }
    // 0048c6ee  81fb646461ea           +cmp ebx, 0xea616464
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932251236 /*0xea616464*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c6f4  7217                   -jb 0x48c70d
    if (cpu.flags.cf)
    {
        goto L_0x0048c70d;
    }
    // 0048c6f6  0f87e8020000           -ja 0x48c9e4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048c9e4;
    }
    // 0048c6fc  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048c6ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c701  740a                   -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c703  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0048c707  0f84ca050000           -je 0x48ccd7
    if (cpu.flags.zf)
    {
        goto L_0x0048ccd7;
    }
L_0x0048c70d:
    // 0048c70d  81c4cc000000           +add esp, 0xcc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(204 /*0xcc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c713  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c714  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c715  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c716  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048c719:
    // 0048c719  76f2                   -jbe 0x48c70d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c71b  8d451c                 -lea eax, [ebp + 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048c71e  898424bc000000         -mov dword ptr [esp + 0xbc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.eax;
    // 0048c725  81fb796c70ea           +cmp ebx, 0xea706c79
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933236345 /*0xea706c79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c72b  0f8377000000           -jae 0x48c7a8
    if (!cpu.flags.cf)
    {
        goto L_0x0048c7a8;
    }
    // 0048c731  81fb6e706fea           +cmp ebx, 0xea6f706e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933171822 /*0xea6f706e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c737  0f8323010000           -jae 0x48c860
    if (!cpu.flags.cf)
    {
        goto L_0x0048c860;
    }
    // 0048c73d  81fb616c6fea           +cmp ebx, 0xea6f6c61
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933170785 /*0xea6f6c61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c743  75c8                   -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c745  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048c748  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c74a  0f8522080000           -jne 0x48cf72
    if (!cpu.flags.zf)
    {
        goto L_0x0048cf72;
    }
    // 0048c750  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
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
    // 0048c757  74b4                   -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c759  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c760  74ab                   -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c762  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 0048c769  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048c770  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048c772  e879ebffff             -call 0x48b2f0
    cpu.esp -= 4;
    sub_48b2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048c777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c779  7492                   -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c77b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c77d  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0048c784  a1ccba4d00             -mov eax, dword ptr [0x4dbacc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */);
    // 0048c789  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048c78b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048c78e  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048c794  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c796  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048c799  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c79c  81c4cc000000           +add esp, 0xcc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(204 /*0xcc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c7a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c7a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c7a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c7a5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048c7a8:
    // 0048c7a8  0f8642020000           -jbe 0x48c9f0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048c9f0;
    }
    // 0048c7ae  81fb707372ea           +cmp ebx, 0xea727370
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933369200 /*0xea727370*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c7b4  7351                   -jae 0x48c807
    if (!cpu.flags.cf)
    {
        goto L_0x0048c807;
    }
    // 0048c7b6  81fb716572ea           +cmp ebx, 0xea726571
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933365617 /*0xea726571*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c7bc  0f854bffffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c7c2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048c7c4  0f8443ffffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c7ca  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 0048c7ce  0f8439ffffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c7d4  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048c7d9  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048c7e0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c7e2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048c7e4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048c7e6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048c7ed  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048c7ef  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048c7f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048c7f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c7f6  e811fbffff             -call 0x48c30c
    cpu.esp -= 4;
    sub_48c30c(app, cpu);
    if (cpu.terminate) return;
    // 0048c7fb  81c4cc000000           +add esp, 0xcc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(204 /*0xcc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c801  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c802  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c803  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c804  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048c807:
    // 0048c807  0f86ca060000           -jbe 0x48ced7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048ced7;
    }
    // 0048c80d  81fb767273ea           +cmp ebx, 0xea737276
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933434486 /*0xea737276*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c813  0f85f4feffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c819  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048c81b  0f84ecfeffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c821  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048c824  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048c826  0f84e1feffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c82c  8d420c                 -lea eax, [edx + 0xc]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c82f  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0048c834  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048c836  e805f1ffff             -call 0x48b940
    cpu.esp -= 4;
    sub_48b940(app, cpu);
    if (cpu.terminate) return;
    // 0048c83b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c83d  0f85cafeffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c843  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048c84a  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048c84d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048c84f  e8b8faffff             -call 0x48c30c
    cpu.esp -= 4;
    sub_48c30c(app, cpu);
    if (cpu.terminate) return;
    // 0048c854  81c4cc000000           +add esp, 0xcc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(204 /*0xcc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c85a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c85b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c85c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c85d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048c860:
    // 0048c860  773b                   -ja 0x48c89d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048c89d;
    }
    // 0048c862  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c866  0f84a1feffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c86c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048c86e  ff5510                 -call dword ptr [ebp + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c871  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c873  0f8594feffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c879  bb216f6eea             -mov ebx, 0xea6e6f21
    cpu.ebx = 3933105953 /*0xea6e6f21*/;
    // 0048c87e  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048c885  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c886  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048c889  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c88b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048c88e  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c891  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048c897  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c898  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c899  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c89a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048c89d:
    // 0048c89d  81fb74756fea           +cmp ebx, 0xea6f7574
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933173108 /*0xea6f7574*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c8a3  0f8564feffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
L_0x0048c8a9:
    // 0048c8a9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048c8ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c8ae  0f85e2060000           -jne 0x48cf96
    if (!cpu.flags.zf)
    {
        goto L_0x0048cf96;
    }
    // 0048c8b4  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048c8ba  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048c8c0  81c4cc000000           +add esp, 0xcc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(204 /*0xcc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c8c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c8c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c8c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c8c9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048c8cc:
    // 0048c8cc  76db                   -jbe 0x48c8a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048c8a9;
    }
    // 0048c8ce  81fb636564ea           +cmp ebx, 0xea646563
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932448099 /*0xea646563*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c8d4  734d                   -jae 0x48c923
    if (!cpu.flags.cf)
    {
        goto L_0x0048c923;
    }
    // 0048c8d6  81fb746164ea           +cmp ebx, 0xea646174
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
    // 0048c8dc  0f852bfeffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c8e2  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048c8e5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048c8e7  0f8596060000           -jne 0x48cf83
    if (!cpu.flags.zf)
    {
        goto L_0x0048cf83;
    }
    // 0048c8ed  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048c8f0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048c8f2  e8f9e9ffff             -call 0x48b2f0
    cpu.esp -= 4;
    sub_48b2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048c8f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c8f9  0f840efeffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c8ff  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c906  0f8401feffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c90c  a1d0ba4d00             -mov eax, dword ptr [0x4dbad0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094096) /* 0x4dbad0 */);
    // 0048c911  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048c917  81c4cc000000           +add esp, 0xcc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(204 /*0xcc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c91d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c91e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c91f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c920  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048c923:
    // 0048c923  0f8646010000           -jbe 0x48ca6f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048ca6f;
    }
    // 0048c929  81fb746567ea           +cmp ebx, 0xea676574
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932644724 /*0xea676574*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c92f  0f85d8fdffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c935  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 0048c939  0f84cefdffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048c93f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048c941  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048c945  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048c948  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c949  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c94a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c94b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c94c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c94d  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048c94f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048c952  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048c955  bb796c70ea             -mov ebx, 0xea706c79
    cpu.ebx = 3933236345 /*0xea706c79*/;
    // 0048c95a  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048c95e  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048c965  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048c96a  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048c96d  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 0048c972  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c974  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048c976  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048c978  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048c97f  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048c981  83f8ff                 +cmp eax, -1
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
    // 0048c984  0f84bc020000           -je 0x48cc46
    if (cpu.flags.zf)
    {
        goto L_0x0048cc46;
    }
    // 0048c98a  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0048c98f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0048c991  d3e7                   +shl edi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.edi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0048c993  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048c996  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048c998  854e50                 -test dword ptr [esi + 0x50], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) & cpu.ecx));
    // 0048c99b  0f84b6020000           -je 0x48cc57
    if (cpu.flags.zf)
    {
        goto L_0x0048cc57;
    }
    // 0048c9a1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048c9a3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048c9a5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048c9a8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048c9aa  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048c9ad  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048c9af  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048c9b2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c9b4  8d7c241c               -lea edi, [esp + 0x1c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048c9b8  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 0048c9bd  8db088000000           -lea esi, [eax + 0x88]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(136) /* 0x88 */);
L_0x0048c9c3:
    // 0048c9c3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0048c9c5:
    // 0048c9c5  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048c9c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c9c8  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048c9cb  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048c9ce  8b9424c8000000         -mov edx, dword ptr [esp + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048c9d5  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c9d8  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048c9de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9e1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048c9e4:
    // 0048c9e4  81fb646162ea           +cmp ebx, 0xea626164
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932316004 /*0xea626164*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c9ea  0f851dfdffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
L_0x0048c9f0:
    // 0048c9f0  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048c9f3  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048c9fa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048c9fc  e8efe8ffff             -call 0x48b2f0
    cpu.esp -= 4;
    sub_48b2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048ca01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ca03  0f8404fdffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048ca09  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ca10  740b                   -je 0x48ca1d
    if (cpu.flags.zf)
    {
        goto L_0x0048ca1d;
    }
    // 0048ca12  a1d0ba4d00             -mov eax, dword ptr [0x4dbad0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094096) /* 0x4dbad0 */);
    // 0048ca17  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
L_0x0048ca1d:
    // 0048ca1d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048ca22  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048ca29  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ca2b  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048ca2d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048ca2f  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048ca36  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ca38  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ca3c  0f84cbfcffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048ca42  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ca44  0f85c3fcffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048ca4a  81ff796c70ea           +cmp edi, 0xea706c79
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933236345 /*0xea706c79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ca50  0f840e020000           -je 0x48cc64
    if (cpu.flags.zf)
    {
        goto L_0x0048cc64;
    }
L_0x0048ca56:
    // 0048ca56  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 0048ca5d  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0048ca63  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048ca69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ca6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ca6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ca6c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048ca6f:
    // 0048ca6f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048ca74  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048ca7b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ca7d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048ca7f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048ca81  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048ca88  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ca8a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ca8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ca8e  0f85a4010000           -jne 0x48cc38
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc38;
    }
    // 0048ca94  833e00                 +cmp dword ptr [esi], 0
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
    // 0048ca97  0f859b010000           -jne 0x48cc38
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc38;
    }
    // 0048ca9d  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 0048caa1  0f8491010000           -je 0x48cc38
    if (cpu.flags.zf)
    {
        goto L_0x0048cc38;
    }
    // 0048caa7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048caac:
    // 0048caac  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048caae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cab0  753c                   -jne 0x48caee
    if (!cpu.flags.zf)
    {
        goto L_0x0048caee;
    }
    // 0048cab2  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 0048cab6  0f8583010000           -jne 0x48cc3f
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc3f;
    }
    // 0048cabc  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0048cabe  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048cac0  0f8479010000           -je 0x48cc3f
    if (cpu.flags.zf)
    {
        goto L_0x0048cc3f;
    }
    // 0048cac6  39fa                   +cmp edx, edi
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
    // 0048cac8  0f8571010000           -jne 0x48cc3f
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc3f;
    }
    // 0048cace  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048cad1  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048cad8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048cada  e811e8ffff             -call 0x48b2f0
    cpu.esp -= 4;
    sub_48b2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048cadf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cae1  0f8458010000           -je 0x48cc3f
    if (cpu.flags.zf)
    {
        goto L_0x0048cc3f;
    }
    // 0048cae7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048caec:
    // 0048caec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048caee:
    // 0048caee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048caf0  0f8417fcffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048caf6  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cafd  7411                   -je 0x48cb10
    if (cpu.flags.zf)
    {
        goto L_0x0048cb10;
    }
    // 0048caff  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 0048cb03  750b                   -jne 0x48cb10
    if (!cpu.flags.zf)
    {
        goto L_0x0048cb10;
    }
    // 0048cb05  a1d0ba4d00             -mov eax, dword ptr [0x4dbad0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094096) /* 0x4dbad0 */);
    // 0048cb0a  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
L_0x0048cb10:
    // 0048cb10  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cb17  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cb1c  83c048                 -add eax, 0x48
    (cpu.eax) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0048cb1f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cb21  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cb23  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cb25  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cb2c  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cb2e  89463c                 -mov dword ptr [esi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0048cb31  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cb38  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cb3d  83c04c                 -add eax, 0x4c
    (cpu.eax) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0048cb40  8b9424c8000000         -mov edx, dword ptr [esp + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cb47  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cb49  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cb4b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cb4d  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cb54  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cb56  894640                 -mov dword ptr [esi + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0048cb59  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cb60  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cb65  83c050                 -add eax, 0x50
    (cpu.eax) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0048cb68  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0048cb6d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cb6f  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cb71  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cb73  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cb7a  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cb7c  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0048cb7f  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cb86  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cb8b  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0048cb8e  8d7e1c                 -lea edi, [esi + 0x1c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048cb91  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cb93  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cb95  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cb97  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cb9e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cba0  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0048cba3  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cbaa  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cbaf  83c058                 -add eax, 0x58
    (cpu.eax) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0048cbb2  83c228                 -add edx, 0x28
    (cpu.edx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0048cbb5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cbb7  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cbb9  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cbbb  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cbc2  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cbc4  89464c                 -mov dword ptr [esi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0048cbc7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048cbc9  e80e99ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048cbce  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cbd5  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cbda  83c06c                 -add eax, 0x6c
    (cpu.eax) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048cbdd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cbdf  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cbe1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cbe3  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cbea  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cbec  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 0048cbf3  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048cbf6  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048cbf9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048cbfb  0f840cfbffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048cc01  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cc08  8b406c                 -mov eax, dword ptr [eax + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 0048cc0b  8b8c24c4000000         -mov ecx, dword ptr [esp + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048cc12  e8d5f6ffff             -call 0x48c2ec
    cpu.esp -= 4;
    sub_48c2ec(app, cpu);
    if (cpu.terminate) return;
    // 0048cc17  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048cc1a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048cc1c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048cc1e  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cc21  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cc23  0f85e4faffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048cc29  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048cc2c  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048cc32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc35  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048cc38:
    // 0048cc38  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048cc3a  e96dfeffff             -jmp 0x48caac
    goto L_0x0048caac;
L_0x0048cc3f:
    // 0048cc3f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048cc41  e9a6feffff             -jmp 0x48caec
    goto L_0x0048caec;
L_0x0048cc46:
    // 0048cc46  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 0048cc4b  8d7c241c               -lea edi, [esp + 0x1c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048cc4f  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048cc52  e96cfdffff             -jmp 0x48c9c3
    goto L_0x0048c9c3;
L_0x0048cc57:
    // 0048cc57  bb646162ea             -mov ebx, 0xea626164
    cpu.ebx = 3932316004 /*0xea626164*/;
    // 0048cc5c  83ea5c                 +sub edx, 0x5c
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(92 /*0x5c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048cc5f  e961fdffff             -jmp 0x48c9c5
    goto L_0x0048c9c5;
L_0x0048cc64:
    // 0048cc64  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cc6b  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cc70  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048cc73  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cc75  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cc77  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cc79  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cc80  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cc82  83f8ff                 +cmp eax, -1
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
    // 0048cc85  754c                   -jne 0x48ccd3
    if (!cpu.flags.zf)
    {
        goto L_0x0048ccd3;
    }
    // 0048cc87  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0048cc8c:
    // 0048cc8c  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cc93  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cc98  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048cc9b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cc9d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cc9f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cca1  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cca8  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ccaa  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048ccad  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048ccb4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048ccb6  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048ccb9  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048ccbc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ccbe  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048ccc0  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ccc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ccc5  0f858bfdffff           -jne 0x48ca56
    if (!cpu.flags.zf)
    {
        goto L_0x0048ca56;
    }
    // 0048cccb  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048ccce  e983fdffff             -jmp 0x48ca56
    goto L_0x0048ca56;
L_0x0048ccd3:
    // 0048ccd3  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048ccd5  ebb5                   -jmp 0x48cc8c
    goto L_0x0048cc8c;
L_0x0048ccd7:
    // 0048ccd7  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048ccde  bb707372ea             -mov ebx, 0xea727370
    cpu.ebx = 3933369200 /*0xea727370*/;
    // 0048cce3  e850f8ffff             -call 0x48c538
    cpu.esp -= 4;
    sub_48c538(app, cpu);
    if (cpu.terminate) return;
    // 0048cce8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ccea  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048ccf1  be20000000             -mov esi, 0x20
    cpu.esi = 32 /*0x20*/;
    // 0048ccf6  899c24b4000000         -mov dword ptr [esp + 0xb4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.ebx;
    // 0048ccfd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ccff  89b424b0000000         -mov dword ptr [esp + 0xb0], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.esi;
    // 0048cd06  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048cd09  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048cd0b  0f8584010000           -jne 0x48ce95
    if (!cpu.flags.zf)
    {
        goto L_0x0048ce95;
    }
    // 0048cd11  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048cd14  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 0048cd1a  8b4050                 -mov eax, dword ptr [eax + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048cd1d  4a                     -dec edx
    (cpu.edx)--;
    // 0048cd1e  e8c9f5ffff             -call 0x48c2ec
    cpu.esp -= 4;
    sub_48c2ec(app, cpu);
    if (cpu.terminate) return;
    // 0048cd23  39d0                   +cmp eax, edx
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
    // 0048cd25  0f8352010000           -jae 0x48ce7d
    if (!cpu.flags.cf)
    {
        goto L_0x0048ce7d;
    }
    // 0048cd2b  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048cd2e  80783c00               +cmp byte ptr [eax + 0x3c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cd32  0f85be000000           -jne 0x48cdf6
    if (!cpu.flags.zf)
    {
        goto L_0x0048cdf6;
    }
L_0x0048cd38:
    // 0048cd38  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cd3f  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0048cd42  898424b8000000         -mov dword ptr [esp + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 0048cd49  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cd50  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048cd57  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048cd5a  8bb424c4000000         -mov esi, dword ptr [esp + 0xc4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048cd61  e84af8ffff             -call 0x48c5b0
    cpu.esp -= 4;
    sub_48c5b0(app, cpu);
    if (cpu.terminate) return;
    // 0048cd66  8d7f28                 -lea edi, [edi + 0x28]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0048cd69  898424c0000000         -mov dword ptr [esp + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 0048cd70  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cd71  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cd72  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cd73  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cd74  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cd75  898424ac000000         -mov dword ptr [esp + 0xac], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0048cd7c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048cd7f  83784c00               +cmp dword ptr [eax + 0x4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cd83  0f85a1000000           -jne 0x48ce2a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ce2a;
    }
L_0x0048cd89:
    // 0048cd89  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048cd8e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048cd93  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048cd97  e8b8f2ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048cd9c  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048cda1  8b9424ac000000         -mov edx, dword ptr [esp + 0xac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048cda8  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048cdac  e8a3f2ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048cdb1  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cdb8  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0048cdbd  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cdc1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048cdc4  e8b7dbffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
L_0x0048cdc9:
    // 0048cdc9  8b9c24b0000000         -mov ebx, dword ptr [esp + 0xb0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048cdd0  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048cdd2  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048cdd9  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048cddc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cddd  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048cde0  8b9c24b8000000         -mov ebx, dword ptr [esp + 0xb8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048cde7  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cdea  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048cdf0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048cdf6:
    // 0048cdf6  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048cdfb  8b9424c8000000         -mov edx, dword ptr [esp + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048ce02  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0048ce05  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048ce08  e833ebffff             -call 0x48b940
    cpu.esp -= 4;
    sub_48b940(app, cpu);
    if (cpu.terminate) return;
    // 0048ce0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ce0f  0f8423ffffff           -je 0x48cd38
    if (cpu.flags.zf)
    {
        goto L_0x0048cd38;
    }
    // 0048ce15  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048ce1a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048ce1f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048ce23  e82cf2ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048ce28  eb9f                   -jmp 0x48cdc9
    goto L_0x0048cdc9;
L_0x0048ce2a:
    // 0048ce2a  8b9c24c0000000         -mov ebx, dword ptr [esp + 0xc0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0048ce31  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048ce38  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048ce3a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ce3c  43                     -inc ebx
    (cpu.ebx)++;
    // 0048ce3d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048ce3f  ff564c                 -call dword ptr [esi + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ce44  0f853fffffff           -jne 0x48cd89
    if (!cpu.flags.zf)
    {
        goto L_0x0048cd89;
    }
    // 0048ce4a  8a8c24c0000000         -mov cl, byte ptr [esp + 0xc0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0048ce51  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048ce56  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048ce58  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048ce5b  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 0048ce5d  8b4850                 -mov ecx, dword ptr [eax + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048ce60  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048ce65  21d1                   +and ecx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048ce67  bafdffffff             -mov edx, 0xfffffffd
    cpu.edx = 4294967293 /*0xfffffffd*/;
    // 0048ce6c  894850                 -mov dword ptr [eax + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 0048ce6f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048ce73  e8dcf1ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048ce78  e94cffffff             -jmp 0x48cdc9
    goto L_0x0048cdc9;
L_0x0048ce7d:
    // 0048ce7d  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048ce82  bafeffffff             -mov edx, 0xfffffffe
    cpu.edx = 4294967294 /*0xfffffffe*/;
    // 0048ce87  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048ce8b  e8c4f1ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048ce90  e934ffffff             -jmp 0x48cdc9
    goto L_0x0048cdc9;
L_0x0048ce95:
    // 0048ce95  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048ce9a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048ce9f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048cea3  e8acf1ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048cea8  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048ceab  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048cead  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048ceb2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ceb4  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 0048ceb9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048cebb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048cebe  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048cec0  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048cec5  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048cec9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048cecb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048cecd  e882f1ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048ced2  e9f2feffff             -jmp 0x48cdc9
    goto L_0x0048cdc9;
L_0x0048ced7:
    // 0048ced7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048ced9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048cedb  e810e4ffff             -call 0x48b2f0
    cpu.esp -= 4;
    sub_48b2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048cee0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cee2  0f8425f8ffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048cee8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048ceed  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cef4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cef6  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cef8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cefa  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cf01  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cf03  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cf05  0f8502f8ffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048cf0b  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cf12  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cf17  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048cf1a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cf1c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cf1e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cf20  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cf27  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cf29  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048cf2c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048cf2f  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0048cf35  83fb01                 +cmp ebx, 1
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
    // 0048cf38  0f85cff7ffff           -jne 0x48c70d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048cf3e  8bb424c8000000         -mov esi, dword ptr [esp + 0xc8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048cf45  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048cf48  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048cf4b  a1ccba4d00             -mov eax, dword ptr [0x4dbacc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */);
    // 0048cf50  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cf51  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cf52  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cf53  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cf54  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048cf55  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048cf5b  a1d0ba4d00             -mov eax, dword ptr [0x4dbad0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094096) /* 0x4dbad0 */);
    // 0048cf60  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048cf66  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048cf6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf6f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048cf72:
    // 0048cf72  e8c1f5ffff             -call 0x48c538
    cpu.esp -= 4;
    sub_48c538(app, cpu);
    if (cpu.terminate) return;
    // 0048cf77  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048cf7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf80  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048cf83:
    // 0048cf83  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048cf85  e8aef5ffff             -call 0x48c538
    cpu.esp -= 4;
    sub_48c538(app, cpu);
    if (cpu.terminate) return;
    // 0048cf8a  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048cf90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf93  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048cf96:
    // 0048cf96  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048cf9d  e896f5ffff             -call 0x48c538
    cpu.esp -= 4;
    sub_48c538(app, cpu);
    if (cpu.terminate) return;
    // 0048cfa2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048cfa4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cfa6  0f8461f7ffff           -je 0x48c70d
    if (cpu.flags.zf)
    {
        goto L_0x0048c70d;
    }
    // 0048cfac  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048cfaf  8d9788000000           -lea edx, [edi + 0x88]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(136) /* 0x88 */);
    // 0048cfb5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cfb7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048cfb9  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 0048cfbe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048cfc1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048cfc3  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0048cfc5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048cfca  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048cfcc  8b5750                 -mov edx, dword ptr [edi + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 0048cfcf  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0048cfd1  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0048cfd3  895750                 -mov dword ptr [edi + 0x50], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0048cfd6  c7465c00000000         -mov dword ptr [esi + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 0048cfdd  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048cfe3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfe4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfe5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfe6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cfec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cfec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cfed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cfee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cfef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cff0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cff1  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0048cff4  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048cff7  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048cff9  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 0048cffd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048cfff  0f8559010000           -jne 0x48d15e
    if (!cpu.flags.zf)
    {
        goto L_0x0048d15e;
    }
    // 0048d005  83b8a800000000         +cmp dword ptr [eax + 0xa8], 0
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
    // 0048d00c  7547                   -jne 0x48d055
    if (!cpu.flags.zf)
    {
        goto L_0x0048d055;
    }
    // 0048d00e  83780c00               +cmp dword ptr [eax + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d012  7441                   -je 0x48d055
    if (cpu.flags.zf)
    {
        goto L_0x0048d055;
    }
    // 0048d014  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0048d019  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048d01b  be90c04800             -mov esi, 0x48c090
    cpu.esi = 4767888 /*0x48c090*/;
    // 0048d020  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048d023  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d025  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048d029  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d02b  7502                   -jne 0x48d02f
    if (!cpu.flags.zf)
    {
        goto L_0x0048d02f;
    }
    // 0048d02d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
L_0x0048d02f:
    // 0048d02f  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0048d033  e8ecf5ffff             -call 0x48c624
    cpu.esp -= 4;
    sub_48c624(app, cpu);
    if (cpu.terminate) return;
    // 0048d038  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0048d03c  8bb8a4000000           -mov edi, dword ptr [eax + 0xa4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0048d042  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048d044  740f                   -je 0x48d055
    if (cpu.flags.zf)
    {
        goto L_0x0048d055;
    }
    // 0048d046  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 0048d04a  7509                   -jne 0x48d055
    if (!cpu.flags.zf)
    {
        goto L_0x0048d055;
    }
    // 0048d04c  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 0048d04f  8990a4000000           -mov dword ptr [eax + 0xa4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = cpu.edx;
L_0x0048d055:
    // 0048d055  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0048d059  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048d05c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048d05e  0f84fa000000           -je 0x48d15e
    if (cpu.flags.zf)
    {
        goto L_0x0048d15e;
    }
    // 0048d064  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048d067  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048d069  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d06b  0f85ed000000           -jne 0x48d15e
    if (!cpu.flags.zf)
    {
        goto L_0x0048d15e;
    }
    // 0048d071  83795000               +cmp dword ptr [ecx + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d075  0f84e3000000           -je 0x48d15e
    if (cpu.flags.zf)
    {
        goto L_0x0048d15e;
    }
    // 0048d07b  c7442450616c6fea       -mov dword ptr [esp + 0x50], 0xea6f6c61
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = 3933170785 /*0xea6f6c61*/;
    // 0048d083  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0048d087  8b90a0000000           -mov edx, dword ptr [eax + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 0048d08d  895c2458               -mov dword ptr [esp + 0x58], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.ebx;
    // 0048d091  83fa02                 +cmp edx, 2
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
    // 0048d094  7c4e                   -jl 0x48d0e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d0e4;
    }
    // 0048d096  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0048d099  8988a0000000           -mov dword ptr [eax + 0xa0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */) = cpu.ecx;
L_0x0048d09f:
    // 0048d09f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048d0a1  8d8688000000           -lea eax, [esi + 0x88]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0048d0a7  897c2460               -mov dword ptr [esp + 0x60], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edi;
    // 0048d0ab  89442454               -mov dword ptr [esp + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 0048d0af  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x0048d0b1:
    // 0048d0b1  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0048d0b7  8b6c2460               -mov ebp, dword ptr [esp + 0x60]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048d0bb  48                     -dec eax
    (cpu.eax)--;
    // 0048d0bc  39e8                   +cmp eax, ebp
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
    // 0048d0be  0f869a000000           -jbe 0x48d15e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048d15e;
    }
    // 0048d0c4  8a4c2460               -mov cl, byte ptr [esp + 0x60]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048d0c8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d0cd  8b5650                 -mov edx, dword ptr [esi + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0048d0d0  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048d0d2  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 0048d0d4  7528                   -jne 0x48d0fe
    if (!cpu.flags.zf)
    {
        goto L_0x0048d0fe;
    }
L_0x0048d0d6:
    // 0048d0d6  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048d0da  41                     -inc ecx
    (cpu.ecx)++;
    // 0048d0db  83c764                 +add edi, 0x64
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d0de  894c2460               -mov dword ptr [esp + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 0048d0e2  ebcd                   -jmp 0x48d0b1
    goto L_0x0048d0b1;
L_0x0048d0e4:
    // 0048d0e4  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0048d0e8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048d0ed  a1d0ba4d00             -mov eax, dword ptr [0x4dbad0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094096) /* 0x4dbad0 */);
    // 0048d0f2  895c2458               -mov dword ptr [esp + 0x58], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.ebx;
    // 0048d0f6  8982a0000000           -mov dword ptr [edx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048d0fc  eba1                   -jmp 0x48d09f
    goto L_0x0048d09f;
L_0x0048d0fe:
    // 0048d0fe  6bcd64                 -imul ecx, ebp, 0x64
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 0048d101  8b97e4000000           -mov edx, dword ptr [edi + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(228) /* 0xe4 */);
    // 0048d107  8d6aff                 -lea ebp, [edx - 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0048d10a  89afe4000000           -mov dword ptr [edi + 0xe4], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(228) /* 0xe4 */) = cpu.ebp;
    // 0048d110  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d112  7513                   -jne 0x48d127
    if (!cpu.flags.zf)
    {
        goto L_0x0048d127;
    }
    // 0048d114  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0048d116  214650                 -and dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) &= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d119  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048d11d  41                     -inc ecx
    (cpu.ecx)++;
    // 0048d11e  83c764                 +add edi, 0x64
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d121  894c2460               -mov dword ptr [esp + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 0048d125  eb8a                   -jmp 0x48d0b1
    goto L_0x0048d0b1;
L_0x0048d127:
    // 0048d127  837c245800             +cmp dword ptr [esp + 0x58], 0
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
    // 0048d12c  74a8                   -je 0x48d0d6
    if (cpu.flags.zf)
    {
        goto L_0x0048d0d6;
    }
    // 0048d12e  8b6c245c               -mov ebp, dword ptr [esp + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0048d132  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048d134  8b542458               -mov edx, dword ptr [esp + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0048d138  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048d13c  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0048d140  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048d143  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048d146  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d148  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d14a  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d14d  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048d151  41                     -inc ecx
    (cpu.ecx)++;
    // 0048d152  83c764                 +add edi, 0x64
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d155  894c2460               -mov dword ptr [esp + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 0048d159  e953ffffff             -jmp 0x48d0b1
    goto L_0x0048d0b1;
L_0x0048d15e:
    // 0048d15e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d163  83c464                 -add esp, 0x64
    (cpu.esp) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0048d166  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d167  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d168  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d169  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d16a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d16b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d16c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d16c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d16d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d16e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048d173  baeccf4800             -mov edx, 0x48cfec
    cpu.edx = 4771820 /*0x48cfec*/;
    // 0048d178  b864435600             -mov eax, 0x564364
    cpu.eax = 5653348 /*0x564364*/;
    // 0048d17d  e8f2edffff             -call 0x48bf74
    cpu.esp -= 4;
    sub_48bf74(app, cpu);
    if (cpu.terminate) return;
    // 0048d182  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d183  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d184  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d188  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d189  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d18a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d18c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048d18e  8b15fcba4d00           -mov edx, dword ptr [0x4dbafc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094140) /* 0x4dbafc */);
    // 0048d194  42                     -inc edx
    (cpu.edx)++;
    // 0048d195  8915fcba4d00           -mov dword ptr [0x4dbafc], edx
    app->getMemory<x86::reg32>(x86::reg32(5094140) /* 0x4dbafc */) = cpu.edx;
    // 0048d19b  83fa01                 +cmp edx, 1
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
    // 0048d19e  7514                   -jne 0x48d1b4
    if (!cpu.flags.zf)
    {
        goto L_0x0048d1b4;
    }
    // 0048d1a0  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048d1a3  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d1a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d1a8  741b                   -je 0x48d1c5
    if (cpu.flags.zf)
    {
        goto L_0x0048d1c5;
    }
    // 0048d1aa  b86cd14800             -mov eax, 0x48d16c
    cpu.eax = 4772204 /*0x48d16c*/;
    // 0048d1af  e8506d0100             -call 0x4a3f04
    cpu.esp -= 4;
    sub_4a3f04(app, cpu);
    if (cpu.terminate) return;
L_0x0048d1b4:
    // 0048d1b4  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048d1b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d1b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d1bb  ff531c                 -call dword ptr [ebx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d1be  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048d1c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d1c3  7505                   -jne 0x48d1ca
    if (!cpu.flags.zf)
    {
        goto L_0x0048d1ca;
    }
L_0x0048d1c5:
    // 0048d1c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1c7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048d1ca:
    // 0048d1ca  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048d1cd  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0048d1d0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048d1d5  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d1d8  8d968c000000           -lea edx, [esi + 0x8c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0048d1de  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d1e0  c7869c00000001000000   -mov dword ptr [esi + 0x9c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 0048d1ea  e891d7ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048d1ef  bb33000000             -mov ebx, 0x33
    cpu.ebx = 51 /*0x33*/;
    // 0048d1f4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048d1f8  8d4644                 -lea eax, [esi + 0x44]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0048d1fb  e8dc92ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048d200  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 0048d205  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048d209  8d4678                 -lea eax, [esi + 0x78]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0048d20c  e8cb92ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048d211  b8fa000000             -mov eax, 0xfa
    cpu.eax = 250 /*0xfa*/;
    // 0048d216  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d217  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d218  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d21c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d21c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d21d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d21e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d21f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d220  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d221  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d223  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048d226  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048d22b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d22d  745b                   -je 0x48d28a
    if (cpu.flags.zf)
    {
        goto L_0x0048d28a;
    }
    // 0048d22f  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 0048d233  7509                   -jne 0x48d23e
    if (!cpu.flags.zf)
    {
        goto L_0x0048d23e;
    }
    // 0048d235  83b8a000000000         +cmp dword ptr [eax + 0xa0], 0
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
    // 0048d23c  7409                   -je 0x48d247
    if (cpu.flags.zf)
    {
        goto L_0x0048d247;
    }
L_0x0048d23e:
    // 0048d23e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d240  e847e0ffff             -call 0x48b28c
    cpu.esp -= 4;
    sub_48b28c(app, cpu);
    if (cpu.terminate) return;
    // 0048d245  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048d247:
    // 0048d247  8baaa8000000           -mov ebp, dword ptr [edx + 0xa8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 0048d24d  c7829c00000000000000   -mov dword ptr [edx + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 0048d257  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048d259  7411                   -je 0x48d26c
    if (cpu.flags.zf)
    {
        goto L_0x0048d26c;
    }
    // 0048d25b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048d25d:
    // 0048d25d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d25f  e84c6cffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 0048d264  3bb2a8000000           +cmp esi, dword ptr [edx + 0xa8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d26a  75f1                   -jne 0x48d25d
    if (!cpu.flags.zf)
    {
        goto L_0x0048d25d;
    }
L_0x0048d26c:
    // 0048d26c  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048d26f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d271  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048d278  ff5620                 -call dword ptr [esi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d27b  8b1dfcba4d00           -mov ebx, dword ptr [0x4dbafc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094140) /* 0x4dbafc */);
    // 0048d281  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048d282  891dfcba4d00           -mov dword ptr [0x4dbafc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094140) /* 0x4dbafc */) = cpu.ebx;
    // 0048d288  7408                   -je 0x48d292
    if (cpu.flags.zf)
    {
        goto L_0x0048d292;
    }
L_0x0048d28a:
    // 0048d28a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d28c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d28d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d28e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d28f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d290  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d291  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d292:
    // 0048d292  b86cd14800             -mov eax, 0x48d16c
    cpu.eax = 4772204 /*0x48d16c*/;
    // 0048d297  e8d06c0100             -call 0x4a3f6c
    cpu.esp -= 4;
    sub_4a3f6c(app, cpu);
    if (cpu.terminate) return;
    // 0048d29c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048d29f  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d2a2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d2a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d2a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d2ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d2ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d2ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d2ae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d2af  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048d2b5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d2b7  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 0048d2be  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 0048d2c5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048d2c7  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0048d2cc  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048d2ce  bee0c04800             -mov esi, 0x48c0e0
    cpu.esi = 4767968 /*0x48c0e0*/;
    // 0048d2d3  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0048d2d7  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0048d2dc  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d2de  e88defffff             -call 0x48c270
    cpu.esp -= 4;
    sub_48c270(app, cpu);
    if (cpu.terminate) return;
    // 0048d2e3  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048d2ea  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0048d2ee  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048d2f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d2f4  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048d2f8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048d2fb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d2fd  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048d300  a1f0375600             -mov eax, dword ptr [0x5637f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */);
    // 0048d305  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0048d30c  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0048d311  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d313  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d315  a3f8ba4d00             -mov dword ptr [0x4dbaf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5094136) /* 0x4dbaf8 */) = cpu.eax;
L_0x0048d31a:
    // 0048d31a  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048d31d  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0048d321  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048d324  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d327  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0048d329:
    // 0048d329  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d32b  e8146cffff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048d330  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d332  7d1d                   -jge 0x48d351
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d351;
    }
L_0x0048d334:
    // 0048d334  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d336  752a                   -jne 0x48d362
    if (!cpu.flags.zf)
    {
        goto L_0x0048d362;
    }
    // 0048d338  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d33a  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048d341  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048d347  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d348  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d349  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d34a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d34b:
    // 0048d34b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d34d  74cb                   -je 0x48d31a
    if (cpu.flags.zf)
    {
        goto L_0x0048d31a;
    }
    // 0048d34f  ebd8                   -jmp 0x48d329
    goto L_0x0048d329;
L_0x0048d351:
    // 0048d351  e87eefffff             -call 0x48c2d4
    cpu.esp -= 4;
    sub_48c2d4(app, cpu);
    if (cpu.terminate) return;
    // 0048d356  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d358  75da                   -jne 0x48d334
    if (!cpu.flags.zf)
    {
        goto L_0x0048d334;
    }
    // 0048d35a  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
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
    // 0048d35e  75eb                   -jne 0x48d34b
    if (!cpu.flags.zf)
    {
        goto L_0x0048d34b;
    }
    // 0048d360  ebd2                   -jmp 0x48d334
    goto L_0x0048d334;
L_0x0048d362:
    // 0048d362  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048d365  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048d368  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d36b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d36d  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048d374  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048d37a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d37b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d37c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d37d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d380  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d381  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d382  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d383  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d384  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048d38a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d38c  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 0048d393  899c24fc000000         -mov dword ptr [esp + 0xfc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.ebx;
    // 0048d39a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0048d39f  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048d3a6  be30c14800             -mov esi, 0x48c130
    cpu.esi = 4768048 /*0x48c130*/;
    // 0048d3ab  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3ad  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
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
    // 0048d3b4  0f857e000000           -jne 0x48d438
    if (!cpu.flags.zf)
    {
        goto L_0x0048d438;
    }
L_0x0048d3ba:
    // 0048d3ba  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 0048d3bf  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048d3c3  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048d3c6  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3c8  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d3cc  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048d3d3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3d5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3d6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3d7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3d8  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048d3df  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048d3e2  8b8c24fc000000         -mov ecx, dword ptr [esp + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0048d3e9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3ea  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3eb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3ec  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3ed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d3ee  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048d3f0  7476                   -je 0x48d468
    if (cpu.flags.zf)
    {
        goto L_0x0048d468;
    }
    // 0048d3f2  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048d3f7  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048d3fb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d3fd  e8da90ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
L_0x0048d402:
    // 0048d402  a1ccab4d00             -mov eax, dword ptr [0x4dabcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048d407  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d409  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d40a  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d40e  bb646461ea             -mov ebx, 0xea616464
    cpu.ebx = 3932251236 /*0xea616464*/;
    // 0048d413  6888000000             -push 0x88
    app->getMemory<x86::reg32>(cpu.esp-4) = 136 /*0x88*/;
    cpu.esp -= 4;
    // 0048d418  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0048d41f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d421  e832f0ffff             -call 0x48c458
    cpu.esp -= 4;
    sub_48c458(app, cpu);
    if (cpu.terminate) return;
    // 0048d426  8b8424b0000000         -mov eax, dword ptr [esp + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
L_0x0048d42d:
    // 0048d42d  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048d433  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d434  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d435  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d436  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d437  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d438:
    // 0048d438  8b9c2400010000         -mov ebx, dword ptr [esp + 0x100]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048d43f  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048d442  e8a9deffff             -call 0x48b2f0
    cpu.esp -= 4;
    sub_48b2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048d447  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d449  7407                   -je 0x48d452
    if (cpu.flags.zf)
    {
        goto L_0x0048d452;
    }
    // 0048d44b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d450  ebdb                   -jmp 0x48d42d
    goto L_0x0048d42d;
L_0x0048d452:
    // 0048d452  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d454  e833deffff             -call 0x48b28c
    cpu.esp -= 4;
    sub_48b28c(app, cpu);
    if (cpu.terminate) return;
    // 0048d459  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 0048d463  e952ffffff             -jmp 0x48d3ba
    goto L_0x0048d3ba;
L_0x0048d468:
    // 0048d468  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d46b  c6403c00               -mov byte ptr [eax + 0x3c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 0048d46f  eb91                   -jmp 0x48d402
    goto L_0x0048d402;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d474(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d474  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d475  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d476  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d477  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d478  81ecfc000000           -sub esp, 0xfc
    (cpu.esp) -= x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 0048d47e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048d480  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0048d485  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048d48c  be80c14800             -mov esi, 0x48c180
    cpu.esi = 4768128 /*0x48c180*/;
    // 0048d491  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d493  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d495  7554                   -jne 0x48d4eb
    if (!cpu.flags.zf)
    {
        goto L_0x0048d4eb;
    }
    // 0048d497  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
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
    // 0048d49e  744b                   -je 0x48d4eb
    if (cpu.flags.zf)
    {
        goto L_0x0048d4eb;
    }
L_0x0048d4a0:
    // 0048d4a0  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048d4a6  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048d4a8  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048d4aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d4ab  bb716572ea             -mov ebx, 0xea726571
    cpu.ebx = 3933365617 /*0xea726571*/;
    // 0048d4b0  8db424cc000000         -lea esi, [esp + 0xcc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 0048d4b7  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 0048d4bc  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0048d4c3  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0048d4c5  e88eefffff             -call 0x48c458
    cpu.esp -= 4;
    sub_48c458(app, cpu);
    if (cpu.terminate) return;
    // 0048d4ca  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 0048d4cf  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d4d1  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
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
    // 0048d4d9  7429                   -je 0x48d504
    if (cpu.flags.zf)
    {
        goto L_0x0048d504;
    }
    // 0048d4db  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d4e0  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 0048d4e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d4e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d4e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d4e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d4ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d4eb:
    // 0048d4eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d4ed  7415                   -je 0x48d504
    if (cpu.flags.zf)
    {
        goto L_0x0048d504;
    }
    // 0048d4ef  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
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
    // 0048d4f6  750c                   -jne 0x48d504
    if (!cpu.flags.zf)
    {
        goto L_0x0048d504;
    }
    // 0048d4f8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d4fa  8d781c                 -lea edi, [eax + 0x1c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048d4fd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d4fe  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d4ff  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d500  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d501  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d502  eb9c                   -jmp 0x48d4a0
    goto L_0x0048d4a0;
L_0x0048d504:
    // 0048d504  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d506  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 0048d50c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d50d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d50e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d50f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d510  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d514(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d514  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d515  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d516  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d517  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048d51a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d51c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d51e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048d522  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048d525  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d527  8b4e30                 -mov ecx, dword ptr [esi + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0048d52a  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048d52e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048d530  0f84e6000000           -je 0x48d61c
    if (cpu.flags.zf)
    {
        goto L_0x0048d61c;
    }
L_0x0048d536:
    // 0048d536  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
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
    // 0048d53d  7411                   -je 0x48d550
    if (cpu.flags.zf)
    {
        goto L_0x0048d550;
    }
    // 0048d53f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d541  e846ddffff             -call 0x48b28c
    cpu.esp -= 4;
    sub_48b28c(app, cpu);
    if (cpu.terminate) return;
    // 0048d546  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
L_0x0048d550:
    // 0048d550  8b5630                 -mov edx, dword ptr [esi + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0048d553  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048d556  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048d55d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d55f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048d562  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048d564  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048d567  8d90ec000000           -lea edx, [eax + 0xec]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(236) /* 0xec */);
    // 0048d56d  8b1de8ab4d00           -mov ebx, dword ptr [0x4dabe8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 0048d573  b81cff4c00             -mov eax, 0x4cff1c
    cpu.eax = 5046044 /*0x4cff1c*/;
    // 0048d578  e81b6fffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 0048d57d  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048d580  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d582  0f8489000000           -je 0x48d611
    if (cpu.flags.zf)
    {
        goto L_0x0048d611;
    }
    // 0048d588  896804                 -mov dword ptr [eax + 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0048d58b  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d58e  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 0048d593  8d7f54                 -lea edi, [edi + 0x54]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 0048d596  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d598  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d59b  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048d5a2  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d5a5  c7405000000000         -mov dword ptr [eax + 0x50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 0048d5ac  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d5af  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d5b2  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0048d5b5  a1ccba4d00             -mov eax, dword ptr [0x4dbacc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */);
    // 0048d5ba  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048d5bd  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048d5c3  a1d0ba4d00             -mov eax, dword ptr [0x4dbad0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094096) /* 0x4dbad0 */);
    // 0048d5c8  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048d5cb  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048d5d1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d5d5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5d6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5d7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5d8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5d9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d5dc  754a                   -jne 0x48d628
    if (!cpu.flags.zf)
    {
        goto L_0x0048d628;
    }
    // 0048d5de  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d5e1  c6403c00               -mov byte ptr [eax + 0x3c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
L_0x0048d5e5:
    // 0048d5e5  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d5e8  8d858c000000           -lea eax, [ebp + 0x8c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 0048d5ee  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048d5f1  e87aecffff             -call 0x48c270
    cpu.esp -= 4;
    sub_48c270(app, cpu);
    if (cpu.terminate) return;
    // 0048d5f6  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048d5f9  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d5fc  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048d5ff  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048d602  ff5328                 -call dword ptr [ebx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d605  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d607  7435                   -je 0x48d63e
    if (cpu.flags.zf)
    {
        goto L_0x0048d63e;
    }
    // 0048d609  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x0048d611:
    // 0048d611  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d615  83c40c                 +add esp, 0xc
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
    // 0048d618  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d619  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d61a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d61b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d61c:
    // 0048d61c  c7463020000000         -mov dword ptr [esi + 0x30], 0x20
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 32 /*0x20*/;
    // 0048d623  e90effffff             -jmp 0x48d536
    goto L_0x0048d536;
L_0x0048d628:
    // 0048d628  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048d62d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d630  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d634  83c03c                 +add eax, 0x3c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d637  e8a08effff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048d63c  eba7                   -jmp 0x48d5e5
    goto L_0x0048d5e5;
L_0x0048d63e:
    // 0048d63e  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d641  e8b672ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0048d646  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0048d64d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d651  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048d654  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d655  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d656  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d657  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d658(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d658  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d659  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048d65c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048d65e  7504                   -jne 0x48d664
    if (!cpu.flags.zf)
    {
        goto L_0x0048d664;
    }
    // 0048d660  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d662  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d663  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d664:
    // 0048d664  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d665  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d666  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048d668  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 0048d66d  8d7e54                 -lea edi, [esi + 0x54]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 0048d670  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d672  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d677  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d679  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d67a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d67b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d67c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d682  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d684  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048d686  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048d689  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d68b  7442                   -je 0x48d6cf
    if (cpu.flags.zf)
    {
        goto L_0x0048d6cf;
    }
    // 0048d68d  837a0800               +cmp dword ptr [edx + 8], 0
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
    // 0048d691  741b                   -je 0x48d6ae
    if (cpu.flags.zf)
    {
        goto L_0x0048d6ae;
    }
L_0x0048d693:
    // 0048d693  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d695  740f                   -je 0x48d6a6
    if (cpu.flags.zf)
    {
        goto L_0x0048d6a6;
    }
    // 0048d697  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048d69a  e85d72ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0048d69f  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x0048d6a6:
    // 0048d6a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d6ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d6ae:
    // 0048d6ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d6af  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048d6b2  83c20c                 +add edx, 0xc
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d6b5  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048d6b8  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d6bb  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048d6be  c6400c00               -mov byte ptr [eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048d6c2  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048d6c5  c7400801000000         -mov dword ptr [eax + 8], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0048d6cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6cd  ebc4                   -jmp 0x48d693
    goto L_0x0048d693;
L_0x0048d6cf:
    // 0048d6cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d6d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d6d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d6d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d6d5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d6d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d6d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d6d8  8b3dccba4d00           -mov edi, dword ptr [0x4dbacc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */);
    // 0048d6de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d6e0  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048d6e3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d6e5  7409                   -je 0x48d6f0
    if (cpu.flags.zf)
    {
        goto L_0x0048d6f0;
    }
    // 0048d6e7  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048d6ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d6ec  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048d6ee  7513                   -jne 0x48d703
    if (!cpu.flags.zf)
    {
        goto L_0x0048d703;
    }
L_0x0048d6f0:
    // 0048d6f0  8b3dccba4d00           -mov edi, dword ptr [0x4dbacc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */);
    // 0048d6f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d6f8  893dccba4d00           -mov dword ptr [0x4dbacc], edi
    app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */) = cpu.edi;
    // 0048d6fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d700  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d701  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d702  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d703:
    // 0048d703  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048d70a  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048d70d  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0048d713  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048d716  e855ebffff             -call 0x48c270
    cpu.esp -= 4;
    sub_48c270(app, cpu);
    if (cpu.terminate) return;
    // 0048d71b  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048d71e  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048d721  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048d724  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048d727  ff5128                 -call dword ptr [ecx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d72a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d72c  7441                   -je 0x48d76f
    if (cpu.flags.zf)
    {
        goto L_0x0048d76f;
    }
    // 0048d72e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d72f  8b3dccba4d00           -mov edi, dword ptr [0x4dbacc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */);
    // 0048d735  c786a000000001000000   -mov dword ptr [esi + 0xa0], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = 1 /*0x1*/;
    // 0048d73f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d741  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048d743:
    // 0048d743  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048d746  8b9984000000           -mov ebx, dword ptr [ecx + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0048d74c  4b                     -dec ebx
    (cpu.ebx)--;
    // 0048d74d  39da                   +cmp edx, ebx
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
    // 0048d74f  730d                   -jae 0x48d75e
    if (!cpu.flags.cf)
    {
        goto L_0x0048d75e;
    }
    // 0048d751  83c064                 +add eax, 0x64
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d754  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048d755  89bc0180000000         -mov dword ptr [ecx + eax + 0x80], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */ + cpu.eax * 1) = cpu.edi;
    // 0048d75c  ebe5                   -jmp 0x48d743
    goto L_0x0048d743;
L_0x0048d75e:
    // 0048d75e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d763  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d764  893dccba4d00           -mov dword ptr [0x4dbacc], edi
    app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */) = cpu.edi;
    // 0048d76a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d76b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d76c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d76d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d76e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d76f:
    // 0048d76f  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048d772  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048d779  8b3dccba4d00           -mov edi, dword ptr [0x4dbacc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */);
    // 0048d77f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d781  893dccba4d00           -mov dword ptr [0x4dbacc], edi
    app->getMemory<x86::reg32>(x86::reg32(5094092) /* 0x4dbacc */) = cpu.edi;
    // 0048d787  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d788  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d789  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d78a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d78b  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
