#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4c17f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c17f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c17f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c17f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c17f3  ff15e0ed4d00           -call dword ptr [0x4dede0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107168) /* 0x4dede0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c17f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c17fa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c17fa  ff15e4ed4d00           -call dword ptr [0x4dede4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107172) /* 0x4dede4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c1800  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1801(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1801  ff15e8ed4d00           -call dword ptr [0x4dede8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107176) /* 0x4dede8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c1807  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1808(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1808  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1809  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c180a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c180c  7410                   -je 0x4c181e
    if (cpu.flags.zf)
    {
        goto L_0x004c181e;
    }
    // 004c180e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c1810  8b35e0ed4d00           -mov esi, dword ptr [0x4dede0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5107168) /* 0x4dede0 */);
    // 004c1816  890de0ed4d00           -mov dword ptr [0x4dede0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5107168) /* 0x4dede0 */) = cpu.ecx;
    // 004c181c  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x004c181e:
    // 004c181e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c1820  740f                   -je 0x4c1831
    if (cpu.flags.zf)
    {
        goto L_0x004c1831;
    }
    // 004c1822  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004c1824  8b0de4ed4d00           -mov ecx, dword ptr [0x4dede4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5107172) /* 0x4dede4 */);
    // 004c182a  a3e4ed4d00             -mov dword ptr [0x4dede4], eax
    app->getMemory<x86::reg32>(x86::reg32(5107172) /* 0x4dede4 */) = cpu.eax;
    // 004c182f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x004c1831:
    // 004c1831  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c1833  740f                   -je 0x4c1844
    if (cpu.flags.zf)
    {
        goto L_0x004c1844;
    }
    // 004c1835  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1837  8b15e8ed4d00           -mov edx, dword ptr [0x4dede8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107176) /* 0x4dede8 */);
    // 004c183d  a3e8ed4d00             -mov dword ptr [0x4dede8], eax
    app->getMemory<x86::reg32>(x86::reg32(5107176) /* 0x4dede8 */) = cpu.eax;
    // 004c1842  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x004c1844:
    // 004c1844  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1845  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1846  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1847(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1847  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c1848  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1849  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c184a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c184b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c184e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1850  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c1852  8a2558934d00           -mov ah, byte ptr [0x4d9358]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5083992) /* 0x4d9358 */);
    // 004c1858  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004c185b  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004c185d  7426                   -je 0x4c1885
    if (cpu.flags.zf)
    {
        goto L_0x004c1885;
    }
    // 004c185f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004c1861  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004c1864  9b                     -wait 
    /*nothing*/;
    // 004c1865  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c1867  741c                   -je 0x4c1885
    if (cpu.flags.zf)
    {
        goto L_0x004c1885;
    }
    // 004c1869  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c186b  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004c186e  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004c1870  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1872  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 004c1874  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1876  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004c1878  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004c187b  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 004c187e  9b                     -wait 
    /*nothing*/;
    // 004c187f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004c1881  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004c1884  9b                     -wait 
    /*nothing*/;
L_0x004c1885:
    // 004c1885  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1887  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 004c188b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c188e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c188f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1890  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1891  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1892  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1893(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1893  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1894  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c1898  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004c189b  6681faff7f             +cmp dx, 0x7fff
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c18a0  751c                   -jne 0x4c18be
    if (!cpu.flags.zf)
    {
        goto L_0x004c18be;
    }
    // 004c18a2  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c18a9  750c                   -jne 0x4c18b7
    if (!cpu.flags.zf)
    {
        goto L_0x004c18b7;
    }
    // 004c18ab  833800                 +cmp dword ptr [eax], 0
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
    // 004c18ae  7507                   -jne 0x4c18b7
    if (!cpu.flags.zf)
    {
        goto L_0x004c18b7;
    }
    // 004c18b0  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004c18b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c18b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c18b7:
    // 004c18b7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004c18bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c18bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c18be:
    // 004c18be  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 004c18c4  7516                   -jne 0x4c18dc
    if (!cpu.flags.zf)
    {
        goto L_0x004c18dc;
    }
    // 004c18c6  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004c18ca  7509                   -jne 0x4c18d5
    if (!cpu.flags.zf)
    {
        goto L_0x004c18d5;
    }
    // 004c18cc  833800                 +cmp dword ptr [eax], 0
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
    // 004c18cf  7504                   -jne 0x4c18d5
    if (!cpu.flags.zf)
    {
        goto L_0x004c18d5;
    }
    // 004c18d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c18d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c18d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c18d5:
    // 004c18d5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004c18da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c18db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c18dc:
    // 004c18dc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004c18e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c18e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c18e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c18e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c18e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c18e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c18e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c18e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c18e9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c18ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c18ec  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c18ee  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c18f0  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c18f2  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c18f4:
    // 004c18f4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c18f6  3c00                   +cmp al, 0
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
    // 004c18f8  742f                   -je 0x4c1929
    if (cpu.flags.zf)
    {
        goto L_0x004c1929;
    }
    // 004c18fa  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c18fc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004c18fe  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1900  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1902  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1904  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c1906  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1908  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c190a  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c190c  01c5                   +add ebp, eax
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
    // 004c190e  11d9                   +adc ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1910  11fa                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 004c1912  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1914  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1916  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c1918  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c191a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c191c  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004c191e  01c5                   +add ebp, eax
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
    // 004c1920  83d100                 +adc ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1923  83d200                 +adc edx, 0
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
    // 004c1926  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c1927  ebcb                   -jmp 0x4c18f4
    goto L_0x004c18f4;
L_0x004c1929:
    // 004c1929  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c192b  bf5e400000             -mov edi, 0x405e
    cpu.edi = 16478 /*0x405e*/;
    // 004c1930  e811000000             -call 0x4c1946
    cpu.esp -= 4;
    sub_4c1946(app, cpu);
    if (cpu.terminate) return;
    // 004c1935  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1936  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c1939  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004c193c  66897508               -mov word ptr [ebp + 8], si
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 004c1940  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1941  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1942  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1943  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1944  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1945  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1946(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1946  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004c1948  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004c194a  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 004c194c  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004c194e  7436                   -je 0x4c1986
    if (cpu.flags.zf)
    {
        goto L_0x004c1986;
    }
    // 004c1950  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c1952  7509                   -jne 0x4c195d
    if (!cpu.flags.zf)
    {
        goto L_0x004c195d;
    }
    // 004c1954  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1956  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1958  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c195a  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004c195d:
    // 004c195d  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c195f  7509                   -jne 0x4c196a
    if (!cpu.flags.zf)
    {
        goto L_0x004c196a;
    }
    // 004c1961  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1963  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1965  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c1967  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004c196a:
    // 004c196a  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c196c  7809                   -js 0x4c1977
    if (cpu.flags.sf)
    {
        goto L_0x004c1977;
    }
    // 004c196e  4f                     -dec edi
    (cpu.edi)--;
    // 004c196f  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1971  11c0                   +adc eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1973  11d2                   +adc edx, edx
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
    // 004c1975  ebf3                   -jmp 0x4c196a
    goto L_0x004c196a;
L_0x004c1977:
    // 004c1977  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1979  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c197c  83d200                 +adc edx, 0
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
    // 004c197f  7303                   -jae 0x4c1984
    if (!cpu.flags.cf)
    {
        goto L_0x004c1984;
    }
    // 004c1981  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
    // 004c1983  47                     -inc edi
    (cpu.edi)++;
L_0x004c1984:
    // 004c1984  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004c1986:
    // 004c1986  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1987(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1987  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c1988  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c198a  e802000000             -call 0x4c1991
    cpu.esp -= 4;
    sub_4c1991(app, cpu);
    if (cpu.terminate) return;
    // 004c198f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1990  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1991(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1991  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1992  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c1994  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1995  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1996  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004c1999  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c199b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004c199d  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004c19a0  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004c19a3  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004c19a6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c19a8  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004c19ab  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c19ae  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004c19b1  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 004c19b4  7407                   -je 0x4c19bd
    if (cpu.flags.zf)
    {
        goto L_0x004c19bd;
    }
    // 004c19b6  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004c19bb  eb3a                   -jmp 0x4c19f7
    goto L_0x004c19f7;
L_0x004c19bd:
    // 004c19bd  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 004c19c0  7407                   -je 0x4c19c9
    if (cpu.flags.zf)
    {
        goto L_0x004c19c9;
    }
    // 004c19c2  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 004c19c7  eb2e                   -jmp 0x4c19f7
    goto L_0x004c19f7;
L_0x004c19c9:
    // 004c19c9  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 004c19cc  7407                   -je 0x4c19d5
    if (cpu.flags.zf)
    {
        goto L_0x004c19d5;
    }
    // 004c19ce  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 004c19d3  eb22                   -jmp 0x4c19f7
    goto L_0x004c19f7;
L_0x004c19d5:
    // 004c19d5  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004c19d8  7407                   -je 0x4c19e1
    if (cpu.flags.zf)
    {
        goto L_0x004c19e1;
    }
    // 004c19da  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004c19df  eb16                   -jmp 0x4c19f7
    goto L_0x004c19f7;
L_0x004c19e1:
    // 004c19e1  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 004c19e4  7407                   -je 0x4c19ed
    if (cpu.flags.zf)
    {
        goto L_0x004c19ed;
    }
    // 004c19e6  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 004c19eb  eb0a                   -jmp 0x4c19f7
    goto L_0x004c19f7;
L_0x004c19ed:
    // 004c19ed  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 004c19f0  7405                   -je 0x4c19f7
    if (cpu.flags.zf)
    {
        goto L_0x004c19f7;
    }
    // 004c19f2  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
L_0x004c19f7:
    // 004c19f7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c19f9  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004c19fc  8b0485e8ed4d00         -mov eax, dword ptr [eax*4 + 0x4dede8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107176) /* 0x4dede8 */ + cpu.eax * 4);
    // 004c1a03  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 004c1a06  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004c1a09  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004c1a0c  740d                   -je 0x4c1a1b
    if (cpu.flags.zf)
    {
        goto L_0x004c1a1b;
    }
    // 004c1a0e  dd05ecfe4c00           +fld qword ptr [0x4cfeec]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5045996) /* 0x4cfeec */)));
    // 004c1a14  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004c1a16  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1a19  eb42                   -jmp 0x4c1a5d
    goto L_0x004c1a5d;
L_0x004c1a1b:
    // 004c1a1b  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 004c1a1e  740a                   -je 0x4c1a2a
    if (cpu.flags.zf)
    {
        goto L_0x004c1a2a;
    }
    // 004c1a20  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004c1a22  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 004c1a25  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004c1a28  eb33                   -jmp 0x4c1a5d
    goto L_0x004c1a5d;
L_0x004c1a2a:
    // 004c1a2a  f6c540                 +test ch, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 64 /*0x40*/));
    // 004c1a2d  740f                   -je 0x4c1a3e
    if (cpu.flags.zf)
    {
        goto L_0x004c1a3e;
    }
    // 004c1a2f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c1a31  bb0000f03f             -mov ebx, 0x3ff00000
    cpu.ebx = 1072693248 /*0x3ff00000*/;
    // 004c1a36  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004c1a39  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004c1a3c  eb1f                   -jmp 0x4c1a5d
    goto L_0x004c1a5d;
L_0x004c1a3e:
    // 004c1a3e  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 004c1a41  740f                   -je 0x4c1a52
    if (cpu.flags.zf)
    {
        goto L_0x004c1a52;
    }
    // 004c1a43  a1ecfe4c00             -mov eax, dword ptr [0x4cfeec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5045996) /* 0x4cfeec */);
    // 004c1a48  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004c1a4b  a1f0fe4c00             -mov eax, dword ptr [0x4cfef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5046000) /* 0x4cfef0 */);
    // 004c1a50  eb08                   -jmp 0x4c1a5a
    goto L_0x004c1a5a;
L_0x004c1a52:
    // 004c1a52  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1a54  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004c1a57  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
L_0x004c1a5a:
    // 004c1a5a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x004c1a5d:
    // 004c1a5d  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004c1a60  e882090000             -call 0x4c23e7
    cpu.esp -= 4;
    sub_4c23e7(app, cpu);
    if (cpu.terminate) return;
    // 004c1a65  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004c1a68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1a6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1a6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c1a6d  833d90805b0000         +cmp dword ptr [0x5b8090], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1a74  7421                   -je 0x4c1a97
    if (cpu.flags.zf)
    {
        goto L_0x004c1a97;
    }
    // 004c1a76  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1a78  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004c1a7a  8a9b95805b00           -mov bl, byte ptr [ebx + 0x5b8095]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5996693) /* 0x5b8095 */);
    // 004c1a80  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c1a83  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c1a89  740c                   -je 0x4c1a97
    if (cpu.flags.zf)
    {
        goto L_0x004c1a97;
    }
    // 004c1a8b  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004c1a8d  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004c1a8f  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004c1a92  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 004c1a95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1a97:
    // 004c1a97  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 004c1a99  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004c1a9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1a9d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1a9d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c1a9e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1a9f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1aa0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c1aa3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004c1aa5:
    // 004c1aa5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1aa7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c1aa9  e87b73ffff             -call 0x4b8e29
    cpu.esp -= 4;
    sub_4b8e29(app, cpu);
    if (cpu.terminate) return;
    // 004c1aae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1ab0  7531                   -jne 0x4c1ae3
    if (!cpu.flags.zf)
    {
        goto L_0x004c1ae3;
    }
    // 004c1ab2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c1ab4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c1ab6  e85b090000             -call 0x4c2416
    cpu.esp -= 4;
    sub_4c2416(app, cpu);
    if (cpu.terminate) return;
    // 004c1abb  e891090000             -call 0x4c2451
    cpu.esp -= 4;
    sub_4c2451(app, cpu);
    if (cpu.terminate) return;
    // 004c1ac0  e8f5090000             -call 0x4c24ba
    cpu.esp -= 4;
    sub_4c24ba(app, cpu);
    if (cpu.terminate) return;
    // 004c1ac5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c1ac7  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 004c1ac9  e833beffff             -call 0x4bd901
    cpu.esp -= 4;
    sub_4bd901(app, cpu);
    if (cpu.terminate) return;
    // 004c1ace  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004c1ad1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c1ad3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c1ad5  e892ffffff             -call 0x4c1a6c
    cpu.esp -= 4;
    sub_4c1a6c(app, cpu);
    if (cpu.terminate) return;
    // 004c1ada  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c1adc  e88473ffff             -call 0x4b8e65
    cpu.esp -= 4;
    sub_4b8e65(app, cpu);
    if (cpu.terminate) return;
    // 004c1ae1  ebc2                   -jmp 0x4c1aa5
    goto L_0x004c1aa5;
L_0x004c1ae3:
    // 004c1ae3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1ae5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c1ae8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1ae9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1aea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1aeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1aec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1aec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c1aed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1aee  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c1af0  3a1a                   +cmp bl, byte ptr [edx]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1af2  7541                   -jne 0x4c1b35
    if (!cpu.flags.zf)
    {
        goto L_0x004c1b35;
    }
    // 004c1af4  833d90805b0000         +cmp dword ptr [0x5b8090], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1afb  741f                   -je 0x4c1b1c
    if (cpu.flags.zf)
    {
        goto L_0x004c1b1c;
    }
    // 004c1afd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1aff  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c1b01  8a9b95805b00           -mov bl, byte ptr [ebx + 0x5b8095]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5996693) /* 0x5b8095 */);
    // 004c1b07  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c1b0a  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c1b10  740a                   -je 0x4c1b1c
    if (cpu.flags.zf)
    {
        goto L_0x004c1b1c;
    }
    // 004c1b12  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c1b15  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004c1b18  38cb                   +cmp bl, cl
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
    // 004c1b1a  7505                   -jne 0x4c1b21
    if (!cpu.flags.zf)
    {
        goto L_0x004c1b21;
    }
L_0x004c1b1c:
    // 004c1b1c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1b1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1b1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1b20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1b21:
    // 004c1b21  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004c1b23  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c1b28  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 004c1b2a  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c1b30  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1b32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1b33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1b34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1b35:
    // 004c1b35  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1b37  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c1b39  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1b3b  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004c1b3d  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1b3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c1b41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1b42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1b44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1b44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1b45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1b46  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1b47  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1b4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1b4b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004c1b4d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004c1b4f  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004c1b53  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c1b55  7402                   -je 0x4c1b59
    if (cpu.flags.zf)
    {
        goto L_0x004c1b59;
    }
    // 004c1b57  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004c1b59:
    // 004c1b59  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004c1b5c:
    // 004c1b5c  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004c1b5e  fec0                   -inc al
    (cpu.al)++;
    // 004c1b60  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c1b65  f68028cd4d0002         +test byte ptr [eax + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004c1b6c  7403                   -je 0x4c1b71
    if (cpu.flags.zf)
    {
        goto L_0x004c1b71;
    }
    // 004c1b6e  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c1b6f  ebeb                   -jmp 0x4c1b5c
    goto L_0x004c1b5c;
L_0x004c1b71:
    // 004c1b71  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 004c1b73  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1b76  7405                   -je 0x4c1b7d
    if (cpu.flags.zf)
    {
        goto L_0x004c1b7d;
    }
    // 004c1b78  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1b7b  7501                   -jne 0x4c1b7e
    if (!cpu.flags.zf)
    {
        goto L_0x004c1b7e;
    }
L_0x004c1b7d:
    // 004c1b7d  42                     -inc edx
    (cpu.edx)++;
L_0x004c1b7e:
    // 004c1b7e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c1b80  752c                   -jne 0x4c1bae
    if (!cpu.flags.zf)
    {
        goto L_0x004c1bae;
    }
    // 004c1b82  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1b85  7514                   -jne 0x4c1b9b
    if (!cpu.flags.zf)
    {
        goto L_0x004c1b9b;
    }
    // 004c1b87  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004c1b8a  80f978                 +cmp cl, 0x78
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1b8d  7405                   -je 0x4c1b94
    if (cpu.flags.zf)
    {
        goto L_0x004c1b94;
    }
    // 004c1b8f  80f958                 +cmp cl, 0x58
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1b92  7507                   -jne 0x4c1b9b
    if (!cpu.flags.zf)
    {
        goto L_0x004c1b9b;
    }
L_0x004c1b94:
    // 004c1b94  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 004c1b99  eb33                   -jmp 0x4c1bce
    goto L_0x004c1bce;
L_0x004c1b9b:
    // 004c1b9b  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1b9e  7507                   -jne 0x4c1ba7
    if (!cpu.flags.zf)
    {
        goto L_0x004c1ba7;
    }
    // 004c1ba0  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 004c1ba5  eb3c                   -jmp 0x4c1be3
    goto L_0x004c1be3;
L_0x004c1ba7:
    // 004c1ba7  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 004c1bac  eb35                   -jmp 0x4c1be3
    goto L_0x004c1be3;
L_0x004c1bae:
    // 004c1bae  83fe02                 +cmp esi, 2
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
    // 004c1bb1  7c05                   -jl 0x4c1bb8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c1bb8;
    }
    // 004c1bb3  83fe24                 +cmp esi, 0x24
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1bb6  7e11                   -jle 0x4c1bc9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c1bc9;
    }
