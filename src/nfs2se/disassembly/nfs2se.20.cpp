#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4813aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004813aa  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004813ad  e966c90100             -jmp 0x49dd18
    return sub_49dd18(app, cpu);
}

/* align: skip  */
void Application::sub_4813b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004813b2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004813b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004813b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004813b5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004813b8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004813ba  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004813bd  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004813c3  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004813c6  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004813c9  83fe01                 +cmp esi, 1
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
    // 004813cc  7418                   -je 0x4813e6
    if (cpu.flags.zf)
    {
        goto L_0x004813e6;
    }
    // 004813ce  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004813d0  740d                   -je 0x4813df
    if (cpu.flags.zf)
    {
        goto L_0x004813df;
    }
    // 004813d2  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004813d5  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004813db  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004813dd  eb30                   -jmp 0x48140f
    goto L_0x0048140f;
L_0x004813df:
    // 004813df  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004813e6:
    // 004813e6  bd8e134800             -mov ebp, 0x48138e
    cpu.ebp = 4723598 /*0x48138e*/;
    // 004813eb  b8aa134800             -mov eax, 0x4813aa
    cpu.eax = 4723626 /*0x4813aa*/;
    // 004813f0  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004813f4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004813f8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004813fa  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004813fd  e8dfc90100             -call 0x49dde1
    cpu.esp -= 4;
    sub_49dde1(app, cpu);
    if (cpu.terminate) return;
    // 00481402  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481404  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00481407  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048140d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0048140f:
    // 0048140f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481412  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481413  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481414  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481415  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481416(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481416  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481417  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481418  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048141b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048141f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00481421  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00481425  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00481428  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048142c  e881ffffff             -call 0x4813b2
    cpu.esp -= 4;
    sub_4813b2(app, cpu);
    if (cpu.terminate) return;
    // 00481431  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481434  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481435  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481436  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481437(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481437  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481438  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481439  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048143b  ff159ce34c00           -call dword ptr [0x4ce39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039004) /* 0x4ce39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481441  a1c44f5400             -mov eax, dword ptr [0x544fc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */);
L_0x00481446:
    // 00481446  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481448  750e                   -jne 0x481458
    if (!cpu.flags.zf)
    {
        goto L_0x00481458;
    }
    // 0048144a  ff15a0e34c00           -call dword ptr [0x4ce3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039008) /* 0x4ce3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481450  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00481455  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481456  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481457  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481458:
    // 00481458  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 0048145b  7404                   -je 0x481461
    if (cpu.flags.zf)
    {
        goto L_0x00481461;
    }
    // 0048145d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048145f  ebe5                   -jmp 0x481446
    goto L_0x00481446;
L_0x00481461:
    // 00481461  ff15a0e34c00           -call dword ptr [0x4ce3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039008) /* 0x4ce3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481467  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048146c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048146e  e803000000             -call 0x481476
    cpu.esp -= 4;
    sub_481476(app, cpu);
    if (cpu.terminate) return;
    // 00481473  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481474  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481475  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481476(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481476  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481477  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481479  e8c3000000             -call 0x481541
    cpu.esp -= 4;
    sub_481541(app, cpu);
    if (cpu.terminate) return;
    // 0048147e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481480  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481482  e821c20100             -call 0x49d6a8
    cpu.esp -= 4;
    sub_49d6a8(app, cpu);
    if (cpu.terminate) return;
    // 00481487  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481489  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048148a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48148b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048148b  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048148e  83f839                 +cmp eax, 0x39
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
    // 00481491  7e03                   -jle 0x481496
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481496;
    }
    // 00481493  83c027                 -add eax, 0x27
    (cpu.eax) += x86::reg32(x86::sreg32(39 /*0x27*/));
L_0x00481496:
    // 00481496  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481497(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481497  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481498  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481499  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048149a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048149b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048149c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048149f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004814a1  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004814a4  e8ced70100             -call 0x49ec77
    cpu.esp -= 4;
    sub_49ec77(app, cpu);
    if (cpu.terminate) return;
    // 004814a9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004814ab  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004814ae  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004814b0  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004814b2  e8c1d80100             -call 0x49ed78
    cpu.esp -= 4;
    sub_49ed78(app, cpu);
    if (cpu.terminate) return;
    // 004814b7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004814b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004814ba:
    // 004814ba  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004814bc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004814be  3c00                   +cmp al, 0
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
    // 004814c0  7410                   -je 0x4814d2
    if (cpu.flags.zf)
    {
        goto L_0x004814d2;
    }
    // 004814c2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004814c5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004814c8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004814cb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004814ce  3c00                   +cmp al, 0
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
    // 004814d0  75e8                   -jne 0x4814ba
    if (!cpu.flags.zf)
    {
        goto L_0x004814ba;
    }
L_0x004814d2:
    // 004814d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814d3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004814d4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004814d6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004814d8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004814da  49                     -dec ecx
    (cpu.ecx)--;
    // 004814db  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004814dd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004814df  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004814e1  49                     -dec ecx
    (cpu.ecx)--;
    // 004814e2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004814e3  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004814e5  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004814e8  c60174                 -mov byte ptr [ecx], 0x74
    app->getMemory<x86::reg8>(cpu.ecx) = 116 /*0x74*/;
    // 004814eb  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x004814ed:
    // 004814ed  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004814ef  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004814f2  e894ffffff             -call 0x48148b
    cpu.esp -= 4;
    sub_48148b(app, cpu);
    if (cpu.terminate) return;
    // 004814f7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004814f9  4a                     -dec edx
    (cpu.edx)--;
    // 004814fa  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 004814fd  39f2                   +cmp edx, esi
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
    // 004814ff  75ec                   -jne 0x4814ed
    if (!cpu.flags.zf)
    {
        goto L_0x004814ed;
    }
    // 00481501  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00481504  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00481507  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048150a  c641055f               -mov byte ptr [ecx + 5], 0x5f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 0048150e  e878ffffff             -call 0x48148b
    cpu.esp -= 4;
    sub_48148b(app, cpu);
    if (cpu.terminate) return;
    // 00481513  884106                 -mov byte ptr [ecx + 6], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00481516  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00481519  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048151c  e86affffff             -call 0x48148b
    cpu.esp -= 4;
    sub_48148b(app, cpu);
    if (cpu.terminate) return;
    // 00481521  c641082e               -mov byte ptr [ecx + 8], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 00481525  c6410974               -mov byte ptr [ecx + 9], 0x74
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 00481529  c6410a6d               -mov byte ptr [ecx + 0xa], 0x6d
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 0048152d  c6410b70               -mov byte ptr [ecx + 0xb], 0x70
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 00481531  c6410c00               -mov byte ptr [ecx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00481535  884107                 -mov byte ptr [ecx + 7], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00481538  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048153b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048153c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048153d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048153e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048153f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481540  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48153b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0048153b;
    // 00481497  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481498  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481499  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048149a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048149b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048149c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048149f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004814a1  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004814a4  e8ced70100             -call 0x49ec77
    cpu.esp -= 4;
    sub_49ec77(app, cpu);
    if (cpu.terminate) return;
    // 004814a9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004814ab  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004814ae  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004814b0  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004814b2  e8c1d80100             -call 0x49ed78
    cpu.esp -= 4;
    sub_49ed78(app, cpu);
    if (cpu.terminate) return;
    // 004814b7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004814b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004814ba:
    // 004814ba  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004814bc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004814be  3c00                   +cmp al, 0
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
    // 004814c0  7410                   -je 0x4814d2
    if (cpu.flags.zf)
    {
        goto L_0x004814d2;
    }
    // 004814c2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004814c5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004814c8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004814cb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004814ce  3c00                   +cmp al, 0
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
    // 004814d0  75e8                   -jne 0x4814ba
    if (!cpu.flags.zf)
    {
        goto L_0x004814ba;
    }
L_0x004814d2:
    // 004814d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814d3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004814d4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004814d6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004814d8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004814da  49                     -dec ecx
    (cpu.ecx)--;
    // 004814db  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004814dd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004814df  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004814e1  49                     -dec ecx
    (cpu.ecx)--;
    // 004814e2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004814e3  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004814e5  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004814e8  c60174                 -mov byte ptr [ecx], 0x74
    app->getMemory<x86::reg8>(cpu.ecx) = 116 /*0x74*/;
    // 004814eb  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x004814ed:
    // 004814ed  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004814ef  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004814f2  e894ffffff             -call 0x48148b
    cpu.esp -= 4;
    sub_48148b(app, cpu);
    if (cpu.terminate) return;
    // 004814f7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004814f9  4a                     -dec edx
    (cpu.edx)--;
    // 004814fa  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 004814fd  39f2                   +cmp edx, esi
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
    // 004814ff  75ec                   -jne 0x4814ed
    if (!cpu.flags.zf)
    {
        goto L_0x004814ed;
    }
    // 00481501  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00481504  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00481507  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048150a  c641055f               -mov byte ptr [ecx + 5], 0x5f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 0048150e  e878ffffff             -call 0x48148b
    cpu.esp -= 4;
    sub_48148b(app, cpu);
    if (cpu.terminate) return;
    // 00481513  884106                 -mov byte ptr [ecx + 6], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00481516  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00481519  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048151c  e86affffff             -call 0x48148b
    cpu.esp -= 4;
    sub_48148b(app, cpu);
    if (cpu.terminate) return;
    // 00481521  c641082e               -mov byte ptr [ecx + 8], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 00481525  c6410974               -mov byte ptr [ecx + 9], 0x74
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 00481529  c6410a6d               -mov byte ptr [ecx + 0xa], 0x6d
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 0048152d  c6410b70               -mov byte ptr [ecx + 0xb], 0x70
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 00481531  c6410c00               -mov byte ptr [ecx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00481535  884107                 -mov byte ptr [ecx + 7], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00481538  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_entry_0x0048153b:
    // 0048153b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048153c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048153d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048153e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048153f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481540  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481541(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481541  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481542  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481543  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481544  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481545  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481546  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 0048154c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048154e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00481550  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 00481554  750a                   -jne 0x481560
    if (!cpu.flags.zf)
    {
        goto L_0x00481560;
    }
    // 00481556  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048155b  e993000000             -jmp 0x4815f3
    goto L_0x004815f3;
L_0x00481560:
    // 00481560  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00481563  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00481565  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00481568  7409                   -je 0x481573
    if (cpu.flags.zf)
    {
        goto L_0x00481573;
    }
    // 0048156a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048156c  e8cfd80100             -call 0x49ee40
    cpu.esp -= 4;
    sub_49ee40(app, cpu);
    if (cpu.terminate) return;
    // 00481571  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00481573:
    // 00481573  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00481576  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048157c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048157e  e8ccd90100             -call 0x49ef4f
    cpu.esp -= 4;
    sub_49ef4f(app, cpu);
    if (cpu.terminate) return;
    // 00481583  83f8ff                 +cmp eax, -1
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
    // 00481586  740e                   -je 0x481596
    if (cpu.flags.zf)
    {
        goto L_0x00481596;
    }
    // 00481588  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048158a  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048158d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048158f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00481591  e812da0100             -call 0x49efa8
    cpu.esp -= 4;
    sub_49efa8(app, cpu);
    if (cpu.terminate) return;
L_0x00481596:
    // 00481596  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00481598  740a                   -je 0x4815a4
    if (cpu.flags.zf)
    {
        goto L_0x004815a4;
    }
    // 0048159a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048159d  e87ada0100             -call 0x49f01c
    cpu.esp -= 4;
    sub_49f01c(app, cpu);
    if (cpu.terminate) return;
    // 004815a2  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x004815a4:
    // 004815a4  f6410c08               +test byte ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 004815a8  7415                   -je 0x4815bf
    if (cpu.flags.zf)
    {
        goto L_0x004815bf;
    }
    // 004815aa  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004815ad  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004815b0  e8f4da0100             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004815b5  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004815b8  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x004815bf:
    // 004815bf  f6410d08               +test byte ptr [ecx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004815c3  7416                   -je 0x4815db
    if (cpu.flags.zf)
    {
        goto L_0x004815db;
    }
    // 004815c5  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004815c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004815ca  8a5014                 -mov dl, byte ptr [eax + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004815cd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004815cf  e8c3feffff             -call 0x481497
    cpu.esp -= 4;
    sub_481497(app, cpu);
    if (cpu.terminate) return;
    // 004815d4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004815d6  e8d2db0100             -call 0x49f1ad
    cpu.esp -= 4;
    sub_49f1ad(app, cpu);
    if (cpu.terminate) return;
L_0x004815db:
    // 004815db  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004815de  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004815e4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004815e6  7409                   -je 0x4815f1
    if (cpu.flags.zf)
    {
        goto L_0x004815f1;
    }
    // 004815e8  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004815eb  ff1598e34c00           -call dword ptr [0x4ce398]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039000) /* 0x4ce398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004815f1:
    // 004815f1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004815f3:
    // 004815f3  81c414010000           +add esp, 0x114
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
    // 004815f9  e93dffffff             -jmp 0x48153b
    return sub_48153b(app, cpu);
}

/* align: skip 0x00 0x00 */
void Application::sub_481600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481600  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481601  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00481603  39c2                   +cmp edx, eax
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
    // 00481605  771d                   -ja 0x481624
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00481624;
    }
L_0x00481607:
    // 00481607  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048160e  752f                   -jne 0x48163f
    if (!cpu.flags.zf)
    {
        goto L_0x0048163f;
    }
    // 00481610  833df8a34c0000         +cmp dword ptr [0x4ca3f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022712) /* 0x4ca3f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481617  7433                   -je 0x48164c
    if (cpu.flags.zf)
    {
        goto L_0x0048164c;
    }
    // 00481619  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048161b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048161d  e8afdb0100             -call 0x49f1d1
    cpu.esp -= 4;
    sub_49f1d1(app, cpu);
    if (cpu.terminate) return;
L_0x00481622:
    // 00481622  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481623  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481624:
    // 00481624  8d1418                 -lea edx, [eax + ebx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00481627  39d1                   +cmp ecx, edx
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
    // 00481629  73dc                   -jae 0x481607
    if (!cpu.flags.cf)
    {
        goto L_0x00481607;
    }
    // 0048162b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048162d  8d1419                 -lea edx, [ecx + ebx]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebx * 1);
L_0x00481630:
    // 00481630  4b                     -dec ebx
    (cpu.ebx)--;
    // 00481631  83fbff                 +cmp ebx, -1
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
    // 00481634  74ec                   -je 0x481622
    if (cpu.flags.zf)
    {
        goto L_0x00481622;
    }
    // 00481636  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481637  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0048163a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048163b  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 0048163d  ebf1                   -jmp 0x481630
    goto L_0x00481630;
L_0x0048163f:
    // 0048163f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481641  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481643  e865dc0100             -call 0x49f2ad
    cpu.esp -= 4;
    sub_49f2ad(app, cpu);
    if (cpu.terminate) return;
    // 00481648  0f77                   -emms 
    cpu.mmx.init();
    // 0048164a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048164b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048164c:
    // 0048164c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048164e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481650  e890600100             -call 0x4976e5
    cpu.esp -= 4;
    sub_4976e5(app, cpu);
    if (cpu.terminate) return;
    // 00481655  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481656  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481660  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481662  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481663  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481664  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481667  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481669  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0048166e  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 00481673  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 00481678  6689542404             -mov word ptr [esp + 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0048167d  e800570300             -call 0x4b6d82
    cpu.esp -= 4;
    sub_4b6d82(app, cpu);
    if (cpu.terminate) return;
    // 00481682  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00481687  668944240c             -mov word ptr [esp + 0xc], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 0048168c  8d442402               -lea eax, [esp + 2]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00481690  e811f6ffff             -call 0x480ca6
    cpu.esp -= 4;
    sub_480ca6(app, cpu);
    if (cpu.terminate) return;
    // 00481695  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0048169a  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0048169f  8d442406               -lea eax, [esp + 6]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004816a3  e8fef5ffff             -call 0x480ca6
    cpu.esp -= 4;
    sub_480ca6(app, cpu);
    if (cpu.terminate) return;
    // 004816a8  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004816ad  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004816b2  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004816b6  e819160000             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 004816bb  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004816c0  babe080000             -mov edx, 0x8be
    cpu.edx = 2238 /*0x8be*/;
    // 004816c5  8d442412               -lea eax, [esp + 0x12]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(18) /* 0x12 */);
    // 004816c9  e806160000             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 004816ce  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 004816d3  e8f0f4ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004816d8  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004816da  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004816de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004816df  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004816e1  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004816e3  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004816e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004816e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004816e9  e882560300             -call 0x4b6d70
    cpu.esp -= 4;
    sub_4b6d70(app, cpu);
    if (cpu.terminate) return;
    // 004816ee  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004816f0  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 004816f5  e8e6f4ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004816fa  83feff                 +cmp esi, -1
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
    // 004816fd  740d                   -je 0x48170c
    if (cpu.flags.zf)
    {
        goto L_0x0048170c;
    }
    // 004816ff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481704  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481707  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481708  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481709  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048170a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048170b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048170c:
    // 0048170c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048170e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481711  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481712  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481713  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481714  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481715  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481718  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481719  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048171a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048171b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048171e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00481721  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00481723  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00481725  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 0048172a  668b720c               -mov si, word ptr [edx + 0xc]
    cpu.si = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048172e  e84f560300             -call 0x4b6d82
    cpu.esp -= 4;
    sub_4b6d82(app, cpu);
    if (cpu.terminate) return;
    // 00481733  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00481738  39c6                   +cmp esi, eax
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
    // 0048173a  7409                   -je 0x481745
    if (cpu.flags.zf)
    {
        goto L_0x00481745;
    }
L_0x0048173c:
    // 0048173c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048173e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00481741  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481742  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481743  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481744  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481745:
    // 00481745  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048174a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048174c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048174e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00481750  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00481752  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00481759  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048175b  83f802                 +cmp eax, 2
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
    // 0048175e  75dc                   -jne 0x48173c
    if (!cpu.flags.zf)
    {
        goto L_0x0048173c;
    }
    // 00481760  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00481762  c1ef06                 -shr edi, 6
    cpu.edi >>= 6 /*0x6*/ % 32;
    // 00481765  8d3403                 -lea esi, [ebx + eax]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00481768  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0048176c  8d7e32                 -lea edi, [esi + 0x32]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(50) /* 0x32 */);
    // 0048176f  8d2c06                 -lea ebp, [esi + eax]
    cpu.ebp = x86::reg32(cpu.esi + cpu.eax * 1);
L_0x00481772:
    // 00481772  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481776  4a                     -dec edx
    (cpu.edx)--;
    // 00481777  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048177b  83faff                 +cmp edx, -1
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
    // 0048177e  750c                   -jne 0x48178c
    if (!cpu.flags.zf)
    {
        goto L_0x0048178c;
    }
    // 00481780  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481785  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00481788  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481789  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048178a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048178b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048178c:
    // 0048178c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00481791  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481793  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00481795  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00481797  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00481799  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004817a0  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004817a2  3dbe080000             +cmp eax, 0x8be
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
    // 004817a7  740b                   -je 0x4817b4
    if (cpu.flags.zf)
    {
        goto L_0x004817b4;
    }
    // 004817a9  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004817ac  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004817af  83c640                 +add esi, 0x40
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
    // 004817b2  ebbe                   -jmp 0x481772
    goto L_0x00481772;
L_0x004817b4:
    // 004817b4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004817b7  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004817b9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004817bb  e820c8f9ff             -call 0x41dfe0
    cpu.esp -= 4;
    sub_41dfe0(app, cpu);
    if (cpu.terminate) return;
    // 004817c0  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004817c3  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004817c6  83c640                 +add esi, 0x40
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
    // 004817c9  eba7                   -jmp 0x481772
    goto L_0x00481772;
}

/* align: skip 0x90 */
void Application::sub_4817cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004817cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004817cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004817ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004817d0  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 004817d5  e8eef3ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004817da  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004817dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004817dd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004817df  6a42                   -push 0x42
    app->getMemory<x86::reg32>(cpu.esp-4) = 66 /*0x42*/;
    cpu.esp -= 4;
    // 004817e1  6852dd5100             -push 0x51dd52
    app->getMemory<x86::reg32>(cpu.esp-4) = 5365074 /*0x51dd52*/;
    cpu.esp -= 4;
    // 004817e6  8b153cdd5100           -mov edx, dword ptr [0x51dd3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365052) /* 0x51dd3c */);
    // 004817ec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004817ed  e87e550300             -call 0x4b6d70
    cpu.esp -= 4;
    sub_4b6d70(app, cpu);
    if (cpu.terminate) return;
    // 004817f2  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 004817f7  e8e4f3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004817fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481802  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481804  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00481809  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048180b  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048180d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048180f  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00481816  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00481818  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048181d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048181f  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00481822  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00481824  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00481826  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00481828  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048182f  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00481831  83fa01                 +cmp edx, 1
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
    // 00481834  7516                   -jne 0x48184c
    if (!cpu.flags.zf)
    {
        goto L_0x0048184c;
    }
    // 00481836  3dbe080000             +cmp eax, 0x8be
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
    // 0048183b  7407                   -je 0x481844
    if (cpu.flags.zf)
    {
        goto L_0x00481844;
    }
    // 0048183d  3dffff0000             +cmp eax, 0xffff
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
    // 00481842  7508                   -jne 0x48184c
    if (!cpu.flags.zf)
    {
        goto L_0x0048184c;
    }
L_0x00481844:
    // 00481844  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481849  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048184a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048184b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048184c:
    // 0048184c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048184e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048184f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481850  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481854(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481854  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481855  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481856  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481857  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481858  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481859  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048185c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048185e  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 00481863  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481865  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00481867  e834550300             -call 0x4b6da0
    cpu.esp -= 4;
    sub_4b6da0(app, cpu);
    if (cpu.terminate) return;
    // 0048186c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048186e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00481870  83f8ff                 +cmp eax, -1
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
    // 00481873  7510                   -jne 0x481885
    if (!cpu.flags.zf)
    {
        goto L_0x00481885;
    }
    // 00481875  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x0048187a:
    // 0048187a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048187c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048187f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481880  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481881  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481882  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481883  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481884  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481885:
    // 00481885  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00481887  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048188b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048188c  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0048188e  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 00481893  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00481898  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481899  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048189d  e8ec540300             -call 0x4b6d8e
    cpu.esp -= 4;
    sub_4b6d8e(app, cpu);
    if (cpu.terminate) return;
    // 004818a2  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004818a4  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004818a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004818a9  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 004818ae  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 004818b3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004818b4  e8d5540300             -call 0x4b6d8e
    cpu.esp -= 4;
    sub_4b6d8e(app, cpu);
    if (cpu.terminate) return;
    // 004818b9  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 004818be  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004818c0  e8d7f3ffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 004818c5  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 004818ca  66c7060600             -mov word ptr [esi], 6
    app->getMemory<x86::reg16>(cpu.esi) = 6 /*0x6*/;
    // 004818cf  e8ae540300             -call 0x4b6d82
    cpu.esp -= 4;
    sub_4b6d82(app, cpu);
    if (cpu.terminate) return;
    // 004818d4  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004818d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004818d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004818d8  6689460c               -mov word ptr [esi + 0xc], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004818dc  e89b540300             -call 0x4b6d7c
    cpu.esp -= 4;
    sub_4b6d7c(app, cpu);
    if (cpu.terminate) return;
    // 004818e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004818e3  7524                   -jne 0x481909
    if (!cpu.flags.zf)
    {
        goto L_0x00481909;
    }
    // 004818e5  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004818e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004818ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004818eb  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004818f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004818f1  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004818f5  e87c540300             -call 0x4b6d76
    cpu.esp -= 4;
    sub_4b6d76(app, cpu);
    if (cpu.terminate) return;
    // 004818fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004818fc  750b                   -jne 0x481909
    if (!cpu.flags.zf)
    {
        goto L_0x00481909;
    }
    // 004818fe  837c24040e             +cmp dword ptr [esp + 4], 0xe
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
    // 00481903  0f8471ffffff           -je 0x48187a
    if (cpu.flags.zf)
    {
        goto L_0x0048187a;
    }
