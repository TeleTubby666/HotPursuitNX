#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45b7f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0045b7f8  48                     -dec eax
    (cpu.eax)--;
    // 0045b7f9  83f80d                 +cmp eax, 0xd
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
    // 0045b7fc  7725                   -ja 0x45b823
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045b823;
    }
    // 0045b7fe  ff2485c0b74500         -jmp dword ptr [eax*4 + 0x45b7c0]
    cpu.ip = app->getMemory<x86::reg32>(4569024 + cpu.eax * 4); goto dynamic_jump;
  case 0x0045b805:
    // 0045b805  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0045b80a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045b80b:
    // 0045b80b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045b810  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045b811:
    // 0045b811  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0045b816  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045b817:
    // 0045b817  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0045b81c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045b81d:
    // 0045b81d  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0045b822  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045b823:
L_0x0045b823:
    // 0045b823  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045b825  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45b830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045b830  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045b832  7501                   -jne 0x45b835
    if (!cpu.flags.zf)
    {
        goto L_0x0045b835;
    }
    // 0045b834  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045b835:
    // 0045b835  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045b836  668b4a02               -mov cx, word ptr [edx + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0045b83a  6689481e               -mov word ptr [eax + 0x1e], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(30) /* 0x1e */) = cpu.cx;
    // 0045b83e  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0045b841  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0045b844  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0045b847  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0045b84a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0045b84d  894828                 -mov dword ptr [eax + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 0045b850  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0045b853  89482c                 -mov dword ptr [eax + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0045b856  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0045b859  895030                 -mov dword ptr [eax + 0x30], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0045b85c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045b85d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45b860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045b860  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045b861  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045b862  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045b863  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045b864  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0045b86a  899c2408010000         -mov dword ptr [esp + 0x108], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.ebx;
    // 0045b871  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0045b873  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045b875  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045b876:
    // 0045b876  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045b878  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045b87a  3c00                   +cmp al, 0
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
    // 0045b87c  7410                   -je 0x45b88e
    if (cpu.flags.zf)
    {
        goto L_0x0045b88e;
    }
    // 0045b87e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045b881  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045b884  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045b887  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045b88a  3c00                   +cmp al, 0
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
    // 0045b88c  75e8                   -jne 0x45b876
    if (!cpu.flags.zf)
    {
        goto L_0x0045b876;
    }
L_0x0045b88e:
    // 0045b88e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045b88f  be08d24b00             -mov esi, 0x4bd208
    cpu.esi = 4968968 /*0x4bd208*/;
    // 0045b894  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0045b896  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045b897  2bc9                   +sub ecx, ecx
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
    // 0045b899  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0045b89a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0045b89c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0045b89e  4f                     -dec edi
    (cpu.edi)--;
L_0x0045b89f:
    // 0045b89f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045b8a1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045b8a3  3c00                   +cmp al, 0
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
    // 0045b8a5  7410                   -je 0x45b8b7
    if (cpu.flags.zf)
    {
        goto L_0x0045b8b7;
    }
    // 0045b8a7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045b8aa  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045b8ad  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045b8b0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045b8b3  3c00                   +cmp al, 0
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
    // 0045b8b5  75e8                   -jne 0x45b89f
    if (!cpu.flags.zf)
    {
        goto L_0x0045b89f;
    }
L_0x0045b8b7:
    // 0045b8b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045b8b8  8b1548544c00           -mov edx, dword ptr [0x4c5448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5002312) /* 0x4c5448 */);
    // 0045b8be  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045b8c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045b8c2  0f8512010000           -jne 0x45b9da
    if (!cpu.flags.zf)
    {
        goto L_0x0045b9da;
    }
L_0x0045b8c8:
    // 0045b8c8  8bbc240c010000         -mov edi, dword ptr [esp + 0x10c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0045b8cf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045b8d1  0f847c010000           -je 0x45ba53
    if (cpu.flags.zf)
    {
        goto L_0x0045ba53;
    }
    // 0045b8d7  81c58c000000           -add ebp, 0x8c
    (cpu.ebp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0045b8dd  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0045b8df  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
    // 0045b8e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045b8e8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0045b8ea:
    // 0045b8ea  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0045b8f1  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045b8f3  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045b8f6  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045b8f8  83c534                 -add ebp, 0x34
    (cpu.ebp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0045b8fb  39d7                   +cmp edi, edx
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
    // 0045b8fd  7420                   -je 0x45b91f
    if (cpu.flags.zf)
    {
        goto L_0x0045b91f;
    }
    // 0045b8ff  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0045b906  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045b908  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0045b90b  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0045b90e  f60201                 +test byte ptr [edx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx) & 1 /*0x1*/));
    // 0045b911  0f844b010000           -je 0x45ba62
    if (cpu.flags.zf)
    {
        goto L_0x0045ba62;
    }
    // 0045b917  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0045b919  40                     -inc eax
    (cpu.eax)++;
    // 0045b91a  6bc006                 -imul eax, eax, 6
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(6 /*0x6*/)));
L_0x0045b91d:
    // 0045b91d  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0045b91f:
    // 0045b91f  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0045b922  3b7a04                 +cmp edi, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045b925  7415                   -je 0x45b93c
    if (cpu.flags.zf)
    {
        goto L_0x0045b93c;
    }
    // 0045b927  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0045b92e  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045b930  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0045b933  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0045b936  6b40040c               -imul eax, dword ptr [eax + 4], 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0045b93a  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0045b93c:
    // 0045b93c  83fb0c                 +cmp ebx, 0xc
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
    // 0045b93f  0f8525010000           -jne 0x45ba6a
    if (!cpu.flags.zf)
    {
        goto L_0x0045ba6a;
    }
L_0x0045b945:
    // 0045b945  3b7904                 +cmp edi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045b948  7428                   -je 0x45b972
    if (cpu.flags.zf)
    {
        goto L_0x0045b972;
    }
    // 0045b94a  8b842408010000         -mov eax, dword ptr [esp + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0045b951  8b801c020000           -mov eax, dword ptr [eax + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 0045b957  833804                 +cmp dword ptr [eax], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045b95a  7516                   -jne 0x45b972
    if (!cpu.flags.zf)
    {
        goto L_0x0045b972;
    }
    // 0045b95c  83fb0e                 +cmp ebx, 0xe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045b95f  0f8513010000           -jne 0x45ba78
    if (!cpu.flags.zf)
    {
        goto L_0x0045ba78;
    }
    // 0045b965  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0045b96a:
    // 0045b96a  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0045b96d  e86e090000             -call 0x45c2e0
    cpu.esp -= 4;
    sub_45c2e0(app, cpu);
    if (cpu.terminate) return;
L_0x0045b972:
    // 0045b972  83fb10                 +cmp ebx, 0x10
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
    // 0045b975  0f8504010000           -jne 0x45ba7f
    if (!cpu.flags.zf)
    {
        goto L_0x0045ba7f;
    }
L_0x0045b97b:
    // 0045b97b  3b7904                 +cmp edi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045b97e  7428                   -je 0x45b9a8
    if (cpu.flags.zf)
    {
        goto L_0x0045b9a8;
    }
    // 0045b980  8b842408010000         -mov eax, dword ptr [esp + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0045b987  8b801c020000           -mov eax, dword ptr [eax + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 0045b98d  83380f                 +cmp dword ptr [eax], 0xf
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045b990  7d16                   -jge 0x45b9a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045b9a8;
    }
    // 0045b992  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045b995  0f85f2000000           -jne 0x45ba8d
    if (!cpu.flags.zf)
    {
        goto L_0x0045ba8d;
    }
    // 0045b99b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0045b9a0:
    // 0045b9a0  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0045b9a3  e8d8080000             -call 0x45c280
    cpu.esp -= 4;
    sub_45c280(app, cpu);
    if (cpu.terminate) return;
L_0x0045b9a8:
    // 0045b9a8  43                     -inc ebx
    (cpu.ebx)++;
    // 0045b9a9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045b9ac  83fb20                 +cmp ebx, 0x20
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045b9af  0f8c35ffffff           -jl 0x45b8ea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045b8ea;
    }
L_0x0045b9b5:
    // 0045b9b5  8b942408010000         -mov edx, dword ptr [esp + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0045b9bc  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0045b9c3  e8387f0000             -call 0x463900
    cpu.esp -= 4;
    sub_463900(app, cpu);
    if (cpu.terminate) return;
    // 0045b9c8  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0045b9cf  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0045b9d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045b9d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045b9d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045b9d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045b9d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045b9da:
    // 0045b9da  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0045b9e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045b9e2  8d8c2400010000         -lea ecx, [esp + 0x100]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0045b9e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045b9eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045b9ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045b9ee  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045b9f2  e8b5220300             -call 0x48dcac
    cpu.esp -= 4;
    sub_48dcac(app, cpu);
    if (cpu.terminate) return;
    // 0045b9f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045b9f9  0f84c9feffff           -je 0x45b8c8
    if (cpu.flags.zf)
    {
        goto L_0x0045b8c8;
    }
    // 0045b9ff  b9e8d14b00             -mov ecx, 0x4bd1e8
    cpu.ecx = 4968936 /*0x4bd1e8*/;
    // 0045ba04  bbde040000             -mov ebx, 0x4de
    cpu.ebx = 1246 /*0x4de*/;
    // 0045ba09  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0045ba10  b810d24b00             -mov eax, 0x4bd210
    cpu.eax = 4968976 /*0x4bd210*/;
    // 0045ba15  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 0045ba1b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045ba1d  890d78a64c00           -mov dword ptr [0x4ca678], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ecx;
    // 0045ba23  e800e80100             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0045ba28  8bb424fc000000         -mov esi, dword ptr [esp + 0xfc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0045ba2f  8b9c2400010000         -mov ebx, dword ptr [esp + 0x100]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0045ba36  8b0d48544c00           -mov ecx, dword ptr [0x4c5448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5002312) /* 0x4c5448 */);
    // 0045ba3c  8984240c010000         -mov dword ptr [esp + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.eax;
    // 0045ba43  01f1                   +add ecx, esi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045ba45  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045ba47  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045ba49  e8b25b0200             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0045ba4e  e975feffff             -jmp 0x45b8c8
    goto L_0x0045b8c8;
L_0x0045ba53:
    // 0045ba53  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045ba58  e8484a0300             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 0045ba5d  e953ffffff             -jmp 0x45b9b5
    goto L_0x0045b9b5;
L_0x0045ba62:
    // 0045ba62  6b0206                 +imul eax, dword ptr [edx], 6
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx))) * x86::sreg64(x86::sreg32(6 /*0x6*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0045ba65  e9b3feffff             -jmp 0x45b91d
    goto L_0x0045b91d;
L_0x0045ba6a:
    // 0045ba6a  83fb0e                 +cmp ebx, 0xe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ba6d  0f84d2feffff           -je 0x45b945
    if (cpu.flags.zf)
    {
        goto L_0x0045b945;
    }
    // 0045ba73  e9fafeffff             -jmp 0x45b972
    goto L_0x0045b972;
L_0x0045ba78:
    // 0045ba78  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ba7a  e9ebfeffff             -jmp 0x45b96a
    goto L_0x0045b96a;
L_0x0045ba7f:
    // 0045ba7f  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ba82  0f84f3feffff           -je 0x45b97b
    if (cpu.flags.zf)
    {
        goto L_0x0045b97b;
    }
    // 0045ba88  e91bffffff             -jmp 0x45b9a8
    goto L_0x0045b9a8;
L_0x0045ba8d:
    // 0045ba8d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ba8f  e90cffffff             -jmp 0x45b9a0
    goto L_0x0045b9a0;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45baa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045baa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045baa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045baa2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045baa3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045baa4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045baa6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045baa8  8b99e4020000           -mov ebx, dword ptr [ecx + 0x2e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(740) /* 0x2e4 */);
    // 0045baae  ba2a000000             -mov edx, 0x2a
    cpu.edx = 42 /*0x2a*/;
    // 0045bab3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045bab5  0f847f000000           -je 0x45bb3a
    if (cpu.flags.zf)
    {
        goto L_0x0045bb3a;
    }
    // 0045babb  8b811c020000           -mov eax, dword ptr [ecx + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(540) /* 0x21c */);
    // 0045bac1  833804                 +cmp dword ptr [eax], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bac4  0f8470000000           -je 0x45bb3a
    if (cpu.flags.zf)
    {
        goto L_0x0045bb3a;
    }
    // 0045baca  8b2d50215000           -mov ebp, dword ptr [0x502150]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5251408) /* 0x502150 */);
    // 0045bad0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045bad2  81fd00ceffff           +cmp ebp, 0xffffce00
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294954496 /*0xffffce00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bad8  0f8e81000000           -jle 0x45bb5f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bb5f;
    }
    // 0045bade  81fd00320000           +cmp ebp, 0x3200
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12800 /*0x3200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bae4  0f8d75000000           -jge 0x45bb5f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045bb5f;
    }
    // 0045baea  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045baec  7e6b                   -jle 0x45bb59
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bb59;
    }
    // 0045baee  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
L_0x0045baf0:
    // 0045baf0  a1600b4e00             -mov eax, dword ptr [0x4e0b60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114720) /* 0x4e0b60 */);
    // 0045baf5  e896e1fdff             -call 0x439c90
    cpu.esp -= 4;
    sub_439c90(app, cpu);
    if (cpu.terminate) return;
    // 0045bafa  83f807                 +cmp eax, 7
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
    // 0045bafd  7527                   -jne 0x45bb26
    if (!cpu.flags.zf)
    {
        goto L_0x0045bb26;
    }
    // 0045baff  83b9e402000000         +cmp dword ptr [ecx + 0x2e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(740) /* 0x2e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bb06  7e1e                   -jle 0x45bb26
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bb26;
    }
    // 0045bb08  8b811c020000           -mov eax, dword ptr [ecx + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(540) /* 0x21c */);
    // 0045bb0e  833807                 +cmp dword ptr [eax], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bb11  0f8579000000           -jne 0x45bb90
    if (!cpu.flags.zf)
    {
        goto L_0x0045bb90;
    }
    // 0045bb17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045bb19  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045bb1c  c1e202                 +shl edx, 2
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
    // 0045bb1f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bb21  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x0045bb24:
    // 0045bb24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0045bb26:
    // 0045bb26  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045bb28  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045bb2b  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045bb2e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bb30  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045bb33  83f82a                 +cmp eax, 0x2a
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
    // 0045bb36  7d63                   -jge 0x45bb9b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045bb9b;
    }
L_0x0045bb38:
    // 0045bb38  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0045bb3a:
    // 0045bb3a  0faf91e4020000         -imul edx, dword ptr [ecx + 0x2e4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(740) /* 0x2e4 */))));
    // 0045bb41  8d4620                 -lea eax, [esi + 0x20]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0045bb44  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045bb46  e825340300             -call 0x48ef70
    cpu.esp -= 4;
    sub_48ef70(app, cpu);
    if (cpu.terminate) return;
    // 0045bb4b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045bb4d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045bb4f  e86c000000             -call 0x45bbc0
    cpu.esp -= 4;
    sub_45bbc0(app, cpu);
    if (cpu.terminate) return;
    // 0045bb54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bb55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bb56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bb57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bb58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045bb59:
    // 0045bb59  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0045bb5b  f7da                   +neg edx
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
    // 0045bb5d  eb91                   -jmp 0x45baf0
    goto L_0x0045baf0;
L_0x0045bb5f:
    // 0045bb5f  8b1d50215000           -mov ebx, dword ptr [0x502150]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5251408) /* 0x502150 */);
    // 0045bb65  81fb00460000           +cmp ebx, 0x4600
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17920 /*0x4600*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bb6b  7e0c                   -jle 0x45bb79
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bb79;
    }
    // 0045bb6d  ba007f0000             -mov edx, 0x7f00
    cpu.edx = 32512 /*0x7f00*/;
    // 0045bb72  29da                   +sub edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045bb74  e977ffffff             -jmp 0x45baf0
    goto L_0x0045baf0;
L_0x0045bb79:
    // 0045bb79  81fb00baffff           +cmp ebx, 0xffffba00
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294949376 /*0xffffba00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bb7f  0f8d6bffffff           -jge 0x45baf0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045baf0;
    }
    // 0045bb85  8d93007f0000           -lea edx, [ebx + 0x7f00]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(32512) /* 0x7f00 */);
    // 0045bb8b  e960ffffff             -jmp 0x45baf0
    goto L_0x0045baf0;
L_0x0045bb90:
    // 0045bb90  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045bb92  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045bb95  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045bb97  d1f8                   +sar eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0045bb99  eb89                   -jmp 0x45bb24
    goto L_0x0045bb24;
L_0x0045bb9b:
    // 0045bb9b  b82a000000             -mov eax, 0x2a
    cpu.eax = 42 /*0x2a*/;
    // 0045bba0  eb96                   -jmp 0x45bb38
    goto L_0x0045bb38;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45bbb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045bbb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045bbb1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045bbb6  e805000000             -call 0x45bbc0
    cpu.esp -= 4;
    sub_45bbc0(app, cpu);
    if (cpu.terminate) return;
    // 0045bbbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bbbc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_45bbc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045bbc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045bbc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045bbc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045bbc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045bbc4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045bbc6  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045bbcb  8b0d1c894c00           -mov ecx, dword ptr [0x4c891c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5015836) /* 0x4c891c */);
    // 0045bbd1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045bbd3  39c8                   +cmp eax, ecx
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
    // 0045bbd5  0f84c3000000           -je 0x45bc9e
    if (cpu.flags.zf)
    {
        goto L_0x0045bc9e;
    }
    // 0045bbdb  81ba8006000000002c00   +cmp dword ptr [edx + 0x680], 0x2c0000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1664) /* 0x680 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2883584 /*0x2c0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bbe5  0f8ec2000000           -jle 0x45bcad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bcad;
    }
    // 0045bbeb  8b827c060000           -mov eax, dword ptr [edx + 0x67c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1660) /* 0x67c */);
    // 0045bbf1  3d66260000             +cmp eax, 0x2666
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9830 /*0x2666*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bbf6  0f8ea7000000           -jle 0x45bca3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bca3;
    }
    // 0045bbfc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0045bbfe:
    // 0045bbfe  81f98f020000           +cmp ecx, 0x28f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(655 /*0x28f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bc04  7e27                   -jle 0x45bc2d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bc2d;
    }
    // 0045bc06  8bba5c010000           -mov edi, dword ptr [edx + 0x15c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(348) /* 0x15c */);
    // 0045bc0c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045bc0e  0f8ea4000000           -jle 0x45bcb8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bcb8;
    }
    // 0045bc14  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0045bc16:
    // 0045bc16  058f020000             -add eax, 0x28f
    (cpu.eax) += x86::reg32(x86::sreg32(655 /*0x28f*/));
    // 0045bc1b  3d3d0a0000             +cmp eax, 0xa3d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2621 /*0xa3d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bc20  0f8e9b000000           -jle 0x45bcc1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bcc1;
    }
    // 0045bc26  b83d0a0000             -mov eax, 0xa3d
    cpu.eax = 2621 /*0xa3d*/;
L_0x0045bc2b:
    // 0045bc2b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0045bc2d:
    // 0045bc2d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045bc2f  0f84ba000000           -je 0x45bcef
    if (cpu.flags.zf)
    {
        goto L_0x0045bcef;
    }
    // 0045bc35  83baf402000000         +cmp dword ptr [edx + 0x2f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(756) /* 0x2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bc3c  740c                   -je 0x45bc4a
    if (cpu.flags.zf)
    {
        goto L_0x0045bc4a;
    }
    // 0045bc3e  81f933b30000           +cmp ecx, 0xb333
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45875 /*0xb333*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bc44  0f8e9b000000           -jle 0x45bce5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bce5;
    }
L_0x0045bc4a:
    // 0045bc4a  e8e12b0200             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 0045bc4f  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0045bc52  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045bc54  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bc56  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bc59  c1e810                 +shr eax, 0x10
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
    // 0045bc5c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bc5e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045bc60  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045bc63  c1e20c                 +shl edx, 0xc
    {
        x86::reg8 tmp = 12 /*0xc*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045bc66  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bc68  c1f80c                 -sar eax, 0xc
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (12 /*0xc*/ % 32));
    // 0045bc6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045bc6d  0f8e9f000000           -jle 0x45bd12
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bd12;
    }
    // 0045bc73  e8b82b0200             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 0045bc78  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0045bc7b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045bc7d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bc7f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bc82  c1e810                 +shr eax, 0x10
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
    // 0045bc85  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bc87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045bc89  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045bc8c  c1e20c                 +shl edx, 0xc
    {
        x86::reg8 tmp = 12 /*0xc*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045bc8f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bc91  c1f80c                 -sar eax, 0xc
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (12 /*0xc*/ % 32));
    // 0045bc94  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0045bc96  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045bc98  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
L_0x0045bc9e:
    // 0045bc9e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bc9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bca0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bca1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bca2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045bca3:
    // 0045bca3  b966260000             -mov ecx, 0x2666
    cpu.ecx = 9830 /*0x2666*/;
    // 0045bca8  e951ffffff             -jmp 0x45bbfe
    goto L_0x0045bbfe;
L_0x0045bcad:
    // 0045bcad  8b8a7c060000           -mov ecx, dword ptr [edx + 0x67c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1660) /* 0x67c */);
    // 0045bcb3  e946ffffff             -jmp 0x45bbfe
    goto L_0x0045bbfe;
L_0x0045bcb8:
    // 0045bcb8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045bcba  f7d8                   +neg eax
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
    // 0045bcbc  e955ffffff             -jmp 0x45bc16
    goto L_0x0045bc16;
L_0x0045bcc1:
    // 0045bcc1  8baa5c010000           -mov ebp, dword ptr [edx + 0x15c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(348) /* 0x15c */);
    // 0045bcc7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045bcc9  7e0c                   -jle 0x45bcd7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bcd7;
    }
    // 0045bccb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0045bccd  058f020000             +add eax, 0x28f
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(655 /*0x28f*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045bcd2  e954ffffff             -jmp 0x45bc2b
    goto L_0x0045bc2b;
L_0x0045bcd7:
    // 0045bcd7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0045bcd9  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0045bcdb  058f020000             +add eax, 0x28f
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(655 /*0x28f*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045bce0  e946ffffff             -jmp 0x45bc2b
    goto L_0x0045bc2b;
L_0x0045bce5:
    // 0045bce5  b933b30000             -mov ecx, 0xb333
    cpu.ecx = 45875 /*0xb333*/;
    // 0045bcea  e95bffffff             -jmp 0x45bc4a
    goto L_0x0045bc4a;
L_0x0045bcef:
    // 0045bcef  83baf802000000         +cmp dword ptr [edx + 0x2f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(760) /* 0x2f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bcf6  0f844effffff           -je 0x45bc4a
    if (cpu.flags.zf)
    {
        goto L_0x0045bc4a;
    }
    // 0045bcfc  81f933b30000           +cmp ecx, 0xb333
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45875 /*0xb333*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bd02  0f8f42ffffff           -jg 0x45bc4a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045bc4a;
    }
    // 0045bd08  b933b30000             -mov ecx, 0xb333
    cpu.ecx = 45875 /*0xb333*/;
    // 0045bd0d  e938ffffff             -jmp 0x45bc4a
    goto L_0x0045bc4a;
L_0x0045bd12:
    // 0045bd12  e8192b0200             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 0045bd17  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0045bd1a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045bd1c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bd1e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bd21  c1e810                 +shr eax, 0x10
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
    // 0045bd24  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bd26  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045bd28  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045bd2b  c1e20c                 +shl edx, 0xc
    {
        x86::reg8 tmp = 12 /*0xc*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045bd2e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bd30  c1f80c                 -sar eax, 0xc
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (12 /*0xc*/ % 32));
    // 0045bd33  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0045bd35  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0045bd37  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0045bd39  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0045bd3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bd40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bd41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bd42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bd43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45bd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045bd50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045bd51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045bd52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045bd53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045bd54  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0045bd57  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045bd59  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045bd5b  83ba8002000002         +cmp dword ptr [edx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bd62  0f8596010000           -jne 0x45befe
    if (!cpu.flags.zf)
    {
        goto L_0x0045befe;
    }
    // 0045bd68  81b9bc00000000000200   +cmp dword ptr [ecx + 0xbc], 0x20000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bd72  0f8d86010000           -jge 0x45befe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045befe;
    }
    // 0045bd78  c7816406000000000000   -mov dword ptr [ecx + 0x664], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1636) /* 0x664 */) = 0 /*0x0*/;
L_0x0045bd82:
    // 0045bd82  8b8164060000           -mov eax, dword ptr [ecx + 0x664]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1636) /* 0x664 */);
    // 0045bd88  3d00c0ffff             +cmp eax, 0xffffc000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294950912 /*0xffffc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bd8d  0f8e8a010000           -jle 0x45bf1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bf1d;
    }
L_0x0045bd93:
    // 0045bd93  8ba964060000           -mov ebp, dword ptr [ecx + 0x664]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1636) /* 0x664 */);
    // 0045bd99  81fd00400000           +cmp ebp, 0x4000
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bd9f  0f8d6e010000           -jge 0x45bf13
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045bf13;
    }
    // 0045bda5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0045bda7:
    // 0045bda7  898164060000           -mov dword ptr [ecx + 0x664], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1636) /* 0x664 */) = cpu.eax;
    // 0045bdad  8b8168060000           -mov eax, dword ptr [ecx + 0x668]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1640) /* 0x668 */);
    // 0045bdb3  3dcc4c0000             +cmp eax, 0x4ccc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bdb8  7d0b                   -jge 0x45bdc5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045bdc5;
    }
    // 0045bdba  3d34b3ffff             +cmp eax, 0xffffb334
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294947636 /*0xffffb334*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bdbf  0f8e6c010000           -jle 0x45bf31
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bf31;
    }
L_0x0045bdc5:
    // 0045bdc5  8b9168060000           -mov edx, dword ptr [ecx + 0x668]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1640) /* 0x668 */);
    // 0045bdcb  81facc4c0000           +cmp edx, 0x4ccc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bdd1  0f8d50010000           -jge 0x45bf27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045bf27;
    }
    // 0045bdd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0045bdd9:
    // 0045bdd9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045bddb  898168060000           -mov dword ptr [ecx + 0x668], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1640) /* 0x668 */) = cpu.eax;
    // 0045bde1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045bde3  e8e8310300             -call 0x48efd0
    cpu.esp -= 4;
    sub_48efd0(app, cpu);
    if (cpu.terminate) return;
    // 0045bde8  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0045bdec  8b9164060000           -mov edx, dword ptr [ecx + 0x664]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1636) /* 0x664 */);
    // 0045bdf2  8d5e20                 -lea ebx, [esi + 0x20]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0045bdf5  e816310300             -call 0x48ef10
    cpu.esp -= 4;
    sub_48ef10(app, cpu);
    if (cpu.terminate) return;
    // 0045bdfa  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0045bdfe  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045be00  e82b320300             -call 0x48f030
    cpu.esp -= 4;
    sub_48f030(app, cpu);
    if (cpu.terminate) return;
    // 0045be05  83b95c06000000         +cmp dword ptr [ecx + 0x65c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1628) /* 0x65c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045be0c  743e                   -je 0x45be4c
    if (cpu.flags.zf)
    {
        goto L_0x0045be4c;
    }
    // 0045be0e  80b9d802000000         +cmp byte ptr [ecx + 0x2d8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(728) /* 0x2d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045be15  0f8420010000           -je 0x45bf3b
    if (cpu.flags.zf)
    {
        goto L_0x0045bf3b;
    }
    // 0045be1b  c744244801000000       -mov dword ptr [esp + 0x48], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = 1 /*0x1*/;
L_0x0045be23:
    // 0045be23  8ba95c060000           -mov ebp, dword ptr [ecx + 0x65c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1628) /* 0x65c */);
    // 0045be29  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045be2b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045be2d  7e1d                   -jle 0x45be4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045be4c;
    }
    // 0045be2f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0045be31:
    // 0045be31  8bb04c060000           -mov esi, dword ptr [eax + 0x64c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1612) /* 0x64c */);
    // 0045be37  8a5c2448               -mov bl, byte ptr [esp + 0x48]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0045be3b  885e01                 -mov byte ptr [esi + 1], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0045be3e  42                     -inc edx
    (cpu.edx)++;
    // 0045be3f  8b995c060000           -mov ebx, dword ptr [ecx + 0x65c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1628) /* 0x65c */);
    // 0045be45  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045be48  39da                   +cmp edx, ebx
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
    // 0045be4a  7ce5                   -jl 0x45be31
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045be31;
    }
L_0x0045be4c:
    // 0045be4c  8bb1b8020000           -mov esi, dword ptr [ecx + 0x2b8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */);
    // 0045be52  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045be54  0f8eec000000           -jle 0x45bf46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bf46;
    }
    // 0045be5a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0045be5c:
    // 0045be5c  8b15c4f74f00           -mov edx, dword ptr [0x4ff7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045be62  3b151c894c00           +cmp edx, dword ptr [0x4c891c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5015836) /* 0x4c891c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045be68  7406                   -je 0x45be70
    if (cpu.flags.zf)
    {
        goto L_0x0045be70;
    }
    // 0045be6a  ff8148060000           -inc dword ptr [ecx + 0x648]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1608) /* 0x648 */))++;
L_0x0045be70:
    // 0045be70  3d00001400             +cmp eax, 0x140000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1310720 /*0x140000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045be75  0f8ed4000000           -jle 0x45bf4f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bf4f;
    }
    // 0045be7b  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x0045be80:
    // 0045be80  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0045be82:
    // 0045be82  83b9f402000000         +cmp dword ptr [ecx + 0x2f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(756) /* 0x2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045be89  7405                   -je 0x45be90
    if (cpu.flags.zf)
    {
        goto L_0x0045be90;
    }
    // 0045be8b  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
L_0x0045be90:
    // 0045be90  83b9f802000000         +cmp dword ptr [ecx + 0x2f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(760) /* 0x2f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045be97  7405                   -je 0x45be9e
    if (cpu.flags.zf)
    {
        goto L_0x0045be9e;
    }
    // 0045be99  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x0045be9e:
    // 0045be9e  83b98002000002         +cmp dword ptr [ecx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bea5  0f85f4000000           -jne 0x45bf9f
    if (!cpu.flags.zf)
    {
        goto L_0x0045bf9f;
    }
    // 0045beab  81b9bc00000000000200   +cmp dword ptr [ecx + 0xbc], 0x20000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045beb5  0f8de4000000           -jge 0x45bf9f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045bf9f;
    }
    // 0045bebb  c781fc02000003000000   -mov dword ptr [ecx + 0x2fc], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */) = 3 /*0x3*/;
L_0x0045bec5:
    // 0045bec5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045bec7:
    // 0045bec7  f681fc02000002         +test byte ptr [ecx + 0x2fc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(764) /* 0x2fc */) & 2 /*0x2*/));
    // 0045bece  7402                   -je 0x45bed2
    if (cpu.flags.zf)
    {
        goto L_0x0045bed2;
    }
    // 0045bed0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0045bed2:
    // 0045bed2  8b9938060000           -mov ebx, dword ptr [ecx + 0x638]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 0045bed8  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045bedb  8b993c060000           -mov ebx, dword ptr [ecx + 0x63c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1596) /* 0x63c */);
    // 0045bee1  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045bee4  8b8140060000           -mov eax, dword ptr [ecx + 0x640]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1600) /* 0x640 */);
    // 0045beea  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0045beed  8b8144060000           -mov eax, dword ptr [ecx + 0x644]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1604) /* 0x644 */);
    // 0045bef3  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0045bef6  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0045bef9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045befa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045befb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045befc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045befd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045befe:
    // 0045befe  81b96406000000400000   +cmp dword ptr [ecx + 0x664], 0x4000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1636) /* 0x664 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bf08  0f8c74feffff           -jl 0x45bd82
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045bd82;
    }
    // 0045bf0e  e980feffff             -jmp 0x45bd93
    goto L_0x0045bd93;
L_0x0045bf13:
    // 0045bf13  b800400000             -mov eax, 0x4000
    cpu.eax = 16384 /*0x4000*/;
    // 0045bf18  e98afeffff             -jmp 0x45bda7
    goto L_0x0045bda7;
L_0x0045bf1d:
    // 0045bf1d  b800c0ffff             -mov eax, 0xffffc000
    cpu.eax = 4294950912 /*0xffffc000*/;
    // 0045bf22  e980feffff             -jmp 0x45bda7
    goto L_0x0045bda7;
L_0x0045bf27:
    // 0045bf27  b8cc4c0000             -mov eax, 0x4ccc
    cpu.eax = 19660 /*0x4ccc*/;
    // 0045bf2c  e9a8feffff             -jmp 0x45bdd9
    goto L_0x0045bdd9;
L_0x0045bf31:
    // 0045bf31  b834b3ffff             -mov eax, 0xffffb334
    cpu.eax = 4294947636 /*0xffffb334*/;
    // 0045bf36  e99efeffff             -jmp 0x45bdd9
    goto L_0x0045bdd9;
L_0x0045bf3b:
    // 0045bf3b  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0045bf3d  89742448               -mov dword ptr [esp + 0x48], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.esi;
    // 0045bf41  e9ddfeffff             -jmp 0x45be23
    goto L_0x0045be23;
L_0x0045bf46:
    // 0045bf46  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045bf48  f7d8                   +neg eax
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
    // 0045bf4a  e90dffffff             -jmp 0x45be5c
    goto L_0x0045be5c;
L_0x0045bf4f:
    // 0045bf4f  3d00000700             +cmp eax, 0x70000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(458752 /*0x70000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bf54  7e0f                   -jle 0x45bf65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bf65;
    }
    // 0045bf56  8b8148060000           -mov eax, dword ptr [ecx + 0x648]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1608) /* 0x648 */);
    // 0045bf5c  83e001                 +and eax, 1
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0045bf5f  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045bf60  e91bffffff             -jmp 0x45be80
    goto L_0x0045be80;
L_0x0045bf65:
    // 0045bf65  3d00800200             +cmp eax, 0x28000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(163840 /*0x28000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bf6a  7e11                   -jle 0x45bf7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bf7d;
    }
    // 0045bf6c  8b8148060000           -mov eax, dword ptr [ecx + 0x648]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1608) /* 0x648 */);
    // 0045bf72  83e002                 -and eax, 2
    cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045bf75  d1f8                   +sar eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0045bf77  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045bf78  e903ffffff             -jmp 0x45be80
    goto L_0x0045be80;
L_0x0045bf7d:
    // 0045bf7d  3d33330000             +cmp eax, 0x3333
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13107 /*0x3333*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bf82  7e12                   -jle 0x45bf96
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bf96;
    }
    // 0045bf84  8b8148060000           -mov eax, dword ptr [ecx + 0x648]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1608) /* 0x648 */);
    // 0045bf8a  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045bf8d  c1f802                 +sar eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0045bf90  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045bf91  e9eafeffff             -jmp 0x45be80
    goto L_0x0045be80;
L_0x0045bf96:
    // 0045bf96  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045bf98  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045bf9a  e9e3feffff             -jmp 0x45be82
    goto L_0x0045be82;
L_0x0045bf9f:
    // 0045bf9f  83b9fc02000000         +cmp dword ptr [ecx + 0x2fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bfa6  0f8426ffffff           -je 0x45bed2
    if (cpu.flags.zf)
    {
        goto L_0x0045bed2;
    }
    // 0045bfac  f681fc02000001         +test byte ptr [ecx + 0x2fc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(764) /* 0x2fc */) & 1 /*0x1*/));
    // 0045bfb3  0f850cffffff           -jne 0x45bec5
    if (!cpu.flags.zf)
    {
        goto L_0x0045bec5;
    }
    // 0045bfb9  e909ffffff             -jmp 0x45bec7
    goto L_0x0045bec7;
}

/* align: skip 0x00 0x00 */
void Application::sub_45bfc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045bfc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045bfc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045bfc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045bfc3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045bfc6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045bfc8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045bfca  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045bfcf  8a818c000000           -mov al, byte ptr [ecx + 0x8c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 0045bfd5  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045bfd7  7519                   -jne 0x45bff2
    if (!cpu.flags.zf)
    {
        goto L_0x0045bff2;
    }
L_0x0045bfd9:
    // 0045bfd9  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 0045bfde  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045bfe1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045bfe3  e8686a0100             -call 0x472a50
    cpu.esp -= 4;
    sub_472a50(app, cpu);
    if (cpu.terminate) return;
    // 0045bfe8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0045bfeb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045bfee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bfef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bff0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bff1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045bff2:
    // 0045bff2  bbff030000             -mov ebx, 0x3ff
    cpu.ebx = 1023 /*0x3ff*/;
    // 0045bff7  bae8d14b00             -mov edx, 0x4bd1e8
    cpu.edx = 4968936 /*0x4bd1e8*/;
    // 0045bffc  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0045bfff  e88ccffdff             -call 0x438f90
    cpu.esp -= 4;
    sub_438f90(app, cpu);
    if (cpu.terminate) return;
    // 0045c004  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c006  74d1                   -je 0x45bfd9
    if (cpu.flags.zf)
    {
        goto L_0x0045bfd9;
    }
    // 0045c008  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0045c00b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045c00d  74ca                   -je 0x45bfd9
    if (cpu.flags.zf)
    {
        goto L_0x0045bfd9;
    }
    // 0045c00f  668b4202               -mov ax, word ptr [edx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0045c013  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0045c018  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045c01b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045c01d  e82e6a0100             -call 0x472a50
    cpu.esp -= 4;
    sub_472a50(app, cpu);
    if (cpu.terminate) return;
    // 0045c022  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0045c025  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c028  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c029  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c02a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c02b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_45c030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c031  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c032  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c033  81bab802000000002c00   +cmp dword ptr [edx + 0x2b8], 0x2c0000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(696) /* 0x2b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2883584 /*0x2c0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c03d  7e2c                   -jle 0x45c06b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c06b;
    }
    // 0045c03f  8bba60060000           -mov edi, dword ptr [edx + 0x660]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c045  81ff47210000           +cmp edi, 0x2147
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8519 /*0x2147*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c04b  7d0c                   -jge 0x45c059
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045c059;
    }
    // 0045c04d  8daf47010000           -lea ebp, [edi + 0x147]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(327) /* 0x147 */);
    // 0045c053  89aa60060000           -mov dword ptr [edx + 0x660], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */) = cpu.ebp;
L_0x0045c059:
    // 0045c059  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0045c05c  8b9260060000           -mov edx, dword ptr [edx + 0x660]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c062  e8a92e0300             -call 0x48ef10
    cpu.esp -= 4;
    sub_48ef10(app, cpu);
    if (cpu.terminate) return;
    // 0045c067  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c068  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c069  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c06a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c06b:
    // 0045c06b  8b9a60060000           -mov ebx, dword ptr [edx + 0x660]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c071  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045c073  7ee4                   -jle 0x45c059
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c059;
    }
    // 0045c075  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c076  8db3b9feffff           -lea esi, [ebx - 0x147]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-327) /* -0x147 */);
    // 0045c07c  89b260060000           -mov dword ptr [edx + 0x660], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */) = cpu.esi;
    // 0045c082  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c083  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0045c086  8b9260060000           -mov edx, dword ptr [edx + 0x660]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c08c  e87f2e0300             -call 0x48ef10
    cpu.esp -= 4;
    sub_48ef10(app, cpu);
    if (cpu.terminate) return;
    // 0045c091  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c092  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c093  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c094  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c0a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c0a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c0a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c0a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c0a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c0a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045c0a7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045c0a9  83ba6006000000         +cmp dword ptr [edx + 0x660], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c0b0  7e6b                   -jle 0x45c11d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c11d;
    }
    // 0045c0b2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0045c0b7:
    // 0045c0b7  8aa1f4010000           -mov ah, byte ptr [ecx + 0x1f4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(500) /* 0x1f4 */);
    // 0045c0bd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045c0bf  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 0045c0c2  7460                   -je 0x45c124
    if (cpu.flags.zf)
    {
        goto L_0x0045c124;
    }
    // 0045c0c4  8bb9f0020000           -mov edi, dword ptr [ecx + 0x2f0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(752) /* 0x2f0 */);
    // 0045c0ca  81ffe8030000           +cmp edi, 0x3e8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c0d0  7e64                   -jle 0x45c136
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c136;
    }
    // 0045c0d2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045c0d4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045c0d7  bf10270000             -mov edi, 0x2710
    cpu.edi = 10000 /*0x2710*/;
    // 0045c0dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c0de  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045c0e1  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c0e3  3d00000100             +cmp eax, 0x10000
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
    // 0045c0e8  7d45                   -jge 0x45c12f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045c12f;
    }
L_0x0045c0ea:
    // 0045c0ea  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 0045c0ef  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c0f1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c0f3  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0045c0f6  0faff0                 -imul esi, eax
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0045c0f9  89b160060000           -mov dword ptr [ecx + 0x660], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1632) /* 0x660 */) = cpu.esi;
L_0x0045c0ff:
    // 0045c0ff  8ba960060000           -mov ebp, dword ptr [ecx + 0x660]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1632) /* 0x660 */);
    // 0045c105  f7dd                   +neg ebp
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebp;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0045c107  8d4320                 -lea eax, [ebx + 0x20]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0045c10a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0045c10c  89a960060000           -mov dword ptr [ecx + 0x660], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1632) /* 0x660 */) = cpu.ebp;
    // 0045c112  e8b92e0300             -call 0x48efd0
    cpu.esp -= 4;
    sub_48efd0(app, cpu);
    if (cpu.terminate) return;
    // 0045c117  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c118  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c119  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c11a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c11b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c11c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c11d:
    // 0045c11d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0045c122  eb93                   -jmp 0x45c0b7
    goto L_0x0045c0b7;
L_0x0045c124:
    // 0045c124  c1e20b                 +shl edx, 0xb
    {
        x86::reg8 tmp = 11 /*0xb*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045c127  899160060000           -mov dword ptr [ecx + 0x660], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1632) /* 0x660 */) = cpu.edx;
    // 0045c12d  ebd0                   -jmp 0x45c0ff
    goto L_0x0045c0ff;
L_0x0045c12f:
    // 0045c12f  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0045c134  ebb4                   -jmp 0x45c0ea
    goto L_0x0045c0ea;
L_0x0045c136:
    // 0045c136  c7816006000000000000   -mov dword ptr [ecx + 0x660], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1632) /* 0x660 */) = 0 /*0x0*/;
    // 0045c140  ebbd                   -jmp 0x45c0ff
    goto L_0x0045c0ff;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c150  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c151  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c152  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c153  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c155  8b9ab8020000           -mov ebx, dword ptr [edx + 0x2b8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(696) /* 0x2b8 */);
    // 0045c15b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c15d  81fb00000a00           +cmp ebx, 0xa0000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(655360 /*0xa0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c163  7e1b                   -jle 0x45c180
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c180;
    }
    // 0045c165  81fb00004300           +cmp ebx, 0x430000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4390912 /*0x430000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c16b  7e05                   -jle 0x45c172
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c172;
    }
    // 0045c16d  b83d0a0000             -mov eax, 0xa3d
    cpu.eax = 2621 /*0xa3d*/;
L_0x0045c172:
    // 0045c172  80bad802000064         +cmp byte ptr [edx + 0x2d8], 0x64
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(728) /* 0x2d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045c179  7605                   -jbe 0x45c180
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045c180;
    }
    // 0045c17b  b87a140000             -mov eax, 0x147a
    cpu.eax = 5242 /*0x147a*/;
L_0x0045c180:
    // 0045c180  8d98b9feffff           -lea ebx, [eax - 0x147]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-327) /* -0x147 */);
    // 0045c186  8bba60060000           -mov edi, dword ptr [edx + 0x660]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c18c  39fb                   +cmp ebx, edi
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
    // 0045c18e  7f27                   -jg 0x45c1b7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045c1b7;
    }
    // 0045c190  0547010000             -add eax, 0x147
    (cpu.eax) += x86::reg32(x86::sreg32(327 /*0x147*/));
    // 0045c195  39f8                   +cmp eax, edi
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
    // 0045c197  7d0c                   -jge 0x45c1a5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045c1a5;
    }
    // 0045c199  8d8771fdffff           -lea eax, [edi - 0x28f]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-655) /* -0x28f */);
    // 0045c19f  898260060000           -mov dword ptr [edx + 0x660], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */) = cpu.eax;
L_0x0045c1a5:
    // 0045c1a5  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0045c1a8  8b9260060000           -mov edx, dword ptr [edx + 0x660]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c1ae  e85d2d0300             -call 0x48ef10
    cpu.esp -= 4;
    sub_48ef10(app, cpu);
    if (cpu.terminate) return;
    // 0045c1b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c1b7:
    // 0045c1b7  8d9f1e050000           -lea ebx, [edi + 0x51e]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1310) /* 0x51e */);
    // 0045c1bd  899a60060000           -mov dword ptr [edx + 0x660], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */) = cpu.ebx;
    // 0045c1c3  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0045c1c6  8b9260060000           -mov edx, dword ptr [edx + 0x660]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c1cc  e83f2d0300             -call 0x48ef10
    cpu.esp -= 4;
    sub_48ef10(app, cpu);
    if (cpu.terminate) return;
    // 0045c1d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c1e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c1e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c1e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c1e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c1e4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c1e6  8b9ab8020000           -mov ebx, dword ptr [edx + 0x2b8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(696) /* 0x2b8 */);
    // 0045c1ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c1ee  81fb00000e00           +cmp ebx, 0xe0000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(917504 /*0xe0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c1f4  7e15                   -jle 0x45c20b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c20b;
    }
    // 0045c1f6  8a9ad8020000           -mov bl, byte ptr [edx + 0x2d8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(728) /* 0x2d8 */);
    // 0045c1fc  b85c0f0000             -mov eax, 0xf5c
    cpu.eax = 3932 /*0xf5c*/;
    // 0045c201  80fb64                 +cmp bl, 0x64
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045c204  7605                   -jbe 0x45c20b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045c20b;
    }
    // 0045c206  b8f5280000             -mov eax, 0x28f5
    cpu.eax = 10485 /*0x28f5*/;
L_0x0045c20b:
    // 0045c20b  8d98b9feffff           -lea ebx, [eax - 0x147]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-327) /* -0x147 */);
    // 0045c211  8bb260060000           -mov esi, dword ptr [edx + 0x660]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c217  39f3                   +cmp ebx, esi
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
    // 0045c219  7f28                   -jg 0x45c243
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045c243;
    }
    // 0045c21b  0547010000             -add eax, 0x147
    (cpu.eax) += x86::reg32(x86::sreg32(327 /*0x147*/));
    // 0045c220  39f0                   +cmp eax, esi
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
    // 0045c222  7d0c                   -jge 0x45c230
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045c230;
    }
    // 0045c224  8daee2faffff           -lea ebp, [esi - 0x51e]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(-1310) /* -0x51e */);
    // 0045c22a  89aa60060000           -mov dword ptr [edx + 0x660], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */) = cpu.ebp;
L_0x0045c230:
    // 0045c230  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0045c233  8b9260060000           -mov edx, dword ptr [edx + 0x660]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c239  e8d22c0300             -call 0x48ef10
    cpu.esp -= 4;
    sub_48ef10(app, cpu);
    if (cpu.terminate) return;
    // 0045c23e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c23f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c240  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c241  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c242  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c243:
    // 0045c243  8d861e050000           -lea eax, [esi + 0x51e]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1310) /* 0x51e */);
    // 0045c249  898260060000           -mov dword ptr [edx + 0x660], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */) = cpu.eax;
    // 0045c24f  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0045c252  8b9260060000           -mov edx, dword ptr [edx + 0x660]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1632) /* 0x660 */);
    // 0045c258  e8b32c0300             -call 0x48ef10
    cpu.esp -= 4;
    sub_48ef10(app, cpu);
    if (cpu.terminate) return;
    // 0045c25d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c25e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c25f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c260  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c261  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c270  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0045c273  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045c275  e9962c0300             -jmp 0x48ef10
    return sub_48ef10(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c283  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c284  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0045c287  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0045c28a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c28c  7426                   -je 0x45c2b4
    if (cpu.flags.zf)
    {
        goto L_0x0045c2b4;
    }
    // 0045c28e  f60002                 +test byte ptr [eax], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 2 /*0x2*/));
    // 0045c291  7421                   -je 0x45c2b4
    if (cpu.flags.zf)
    {
        goto L_0x0045c2b4;
    }
    // 0045c293  8d5804                 -lea ebx, [eax + 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045c296  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045c298  741f                   -je 0x45c2b9
    if (cpu.flags.zf)
    {
        goto L_0x0045c2b9;
    }
L_0x0045c29a:
    // 0045c29a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c29c  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045c29f  6bd206                 -imul edx, edx, 6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(6 /*0x6*/)));
    // 0045c2a2  668b3c11               -mov di, word ptr [ecx + edx]
    cpu.di = app->getMemory<x86::reg16>(cpu.ecx + cpu.edx * 1);
    // 0045c2a6  83ef05                 -sub edi, 5
    (cpu.edi) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0045c2a9  40                     -inc eax
    (cpu.eax)++;
    // 0045c2aa  66893c11               -mov word ptr [ecx + edx], di
    app->getMemory<x86::reg16>(cpu.ecx + cpu.edx * 1) = cpu.di;
    // 0045c2ae  39d8                   +cmp eax, ebx
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
    // 0045c2b0  75e8                   -jne 0x45c29a
    if (!cpu.flags.zf)
    {
        goto L_0x0045c29a;
    }
    // 0045c2b2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0045c2b4:
    // 0045c2b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c2b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c2b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c2b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c2b8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c2b9:
    // 0045c2b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c2bb  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045c2be  6bd206                 -imul edx, edx, 6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(6 /*0x6*/)));
    // 0045c2c1  668b3411               -mov si, word ptr [ecx + edx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + cpu.edx * 1);
    // 0045c2c5  83c605                 -add esi, 5
    (cpu.esi) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0045c2c8  40                     -inc eax
    (cpu.eax)++;
    // 0045c2c9  66893411               -mov word ptr [ecx + edx], si
    app->getMemory<x86::reg16>(cpu.ecx + cpu.edx * 1) = cpu.si;
    // 0045c2cd  39d8                   +cmp eax, ebx
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
    // 0045c2cf  75e8                   -jne 0x45c2b9
    if (!cpu.flags.zf)
    {
        goto L_0x0045c2b9;
    }
    // 0045c2d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c2d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c2d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c2d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c2d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c2e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c2e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c2e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c2e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c2e4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045c2e6  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0045c2e9  8b5814                 -mov ebx, dword ptr [eax + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0045c2ec  8d7204                 -lea esi, [edx + 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0045c2ef  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c2f1  7423                   -je 0x45c316
    if (cpu.flags.zf)
    {
        goto L_0x0045c316;
    }
L_0x0045c2f3:
    // 0045c2f3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c2f5  8a4a04                 -mov cl, byte ptr [edx + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0045c2f8  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0045c2ff  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c301  668b3c43               -mov di, word ptr [ebx + eax*2]
    cpu.di = app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2);
    // 0045c305  83ef05                 -sub edi, 5
    (cpu.edi) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0045c308  42                     -inc edx
    (cpu.edx)++;
    // 0045c309  66893c43               -mov word ptr [ebx + eax*2], di
    app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2) = cpu.di;
    // 0045c30d  39f2                   +cmp edx, esi
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
    // 0045c30f  75e2                   -jne 0x45c2f3
    if (!cpu.flags.zf)
    {
        goto L_0x0045c2f3;
    }
    // 0045c311  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c312  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c313  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c314  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c315  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c316:
    // 0045c316  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c318  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0045c31b  6bc006                 -imul eax, eax, 6
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(6 /*0x6*/)));
    // 0045c31e  668b0c03               -mov cx, word ptr [ebx + eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 1);
    // 0045c322  83c105                 -add ecx, 5
    (cpu.ecx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0045c325  42                     -inc edx
    (cpu.edx)++;
    // 0045c326  66890c03               -mov word ptr [ebx + eax], cx
    app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 1) = cpu.cx;
    // 0045c32a  39f2                   +cmp edx, esi
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
    // 0045c32c  75e8                   -jne 0x45c316
    if (!cpu.flags.zf)
    {
        goto L_0x0045c316;
    }
    // 0045c32e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c32f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c330  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c331  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c332  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c340  e90b3e0100             -jmp 0x470150
    return sub_470150(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c350  e88b180000             -call 0x45dbe0
    cpu.esp -= 4;
    sub_45dbe0(app, cpu);
    if (cpu.terminate) return;
    // 0045c355  e9063e0100             -jmp 0x470160
    return sub_470160(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c360  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c361  a1540b4e00             -mov eax, dword ptr [0x4e0b54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114708) /* 0x4e0b54 */);
    // 0045c366  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c368  e8e37d0100             -call 0x474150
    cpu.esp -= 4;
    sub_474150(app, cpu);
    if (cpu.terminate) return;
    // 0045c36d  8915540b4e00           -mov dword ptr [0x4e0b54], edx
    app->getMemory<x86::reg32>(x86::reg32(5114708) /* 0x4e0b54 */) = cpu.edx;
    // 0045c373  e878140100             -call 0x46d7f0
    cpu.esp -= 4;
    sub_46d7f0(app, cpu);
    if (cpu.terminate) return;
    // 0045c378  e8f33d0100             -call 0x470170
    cpu.esp -= 4;
    sub_470170(app, cpu);
    if (cpu.terminate) return;
    // 0045c37d  e8ae8a0100             -call 0x474e30
    cpu.esp -= 4;
    sub_474e30(app, cpu);
    if (cpu.terminate) return;
    // 0045c382  e8e94a0000             -call 0x460e70
    cpu.esp -= 4;
    sub_460e70(app, cpu);
    if (cpu.terminate) return;
    // 0045c387  e8e4290100             -call 0x46ed70
    cpu.esp -= 4;
    sub_46ed70(app, cpu);
    if (cpu.terminate) return;
    // 0045c38c  e83f610000             -call 0x4624d0
    cpu.esp -= 4;
    sub_4624d0(app, cpu);
    if (cpu.terminate) return;
    // 0045c391  e81ae1feff             -call 0x44a4b0
    cpu.esp -= 4;
    sub_44a4b0(app, cpu);
    if (cpu.terminate) return;
    // 0045c396  e8c5b8feff             -call 0x447c60
    cpu.esp -= 4;
    sub_447c60(app, cpu);
    if (cpu.terminate) return;
    // 0045c39b  e8b0b8feff             -call 0x447c50
    cpu.esp -= 4;
    sub_447c50(app, cpu);
    if (cpu.terminate) return;
    // 0045c3a0  e84b1a0000             -call 0x45ddf0
    cpu.esp -= 4;
    sub_45ddf0(app, cpu);
    if (cpu.terminate) return;
    // 0045c3a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c3a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c3b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c3b1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c3b3  e8988a0100             -call 0x474e50
    cpu.esp -= 4;
    sub_474e50(app, cpu);
    if (cpu.terminate) return;
    // 0045c3b8  8915500b4e00           -mov dword ptr [0x4e0b50], edx
    app->getMemory<x86::reg32>(x86::reg32(5114704) /* 0x4e0b50 */) = cpu.edx;
    // 0045c3be  e8ed050000             -call 0x45c9b0
    cpu.esp -= 4;
    sub_45c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0045c3c3  e8f83d0100             -call 0x4701c0
    cpu.esp -= 4;
    sub_4701c0(app, cpu);
    if (cpu.terminate) return;
    // 0045c3c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c3c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c3d0  e8db3d0100             -call 0x4701b0
    cpu.esp -= 4;
    sub_4701b0(app, cpu);
    if (cpu.terminate) return;
    // 0045c3d5  e83610feff             -call 0x43d410
    cpu.esp -= 4;
    sub_43d410(app, cpu);
    if (cpu.terminate) return;
    // 0045c3da  e8a1290100             -call 0x46ed80
    cpu.esp -= 4;
    sub_46ed80(app, cpu);
    if (cpu.terminate) return;
    // 0045c3df  e89c4a0000             -call 0x460e80
    cpu.esp -= 4;
    sub_460e80(app, cpu);
    if (cpu.terminate) return;
    // 0045c3e4  e9f7600000             -jmp 0x4624e0
    return sub_4624e0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c3f0  e8bb3e0100             -call 0x4702b0
    cpu.esp -= 4;
    sub_4702b0(app, cpu);
    if (cpu.terminate) return;
    // 0045c3f5  e8768a0100             -call 0x474e70
    cpu.esp -= 4;
    sub_474e70(app, cpu);
    if (cpu.terminate) return;
    // 0045c3fa  e84111feff             -call 0x43d540
    cpu.esp -= 4;
    sub_43d540(app, cpu);
    if (cpu.terminate) return;
    // 0045c3ff  e89c4a0000             -call 0x460ea0
    cpu.esp -= 4;
    sub_460ea0(app, cpu);
    if (cpu.terminate) return;
    // 0045c404  e887290100             -call 0x46ed90
    cpu.esp -= 4;
    sub_46ed90(app, cpu);
    if (cpu.terminate) return;
    // 0045c409  e8e2600000             -call 0x4624f0
    cpu.esp -= 4;
    sub_4624f0(app, cpu);
    if (cpu.terminate) return;
    // 0045c40e  e87db9feff             -call 0x447d90
    cpu.esp -= 4;
    sub_447d90(app, cpu);
    if (cpu.terminate) return;
    // 0045c413  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0045c418  e853ef0000             -call 0x46b370
    cpu.esp -= 4;
    sub_46b370(app, cpu);
    if (cpu.terminate) return;
    // 0045c41d  e84eb9feff             -call 0x447d70
    cpu.esp -= 4;
    sub_447d70(app, cpu);
    if (cpu.terminate) return;
    // 0045c422  e899e0feff             -call 0x44a4c0
    cpu.esp -= 4;
    sub_44a4c0(app, cpu);
    if (cpu.terminate) return;
    // 0045c427  e9e4190000             -jmp 0x45de10
    return sub_45de10(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_45c430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c430  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c431  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045c436  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c438  e803ddfeff             -call 0x44a140
    cpu.esp -= 4;
    sub_44a140(app, cpu);
    if (cpu.terminate) return;
    // 0045c43d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c43f  741c                   -je 0x45c45d
    if (cpu.flags.zf)
    {
        goto L_0x0045c45d;
    }
    // 0045c441  8b15d48b4c00           -mov edx, dword ptr [0x4c8bd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016532) /* 0x4c8bd4 */);
    // 0045c447  42                     -inc edx
    (cpu.edx)++;
    // 0045c448  8915d48b4c00           -mov dword ptr [0x4c8bd4], edx
    app->getMemory<x86::reg32>(x86::reg32(5016532) /* 0x4c8bd4 */) = cpu.edx;
    // 0045c44e  83fa01                 +cmp edx, 1
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
    // 0045c451  7e0a                   -jle 0x45c45d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c45d;
    }
    // 0045c453  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c454  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c456  891dd48b4c00           -mov dword ptr [0x4c8bd4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5016532) /* 0x4c8bd4 */) = cpu.ebx;
    // 0045c45c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045c45d:
    // 0045c45d  e8ce10feff             -call 0x43d530
    cpu.esp -= 4;
    sub_43d530(app, cpu);
    if (cpu.terminate) return;
    // 0045c462  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c463  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045c476  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c478  7438                   -je 0x45c4b2
    if (cpu.flags.zf)
    {
        goto L_0x0045c4b2;
    }
    // 0045c47a  833d500b4e0000         +cmp dword ptr [0x4e0b50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5114704) /* 0x4e0b50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c481  7519                   -jne 0x45c49c
    if (!cpu.flags.zf)
    {
        goto L_0x0045c49c;
    }
    // 0045c483  c705500b4e0001000000   -mov dword ptr [0x4e0b50], 1
    app->getMemory<x86::reg32>(x86::reg32(5114704) /* 0x4e0b50 */) = 1 /*0x1*/;
    // 0045c48d  e89e7c0100             -call 0x474130
    cpu.esp -= 4;
    sub_474130(app, cpu);
    if (cpu.terminate) return;
    // 0045c492  e8790cffff             -call 0x44d110
    cpu.esp -= 4;
    sub_44d110(app, cpu);
    if (cpu.terminate) return;
    // 0045c497  e894380100             -call 0x46fd30
    cpu.esp -= 4;
    sub_46fd30(app, cpu);
    if (cpu.terminate) return;
L_0x0045c49c:
    // 0045c49c  e86f380100             -call 0x46fd10
    cpu.esp -= 4;
    sub_46fd10(app, cpu);
    if (cpu.terminate) return;
    // 0045c4a1  e8ca0dffff             -call 0x44d270
    cpu.esp -= 4;
    sub_44d270(app, cpu);
    if (cpu.terminate) return;
    // 0045c4a6  e845380100             -call 0x46fcf0
    cpu.esp -= 4;
    sub_46fcf0(app, cpu);
    if (cpu.terminate) return;
    // 0045c4ab  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045c4ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c4af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c4b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c4b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c4b2:
    // 0045c4b2  8b15500b4e00           -mov edx, dword ptr [0x4e0b50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114704) /* 0x4e0b50 */);
    // 0045c4b8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045c4ba  0f859b000000           -jne 0x45c55b
    if (!cpu.flags.zf)
    {
        goto L_0x0045c55b;
    }
    // 0045c4c0  833d28f54d0001         +cmp dword ptr [0x4df528], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c4c7  0f84a9000000           -je 0x45c576
    if (cpu.flags.zf)
    {
        goto L_0x0045c576;
    }
    // 0045c4cd  e89ea6fdff             -call 0x436b70
    cpu.esp -= 4;
    sub_436b70(app, cpu);
    if (cpu.terminate) return;
    // 0045c4d2  e8994a0000             -call 0x460f70
    cpu.esp -= 4;
    sub_460f70(app, cpu);
    if (cpu.terminate) return;
    // 0045c4d7  e8b4410100             -call 0x470690
    cpu.esp -= 4;
    sub_470690(app, cpu);
    if (cpu.terminate) return;
    // 0045c4dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c4dd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c4df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c4e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c4e3  e818010000             -call 0x45c600
    cpu.esp -= 4;
    sub_45c600(app, cpu);
    if (cpu.terminate) return;
    // 0045c4e8  833dd48b4c0000         +cmp dword ptr [0x4c8bd4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5016532) /* 0x4c8bd4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c4ef  7535                   -jne 0x45c526
    if (!cpu.flags.zf)
    {
        goto L_0x0045c526;
    }
    // 0045c4f1  833db4f34d0000         +cmp dword ptr [0x4df3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108660) /* 0x4df3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c4f8  742c                   -je 0x45c526
    if (cpu.flags.zf)
    {
        goto L_0x0045c526;
    }
    // 0045c4fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c4fb  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045c4ff  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c503  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045c507  e8e4910000             -call 0x4656f0
    cpu.esp -= 4;
    sub_4656f0(app, cpu);
    if (cpu.terminate) return;
    // 0045c50c  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045c510  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c514  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045c518  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c519  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045c51e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c520  e8db000000             -call 0x45c600
    cpu.esp -= 4;
    sub_45c600(app, cpu);
    if (cpu.terminate) return;
    // 0045c525  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045c526:
    // 0045c526  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045c528  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0045c52d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c52f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c531  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c533  e8c8000000             -call 0x45c600
    cpu.esp -= 4;
    sub_45c600(app, cpu);
    if (cpu.terminate) return;
    // 0045c538  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045c53a  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0045c53f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c541  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c543  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c545  e8b6000000             -call 0x45c600
    cpu.esp -= 4;
    sub_45c600(app, cpu);
    if (cpu.terminate) return;
    // 0045c54a  e8a1430100             -call 0x4708f0
    cpu.esp -= 4;
    sub_4708f0(app, cpu);
    if (cpu.terminate) return;
    // 0045c54f  e82c3e0100             -call 0x470380
    cpu.esp -= 4;
    sub_470380(app, cpu);
    if (cpu.terminate) return;
    // 0045c554  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045c557  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c558  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c559  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c55a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c55b:
    // 0045c55b  a3500b4e00             -mov dword ptr [0x4e0b50], eax
    app->getMemory<x86::reg32>(x86::reg32(5114704) /* 0x4e0b50 */) = cpu.eax;
    // 0045c560  e89b0bffff             -call 0x44d100
    cpu.esp -= 4;
    sub_44d100(app, cpu);
    if (cpu.terminate) return;
    // 0045c565  e8b6370100             -call 0x46fd20
    cpu.esp -= 4;
    sub_46fd20(app, cpu);
    if (cpu.terminate) return;
    // 0045c56a  e8d17b0100             -call 0x474140
    cpu.esp -= 4;
    sub_474140(app, cpu);
    if (cpu.terminate) return;
    // 0045c56f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045c572  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c573  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c574  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c575  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c576:
    // 0045c576  e8f5a5fdff             -call 0x436b70
    cpu.esp -= 4;
    sub_436b70(app, cpu);
    if (cpu.terminate) return;
    // 0045c57b  e8f0490000             -call 0x460f70
    cpu.esp -= 4;
    sub_460f70(app, cpu);
    if (cpu.terminate) return;
    // 0045c580  e80b410100             -call 0x470690
    cpu.esp -= 4;
    sub_470690(app, cpu);
    if (cpu.terminate) return;
    // 0045c585  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c586  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c588  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c58a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c58c  e86f000000             -call 0x45c600
    cpu.esp -= 4;
    sub_45c600(app, cpu);
    if (cpu.terminate) return;
    // 0045c591  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045c593  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045c598  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c59a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c59c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c59e  e85d000000             -call 0x45c600
    cpu.esp -= 4;
    sub_45c600(app, cpu);
    if (cpu.terminate) return;
    // 0045c5a3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045c5a5  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0045c5aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c5ac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c5ae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c5b0  e84b000000             -call 0x45c600
    cpu.esp -= 4;
    sub_45c600(app, cpu);
    if (cpu.terminate) return;
    // 0045c5b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045c5b7  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0045c5bc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c5be  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c5c0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c5c2  e839000000             -call 0x45c600
    cpu.esp -= 4;
    sub_45c600(app, cpu);
    if (cpu.terminate) return;
    // 0045c5c7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045c5c9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045c5ce  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0045c5d3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c5d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c5d7  e824000000             -call 0x45c600
    cpu.esp -= 4;
    sub_45c600(app, cpu);
    if (cpu.terminate) return;
    // 0045c5dc  e80f430100             -call 0x4708f0
    cpu.esp -= 4;
    sub_4708f0(app, cpu);
    if (cpu.terminate) return;
    // 0045c5e1  e89a3d0100             -call 0x470380
    cpu.esp -= 4;
    sub_470380(app, cpu);
    if (cpu.terminate) return;
    // 0045c5e6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045c5e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c5ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c5eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c5ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_45c600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0045c600  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c601  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c602  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c605  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045c607  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045c609  a1540b4e00             -mov eax, dword ptr [0x4e0b54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114708) /* 0x4e0b54 */);
    // 0045c60e  89355c0b4e00           -mov dword ptr [0x4e0b5c], esi
    app->getMemory<x86::reg32>(x86::reg32(5114716) /* 0x4e0b5c */) = cpu.esi;
    // 0045c614  8915600b4e00           -mov dword ptr [0x4e0b60], edx
    app->getMemory<x86::reg32>(x86::reg32(5114720) /* 0x4e0b60 */) = cpu.edx;
    // 0045c61a  891dc40b4e00           -mov dword ptr [0x4e0bc4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114820) /* 0x4e0bc4 */) = cpu.ebx;
    // 0045c620  a3580b4e00             -mov dword ptr [0x4e0b58], eax
    app->getMemory<x86::reg32>(x86::reg32(5114712) /* 0x4e0b58 */) = cpu.eax;
    // 0045c625  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045c629  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c62b  a3cc0b4e00             -mov dword ptr [0x4e0bcc], eax
    app->getMemory<x86::reg32>(x86::reg32(5114828) /* 0x4e0bcc */) = cpu.eax;
    // 0045c630  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c635  890dc80b4e00           -mov dword ptr [0x4e0bc8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114824) /* 0x4e0bc8 */) = cpu.ecx;
    // 0045c63b  e8e00dfeff             -call 0x43d420
    cpu.esp -= 4;
    sub_43d420(app, cpu);
    if (cpu.terminate) return;
    // 0045c640  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c643  7718                   -ja 0x45c65d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045c65d;
    }
    // 0045c645  ff24b5f0c54500         -jmp dword ptr [esi*4 + 0x45c5f0]
    cpu.ip = app->getMemory<x86::reg32>(4572656 + cpu.esi * 4); goto dynamic_jump;
  case 0x0045c64c:
    // 0045c64c  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c651  e82aa3fdff             -call 0x436980
    cpu.esp -= 4;
    sub_436980(app, cpu);
    if (cpu.terminate) return;
    // 0045c656  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045c658  e863000000             -call 0x45c6c0
    cpu.esp -= 4;
    sub_45c6c0(app, cpu);
    if (cpu.terminate) return;
L_0x0045c65d:
    // 0045c65d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0045c662  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c667  e8b40dfeff             -call 0x43d420
    cpu.esp -= 4;
    sub_43d420(app, cpu);
    if (cpu.terminate) return;
    // 0045c66c  8b15400b4e00           -mov edx, dword ptr [0x4e0b40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114688) /* 0x4e0b40 */);
    // 0045c672  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c673  8b0d3c0b4e00           -mov ecx, dword ptr [0x4e0b3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114684) /* 0x4e0b3c */);
    // 0045c679  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c67a  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c67f  e81c420100             -call 0x4708a0
    cpu.esp -= 4;
    sub_4708a0(app, cpu);
    if (cpu.terminate) return;
    // 0045c684  83c410                 +add esp, 0x10
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
    // 0045c687  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c688  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c689  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0045c68c:
    // 0045c68c  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c691  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c693  bf3c0b4e00             -mov edi, 0x4e0b3c
    cpu.edi = 5114684 /*0x4e0b3c*/;
    // 0045c698  e8f3a9feff             -call 0x447090
    cpu.esp -= 4;
    sub_447090(app, cpu);
    if (cpu.terminate) return;
    // 0045c69d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c69f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c6a0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c6a1  ebba                   -jmp 0x45c65d
    goto L_0x0045c65d;
  case 0x0045c6a3:
    // 0045c6a3  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c6a7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045c6a9  e852abfeff             -call 0x447200
    cpu.esp -= 4;
    sub_447200(app, cpu);
    if (cpu.terminate) return;
    // 0045c6ae  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c6b2  bf3c0b4e00             -mov edi, 0x4e0b3c
    cpu.edi = 5114684 /*0x4e0b3c*/;
    // 0045c6b7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c6b8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c6b9  eba2                   -jmp 0x45c65d
    goto L_0x0045c65d;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c6c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c6c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c6c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c6c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c6c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c6c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c6c6  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0045c6c9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c6cb  e8a01b0000             -call 0x45e270
    cpu.esp -= 4;
    sub_45e270(app, cpu);
    if (cpu.terminate) return;
    // 0045c6d0  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c6d5  e816480100             -call 0x470ef0
    cpu.esp -= 4;
    sub_470ef0(app, cpu);
    if (cpu.terminate) return;
    // 0045c6da  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c6df  e86ca3fdff             -call 0x436a50
    cpu.esp -= 4;
    sub_436a50(app, cpu);
    if (cpu.terminate) return;
    // 0045c6e4  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c6e9  e8d2470000             -call 0x460ec0
    cpu.esp -= 4;
    sub_460ec0(app, cpu);
    if (cpu.terminate) return;
    // 0045c6ee  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c6f3  e878d7ffff             -call 0x459e70
    cpu.esp -= 4;
    sub_459e70(app, cpu);
    if (cpu.terminate) return;
    // 0045c6f8  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c6fd  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c6ff  e8dc260100             -call 0x46ede0
    cpu.esp -= 4;
    sub_46ede0(app, cpu);
    if (cpu.terminate) return;
    // 0045c704  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c709  bf3c0b4e00             -mov edi, 0x4e0b3c
    cpu.edi = 5114684 /*0x4e0b3c*/;
    // 0045c70e  e8bdddfeff             -call 0x44a4d0
    cpu.esp -= 4;
    sub_44a4d0(app, cpu);
    if (cpu.terminate) return;
    // 0045c713  e868170000             -call 0x45de80
    cpu.esp -= 4;
    sub_45de80(app, cpu);
    if (cpu.terminate) return;
    // 0045c718  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c71a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045c71f  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c724  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c725  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c726  e8f50cfeff             -call 0x43d420
    cpu.esp -= 4;
    sub_43d420(app, cpu);
    if (cpu.terminate) return;
    // 0045c72b  8b15400b4e00           -mov edx, dword ptr [0x4e0b40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114688) /* 0x4e0b40 */);
    // 0045c731  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c732  8b1d3c0b4e00           -mov ebx, dword ptr [0x4e0b3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114684) /* 0x4e0b3c */);
    // 0045c738  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c739  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c73e  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045c742  e8f9d5feff             -call 0x449d40
    cpu.esp -= 4;
    sub_449d40(app, cpu);
    if (cpu.terminate) return;
    // 0045c747  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c74b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c74c  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c750  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c751  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045c755  e816010000             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 0045c75a  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045c75e  bf3c0b4e00             -mov edi, 0x4e0b3c
    cpu.edi = 5114684 /*0x4e0b3c*/;
    // 0045c763  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c764  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c765  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c768  740a                   -je 0x45c774
    if (cpu.flags.zf)
    {
        goto L_0x0045c774;
    }
    // 0045c76a  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0045c76d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c76e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c76f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c770  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c771  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c772  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c773  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c774:
    // 0045c774  b85c0b4e00             -mov eax, 0x4e0b5c
    cpu.eax = 5114716 /*0x4e0b5c*/;
    // 0045c779  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045c77d  e80e8b0100             -call 0x475290
    cpu.esp -= 4;
    sub_475290(app, cpu);
    if (cpu.terminate) return;
    // 0045c782  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045c786  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c787  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045c78b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045c78c  8b15400b4e00           -mov edx, dword ptr [0x4e0b40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114688) /* 0x4e0b40 */);
    // 0045c792  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c793  8b0d3c0b4e00           -mov ecx, dword ptr [0x4e0b3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114684) /* 0x4e0b3c */);
    // 0045c799  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c79a  8d742430               -lea esi, [esp + 0x30]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0045c79e  bf3c0b4e00             -mov edi, 0x4e0b3c
    cpu.edi = 5114684 /*0x4e0b3c*/;
    // 0045c7a3  e8c8000000             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 0045c7a8  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045c7ac  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c7ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c7ae  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0045c7b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c7c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c7c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c7c2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c7c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045c7c7  8b154c0b4e00           -mov edx, dword ptr [0x4e0b4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114700) /* 0x4e0b4c */);
    // 0045c7cd  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0045c7d0  8b15480b4e00           -mov edx, dword ptr [0x4e0b48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114696) /* 0x4e0b48 */);
    // 0045c7d6  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0045c7da  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045c7dc  750c                   -jne 0x45c7ea
    if (!cpu.flags.zf)
    {
        goto L_0x0045c7ea;
    }
    // 0045c7de  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c7e0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045c7e2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c7e3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c7e4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c7e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c7ea:
    // 0045c7ea  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0045c7f0  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c7f2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045c7f4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c7f5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c7f6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c7f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c7fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_45c800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c800  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c801  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c803  e868010000             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 0045c808  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c80a  741e                   -je 0x45c82a
    if (cpu.flags.zf)
    {
        goto L_0x0045c82a;
    }
    // 0045c80c  833d4c0b4e0000         +cmp dword ptr [0x4e0b4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5114700) /* 0x4e0b4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c813  7417                   -je 0x45c82c
    if (cpu.flags.zf)
    {
        goto L_0x0045c82c;
    }
    // 0045c815  a1480b4e00             -mov eax, dword ptr [0x4e0b48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114696) /* 0x4e0b48 */);
    // 0045c81a  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0045c81c  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0045c81e  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0045c820  a3480b4e00             -mov dword ptr [0x4e0b48], eax
    app->getMemory<x86::reg32>(x86::reg32(5114696) /* 0x4e0b48 */) = cpu.eax;
    // 0045c825  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0045c82a:
    // 0045c82a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c82b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c82c:
    // 0045c82c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0045c82e  a34c0b4e00             -mov dword ptr [0x4e0b4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5114700) /* 0x4e0b4c */) = cpu.eax;
    // 0045c833  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0045c835  a3480b4e00             -mov dword ptr [0x4e0b48], eax
    app->getMemory<x86::reg32>(x86::reg32(5114696) /* 0x4e0b48 */) = cpu.eax;
    // 0045c83a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045c83f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c840  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c850  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c851  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c853  8915480b4e00           -mov dword ptr [0x4e0b48], edx
    app->getMemory<x86::reg32>(x86::reg32(5114696) /* 0x4e0b48 */) = cpu.edx;
    // 0045c859  89154c0b4e00           -mov dword ptr [0x4e0b4c], edx
    app->getMemory<x86::reg32>(x86::reg32(5114700) /* 0x4e0b4c */) = cpu.edx;
    // 0045c85f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c860  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c871  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c872  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c873  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c876  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045c878  837c241800             +cmp dword ptr [esp + 0x18], 0
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
    // 0045c87d  7421                   -je 0x45c8a0
    if (cpu.flags.zf)
    {
        goto L_0x0045c8a0;
    }
    // 0045c87f  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045c883  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045c885  7521                   -jne 0x45c8a8
    if (!cpu.flags.zf)
    {
        goto L_0x0045c8a8;
    }
    // 0045c887  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0045c889  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0045c88d:
    // 0045c88d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c88e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c88f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c891  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045c893  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c894  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c895  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c897  83c408                 +add esp, 8
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
    // 0045c89a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c89b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c89c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c89d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0045c8a0:
    // 0045c8a0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0045c8a2  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045c8a6  ebe5                   -jmp 0x45c88d
    goto L_0x0045c88d;
L_0x0045c8a8:
    // 0045c8a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c8a9  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0045c8ad  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045c8b1  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045c8b5  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045c8b9  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0045c8bd  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0045c8bf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c8c0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c8c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8c2  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c8c4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045c8c6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c8c7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c8c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c8ca  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c8cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8d0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c8e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c8e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c8e2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c8e5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045c8e7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045c8ea  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045c8ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c8f0  750e                   -jne 0x45c900
    if (!cpu.flags.zf)
    {
        goto L_0x0045c900;
    }
    // 0045c8f2  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c8f4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045c8f6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c8f7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c8f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c8fa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c8fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c900:
    // 0045c900  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0045c906  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c908  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045c90a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c90b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c90c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c90e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c911  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c912  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c913  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c920  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c921  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c922  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c925  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045c927  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0045c929  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c92b  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c92d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0045c931  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0045c934  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c935  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c936  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c939  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c93a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c93b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_45c940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c940  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c941  8b15580b4e00           -mov edx, dword ptr [0x4e0b58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114712) /* 0x4e0b58 */);
    // 0045c947  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0045c949  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c94b  8b15540b4e00           -mov edx, dword ptr [0x4e0b54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114708) /* 0x4e0b54 */);
    // 0045c951  8b0d440b4e00           -mov ecx, dword ptr [0x4e0b44]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114692) /* 0x4e0b44 */);
    // 0045c957  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c959  39c8                   +cmp eax, ecx
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
    // 0045c95b  7e04                   -jle 0x45c961
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c961;
    }
    // 0045c95d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c95f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c960  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c961:
    // 0045c961  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045c966  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c967  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c972  8b1d580b4e00           -mov ebx, dword ptr [0x4e0b58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114712) /* 0x4e0b58 */);
    // 0045c978  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0045c97a  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045c97c  8b15540b4e00           -mov edx, dword ptr [0x4e0b54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114708) /* 0x4e0b54 */);
    // 0045c982  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045c984  8b0d440b4e00           -mov ecx, dword ptr [0x4e0b44]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114692) /* 0x4e0b44 */);
    // 0045c98a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c98c  39c8                   +cmp eax, ecx
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
    // 0045c98e  7e0b                   -jle 0x45c99b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c99b;
    }
    // 0045c990  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c992  891d580b4e00           -mov dword ptr [0x4e0b58], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114712) /* 0x4e0b58 */) = cpu.ebx;
    // 0045c998  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c999  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c99a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c99b:
    // 0045c99b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045c9a0  891d580b4e00           -mov dword ptr [0x4e0b58], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114712) /* 0x4e0b58 */) = cpu.ebx;
    // 0045c9a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c9a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c9a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c9b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c9b1  b8440b4e00             -mov eax, 0x4e0b44
    cpu.eax = 5114692 /*0x4e0b44*/;
    // 0045c9b6  e8a5770100             -call 0x474160
    cpu.esp -= 4;
    sub_474160(app, cpu);
    if (cpu.terminate) return;
    // 0045c9bb  8b15440b4e00           -mov edx, dword ptr [0x4e0b44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114692) /* 0x4e0b44 */);
    // 0045c9c1  a3540b4e00             -mov dword ptr [0x4e0b54], eax
    app->getMemory<x86::reg32>(x86::reg32(5114708) /* 0x4e0b54 */) = cpu.eax;
    // 0045c9c6  83ea64                 -sub edx, 0x64
    (cpu.edx) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0045c9c9  a3580b4e00             -mov dword ptr [0x4e0b58], eax
    app->getMemory<x86::reg32>(x86::reg32(5114712) /* 0x4e0b58 */) = cpu.eax;
    // 0045c9ce  8915440b4e00           -mov dword ptr [0x4e0b44], edx
    app->getMemory<x86::reg32>(x86::reg32(5114692) /* 0x4e0b44 */) = cpu.edx;
    // 0045c9d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c9d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c9e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c9e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c9e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c9e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c9e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c9e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c9e6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c9e8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045c9eb  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c9ed  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045c9f0  8b35c4f74f00           -mov esi, dword ptr [0x4ff7c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045c9f6  8b9040104e00           -mov edx, dword ptr [eax + 0x4e1040]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115968) /* 0x4e1040 */);
    // 0045c9fc  81ee00020000           -sub esi, 0x200
    (cpu.esi) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045ca02  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045ca04  0f85d1000000           -jne 0x45cadb
    if (!cpu.flags.zf)
    {
        goto L_0x0045cadb;
    }
    // 0045ca0a  8b803c104e00           -mov eax, dword ptr [eax + 0x4e103c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115964) /* 0x4e103c */);
    // 0045ca10  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045ca13  8b98008c4c00           -mov ebx, dword ptr [eax + 0x4c8c00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5016576) /* 0x4c8c00 */);
    // 0045ca19  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ca1c  0f85c0000000           -jne 0x45cae2
    if (!cpu.flags.zf)
    {
        goto L_0x0045cae2;
    }
L_0x0045ca22:
    // 0045ca22  ba80020000             -mov edx, 0x280
    cpu.edx = 640 /*0x280*/;
L_0x0045ca27:
    // 0045ca27  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0045ca2e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045ca30  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045ca33  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0045ca35  2b9834104e00           -sub ebx, dword ptr [eax + 0x4e1034]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115956) /* 0x4e1034 */)));
    // 0045ca3b  39d3                   +cmp ebx, edx
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
    // 0045ca3d  0f8e98000000           -jle 0x45cadb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045cadb;
    }
    // 0045ca43  8b803c104e00           -mov eax, dword ptr [eax + 0x4e103c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115964) /* 0x4e103c */);
    // 0045ca49  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045ca4c  8b90008c4c00           -mov edx, dword ptr [eax + 0x4c8c00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5016576) /* 0x4c8c00 */);
    // 0045ca52  83fa06                 +cmp edx, 6
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
    // 0045ca55  7405                   -je 0x45ca5c
    if (cpu.flags.zf)
    {
        goto L_0x0045ca5c;
    }
    // 0045ca57  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ca5a  7514                   -jne 0x45ca70
    if (!cpu.flags.zf)
    {
        goto L_0x0045ca70;
    }
L_0x0045ca5c:
    // 0045ca5c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0045ca63  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045ca65  c7048540104e0001000000 -mov dword ptr [eax*4 + 0x4e1040], 1
    app->getMemory<x86::reg32>(x86::reg32(5115968) /* 0x4e1040 */ + cpu.eax * 4) = 1 /*0x1*/;
L_0x0045ca70:
    // 0045ca70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045ca72  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045ca75  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045ca77  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045ca7a  8b80d4514c00           -mov eax, dword ptr [eax + 0x4c51d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5001684) /* 0x4c51d4 */);
    // 0045ca80  83b88802000000         +cmp dword ptr [eax + 0x288], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(648) /* 0x288 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ca87  746c                   -je 0x45caf5
    if (cpu.flags.zf)
    {
        goto L_0x0045caf5;
    }
    // 0045ca89  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0045ca8e  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0045ca95  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045ca97  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045ca99  8915048c4c00           -mov dword ptr [0x4c8c04], edx
    app->getMemory<x86::reg32>(x86::reg32(5016580) /* 0x4c8c04 */) = cpu.edx;
    // 0045ca9f  8915108c4c00           -mov dword ptr [0x4c8c10], edx
    app->getMemory<x86::reg32>(x86::reg32(5016592) /* 0x4c8c10 */) = cpu.edx;
    // 0045caa5  89348540104e00         -mov dword ptr [eax*4 + 0x4e1040], esi
    app->getMemory<x86::reg32>(x86::reg32(5115968) /* 0x4e1040 */ + cpu.eax * 4) = cpu.esi;
L_0x0045caac:
    // 0045caac  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0045cab3  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045cab5  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0045cab8  8b933c104e00           -mov edx, dword ptr [ebx + 0x4e103c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5115964) /* 0x4e103c */);
    // 0045cabe  42                     -inc edx
    (cpu.edx)++;
    // 0045cabf  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0045cac4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045cac6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045cac9  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045cacb  8bbb40104e00           -mov edi, dword ptr [ebx + 0x4e1040]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5115968) /* 0x4e1040 */);
    // 0045cad1  89933c104e00           -mov dword ptr [ebx + 0x4e103c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5115964) /* 0x4e103c */) = cpu.edx;
    // 0045cad7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045cad9  742d                   -je 0x45cb08
    if (cpu.flags.zf)
    {
        goto L_0x0045cb08;
    }
L_0x0045cadb:
    // 0045cadb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cadc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cadd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cade  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cadf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cae0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cae1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cae2:
    // 0045cae2  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cae5  0f8437ffffff           -je 0x45ca22
    if (cpu.flags.zf)
    {
        goto L_0x0045ca22;
    }
    // 0045caeb  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0045caf0  e932ffffff             -jmp 0x45ca27
    goto L_0x0045ca27;
L_0x0045caf5:
    // 0045caf5  bd06000000             -mov ebp, 6
    cpu.ebp = 6 /*0x6*/;
    // 0045cafa  892d048c4c00           -mov dword ptr [0x4c8c04], ebp
    app->getMemory<x86::reg32>(x86::reg32(5016580) /* 0x4c8c04 */) = cpu.ebp;
    // 0045cb00  892d108c4c00           -mov dword ptr [0x4c8c10], ebp
    app->getMemory<x86::reg32>(x86::reg32(5016592) /* 0x4c8c10 */) = cpu.ebp;
    // 0045cb06  eba4                   -jmp 0x45caac
    goto L_0x0045caac;
L_0x0045cb08:
    // 0045cb08  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cb0a  e811000000             -call 0x45cb20
    cpu.esp -= 4;
    sub_45cb20(app, cpu);
    if (cpu.terminate) return;
    // 0045cb0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45cb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045cb20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045cb21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045cb22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045cb23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045cb24  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045cb26  833d14f64f0002         +cmp dword ptr [0x4ff614], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cb2d  7528                   -jne 0x45cb57
    if (!cpu.flags.zf)
    {
        goto L_0x0045cb57;
    }
    // 0045cb2f  e82b2c0300             -call 0x48f75f
    cpu.esp -= 4;
    sub_48f75f(app, cpu);
    if (cpu.terminate) return;
    // 0045cb34  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045cb36  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045cb39  c1e20b                 +shl edx, 0xb
    {
        x86::reg8 tmp = 11 /*0xb*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045cb3c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045cb3e  c1f80b                 -sar eax, 0xb
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (11 /*0xb*/ % 32));
    // 0045cb41  83f804                 +cmp eax, 4
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
    // 0045cb44  7d6e                   -jge 0x45cbb4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045cbb4;
    }
    // 0045cb46  83f802                 +cmp eax, 2
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
    // 0045cb49  7d62                   -jge 0x45cbad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045cbad;
    }
    // 0045cb4b  ba7a540000             -mov edx, 0x547a
    cpu.edx = 21626 /*0x547a*/;
L_0x0045cb50:
    // 0045cb50  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0045cb52:
    // 0045cb52  e889cdfdff             -call 0x4398e0
    cpu.esp -= 4;
    sub_4398e0(app, cpu);
    if (cpu.terminate) return;
L_0x0045cb57:
    // 0045cb57  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0045cb5e  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045cb60  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0045cb63  8b933c104e00           -mov edx, dword ptr [ebx + 0x4e103c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5115964) /* 0x4e103c */);
    // 0045cb69  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cb6b  8b1495008c4c00         -mov edx, dword ptr [edx*4 + 0x4c8c00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016576) /* 0x4c8c00 */ + cpu.edx * 4);
    // 0045cb72  e869d0fdff             -call 0x439be0
    cpu.esp -= 4;
    sub_439be0(app, cpu);
    if (cpu.terminate) return;
    // 0045cb77  8b833c104e00           -mov eax, dword ptr [ebx + 0x4e103c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5115964) /* 0x4e103c */);
    // 0045cb7d  833c85008c4c0006       +cmp dword ptr [eax*4 + 0x4c8c00], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5016576) /* 0x4c8c00 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cb85  7433                   -je 0x45cbba
    if (cpu.flags.zf)
    {
        goto L_0x0045cbba;
    }
L_0x0045cb87:
    // 0045cb87  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cb89  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0045cb8c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045cb8e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045cb90  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045cb95  89348d40104e00         -mov dword ptr [ecx*4 + 0x4e1040], esi
    app->getMemory<x86::reg32>(x86::reg32(5115968) /* 0x4e1040 */ + cpu.ecx * 4) = cpu.esi;
    // 0045cb9c  2d00020000             +sub eax, 0x200
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045cba1  89048d34104e00         -mov dword ptr [ecx*4 + 0x4e1034], eax
    app->getMemory<x86::reg32>(x86::reg32(5115956) /* 0x4e1034 */ + cpu.ecx * 4) = cpu.eax;
    // 0045cba8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cba9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cbad:
    // 0045cbad  ba86abffff             -mov edx, 0xffffab86
    cpu.edx = 4294945670 /*0xffffab86*/;
    // 0045cbb2  eb9c                   -jmp 0x45cb50
    goto L_0x0045cb50;
L_0x0045cbb4:
    // 0045cbb4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cbb6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045cbb8  eb98                   -jmp 0x45cb52
    goto L_0x0045cb52;
L_0x0045cbba:
    // 0045cbba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cbbc  e87feefdff             -call 0x43ba40
    cpu.esp -= 4;
    sub_43ba40(app, cpu);
    if (cpu.terminate) return;
    // 0045cbc1  ebc4                   -jmp 0x45cb87
    goto L_0x0045cb87;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45cbe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0045cbe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045cbe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045cbe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045cbe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045cbe4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045cbe5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045cbe6  a11c104e00             -mov eax, dword ptr [0x4e101c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
    // 0045cbeb  8b1485dc8b4c00         -mov edx, dword ptr [eax*4 + 0x4c8bdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016540) /* 0x4c8bdc */ + cpu.eax * 4);
    // 0045cbf2  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045cbf7  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cbfa  7513                   -jne 0x45cc0f
    if (!cpu.flags.zf)
    {
        goto L_0x0045cc0f;
    }
    // 0045cbfc  803ddc514c0007         +cmp byte ptr [0x4c51dc], 7
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5001692) /* 0x4c51dc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045cc03  750a                   -jne 0x45cc0f
    if (!cpu.flags.zf)
    {
        goto L_0x0045cc0f;
    }
    // 0045cc05  c7051c104e0004000000   -mov dword ptr [0x4e101c], 4
    app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */) = 4 /*0x4*/;
L_0x0045cc0f:
    // 0045cc0f  833d28f54d0001         +cmp dword ptr [0x4df528], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cc16  7505                   -jne 0x45cc1d
    if (!cpu.flags.zf)
    {
        goto L_0x0045cc1d;
    }
    // 0045cc18  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x0045cc1d:
    // 0045cc1d  8b3d2c104e00           -mov edi, dword ptr [0x4e102c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5115948) /* 0x4e102c */);
    // 0045cc23  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045cc25  7e5b                   -jle 0x45cc82
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045cc82;
    }
    // 0045cc27  833d28104e0000         +cmp dword ptr [0x4e1028], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115944) /* 0x4e1028 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cc2e  7452                   -je 0x45cc82
    if (cpu.flags.zf)
    {
        goto L_0x0045cc82;
    }
    // 0045cc30  893d1c104e00           -mov dword ptr [0x4e101c], edi
    app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */) = cpu.edi;
    // 0045cc36  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045cc38  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045cc3a  7e46                   -jle 0x45cc82
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045cc82;
    }
    // 0045cc3c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045cc3e:
    // 0045cc3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045cc40  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045cc42  898330104e00           -mov dword ptr [ebx + 0x4e1030], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5115952) /* 0x4e1030 */) = cpu.eax;
    // 0045cc48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cc4a  e891ccfdff             -call 0x4398e0
    cpu.esp -= 4;
    sub_4398e0(app, cpu);
    if (cpu.terminate) return;
    // 0045cc4f  8b151c104e00           -mov edx, dword ptr [0x4e101c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
    // 0045cc55  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cc57  8b1495dc8b4c00         -mov edx, dword ptr [edx*4 + 0x4c8bdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016540) /* 0x4c8bdc */ + cpu.edx * 4);
    // 0045cc5e  e87dcffdff             -call 0x439be0
    cpu.esp -= 4;
    sub_439be0(app, cpu);
    if (cpu.terminate) return;
    // 0045cc63  8b151c104e00           -mov edx, dword ptr [0x4e101c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
    // 0045cc69  833c95dc8b4c0006       +cmp dword ptr [edx*4 + 0x4c8bdc], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5016540) /* 0x4c8bdc */ + cpu.edx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cc71  7507                   -jne 0x45cc7a
    if (!cpu.flags.zf)
    {
        goto L_0x0045cc7a;
    }
    // 0045cc73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cc75  e8c6edfdff             -call 0x43ba40
    cpu.esp -= 4;
    sub_43ba40(app, cpu);
    if (cpu.terminate) return;
L_0x0045cc7a:
    // 0045cc7a  41                     -inc ecx
    (cpu.ecx)++;
    // 0045cc7b  83c314                 -add ebx, 0x14
    (cpu.ebx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045cc7e  39f1                   +cmp ecx, esi
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
    // 0045cc80  7cbc                   -jl 0x45cc3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045cc3e;
    }
L_0x0045cc82:
    // 0045cc82  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045cc84  a124104e00             -mov eax, dword ptr [0x4e1024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115940) /* 0x4e1024 */);
    // 0045cc89  892d28104e00           -mov dword ptr [0x4e1028], ebp
    app->getMemory<x86::reg32>(x86::reg32(5115944) /* 0x4e1028 */) = cpu.ebp;
    // 0045cc8f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045cc91  7e1d                   -jle 0x45ccb0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ccb0;
    }
    // 0045cc93  48                     -dec eax
    (cpu.eax)--;
L_0x0045cc94:
    // 0045cc94  a324104e00             -mov dword ptr [0x4e1024], eax
    app->getMemory<x86::reg32>(x86::reg32(5115940) /* 0x4e1024 */) = cpu.eax;
    // 0045cc99  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0045cc9c:
    // 0045cc9c  833dacf74f0000         +cmp dword ptr [0x4ff7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cca3  0f8519020000           -jne 0x45cec2
    if (!cpu.flags.zf)
    {
        goto L_0x0045cec2;
    }
    // 0045cca9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ccaa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ccab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ccac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ccad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ccae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ccaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ccb0:
    // 0045ccb0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045ccb5  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0045ccba  e821d4feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ccbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ccc1  7427                   -je 0x45ccea
    if (cpu.flags.zf)
    {
        goto L_0x0045ccea;
    }
    // 0045ccc3  8b3d20104e00           -mov edi, dword ptr [0x4e1020]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5115936) /* 0x4e1020 */);
    // 0045ccc9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045cccb  7ecf                   -jle 0x45cc9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045cc9c;
    }
    // 0045cccd  8d6fff                 -lea ebp, [edi - 1]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 0045ccd0  892d20104e00           -mov dword ptr [0x4e1020], ebp
    app->getMemory<x86::reg32>(x86::reg32(5115936) /* 0x4e1020 */) = cpu.ebp;
    // 0045ccd6  833dacf74f0000         +cmp dword ptr [0x4ff7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ccdd  0f85df010000           -jne 0x45cec2
    if (!cpu.flags.zf)
    {
        goto L_0x0045cec2;
    }
    // 0045cce3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cce4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cce5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cce6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cce7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cce8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cce9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ccea:
    // 0045ccea  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045ccef  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0045ccf4  e8e7d3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ccf9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ccfb  7428                   -je 0x45cd25
    if (cpu.flags.zf)
    {
        goto L_0x0045cd25;
    }
    // 0045ccfd  8b1d20104e00           -mov ebx, dword ptr [0x4e1020]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5115936) /* 0x4e1020 */);
    // 0045cd03  83fb03                 +cmp ebx, 3
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
    // 0045cd06  7d94                   -jge 0x45cc9c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045cc9c;
    }
    // 0045cd08  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0045cd0b  893520104e00           -mov dword ptr [0x4e1020], esi
    app->getMemory<x86::reg32>(x86::reg32(5115936) /* 0x4e1020 */) = cpu.esi;
    // 0045cd11  833dacf74f0000         +cmp dword ptr [0x4ff7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cd18  0f85a4010000           -jne 0x45cec2
    if (!cpu.flags.zf)
    {
        goto L_0x0045cec2;
    }
    // 0045cd1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd21  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cd25:
    // 0045cd25  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045cd2a  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0045cd2f  e8acd3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045cd34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045cd36  0f8460ffffff           -je 0x45cc9c
    if (cpu.flags.zf)
    {
        goto L_0x0045cc9c;
    }
    // 0045cd3c  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0045cd41  a120104e00             -mov eax, dword ptr [0x4e1020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115936) /* 0x4e1020 */);
    // 0045cd46  891524104e00           -mov dword ptr [0x4e1024], edx
    app->getMemory<x86::reg32>(x86::reg32(5115940) /* 0x4e1024 */) = cpu.edx;
    // 0045cd4c  83f803                 +cmp eax, 3
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
    // 0045cd4f  0f8747ffffff           -ja 0x45cc9c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045cc9c;
    }
    // 0045cd55  ff2485d0cb4500         -jmp dword ptr [eax*4 + 0x45cbd0]
    cpu.ip = app->getMemory<x86::reg32>(4574160 + cpu.eax * 4); goto dynamic_jump;
  case 0x0045cd5c:
    // 0045cd5c  803510104e0001         -xor byte ptr [0x4e1010], 1
    app->getMemory<x86::reg8>(x86::reg32(5115920) /* 0x4e1010 */) ^= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0045cd63  833dacf74f0000         +cmp dword ptr [0x4ff7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cd6a  0f8552010000           -jne 0x45cec2
    if (!cpu.flags.zf)
    {
        goto L_0x0045cec2;
    }
    // 0045cd70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd76  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045cd77:
    // 0045cd77  8b1514104e00           -mov edx, dword ptr [0x4e1014]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */);
    // 0045cd7d  8b0d28f54d00           -mov ecx, dword ptr [0x4df528]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0045cd83  42                     -inc edx
    (cpu.edx)++;
    // 0045cd84  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cd87  7526                   -jne 0x45cdaf
    if (!cpu.flags.zf)
    {
        goto L_0x0045cdaf;
    }
    // 0045cd89  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0045cd8e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045cd90  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045cd93  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045cd95  891514104e00           -mov dword ptr [0x4e1014], edx
    app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */) = cpu.edx;
    // 0045cd9b  833dacf74f0000         +cmp dword ptr [0x4ff7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cda2  0f851a010000           -jne 0x45cec2
    if (!cpu.flags.zf)
    {
        goto L_0x0045cec2;
    }
    // 0045cda8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cda9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cdaf:
    // 0045cdaf  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045cdb4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045cdb6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045cdb9  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045cdbb  891514104e00           -mov dword ptr [0x4e1014], edx
    app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */) = cpu.edx;
    // 0045cdc1  833dacf74f0000         +cmp dword ptr [0x4ff7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cdc8  0f85f4000000           -jne 0x45cec2
    if (!cpu.flags.zf)
    {
        goto L_0x0045cec2;
    }
    // 0045cdce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdcf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdd1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdd3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cdd4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045cdd5:
    // 0045cdd5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045cdda  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 0045cddf  891518104e00           -mov dword ptr [0x4e1018], edx
    app->getMemory<x86::reg32>(x86::reg32(5115928) /* 0x4e1018 */) = cpu.edx;
    // 0045cde5  e9aafeffff             -jmp 0x45cc94
    goto L_0x0045cc94;
  case 0x0045cdea:
    // 0045cdea  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0045cdef  8b1d28f54d00           -mov ebx, dword ptr [0x4df528]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0045cdf5  890d28104e00           -mov dword ptr [0x4e1028], ecx
    app->getMemory<x86::reg32>(x86::reg32(5115944) /* 0x4e1028 */) = cpu.ecx;
    // 0045cdfb  39cb                   +cmp ebx, ecx
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
    // 0045cdfd  741b                   -je 0x45ce1a
    if (cpu.flags.zf)
    {
        goto L_0x0045ce1a;
    }
    // 0045cdff  a12cf54d00             -mov eax, dword ptr [0x4df52c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 0045ce04  8b048528f04d00         -mov eax, dword ptr [eax*4 + 0x4df028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107752) /* 0x4df028 */ + cpu.eax * 4);
    // 0045ce0b  8b801c020000           -mov eax, dword ptr [eax + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 0045ce11  83380f                 +cmp dword ptr [eax], 0xf
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ce14  0f8c96000000           -jl 0x45ceb0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045ceb0;
    }
L_0x0045ce1a:
    // 0045ce1a  8b151c104e00           -mov edx, dword ptr [0x4e101c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
    // 0045ce20  42                     -inc edx
    (cpu.edx)++;
    // 0045ce21  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
L_0x0045ce26:
    // 0045ce26  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045ce28  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045ce2b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045ce2d  89151c104e00           -mov dword ptr [0x4e101c], edx
    app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */) = cpu.edx;
    // 0045ce33  a11c104e00             -mov eax, dword ptr [0x4e101c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
    // 0045ce38  8b2c85dc8b4c00         -mov ebp, dword ptr [eax*4 + 0x4c8bdc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5016540) /* 0x4c8bdc */ + cpu.eax * 4);
    // 0045ce3f  a32c104e00             -mov dword ptr [0x4e102c], eax
    app->getMemory<x86::reg32>(x86::reg32(5115948) /* 0x4e102c */) = cpu.eax;
    // 0045ce44  83fd0a                 +cmp ebp, 0xa
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ce47  0f854ffeffff           -jne 0x45cc9c
    if (!cpu.flags.zf)
    {
        goto L_0x0045cc9c;
    }
    // 0045ce4d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045ce4f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045ce51  0f8e45feffff           -jle 0x45cc9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045cc9c;
    }
    // 0045ce57  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045ce59:
    // 0045ce59  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045ce5c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045ce61  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045ce63  89911c104e00           -mov dword ptr [ecx + 0x4e101c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5115932) /* 0x4e101c */) = cpu.edx;
    // 0045ce69  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045ce6b  89b924104e00           -mov dword ptr [ecx + 0x4e1024], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5115940) /* 0x4e1024 */) = cpu.edi;
    // 0045ce71  8b15c4f74f00           -mov edx, dword ptr [0x4ff7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045ce77  89b928104e00           -mov dword ptr [ecx + 0x4e1028], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5115944) /* 0x4e1028 */) = cpu.edi;
    // 0045ce7d  81ea00020000           -sub edx, 0x200
    (cpu.edx) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045ce83  43                     -inc ebx
    (cpu.ebx)++;
    // 0045ce84  899120104e00           -mov dword ptr [ecx + 0x4e1020], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5115936) /* 0x4e1020 */) = cpu.edx;
    // 0045ce8a  8b14bd008c4c00         -mov edx, dword ptr [edi*4 + 0x4c8c00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016576) /* 0x4c8c00 */ + cpu.edi * 4);
    // 0045ce91  89b92c104e00           -mov dword ptr [ecx + 0x4e102c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5115948) /* 0x4e102c */) = cpu.edi;
    // 0045ce97  e844cdfdff             -call 0x439be0
    cpu.esp -= 4;
    sub_439be0(app, cpu);
    if (cpu.terminate) return;
    // 0045ce9c  39f3                   +cmp ebx, esi
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
    // 0045ce9e  7cb9                   -jl 0x45ce59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045ce59;
    }
    // 0045cea0  833dacf74f0000         +cmp dword ptr [0x4ff7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cea7  7519                   -jne 0x45cec2
    if (!cpu.flags.zf)
    {
        goto L_0x0045cec2;
    }
    // 0045cea9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ceaa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ceab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ceac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cead  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ceae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ceaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ceb0:
    // 0045ceb0  8b151c104e00           -mov edx, dword ptr [0x4e101c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
    // 0045ceb6  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045ceb8  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0045cebd  e964ffffff             -jmp 0x45ce26
    goto L_0x0045ce26;
L_0x0045cec2:
    // 0045cec2  e82de2fdff             -call 0x43b0f4
    cpu.esp -= 4;
    sub_43b0f4(app, cpu);
    if (cpu.terminate) return;
    // 0045cec7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cec8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cec9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ceca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cecb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cecc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cecd  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_45ced0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ced0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ced1  8b1514f64f00           -mov edx, dword ptr [0x4ff614]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
    // 0045ced7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045ced9  7405                   -je 0x45cee0
    if (cpu.flags.zf)
    {
        goto L_0x0045cee0;
    }
    // 0045cedb  83fa01                 +cmp edx, 1
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
    // 0045cede  750d                   -jne 0x45ceed
    if (!cpu.flags.zf)
    {
        goto L_0x0045ceed;
    }
L_0x0045cee0:
    // 0045cee0  8b80ec010000           -mov eax, dword ptr [eax + 0x1ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(492) /* 0x1ec */);
    // 0045cee6  e885020000             -call 0x45d170
    cpu.esp -= 4;
    sub_45d170(app, cpu);
    if (cpu.terminate) return;
    // 0045ceeb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ceec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ceed:
    // 0045ceed  8b80ec010000           -mov eax, dword ptr [eax + 0x1ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(492) /* 0x1ec */);
    // 0045cef3  e8e8000000             -call 0x45cfe0
    cpu.esp -= 4;
    sub_45cfe0(app, cpu);
    if (cpu.terminate) return;
    // 0045cef8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cef9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45cf00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045cf00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045cf01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045cf02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045cf03  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0045cf06  6820d24b00             -push 0x4bd220
    app->getMemory<x86::reg32>(cpu.esp-4) = 4968992 /*0x4bd220*/;
    cpu.esp -= 4;
    // 0045cf0b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045cf0f  8d4c2458               -lea ecx, [esp + 0x58]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0045cf13  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045cf15  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045cf16  8d5c2458               -lea ebx, [esp + 0x58]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0045cf1a  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 0045cf1e  e8bef00100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0045cf23  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045cf26  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0045cf2a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045cf2c  e8ab010200             -call 0x47d0dc
    cpu.esp -= 4;
    sub_47d0dc(app, cpu);
    if (cpu.terminate) return;
    // 0045cf31  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0045cf35  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045cf37  750d                   -jne 0x45cf46
    if (!cpu.flags.zf)
    {
        goto L_0x0045cf46;
    }
    // 0045cf39  890d14f64f00           -mov dword ptr [0x4ff614], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */) = cpu.ecx;
    // 0045cf3f  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0045cf42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cf43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cf44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cf45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cf46:
    // 0045cf46  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0045cf4a  ba58104e00             -mov edx, 0x4e1058
    cpu.edx = 5115992 /*0x4e1058*/;
    // 0045cf4f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cf51  e822030200             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 0045cf56  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0045cf5a  e811030200             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0045cf5f  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0045cf62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cf63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cf64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cf65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45cf70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045cf70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045cf71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045cf72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045cf73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045cf74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045cf75  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0045cf78  6820d24b00             -push 0x4bd220
    app->getMemory<x86::reg32>(cpu.esp-4) = 4968992 /*0x4bd220*/;
    cpu.esp -= 4;
    // 0045cf7d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045cf81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045cf82  e85af00100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0045cf87  8b1514f64f00           -mov edx, dword ptr [0x4ff614]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
    // 0045cf8d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045cf90  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045cf92  750a                   -jne 0x45cf9e
    if (!cpu.flags.zf)
    {
        goto L_0x0045cf9e;
    }
    // 0045cf94  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045cf99  a3d88b4c00             -mov dword ptr [0x4c8bd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5016536) /* 0x4c8bd8 */) = cpu.eax;
L_0x0045cf9e:
    // 0045cf9e  b96c010000             -mov ecx, 0x16c
    cpu.ecx = 364 /*0x16c*/;
    // 0045cfa3  bf58104e00             -mov edi, 0x4e1058
    cpu.edi = 5115992 /*0x4e1058*/;
    // 0045cfa8  be18f54d00             -mov esi, 0x4df518
    cpu.esi = 5109016 /*0x4df518*/;
    // 0045cfad  bbb4e50100             -mov ebx, 0x1e5b4
    cpu.ebx = 124340 /*0x1e5b4*/;
    // 0045cfb2  ba58104e00             -mov edx, 0x4e1058
    cpu.edx = 5115992 /*0x4e1058*/;
    // 0045cfb7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045cfb9  a1d88b4c00             -mov eax, dword ptr [0x4c8bd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016536) /* 0x4c8bd8 */);
    // 0045cfbe  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0045cfc3  a308164e00             -mov dword ptr [0x4e1608], eax
    app->getMemory<x86::reg32>(x86::reg32(5117448) /* 0x4e1608 */) = cpu.eax;
    // 0045cfc8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045cfca  890d74104e00           -mov dword ptr [0x4e1074], ecx
    app->getMemory<x86::reg32>(x86::reg32(5116020) /* 0x4e1074 */) = cpu.ecx;
    // 0045cfd0  e8fbfe0100             -call 0x47ced0
    cpu.esp -= 4;
    sub_47ced0(app, cpu);
    if (cpu.terminate) return;
    // 0045cfd5  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0045cfd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cfd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cfda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cfdb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cfdc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cfdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45cfe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045cfe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045cfe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045cfe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045cfe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045cfe4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045cfe5  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0045cfeb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045cfed  833c85f00b4e0000       +cmp dword ptr [eax*4 + 0x4e0bf0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5114864) /* 0x4e0bf0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cff5  0f8597000000           -jne 0x45d092
    if (!cpu.flags.zf)
    {
        goto L_0x0045d092;
    }
    // 0045cffb  a110f64f00             -mov eax, dword ptr [0x4ff610]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */);
    // 0045d000  80b80c164e0000         +cmp byte ptr [eax + 0x4e160c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5117452) /* 0x4e160c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045d007  7568                   -jne 0x45d071
    if (!cpu.flags.zf)
    {
        goto L_0x0045d071;
    }
    // 0045d009  c70514f64f0004000000   -mov dword ptr [0x4ff614], 4
    app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */) = 4 /*0x4*/;
L_0x0045d013:
    // 0045d013  8b2c95f00b4e00         -mov ebp, dword ptr [edx*4 + 0x4e0bf0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5114864) /* 0x4e0bf0 */ + cpu.edx * 4);
    // 0045d01a  45                     -inc ebp
    (cpu.ebp)++;
    // 0045d01b  a128f54d00             -mov eax, dword ptr [0x4df528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0045d020  892c95f00b4e00         -mov dword ptr [edx*4 + 0x4e0bf0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5114864) /* 0x4e0bf0 */ + cpu.edx * 4) = cpu.ebp;
    // 0045d027  83f802                 +cmp eax, 2
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
    // 0045d02a  0f8ce5000000           -jl 0x45d115
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d115;
    }
    // 0045d030  3b152cf54d00           +cmp edx, dword ptr [0x4df52c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d036  0f85d9000000           -jne 0x45d115
    if (!cpu.flags.zf)
    {
        goto L_0x0045d115;
    }
L_0x0045d03c:
    // 0045d03c  833d30104e0000         +cmp dword ptr [0x4e1030], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115952) /* 0x4e1030 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d043  7410                   -je 0x45d055
    if (cpu.flags.zf)
    {
        goto L_0x0045d055;
    }
    // 0045d045  833dc0f74f0000         +cmp dword ptr [0x4ff7c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240768) /* 0x4ff7c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d04c  7407                   -je 0x45d055
    if (cpu.flags.zf)
    {
        goto L_0x0045d055;
    }
    // 0045d04e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045d050:
    // 0045d050  e88bf9ffff             -call 0x45c9e0
    cpu.esp -= 4;
    sub_45c9e0(app, cpu);
    if (cpu.terminate) return;
L_0x0045d055:
    // 0045d055  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0045d058  83baf00b4e0020         +cmp dword ptr [edx + 0x4e0bf0], 0x20
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5114864) /* 0x4e0bf0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d05f  0f84f2000000           -je 0x45d157
    if (cpu.flags.zf)
    {
        goto L_0x0045d157;
    }
    // 0045d065  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0045d06b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d06c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d06d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d06e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d06f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d070  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d071:
    // 0045d071  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d072  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045d076  e8b5010000             -call 0x45d230
    cpu.esp -= 4;
    sub_45d230(app, cpu);
    if (cpu.terminate) return;
    // 0045d07b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045d07d  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 0045d080  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0045d085  8dbe100c4e00           -lea edi, [esi + 0x4e0c10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(5114896) /* 0x4e0c10 */);
    // 0045d08b  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045d08f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d091  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045d092:
    // 0045d092  8b1d14f64f00           -mov ebx, dword ptr [0x4ff614]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
    // 0045d098  83fb02                 +cmp ebx, 2
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
    // 0045d09b  7550                   -jne 0x45d0ed
    if (!cpu.flags.zf)
    {
        goto L_0x0045d0ed;
    }
    // 0045d09d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045d09f  8b0495f00b4e00         -mov eax, dword ptr [edx*4 + 0x4e0bf0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114864) /* 0x4e0bf0 */ + cpu.edx * 4);
    // 0045d0a6  c1e107                 -shl ecx, 7
    cpu.ecx <<= 7 /*0x7*/ % 32;
    // 0045d0a9  8a9c01100c4e00         -mov bl, byte ptr [ecx + eax + 0x4e0c10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5114896) /* 0x4e0c10 */ + cpu.eax * 1);
    // 0045d0b0  80eb40                 -sub bl, 0x40
    (cpu.bl) -= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0045d0b3  c0e302                 -shl bl, 2
    cpu.bl <<= 2 /*0x2*/ % 32;
    // 0045d0b6  881d58fd4d00           -mov byte ptr [0x4dfd58], bl
    app->getMemory<x86::reg8>(x86::reg32(5111128) /* 0x4dfd58 */) = cpu.bl;
    // 0045d0bc  8a9c01300c4e00         -mov bl, byte ptr [ecx + eax + 0x4e0c30]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5114928) /* 0x4e0c30 */ + cpu.eax * 1);
    // 0045d0c3  c0e303                 -shl bl, 3
    cpu.bl <<= 3 /*0x3*/ % 32;
    // 0045d0c6  881d59fd4d00           -mov byte ptr [0x4dfd59], bl
    app->getMemory<x86::reg8>(x86::reg32(5111129) /* 0x4dfd59 */) = cpu.bl;
    // 0045d0cc  8a9c01500c4e00         -mov bl, byte ptr [ecx + eax + 0x4e0c50]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5114960) /* 0x4e0c50 */ + cpu.eax * 1);
    // 0045d0d3  c0e303                 +shl bl, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg8& op = cpu.bl;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0045d0d6  8a8401700c4e00         -mov al, byte ptr [ecx + eax + 0x4e0c70]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5114992) /* 0x4e0c70 */ + cpu.eax * 1);
    // 0045d0dd  881d5afd4d00           -mov byte ptr [0x4dfd5a], bl
    app->getMemory<x86::reg8>(x86::reg32(5111130) /* 0x4dfd5a */) = cpu.bl;
    // 0045d0e3  a25bfd4d00             -mov byte ptr [0x4dfd5b], al
    app->getMemory<x86::reg8>(x86::reg32(5111131) /* 0x4dfd5b */) = cpu.al;
    // 0045d0e8  e926ffffff             -jmp 0x45d013
    goto L_0x0045d013;
L_0x0045d0ed:
    // 0045d0ed  83fb03                 +cmp ebx, 3
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
    // 0045d0f0  0f851dffffff           -jne 0x45d013
    if (!cpu.flags.zf)
    {
        goto L_0x0045d013;
    }
    // 0045d0f6  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 0045d0f8  883d59fd4d00           -mov byte ptr [0x4dfd59], bh
    app->getMemory<x86::reg8>(x86::reg32(5111129) /* 0x4dfd59 */) = cpu.bh;
    // 0045d0fe  883d5afd4d00           -mov byte ptr [0x4dfd5a], bh
    app->getMemory<x86::reg8>(x86::reg32(5111130) /* 0x4dfd5a */) = cpu.bh;
    // 0045d104  883d5bfd4d00           -mov byte ptr [0x4dfd5b], bh
    app->getMemory<x86::reg8>(x86::reg32(5111131) /* 0x4dfd5b */) = cpu.bh;
    // 0045d10a  883d58fd4d00           -mov byte ptr [0x4dfd58], bh
    app->getMemory<x86::reg8>(x86::reg32(5111128) /* 0x4dfd58 */) = cpu.bh;
    // 0045d110  e9fefeffff             -jmp 0x45d013
    goto L_0x0045d013;
L_0x0045d115:
    // 0045d115  8b1d28f54d00           -mov ebx, dword ptr [0x4df528]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0045d11b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045d11d  0f8419ffffff           -je 0x45d03c
    if (cpu.flags.zf)
    {
        goto L_0x0045d03c;
    }
    // 0045d123  83fb01                 +cmp ebx, 1
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
    // 0045d126  0f8529ffffff           -jne 0x45d055
    if (!cpu.flags.zf)
    {
        goto L_0x0045d055;
    }
    // 0045d12c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045d133  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045d135  833c8530104e0000       +cmp dword ptr [eax*4 + 0x4e1030], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115952) /* 0x4e1030 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d13d  0f8412ffffff           -je 0x45d055
    if (cpu.flags.zf)
    {
        goto L_0x0045d055;
    }
    // 0045d143  833dc0f74f0000         +cmp dword ptr [0x4ff7c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240768) /* 0x4ff7c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d14a  0f8405ffffff           -je 0x45d055
    if (cpu.flags.zf)
    {
        goto L_0x0045d055;
    }
    // 0045d150  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045d152  e9f9feffff             -jmp 0x45d050
    goto L_0x0045d050;
L_0x0045d157:
    // 0045d157  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045d159  89b2f00b4e00           -mov dword ptr [edx + 0x4e0bf0], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5114864) /* 0x4e0bf0 */) = cpu.esi;
    // 0045d15f  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0045d165  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d166  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d167  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d168  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d169  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d16a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d173  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d174  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045d176  e885d0feff             -call 0x44a200
    cpu.esp -= 4;
    sub_44a200(app, cpu);
    if (cpu.terminate) return;
    // 0045d17b  8b1555fd4d00           -mov edx, dword ptr [0x4dfd55]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5111125) /* 0x4dfd55 */);
    // 0045d181  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0045d184  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045d186  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045d189  c1e202                 +shl edx, 2
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
    // 0045d18c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045d18e  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0045d191  8d0c9d00000000         -lea ecx, [ebx*4]
    cpu.ecx = x86::reg32(cpu.ebx * 4);
    // 0045d198  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0045d19a  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 0045d19d  8b99f00b4e00           -mov ebx, dword ptr [ecx + 0x4e0bf0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5114864) /* 0x4e0bf0 */);
    // 0045d1a3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045d1a5  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0045d1a8  8a1559fd4d00           -mov dl, byte ptr [0x4dfd59]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5111129) /* 0x4dfd59 */);
    // 0045d1ae  88841e100c4e00         -mov byte ptr [esi + ebx + 0x4e0c10], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5114896) /* 0x4e0c10 */ + cpu.ebx * 1) = cpu.al;
    // 0045d1b5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045d1b7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045d1ba  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045d1bd  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045d1bf  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0045d1c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045d1c4  8a155afd4d00           -mov dl, byte ptr [0x4dfd5a]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5111130) /* 0x4dfd5a */);
    // 0045d1ca  88841e300c4e00         -mov byte ptr [esi + ebx + 0x4e0c30], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5114928) /* 0x4e0c30 */ + cpu.ebx * 1) = cpu.al;
    // 0045d1d1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045d1d3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045d1d6  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045d1d9  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045d1db  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0045d1de  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0045d1e1  88841e500c4e00         -mov byte ptr [esi + ebx + 0x4e0c50], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5114960) /* 0x4e0c50 */ + cpu.ebx * 1) = cpu.al;
    // 0045d1e8  a05bfd4d00             -mov al, byte ptr [0x4dfd5b]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5111131) /* 0x4dfd5b */);
    // 0045d1ed  8991f00b4e00           -mov dword ptr [ecx + 0x4e0bf0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5114864) /* 0x4e0bf0 */) = cpu.edx;
    // 0045d1f3  88841e700c4e00         -mov byte ptr [esi + ebx + 0x4e0c70], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5114992) /* 0x4e0c70 */ + cpu.ebx * 1) = cpu.al;
    // 0045d1fa  83fa20                 +cmp edx, 0x20
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d1fd  7405                   -je 0x45d204
    if (cpu.flags.zf)
    {
        goto L_0x0045d204;
    }
    // 0045d1ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d200  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d201  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d202  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d203  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d204:
    // 0045d204  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d205  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0045d20b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045d20d  8db6100c4e00           -lea esi, [esi + 0x4e0c10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(5114896) /* 0x4e0c10 */);
    // 0045d213  89b9f00b4e00           -mov dword ptr [ecx + 0x4e0bf0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5114864) /* 0x4e0bf0 */) = cpu.edi;
    // 0045d219  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045d21b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0045d21d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d21f  e8cc010000             -call 0x45d3f0
    cpu.esp -= 4;
    sub_45d3f0(app, cpu);
    if (cpu.terminate) return;
    // 0045d224  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d225  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d226  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d227  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d228  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d229  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d231  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d232  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d233  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d234  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0045d23a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045d23c  8b3510f64f00           -mov esi, dword ptr [0x4ff610]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */);
    // 0045d242  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d244  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d24b  8a8e0c164e00           -mov cl, byte ptr [esi + 0x4e160c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5117452) /* 0x4e160c */);
    // 0045d251  81c60c164e00           -add esi, 0x4e160c
    (cpu.esi) += x86::reg32(x86::sreg32(5117452 /*0x4e160c*/));
    // 0045d257  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d258  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d25a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d25d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d25f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d261  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d264  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d266  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d267  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d26e  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0045d273  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0045d275  e8d6040000             -call 0x45d750
    cpu.esp -= 4;
    sub_45d750(app, cpu);
    if (cpu.terminate) return;
    // 0045d27a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045d27c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d27d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d27f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d282  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d284  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d286  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d289  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d28b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d28c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d28e  8b0d10f64f00           -mov ecx, dword ptr [0x4ff610]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */);
    // 0045d294  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d29b  be0c164e00             -mov esi, 0x4e160c
    cpu.esi = 5117452 /*0x4e160c*/;
    // 0045d2a0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d2a2  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d2a9  890d10f64f00           -mov dword ptr [0x4ff610], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */) = cpu.ecx;
    // 0045d2af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d2b1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d2b3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d2b5  8a880c164e00           -mov cl, byte ptr [eax + 0x4e160c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5117452) /* 0x4e160c */);
    // 0045d2bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d2bc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d2be  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d2c1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d2c3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d2c5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d2c8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d2ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d2cb  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d2d2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0045d2d7  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045d2db  e870040000             -call 0x45d750
    cpu.esp -= 4;
    sub_45d750(app, cpu);
    if (cpu.terminate) return;
    // 0045d2e0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045d2e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d2e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d2e5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d2e8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d2ea  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d2ec  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d2ef  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d2f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d2f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d2f4  8b1d10f64f00           -mov ebx, dword ptr [0x4ff610]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */);
    // 0045d2fa  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d301  be0c164e00             -mov esi, 0x4e160c
    cpu.esi = 5117452 /*0x4e160c*/;
    // 0045d306  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d308  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d30a  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d311  8a8b0c164e00           -mov cl, byte ptr [ebx + 0x4e160c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5117452) /* 0x4e160c */);
    // 0045d317  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045d319  891d10f64f00           -mov dword ptr [0x4ff610], ebx
    app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */) = cpu.ebx;
    // 0045d31f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d320  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d322  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d325  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d327  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d329  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d32c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d32e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d32f  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d336  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0045d33b  8d7c2440               -lea edi, [esp + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0045d33f  e80c040000             -call 0x45d750
    cpu.esp -= 4;
    sub_45d750(app, cpu);
    if (cpu.terminate) return;
    // 0045d344  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045d346  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d347  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d349  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d34c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d34e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d350  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d353  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d355  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d356  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d358  8b3510f64f00           -mov esi, dword ptr [0x4ff610]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */);
    // 0045d35e  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d365  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d367  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d369  893510f64f00           -mov dword ptr [0x4ff610], esi
    app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */) = cpu.esi;
    // 0045d36f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045d371  8a8e0c164e00           -mov cl, byte ptr [esi + 0x4e160c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5117452) /* 0x4e160c */);
    // 0045d377  be0c164e00             -mov esi, 0x4e160c
    cpu.esi = 5117452 /*0x4e160c*/;
    // 0045d37c  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d383  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d385  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d386  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d388  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d38b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d38d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d38f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d392  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d394  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d395  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d39c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0045d3a1  8d7c2460               -lea edi, [esp + 0x60]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0045d3a5  e8a6030000             -call 0x45d750
    cpu.esp -= 4;
    sub_45d750(app, cpu);
    if (cpu.terminate) return;
    // 0045d3aa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045d3ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d3ad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d3af  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d3b2  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d3b4  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d3b6  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d3b9  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d3bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d3bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d3be  8b3d10f64f00           -mov edi, dword ptr [0x4ff610]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */);
    // 0045d3c4  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d3cb  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0045d3d0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d3d2  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045d3d4  893d10f64f00           -mov dword ptr [0x4ff610], edi
    app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */) = cpu.edi;
    // 0045d3da  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045d3dc  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d3de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045d3e0  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0045d3e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d3e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d3e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d3e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d3ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d3f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d3f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045d3f2  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0045d3f5  a10cf64f00             -mov eax, dword ptr [0x4ff60c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */);
    // 0045d3fa  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0045d3ff  3d00e00100             +cmp eax, 0x1e000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122880 /*0x1e000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d404  7c1d                   -jl 0x45d423
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d423;
    }
    // 0045d406  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045d40b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045d410  a3d88b4c00             -mov dword ptr [0x4c8bd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5016536) /* 0x4c8bd8 */) = cpu.eax;
    // 0045d415  893d14f64f00           -mov dword ptr [0x4ff614], edi
    app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */) = cpu.edi;
    // 0045d41b  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0045d41e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d41f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d420  c28000                 -ret 0x80
    cpu.esp += 4+128 /*0x80*/;
    return;
L_0x0045d423:
    // 0045d423  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d424  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d425  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d426  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d427  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0045d42b  b921000000             -mov ecx, 0x21
    cpu.ecx = 33 /*0x21*/;
    // 0045d430  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d434  e887030000             -call 0x45d7c0
    cpu.esp -= 4;
    sub_45d7c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d439  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045d43b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d43c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d43e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d441  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d443  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d445  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d448  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d44a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d44b  bf0c164e00             -mov edi, 0x4e160c
    cpu.edi = 5117452 /*0x4e160c*/;
    // 0045d450  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d454  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d456  8b150cf64f00           -mov edx, dword ptr [0x4ff60c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */);
    // 0045d45c  8a4c2410               -mov cl, byte ptr [esp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d460  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045d462  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d463  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d465  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d468  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d46a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d46c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d46f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d471  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d472  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d474  8b0d0cf64f00           -mov ecx, dword ptr [0x4ff60c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */);
    // 0045d47a  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d47e  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d482  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d484  8d442460               -lea eax, [esp + 0x60]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0045d488  890d0cf64f00           -mov dword ptr [0x4ff60c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */) = cpu.ecx;
    // 0045d48e  e82d030000             -call 0x45d7c0
    cpu.esp -= 4;
    sub_45d7c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d493  b921000000             -mov ecx, 0x21
    cpu.ecx = 33 /*0x21*/;
    // 0045d498  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045d49a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d49b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d49d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d4a0  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d4a2  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d4a4  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d4a7  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d4a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d4aa  bf0c164e00             -mov edi, 0x4e160c
    cpu.edi = 5117452 /*0x4e160c*/;
    // 0045d4af  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d4b3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d4b5  8b1d0cf64f00           -mov ebx, dword ptr [0x4ff60c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */);
    // 0045d4bb  8a4c2410               -mov cl, byte ptr [esp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d4bf  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045d4c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d4c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d4c4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d4c7  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d4c9  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d4cb  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d4ce  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d4d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d4d1  b921000000             -mov ecx, 0x21
    cpu.ecx = 33 /*0x21*/;
    // 0045d4d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d4d8  8b350cf64f00           -mov esi, dword ptr [0x4ff60c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */);
    // 0045d4de  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d4e2  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d4e6  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d4e8  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0045d4ef  89350cf64f00           -mov dword ptr [0x4ff60c], esi
    app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */) = cpu.esi;
    // 0045d4f5  e8c6020000             -call 0x45d7c0
    cpu.esp -= 4;
    sub_45d7c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d4fa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045d4fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d4fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d4ff  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d502  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d504  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d506  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d509  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d50b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d50c  bf0c164e00             -mov edi, 0x4e160c
    cpu.edi = 5117452 /*0x4e160c*/;
    // 0045d511  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d515  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d517  8b2d0cf64f00           -mov ebp, dword ptr [0x4ff60c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */);
    // 0045d51d  8a4c2410               -mov cl, byte ptr [esp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d521  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045d523  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d524  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d526  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d529  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d52b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d52d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d530  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d532  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d533  b921000000             -mov ecx, 0x21
    cpu.ecx = 33 /*0x21*/;
    // 0045d538  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d53a  8b150cf64f00           -mov edx, dword ptr [0x4ff60c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */);
    // 0045d540  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d544  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d548  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d54a  8d8424a0000000         -lea eax, [esp + 0xa0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0045d551  89150cf64f00           -mov dword ptr [0x4ff60c], edx
    app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */) = cpu.edx;
    // 0045d557  e864020000             -call 0x45d7c0
    cpu.esp -= 4;
    sub_45d7c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d55c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045d55e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d55f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d561  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d564  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d566  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d568  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d56b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d56d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d56e  bf0c164e00             -mov edi, 0x4e160c
    cpu.edi = 5117452 /*0x4e160c*/;
    // 0045d573  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d577  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d579  8b1d0cf64f00           -mov ebx, dword ptr [0x4ff60c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */);
    // 0045d57f  8a4c2410               -mov cl, byte ptr [esp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d583  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045d585  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d586  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045d588  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045d58b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d58d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045d58f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045d592  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045d594  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d595  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d597  8b350cf64f00           -mov esi, dword ptr [0x4ff60c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */);
    // 0045d59d  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d5a1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d5a3  89350cf64f00           -mov dword ptr [0x4ff60c], esi
    app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */) = cpu.esi;
    // 0045d5a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5ad  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0045d5b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5b2  c28000                 -ret 0x80
    cpu.esp += 4+128 /*0x80*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d5c0  833d14f64f0001         +cmp dword ptr [0x4ff614], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d5c7  7e13                   -jle 0x45d5dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d5dc;
    }
L_0x0045d5c9:
    // 0045d5c9  833d14f64f0001         +cmp dword ptr [0x4ff614], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d5d0  7e09                   -jle 0x45d5db
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d5db;
    }
    // 0045d5d2  833d28f54d0002         +cmp dword ptr [0x4df528], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d5d9  7d08                   -jge 0x45d5e3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045d5e3;
    }
L_0x0045d5db:
    // 0045d5db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d5dc:
    // 0045d5dc  e88ff9ffff             -call 0x45cf70
    cpu.esp -= 4;
    sub_45cf70(app, cpu);
    if (cpu.terminate) return;
    // 0045d5e1  ebe6                   -jmp 0x45d5c9
    goto L_0x0045d5c9;
L_0x0045d5e3:
    // 0045d5e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d5e4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045d5e6  893528f54d00           -mov dword ptr [0x4df528], esi
    app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */) = cpu.esi;
    // 0045d5ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45d5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d5f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d5f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d5f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045d5f3  8b1514f64f00           -mov edx, dword ptr [0x4ff614]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
    // 0045d5f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d5fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d5fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045d5fd  756d                   -jne 0x45d66c
    if (!cpu.flags.zf)
    {
        goto L_0x0045d66c;
    }
L_0x0045d5ff:
    // 0045d5ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045d601:
    // 0045d601  40                     -inc eax
    (cpu.eax)++;
    // 0045d602  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0045d604  88980b164e00           -mov byte ptr [eax + 0x4e160b], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5117451) /* 0x4e160b */) = cpu.bl;
    // 0045d60a  3d00e00100             +cmp eax, 0x1e000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122880 /*0x1e000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d60f  7cf0                   -jl 0x45d601
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d601;
    }
    // 0045d611  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045d613  892d10f64f00           -mov dword ptr [0x4ff610], ebp
    app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */) = cpu.ebp;
    // 0045d619  892d0cf64f00           -mov dword ptr [0x4ff60c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5240332) /* 0x4ff60c */) = cpu.ebp;
L_0x0045d61f:
    // 0045d61f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d621  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045d626  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045d628:
    // 0045d628  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045d62b  898820104e00           -mov dword ptr [eax + 0x4e1020], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115936) /* 0x4e1020 */) = cpu.ecx;
    // 0045d631  898824104e00           -mov dword ptr [eax + 0x4e1024], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115940) /* 0x4e1024 */) = cpu.ecx;
    // 0045d637  898828104e00           -mov dword ptr [eax + 0x4e1028], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115944) /* 0x4e1028 */) = cpu.ecx;
    // 0045d63d  89882c104e00           -mov dword ptr [eax + 0x4e102c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115948) /* 0x4e102c */) = cpu.ecx;
    // 0045d643  89981c104e00           -mov dword ptr [eax + 0x4e101c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115932) /* 0x4e101c */) = cpu.ebx;
    // 0045d649  83f828                 +cmp eax, 0x28
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d64c  75da                   -jne 0x45d628
    if (!cpu.flags.zf)
    {
        goto L_0x0045d628;
    }
    // 0045d64e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d650  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d651  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045d652:
    // 0045d652  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045d655  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045d657  89b0ec0b4e00           -mov dword ptr [eax + 0x4e0bec], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5114860) /* 0x4e0bec */) = cpu.esi;
    // 0045d65d  83f820                 +cmp eax, 0x20
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
    // 0045d660  75f0                   -jne 0x45d652
    if (!cpu.flags.zf)
    {
        goto L_0x0045d652;
    }
    // 0045d662  891514f64f00           -mov dword ptr [0x4ff614], edx
    app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */) = cpu.edx;
    // 0045d668  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d669  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d66a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d66b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d66c:
    // 0045d66c  83fa01                 +cmp edx, 1
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
    // 0045d66f  748e                   -je 0x45d5ff
    if (cpu.flags.zf)
    {
        goto L_0x0045d5ff;
    }
    // 0045d671  83fa02                 +cmp edx, 2
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
    // 0045d674  7ca9                   -jl 0x45d61f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d61f;
    }
    // 0045d676  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d678  890d10104e00           -mov dword ptr [0x4e1010], ecx
    app->getMemory<x86::reg32>(x86::reg32(5115920) /* 0x4e1010 */) = cpu.ecx;
    // 0045d67e  890d18104e00           -mov dword ptr [0x4e1018], ecx
    app->getMemory<x86::reg32>(x86::reg32(5115928) /* 0x4e1018 */) = cpu.ecx;
    // 0045d684  890d20104e00           -mov dword ptr [0x4e1020], ecx
    app->getMemory<x86::reg32>(x86::reg32(5115936) /* 0x4e1020 */) = cpu.ecx;
    // 0045d68a  890d24104e00           -mov dword ptr [0x4e1024], ecx
    app->getMemory<x86::reg32>(x86::reg32(5115940) /* 0x4e1024 */) = cpu.ecx;
    // 0045d690  890d28104e00           -mov dword ptr [0x4e1028], ecx
    app->getMemory<x86::reg32>(x86::reg32(5115944) /* 0x4e1028 */) = cpu.ecx;
    // 0045d696  890d10f64f00           -mov dword ptr [0x4ff610], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */) = cpu.ecx;
    // 0045d69c  83fa04                 +cmp edx, 4
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
    // 0045d69f  751c                   -jne 0x45d6bd
    if (!cpu.flags.zf)
    {
        goto L_0x0045d6bd;
    }
    // 0045d6a1  833d1c104e0000         +cmp dword ptr [0x4e101c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d6a8  740f                   -je 0x45d6b9
    if (cpu.flags.zf)
    {
        goto L_0x0045d6b9;
    }
    // 0045d6aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0045d6af:
    // 0045d6af  a328104e00             -mov dword ptr [0x4e1028], eax
    app->getMemory<x86::reg32>(x86::reg32(5115944) /* 0x4e1028 */) = cpu.eax;
    // 0045d6b4  e966ffffff             -jmp 0x45d61f
    goto L_0x0045d61f;
L_0x0045d6b9:
    // 0045d6b9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045d6bb  ebf2                   -jmp 0x45d6af
    goto L_0x0045d6af;
L_0x0045d6bd:
    // 0045d6bd  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0045d6c2  890d2c104e00           -mov dword ptr [0x4e102c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5115948) /* 0x4e102c */) = cpu.ecx;
    // 0045d6c8  890d1c104e00           -mov dword ptr [0x4e101c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */) = cpu.ecx;
    // 0045d6ce  891d14104e00           -mov dword ptr [0x4e1014], ebx
    app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */) = cpu.ebx;
    // 0045d6d4  e946ffffff             -jmp 0x45d61f
    goto L_0x0045d61f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d6e0  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0045d6e3  a134f54d00             -mov eax, dword ptr [0x4df534]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
    // 0045d6e8  a314f64f00             -mov dword ptr [0x4ff614], eax
    app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */) = cpu.eax;
    // 0045d6ed  83f802                 +cmp eax, 2
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
    // 0045d6f0  7404                   -je 0x45d6f6
    if (cpu.flags.zf)
    {
        goto L_0x0045d6f6;
    }
    // 0045d6f2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0045d6f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d6f6:
    // 0045d6f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d6f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d6f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d6f9  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 0045d6fe  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045d702  be54f54d00             -mov esi, 0x4df554
    cpu.esi = 5109076 /*0x4df554*/;
    // 0045d707  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d709  b96c010000             -mov ecx, 0x16c
    cpu.ecx = 364 /*0x16c*/;
    // 0045d70e  bf18f54d00             -mov edi, 0x4df518
    cpu.edi = 5109016 /*0x4df518*/;
    // 0045d713  be58104e00             -mov esi, 0x4e1058
    cpu.esi = 5115992 /*0x4e1058*/;
    // 0045d718  e8e3f7ffff             -call 0x45cf00
    cpu.esp -= 4;
    sub_45cf00(app, cpu);
    if (cpu.terminate) return;
    // 0045d71d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d71f  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 0045d724  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045d728  bf54f54d00             -mov edi, 0x4df554
    cpu.edi = 5109076 /*0x4df554*/;
    // 0045d72d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045d72f  a108164e00             -mov eax, dword ptr [0x4e1608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5117448) /* 0x4e1608 */);
    // 0045d734  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d736  a3d88b4c00             -mov dword ptr [0x4c8bd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5016536) /* 0x4c8bd8 */) = cpu.eax;
    // 0045d73b  890d10f64f00           -mov dword ptr [0x4ff610], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240336) /* 0x4ff610 */) = cpu.ecx;
    // 0045d741  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d742  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d743  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d744  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0045d747  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d754  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d755  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045d756  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045d759  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0045d75b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d75d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045d762  8a4d00                 -mov cl, byte ptr [ebp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp);
    // 0045d765  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d767  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0045d76a  39d1                   +cmp ecx, edx
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
    // 0045d76c  7e2b                   -jle 0x45d799
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d799;
    }
L_0x0045d76e:
    // 0045d76e  8d342a                 -lea esi, [edx + ebp]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0045d771  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0045d773  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045d776  7530                   -jne 0x45d7a8
    if (!cpu.flags.zf)
    {
        goto L_0x0045d7a8;
    }
    // 0045d778  0fb67e01               -movzx edi, byte ptr [esi + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0045d77c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d77e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045d780  7e0f                   -jle 0x45d791
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d791;
    }
L_0x0045d782:
    // 0045d782  40                     -inc eax
    (cpu.eax)++;
    // 0045d783  8a5e02                 -mov bl, byte ptr [esi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0045d786  41                     -inc ecx
    (cpu.ecx)++;
    // 0045d787  8898cf0b4e00           -mov byte ptr [eax + 0x4e0bcf], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5114831) /* 0x4e0bcf */) = cpu.bl;
    // 0045d78d  39f9                   +cmp ecx, edi
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
    // 0045d78f  7cf1                   -jl 0x45d782
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d782;
    }
L_0x0045d791:
    // 0045d791  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0045d794:
    // 0045d794  3b1424                 +cmp edx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d797  7cd5                   -jl 0x45d76e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d76e;
    }
L_0x0045d799:
    // 0045d799  b8d00b4e00             -mov eax, 0x4e0bd0
    cpu.eax = 5114832 /*0x4e0bd0*/;
    // 0045d79e  83c404                 +add esp, 4
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
    // 0045d7a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d7a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d7a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d7a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d7a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d7a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d7a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d7a8:
    // 0045d7a8  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045d7a9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045d7aa  8888cf0b4e00           -mov byte ptr [eax + 0x4e0bcf], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5114831) /* 0x4e0bcf */) = cpu.cl;
    // 0045d7b0  ebe2                   -jmp 0x45d794
    goto L_0x0045d794;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d7c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d7c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d7c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d7c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d7c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d7c5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045d7c7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045d7cc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045d7ce:
    // 0045d7ce  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 0045d7d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045d7d3  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
L_0x0045d7d5:
    // 0045d7d5  41                     -inc ecx
    (cpu.ecx)++;
    // 0045d7d6  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045d7d9  46                     -inc esi
    (cpu.esi)++;
    // 0045d7da  42                     -inc edx
    (cpu.edx)++;
    // 0045d7db  38df                   +cmp bh, bl
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045d7dd  7505                   -jne 0x45d7e4
    if (!cpu.flags.zf)
    {
        goto L_0x0045d7e4;
    }
    // 0045d7df  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d7e2  7cf1                   -jl 0x45d7d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d7d5;
    }
L_0x0045d7e4:
    // 0045d7e4  83fa03                 +cmp edx, 3
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
    // 0045d7e7  7c34                   -jl 0x45d81d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d81d;
    }
    // 0045d7e9  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0045d7ec  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 0045d7ee  889817f64f00           -mov byte ptr [eax + 0x4ff617], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5240343) /* 0x4ff617 */) = cpu.bl;
    // 0045d7f4  889016f64f00           -mov byte ptr [eax + 0x4ff616], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5240342) /* 0x4ff616 */) = cpu.dl;
    // 0045d7fa  88b015f64f00           -mov byte ptr [eax + 0x4ff615], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5240341) /* 0x4ff615 */) = cpu.dh;
L_0x0045d800:
    // 0045d800  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d803  7cc9                   -jl 0x45d7ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d7ce;
    }
    // 0045d805  a218f64f00             -mov byte ptr [0x4ff618], al
    app->getMemory<x86::reg8>(x86::reg32(5240344) /* 0x4ff618 */) = cpu.al;
    // 0045d80a  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0045d80c  889818f64f00           -mov byte ptr [eax + 0x4ff618], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5240344) /* 0x4ff618 */) = cpu.bl;
    // 0045d812  b818f64f00             -mov eax, 0x4ff618
    cpu.eax = 5240344 /*0x4ff618*/;
    // 0045d817  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d818  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d819  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d81a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d81b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d81c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d81d:
    // 0045d81d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045d81f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045d821  7edd                   -jle 0x45d800
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d800;
    }
L_0x0045d823:
    // 0045d823  40                     -inc eax
    (cpu.eax)++;
    // 0045d824  46                     -inc esi
    (cpu.esi)++;
    // 0045d825  889817f64f00           -mov byte ptr [eax + 0x4ff617], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5240343) /* 0x4ff617 */) = cpu.bl;
    // 0045d82b  39d6                   +cmp esi, edx
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
    // 0045d82d  7cf4                   -jl 0x45d823
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d823;
    }
    // 0045d82f  ebcf                   -jmp 0x45d800
    goto L_0x0045d800;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d840  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d841  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d842  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045d843  81eca4020000           -sub esp, 0x2a4
    (cpu.esp) -= x86::reg32(x86::sreg32(676 /*0x2a4*/));
    // 0045d849  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045d84b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0045d84d  8b8424b4020000         -mov eax, dword ptr [esp + 0x2b4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(692) /* 0x2b4 */);
    // 0045d854  89842484020000         -mov dword ptr [esp + 0x284], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */) = cpu.eax;
    // 0045d85b  8b8424b8020000         -mov eax, dword ptr [esp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(696) /* 0x2b8 */);
    // 0045d862  89942490020000         -mov dword ptr [esp + 0x290], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(656) /* 0x290 */) = cpu.edx;
    // 0045d869  89842498020000         -mov dword ptr [esp + 0x298], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(664) /* 0x298 */) = cpu.eax;
    // 0045d870  8b8424bc020000         -mov eax, dword ptr [esp + 0x2bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */);
    // 0045d877  899c2480020000         -mov dword ptr [esp + 0x280], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */) = cpu.ebx;
    // 0045d87e  89842488020000         -mov dword ptr [esp + 0x288], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(648) /* 0x288 */) = cpu.eax;
    // 0045d885  8b8424c0020000         -mov eax, dword ptr [esp + 0x2c0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0045d88c  898c2494020000         -mov dword ptr [esp + 0x294], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(660) /* 0x294 */) = cpu.ecx;
    // 0045d893  8984249c020000         -mov dword ptr [esp + 0x29c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(668) /* 0x29c */) = cpu.eax;
    // 0045d89a  8b8424c4020000         -mov eax, dword ptr [esp + 0x2c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(708) /* 0x2c4 */);
    // 0045d8a1  8d8c2440010000         -lea ecx, [esp + 0x140]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 0045d8a8  8984248c020000         -mov dword ptr [esp + 0x28c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(652) /* 0x28c */) = cpu.eax;
    // 0045d8af  8d8424a0020000         -lea eax, [esp + 0x2a0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(672) /* 0x2a0 */);
    // 0045d8b6  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0045d8bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045d8bc  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045d8c0  8d942484020000         -lea edx, [esp + 0x284]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(644) /* 0x284 */);
    // 0045d8c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045d8c8  8d842498020000         -lea eax, [esp + 0x298]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(664) /* 0x298 */);
    // 0045d8cf  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045d8d1  e87a000000             -call 0x45d950
    cpu.esp -= 4;
    sub_45d950(app, cpu);
    if (cpu.terminate) return;
    // 0045d8d6  8b9424c0020000         -mov edx, dword ptr [esp + 0x2c0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0045d8dd  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0045d8df  39d5                   +cmp ebp, edx
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
    // 0045d8e1  7f5f                   -jg 0x45d942
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045d942;
    }
    // 0045d8e3  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0045d8e6  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045d8e8  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 0045d8ea  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x0045d8ec:
    // 0045d8ec  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
L_0x0045d8f3:
    // 0045d8f3  3b9c0c44010000         +cmp ebx, dword ptr [esp + ecx + 0x144]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */ + cpu.ecx * 1)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d8fa  7e06                   -jle 0x45d902
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d902;
    }
    // 0045d8fc  46                     -inc esi
    (cpu.esi)++;
    // 0045d8fd  83c104                 +add ecx, 4
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
    // 0045d900  ebf1                   -jmp 0x45d8f3
    goto L_0x0045d8f3;
L_0x0045d902:
    // 0045d902  8b440c04               -mov eax, dword ptr [esp + ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 0045d906  8b2c0c                 -mov ebp, dword ptr [esp + ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 1);
    // 0045d909  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045d90b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045d90d  8bac0c40010000         -mov ebp, dword ptr [esp + ecx + 0x140]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */ + cpu.ecx * 1);
    // 0045d914  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045d916  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0045d919  8b840c44010000         -mov eax, dword ptr [esp + ecx + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */ + cpu.ecx * 1);
    // 0045d920  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045d922  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0045d924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045d926  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045d929  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045d92b  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045d92e  8b140c                 -mov edx, dword ptr [esp + ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 1);
    // 0045d931  43                     -inc ebx
    (cpu.ebx)++;
    // 0045d932  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045d934  8b8c24c0020000         -mov ecx, dword ptr [esp + 0x2c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0045d93b  8947fc                 -mov dword ptr [edi - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0045d93e  39cb                   +cmp ebx, ecx
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
    // 0045d940  7eaa                   -jle 0x45d8ec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d8ec;
    }
L_0x0045d942:
    // 0045d942  81c4a4020000           -add esp, 0x2a4
    (cpu.esp) += x86::reg32(x86::sreg32(676 /*0x2a4*/));
    // 0045d948  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d949  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d94a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d94b  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45d950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d950  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d951  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d952  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045d953  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0045d956  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0045d95a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0045d95e  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0045d962  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0045d965  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0045d967  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0045d969  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0045d96b  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0045d96f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045d971  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045d975  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045d97a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0045d97c  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0045d980  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0045d984  83fb02                 +cmp ebx, 2
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
    // 0045d987  7f2d                   -jg 0x45d9b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045d9b6;
    }
L_0x0045d989:
    // 0045d989  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045d98d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045d991  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045d994  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045d996  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0045d99a  3b5afc                 +cmp ebx, dword ptr [edx - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d99d  0f85fa010000           -jne 0x45db9d
    if (!cpu.flags.zf)
    {
        goto L_0x0045db9d;
    }
    // 0045d9a3  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0045d9a7  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045d9ab  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045d9ad  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0045d9b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d9b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d9b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d9b3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0045d9b6:
    // 0045d9b6  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0045d9bb  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045d9bf  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0045d9c3  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d9c5  7cc2                   -jl 0x45d989
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d989;
    }
    // 0045d9c7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045d9cb  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045d9ce  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0045d9d2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045d9d6  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045d9d9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0045d9dd:
    // 0045d9dd  837c241002             +cmp dword ptr [esp + 0x10], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d9e2  0f8591010000           -jne 0x45db79
    if (!cpu.flags.zf)
    {
        goto L_0x0045db79;
    }
    // 0045d9e8  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045d9ec  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045d9f0  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0045d9f2  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
L_0x0045d9f4:
    // 0045d9f4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045d9f8  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d9fc  0f858a010000           -jne 0x45db8c
    if (!cpu.flags.zf)
    {
        goto L_0x0045db8c;
    }
    // 0045da02  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045da06  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045da0a  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045da0d  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
L_0x0045da10:
    // 0045da10  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0045da14  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0045da17  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0045da1a  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045da1d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045da20  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0045da23  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0045da27  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045da2b  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0045da2f  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0045da33  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045da37  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0045da3b  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0045da3f  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045da43  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0045da47  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045da4a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045da4c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045da4e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0045da50:
    // 0045da50  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0045da54  8b81dcf64f00           -mov eax, dword ptr [ecx + 0x4ff6dc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5240540) /* 0x4ff6dc */);
    // 0045da5a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045da5c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045da5f  c1e810                 +shr eax, 0x10
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
    // 0045da62  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045da64  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0045da68  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045da6a  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045da6d  8b812cf74f00           -mov eax, dword ptr [ecx + 0x4ff72c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5240620) /* 0x4ff72c */);
    // 0045da73  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045da76  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045da78  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045da7b  c1e810                 +shr eax, 0x10
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
    // 0045da7e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045da80  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0045da84  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045da86  8b52f8                 -mov edx, dword ptr [edx - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0045da89  8b813cf64f00           -mov eax, dword ptr [ecx + 0x4ff63c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5240380) /* 0x4ff63c */);
    // 0045da8f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045da92  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045da94  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045da97  c1e810                 +shr eax, 0x10
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
    // 0045da9a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045da9c  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0045daa0  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045daa2  8b818cf64f00           -mov eax, dword ptr [ecx + 0x4ff68c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5240460) /* 0x4ff68c */);
    // 0045daa8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045daaa  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045daad  c1e810                 +shr eax, 0x10
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
    // 0045dab0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045dab2  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045dab6  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045dab8  8b81dcf64f00           -mov eax, dword ptr [ecx + 0x4ff6dc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5240540) /* 0x4ff6dc */);
    // 0045dabe  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045dac0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045dac3  c1e810                 +shr eax, 0x10
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
    // 0045dac6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045dac8  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0045dacc  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0045dace  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045dad1  8b812cf74f00           -mov eax, dword ptr [ecx + 0x4ff72c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5240620) /* 0x4ff72c */);
    // 0045dad7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045dada  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045dadc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045dadf  c1e810                 +shr eax, 0x10
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
    // 0045dae2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045dae4  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0045dae8  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045daea  8b52f8                 -mov edx, dword ptr [edx - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0045daed  8b813cf64f00           -mov eax, dword ptr [ecx + 0x4ff63c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5240380) /* 0x4ff63c */);
    // 0045daf3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045daf6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045daf8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045dafb  c1e810                 +shr eax, 0x10
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
    // 0045dafe  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045db00  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045db04  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045db06  8b818cf64f00           -mov eax, dword ptr [ecx + 0x4ff68c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5240460) /* 0x4ff68c */);
    // 0045db0c  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0045db0f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045db11  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045db14  c1e810                 +shr eax, 0x10
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
    // 0045db17  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045db19  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045db1b  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0045db1f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045db22  39eb                   +cmp ebx, ebp
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
    // 0045db24  7417                   -je 0x45db3d
    if (cpu.flags.zf)
    {
        goto L_0x0045db3d;
    }
    // 0045db26  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0045db28  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 0045db2c  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0045db2e  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045db32  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045db35  40                     -inc eax
    (cpu.eax)++;
    // 0045db36  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045db39  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
L_0x0045db3d:
    // 0045db3d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045db40  83f950                 +cmp ecx, 0x50
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045db43  0f8507ffffff           -jne 0x45da50
    if (!cpu.flags.zf)
    {
        goto L_0x0045da50;
    }
    // 0045db49  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045db4d  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045db51  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045db55  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045db59  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045db5c  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045db5f  40                     -inc eax
    (cpu.eax)++;
    // 0045db60  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0045db64  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0045db68  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0045db6c  39d0                   +cmp eax, edx
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
    // 0045db6e  0f8f15feffff           -jg 0x45d989
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045d989;
    }
    // 0045db74  e964feffff             -jmp 0x45d9dd
    goto L_0x0045d9dd;
L_0x0045db79:
    // 0045db79  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045db7d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045db81  8b5bf4                 -mov ebx, dword ptr [ebx - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-12) /* -0xc */);
    // 0045db84  8b49f4                 -mov ecx, dword ptr [ecx - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-12) /* -0xc */);
    // 0045db87  e968feffff             -jmp 0x45d9f4
    goto L_0x0045d9f4;
L_0x0045db8c:
    // 0045db8c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045db90  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045db94  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0045db96  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0045db98  e973feffff             -jmp 0x45da10
    goto L_0x0045da10;
L_0x0045db9d:
    // 0045db9d  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045dba1  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0045dba4  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045dba8  8b7c244c               -mov edi, dword ptr [esp + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0045dbac  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045dbb0  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045dbb3  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0045dbb6  45                     -inc ebp
    (cpu.ebp)++;
    // 0045dbb7  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045dbb9  891419                 -mov dword ptr [ecx + ebx], edx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.ebx * 1) = cpu.edx;
    // 0045dbbc  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0045dbbe  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0045dbc1  896c2438               -mov dword ptr [esp + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 0045dbc5  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0045dbc7  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0045dbcb  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045dbcf  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045dbd1  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0045dbd4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbd5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbd6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbd7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45dbe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045dbe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045dbe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045dbe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045dbe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045dbe4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dbe5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045dbe6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045dbe9  bb00000600             -mov ebx, 0x60000
    cpu.ebx = 393216 /*0x60000*/;
    // 0045dbee  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0045dbf3  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045dbf4  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dbf6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045dbf8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dbfa  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045dbfe  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045dc01  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dc03  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045dc06  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045dc08  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045dc0a  bb00000300             -mov ebx, 0x30000
    cpu.ebx = 196608 /*0x30000*/;
    // 0045dc0f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0045dc13  b800000200             -mov eax, 0x20000
    cpu.eax = 131072 /*0x20000*/;
    // 0045dc18  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0045dc1c  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045dc1d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dc1f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045dc21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dc23  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045dc27  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045dc2a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dc2c  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045dc2f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045dc31  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0045dc35:
    // 0045dc35  bb00001300             -mov ebx, 0x130000
    cpu.ebx = 1245184 /*0x130000*/;
    // 0045dc3a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045dc3e  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045dc3f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dc41  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045dc43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dc45  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045dc49  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045dc4c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dc4e  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045dc51  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045dc53  bb00000600             -mov ebx, 0x60000
    cpu.ebx = 393216 /*0x60000*/;
    // 0045dc58  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045dc5a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045dc5c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045dc5e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045dc61  c1e810                 +shr eax, 0x10
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
    // 0045dc64  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045dc66  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045dc68  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045dc6b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045dc6d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045dc70  c1e810                 +shr eax, 0x10
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
    // 0045dc73  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045dc75  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045dc77  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045dc78  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dc7a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045dc7c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dc7e  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045dc82  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045dc85  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dc87  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045dc8a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045dc8c  8985dcf64f00           -mov dword ptr [ebp + 0x4ff6dc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5240540) /* 0x4ff6dc */) = cpu.eax;
    // 0045dc92  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0045dc95  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0045dc97  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045dc99  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045dc9d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045dc9f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045dca1  89852cf74f00           -mov dword ptr [ebp + 0x4ff72c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5240620) /* 0x4ff72c */) = cpu.eax;
    // 0045dca7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045dca9  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0045dcac  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045dcae  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045dcb2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045dcb4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045dcb6  89853cf64f00           -mov dword ptr [ebp + 0x4ff63c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5240380) /* 0x4ff63c */) = cpu.eax;
    // 0045dcbc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045dcbe  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045dcc1  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0045dcc3  bb00000600             -mov ebx, 0x60000
    cpu.ebx = 393216 /*0x60000*/;
    // 0045dcc8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045dcca  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045dccc  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 0045dcce  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045dccf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dcd1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045dcd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dcd5  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045dcd9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045dcdc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045dcde  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045dce1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045dce3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045dce7  8b54240e               -mov edx, dword ptr [esp + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 0045dceb  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dced  42                     -inc edx
    (cpu.edx)++;
    // 0045dcee  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0045dcf1  668954240e             -mov word ptr [esp + 0xe], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 0045dcf6  898588f64f00           -mov dword ptr [ebp + 0x4ff688], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5240456) /* 0x4ff688 */) = cpu.eax;
    // 0045dcfc  83fd50                 +cmp ebp, 0x50
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045dcff  0f8530ffffff           -jne 0x45dc35
    if (!cpu.flags.zf)
    {
        goto L_0x0045dc35;
    }
    // 0045dd05  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045dd08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45dd10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045dd10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045dd11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045dd12  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045dd14  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045dd16  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0045dd18  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0045dd1a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045dd1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045dd1e  7e21                   -jle 0x45dd41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045dd41;
    }
L_0x0045dd20:
    // 0045dd20  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045dd22  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0045dd25  2b4108                 -sub eax, dword ptr [ecx + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 0045dd28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045dd2a  7e19                   -jle 0x45dd45
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045dd45;
    }
L_0x0045dd2c:
    // 0045dd2c  39c2                   +cmp edx, eax
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
    // 0045dd2e  7e19                   -jle 0x45dd49
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045dd49;
    }
    // 0045dd30  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0045dd33  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045dd35  39d8                   +cmp eax, ebx
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
    // 0045dd37  7d21                   -jge 0x45dd5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045dd5a;
    }
    // 0045dd39  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045dd3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045dd41:
    // 0045dd41  f7d8                   +neg eax
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
    // 0045dd43  ebdb                   -jmp 0x45dd20
    goto L_0x0045dd20;
L_0x0045dd45:
    // 0045dd45  f7d8                   +neg eax
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
    // 0045dd47  ebe3                   -jmp 0x45dd2c
    goto L_0x0045dd2c;
L_0x0045dd49:
    // 0045dd49  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0045dd4c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045dd4e  39d8                   +cmp eax, ebx
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
    // 0045dd50  7d08                   -jge 0x45dd5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045dd5a;
    }
    // 0045dd52  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045dd57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045dd5a:
    // 0045dd5a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dd5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45dd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045dd60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045dd61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045dd62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045dd63  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045dd69  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045dd6b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045dd6c  b32f                   -mov bl, 0x2f
    cpu.bl = 47 /*0x2f*/;
    // 0045dd6e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045dd70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045dd72:
    // 0045dd72  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dd74  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0045dd76  e855000000             -call 0x45ddd0
    cpu.esp -= 4;
    sub_45ddd0(app, cpu);
    if (cpu.terminate) return;
    // 0045dd7b  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0045dd7d  7418                   -je 0x45dd97
    if (cpu.flags.zf)
    {
        goto L_0x0045dd97;
    }
    // 0045dd7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045dd80:
    // 0045dd80  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dd82  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0045dd84  e847000000             -call 0x45ddd0
    cpu.esp -= 4;
    sub_45ddd0(app, cpu);
    if (cpu.terminate) return;
    // 0045dd89  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0045dd8b  741e                   -je 0x45ddab
    if (cpu.flags.zf)
    {
        goto L_0x0045ddab;
    }
    // 0045dd8d  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045dd8e  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0045dd90  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045dd91  88440cff               -mov byte ptr [esp + ecx - 1], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1) = cpu.al;
    // 0045dd95  ebe9                   -jmp 0x45dd80
    goto L_0x0045dd80;
L_0x0045dd97:
    // 0045dd97  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045dd99  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 0045dd9b  42                     -inc edx
    (cpu.edx)++;
    // 0045dd9c  38fb                   +cmp bl, bh
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
    // 0045dd9e  75d2                   -jne 0x45dd72
    if (!cpu.flags.zf)
    {
        goto L_0x0045dd72;
    }
L_0x0045dda0:
    // 0045dda0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045dda2  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 0045dda4  42                     -inc edx
    (cpu.edx)++;
    // 0045dda5  38fb                   +cmp bl, bh
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
    // 0045dda7  75f7                   -jne 0x45dda0
    if (!cpu.flags.zf)
    {
        goto L_0x0045dda0;
    }
    // 0045dda9  ebc7                   -jmp 0x45dd72
    goto L_0x0045dd72;
L_0x0045ddab:
    // 0045ddab  88040c                 -mov byte ptr [esp + ecx], al
    app->getMemory<x86::reg8>(cpu.esp + cpu.ecx * 1) = cpu.al;
    // 0045ddae  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045ddb0  e841270300             -call 0x4904f6
    cpu.esp -= 4;
    sub_4904f6(app, cpu);
    if (cpu.terminate) return;
    // 0045ddb5  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0045ddb7  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045ddbd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ddd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ddd0  3c30                   +cmp al, 0x30
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
    // 0045ddd2  7204                   -jb 0x45ddd8
    if (cpu.flags.cf)
    {
        goto L_0x0045ddd8;
    }
    // 0045ddd4  3c39                   +cmp al, 0x39
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
    // 0045ddd6  7608                   -jbe 0x45dde0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045dde0;
    }
L_0x0045ddd8:
    // 0045ddd8  3c2d                   +cmp al, 0x2d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045ddda  7404                   -je 0x45dde0
    if (cpu.flags.zf)
    {
        goto L_0x0045dde0;
    }
    // 0045dddc  3c2b                   +cmp al, 0x2b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045ddde  7503                   -jne 0x45dde3
    if (!cpu.flags.zf)
    {
        goto L_0x0045dde3;
    }
L_0x0045dde0:
    // 0045dde0  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0045dde2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045dde3:
    // 0045dde3  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0045dde5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ddf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ddf0  a17cf74f00             -mov eax, dword ptr [0x4ff77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240700) /* 0x4ff77c */);
    // 0045ddf5  e892c80100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0045ddfa  a180f74f00             -mov eax, dword ptr [0x4ff780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240704) /* 0x4ff780 */);
    // 0045ddff  e988c80100             -jmp 0x47a68c
    return sub_47a68c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45de10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045de10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045de11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045de12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045de13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045de14  ba2cd24b00             -mov edx, 0x4bd22c
    cpu.edx = 4969004 /*0x4bd22c*/;
    // 0045de19  b9d0000000             -mov ecx, 0xd0
    cpu.ecx = 208 /*0xd0*/;
    // 0045de1e  b84cd24b00             -mov eax, 0x4bd24c
    cpu.eax = 4969036 /*0x4bd24c*/;
    // 0045de23  bed1000000             -mov esi, 0xd1
    cpu.esi = 209 /*0xd1*/;
    // 0045de28  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045de2a  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0045de30  ba60130000             -mov edx, 0x1360
    cpu.edx = 4960 /*0x1360*/;
    // 0045de35  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0045de3b  e8e8c30100             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0045de40  bb2cd24b00             -mov ebx, 0x4bd22c
    cpu.ebx = 4969004 /*0x4bd22c*/;
    // 0045de45  ba60130000             -mov edx, 0x1360
    cpu.edx = 4960 /*0x1360*/;
    // 0045de4a  a37cf74f00             -mov dword ptr [0x4ff77c], eax
    app->getMemory<x86::reg32>(x86::reg32(5240700) /* 0x4ff77c */) = cpu.eax;
    // 0045de4f  b864d24b00             -mov eax, 0x4bd264
    cpu.eax = 4969060 /*0x4bd264*/;
    // 0045de54  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 0045de5a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045de5c  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 0045de62  e8c1c30100             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0045de67  a380f74f00             -mov dword ptr [0x4ff780], eax
    app->getMemory<x86::reg32>(x86::reg32(5240704) /* 0x4ff780 */) = cpu.eax;
    // 0045de6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045de6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045de6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045de6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045de70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45de80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045de80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045de81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045de82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045de83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045de84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045de85  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045de88  8b2d7cf74f00           -mov ebp, dword ptr [0x4ff77c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5240700) /* 0x4ff77c */);
    // 0045de8e  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0045de92  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045de94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045de96  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045de98:
    // 0045de98  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0045de9a  833c0200               +cmp dword ptr [edx + eax], 0
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
    // 0045de9e  752c                   -jne 0x45decc
    if (!cpu.flags.zf)
    {
        goto L_0x0045decc;
    }
L_0x0045dea0:
    // 0045dea0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045dea3  3d60130000             +cmp eax, 0x1360
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4960 /*0x1360*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045dea8  75ee                   -jne 0x45de98
    if (!cpu.flags.zf)
    {
        goto L_0x0045de98;
    }
    // 0045deaa  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045deae  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045deb0  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0045deb4  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0045deb7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045deb8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045deb9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045debd  892d7cf74f00           -mov dword ptr [0x4ff77c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5240700) /* 0x4ff77c */) = cpu.ebp;
    // 0045dec3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045dec6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dec7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dec8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dec9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045deca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045decb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045decc:
    // 0045decc  8b1580f74f00           -mov edx, dword ptr [0x4ff780]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240704) /* 0x4ff780 */);
    // 0045ded2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045ded4  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0045ded6  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0045ded8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045deda  7502                   -jne 0x45dede
    if (!cpu.flags.zf)
    {
        goto L_0x0045dede;
    }
    // 0045dedc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
L_0x0045dede:
    // 0045dede  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0045dee0  8b1c02                 -mov ebx, dword ptr [edx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 0045dee3  ebbb                   -jmp 0x45dea0
    goto L_0x0045dea0;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45def0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045def0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045def1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045def2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045def3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045def6  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045defa  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045defc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045defe  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045df02  81ef00000a00           -sub edi, 0xa0000
    (cpu.edi) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0045df08  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045df0a  7442                   -je 0x45df4e
    if (cpu.flags.zf)
    {
        goto L_0x0045df4e;
    }
    // 0045df0c  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0045df0e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045df10  0f8eb2000000           -jle 0x45dfc8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045dfc8;
    }
    // 0045df16  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
L_0x0045df18:
    // 0045df18  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045df1b  7e31                   -jle 0x45df4e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045df4e;
    }
    // 0045df1d  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0045df1f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045df21  0f8eaa000000           -jle 0x45dfd1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045dfd1;
    }
L_0x0045df27:
    // 0045df27  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045df2a  7e22                   -jle 0x45df4e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045df4e;
    }
    // 0045df2c  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0045df2e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045df30  0f8ea2000000           -jle 0x45dfd8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045dfd8;
    }
L_0x0045df36:
    // 0045df36  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045df39  7e13                   -jle 0x45df4e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045df4e;
    }
    // 0045df3b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0045df3d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045df3f  0f8e9a000000           -jle 0x45dfdf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045dfdf;
    }
L_0x0045df45:
    // 0045df45  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045df48  0f8fad000000           -jg 0x45dffb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045dffb;
    }
L_0x0045df4e:
    // 0045df4e  8b480a                 -mov ecx, dword ptr [eax + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0045df51  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045df54  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0045df57  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045df59  8b4e0a                 -mov ecx, dword ptr [esi + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0045df5c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045df5f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045df62  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0045df65  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0045df68  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045df6a  8b4b0a                 -mov ecx, dword ptr [ebx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0045df6d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045df6f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045df72  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0045df75  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045df77  8b4a0a                 -mov ecx, dword ptr [edx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0045df7a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045df7d  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0045df80  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045df82  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0045df84  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045df86  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0045df89  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0045df8b  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0045df8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045df90  7c69                   -jl 0x45dffb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045dffb;
    }
    // 0045df92  3dd7040000             +cmp eax, 0x4d7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1239 /*0x4d7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045df97  7f62                   -jg 0x45dffb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045dffb;
    }
    // 0045df99  8b157cf74f00           -mov edx, dword ptr [0x4ff77c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240700) /* 0x4ff77c */);
    // 0045df9f  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0045dfa6  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045dfa8  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0045dfaa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045dfac  7438                   -je 0x45dfe6
    if (cpu.flags.zf)
    {
        goto L_0x0045dfe6;
    }
    // 0045dfae  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045dfb2  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0045dfb4  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045dfb8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0045dfba:
    // 0045dfba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045dfbf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045dfc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dfc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dfc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dfc5  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0045dfc8:
    // 0045dfc8  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0045dfca  f7d9                   +neg ecx
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
    // 0045dfcc  e947ffffff             -jmp 0x45df18
    goto L_0x0045df18;
L_0x0045dfd1:
    // 0045dfd1  f7d9                   +neg ecx
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
    // 0045dfd3  e94fffffff             -jmp 0x45df27
    goto L_0x0045df27;
L_0x0045dfd8:
    // 0045dfd8  f7d9                   +neg ecx
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
    // 0045dfda  e957ffffff             -jmp 0x45df36
    goto L_0x0045df36;
L_0x0045dfdf:
    // 0045dfdf  f7d9                   +neg ecx
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
    // 0045dfe1  e95fffffff             -jmp 0x45df45
    goto L_0x0045df45;
L_0x0045dfe6:
    // 0045dfe6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045dfea  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045dfec  a180f74f00             -mov eax, dword ptr [0x4ff780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240704) /* 0x4ff780 */);
    // 0045dff1  01c1                   +add ecx, eax
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
    // 0045dff3  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045dff7  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0045dff9  ebbf                   -jmp 0x45dfba
    goto L_0x0045dfba;
L_0x0045dffb:
    // 0045dffb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dffd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e000  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e001  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e002  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e003  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e010  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e011  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e012  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e013  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e016  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045e01a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0045e01c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045e020  81e900000a00           -sub ecx, 0xa0000
    (cpu.ecx) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0045e026  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0045e028  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0045e02c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045e02e  0f8ead000000           -jle 0x45e0e1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e0e1;
    }
    // 0045e034  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
L_0x0045e036:
    // 0045e036  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e039  7e31                   -jle 0x45e06c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e06c;
    }
    // 0045e03b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0045e03d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e03f  0f8ea5000000           -jle 0x45e0ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e0ea;
    }
L_0x0045e045:
    // 0045e045  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e048  7e22                   -jle 0x45e06c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e06c;
    }
    // 0045e04a  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0045e04c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e04e  0f8e9d000000           -jle 0x45e0f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e0f1;
    }
L_0x0045e054:
    // 0045e054  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e057  7e13                   -jle 0x45e06c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e06c;
    }
    // 0045e059  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0045e05b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e05d  0f8e95000000           -jle 0x45e0f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e0f8;
    }
L_0x0045e063:
    // 0045e063  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e066  0f8fa1000000           -jg 0x45e10d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045e10d;
    }
L_0x0045e06c:
    // 0045e06c  8b480a                 -mov ecx, dword ptr [eax + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0045e06f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045e072  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0045e075  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045e077  8b4a0a                 -mov ecx, dword ptr [edx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0045e07a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045e07d  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045e080  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0045e083  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0045e086  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045e088  8b4b0a                 -mov ecx, dword ptr [ebx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0045e08b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045e08d  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045e090  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0045e093  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045e095  8b4e0a                 -mov ecx, dword ptr [esi + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0045e098  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045e09a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045e09d  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0045e0a0  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045e0a2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045e0a4  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045e0a8  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0045e0ab  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045e0ad  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0045e0b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e0b2  7c59                   -jl 0x45e10d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e10d;
    }
    // 0045e0b4  3dd7040000             +cmp eax, 0x4d7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1239 /*0x4d7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e0b9  7f52                   -jg 0x45e10d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045e10d;
    }
    // 0045e0bb  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0045e0c2  a17cf74f00             -mov eax, dword ptr [0x4ff77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240700) /* 0x4ff77c */);
    // 0045e0c7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045e0c9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045e0cb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e0cd  7430                   -je 0x45e0ff
    if (cpu.flags.zf)
    {
        goto L_0x0045e0ff;
    }
    // 0045e0cf  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0045e0d1  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
L_0x0045e0d3:
    // 0045e0d3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e0d8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e0db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e0dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e0dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e0de  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0045e0e1:
    // 0045e0e1  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0045e0e3  f7d9                   +neg ecx
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
    // 0045e0e5  e94cffffff             -jmp 0x45e036
    goto L_0x0045e036;
L_0x0045e0ea:
    // 0045e0ea  f7d9                   +neg ecx
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
    // 0045e0ec  e954ffffff             -jmp 0x45e045
    goto L_0x0045e045;
L_0x0045e0f1:
    // 0045e0f1  f7d9                   +neg ecx
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
    // 0045e0f3  e95cffffff             -jmp 0x45e054
    goto L_0x0045e054;
L_0x0045e0f8:
    // 0045e0f8  f7d9                   +neg ecx
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
    // 0045e0fa  e964ffffff             -jmp 0x45e063
    goto L_0x0045e063;
L_0x0045e0ff:
    // 0045e0ff  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0045e101  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0045e103  a180f74f00             -mov eax, dword ptr [0x4ff780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240704) /* 0x4ff780 */);
    // 0045e108  893c02                 -mov dword ptr [edx + eax], edi
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = cpu.edi;
    // 0045e10b  ebc6                   -jmp 0x45e0d3
    goto L_0x0045e0d3;
L_0x0045e10d:
    // 0045e10d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e10f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e112  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e113  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e114  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e115  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e121  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e122  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e123  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e124  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e125  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e126  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045e129  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0045e12d  81ea00000a00           -sub edx, 0xa0000
    (cpu.edx) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0045e133  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0045e137  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0045e13b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e13d  7452                   -je 0x45e191
    if (cpu.flags.zf)
    {
        goto L_0x0045e191;
    }
L_0x0045e13f:
    // 0045e13f  8b6c2430               -mov ebp, dword ptr [esp + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0045e143  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045e145  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0045e148  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0045e14b  8b7814                 -mov edi, dword ptr [eax + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0045e14e  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0045e152  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0045e155  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045e157  0f8450000000           -je 0x45e1ad
    if (cpu.flags.zf)
    {
        goto L_0x0045e1ad;
    }
    // 0045e15d  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0045e15f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e161  7e3a                   -jle 0x45e19d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e19d;
    }
L_0x0045e163:
    // 0045e163  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e166  7e45                   -jle 0x45e1ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e1ad;
    }
    // 0045e168  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0045e16a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e16c  7e33                   -jle 0x45e1a1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e1a1;
    }
L_0x0045e16e:
    // 0045e16e  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e171  7e3a                   -jle 0x45e1ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e1ad;
    }
    // 0045e173  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0045e175  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e177  7e2c                   -jle 0x45e1a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e1a5;
    }
L_0x0045e179:
    // 0045e179  3b4f08                 +cmp ecx, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e17c  7e2f                   -jle 0x45e1ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e1ad;
    }
    // 0045e17e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0045e180  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e182  7e25                   -jle 0x45e1a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e1a9;
    }
L_0x0045e184:
    // 0045e184  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e187  7e24                   -jle 0x45e1ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e1ad;
    }
L_0x0045e189:
    // 0045e189  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045e18d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e18f  75ae                   -jne 0x45e13f
    if (!cpu.flags.zf)
    {
        goto L_0x0045e13f;
    }
L_0x0045e191:
    // 0045e191  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045e194  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e195  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e196  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e197  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e198  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e199  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e19a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0045e19d:
    // 0045e19d  f7d9                   +neg ecx
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
    // 0045e19f  ebc2                   -jmp 0x45e163
    goto L_0x0045e163;
L_0x0045e1a1:
    // 0045e1a1  f7d9                   +neg ecx
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
    // 0045e1a3  ebc9                   -jmp 0x45e16e
    goto L_0x0045e16e;
L_0x0045e1a5:
    // 0045e1a5  f7d9                   +neg ecx
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
    // 0045e1a7  ebd0                   -jmp 0x45e179
    goto L_0x0045e179;
L_0x0045e1a9:
    // 0045e1a9  f7d9                   +neg ecx
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
    // 0045e1ab  ebd7                   -jmp 0x45e184
    goto L_0x0045e184;
L_0x0045e1ad:
    // 0045e1ad  8b4b0a                 -mov ecx, dword ptr [ebx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0045e1b0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045e1b3  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0045e1b6  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0045e1b8  8b4e0a                 -mov ecx, dword ptr [esi + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0045e1bb  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0045e1be  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045e1c1  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0045e1c4  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0045e1c6  031c24                 -add ebx, dword ptr [esp]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0045e1c9  8b4f0a                 -mov ecx, dword ptr [edi + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0045e1cc  8b7708                 -mov esi, dword ptr [edi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0045e1cf  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045e1d2  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0045e1d4  8b4a0a                 -mov ecx, dword ptr [edx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0045e1d7  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045e1da  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0045e1dd  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045e1df  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0045e1e1  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e1e3  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0045e1e7  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0045e1ea  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e1ec  c1fa0f                 -sar edx, 0xf
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (15 /*0xf*/ % 32));
    // 0045e1ef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045e1f1  7c96                   -jl 0x45e189
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e189;
    }
    // 0045e1f3  81fad7040000           +cmp edx, 0x4d7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1239 /*0x4d7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e1f9  7f8e                   -jg 0x45e189
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045e189;
    }
    // 0045e1fb  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0045e202  8b157cf74f00           -mov edx, dword ptr [0x4ff77c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240700) /* 0x4ff77c */);
    // 0045e208  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045e20a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0045e20c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045e20e  7409                   -je 0x45e219
    if (cpu.flags.zf)
    {
        goto L_0x0045e219;
    }
    // 0045e210  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0045e212  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045e214  e970ffffff             -jmp 0x45e189
    goto L_0x0045e189;
L_0x0045e219:
    // 0045e219  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0045e21b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045e21d  8b1580f74f00           -mov edx, dword ptr [0x4ff780]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240704) /* 0x4ff780 */);
    // 0045e223  890411                 -mov dword ptr [ecx + edx], eax
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.eax;
    // 0045e226  e95effffff             -jmp 0x45e189
    goto L_0x0045e189;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e231  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e232  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0045e239  a17cf74f00             -mov eax, dword ptr [0x4ff77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240700) /* 0x4ff77c */);
    // 0045e23e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045e240  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045e242  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045e244  7407                   -je 0x45e24d
    if (cpu.flags.zf)
    {
        goto L_0x0045e24d;
    }
    // 0045e246  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0045e248  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0045e24a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e24b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e24c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e24d:
    // 0045e24d  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0045e24f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0045e251  a180f74f00             -mov eax, dword ptr [0x4ff780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240704) /* 0x4ff780 */);
    // 0045e256  891401                 -mov dword ptr [ecx + eax], edx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.edx;
    // 0045e259  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e25a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e25b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_45e260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e260  0500000a00             -add eax, 0xa0000
    (cpu.eax) += x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0045e265  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0045e268  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e270  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e271  ba60130000             -mov edx, 0x1360
    cpu.edx = 4960 /*0x1360*/;
    // 0045e276  a17cf74f00             -mov eax, dword ptr [0x4ff77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240700) /* 0x4ff77c */);
    // 0045e27b  e81c2a0200             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0045e280  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e281  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e291  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e292  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e293  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e294  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045e296  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045e299  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045e29b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045e29d  7e13                   -jle 0x45e2b2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e2b2;
    }
    // 0045e29f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0045e2a1:
    // 0045e2a1  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e2a5  7510                   -jne 0x45e2b7
    if (!cpu.flags.zf)
    {
        goto L_0x0045e2b7;
    }
    // 0045e2a7  41                     -inc ecx
    (cpu.ecx)++;
    // 0045e2a8  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0045e2ab  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e2ae  39d9                   +cmp ecx, ebx
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
    // 0045e2b0  7cef                   -jl 0x45e2a1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e2a1;
    }
L_0x0045e2b2:
    // 0045e2b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e2b7:
    // 0045e2b7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0045e2b9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0045e2bc  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0045e2bf  41                     -inc ecx
    (cpu.ecx)++;
    // 0045e2c0  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0045e2c3  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e2c6  39d9                   +cmp ecx, ebx
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
    // 0045e2c8  7cd7                   -jl 0x45e2a1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e2a1;
    }
    // 0045e2ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45e2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e2d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e2d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e2d2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e2d5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045e2d8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0045e2da  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045e2dc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0045e2df  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0045e2e2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e2e4  0f8481000000           -je 0x45e36b
    if (cpu.flags.zf)
    {
        goto L_0x0045e36b;
    }
    // 0045e2ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e2eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e2ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e2ee  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e2f0  7e5d                   -jle 0x45e34f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e34f;
    }
L_0x0045e2f2:
    // 0045e2f2  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 0045e2f5  7549                   -jne 0x45e340
    if (!cpu.flags.zf)
    {
        goto L_0x0045e340;
    }
    // 0045e2f7  3b6a10                 +cmp ebp, dword ptr [edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e2fa  7544                   -jne 0x45e340
    if (!cpu.flags.zf)
    {
        goto L_0x0045e340;
    }
    // 0045e2fc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e300  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045e302  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045e305  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0045e308  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0045e30a  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0045e30d  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e310  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0045e312:
    // 0045e312  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e316  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045e319  48                     -dec eax
    (cpu.eax)--;
    // 0045e31a  39c5                   +cmp ebp, eax
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
    // 0045e31c  7d31                   -jge 0x45e34f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045e34f;
    }
    // 0045e31e  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045e323  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045e325  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0045e327  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e328  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e32a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045e32d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045e32f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045e331  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045e334  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045e336  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e337  45                     -inc ebp
    (cpu.ebp)++;
    // 0045e338  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e33b  83c210                 +add edx, 0x10
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045e33e  ebd2                   -jmp 0x45e312
    goto L_0x0045e312;
L_0x0045e340:
    // 0045e340  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e344  43                     -inc ebx
    (cpu.ebx)++;
    // 0045e345  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0045e348  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e34b  39fb                   +cmp ebx, edi
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
    // 0045e34d  7ca3                   -jl 0x45e2f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e2f2;
    }
L_0x0045e34f:
    // 0045e34f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e353  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045e356  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e35a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045e35d  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0045e35f  c74008fe7f0000         -mov dword ptr [eax + 8], 0x7ffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 32766 /*0x7ffe*/;
    // 0045e366  ff4f04                 -dec dword ptr [edi + 4]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))--;
    // 0045e369  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e36a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045e36b:
    // 0045e36b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e36e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e36f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e370  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e380  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e381  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e382  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e383  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0045e386  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0045e38a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0045e38e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0045e391  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0045e395  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045e398  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045e39a  41                     -inc ecx
    (cpu.ecx)++;
    // 0045e39b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0045e39f  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0045e3a2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e3a4  7e22                   -jle 0x45e3c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e3c8;
    }
    // 0045e3a6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0045e3a8:
    // 0045e3a8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e3ac  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0045e3af  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0045e3b3  39f8                   +cmp eax, edi
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
    // 0045e3b5  7c39                   -jl 0x45e3f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e3f0;
    }
    // 0045e3b7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045e3bb  42                     -inc edx
    (cpu.edx)++;
    // 0045e3bc  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045e3bf  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e3c2  39f2                   +cmp edx, esi
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
    // 0045e3c4  7ce2                   -jl 0x45e3a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e3a8;
    }
    // 0045e3c6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0045e3c8:
    // 0045e3c8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045e3cc  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045e3d0  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0045e3d3  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e3d5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e3d9  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0045e3dc  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045e3e0  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0045e3e3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0045e3e6  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0045e3e9  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0045e3ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e3ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e3ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e3ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e3f0:
    // 0045e3f0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045e3f4  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045e3f7  48                     -dec eax
    (cpu.eax)--;
    // 0045e3f8  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0045e3fc  39c2                   +cmp edx, eax
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
    // 0045e3fe  7dc8                   -jge 0x45e3c8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045e3c8;
    }
    // 0045e400  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045e404  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045e408  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0045e40b  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045e40e  8d2c03                 -lea ebp, [ebx + eax]
    cpu.ebp = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0045e411  83eb10                 -sub ebx, 0x10
    (cpu.ebx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e414  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0045e416:
    // 0045e416  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045e41b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0045e41d  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0045e41f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e420  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e422  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045e425  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045e427  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045e429  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045e42c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045e42e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e42f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045e433  83ed10                 -sub ebp, 0x10
    (cpu.ebp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e436  48                     -dec eax
    (cpu.eax)--;
    // 0045e437  83eb10                 -sub ebx, 0x10
    (cpu.ebx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e43a  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0045e43e  39c2                   +cmp edx, eax
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
    // 0045e440  7cd4                   -jl 0x45e416
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e416;
    }
    // 0045e442  eb84                   -jmp 0x45e3c8
    goto L_0x0045e3c8;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e450  e937c20100             -jmp 0x47a68c
    return sub_47a68c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e460  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e461  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e462  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e463  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045e465  c70578a64c007cd24b00   -mov dword ptr [0x4ca678], 0x4bd27c
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = 4969084 /*0x4bd27c*/;
    // 0045e46f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045e471  b956000000             -mov ecx, 0x56
    cpu.ecx = 86 /*0x56*/;
    // 0045e476  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0045e479  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e47b  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0045e47e  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0045e484  e89fbd0100             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0045e489  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0045e490  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0045e492  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045e494  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045e496  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045e498  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045e49a  7e18                   -jle 0x45e4b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e4b4;
    }
L_0x0045e49c:
    // 0045e49c  c74008fe7f0000         -mov dword ptr [eax + 8], 0x7ffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 32766 /*0x7ffe*/;
    // 0045e4a3  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0045e4aa  42                     -inc edx
    (cpu.edx)++;
    // 0045e4ab  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0045e4ad  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e4b0  39f2                   +cmp edx, esi
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
    // 0045e4b2  7ce8                   -jl 0x45e49c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e49c;
    }
L_0x0045e4b4:
    // 0045e4b4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e4b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e4b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e4b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e4b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e4c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e4c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e4c2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045e4c4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045e4c6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045e4c8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0045e4ca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045e4cc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045e4cf  c1e204                 +shl edx, 4
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
    // 0045e4d2  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045e4d4  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0045e4d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045e4d9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045e4dc  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045e4df  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045e4e1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045e4e4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045e4e6  83f814                 +cmp eax, 0x14
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
    // 0045e4e9  7c05                   -jl 0x45e4f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e4f0;
    }
    // 0045e4eb  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x0045e4f0:
    // 0045e4f0  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0045e4f7  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045e4f9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045e4fc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045e4fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e500  8a82888c4c00           -mov al, byte ptr [edx + 0x4c8c88]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5016712) /* 0x4c8c88 */);
    // 0045e506  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045e509  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045e50d  8b90188c4c00           -mov edx, dword ptr [eax + 0x4c8c18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5016600) /* 0x4c8c18 */);
    // 0045e513  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0045e515  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045e519  8b90508c4c00           -mov edx, dword ptr [eax + 0x4c8c50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5016656) /* 0x4c8c50 */);
    // 0045e51f  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0045e521  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045e525  8b90348c4c00           -mov edx, dword ptr [eax + 0x4c8c34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5016628) /* 0x4c8c34 */);
    // 0045e52b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0045e52d  833dc4f74f0000         +cmp dword ptr [0x4ff7c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e534  7525                   -jne 0x45e55b
    if (!cpu.flags.zf)
    {
        goto L_0x0045e55b;
    }
    // 0045e536  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045e538:
    // 0045e538  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045e53d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045e53f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045e542  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045e544  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045e546  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0045e549  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e54b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045e54d  39c8                   +cmp eax, ecx
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
    // 0045e54f  7512                   -jne 0x45e563
    if (!cpu.flags.zf)
    {
        goto L_0x0045e563;
    }
    // 0045e551  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e556  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e557  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e558  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0045e55b:
    // 0045e55b  8b886c8c4c00           -mov ecx, dword ptr [eax + 0x4c8c6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5016684) /* 0x4c8c6c */);
    // 0045e561  ebd5                   -jmp 0x45e538
    goto L_0x0045e538;
L_0x0045e563:
    // 0045e563  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e565  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e566  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e567  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e572  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e573  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e574  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e575  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e576  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045e579  b406                   -mov ah, 6
    cpu.ah = 6 /*0x6*/;
    // 0045e57b  be6c024e00             -mov esi, 0x4e026c
    cpu.esi = 5112428 /*0x4e026c*/;
    // 0045e580  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e584  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0045e589  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045e58b  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0045e58e  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 0045e593  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045e597  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045e598:
    // 0045e598  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045e59a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045e59c  3c00                   +cmp al, 0
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
    // 0045e59e  7410                   -je 0x45e5b0
    if (cpu.flags.zf)
    {
        goto L_0x0045e5b0;
    }
    // 0045e5a0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045e5a3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045e5a6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045e5a9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045e5ac  3c00                   +cmp al, 0
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
    // 0045e5ae  75e8                   -jne 0x45e598
    if (!cpu.flags.zf)
    {
        goto L_0x0045e598;
    }
L_0x0045e5b0:
    // 0045e5b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e5b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e5b3  e81832ffff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
    // 0045e5b8  66833d50074e0000       +cmp word ptr [0x4e0750], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113680) /* 0x4e0750 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e5c0  7517                   -jne 0x45e5d9
    if (!cpu.flags.zf)
    {
        goto L_0x0045e5d9;
    }
L_0x0045e5c2:
    // 0045e5c2  e80930ffff             -call 0x4515d0
    cpu.esp -= 4;
    sub_4515d0(app, cpu);
    if (cpu.terminate) return;
    // 0045e5c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e5c9  0f85a3000000           -jne 0x45e672
    if (!cpu.flags.zf)
    {
        goto L_0x0045e672;
    }
    // 0045e5cf  66833d50074e0000       +cmp word ptr [0x4e0750], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113680) /* 0x4e0750 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e5d7  74e9                   -je 0x45e5c2
    if (cpu.flags.zf)
    {
        goto L_0x0045e5c2;
    }
L_0x0045e5d9:
    // 0045e5d9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045e5db  8a157e074e00           -mov dl, byte ptr [0x4e077e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */);
    // 0045e5e1  66890d50074e00         -mov word ptr [0x4e0750], cx
    app->getMemory<x86::reg16>(x86::reg32(5113680) /* 0x4e0750 */) = cpu.cx;
    // 0045e5e8  80fa02                 +cmp dl, 2
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045e5eb  0f8509010000           -jne 0x45e6fa
    if (!cpu.flags.zf)
    {
        goto L_0x0045e6fa;
    }
    // 0045e5f1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045e5f5  8b1588f74f00           -mov edx, dword ptr [0x4ff788]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240712) /* 0x4ff788 */);
    // 0045e5fb  39d0                   +cmp eax, edx
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
    // 0045e5fd  7e77                   -jle 0x45e676
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e676;
    }
    // 0045e5ff  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045e604  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045e606  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e608  892d2cf54d00           -mov dword ptr [0x4df52c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */) = cpu.ebp;
L_0x0045e60e:
    // 0045e60e  66a32c074e00           -mov word ptr [0x4e072c], ax
    app->getMemory<x86::reg16>(x86::reg32(5113644) /* 0x4e072c */) = cpu.ax;
    // 0045e614  66893d78074e00         -mov word ptr [0x4e0778], di
    app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */) = cpu.di;
L_0x0045e61b:
    // 0045e61b  be8cf74f00             -mov esi, 0x4ff78c
    cpu.esi = 5240716 /*0x4ff78c*/;
    // 0045e620  bf98064e00             -mov edi, 0x4e0698
    cpu.edi = 5113496 /*0x4e0698*/;
    // 0045e625  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045e626:
    // 0045e626  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045e628  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045e62a  3c00                   +cmp al, 0
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
    // 0045e62c  7410                   -je 0x45e63e
    if (cpu.flags.zf)
    {
        goto L_0x0045e63e;
    }
    // 0045e62e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045e631  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045e634  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045e637  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045e63a  3c00                   +cmp al, 0
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
    // 0045e63c  75e8                   -jne 0x45e626
    if (!cpu.flags.zf)
    {
        goto L_0x0045e626;
    }
L_0x0045e63e:
    // 0045e63e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e63f  be6c024e00             -mov esi, 0x4e026c
    cpu.esi = 5112428 /*0x4e026c*/;
    // 0045e644  bfe1064e00             -mov edi, 0x4e06e1
    cpu.edi = 5113569 /*0x4e06e1*/;
    // 0045e649  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045e64a:
    // 0045e64a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045e64c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045e64e  3c00                   +cmp al, 0
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
    // 0045e650  7410                   -je 0x45e662
    if (cpu.flags.zf)
    {
        goto L_0x0045e662;
    }
    // 0045e652  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045e655  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045e658  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045e65b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045e65e  3c00                   +cmp al, 0
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
    // 0045e660  75e8                   -jne 0x45e64a
    if (!cpu.flags.zf)
    {
        goto L_0x0045e64a;
    }
L_0x0045e662:
    // 0045e662  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e663  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0045e668:
    // 0045e668  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045e66b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e66c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e66d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e66e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e66f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e670  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e671  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e672:
    // 0045e672  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045e674  ebf2                   -jmp 0x45e668
    goto L_0x0045e668;
L_0x0045e676:
    // 0045e676  7d2d                   -jge 0x45e6a5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045e6a5;
    }
    // 0045e678  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045e67d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045e682  66890d78074e00         -mov word ptr [0x4e0778], cx
    app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */) = cpu.cx;
    // 0045e689  893d2cf54d00           -mov dword ptr [0x4df52c], edi
    app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */) = cpu.edi;
    // 0045e68f  6689352c074e00         -mov word ptr [0x4e072c], si
    app->getMemory<x86::reg16>(x86::reg32(5113644) /* 0x4e072c */) = cpu.si;
    // 0045e696  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e69b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045e69e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e69f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e6a5:
    // 0045e6a5  ba8cf74f00             -mov edx, 0x4ff78c
    cpu.edx = 5240716 /*0x4ff78c*/;
    // 0045e6aa  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e6ae  e8fdad0100             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 0045e6b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e6b5  7c16                   -jl 0x45e6cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e6cd;
    }
    // 0045e6b7  7eb9                   -jle 0x45e672
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e672;
    }
    // 0045e6b9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045e6be  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e6c0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045e6c2  891d2cf54d00           -mov dword ptr [0x4df52c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */) = cpu.ebx;
    // 0045e6c8  e941ffffff             -jmp 0x45e60e
    goto L_0x0045e60e;
L_0x0045e6cd:
    // 0045e6cd  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045e6d2  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045e6d7  66890d78074e00         -mov word ptr [0x4e0778], cx
    app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */) = cpu.cx;
    // 0045e6de  89352cf54d00           -mov dword ptr [0x4df52c], esi
    app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */) = cpu.esi;
    // 0045e6e4  66891d2c074e00         -mov word ptr [0x4e072c], bx
    app->getMemory<x86::reg16>(x86::reg32(5113644) /* 0x4e072c */) = cpu.bx;
    // 0045e6eb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e6f0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045e6f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e6fa:
    // 0045e6fa  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e702  0f8513ffffff           -jne 0x45e61b
    if (!cpu.flags.zf)
    {
        goto L_0x0045e61b;
    }
    // 0045e708  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e70d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045e710  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e711  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e712  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e713  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e714  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e715  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e716  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e720  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e721  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e722  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e723  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e724  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e725  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045e727  e8d42effff             -call 0x451600
    cpu.esp -= 4;
    sub_451600(app, cpu);
    if (cpu.terminate) return;
    // 0045e72c  e8df31fcff             -call 0x421910
    cpu.esp -= 4;
    sub_421910(app, cpu);
    if (cpu.terminate) return;
    // 0045e731  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0045e736  8a257e074e00           -mov ah, byte ptr [0x4e077e]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */);
    // 0045e73c  66891d2a074e00         -mov word ptr [0x4e072a], bx
    app->getMemory<x86::reg16>(x86::reg32(5113642) /* 0x4e072a */) = cpu.bx;
    // 0045e743  80fc01                 +cmp ah, 1
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
    // 0045e746  0f847e000000           -je 0x45e7ca
    if (cpu.flags.zf)
    {
        goto L_0x0045e7ca;
    }
    // 0045e74c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0045e74e  a3f4034e00             -mov dword ptr [0x4e03f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5112820) /* 0x4e03f4 */) = cpu.eax;
L_0x0045e753:
    // 0045e753  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0045e759  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045e75b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045e75e  c1e204                 +shl edx, 4
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
    // 0045e761  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045e763  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0045e766  8a157e074e00           -mov dl, byte ptr [0x4e077e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */);
    // 0045e76c  a3e4034e00             -mov dword ptr [0x4e03e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5112804) /* 0x4e03e4 */) = cpu.eax;
    // 0045e771  80fa01                 +cmp dl, 1
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045e774  0f8595000000           -jne 0x45e80f
    if (!cpu.flags.zf)
    {
        goto L_0x0045e80f;
    }
    // 0045e77a  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0045e780  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
L_0x0045e785:
    // 0045e785  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045e787  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045e78a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045e78c  a3e8034e00             -mov dword ptr [0x4e03e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5112808) /* 0x4e03e8 */) = cpu.eax;
    // 0045e791  a3ec034e00             -mov dword ptr [0x4e03ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5112812) /* 0x4e03ec */) = cpu.eax;
    // 0045e796  bb09000000             -mov ebx, 9
    cpu.ebx = 9 /*0x9*/;
    // 0045e79b  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 0045e7a0  b8c0034e00             -mov eax, 0x4e03c0
    cpu.eax = 5112768 /*0x4e03c0*/;
    // 0045e7a5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045e7a7  891dfc034e00           -mov dword ptr [0x4e03fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5112828) /* 0x4e03fc */) = cpu.ebx;
    // 0045e7ad  893500044e00           -mov dword ptr [0x4e0400], esi
    app->getMemory<x86::reg32>(x86::reg32(5112832) /* 0x4e0400 */) = cpu.esi;
    // 0045e7b3  893504044e00           -mov dword ptr [0x4e0404], esi
    app->getMemory<x86::reg32>(x86::reg32(5112836) /* 0x4e0404 */) = cpu.esi;
    // 0045e7b9  892d08044e00           -mov dword ptr [0x4e0408], ebp
    app->getMemory<x86::reg32>(x86::reg32(5112840) /* 0x4e0408 */) = cpu.ebp;
    // 0045e7bf  e8ac2fffff             -call 0x451770
    cpu.esp -= 4;
    sub_451770(app, cpu);
    if (cpu.terminate) return;
    // 0045e7c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e7c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e7c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e7c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e7c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e7c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e7ca:
    // 0045e7ca  e88158fcff             -call 0x424050
    cpu.esp -= 4;
    sub_424050(app, cpu);
    if (cpu.terminate) return;
    // 0045e7cf  668b0d78074e00         -mov cx, word ptr [0x4e0778]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
    // 0045e7d6  a3f8034e00             -mov dword ptr [0x4e03f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5112824) /* 0x4e03f8 */) = cpu.eax;
    // 0045e7db  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0045e7de  7413                   -je 0x45e7f3
    if (cpu.flags.zf)
    {
        goto L_0x0045e7f3;
    }
    // 0045e7e0  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045e7e2  891520044e00           -mov dword ptr [0x4e0420], edx
    app->getMemory<x86::reg32>(x86::reg32(5112864) /* 0x4e0420 */) = cpu.edx;
    // 0045e7e8  891524044e00           -mov dword ptr [0x4e0424], edx
    app->getMemory<x86::reg32>(x86::reg32(5112868) /* 0x4e0424 */) = cpu.edx;
    // 0045e7ee  e960ffffff             -jmp 0x45e753
    goto L_0x0045e753;
L_0x0045e7f3:
    // 0045e7f3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045e7f5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e7f8  a324044e00             -mov dword ptr [0x4e0424], eax
    app->getMemory<x86::reg32>(x86::reg32(5112868) /* 0x4e0424 */) = cpu.eax;
    // 0045e7fd  8b422c                 -mov eax, dword ptr [edx + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 0045e800  05a0000000             +add eax, 0xa0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045e805  a320044e00             -mov dword ptr [0x4e0420], eax
    app->getMemory<x86::reg32>(x86::reg32(5112864) /* 0x4e0420 */) = cpu.eax;
    // 0045e80a  e944ffffff             -jmp 0x45e753
    goto L_0x0045e753;
L_0x0045e80f:
    // 0045e80f  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0045e815  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0045e81a  e966ffffff             -jmp 0x45e785
    goto L_0x0045e785;
}

/* align: skip 0x00 */
void Application::sub_45e820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e820  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e821  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e822  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e823  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0045e828  bf84f74f00             -mov edi, 0x4ff784
    cpu.edi = 5240708 /*0x4ff784*/;
    // 0045e82d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045e82f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045e834  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e835  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e837  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045e83a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045e83c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045e83e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045e841  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045e843  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e844  66891550074e00         -mov word ptr [0x4e0750], dx
    app->getMemory<x86::reg16>(x86::reg32(5113680) /* 0x4e0750 */) = cpu.dx;
    // 0045e84b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e84c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e84d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e84e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45e850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e852  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e853  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e854  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045e856  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0045e858  88257f074e00           -mov byte ptr [0x4e077f], ah
    app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */) = cpu.ah;
    // 0045e85e  a0c9004e00             -mov al, byte ptr [0x4e00c9]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5112009) /* 0x4e00c9 */);
    // 0045e863  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e865  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045e867  726c                   -jb 0x45e8d5
    if (cpu.flags.cf)
    {
        goto L_0x0045e8d5;
    }
    // 0045e869  775d                   -ja 0x45e8c8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045e8c8;
    }
    // 0045e86b  c6057e074e0001         -mov byte ptr [0x4e077e], 1
    app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */) = 1 /*0x1*/;
L_0x0045e872:
    // 0045e872  ba07030000             -mov edx, 0x307
    cpu.edx = 775 /*0x307*/;
    // 0045e877  b804030000             -mov eax, 0x304
    cpu.eax = 772 /*0x304*/;
    // 0045e87c  e82f3bfaff             -call 0x4023b0
    cpu.esp -= 4;
    sub_4023b0(app, cpu);
    if (cpu.terminate) return;
    // 0045e881  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045e883  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045e885  e896feffff             -call 0x45e720
    cpu.esp -= 4;
    sub_45e720(app, cpu);
    if (cpu.terminate) return;
    // 0045e88a  a07e074e00             -mov al, byte ptr [0x4e077e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */);
    // 0045e88f  3c01                   +cmp al, 1
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
    // 0045e891  736a                   -jae 0x45e8fd
    if (!cpu.flags.cf)
    {
        goto L_0x0045e8fd;
    }
L_0x0045e893:
    // 0045e893  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045e895  0f859e000000           -jne 0x45e939
    if (!cpu.flags.zf)
    {
        goto L_0x0045e939;
    }
L_0x0045e89b:
    // 0045e89b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045e89d  0f8560010000           -jne 0x45ea03
    if (!cpu.flags.zf)
    {
        goto L_0x0045ea03;
    }
L_0x0045e8a3:
    // 0045e8a3  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0045e8a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e8aa  e8913afaff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0045e8af  e8ec2cffff             -call 0x4515a0
    cpu.esp -= 4;
    sub_4515a0(app, cpu);
    if (cpu.terminate) return;
    // 0045e8b4  e8f8a50100             -call 0x478eb1
    cpu.esp -= 4;
    sub_478eb1(app, cpu);
    if (cpu.terminate) return;
    // 0045e8b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e8bb  0f8425010000           -je 0x45e9e6
    if (cpu.flags.zf)
    {
        goto L_0x0045e9e6;
    }
L_0x0045e8c1:
    // 0045e8c1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045e8c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e8c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e8c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e8c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e8c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e8c8:
    // 0045e8c8  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045e8ca  7509                   -jne 0x45e8d5
    if (!cpu.flags.zf)
    {
        goto L_0x0045e8d5;
    }
    // 0045e8cc  c6057e074e0002         -mov byte ptr [0x4e077e], 2
    app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */) = 2 /*0x2*/;
    // 0045e8d3  eb9d                   -jmp 0x45e872
    goto L_0x0045e872;
L_0x0045e8d5:
    // 0045e8d5  bab4d24b00             -mov edx, 0x4bd2b4
    cpu.edx = 4969140 /*0x4bd2b4*/;
    // 0045e8da  b971000000             -mov ecx, 0x71
    cpu.ecx = 113 /*0x71*/;
    // 0045e8df  68d4d24b00             -push 0x4bd2d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4969172 /*0x4bd2d4*/;
    cpu.esp -= 4;
    // 0045e8e4  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0045e8ea  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0045e8f0  e88bb50100             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0045e8f5  83c404                 +add esp, 4
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
    // 0045e8f8  e975ffffff             -jmp 0x45e872
    goto L_0x0045e872;
L_0x0045e8fd:
    // 0045e8fd  761f                   -jbe 0x45e91e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045e91e;
    }
    // 0045e8ff  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045e901  7590                   -jne 0x45e893
    if (!cpu.flags.zf)
    {
        goto L_0x0045e893;
    }
    // 0045e903  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0045e908  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0045e90d  b8c0034e00             -mov eax, 0x4e03c0
    cpu.eax = 5112768 /*0x4e03c0*/;
    // 0045e912  e8491d0300             -call 0x490660
    cpu.esp -= 4;
    sub_490660(app, cpu);
    if (cpu.terminate) return;
    // 0045e917  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045e919  e975ffffff             -jmp 0x45e893
    goto L_0x0045e893;
L_0x0045e91e:
    // 0045e91e  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0045e923  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0045e928  b8c0034e00             -mov eax, 0x4e03c0
    cpu.eax = 5112768 /*0x4e03c0*/;
    // 0045e92d  e88e1bfcff             -call 0x4204c0
    cpu.esp -= 4;
    sub_4204c0(app, cpu);
    if (cpu.terminate) return;
    // 0045e932  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045e934  e95affffff             -jmp 0x45e893
    goto L_0x0045e893;
L_0x0045e939:
    // 0045e939  a1606c4c00             -mov eax, dword ptr [0x4c6c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008480) /* 0x4c6c60 */);
    // 0045e93e  e885220200             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0045e943  e828fcffff             -call 0x45e570
    cpu.esp -= 4;
    sub_45e570(app, cpu);
    if (cpu.terminate) return;
    // 0045e948  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e94a  0f8480000000           -je 0x45e9d0
    if (cpu.flags.zf)
    {
        goto L_0x0045e9d0;
    }
    // 0045e950  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e958  7542                   -jne 0x45e99c
    if (!cpu.flags.zf)
    {
        goto L_0x0045e99c;
    }
    // 0045e95a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e95b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0045e95d:
    // 0045e95d  668b3d44074e00         -mov di, word ptr [0x4e0744]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5113668) /* 0x4e0744 */);
    // 0045e964  6639fe                 +cmp si, di
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e967  7523                   -jne 0x45e98c
    if (!cpu.flags.zf)
    {
        goto L_0x0045e98c;
    }
    // 0045e969  e8622cffff             -call 0x4515d0
    cpu.esp -= 4;
    sub_4515d0(app, cpu);
    if (cpu.terminate) return;
    // 0045e96e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e970  743e                   -je 0x45e9b0
    if (cpu.flags.zf)
    {
        goto L_0x0045e9b0;
    }
    // 0045e972  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045e977  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0045e979  6689157a074e00         -mov word ptr [0x4e077a], dx
    app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */) = cpu.dx;
    // 0045e980  6689157c074e00         -mov word ptr [0x4e077c], dx
    app->getMemory<x86::reg16>(x86::reg32(5113724) /* 0x4e077c */) = cpu.dx;
    // 0045e987  e8a8250200             -call 0x480f34
    cpu.esp -= 4;
    sub_480f34(app, cpu);
    if (cpu.terminate) return;
L_0x0045e98c:
    // 0045e98c  a1606c4c00             -mov eax, dword ptr [0x4c6c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008480) /* 0x4c6c60 */);
    // 0045e991  e84a220200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0045e996  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e997  e9fffeffff             -jmp 0x45e89b
    goto L_0x0045e89b;
L_0x0045e99c:
    // 0045e99c  a1606c4c00             -mov eax, dword ptr [0x4c6c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008480) /* 0x4c6c60 */);
    // 0045e9a1  e83a220200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0045e9a6  e8052affff             -call 0x4513b0
    cpu.esp -= 4;
    sub_4513b0(app, cpu);
    if (cpu.terminate) return;
    // 0045e9ab  e9ebfeffff             -jmp 0x45e89b
    goto L_0x0045e89b;
L_0x0045e9b0:
    // 0045e9b0  663b3d7a074e00         +cmp di, word ptr [0x4e077a]
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e9b7  74a4                   -je 0x45e95d
    if (cpu.flags.zf)
    {
        goto L_0x0045e95d;
    }
    // 0045e9b9  e876250200             -call 0x480f34
    cpu.esp -= 4;
    sub_480f34(app, cpu);
    if (cpu.terminate) return;
    // 0045e9be  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0045e9c0  a1606c4c00             -mov eax, dword ptr [0x4c6c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008480) /* 0x4c6c60 */);
    // 0045e9c5  e816220200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0045e9ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e9cb  e9cbfeffff             -jmp 0x45e89b
    goto L_0x0045e89b;
L_0x0045e9d0:
    // 0045e9d0  e85f250200             -call 0x480f34
    cpu.esp -= 4;
    sub_480f34(app, cpu);
    if (cpu.terminate) return;
    // 0045e9d5  a1606c4c00             -mov eax, dword ptr [0x4c6c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008480) /* 0x4c6c60 */);
    // 0045e9da  e801220200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0045e9df  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0045e9e1  e9bdfeffff             -jmp 0x45e8a3
    goto L_0x0045e8a3;
L_0x0045e9e6:
    // 0045e9e6  e8d56efaff             -call 0x4058c0
    cpu.esp -= 4;
    sub_4058c0(app, cpu);
    if (cpu.terminate) return;
    // 0045e9eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e9ed  0f85cefeffff           -jne 0x45e8c1
    if (!cpu.flags.zf)
    {
        goto L_0x0045e8c1;
    }
    // 0045e9f3  e8b9a40100             -call 0x478eb1
    cpu.esp -= 4;
    sub_478eb1(app, cpu);
    if (cpu.terminate) return;
    // 0045e9f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e9fa  74ea                   -je 0x45e9e6
    if (cpu.flags.zf)
    {
        goto L_0x0045e9e6;
    }
    // 0045e9fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045e9fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e9ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ea03:
    // 0045ea03  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045ea05  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ea07  e83439faff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0045ea0c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045ea0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ea20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ea20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045ea21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ea22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ea23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045ea24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ea25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045ea26  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045ea29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045ea2b  8b35b8f14d00           -mov esi, dword ptr [0x4df1b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108152) /* 0x4df1b8 */);
    // 0045ea31  e80ab20100             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0045ea36  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045ea38  8b15b8f14d00           -mov edx, dword ptr [0x4df1b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108152) /* 0x4df1b8 */);
    // 0045ea3e  81c610270000           -add esi, 0x2710
    (cpu.esi) += x86::reg32(x86::sreg32(10000 /*0x2710*/));
    // 0045ea44  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045ea46  0f8e94010000           -jle 0x45ebe0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ebe0;
    }
L_0x0045ea4c:
    // 0045ea4c  a15cfd4d00             -mov eax, dword ptr [0x4dfd5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111132) /* 0x4dfd5c */);
    // 0045ea51  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045ea53  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ea55  a3c8f74f00             -mov dword ptr [0x4ff7c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5240776) /* 0x4ff7c8 */) = cpu.eax;
    // 0045ea5a  e8d163fdff             -call 0x434e30
    cpu.esp -= 4;
    sub_434e30(app, cpu);
    if (cpu.terminate) return;
    // 0045ea5f  e8dc63fdff             -call 0x434e40
    cpu.esp -= 4;
    sub_434e40(app, cpu);
    if (cpu.terminate) return;
    // 0045ea64  e8b3940100             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0045ea69  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045ea6b  e8d03afcff             -call 0x422540
    cpu.esp -= 4;
    sub_422540(app, cpu);
    if (cpu.terminate) return;
    // 0045ea70  833da4f74f0000         +cmp dword ptr [0x4ff7a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ea77  0f854c010000           -jne 0x45ebc9
    if (!cpu.flags.zf)
    {
        goto L_0x0045ebc9;
    }
L_0x0045ea7d:
    // 0045ea7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045ea7f  e8bcb10100             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0045ea84  a1f48c4c00             -mov eax, dword ptr [0x4c8cf4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016820) /* 0x4c8cf4 */);
    // 0045ea89  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045ea8b  a3b0f74f00             -mov dword ptr [0x4ff7b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5240752) /* 0x4ff7b0 */) = cpu.eax;
    // 0045ea90  a1b8f14d00             -mov eax, dword ptr [0x4df1b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108152) /* 0x4df1b8 */);
    // 0045ea95  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045ea97  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0045ea99  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045ea9b  8b15b0f74f00           -mov edx, dword ptr [0x4ff7b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240752) /* 0x4ff7b0 */);
    // 0045eaa1  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045eaa3  39d6                   +cmp esi, edx
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
    // 0045eaa5  7e06                   -jle 0x45eaad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045eaad;
    }
    // 0045eaa7  ff05b0f74f00           -inc dword ptr [0x4ff7b0]
    (app->getMemory<x86::reg32>(x86::reg32(5240752) /* 0x4ff7b0 */))++;
L_0x0045eaad:
    // 0045eaad  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045eaaf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045eab1  8b15c8f74f00           -mov edx, dword ptr [0x4ff7c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240776) /* 0x4ff7c8 */);
    // 0045eab7  a3b8f74f00             -mov dword ptr [0x4ff7b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5240760) /* 0x4ff7b8 */) = cpu.eax;
    // 0045eabc  a15cfd4d00             -mov eax, dword ptr [0x4dfd5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111132) /* 0x4dfd5c */);
    // 0045eac1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045eac3  8b0db0f74f00           -mov ecx, dword ptr [0x4ff7b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5240752) /* 0x4ff7b0 */);
    // 0045eac9  83f810                 +cmp eax, 0x10
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
    // 0045eacc  0f8f1d010000           -jg 0x45ebef
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045ebef;
    }
L_0x0045ead2:
    // 0045ead2  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 0045ead7  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045eadc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045eade:
    // 0045eade  8b155cfd4d00           -mov edx, dword ptr [0x4dfd5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5111132) /* 0x4dfd5c */);
    // 0045eae4  3b15c8f74f00           +cmp edx, dword ptr [0x4ff7c8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240776) /* 0x4ff7c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eaea  7c0c                   -jl 0x45eaf8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045eaf8;
    }
    // 0045eaec  3b1da4f74f00           +cmp ebx, dword ptr [0x4ff7a4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eaf2  0f8406010000           -je 0x45ebfe
    if (cpu.flags.zf)
    {
        goto L_0x0045ebfe;
    }
L_0x0045eaf8:
    // 0045eaf8  833da8f74f0000         +cmp dword ptr [0x4ff7a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eaff  0f8507040000           -jne 0x45ef0c
    if (!cpu.flags.zf)
    {
        goto L_0x0045ef0c;
    }
    // 0045eb05  833dacf74f0000         +cmp dword ptr [0x4ff7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb0c  0f85fa030000           -jne 0x45ef0c
    if (!cpu.flags.zf)
    {
        goto L_0x0045ef0c;
    }
    // 0045eb12  833da4f74f0000         +cmp dword ptr [0x4ff7a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb19  0f85ed030000           -jne 0x45ef0c
    if (!cpu.flags.zf)
    {
        goto L_0x0045ef0c;
    }
    // 0045eb1f  8b2db0f74f00           -mov ebp, dword ptr [0x4ff7b0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5240752) /* 0x4ff7b0 */);
    // 0045eb25  3b2db4f74f00           +cmp ebp, dword ptr [0x4ff7b4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb2b  0f8cf9020000           -jl 0x45ee2a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045ee2a;
    }
L_0x0045eb31:
    // 0045eb31  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 0045eb36  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0045eb3b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045eb3d:
    // 0045eb3d  8b15b0f74f00           -mov edx, dword ptr [0x4ff7b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240752) /* 0x4ff7b0 */);
    // 0045eb43  3b15b4f74f00           +cmp edx, dword ptr [0x4ff7b4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb49  7c0f                   -jl 0x45eb5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045eb5a;
    }
    // 0045eb4b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045eb4d  e81e040000             -call 0x45ef70
    cpu.esp -= 4;
    sub_45ef70(app, cpu);
    if (cpu.terminate) return;
    // 0045eb52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045eb54  0f84df020000           -je 0x45ee39
    if (cpu.flags.zf)
    {
        goto L_0x0045ee39;
    }
L_0x0045eb5a:
    // 0045eb5a  833db8f74f0000         +cmp dword ptr [0x4ff7b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240760) /* 0x4ff7b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb61  750a                   -jne 0x45eb6d
    if (!cpu.flags.zf)
    {
        goto L_0x0045eb6d;
    }
    // 0045eb63  a1a8f74f00             -mov eax, dword ptr [0x4ff7a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */);
    // 0045eb68  e803d9ffff             -call 0x45c470
    cpu.esp -= 4;
    sub_45c470(app, cpu);
    if (cpu.terminate) return;
L_0x0045eb6d:
    // 0045eb6d  833d28f54d0004         +cmp dword ptr [0x4df528], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb74  7517                   -jne 0x45eb8d
    if (!cpu.flags.zf)
    {
        goto L_0x0045eb8d;
    }
    // 0045eb76  833d34f54d0001         +cmp dword ptr [0x4df534], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb7d  7f0e                   -jg 0x45eb8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045eb8d;
    }
    // 0045eb7f  833d2cf54d0000         +cmp dword ptr [0x4df52c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb86  7505                   -jne 0x45eb8d
    if (!cpu.flags.zf)
    {
        goto L_0x0045eb8d;
    }
    // 0045eb88  e853d80000             -call 0x46c3e0
    cpu.esp -= 4;
    sub_46c3e0(app, cpu);
    if (cpu.terminate) return;
L_0x0045eb8d:
    // 0045eb8d  e8beb4feff             -call 0x44a050
    cpu.esp -= 4;
    sub_44a050(app, cpu);
    if (cpu.terminate) return;
    // 0045eb92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045eb94  0f847c030000           -je 0x45ef16
    if (cpu.flags.zf)
    {
        goto L_0x0045ef16;
    }
L_0x0045eb9a:
    // 0045eb9a  833d34f54d0001         +cmp dword ptr [0x4df534], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eba1  7f11                   -jg 0x45ebb4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045ebb4;
    }
    // 0045eba3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045eba8  891dfc8c4c00           -mov dword ptr [0x4c8cfc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5016828) /* 0x4c8cfc */) = cpu.ebx;
    // 0045ebae  891df88c4c00           -mov dword ptr [0x4c8cf8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.ebx;
L_0x0045ebb4:
    // 0045ebb4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045ebb9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045ebbe  e8fd270000             -call 0x4613c0
    cpu.esp -= 4;
    sub_4613c0(app, cpu);
    if (cpu.terminate) return;
    // 0045ebc3  893da4f74f00           -mov dword ptr [0x4ff7a4], edi
    app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */) = cpu.edi;
L_0x0045ebc9:
    // 0045ebc9  833d34f54d0001         +cmp dword ptr [0x4df534], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ebd0  0f8e79030000           -jle 0x45ef4f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ef4f;
    }
    // 0045ebd6  83c404                 +add esp, 4
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
    // 0045ebd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebdf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ebe0:
    // 0045ebe0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045ebe5  e8bb180300             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 0045ebea  e95dfeffff             -jmp 0x45ea4c
    goto L_0x0045ea4c;
L_0x0045ebef:
    // 0045ebef  a15cfd4d00             -mov eax, dword ptr [0x4dfd5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111132) /* 0x4dfd5c */);
    // 0045ebf4  a3c8f74f00             -mov dword ptr [0x4ff7c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5240776) /* 0x4ff7c8 */) = cpu.eax;
    // 0045ebf9  e9d4feffff             -jmp 0x45ead2
    goto L_0x0045ead2;
L_0x0045ebfe:
    // 0045ebfe  3b2d28f54d00           +cmp ebp, dword ptr [0x4df528]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ec04  7e05                   -jle 0x45ec0b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ec0b;
    }
    // 0045ec06  e825d8ffff             -call 0x45c430
    cpu.esp -= 4;
    sub_45c430(app, cpu);
    if (cpu.terminate) return;
L_0x0045ec0b:
    // 0045ec0b  3b2d14f64f00           +cmp ebp, dword ptr [0x4ff614]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ec11  7547                   -jne 0x45ec5a
    if (!cpu.flags.zf)
    {
        goto L_0x0045ec5a;
    }
    // 0045ec13  8b15a8f74f00           -mov edx, dword ptr [0x4ff7a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */);
    // 0045ec19  39d3                   +cmp ebx, edx
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
    // 0045ec1b  753d                   -jne 0x45ec5a
    if (!cpu.flags.zf)
    {
        goto L_0x0045ec5a;
    }
    // 0045ec1d  e8bedfffff             -call 0x45cbe0
    cpu.esp -= 4;
    sub_45cbe0(app, cpu);
    if (cpu.terminate) return;
    // 0045ec22  833d24104e0004         +cmp dword ptr [0x4e1024], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115940) /* 0x4e1024 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ec29  752f                   -jne 0x45ec5a
    if (!cpu.flags.zf)
    {
        goto L_0x0045ec5a;
    }
    // 0045ec2b  a118104e00             -mov eax, dword ptr [0x4e1018]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115928) /* 0x4e1018 */);
    // 0045ec30  891524104e00           -mov dword ptr [0x4e1024], edx
    app->getMemory<x86::reg32>(x86::reg32(5115940) /* 0x4e1024 */) = cpu.edx;
    // 0045ec36  a3a4f74f00             -mov dword ptr [0x4ff7a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */) = cpu.eax;
    // 0045ec3b  39c2                   +cmp edx, eax
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
    // 0045ec3d  0f848c010000           -je 0x45edcf
    if (cpu.flags.zf)
    {
        goto L_0x0045edcf;
    }
    // 0045ec43  3b15acf74f00           +cmp edx, dword ptr [0x4ff7ac]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ec49  0f8480010000           -je 0x45edcf
    if (cpu.flags.zf)
    {
        goto L_0x0045edcf;
    }
    // 0045ec4f  8915acf74f00           -mov dword ptr [0x4ff7ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */) = cpu.edx;
    // 0045ec55  e8a621fdff             -call 0x430e00
    cpu.esp -= 4;
    sub_430e00(app, cpu);
    if (cpu.terminate) return;
L_0x0045ec5a:
    // 0045ec5a  8b15a4f74f00           -mov edx, dword ptr [0x4ff7a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */);
    // 0045ec60  39d3                   +cmp ebx, edx
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
    // 0045ec62  7511                   -jne 0x45ec75
    if (!cpu.flags.zf)
    {
        goto L_0x0045ec75;
    }
    // 0045ec64  3b15a8f74f00           +cmp edx, dword ptr [0x4ff7a8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ec6a  0f8494010000           -je 0x45ee04
    if (cpu.flags.zf)
    {
        goto L_0x0045ee04;
    }
    // 0045ec70  e8ab030000             -call 0x45f020
    cpu.esp -= 4;
    sub_45f020(app, cpu);
    if (cpu.terminate) return;
L_0x0045ec75:
    // 0045ec75  3b1da8f74f00           +cmp ebx, dword ptr [0x4ff7a8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ec7b  0f852b010000           -jne 0x45edac
    if (!cpu.flags.zf)
    {
        goto L_0x0045edac;
    }
    // 0045ec81  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 0045ec86  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ec88  e853b4feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ec8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ec8f  7405                   -je 0x45ec96
    if (cpu.flags.zf)
    {
        goto L_0x0045ec96;
    }
    // 0045ec91  e8da1f0100             -call 0x470c70
    cpu.esp -= 4;
    sub_470c70(app, cpu);
    if (cpu.terminate) return;
L_0x0045ec96:
    // 0045ec96  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0045ec9b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ec9d  e83eb4feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045eca2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045eca4  7405                   -je 0x45ecab
    if (cpu.flags.zf)
    {
        goto L_0x0045ecab;
    }
    // 0045eca6  e835200100             -call 0x470ce0
    cpu.esp -= 4;
    sub_470ce0(app, cpu);
    if (cpu.terminate) return;
L_0x0045ecab:
    // 0045ecab  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0045ecb0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ecb2  e829b4feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ecb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ecb9  7405                   -je 0x45ecc0
    if (cpu.flags.zf)
    {
        goto L_0x0045ecc0;
    }
    // 0045ecbb  e86062fdff             -call 0x434f20
    cpu.esp -= 4;
    sub_434f20(app, cpu);
    if (cpu.terminate) return;
L_0x0045ecc0:
    // 0045ecc0  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0045ecc5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ecc7  e814b4feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045eccc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ecce  7405                   -je 0x45ecd5
    if (cpu.flags.zf)
    {
        goto L_0x0045ecd5;
    }
    // 0045ecd0  e8bb450100             -call 0x473290
    cpu.esp -= 4;
    sub_473290(app, cpu);
    if (cpu.terminate) return;
L_0x0045ecd5:
    // 0045ecd5  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 0045ecda  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ecdc  e8ffb3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ece1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ece3  7407                   -je 0x45ecec
    if (cpu.flags.zf)
    {
        goto L_0x0045ecec;
    }
    // 0045ece5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045ece7  e8148ffeff             -call 0x447c00
    cpu.esp -= 4;
    sub_447c00(app, cpu);
    if (cpu.terminate) return;
L_0x0045ecec:
    // 0045ecec  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 0045ecf1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ecf3  e8e8b3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ecf8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ecfa  7407                   -je 0x45ed03
    if (cpu.flags.zf)
    {
        goto L_0x0045ed03;
    }
    // 0045ecfc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045ecfe  e8fd8efeff             -call 0x447c00
    cpu.esp -= 4;
    sub_447c00(app, cpu);
    if (cpu.terminate) return;
L_0x0045ed03:
    // 0045ed03  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 0045ed08  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ed0a  e8d1b3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ed0f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ed11  7405                   -je 0x45ed18
    if (cpu.flags.zf)
    {
        goto L_0x0045ed18;
    }
    // 0045ed13  e8a88efeff             -call 0x447bc0
    cpu.esp -= 4;
    sub_447bc0(app, cpu);
    if (cpu.terminate) return;
L_0x0045ed18:
    // 0045ed18  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 0045ed1d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ed1f  e8bcb3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ed24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ed26  7405                   -je 0x45ed2d
    if (cpu.flags.zf)
    {
        goto L_0x0045ed2d;
    }
    // 0045ed28  e8731ffdff             -call 0x430ca0
    cpu.esp -= 4;
    sub_430ca0(app, cpu);
    if (cpu.terminate) return;
L_0x0045ed2d:
    // 0045ed2d  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 0045ed32  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045ed34  e8a7b3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ed39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ed3b  7405                   -je 0x45ed42
    if (cpu.flags.zf)
    {
        goto L_0x0045ed42;
    }
    // 0045ed3d  e81e1ffdff             -call 0x430c60
    cpu.esp -= 4;
    sub_430c60(app, cpu);
    if (cpu.terminate) return;
L_0x0045ed42:
    // 0045ed42  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045ed44  e8f7740000             -call 0x466240
    cpu.esp -= 4;
    sub_466240(app, cpu);
    if (cpu.terminate) return;
    // 0045ed49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ed4b  740f                   -je 0x45ed5c
    if (cpu.flags.zf)
    {
        goto L_0x0045ed5c;
    }
    // 0045ed4d  3b2d14f64f00           +cmp ebp, dword ptr [0x4ff614]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ed53  7e07                   -jle 0x45ed5c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ed5c;
    }
    // 0045ed55  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045ed57  e8e4abfdff             -call 0x439940
    cpu.esp -= 4;
    sub_439940(app, cpu);
    if (cpu.terminate) return;
L_0x0045ed5c:
    // 0045ed5c  8b1528f54d00           -mov edx, dword ptr [0x4df528]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0045ed62  39d7                   +cmp edi, edx
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
    // 0045ed64  751a                   -jne 0x45ed80
    if (!cpu.flags.zf)
    {
        goto L_0x0045ed80;
    }
    // 0045ed66  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045ed68  e8d3740000             -call 0x466240
    cpu.esp -= 4;
    sub_466240(app, cpu);
    if (cpu.terminate) return;
    // 0045ed6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ed6f  740f                   -je 0x45ed80
    if (cpu.flags.zf)
    {
        goto L_0x0045ed80;
    }
    // 0045ed71  3b2d14f64f00           +cmp ebp, dword ptr [0x4ff614]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ed77  7e07                   -jle 0x45ed80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ed80;
    }
    // 0045ed79  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045ed7b  e8c0abfdff             -call 0x439940
    cpu.esp -= 4;
    sub_439940(app, cpu);
    if (cpu.terminate) return;
L_0x0045ed80:
    // 0045ed80  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
    // 0045ed85  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045ed87  e854b3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ed8c  8b1528f54d00           -mov edx, dword ptr [0x4df528]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0045ed92  a3e8fb4d00             -mov dword ptr [0x4dfbe8], eax
    app->getMemory<x86::reg32>(x86::reg32(5110760) /* 0x4dfbe8 */) = cpu.eax;
    // 0045ed97  39d7                   +cmp edi, edx
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
    // 0045ed99  7511                   -jne 0x45edac
    if (!cpu.flags.zf)
    {
        goto L_0x0045edac;
    }
    // 0045ed9b  b819000000             -mov eax, 0x19
    cpu.eax = 25 /*0x19*/;
    // 0045eda0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045eda2  e839b3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045eda7  a3ecfb4d00             -mov dword ptr [0x4dfbec], eax
    app->getMemory<x86::reg32>(x86::reg32(5110764) /* 0x4dfbec */) = cpu.eax;
L_0x0045edac:
    // 0045edac  3b2d28f54d00           +cmp ebp, dword ptr [0x4df528]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045edb2  7e5c                   -jle 0x45ee10
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ee10;
    }
L_0x0045edb4:
    // 0045edb4  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0045edb9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045edbb  e820b3feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045edc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045edc2  7556                   -jne 0x45ee1a
    if (!cpu.flags.zf)
    {
        goto L_0x0045ee1a;
    }
L_0x0045edc4:
    // 0045edc4  ff05c8f74f00           +inc dword ptr [0x4ff7c8]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5240776) /* 0x4ff7c8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045edca  e90ffdffff             -jmp 0x45eade
    goto L_0x0045eade;
L_0x0045edcf:
    // 0045edcf  8b1510104e00           -mov edx, dword ptr [0x4e1010]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5115920) /* 0x4e1010 */);
    // 0045edd5  3b15acf74f00           +cmp edx, dword ptr [0x4ff7ac]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eddb  0f8479feffff           -je 0x45ec5a
    if (cpu.flags.zf)
    {
        goto L_0x0045ec5a;
    }
    // 0045ede1  8915acf74f00           -mov dword ptr [0x4ff7ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */) = cpu.edx;
    // 0045ede7  39d3                   +cmp ebx, edx
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
    // 0045ede9  740f                   -je 0x45edfa
    if (cpu.flags.zf)
    {
        goto L_0x0045edfa;
    }
    // 0045edeb  e804c3fdff             -call 0x43b0f4
    cpu.esp -= 4;
    sub_43b0f4(app, cpu);
    if (cpu.terminate) return;
    // 0045edf0  e89b20fdff             -call 0x430e90
    cpu.esp -= 4;
    sub_430e90(app, cpu);
    if (cpu.terminate) return;
    // 0045edf5  e960feffff             -jmp 0x45ec5a
    goto L_0x0045ec5a;
L_0x0045edfa:
    // 0045edfa  e87120fdff             -call 0x430e70
    cpu.esp -= 4;
    sub_430e70(app, cpu);
    if (cpu.terminate) return;
    // 0045edff  e956feffff             -jmp 0x45ec5a
    goto L_0x0045ec5a;
L_0x0045ee04:
    // 0045ee04  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045ee06  e865010000             -call 0x45ef70
    cpu.esp -= 4;
    sub_45ef70(app, cpu);
    if (cpu.terminate) return;
    // 0045ee0b  e965feffff             -jmp 0x45ec75
    goto L_0x0045ec75;
L_0x0045ee10:
    // 0045ee10  3b3d34f54d00           +cmp edi, dword ptr [0x4df534]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ee16  7c9c                   -jl 0x45edb4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045edb4;
    }
    // 0045ee18  ebaa                   -jmp 0x45edc4
    goto L_0x0045edc4;
L_0x0045ee1a:
    // 0045ee1a  e8d1060000             -call 0x45f4f0
    cpu.esp -= 4;
    sub_45f4f0(app, cpu);
    if (cpu.terminate) return;
    // 0045ee1f  ff05c8f74f00           +inc dword ptr [0x4ff7c8]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5240776) /* 0x4ff7c8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045ee25  e9b4fcffff             -jmp 0x45eade
    goto L_0x0045eade;
L_0x0045ee2a:
    // 0045ee2a  c705b8f74f0001000000   -mov dword ptr [0x4ff7b8], 1
    app->getMemory<x86::reg32>(x86::reg32(5240760) /* 0x4ff7b8 */) = 1 /*0x1*/;
    // 0045ee34  e9f8fcffff             -jmp 0x45eb31
    goto L_0x0045eb31;
L_0x0045ee39:
    // 0045ee39  a1b4f74f00             -mov eax, dword ptr [0x4ff7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */);
    // 0045ee3e  85c5                   +test ebp, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.eax));
    // 0045ee40  7507                   -jne 0x45ee49
    if (!cpu.flags.zf)
    {
        goto L_0x0045ee49;
    }
    // 0045ee42  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045ee44  e807160000             -call 0x460450
    cpu.esp -= 4;
    sub_460450(app, cpu);
    if (cpu.terminate) return;
L_0x0045ee49:
    // 0045ee49  8b1514f64f00           -mov edx, dword ptr [0x4ff614]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
    // 0045ee4f  891dd88c4c00           -mov dword ptr [0x4c8cd8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5016792) /* 0x4c8cd8 */) = cpu.ebx;
    // 0045ee55  39d7                   +cmp edi, edx
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
    // 0045ee57  0f857d000000           -jne 0x45eeda
    if (!cpu.flags.zf)
    {
        goto L_0x0045eeda;
    }
    // 0045ee5d  3b1d14104e00           +cmp ebx, dword ptr [0x4e1014]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ee63  752d                   -jne 0x45ee92
    if (!cpu.flags.zf)
    {
        goto L_0x0045ee92;
    }
    // 0045ee65  a1b4f74f00             -mov eax, dword ptr [0x4ff7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */);
    // 0045ee6a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045ee6c  c7042404000000         -mov dword ptr [esp], 4
    app->getMemory<x86::reg32>(cpu.esp) = 4 /*0x4*/;
    // 0045ee73  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045ee76  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045ee79  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045ee7b  7515                   -jne 0x45ee92
    if (!cpu.flags.zf)
    {
        goto L_0x0045ee92;
    }
L_0x0045ee7d:
    // 0045ee7d  a1b4f74f00             -mov eax, dword ptr [0x4ff7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */);
    // 0045ee82  e8a9020000             -call 0x45f130
    cpu.esp -= 4;
    sub_45f130(app, cpu);
    if (cpu.terminate) return;
    // 0045ee87  ff05b4f74f00           +inc dword ptr [0x4ff7b4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045ee8d  e9abfcffff             -jmp 0x45eb3d
    goto L_0x0045eb3d;
L_0x0045ee92:
    // 0045ee92  3b2d14104e00           +cmp ebp, dword ptr [0x4e1014]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ee98  7510                   -jne 0x45eeaa
    if (!cpu.flags.zf)
    {
        goto L_0x0045eeaa;
    }
    // 0045ee9a  a1b4f74f00             -mov eax, dword ptr [0x4ff7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */);
    // 0045ee9f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045eea1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045eea4  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045eea6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045eea8  74d3                   -je 0x45ee7d
    if (cpu.flags.zf)
    {
        goto L_0x0045ee7d;
    }
L_0x0045eeaa:
    // 0045eeaa  a114104e00             -mov eax, dword ptr [0x4e1014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */);
    // 0045eeaf  39c7                   +cmp edi, eax
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
    // 0045eeb1  74ca                   -je 0x45ee7d
    if (cpu.flags.zf)
    {
        goto L_0x0045ee7d;
    }
    // 0045eeb3  83f803                 +cmp eax, 3
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
    // 0045eeb6  750c                   -jne 0x45eec4
    if (!cpu.flags.zf)
    {
        goto L_0x0045eec4;
    }
    // 0045eeb8  a1b4f74f00             -mov eax, dword ptr [0x4ff7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */);
    // 0045eebd  e86e020000             -call 0x45f130
    cpu.esp -= 4;
    sub_45f130(app, cpu);
    if (cpu.terminate) return;
    // 0045eec2  ebb9                   -jmp 0x45ee7d
    goto L_0x0045ee7d;
L_0x0045eec4:
    // 0045eec4  892dd88c4c00           -mov dword ptr [0x4c8cd8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5016792) /* 0x4c8cd8 */) = cpu.ebp;
    // 0045eeca  e825c2fdff             -call 0x43b0f4
    cpu.esp -= 4;
    sub_43b0f4(app, cpu);
    if (cpu.terminate) return;
    // 0045eecf  ff05b4f74f00           +inc dword ptr [0x4ff7b4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045eed5  e963fcffff             -jmp 0x45eb3d
    goto L_0x0045eb3d;
L_0x0045eeda:
    // 0045eeda  83fa04                 +cmp edx, 4
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
    // 0045eedd  759e                   -jne 0x45ee7d
    if (!cpu.flags.zf)
    {
        goto L_0x0045ee7d;
    }
    // 0045eedf  e8ec1dfdff             -call 0x430cd0
    cpu.esp -= 4;
    sub_430cd0(app, cpu);
    if (cpu.terminate) return;
    // 0045eee4  e88720ffff             -call 0x450f70
    cpu.esp -= 4;
    sub_450f70(app, cpu);
    if (cpu.terminate) return;
    // 0045eee9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0045eeee  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045eef3  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0045eef5  891514f64f00           -mov dword ptr [0x4ff614], edx
    app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */) = cpu.edx;
    // 0045eefb  891db8f74f00           -mov dword ptr [0x4ff7b8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5240760) /* 0x4ff7b8 */) = cpu.ebx;
    // 0045ef01  893df48c4c00           -mov dword ptr [0x4c8cf4], edi
    app->getMemory<x86::reg32>(x86::reg32(5016820) /* 0x4c8cf4 */) = cpu.edi;
    // 0045ef07  e961fcffff             -jmp 0x45eb6d
    goto L_0x0045eb6d;
L_0x0045ef0c:
    // 0045ef0c  e8e3c1fdff             -call 0x43b0f4
    cpu.esp -= 4;
    sub_43b0f4(app, cpu);
    if (cpu.terminate) return;
    // 0045ef11  e944fcffff             -jmp 0x45eb5a
    goto L_0x0045eb5a;
L_0x0045ef16:
    // 0045ef16  66833d7a074e0000       +cmp word ptr [0x4e077a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045ef1e  0f8576fcffff           -jne 0x45eb9a
    if (!cpu.flags.zf)
    {
        goto L_0x0045eb9a;
    }
    // 0045ef24  833d14f64f0003         +cmp dword ptr [0x4ff614], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef2b  7510                   -jne 0x45ef3d
    if (!cpu.flags.zf)
    {
        goto L_0x0045ef3d;
    }
    // 0045ef2d  813dc4f74f0040020000   +cmp dword ptr [0x4ff7c4], 0x240
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(576 /*0x240*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef37  0f8f5dfcffff           -jg 0x45eb9a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045eb9a;
    }
L_0x0045ef3d:
    // 0045ef3d  833da4f74f0000         +cmp dword ptr [0x4ff7a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef44  0f8433fbffff           -je 0x45ea7d
    if (cpu.flags.zf)
    {
        goto L_0x0045ea7d;
    }
    // 0045ef4a  e97afcffff             -jmp 0x45ebc9
    goto L_0x0045ebc9;
L_0x0045ef4f:
    // 0045ef4f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045ef54  a3fc8c4c00             -mov dword ptr [0x4c8cfc], eax
    app->getMemory<x86::reg32>(x86::reg32(5016828) /* 0x4c8cfc */) = cpu.eax;
    // 0045ef59  a3f88c4c00             -mov dword ptr [0x4c8cf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.eax;
    // 0045ef5e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045ef61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef64  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ef70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ef70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ef71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045ef72  833da0f74f0000         +cmp dword ptr [0x4ff7a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240736) /* 0x4ff7a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef79  0f8587000000           -jne 0x45f006
    if (!cpu.flags.zf)
    {
        goto L_0x0045f006;
    }
    // 0045ef7f  8b0dc4f74f00           -mov ecx, dword ptr [0x4ff7c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045ef85  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef88  0f8c78000000           -jl 0x45f006
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f006;
    }
    // 0045ef8e  81f940010000           +cmp ecx, 0x140
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef94  7d09                   -jge 0x45ef9f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ef9f;
    }
    // 0045ef96  833d34f54d0001         +cmp dword ptr [0x4df534], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef9d  7e67                   -jle 0x45f006
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f006;
    }
L_0x0045ef9f:
    // 0045ef9f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045efa1  7424                   -je 0x45efc7
    if (cpu.flags.zf)
    {
        goto L_0x0045efc7;
    }
    // 0045efa3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045efa4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045efa9  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0045efae  e82db1feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045efb3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045efb8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045efba  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0045efbf  e81cb1feff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0045efc4  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045efc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045efc7:
    // 0045efc7  e8b40e0000             -call 0x45fe80
    cpu.esp -= 4;
    sub_45fe80(app, cpu);
    if (cpu.terminate) return;
    // 0045efcc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045efce  7433                   -je 0x45f003
    if (cpu.flags.zf)
    {
        goto L_0x0045f003;
    }
    // 0045efd0  833d28f54d0002         +cmp dword ptr [0x4df528], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045efd7  7d32                   -jge 0x45f00b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045f00b;
    }
    // 0045efd9  a1bcf14d00             -mov eax, dword ptr [0x4df1bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108156) /* 0x4df1bc */);
    // 0045efde  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0045efe1:
    // 0045efe1  a3bcf74f00             -mov dword ptr [0x4ff7bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5240764) /* 0x4ff7bc */) = cpu.eax;
    // 0045efe6  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0045efeb  e8a01efdff             -call 0x430e90
    cpu.esp -= 4;
    sub_430e90(app, cpu);
    if (cpu.terminate) return;
    // 0045eff0  892df88c4c00           -mov dword ptr [0x4c8cf8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.ebp;
    // 0045eff6  892da8f74f00           -mov dword ptr [0x4ff7a8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */) = cpu.ebp;
    // 0045effc  e89f880000             -call 0x4678a0
    cpu.esp -= 4;
    sub_4678a0(app, cpu);
    if (cpu.terminate) return;
    // 0045f001  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0045f003:
    // 0045f003  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f004  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f005  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f006:
    // 0045f006  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045f008  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f009  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f00a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f00b:
    // 0045f00b  a1bcf14d00             -mov eax, dword ptr [0x4df1bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108156) /* 0x4df1bc */);
    // 0045f010  83c020                 +add eax, 0x20
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045f013  ebcc                   -jmp 0x45efe1
    goto L_0x0045efe1;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f020  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f021  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f022  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f023  8b15bcf14d00           -mov edx, dword ptr [0x4df1bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108156) /* 0x4df1bc */);
    // 0045f029  3b15bcf74f00           +cmp edx, dword ptr [0x4ff7bc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240764) /* 0x4ff7bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f02f  7c0a                   -jl 0x45f03b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f03b;
    }
    // 0045f031  8b0de88c4c00           -mov ecx, dword ptr [0x4c8ce8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5016808) /* 0x4c8ce8 */);
    // 0045f037  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045f039  7404                   -je 0x45f03f
    if (cpu.flags.zf)
    {
        goto L_0x0045f03f;
    }
L_0x0045f03b:
    // 0045f03b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f03c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f03d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f03e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f03f:
    // 0045f03f  e83ce2feff             -call 0x44d280
    cpu.esp -= 4;
    sub_44d280(app, cpu);
    if (cpu.terminate) return;
    // 0045f044  e8b70a0000             -call 0x45fb00
    cpu.esp -= 4;
    sub_45fb00(app, cpu);
    if (cpu.terminate) return;
    // 0045f049  83f801                 +cmp eax, 1
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
    // 0045f04c  745c                   -je 0x45f0aa
    if (cpu.flags.zf)
    {
        goto L_0x0045f0aa;
    }
    // 0045f04e  83f802                 +cmp eax, 2
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
    // 0045f051  0f847f000000           -je 0x45f0d6
    if (cpu.flags.zf)
    {
        goto L_0x0045f0d6;
    }
    // 0045f057  83f803                 +cmp eax, 3
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
    // 0045f05a  0f849e000000           -je 0x45f0fe
    if (cpu.flags.zf)
    {
        goto L_0x0045f0fe;
    }
    // 0045f060  83f804                 +cmp eax, 4
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
    // 0045f063  75d6                   -jne 0x45f03b
    if (!cpu.flags.zf)
    {
        goto L_0x0045f03b;
    }
    // 0045f065  e8961dfdff             -call 0x430e00
    cpu.esp -= 4;
    sub_430e00(app, cpu);
    if (cpu.terminate) return;
    // 0045f06a  e8998e0100             -call 0x477f08
    cpu.esp -= 4;
    sub_477f08(app, cpu);
    if (cpu.terminate) return;
    // 0045f06f  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0045f074  e877910100             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 0045f079  e8d2de0200             -call 0x48cf50
    cpu.esp -= 4;
    sub_48cf50(app, cpu);
    if (cpu.terminate) return;
    // 0045f07e  e8dd870000             -call 0x467860
    cpu.esp -= 4;
    sub_467860(app, cpu);
    if (cpu.terminate) return;
    // 0045f083  e8185cfdff             -call 0x434ca0
    cpu.esp -= 4;
    sub_434ca0(app, cpu);
    if (cpu.terminate) return;
    // 0045f088  e8f33b0000             -call 0x462c80
    cpu.esp -= 4;
    sub_462c80(app, cpu);
    if (cpu.terminate) return;
    // 0045f08d  e8fe1cffff             -call 0x450d90
    cpu.esp -= 4;
    sub_450d90(app, cpu);
    if (cpu.terminate) return;
    // 0045f092  e865c00100             -call 0x47b0fc
    cpu.esp -= 4;
    sub_47b0fc(app, cpu);
    if (cpu.terminate) return;
    // 0045f097  e8541fffff             -call 0x450ff0
    cpu.esp -= 4;
    sub_450ff0(app, cpu);
    if (cpu.terminate) return;
    // 0045f09c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045f0a1  e8ff130300             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 0045f0a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f0aa:
    // 0045f0aa  e8d18bfeff             -call 0x447c80
    cpu.esp -= 4;
    sub_447c80(app, cpu);
    if (cpu.terminate) return;
    // 0045f0af  833dacf74f0000         +cmp dword ptr [0x4ff7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f0b6  7505                   -jne 0x45f0bd
    if (!cpu.flags.zf)
    {
        goto L_0x0045f0bd;
    }
    // 0045f0b8  e8b31dfdff             -call 0x430e70
    cpu.esp -= 4;
    sub_430e70(app, cpu);
    if (cpu.terminate) return;
L_0x0045f0bd:
    // 0045f0bd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f0be  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f0c0  891df88c4c00           -mov dword ptr [0x4c8cf8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.ebx;
    // 0045f0c6  891da8f74f00           -mov dword ptr [0x4ff7a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */) = cpu.ebx;
    // 0045f0cc  e8af870000             -call 0x467880
    cpu.esp -= 4;
    sub_467880(app, cpu);
    if (cpu.terminate) return;
    // 0045f0d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f0d6:
    // 0045f0d6  e8a58bfeff             -call 0x447c80
    cpu.esp -= 4;
    sub_447c80(app, cpu);
    if (cpu.terminate) return;
    // 0045f0db  e8d01cfdff             -call 0x430db0
    cpu.esp -= 4;
    sub_430db0(app, cpu);
    if (cpu.terminate) return;
    // 0045f0e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045f0e5  890da8f74f00           -mov dword ptr [0x4ff7a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */) = cpu.ecx;
    // 0045f0eb  a3a4f74f00             -mov dword ptr [0x4ff7a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */) = cpu.eax;
    // 0045f0f0  a3a0f74f00             -mov dword ptr [0x4ff7a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5240736) /* 0x4ff7a0 */) = cpu.eax;
    // 0045f0f5  e866870000             -call 0x467860
    cpu.esp -= 4;
    sub_467860(app, cpu);
    if (cpu.terminate) return;
    // 0045f0fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f0fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f0fe:
    // 0045f0fe  e87d8bfeff             -call 0x447c80
    cpu.esp -= 4;
    sub_447c80(app, cpu);
    if (cpu.terminate) return;
    // 0045f103  e8f81cfdff             -call 0x430e00
    cpu.esp -= 4;
    sub_430e00(app, cpu);
    if (cpu.terminate) return;
    // 0045f108  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045f10d  890da8f74f00           -mov dword ptr [0x4ff7a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */) = cpu.ecx;
    // 0045f113  890da0f74f00           -mov dword ptr [0x4ff7a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240736) /* 0x4ff7a0 */) = cpu.ecx;
    // 0045f119  8935a4f74f00           -mov dword ptr [0x4ff7a4], esi
    app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */) = cpu.esi;
    // 0045f11f  e83c870000             -call 0x467860
    cpu.esp -= 4;
    sub_467860(app, cpu);
    if (cpu.terminate) return;
    // 0045f124  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045f126  e895220000             -call 0x4613c0
    cpu.esp -= 4;
    sub_4613c0(app, cpu);
    if (cpu.terminate) return;
    // 0045f12b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f12c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f12d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f12e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45f130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f131  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f132  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f133  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f134  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f135  833dc0f74f0000         +cmp dword ptr [0x4ff7c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240768) /* 0x4ff7c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f13c  7550                   -jne 0x45f18e
    if (!cpu.flags.zf)
    {
        goto L_0x0045f18e;
    }
    // 0045f13e  8b0dc4f74f00           -mov ecx, dword ptr [0x4ff7c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0045f144  81f900020000           +cmp ecx, 0x200
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f14a  0f8c96000000           -jl 0x45f1e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f1e6;
    }
    // 0045f150  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045f155  8a2d6c4f4c00           -mov ch, byte ptr [0x4c4f6c]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */);
    // 0045f15b  8935c0f74f00           -mov dword ptr [0x4ff7c0], esi
    app->getMemory<x86::reg32>(x86::reg32(5240768) /* 0x4ff7c0 */) = cpu.esi;
    // 0045f161  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 0045f163  7429                   -je 0x45f18e
    if (cpu.flags.zf)
    {
        goto L_0x0045f18e;
    }
    // 0045f165  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0045f16a  8b3d2c8d4c00           -mov edi, dword ptr [0x4c8d2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5016876) /* 0x4c8d2c */);
    // 0045f170  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0045f172  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045f174  7469                   -je 0x45f1df
    if (cpu.flags.zf)
    {
        goto L_0x0045f1df;
    }
    // 0045f176  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045f178:
    // 0045f178  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0045f17d  a160874d00             -mov eax, dword ptr [0x4d8760]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5080928) /* 0x4d8760 */);
    // 0045f182  e8491dfdff             -call 0x430ed0
    cpu.esp -= 4;
    sub_430ed0(app, cpu);
    if (cpu.terminate) return;
    // 0045f187  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0045f189  a26c4f4c00             -mov byte ptr [0x4c4f6c], al
    app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */) = cpu.al;
L_0x0045f18e:
    // 0045f18e  e8ed33feff             -call 0x442580
    cpu.esp -= 4;
    sub_442580(app, cpu);
    if (cpu.terminate) return;
    // 0045f193  e8d8270000             -call 0x461970
    cpu.esp -= 4;
    sub_461970(app, cpu);
    if (cpu.terminate) return;
    // 0045f198  f605c4f74f0001         +test byte ptr [0x4ff7c4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5240772) /* 0x4ff7c4 */) & 1 /*0x1*/));
    // 0045f19f  7516                   -jne 0x45f1b7
    if (!cpu.flags.zf)
    {
        goto L_0x0045f1b7;
    }
    // 0045f1a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045f1a3  e898aa0100             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0045f1a8  a1d0f74f00             -mov eax, dword ptr [0x4ff7d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240784) /* 0x4ff7d0 */);
    // 0045f1ad  e8def0ffff             -call 0x45e290
    cpu.esp -= 4;
    sub_45e290(app, cpu);
    if (cpu.terminate) return;
    // 0045f1b2  e839210000             -call 0x4612f0
    cpu.esp -= 4;
    sub_4612f0(app, cpu);
    if (cpu.terminate) return;
L_0x0045f1b7:
    // 0045f1b7  a1ccf74f00             -mov eax, dword ptr [0x4ff7cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240780) /* 0x4ff7cc */);
    // 0045f1bc  e8cff0ffff             -call 0x45e290
    cpu.esp -= 4;
    sub_45e290(app, cpu);
    if (cpu.terminate) return;
    // 0045f1c1  ff05c4f74f00           -inc dword ptr [0x4ff7c4]
    (app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */))++;
    // 0045f1c7  f605c4f74f0001         +test byte ptr [0x4ff7c4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5240772) /* 0x4ff7c4 */) & 1 /*0x1*/));
    // 0045f1ce  0f84ec000000           -je 0x45f2c0
    if (cpu.flags.zf)
    {
        goto L_0x0045f2c0;
    }
    // 0045f1d4  e8d7270000             -call 0x4619b0
    cpu.esp -= 4;
    sub_4619b0(app, cpu);
    if (cpu.terminate) return;
    // 0045f1d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f1da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f1db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f1dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f1dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f1de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f1df:
    // 0045f1df  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0045f1e4  eb92                   -jmp 0x45f178
    goto L_0x0045f178;
L_0x0045f1e6:
    // 0045f1e6  81f9c0010000           +cmp ecx, 0x1c0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(448 /*0x1c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f1ec  7c3e                   -jl 0x45f22c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f22c;
    }
    // 0045f1ee  803d6c4f4c0001         +cmp byte ptr [0x4c4f6c], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045f1f5  7497                   -je 0x45f18e
    if (cpu.flags.zf)
    {
        goto L_0x0045f18e;
    }
    // 0045f1f7  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0045f1fc  8b1d2c8d4c00           -mov ebx, dword ptr [0x4c8d2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5016876) /* 0x4c8d2c */);
    // 0045f202  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0045f204  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045f206  741d                   -je 0x45f225
    if (cpu.flags.zf)
    {
        goto L_0x0045f225;
    }
    // 0045f208  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x0045f20a:
    // 0045f20a  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0045f20f  a160874d00             -mov eax, dword ptr [0x4d8760]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5080928) /* 0x4d8760 */);
    // 0045f214  e8b71cfdff             -call 0x430ed0
    cpu.esp -= 4;
    sub_430ed0(app, cpu);
    if (cpu.terminate) return;
    // 0045f219  c6056c4f4c0001         -mov byte ptr [0x4c4f6c], 1
    app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */) = 1 /*0x1*/;
    // 0045f220  e969ffffff             -jmp 0x45f18e
    goto L_0x0045f18e;
L_0x0045f225:
    // 0045f225  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0045f22a  ebde                   -jmp 0x45f20a
    goto L_0x0045f20a;
L_0x0045f22c:
    // 0045f22c  81f980010000           +cmp ecx, 0x180
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f232  7c42                   -jl 0x45f276
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f276;
    }
    // 0045f234  803d6c4f4c0002         +cmp byte ptr [0x4c4f6c], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045f23b  0f844dffffff           -je 0x45f18e
    if (cpu.flags.zf)
    {
        goto L_0x0045f18e;
    }
    // 0045f241  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0045f246  8b152c8d4c00           -mov edx, dword ptr [0x4c8d2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016876) /* 0x4c8d2c */);
    // 0045f24c  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0045f24e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045f250  741d                   -je 0x45f26f
    if (cpu.flags.zf)
    {
        goto L_0x0045f26f;
    }
    // 0045f252  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x0045f254:
    // 0045f254  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045f259  a160874d00             -mov eax, dword ptr [0x4d8760]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5080928) /* 0x4d8760 */);
    // 0045f25e  e86d1cfdff             -call 0x430ed0
    cpu.esp -= 4;
    sub_430ed0(app, cpu);
    if (cpu.terminate) return;
    // 0045f263  c6056c4f4c0002         -mov byte ptr [0x4c4f6c], 2
    app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */) = 2 /*0x2*/;
    // 0045f26a  e91fffffff             -jmp 0x45f18e
    goto L_0x0045f18e;
L_0x0045f26f:
    // 0045f26f  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0045f274  ebde                   -jmp 0x45f254
    goto L_0x0045f254;
L_0x0045f276:
    // 0045f276  81f940010000           +cmp ecx, 0x140
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f27c  0f8c0cffffff           -jl 0x45f18e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f18e;
    }
    // 0045f282  803d6c4f4c0003         +cmp byte ptr [0x4c4f6c], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045f289  0f84fffeffff           -je 0x45f18e
    if (cpu.flags.zf)
    {
        goto L_0x0045f18e;
    }
    // 0045f28f  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0045f294  a12c8d4c00             -mov eax, dword ptr [0x4c8d2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016876) /* 0x4c8d2c */);
    // 0045f299  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0045f29b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045f29d  741a                   -je 0x45f2b9
    if (cpu.flags.zf)
    {
        goto L_0x0045f2b9;
    }
    // 0045f29f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045f2a1:
    // 0045f2a1  a160874d00             -mov eax, dword ptr [0x4d8760]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5080928) /* 0x4d8760 */);
    // 0045f2a6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045f2a8  e8231cfdff             -call 0x430ed0
    cpu.esp -= 4;
    sub_430ed0(app, cpu);
    if (cpu.terminate) return;
    // 0045f2ad  c6056c4f4c0003         -mov byte ptr [0x4c4f6c], 3
    app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */) = 3 /*0x3*/;
    // 0045f2b4  e9d5feffff             -jmp 0x45f18e
    goto L_0x0045f18e;
L_0x0045f2b9:
    // 0045f2b9  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0045f2be  ebe1                   -jmp 0x45f2a1
    goto L_0x0045f2a1;
L_0x0045f2c0:
    // 0045f2c0  e85b17fdff             -call 0x430a20
    cpu.esp -= 4;
    sub_430a20(app, cpu);
    if (cpu.terminate) return;
    // 0045f2c5  e8e6260000             -call 0x4619b0
    cpu.esp -= 4;
    sub_4619b0(app, cpu);
    if (cpu.terminate) return;
    // 0045f2ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_45f2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f2d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f2d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f2d2  e849850000             -call 0x467820
    cpu.esp -= 4;
    sub_467820(app, cpu);
    if (cpu.terminate) return;
    // 0045f2d7  e894140000             -call 0x460770
    cpu.esp -= 4;
    sub_460770(app, cpu);
    if (cpu.terminate) return;
    // 0045f2dc  baf4b04300             -mov edx, 0x43b0f4
    cpu.edx = 4436212 /*0x43b0f4*/;
    // 0045f2e1  a1ccf74f00             -mov eax, dword ptr [0x4ff7cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240780) /* 0x4ff7cc */);
    // 0045f2e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f2e8  e8e3efffff             -call 0x45e2d0
    cpu.esp -= 4;
    sub_45e2d0(app, cpu);
    if (cpu.terminate) return;
    // 0045f2ed  e89ec4fcff             -call 0x42b790
    cpu.esp -= 4;
    sub_42b790(app, cpu);
    if (cpu.terminate) return;
    // 0045f2f2  e8e9e6fdff             -call 0x43d9e0
    cpu.esp -= 4;
    sub_43d9e0(app, cpu);
    if (cpu.terminate) return;
    // 0045f2f7  e854c3ffff             -call 0x45b650
    cpu.esp -= 4;
    sub_45b650(app, cpu);
    if (cpu.terminate) return;
    // 0045f2fc  e8ef150000             -call 0x4608f0
    cpu.esp -= 4;
    sub_4608f0(app, cpu);
    if (cpu.terminate) return;
    // 0045f301  e88a450000             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    if (cpu.terminate) return;
    // 0045f306  e895c4fcff             -call 0x42b7a0
    cpu.esp -= 4;
    sub_42b7a0(app, cpu);
    if (cpu.terminate) return;
    // 0045f30b  e810a8feff             -call 0x449b20
    cpu.esp -= 4;
    sub_449b20(app, cpu);
    if (cpu.terminate) return;
    // 0045f310  a1d0f74f00             -mov eax, dword ptr [0x4ff7d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240784) /* 0x4ff7d0 */);
    // 0045f315  e836f1ffff             -call 0x45e450
    cpu.esp -= 4;
    sub_45e450(app, cpu);
    if (cpu.terminate) return;
    // 0045f31a  a1ccf74f00             -mov eax, dword ptr [0x4ff7cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240780) /* 0x4ff7cc */);
    // 0045f31f  e82cf1ffff             -call 0x45e450
    cpu.esp -= 4;
    sub_45e450(app, cpu);
    if (cpu.terminate) return;
    // 0045f324  e87789feff             -call 0x447ca0
    cpu.esp -= 4;
    sub_447ca0(app, cpu);
    if (cpu.terminate) return;
    // 0045f329  e812000000             -call 0x45f340
    cpu.esp -= 4;
    sub_45f340(app, cpu);
    if (cpu.terminate) return;
    // 0045f32e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f32f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f330  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f340  e81b190100             -call 0x470c60
    cpu.esp -= 4;
    sub_470c60(app, cpu);
    if (cpu.terminate) return;
    // 0045f345  a360f54d00             -mov dword ptr [0x4df560], eax
    app->getMemory<x86::reg32>(x86::reg32(5109088) /* 0x4df560 */) = cpu.eax;
    // 0045f34a  a2ee014e00             -mov byte ptr [0x4e01ee], al
    app->getMemory<x86::reg8>(x86::reg32(5112302) /* 0x4e01ee */) = cpu.al;
    // 0045f34f  e8bc190100             -call 0x470d10
    cpu.esp -= 4;
    sub_470d10(app, cpu);
    if (cpu.terminate) return;
    // 0045f354  a364f54d00             -mov dword ptr [0x4df564], eax
    app->getMemory<x86::reg32>(x86::reg32(5109092) /* 0x4df564 */) = cpu.eax;
    // 0045f359  a2ef014e00             -mov byte ptr [0x4e01ef], al
    app->getMemory<x86::reg8>(x86::reg32(5112303) /* 0x4e01ef */) = cpu.al;
    // 0045f35e  a068f54d00             -mov al, byte ptr [0x4df568]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5109096) /* 0x4df568 */);
    // 0045f363  a2f1014e00             -mov byte ptr [0x4e01f1], al
    app->getMemory<x86::reg8>(x86::reg32(5112305) /* 0x4e01f1 */) = cpu.al;
    // 0045f368  e8c35cfdff             -call 0x435030
    cpu.esp -= 4;
    sub_435030(app, cpu);
    if (cpu.terminate) return;
    // 0045f36d  a36cf54d00             -mov dword ptr [0x4df56c], eax
    app->getMemory<x86::reg32>(x86::reg32(5109100) /* 0x4df56c */) = cpu.eax;
    // 0045f372  a2f0014e00             -mov byte ptr [0x4e01f0], al
    app->getMemory<x86::reg8>(x86::reg32(5112304) /* 0x4e01f0 */) = cpu.al;
    // 0045f377  a16cb85100             -mov eax, dword ptr [0x51b86c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355628) /* 0x51b86c */);
    // 0045f37c  a370f54d00             -mov dword ptr [0x4df570], eax
    app->getMemory<x86::reg32>(x86::reg32(5109104) /* 0x4df570 */) = cpu.eax;
    // 0045f381  a2f2014e00             -mov byte ptr [0x4e01f2], al
    app->getMemory<x86::reg8>(x86::reg32(5112306) /* 0x4e01f2 */) = cpu.al;
    // 0045f386  e9959bfaff             -jmp 0x408f20
    return sub_408f20(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f391  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f393  a144f54d00             -mov eax, dword ptr [0x4df544]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109060) /* 0x4df544 */);
    // 0045f398  8915a4f74f00           -mov dword ptr [0x4ff7a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */) = cpu.edx;
    // 0045f39e  8915a8f74f00           -mov dword ptr [0x4ff7a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */) = cpu.edx;
    // 0045f3a4  8915acf74f00           -mov dword ptr [0x4ff7ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */) = cpu.edx;
    // 0045f3aa  8915b0f74f00           -mov dword ptr [0x4ff7b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5240752) /* 0x4ff7b0 */) = cpu.edx;
    // 0045f3b0  8915b4f74f00           -mov dword ptr [0x4ff7b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */) = cpu.edx;
    // 0045f3b6  8915c0f74f00           -mov dword ptr [0x4ff7c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5240768) /* 0x4ff7c0 */) = cpu.edx;
    // 0045f3bc  8915c4f74f00           -mov dword ptr [0x4ff7c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */) = cpu.edx;
    // 0045f3c2  e8d9a6feff             -call 0x449aa0
    cpu.esp -= 4;
    sub_449aa0(app, cpu);
    if (cpu.terminate) return;
    // 0045f3c7  e814c3fcff             -call 0x42b6e0
    cpu.esp -= 4;
    sub_42b6e0(app, cpu);
    if (cpu.terminate) return;
    // 0045f3cc  e80fc3ffff             -call 0x45b6e0
    cpu.esp -= 4;
    sub_45b6e0(app, cpu);
    if (cpu.terminate) return;
    // 0045f3d1  e86aeefdff             -call 0x43e240
    cpu.esp -= 4;
    sub_43e240(app, cpu);
    if (cpu.terminate) return;
    // 0045f3d6  e895160000             -call 0x460a70
    cpu.esp -= 4;
    sub_460a70(app, cpu);
    if (cpu.terminate) return;
    // 0045f3db  e8a0c1fcff             -call 0x42b580
    cpu.esp -= 4;
    sub_42b580(app, cpu);
    if (cpu.terminate) return;
    // 0045f3e0  e8ebcfffff             -call 0x45c3d0
    cpu.esp -= 4;
    sub_45c3d0(app, cpu);
    if (cpu.terminate) return;
    // 0045f3e5  e856840000             -call 0x467840
    cpu.esp -= 4;
    sub_467840(app, cpu);
    if (cpu.terminate) return;
    // 0045f3ea  a15cfd4d00             -mov eax, dword ptr [0x4dfd5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111132) /* 0x4dfd5c */);
    // 0045f3ef  a3c8f74f00             -mov dword ptr [0x4ff7c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5240776) /* 0x4ff7c8 */) = cpu.eax;
    // 0045f3f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f3f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f401  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f402  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f403  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045f408  b8a8d44b00             -mov eax, 0x4bd4a8
    cpu.eax = 4969640 /*0x4bd4a8*/;
    // 0045f40d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045f40f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f411  8915a0f74f00           -mov dword ptr [0x4ff7a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5240736) /* 0x4ff7a0 */) = cpu.edx;
    // 0045f417  890da4f74f00           -mov dword ptr [0x4ff7a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */) = cpu.ecx;
    // 0045f41d  890da8f74f00           -mov dword ptr [0x4ff7a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */) = cpu.ecx;
    // 0045f423  890dacf74f00           -mov dword ptr [0x4ff7ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240748) /* 0x4ff7ac */) = cpu.ecx;
    // 0045f429  890db0f74f00           -mov dword ptr [0x4ff7b0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240752) /* 0x4ff7b0 */) = cpu.ecx;
    // 0045f42f  890db4f74f00           -mov dword ptr [0x4ff7b4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240756) /* 0x4ff7b4 */) = cpu.ecx;
    // 0045f435  890dc0f74f00           -mov dword ptr [0x4ff7c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240768) /* 0x4ff7c0 */) = cpu.ecx;
    // 0045f43b  ba90000000             -mov edx, 0x90
    cpu.edx = 144 /*0x90*/;
    // 0045f440  890dc4f74f00           -mov dword ptr [0x4ff7c4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */) = cpu.ecx;
    // 0045f446  e815f0ffff             -call 0x45e460
    cpu.esp -= 4;
    sub_45e460(app, cpu);
    if (cpu.terminate) return;
    // 0045f44b  ba90000000             -mov edx, 0x90
    cpu.edx = 144 /*0x90*/;
    // 0045f450  a3d0f74f00             -mov dword ptr [0x4ff7d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5240784) /* 0x4ff7d0 */) = cpu.eax;
    // 0045f455  b8b0d44b00             -mov eax, 0x4bd4b0
    cpu.eax = 4969648 /*0x4bd4b0*/;
    // 0045f45a  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0045f45f  e8fcefffff             -call 0x45e460
    cpu.esp -= 4;
    sub_45e460(app, cpu);
    if (cpu.terminate) return;
    // 0045f464  bae0d64300             -mov edx, 0x43d6e0
    cpu.edx = 4445920 /*0x43d6e0*/;
    // 0045f469  a3ccf74f00             -mov dword ptr [0x4ff7cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5240780) /* 0x4ff7cc */) = cpu.eax;
    // 0045f46e  a1d0f74f00             -mov eax, dword ptr [0x4ff7d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240784) /* 0x4ff7d0 */);
    // 0045f473  e808efffff             -call 0x45e380
    cpu.esp -= 4;
    sub_45e380(app, cpu);
    if (cpu.terminate) return;
    // 0045f478  a144f54d00             -mov eax, dword ptr [0x4df544]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109060) /* 0x4df544 */);
    // 0045f47d  e81ea6feff             -call 0x449aa0
    cpu.esp -= 4;
    sub_449aa0(app, cpu);
    if (cpu.terminate) return;
    // 0045f482  e869c2fcff             -call 0x42b6f0
    cpu.esp -= 4;
    sub_42b6f0(app, cpu);
    if (cpu.terminate) return;
    // 0045f487  e824c2ffff             -call 0x45b6b0
    cpu.esp -= 4;
    sub_45b6b0(app, cpu);
    if (cpu.terminate) return;
    // 0045f48c  e81f440000             -call 0x4638b0
    cpu.esp -= 4;
    sub_4638b0(app, cpu);
    if (cpu.terminate) return;
    // 0045f491  e83ae7fdff             -call 0x43dbd0
    cpu.esp -= 4;
    sub_43dbd0(app, cpu);
    if (cpu.terminate) return;
    // 0045f496  e845820000             -call 0x4676e0
    cpu.esp -= 4;
    sub_4676e0(app, cpu);
    if (cpu.terminate) return;
    // 0045f49b  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0045f4a0  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 0045f4a5  e8c6be0000             -call 0x46b370
    cpu.esp -= 4;
    sub_46b370(app, cpu);
    if (cpu.terminate) return;
    // 0045f4aa  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0045f4af  baf4b04300             -mov edx, 0x43b0f4
    cpu.edx = 4436212 /*0x43b0f4*/;
    // 0045f4b4  e8b7be0000             -call 0x46b370
    cpu.esp -= 4;
    sub_46b370(app, cpu);
    if (cpu.terminate) return;
    // 0045f4b9  e802c2fcff             -call 0x42b6c0
    cpu.esp -= 4;
    sub_42b6c0(app, cpu);
    if (cpu.terminate) return;
    // 0045f4be  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0045f4c3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f4c5  e8a6be0000             -call 0x46b370
    cpu.esp -= 4;
    sub_46b370(app, cpu);
    if (cpu.terminate) return;
    // 0045f4ca  e85158fdff             -call 0x434d20
    cpu.esp -= 4;
    sub_434d20(app, cpu);
    if (cpu.terminate) return;
    // 0045f4cf  a1ccf74f00             -mov eax, dword ptr [0x4ff7cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240780) /* 0x4ff7cc */);
    // 0045f4d4  e8a7eeffff             -call 0x45e380
    cpu.esp -= 4;
    sub_45e380(app, cpu);
    if (cpu.terminate) return;
    // 0045f4d9  e892e6fdff             -call 0x43db70
    cpu.esp -= 4;
    sub_43db70(app, cpu);
    if (cpu.terminate) return;
    // 0045f4de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f4df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f4e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f4e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f4f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f4f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f4f2  81ec00030000           -sub esp, 0x300
    (cpu.esp) -= x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0045f4f8  833d28f54d0002         +cmp dword ptr [0x4df528], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f4ff  7c09                   -jl 0x45f50a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f50a;
    }
L_0x0045f501:
    // 0045f501  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0045f507  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f508  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f509  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f50a:
    // 0045f50a  8b0de48c4c00           -mov ecx, dword ptr [0x4c8ce4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5016804) /* 0x4c8ce4 */);
    // 0045f510  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0045f515  41                     -inc ecx
    (cpu.ecx)++;
    // 0045f516  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045f518  890de48c4c00           -mov dword ptr [0x4c8ce4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016804) /* 0x4c8ce4 */) = cpu.ecx;
    // 0045f51e  e8fd4b0100             -call 0x474120
    cpu.esp -= 4;
    sub_474120(app, cpu);
    if (cpu.terminate) return;
    // 0045f523  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045f525  74da                   -je 0x45f501
    if (cpu.flags.zf)
    {
        goto L_0x0045f501;
    }
    // 0045f527  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f528  8b1de48c4c00           -mov ebx, dword ptr [0x4c8ce4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5016804) /* 0x4c8ce4 */);
    // 0045f52e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f52f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045f533  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045f534  686cd44b00             -push 0x4bd46c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4969580 /*0x4bd46c*/;
    cpu.esp -= 4;
    // 0045f539  8d842410020000         -lea eax, [esp + 0x210]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0045f540  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045f541  e89bca0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0045f546  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045f549  e8a6890100             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 0045f54e  8d842404020000         -lea eax, [esp + 0x204]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 0045f555  e8fed80100             -call 0x47ce58
    cpu.esp -= 4;
    sub_47ce58(app, cpu);
    if (cpu.terminate) return;
    // 0045f55a  e8bd890100             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0045f55f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f560  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0045f566  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f567  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f568  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f570  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f571  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045f573  833dec8c4c0000         +cmp dword ptr [0x4c8cec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5016812) /* 0x4c8cec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f57a  743c                   -je 0x45f5b8
    if (cpu.flags.zf)
    {
        goto L_0x0045f5b8;
    }
    // 0045f57c  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045f584  7534                   -jne 0x45f5ba
    if (!cpu.flags.zf)
    {
        goto L_0x0045f5ba;
    }
    // 0045f586  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045f58d  752b                   -jne 0x45f5ba
    if (!cpu.flags.zf)
    {
        goto L_0x0045f5ba;
    }
    // 0045f58f  8b0d84f54d00           -mov ecx, dword ptr [0x4df584]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */);
    // 0045f595  49                     -dec ecx
    (cpu.ecx)--;
    // 0045f596  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045f598  7c1e                   -jl 0x45f5b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f5b8;
    }
    // 0045f59a  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0045f5a1  42                     -inc edx
    (cpu.edx)++;
    // 0045f5a2  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0045f5a4:
    // 0045f5a4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045f5a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f5a8  e887100000             -call 0x460634
    cpu.esp -= 4;
    sub_460634(app, cpu);
    if (cpu.terminate) return;
    // 0045f5ad  49                     -dec ecx
    (cpu.ecx)--;
    // 0045f5ae  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045f5b1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045f5b3  7def                   -jge 0x45f5a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045f5a4;
    }
    // 0045f5b5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0045f5b8:
    // 0045f5b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f5b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f5ba:
    // 0045f5ba  0fbe4201               -movsx eax, byte ptr [edx + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */)));
    // 0045f5be  e8ad0c0000             -call 0x460270
    cpu.esp -= 4;
    sub_460270(app, cpu);
    if (cpu.terminate) return;
    // 0045f5c3  8a1d7f074e00           -mov bl, byte ptr [0x4e077f]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
    // 0045f5c9  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045f5cc  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045f5cf  7415                   -je 0x45f5e6
    if (cpu.flags.zf)
    {
        goto L_0x0045f5e6;
    }
    // 0045f5d1  833d2cf54d0000         +cmp dword ptr [0x4df52c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f5d8  752f                   -jne 0x45f609
    if (!cpu.flags.zf)
    {
        goto L_0x0045f609;
    }
    // 0045f5da  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045f5df  e850100000             -call 0x460634
    cpu.esp -= 4;
    sub_460634(app, cpu);
    if (cpu.terminate) return;
    // 0045f5e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f5e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f5e6:
    // 0045f5e6  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045f5eb  e8d8150200             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0045f5f0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f5f2  e8691fffff             -call 0x451560
    cpu.esp -= 4;
    sub_451560(app, cpu);
    if (cpu.terminate) return;
    // 0045f5f7  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0045f5f8  e8030f0000             -call 0x460500
    cpu.esp -= 4;
    sub_460500(app, cpu);
    if (cpu.terminate) return;
    // 0045f5fd  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045f602  e8d9150200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0045f607  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f608  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f609:
    // 0045f609  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045f60b  e824100000             -call 0x460634
    cpu.esp -= 4;
    sub_460634(app, cpu);
    if (cpu.terminate) return;
    // 0045f610  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f611  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f621  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f622  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f623  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0045f626  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045f628  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045f62f  755d                   -jne 0x45f68e
    if (!cpu.flags.zf)
    {
        goto L_0x0045f68e;
    }
    // 0045f631  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045f639  7453                   -je 0x45f68e
    if (cpu.flags.zf)
    {
        goto L_0x0045f68e;
    }
    // 0045f63b  b305                   -mov bl, 5
    cpu.bl = 5 /*0x5*/;
    // 0045f63d  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045f642  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045f644  881c24                 -mov byte ptr [esp], bl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.bl;
    // 0045f647  e87c150200             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0045f64c  a12cf54d00             -mov eax, dword ptr [0x4df52c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 0045f651  e8de0f0000             -call 0x460634
    cpu.esp -= 4;
    sub_460634(app, cpu);
    if (cpu.terminate) return;
    // 0045f656  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045f658  7511                   -jne 0x45f66b
    if (!cpu.flags.zf)
    {
        goto L_0x0045f66b;
    }
    // 0045f65a  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045f65f  e87c150200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0045f664:
    // 0045f664  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0045f667  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f668  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f669  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f66a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f66b:
    // 0045f66b  8d442401               -lea eax, [esp + 1]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0045f66f  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 0045f674  e8870c0000             -call 0x460300
    cpu.esp -= 4;
    sub_460300(app, cpu);
    if (cpu.terminate) return;
    // 0045f679  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045f67e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045f680  e85b150200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0045f685  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045f687  e84421ffff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
    // 0045f68c  ebd6                   -jmp 0x45f664
    goto L_0x0045f664;
L_0x0045f68e:
    // 0045f68e  e8fd0b0000             -call 0x460290
    cpu.esp -= 4;
    sub_460290(app, cpu);
    if (cpu.terminate) return;
    // 0045f693  8a157f074e00           -mov dl, byte ptr [0x4e077f]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
    // 0045f699  a2f5f74f00             -mov byte ptr [0x4ff7f5], al
    app->getMemory<x86::reg8>(x86::reg32(5240821) /* 0x4ff7f5 */) = cpu.al;
    // 0045f69e  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0045f6a0  7510                   -jne 0x45f6b2
    if (!cpu.flags.zf)
    {
        goto L_0x0045f6b2;
    }
    // 0045f6a2  a12cf54d00             -mov eax, dword ptr [0x4df52c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 0045f6a7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045f6a9  e8860f0000             -call 0x460634
    cpu.esp -= 4;
    sub_460634(app, cpu);
    if (cpu.terminate) return;
    // 0045f6ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045f6b0  74b2                   -je 0x45f664
    if (cpu.flags.zf)
    {
        goto L_0x0045f664;
    }
L_0x0045f6b2:
    // 0045f6b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f6b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f6b4  b605                   -mov dh, 5
    cpu.dh = 5 /*0x5*/;
    // 0045f6b6  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045f6bb  bff6f74f00             -mov edi, 0x4ff7f6
    cpu.edi = 5240822 /*0x4ff7f6*/;
    // 0045f6c0  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0045f6c5  8835f4f74f00           -mov byte ptr [0x4ff7f4], dh
    app->getMemory<x86::reg8>(x86::reg32(5240820) /* 0x4ff7f4 */) = cpu.dh;
    // 0045f6cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f6cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f6ce  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f6d1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f6d3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f6d5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f6d8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f6da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6db  baf4f74f00             -mov edx, 0x4ff7f4
    cpu.edx = 5240820 /*0x4ff7f4*/;
    // 0045f6e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045f6e2  e8e920ffff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
    // 0045f6e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6e9  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0045f6ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_45f6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f6f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f6f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f6f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f6f3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045f6f5  8b3dd8f74f00           -mov edi, dword ptr [0x4ff7d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5240792) /* 0x4ff7d8 */);
    // 0045f6fb  8b0dd4f74f00           -mov ecx, dword ptr [0x4ff7d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5240788) /* 0x4ff7d4 */);
    // 0045f701  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0045f704  46                     -inc esi
    (cpu.esi)++;
    // 0045f705  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045f707  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045f709  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f70a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f70c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f70f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f711  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f713  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f716  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f718  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f719  0115d4f74f00           -add dword ptr [0x4ff7d4], edx
    (app->getMemory<x86::reg32>(x86::reg32(5240788) /* 0x4ff7d4 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045f71f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f720  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f721  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f722  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f730  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f731  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f732  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f733  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f734  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f735  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045f736  81ec94000000           -sub esp, 0x94
    (cpu.esp) -= x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0045f73c  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0045f741  be54f54d00             -mov esi, 0x4df554
    cpu.esi = 5109076 /*0x4df554*/;
    // 0045f746  8d7c2464               -lea edi, [esp + 0x64]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0045f74a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f74b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f74d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f750  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f752  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f754  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f757  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f759  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f75a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f75c  b918f54d00             -mov ecx, 0x4df518
    cpu.ecx = 5109016 /*0x4df518*/;
    // 0045f761  b8002d0000             -mov eax, 0x2d00
    cpu.eax = 11520 /*0x2d00*/;
    // 0045f766  8915d4f74f00           -mov dword ptr [0x4ff7d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5240788) /* 0x4ff7d4 */) = cpu.edx;
    // 0045f76c  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0045f771  890dd8f74f00           -mov dword ptr [0x4ff7d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240792) /* 0x4ff7d8 */) = cpu.ecx;
    // 0045f777  e81419ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045f77c  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045f784  0f84e0000000           -je 0x45f86a
    if (cpu.flags.zf)
    {
        goto L_0x0045f86a;
    }
    // 0045f78a  8b1d146c4c00           -mov ebx, dword ptr [0x4c6c14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5008404) /* 0x4c6c14 */);
    // 0045f790  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045f792  741c                   -je 0x45f7b0
    if (cpu.flags.zf)
    {
        goto L_0x0045f7b0;
    }
    // 0045f794  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0045f799  bf24fa4d00             -mov edi, 0x4dfa24
    cpu.edi = 5110308 /*0x4dfa24*/;
    // 0045f79e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0045f7a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f7a1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f7a3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f7a6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f7a8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f7aa  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f7ad  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f7af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045f7b0:
    // 0045f7b0  8b35106c4c00           -mov esi, dword ptr [0x4c6c10]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5008400) /* 0x4c6c10 */);
    // 0045f7b6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045f7b8  0f8587000000           -jne 0x45f845
    if (!cpu.flags.zf)
    {
        goto L_0x0045f845;
    }
L_0x0045f7be:
    // 0045f7be  b948000000             -mov ecx, 0x48
    cpu.ecx = 72 /*0x48*/;
    // 0045f7c3  bea4014e00             -mov esi, 0x4e01a4
    cpu.esi = 5112228 /*0x4e01a4*/;
    // 0045f7c8  bf36fa4d00             -mov edi, 0x4dfa36
    cpu.edi = 5110326 /*0x4dfa36*/;
    // 0045f7cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f7ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f7d0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f7d3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f7d5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f7d7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f7da  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f7dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f7dd  b404                   -mov ah, 4
    cpu.ah = 4 /*0x4*/;
    // 0045f7df  bfb0050000             -mov edi, 0x5b0
    cpu.edi = 1456 /*0x5b0*/;
    // 0045f7e4  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0045f7e7  89bc2490000000         -mov dword ptr [esp + 0x90], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edi;
L_0x0045f7ee:
    // 0045f7ee  bd62000000             -mov ebp, 0x62
    cpu.ebp = 98 /*0x62*/;
L_0x0045f7f3:
    // 0045f7f3  8d7c2401               -lea edi, [esp + 1]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0045f7f7  8b35d8f74f00           -mov esi, dword ptr [0x4ff7d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240792) /* 0x4ff7d8 */);
    // 0045f7fd  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0045f7ff  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045f801  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f802  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f804  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f807  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f809  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f80b  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f80e  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f810  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f811  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0045f814  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045f816  e8b51fffff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
    // 0045f81b  a1d8f74f00             -mov eax, dword ptr [0x4ff7d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240792) /* 0x4ff7d8 */);
    // 0045f820  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0045f827  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045f829  83ea62                 -sub edx, 0x62
    (cpu.edx) -= x86::reg32(x86::sreg32(98 /*0x62*/));
    // 0045f82c  a3d8f74f00             -mov dword ptr [0x4ff7d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5240792) /* 0x4ff7d8 */) = cpu.eax;
    // 0045f831  89942490000000         -mov dword ptr [esp + 0x90], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 0045f838  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045f83a  7e2e                   -jle 0x45f86a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f86a;
    }
    // 0045f83c  83fa62                 +cmp edx, 0x62
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98 /*0x62*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f83f  7dad                   -jge 0x45f7ee
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045f7ee;
    }
    // 0045f841  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0045f843  ebae                   -jmp 0x45f7f3
    goto L_0x0045f7f3;
L_0x0045f845:
    // 0045f845  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045f84a  bf14fa4d00             -mov edi, 0x4dfa14
    cpu.edi = 5110292 /*0x4dfa14*/;
    // 0045f84f  81c6b0020000           -add esi, 0x2b0
    (cpu.esi) += x86::reg32(x86::sreg32(688 /*0x2b0*/));
    // 0045f855  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f856  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f858  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f85b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f85d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f85f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f862  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f864  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f865  e954ffffff             -jmp 0x45f7be
    goto L_0x0045f7be;
L_0x0045f86a:
    // 0045f86a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0045f86f  b8000f0000             -mov eax, 0xf00
    cpu.eax = 3840 /*0xf00*/;
    // 0045f874  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0045f879  e81218ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045f87e  8b152a074e00           -mov edx, dword ptr [0x4e072a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113642) /* 0x4e072a */);
    // 0045f884  8d742464               -lea esi, [esp + 0x64]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0045f888  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045f88b  bf54f54d00             -mov edi, 0x4df554
    cpu.edi = 5109076 /*0x4df554*/;
    // 0045f890  89152cf54d00           -mov dword ptr [0x4df52c], edx
    app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */) = cpu.edx;
    // 0045f896  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f897  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f899  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f89c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f89e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f8a0  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f8a3  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f8a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f8a6  8b35146c4c00           -mov esi, dword ptr [0x4c6c14]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5008404) /* 0x4c6c14 */);
    // 0045f8ac  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045f8ae  741c                   -je 0x45f8cc
    if (cpu.flags.zf)
    {
        goto L_0x0045f8cc;
    }
    // 0045f8b0  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0045f8b5  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0045f8b7  be24fa4d00             -mov esi, 0x4dfa24
    cpu.esi = 5110308 /*0x4dfa24*/;
    // 0045f8bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f8bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f8bf  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f8c2  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f8c4  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f8c6  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f8c9  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f8cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045f8cc:
    // 0045f8cc  8b3d106c4c00           -mov edi, dword ptr [0x4c6c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5008400) /* 0x4c6c10 */);
    // 0045f8d2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045f8d4  752c                   -jne 0x45f902
    if (!cpu.flags.zf)
    {
        goto L_0x0045f902;
    }
L_0x0045f8d6:
    // 0045f8d6  b948000000             -mov ecx, 0x48
    cpu.ecx = 72 /*0x48*/;
    // 0045f8db  be36fa4d00             -mov esi, 0x4dfa36
    cpu.esi = 5110326 /*0x4dfa36*/;
    // 0045f8e0  bfa4014e00             -mov edi, 0x4e01a4
    cpu.edi = 5112228 /*0x4e01a4*/;
    // 0045f8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f8e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f8e8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f8eb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f8ed  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f8ef  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f8f2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f8f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f8f5  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0045f8fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f8fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f8fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f8fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f8ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f900  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f901  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f902:
    // 0045f902  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045f907  be14fa4d00             -mov esi, 0x4dfa14
    cpu.esi = 5110292 /*0x4dfa14*/;
    // 0045f90c  81c7b0020000           -add edi, 0x2b0
    (cpu.edi) += x86::reg32(x86::sreg32(688 /*0x2b0*/));
    // 0045f912  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f913  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f915  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045f918  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f91a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045f91c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045f91f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045f921  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f922  ebb2                   -jmp 0x45f8d6
    goto L_0x0045f8d6;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f930  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0045f933  833d34f54d0001         +cmp dword ptr [0x4df534], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f93a  7e04                   -jle 0x45f940
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f940;
    }
    // 0045f93c  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0045f93f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f940:
    // 0045f940  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f941  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f943  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f944  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f945  e8be850100             -call 0x477f08
    cpu.esp -= 4;
    sub_477f08(app, cpu);
    if (cpu.terminate) return;
    // 0045f94a  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0045f94f  e89c880100             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 0045f954  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045f959  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045f95d  e8ce87feff             -call 0x448130
    cpu.esp -= 4;
    sub_448130(app, cpu);
    if (cpu.terminate) return;
    // 0045f962  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045f964  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045f965:
    // 0045f965  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045f967  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045f969  3c00                   +cmp al, 0
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
    // 0045f96b  7410                   -je 0x45f97d
    if (cpu.flags.zf)
    {
        goto L_0x0045f97d;
    }
    // 0045f96d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045f970  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045f973  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045f976  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045f979  3c00                   +cmp al, 0
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
    // 0045f97b  75e8                   -jne 0x45f965
    if (!cpu.flags.zf)
    {
        goto L_0x0045f965;
    }
L_0x0045f97d:
    // 0045f97d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f97e  beb8d44b00             -mov esi, 0x4bd4b8
    cpu.esi = 4969656 /*0x4bd4b8*/;
    // 0045f983  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045f987  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f988  2bc9                   +sub ecx, ecx
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
    // 0045f98a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0045f98b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0045f98d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0045f98f  4f                     -dec edi
    (cpu.edi)--;
L_0x0045f990:
    // 0045f990  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045f992  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045f994  3c00                   +cmp al, 0
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
    // 0045f996  7410                   -je 0x45f9a8
    if (cpu.flags.zf)
    {
        goto L_0x0045f9a8;
    }
    // 0045f998  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045f99b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045f99e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045f9a1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045f9a4  3c00                   +cmp al, 0
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
    // 0045f9a6  75e8                   -jne 0x45f990
    if (!cpu.flags.zf)
    {
        goto L_0x0045f990;
    }
L_0x0045f9a8:
    // 0045f9a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f9a9  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045f9ad  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045f9af  49                     -dec ecx
    (cpu.ecx)--;
    // 0045f9b0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045f9b2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0045f9b4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0045f9b6  49                     -dec ecx
    (cpu.ecx)--;
    // 0045f9b7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045f9b9  d1ea                   -shr edx, 1
    cpu.edx >>= 1 /*0x1*/ % 32;
    // 0045f9bb  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045f9c2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045f9c4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f9c6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045f9c9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f9cb  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0045f9d0  bbdc000000             -mov ebx, 0xdc
    cpu.ebx = 220 /*0xdc*/;
    // 0045f9d5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045f9d7  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045f9db  e8c09d0000             -call 0x4697a0
    cpu.esp -= 4;
    sub_4697a0(app, cpu);
    if (cpu.terminate) return;
    // 0045f9e0  e86bd50200             -call 0x48cf50
    cpu.esp -= 4;
    sub_48cf50(app, cpu);
    if (cpu.terminate) return;
    // 0045f9e5  e81e850100             -call 0x477f08
    cpu.esp -= 4;
    sub_477f08(app, cpu);
    if (cpu.terminate) return;
    // 0045f9ea  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0045f9ef  e8fc870100             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 0045f9f4  e823850100             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0045f9f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f9fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f9fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f9fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f9fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f9fe  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0045fa01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45fa20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0045fa20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045fa21  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045fa23  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0045fa26  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045fa28  771d                   -ja 0x45fa47
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045fa47;
    }
    // 0045fa2a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0045fa2f  ff248510fa4500         -jmp dword ptr [eax*4 + 0x45fa10]
    cpu.ip = app->getMemory<x86::reg32>(4586000 + cpu.eax * 4); goto dynamic_jump;
  case 0x0045fa36:
    // 0045fa36  833d2cf54d0000         +cmp dword ptr [0x4df52c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fa3d  740a                   -je 0x45fa49
    if (cpu.flags.zf)
    {
        goto L_0x0045fa49;
    }
    // 0045fa3f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0045fa42  a3e0f74f00             -mov dword ptr [0x4ff7e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */) = cpu.eax;
L_0x0045fa47:
    // 0045fa47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fa48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fa49:
    // 0045fa49  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045fa4e  e875110200             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0045fa53  833de0f74f0000         +cmp dword ptr [0x4ff7e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fa5a  7519                   -jne 0x45fa75
    if (!cpu.flags.zf)
    {
        goto L_0x0045fa75;
    }
    // 0045fa5c  e88f080000             -call 0x4602f0
    cpu.esp -= 4;
    sub_4602f0(app, cpu);
    if (cpu.terminate) return;
    // 0045fa61  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045fa66  a3e0f74f00             -mov dword ptr [0x4ff7e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */) = cpu.eax;
    // 0045fa6b  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045fa6e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045fa70  e85b1dffff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
L_0x0045fa75:
    // 0045fa75  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045fa7a  e861110200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0045fa7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fa80  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045fa81:
    // 0045fa81  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045fa89  740c                   -je 0x45fa97
    if (cpu.flags.zf)
    {
        goto L_0x0045fa97;
    }
    // 0045fa8b  c705dcf74f0001000000   -mov dword ptr [0x4ff7dc], 1
    app->getMemory<x86::reg32>(x86::reg32(5240796) /* 0x4ff7dc */) = 1 /*0x1*/;
    // 0045fa95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fa96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fa97:
    // 0045fa97  66c7054a074e001200     -mov word ptr [0x4e074a], 0x12
    app->getMemory<x86::reg16>(x86::reg32(5113674) /* 0x4e074a */) = 18 /*0x12*/;
    // 0045faa0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045faa1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045faa2:
    // 0045faa2  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045faaa  759b                   -jne 0x45fa47
    if (!cpu.flags.zf)
    {
        goto L_0x0045fa47;
    }
    // 0045faac  66c7054a074e001500     -mov word ptr [0x4e074a], 0x15
    app->getMemory<x86::reg16>(x86::reg32(5113674) /* 0x4e074a */) = 21 /*0x15*/;
    // 0045fab5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fab6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045fab7:
    // 0045fab7  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045fabf  750b                   -jne 0x45facc
    if (!cpu.flags.zf)
    {
        goto L_0x0045facc;
    }
    // 0045fac1  66c7054a074e001600     -mov word ptr [0x4e074a], 0x16
    app->getMemory<x86::reg16>(x86::reg32(5113674) /* 0x4e074a */) = 22 /*0x16*/;
    // 0045faca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045facb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045facc:
    // 0045facc  a1646c4c00             -mov eax, dword ptr [0x4c6c64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008484) /* 0x4c6c64 */);
    // 0045fad1  e8f2100200             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0045fad6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045fad8  e8831affff             -call 0x451560
    cpu.esp -= 4;
    sub_451560(app, cpu);
    if (cpu.terminate) return;
    // 0045fadd  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0045fade  66c7044558074e001600   -mov word ptr [eax*2 + 0x4e0758], 0x16
    app->getMemory<x86::reg16>(x86::reg32(5113688) /* 0x4e0758 */ + cpu.eax * 2) = 22 /*0x16*/;
    // 0045fae8  a1646c4c00             -mov eax, dword ptr [0x4c6c64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008484) /* 0x4c6c64 */);
    // 0045faed  e8ee100200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0045faf2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045faf3  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45fb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045fb00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045fb01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045fb02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045fb03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045fb04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045fb05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045fb06  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fb09  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045fb0b  8b1528f54d00           -mov edx, dword ptr [0x4df528]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0045fb11  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045fb13  740e                   -je 0x45fb23
    if (cpu.flags.zf)
    {
        goto L_0x0045fb23;
    }
    // 0045fb15  83fa01                 +cmp edx, 1
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
    // 0045fb18  7409                   -je 0x45fb23
    if (cpu.flags.zf)
    {
        goto L_0x0045fb23;
    }
    // 0045fb1a  833d34f54d0001         +cmp dword ptr [0x4df534], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fb21  7e0e                   -jle 0x45fb31
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fb31;
    }
L_0x0045fb23:
    // 0045fb23  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045fb25  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fb27  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fb2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fb2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fb2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fb2d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fb2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fb2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fb30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fb31:
    // 0045fb31  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 0045fb36  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045fb38  e8a37f0100             -call 0x477ae0
    cpu.esp -= 4;
    sub_477ae0(app, cpu);
    if (cpu.terminate) return;
    // 0045fb3d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045fb3f  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0045fb45  81f9ff000000           +cmp ecx, 0xff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fb4b  7d09                   -jge 0x45fb56
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045fb56;
    }
    // 0045fb4d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045fb4f  e8aec40100             -call 0x47c002
    cpu.esp -= 4;
    sub_47c002(app, cpu);
    if (cpu.terminate) return;
    // 0045fb54  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0045fb56:
    // 0045fb56  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045fb58  0f84ae000000           -je 0x45fc0c
    if (cpu.flags.zf)
    {
        goto L_0x0045fc0c;
    }
    // 0045fb5e  3b0df0f74f00           +cmp ecx, dword ptr [0x4ff7f0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240816) /* 0x4ff7f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fb64  0f8496000000           -je 0x45fc00
    if (cpu.flags.zf)
    {
        goto L_0x0045fc00;
    }
L_0x0045fb6a:
    // 0045fb6a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045fb6f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045fb71  e83a19fcff             -call 0x4214b0
    cpu.esp -= 4;
    sub_4214b0(app, cpu);
    if (cpu.terminate) return;
    // 0045fb76  3b0df0f74f00           +cmp ecx, dword ptr [0x4ff7f0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240816) /* 0x4ff7f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fb7c  0f849c000000           -je 0x45fc1e
    if (cpu.flags.zf)
    {
        goto L_0x0045fc1e;
    }
    // 0045fb82  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x0045fb85:
    // 0045fb85  8935ecf74f00           -mov dword ptr [0x4ff7ec], esi
    app->getMemory<x86::reg32>(x86::reg32(5240812) /* 0x4ff7ec */) = cpu.esi;
    // 0045fb8b  890df0f74f00           -mov dword ptr [0x4ff7f0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240816) /* 0x4ff7f0 */) = cpu.ecx;
L_0x0045fb91:
    // 0045fb91  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045fb99  0f84a3010000           -je 0x45fd42
    if (cpu.flags.zf)
    {
        goto L_0x0045fd42;
    }
    // 0045fb9f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0045fba4  3b0d84f54d00           +cmp ecx, dword ptr [0x4df584]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fbaa  0f8dd1000000           -jge 0x45fc81
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045fc81;
    }
    // 0045fbb0  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0045fbb5:
    // 0045fbb5  833ddcf74f0000         +cmp dword ptr [0x4ff7dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240796) /* 0x4ff7dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fbbc  7468                   -je 0x45fc26
    if (cpu.flags.zf)
    {
        goto L_0x0045fc26;
    }
L_0x0045fbbe:
    // 0045fbbe  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0045fbc3  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045fbc8  e8c314ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045fbcd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045fbcf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045fbd4  893dfc8c4c00           -mov dword ptr [0x4c8cfc], edi
    app->getMemory<x86::reg32>(x86::reg32(5016828) /* 0x4c8cfc */) = cpu.edi;
    // 0045fbda  893ddcf74f00           -mov dword ptr [0x4ff7dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5240796) /* 0x4ff7dc */) = cpu.edi;
    // 0045fbe0  e8bb18fcff             -call 0x4214a0
    cpu.esp -= 4;
    sub_4214a0(app, cpu);
    if (cpu.terminate) return;
    // 0045fbe5  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045fbea  e8a114ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045fbef  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045fbf4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fbf6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fbf9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fbfa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fbfb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fbfc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fbfd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fbfe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fbff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fc00:
    // 0045fc00  3b35ecf74f00           +cmp esi, dword ptr [0x4ff7ec]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240812) /* 0x4ff7ec */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fc06  0f8f5effffff           -jg 0x45fb6a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045fb6a;
    }
L_0x0045fc0c:
    // 0045fc0c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045fc0e  890df0f74f00           -mov dword ptr [0x4ff7f0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240816) /* 0x4ff7f0 */) = cpu.ecx;
    // 0045fc14  a3ecf74f00             -mov dword ptr [0x4ff7ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5240812) /* 0x4ff7ec */) = cpu.eax;
    // 0045fc19  e973ffffff             -jmp 0x45fb91
    goto L_0x0045fb91;
L_0x0045fc1e:
    // 0045fc1e  83c605                 +add esi, 5
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045fc21  e95fffffff             -jmp 0x45fb85
    goto L_0x0045fb85;
L_0x0045fc26:
    // 0045fc26  668b8258074e00         -mov ax, word ptr [edx + 0x4e0758]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5113688) /* 0x4e0758 */);
    // 0045fc2d  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0045fc30  763d                   -jbe 0x45fc6f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045fc6f;
    }
    // 0045fc32  663d1600               +cmp ax, 0x16
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045fc36  756c                   -jne 0x45fca4
    if (!cpu.flags.zf)
    {
        goto L_0x0045fca4;
    }
    // 0045fc38  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045fc3f  755c                   -jne 0x45fc9d
    if (!cpu.flags.zf)
    {
        goto L_0x0045fc9d;
    }
    // 0045fc41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045fc43  e898c60000             -call 0x46c2e0
    cpu.esp -= 4;
    sub_46c2e0(app, cpu);
    if (cpu.terminate) return;
L_0x0045fc48:
    // 0045fc48  a1646c4c00             -mov eax, dword ptr [0x4c6c64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008484) /* 0x4c6c64 */);
    // 0045fc4d  e8760f0200             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0045fc52  6683ba58074e0016       +cmp word ptr [edx + 0x4e0758], 0x16
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5113688) /* 0x4e0758 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045fc5a  7509                   -jne 0x45fc65
    if (!cpu.flags.zf)
    {
        goto L_0x0045fc65;
    }
    // 0045fc5c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045fc5e  6689ba58074e00         -mov word ptr [edx + 0x4e0758], di
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5113688) /* 0x4e0758 */) = cpu.di;
L_0x0045fc65:
    // 0045fc65  a1646c4c00             -mov eax, dword ptr [0x4c6c64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008484) /* 0x4c6c64 */);
    // 0045fc6a  e8710f0200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0045fc6f:
    // 0045fc6f  8b2d84f54d00           -mov ebp, dword ptr [0x4df584]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */);
    // 0045fc75  41                     -inc ecx
    (cpu.ecx)++;
    // 0045fc76  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045fc79  39e9                   +cmp ecx, ebp
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
    // 0045fc7b  0f8c34ffffff           -jl 0x45fbb5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045fbb5;
    }
L_0x0045fc81:
    // 0045fc81  83fb02                 +cmp ebx, 2
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
    // 0045fc84  733d                   -jae 0x45fcc3
    if (!cpu.flags.cf)
    {
        goto L_0x0045fcc3;
    }
    // 0045fc86  83fb01                 +cmp ebx, 1
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
    // 0045fc89  0f842fffffff           -je 0x45fbbe
    if (cpu.flags.zf)
    {
        goto L_0x0045fbbe;
    }
L_0x0045fc8f:
    // 0045fc8f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045fc91  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fc93  83c410                 +add esp, 0x10
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
    // 0045fc96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fc97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fc98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fc99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fc9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fc9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fc9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fc9d:
    // 0045fc9d  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0045fca2  eba4                   -jmp 0x45fc48
    goto L_0x0045fc48;
L_0x0045fca4:
    // 0045fca4  a1646c4c00             -mov eax, dword ptr [0x4c6c64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008484) /* 0x4c6c64 */);
    // 0045fca9  e81a0f0200             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0045fcae  6683ba58074e0016       +cmp word ptr [edx + 0x4e0758], 0x16
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5113688) /* 0x4e0758 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045fcb6  74ad                   -je 0x45fc65
    if (cpu.flags.zf)
    {
        goto L_0x0045fc65;
    }
    // 0045fcb8  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0045fcba  6689b258074e00         -mov word ptr [edx + 0x4e0758], si
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5113688) /* 0x4e0758 */) = cpu.si;
    // 0045fcc1  eba2                   -jmp 0x45fc65
    goto L_0x0045fc65;
L_0x0045fcc3:
    // 0045fcc3  7658                   -jbe 0x45fd1d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045fd1d;
    }
    // 0045fcc5  83fb03                 +cmp ebx, 3
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
    // 0045fcc8  75c5                   -jne 0x45fc8f
    if (!cpu.flags.zf)
    {
        goto L_0x0045fc8f;
    }
    // 0045fcca  8b15a0f14d00           -mov edx, dword ptr [0x4df1a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 0045fcd0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045fcd2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045fcd4  7e22                   -jle 0x45fcf8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fcf8;
    }
    // 0045fcd6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0045fcd8:
    // 0045fcd8  8b8a28f04d00           -mov ecx, dword ptr [edx + 0x4df028]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107752) /* 0x4df028 */);
    // 0045fcde  40                     -inc eax
    (cpu.eax)++;
    // 0045fcdf  c7818002000001000000   -mov dword ptr [ecx + 0x280], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
    // 0045fce9  8b0da0f14d00           -mov ecx, dword ptr [0x4df1a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 0045fcef  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045fcf2  39c8                   +cmp eax, ecx
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
    // 0045fcf4  7ce2                   -jl 0x45fcd8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045fcd8;
    }
    // 0045fcf6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0045fcf8:
    // 0045fcf8  ba16000000             -mov edx, 0x16
    cpu.edx = 22 /*0x16*/;
    // 0045fcfd  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045fd02  e88913ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045fd07  e89417fcff             -call 0x4214a0
    cpu.esp -= 4;
    sub_4214a0(app, cpu);
    if (cpu.terminate) return;
    // 0045fd0c  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0045fd11  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fd13  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fd16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd17  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fd1d:
    // 0045fd1d  ba15000000             -mov edx, 0x15
    cpu.edx = 21 /*0x15*/;
    // 0045fd22  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045fd27  e86413ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045fd2c  e86f17fcff             -call 0x4214a0
    cpu.esp -= 4;
    sub_4214a0(app, cpu);
    if (cpu.terminate) return;
    // 0045fd31  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0045fd36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fd38  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fd3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fd42:
    // 0045fd42  66a14a074e00           -mov ax, word ptr [0x4e074a]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5113674) /* 0x4e074a */);
    // 0045fd48  663d1500               +cmp ax, 0x15
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21 /*0x15*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045fd4c  733d                   -jae 0x45fd8b
    if (!cpu.flags.cf)
    {
        goto L_0x0045fd8b;
    }
    // 0045fd4e  663d1200               +cmp ax, 0x12
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18 /*0x12*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045fd52  0f848d000000           -je 0x45fde5
    if (cpu.flags.zf)
    {
        goto L_0x0045fde5;
    }
L_0x0045fd58:
    // 0045fd58  83fb01                 +cmp ebx, 1
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
    // 0045fd5b  0f85c0000000           -jne 0x45fe21
    if (!cpu.flags.zf)
    {
        goto L_0x0045fe21;
    }
    // 0045fd61  b307                   -mov bl, 7
    cpu.bl = 7 /*0x7*/;
    // 0045fd63  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045fd67  885c2408               -mov byte ptr [esp + 8], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 0045fd6b  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
    // 0045fd6d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045fd6f  887c2409               -mov byte ptr [esp + 9], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */) = cpu.bh;
    // 0045fd73  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045fd78  e8531affff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
L_0x0045fd7d:
    // 0045fd7d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045fd7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fd81  83c410                 +add esp, 0x10
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
    // 0045fd84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd87  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fd8a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fd8b:
    // 0045fd8b  7690                   -jbe 0x45fd1d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045fd1d;
    }
    // 0045fd8d  663d1600               +cmp ax, 0x16
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045fd91  75c5                   -jne 0x45fd58
    if (!cpu.flags.zf)
    {
        goto L_0x0045fd58;
    }
    // 0045fd93  8b0da0f14d00           -mov ecx, dword ptr [0x4df1a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 0045fd99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045fd9b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045fd9d  7e21                   -jle 0x45fdc0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fdc0;
    }
    // 0045fd9f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0045fda1:
    // 0045fda1  8b3da0f14d00           -mov edi, dword ptr [0x4df1a0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 0045fda7  8b8a28f04d00           -mov ecx, dword ptr [edx + 0x4df028]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107752) /* 0x4df028 */);
    // 0045fdad  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045fdb0  40                     -inc eax
    (cpu.eax)++;
    // 0045fdb1  c7818002000001000000   -mov dword ptr [ecx + 0x280], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
    // 0045fdbb  39f8                   +cmp eax, edi
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
    // 0045fdbd  7ce2                   -jl 0x45fda1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045fda1;
    }
    // 0045fdbf  90                     -nop 
    ;
L_0x0045fdc0:
    // 0045fdc0  ba16000000             -mov edx, 0x16
    cpu.edx = 22 /*0x16*/;
    // 0045fdc5  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045fdca  e8c112ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045fdcf  e8cc16fcff             -call 0x4214a0
    cpu.esp -= 4;
    sub_4214a0(app, cpu);
    if (cpu.terminate) return;
    // 0045fdd4  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0045fdd9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fddb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fdde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fddf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fde0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fde1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fde2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fde3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fde4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fde5:
    // 0045fde5  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0045fdea  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045fdef  e89c12ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045fdf4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045fdf6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045fdfb  891dfc8c4c00           -mov dword ptr [0x4c8cfc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5016828) /* 0x4c8cfc */) = cpu.ebx;
    // 0045fe01  e89a16fcff             -call 0x4214a0
    cpu.esp -= 4;
    sub_4214a0(app, cpu);
    if (cpu.terminate) return;
    // 0045fe06  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045fe0b  e88012ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045fe10  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045fe15  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fe17  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fe1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fe21:
    // 0045fe21  83fb03                 +cmp ebx, 3
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
    // 0045fe24  0f8553ffffff           -jne 0x45fd7d
    if (!cpu.flags.zf)
    {
        goto L_0x0045fd7d;
    }
    // 0045fe2a  b407                   -mov ah, 7
    cpu.ah = 7 /*0x7*/;
    // 0045fe2c  b203                   -mov dl, 3
    cpu.dl = 3 /*0x3*/;
    // 0045fe2e  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045fe33  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0045fe36  88542401               -mov byte ptr [esp + 1], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0045fe3a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045fe3c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045fe3e  e88d19ffff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
    // 0045fe43  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045fe4a  0f852dffffff           -jne 0x45fd7d
    if (!cpu.flags.zf)
    {
        goto L_0x0045fd7d;
    }
    // 0045fe50  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045fe55  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0045fe5a  66891d7c074e00         -mov word ptr [0x4e077c], bx
    app->getMemory<x86::reg16>(x86::reg32(5113724) /* 0x4e077c */) = cpu.bx;
    // 0045fe61  66891d7a074e00         -mov word ptr [0x4e077a], bx
    app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */) = cpu.bx;
    // 0045fe68  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fe6a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fe6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe70  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe71  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45fe80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045fe80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045fe81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045fe82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045fe83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045fe84  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045fe87  8b1528f54d00           -mov edx, dword ptr [0x4df528]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0045fe8d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045fe8f  0f8477000000           -je 0x45ff0c
    if (cpu.flags.zf)
    {
        goto L_0x0045ff0c;
    }
    // 0045fe95  83fa01                 +cmp edx, 1
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
    // 0045fe98  0f846e000000           -je 0x45ff0c
    if (cpu.flags.zf)
    {
        goto L_0x0045ff0c;
    }
    // 0045fe9e  833d34f54d0001         +cmp dword ptr [0x4df534], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fea5  7f65                   -jg 0x45ff0c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045ff0c;
    }
    // 0045fea7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045fea9  7456                   -je 0x45ff01
    if (cpu.flags.zf)
    {
        goto L_0x0045ff01;
    }
    // 0045feab  8b35e0f74f00           -mov esi, dword ptr [0x4ff7e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */);
    // 0045feb1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045feb3  754c                   -jne 0x45ff01
    if (!cpu.flags.zf)
    {
        goto L_0x0045ff01;
    }
    // 0045feb5  833df08c4c0000         +cmp dword ptr [0x4c8cf0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5016816) /* 0x4c8cf0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045febc  7543                   -jne 0x45ff01
    if (!cpu.flags.zf)
    {
        goto L_0x0045ff01;
    }
    // 0045febe  8b15e4f74f00           -mov edx, dword ptr [0x4ff7e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240804) /* 0x4ff7e4 */);
    // 0045fec4  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0045fec7  e814040000             -call 0x4602e0
    cpu.esp -= 4;
    sub_4602e0(app, cpu);
    if (cpu.terminate) return;
    // 0045fecc  39c2                   +cmp edx, eax
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
    // 0045fece  7d31                   -jge 0x45ff01
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ff01;
    }
    // 0045fed0  b407                   -mov ah, 7
    cpu.ah = 7 /*0x7*/;
    // 0045fed2  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0045fed4  8b2d2cf54d00           -mov ebp, dword ptr [0x4df52c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 0045feda  88542401               -mov byte ptr [esp + 1], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0045fede  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0045fee1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045fee3  742f                   -je 0x45ff14
    if (cpu.flags.zf)
    {
        goto L_0x0045ff14;
    }
    // 0045fee5  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045feea  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045feec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045feee  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0045fef2  e8d918ffff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
    // 0045fef7  c705f08c4c0001000000   -mov dword ptr [0x4c8cf0], 1
    app->getMemory<x86::reg32>(x86::reg32(5016816) /* 0x4c8cf0 */) = 1 /*0x1*/;
L_0x0045ff01:
    // 0045ff01  833de0f74f0000         +cmp dword ptr [0x4ff7e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ff08  753c                   -jne 0x45ff46
    if (!cpu.flags.zf)
    {
        goto L_0x0045ff46;
    }
L_0x0045ff0a:
    // 0045ff0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045ff0c:
    // 0045ff0c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045ff0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ff14:
    // 0045ff14  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045ff19  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045ff1e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045ff20  e8a30c0200             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0045ff25  e8c6030000             -call 0x4602f0
    cpu.esp -= 4;
    sub_4602f0(app, cpu);
    if (cpu.terminate) return;
    // 0045ff2a  a3e0f74f00             -mov dword ptr [0x4ff7e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */) = cpu.eax;
    // 0045ff2f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045ff33  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045ff35  e89618ffff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
    // 0045ff3a  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045ff3f  e89c0c0200             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0045ff44  ebbb                   -jmp 0x45ff01
    goto L_0x0045ff01;
L_0x0045ff46:
    // 0045ff46  e895030000             -call 0x4602e0
    cpu.esp -= 4;
    sub_4602e0(app, cpu);
    if (cpu.terminate) return;
    // 0045ff4b  3b05e0f74f00           +cmp eax, dword ptr [0x4ff7e0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ff51  75b7                   -jne 0x45ff0a
    if (!cpu.flags.zf)
    {
        goto L_0x0045ff0a;
    }
    // 0045ff53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ff54  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045ff59  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 0045ff5e  b8000f0000             -mov eax, 0xf00
    cpu.eax = 3840 /*0xf00*/;
    // 0045ff63  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045ff65  8935f88c4c00           -mov dword ptr [0x4c8cf8], esi
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.esi;
    // 0045ff6b  e82011ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045ff70  a1e0f74f00             -mov eax, dword ptr [0x4ff7e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */);
    // 0045ff75  893df08c4c00           -mov dword ptr [0x4c8cf0], edi
    app->getMemory<x86::reg32>(x86::reg32(5016816) /* 0x4c8cf0 */) = cpu.edi;
    // 0045ff7b  893ddcf74f00           -mov dword ptr [0x4ff7dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5240796) /* 0x4ff7dc */) = cpu.edi;
    // 0045ff81  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ff83  a3e4f74f00             -mov dword ptr [0x4ff7e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5240804) /* 0x4ff7e4 */) = cpu.eax;
    // 0045ff88  893de0f74f00           -mov dword ptr [0x4ff7e0], edi
    app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */) = cpu.edi;
    // 0045ff8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045ff8f:
    // 0045ff8f  e8e8da0100             -call 0x47da7c
    cpu.esp -= 4;
    sub_47da7c(app, cpu);
    if (cpu.terminate) return;
    // 0045ff94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ff96  7409                   -je 0x45ffa1
    if (cpu.flags.zf)
    {
        goto L_0x0045ffa1;
    }
    // 0045ff98  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045ff9a  e8a19c0100             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0045ff9f  ebee                   -jmp 0x45ff8f
    goto L_0x0045ff8f;
L_0x0045ffa1:
    // 0045ffa1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045ffa6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045ffa9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45ffb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ffb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ffb1  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0045ffb6  b8003c0000             -mov eax, 0x3c00
    cpu.eax = 15360 /*0x3c00*/;
    // 0045ffbb  e8d010ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0045ffc0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ffc2  a1e8f74f00             -mov eax, dword ptr [0x4ff7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */);
    // 0045ffc7  8915ec8c4c00           -mov dword ptr [0x4c8cec], edx
    app->getMemory<x86::reg32>(x86::reg32(5016812) /* 0x4c8cec */) = cpu.edx;
    // 0045ffcd  e8220c0200             -call 0x480bf4
    cpu.esp -= 4;
    sub_480bf4(app, cpu);
    if (cpu.terminate) return;
    // 0045ffd2  66833d7a074e0000       +cmp word ptr [0x4e077a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045ffda  7502                   -jne 0x45ffde
    if (!cpu.flags.zf)
    {
        goto L_0x0045ffde;
    }
    // 0045ffdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffdd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ffde:
    // 0045ffde  e8510f0200             -call 0x480f34
    cpu.esp -= 4;
    sub_480f34(app, cpu);
    if (cpu.terminate) return;
    // 0045ffe3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffe4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45fff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045fff0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045fff1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045fff2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0045fff7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045fff9  890de4f74f00           -mov dword ptr [0x4ff7e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240804) /* 0x4ff7e4 */) = cpu.ecx;
    // 0045ffff  8915e0f74f00           -mov dword ptr [0x4ff7e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5240800) /* 0x4ff7e0 */) = cpu.edx;
    // 00460005  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460006  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460007  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460010  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460011  e8620b0200             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00460016  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046001b  a3e8f74f00             -mov dword ptr [0x4ff7e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5240808) /* 0x4ff7e8 */) = cpu.eax;
    // 00460020  8915ec8c4c00           -mov dword ptr [0x4c8cec], edx
    app->getMemory<x86::reg32>(x86::reg32(5016812) /* 0x4c8cec */) = cpu.edx;
    // 00460026  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460027  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460044(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00460044  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460045  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460046  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460047  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460048  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460049  8b1528f54d00           -mov edx, dword ptr [0x4df528]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0046004f  83fa04                 +cmp edx, 4
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
    // 00460052  0f8719010000           -ja 0x460171
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00460171;
    }
    // 00460058  ff249530004600         -jmp dword ptr [edx*4 + 0x460030]
    cpu.ip = app->getMemory<x86::reg32>(4587568 + cpu.edx * 4); goto dynamic_jump;
  case 0x0046005f:
L_0x0046005f:
    // 0046005f  8b2d24f84f00           -mov ebp, dword ptr [0x4ff824]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5240868) /* 0x4ff824 */);
    // 00460065  a1280c5000             -mov eax, dword ptr [0x500c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5245992) /* 0x500c28 */);
    // 0046006a  8b152c0c5000           -mov edx, dword ptr [0x500c2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */);
    // 00460070  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00460072  39d0                   +cmp eax, edx
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
    // 00460074  0f8fef000000           -jg 0x460169
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00460169;
    }
L_0x0046007a:
    // 0046007a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046007f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460080  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460081  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460082  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460083  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460084  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00460085:
    // 00460085  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046008c  755a                   -jne 0x4600e8
    if (!cpu.flags.zf)
    {
        goto L_0x004600e8;
    }
    // 0046008e  833d2cf54d0000         +cmp dword ptr [0x4df52c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460095  7537                   -jne 0x4600ce
    if (!cpu.flags.zf)
    {
        goto L_0x004600ce;
    }
    // 00460097  833dfc8c4c0000         +cmp dword ptr [0x4c8cfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5016828) /* 0x4c8cfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046009e  7404                   -je 0x4600a4
    if (cpu.flags.zf)
    {
        goto L_0x004600a4;
    }
    // 004600a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004600a2  75d6                   -jne 0x46007a
    if (!cpu.flags.zf)
    {
        goto L_0x0046007a;
    }
L_0x004600a4:
    // 004600a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004600a6  750f                   -jne 0x4600b7
    if (!cpu.flags.zf)
    {
        goto L_0x004600b7;
    }
    // 004600a8  8b1d20f84f00           -mov ebx, dword ptr [0x4ff820]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5240864) /* 0x4ff820 */);
    // 004600ae  a04c0c5000             -mov al, byte ptr [0x500c4c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5246028) /* 0x500c4c */);
    // 004600b3  39d8                   +cmp eax, ebx
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
    // 004600b5  7f1f                   -jg 0x4600d6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004600d6;
    }
L_0x004600b7:
    // 004600b7  8b3524f84f00           -mov esi, dword ptr [0x4ff824]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240868) /* 0x4ff824 */);
    // 004600bd  a1280c5000             -mov eax, dword ptr [0x500c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5245992) /* 0x500c28 */);
    // 004600c2  8b3d2c0c5000           -mov edi, dword ptr [0x500c2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */);
    // 004600c8  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004600ca  39f8                   +cmp eax, edi
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
    // 004600cc  7eac                   -jle 0x46007a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046007a;
    }
L_0x004600ce:
    // 004600ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004600d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004600d6:
    // 004600d6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004600d8  a24c0c5000             -mov byte ptr [0x500c4c], al
    app->getMemory<x86::reg8>(x86::reg32(5246028) /* 0x500c4c */) = cpu.al;
    // 004600dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004600e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004600e8:
    // 004600e8  8b1d2cf54d00           -mov ebx, dword ptr [0x4df52c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 004600ee  39d8                   +cmp eax, ebx
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
    // 004600f0  75dc                   -jne 0x4600ce
    if (!cpu.flags.zf)
    {
        goto L_0x004600ce;
    }
    // 004600f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004600f4  8a154c0c5000           -mov dl, byte ptr [0x500c4c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5246028) /* 0x500c4c */);
    // 004600fa  83fa08                 +cmp edx, 8
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
    // 004600fd  7f4f                   -jg 0x46014e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046014e;
    }
    // 004600ff  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 00460106  a1280c5000             -mov eax, dword ptr [0x500c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5245992) /* 0x500c28 */);
    // 0046010b  8b3520f84f00           -mov esi, dword ptr [0x4ff820]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240864) /* 0x4ff820 */);
    // 00460111  8bba2c0c5000           -mov edi, dword ptr [edx + 0x500c2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5245996) /* 0x500c2c */);
    // 00460117  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00460119  39f8                   +cmp eax, edi
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
    // 0046011b  0f8e59ffffff           -jle 0x46007a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046007a;
    }
    // 00460121  a1300c5000             -mov eax, dword ptr [0x500c30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5246000) /* 0x500c30 */);
    // 00460126  8b152c0c5000           -mov edx, dword ptr [0x500c2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */);
    // 0046012c  39c2                   +cmp edx, eax
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
    // 0046012e  7e02                   -jle 0x460132
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460132;
    }
    // 00460130  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00460132:
    // 00460132  8b2d24f84f00           -mov ebp, dword ptr [0x4ff824]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5240868) /* 0x4ff824 */);
    // 00460138  a1280c5000             -mov eax, dword ptr [0x500c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5245992) /* 0x500c28 */);
    // 0046013d  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046013f  39c2                   +cmp edx, eax
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
    // 00460141  7c8b                   -jl 0x4600ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004600ce;
    }
    // 00460143  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00460148  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460149  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046014a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046014b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046014c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046014d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046014e:
    // 0046014e  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00460150  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00460155  88354c0c5000           -mov byte ptr [0x500c4c], dh
    app->getMemory<x86::reg8>(x86::reg32(5246028) /* 0x500c4c */) = cpu.dh;
    // 0046015b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046015c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046015d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046015e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046015f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460160  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00460161:
    // 00460161  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460163  0f84f6feffff           -je 0x46005f
    if (cpu.flags.zf)
    {
        goto L_0x0046005f;
    }
L_0x00460169:
    // 00460169  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046016b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046016c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046016d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046016e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046016f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460170  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460171:
    // 00460171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460172  bac8d44b00             -mov edx, 0x4bd4c8
    cpu.edx = 4969672 /*0x4bd4c8*/;
    // 00460177  b9ae030000             -mov ecx, 0x3ae
    cpu.ecx = 942 /*0x3ae*/;
    // 0046017c  68ecd44b00             -push 0x4bd4ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4969708 /*0x4bd4ec*/;
    cpu.esp -= 4;
    // 00460181  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00460187  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046018d  e8ee9c0100             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00460192  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460195  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00460197  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460198  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460199  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046019a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046019b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046019c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046019d  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_4601b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004601b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004601b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004601b6  8b1524f84f00           -mov edx, dword ptr [0x4ff824]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240868) /* 0x4ff824 */);
    // 004601bc  8b0d20f84f00           -mov ecx, dword ptr [0x4ff820]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5240864) /* 0x4ff820 */);
    // 004601c2  a128f54d00             -mov eax, dword ptr [0x4df528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 004601c7  83f804                 +cmp eax, 4
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
    // 004601ca  770c                   -ja 0x4601d8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004601d8;
    }
    // 004601cc  ff2485a0014600         -jmp dword ptr [eax*4 + 0x4601a0]
    cpu.ip = app->getMemory<x86::reg32>(4587936 + cpu.eax * 4); goto dynamic_jump;
  case 0x004601d3:
    // 004601d3  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x004601d8:
    // 004601d8  890d20f84f00           -mov dword ptr [0x4ff820], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240864) /* 0x4ff820 */) = cpu.ecx;
    // 004601de  891524f84f00           -mov dword ptr [0x4ff824], edx
    app->getMemory<x86::reg32>(x86::reg32(5240868) /* 0x4ff824 */) = cpu.edx;
    // 004601e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004601e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004601e6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004601e7:
    // 004601e7  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004601ee  7526                   -jne 0x460216
    if (!cpu.flags.zf)
    {
        goto L_0x00460216;
    }
    // 004601f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004601f1  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004601f6  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004601fb  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00460200  891d1cf84f00           -mov dword ptr [0x4ff81c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5240860) /* 0x4ff81c */) = cpu.ebx;
    // 00460206  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460207  890d20f84f00           -mov dword ptr [0x4ff820], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240864) /* 0x4ff820 */) = cpu.ecx;
    // 0046020d  891524f84f00           -mov dword ptr [0x4ff824], edx
    app->getMemory<x86::reg32>(x86::reg32(5240868) /* 0x4ff824 */) = cpu.edx;
    // 00460213  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460214  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460215  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460216:
    // 00460216  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0046021b  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00460220  89151cf84f00           -mov dword ptr [0x4ff81c], edx
    app->getMemory<x86::reg32>(x86::reg32(5240860) /* 0x4ff81c */) = cpu.edx;
    // 00460226  890d20f84f00           -mov dword ptr [0x4ff820], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240864) /* 0x4ff820 */) = cpu.ecx;
    // 0046022c  891524f84f00           -mov dword ptr [0x4ff824], edx
    app->getMemory<x86::reg32>(x86::reg32(5240868) /* 0x4ff824 */) = cpu.edx;
    // 00460232  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460233  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460234  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00460235:
    // 00460235  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 0046023a  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0046023f  890d20f84f00           -mov dword ptr [0x4ff820], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240864) /* 0x4ff820 */) = cpu.ecx;
    // 00460245  891524f84f00           -mov dword ptr [0x4ff824], edx
    app->getMemory<x86::reg32>(x86::reg32(5240868) /* 0x4ff824 */) = cpu.edx;
    // 0046024b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046024c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046024d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046024e:
    // 0046024e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00460253  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00460255  890d20f84f00           -mov dword ptr [0x4ff820], ecx
    app->getMemory<x86::reg32>(x86::reg32(5240864) /* 0x4ff820 */) = cpu.ecx;
    // 0046025b  891524f84f00           -mov dword ptr [0x4ff824], edx
    app->getMemory<x86::reg32>(x86::reg32(5240868) /* 0x4ff824 */) = cpu.edx;
    // 00460261  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460262  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460263  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460270  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460271  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00460273  8a154c0c5000           -mov dl, byte ptr [0x500c4c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5246028) /* 0x500c4c */);
    // 00460279  39d0                   +cmp eax, edx
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
    // 0046027b  7e07                   -jle 0x460284
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460284;
    }
    // 0046027d  a24c0c5000             -mov byte ptr [0x500c4c], al
    app->getMemory<x86::reg8>(x86::reg32(5246028) /* 0x500c4c */) = cpu.al;
    // 00460282  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460283  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460284:
    // 00460284  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460286  a24c0c5000             -mov byte ptr [0x500c4c], al
    app->getMemory<x86::reg8>(x86::reg32(5246028) /* 0x500c4c */) = cpu.al;
    // 0046028b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046028c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_460290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460290  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460291  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00460298  7424                   -je 0x4602be
    if (cpu.flags.zf)
    {
        goto L_0x004602be;
    }
    // 0046029a  833d2cf54d0000         +cmp dword ptr [0x4df52c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004602a1  752c                   -jne 0x4602cf
    if (!cpu.flags.zf)
    {
        goto L_0x004602cf;
    }
    // 004602a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004602a8:
    // 004602a8  8b152cf54d00           -mov edx, dword ptr [0x4df52c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 004602ae  8a04852c0c5000         -mov al, byte ptr [eax*4 + 0x500c2c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5245996) /* 0x500c2c */ + cpu.eax * 4);
    // 004602b5  2a04952c0c5000         -sub al, byte ptr [edx*4 + 0x500c2c]
    (cpu.al) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5245996) /* 0x500c2c */ + cpu.edx * 4)));
    // 004602bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004602bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004602be:
    // 004602be  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004602bf  8a3d280c5000           -mov bh, byte ptr [0x500c28]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(5245992) /* 0x500c28 */);
    // 004602c5  a02c0c5000             -mov al, byte ptr [0x500c2c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5245996) /* 0x500c2c */);
    // 004602ca  28f8                   -sub al, bh
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.bh));
    // 004602cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004602cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004602ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004602cf:
    // 004602cf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004602d1  ebd5                   -jmp 0x4602a8
    goto L_0x004602a8;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4602e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004602e0  a1280c5000             -mov eax, dword ptr [0x500c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5245992) /* 0x500c28 */);
    // 004602e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4602f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004602f0  a12c0c5000             -mov eax, dword ptr [0x500c2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */);
    // 004602f5  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004602f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