L_0x004c1bb8:
    // 004c1bb8  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 004c1bbd  e85e06feff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004c1bc2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c1bc4  e9b3000000             -jmp 0x4c1c7c
    goto L_0x004c1c7c;
L_0x004c1bc9:
    // 004c1bc9  83fe10                 +cmp esi, 0x10
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
    // 004c1bcc  7515                   -jne 0x4c1be3
    if (!cpu.flags.zf)
    {
        goto L_0x004c1be3;
    }
L_0x004c1bce:
    // 004c1bce  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1bd1  7510                   -jne 0x4c1be3
    if (!cpu.flags.zf)
    {
        goto L_0x004c1be3;
    }
    // 004c1bd3  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004c1bd6  80ff78                 +cmp bh, 0x78
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1bd9  7405                   -je 0x4c1be0
    if (cpu.flags.zf)
    {
        goto L_0x004c1be0;
    }
    // 004c1bdb  80ff58                 +cmp bh, 0x58
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1bde  7503                   -jne 0x4c1be3
    if (!cpu.flags.zf)
    {
        goto L_0x004c1be3;
    }
L_0x004c1be0:
    // 004c1be0  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004c1be3:
    // 004c1be3  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c1be7  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004c1be9  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004c1beb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1bed  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x004c1bf0:
    // 004c1bf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1bf2  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004c1bf4  e89c000000             -call 0x4c1c95
    cpu.esp -= 4;
    sub_4c1c95(app, cpu);
    if (cpu.terminate) return;
    // 004c1bf9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c1bfd  39f0                   +cmp eax, esi
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
    // 004c1bff  7d1c                   -jge 0x4c1c1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c1c1d;
    }
    // 004c1c01  3b9f40ee4d00           +cmp ebx, dword ptr [edi + 0x4dee40]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5107264) /* 0x4dee40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1c07  7602                   -jbe 0x4c1c0b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c1c0b;
    }
    // 004c1c09  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004c1c0b:
    // 004c1c0b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c1c0d  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004c1c10  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c1c14  39c3                   +cmp ebx, eax
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
    // 004c1c16  7302                   -jae 0x4c1c1a
    if (!cpu.flags.cf)
    {
        goto L_0x004c1c1a;
    }
    // 004c1c18  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004c1c1a:
    // 004c1c1a  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c1c1b  ebd3                   -jmp 0x4c1bf0
    goto L_0x004c1bf0;
L_0x004c1c1d:
    // 004c1c1d  3b542404               +cmp edx, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1c21  7503                   -jne 0x4c1c26
    if (!cpu.flags.zf)
    {
        goto L_0x004c1c26;
    }
    // 004c1c23  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004c1c26:
    // 004c1c26  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c1c28  7403                   -je 0x4c1c2d
    if (cpu.flags.zf)
    {
        goto L_0x004c1c2d;
    }
    // 004c1c2a  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
L_0x004c1c2d:
    // 004c1c2d  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1c32  750f                   -jne 0x4c1c43
    if (!cpu.flags.zf)
    {
        goto L_0x004c1c43;
    }
    // 004c1c34  81fb00000080           +cmp ebx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1c3a  7207                   -jb 0x4c1c43
    if (cpu.flags.cf)
    {
        goto L_0x004c1c43;
    }
    // 004c1c3c  7509                   -jne 0x4c1c47
    if (!cpu.flags.zf)
    {
        goto L_0x004c1c47;
    }
    // 004c1c3e  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1c41  7504                   -jne 0x4c1c47
    if (!cpu.flags.zf)
    {
        goto L_0x004c1c47;
    }
L_0x004c1c43:
    // 004c1c43  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004c1c45  742c                   -je 0x4c1c73
    if (cpu.flags.zf)
    {
        goto L_0x004c1c73;
    }
L_0x004c1c47:
    // 004c1c47  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004c1c4c  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1c50  e8cb05feff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004c1c55  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c1c57  7507                   -jne 0x4c1c60
    if (!cpu.flags.zf)
    {
        goto L_0x004c1c60;
    }
    // 004c1c59  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c1c5e  eb1c                   -jmp 0x4c1c7c
    goto L_0x004c1c7c;
L_0x004c1c60:
    // 004c1c60  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1c63  7507                   -jne 0x4c1c6c
    if (!cpu.flags.zf)
    {
        goto L_0x004c1c6c;
    }
    // 004c1c65  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 004c1c6a  eb10                   -jmp 0x4c1c7c
    goto L_0x004c1c7c;
L_0x004c1c6c:
    // 004c1c6c  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 004c1c71  eb09                   -jmp 0x4c1c7c
    goto L_0x004c1c7c;
L_0x004c1c73:
    // 004c1c73  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1c76  7502                   -jne 0x4c1c7a
    if (!cpu.flags.zf)
    {
        goto L_0x004c1c7a;
    }
    // 004c1c78  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x004c1c7a:
    // 004c1c7a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004c1c7c:
    // 004c1c7c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c1c7f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c82  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1c83(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1c83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1c84  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c1c86  e8b9feffff             -call 0x4c1b44
    cpu.esp -= 4;
    sub_4c1b44(app, cpu);
    if (cpu.terminate) return;
    // 004c1c8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1c86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c1c86;
    // 004c1c83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1c84  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x004c1c86:
    // 004c1c86  e8b9feffff             -call 0x4c1b44
    cpu.esp -= 4;
    sub_4c1b44(app, cpu);
    if (cpu.terminate) return;
    // 004c1c8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1c8d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1c8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1c8e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004c1c93  ebf1                   -jmp 0x4c1c86
    return sub_4c1c86(app, cpu);
}