L_0x00481909:
    // 00481909  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048190a  e88b540300             -call 0x4b6d9a
    cpu.esp -= 4;
    sub_4b6d9a(app, cpu);
    if (cpu.terminate) return;
    // 0048190f  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00481914  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481916  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00481919  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048191a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048191b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048191c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048191d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048191e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481921  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481922  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481923  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481924  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481925  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481926  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 0048192c  e8af5e0100             -call 0x4977e0
    cpu.esp -= 4;
    sub_4977e0(app, cpu);
    if (cpu.terminate) return;
    // 00481931  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 00481936  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 0048193b  8d5804                 -lea ebx, [eax + 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048193e  6689942418030000       -mov word ptr [esp + 0x318], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.dx;
    // 00481946  e837540300             -call 0x4b6d82
    cpu.esp -= 4;
    sub_4b6d82(app, cpu);
    if (cpu.terminate) return;
    // 0048194b  8d942414030000         -lea edx, [esp + 0x314]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 00481952  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00481953  e8c8c7f9ff             -call 0x41e120
    cpu.esp -= 4;
    sub_41e120(app, cpu);
    if (cpu.terminate) return;
    // 00481958  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048195d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048195f  891538dd5100           -mov dword ptr [0x51dd38], edx
    app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */) = cpu.edx;
    // 00481965  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 0048196a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048196c:
    // 0048196c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00481971  a13cdd5100             -mov eax, dword ptr [0x51dd3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365052) /* 0x51dd3c */);
    // 00481976  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00481978  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 0048197f  89842404020000         -mov dword ptr [esp + 0x204], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.eax;
    // 00481986  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00481989  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 0048198e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481990  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00481992  89842424030000         -mov dword ptr [esp + 0x324], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.eax;
    // 00481999  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048199b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048199d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004819a0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004819a2  69c2e8030000           -imul eax, edx, 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 004819a8  89842428030000         -mov dword ptr [esp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 004819af  8d842424030000         -lea eax, [esp + 0x324]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 004819b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004819b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004819b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004819b9  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004819c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004819c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004819c2  e897530300             -call 0x4b6d5e
    cpu.esp -= 4;
    sub_4b6d5e(app, cpu);
    if (cpu.terminate) return;
    // 004819c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004819c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004819cb  0f84bc000000           -je 0x481a8d
    if (cpu.flags.zf)
    {
        goto L_0x00481a8d;
    }
    // 004819d1  83f8ff                 +cmp eax, -1
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
    // 004819d4  0f84b3000000           -je 0x481a8d
    if (cpu.flags.zf)
    {
        goto L_0x00481a8d;
    }
    // 004819da  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 004819df  89ac242c030000         -mov dword ptr [esp + 0x32c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = cpu.ebp;
    // 004819e6  e8ddf1ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004819eb  8d84242c030000         -lea eax, [esp + 0x32c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(812) /* 0x32c */);
    // 004819f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004819f3  8d842408030000         -lea eax, [esp + 0x308]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 004819fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004819fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004819fc  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00481a01  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00481a05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481a06  a13cdd5100             -mov eax, dword ptr [0x51dd3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365052) /* 0x51dd3c */);
    // 00481a0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481a0c  e8a1530300             -call 0x4b6db2
    cpu.esp -= 4;
    sub_4b6db2(app, cpu);
    if (cpu.terminate) return;
    // 00481a11  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481a13  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00481a18  e8c3f1ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00481a1d  83fa04                 +cmp edx, 4
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
    // 00481a20  7517                   -jne 0x481a39
    if (!cpu.flags.zf)
    {
        goto L_0x00481a39;
    }
    // 00481a22  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481a24  e8d7fdffff             -call 0x481800
    cpu.esp -= 4;
    sub_481800(app, cpu);
    if (cpu.terminate) return;
    // 00481a29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481a2b  740c                   -je 0x481a39
    if (cpu.flags.zf)
    {
        goto L_0x00481a39;
    }
    // 00481a2d  8d842404030000         -lea eax, [esp + 0x304]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 00481a34  e893fdffff             -call 0x4817cc
    cpu.esp -= 4;
    sub_4817cc(app, cpu);
    if (cpu.terminate) return;
L_0x00481a39:
    // 00481a39  3b3d38dd5100           +cmp edi, dword ptr [0x51dd38]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481a3f  7425                   -je 0x481a66
    if (cpu.flags.zf)
    {
        goto L_0x00481a66;
    }
    // 00481a41  e89a5d0100             -call 0x4977e0
    cpu.esp -= 4;
    sub_4977e0(app, cpu);
    if (cpu.terminate) return;
    // 00481a46  39c3                   +cmp ebx, eax
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
    // 00481a48  731c                   -jae 0x481a66
    if (!cpu.flags.cf)
    {
        goto L_0x00481a66;
    }
    // 00481a4a  8d842414030000         -lea eax, [esp + 0x314]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 00481a51  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00481a56  e871fdffff             -call 0x4817cc
    cpu.esp -= 4;
    sub_4817cc(app, cpu);
    if (cpu.terminate) return;
    // 00481a5b  e8805d0100             -call 0x4977e0
    cpu.esp -= 4;
    sub_4977e0(app, cpu);
    if (cpu.terminate) return;
    // 00481a60  8d9860ea0000           -lea ebx, [eax + 0xea60]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(60000) /* 0xea60 */);
L_0x00481a66:
    // 00481a66  3b3d38dd5100           +cmp edi, dword ptr [0x51dd38]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481a6c  0f85fafeffff           -jne 0x48196c
    if (!cpu.flags.zf)
    {
        goto L_0x0048196c;
    }
L_0x00481a72:
    // 00481a72  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00481a74  7526                   -jne 0x481a9c
    if (!cpu.flags.zf)
    {
        goto L_0x00481a9c;
    }
L_0x00481a76:
    // 00481a76  c70534dd510001000000   -mov dword ptr [0x51dd34], 1
    app->getMemory<x86::reg32>(x86::reg32(5365044) /* 0x51dd34 */) = 1 /*0x1*/;
    // 00481a80  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 00481a86  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a89  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481a8d:
    // 00481a8d  83faff                 +cmp edx, -1
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
    // 00481a90  75a7                   -jne 0x481a39
    if (!cpu.flags.zf)
    {
        goto L_0x00481a39;
    }
    // 00481a92  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00481a94  891d38dd5100           -mov dword ptr [0x51dd38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */) = cpu.ebx;
    // 00481a9a  ebd6                   -jmp 0x481a72
    goto L_0x00481a72;
L_0x00481a9c:
    // 00481a9c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00481aa1  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00481aa6  b892dd5100             -mov eax, 0x51dd92
    cpu.eax = 5365138 /*0x51dd92*/;
    // 00481aab  e824120000             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00481ab0  8d842414030000         -lea eax, [esp + 0x314]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 00481ab7  e810fdffff             -call 0x4817cc
    cpu.esp -= 4;
    sub_4817cc(app, cpu);
    if (cpu.terminate) return;
    // 00481abc  ebb8                   -jmp 0x481a76
    goto L_0x00481a76;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481ac0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481ac1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481ac2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481ac3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00481ac5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00481ac7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00481ac9  833d38dd510000         +cmp dword ptr [0x51dd38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481ad0  7409                   -je 0x481adb
    if (cpu.flags.zf)
    {
        goto L_0x00481adb;
    }
L_0x00481ad2:
    // 00481ad2  a138dd5100             -mov eax, dword ptr [0x51dd38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */);
    // 00481ad7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ad8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ad9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ada  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481adb:
    // 00481adb  b844dd5100             -mov eax, 0x51dd44
    cpu.eax = 5365060 /*0x51dd44*/;
    // 00481ae0  e86ffdffff             -call 0x481854
    cpu.esp -= 4;
    sub_481854(app, cpu);
    if (cpu.terminate) return;
    // 00481ae5  a33cdd5100             -mov dword ptr [0x51dd3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5365052) /* 0x51dd3c */) = cpu.eax;
    // 00481aea  83f8ff                 +cmp eax, -1
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
    // 00481aed  74e3                   -je 0x481ad2
    if (cpu.flags.zf)
    {
        goto L_0x00481ad2;
    }
    // 00481aef  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00481af4  b852dd5100             -mov eax, 0x51dd52
    cpu.eax = 5365074 /*0x51dd52*/;
    // 00481af9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00481afb  893d40dd5100           -mov dword ptr [0x51dd40], edi
    app->getMemory<x86::reg32>(x86::reg32(5365056) /* 0x51dd40 */) = cpu.edi;
    // 00481b01  e8ce110000             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00481b06  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00481b0b  babe080000             -mov edx, 0x8be
    cpu.edx = 2238 /*0x8be*/;
    // 00481b10  b854dd5100             -mov eax, 0x51dd54
    cpu.eax = 5365076 /*0x51dd54*/;
    // 00481b15  e8ba110000             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00481b1a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00481b1f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00481b24  b892dd5100             -mov eax, 0x51dd92
    cpu.eax = 5365138 /*0x51dd92*/;
    // 00481b29  e8a6110000             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00481b2e  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 00481b33  b856dd5100             -mov eax, 0x51dd56
    cpu.eax = 5365078 /*0x51dd56*/;
    // 00481b38  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00481b3a  bf86dd5100             -mov edi, 0x51dd86
    cpu.edi = 5365126 /*0x51dd86*/;
    // 00481b3f  e878a4ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00481b44  6820dd5100             -push 0x51dd20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5365024 /*0x51dd20*/;
    cpu.esp -= 4;
    // 00481b49  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00481b4e  b820194800             -mov eax, 0x481920
    cpu.eax = 4725024 /*0x481920*/;
    // 00481b53  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481b55  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00481b56  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00481b57  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00481b58  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481b5a  890d34dd5100           -mov dword ptr [0x51dd34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5365044) /* 0x51dd34 */) = cpu.ecx;
    // 00481b60  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00481b65  e8f6ebffff             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 00481b6a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481b6c  7422                   -je 0x481b90
    if (cpu.flags.zf)
    {
        goto L_0x00481b90;
    }
    // 00481b6e  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00481b73  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00481b75:
    // 00481b75  8b1d38dd5100           -mov ebx, dword ptr [0x51dd38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */);
    // 00481b7b  39d9                   +cmp ecx, ebx
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
    // 00481b7d  7511                   -jne 0x481b90
    if (!cpu.flags.zf)
    {
        goto L_0x00481b90;
    }
    // 00481b7f  3b1d34dd5100           +cmp ebx, dword ptr [0x51dd34]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5365044) /* 0x51dd34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481b85  7509                   -jne 0x481b90
    if (!cpu.flags.zf)
    {
        goto L_0x00481b90;
    }
    // 00481b87  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481b89  e88eecffff             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00481b8e  ebe5                   -jmp 0x481b75
    goto L_0x00481b75;
L_0x00481b90:
    // 00481b90  833d34dd510000         +cmp dword ptr [0x51dd34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365044) /* 0x51dd34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481b97  0f8435ffffff           -je 0x481ad2
    if (cpu.flags.zf)
    {
        goto L_0x00481ad2;
    }
    // 00481b9d  a13cdd5100             -mov eax, dword ptr [0x51dd3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365052) /* 0x51dd3c */);
    // 00481ba2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481ba3  e8f2510300             -call 0x4b6d9a
    cpu.esp -= 4;
    sub_4b6d9a(app, cpu);
    if (cpu.terminate) return;
    // 00481ba8  a138dd5100             -mov eax, dword ptr [0x51dd38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */);
    // 00481bad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481bae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481baf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481bb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481bb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481bb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481bb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481bb6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481bb7  833d38dd510000         +cmp dword ptr [0x51dd38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481bbe  7509                   -jne 0x481bc9
    if (!cpu.flags.zf)
    {
        goto L_0x00481bc9;
    }
L_0x00481bc0:
    // 00481bc0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481bc5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481bc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481bc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481bc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481bc9:
    // 00481bc9  8b1d3cdd5100           -mov ebx, dword ptr [0x51dd3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5365052) /* 0x51dd3c */);
    // 00481bcf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481bd1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481bd2  890d38dd5100           -mov dword ptr [0x51dd38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5365048) /* 0x51dd38 */) = cpu.ecx;
    // 00481bd8  e8bd510300             -call 0x4b6d9a
    cpu.esp -= 4;
    sub_4b6d9a(app, cpu);
    if (cpu.terminate) return;
    // 00481bdd  833d34dd510000         +cmp dword ptr [0x51dd34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365044) /* 0x51dd34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481be4  75da                   -jne 0x481bc0
    if (!cpu.flags.zf)
    {
        goto L_0x00481bc0;
    }
L_0x00481be6:
    // 00481be6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481beb  e82cecffff             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00481bf0  833d34dd510000         +cmp dword ptr [0x51dd34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365044) /* 0x51dd34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481bf7  74ed                   -je 0x481be6
    if (cpu.flags.zf)
    {
        goto L_0x00481be6;
    }
    // 00481bf9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481bfe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481bff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481c11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481c12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481c13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481c14  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481c16  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00481c18  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00481c1a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00481c1c  39d0                   +cmp eax, edx
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
    // 00481c1e  7540                   -jne 0x481c60
    if (!cpu.flags.zf)
    {
        goto L_0x00481c60;
    }
    // 00481c20  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481c22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481c24  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00481c28  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00481c2c  39d0                   +cmp eax, edx
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
    // 00481c2e  7530                   -jne 0x481c60
    if (!cpu.flags.zf)
    {
        goto L_0x00481c60;
    }
    // 00481c30  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481c32  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481c34  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00481c38  668b5706               -mov dx, word ptr [edi + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 00481c3c  39d0                   +cmp eax, edx
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
    // 00481c3e  7520                   -jne 0x481c60
    if (!cpu.flags.zf)
    {
        goto L_0x00481c60;
    }
    // 00481c40  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00481c42  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00481c45  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481c47  8a7f08                 -mov bh, byte ptr [edi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00481c4a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00481c4c  38fb                   +cmp bl, bh
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
    // 00481c4e  7510                   -jne 0x481c60
    if (!cpu.flags.zf)
    {
        goto L_0x00481c60;
    }
L_0x00481c50:
    // 00481c50  42                     -inc edx
    (cpu.edx)++;
    // 00481c51  40                     -inc eax
    (cpu.eax)++;
    // 00481c52  41                     -inc ecx
    (cpu.ecx)++;
    // 00481c53  83f808                 +cmp eax, 8
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
    // 00481c56  7d0f                   -jge 0x481c67
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481c67;
    }
    // 00481c58  8a5908                 -mov bl, byte ptr [ecx + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00481c5b  3a5a08                 +cmp bl, byte ptr [edx + 8]
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
    // 00481c5e  74f0                   -je 0x481c50
    if (cpu.flags.zf)
    {
        goto L_0x00481c50;
    }
L_0x00481c60:
    // 00481c60  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481c62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481c67:
    // 00481c67  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481c6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481c74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c74  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481c75  833d74af4c0000         +cmp dword ptr [0x4caf74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025652) /* 0x4caf74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481c7c  742b                   -je 0x481ca9
    if (cpu.flags.zf)
    {
        goto L_0x00481ca9;
    }
L_0x00481c7e:
    // 00481c7e  b8d4dd5100             -mov eax, 0x51ddd4
    cpu.eax = 5365204 /*0x51ddd4*/;
    // 00481c83  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481c85  e86a0d0000             -call 0x4829f4
    cpu.esp -= 4;
    sub_4829f4(app, cpu);
    if (cpu.terminate) return;
    // 00481c8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481c8c  7407                   -je 0x481c95
    if (cpu.flags.zf)
    {
        goto L_0x00481c95;
    }
    // 00481c8e  e8e9010000             -call 0x481e7c
    cpu.esp -= 4;
    sub_481e7c(app, cpu);
    if (cpu.terminate) return;
    // 00481c93  ebe9                   -jmp 0x481c7e
    goto L_0x00481c7e;
L_0x00481c95:
    // 00481c95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481c96  b8d4dd5100             -mov eax, 0x51ddd4
    cpu.eax = 5365204 /*0x51ddd4*/;
    // 00481c9b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481c9d  e84a0a0000             -call 0x4826ec
    cpu.esp -= 4;
    sub_4826ec(app, cpu);
    if (cpu.terminate) return;
    // 00481ca2  890d74af4c00           -mov dword ptr [0x4caf74], ecx
    app->getMemory<x86::reg32>(x86::reg32(5025652) /* 0x4caf74 */) = cpu.ecx;
    // 00481ca8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481ca9:
    // 00481ca9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481caa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481cac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481cad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481cae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481caf  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481cb2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00481cb6  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00481cb9  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00481cbd  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00481cbf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481cc4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481cc6  8b0d70af4c00           -mov ecx, dword ptr [0x4caf70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5025648) /* 0x4caf70 */);
    // 00481ccc  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00481cd0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481cd2  7e43                   -jle 0x481d17
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481d17;
    }
    // 00481cd4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00481cd6:
    // 00481cd6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481cd8  743d                   -je 0x481d17
    if (cpu.flags.zf)
    {
        goto L_0x00481d17;
    }
    // 00481cda  8b9694dd5100           -mov edx, dword ptr [esi + 0x51dd94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5365140) /* 0x51dd94 */);
    // 00481ce0  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00481ce3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481ce5  7537                   -jne 0x481d1e
    if (!cpu.flags.zf)
    {
        goto L_0x00481d1e;
    }
    // 00481ce7  83ff20                 +cmp edi, 0x20
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
    // 00481cea  7715                   -ja 0x481d01
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00481d01;
    }
    // 00481cec  8b86b4dd5100           -mov eax, dword ptr [esi + 0x51ddb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5365172) /* 0x51ddb4 */);
    // 00481cf2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481cf5  bbfa000000             -mov ebx, 0xfa
    cpu.ebx = 250 /*0xfa*/;
    // 00481cfa  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00481cfd  ff542408               -call dword ptr [esp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00481d01:
    // 00481d01  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00481d05  8b2d70af4c00           -mov ebp, dword ptr [0x4caf70]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5025648) /* 0x4caf70 */);
    // 00481d0b  43                     -inc ebx
    (cpu.ebx)++;
    // 00481d0c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481d0f  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00481d13  39eb                   +cmp ebx, ebp
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
    // 00481d15  7cbf                   -jl 0x481cd6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481cd6;
    }
L_0x00481d17:
    // 00481d17  83c410                 +add esp, 0x10
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
    // 00481d1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481d1e:
    // 00481d1e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481d22  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481d26  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00481d28  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00481d2a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00481d2d  ff5504                 -call dword ptr [ebp + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481d30  ebcf                   -jmp 0x481d01
    goto L_0x00481d01;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481d34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481d34  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481d35  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481d36  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481d37  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481d3a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481d3c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00481d40  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00481d43  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00481d47  8b1574af4c00           -mov edx, dword ptr [0x4caf74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025652) /* 0x4caf74 */);
    // 00481d4d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481d4f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481d51  0f84a4000000           -je 0x481dfb
    if (cpu.flags.zf)
    {
        goto L_0x00481dfb;
    }
L_0x00481d57:
    // 00481d57  b8d4dd5100             -mov eax, 0x51ddd4
    cpu.eax = 5365204 /*0x51ddd4*/;
    // 00481d5c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00481d5e  e86d0b0000             -call 0x4828d0
    cpu.esp -= 4;
    sub_4828d0(app, cpu);
    if (cpu.terminate) return;
    // 00481d63  83f8ff                 +cmp eax, -1
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
    // 00481d66  7407                   -je 0x481d6f
    if (cpu.flags.zf)
    {
        goto L_0x00481d6f;
    }
    // 00481d68  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481d6a  e80d010000             -call 0x481e7c
    cpu.esp -= 4;
    sub_481e7c(app, cpu);
    if (cpu.terminate) return;
L_0x00481d6f:
    // 00481d6f  baac000000             -mov edx, 0xac
    cpu.edx = 172 /*0xac*/;
    // 00481d74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481d76  e821efffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00481d7b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00481d7d  a170af4c00             -mov eax, dword ptr [0x4caf70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025648) /* 0x4caf70 */);
    // 00481d82  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00481d86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481d88  7e62                   -jle 0x481dec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481dec;
    }
    // 00481d8a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00481d8c:
    // 00481d8c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481d8e  755c                   -jne 0x481dec
    if (!cpu.flags.zf)
    {
        goto L_0x00481dec;
    }
    // 00481d90  8b87b4dd5100           -mov eax, dword ptr [edi + 0x51ddb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5365172) /* 0x51ddb4 */);
    // 00481d96  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00481d99  8b8794dd5100           -mov eax, dword ptr [edi + 0x51dd94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5365140) /* 0x51dd94 */);
    // 00481d9f  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00481da2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481da6  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00481da9  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00481dac  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00481db0  0f848d000000           -je 0x481e43
    if (cpu.flags.zf)
    {
        goto L_0x00481e43;
    }
L_0x00481db6:
    // 00481db6  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00481dba  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00481dbe  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00481dc2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481dc3  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00481dc7  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00481dca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481dcb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481dcd  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481dd1  ff5508                 -call dword ptr [ebp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481dd4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00481dd6:
    // 00481dd6  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00481dda  8b1d70af4c00           -mov ebx, dword ptr [0x4caf70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5025648) /* 0x4caf70 */);
    // 00481de0  42                     -inc edx
    (cpu.edx)++;
    // 00481de1  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481de4  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00481de8  39da                   +cmp edx, ebx
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
    // 00481dea  7ca0                   -jl 0x481d8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481d8c;
    }