/* align: skip  */
void Application::sub_4c1c95(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1c95  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1c96  3c30                   +cmp al, 0x30
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
    // 004c1c98  720e                   -jb 0x4c1ca8
    if (cpu.flags.cf)
    {
        goto L_0x004c1ca8;
    }
    // 004c1c9a  3c39                   +cmp al, 0x39
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
    // 004c1c9c  770a                   -ja 0x4c1ca8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c1ca8;
    }
    // 004c1c9e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c1ca3  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004c1ca6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1ca7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1ca8:
    // 004c1ca8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c1cad  e8e836feff             -call 0x4a539a
    cpu.esp -= 4;
    sub_4a539a(app, cpu);
    if (cpu.terminate) return;
    // 004c1cb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1cb4  3c61                   +cmp al, 0x61
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1cb6  720d                   -jb 0x4c1cc5
    if (cpu.flags.cf)
    {
        goto L_0x004c1cc5;
    }
    // 004c1cb8  3c69                   +cmp al, 0x69
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(105 /*0x69*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1cba  7709                   -ja 0x4c1cc5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c1cc5;
    }
    // 004c1cbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1cbe  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004c1cc0  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004c1cc3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1cc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1cc5:
    // 004c1cc5  3c6a                   +cmp al, 0x6a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(106 /*0x6a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1cc7  720e                   -jb 0x4c1cd7
    if (cpu.flags.cf)
    {
        goto L_0x004c1cd7;
    }
    // 004c1cc9  3c72                   +cmp al, 0x72
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
    // 004c1ccb  770a                   -ja 0x4c1cd7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c1cd7;
    }
L_0x004c1ccd:
    // 004c1ccd  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c1cd2  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004c1cd5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1cd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1cd7:
    // 004c1cd7  3c73                   +cmp al, 0x73
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1cd9  7204                   -jb 0x4c1cdf
    if (cpu.flags.cf)
    {
        goto L_0x004c1cdf;
    }
    // 004c1cdb  3c7a                   +cmp al, 0x7a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(122 /*0x7a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1cdd  76ee                   -jbe 0x4c1ccd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c1ccd;
    }
L_0x004c1cdf:
    // 004c1cdf  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 004c1ce4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1ce5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1ce6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1ce6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c1ce7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1ce8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1ce9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1cea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1ceb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1cec  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004c1cef  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c1cf1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004c1cf6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004c1cfb  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004c1cfe  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004c1d03  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004c1d07  e8c8070000             -call 0x4c24d4
    cpu.esp -= 4;
    sub_4c24d4(app, cpu);
    if (cpu.terminate) return;
    // 004c1d0c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1d0e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1d10  7469                   -je 0x4c1d7b
    if (cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1d12  39e8                   +cmp eax, ebp
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
    // 004c1d14  7465                   -je 0x4c1d7b
    if (cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1d16  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c1d18  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004c1d1c  40                     -inc eax
    (cpu.eax)++;
    // 004c1d1d  e81104feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004c1d22  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1d24  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c1d28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1d2a  744f                   -je 0x4c1d7b
    if (cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1d2c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c1d30  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004c1d32  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c1d34  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c1d35  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c1d37  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c1d39  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1d3a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1d3c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c1d3f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c1d41  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c1d43  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c1d46  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c1d48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1d49  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c1d4a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c1d4e  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004c1d51  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004c1d55  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c1d57  e88ba2feff             -call 0x4abfe7
    cpu.esp -= 4;
    sub_4abfe7(app, cpu);
    if (cpu.terminate) return;
    // 004c1d5c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004c1d60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1d62  7446                   -je 0x4c1daa
    if (cpu.flags.zf)
    {
        goto L_0x004c1daa;
    }
    // 004c1d64  40                     -inc eax
    (cpu.eax)++;
    // 004c1d65  e8c903feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004c1d6a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1d6c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c1d70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1d72  7511                   -jne 0x4c1d85
    if (!cpu.flags.zf)
    {
        goto L_0x004c1d85;
    }
    // 004c1d74  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004c1d76:
    // 004c1d76  e83d53feff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
L_0x004c1d7b:
    // 004c1d7b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c1d80  e9af000000             -jmp 0x4c1e34
    goto L_0x004c1e34;
L_0x004c1d85:
    // 004c1d85  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004c1d89  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c1d8b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c1d8c  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c1d8e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c1d90  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1d91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1d93  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c1d96  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c1d98  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c1d9a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c1d9d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c1d9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1da0  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c1da1  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1da5  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004c1da8  eb04                   -jmp 0x4c1dae
    goto L_0x004c1dae;
L_0x004c1daa:
    // 004c1daa  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004c1dae:
    // 004c1dae  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1db2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1db3  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1db7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1db8  2eff1554454c00         -call dword ptr cs:[0x4c4554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998484) /* 0x4c4554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c1dbf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1dc1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1dc5  e8ee52feff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004c1dca  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1dce  e8e552feff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004c1dd3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c1dd5  74a4                   -je 0x4c1d7b
    if (cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1dd7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1dd9  e860000000             -call 0x4c1e3e
    cpu.esp -= 4;
    sub_4c1e3e(app, cpu);
    if (cpu.terminate) return;
    // 004c1dde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1de0  7599                   -jne 0x4c1d7b
    if (!cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1de2  833d78705b0000         +cmp dword ptr [0x5b7078], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5992568) /* 0x5b7078 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1de9  7449                   -je 0x4c1e34
    if (cpu.flags.zf)
    {
        goto L_0x004c1e34;
    }
    // 004c1deb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1ded  e8f5a1feff             -call 0x4abfe7
    cpu.esp -= 4;
    sub_4abfe7(app, cpu);
    if (cpu.terminate) return;
    // 004c1df2  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c1df5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004c1df8  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004c1dfb  e83303feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004c1e00  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c1e02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1e04  750f                   -jne 0x4c1e15
    if (!cpu.flags.zf)
    {
        goto L_0x004c1e15;
    }
    // 004c1e06  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004c1e0b  e8c102feff             -call 0x4a20d1
    cpu.esp -= 4;
    sub_4a20d1(app, cpu);
    if (cpu.terminate) return;
    // 004c1e10  e966ffffff             -jmp 0x4c1d7b
    goto L_0x004c1d7b;
L_0x004c1e15:
    // 004c1e15  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004c1e1a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c1e1c  e8e8a1feff             -call 0x4ac009
    cpu.esp -= 4;
    sub_4ac009(app, cpu);
    if (cpu.terminate) return;
    // 004c1e21  83f8ff                 +cmp eax, -1
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
    // 004c1e24  7507                   -jne 0x4c1e2d
    if (!cpu.flags.zf)
    {
        goto L_0x004c1e2d;
    }
    // 004c1e26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1e28  e949ffffff             -jmp 0x4c1d76
    goto L_0x004c1d76;
L_0x004c1e2d:
    // 004c1e2d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1e2f  e871cbffff             -call 0x4be9a5
    cpu.esp -= 4;
    sub_4be9a5(app, cpu);
    if (cpu.terminate) return;
L_0x004c1e34:
    // 004c1e34  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004c1e37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1e37(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c1e37;
    // 004c1ce6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c1ce7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1ce8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1ce9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1cea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1ceb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1cec  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004c1cef  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c1cf1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004c1cf6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004c1cfb  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004c1cfe  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004c1d03  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004c1d07  e8c8070000             -call 0x4c24d4
    cpu.esp -= 4;
    sub_4c24d4(app, cpu);
    if (cpu.terminate) return;
    // 004c1d0c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1d0e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1d10  7469                   -je 0x4c1d7b
    if (cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1d12  39e8                   +cmp eax, ebp
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
    // 004c1d14  7465                   -je 0x4c1d7b
    if (cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1d16  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c1d18  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004c1d1c  40                     -inc eax
    (cpu.eax)++;
    // 004c1d1d  e81104feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004c1d22  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1d24  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c1d28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1d2a  744f                   -je 0x4c1d7b
    if (cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1d2c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c1d30  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004c1d32  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c1d34  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c1d35  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c1d37  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c1d39  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1d3a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1d3c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c1d3f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c1d41  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c1d43  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c1d46  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c1d48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1d49  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c1d4a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c1d4e  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004c1d51  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004c1d55  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c1d57  e88ba2feff             -call 0x4abfe7
    cpu.esp -= 4;
    sub_4abfe7(app, cpu);
    if (cpu.terminate) return;
    // 004c1d5c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004c1d60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1d62  7446                   -je 0x4c1daa
    if (cpu.flags.zf)
    {
        goto L_0x004c1daa;
    }
    // 004c1d64  40                     -inc eax
    (cpu.eax)++;
    // 004c1d65  e8c903feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004c1d6a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1d6c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c1d70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1d72  7511                   -jne 0x4c1d85
    if (!cpu.flags.zf)
    {
        goto L_0x004c1d85;
    }
    // 004c1d74  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004c1d76:
    // 004c1d76  e83d53feff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
L_0x004c1d7b:
    // 004c1d7b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c1d80  e9af000000             -jmp 0x4c1e34
    goto L_0x004c1e34;
L_0x004c1d85:
    // 004c1d85  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004c1d89  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c1d8b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c1d8c  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c1d8e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c1d90  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1d91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1d93  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c1d96  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c1d98  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c1d9a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c1d9d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c1d9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1da0  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c1da1  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1da5  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004c1da8  eb04                   -jmp 0x4c1dae
    goto L_0x004c1dae;
L_0x004c1daa:
    // 004c1daa  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004c1dae:
    // 004c1dae  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1db2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1db3  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1db7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1db8  2eff1554454c00         -call dword ptr cs:[0x4c4554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998484) /* 0x4c4554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c1dbf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1dc1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1dc5  e8ee52feff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004c1dca  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1dce  e8e552feff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004c1dd3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c1dd5  74a4                   -je 0x4c1d7b
    if (cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1dd7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1dd9  e860000000             -call 0x4c1e3e
    cpu.esp -= 4;
    sub_4c1e3e(app, cpu);
    if (cpu.terminate) return;
    // 004c1dde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1de0  7599                   -jne 0x4c1d7b
    if (!cpu.flags.zf)
    {
        goto L_0x004c1d7b;
    }
    // 004c1de2  833d78705b0000         +cmp dword ptr [0x5b7078], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5992568) /* 0x5b7078 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1de9  7449                   -je 0x4c1e34
    if (cpu.flags.zf)
    {
        goto L_0x004c1e34;
    }
    // 004c1deb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1ded  e8f5a1feff             -call 0x4abfe7
    cpu.esp -= 4;
    sub_4abfe7(app, cpu);
    if (cpu.terminate) return;
    // 004c1df2  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c1df5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004c1df8  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004c1dfb  e83303feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004c1e00  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c1e02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1e04  750f                   -jne 0x4c1e15
    if (!cpu.flags.zf)
    {
        goto L_0x004c1e15;
    }
    // 004c1e06  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004c1e0b  e8c102feff             -call 0x4a20d1
    cpu.esp -= 4;
    sub_4a20d1(app, cpu);
    if (cpu.terminate) return;
    // 004c1e10  e966ffffff             -jmp 0x4c1d7b
    goto L_0x004c1d7b;
L_0x004c1e15:
    // 004c1e15  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004c1e1a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c1e1c  e8e8a1feff             -call 0x4ac009
    cpu.esp -= 4;
    sub_4ac009(app, cpu);
    if (cpu.terminate) return;
    // 004c1e21  83f8ff                 +cmp eax, -1
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
    // 004c1e24  7507                   -jne 0x4c1e2d
    if (!cpu.flags.zf)
    {
        goto L_0x004c1e2d;
    }
    // 004c1e26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1e28  e949ffffff             -jmp 0x4c1d76
    goto L_0x004c1d76;
L_0x004c1e2d:
    // 004c1e2d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1e2f  e871cbffff             -call 0x4be9a5
    cpu.esp -= 4;
    sub_4be9a5(app, cpu);
    if (cpu.terminate) return;
L_0x004c1e34:
    // 004c1e34  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_entry_0x004c1e37:
    // 004c1e37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1e3e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1e3e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c1e3f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1e40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1e41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1e42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1e43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1e44  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c1e47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1e48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1e4a  750a                   -jne 0x4c1e56
    if (!cpu.flags.zf)
    {
        goto L_0x004c1e56;
    }
L_0x004c1e4c:
    // 004c1e4c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c1e51  e94b010000             -jmp 0x4c1fa1
    goto L_0x004c1fa1;
L_0x004c1e56:
    // 004c1e56  803800                 +cmp byte ptr [eax], 0
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
    // 004c1e59  7411                   -je 0x4c1e6c
    if (cpu.flags.zf)
    {
        goto L_0x004c1e6c;
    }
    // 004c1e5b  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c1e5e  eb06                   -jmp 0x4c1e66
    goto L_0x004c1e66;
L_0x004c1e60:
    // 004c1e60  80ff3d                 +cmp bh, 0x3d
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1e63  7407                   -je 0x4c1e6c
    if (cpu.flags.zf)
    {
        goto L_0x004c1e6c;
    }
    // 004c1e65  42                     -inc edx
    (cpu.edx)++;
L_0x004c1e66:
    // 004c1e66  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 004c1e68  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004c1e6a  75f4                   -jne 0x4c1e60
    if (!cpu.flags.zf)
    {
        goto L_0x004c1e60;
    }
L_0x004c1e6c:
    // 004c1e6c  803a00                 +cmp byte ptr [edx], 0
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
    // 004c1e6f  74db                   -je 0x4c1e4c
    if (cpu.flags.zf)
    {
        goto L_0x004c1e4c;
    }
    // 004c1e71  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 004c1e75  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004c1e78  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 004c1e7b  a174705b00             -mov eax, dword ptr [0x5b7074]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5992564) /* 0x5b7074 */);
    // 004c1e80  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c1e84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1e86  7531                   -jne 0x4c1eb9
    if (!cpu.flags.zf)
    {
        goto L_0x004c1eb9;
    }
    // 004c1e88  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c1e8a  0f8511010000           -jne 0x4c1fa1
    if (!cpu.flags.zf)
    {
        goto L_0x004c1fa1;
    }
    // 004c1e90  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004c1e95  e89902feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004c1e9a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c1e9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1ea0  74aa                   -je 0x4c1e4c
    if (cpu.flags.zf)
    {
        goto L_0x004c1e4c;
    }
    // 004c1ea2  a374705b00             -mov dword ptr [0x5b7074], eax
    app->getMemory<x86::reg32>(x86::reg32(5992564) /* 0x5b7074 */) = cpu.eax;
    // 004c1ea7  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 004c1ea9  83c008                 +add eax, 8
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
    // 004c1eac  8968fc                 -mov dword ptr [eax - 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 004c1eaf  a370705b00             -mov dword ptr [0x5b7070], eax
    app->getMemory<x86::reg32>(x86::reg32(5992560) /* 0x5b7070 */) = cpu.eax;
    // 004c1eb4  e9cd000000             -jmp 0x4c1f86
    goto L_0x004c1f86;