L_0x00481dec:
    // 00481dec  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481dee  7572                   -jne 0x481e62
    if (!cpu.flags.zf)
    {
        goto L_0x00481e62;
    }
    // 00481df0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481df2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481df5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481df6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481df7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481df8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00481dfb:
    // 00481dfb  b8d4dd5100             -mov eax, 0x51ddd4
    cpu.eax = 5365204 /*0x51ddd4*/;
    // 00481e00  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481e02  e8a5080000             -call 0x4826ac
    cpu.esp -= 4;
    sub_4826ac(app, cpu);
    if (cpu.terminate) return;
    // 00481e07  b8741c4800             -mov eax, 0x481c74
    cpu.eax = 4725876 /*0x481c74*/;
    // 00481e0c  e8cbe80000             -call 0x4906dc
    cpu.esp -= 4;
    sub_4906dc(app, cpu);
    if (cpu.terminate) return;
    // 00481e11  833d68af4c0000         +cmp dword ptr [0x4caf68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025640) /* 0x4caf68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e18  751a                   -jne 0x481e34
    if (!cpu.flags.zf)
    {
        goto L_0x00481e34;
    }
    // 00481e1a  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00481e20  83c209                 -add edx, 9
    (cpu.edx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00481e23  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 00481e28  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e2a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00481e2d  f7ff                   +idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00481e2f  a368af4c00             -mov dword ptr [0x4caf68], eax
    app->getMemory<x86::reg32>(x86::reg32(5025640) /* 0x4caf68 */) = cpu.eax;
L_0x00481e34:
    // 00481e34  c70574af4c0001000000   -mov dword ptr [0x4caf74], 1
    app->getMemory<x86::reg32>(x86::reg32(5025652) /* 0x4caf74 */) = 1 /*0x1*/;
    // 00481e3e  e914ffffff             -jmp 0x481d57
    goto L_0x00481d57;
L_0x00481e43:
    // 00481e43  8b87b4dd5100           -mov eax, dword ptr [edi + 0x51ddb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5365172) /* 0x51ddb4 */);
    // 00481e49  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481e4d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481e50  e8bbfdffff             -call 0x481c10
    cpu.esp -= 4;
    sub_481c10(app, cpu);
    if (cpu.terminate) return;
    // 00481e55  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481e57  0f8559ffffff           -jne 0x481db6
    if (!cpu.flags.zf)
    {
        goto L_0x00481db6;
    }
    // 00481e5d  e974ffffff             -jmp 0x481dd6
    goto L_0x00481dd6;
L_0x00481e62:
    // 00481e62  b8d4dd5100             -mov eax, 0x51ddd4
    cpu.eax = 5365204 /*0x51ddd4*/;
    // 00481e67  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00481e69  e892080000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 00481e6e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481e70  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481e73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e74  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e76  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481e7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481e7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481e7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481e7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481e7f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481e81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481e83  b8d4dd5100             -mov eax, 0x51ddd4
    cpu.eax = 5365204 /*0x51ddd4*/;
    // 00481e88  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481e8a  e8410a0000             -call 0x4828d0
    cpu.esp -= 4;
    sub_4828d0(app, cpu);
    if (cpu.terminate) return;
    // 00481e8f  83f8ff                 +cmp eax, -1
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
    // 00481e92  7506                   -jne 0x481e9a
    if (!cpu.flags.zf)
    {
        goto L_0x00481e9a;
    }
    // 00481e94  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481e96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481e9a:
    // 00481e9a  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00481e9d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481e9f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00481ea1  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481ea4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481ea6  b8d4dd5100             -mov eax, 0x51ddd4
    cpu.eax = 5365204 /*0x51ddd4*/;
    // 00481eab  e8e8090000             -call 0x482898
    cpu.esp -= 4;
    sub_482898(app, cpu);
    if (cpu.terminate) return;
    // 00481eb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481eb2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481eb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481eb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481eb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481eb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481eb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481eb9  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481ebc  ff5610                 -call dword ptr [esi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481ebf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ec0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481ec4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481ec5  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481ec8  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481ecb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ecc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481ed0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481ed1  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481ed4  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481ed7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ed8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481edc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481edc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481edd  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481ee0  ff561c                 -call dword ptr [esi + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481ee3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ee4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481ee8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481ee8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481ee9  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481eec  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481eef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ef0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481ef4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481ef4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481ef5  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481ef8  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481efb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481efc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481f01  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481f04  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481f07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481f0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f0c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481f0d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481f0e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481f10  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481f12  b8d4dd5100             -mov eax, 0x51ddd4
    cpu.eax = 5365204 /*0x51ddd4*/;
    // 00481f17  e8b4090000             -call 0x4828d0
    cpu.esp -= 4;
    sub_4828d0(app, cpu);
    if (cpu.terminate) return;
    // 00481f1c  83f8ff                 +cmp eax, -1
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
    // 00481f1f  7508                   -jne 0x481f29
    if (!cpu.flags.zf)
    {
        goto L_0x00481f29;
    }
    // 00481f21  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481f26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f29:
    // 00481f29  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00481f2c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481f2e  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481f31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481f34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f34  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481f35  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481f38  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481f3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481f41  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481f44  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481f47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481f4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481f4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481f4e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00481f50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481f52  740a                   -je 0x481f5e
    if (cpu.flags.zf)
    {
        goto L_0x00481f5e;
    }
    // 00481f54  c7404400000000         -mov dword ptr [eax + 0x44], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 00481f5b  894848                 -mov dword ptr [eax + 0x48], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.ecx;
L_0x00481f5e:
    // 00481f5e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00481f60  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00481f63  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00481f65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481f67  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481f69  ff5738                 -call dword ptr [edi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481f6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481f71  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00481f74  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00481f77  ff513c                 -call dword ptr [ecx + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481f7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481f7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481f7d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00481f80  837e3800               +cmp dword ptr [esi + 0x38], 0
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
    // 00481f84  7504                   -jne 0x481f8a
    if (!cpu.flags.zf)
    {
        goto L_0x00481f8a;
    }
    // 00481f86  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481f88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f8a:
    // 00481f8a  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00481f8d  ff5638                 -call dword ptr [esi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481f90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481f94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481f95  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00481f98  837a2400               +cmp dword ptr [edx + 0x24], 0
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
    // 00481f9c  7504                   -jne 0x481fa2
    if (!cpu.flags.zf)
    {
        goto L_0x00481fa2;
    }
    // 00481f9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481fa0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fa1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481fa2:
    // 00481fa2  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00481fa5  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481fa8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fa9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481fb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481fb1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481fb2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481fb4  833d7caf4c0000         +cmp dword ptr [0x4caf7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025660) /* 0x4caf7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481fbb  7424                   -je 0x481fe1
    if (cpu.flags.zf)
    {
        goto L_0x00481fe1;
    }
L_0x00481fbd:
    // 00481fbd  833d78af4c0000         +cmp dword ptr [0x4caf78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025656) /* 0x4caf78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481fc4  750a                   -jne 0x481fd0
    if (!cpu.flags.zf)
    {
        goto L_0x00481fd0;
    }
    // 00481fc6  e8adebffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00481fcb  a378af4c00             -mov dword ptr [0x4caf78], eax
    app->getMemory<x86::reg32>(x86::reg32(5025656) /* 0x4caf78 */) = cpu.eax;
L_0x00481fd0:
    // 00481fd0  833d7caf4c0000         +cmp dword ptr [0x4caf7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025660) /* 0x4caf7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481fd7  7453                   -je 0x48202c
    if (cpu.flags.zf)
    {
        goto L_0x0048202c;
    }
    // 00481fd9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481fde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fe0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481fe1:
    // 00481fe1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481fe2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481fe3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481fe4  be10044c00             -mov esi, 0x4c0410
    cpu.esi = 4981776 /*0x4c0410*/;
    // 00481fe9  bf62000000             -mov edi, 0x62
    cpu.edi = 98 /*0x62*/;
    // 00481fee  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00481ff1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00481ff3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00481ff5  83c004                 +add eax, 4
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
    // 00481ff8  893578a64c00           -mov dword ptr [0x4ca678], esi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.esi;
    // 00481ffe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482000  b820044c00             -mov eax, 0x4c0420
    cpu.eax = 4981792 /*0x4c0420*/;
    // 00482005  893d7ca64c00           -mov dword ptr [0x4ca67c], edi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edi;
    // 0048200b  e81882ffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00482010  a37caf4c00             -mov dword ptr [0x4caf7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5025660) /* 0x4caf7c */) = cpu.eax;
    // 00482015  890df0dd5100           -mov dword ptr [0x51ddf0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5365232) /* 0x51ddf0 */) = cpu.ecx;
    // 0048201b  892df8dd5100           -mov dword ptr [0x51ddf8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5365240) /* 0x51ddf8 */) = cpu.ebp;
    // 00482021  892df4dd5100           -mov dword ptr [0x51ddf4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5365236) /* 0x51ddf4 */) = cpu.ebp;
    // 00482027  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482028  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482029  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048202a  eb91                   -jmp 0x481fbd
    goto L_0x00481fbd;
L_0x0048202c:
    // 0048202c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048202e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048202f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482030  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482034(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482034  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482035  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482036  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482037  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482038  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482039  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048203a  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048203c  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 00482042  833d7caf4c0000         +cmp dword ptr [0x4caf7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025660) /* 0x4caf7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482049  0f8460020000           -je 0x4822af
    if (cpu.flags.zf)
    {
        goto L_0x004822af;
    }
    // 0048204f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482051  0f8458020000           -je 0x4822af
    if (cpu.flags.zf)
    {
        goto L_0x004822af;
    }
    // 00482057  e8bcd30100             -call 0x49f418
    cpu.esp -= 4;
    sub_49f418(app, cpu);
    if (cpu.terminate) return;
L_0x0048205c:
    // 0048205c  8b157caf4c00           -mov edx, dword ptr [0x4caf7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025660) /* 0x4caf7c */);
    // 00482062  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00482065  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482067  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0048206a  890d7caf4c00           -mov dword ptr [0x4caf7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5025660) /* 0x4caf7c */) = cpu.ecx;
    // 00482070  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482072  0f84ff020000           -je 0x482377
    if (cpu.flags.zf)
    {
        goto L_0x00482377;
    }
    // 00482078  a1f8dd5100             -mov eax, dword ptr [0x51ddf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365240) /* 0x51ddf8 */);
    // 0048207d  8b1df0dd5100           -mov ebx, dword ptr [0x51ddf0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5365232) /* 0x51ddf0 */);
    // 00482083  39d8                   +cmp eax, ebx
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
    // 00482085  0f8d2b020000           -jge 0x4822b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004822b6;
    }
L_0x0048208b:
    // 0048208b  a3f8dd5100             -mov dword ptr [0x51ddf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5365240) /* 0x51ddf8 */) = cpu.eax;
L_0x00482090:
    // 00482090  8b35f8dd5100           -mov esi, dword ptr [0x51ddf8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5365240) /* 0x51ddf8 */);
    // 00482096  4e                     -dec esi
    (cpu.esi)--;
    // 00482097  8935f8dd5100           -mov dword ptr [0x51ddf8], esi
    app->getMemory<x86::reg32>(x86::reg32(5365240) /* 0x51ddf8 */) = cpu.esi;
    // 0048209d  83feff                 +cmp esi, -1
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
    // 004820a0  0f84c9020000           -je 0x48236f
    if (cpu.flags.zf)
    {
        goto L_0x0048236f;
    }
    // 004820a6  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004820a9  8b35f4dd5100           -mov esi, dword ptr [0x51ddf4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5365236) /* 0x51ddf4 */);
    // 004820af  8b15f4dd5100           -mov edx, dword ptr [0x51ddf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365236) /* 0x51ddf4 */);
    // 004820b5  8b0df0dd5100           -mov ecx, dword ptr [0x51ddf0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5365232) /* 0x51ddf0 */);
    // 004820bb  c1e606                 -shl esi, 6
    cpu.esi <<= 6 /*0x6*/ % 32;
    // 004820be  42                     -inc edx
    (cpu.edx)++;
    // 004820bf  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004820c1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004820c3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004820c6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004820c8  8a6609                 -mov ah, byte ptr [esi + 9]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 004820cb  8915f4dd5100           -mov dword ptr [0x51ddf4], edx
    app->getMemory<x86::reg32>(x86::reg32(5365236) /* 0x51ddf4 */) = cpu.edx;
    // 004820d1  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004820d3  0f84ee010000           -je 0x4822c7
    if (cpu.flags.zf)
    {
        goto L_0x004822c7;
    }
    // 004820d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004820db  8a4609                 -mov al, byte ptr [esi + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 004820de  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004820e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004820e2  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 004820e5  0f84d2010000           -je 0x4822bd
    if (cpu.flags.zf)
    {
        goto L_0x004822bd;
    }
    // 004820eb  b82c044c00             -mov eax, 0x4c042c
    cpu.eax = 4981804 /*0x4c042c*/;
L_0x004820f0:
    // 004820f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004820f1  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004820f3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004820f4  683c044c00             -push 0x4c043c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981820 /*0x4c043c*/;
    cpu.esp -= 4;
    // 004820f9  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004820ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482100  e8dc9effff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00482105  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00482108:
    // 00482108  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048210e  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00482114  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482116  49                     -dec ecx
    (cpu.ecx)--;
    // 00482117  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482119  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048211b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048211d  49                     -dec ecx
    (cpu.ecx)--;
    // 0048211e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00482121  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00482123  e854d40100             -call 0x49f57c
    cpu.esp -= 4;
    sub_49f57c(app, cpu);
    if (cpu.terminate) return;
    // 00482128  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048212d  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00482130  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00482133  e89c0b0000             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00482138  8a5df8                 -mov bl, byte ptr [ebp - 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048213b  80fb20                 +cmp bl, 0x20
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
    // 0048213e  0f83b2010000           -jae 0x4822f6
    if (!cpu.flags.cf)
    {
        goto L_0x004822f6;
    }
L_0x00482144:
    // 00482144  c645f85f               -mov byte ptr [ebp - 8], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 95 /*0x5f*/;
L_0x00482148:
    // 00482148  8a6df9                 -mov ch, byte ptr [ebp - 7]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 0048214b  80fd20                 +cmp ch, 0x20
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
    // 0048214e  0f83b0010000           -jae 0x482304
    if (!cpu.flags.cf)
    {
        goto L_0x00482304;
    }
L_0x00482154:
    // 00482154  c645f95f               -mov byte ptr [ebp - 7], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */) = 95 /*0x5f*/;
L_0x00482158:
    // 00482158  8a55fa                 -mov dl, byte ptr [ebp - 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0048215b  80fa20                 +cmp dl, 0x20
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
    // 0048215e  0f83ae010000           -jae 0x482312
    if (!cpu.flags.cf)
    {
        goto L_0x00482312;
    }
L_0x00482164:
    // 00482164  c645fa5f               -mov byte ptr [ebp - 6], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = 95 /*0x5f*/;
L_0x00482168:
    // 00482168  8a7dfb                 -mov bh, byte ptr [ebp - 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 0048216b  80ff20                 +cmp bh, 0x20
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
    // 0048216e  0f83ac010000           -jae 0x482320
    if (!cpu.flags.cf)
    {
        goto L_0x00482320;
    }
L_0x00482174:
    // 00482174  c645fb5f               -mov byte ptr [ebp - 5], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) = 95 /*0x5f*/;
L_0x00482178:
    // 00482178  f6460a02               +test byte ptr [esi + 0xa], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 2 /*0x2*/));
    // 0048217c  0f84ac010000           -je 0x48232e
    if (cpu.flags.zf)
    {
        goto L_0x0048232e;
    }
    // 00482182  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482184  8a45fb                 -mov al, byte ptr [ebp - 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 00482187  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482188  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048218a  8a45fa                 -mov al, byte ptr [ebp - 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0048218d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048218e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482190  8a45f9                 -mov al, byte ptr [ebp - 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 00482193  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482194  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482196  8a45f8                 -mov al, byte ptr [ebp - 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00482199  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048219a  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048219d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048219e  685c044c00             -push 0x4c045c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981852 /*0x4c045c*/;
    cpu.esp -= 4;
    // 004821a3  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004821a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004821aa  e8329effff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 004821af  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x004821b2:
    // 004821b2  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004821b8  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004821be  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004821c0  49                     -dec ecx
    (cpu.ecx)--;
    // 004821c1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004821c3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004821c5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004821c7  49                     -dec ecx
    (cpu.ecx)--;
    // 004821c8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004821cb  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004821cd  e8aad30100             -call 0x49f57c
    cpu.esp -= 4;
    sub_49f57c(app, cpu);
    if (cpu.terminate) return;
    // 004821d2  f6460a01               +test byte ptr [esi + 0xa], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 1 /*0x1*/));
    // 004821d6  7473                   -je 0x48224b
    if (cpu.flags.zf)
    {
        goto L_0x0048224b;
    }
    // 004821d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004821da  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 004821df  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004821e2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004821e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004821e6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004821e8  7e09                   -jle 0x4821f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004821f3;
    }
    // 004821ea  83fa35                 +cmp edx, 0x35
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
    // 004821ed  0f8d5b010000           -jge 0x48234e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048234e;
    }
L_0x004821f3:
    // 004821f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004821f5  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 004821fa  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004821fd  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004821ff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482201  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482203  0f8e3e010000           -jle 0x482347
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482347;
    }
L_0x00482209:
    // 00482209  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048220b:
    // 0048220b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048220d  8d560b                 -lea edx, [esi + 0xb]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 00482210  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00482213  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00482215  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482217  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048221d  e89a9dffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00482222  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00482224  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048222a  889429f4feffff         -mov byte ptr [ecx + ebp - 0x10c], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-268) /* -0x10c */ + cpu.ebp * 1) = cpu.dl;
    // 00482231  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482233  49                     -dec ecx
    (cpu.ecx)--;
    // 00482234  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482236  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00482238  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048223a  49                     -dec ecx
    (cpu.ecx)--;
    // 0048223b  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00482241  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00482244  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00482246  e831d30100             -call 0x49f57c
    cpu.esp -= 4;
    sub_49f57c(app, cpu);
    if (cpu.terminate) return;
L_0x0048224b:
    // 0048224b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00482250  ba7c044c00             -mov edx, 0x4c047c
    cpu.edx = 4981884 /*0x4c047c*/;
    // 00482255  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00482258  e81fd30100             -call 0x49f57c
    cpu.esp -= 4;
    sub_49f57c(app, cpu);
    if (cpu.terminate) return;
    // 0048225d  f6460a04               +test byte ptr [esi + 0xa], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 4 /*0x4*/));
    // 00482261  0f84f1000000           -je 0x482358
    if (cpu.flags.zf)
    {
        goto L_0x00482358;
    }
    // 00482267  8d4e0b                 -lea ecx, [esi + 0xb]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 0048226a  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
L_0x0048226f:
    // 0048226f  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00482272  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 00482274  fecc                   -dec ah
    (cpu.ah)--;
    // 00482276  886608                 -mov byte ptr [esi + 8], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ah;
    // 00482279  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0048227b  0f84d7000000           -je 0x482358
    if (cpu.flags.zf)
    {
        goto L_0x00482358;
    }
    // 00482281  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00482283  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482285  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00482287  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482288  6880044c00             -push 0x4c0480
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981888 /*0x4c0480*/;
    cpu.esp -= 4;
    // 0048228d  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00482293  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482294  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00482296  e8469dffff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0048229b  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004822a1  83c40c                 +add esp, 0xc
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
    // 004822a4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004822a7  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004822a8  e8cfd20100             -call 0x49f57c
    cpu.esp -= 4;
    sub_49f57c(app, cpu);
    if (cpu.terminate) return;
    // 004822ad  ebc0                   -jmp 0x48226f
    goto L_0x0048226f;
L_0x004822af:
    // 004822af  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004822b1  e9a6fdffff             -jmp 0x48205c
    goto L_0x0048205c;
L_0x004822b6:
    // 004822b6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004822b8  e9cefdffff             -jmp 0x48208b
    goto L_0x0048208b;
L_0x004822bd:
    // 004822bd  b834044c00             -mov eax, 0x4c0434
    cpu.eax = 4981812 /*0x4c0434*/;
    // 004822c2  e929feffff             -jmp 0x4820f0
    goto L_0x004820f0;
L_0x004822c7:
    // 004822c7  f6460a08               +test byte ptr [esi + 0xa], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 8 /*0x8*/));
    // 004822cb  7422                   -je 0x4822ef
    if (cpu.flags.zf)
    {
        goto L_0x004822ef;
    }
    // 004822cd  b82c044c00             -mov eax, 0x4c042c
    cpu.eax = 4981804 /*0x4c042c*/;
L_0x004822d2:
    // 004822d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004822d3  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004822d5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004822d6  684c044c00             -push 0x4c044c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981836 /*0x4c044c*/;
    cpu.esp -= 4;
    // 004822db  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004822e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004822e2  e8fa9cffff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 004822e7  83c410                 +add esp, 0x10
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
    // 004822ea  e919feffff             -jmp 0x482108
    goto L_0x00482108;
L_0x004822ef:
    // 004822ef  b834044c00             -mov eax, 0x4c0434
    cpu.eax = 4981812 /*0x4c0434*/;
    // 004822f4  ebdc                   -jmp 0x4822d2
    goto L_0x004822d2;
L_0x004822f6:
    // 004822f6  80fb7f                 +cmp bl, 0x7f
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
    // 004822f9  0f8745feffff           -ja 0x482144
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00482144;
    }
    // 004822ff  e944feffff             -jmp 0x482148
    goto L_0x00482148;
L_0x00482304:
    // 00482304  80fd7f                 +cmp ch, 0x7f
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
    // 00482307  0f8747feffff           -ja 0x482154
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00482154;
    }
    // 0048230d  e946feffff             -jmp 0x482158
    goto L_0x00482158;
L_0x00482312:
    // 00482312  80fa7f                 +cmp dl, 0x7f
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
    // 00482315  0f8749feffff           -ja 0x482164
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00482164;
    }
    // 0048231b  e948feffff             -jmp 0x482168
    goto L_0x00482168;
L_0x00482320:
    // 00482320  80ff7f                 +cmp bh, 0x7f
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
    // 00482323  0f874bfeffff           -ja 0x482174
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00482174;
    }
    // 00482329  e94afeffff             -jmp 0x482178
    goto L_0x00482178;
L_0x0048232e:
    // 0048232e  686c044c00             -push 0x4c046c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981868 /*0x4c046c*/;
    cpu.esp -= 4;
    // 00482333  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00482339  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048233a  e8a29cffff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0048233f  83c408                 +add esp, 8
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
    // 00482342  e96bfeffff             -jmp 0x4821b2
    goto L_0x004821b2;
L_0x00482347:
    // 00482347  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00482349  e9bbfeffff             -jmp 0x482209
    goto L_0x00482209;
L_0x0048234e:
    // 0048234e  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 00482353  e9b3feffff             -jmp 0x48220b
    goto L_0x0048220b;
L_0x00482358:
    // 00482358  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048235d  ba88044c00             -mov edx, 0x4c0488
    cpu.edx = 4981896 /*0x4c0488*/;
    // 00482362  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00482365  e812d20100             -call 0x49f57c
    cpu.esp -= 4;
    sub_49f57c(app, cpu);
    if (cpu.terminate) return;
    // 0048236a  e921fdffff             -jmp 0x482090
    goto L_0x00482090;
L_0x0048236f:
    // 0048236f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00482372  e805d10100             -call 0x49f47c
    cpu.esp -= 4;
    sub_49f47c(app, cpu);
    if (cpu.terminate) return;
L_0x00482377:
    // 00482377  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0048237a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048237c  7407                   -je 0x482385
    if (cpu.flags.zf)
    {
        goto L_0x00482385;
    }
    // 0048237e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482380  e80783ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x00482385:
    // 00482385  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00482389  740e                   -je 0x482399
    if (cpu.flags.zf)
    {
        goto L_0x00482399;
    }
    // 0048238b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482390  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00482392  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482393  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482394  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482395  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482396  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482397  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482398  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482399:
    // 00482399  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048239b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0048239d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048239e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048239f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4823a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004823a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004823a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004823a6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004823a7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004823a9  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004823ac  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004823af  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004823b2  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004823b5  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004823b8  a178af4c00             -mov eax, dword ptr [0x4caf78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025656) /* 0x4caf78 */);
    // 004823bd  e806e8ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004823c2  833d7caf4c0000         +cmp dword ptr [0x4caf7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025660) /* 0x4caf7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004823c9  0f847d010000           -je 0x48254c
    if (cpu.flags.zf)
    {
        goto L_0x0048254c;
    }
    // 004823cf  8b15f4dd5100           -mov edx, dword ptr [0x51ddf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365236) /* 0x51ddf4 */);
    // 004823d5  8b0df8dd5100           -mov ecx, dword ptr [0x51ddf8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5365240) /* 0x51ddf8 */);
    // 004823db  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004823dd  8b1df0dd5100           -mov ebx, dword ptr [0x51ddf0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5365232) /* 0x51ddf0 */);
    // 004823e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004823e5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004823e8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004823ea  8b357caf4c00           -mov esi, dword ptr [0x4caf7c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5025660) /* 0x4caf7c */);
    // 004823f0  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 004823f3  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004823f5  39d9                   +cmp ecx, ebx
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
    // 004823f7  0f856f010000           -jne 0x48256c
    if (!cpu.flags.zf)
    {
        goto L_0x0048256c;
    }
    // 004823fd  8b15f4dd5100           -mov edx, dword ptr [0x51ddf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365236) /* 0x51ddf4 */);
    // 00482403  42                     -inc edx
    (cpu.edx)++;
    // 00482404  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482406  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00482409  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048240b  8915f4dd5100           -mov dword ptr [0x51ddf4], edx
    app->getMemory<x86::reg32>(x86::reg32(5365236) /* 0x51ddf4 */) = cpu.edx;
L_0x00482411:
    // 00482411  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00482414  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482416  0f8467010000           -je 0x482583
    if (cpu.flags.zf)
    {
        goto L_0x00482583;
    }
    // 0048241c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048241e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482420  49                     -dec ecx
    (cpu.ecx)--;
    // 00482421  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482423  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00482425  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00482427  49                     -dec ecx
    (cpu.ecx)--;
    // 00482428  83f935                 +cmp ecx, 0x35
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
    // 0048242b  0f8348010000           -jae 0x482579
    if (!cpu.flags.cf)
    {
        goto L_0x00482579;
    }
    // 00482431  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00482433  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482435  49                     -dec ecx
    (cpu.ecx)--;
    // 00482436  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482438  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048243a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048243c  49                     -dec ecx
    (cpu.ecx)--;