L_0x004c1eb9:
    // 004c1eb9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004c1ebc  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c1ebe  e8e6000000             -call 0x4c1fa9
    cpu.esp -= 4;
    sub_4c1fa9(app, cpu);
    if (cpu.terminate) return;
    // 004c1ec3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c1ec5  0f85d4000000           -jne 0x4c1f9f
    if (!cpu.flags.zf)
    {
        goto L_0x004c1f9f;
    }
    // 004c1ecb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1ecd  0f8fb0000000           -jg 0x4c1f83
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c1f83;
    }
    // 004c1ed3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c1ed5  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 004c1ed7  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004c1eda  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004c1edc  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004c1edf  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004c1ee2  8b3570705b00           -mov esi, dword ptr [0x5b7070]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5992560) /* 0x5b7070 */);
    // 004c1ee8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c1eec  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1eee  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c1ef0  7545                   -jne 0x4c1f37
    if (!cpu.flags.zf)
    {
        goto L_0x004c1f37;
    }
    // 004c1ef2  e83c02feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004c1ef7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1ef9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c1efd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1eff  0f8447ffffff           -je 0x4c1e4c
    if (cpu.flags.zf)
    {
        goto L_0x004c1e4c;
    }
    // 004c1f05  8b3574705b00           -mov esi, dword ptr [0x5b7074]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5992564) /* 0x5b7074 */);
    // 004c1f0b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c1f0d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c1f0e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c1f10  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c1f12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1f13  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1f15  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c1f18  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c1f1a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c1f1c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c1f1f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c1f21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1f22  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c1f23  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c1f27  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c1f29  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c1f2b  a370705b00             -mov dword ptr [0x5b7070], eax
    app->getMemory<x86::reg32>(x86::reg32(5992560) /* 0x5b7070 */) = cpu.eax;
    // 004c1f30  e83ab6fcff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 004c1f35  eb32                   -jmp 0x4c1f69
    goto L_0x004c1f69;
L_0x004c1f37:
    // 004c1f37  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1f39  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1f3d  e869a5feff             -call 0x4ac4ab
    cpu.esp -= 4;
    sub_4ac4ab(app, cpu);
    if (cpu.terminate) return;
    // 004c1f42  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c1f46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1f48  0f84fefeffff           -je 0x4c1e4c
    if (cpu.flags.zf)
    {
        goto L_0x004c1e4c;
    }
    // 004c1f4e  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c1f52  8b1570705b00           -mov edx, dword ptr [0x5b7070]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5992560) /* 0x5b7070 */);
    // 004c1f58  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c1f5a  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004c1f5c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1f5e  e8c2a5feff             -call 0x4ac525
    cpu.esp -= 4;
    sub_4ac525(app, cpu);
    if (cpu.terminate) return;
    // 004c1f63  890d70705b00           -mov dword ptr [0x5b7070], ecx
    app->getMemory<x86::reg32>(x86::reg32(5992560) /* 0x5b7070 */) = cpu.ecx;
L_0x004c1f69:
    // 004c1f69  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1f6b  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1f6f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c1f72  01f8                   +add eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1f74  893d74705b00           -mov dword ptr [0x5b7074], edi
    app->getMemory<x86::reg32>(x86::reg32(5992564) /* 0x5b7074 */) = cpu.edi;
    // 004c1f7a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c1f81  eb03                   -jmp 0x4c1f86
    goto L_0x004c1f86;
L_0x004c1f83:
    // 004c1f83  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004c1f86:
    // 004c1f86  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1f88  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1f8c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c1f8f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c1f91  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004c1f94  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004c1f96  a170705b00             -mov eax, dword ptr [0x5b7070]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5992560) /* 0x5b7070 */);
    // 004c1f9b  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x004c1f9f:
    // 004c1f9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c1fa1:
    // 004c1fa1  83c40c                 +add esp, 0xc
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
    // 004c1fa4  e98efeffff             -jmp 0x4c1e37
    return sub_4c1e37(app, cpu);
}

/* align: skip  */
void Application::sub_4c1fa9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1fa9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c1faa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1fab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1fac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1fad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1fae  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c1fb0  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004c1fb2  8b3574705b00           -mov esi, dword ptr [0x5b7074]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5992564) /* 0x5b7074 */);
    // 004c1fb8  e9b2000000             -jmp 0x4c206f
    goto L_0x004c206f;
L_0x004c1fbd:
    // 004c1fbd  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004c1fbf  e99f000000             -jmp 0x4c2063
    goto L_0x004c2063;
L_0x004c1fc4:
    // 004c1fc4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1fc6  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004c1fc8  e8c529fcff             -call 0x484992
    cpu.esp -= 4;
    sub_484992(app, cpu);
    if (cpu.terminate) return;
    // 004c1fcd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c1fcf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1fd1  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004c1fd3  e8ba29fcff             -call 0x484992
    cpu.esp -= 4;
    sub_484992(app, cpu);
    if (cpu.terminate) return;
    // 004c1fd8  39c1                   +cmp ecx, eax
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
    // 004c1fda  0f858c000000           -jne 0x4c206c
    if (!cpu.flags.zf)
    {
        goto L_0x004c206c;
    }
    // 004c1fe0  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1fe3  0f8578000000           -jne 0x4c2061
    if (!cpu.flags.zf)
    {
        goto L_0x004c2061;
    }
    // 004c1fe9  8b1574705b00           -mov edx, dword ptr [0x5b7074]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5992564) /* 0x5b7074 */);
    // 004c1fef  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004c1ff1  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1ff3  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004c1ff6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c1ff8  7462                   -je 0x4c205c
    if (cpu.flags.zf)
    {
        goto L_0x004c205c;
    }
    // 004c1ffa  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004c1ffc  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004c1ffe  eb08                   -jmp 0x4c2008
    goto L_0x004c2008;
L_0x004c2000:
    // 004c2000  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004c2003  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004c2005  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004c2008:
    // 004c2008  833900                 +cmp dword ptr [ecx], 0
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
    // 004c200b  75f3                   -jne 0x4c2000
    if (!cpu.flags.zf)
    {
        goto L_0x004c2000;
    }
    // 004c200d  8b3570705b00           -mov esi, dword ptr [0x5b7070]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5992560) /* 0x5b7070 */);
    // 004c2013  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c2015  7441                   -je 0x4c2058
    if (cpu.flags.zf)
    {
        goto L_0x004c2058;
    }
    // 004c2017  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c2019  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c201d  7407                   -je 0x4c2026
    if (cpu.flags.zf)
    {
        goto L_0x004c2026;
    }
    // 004c201f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c2021  e89250feff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
L_0x004c2026:
    // 004c2026  8b2d74705b00           -mov ebp, dword ptr [0x5b7074]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5992564) /* 0x5b7074 */);
    // 004c202c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c202e  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c2030  8b1570705b00           -mov edx, dword ptr [0x5b7070]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5992560) /* 0x5b7070 */);
    // 004c2036  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004c2039  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c203b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004c203d  e8e3a4feff             -call 0x4ac525
    cpu.esp -= 4;
    sub_4ac525(app, cpu);
    if (cpu.terminate) return;
    // 004c2042  890d70705b00           -mov dword ptr [0x5b7070], ecx
    app->getMemory<x86::reg32>(x86::reg32(5992560) /* 0x5b7070 */) = cpu.ecx;
    // 004c2048  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004c204b  eb07                   -jmp 0x4c2054
    goto L_0x004c2054;
L_0x004c204d:
    // 004c204d  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c2050  47                     -inc edi
    (cpu.edi)++;
    // 004c2051  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004c2053  40                     -inc eax
    (cpu.eax)++;
L_0x004c2054:
    // 004c2054  39f7                   +cmp edi, esi
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
    // 004c2056  7cf5                   -jl 0x4c204d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c204d;
    }
L_0x004c2058:
    // 004c2058  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c205a  eb27                   -jmp 0x4c2083
    goto L_0x004c2083;
L_0x004c205c:
    // 004c205c  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004c205f  eb22                   -jmp 0x4c2083
    goto L_0x004c2083;
L_0x004c2061:
    // 004c2061  42                     -inc edx
    (cpu.edx)++;
    // 004c2062  43                     -inc ebx
    (cpu.ebx)++;
L_0x004c2063:
    // 004c2063  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c2066  0f8558ffffff           -jne 0x4c1fc4
    if (!cpu.flags.zf)
    {
        goto L_0x004c1fc4;
    }
L_0x004c206c:
    // 004c206c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004c206f:
    // 004c206f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004c2071  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c2073  0f8544ffffff           -jne 0x4c1fbd
    if (!cpu.flags.zf)
    {
        goto L_0x004c1fbd;
    }
    // 004c2079  a174705b00             -mov eax, dword ptr [0x5b7074]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5992564) /* 0x5b7074 */);
    // 004c207e  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004c2080  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004c2083:
    // 004c2083  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2084  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2085  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2086  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2087  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2088  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2089(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2089  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c208a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x004c208c:
    // 004c208c  663b18                 +cmp bx, word ptr [eax]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c208f  740c                   -je 0x4c209d
    if (cpu.flags.zf)
    {
        goto L_0x004c209d;
    }
    // 004c2091  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c2093  40                     -inc eax
    (cpu.eax)++;
    // 004c2094  40                     -inc eax
    (cpu.eax)++;
    // 004c2095  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c2099  75f1                   -jne 0x4c208c
    if (!cpu.flags.zf)
    {
        goto L_0x004c208c;
    }
    // 004c209b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c209d:
    // 004c209d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c209e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c20a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c20a0  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c20a2  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c20a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c20a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c20a5  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c20aa  e881040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20af  eb1d                   -jmp 0x4c20ce
    goto L_0x004c20ce;
    // 004c20b1  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c20b6  e875040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20bb  eb11                   -jmp 0x4c20ce
    goto L_0x004c20ce;
    // 004c20bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c20be  e87201feff             -call 0x4a2235
    cpu.esp -= 4;
    sub_4a2235(app, cpu);
    if (cpu.terminate) return;
    // 004c20c3  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 004c20c8  e863040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20cd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c20ce:
    // 004c20ce  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c20d3  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c20d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c20da  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c20dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c20bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c20bd;
    // 004c20a5  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c20aa  e881040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20af  eb1d                   -jmp 0x4c20ce
    goto L_0x004c20ce;
    // 004c20b1  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c20b6  e875040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20bb  eb11                   -jmp 0x4c20ce
    goto L_0x004c20ce;
L_entry_0x004c20bd:
    // 004c20bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c20be  e87201feff             -call 0x4a2235
    cpu.esp -= 4;
    sub_4a2235(app, cpu);
    if (cpu.terminate) return;
    // 004c20c3  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 004c20c8  e863040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20cd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c20ce:
    // 004c20ce  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c20d3  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c20d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c20da  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c20dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c20b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c20b1;
    // 004c20a5  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c20aa  e881040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20af  eb1d                   -jmp 0x4c20ce
    goto L_0x004c20ce;
L_entry_0x004c20b1:
    // 004c20b1  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c20b6  e875040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20bb  eb11                   -jmp 0x4c20ce
    goto L_0x004c20ce;
    // 004c20bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c20be  e87201feff             -call 0x4a2235
    cpu.esp -= 4;
    sub_4a2235(app, cpu);
    if (cpu.terminate) return;
    // 004c20c3  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 004c20c8  e863040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20cd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c20ce:
    // 004c20ce  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c20d3  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c20d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c20da  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c20dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c20dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c20dd  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c20e2  e849040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20e7  eb11                   -jmp 0x4c20fa
    goto L_0x004c20fa;
    // 004c20e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c20ea  e84601feff             -call 0x4a2235
    cpu.esp -= 4;
    sub_4a2235(app, cpu);
    if (cpu.terminate) return;
    // 004c20ef  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 004c20f4  e837040000             -call 0x4c2530
    cpu.esp -= 4;
    sub_4c2530(app, cpu);
    if (cpu.terminate) return;
    // 004c20f9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c20fa:
    // 004c20fa  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c20ff  0d0000807f             -or eax, 0x7f800000
    cpu.eax |= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 004c2104  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4c2108(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2108  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2109  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c210b  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004c210c  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c210f  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c2112  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004c2115  83f907                 +cmp ecx, 7
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
    // 004c2118  7e42                   -jle 0x4c215c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c215c;
    }
    // 004c211a  83e907                 -sub ecx, 7
    (cpu.ecx) -= x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004c211d:
    // 004c211d  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 004c211f  df4702                 -fild word ptr [edi + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */))));
    // 004c2122  df4704                 -fild word ptr [edi + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 004c2125  df4706                 -fild word ptr [edi + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */))));
    // 004c2128  df4708                 -fild word ptr [edi + 8]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 004c212b  df470a                 -fild word ptr [edi + 0xa]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */))));
    // 004c212e  df470c                 -fild word ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 004c2131  df470e                 -fild word ptr [edi + 0xe]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(14) /* 0xe */))));
    // 004c2134  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 004c2136  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2139  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c213c  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c213f  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2142  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2145  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2148  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c214b  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c214e  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c2151  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004c2154  83e908                 +sub ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c2157  7fc4                   -jg 0x4c211d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c211d;
    }
    // 004c2159  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004c215c:
    // 004c215c  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c215f  7e10                   -jle 0x4c2171
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c2171;
    }
    // 004c2161  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 004c2163  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2166  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004c2169  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c216c  83e901                 +sub ecx, 1
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
    // 004c216f  7feb                   -jg 0x4c215c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c215c;
    }
L_0x004c2171:
    // 004c2171  61                     -popal 
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
    // 004c2172  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2173  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2174(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2174  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2175  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c2177  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004c2178  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c217b  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c217e  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004c2181  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c2183  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2185  83f903                 +cmp ecx, 3
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
    // 004c2188  7e44                   -jle 0x4c21ce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c21ce;
    }
    // 004c218a  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004c218d:
    // 004c218d  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004c218f  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004c2192  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2195  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c2198  8b1c85a4815b00         -mov ebx, dword ptr [eax*4 + 0x5b81a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5996964) /* 0x5b81a4 */ + cpu.eax * 4);
    // 004c219f  8b3495a4815b00         -mov esi, dword ptr [edx*4 + 0x5b81a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5996964) /* 0x5b81a4 */ + cpu.edx * 4);
    // 004c21a6  8a47fe                 -mov al, byte ptr [edi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 004c21a9  8a57ff                 -mov dl, byte ptr [edi - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004c21ac  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004c21af  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 004c21b2  8b1c85a4815b00         -mov ebx, dword ptr [eax*4 + 0x5b81a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5996964) /* 0x5b81a4 */ + cpu.eax * 4);
    // 004c21b9  8b3495a4815b00         -mov esi, dword ptr [edx*4 + 0x5b81a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5996964) /* 0x5b81a4 */ + cpu.edx * 4);
    // 004c21c0  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004c21c3  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004c21c6  83e904                 +sub ecx, 4
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
    // 004c21c9  7fc2                   -jg 0x4c218d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c218d;
    }
    // 004c21cb  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004c21ce:
    // 004c21ce  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c21d1  7e17                   -jle 0x4c21ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c21ea;
    }
    // 004c21d3  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004c21d5  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004c21d8  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c21db  8b1c85a4815b00         -mov ebx, dword ptr [eax*4 + 0x5b81a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5996964) /* 0x5b81a4 */ + cpu.eax * 4);
    // 004c21e2  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004c21e5  83e901                 +sub ecx, 1
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
    // 004c21e8  7fe4                   -jg 0x4c21ce
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c21ce;
    }
L_0x004c21ea:
    // 004c21ea  61                     -popal 
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
    // 004c21eb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c21ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c21ed(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c21ed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c21ee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c21ef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c21f0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c21f1  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004c21f3  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004c21f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c21f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c21f8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c21fb  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004c21fe  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004c2200  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004c2203  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004c2206  8b15ec435b00           -mov edx, dword ptr [0x5b43ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5981164) /* 0x5b43ec */);
    // 004c220c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004c220e  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004c2211  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004c2214  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c2216  753e                   -jne 0x4c2256
    if (!cpu.flags.zf)
    {
        goto L_0x004c2256;
    }
    // 004c2218  a17ce74d00             -mov eax, dword ptr [0x4de77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5105532) /* 0x4de77c */);
    // 004c221d  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004c2220  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004c2222  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c2224  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004c2226  8b1d7ce74d00           -mov ebx, dword ptr [0x4de77c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5105532) /* 0x4de77c */);
    // 004c222c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c222e  e83cb3fcff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 004c2233  a17ce74d00             -mov eax, dword ptr [0x4de77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5105532) /* 0x4de77c */);
    // 004c2238  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 004c223e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c2240  e82443ffff             -call 0x4b6569
    cpu.esp -= 4;
    sub_4b6569(app, cpu);
    if (cpu.terminate) return;
    // 004c2245  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2247  750d                   -jne 0x4c2256
    if (!cpu.flags.zf)
    {
        goto L_0x004c2256;
    }
    // 004c2249  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004c224c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c224d  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2254  eb32                   -jmp 0x4c2288
    goto L_0x004c2288;
L_0x004c2256:
    // 004c2256  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004c2259  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c225f  8998de000000           -mov dword ptr [eax + 0xde], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */) = cpu.ebx;
    // 004c2265  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004c2268  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c2269  2eff155c454c00         -call dword ptr cs:[0x4c455c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998492) /* 0x4c455c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2270  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c2273  e8cb4affff             -call 0x4b6d43
    cpu.esp -= 4;
    sub_4b6d43(app, cpu);
    if (cpu.terminate) return;
    // 004c2278  ff155ccb4d00           -call dword ptr [0x4dcb5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098332) /* 0x4dcb5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c227e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c2280  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2283  e872f5ffff             -call 0x4c17fa
    cpu.esp -= 4;
    sub_4c17fa(app, cpu);
    if (cpu.terminate) return;
L_0x004c2288:
    // 004c2288  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004c228a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c228b  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c228d  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c228f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c2290  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2291  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2292  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2293  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2294(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2294  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c2295  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c2296  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c2297  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c2298  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2299  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004c229c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c229e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004c22a0  833d18cb4d00ff         +cmp dword ptr [0x4dcb18], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c22a7  7512                   -jne 0x4c22bb
    if (!cpu.flags.zf)
    {
        goto L_0x004c22bb;
    }
    // 004c22a9  e86642ffff             -call 0x4b6514
    cpu.esp -= 4;
    sub_4b6514(app, cpu);
    if (cpu.terminate) return;
    // 004c22ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c22b0  0f84ae000000           -je 0x4c2364
    if (cpu.flags.zf)
    {
        goto L_0x004c2364;
    }
    // 004c22b6  e87e43ffff             -call 0x4b6639
    cpu.esp -= 4;
    sub_4b6639(app, cpu);
    if (cpu.terminate) return;
L_0x004c22bb:
    // 004c22bb  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004c22bf  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004c22c3  2eff15a4444c00         -call dword ptr cs:[0x4c44a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998308) /* 0x4c44a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c22ca  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004c22ce  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c22d0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004c22d2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c22d4  be18fe4c00             -mov esi, 0x4cfe18
    cpu.esi = 5045784 /*0x4cfe18*/;
    // 004c22d9  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004c22de  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004c22df  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004c22e0  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c22e1  2eff15a0444c00         -call dword ptr cs:[0x4c44a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998304) /* 0x4c44a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c22e8  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c22ec  e8ed78ffff             -call 0x4b9bde
    cpu.esp -= 4;
    sub_4b9bde(app, cpu);
    if (cpu.terminate) return;
    // 004c22f1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c22f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c22f4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c22f6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c22f8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c22fa  2eff152c444c00         -call dword ptr cs:[0x4c442c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998188) /* 0x4c442c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2301  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004c2305  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004c2309  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004c230d  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004c2311  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c2312  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c2314  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004c2318  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c2319  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004c231f  68ed214c00             -push 0x4c21ed
    app->getMemory<x86::reg32>(cpu.esp-4) = 4989421 /*0x4c21ed*/;
    cpu.esp -= 4;
    // 004c2324  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 004c232a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c232b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c232d  2eff153c444c00         -call dword ptr cs:[0x4c443c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998204) /* 0x4c443c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2334  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004c2338  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c233a  750a                   -jne 0x4c2346
    if (!cpu.flags.zf)
    {
        goto L_0x004c2346;
    }
    // 004c233c  c7442438ffffffff       -mov dword ptr [esp + 0x38], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 4294967295 /*0xffffffff*/;
    // 004c2344  eb0e                   -jmp 0x4c2354
    goto L_0x004c2354;
L_0x004c2346:
    // 004c2346  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004c2348  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004c234c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c234d  2eff15ac454c00         -call dword ptr cs:[0x4c45ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998572) /* 0x4c45ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2354:
    // 004c2354  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004c2358  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c2359  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2360  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
L_0x004c2364:
    // 004c2364  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004c2367  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2368  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c2369  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c236a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c236b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c236c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c236d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c236d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c236e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c236f  ff1560cb4d00           -call dword ptr [0x4dcb60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098336) /* 0x4dcb60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2375  e8154affff             -call 0x4b6d8f
    cpu.esp -= 4;
    sub_4b6d8f(app, cpu);
    if (cpu.terminate) return;
    // 004c237a  833dec435b0000         +cmp dword ptr [0x5b43ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5981164) /* 0x5b43ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2381  750a                   -jne 0x4c238d
    if (!cpu.flags.zf)
    {
        goto L_0x004c238d;
    }
    // 004c2383  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004c2388  e82b42ffff             -call 0x4b65b8
    cpu.esp -= 4;
    sub_4b65b8(app, cpu);
    if (cpu.terminate) return;
L_0x004c238d:
    // 004c238d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c238f  2eff155c444c00         -call dword ptr cs:[0x4c445c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998236) /* 0x4c445c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2396  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2397  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2398  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2399(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2399  a3f0ee4d00             -mov dword ptr [0x4deef0], eax
    app->getMemory<x86::reg32>(x86::reg32(5107440) /* 0x4deef0 */) = cpu.eax;
    // 004c239e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c239f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c239f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c23a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c23a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c23a2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c23a4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004c23a6  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004c23ab  e88d010000             -call 0x4c253d
    cpu.esp -= 4;
    sub_4c253d(app, cpu);
    if (cpu.terminate) return;
    // 004c23b0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c23b2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c23b4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c23b6  8b0485d4ee4d00         -mov eax, dword ptr [eax*4 + 0x4deed4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107412) /* 0x4deed4 */ + cpu.eax * 4);
    // 004c23bd  e89a010000             -call 0x4c255c
    cpu.esp -= 4;
    sub_4c255c(app, cpu);
    if (cpu.terminate) return;
    // 004c23c2  b8a9fe4c00             -mov eax, 0x4cfea9
    cpu.eax = 5045929 /*0x4cfea9*/;
    // 004c23c7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c23c9  e88e010000             -call 0x4c255c
    cpu.esp -= 4;
    sub_4c255c(app, cpu);
    if (cpu.terminate) return;
    // 004c23ce  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c23d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c23d2  e885010000             -call 0x4c255c
    cpu.esp -= 4;
    sub_4c255c(app, cpu);
    if (cpu.terminate) return;
    // 004c23d7  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004c23dc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c23de  e8c2c8feff             -call 0x4aeca5
    cpu.esp -= 4;
    sub_4aeca5(app, cpu);
    if (cpu.terminate) return;
    // 004c23e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c23e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c23e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c23e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c23e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c23e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c23e8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c23e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c23eb  ff15f0ee4d00           -call dword ptr [0x4deef0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107440) /* 0x4deef0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c23f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c23f3  751b                   -jne 0x4c2410
    if (!cpu.flags.zf)
    {
        goto L_0x004c2410;
    }
    // 004c23f5  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c23f8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c23fa  e8a0ffffff             -call 0x4c239f
    cpu.esp -= 4;
    sub_4c239f(app, cpu);
    if (cpu.terminate) return;
    // 004c23ff  833b01                 +cmp dword ptr [ebx], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2402  7507                   -jne 0x4c240b
    if (!cpu.flags.zf)
    {
        goto L_0x004c240b;
    }
    // 004c2404  e825fefdff             -call 0x4a222e
    cpu.esp -= 4;
    sub_4a222e(app, cpu);
    if (cpu.terminate) return;
    // 004c2409  eb05                   -jmp 0x4c2410
    goto L_0x004c2410;
L_0x004c240b:
    // 004c240b  e825fefdff             -call 0x4a2235
    cpu.esp -= 4;
    sub_4a2235(app, cpu);
    if (cpu.terminate) return;
L_0x004c2410:
    // 004c2410  dd4318                 -fld qword ptr [ebx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 004c2413  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2414  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2415  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2416(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2416  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c2417  833d90805b0000         +cmp dword ptr [0x5b8090], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c241e  7428                   -je 0x4c2448
    if (cpu.flags.zf)
    {
        goto L_0x004c2448;
    }
    // 004c2420  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2422  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c2424  8a9295805b00           -mov dl, byte ptr [edx + 0x5b8095]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5996693) /* 0x5b8095 */);
    // 004c242a  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c242d  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c2433  7413                   -je 0x4c2448
    if (cpu.flags.zf)
    {
        goto L_0x004c2448;
    }
    // 004c2435  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2437  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c2439  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004c243c  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c243f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c2444  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2446  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2447  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c2448:
    // 004c2448  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004c244a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c244f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2450  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2451(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2451  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c2452  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c2453  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c2454  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2457  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c2459  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c245b  e85a000000             -call 0x4c24ba
    cpu.esp -= 4;
    sub_4c24ba(app, cpu);
    if (cpu.terminate) return;
    // 004c2460  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c2462  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004c2464  e898b4ffff             -call 0x4bd901
    cpu.esp -= 4;
    sub_4bd901(app, cpu);
    if (cpu.terminate) return;
    // 004c2469  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004c246c  813d98e84d00a4030000   +cmp dword ptr [0x4de898], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5105816) /* 0x4de898 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2476  7526                   -jne 0x4c249e
    if (!cpu.flags.zf)
    {
        goto L_0x004c249e;
    }
    // 004c2478  833d90805b0000         +cmp dword ptr [0x5b8090], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c247f  741d                   -je 0x4c249e
    if (cpu.flags.zf)
    {
        goto L_0x004c249e;
    }
    // 004c2481  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c2483  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004c2486  8a8095805b00           -mov al, byte ptr [eax + 0x5b8095]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5996693) /* 0x5b8095 */);
    // 004c248c  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c248e  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c2493  7409                   -je 0x4c249e
    if (cpu.flags.zf)
    {
        goto L_0x004c249e;
    }
    // 004c2495  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c2497  e856010000             -call 0x4c25f2
    cpu.esp -= 4;
    sub_4c25f2(app, cpu);
    if (cpu.terminate) return;
    // 004c249c  eb15                   -jmp 0x4c24b3
    goto L_0x004c24b3;
L_0x004c249e:
    // 004c249e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004c24a0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c24a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c24a5  2eff1598434c00         -call dword ptr cs:[0x4c4398]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998040) /* 0x4c4398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c24ac  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c24ae  e863ffffff             -call 0x4c2416
    cpu.esp -= 4;
    sub_4c2416(app, cpu);
    if (cpu.terminate) return;