L_0x0048243d:
    // 0048243d  837df000               +cmp dword ptr [ebp - 0x10], 0
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
    // 00482441  0f8443010000           -je 0x48258a
    if (cpu.flags.zf)
    {
        goto L_0x0048258a;
    }
    // 00482447  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482449  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0048244e  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 00482450  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00482452  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00482455  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482457  39fa                   +cmp edx, edi
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
    // 00482459  7e02                   -jle 0x48245d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048245d;
    }
    // 0048245b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0048245d:
    // 0048245d  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
L_0x00482460:
    // 00482460  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00482463  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482465  7405                   -je 0x48246c
    if (cpu.flags.zf)
    {
        goto L_0x0048246c;
    }
    // 00482467  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x0048246c:
    // 0048246c  88460a                 -mov byte ptr [esi + 0xa], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.al;
    // 0048246f  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00482474  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00482476  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00482479  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0048247c  884609                 -mov byte ptr [esi + 9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 0048247f  8d460b                 -lea eax, [esi + 0xb]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 00482482  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482484  742a                   -je 0x4824b0
    if (cpu.flags.zf)
    {
        goto L_0x004824b0;
    }
    // 00482486  807e0800               +cmp byte ptr [esi + 8], 0
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
    // 0048248a  7424                   -je 0x4824b0
    if (cpu.flags.zf)
    {
        goto L_0x004824b0;
    }
    // 0048248c  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0048248f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00482491  80ce04                 -or dh, 4
    cpu.dh |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00482494  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00482497  88760a                 -mov byte ptr [esi + 0xa], dh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dh;
    // 0048249a  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0048249d  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 0048249f  760f                   -jbe 0x4824b0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004824b0;
    }
L_0x004824a1:
    // 004824a1  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 004824a3  42                     -inc edx
    (cpu.edx)++;
    // 004824a4  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
    // 004824a6  fec3                   -inc bl
    (cpu.bl)++;
    // 004824a8  8a6e08                 -mov ch, byte ptr [esi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004824ab  40                     -inc eax
    (cpu.eax)++;
    // 004824ac  38eb                   +cmp bl, ch
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
    // 004824ae  72f1                   -jb 0x4824a1
    if (cpu.flags.cf)
    {
        goto L_0x004824a1;
    }
L_0x004824b0:
    // 004824b0  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 004824b4  7425                   -je 0x4824db
    if (cpu.flags.zf)
    {
        goto L_0x004824db;
    }
    // 004824b6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004824b8  7421                   -je 0x4824db
    if (cpu.flags.zf)
    {
        goto L_0x004824db;
    }
    // 004824ba  8a560a                 -mov dl, byte ptr [esi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004824bd  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004824c0  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004824c2  88560a                 -mov byte ptr [esi + 0xa], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dl;
    // 004824c5  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004824c8  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004824ca  760c                   -jbe 0x4824d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004824d8;
    }
L_0x004824cc:
    // 004824cc  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 004824ce  42                     -inc edx
    (cpu.edx)++;
    // 004824cf  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
    // 004824d1  fec3                   -inc bl
    (cpu.bl)++;
    // 004824d3  40                     -inc eax
    (cpu.eax)++;
    // 004824d4  38cb                   +cmp bl, cl
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
    // 004824d6  72f4                   -jb 0x4824cc
    if (cpu.flags.cf)
    {
        goto L_0x004824cc;
    }
L_0x004824d8:
    // 004824d8  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x004824db:
    // 004824db  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004824de  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004824e0  0f84ad000000           -je 0x482593
    if (cpu.flags.zf)
    {
        goto L_0x00482593;
    }
    // 004824e6  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004824e9  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004824eb  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004824ee  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004824f1  88760a                 -mov byte ptr [esi + 0xa], dh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dh;
L_0x004824f4:
    // 004824f4  833d80af4c0000         +cmp dword ptr [0x4caf80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025664) /* 0x4caf80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004824fb  744f                   -je 0x48254c
    if (cpu.flags.zf)
    {
        goto L_0x0048254c;
    }
    // 004824fd  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00482500  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00482503  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482504  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482506  0f848f000000           -je 0x48259b
    if (cpu.flags.zf)
    {
        goto L_0x0048259b;
    }
    // 0048250c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0048250e:
    // 0048250e  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00482511  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482512  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482514  0f848b000000           -je 0x4825a5
    if (cpu.flags.zf)
    {
        goto L_0x004825a5;
    }
    // 0048251a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
L_0x0048251c:
    // 0048251c  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048251f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482520  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00482522  0f8484000000           -je 0x4825ac
    if (cpu.flags.zf)
    {
        goto L_0x004825ac;
    }
    // 00482528  b82c044c00             -mov eax, 0x4c042c
    cpu.eax = 4981804 /*0x4c042c*/;
L_0x0048252d:
    // 0048252d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048252e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482530  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00482533  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482534  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482536  a084af4c00             -mov al, byte ptr [0x4caf84]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5025668) /* 0x4caf84 */);
    // 0048253b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048253c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048253e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048253f  6890044c00             -push 0x4c0490
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981904 /*0x4c0490*/;
    cpu.esp -= 4;
    // 00482544  e857330000             -call 0x4858a0
    cpu.esp -= 4;
    sub_4858a0(app, cpu);
    if (cpu.terminate) return;
    // 00482549  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0048254c:
    // 0048254c  a178af4c00             -mov eax, dword ptr [0x4caf78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025656) /* 0x4caf78 */);
    // 00482551  e88ae6ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482556  833d7caf4c0000         +cmp dword ptr [0x4caf7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025660) /* 0x4caf7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048255d  7457                   -je 0x4825b6
    if (cpu.flags.zf)
    {
        goto L_0x004825b6;
    }
    // 0048255f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482564  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00482566  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482567  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482568  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482569  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048256c:
    // 0048256c  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0048256f  a3f8dd5100             -mov dword ptr [0x51ddf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5365240) /* 0x51ddf8 */) = cpu.eax;
    // 00482574  e998feffff             -jmp 0x482411
    goto L_0x00482411;
L_0x00482579:
    // 00482579  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 0048257e  e9bafeffff             -jmp 0x48243d
    goto L_0x0048243d;
L_0x00482583:
    // 00482583  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00482585  e9b3feffff             -jmp 0x48243d
    goto L_0x0048243d;
L_0x0048258a:
    // 0048258a  c6460800               -mov byte ptr [esi + 8], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048258e  e9cdfeffff             -jmp 0x482460
    goto L_0x00482460;
L_0x00482593:
    // 00482593  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00482596  e959ffffff             -jmp 0x4824f4
    goto L_0x004824f4;
L_0x0048259b:
    // 0048259b  b88c044c00             -mov eax, 0x4c048c
    cpu.eax = 4981900 /*0x4c048c*/;
    // 004825a0  e969ffffff             -jmp 0x48250e
    goto L_0x0048250e;
L_0x004825a5:
    // 004825a5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004825a7  e970ffffff             -jmp 0x48251c
    goto L_0x0048251c;
L_0x004825ac:
    // 004825ac  b834044c00             -mov eax, 0x4c0434
    cpu.eax = 4981812 /*0x4c0434*/;
    // 004825b1  e977ffffff             -jmp 0x48252d
    goto L_0x0048252d;
L_0x004825b6:
    // 004825b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004825b8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004825ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825bd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4825c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004825c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x004825c1:
    // 004825c1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004825c3  7504                   -jne 0x4825c9
    if (!cpu.flags.zf)
    {
        goto L_0x004825c9;
    }
L_0x004825c5:
    // 004825c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004825c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004825c9:
    // 004825c9  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004825cb  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 004825cd  38e9                   +cmp cl, ch
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
    // 004825cf  740e                   -je 0x4825df
    if (cpu.flags.zf)
    {
        goto L_0x004825df;
    }
    // 004825d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004825d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004825d5  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 004825d7  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 004825d9  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004825db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004825dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004825df:
    // 004825df  803800                 +cmp byte ptr [eax], 0
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
    // 004825e2  74e1                   -je 0x4825c5
    if (cpu.flags.zf)
    {
        goto L_0x004825c5;
    }
    // 004825e4  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004825e5  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004825e6  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004825e7  ebd8                   -jmp 0x4825c1
    goto L_0x004825c1;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4825f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004825f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4825f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004825f4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004825f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004825f8  740c                   -je 0x482606
    if (cpu.flags.zf)
    {
        goto L_0x00482606;
    }
L_0x004825fa:
    // 004825fa  4a                     -dec edx
    (cpu.edx)--;
    // 004825fb  83faff                 +cmp edx, -1
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
    // 004825fe  7406                   -je 0x482606
    if (cpu.flags.zf)
    {
        goto L_0x00482606;
    }
    // 00482600  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00482602  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482604  75f4                   -jne 0x4825fa
    if (!cpu.flags.zf)
    {
        goto L_0x004825fa;
    }
L_0x00482606:
    // 00482606  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482608(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482608  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482609  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048260a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048260b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048260c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048260d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048260f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482611  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482613  7441                   -je 0x482656
    if (cpu.flags.zf)
    {
        goto L_0x00482656;
    }
    // 00482615  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00482617  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482619  763b                   -jbe 0x482656
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482656;
    }
    // 0048261b  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048261e  39fa                   +cmp edx, edi
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
    // 00482620  743c                   -je 0x48265e
    if (cpu.flags.zf)
    {
        goto L_0x0048265e;
    }
    // 00482622  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 00482624  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482626  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00482628  740b                   -je 0x482635
    if (cpu.flags.zf)
    {
        goto L_0x00482635;
    }
L_0x0048262a:
    // 0048262a  3b10                   +cmp edx, dword ptr [eax]
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
    // 0048262c  7407                   -je 0x482635
    if (cpu.flags.zf)
    {
        goto L_0x00482635;
    }
    // 0048262e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00482630  833800                 +cmp dword ptr [eax], 0
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
    // 00482633  75f5                   -jne 0x48262a
    if (!cpu.flags.zf)
    {
        goto L_0x0048262a;
    }
L_0x00482635:
    // 00482635  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00482637  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482639  7417                   -je 0x482652
    if (cpu.flags.zf)
    {
        goto L_0x00482652;
    }
    // 0048263b  39f2                   +cmp edx, esi
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
    // 0048263d  7513                   -jne 0x482652
    if (!cpu.flags.zf)
    {
        goto L_0x00482652;
    }
    // 0048263f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00482644  2919                   -sub dword ptr [ecx], ebx
    (app->getMemory<x86::reg32>(cpu.ecx)) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482646  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00482648  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0048264a  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
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
    // 0048264d  7503                   -jne 0x482652
    if (!cpu.flags.zf)
    {
        goto L_0x00482652;
    }
    // 0048264f  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00482652:
    // 00482652  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482654  7544                   -jne 0x48269a
    if (!cpu.flags.zf)
    {
        goto L_0x0048269a;
    }
L_0x00482656:
    // 00482656  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482658  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482659  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048265a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048265b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048265c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048265d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048265e:
    // 0048265e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00482663  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482665  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482667  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048266a  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0048266c  39f7                   +cmp edi, esi
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
    // 0048266e  7519                   -jne 0x482689
    if (!cpu.flags.zf)
    {
        goto L_0x00482689;
    }
    // 00482670  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00482677  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048267a  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048267d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048267f  7519                   -jne 0x48269a
    if (!cpu.flags.zf)
    {
        goto L_0x0048269a;
    }
    // 00482681  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482683  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482684  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482685  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482686  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482687  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482688  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482689:
    // 00482689  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048268b  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048268e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482690  7508                   -jne 0x48269a
    if (!cpu.flags.zf)
    {
        goto L_0x0048269a;
    }
    // 00482692  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482694  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482695  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482696  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482697  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482698  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482699  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048269a:
    // 0048269a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004826a0  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004826a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004826a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4826ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004826ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004826ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004826af  e8c4e4ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 004826b4  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 004826ba  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004826c1  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004826c8  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004826cf  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004826d2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004826d4  7408                   -je 0x4826de
    if (cpu.flags.zf)
    {
        goto L_0x004826de;
    }
    // 004826d6  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004826d9  895914                 -mov dword ptr [ecx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004826dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004826de:
    // 004826de  baf0254800             -mov edx, 0x4825f0
    cpu.edx = 4728304 /*0x4825f0*/;
    // 004826e3  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004826e6  895914                 -mov dword ptr [ecx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004826e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4826ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004826ec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004826ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004826ef  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004826f2  e8fde4ffff             -call 0x480bf4
    cpu.esp -= 4;
    sub_480bf4(app, cpu);
    if (cpu.terminate) return;
    // 004826f7  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004826fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482700  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482701  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482703  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482706  e8bde4ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048270b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048270d  741b                   -je 0x48272a
    if (cpu.flags.zf)
    {
        goto L_0x0048272a;
    }
    // 0048270f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482710  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00482713  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00482715  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00482717  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048271a  43                     -inc ebx
    (cpu.ebx)++;
    // 0048271b  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0048271d  833a00                 +cmp dword ptr [edx], 0
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
    // 00482720  7503                   -jne 0x482725
    if (!cpu.flags.zf)
    {
        goto L_0x00482725;
    }
    // 00482722  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00482725:
    // 00482725  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00482729  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048272a:
    // 0048272a  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048272d  e8aee4ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482732  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482733  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482734(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482734  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482735  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482737  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048273a  e889e4ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048273f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482741  741e                   -je 0x482761
    if (cpu.flags.zf)
    {
        goto L_0x00482761;
    }
    // 00482743  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482744  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482747  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0048274d  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048274f  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00482752  43                     -inc ebx
    (cpu.ebx)++;
    // 00482753  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00482755  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482757  7512                   -jne 0x48276b
    if (!cpu.flags.zf)
    {
        goto L_0x0048276b;
    }
    // 00482759  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048275c  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00482760  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482761:
    // 00482761  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482764  e877e4ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482769  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048276a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048276b:
    // 0048276b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0048276d  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00482771  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482772  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482775  e866e4ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048277a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048277b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48277c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048277c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048277d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048277e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482780  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482783  e840e4ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482788  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048278b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048278d  741a                   -je 0x4827a9
    if (cpu.flags.zf)
    {
        goto L_0x004827a9;
    }
    // 0048278f  3b4a0c                 +cmp ecx, dword ptr [edx + 0xc]
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
    // 00482792  7526                   -jne 0x4827ba
    if (!cpu.flags.zf)
    {
        goto L_0x004827ba;
    }
    // 00482794  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048279b  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
L_0x0048279e:
    // 0048279e  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004827a1  ff0a                   -dec dword ptr [edx]
    (app->getMemory<x86::reg32>(cpu.edx))--;
    // 004827a3  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x004827a9:
    // 004827a9  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004827ad  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004827b0  e82be4ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004827b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004827b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004827ba:
    // 004827ba  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004827bc  ebe0                   -jmp 0x48279e
    goto L_0x0048279e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4827c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004827c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004827c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004827c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004827c4  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004827c7  e8fce3ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004827cc  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004827cf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004827d1  742f                   -je 0x482802
    if (cpu.flags.zf)
    {
        goto L_0x00482802;
    }
    // 004827d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004827d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004827d5  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004827d7  4b                     -dec ebx
    (cpu.ebx)--;
    // 004827d8  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004827db  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004827dd  39f1                   +cmp ecx, esi
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
    // 004827df  7432                   -je 0x482813
    if (cpu.flags.zf)
    {
        goto L_0x00482813;
    }
    // 004827e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004827e2  89720c                 -mov dword ptr [edx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x004827e5:
    // 004827e5  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004827e8  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004827ea  39f9                   +cmp ecx, edi
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
    // 004827ec  7405                   -je 0x4827f3
    if (cpu.flags.zf)
    {
        goto L_0x004827f3;
    }
    // 004827ee  897a0c                 -mov dword ptr [edx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004827f1  ebf2                   -jmp 0x4827e5
    goto L_0x004827e5;
L_0x004827f3:
    // 004827f3  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004827f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004827fa:
    // 004827fa  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00482800  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482801  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482802:
    // 00482802  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00482806  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00482809  e8d2e3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048280e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482810  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482811  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482812  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482813:
    // 00482813  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048281a  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048281d  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00482820  ebd8                   -jmp 0x4827fa
    goto L_0x004827fa;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482824(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482824  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482825  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482826  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482828  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048282a  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048282d  e896e3ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482832  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482834  750b                   -jne 0x482841
    if (!cpu.flags.zf)
    {
        goto L_0x00482841;
    }
    // 00482836  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00482839  e8a2e3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048283e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048283f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482840  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482841:
    // 00482841  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482842  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482843  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482844  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00482846  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00482849  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048284b  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048284e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00482850  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482852  42                     -inc edx
    (cpu.edx)++;
    // 00482853  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00482856  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00482858  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048285a  7414                   -je 0x482870
    if (cpu.flags.zf)
    {
        goto L_0x00482870;
    }
L_0x0048285c:
    // 0048285c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048285e  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00482861  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482864  39f8                   +cmp eax, edi
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
    // 00482866  7308                   -jae 0x482870
    if (!cpu.flags.cf)
    {
        goto L_0x00482870;
    }
    // 00482868  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048286a  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048286c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048286e  75ec                   -jne 0x48285c
    if (!cpu.flags.zf)
    {
        goto L_0x0048285c;
    }
L_0x00482870:
    // 00482870  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 00482873  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482875  751c                   -jne 0x482893
    if (!cpu.flags.zf)
    {
        goto L_0x00482893;
    }
    // 00482877  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x0048287a:
    // 0048287a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048287c  7503                   -jne 0x482881
    if (!cpu.flags.zf)
    {
        goto L_0x00482881;
    }
    // 0048287e  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
L_0x00482881:
    // 00482881  804b0401               +or byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00482885  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482886  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482887  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482888  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048288b  e850e3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482890  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482891  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482892  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482893:
    // 00482893  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00482895  ebe3                   -jmp 0x48287a
    goto L_0x0048287a;
}

/* align: skip 0x90 */
void Application::sub_482898(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482898  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482899  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048289a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048289c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048289f  e824e3ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004828a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004828a6  750d                   -jne 0x4828b5
    if (!cpu.flags.zf)
    {
        goto L_0x004828b5;
    }
    // 004828a8  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004828ab  e830e3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004828b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004828b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004828b5:
    // 004828b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004828b7  e84cfdffff             -call 0x482608
    cpu.esp -= 4;
    sub_482608(app, cpu);
    if (cpu.terminate) return;
    // 004828bc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004828be  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004828c1  e81ae3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004828c6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004828c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4828cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004828cc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004828ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4828d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004828d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004828d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004828d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004828d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004828d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004828d5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004828d8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004828da  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004828dc  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004828df  e8e4e2ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004828e4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004828e6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004828e8  742b                   -je 0x482915
    if (cpu.flags.zf)
    {
        goto L_0x00482915;
    }
    // 004828ea  8b7710                 -mov esi, dword ptr [edi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004828ed  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004828f0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004828f2  7539                   -jne 0x48292d
    if (!cpu.flags.zf)
    {
        goto L_0x0048292d;
    }
    // 004828f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004828f6:
    // 004828f6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004828f9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004828fb  7414                   -je 0x482911
    if (cpu.flags.zf)
    {
        goto L_0x00482911;
    }
L_0x004828fd:
    // 004828fd  39e9                   +cmp ecx, ebp
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
    // 004828ff  7410                   -je 0x482911
    if (cpu.flags.zf)
    {
        goto L_0x00482911;
    }
    // 00482901  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482903  7431                   -je 0x482936
    if (cpu.flags.zf)
    {
        goto L_0x00482936;
    }
    // 00482905  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482907  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0048290a  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048290c  3b0424                 +cmp eax, dword ptr [esp]
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
    // 0048290f  7625                   -jbe 0x482936
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482936;
    }
L_0x00482911:
    // 00482911  39e9                   +cmp ecx, ebp
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
    // 00482913  7405                   -je 0x48291a
    if (cpu.flags.zf)
    {
        goto L_0x0048291a;
    }
L_0x00482915:
    // 00482915  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x0048291a:
    // 0048291a  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048291d  e8bee2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482922  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482924  83c404                 +add esp, 4
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
    // 00482927  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482928  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482929  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048292a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048292b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048292c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048292d:
    // 0048292d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048292f  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00482932  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482934  ebc0                   -jmp 0x4828f6
    goto L_0x004828f6;
L_0x00482936:
    // 00482936  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00482938  43                     -inc ebx
    (cpu.ebx)++;
    // 00482939  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048293b  75c0                   -jne 0x4828fd
    if (!cpu.flags.zf)
    {
        goto L_0x004828fd;
    }
    // 0048293d  ebd2                   -jmp 0x482911
    goto L_0x00482911;
}

/* align: skip 0x90 */
void Application::sub_482940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482941  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482943  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482945  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482948  e87be2ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048294d  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00482950  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00482955  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482957  750e                   -jne 0x482967
    if (!cpu.flags.zf)
    {
        goto L_0x00482967;
    }
    // 00482959  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048295c  e87fe2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482961  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482963  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482964  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482965  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482966  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482967:
    // 00482967  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482969  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048296c  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048296f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482971  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482974  e867e2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482979  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048297b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482981  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482982  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482983  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482985  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482988  e83be2ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048298d  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00482990  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482992  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482994  750e                   -jne 0x4829a4
    if (!cpu.flags.zf)
    {
        goto L_0x004829a4;
    }
    // 00482996  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482999  e842e2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048299e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004829a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004829a4:
    // 004829a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004829a6  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004829a9  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004829ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004829ae  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004829b1  e82ae2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004829b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004829b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4829bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004829bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004829bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004829be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004829bf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004829c1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004829c3  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004829c6  e8fde1ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004829cb  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004829ce  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004829d0  7414                   -je 0x4829e6
    if (cpu.flags.zf)
    {
        goto L_0x004829e6;
    }
L_0x004829d2:
    // 004829d2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004829d4  7410                   -je 0x4829e6
    if (cpu.flags.zf)
    {
        goto L_0x004829e6;
    }
    // 004829d6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004829d8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004829da  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004829dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004829de  7506                   -jne 0x4829e6
    if (!cpu.flags.zf)
    {
        goto L_0x004829e6;
    }
    // 004829e0  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004829e2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004829e4  75ec                   -jne 0x4829d2
    if (!cpu.flags.zf)
    {
        goto L_0x004829d2;
    }
L_0x004829e6:
    // 004829e6  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004829e9  e8f2e1ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004829ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004829f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4829f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004829f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004829f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004829f6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004829f8  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004829fb  e8c8e1ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482a00  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00482a03  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482a05  741f                   -je 0x482a26
    if (cpu.flags.zf)
    {
        goto L_0x00482a26;
    }
    // 00482a07  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482a09  770f                   -ja 0x482a1a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00482a1a;
    }
    // 00482a0b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00482a0d:
    // 00482a0d  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482a10  e8cbe1ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482a15  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482a17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482a1a:
    // 00482a1a  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482a1b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482a1d  e8d2fbffff             -call 0x4825f4
    cpu.esp -= 4;
    sub_4825f4(app, cpu);
    if (cpu.terminate) return;
    // 00482a22  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482a24  ebe7                   -jmp 0x482a0d
    goto L_0x00482a0d;
L_0x00482a26:
    // 00482a26  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482a28  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482a2b  e8b0e1ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482a30  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482a32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482a38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482a38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482a39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482a3a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482a3b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482a3d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482a3f  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482a42  e881e1ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482a47  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00482a4a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482a4c  7412                   -je 0x482a60
    if (cpu.flags.zf)
    {
        goto L_0x00482a60;
    }
L_0x00482a4e:
    // 00482a4e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482a50  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00482a53  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482a56  39f0                   +cmp eax, esi
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
    // 00482a58  7306                   -jae 0x482a60
    if (!cpu.flags.cf)
    {
        goto L_0x00482a60;
    }
    // 00482a5a  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00482a5c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482a5e  75ee                   -jne 0x482a4e
    if (!cpu.flags.zf)
    {
        goto L_0x00482a4e;
    }
L_0x00482a60:
    // 00482a60  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482a62  750e                   -jne 0x482a72
    if (!cpu.flags.zf)
    {
        goto L_0x00482a72;
    }
L_0x00482a64:
    // 00482a64  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00482a67  e874e1ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482a6c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482a6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482a72:
    // 00482a72  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482a74  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00482a77  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482a7a  39f0                   +cmp eax, esi
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
    // 00482a7c  74e6                   -je 0x482a64
    if (cpu.flags.zf)
    {
        goto L_0x00482a64;
    }
    // 00482a7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482a80  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00482a83  e858e1ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482a88  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482a8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482a90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482a91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482a92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482a93  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482a95  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482a97  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482a9a  e829e1ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482a9f  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00482aa2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482aa4  7414                   -je 0x482aba
    if (cpu.flags.zf)
    {
        goto L_0x00482aba;
    }
L_0x00482aa6:
    // 00482aa6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482aa8  7410                   -je 0x482aba
    if (cpu.flags.zf)
    {
        goto L_0x00482aba;
    }
    // 00482aaa  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00482aac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482aae  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482ab0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482ab2  7506                   -jne 0x482aba
    if (!cpu.flags.zf)
    {
        goto L_0x00482aba;
    }
    // 00482ab4  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00482ab6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482ab8  75ec                   -jne 0x482aa6
    if (!cpu.flags.zf)
    {
        goto L_0x00482aa6;
    }
L_0x00482aba:
    // 00482aba  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482abc  750e                   -jne 0x482acc
    if (!cpu.flags.zf)
    {
        goto L_0x00482acc;
    }
L_0x00482abe:
    // 00482abe  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00482ac1  e81ae1ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482ac6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482ac8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ac9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482aca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482acb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482acc:
    // 00482acc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00482ace  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482ad0  e833fbffff             -call 0x482608
    cpu.esp -= 4;
    sub_482608(app, cpu);
    if (cpu.terminate) return;
    // 00482ad5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482ad7  75e5                   -jne 0x482abe
    if (!cpu.flags.zf)
    {
        goto L_0x00482abe;
    }
    // 00482ad9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482adb  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00482ade  e8fde0ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482ae3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482ae5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ae6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ae7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ae8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482aec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482aec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482aed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482aee  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482af0  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00482af2  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482af5  e8cee0ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482afa  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00482afd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482aff  7433                   -je 0x482b34
    if (cpu.flags.zf)
    {
        goto L_0x00482b34;
    }
    // 00482b01  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482b03  7713                   -ja 0x482b18
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00482b18;
    }
    // 00482b05  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00482b07:
    // 00482b07  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482b09  751c                   -jne 0x482b27
    if (!cpu.flags.zf)
    {
        goto L_0x00482b27;
    }
L_0x00482b0b:
    // 00482b0b  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482b0e  e8cde0ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482b13  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482b15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482b18:
    // 00482b18  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00482b1b  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00482b1e  e8d1faffff             -call 0x4825f4
    cpu.esp -= 4;
    sub_4825f4(app, cpu);
    if (cpu.terminate) return;
    // 00482b23  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482b25  ebe0                   -jmp 0x482b07
    goto L_0x00482b07;
L_0x00482b27:
    // 00482b27  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00482b29  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482b2b  e8d8faffff             -call 0x482608
    cpu.esp -= 4;
    sub_482608(app, cpu);
    if (cpu.terminate) return;
    // 00482b30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482b32  75d7                   -jne 0x482b0b
    if (!cpu.flags.zf)
    {
        goto L_0x00482b0b;
    }
L_0x00482b34:
    // 00482b34  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482b36  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482b39  e8a2e0ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482b3e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482b40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482b44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482b44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482b45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482b46  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482b48  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482b4a  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482b4d  e876e0ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482b52  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00482b54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482b56  e899faffff             -call 0x4825f4
    cpu.esp -= 4;
    sub_4825f4(app, cpu);
    if (cpu.terminate) return;
    // 00482b5b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482b5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482b5f  750d                   -jne 0x482b6e
    if (!cpu.flags.zf)
    {
        goto L_0x00482b6e;
    }
L_0x00482b61:
    // 00482b61  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482b64  e877e0ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482b69  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482b6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482b6e:
    // 00482b6e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482b70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482b72  e891faffff             -call 0x482608
    cpu.esp -= 4;
    sub_482608(app, cpu);
    if (cpu.terminate) return;
    // 00482b77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482b79  75e6                   -jne 0x482b61
    if (!cpu.flags.zf)
    {
        goto L_0x00482b61;
    }
    // 00482b7b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482b7d  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482b80  e85be0ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482b85  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482b87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482b8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482b8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482b8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482b8e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482b8f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482b91  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482b93  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482b96  e82de0ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482b9b  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00482b9e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482ba0  7412                   -je 0x482bb4
    if (cpu.flags.zf)
    {
        goto L_0x00482bb4;
    }
L_0x00482ba2:
    // 00482ba2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482ba4  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00482ba7  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482baa  39f0                   +cmp eax, esi
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
    // 00482bac  7306                   -jae 0x482bb4
    if (!cpu.flags.cf)
    {
        goto L_0x00482bb4;
    }
    // 00482bae  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00482bb0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482bb2  75ee                   -jne 0x482ba2
    if (!cpu.flags.zf)
    {
        goto L_0x00482ba2;
    }
L_0x00482bb4:
    // 00482bb4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482bb6  7510                   -jne 0x482bc8
    if (!cpu.flags.zf)
    {
        goto L_0x00482bc8;
    }
L_0x00482bb8:
    // 00482bb8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00482bba:
    // 00482bba  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00482bbd  e81ee0ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482bc2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482bc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482bc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482bc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482bc7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482bc8:
    // 00482bc8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482bca  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00482bcd  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482bd0  39f0                   +cmp eax, esi
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
    // 00482bd2  75e4                   -jne 0x482bb8
    if (!cpu.flags.zf)
    {
        goto L_0x00482bb8;
    }
    // 00482bd4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00482bd6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482bd8  e82bfaffff             -call 0x482608
    cpu.esp -= 4;
    sub_482608(app, cpu);
    if (cpu.terminate) return;
    // 00482bdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482bdf  75d9                   -jne 0x482bba
    if (!cpu.flags.zf)
    {
        goto L_0x00482bba;
    }
    // 00482be1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482be3  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00482be6  e8f5dfffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482beb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482bed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482bee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482bef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482bf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482bf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482bf4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482bf5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482bf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482bf7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482bf8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482bfb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482bfd  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00482bff  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00482c01  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482c04  e8bfdfffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482c09  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00482c0c  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00482c0f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00482c12  806604fe               -and byte ptr [esi + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00482c16  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00482c19  e8c2dfffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482c1e  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00482c21  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482c23  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482c25  7422                   -je 0x482c49
    if (cpu.flags.zf)
    {
        goto L_0x00482c49;
    }
L_0x00482c27:
    // 00482c27  8a5604                 -mov dl, byte ptr [esi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00482c2a  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00482c2d  751a                   -jne 0x482c49
    if (!cpu.flags.zf)
    {
        goto L_0x00482c49;
    }
    // 00482c2f  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00482c32  750f                   -jne 0x482c43
    if (!cpu.flags.zf)
    {
        goto L_0x00482c43;
    }
    // 00482c34  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00482c36  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482c38  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482c3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482c3c  7504                   -jne 0x482c42
    if (!cpu.flags.zf)
    {
        goto L_0x00482c42;
    }
    // 00482c3e  804e0401               -or byte ptr [esi + 4], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00482c42:
    // 00482c42  43                     -inc ebx
    (cpu.ebx)++;
L_0x00482c43:
    // 00482c43  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00482c45  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482c47  75de                   -jne 0x482c27
    if (!cpu.flags.zf)
    {
        goto L_0x00482c27;
    }
L_0x00482c49:
    // 00482c49  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00482c4c  e877dfffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482c51  f6460401               +test byte ptr [esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 00482c55  741d                   -je 0x482c74
    if (cpu.flags.zf)
    {
        goto L_0x00482c74;
    }
L_0x00482c57:
    // 00482c57  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00482c5a  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00482c5d  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00482c5f  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00482c62  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00482c65  e876dfffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482c6a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482c6c  83c404                 +add esp, 4
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
    // 00482c6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482c74:
    // 00482c74  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00482c79  ebdc                   -jmp 0x482c57
    goto L_0x00482c57;
}

/* align: skip 0x90 */
void Application::sub_482c7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482c7c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482c7d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482c7f  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482c82  e841dfffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00482c87  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482c89  e866ffffff             -call 0x482bf4
    cpu.esp -= 4;
    sub_482bf4(app, cpu);
    if (cpu.terminate) return;
    // 00482c8e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482c90  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00482c93  e848dfffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00482c98  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482c9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482c9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482c9c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482c9f  e924dfffff             -jmp 0x480bc8
    return sub_480bc8(app, cpu);
}

/* align: skip  */
void Application::sub_482ca4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482ca4  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482ca7  e934dfffff             -jmp 0x480be0
    return sub_480be0(app, cpu);
}

/* align: skip  */
void Application::sub_482cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482cac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482cad  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00482caf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00482cb1  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00482cb3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00482cb5  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00482cbc  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00482cbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482cc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482cc1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00482cc3  8b4408fc               -mov eax, dword ptr [eax + ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 1);
    // 00482cc7  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00482cc9  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00482cd0  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00482cd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482cd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482cd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482cd5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00482cd7  8d4408ff               -lea eax, [eax + ecx - 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 00482cdb  83e901                 +sub ecx, 1
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
    // 00482cde  7c0d                   -jl 0x482ced
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482ced;
    }
L_0x00482ce0:
    // 00482ce0  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00482ce2  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00482ce5  83e901                 +sub ecx, 1
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
    // 00482ce8  8d40ff                 -lea eax, [eax - 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00482ceb  7df3                   -jge 0x482ce0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00482ce0;
    }
L_0x00482ced:
    // 00482ced  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482cef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482cef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482cf0  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00482cf2  83e901                 +sub ecx, 1
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
    // 00482cf5  7c0d                   -jl 0x482d04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482d04;
    }
L_0x00482cf7:
    // 00482cf7  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00482cf9  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00482cfc  83e901                 +sub ecx, 1
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
    // 00482cff  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00482d02  7df3                   -jge 0x482cf7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00482cf7;
    }
L_0x00482d04:
    // 00482d04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482d10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482daa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dbc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dbe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dcc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ddc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ebc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ebe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ecc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ece  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482edc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ede  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482ef1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482ef3  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 00482ef6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482ef7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482ef9  8a480e                 -mov cl, byte ptr [eax + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 00482efc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482efd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482eff  8a480d                 -mov cl, byte ptr [eax + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00482f02  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f03  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f05  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00482f08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f09  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f0b  8a480b                 -mov cl, byte ptr [eax + 0xb]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00482f0e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f0f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f11  8a480a                 -mov cl, byte ptr [eax + 0xa]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00482f14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f15  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f17  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 00482f1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f1b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f1d  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00482f20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f21  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f23  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00482f27  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f28  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f2a  668b4804               -mov cx, word ptr [eax + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00482f2e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f2f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00482f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f32  68b8044c00             -push 0x4c04b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981944 /*0x4c04b8*/;
    cpu.esp -= 4;
    // 00482f37  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482f38  e8a490ffff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00482f3d  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00482f40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00482ef0;
    // 00482d10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482d9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482da8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482daa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482db8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dbc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dbe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dc8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dcc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ddc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482de8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482df8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482dfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482e9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ea8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eb8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ebc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ebe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ec8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ecc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ece  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ed8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482edc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ede  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482ee8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00482eee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x00482ef0:
    // 00482ef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482ef1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482ef3  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 00482ef6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482ef7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482ef9  8a480e                 -mov cl, byte ptr [eax + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 00482efc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482efd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482eff  8a480d                 -mov cl, byte ptr [eax + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00482f02  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f03  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f05  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00482f08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f09  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f0b  8a480b                 -mov cl, byte ptr [eax + 0xb]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00482f0e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f0f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f11  8a480a                 -mov cl, byte ptr [eax + 0xa]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00482f14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f15  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f17  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 00482f1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f1b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f1d  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00482f20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f21  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f23  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00482f27  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f28  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f2a  668b4804               -mov cx, word ptr [eax + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00482f2e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f2f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00482f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f32  68b8044c00             -push 0x4c04b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981944 /*0x4c04b8*/;
    cpu.esp -= 4;
    // 00482f37  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482f38  e8a490ffff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00482f3d  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00482f40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482f44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482f44  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482f45  8b1560d25100           -mov edx, dword ptr [0x51d260]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */);
    // 00482f4b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482f4d  a38caf4c00             -mov dword ptr [0x4caf8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5025676) /* 0x4caf8c */) = cpu.eax;
    // 00482f52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482f54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482f54  a160d25100             -mov eax, dword ptr [0x51d260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */);
    // 00482f59  2b058caf4c00           -sub eax, dword ptr [0x4caf8c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5025676) /* 0x4caf8c */)));
    // 00482f5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482f61  7c06                   -jl 0x482f69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482f69;
    }
    // 00482f63  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482f68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482f69:
    // 00482f69  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482f6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482f6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482f6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f6d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482f6e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482f70  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482f72  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482f74  740e                   -je 0x482f84
    if (cpu.flags.zf)
    {
        goto L_0x00482f84;
    }
L_0x00482f76:
    // 00482f76  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482f78  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00482f7a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00482f7c  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f7e  42                     -inc edx
    (cpu.edx)++;
    // 00482f7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482f81  75f3                   -jne 0x482f76
    if (!cpu.flags.zf)
    {
        goto L_0x00482f76;
    }
    // 00482f83  90                     -nop 
    ;
L_0x00482f84:
    // 00482f84  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482f86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482f8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482f8c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f8d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482f8e  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00482f94  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482f96  899424ac000000         -mov dword ptr [esp + 0xac], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.edx;
    // 00482f9d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00482f9f  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00482fa2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482fa4  750a                   -jne 0x482fb0
    if (!cpu.flags.zf)
    {
        goto L_0x00482fb0;
    }
    // 00482fa6  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00482faa  0f851e010000           -jne 0x4830ce
    if (!cpu.flags.zf)
    {
        goto L_0x004830ce;
    }
L_0x00482fb0:
    // 00482fb0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482fb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482fb2  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00482fb7  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482fbb  e814fdffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00482fc0  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00482fc5  8d442450               -lea eax, [esp + 0x50]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00482fc9  8b5174                 -mov edx, dword ptr [ecx + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */);
    // 00482fcc  e803fdffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00482fd1  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00482fd6  8d442454               -lea eax, [esp + 0x54]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00482fda  8b5178                 -mov edx, dword ptr [ecx + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 00482fdd  e8f2fcffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00482fe2  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00482fe7  8d442458               -lea eax, [esp + 0x58]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00482feb  8b517c                 -mov edx, dword ptr [ecx + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 00482fee  e8e1fcffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00482ff3  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00482ff8  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00482ffc  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 00483002  be636564ea             -mov esi, 0xea646563
    cpu.esi = 3932448099 /*0xea646563*/;
    // 00483007  e8c8fcffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 0048300c  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00483011  8d442460               -lea eax, [esp + 0x60]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00483015  8b9184000000           -mov edx, dword ptr [ecx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0048301b  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048301f  e8b0fcffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483024  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00483029  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048302d  8b5150                 -mov edx, dword ptr [ecx + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 00483030  89b424b8000000         -mov dword ptr [esp + 0xb8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.esi;
    // 00483037  e898fcffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 0048303c  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00483041  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00483044  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00483048  8d5154                 -lea edx, [ecx + 0x54]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 0048304b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048304c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048304d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048304e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048304f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00483050  e8678fffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00483055  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00483057  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00483059:
    // 00483059  40                     -inc eax
    (cpu.eax)++;
    // 0048305a  8a9a94000000           -mov bl, byte ptr [edx + 0x94]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(148) /* 0x94 */);
    // 00483060  42                     -inc edx
    (cpu.edx)++;
    // 00483061  885c0427               -mov byte ptr [esp + eax + 0x27], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(39) /* 0x27 */ + cpu.eax * 1) = cpu.bl;
    // 00483065  83f808                 +cmp eax, 8
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
    // 00483068  7cef                   -jl 0x483059
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483059;
    }
    // 0048306a  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048306f  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00483073  8b958c000000           -mov edx, dword ptr [ebp + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 00483079  e856fcffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 0048307e  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00483083  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483085  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00483089  668b9590000000         -mov dx, word ptr [ebp + 0x90]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 00483090  e83ffcffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483095  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048309a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048309c  8d442426               -lea eax, [esp + 0x26]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(38) /* 0x26 */);
    // 004830a0  668b9592000000         -mov dx, word ptr [ebp + 0x92]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(146) /* 0x92 */);
    // 004830a7  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004830ab  e824fcffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 004830b0  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 004830b5  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 004830bc  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004830bf  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 004830c6  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004830c9  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004830cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004830ce:
    // 004830ce  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 004830d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4830d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004830d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004830d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004830da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004830db  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004830de  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004830e0  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004830e4  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004830e8  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004830ec  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004830f3  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004830f6  a188af4c00             -mov eax, dword ptr [0x4caf88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025672) /* 0x4caf88 */);
    // 004830fb  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00483100  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00483102  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483104  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00483106  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048310b  a388af4c00             -mov dword ptr [0x4caf88], eax
    app->getMemory<x86::reg32>(x86::reg32(5025672) /* 0x4caf88 */) = cpu.eax;
    // 00483110  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483112  e8bdfbffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483117  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048311a  83784400               +cmp dword ptr [eax + 0x44], 0
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
    // 0048311e  7540                   -jne 0x483160
    if (!cpu.flags.zf)
    {
        goto L_0x00483160;
    }
L_0x00483120:
    // 00483120  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00483124  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00483127  a160d25100             -mov eax, dword ptr [0x51d260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */);
    // 0048312c  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00483130  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00483132  a38caf4c00             -mov dword ptr [0x4caf8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5025676) /* 0x4caf8c */) = cpu.eax;
    // 00483137  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048313b  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0048313f  750f                   -jne 0x483150
    if (!cpu.flags.zf)
    {
        goto L_0x00483150;
    }
    // 00483141  8d471c                 -lea eax, [edi + 0x1c]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00483144  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00483147:
    // 00483147  e808feffff             -call 0x482f54
    cpu.esp -= 4;
    sub_482f54(app, cpu);
    if (cpu.terminate) return;
    // 0048314c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048314e  741d                   -je 0x48316d
    if (cpu.flags.zf)
    {
        goto L_0x0048316d;
    }
L_0x00483150:
    // 00483150  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00483157  83c410                 +add esp, 0x10
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
    // 0048315a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048315b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048315c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048315d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00483160:
    // 00483160  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00483162  8d571c                 -lea edx, [edi + 0x1c]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00483165  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00483168  ff5544                 -call dword ptr [ebp + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048316b  ebb3                   -jmp 0x483120
    goto L_0x00483120;
L_0x0048316d:
    // 0048316d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00483171  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00483175  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483179  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048317c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048317d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483181  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00483184  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483187  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483189  7406                   -je 0x483191
    if (cpu.flags.zf)
    {
        goto L_0x00483191;
    }
    // 0048318b  8b3568af4c00           -mov esi, dword ptr [0x4caf68]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5025640) /* 0x4caf68 */);
L_0x00483191:
    // 00483191  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483193  e83c6bffff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483198  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048319a  7cb4                   -jl 0x483150
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483150;
    }
    // 0048319c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004831a0  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004831a4  74a1                   -je 0x483147
    if (cpu.flags.zf)
    {
        goto L_0x00483147;
    }
    // 004831a6  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004831ad  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004831b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831b3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4831b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004831b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004831b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004831ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004831bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004831bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004831bd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004831c0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004831c2  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004831c4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004831c6  8db088000000           -lea esi, [eax + 0x88]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(136) /* 0x88 */);
L_0x004831cc:
    // 004831cc  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004831cf  8b8784000000           -mov eax, dword ptr [edi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 004831d5  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004831d8  48                     -dec eax
    (cpu.eax)--;
    // 004831d9  39c8                   +cmp eax, ecx
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
    // 004831db  7645                   -jbe 0x483222
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483222;
    }
    // 004831dd  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004831e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004831e5  8b5f50                 -mov ebx, dword ptr [edi + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 004831e8  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004831ea  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 004831ec  7509                   -jne 0x4831f7
    if (!cpu.flags.zf)
    {
        goto L_0x004831f7;
    }
L_0x004831ee:
    // 004831ee  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004831f1  42                     -inc edx
    (cpu.edx)++;
    // 004831f2  83c664                 +add esi, 0x64
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
    // 004831f5  ebd5                   -jmp 0x4831cc
    goto L_0x004831cc;
L_0x004831f7:
    // 004831f7  6b0c2464               -imul ecx, dword ptr [esp], 0x64
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 004831fb  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004831fd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004831ff  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00483202  e869edffff             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 00483207  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483209  74e3                   -je 0x4831ee
    if (cpu.flags.zf)
    {
        goto L_0x004831ee;
    }
    // 0048320b  a160af4c00             -mov eax, dword ptr [0x4caf60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */);
    // 00483210  898439e4000000         -mov dword ptr [ecx + edi + 0xe4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */ + cpu.edi * 1) = cpu.eax;
    // 00483217  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483219  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048321c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048321d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048321e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048321f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483220  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483221  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483222:
    // 00483222  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483224  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483227  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483228  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483229  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048322a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048322b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048322c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483231  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483232  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483233  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00483235  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00483237  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00483239:
    // 00483239  8b9384000000           -mov edx, dword ptr [ebx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(132) /* 0x84 */);
    // 0048323f  4a                     -dec edx
    (cpu.edx)--;
    // 00483240  39d0                   +cmp eax, edx
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
    // 00483242  7356                   -jae 0x48329a
    if (!cpu.flags.cf)
    {
        goto L_0x0048329a;
    }
    // 00483244  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00483249  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0048324b  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048324d  8b4b50                 -mov ecx, dword ptr [ebx + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */);
    // 00483250  85ca                   +test edx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.ecx));
    // 00483252  7403                   -je 0x483257
    if (cpu.flags.zf)
    {
        goto L_0x00483257;
    }
    // 00483254  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483255  ebe2                   -jmp 0x483239
    goto L_0x00483239;