L_0x004c24b3:
    // 004c24b3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c24b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c24b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c24b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c24b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c24ba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c24ba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c24bb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c24bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c24bf  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 004c24c2  740c                   -je 0x4c24d0
    if (cpu.flags.zf)
    {
        goto L_0x004c24d0;
    }
    // 004c24c4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c24c6  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004c24c9  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004c24cc  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004c24ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c24cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c24d0:
    // 004c24d0  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004c24d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c24d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c24d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c24d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c24d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c24d6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c24d9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c24db  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004c24dd  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c24df  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c24e1  e8d4ffffff             -call 0x4c24ba
    cpu.esp -= 4;
    sub_4c24ba(app, cpu);
    if (cpu.terminate) return;
    // 004c24e6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c24e8  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004c24ea  e812b4ffff             -call 0x4bd901
    cpu.esp -= 4;
    sub_4bd901(app, cpu);
    if (cpu.terminate) return;
    // 004c24ef  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x004c24f2:
    // 004c24f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c24f4  e83069ffff             -call 0x4b8e29
    cpu.esp -= 4;
    sub_4b8e29(app, cpu);
    if (cpu.terminate) return;
    // 004c24f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c24fb  7518                   -jne 0x4c2515
    if (!cpu.flags.zf)
    {
        goto L_0x004c2515;
    }
    // 004c24fd  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c24ff  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c2501  e8e6f5ffff             -call 0x4c1aec
    cpu.esp -= 4;
    sub_4c1aec(app, cpu);
    if (cpu.terminate) return;
    // 004c2506  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2508  740b                   -je 0x4c2515
    if (cpu.flags.zf)
    {
        goto L_0x004c2515;
    }
    // 004c250a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c250c  e85469ffff             -call 0x4b8e65
    cpu.esp -= 4;
    sub_4b8e65(app, cpu);
    if (cpu.terminate) return;
    // 004c2511  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c2513  ebdd                   -jmp 0x4c24f2
    goto L_0x004c24f2;
L_0x004c2515:
    // 004c2515  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c2517  e80d69ffff             -call 0x4b8e29
    cpu.esp -= 4;
    sub_4b8e29(app, cpu);
    if (cpu.terminate) return;
    // 004c251c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c251e  7404                   -je 0x4c2524
    if (cpu.flags.zf)
    {
        goto L_0x004c2524;
    }
    // 004c2520  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004c2522  7504                   -jne 0x4c2528
    if (!cpu.flags.zf)
    {
        goto L_0x004c2528;
    }
L_0x004c2524:
    // 004c2524  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c2526  eb02                   -jmp 0x4c252a
    goto L_0x004c252a;
L_0x004c2528:
    // 004c2528  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c252a:
    // 004c252a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c252d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c252e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c252f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2530  ff15e3b84d00           -call dword ptr [0x4db8e3]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093603) /* 0x4db8e3 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2536  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c2538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2538  e9c8000000             -jmp 0x4c2605
    return sub_4c2605(app, cpu);
}

/* align: skip  */
void Application::sub_4c253d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c253d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c253e  83f803                 +cmp eax, 3
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
    // 004c2541  7604                   -jbe 0x4c2547
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c2547;
    }
    // 004c2543  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c2545  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2546  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c2547:
    // 004c2547  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c2549  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c254c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c254e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c2551  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c2553  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c2555  0508c94d00             -add eax, 0x4dc908
    (cpu.eax) += x86::reg32(x86::sreg32(5097736 /*0x4dc908*/));
    // 004c255a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c255b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c255c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c255c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c255d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c255e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c255f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c2560  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2561  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c2563  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c2565  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004c2568  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c256e  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004c2571  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004c2575  7507                   -jne 0x4c257e
    if (!cpu.flags.zf)
    {
        goto L_0x004c257e;
    }
    // 004c2577  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c2579  e84d98feff             -call 0x4abdcb
    cpu.esp -= 4;
    sub_4abdcb(app, cpu);
    if (cpu.terminate) return;
L_0x004c257e:
    // 004c257e  8a630d                 -mov ah, byte ptr [ebx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004c2581  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004c2583  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004c2586  7415                   -je 0x4c259d
    if (cpu.flags.zf)
    {
        goto L_0x004c259d;
    }
    // 004c2588  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004c258a  80e2f9                 -and dl, 0xf9
    cpu.dl &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004c258d  88530d                 -mov byte ptr [ebx + 0xd], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.dl;
    // 004c2590  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004c2592  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004c2595  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004c259a  88730d                 -mov byte ptr [ebx + 0xd], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.dh;
L_0x004c259d:
    // 004c259d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004c259f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004c25a1:
    // 004c25a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c25a3  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004c25a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c25a7  740f                   -je 0x4c25b8
    if (cpu.flags.zf)
    {
        goto L_0x004c25b8;
    }
    // 004c25a9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c25ab  41                     -inc ecx
    (cpu.ecx)++;
    // 004c25ac  e8f4c6feff             -call 0x4aeca5
    cpu.esp -= 4;
    sub_4aeca5(app, cpu);
    if (cpu.terminate) return;
    // 004c25b1  83f8ff                 +cmp eax, -1
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
    // 004c25b4  75eb                   -jne 0x4c25a1
    if (!cpu.flags.zf)
    {
        goto L_0x004c25a1;
    }
    // 004c25b6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004c25b8:
    // 004c25b8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004c25ba  741d                   -je 0x4c25d9
    if (cpu.flags.zf)
    {
        goto L_0x004c25d9;
    }
    // 004c25bc  8a430d                 -mov al, byte ptr [ebx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004c25bf  24f9                   -and al, 0xf9
    cpu.al &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004c25c1  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004c25c4  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004c25c6  80cc04                 -or ah, 4
    cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004c25c9  88630d                 -mov byte ptr [ebx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004c25cc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c25ce  7509                   -jne 0x4c25d9
    if (!cpu.flags.zf)
    {
        goto L_0x004c25d9;
    }
    // 004c25d0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c25d2  e87848feff             -call 0x4a6e4f
    cpu.esp -= 4;
    sub_4a6e4f(app, cpu);
    if (cpu.terminate) return;
    // 004c25d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004c25d9:
    // 004c25d9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c25db  7504                   -jne 0x4c25e1
    if (!cpu.flags.zf)
    {
        goto L_0x004c25e1;
    }
    // 004c25dd  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c25df  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004c25e1:
    // 004c25e1  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c25e4  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c25ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c25ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c25ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c25ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c25ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c25f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c25f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c25f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c25f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c25f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c25f5  e80e000000             -call 0x4c2608
    cpu.esp -= 4;
    sub_4c2608(app, cpu);
    if (cpu.terminate) return;
    // 004c25fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c25fc  7403                   -je 0x4c2601
    if (cpu.flags.zf)
    {
        goto L_0x004c2601;
    }
    // 004c25fe  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x004c2601:
    // 004c2601  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c2603  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2604  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2605(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2605  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c2607  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2608(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2608  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c2609  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c260b  e83b000000             -call 0x4c264b
    cpu.esp -= 4;
    sub_4c264b(app, cpu);
    if (cpu.terminate) return;
    // 004c2610  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2612  741f                   -je 0x4c2633
    if (cpu.flags.zf)
    {
        goto L_0x004c2633;
    }
    // 004c2614  81fa81820000           +cmp edx, 0x8281
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33409 /*0x8281*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c261a  7211                   -jb 0x4c262d
    if (cpu.flags.cf)
    {
        goto L_0x004c262d;
    }
    // 004c261c  81fa9a820000           +cmp edx, 0x829a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33434 /*0x829a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2622  7709                   -ja 0x4c262d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c262d;
    }
    // 004c2624  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004c2629  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c262b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c262c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c262d:
    // 004c262d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c262f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c2631  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2632  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c2633:
    // 004c2633  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004c2635  fec0                   -inc al
    (cpu.al)++;
    // 004c2637  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2639  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004c263b  8a8228cd4d00           -mov al, byte ptr [edx + 0x4dcd28]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */);
    // 004c2641  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004c2643  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2645  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004c2647  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c2649  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c264a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c264b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c264b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c264c  833d90805b0000         +cmp dword ptr [0x5b8090], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2653  7431                   -je 0x4c2686
    if (cpu.flags.zf)
    {
        goto L_0x004c2686;
    }
    // 004c2655  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c2657  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004c265a  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c2660  8a9295805b00           -mov dl, byte ptr [edx + 0x5b8095]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5996693) /* 0x5b8095 */);
    // 004c2666  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c2669  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c266f  7415                   -je 0x4c2686
    if (cpu.flags.zf)
    {
        goto L_0x004c2686;
    }
    // 004c2671  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c2676  e80f000000             -call 0x4c268a
    cpu.esp -= 4;
    sub_4c268a(app, cpu);
    if (cpu.terminate) return;
    // 004c267b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c267d  7407                   -je 0x4c2686
    if (cpu.flags.zf)
    {
        goto L_0x004c2686;
    }
    // 004c267f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004c2684  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2685  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c2686:
    // 004c2686  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c2688  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2689  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c268a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c268a  833d90805b0000         +cmp dword ptr [0x5b8090], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2691  7429                   -je 0x4c26bc
    if (cpu.flags.zf)
    {
        goto L_0x004c26bc;
    }
    // 004c2693  813d98e84d00a4030000   +cmp dword ptr [0x4de898], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5105816) /* 0x4de898 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c269d  740a                   -je 0x4c26a9
    if (cpu.flags.zf)
    {
        goto L_0x004c26a9;
    }
    // 004c269f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c26a1  741b                   -je 0x4c26be
    if (cpu.flags.zf)
    {
        goto L_0x004c26be;
    }
    // 004c26a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004c26a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c26a9:
    // 004c26a9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c26ae  8a80f5ee4d00           -mov al, byte ptr [eax + 0x4deef5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107445) /* 0x4deef5 */);
    // 004c26b4  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004c26b6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c26bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c26bc:
    // 004c26bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c26be:
    // 004c26be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c26c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c26c0  833d4cf04d0000         +cmp dword ptr [0x4df04c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107788) /* 0x4df04c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c26c7  751e                   -jne 0x4c26e7
    if (!cpu.flags.zf)
    {
        goto L_0x004c26e7;
    }
    // 004c26c9  68f8f34d00             -push 0x4df3f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108728 /*0x4df3f8*/;
    cpu.esp -= 4;
    // 004c26ce  ff1518454c00           -call dword ptr [0x4c4518]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4998424) /* 0x4c4518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c26d4  a34cf04d00             -mov dword ptr [0x4df04c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107788) /* 0x4df04c */) = cpu.eax;
    // 004c26d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c26db  750a                   -jne 0x4c26e7
    if (!cpu.flags.zf)
    {
        goto L_0x004c26e7;
    }
    // 004c26dd  c7054cf04d00ffffffff   -mov dword ptr [0x4df04c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5107788) /* 0x4df04c */) = 4294967295 /*0xffffffff*/;
L_0x004c26e7:
    // 004c26e7  833d4cf04d00ff         +cmp dword ptr [0x4df04c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107788) /* 0x4df04c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c26ee  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c26f3  7420                   -je 0x4c2715
    if (cpu.flags.zf)
    {
        goto L_0x004c2715;
    }
    // 004c26f5  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004c26f9  ff354cf04d00           -push dword ptr [0x4df04c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5107788) /* 0x4df04c */);
    cpu.esp -= 4;
    // 004c26ff  ff15e8444c00           -call dword ptr [0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2705  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c2709  83f801                 +cmp eax, 1
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
    // 004c270c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004c270e  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004c2710  2549000080             -and eax, 0x80000049
    cpu.eax &= x86::reg32(x86::sreg32(2147483721 /*0x80000049*/));
L_0x004c2715:
    // 004c2715  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4c2718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2718  833d6cf04d0000         +cmp dword ptr [0x4df06c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107820) /* 0x4df06c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c271f  751f                   -jne 0x4c2740
    if (!cpu.flags.zf)
    {
        goto L_0x004c2740;
    }
    // 004c2721  686cf04d00             -push 0x4df06c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5107820 /*0x4df06c*/;
    cpu.esp -= 4;
    // 004c2726  6870f44d00             -push 0x4df470
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108848 /*0x4df470*/;
    cpu.esp -= 4;
    // 004c272b  e890ffffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c2730  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2732  740c                   -je 0x4c2740
    if (cpu.flags.zf)
    {
        goto L_0x004c2740;
    }
    // 004c2734  c7056cf04d00ffffffff   -mov dword ptr [0x4df06c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5107820) /* 0x4df06c */) = 4294967295 /*0xffffffff*/;
    // 004c273e  eb20                   -jmp 0x4c2760
    goto L_0x004c2760;
L_0x004c2740:
    // 004c2740  833d6cf04d00ff         +cmp dword ptr [0x4df06c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107820) /* 0x4df06c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2747  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c274c  7412                   -je 0x4c2760
    if (cpu.flags.zf)
    {
        goto L_0x004c2760;
    }
    // 004c274e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2752  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2756  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c275a  ff156cf04d00           -call dword ptr [0x4df06c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107820) /* 0x4df06c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2760:
    // 004c2760  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c2763(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2763  833d7cf04d0000         +cmp dword ptr [0x4df07c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107836) /* 0x4df07c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c276a  751f                   -jne 0x4c278b
    if (!cpu.flags.zf)
    {
        goto L_0x004c278b;
    }
    // 004c276c  687cf04d00             -push 0x4df07c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5107836 /*0x4df07c*/;
    cpu.esp -= 4;
    // 004c2771  68b8f44d00             -push 0x4df4b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108920 /*0x4df4b8*/;
    cpu.esp -= 4;
    // 004c2776  e845ffffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c277b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c277d  740c                   -je 0x4c278b
    if (cpu.flags.zf)
    {
        goto L_0x004c278b;
    }
    // 004c277f  c7057cf04d00ffffffff   -mov dword ptr [0x4df07c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5107836) /* 0x4df07c */) = 4294967295 /*0xffffffff*/;
    // 004c2789  eb18                   -jmp 0x4c27a3
    goto L_0x004c27a3;