L_0x00483257:
    // 00483257  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483258  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048325a  09d7                   -or edi, edx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.edx));
    // 0048325c  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00483263  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00483265  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00483268  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048326a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048326d  897b50                 -mov dword ptr [ebx + 0x50], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 00483270  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00483272  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 00483277  8dbb88000000           -lea edi, [ebx + 0x88]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(136) /* 0x88 */);
    // 0048327d  8b1560af4c00           -mov edx, dword ptr [0x4caf60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */);
    // 00483283  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00483285  8993e4000000           -mov dword ptr [ebx + 0xe4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(228) /* 0xe4 */) = cpu.edx;
    // 0048328b  8983e8000000           -mov dword ptr [ebx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 00483291  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483293  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483294  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483296  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483297  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483298  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483299  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048329a:
    // 0048329a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048329c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048329e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048329f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4832a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004832a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004832a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004832a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004832a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004832a8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004832a9  81ecc8000000           -sub esp, 0xc8
    (cpu.esp) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 004832af  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004832b1  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004832b4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004832b6  898424c4000000         -mov dword ptr [esp + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.eax;
L_0x004832bd:
    // 004832bd  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 004832c2  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 004832c7  8b8424c4000000         -mov eax, dword ptr [esp + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004832ce  899424c0000000         -mov dword ptr [esp + 0xc0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.edx;
    // 004832d5  8d9424ac000000         -lea edx, [esp + 0xac]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004832dc  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004832de  e81de3ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 004832e3  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 004832e8  8d9c24c4000000         -lea ebx, [esp + 0xc4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004832ef  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004832f2  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004832f9  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004832fc  ff5554                 -call dword ptr [ebp + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004832ff  83bc24c000000000       +cmp dword ptr [esp + 0xc0], 0
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
    // 00483307  7516                   -jne 0x48331f
    if (!cpu.flags.zf)
    {
        goto L_0x0048331f;
    }
L_0x00483309:
    // 00483309  83bc24c000000000       +cmp dword ptr [esp + 0xc0], 0
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
    // 00483311  75aa                   -jne 0x4832bd
    if (!cpu.flags.zf)
    {
        goto L_0x004832bd;
    }
    // 00483313  81c4c8000000           +add esp, 0xc8
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
    // 00483319  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048331a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048331b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048331c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048331d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048331e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048331f:
    // 0048331f  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00483321  8b9c24c0000000         -mov ebx, dword ptr [esp + 0xc0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00483328  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483329  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00483330  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483332  e805000000             -call 0x48333c
    cpu.esp -= 4;
    sub_48333c(app, cpu);
    if (cpu.terminate) return;
    // 00483337  ebd0                   -jmp 0x483309
    goto L_0x00483309;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48333c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048333c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048333d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048333e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048333f  81eccc000000           -sub esp, 0xcc
    (cpu.esp) -= x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00483345  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483347  899424c4000000         -mov dword ptr [esp + 0xc4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.edx;
    // 0048334e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00483350  898c24c8000000         -mov dword ptr [esp + 0xc8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */) = cpu.ecx;
    // 00483357  8b6810                 -mov ebp, dword ptr [eax + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048335a  81fb216f6eea           +cmp ebx, 0xea6e6f21
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
    // 00483360  7337                   -jae 0x483399
    if (!cpu.flags.cf)
    {
        goto L_0x00483399;
    }
    // 00483362  81fb657962ea           +cmp ebx, 0xea627965
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
    // 00483368  0f83de010000           -jae 0x48354c
    if (!cpu.flags.cf)
    {
        goto L_0x0048354c;
    }
    // 0048336e  81fb646461ea           +cmp ebx, 0xea616464
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
    // 00483374  7217                   -jb 0x48338d
    if (cpu.flags.cf)
    {
        goto L_0x0048338d;
    }
    // 00483376  0f87e8020000           -ja 0x483664
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00483664;
    }
    // 0048337c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048337f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483381  740a                   -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483383  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00483387  0f84ca050000           -je 0x483957
    if (cpu.flags.zf)
    {
        goto L_0x00483957;
    }
L_0x0048338d:
    // 0048338d  81c4cc000000           +add esp, 0xcc
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
    // 00483393  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483394  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483395  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483396  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00483399:
    // 00483399  76f2                   -jbe 0x48338d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 0048339b  8d451c                 -lea eax, [ebp + 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048339e  898424bc000000         -mov dword ptr [esp + 0xbc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.eax;
    // 004833a5  81fb796c70ea           +cmp ebx, 0xea706c79
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
    // 004833ab  0f8377000000           -jae 0x483428
    if (!cpu.flags.cf)
    {
        goto L_0x00483428;
    }
    // 004833b1  81fb6e706fea           +cmp ebx, 0xea6f706e
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
    // 004833b7  0f8323010000           -jae 0x4834e0
    if (!cpu.flags.cf)
    {
        goto L_0x004834e0;
    }
    // 004833bd  81fb616c6fea           +cmp ebx, 0xea6f6c61
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
    // 004833c3  75c8                   -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004833c5  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004833c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004833ca  0f8522080000           -jne 0x483bf2
    if (!cpu.flags.zf)
    {
        goto L_0x00483bf2;
    }
    // 004833d0  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
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
    // 004833d7  74b4                   -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004833d9  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
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
    // 004833e0  74ab                   -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004833e2  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 004833e9  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004833f0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004833f2  e879ebffff             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 004833f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004833f9  7492                   -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004833fb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004833fd  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00483404  a160af4c00             -mov eax, dword ptr [0x4caf60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */);
    // 00483409  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048340b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048340e  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00483414  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483416  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00483419  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048341c  81c4cc000000           +add esp, 0xcc
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
    // 00483422  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483423  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483424  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483425  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00483428:
    // 00483428  0f8642020000           -jbe 0x483670
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483670;
    }
    // 0048342e  81fb707372ea           +cmp ebx, 0xea727370
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
    // 00483434  7351                   -jae 0x483487
    if (!cpu.flags.cf)
    {
        goto L_0x00483487;
    }
    // 00483436  81fb716572ea           +cmp ebx, 0xea726571
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
    // 0048343c  0f854bffffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483442  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00483444  0f8443ffffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 0048344a  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 0048344e  0f8439ffffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483454  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00483459  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483460  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00483462  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00483464  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00483466  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048346d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048346f  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00483472  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00483474  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483476  e811fbffff             -call 0x482f8c
    cpu.esp -= 4;
    sub_482f8c(app, cpu);
    if (cpu.terminate) return;
    // 0048347b  81c4cc000000           +add esp, 0xcc
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
    // 00483481  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483482  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483483  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483484  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00483487:
    // 00483487  0f86ca060000           -jbe 0x483b57
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483b57;
    }
    // 0048348d  81fb767273ea           +cmp ebx, 0xea737276
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
    // 00483493  0f85f4feffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483499  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048349b  0f84ecfeffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004834a1  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004834a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004834a6  0f84e1feffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004834ac  8d420c                 -lea eax, [edx + 0xc]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004834af  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004834b4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004834b6  e805f1ffff             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 004834bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004834bd  0f85cafeffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004834c3  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004834ca  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004834cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004834cf  e8b8faffff             -call 0x482f8c
    cpu.esp -= 4;
    sub_482f8c(app, cpu);
    if (cpu.terminate) return;
    // 004834d4  81c4cc000000           +add esp, 0xcc
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
    // 004834da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834dd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004834e0:
    // 004834e0  773b                   -ja 0x48351d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048351d;
    }
    // 004834e2  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 004834e6  0f84a1feffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004834ec  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004834ee  ff5510                 -call dword ptr [ebp + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004834f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004834f3  0f8594feffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004834f9  bb216f6eea             -mov ebx, 0xea6e6f21
    cpu.ebx = 3933105953 /*0xea6e6f21*/;
    // 004834fe  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00483505  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483506  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00483509  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048350b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048350e  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483511  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00483517  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483518  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483519  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048351a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048351d:
    // 0048351d  81fb74756fea           +cmp ebx, 0xea6f7574
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
    // 00483523  0f8564feffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
L_0x00483529:
    // 00483529  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048352c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048352e  0f85e2060000           -jne 0x483c16
    if (!cpu.flags.zf)
    {
        goto L_0x00483c16;
    }
    // 00483534  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048353a  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00483540  81c4cc000000           +add esp, 0xcc
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
    // 00483546  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483547  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483548  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483549  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048354c:
    // 0048354c  76db                   -jbe 0x483529
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483529;
    }
    // 0048354e  81fb636564ea           +cmp ebx, 0xea646563
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
    // 00483554  734d                   -jae 0x4835a3
    if (!cpu.flags.cf)
    {
        goto L_0x004835a3;
    }
    // 00483556  81fb746164ea           +cmp ebx, 0xea646174
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
    // 0048355c  0f852bfeffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483562  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00483565  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483567  0f8596060000           -jne 0x483c03
    if (!cpu.flags.zf)
    {
        goto L_0x00483c03;
    }
    // 0048356d  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00483570  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00483572  e8f9e9ffff             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 00483577  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483579  0f840efeffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 0048357f  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
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
    // 00483586  0f8401feffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 0048358c  a164af4c00             -mov eax, dword ptr [0x4caf64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025636) /* 0x4caf64 */);
    // 00483591  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00483597  81c4cc000000           +add esp, 0xcc
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
    // 0048359d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048359e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048359f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835a0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004835a3:
    // 004835a3  0f8646010000           -jbe 0x4836ef
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004836ef;
    }
    // 004835a9  81fb746567ea           +cmp ebx, 0xea676574
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
    // 004835af  0f85d8fdffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004835b5  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 004835b9  0f84cefdffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004835bf  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004835c1  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004835c5  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004835c8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004835c9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004835ca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004835cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004835cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004835cd  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004835cf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004835d2  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004835d5  bb796c70ea             -mov ebx, 0xea706c79
    cpu.ebx = 3933236345 /*0xea706c79*/;
    // 004835da  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004835de  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004835e5  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004835ea  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004835ed  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 004835f2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004835f4  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004835f6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004835f8  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004835ff  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00483601  83f8ff                 +cmp eax, -1
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
    // 00483604  0f84bc020000           -je 0x4838c6
    if (cpu.flags.zf)
    {
        goto L_0x004838c6;
    }
    // 0048360a  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0048360f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00483611  d3e7                   +shl edi, cl
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
    // 00483613  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00483616  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00483618  854e50                 -test dword ptr [esi + 0x50], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) & cpu.ecx));
    // 0048361b  0f84b6020000           -je 0x4838d7
    if (cpu.flags.zf)
    {
        goto L_0x004838d7;
    }
    // 00483621  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00483623  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483625  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00483628  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048362a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048362d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048362f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00483632  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00483634  8d7c241c               -lea edi, [esp + 0x1c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00483638  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 0048363d  8db088000000           -lea esi, [eax + 0x88]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(136) /* 0x88 */);
L_0x00483643:
    // 00483643  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x00483645:
    // 00483645  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00483647  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483648  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048364b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048364e  8b9424c8000000         -mov edx, dword ptr [esp + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483655  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483658  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0048365e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048365f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483660  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483661  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00483664:
    // 00483664  81fb646162ea           +cmp ebx, 0xea626164
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
    // 0048366a  0f851dfdffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
L_0x00483670:
    // 00483670  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00483673  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048367a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048367c  e8efe8ffff             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 00483681  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483683  0f8404fdffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483689  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
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
    // 00483690  740b                   -je 0x48369d
    if (cpu.flags.zf)
    {
        goto L_0x0048369d;
    }
    // 00483692  a164af4c00             -mov eax, dword ptr [0x4caf64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025636) /* 0x4caf64 */);
    // 00483697  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
L_0x0048369d:
    // 0048369d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004836a2  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004836a9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004836ab  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004836ad  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004836af  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004836b6  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004836b8  837e1800               +cmp dword ptr [esi + 0x18], 0
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
    // 004836bc  0f84cbfcffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004836c2  3b06                   +cmp eax, dword ptr [esi]
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
    // 004836c4  0f85c3fcffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004836ca  81ff796c70ea           +cmp edi, 0xea706c79
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
    // 004836d0  0f840e020000           -je 0x4838e4
    if (cpu.flags.zf)
    {
        goto L_0x004838e4;
    }
L_0x004836d6:
    // 004836d6  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004836dd  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004836e3  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004836e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004836ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004836eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004836ec  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004836ef:
    // 004836ef  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004836f4  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004836fb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004836fd  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004836ff  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00483701  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00483708  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048370a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048370c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048370e  0f85a4010000           -jne 0x4838b8
    if (!cpu.flags.zf)
    {
        goto L_0x004838b8;
    }
    // 00483714  833e00                 +cmp dword ptr [esi], 0
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
    // 00483717  0f859b010000           -jne 0x4838b8
    if (!cpu.flags.zf)
    {
        goto L_0x004838b8;
    }
    // 0048371d  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 00483721  0f8491010000           -je 0x4838b8
    if (cpu.flags.zf)
    {
        goto L_0x004838b8;
    }
    // 00483727  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048372c:
    // 0048372c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048372e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483730  753c                   -jne 0x48376e
    if (!cpu.flags.zf)
    {
        goto L_0x0048376e;
    }
    // 00483732  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 00483736  0f8583010000           -jne 0x4838bf
    if (!cpu.flags.zf)
    {
        goto L_0x004838bf;
    }
    // 0048373c  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0048373e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00483740  0f8479010000           -je 0x4838bf
    if (cpu.flags.zf)
    {
        goto L_0x004838bf;
    }
    // 00483746  39fa                   +cmp edx, edi
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
    // 00483748  0f8571010000           -jne 0x4838bf
    if (!cpu.flags.zf)
    {
        goto L_0x004838bf;
    }
    // 0048374e  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00483751  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00483758  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048375a  e811e8ffff             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 0048375f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483761  0f8458010000           -je 0x4838bf
    if (cpu.flags.zf)
    {
        goto L_0x004838bf;
    }
    // 00483767  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048376c:
    // 0048376c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048376e:
    // 0048376e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483770  0f8417fcffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483776  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
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
    // 0048377d  7411                   -je 0x483790
    if (cpu.flags.zf)
    {
        goto L_0x00483790;
    }
    // 0048377f  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 00483783  750b                   -jne 0x483790
    if (!cpu.flags.zf)
    {
        goto L_0x00483790;
    }
    // 00483785  a164af4c00             -mov eax, dword ptr [0x4caf64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025636) /* 0x4caf64 */);
    // 0048378a  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
L_0x00483790:
    // 00483790  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483797  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048379c  83c048                 -add eax, 0x48
    (cpu.eax) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0048379f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004837a1  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004837a3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004837a5  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004837ac  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004837ae  89463c                 -mov dword ptr [esi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004837b1  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004837b8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004837bd  83c04c                 -add eax, 0x4c
    (cpu.eax) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004837c0  8b9424c8000000         -mov edx, dword ptr [esp + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004837c7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004837c9  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004837cb  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004837cd  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004837d4  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004837d6  894640                 -mov dword ptr [esi + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004837d9  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004837e0  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004837e5  83c050                 -add eax, 0x50
    (cpu.eax) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004837e8  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004837ed  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004837ef  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004837f1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004837f3  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004837fa  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004837fc  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 004837ff  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483806  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048380b  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0048380e  8d7e1c                 -lea edi, [esi + 0x1c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00483811  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00483813  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00483815  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00483817  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048381e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00483820  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00483823  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0048382a  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048382f  83c058                 -add eax, 0x58
    (cpu.eax) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00483832  83c228                 -add edx, 0x28
    (cpu.edx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00483835  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00483837  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00483839  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048383b  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00483842  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00483844  89464c                 -mov dword ptr [esi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00483847  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483849  e86e87ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0048384e  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483855  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048385a  83c06c                 -add eax, 0x6c
    (cpu.eax) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048385d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048385f  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00483861  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00483863  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048386a  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048386c  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00483873  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00483876  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00483879  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048387b  0f840cfbffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483881  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483888  8b406c                 -mov eax, dword ptr [eax + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 0048388b  8b8c24c4000000         -mov ecx, dword ptr [esp + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00483892  e8d5f6ffff             -call 0x482f6c
    cpu.esp -= 4;
    sub_482f6c(app, cpu);
    if (cpu.terminate) return;
    // 00483897  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048389a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048389c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048389e  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004838a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004838a3  0f85e4faffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 004838a9  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004838ac  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004838b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838b5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004838b8:
    // 004838b8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004838ba  e96dfeffff             -jmp 0x48372c
    goto L_0x0048372c;
L_0x004838bf:
    // 004838bf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004838c1  e9a6feffff             -jmp 0x48376c
    goto L_0x0048376c;
L_0x004838c6:
    // 004838c6  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 004838cb  8d7c241c               -lea edi, [esp + 0x1c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004838cf  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 004838d2  e96cfdffff             -jmp 0x483643
    goto L_0x00483643;
L_0x004838d7:
    // 004838d7  bb646162ea             -mov ebx, 0xea626164
    cpu.ebx = 3932316004 /*0xea626164*/;
    // 004838dc  83ea5c                 +sub edx, 0x5c
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
    // 004838df  e961fdffff             -jmp 0x483645
    goto L_0x00483645;
L_0x004838e4:
    // 004838e4  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004838eb  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004838f0  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004838f3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004838f5  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004838f7  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004838f9  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00483900  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00483902  83f8ff                 +cmp eax, -1
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
    // 00483905  754c                   -jne 0x483953
    if (!cpu.flags.zf)
    {
        goto L_0x00483953;
    }
    // 00483907  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0048390c:
    // 0048390c  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483913  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00483918  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048391b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048391d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048391f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00483921  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00483928  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048392a  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048392d  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483934  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00483936  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483939  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048393c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048393e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483940  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483943  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483945  0f858bfdffff           -jne 0x4836d6
    if (!cpu.flags.zf)
    {
        goto L_0x004836d6;
    }
    // 0048394b  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048394e  e983fdffff             -jmp 0x4836d6
    goto L_0x004836d6;
L_0x00483953:
    // 00483953  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00483955  ebb5                   -jmp 0x48390c
    goto L_0x0048390c;
L_0x00483957:
    // 00483957  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0048395e  bb707372ea             -mov ebx, 0xea727370
    cpu.ebx = 3933369200 /*0xea727370*/;
    // 00483963  e850f8ffff             -call 0x4831b8
    cpu.esp -= 4;
    sub_4831b8(app, cpu);
    if (cpu.terminate) return;
    // 00483968  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048396a  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483971  be20000000             -mov esi, 0x20
    cpu.esi = 32 /*0x20*/;
    // 00483976  899c24b4000000         -mov dword ptr [esp + 0xb4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.ebx;
    // 0048397d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048397f  89b424b0000000         -mov dword ptr [esp + 0xb0], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.esi;
    // 00483986  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00483989  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048398b  0f8584010000           -jne 0x483b15
    if (!cpu.flags.zf)
    {
        goto L_0x00483b15;
    }
    // 00483991  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00483994  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 0048399a  8b4050                 -mov eax, dword ptr [eax + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048399d  4a                     -dec edx
    (cpu.edx)--;
    // 0048399e  e8c9f5ffff             -call 0x482f6c
    cpu.esp -= 4;
    sub_482f6c(app, cpu);
    if (cpu.terminate) return;
    // 004839a3  39d0                   +cmp eax, edx
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
    // 004839a5  0f8352010000           -jae 0x483afd
    if (!cpu.flags.cf)
    {
        goto L_0x00483afd;
    }
    // 004839ab  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004839ae  80783c00               +cmp byte ptr [eax + 0x3c], 0
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
    // 004839b2  0f85be000000           -jne 0x483a76
    if (!cpu.flags.zf)
    {
        goto L_0x00483a76;
    }
L_0x004839b8:
    // 004839b8  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004839bf  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004839c2  898424b8000000         -mov dword ptr [esp + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 004839c9  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004839d0  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 004839d7  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004839da  8bb424c4000000         -mov esi, dword ptr [esp + 0xc4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004839e1  e84af8ffff             -call 0x483230
    cpu.esp -= 4;
    sub_483230(app, cpu);
    if (cpu.terminate) return;
    // 004839e6  8d7f28                 -lea edi, [edi + 0x28]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004839e9  898424c0000000         -mov dword ptr [esp + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 004839f0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004839f1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004839f2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004839f3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004839f4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004839f5  898424ac000000         -mov dword ptr [esp + 0xac], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 004839fc  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004839ff  83784c00               +cmp dword ptr [eax + 0x4c], 0
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
    // 00483a03  0f85a1000000           -jne 0x483aaa
    if (!cpu.flags.zf)
    {
        goto L_0x00483aaa;
    }
L_0x00483a09:
    // 00483a09  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00483a0e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00483a13  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00483a17  e8b8f2ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483a1c  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00483a21  8b9424ac000000         -mov edx, dword ptr [esp + 0xac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00483a28  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00483a2c  e8a3f2ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483a31  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483a38  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00483a3d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483a41  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483a44  e8b7dbffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
L_0x00483a49:
    // 00483a49  8b9c24b0000000         -mov ebx, dword ptr [esp + 0xb0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00483a50  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00483a52  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00483a59  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00483a5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483a5d  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00483a60  8b9c24b8000000         -mov ebx, dword ptr [esp + 0xb8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00483a67  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483a6a  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00483a70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a73  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00483a76:
    // 00483a76  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00483a7b  8b9424c8000000         -mov edx, dword ptr [esp + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483a82  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00483a85  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00483a88  e833ebffff             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 00483a8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483a8f  0f8423ffffff           -je 0x4839b8
    if (cpu.flags.zf)
    {
        goto L_0x004839b8;
    }
    // 00483a95  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00483a9a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00483a9f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00483aa3  e82cf2ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483aa8  eb9f                   -jmp 0x483a49
    goto L_0x00483a49;
L_0x00483aaa:
    // 00483aaa  8b9c24c0000000         -mov ebx, dword ptr [esp + 0xc0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00483ab1  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00483ab8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483aba  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483abc  43                     -inc ebx
    (cpu.ebx)++;
    // 00483abd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00483abf  ff564c                 -call dword ptr [esi + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483ac2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483ac4  0f853fffffff           -jne 0x483a09
    if (!cpu.flags.zf)
    {
        goto L_0x00483a09;
    }
    // 00483aca  8a8c24c0000000         -mov cl, byte ptr [esp + 0xc0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00483ad1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00483ad6  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00483ad8  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00483adb  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00483add  8b4850                 -mov ecx, dword ptr [eax + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00483ae0  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00483ae5  21d1                   +and ecx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00483ae7  bafdffffff             -mov edx, 0xfffffffd
    cpu.edx = 4294967293 /*0xfffffffd*/;
    // 00483aec  894850                 -mov dword ptr [eax + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 00483aef  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00483af3  e8dcf1ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483af8  e94cffffff             -jmp 0x483a49
    goto L_0x00483a49;
L_0x00483afd:
    // 00483afd  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00483b02  bafeffffff             -mov edx, 0xfffffffe
    cpu.edx = 4294967294 /*0xfffffffe*/;
    // 00483b07  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00483b0b  e8c4f1ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483b10  e934ffffff             -jmp 0x483a49
    goto L_0x00483a49;
L_0x00483b15:
    // 00483b15  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00483b1a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00483b1f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00483b23  e8acf1ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483b28  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00483b2b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00483b2d  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00483b32  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00483b34  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00483b39  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483b3b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00483b3e  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00483b40  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00483b45  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00483b49  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483b4b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483b4d  e882f1ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483b52  e9f2feffff             -jmp 0x483a49
    goto L_0x00483a49;
L_0x00483b57:
    // 00483b57  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00483b59  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00483b5b  e810e4ffff             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 00483b60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483b62  0f8425f8ffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483b68  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00483b6d  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483b74  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00483b76  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00483b78  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00483b7a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00483b81  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00483b83  3b06                   +cmp eax, dword ptr [esi]
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
    // 00483b85  0f8502f8ffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483b8b  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483b92  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00483b97  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00483b9a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00483b9c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00483b9e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00483ba0  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00483ba7  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00483ba9  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00483bac  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00483baf  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00483bb5  83fb01                 +cmp ebx, 1
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
    // 00483bb8  0f85cff7ffff           -jne 0x48338d
    if (!cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483bbe  8bb424c8000000         -mov esi, dword ptr [esp + 0xc8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00483bc5  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00483bc8  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00483bcb  a160af4c00             -mov eax, dword ptr [0x4caf60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */);
    // 00483bd0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00483bd1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00483bd2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00483bd3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00483bd4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00483bd5  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00483bdb  a164af4c00             -mov eax, dword ptr [0x4caf64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025636) /* 0x4caf64 */);
    // 00483be0  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00483be6  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00483bec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bef  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00483bf2:
    // 00483bf2  e8c1f5ffff             -call 0x4831b8
    cpu.esp -= 4;
    sub_4831b8(app, cpu);
    if (cpu.terminate) return;
    // 00483bf7  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00483bfd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bfe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c00  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00483c03:
    // 00483c03  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483c05  e8aef5ffff             -call 0x4831b8
    cpu.esp -= 4;
    sub_4831b8(app, cpu);
    if (cpu.terminate) return;
    // 00483c0a  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00483c10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c13  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00483c16:
    // 00483c16  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00483c1d  e896f5ffff             -call 0x4831b8
    cpu.esp -= 4;
    sub_4831b8(app, cpu);
    if (cpu.terminate) return;
    // 00483c22  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483c24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483c26  0f8461f7ffff           -je 0x48338d
    if (cpu.flags.zf)
    {
        goto L_0x0048338d;
    }
    // 00483c2c  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00483c2f  8d9788000000           -lea edx, [edi + 0x88]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(136) /* 0x88 */);
    // 00483c35  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00483c37  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483c39  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00483c3e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00483c41  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00483c43  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00483c45  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483c4a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00483c4c  8b5750                 -mov edx, dword ptr [edi + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 00483c4f  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00483c51  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00483c53  895750                 -mov dword ptr [edi + 0x50], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 00483c56  c7465c00000000         -mov dword ptr [esi + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 00483c5d  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00483c63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c66  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483c6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483c6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483c6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483c6e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483c6f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483c70  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483c71  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00483c74  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00483c77  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483c79  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 00483c7d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483c7f  0f8559010000           -jne 0x483dde
    if (!cpu.flags.zf)
    {
        goto L_0x00483dde;
    }
    // 00483c85  83b8a800000000         +cmp dword ptr [eax + 0xa8], 0
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
    // 00483c8c  7547                   -jne 0x483cd5
    if (!cpu.flags.zf)
    {
        goto L_0x00483cd5;
    }
    // 00483c8e  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 00483c92  7441                   -je 0x483cd5
    if (cpu.flags.zf)
    {
        goto L_0x00483cd5;
    }
    // 00483c94  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00483c99  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00483c9b  be102d4800             -mov esi, 0x482d10
    cpu.esi = 4730128 /*0x482d10*/;
    // 00483ca0  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00483ca3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00483ca5  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00483ca9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483cab  7502                   -jne 0x483caf
    if (!cpu.flags.zf)
    {
        goto L_0x00483caf;
    }
    // 00483cad  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
L_0x00483caf:
    // 00483caf  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00483cb3  e8ecf5ffff             -call 0x4832a4
    cpu.esp -= 4;
    sub_4832a4(app, cpu);
    if (cpu.terminate) return;
    // 00483cb8  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00483cbc  8bb8a4000000           -mov edi, dword ptr [eax + 0xa4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 00483cc2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00483cc4  740f                   -je 0x483cd5
    if (cpu.flags.zf)
    {
        goto L_0x00483cd5;
    }
    // 00483cc6  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 00483cca  7509                   -jne 0x483cd5
    if (!cpu.flags.zf)
    {
        goto L_0x00483cd5;
    }
    // 00483ccc  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00483ccf  8990a4000000           -mov dword ptr [eax + 0xa4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = cpu.edx;
L_0x00483cd5:
    // 00483cd5  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00483cd9  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00483cdc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483cde  0f84fa000000           -je 0x483dde
    if (cpu.flags.zf)
    {
        goto L_0x00483dde;
    }
    // 00483ce4  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00483ce7  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00483ce9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483ceb  0f85ed000000           -jne 0x483dde
    if (!cpu.flags.zf)
    {
        goto L_0x00483dde;
    }
    // 00483cf1  83795000               +cmp dword ptr [ecx + 0x50], 0
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
    // 00483cf5  0f84e3000000           -je 0x483dde
    if (cpu.flags.zf)
    {
        goto L_0x00483dde;
    }
    // 00483cfb  c7442450616c6fea       -mov dword ptr [esp + 0x50], 0xea6f6c61
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = 3933170785 /*0xea6f6c61*/;
    // 00483d03  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00483d07  8b90a0000000           -mov edx, dword ptr [eax + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 00483d0d  895c2458               -mov dword ptr [esp + 0x58], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.ebx;
    // 00483d11  83fa02                 +cmp edx, 2
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
    // 00483d14  7c4e                   -jl 0x483d64
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483d64;
    }
    // 00483d16  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00483d19  8988a0000000           -mov dword ptr [eax + 0xa0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */) = cpu.ecx;
L_0x00483d1f:
    // 00483d1f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00483d21  8d8688000000           -lea eax, [esi + 0x88]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 00483d27  897c2460               -mov dword ptr [esp + 0x60], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edi;
    // 00483d2b  89442454               -mov dword ptr [esp + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00483d2f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x00483d31:
    // 00483d31  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00483d37  8b6c2460               -mov ebp, dword ptr [esp + 0x60]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00483d3b  48                     -dec eax
    (cpu.eax)--;
    // 00483d3c  39e8                   +cmp eax, ebp
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
    // 00483d3e  0f869a000000           -jbe 0x483dde
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483dde;
    }
    // 00483d44  8a4c2460               -mov cl, byte ptr [esp + 0x60]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00483d48  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483d4d  8b5650                 -mov edx, dword ptr [esi + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 00483d50  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00483d52  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 00483d54  7528                   -jne 0x483d7e
    if (!cpu.flags.zf)
    {
        goto L_0x00483d7e;
    }
L_0x00483d56:
    // 00483d56  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00483d5a  41                     -inc ecx
    (cpu.ecx)++;
    // 00483d5b  83c764                 +add edi, 0x64
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
    // 00483d5e  894c2460               -mov dword ptr [esp + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 00483d62  ebcd                   -jmp 0x483d31
    goto L_0x00483d31;
L_0x00483d64:
    // 00483d64  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00483d68  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00483d6d  a164af4c00             -mov eax, dword ptr [0x4caf64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025636) /* 0x4caf64 */);
    // 00483d72  895c2458               -mov dword ptr [esp + 0x58], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.ebx;
    // 00483d76  8982a0000000           -mov dword ptr [edx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00483d7c  eba1                   -jmp 0x483d1f
    goto L_0x00483d1f;
L_0x00483d7e:
    // 00483d7e  6bcd64                 -imul ecx, ebp, 0x64
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 00483d81  8b97e4000000           -mov edx, dword ptr [edi + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(228) /* 0xe4 */);
    // 00483d87  8d6aff                 -lea ebp, [edx - 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00483d8a  89afe4000000           -mov dword ptr [edi + 0xe4], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(228) /* 0xe4 */) = cpu.ebp;
    // 00483d90  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483d92  7513                   -jne 0x483da7
    if (!cpu.flags.zf)
    {
        goto L_0x00483da7;
    }
    // 00483d94  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00483d96  214650                 -and dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) &= x86::reg32(x86::sreg32(cpu.eax));
    // 00483d99  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00483d9d  41                     -inc ecx
    (cpu.ecx)++;
    // 00483d9e  83c764                 +add edi, 0x64
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
    // 00483da1  894c2460               -mov dword ptr [esp + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 00483da5  eb8a                   -jmp 0x483d31
    goto L_0x00483d31;
L_0x00483da7:
    // 00483da7  837c245800             +cmp dword ptr [esp + 0x58], 0
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
    // 00483dac  74a8                   -je 0x483d56
    if (cpu.flags.zf)
    {
        goto L_0x00483d56;
    }
    // 00483dae  8b6c245c               -mov ebp, dword ptr [esp + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00483db2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483db4  8b542458               -mov edx, dword ptr [esp + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00483db8  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00483dbc  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00483dc0  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00483dc3  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00483dc6  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00483dc8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483dca  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483dcd  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00483dd1  41                     -inc ecx
    (cpu.ecx)++;
    // 00483dd2  83c764                 +add edi, 0x64
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
    // 00483dd5  894c2460               -mov dword ptr [esp + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 00483dd9  e953ffffff             -jmp 0x483d31
    goto L_0x00483d31;
L_0x00483dde:
    // 00483dde  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483de3  83c464                 -add esp, 0x64
    (cpu.esp) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00483de6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483de7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483de8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483de9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483deb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483dec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483dec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483ded  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483dee  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00483df3  ba6c3c4800             -mov edx, 0x483c6c
    cpu.edx = 4734060 /*0x483c6c*/;
    // 00483df8  b8d4dd5100             -mov eax, 0x51ddd4
    cpu.eax = 5365204 /*0x51ddd4*/;
    // 00483dfd  e8f2edffff             -call 0x482bf4
    cpu.esp -= 4;
    sub_482bf4(app, cpu);
    if (cpu.terminate) return;
    // 00483e02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483e08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483e08  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483e09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483e0a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483e0c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00483e0e  8b1590af4c00           -mov edx, dword ptr [0x4caf90]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025680) /* 0x4caf90 */);
    // 00483e14  42                     -inc edx
    (cpu.edx)++;
    // 00483e15  891590af4c00           -mov dword ptr [0x4caf90], edx
    app->getMemory<x86::reg32>(x86::reg32(5025680) /* 0x4caf90 */) = cpu.edx;
    // 00483e1b  83fa01                 +cmp edx, 1
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
    // 00483e1e  7514                   -jne 0x483e34
    if (!cpu.flags.zf)
    {
        goto L_0x00483e34;
    }
    // 00483e20  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00483e23  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483e26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483e28  741b                   -je 0x483e45
    if (cpu.flags.zf)
    {
        goto L_0x00483e45;
    }
    // 00483e2a  b8ec3d4800             -mov eax, 0x483dec
    cpu.eax = 4734444 /*0x483dec*/;
    // 00483e2f  e8003b0100             -call 0x497934
    cpu.esp -= 4;
    sub_497934(app, cpu);
    if (cpu.terminate) return;
L_0x00483e34:
    // 00483e34  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00483e37  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483e39  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483e3b  ff531c                 -call dword ptr [ebx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483e3e  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00483e41  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483e43  7505                   -jne 0x483e4a
    if (!cpu.flags.zf)
    {
        goto L_0x00483e4a;
    }
L_0x00483e45:
    // 00483e45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e47  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00483e4a:
    // 00483e4a  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00483e4d  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00483e50  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00483e55  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483e58  8d968c000000           -lea edx, [esi + 0x8c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00483e5e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483e60  c7869c00000001000000   -mov dword ptr [esi + 0x9c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 00483e6a  e891d7ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00483e6f  bb33000000             -mov ebx, 0x33
    cpu.ebx = 51 /*0x33*/;
    // 00483e74  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00483e78  8d4644                 -lea eax, [esi + 0x44]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00483e7b  e83c81ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00483e80  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 00483e85  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00483e89  8d4678                 -lea eax, [esi + 0x78]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00483e8c  e82b81ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00483e91  b8fa000000             -mov eax, 0xfa
    cpu.eax = 250 /*0xfa*/;
    // 00483e96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e98  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_483e9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483e9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483e9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483e9e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483e9f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483ea0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483ea1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483ea3  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00483ea6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00483eab  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483ead  745b                   -je 0x483f0a
    if (cpu.flags.zf)
    {
        goto L_0x00483f0a;
    }
    // 00483eaf  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 00483eb3  7509                   -jne 0x483ebe
    if (!cpu.flags.zf)
    {
        goto L_0x00483ebe;
    }
    // 00483eb5  83b8a000000000         +cmp dword ptr [eax + 0xa0], 0
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
    // 00483ebc  7409                   -je 0x483ec7
    if (cpu.flags.zf)
    {
        goto L_0x00483ec7;
    }
L_0x00483ebe:
    // 00483ebe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483ec0  e847e0ffff             -call 0x481f0c
    cpu.esp -= 4;
    sub_481f0c(app, cpu);
    if (cpu.terminate) return;
    // 00483ec5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00483ec7:
    // 00483ec7  8baaa8000000           -mov ebp, dword ptr [edx + 0xa8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 00483ecd  c7829c00000000000000   -mov dword ptr [edx + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 00483ed7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00483ed9  7411                   -je 0x483eec
    if (cpu.flags.zf)
    {
        goto L_0x00483eec;
    }
    // 00483edb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00483edd:
    // 00483edd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483edf  e85c5dffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00483ee4  3bb2a8000000           +cmp esi, dword ptr [edx + 0xa8]
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
    // 00483eea  75f1                   -jne 0x483edd
    if (!cpu.flags.zf)
    {
        goto L_0x00483edd;
    }
L_0x00483eec:
    // 00483eec  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00483eef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00483ef1  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00483ef8  ff5620                 -call dword ptr [esi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483efb  8b1d90af4c00           -mov ebx, dword ptr [0x4caf90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5025680) /* 0x4caf90 */);
    // 00483f01  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483f02  891d90af4c00           -mov dword ptr [0x4caf90], ebx
    app->getMemory<x86::reg32>(x86::reg32(5025680) /* 0x4caf90 */) = cpu.ebx;
    // 00483f08  7408                   -je 0x483f12
    if (cpu.flags.zf)
    {
        goto L_0x00483f12;
    }
L_0x00483f0a:
    // 00483f0a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483f0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f0e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483f12:
    // 00483f12  b8ec3d4800             -mov eax, 0x483dec
    cpu.eax = 4734444 /*0x483dec*/;
    // 00483f17  e8803a0100             -call 0x49799c
    cpu.esp -= 4;
    sub_49799c(app, cpu);
    if (cpu.terminate) return;
    // 00483f1c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00483f1f  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483f22  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483f24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483f26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483f2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f2c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483f2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483f2e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483f2f  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00483f35  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00483f37  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 00483f3e  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 00483f45  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00483f47  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00483f4c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00483f4e  be602d4800             -mov esi, 0x482d60
    cpu.esi = 4730208 /*0x482d60*/;
    // 00483f53  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00483f57  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00483f5c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00483f5e  e88defffff             -call 0x482ef0
    cpu.esp -= 4;
    sub_482ef0(app, cpu);
    if (cpu.terminate) return;
    // 00483f63  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00483f6a  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00483f6e  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00483f72  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483f74  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00483f78  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00483f7b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00483f7d  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00483f80  a160d25100             -mov eax, dword ptr [0x51d260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */);
    // 00483f85  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00483f8c  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00483f91  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00483f93  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483f95  a38caf4c00             -mov dword ptr [0x4caf8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5025676) /* 0x4caf8c */) = cpu.eax;
L_0x00483f9a:
    // 00483f9a  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00483f9d  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00483fa1  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00483fa4  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483fa7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00483fa9:
    // 00483fa9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483fab  e8245dffff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 00483fb0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483fb2  7d1d                   -jge 0x483fd1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483fd1;
    }
L_0x00483fb4:
    // 00483fb4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483fb6  752a                   -jne 0x483fe2
    if (!cpu.flags.zf)
    {
        goto L_0x00483fe2;
    }
    // 00483fb8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483fba  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00483fc1  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00483fc7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483fc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483fc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483fca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483fcb:
    // 00483fcb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483fcd  74cb                   -je 0x483f9a
    if (cpu.flags.zf)
    {
        goto L_0x00483f9a;
    }
    // 00483fcf  ebd8                   -jmp 0x483fa9
    goto L_0x00483fa9;
L_0x00483fd1:
    // 00483fd1  e87eefffff             -call 0x482f54
    cpu.esp -= 4;
    sub_482f54(app, cpu);
    if (cpu.terminate) return;
    // 00483fd6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483fd8  75da                   -jne 0x483fb4
    if (!cpu.flags.zf)
    {
        goto L_0x00483fb4;
    }
    // 00483fda  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
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
    // 00483fde  75eb                   -jne 0x483fcb
    if (!cpu.flags.zf)
    {
        goto L_0x00483fcb;
    }
    // 00483fe0  ebd2                   -jmp 0x483fb4
    goto L_0x00483fb4;
L_0x00483fe2:
    // 00483fe2  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00483fe5  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00483fe8  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483feb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483fed  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00483ff4  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00483ffa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ffb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ffc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ffd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484000  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484001  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484002  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484003  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484004  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048400a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048400c  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 00484013  899c24fc000000         -mov dword ptr [esp + 0xfc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.ebx;
    // 0048401a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0048401f  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00484026  beb02d4800             -mov esi, 0x482db0
    cpu.esi = 4730288 /*0x482db0*/;
    // 0048402b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048402d  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
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
    // 00484034  0f857e000000           -jne 0x4840b8
    if (!cpu.flags.zf)
    {
        goto L_0x004840b8;
    }
L_0x0048403a:
    // 0048403a  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 0048403f  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00484043  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00484046  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484048  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048404c  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00484053  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484054  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484055  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484056  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484057  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484058  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048405f  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484062  8b8c24fc000000         -mov ecx, dword ptr [esp + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 00484069  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048406a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048406b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048406c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048406d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048406e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00484070  7476                   -je 0x4840e8
    if (cpu.flags.zf)
    {
        goto L_0x004840e8;
    }
    // 00484072  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00484077  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048407b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048407d  e83a7fffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
L_0x00484082:
    // 00484082  a120a44c00             -mov eax, dword ptr [0x4ca420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00484087  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484089  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048408a  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048408e  bb646461ea             -mov ebx, 0xea616464
    cpu.ebx = 3932251236 /*0xea616464*/;
    // 00484093  6888000000             -push 0x88
    app->getMemory<x86::reg32>(cpu.esp-4) = 136 /*0x88*/;
    cpu.esp -= 4;
    // 00484098  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0048409f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004840a1  e832f0ffff             -call 0x4830d8
    cpu.esp -= 4;
    sub_4830d8(app, cpu);
    if (cpu.terminate) return;
    // 004840a6  8b8424b0000000         -mov eax, dword ptr [esp + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
L_0x004840ad:
    // 004840ad  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004840b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004840b8:
    // 004840b8  8b9c2400010000         -mov ebx, dword ptr [esp + 0x100]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004840bf  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004840c2  e8a9deffff             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 004840c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004840c9  7407                   -je 0x4840d2
    if (cpu.flags.zf)
    {
        goto L_0x004840d2;
    }
    // 004840cb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004840d0  ebdb                   -jmp 0x4840ad
    goto L_0x004840ad;
L_0x004840d2:
    // 004840d2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004840d4  e833deffff             -call 0x481f0c
    cpu.esp -= 4;
    sub_481f0c(app, cpu);
    if (cpu.terminate) return;
    // 004840d9  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 004840e3  e952ffffff             -jmp 0x48403a
    goto L_0x0048403a;
L_0x004840e8:
    // 004840e8  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004840eb  c6403c00               -mov byte ptr [eax + 0x3c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 004840ef  eb91                   -jmp 0x484082
    goto L_0x00484082;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4840f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004840f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004840f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004840f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004840f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004840f8  81ecfc000000           -sub esp, 0xfc
    (cpu.esp) -= x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 004840fe  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00484100  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00484105  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048410c  be002e4800             -mov esi, 0x482e00
    cpu.esi = 4730368 /*0x482e00*/;
    // 00484111  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484113  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484115  7554                   -jne 0x48416b
    if (!cpu.flags.zf)
    {
        goto L_0x0048416b;
    }
    // 00484117  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
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
    // 0048411e  744b                   -je 0x48416b
    if (cpu.flags.zf)
    {
        goto L_0x0048416b;
    }
L_0x00484120:
    // 00484120  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00484126  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484128  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048412a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048412b  bb716572ea             -mov ebx, 0xea726571
    cpu.ebx = 3933365617 /*0xea726571*/;
    // 00484130  8db424cc000000         -lea esi, [esp + 0xcc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00484137  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 0048413c  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00484143  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00484145  e88eefffff             -call 0x4830d8
    cpu.esp -= 4;
    sub_4830d8(app, cpu);
    if (cpu.terminate) return;
    // 0048414a  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 0048414f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484151  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
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
    // 00484159  7429                   -je 0x484184
    if (cpu.flags.zf)
    {
        goto L_0x00484184;
    }
    // 0048415b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484160  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 00484166  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484167  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484168  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484169  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048416a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048416b:
    // 0048416b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048416d  7415                   -je 0x484184
    if (cpu.flags.zf)
    {
        goto L_0x00484184;
    }
    // 0048416f  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
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
    // 00484176  750c                   -jne 0x484184
    if (!cpu.flags.zf)
    {
        goto L_0x00484184;
    }
    // 00484178  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048417a  8d781c                 -lea edi, [eax + 0x1c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048417d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048417e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048417f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484180  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484181  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484182  eb9c                   -jmp 0x484120
    goto L_0x00484120;
L_0x00484184:
    // 00484184  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484186  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 0048418c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048418d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048418e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048418f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484190  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484194(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484194  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484195  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484196  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484197  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048419a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048419c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048419e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004841a2  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004841a5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004841a7  8b4e30                 -mov ecx, dword ptr [esi + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004841aa  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004841ae  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004841b0  0f84e6000000           -je 0x48429c
    if (cpu.flags.zf)
    {
        goto L_0x0048429c;
    }
L_0x004841b6:
    // 004841b6  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
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
    // 004841bd  7411                   -je 0x4841d0
    if (cpu.flags.zf)
    {
        goto L_0x004841d0;
    }
    // 004841bf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004841c1  e846ddffff             -call 0x481f0c
    cpu.esp -= 4;
    sub_481f0c(app, cpu);
    if (cpu.terminate) return;
    // 004841c6  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
L_0x004841d0:
    // 004841d0  8b5630                 -mov edx, dword ptr [esi + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004841d3  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004841d6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004841dd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004841df  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004841e2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004841e4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004841e7  8d90ec000000           -lea edx, [eax + 0xec]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(236) /* 0xec */);
    // 004841ed  8b1d3ca44c00           -mov ebx, dword ptr [0x4ca43c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 004841f3  b8f0044c00             -mov eax, 0x4c04f0
    cpu.eax = 4982000 /*0x4c04f0*/;
    // 004841f8  e82b60ffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 004841fd  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00484200  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484202  0f8489000000           -je 0x484291
    if (cpu.flags.zf)
    {
        goto L_0x00484291;
    }
    // 00484208  896804                 -mov dword ptr [eax + 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0048420b  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048420e  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 00484213  8d7f54                 -lea edi, [edi + 0x54]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 00484216  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484218  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048421b  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00484222  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484225  c7405000000000         -mov dword ptr [eax + 0x50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 0048422c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048422f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00484232  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 00484235  a160af4c00             -mov eax, dword ptr [0x4caf60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */);
    // 0048423a  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048423d  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00484243  a164af4c00             -mov eax, dword ptr [0x4caf64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025636) /* 0x4caf64 */);
    // 00484248  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048424b  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00484251  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484255  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484256  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484257  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484258  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484259  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048425a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048425c  754a                   -jne 0x4842a8
    if (!cpu.flags.zf)
    {
        goto L_0x004842a8;
    }
    // 0048425e  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484261  c6403c00               -mov byte ptr [eax + 0x3c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
L_0x00484265:
    // 00484265  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484268  8d858c000000           -lea eax, [ebp + 0x8c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 0048426e  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484271  e87aecffff             -call 0x482ef0
    cpu.esp -= 4;
    sub_482ef0(app, cpu);
    if (cpu.terminate) return;
    // 00484276  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484279  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048427c  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048427f  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484282  ff5328                 -call dword ptr [ebx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484285  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484287  7435                   -je 0x4842be
    if (cpu.flags.zf)
    {
        goto L_0x004842be;
    }
    // 00484289  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x00484291:
    // 00484291  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484295  83c40c                 +add esp, 0xc
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
    // 00484298  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484299  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048429a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048429b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048429c:
    // 0048429c  c7463020000000         -mov dword ptr [esi + 0x30], 0x20
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 32 /*0x20*/;
    // 004842a3  e90effffff             -jmp 0x4841b6
    goto L_0x004841b6;
L_0x004842a8:
    // 004842a8  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004842ad  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004842b0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004842b4  83c03c                 +add eax, 0x3c
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
    // 004842b7  e8007dffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 004842bc  eba7                   -jmp 0x484265
    goto L_0x00484265;
L_0x004842be:
    // 004842be  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004842c1  e8c663ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 004842c6  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004842cd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004842d1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004842d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4842d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004842d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004842d9  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004842dc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004842de  7504                   -jne 0x4842e4
    if (!cpu.flags.zf)
    {
        goto L_0x004842e4;
    }
    // 004842e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004842e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004842e4:
    // 004842e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004842e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004842e6  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004842e8  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 004842ed  8d7e54                 -lea edi, [esi + 0x54]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 004842f0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004842f2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004842f7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004842f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484302  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484304  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00484306  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00484309  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048430b  7442                   -je 0x48434f
    if (cpu.flags.zf)
    {
        goto L_0x0048434f;
    }
    // 0048430d  837a0800               +cmp dword ptr [edx + 8], 0
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
    // 00484311  741b                   -je 0x48432e
    if (cpu.flags.zf)
    {
        goto L_0x0048432e;
    }
L_0x00484313:
    // 00484313  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484315  740f                   -je 0x484326
    if (cpu.flags.zf)
    {
        goto L_0x00484326;
    }
    // 00484317  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048431a  e86d63ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0048431f  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00484326:
    // 00484326  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048432b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048432c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048432d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048432e:
    // 0048432e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048432f  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484332  83c20c                 +add edx, 0xc
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
    // 00484335  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00484338  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048433b  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048433e  c6400c00               -mov byte ptr [eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00484342  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00484345  c7400801000000         -mov dword ptr [eax + 8], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0048434c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048434d  ebc4                   -jmp 0x484313
    goto L_0x00484313;
L_0x0048434f:
    // 0048434f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484351  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484352  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484353  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484354(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484354  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484355  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484356  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484357  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484358  8b3d60af4c00           -mov edi, dword ptr [0x4caf60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */);
    // 0048435e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484360  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00484363  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484365  7409                   -je 0x484370
    if (cpu.flags.zf)
    {
        goto L_0x00484370;
    }
    // 00484367  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048436a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048436c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048436e  7513                   -jne 0x484383
    if (!cpu.flags.zf)
    {
        goto L_0x00484383;
    }
L_0x00484370:
    // 00484370  8b3d60af4c00           -mov edi, dword ptr [0x4caf60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */);
    // 00484376  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484378  893d60af4c00           -mov dword ptr [0x4caf60], edi
    app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */) = cpu.edi;
    // 0048437e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048437f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484380  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484381  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484382  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484383:
    // 00484383  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048438a  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048438d  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00484393  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484396  e855ebffff             -call 0x482ef0
    cpu.esp -= 4;
    sub_482ef0(app, cpu);
    if (cpu.terminate) return;
    // 0048439b  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048439e  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004843a1  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004843a4  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004843a7  ff5128                 -call dword ptr [ecx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004843aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004843ac  7441                   -je 0x4843ef
    if (cpu.flags.zf)
    {
        goto L_0x004843ef;
    }
    // 004843ae  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004843af  8b3d60af4c00           -mov edi, dword ptr [0x4caf60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */);
    // 004843b5  c786a000000001000000   -mov dword ptr [esi + 0xa0], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = 1 /*0x1*/;
    // 004843bf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004843c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004843c3:
    // 004843c3  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004843c6  8b9984000000           -mov ebx, dword ptr [ecx + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 004843cc  4b                     -dec ebx
    (cpu.ebx)--;
    // 004843cd  39da                   +cmp edx, ebx
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
    // 004843cf  730d                   -jae 0x4843de
    if (!cpu.flags.cf)
    {
        goto L_0x004843de;
    }
    // 004843d1  83c064                 +add eax, 0x64
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
    // 004843d4  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004843d5  89bc0180000000         -mov dword ptr [ecx + eax + 0x80], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */ + cpu.eax * 1) = cpu.edi;
    // 004843dc  ebe5                   -jmp 0x4843c3
    goto L_0x004843c3;
L_0x004843de:
    // 004843de  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004843e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843e4  893d60af4c00           -mov dword ptr [0x4caf60], edi
    app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */) = cpu.edi;
    // 004843ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004843ef:
    // 004843ef  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004843f2  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004843f9  8b3d60af4c00           -mov edi, dword ptr [0x4caf60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */);
    // 004843ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484401  893d60af4c00           -mov dword ptr [0x4caf60], edi
    app->getMemory<x86::reg32>(x86::reg32(5025632) /* 0x4caf60 */) = cpu.edi;
    // 00484407  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484408  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484409  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048440a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048440b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48440c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048440c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048440d  81ecb0000000           -sub esp, 0xb0
    (cpu.esp) -= x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 00484413  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00484415  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
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
    // 0048441c  0f84e8000000           -je 0x48450a
    if (cpu.flags.zf)
    {
        goto L_0x0048450a;
    }
    // 00484422  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484423  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484424  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484425  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484426  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484427  a188af4c00             -mov eax, dword ptr [0x4caf88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025672) /* 0x4caf88 */);
    // 0048442c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00484430  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00484434  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484437  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484438  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484439  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048443a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048443b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048443c  40                     -inc eax
    (cpu.eax)++;
    // 0048443d  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484440  a388af4c00             -mov dword ptr [0x4caf88], eax
    app->getMemory<x86::reg32>(x86::reg32(5025672) /* 0x4caf88 */) = cpu.eax;
    // 00484445  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00484447  0f84ca000000           -je 0x484517
    if (cpu.flags.zf)
    {
        goto L_0x00484517;
    }
    // 0048444d  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00484450  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00484452  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484454  0f8588000000           -jne 0x4844e2
    if (!cpu.flags.zf)
    {
        goto L_0x004844e2;
    }
    // 0048445a  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048445d  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484460  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00484463  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484466  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484469  899c24c0000000         -mov dword ptr [esp + 0xc0], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.ebx;
    // 00484470  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00484472  c6400c00               -mov byte ptr [eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x00484476:
    // 00484476  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484479  8b7850                 -mov edi, dword ptr [eax + 0x50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048447c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048447e  7462                   -je 0x4844e2
    if (cpu.flags.zf)
    {
        goto L_0x004844e2;
    }
    // 00484480  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 00484486  8b8c24c0000000         -mov ecx, dword ptr [esp + 0xc0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0048448d  4a                     -dec edx
    (cpu.edx)--;
    // 0048448e  39ca                   +cmp edx, ecx
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
    // 00484490  7650                   -jbe 0x4844e2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004844e2;
    }
    // 00484492  8a8c24c0000000         -mov cl, byte ptr [esp + 0xc0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00484499  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048449e  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004844a0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004844a2  85fa                   +test edx, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edi));
    // 004844a4  7514                   -jne 0x4844ba
    if (!cpu.flags.zf)
    {
        goto L_0x004844ba;
    }
L_0x004844a6:
    // 004844a6  8b8424c0000000         -mov eax, dword ptr [esp + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 004844ad  40                     -inc eax
    (cpu.eax)++;
    // 004844ae  83c664                 +add esi, 0x64
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
    // 004844b1  898424c0000000         -mov dword ptr [esp + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 004844b8  ebbc                   -jmp 0x484476
    goto L_0x00484476;
L_0x004844ba:
    // 004844ba  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004844bc  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 004844be  21cf                   -and edi, ecx
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004844c0  bb657962ea             -mov ebx, 0xea627965
    cpu.ebx = 3932322149 /*0xea627965*/;
    // 004844c5  897850                 -mov dword ptr [eax + 0x50], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 004844c8  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004844cc  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004844cf  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004844d2  81c288000000           -add edx, 0x88
    (cpu.edx) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 004844d8  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004844db  01f2                   +add edx, esi
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
    // 004844dd  ff5750                 -call dword ptr [edi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004844e0  ebc4                   -jmp 0x4844a6
    goto L_0x004844a6;
L_0x004844e2:
    // 004844e2  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004844e5  e8a261ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 004844ea  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x004844f1:
    // 004844f1  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 004844fb  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 00484505  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484506  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484507  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484508  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484509  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048450a:
    // 0048450a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048450f  81c4b0000000           +add esp, 0xb0
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
    // 00484515  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484516  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484517:
    // 00484517  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00484519  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048451d  bb657962ea             -mov ebx, 0xea627965
    cpu.ebx = 3932322149 /*0xea627965*/;
    // 00484522  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484525  8d551c                 -lea edx, [ebp + 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484528  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048452b  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048452e  ebc1                   -jmp 0x4844f1
    goto L_0x004844f1;
}

/* align: skip  */
void Application::sub_484530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484530  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484531  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484532  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484533  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484534  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0048453a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048453c  899c24fc000000         -mov dword ptr [esp + 0xfc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.ebx;
    // 00484543  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484545  898c2404010000         -mov dword ptr [esp + 0x104], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.ecx;
    // 0048454c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048454e  0f85a2000000           -jne 0x4845f6
    if (!cpu.flags.zf)
    {
        goto L_0x004845f6;
    }
    // 00484554  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
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
    // 0048455b  0f8495000000           -je 0x4845f6
    if (cpu.flags.zf)
    {
        goto L_0x004845f6;
    }
    // 00484561  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x00484564:
    // 00484564  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 00484568  0f84d8000000           -je 0x484646
    if (cpu.flags.zf)
    {
        goto L_0x00484646;
    }
    // 0048456e  8d451c                 -lea eax, [ebp + 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484571  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00484573  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484575  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484577  e8f4d9ffff             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 0048457c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048457e  0f84c2000000           -je 0x484646
    if (cpu.flags.zf)
    {
        goto L_0x00484646;
    }
    // 00484584  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00484589  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048458c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048458e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484590  ff9424fc000000         -call dword ptr [esp + 0xfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484597  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484599  0f8451020000           -je 0x4847f0
    if (cpu.flags.zf)
    {
        goto L_0x004847f0;
    }
    // 0048459f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004845a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004845a6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004845a8  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
    // 004845af  89842408010000         -mov dword ptr [esp + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
L_0x004845b6:
    // 004845b6  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004845b9  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 004845bf  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004845c6  4a                     -dec edx
    (cpu.edx)--;
    // 004845c7  39fa                   +cmp edx, edi
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
    // 004845c9  0f8621020000           -jbe 0x4847f0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004847f0;
    }
    // 004845cf  8a8c2408010000         -mov cl, byte ptr [esp + 0x108]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004845d6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004845db  d3e2                   +shl edx, cl
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
    // 004845dd  855050                 -test dword ptr [eax + 0x50], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) & cpu.edx));
    // 004845e0  753d                   -jne 0x48461f
    if (!cpu.flags.zf)
    {
        goto L_0x0048461f;
    }
L_0x004845e2:
    // 004845e2  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004845e9  47                     -inc edi
    (cpu.edi)++;
    // 004845ea  83c664                 +add esi, 0x64
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
    // 004845ed  89bc2408010000         -mov dword ptr [esp + 0x108], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.edi;
    // 004845f4  ebc0                   -jmp 0x4845b6
    goto L_0x004845b6;
L_0x004845f6:
    // 004845f6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004845f8  7418                   -je 0x484612
    if (cpu.flags.zf)
    {
        goto L_0x00484612;
    }
    // 004845fa  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
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
    // 00484601  750f                   -jne 0x484612
    if (!cpu.flags.zf)
    {
        goto L_0x00484612;
    }
    // 00484603  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00484605  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484608  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00484609  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048460a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048460b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048460c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048460d  e952ffffff             -jmp 0x484564
    goto L_0x00484564;
L_0x00484612:
    // 00484612  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484614  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0048461a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048461b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048461c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048461d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048461e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048461f:
    // 0048461f  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00484624  8d5f01                 -lea ebx, [edi + 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00484627  8d1430                 -lea edx, [eax + esi]
    cpu.edx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0048462a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048462c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048462e  ff9424fc000000         -call dword ptr [esp + 0xfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484635  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484637  0f84b3010000           -je 0x4847f0
    if (cpu.flags.zf)
    {
        goto L_0x004847f0;
    }
    // 0048463d  ff842404010000         +inc dword ptr [esp + 0x104]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00484644  eb9c                   -jmp 0x4845e2
    goto L_0x004845e2;
L_0x00484646:
    // 00484646  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0048464b  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00484652  bb716572ea             -mov ebx, 0xea726571
    cpu.ebx = 3933365617 /*0xea726571*/;
    // 00484657  a120a44c00             -mov eax, dword ptr [0x4ca420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0048465c  be502e4800             -mov esi, 0x482e50
    cpu.esi = 4730448 /*0x482e50*/;
    // 00484661  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484663  8d9424ac000000         -lea edx, [esp + 0xac]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048466a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048466b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048466d  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 00484672  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484676  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484678  e85beaffff             -call 0x4830d8
    cpu.esp -= 4;
    sub_4830d8(app, cpu);
    if (cpu.terminate) return;
    // 0048467d  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
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
    // 00484685  0f8465010000           -je 0x4847f0
    if (cpu.flags.zf)
    {
        goto L_0x004847f0;
    }
    // 0048468b  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00484692  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00484697  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048469c  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 004846a3  899424b0000000         -mov dword ptr [esp + 0xb0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.edx;
    // 004846aa  8b8424fc000000         -mov eax, dword ptr [esp + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 004846b1  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004846b6  898424c4000000         -mov dword ptr [esp + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 004846bd  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004846c1  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004846c5  e80ae6ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 004846ca  a120a44c00             -mov eax, dword ptr [0x4ca420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004846cf  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004846d1  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004846d3  bb746567ea             -mov ebx, 0xea676574
    cpu.ebx = 3932644724 /*0xea676574*/;
    // 004846d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004846d9  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004846e0  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004846e3  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 004846e5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004846e7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004846e8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004846e9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004846ea  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004846eb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004846ec  e8e7e9ffff             -call 0x4830d8
    cpu.esp -= 4;
    sub_4830d8(app, cpu);
    if (cpu.terminate) return;
    // 004846f1  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
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
    // 004846f9  0f8403010000           -je 0x484802
    if (cpu.flags.zf)
    {
        goto L_0x00484802;
    }
    // 004846ff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00484704:
    // 00484704  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048470b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048470d  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 00484714  899c240c010000         -mov dword ptr [esp + 0x10c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebx;
    // 0048471b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048471d  0f84cd000000           -je 0x4847f0
    if (cpu.flags.zf)
    {
        goto L_0x004847f0;
    }
L_0x00484723:
    // 00484723  83bc240c0100001f       +cmp dword ptr [esp + 0x10c], 0x1f
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
    // 0048472b  0f8dbf000000           -jge 0x4847f0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004847f0;
    }
    // 00484731  83bc24c400000000       +cmp dword ptr [esp + 0xc4], 0
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
    // 00484739  0f84b1000000           -je 0x4847f0
    if (cpu.flags.zf)
    {
        goto L_0x004847f0;
    }
    // 0048473f  83bc240401000000       +cmp dword ptr [esp + 0x104], 0
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
    // 00484747  0f84a3000000           -je 0x4847f0
    if (cpu.flags.zf)
    {
        goto L_0x004847f0;
    }
    // 0048474d  8a8c240c010000         -mov cl, byte ptr [esp + 0x10c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00484754  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484759  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00484760  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00484762  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 00484764  746c                   -je 0x4847d2
    if (cpu.flags.zf)
    {
        goto L_0x004847d2;
    }
    // 00484766  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048476b  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00484772  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00484776  e859e5ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 0048477b  a120a44c00             -mov eax, dword ptr [0x4ca420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00484780  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484782  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484783  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484787  bb746567ea             -mov ebx, 0xea676574
    cpu.ebx = 3932644724 /*0xea676574*/;
    // 0048478c  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0048478e  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00484795  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484797  e83ce9ffff             -call 0x4830d8
    cpu.esp -= 4;
    sub_4830d8(app, cpu);
    if (cpu.terminate) return;
    // 0048479c  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
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
    // 004847a4  7463                   -je 0x484809
    if (cpu.flags.zf)
    {
        goto L_0x00484809;
    }
    // 004847a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004847ab:
    // 004847ab  8a8c240c010000         -mov cl, byte ptr [esp + 0x10c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004847b2  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 004847b9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004847be  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004847c0  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004847c7  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004847c9  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 004847cb  899c240c010000         -mov dword ptr [esp + 0x10c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebx;
L_0x004847d2:
    // 004847d2  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004847d9  42                     -inc edx
    (cpu.edx)++;
    // 004847da  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004847e1  8994240c010000         -mov dword ptr [esp + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 004847e8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004847ea  0f8533ffffff           -jne 0x484723
    if (!cpu.flags.zf)
    {
        goto L_0x00484723;
    }
L_0x004847f0:
    // 004847f0  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004847f7  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004847fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484800  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484801  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484802:
    // 00484802  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484804  e9fbfeffff             -jmp 0x484704
    goto L_0x00484704;
L_0x00484809:
    // 00484809  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048480b  eb9e                   -jmp 0x4847ab
    goto L_0x004847ab;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484810  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484811  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484812  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484813  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484814  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484817  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484819  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048481c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048481e  750a                   -jne 0x48482a
    if (!cpu.flags.zf)
    {
        goto L_0x0048482a;
    }
L_0x00484820:
    // 00484820  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484822  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484825  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484826  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484827  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484828  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484829  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048482a:
    // 0048482a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048482c  e887e9ffff             -call 0x4831b8
    cpu.esp -= 4;
    sub_4831b8(app, cpu);
    if (cpu.terminate) return;
    // 00484831  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484833  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484835  74e9                   -je 0x484820
    if (cpu.flags.zf)
    {
        goto L_0x00484820;
    }
    // 00484837  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484838  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048483b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048483d  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00484842  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00484844  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00484849  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048484b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048484e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00484850  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484852  bb74756fea             -mov ebx, 0xea6f7574
    cpu.ebx = 3933173108 /*0xea6f7574*/;
    // 00484857  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048485a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048485e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00484860  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484862  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00484865  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484868  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048486c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484871  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00484874  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00484876  8b5a50                 -mov ebx, dword ptr [edx + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 00484879  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0048487b  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0048487d  895a50                 -mov dword ptr [edx + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00484880  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484881  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484883  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484886  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484887  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484888  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484889  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048488a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48488c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048488c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048488d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048488f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484891  745a                   -je 0x4848ed
    if (cpu.flags.zf)
    {
        goto L_0x004848ed;
    }
    // 00484893  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484894  837a2400               +cmp dword ptr [edx + 0x24], 0
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
    // 00484898  7515                   -jne 0x4848af
    if (!cpu.flags.zf)
    {
        goto L_0x004848af;
    }
    // 0048489a  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004848a0  bf1e000000             -mov edi, 0x1e
    cpu.edi = 30 /*0x1e*/;
    // 004848a5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004848a7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004848aa  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004848ac  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004848af:
    // 004848af  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 004848b3  7515                   -jne 0x4848ca
    if (!cpu.flags.zf)
    {
        goto L_0x004848ca;
    }
    // 004848b5  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004848bb  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 004848c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004848c2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004848c5  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004848c7  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x004848ca:
    // 004848ca  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 004848ce  7515                   -jne 0x4848e5
    if (!cpu.flags.zf)
    {
        goto L_0x004848e5;
    }
    // 004848d0  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004848d6  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 004848db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004848dd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004848e0  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004848e2  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x004848e5:
    // 004848e5  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004848ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004848ed:
    // 004848ed  ba80494c00             -mov edx, 0x4c4980
    cpu.edx = 4999552 /*0x4c4980*/;
    // 004848f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004848f3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004848f5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004848f7  bbd0af4c00             -mov ebx, 0x4cafd0
    cpu.ebx = 5025744 /*0x4cafd0*/;
    // 004848fc  e807c5ffff             -call 0x480e08
    cpu.esp -= 4;
    sub_480e08(app, cpu);
    if (cpu.terminate) return;
    // 00484901  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484902  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484904  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484905  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484906  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484907  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484908  8b7048                 -mov esi, dword ptr [eax + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048490b  8915fcdd5100           -mov dword ptr [0x51ddfc], edx
    app->getMemory<x86::reg32>(x86::reg32(5365244) /* 0x51ddfc */) = cpu.edx;
    // 00484911  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00484914  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484916  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484918  7459                   -je 0x484973
    if (cpu.flags.zf)
    {
        goto L_0x00484973;
    }
    // 0048491a  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048491d  837a4400               +cmp dword ptr [edx + 0x44], 0
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
    // 00484921  740b                   -je 0x48492e
    if (cpu.flags.zf)
    {
        goto L_0x0048492e;
    }
    // 00484923  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484925  8d5030                 -lea edx, [eax + 0x30]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00484928  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048492b  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048492e:
    // 0048492e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048492f  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 00484934  8d5730                 -lea edx, [edi + 0x30]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 00484937  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048493a  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048493d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048493f  ff5558                 -call dword ptr [ebp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484942  a1ecdd5100             -mov eax, dword ptr [0x51ddec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365228) /* 0x51ddec */);
    // 00484947  e87cc2ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048494c  8b9ea8000000           -mov ebx, dword ptr [esi + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 00484952  43                     -inc ebx
    (cpu.ebx)++;
    // 00484953  a1ecdd5100             -mov eax, dword ptr [0x51ddec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365228) /* 0x51ddec */);
    // 00484958  899ea8000000           -mov dword ptr [esi + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 0048495e  e87dc2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00484963  c74744ffffffff         -mov dword ptr [edi + 0x44], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = 4294967295 /*0xffffffff*/;
    // 0048496a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048496b  8b4744                 -mov eax, dword ptr [edi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 0048496e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048496f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484970  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484971  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484972  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484973:
    // 00484973  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 00484976  8b4744                 -mov eax, dword ptr [edi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 00484979  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048497a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048497b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048497c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048497d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484981  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484982  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484983  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484984  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484985  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484987  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048498a  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048498d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048498f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484991  7409                   -je 0x48499c
    if (cpu.flags.zf)
    {
        goto L_0x0048499c;
    }
    // 00484993  83baa800000000         +cmp dword ptr [edx + 0xa8], 0
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
    // 0048499a  7512                   -jne 0x4849ae
    if (!cpu.flags.zf)
    {
        goto L_0x004849ae;
    }
L_0x0048499c:
    // 0048499c  c7474400000000         -mov dword ptr [edi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 004849a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004849a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004849ae:
    // 004849ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004849af  a1ecdd5100             -mov eax, dword ptr [0x51ddec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365228) /* 0x51ddec */);
    // 004849b4  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 004849b9  e80ac2ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004849be  8d7130                 -lea esi, [ecx + 0x30]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 004849c1  8baaa8000000           -mov ebp, dword ptr [edx + 0xa8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 004849c7  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004849cc  4d                     -dec ebp
    (cpu.ebp)--;
    // 004849cd  a1ecdd5100             -mov eax, dword ptr [0x51ddec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365228) /* 0x51ddec */);
    // 004849d2  89aaa8000000           -mov dword ptr [edx + 0xa8], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.ebp;
    // 004849d8  e803c2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004849dd  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004849e0  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004849e3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004849e5  ff5558                 -call dword ptr [ebp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004849e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849e9  c7474400000000         -mov dword ptr [edi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 004849f0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004849f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4849fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004849fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004849fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004849fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004849ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484a01  8b1dfcdd5100           -mov ebx, dword ptr [0x51ddfc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5365244) /* 0x51ddfc */);
    // 00484a07  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484a09  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484a0b  751b                   -jne 0x484a28
    if (!cpu.flags.zf)
    {
        goto L_0x00484a28;
    }
L_0x00484a0d:
    // 00484a0d  83794400               +cmp dword ptr [ecx + 0x44], 0
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
    // 00484a11  7428                   -je 0x484a3b
    if (cpu.flags.zf)
    {
        goto L_0x00484a3b;
    }
    // 00484a13  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00484a16  83b89c00000000         +cmp dword ptr [eax + 0x9c], 0
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
    // 00484a1d  741c                   -je 0x484a3b
    if (cpu.flags.zf)
    {
        goto L_0x00484a3b;
    }
    // 00484a1f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484a24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484a28:
    // 00484a28  e833000000             -call 0x484a60
    cpu.esp -= 4;
    sub_484a60(app, cpu);
    if (cpu.terminate) return;
    // 00484a2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484a2f  74dc                   -je 0x484a0d
    if (cpu.flags.zf)
    {
        goto L_0x00484a0d;
    }
    // 00484a31  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484a33  ff15fcdd5100           -call dword ptr [0x51ddfc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5365244) /* 0x51ddfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484a39  ebd2                   -jmp 0x484a0d
    goto L_0x00484a0d;
L_0x00484a3b:
    // 00484a3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484a3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a40  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