L_0x004c278b:
    // 004c278b  833d7cf04d00ff         +cmp dword ptr [0x4df07c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107836) /* 0x4df07c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2792  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c2797  740a                   -je 0x4c27a3
    if (cpu.flags.zf)
    {
        goto L_0x004c27a3;
    }
    // 004c2799  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004c279d  ff157cf04d00           -call dword ptr [0x4df07c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107836) /* 0x4df07c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c27a3:
    // 004c27a3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4c27a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c27a6  833da4f04d0000         +cmp dword ptr [0x4df0a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107876) /* 0x4df0a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c27ad  751f                   -jne 0x4c27ce
    if (!cpu.flags.zf)
    {
        goto L_0x004c27ce;
    }
    // 004c27af  68a4f04d00             -push 0x4df0a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5107876 /*0x4df0a4*/;
    cpu.esp -= 4;
    // 004c27b4  6888f54d00             -push 0x4df588
    app->getMemory<x86::reg32>(cpu.esp-4) = 5109128 /*0x4df588*/;
    cpu.esp -= 4;
    // 004c27b9  e802ffffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c27be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c27c0  740c                   -je 0x4c27ce
    if (cpu.flags.zf)
    {
        goto L_0x004c27ce;
    }
    // 004c27c2  c705a4f04d00ffffffff   -mov dword ptr [0x4df0a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5107876) /* 0x4df0a4 */) = 4294967295 /*0xffffffff*/;
    // 004c27cc  eb18                   -jmp 0x4c27e6
    goto L_0x004c27e6;
L_0x004c27ce:
    // 004c27ce  833da4f04d00ff         +cmp dword ptr [0x4df0a4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107876) /* 0x4df0a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c27d5  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c27da  740a                   -je 0x4c27e6
    if (cpu.flags.zf)
    {
        goto L_0x004c27e6;
    }
    // 004c27dc  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004c27e0  ff15a4f04d00           -call dword ptr [0x4df0a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107876) /* 0x4df0a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c27e6:
    // 004c27e6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4c27e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c27e9  833dbcf04d0000         +cmp dword ptr [0x4df0bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107900) /* 0x4df0bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c27f0  751f                   -jne 0x4c2811
    if (!cpu.flags.zf)
    {
        goto L_0x004c2811;
    }
    // 004c27f2  68bcf04d00             -push 0x4df0bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5107900 /*0x4df0bc*/;
    cpu.esp -= 4;
    // 004c27f7  68e8f54d00             -push 0x4df5e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5109224 /*0x4df5e8*/;
    cpu.esp -= 4;
    // 004c27fc  e8bffeffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c2801  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2803  740c                   -je 0x4c2811
    if (cpu.flags.zf)
    {
        goto L_0x004c2811;
    }
    // 004c2805  c705bcf04d00ffffffff   -mov dword ptr [0x4df0bc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5107900) /* 0x4df0bc */) = 4294967295 /*0xffffffff*/;
    // 004c280f  eb20                   -jmp 0x4c2831
    goto L_0x004c2831;
L_0x004c2811:
    // 004c2811  833dbcf04d00ff         +cmp dword ptr [0x4df0bc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107900) /* 0x4df0bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2818  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c281d  7412                   -je 0x4c2831
    if (cpu.flags.zf)
    {
        goto L_0x004c2831;
    }
    // 004c281f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2823  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2827  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c282b  ff15bcf04d00           -call dword ptr [0x4df0bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107900) /* 0x4df0bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2831:
    // 004c2831  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c2834(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2834  833d58f14d0000         +cmp dword ptr [0x4df158], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108056) /* 0x4df158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c283b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c283c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c283e  751f                   -jne 0x4c285f
    if (!cpu.flags.zf)
    {
        goto L_0x004c285f;
    }
    // 004c2840  6858f14d00             -push 0x4df158
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108056 /*0x4df158*/;
    cpu.esp -= 4;
    // 004c2845  68f4f84d00             -push 0x4df8f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5110004 /*0x4df8f4*/;
    cpu.esp -= 4;
    // 004c284a  e871feffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c284f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2851  740c                   -je 0x4c285f
    if (cpu.flags.zf)
    {
        goto L_0x004c285f;
    }
    // 004c2853  c70558f14d00ffffffff   -mov dword ptr [0x4df158], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108056) /* 0x4df158 */) = 4294967295 /*0xffffffff*/;
    // 004c285d  eb23                   -jmp 0x4c2882
    goto L_0x004c2882;
L_0x004c285f:
    // 004c285f  833d58f14d00ff         +cmp dword ptr [0x4df158], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108056) /* 0x4df158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2866  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c286b  7415                   -je 0x4c2882
    if (cpu.flags.zf)
    {
        goto L_0x004c2882;
    }
    // 004c286d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c2870  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c2873  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c2876  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2879  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c287c  ff1558f14d00           -call dword ptr [0x4df158]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108056) /* 0x4df158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2882:
    // 004c2882  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2883  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4c2886(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2886  833d64f14d0000         +cmp dword ptr [0x4df164], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108068) /* 0x4df164 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c288d  751f                   -jne 0x4c28ae
    if (!cpu.flags.zf)
    {
        goto L_0x004c28ae;
    }
    // 004c288f  6864f14d00             -push 0x4df164
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108068 /*0x4df164*/;
    cpu.esp -= 4;
    // 004c2894  6824f94d00             -push 0x4df924
    app->getMemory<x86::reg32>(cpu.esp-4) = 5110052 /*0x4df924*/;
    cpu.esp -= 4;
    // 004c2899  e822feffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c289e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c28a0  740c                   -je 0x4c28ae
    if (cpu.flags.zf)
    {
        goto L_0x004c28ae;
    }
    // 004c28a2  c70564f14d00ffffffff   -mov dword ptr [0x4df164], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108068) /* 0x4df164 */) = 4294967295 /*0xffffffff*/;
    // 004c28ac  eb20                   -jmp 0x4c28ce
    goto L_0x004c28ce;
L_0x004c28ae:
    // 004c28ae  833d64f14d00ff         +cmp dword ptr [0x4df164], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108068) /* 0x4df164 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c28b5  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c28ba  7412                   -je 0x4c28ce
    if (cpu.flags.zf)
    {
        goto L_0x004c28ce;
    }
    // 004c28bc  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c28c0  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c28c4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c28c8  ff1564f14d00           -call dword ptr [0x4df164]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108068) /* 0x4df164 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c28ce:
    // 004c28ce  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c28d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c28d1  833d80f14d0000         +cmp dword ptr [0x4df180], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108096) /* 0x4df180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c28d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c28d9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c28db  751f                   -jne 0x4c28fc
    if (!cpu.flags.zf)
    {
        goto L_0x004c28fc;
    }
    // 004c28dd  6880f14d00             -push 0x4df180
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108096 /*0x4df180*/;
    cpu.esp -= 4;
    // 004c28e2  689cf94d00             -push 0x4df99c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5110172 /*0x4df99c*/;
    cpu.esp -= 4;
    // 004c28e7  e8d4fdffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c28ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c28ee  740c                   -je 0x4c28fc
    if (cpu.flags.zf)
    {
        goto L_0x004c28fc;
    }
    // 004c28f0  c70580f14d00ffffffff   -mov dword ptr [0x4df180], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108096) /* 0x4df180 */) = 4294967295 /*0xffffffff*/;
    // 004c28fa  eb26                   -jmp 0x4c2922
    goto L_0x004c2922;
L_0x004c28fc:
    // 004c28fc  833d80f14d00ff         +cmp dword ptr [0x4df180], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108096) /* 0x4df180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2903  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c2908  7418                   -je 0x4c2922
    if (cpu.flags.zf)
    {
        goto L_0x004c2922;
    }
    // 004c290a  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004c290d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c2910  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c2913  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c2916  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2919  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c291c  ff1580f14d00           -call dword ptr [0x4df180]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108096) /* 0x4df180 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2922:
    // 004c2922  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2923  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_4c2926(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2926  833d8cf14d0000         +cmp dword ptr [0x4df18c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108108) /* 0x4df18c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c292d  751f                   -jne 0x4c294e
    if (!cpu.flags.zf)
    {
        goto L_0x004c294e;
    }
    // 004c292f  688cf14d00             -push 0x4df18c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108108 /*0x4df18c*/;
    cpu.esp -= 4;
    // 004c2934  68c0f94d00             -push 0x4df9c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5110208 /*0x4df9c0*/;
    cpu.esp -= 4;
    // 004c2939  e882fdffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c293e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2940  740c                   -je 0x4c294e
    if (cpu.flags.zf)
    {
        goto L_0x004c294e;
    }
    // 004c2942  c7058cf14d00ffffffff   -mov dword ptr [0x4df18c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108108) /* 0x4df18c */) = 4294967295 /*0xffffffff*/;
    // 004c294c  eb1c                   -jmp 0x4c296a
    goto L_0x004c296a;
L_0x004c294e:
    // 004c294e  833d8cf14d00ff         +cmp dword ptr [0x4df18c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108108) /* 0x4df18c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2955  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c295a  740e                   -je 0x4c296a
    if (cpu.flags.zf)
    {
        goto L_0x004c296a;
    }
    // 004c295c  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c2960  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c2964  ff158cf14d00           -call dword ptr [0x4df18c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108108) /* 0x4df18c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c296a:
    // 004c296a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4c296d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c296d  833dd8f14d0000         +cmp dword ptr [0x4df1d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108184) /* 0x4df1d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2974  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2975  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c2977  751f                   -jne 0x4c2998
    if (!cpu.flags.zf)
    {
        goto L_0x004c2998;
    }
    // 004c2979  68d8f14d00             -push 0x4df1d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108184 /*0x4df1d8*/;
    cpu.esp -= 4;
    // 004c297e  6834fb4d00             -push 0x4dfb34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5110580 /*0x4dfb34*/;
    cpu.esp -= 4;
    // 004c2983  e838fdffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c2988  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c298a  740c                   -je 0x4c2998
    if (cpu.flags.zf)
    {
        goto L_0x004c2998;
    }
    // 004c298c  c705d8f14d00ffffffff   -mov dword ptr [0x4df1d8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108184) /* 0x4df1d8 */) = 4294967295 /*0xffffffff*/;
    // 004c2996  eb23                   -jmp 0x4c29bb
    goto L_0x004c29bb;
L_0x004c2998:
    // 004c2998  833dd8f14d00ff         +cmp dword ptr [0x4df1d8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108184) /* 0x4df1d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c299f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c29a4  7415                   -je 0x4c29bb
    if (cpu.flags.zf)
    {
        goto L_0x004c29bb;
    }
    // 004c29a6  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c29a9  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c29ac  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c29af  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c29b2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c29b5  ff15d8f14d00           -call dword ptr [0x4df1d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108184) /* 0x4df1d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c29bb:
    // 004c29bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c29bc  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4c29bf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c29bf  833de4f14d0000         +cmp dword ptr [0x4df1e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108196) /* 0x4df1e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c29c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c29c7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c29c9  751f                   -jne 0x4c29ea
    if (!cpu.flags.zf)
    {
        goto L_0x004c29ea;
    }
    // 004c29cb  68e4f14d00             -push 0x4df1e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108196 /*0x4df1e4*/;
    cpu.esp -= 4;
    // 004c29d0  686cfb4d00             -push 0x4dfb6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5110636 /*0x4dfb6c*/;
    cpu.esp -= 4;
    // 004c29d5  e8e6fcffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c29da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c29dc  740c                   -je 0x4c29ea
    if (cpu.flags.zf)
    {
        goto L_0x004c29ea;
    }
    // 004c29de  c705e4f14d00ffffffff   -mov dword ptr [0x4df1e4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108196) /* 0x4df1e4 */) = 4294967295 /*0xffffffff*/;
    // 004c29e8  eb23                   -jmp 0x4c2a0d
    goto L_0x004c2a0d;
L_0x004c29ea:
    // 004c29ea  833de4f14d00ff         +cmp dword ptr [0x4df1e4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108196) /* 0x4df1e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c29f1  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c29f6  7415                   -je 0x4c2a0d
    if (cpu.flags.zf)
    {
        goto L_0x004c2a0d;
    }
    // 004c29f8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c29fb  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c29fe  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c2a01  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2a04  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c2a07  ff15e4f14d00           -call dword ptr [0x4df1e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108196) /* 0x4df1e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2a0d:
    // 004c2a0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2a0e  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4c2a11(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2a11  833dfcf14d0000         +cmp dword ptr [0x4df1fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108220) /* 0x4df1fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2a18  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2a19  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c2a1b  751f                   -jne 0x4c2a3c
    if (!cpu.flags.zf)
    {
        goto L_0x004c2a3c;
    }
    // 004c2a1d  68fcf14d00             -push 0x4df1fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108220 /*0x4df1fc*/;
    cpu.esp -= 4;
    // 004c2a22  68d8fb4d00             -push 0x4dfbd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5110744 /*0x4dfbd8*/;
    cpu.esp -= 4;
    // 004c2a27  e894fcffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c2a2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2a2e  740c                   -je 0x4c2a3c
    if (cpu.flags.zf)
    {
        goto L_0x004c2a3c;
    }
    // 004c2a30  c705fcf14d00ffffffff   -mov dword ptr [0x4df1fc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108220) /* 0x4df1fc */) = 4294967295 /*0xffffffff*/;
    // 004c2a3a  eb26                   -jmp 0x4c2a62
    goto L_0x004c2a62;
L_0x004c2a3c:
    // 004c2a3c  833dfcf14d00ff         +cmp dword ptr [0x4df1fc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108220) /* 0x4df1fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2a43  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c2a48  7418                   -je 0x4c2a62
    if (cpu.flags.zf)
    {
        goto L_0x004c2a62;
    }
    // 004c2a4a  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004c2a4d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c2a50  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c2a53  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c2a56  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2a59  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c2a5c  ff15fcf14d00           -call dword ptr [0x4df1fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108220) /* 0x4df1fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2a62:
    // 004c2a62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2a63  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_4c2a66(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2a66  833d04f24d0000         +cmp dword ptr [0x4df204], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108228) /* 0x4df204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2a6d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2a6e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c2a70  751f                   -jne 0x4c2a91
    if (!cpu.flags.zf)
    {
        goto L_0x004c2a91;
    }
    // 004c2a72  6804f24d00             -push 0x4df204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108228 /*0x4df204*/;
    cpu.esp -= 4;
    // 004c2a77  6808fc4d00             -push 0x4dfc08
    app->getMemory<x86::reg32>(cpu.esp-4) = 5110792 /*0x4dfc08*/;
    cpu.esp -= 4;
    // 004c2a7c  e83ffcffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c2a81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2a83  740c                   -je 0x4c2a91
    if (cpu.flags.zf)
    {
        goto L_0x004c2a91;
    }
    // 004c2a85  c70504f24d00ffffffff   -mov dword ptr [0x4df204], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108228) /* 0x4df204 */) = 4294967295 /*0xffffffff*/;
    // 004c2a8f  eb2f                   -jmp 0x4c2ac0
    goto L_0x004c2ac0;
L_0x004c2a91:
    // 004c2a91  833d04f24d00ff         +cmp dword ptr [0x4df204], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108228) /* 0x4df204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2a98  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c2a9d  7421                   -je 0x4c2ac0
    if (cpu.flags.zf)
    {
        goto L_0x004c2ac0;
    }
    // 004c2a9f  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 004c2aa2  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 004c2aa5  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004c2aa8  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004c2aab  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c2aae  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c2ab1  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c2ab4  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2ab7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c2aba  ff1504f24d00           -call dword ptr [0x4df204]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108228) /* 0x4df204 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2ac0:
    // 004c2ac0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2ac1  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_4c2ac4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2ac4  833d94f24d0000         +cmp dword ptr [0x4df294], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108372) /* 0x4df294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2acb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2acc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c2ace  751f                   -jne 0x4c2aef
    if (!cpu.flags.zf)
    {
        goto L_0x004c2aef;
    }
    // 004c2ad0  6894f24d00             -push 0x4df294
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108372 /*0x4df294*/;
    cpu.esp -= 4;
    // 004c2ad5  68c8fe4d00             -push 0x4dfec8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5111496 /*0x4dfec8*/;
    cpu.esp -= 4;
    // 004c2ada  e8e1fbffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c2adf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2ae1  740c                   -je 0x4c2aef
    if (cpu.flags.zf)
    {
        goto L_0x004c2aef;
    }
    // 004c2ae3  c70594f24d00ffffffff   -mov dword ptr [0x4df294], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108372) /* 0x4df294 */) = 4294967295 /*0xffffffff*/;
    // 004c2aed  eb20                   -jmp 0x4c2b0f
    goto L_0x004c2b0f;
L_0x004c2aef:
    // 004c2aef  833d94f24d00ff         +cmp dword ptr [0x4df294], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108372) /* 0x4df294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2af6  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c2afb  7412                   -je 0x4c2b0f
    if (cpu.flags.zf)
    {
        goto L_0x004c2b0f;
    }
    // 004c2afd  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c2b00  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c2b03  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2b06  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c2b09  ff1594f24d00           -call dword ptr [0x4df294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108372) /* 0x4df294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2b0f:
    // 004c2b0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2b10  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_4c2b13(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2b13  833db0f24d0000         +cmp dword ptr [0x4df2b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108400) /* 0x4df2b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2b1a  751f                   -jne 0x4c2b3b
    if (!cpu.flags.zf)
    {
        goto L_0x004c2b3b;
    }
    // 004c2b1c  68b0f24d00             -push 0x4df2b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108400 /*0x4df2b0*/;
    cpu.esp -= 4;
    // 004c2b21  6854ff4d00             -push 0x4dff54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5111636 /*0x4dff54*/;
    cpu.esp -= 4;
    // 004c2b26  e895fbffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c2b2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2b2d  740c                   -je 0x4c2b3b
    if (cpu.flags.zf)
    {
        goto L_0x004c2b3b;
    }
    // 004c2b2f  c705b0f24d00ffffffff   -mov dword ptr [0x4df2b0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108400) /* 0x4df2b0 */) = 4294967295 /*0xffffffff*/;
    // 004c2b39  eb20                   -jmp 0x4c2b5b
    goto L_0x004c2b5b;
L_0x004c2b3b:
    // 004c2b3b  833db0f24d00ff         +cmp dword ptr [0x4df2b0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108400) /* 0x4df2b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2b42  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c2b47  7412                   -je 0x4c2b5b
    if (cpu.flags.zf)
    {
        goto L_0x004c2b5b;
    }
    // 004c2b49  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2b4d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2b51  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c2b55  ff15b0f24d00           -call dword ptr [0x4df2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108400) /* 0x4df2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2b5b:
    // 004c2b5b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c2b5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2b5e  833ddcf24d0000         +cmp dword ptr [0x4df2dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108444) /* 0x4df2dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2b65  751f                   -jne 0x4c2b86
    if (!cpu.flags.zf)
    {
        goto L_0x004c2b86;
    }
    // 004c2b67  68dcf24d00             -push 0x4df2dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108444 /*0x4df2dc*/;
    cpu.esp -= 4;
    // 004c2b6c  6834004e00             -push 0x4e0034
    app->getMemory<x86::reg32>(cpu.esp-4) = 5111860 /*0x4e0034*/;
    cpu.esp -= 4;
    // 004c2b71  e84afbffff             -call 0x4c26c0
    cpu.esp -= 4;
    sub_4c26c0(app, cpu);
    if (cpu.terminate) return;
    // 004c2b76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2b78  740c                   -je 0x4c2b86
    if (cpu.flags.zf)
    {
        goto L_0x004c2b86;
    }
    // 004c2b7a  c705dcf24d00ffffffff   -mov dword ptr [0x4df2dc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5108444) /* 0x4df2dc */) = 4294967295 /*0xffffffff*/;
    // 004c2b84  eb18                   -jmp 0x4c2b9e
    goto L_0x004c2b9e;
L_0x004c2b86:
    // 004c2b86  833ddcf24d00ff         +cmp dword ptr [0x4df2dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108444) /* 0x4df2dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2b8d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c2b92  740a                   -je 0x4c2b9e
    if (cpu.flags.zf)
    {
        goto L_0x004c2b9e;
    }
    // 004c2b94  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004c2b98  ff15dcf24d00           -call dword ptr [0x4df2dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5108444) /* 0x4df2dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c2b9e:
    // 004c2b9e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 68064e000000000003ffff000000000058064e000400000003ffff000000000048064e000800000003ffff8000000000000000000c0000000cffff0000000000000000000d0000000cffff0000000000000000000e0000000cffff8000000000000000000f0000000cffff80000000001800000010000000020000001000000007000000b02b4c00000000000000000068064e000000000003ffff800001000058064e000400000003ffff800001000048064e000800000003ffff8000010000b8064e000c00000003ffff8000010000a8064e001000000003ffff800001000098064e001400000003ffff800001000088064e001800000003ffff800001000088064e001c00000003ffff800001000078064e002000000010ffff800000000078064e002400000010ffff800000000078064e002800000010ffff800000000078064e002c00000010ffff800000000000000000300000000cffff800000000000000000310000000cffff800000000000000000320000000cffff800000000000000000330000000cffff800000000000000000340000000cffff800000000000000000350000000cffff800000000000000000360000000cffff800000000000000000370000000cffff800000000000000000380000000cffff800000000000000000390000000cffff8000000000000000003a0000000cffff8000000000000000003b0000000cffff8000000000000000003c0000000cffff8000000000000000003d0000000cffff8000000000000000003e0000000cffff8000000000000000003f0000000cffff800000000000000000400000000cffff800000000000000000410000000cffff800000000000000000420000000cffff800000000000000000430000000cffff800000000000000000440000000cffff800000000000000000450000000cffff800000000000000000460000000cffff800000000000000000470000000cffff800000000000000000480000000cffff800000000000000000490000000cffff8000000000000000004a0000000cffff8000000000000000004b0000000cffff8000000000000000004c0000000cffff8000000000000000004d0000000cffff8000000000000000004e0000000cffff8000000000000000004f0000000cffff8000000000180000001000000001000000500000002c000000402c4c00 */
void Application::sub_4c2f18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f18  ff2558454c00           -jmp dword ptr [0x4c4558]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998488), cpu);
}

/* align: skip  */
void Application::sub_4c2f1e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f1e  ff256c444c00           -jmp dword ptr [0x4c446c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998252), cpu);
}

/* align: skip  */
void Application::sub_4c2f24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f24  ff2520454c00           -jmp dword ptr [0x4c4520]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998432), cpu);
}

/* align: skip  */
void Application::sub_4c2f2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f2a  ff2574454c00           -jmp dword ptr [0x4c4574]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998516), cpu);
}

/* align: skip  */
void Application::sub_4c2f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f30  ff2590454c00           -jmp dword ptr [0x4c4590]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998544), cpu);
}

/* align: skip  */
void Application::sub_4c2f36(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f36  ff25a4454c00           -jmp dword ptr [0x4c45a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998564), cpu);
}

/* align: skip  */
void Application::sub_4c2f3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f3c  ff2524454c00           -jmp dword ptr [0x4c4524]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998436), cpu);
}

/* align: skip  */
void Application::sub_4c2f42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f42  ff25d8444c00           -jmp dword ptr [0x4c44d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998360), cpu);
}

/* align: skip  */
void Application::sub_4c2f48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f48  ff2584454c00           -jmp dword ptr [0x4c4584]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998532), cpu);
}

/* align: skip  */
void Application::sub_4c2f4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f4e  ff258c454c00           -jmp dword ptr [0x4c458c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998540), cpu);
}

/* align: skip  */
void Application::sub_4c2f54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f54  ff2580454c00           -jmp dword ptr [0x4c4580]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998528), cpu);
}

/* align: skip  */
void Application::sub_4c2f5a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f5a  ff2568454c00           -jmp dword ptr [0x4c4568]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998504), cpu);
}

/* align: skip  */
void Application::sub_4c2f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f60  ff2588454c00           -jmp dword ptr [0x4c4588]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998536), cpu);
}

/* align: skip  */
void Application::sub_4c2f66(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f66  ff25bc444c00           -jmp dword ptr [0x4c44bc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998332), cpu);
}

/* align: skip  */
void Application::sub_4c2f6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f6c  ff25ec444c00           -jmp dword ptr [0x4c44ec]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998380), cpu);
}

/* align: skip  */
void Application::sub_4c2f72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f72  ff256c454c00           -jmp dword ptr [0x4c456c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998508), cpu);
}

/* align: skip  */
void Application::sub_4c2f78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f78  ff25fc444c00           -jmp dword ptr [0x4c44fc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998396), cpu);
}

/* align: skip  */
void Application::sub_4c2f7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f7e  ff25c4434c00           -jmp dword ptr [0x4c43c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998084), cpu);
}

/* align: skip  */
void Application::sub_4c2f84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f84  ff259c444c00           -jmp dword ptr [0x4c449c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998300), cpu);
}

/* align: skip  */
void Application::sub_4c2f8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f8a  ff258c444c00           -jmp dword ptr [0x4c448c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998284), cpu);
}

/* align: skip  */
void Application::sub_4c2f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f90  ff2588444c00           -jmp dword ptr [0x4c4488]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998280), cpu);
}

/* align: skip  */
void Application::sub_4c2f96(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f96  ff25d4444c00           -jmp dword ptr [0x4c44d4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998356), cpu);
}

/* align: skip  */
void Application::sub_4c2f9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2f9c  ff2500454c00           -jmp dword ptr [0x4c4500]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998400), cpu);
}

/* align: skip  */
void Application::sub_4c2fa2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fa2  ff25b0444c00           -jmp dword ptr [0x4c44b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998320), cpu);
}

/* align: skip  */
void Application::sub_4c2fa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fa8  ff25c8444c00           -jmp dword ptr [0x4c44c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998344), cpu);
}

/* align: skip  */
void Application::sub_4c2fae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fae  ff256c434c00           -jmp dword ptr [0x4c436c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4997996), cpu);
}

/* align: skip  */
void Application::sub_4c2fb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fb4  ff2578434c00           -jmp dword ptr [0x4c4378]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998008), cpu);
}

/* align: skip  */
void Application::sub_4c2fba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fba  ff2574434c00           -jmp dword ptr [0x4c4374]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998004), cpu);
}

/* align: skip  */
void Application::sub_4c2fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fc0  ff25a0454c00           -jmp dword ptr [0x4c45a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998560), cpu);
}

/* align: skip  */
void Application::sub_4c2fc6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fc6  ff251c444c00           -jmp dword ptr [0x4c441c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998172), cpu);
}

/* align: skip  */
void Application::sub_4c2fcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fcc  ff25c0434c00           -jmp dword ptr [0x4c43c0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998080), cpu);
}

/* align: skip  */
void Application::sub_4c2fd2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fd2  ff25ac444c00           -jmp dword ptr [0x4c44ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998316), cpu);
}

/* align: skip  */
void Application::sub_4c2fd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fd8  ff2554454c00           -jmp dword ptr [0x4c4554]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998484), cpu);
}

/* align: skip  */
void Application::sub_4c2fde(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2fde  ff2598454c00           -jmp dword ptr [0x4c4598]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998552), cpu);
}

}
