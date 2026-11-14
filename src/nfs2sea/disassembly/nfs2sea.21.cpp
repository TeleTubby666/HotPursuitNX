#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_48d748(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d748  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d749  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d74d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d74e  e83dfeffff             -call 0x48d590
    cpu.esp -= 4;
    sub_48d590(app, cpu);
    if (cpu.terminate) return;
    // 0048d753  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d755  7402                   -je 0x48d759
    if (cpu.flags.zf)
    {
        goto L_0x0048d759;
    }
    // 0048d757  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0048d759:
    // 0048d759  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d75a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d760  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048d762  e829feffff             -call 0x48d590
    cpu.esp -= 4;
    sub_48d590(app, cpu);
    if (cpu.terminate) return;
    // 0048d767  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d769  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d76c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d76c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048d76e  e81dfeffff             -call 0x48d590
    cpu.esp -= 4;
    sub_48d590(app, cpu);
    if (cpu.terminate) return;
    // 0048d773  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d775  7402                   -je 0x48d779
    if (cpu.flags.zf)
    {
        goto L_0x0048d779;
    }
    // 0048d777  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0048d779:
    // 0048d779  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48d780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d782  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d783  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d784  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048d786  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0048d78d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048d78f:
    // 0048d78f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d791  8d4b20                 -lea ecx, [ebx + 0x20]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(32) /* 0x20 */);
L_0x0048d794:
    // 0048d794  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d797  8b151c084e00           -mov edx, dword ptr [0x4e081c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113884) /* 0x4e081c */);
    // 0048d79d  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0048d7a0  39c8                   +cmp eax, ecx
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
    // 0048d7a2  75f0                   -jne 0x48d794
    if (!cpu.flags.zf)
    {
        goto L_0x0048d794;
    }
    // 0048d7a4  46                     -inc esi
    (cpu.esi)++;
    // 0048d7a5  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d7a7  83fe08                 +cmp esi, 8
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
    // 0048d7aa  7ce3                   -jl 0x48d78f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d78f;
    }
    // 0048d7ac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d7ad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d7ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d7af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d7b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d7b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d7b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d7b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d7b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d7b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d7b8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d7bb  b880ffffff             -mov eax, 0xffffff80
    cpu.eax = 4294967168 /*0xffffff80*/;
    // 0048d7c0  b9c0ffffff             -mov ecx, 0xffffffc0
    cpu.ecx = 4294967232 /*0xffffffc0*/;
    // 0048d7c5  be3f000000             -mov esi, 0x3f
    cpu.esi = 63 /*0x3f*/;
L_0x0048d7ca:
    // 0048d7ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d7cc  83f8c0                 +cmp eax, -0x40
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
    // 0048d7cf  0f8d2e010000           -jge 0x48d903
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d903;
    }
    // 0048d7d5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0048d7d7:
    // 0048d7d7  88d3                   -mov bl, dl
    cpu.bl = cpu.dl;
    // 0048d7d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d7db  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048d7e1  80c340                 -add bl, 0x40
    (cpu.bl) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0048d7e4  40                     -inc eax
    (cpu.eax)++;
    // 0048d7e5  889a3cac5600           -mov byte ptr [edx + 0x56ac3c], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */) = cpu.bl;
    // 0048d7eb  83f87f                 +cmp eax, 0x7f
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
    // 0048d7ee  7cda                   -jl 0x48d7ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d7ca;
    }
    // 0048d7f0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048d7f2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0048d7f4:
    // 0048d7f4  668b83849c4d00         -mov ax, word ptr [ebx + 0x4d9c84]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5086340) /* 0x4d9c84 */);
    // 0048d7fb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d7fd  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 0048d802  ba0d000000             -mov edx, 0xd
    cpu.edx = 13 /*0xd*/;
    // 0048d807  668b4c2402             -mov cx, word ptr [esp + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 0048d80c  668b83889c4d00         -mov ax, word ptr [ebx + 0x4d9c88]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5086344) /* 0x4d9c88 */);
    // 0048d813  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d815  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 0048d819  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048d81b  8b83909c4d00           -mov eax, dword ptr [ebx + 0x4d9c90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5086352) /* 0x4d9c90 */);
    // 0048d821  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048d826  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0048d829  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048d82b  83fe17                 +cmp esi, 0x17
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
    // 0048d82e  7507                   -jne 0x48d837
    if (!cpu.flags.zf)
    {
        goto L_0x0048d837;
    }
    // 0048d830  66c74424022100         -mov word ptr [esp + 2], 0x21
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = 33 /*0x21*/;
L_0x0048d837:
    // 0048d837  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d839  7e1e                   -jle 0x48d859
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d859;
    }
    // 0048d83b  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0048d842  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048d845  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d847  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d849  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x0048d84c:
    // 0048d84c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d84f  898838235600           -mov dword ptr [eax + 0x562338], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5645112) /* 0x562338 */) = cpu.ecx;
    // 0048d855  39d0                   +cmp eax, edx
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
    // 0048d857  7cf3                   -jl 0x48d84c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d84c;
    }
L_0x0048d859:
    // 0048d859  46                     -inc esi
    (cpu.esi)++;
    // 0048d85a  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048d85d  83fe60                 +cmp esi, 0x60
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
    // 0048d860  7c92                   -jl 0x48d7f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d7f4;
    }
    // 0048d862  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d863  be20000000             -mov esi, 0x20
    cpu.esi = 32 /*0x20*/;
    // 0048d868  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048d86a  6689742406             -mov word ptr [esp + 6], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.si;
    // 0048d86f  66897c2404             -mov word ptr [esp + 4], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.di;
    // 0048d874  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d876  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d87a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048d87b:
    // 0048d87b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d87e  899038235600           -mov dword ptr [eax + 0x562338], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5645112) /* 0x562338 */) = cpu.edx;
    // 0048d884  3d80000000             +cmp eax, 0x80
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
    // 0048d889  75f0                   -jne 0x48d87b
    if (!cpu.flags.zf)
    {
        goto L_0x0048d87b;
    }
    // 0048d88b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0048d88d:
    // 0048d88d  668b8384a24d00         -mov ax, word ptr [ebx + 0x4da284]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5087876) /* 0x4da284 */);
    // 0048d894  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d896  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 0048d89b  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0048d8a0  668b4c2402             -mov cx, word ptr [esp + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 0048d8a5  668b8388a24d00         -mov ax, word ptr [ebx + 0x4da288]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5087880) /* 0x4da288 */);
    // 0048d8ac  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d8ae  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 0048d8b2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048d8b4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048d8b9  8b8390a24d00           -mov eax, dword ptr [ebx + 0x4da290]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5087888) /* 0x4da290 */);
    // 0048d8bf  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048d8c1  c1e807                 -shr eax, 7
    cpu.eax >>= 7 /*0x7*/ % 32;
    // 0048d8c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d8c6  7e1e                   -jle 0x48d8e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d8e6;
    }
    // 0048d8c8  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d8cb  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 0048d8d2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048d8d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d8d7  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0048d8d9:
    // 0048d8d9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d8dc  898838a35600           -mov dword ptr [eax + 0x56a338], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5677880) /* 0x56a338 */) = cpu.ecx;
    // 0048d8e2  39d0                   +cmp eax, edx
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
    // 0048d8e4  7cf3                   -jl 0x48d8d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d8d9;
    }
L_0x0048d8e6:
    // 0048d8e6  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048d8e9  81fb00080000           +cmp ebx, 0x800
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
    // 0048d8ef  759c                   -jne 0x48d88d
    if (!cpu.flags.zf)
    {
        goto L_0x0048d88d;
    }
    // 0048d8f1  c7053cb1560001000000   -mov dword ptr [0x56b13c], 1
    app->getMemory<x86::reg32>(x86::reg32(5681468) /* 0x56b13c */) = 1 /*0x1*/;
    // 0048d8fb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d8fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d8ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d900  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d901  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d902  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d903:
    // 0048d903  83f83f                 +cmp eax, 0x3f
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
    // 0048d906  0f8ecbfeffff           -jle 0x48d7d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d7d7;
    }
    // 0048d90c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048d90e  e9c4feffff             -jmp 0x48d7d7
    goto L_0x0048d7d7;
}

/* align: skip 0x90 */
void Application::sub_48d914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d914  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d915  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d916  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d917  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048d919  a11c094e00             -mov eax, dword ptr [0x4e091c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114140) /* 0x4e091c */);
    // 0048d91e  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048d923  a33cab5600             -mov dword ptr [0x56ab3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5679932) /* 0x56ab3c */) = cpu.eax;
L_0x0048d928:
    // 0048d928  8b8184aa4d00           -mov eax, dword ptr [ecx + 0x4daa84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5089924) /* 0x4daa84 */);
    // 0048d92e  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048d931  8b911c094e00           -mov edx, dword ptr [ecx + 0x4e091c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5114140) /* 0x4e091c */);
    // 0048d937  c1e00c                 -shl eax, 0xc
    cpu.eax <<= 12 /*0xc*/ % 32;
    // 0048d93a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d93d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048d93f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048d942  c1e810                 +shr eax, 0x10
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
    // 0048d945  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048d947  898138ab5600           -mov dword ptr [ecx + 0x56ab38], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5679928) /* 0x56ab38 */) = cpu.eax;
    // 0048d94d  81f900010000           +cmp ecx, 0x100
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
    // 0048d953  75d3                   -jne 0x48d928
    if (!cpu.flags.zf)
    {
        goto L_0x0048d928;
    }
    // 0048d955  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d956  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d957  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d958  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d95c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d95c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d95d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d95f  833d3cb1560000         +cmp dword ptr [0x56b13c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5681468) /* 0x56b13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d966  7409                   -je 0x48d971
    if (cpu.flags.zf)
    {
        goto L_0x0048d971;
    }
    // 0048d968  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d96a  e835b20100             -call 0x4a8ba4
    cpu.esp -= 4;
    sub_4a8ba4(app, cpu);
    if (cpu.terminate) return;
    // 0048d96f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d970  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d971:
    // 0048d971  e83efeffff             -call 0x48d7b4
    cpu.esp -= 4;
    sub_48d7b4(app, cpu);
    if (cpu.terminate) return;
    // 0048d976  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d978  e827b20100             -call 0x4a8ba4
    cpu.esp -= 4;
    sub_4a8ba4(app, cpu);
    if (cpu.terminate) return;
    // 0048d97d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d97e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d981  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d982  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d983  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d984  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d987  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d989  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048d98b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048d98e  833d3cb1560000         +cmp dword ptr [0x56b13c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5681468) /* 0x56b13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d995  0f842d020000           -je 0x48dbc8
    if (cpu.flags.zf)
    {
        goto L_0x0048dbc8;
    }
L_0x0048d99b:
    // 0048d99b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d99d  e812b30100             -call 0x4a8cb4
    cpu.esp -= 4;
    sub_4a8cb4(app, cpu);
    if (cpu.terminate) return;
    // 0048d9a2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048d9a4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d9a6  83f802                 +cmp eax, 2
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
    // 0048d9a9  0f8523020000           -jne 0x48dbd2
    if (!cpu.flags.zf)
    {
        goto L_0x0048dbd2;
    }
    // 0048d9af  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0048d9b4  b83c215600             -mov eax, 0x56213c
    cpu.eax = 5644604 /*0x56213c*/;
    // 0048d9b9  e8c2fdffff             -call 0x48d780
    cpu.esp -= 4;
    sub_48d780(app, cpu);
    if (cpu.terminate) return;
L_0x0048d9be:
    // 0048d9be  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d9c0  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0048d9c3  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d9c5  e8eab20100             -call 0x4a8cb4
    cpu.esp -= 4;
    sub_4a8cb4(app, cpu);
    if (cpu.terminate) return;
    // 0048d9ca  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d9cc  83f802                 +cmp eax, 2
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
    // 0048d9cf  0f8511020000           -jne 0x48dbe6
    if (!cpu.flags.zf)
    {
        goto L_0x0048dbe6;
    }
    // 0048d9d5  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0048d9da  b83c225600             -mov eax, 0x56223c
    cpu.eax = 5644860 /*0x56223c*/;
    // 0048d9df  e89cfdffff             -call 0x48d780
    cpu.esp -= 4;
    sub_48d780(app, cpu);
    if (cpu.terminate) return;
L_0x0048d9e4:
    // 0048d9e4  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d9e6  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0048d9e9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d9eb  e8c4b20100             -call 0x4a8cb4
    cpu.esp -= 4;
    sub_4a8cb4(app, cpu);
    if (cpu.terminate) return;
    // 0048d9f0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d9f2  83f802                 +cmp eax, 2
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
    // 0048d9f5  0f85ff010000           -jne 0x48dbfa
    if (!cpu.flags.zf)
    {
        goto L_0x0048dbfa;
    }
    // 0048d9fb  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048da00  b83cad5600             -mov eax, 0x56ad3c
    cpu.eax = 5680444 /*0x56ad3c*/;
    // 0048da05  e876fdffff             -call 0x48d780
    cpu.esp -= 4;
    sub_48d780(app, cpu);
    if (cpu.terminate) return;
L_0x0048da0a:
    // 0048da0a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048da0c  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0048da0f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048da11  e89eb20100             -call 0x4a8cb4
    cpu.esp -= 4;
    sub_4a8cb4(app, cpu);
    if (cpu.terminate) return;
    // 0048da16  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048da18  83f802                 +cmp eax, 2
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
    // 0048da1b  0f85ed010000           -jne 0x48dc0e
    if (!cpu.flags.zf)
    {
        goto L_0x0048dc0e;
    }
    // 0048da21  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048da26  b85cad5600             -mov eax, 0x56ad5c
    cpu.eax = 5680476 /*0x56ad5c*/;
    // 0048da2b  e850fdffff             -call 0x48d780
    cpu.esp -= 4;
    sub_48d780(app, cpu);
    if (cpu.terminate) return;
L_0x0048da30:
    // 0048da30  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048da32  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0048da35  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048da37  e878b20100             -call 0x4a8cb4
    cpu.esp -= 4;
    sub_4a8cb4(app, cpu);
    if (cpu.terminate) return;
    // 0048da3c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048da3e  83f802                 +cmp eax, 2
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
    // 0048da41  0f85db010000           -jne 0x48dc22
    if (!cpu.flags.zf)
    {
        goto L_0x0048dc22;
    }
    // 0048da47  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048da4c  b83caf5600             -mov eax, 0x56af3c
    cpu.eax = 5680956 /*0x56af3c*/;
    // 0048da51  e82afdffff             -call 0x48d780
    cpu.esp -= 4;
    sub_48d780(app, cpu);
    if (cpu.terminate) return;
L_0x0048da56:
    // 0048da56  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048da58  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0048da5b  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048da5d  e852b20100             -call 0x4a8cb4
    cpu.esp -= 4;
    sub_4a8cb4(app, cpu);
    if (cpu.terminate) return;
    // 0048da62  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048da64  83f802                 +cmp eax, 2
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
    // 0048da67  0f85c9010000           -jne 0x48dc36
    if (!cpu.flags.zf)
    {
        goto L_0x0048dc36;
    }
    // 0048da6d  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048da72  b85caf5600             -mov eax, 0x56af5c
    cpu.eax = 5680988 /*0x56af5c*/;
    // 0048da77  e804fdffff             -call 0x48d780
    cpu.esp -= 4;
    sub_48d780(app, cpu);
    if (cpu.terminate) return;
L_0x0048da7c:
    // 0048da7c  ba3c215600             -mov edx, 0x56213c
    cpu.edx = 5644604 /*0x56213c*/;
    // 0048da81  b83cad5600             -mov eax, 0x56ad3c
    cpu.eax = 5680444 /*0x56ad3c*/;
    // 0048da86  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048da88  e8b9b20100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048da8d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048da90  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048da92  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048da95  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048da97  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048da99  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048da9b  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 0048daa2  ba3c215600             -mov edx, 0x56213c
    cpu.edx = 5644604 /*0x56213c*/;
    // 0048daa7  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048daa9  b87cad5600             -mov eax, 0x56ad7c
    cpu.eax = 5680508 /*0x56ad7c*/;
    // 0048daae  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048dab0  e891b20100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048dab5  ba5c215600             -mov edx, 0x56215c
    cpu.edx = 5644636 /*0x56215c*/;
    // 0048daba  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048dabc  b8bcad5600             -mov eax, 0x56adbc
    cpu.eax = 5680572 /*0x56adbc*/;
    // 0048dac1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048dac3  e87eb20100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048dac8  ba5c215600             -mov edx, 0x56215c
    cpu.edx = 5644636 /*0x56215c*/;
    // 0048dacd  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048dacf  b8fcad5600             -mov eax, 0x56adfc
    cpu.eax = 5680636 /*0x56adfc*/;
    // 0048dad4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048dad6  e86bb20100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048dadb  ba7c215600             -mov edx, 0x56217c
    cpu.edx = 5644668 /*0x56217c*/;
    // 0048dae0  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048dae2  b83cae5600             -mov eax, 0x56ae3c
    cpu.eax = 5680700 /*0x56ae3c*/;
    // 0048dae7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048dae9  e858b20100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048daee  ba7c215600             -mov edx, 0x56217c
    cpu.edx = 5644668 /*0x56217c*/;
    // 0048daf3  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048daf5  b87cae5600             -mov eax, 0x56ae7c
    cpu.eax = 5680764 /*0x56ae7c*/;
    // 0048dafa  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048dafc  e845b20100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048db01  ba9c215600             -mov edx, 0x56219c
    cpu.edx = 5644700 /*0x56219c*/;
    // 0048db06  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048db08  b8bcae5600             -mov eax, 0x56aebc
    cpu.eax = 5680828 /*0x56aebc*/;
    // 0048db0d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048db0f  e832b20100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048db14  ba9c215600             -mov edx, 0x56219c
    cpu.edx = 5644700 /*0x56219c*/;
    // 0048db19  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048db1b  b8fcae5600             -mov eax, 0x56aefc
    cpu.eax = 5680892 /*0x56aefc*/;
    // 0048db20  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048db22  e81fb20100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048db27  babc215600             -mov edx, 0x5621bc
    cpu.edx = 5644732 /*0x5621bc*/;
    // 0048db2c  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048db2e  b83caf5600             -mov eax, 0x56af3c
    cpu.eax = 5680956 /*0x56af3c*/;
    // 0048db33  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048db35  e80cb20100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048db3a  babc215600             -mov edx, 0x5621bc
    cpu.edx = 5644732 /*0x5621bc*/;
    // 0048db3f  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048db41  b87caf5600             -mov eax, 0x56af7c
    cpu.eax = 5681020 /*0x56af7c*/;
    // 0048db46  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048db48  e8f9b10100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048db4d  badc215600             -mov edx, 0x5621dc
    cpu.edx = 5644764 /*0x5621dc*/;
    // 0048db52  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048db54  b8bcaf5600             -mov eax, 0x56afbc
    cpu.eax = 5681084 /*0x56afbc*/;
    // 0048db59  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048db5b  e8e6b10100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048db60  badc215600             -mov edx, 0x5621dc
    cpu.edx = 5644764 /*0x5621dc*/;
    // 0048db65  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048db67  b8fcaf5600             -mov eax, 0x56affc
    cpu.eax = 5681148 /*0x56affc*/;
    // 0048db6c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048db6e  e8d3b10100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048db73  bafc215600             -mov edx, 0x5621fc
    cpu.edx = 5644796 /*0x5621fc*/;
    // 0048db78  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048db7a  b83cb05600             -mov eax, 0x56b03c
    cpu.eax = 5681212 /*0x56b03c*/;
    // 0048db7f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048db81  e8c0b10100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048db86  bafc215600             -mov edx, 0x5621fc
    cpu.edx = 5644796 /*0x5621fc*/;
    // 0048db8b  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048db8d  b87cb05600             -mov eax, 0x56b07c
    cpu.eax = 5681276 /*0x56b07c*/;
    // 0048db92  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048db94  e8adb10100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048db99  ba1c225600             -mov edx, 0x56221c
    cpu.edx = 5644828 /*0x56221c*/;
    // 0048db9e  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048dba0  b8bcb05600             -mov eax, 0x56b0bc
    cpu.eax = 5681340 /*0x56b0bc*/;
    // 0048dba5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048dba7  e89ab10100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048dbac  ba1c225600             -mov edx, 0x56221c
    cpu.edx = 5644828 /*0x56221c*/;
    // 0048dbb1  b8fcb05600             -mov eax, 0x56b0fc
    cpu.eax = 5681404 /*0x56b0fc*/;
    // 0048dbb6  8d1c39                 -lea ebx, [ecx + edi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 0048dbb9  e888b10100             -call 0x4a8d46
    cpu.esp -= 4;
    sub_4a8d46(app, cpu);
    if (cpu.terminate) return;
    // 0048dbbe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048dbc0  83c404                 +add esp, 4
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
    // 0048dbc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbc5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbc7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dbc8:
    // 0048dbc8  e8e7fbffff             -call 0x48d7b4
    cpu.esp -= 4;
    sub_48d7b4(app, cpu);
    if (cpu.terminate) return;
    // 0048dbcd  e9c9fdffff             -jmp 0x48d99b
    goto L_0x0048d99b;
L_0x0048dbd2:
    // 0048dbd2  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0048dbd7  b83c215600             -mov eax, 0x56213c
    cpu.eax = 5644604 /*0x56213c*/;
    // 0048dbdc  e838ae0100             -call 0x4a8a19
    cpu.esp -= 4;
    sub_4a8a19(app, cpu);
    if (cpu.terminate) return;
    // 0048dbe1  e9d8fdffff             -jmp 0x48d9be
    goto L_0x0048d9be;
L_0x0048dbe6:
    // 0048dbe6  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0048dbeb  b83c225600             -mov eax, 0x56223c
    cpu.eax = 5644860 /*0x56223c*/;
    // 0048dbf0  e824ae0100             -call 0x4a8a19
    cpu.esp -= 4;
    sub_4a8a19(app, cpu);
    if (cpu.terminate) return;
    // 0048dbf5  e9eafdffff             -jmp 0x48d9e4
    goto L_0x0048d9e4;
L_0x0048dbfa:
    // 0048dbfa  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048dbff  b83cad5600             -mov eax, 0x56ad3c
    cpu.eax = 5680444 /*0x56ad3c*/;
    // 0048dc04  e810ae0100             -call 0x4a8a19
    cpu.esp -= 4;
    sub_4a8a19(app, cpu);
    if (cpu.terminate) return;
    // 0048dc09  e9fcfdffff             -jmp 0x48da0a
    goto L_0x0048da0a;
L_0x0048dc0e:
    // 0048dc0e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048dc13  b85cad5600             -mov eax, 0x56ad5c
    cpu.eax = 5680476 /*0x56ad5c*/;
    // 0048dc18  e8fcad0100             -call 0x4a8a19
    cpu.esp -= 4;
    sub_4a8a19(app, cpu);
    if (cpu.terminate) return;
    // 0048dc1d  e90efeffff             -jmp 0x48da30
    goto L_0x0048da30;
L_0x0048dc22:
    // 0048dc22  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048dc27  b83caf5600             -mov eax, 0x56af3c
    cpu.eax = 5680956 /*0x56af3c*/;
    // 0048dc2c  e8e8ad0100             -call 0x4a8a19
    cpu.esp -= 4;
    sub_4a8a19(app, cpu);
    if (cpu.terminate) return;
    // 0048dc31  e920feffff             -jmp 0x48da56
    goto L_0x0048da56;
L_0x0048dc36:
    // 0048dc36  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048dc3b  b85caf5600             -mov eax, 0x56af5c
    cpu.eax = 5680988 /*0x56af5c*/;
    // 0048dc40  e8d4ad0100             -call 0x4a8a19
    cpu.esp -= 4;
    sub_4a8a19(app, cpu);
    if (cpu.terminate) return;
    // 0048dc45  e932feffff             -jmp 0x48da7c
    goto L_0x0048da7c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48dc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dc50  83ec04                 +sub esp, 4
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
    // 0048dc53  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0048dc55  d85c2408               +fcomp dword ptr [esp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 0048dc59  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0048dc5b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0048dc5c  771b                   -ja 0x48dc79
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048dc79;
    }
    // 0048dc5e  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0048dc62  dc0518e44c00           -fadd qword ptr [0x4ce418]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5039128) /* 0x4ce418 */));
    // 0048dc68  e8336dffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 0048dc6d  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0048dc70  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048dc73  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dc76  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048dc79:
    // 0048dc79  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0048dc7d  dc0510e44c00           -fadd qword ptr [0x4ce410]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5039120) /* 0x4ce410 */));
    // 0048dc83  e8186dffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 0048dc88  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0048dc8b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048dc8e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dc91  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_48dc94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dc94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dc95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dc96  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048dc97  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048dc98  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048dc99  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048dc9a  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048dc9d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048dca1  b9c0ffffff             -mov ecx, 0xffffffc0
    cpu.ecx = 4294967232 /*0xffffffc0*/;
    // 0048dca6  bb71000000             -mov ebx, 0x71
    cpu.ebx = 113 /*0x71*/;
    // 0048dcab  bf00180200             -mov edi, 0x21800
    cpu.edi = 137216 /*0x21800*/;
    // 0048dcb0  be0000802c             -mov esi, 0x2c800000
    cpu.esi = 746586112 /*0x2c800000*/;
    // 0048dcb5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048dcb7:
    // 0048dcb7  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048dcbb  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0048dcbe  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0048dcc2  dc0540e44c00           -fadd qword ptr [0x4ce440]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5039168) /* 0x4ce440 */));
    // 0048dcc8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048dcca  dd1424                 -fst qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    // 0048dccd  dc0d20e44c00           -fmul qword ptr [0x4ce420]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5039136) /* 0x4ce420 */));
    // 0048dcd3  8982a8bf5600           -mov dword ptr [edx + 0x56bfa8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5685160) /* 0x56bfa8 */) = cpu.eax;
    // 0048dcd9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dcdc  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048dcdf  e86cffffff             -call 0x48dc50
    cpu.esp -= 4;
    sub_48dc50(app, cpu);
    if (cpu.terminate) return;
    // 0048dce4  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0048dce7  dc0d28e44c00           -fmul qword ptr [0x4ce428]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5039144) /* 0x4ce428 */));
    // 0048dced  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dcf0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048dcf2  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048dcf5  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048dcfb  e850ffffff             -call 0x48dc50
    cpu.esp -= 4;
    sub_48dc50(app, cpu);
    if (cpu.terminate) return;
    // 0048dd00  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0048dd03  c1e50b                 -shl ebp, 0xb
    cpu.ebp <<= 11 /*0xb*/ % 32;
    // 0048dd06  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048dd0b  dc0d30e44c00           -fmul qword ptr [0x4ce430]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5039152) /* 0x4ce430 */));
    // 0048dd11  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048dd13  8982a8c15600           -mov dword ptr [edx + 0x56c1a8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5685672) /* 0x56c1a8 */) = cpu.eax;
    // 0048dd19  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dd1c  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048dd1f  e82cffffff             -call 0x48dc50
    cpu.esp -= 4;
    sub_48dc50(app, cpu);
    if (cpu.terminate) return;
    // 0048dd24  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0048dd27  dc0d38e44c00           -fmul qword ptr [0x4ce438]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5039160) /* 0x4ce438 */));
    // 0048dd2d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dd30  81c700080000           -add edi, 0x800
    (cpu.edi) += x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 0048dd36  81c600008000           -add esi, 0x800000
    (cpu.esi) += x86::reg32(x86::sreg32(8388608 /*0x800000*/));
    // 0048dd3c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048dd40  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dd43  41                     -inc ecx
    (cpu.ecx)++;
    // 0048dd44  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048dd47  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048dd4b  e800ffffff             -call 0x48dc50
    cpu.esp -= 4;
    sub_48dc50(app, cpu);
    if (cpu.terminate) return;
    // 0048dd50  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048dd56  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048dd5b  c1e00b                 -shl eax, 0xb
    cpu.eax <<= 11 /*0xb*/ % 32;
    // 0048dd5e  c1e517                 -shl ebp, 0x17
    cpu.ebp <<= 23 /*0x17*/ % 32;
    // 0048dd61  43                     -inc ebx
    (cpu.ebx)++;
    // 0048dd62  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048dd64  8982a4c35600           -mov dword ptr [edx + 0x56c3a4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5686180) /* 0x56c3a4 */) = cpu.eax;
    // 0048dd6a  83f940                 +cmp ecx, 0x40
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
    // 0048dd6d  0f8c44ffffff           -jl 0x48dcb7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048dcb7;
    }
    // 0048dd73  ba67ffffff             -mov edx, 0xffffff67
    cpu.edx = 4294967143 /*0xffffff67*/;
    // 0048dd78  b99cfdffff             -mov ecx, 0xfffffd9c
    cpu.ecx = 4294966684 /*0xfffffd9c*/;
    // 0048dd7d  be1f000000             -mov esi, 0x1f
    cpu.esi = 31 /*0x1f*/;
    // 0048dd82  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048dd86  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048dd88:
    // 0048dd88  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0048dd8b  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 0048dd90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048dd92  0f8c08010000           -jl 0x48dea0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048dea0;
    }
    // 0048dd98  3dff000000             +cmp eax, 0xff
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
    // 0048dd9d  7e05                   -jle 0x48dda4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048dda4;
    }
    // 0048dd9f  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0048dda4:
    // 0048dda4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048dda6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dda9  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048ddac  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0048ddaf  83f81f                 +cmp eax, 0x1f
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
    // 0048ddb2  7e02                   -jle 0x48ddb6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ddb6;
    }
    // 0048ddb4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0048ddb6:
    // 0048ddb6  83fd0f                 +cmp ebp, 0xf
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
    // 0048ddb9  0f85e8000000           -jne 0x48dea7
    if (!cpu.flags.zf)
    {
        goto L_0x0048dea7;
    }
    // 0048ddbf  c1e31a                 -shl ebx, 0x1a
    cpu.ebx <<= 26 /*0x1a*/ % 32;
    // 0048ddc2  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
L_0x0048ddc5:
    // 0048ddc5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ddc7  898144bd5600           -mov dword ptr [ecx + 0x56bd44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5684548) /* 0x56bd44 */) = cpu.eax;
    // 0048ddcd  42                     -inc edx
    (cpu.edx)++;
    // 0048ddce  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ddd1  81fa99000000           +cmp edx, 0x99
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
    // 0048ddd7  7caf                   -jl 0x48dd88
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048dd88;
    }
    // 0048ddd9  ba7dffffff             -mov edx, 0xffffff7d
    cpu.edx = 4294967165 /*0xffffff7d*/;
    // 0048ddde  b9f4fdffff             -mov ecx, 0xfffffdf4
    cpu.ecx = 4294966772 /*0xfffffdf4*/;
    // 0048dde3  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0048dde8  bf3f000000             -mov edi, 0x3f
    cpu.edi = 63 /*0x3f*/;
    // 0048dded  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048ddef:
    // 0048ddef  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0048ddf2  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 0048ddf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ddf9  0f8cb3000000           -jl 0x48deb2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048deb2;
    }
    // 0048ddff  3dff000000             +cmp eax, 0xff
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
    // 0048de04  7e02                   -jle 0x48de08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048de08;
    }
    // 0048de06  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0048de08:
    // 0048de08  837c24080f             +cmp dword ptr [esp + 8], 0xf
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
    // 0048de0d  0f85a6000000           -jne 0x48deb9
    if (!cpu.flags.zf)
    {
        goto L_0x0048deb9;
    }
    // 0048de13  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048de15  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048de18  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048de1b  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0048de1e  83f81f                 +cmp eax, 0x1f
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
    // 0048de21  7e05                   -jle 0x48de28
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048de28;
    }
    // 0048de23  b81f000000             -mov eax, 0x1f
    cpu.eax = 31 /*0x1f*/;
L_0x0048de28:
    // 0048de28  c1e315                 -shl ebx, 0x15
    cpu.ebx <<= 21 /*0x15*/ % 32;
    // 0048de2b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048de2e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048de31  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048de33  42                     -inc edx
    (cpu.edx)++;
    // 0048de34  8981d0b85600           -mov dword ptr [ecx + 0x56b8d0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5683408) /* 0x56b8d0 */) = cpu.eax;
    // 0048de3a  81fa83000000           +cmp edx, 0x83
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
    // 0048de40  7cad                   -jl 0x48ddef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ddef;
    }
    // 0048de42  ba4fffffff             -mov edx, 0xffffff4f
    cpu.edx = 4294967119 /*0xffffff4f*/;
    // 0048de47  b93cfdffff             -mov ecx, 0xfffffd3c
    cpu.ecx = 4294966588 /*0xfffffd3c*/;
    // 0048de4c  bd1f000000             -mov ebp, 0x1f
    cpu.ebp = 31 /*0x1f*/;
    // 0048de51  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
    // 0048de56  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048de58:
    // 0048de58  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0048de5b  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 0048de60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048de62  7c70                   -jl 0x48ded4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ded4;
    }
    // 0048de64  3dff000000             +cmp eax, 0xff
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
    // 0048de69  7e02                   -jle 0x48de6d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048de6d;
    }
    // 0048de6b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0048de6d:
    // 0048de6d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048de6f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048de72  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048de75  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0048de78  83f81f                 +cmp eax, 0x1f
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
    // 0048de7b  7e02                   -jle 0x48de7f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048de7f;
    }
    // 0048de7d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0048de7f:
    // 0048de7f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0048de82  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048de85  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048de87  42                     -inc edx
    (cpu.edx)++;
    // 0048de88  898100b45600           -mov dword ptr [ecx + 0x56b400], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5682176) /* 0x56b400 */) = cpu.eax;
    // 0048de8e  81fab1000000           +cmp edx, 0xb1
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
    // 0048de94  7cc2                   -jl 0x48de58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048de58;
    }
    // 0048de96  83c410                 +add esp, 0x10
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
    // 0048de99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de9f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dea0:
    // 0048dea0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048dea2  e9fdfeffff             -jmp 0x48dda4
    goto L_0x0048dda4;
L_0x0048dea7:
    // 0048dea7  c1e31b                 -shl ebx, 0x1b
    cpu.ebx <<= 27 /*0x1b*/ % 32;
    // 0048deaa  c1e00b                 +shl eax, 0xb
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
    // 0048dead  e913ffffff             -jmp 0x48ddc5
    goto L_0x0048ddc5;
L_0x0048deb2:
    // 0048deb2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048deb4  e94fffffff             -jmp 0x48de08
    goto L_0x0048de08;
L_0x0048deb9:
    // 0048deb9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048debb  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048debe  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048dec1  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
    // 0048dec4  83f83f                 +cmp eax, 0x3f
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
    // 0048dec7  0f8e5bffffff           -jle 0x48de28
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048de28;
    }
    // 0048decd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048decf  e954ffffff             -jmp 0x48de28
    goto L_0x0048de28;
L_0x0048ded4:
    // 0048ded4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048ded6  eb95                   -jmp 0x48de6d
    goto L_0x0048de6d;
}

/* align: skip  */
void Application::sub_48ded8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ded8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ded9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048deda  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048dedb  81ec480a0000           -sub esp, 0xa48
    (cpu.esp) -= x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048dee1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048dee3  899424100a0000         -mov dword ptr [esp + 0xa10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.edx;
    // 0048deea  899c240c0a0000         -mov dword ptr [esp + 0xa0c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebx;
    // 0048def1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048def3  8b94245c0a0000         -mov edx, dword ptr [esp + 0xa5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 0048defa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048defc  0f85e8010000           -jne 0x48e0ea
    if (!cpu.flags.zf)
    {
        goto L_0x0048e0ea;
    }
    // 0048df02  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0048df07:
    // 0048df07  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048df09  8a1578904d00           -mov dl, byte ptr [0x4d9078]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 0048df0f  83fa0f                 +cmp edx, 0xf
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
    // 0048df12  7409                   -je 0x48df1d
    if (cpu.flags.zf)
    {
        goto L_0x0048df1d;
    }
    // 0048df14  83fa10                 +cmp edx, 0x10
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
    // 0048df17  0f85f7010000           -jne 0x48e114
    if (!cpu.flags.zf)
    {
        goto L_0x0048e114;
    }
L_0x0048df1d:
    // 0048df1d  3b15a8c55600           +cmp edx, dword ptr [0x56c5a8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5686696) /* 0x56c5a8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048df23  740d                   -je 0x48df32
    if (cpu.flags.zf)
    {
        goto L_0x0048df32;
    }
    // 0048df25  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048df27  e868fdffff             -call 0x48dc94
    cpu.esp -= 4;
    sub_48dc94(app, cpu);
    if (cpu.terminate) return;
    // 0048df2c  8915a8c55600           -mov dword ptr [0x56c5a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5686696) /* 0x56c5a8 */) = cpu.edx;
L_0x0048df32:
    // 0048df32  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048df34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048df36  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 0048df3c  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048df3f  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0048df45  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048df48  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 0048df4e  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048df51  6683e6fe               -and si, 0xfffe
    cpu.si &= x86::reg16(x86::sreg16(65534 /*0xfffe*/));
    // 0048df55  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048df57  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048df59  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048df5b  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0048df5e  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0048df61  8b8424580a0000         -mov eax, dword ptr [esp + 0xa58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2648) /* 0xa58 */);
    // 0048df68  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048df6b  899424080a0000         -mov dword ptr [esp + 0xa08], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edx;
    // 0048df72  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048df79  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048df7b  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
    // 0048df82  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048df84  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048df86  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048df89  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048df8b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048df8d  8b1568904d00           -mov edx, dword ptr [0x4d9068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 0048df93  898424040a0000         -mov dword ptr [esp + 0xa04], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */) = cpu.eax;
    // 0048df9a  39d6                   +cmp esi, edx
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
    // 0048df9c  7d22                   -jge 0x48dfc0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048dfc0;
    }
    // 0048df9e  8d1c09                 -lea ebx, [ecx + ecx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 0048dfa1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dfa3  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0048dfa6  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048dfa8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048dfaa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dfac  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dfaf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048dfb1  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048dfb4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048dfb7  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048dfb9  0184240c0a0000         -add dword ptr [esp + 0xa0c], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0048dfc0:
    // 0048dfc0  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0048dfc7  8b3d70904d00           -mov edi, dword ptr [0x4d9070]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 0048dfcd  39f8                   +cmp eax, edi
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
    // 0048dfcf  7e07                   -jle 0x48dfd8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048dfd8;
    }
    // 0048dfd1  89bc24080a0000         -mov dword ptr [esp + 0xa08], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edi;
L_0x0048dfd8:
    // 0048dfd8  8b8424100a0000         -mov eax, dword ptr [esp + 0xa10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048dfdf  8b2d6c904d00           -mov ebp, dword ptr [0x4d906c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 0048dfe5  39e8                   +cmp eax, ebp
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
    // 0048dfe7  7d47                   -jge 0x48e030
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e030;
    }
    // 0048dfe9  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048dff0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048dff2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048dff4  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0048dff7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048dff9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dffb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dffe  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048e000  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048e002  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048e005  0faf8424040a0000       -imul eax, dword ptr [esp + 0xa04]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */))));
    // 0048e00d  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048e014  8bac240c0a0000         -mov ebp, dword ptr [esp + 0xa0c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048e01b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048e01e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e020  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e022  899c24100a0000         -mov dword ptr [esp + 0xa10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.ebx;
    // 0048e029  89ac240c0a0000         -mov dword ptr [esp + 0xa0c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebp;
L_0x0048e030:
    // 0048e030  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e037  8b1574904d00           -mov edx, dword ptr [0x4d9074]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 0048e03d  39d0                   +cmp eax, edx
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
    // 0048e03f  7e07                   -jle 0x48e048
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e048;
    }
    // 0048e041  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
L_0x0048e048:
    // 0048e048  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0048e04f  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048e051  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e053  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e055  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048e058  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048e05a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048e05c  83f802                 +cmp eax, 2
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
    // 0048e05f  0f8c77000000           -jl 0x48e0dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e0dc;
    }
    // 0048e065  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0048e06c  8b8c245c0a0000         -mov ecx, dword ptr [esp + 0xa5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 0048e073  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048e076  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048e078  0f85a7000000           -jne 0x48e125
    if (!cpu.flags.zf)
    {
        goto L_0x0048e125;
    }
    // 0048e07e  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048e085  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e08c  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048e093  39dd                   +cmp ebp, ebx
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
    // 0048e095  7d45                   -jge 0x48e0dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e0dc;
    }
    // 0048e097  898424200a0000         -mov dword ptr [esp + 0xa20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */) = cpu.eax;
L_0x0048e09e:
    // 0048e09e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048e0a0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e0a2  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 0048e0a8  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048e0ab  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0048e0b1  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048e0b4  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 0048e0ba  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048e0bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e0be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e0c0  45                     -inc ebp
    (cpu.ebp)++;
    // 0048e0c1  e8f2770000             -call 0x4958b8
    cpu.esp -= 4;
    sub_4958b8(app, cpu);
    if (cpu.terminate) return;
    // 0048e0c6  8b8424200a0000         -mov eax, dword ptr [esp + 0xa20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */);
    // 0048e0cd  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e0d4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e0d6  39d5                   +cmp ebp, edx
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
    // 0048e0d8  7cc4                   -jl 0x48e09e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e09e;
    }
    // 0048e0da  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0048e0dc:
    // 0048e0dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e0de  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048e0e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0e7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e0ea:
    // 0048e0ea  83fa01                 +cmp edx, 1
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
    // 0048e0ed  750a                   -jne 0x48e0f9
    if (!cpu.flags.zf)
    {
        goto L_0x0048e0f9;
    }
L_0x0048e0ef:
    // 0048e0ef  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048e0f4  e90efeffff             -jmp 0x48df07
    goto L_0x0048df07;
L_0x0048e0f9:
    // 0048e0f9  83fa02                 +cmp edx, 2
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
    // 0048e0fc  74f1                   -je 0x48e0ef
    if (cpu.flags.zf)
    {
        goto L_0x0048e0ef;
    }
    // 0048e0fe  83fa03                 +cmp edx, 3
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
    // 0048e101  74ec                   -je 0x48e0ef
    if (cpu.flags.zf)
    {
        goto L_0x0048e0ef;
    }
    // 0048e103  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048e108  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048e10e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e10f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e110  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e111  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e114:
    // 0048e114  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0048e119  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048e11f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e120  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e121  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e122  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e125:
    // 0048e125  83f903                 +cmp ecx, 3
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
    // 0048e128  0f8578010000           -jne 0x48e2a6
    if (!cpu.flags.zf)
    {
        goto L_0x0048e2a6;
    }
    // 0048e12e  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048e135  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e13c  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048e143  39dd                   +cmp ebp, ebx
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
    // 0048e145  7d71                   -jge 0x48e1b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e1b8;
    }
    // 0048e147  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048e149  4a                     -dec edx
    (cpu.edx)--;
    // 0048e14a  899424180a0000         -mov dword ptr [esp + 0xa18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */) = cpu.edx;
    // 0048e151  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0048e154  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e157  898424140a0000         -mov dword ptr [esp + 0xa14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */) = cpu.eax;
    // 0048e15e  899424280a0000         -mov dword ptr [esp + 0xa28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */) = cpu.edx;
L_0x0048e165:
    // 0048e165  8b9c24180a0000         -mov ebx, dword ptr [esp + 0xa18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */);
    // 0048e16c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e16e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e170  e8b9790000             -call 0x495b2e
    cpu.esp -= 4;
    sub_495b2e(app, cpu);
    if (cpu.terminate) return;
    // 0048e175  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048e177  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e179  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 0048e17f  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048e182  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0048e188  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048e18b  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 0048e191  8b9c24280a0000         -mov ebx, dword ptr [esp + 0xa28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */);
    // 0048e198  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e19a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048e19c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e19f  e814770000             -call 0x4958b8
    cpu.esp -= 4;
    sub_4958b8(app, cpu);
    if (cpu.terminate) return;
    // 0048e1a4  8b8424140a0000         -mov eax, dword ptr [esp + 0xa14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */);
    // 0048e1ab  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e1b2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e1b4  39d5                   +cmp ebp, edx
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
    // 0048e1b6  7cad                   -jl 0x48e165
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e165;
    }
L_0x0048e1b8:
    // 0048e1b8  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0048e1bf  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e1c6  8b8c24100a0000         -mov ecx, dword ptr [esp + 0xa10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048e1cd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048e1cf  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e1d1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048e1d4  3d00580200             +cmp eax, 0x25800
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
    // 0048e1d9  0f8fae000000           -jg 0x48e28d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048e28d;
    }
L_0x0048e1df:
    // 0048e1df  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048e1e6  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 0048e1e9  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048e1f0  899424340a0000         -mov dword ptr [esp + 0xa34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */) = cpu.edx;
    // 0048e1f7  8b9424040a0000         -mov edx, dword ptr [esp + 0xa04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0048e1fe  45                     -inc ebp
    (cpu.ebp)++;
    // 0048e1ff  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048e202  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048e204  899424240a0000         -mov dword ptr [esp + 0xa24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */) = cpu.edx;
    // 0048e20b  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e212  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e215  4a                     -dec edx
    (cpu.edx)--;
    // 0048e216  89bc24300a0000         -mov dword ptr [esp + 0xa30], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */) = cpu.edi;
    // 0048e21d  899424380a0000         -mov dword ptr [esp + 0xa38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2616) /* 0xa38 */) = cpu.edx;
    // 0048e224  39d5                   +cmp ebp, edx
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
    // 0048e226  0f8db0feffff           -jge 0x48e0dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e0dc;
    }
L_0x0048e22c:
    // 0048e22c  8bbc24240a0000         -mov edi, dword ptr [esp + 0xa24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 0048e233  8b8c24340a0000         -mov ecx, dword ptr [esp + 0xa34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */);
    // 0048e23a  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e23c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048e23e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048e240  e845790000             -call 0x495b8a
    cpu.esp -= 4;
    sub_495b8a(app, cpu);
    if (cpu.terminate) return;
    // 0048e245  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048e247  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e249  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 0048e24f  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048e252  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0048e258  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048e25b  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 0048e261  8b9c24300a0000         -mov ebx, dword ptr [esp + 0xa30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */);
    // 0048e268  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e26a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048e26c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e26f  e844760000             -call 0x4958b8
    cpu.esp -= 4;
    sub_4958b8(app, cpu);
    if (cpu.terminate) return;
    // 0048e274  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048e276  3bac24380a0000         +cmp ebp, dword ptr [esp + 0xa38]
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
    // 0048e27d  7cad                   -jl 0x48e22c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e22c;
    }
    // 0048e27f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e281  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048e287  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e288  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e289  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e28a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e28d:
    // 0048e28d  e8a641ffff             -call 0x482438
    cpu.esp -= 4;
    sub_482438(app, cpu);
    if (cpu.terminate) return;
    // 0048e292  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e294  0f8545ffffff           -jne 0x48e1df
    if (!cpu.flags.zf)
    {
        goto L_0x0048e1df;
    }
    // 0048e29a  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048e2a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2a3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e2a6:
    // 0048e2a6  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048e2ad  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e2b4  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048e2bb  39dd                   +cmp ebp, ebx
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
    // 0048e2bd  7d45                   -jge 0x48e304
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e304;
    }
    // 0048e2bf  8984241c0a0000         -mov dword ptr [esp + 0xa1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */) = cpu.eax;
L_0x0048e2c6:
    // 0048e2c6  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048e2c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e2ca  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 0048e2d0  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048e2d3  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0048e2d9  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048e2dc  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 0048e2e2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048e2e4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e2e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e2e8  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e2eb  e89b760000             -call 0x49598b
    cpu.esp -= 4;
    sub_49598b(app, cpu);
    if (cpu.terminate) return;
    // 0048e2f0  8b84241c0a0000         -mov eax, dword ptr [esp + 0xa1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */);
    // 0048e2f7  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e2fe  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e300  39d5                   +cmp ebp, edx
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
    // 0048e302  7cc2                   -jl 0x48e2c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e2c6;
    }
L_0x0048e304:
    // 0048e304  83bc245c0a000002       +cmp dword ptr [esp + 0xa5c], 2
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
    // 0048e30c  0f85cafdffff           -jne 0x48e0dc
    if (!cpu.flags.zf)
    {
        goto L_0x0048e0dc;
    }
    // 0048e312  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0048e319  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e320  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048e327  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048e329  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e32b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048e32e  3d00580200             +cmp eax, 0x25800
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
    // 0048e333  0f8fab000000           -jg 0x48e3e4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048e3e4;
    }
L_0x0048e339:
    // 0048e339  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048e340  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 0048e347  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0048e34e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048e351  8984242c0a0000         -mov dword ptr [esp + 0xa2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */) = cpu.eax;
    // 0048e358  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048e35f  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048e366  48                     -dec eax
    (cpu.eax)--;
    // 0048e367  45                     -inc ebp
    (cpu.ebp)++;
    // 0048e368  8984243c0a0000         -mov dword ptr [esp + 0xa3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */) = cpu.eax;
    // 0048e36f  39c5                   +cmp ebp, eax
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
    // 0048e371  0f8d65fdffff           -jge 0x48e0dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e0dc;
    }
L_0x0048e377:
    // 0048e377  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048e379  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e37b  8b8c242c0a0000         -mov ecx, dword ptr [esp + 0xa2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */);
    // 0048e382  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 0048e388  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048e38b  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0048e391  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048e394  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 0048e39a  8b9424400a0000         -mov edx, dword ptr [esp + 0xa40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 0048e3a1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048e3a3  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e3a6  8b8424400a0000         -mov eax, dword ptr [esp + 0xa40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 0048e3ad  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e3af  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048e3b1  899424000a0000         -mov dword ptr [esp + 0xa00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */) = cpu.edx;
    // 0048e3b8  e895760000             -call 0x495a52
    cpu.esp -= 4;
    sub_495a52(app, cpu);
    if (cpu.terminate) return;
    // 0048e3bd  8b8424000a0000         -mov eax, dword ptr [esp + 0xa00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */);
    // 0048e3c4  8b9c243c0a0000         -mov ebx, dword ptr [esp + 0xa3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */);
    // 0048e3cb  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 0048e3d2  39dd                   +cmp ebp, ebx
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
    // 0048e3d4  7ca1                   -jl 0x48e377
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e377;
    }
    // 0048e3d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e3d8  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048e3de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3e1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e3e4:
    // 0048e3e4  e84f40ffff             -call 0x482438
    cpu.esp -= 4;
    sub_482438(app, cpu);
    if (cpu.terminate) return;
    // 0048e3e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e3eb  0f8548ffffff           -jne 0x48e339
    if (!cpu.flags.zf)
    {
        goto L_0x0048e339;
    }
    // 0048e3f1  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048e3f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3fa  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_48e400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e400  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e402  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48e404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e404  a384ab4d00             -mov dword ptr [0x4dab84], eax
    app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */) = cpu.eax;
    // 0048e409  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e40c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e40c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e40d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e40f  8b1584ab4d00           -mov edx, dword ptr [0x4dab84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0048e415  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 0048e41a  a398ab4d00             -mov dword ptr [0x4dab98], eax
    app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */) = cpu.eax;
    // 0048e41f  05c0000000             -add eax, 0xc0
    (cpu.eax) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0048e424  e80f210000             -call 0x490538
    cpu.esp -= 4;
    sub_490538(app, cpu);
    if (cpu.terminate) return;
    // 0048e429  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0048e42f  89463c                 -mov dword ptr [esi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0048e432  8b8688000000           -mov eax, dword ptr [esi + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0048e438  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048e43b  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0048e441  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0048e447  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e449  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048e44c  894e2c                 -mov dword ptr [esi + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0048e44f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048e452  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048e455  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048e458  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048e45b  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048e45e  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048e461  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048e464  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048e467  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0048e46e  895e40                 -mov dword ptr [esi + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0048e471  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0048e478  c7467000000000         -mov dword ptr [esi + 0x70], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 0048e47f  c7467800000000         -mov dword ptr [esi + 0x78], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 0048e486  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0048e489  89467c                 -mov dword ptr [esi + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 0048e48c  c7462007000000         -mov dword ptr [esi + 0x20], 7
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048e493  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0048e49a  c7463800000000         -mov dword ptr [esi + 0x38], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 0048e4a1  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0048e4a4  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0048e4a7  c786bc00000000000000   -mov dword ptr [esi + 0xbc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 0048e4b1  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0048e4b7  8986b8000000           -mov dword ptr [esi + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 0048e4bd  c7463000000000         -mov dword ptr [esi + 0x30], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0048e4c4  e8b39dffff             -call 0x48827c
    cpu.esp -= 4;
    sub_48827c(app, cpu);
    if (cpu.terminate) return;
    // 0048e4c9  8986a4000000           -mov dword ptr [esi + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048e4cf  e8949effff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048e4d4  8986ac000000           -mov dword ptr [esi + 0xac], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0048e4da  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0048e4df  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0048e4e5  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048e4ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048e4eb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e4ed  b8b8ee4800             -mov eax, 0x48eeb8
    cpu.eax = 4779704 /*0x48eeb8*/;
    // 0048e4f2  e8599affff             -call 0x487f50
    cpu.esp -= 4;
    sub_487f50(app, cpu);
    if (cpu.terminate) return;
    // 0048e4f7  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0048e4fd  e8ca9dffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048e502  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e504  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e505  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e508(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e508  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e509  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e50b  e8fcfeffff             -call 0x48e40c
    cpu.esp -= 4;
    sub_48e40c(app, cpu);
    if (cpu.terminate) return;
    // 0048e510  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e511  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e514(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e514  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e515  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e51a  e8edfeffff             -call 0x48e40c
    cpu.esp -= 4;
    sub_48e40c(app, cpu);
    if (cpu.terminate) return;
    // 0048e51f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e520  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e524(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e524  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e525  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e526  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e527  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048e52a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048e52e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048e530  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0048e532  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048e534  66a9ff0f               +test ax, 0xfff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 4095 /*0xfff*/));
    // 0048e538  740c                   -je 0x48e546
    if (cpu.flags.zf)
    {
        goto L_0x0048e546;
    }
    // 0048e53a  8db800100000           -lea edi, [eax + 0x1000]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4096) /* 0x1000 */);
    // 0048e540  81e700f0ff7f           -and edi, 0x7ffff000
    cpu.edi &= x86::reg32(x86::sreg32(2147479552 /*0x7ffff000*/));
L_0x0048e546:
    // 0048e546  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0048e54b  b8c0e44c00             -mov eax, 0x4ce4c0
    cpu.eax = 5039296 /*0x4ce4c0*/;
    // 0048e550  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048e552  e8c943ffff             -call 0x482920
    cpu.esp -= 4;
    sub_482920(app, cpu);
    if (cpu.terminate) return;
    // 0048e557  8b1584ab4d00           -mov edx, dword ptr [0x4dab84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0048e55d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048e560  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048e567  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e569  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048e56c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e56e  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048e575  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048e577  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048e57a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048e57c  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 0048e582  b8e8e44c00             -mov eax, 0x4ce4e8
    cpu.eax = 5039336 /*0x4ce4e8*/;
    // 0048e587  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0048e58d  e8a243ffff             -call 0x482934
    cpu.esp -= 4;
    sub_482934(app, cpu);
    if (cpu.terminate) return;
    // 0048e592  8b1584ab4d00           -mov edx, dword ptr [0x4dab84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0048e598  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e59a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048e5a1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e5a3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048e5a6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e5a8  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048e5af  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048e5b2  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 0048e5b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e5ba  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0048e5c0  e8c79effff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048e5c5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e5c8  898688000000           -mov dword ptr [esi + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0048e5ce  89be84000000           -mov dword ptr [esi + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 0048e5d4  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 0048e5d9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048e5db  e820920000             -call 0x497800
    cpu.esp -= 4;
    sub_497800(app, cpu);
    if (cpu.terminate) return;
    // 0048e5e0  8b3d84ab4d00           -mov edi, dword ptr [0x4dab84]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0048e5e6  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 0048e5ed  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048e5ef  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048e5f2  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048e5f4  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048e5f7  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048e5fa  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 0048e5ff  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 0048e605  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e607  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0048e60d  e8ee910000             -call 0x497800
    cpu.esp -= 4;
    sub_497800(app, cpu);
    if (cpu.terminate) return;
    // 0048e612  8b3d84ab4d00           -mov edi, dword ptr [0x4dab84]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0048e618  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 0048e61f  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048e621  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048e624  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048e626  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048e629  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048e62b  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048e62e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e632  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 0048e638  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e63a  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0048e640  e8c7fdffff             -call 0x48e40c
    cpu.esp -= 4;
    sub_48e40c(app, cpu);
    if (cpu.terminate) return;
    // 0048e645  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048e648  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e649  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e64a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e64b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48e64c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e64c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e64d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e64f  e8d0feffff             -call 0x48e524
    cpu.esp -= 4;
    sub_48e524(app, cpu);
    if (cpu.terminate) return;
    // 0048e654  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e655  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e658(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e658  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e659  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e65e  e8c1feffff             -call 0x48e524
    cpu.esp -= 4;
    sub_48e524(app, cpu);
    if (cpu.terminate) return;
    // 0048e663  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e664  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e668  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e669  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e66a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e66b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e66c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e66d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048e670  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e672  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048e674  e81735ffff             -call 0x481b90
    cpu.esp -= 4;
    sub_481b90(app, cpu);
    if (cpu.terminate) return;
    // 0048e679  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e67d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e67f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048e683  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e687  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e68b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048e68c  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e690  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e692  e849a90100             -call 0x4a8fe0
    cpu.esp -= 4;
    sub_4a8fe0(app, cpu);
    if (cpu.terminate) return;
    // 0048e697  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048e699  0f8590000000           -jne 0x48e72f
    if (!cpu.flags.zf)
    {
        goto L_0x0048e72f;
    }
    // 0048e69f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e6a2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048e6a6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e6aa  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048e6ae  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e6b2  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0048e6b6:
    // 0048e6b6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e6ba  2d00200000             -sub eax, 0x2000
    (cpu.eax) -= x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 0048e6bf  662500e0               -and ax, 0xe000
    cpu.ax &= x86::reg16(x86::sreg16(57344 /*0xe000*/));
    // 0048e6c3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048e6c7  3d00000400             +cmp eax, 0x40000
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
    // 0048e6cc  0f8f7a000000           -jg 0x48e74c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048e74c;
    }
L_0x0048e6d2:
    // 0048e6d2  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 0048e6d7  b854e54c00             -mov eax, 0x4ce554
    cpu.eax = 5039444 /*0x4ce554*/;
    // 0048e6dc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e6de  e82542ffff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0048e6e3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e6e5  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 0048e6ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e6ec  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e6f0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048e6f3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048e6f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0048e6f7:
    // 0048e6f7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e6fa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048e6fc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048e6fe  e869a90100             -call 0x4a906c
    cpu.esp -= 4;
    sub_4a906c(app, cpu);
    if (cpu.terminate) return;
    // 0048e703  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e705  74f0                   -je 0x48e6f7
    if (cpu.flags.zf)
    {
        goto L_0x0048e6f7;
    }
    // 0048e707  e82b31ffff             -call 0x481837
    cpu.esp -= 4;
    sub_481837(app, cpu);
    if (cpu.terminate) return;
    // 0048e70c  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e710  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048e712  7e4f                   -jle 0x48e763
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e763;
    }
    // 0048e714  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0048e716:
    // 0048e716  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e719  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048e71b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048e71d  e84aa90100             -call 0x4a906c
    cpu.esp -= 4;
    sub_4a906c(app, cpu);
    if (cpu.terminate) return;
    // 0048e722  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e724  7533                   -jne 0x48e759
    if (!cpu.flags.zf)
    {
        goto L_0x0048e759;
    }
    // 0048e726  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e728  e8f33bffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0048e72d  ebe7                   -jmp 0x48e716
    goto L_0x0048e716;
L_0x0048e72f:
    // 0048e72f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e733  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e737  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048e73b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048e73c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e740  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048e742  e899a80100             -call 0x4a8fe0
    cpu.esp -= 4;
    sub_4a8fe0(app, cpu);
    if (cpu.terminate) return;
    // 0048e747  e96affffff             -jmp 0x48e6b6
    goto L_0x0048e6b6;
L_0x0048e74c:
    // 0048e74c  c744240800000400       -mov dword ptr [esp + 8], 0x40000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 262144 /*0x40000*/;
    // 0048e754  e979ffffff             -jmp 0x48e6d2
    goto L_0x0048e6d2;
L_0x0048e759:
    // 0048e759  81ef00200000           -sub edi, 0x2000
    (cpu.edi) -= x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 0048e75f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048e761  7fb3                   -jg 0x48e716
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048e716;
    }
L_0x0048e763:
    // 0048e763  e8cf30ffff             -call 0x481837
    cpu.esp -= 4;
    sub_481837(app, cpu);
    if (cpu.terminate) return;
    // 0048e768  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048e76a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0048e76c:
    // 0048e76c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e770  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048e772  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048e774  e8f3a80100             -call 0x4a906c
    cpu.esp -= 4;
    sub_4a906c(app, cpu);
    if (cpu.terminate) return;
    // 0048e779  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e77b  7509                   -jne 0x48e786
    if (!cpu.flags.zf)
    {
        goto L_0x0048e786;
    }
    // 0048e77d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e77f  e89c3bffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0048e784  ebe6                   -jmp 0x48e76c
    goto L_0x0048e76c;
L_0x0048e786:
    // 0048e786  e8ac30ffff             -call 0x481837
    cpu.esp -= 4;
    sub_481837(app, cpu);
    if (cpu.terminate) return;
    // 0048e78b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048e78d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e790  e877a80100             -call 0x4a900c
    cpu.esp -= 4;
    sub_4a900c(app, cpu);
    if (cpu.terminate) return;
    // 0048e795  837c241c00             +cmp dword ptr [esp + 0x1c], 0
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
    // 0048e79a  7409                   -je 0x48e7a5
    if (cpu.flags.zf)
    {
        goto L_0x0048e7a5;
    }
    // 0048e79c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e7a0  e867a80100             -call 0x4a900c
    cpu.esp -= 4;
    sub_4a900c(app, cpu);
    if (cpu.terminate) return;
L_0x0048e7a5:
    // 0048e7a5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e7a7  e8c045ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0048e7ac  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 0048e7b3  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0048e7b6  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e7b8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048e7bb  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e7bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e7c1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048e7c4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048e7c6  a3acc55600             -mov dword ptr [0x56c5ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5686700) /* 0x56c5ac */) = cpu.eax;
    // 0048e7cb  83f801                 +cmp eax, 1
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
    // 0048e7ce  7d0a                   -jge 0x48e7da
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e7da;
    }
    // 0048e7d0  c705acc5560001000000   -mov dword ptr [0x56c5ac], 1
    app->getMemory<x86::reg32>(x86::reg32(5686700) /* 0x56c5ac */) = 1 /*0x1*/;
L_0x0048e7da:
    // 0048e7da  b80000e803             -mov eax, 0x3e80000
    cpu.eax = 65536000 /*0x3e80000*/;
    // 0048e7df  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e7e1  8b0dacc55600           -mov ecx, dword ptr [0x56c5ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5686700) /* 0x56c5ac */);
    // 0048e7e7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048e7ea  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048e7ec  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e7f0  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 0048e7f7  a3b0c55600             -mov dword ptr [0x56c5b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5686704) /* 0x56c5b0 */) = cpu.eax;
    // 0048e7fc  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048e7fe  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e802  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e804  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048e807  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048e80a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e80c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e80e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048e811  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048e813  a388ab4d00             -mov dword ptr [0x4dab88], eax
    app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */) = cpu.eax;
    // 0048e818  3dda000000             +cmp eax, 0xda
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
    // 0048e81d  7f25                   -jg 0x48e844
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048e844;
    }
    // 0048e81f  3da3000000             +cmp eax, 0xa3
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
    // 0048e824  7c2a                   -jl 0x48e850
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e850;
    }
L_0x0048e826:
    // 0048e826  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048e82d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e82f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e831  a38cab4d00             -mov dword ptr [0x4dab8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090188) /* 0x4dab8c */) = cpu.eax;
    // 0048e836  a1b0c55600             -mov eax, dword ptr [0x56c5b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5686704) /* 0x56c5b0 */);
    // 0048e83b  83c420                 +add esp, 0x20
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
    // 0048e83e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e83f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e840  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e841  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e842  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e843  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e844:
    // 0048e844  c70588ab4d00da000000   -mov dword ptr [0x4dab88], 0xda
    app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */) = 218 /*0xda*/;
    // 0048e84e  ebd6                   -jmp 0x48e826
    goto L_0x0048e826;
L_0x0048e850:
    // 0048e850  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e855  890dfcb04d00           -mov dword ptr [0x4db0fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091580) /* 0x4db0fc */) = cpu.ecx;
    // 0048e85b  890d88ab4d00           -mov dword ptr [0x4dab88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */) = cpu.ecx;
    // 0048e861  ebc3                   -jmp 0x48e826
    goto L_0x0048e826;
}

/* align: skip 0x90 */
void Application::sub_48e864(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e864  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e865  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e866  bada000000             -mov edx, 0xda
    cpu.edx = 218 /*0xda*/;
    // 0048e86b  b92c010000             -mov ecx, 0x12c
    cpu.ecx = 300 /*0x12c*/;
    // 0048e870  891588ab4d00           -mov dword ptr [0x4dab88], edx
    app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */) = cpu.edx;
    // 0048e876  890d8cab4d00           -mov dword ptr [0x4dab8c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090188) /* 0x4dab8c */) = cpu.ecx;
    // 0048e87c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e87d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e87e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48e880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e880  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e881  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e882  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e884  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048e88a  39d0                   +cmp eax, edx
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
    // 0048e88c  7403                   -je 0x48e891
    if (cpu.flags.zf)
    {
        goto L_0x0048e891;
    }
    // 0048e88e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e88f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e890  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e891:
    // 0048e891  c7422408000000         -mov dword ptr [edx + 0x24], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 8 /*0x8*/;
    // 0048e898  8b92a8000000           -mov edx, dword ptr [edx + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 0048e89e  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0048e8a3  e8e899ffff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0048e8a8  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 0048e8ae  e8199affff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048e8b3  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 0048e8b9  e89a9affff             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 0048e8be  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048e8c4  e81b9bffff             -call 0x4883e4
    cpu.esp -= 4;
    sub_4883e4(app, cpu);
    if (cpu.terminate) return;
    // 0048e8c9  c781ac00000000000000   -mov dword ptr [ecx + 0xac], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 0048e8d3  8d818c000000           -lea eax, [ecx + 0x8c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 0048e8d9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e8db  e80097ffff             -call 0x487fe0
    cpu.esp -= 4;
    sub_487fe0(app, cpu);
    if (cpu.terminate) return;
    // 0048e8e0  890d98ab4d00           -mov dword ptr [0x4dab98], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */) = cpu.ecx;
    // 0048e8e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e8ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e8ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e8ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e8ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e8ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e8f1  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048e8f7  39c8                   +cmp eax, ecx
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
    // 0048e8f9  7440                   -je 0x48e93b
    if (cpu.flags.zf)
    {
        goto L_0x0048e93b;
    }
    // 0048e8fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e8fd  83797000               +cmp dword ptr [ecx + 0x70], 0
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
    // 0048e901  740e                   -je 0x48e911
    if (cpu.flags.zf)
    {
        goto L_0x0048e911;
    }
L_0x0048e903:
    // 0048e903  3b5070                 +cmp edx, dword ptr [eax + 0x70]
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
    // 0048e906  7409                   -je 0x48e911
    if (cpu.flags.zf)
    {
        goto L_0x0048e911;
    }
    // 0048e908  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048e90b  83787000               +cmp dword ptr [eax + 0x70], 0
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
    // 0048e90f  75f2                   -jne 0x48e903
    if (!cpu.flags.zf)
    {
        goto L_0x0048e903;
    }
L_0x0048e911:
    // 0048e911  8b4a70                 -mov ecx, dword ptr [edx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0048e914  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 0048e917  8b8288000000           -mov eax, dword ptr [edx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 0048e91d  e84a44ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0048e922  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e924  e84344ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0048e929  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048e92b  892d9cab4d00           -mov dword ptr [0x4dab9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.ebp;
    // 0048e931  892d98ab4d00           -mov dword ptr [0x4dab98], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */) = cpu.ebp;
    // 0048e937  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e938  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e939  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e93a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e93b:
    // 0048e93b  e840ffffff             -call 0x48e880
    cpu.esp -= 4;
    sub_48e880(app, cpu);
    if (cpu.terminate) return;
L_0x0048e940:
    // 0048e940  8b4970                 -mov ecx, dword ptr [ecx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 0048e943  8b8288000000           -mov eax, dword ptr [edx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 0048e949  e81e44ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0048e94e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e950  e81744ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0048e955  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048e957  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048e959  75e5                   -jne 0x48e940
    if (!cpu.flags.zf)
    {
        goto L_0x0048e940;
    }
    // 0048e95b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048e95d  892d9cab4d00           -mov dword ptr [0x4dab9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.ebp;
    // 0048e963  892d98ab4d00           -mov dword ptr [0x4dab98], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */) = cpu.ebp;
    // 0048e969  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e96a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e96b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e96c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e972  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e973  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e975  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048e977  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0048e979  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048e97d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048e983  e8309affff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048e988  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e98a  e8c51c0000             -call 0x490654
    cpu.esp -= 4;
    sub_490654(app, cpu);
    if (cpu.terminate) return;
    // 0048e98f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e991  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e993  746a                   -je 0x48e9ff
    if (cpu.flags.zf)
    {
        goto L_0x0048e9ff;
    }
    // 0048e995  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 0048e99a  e8ad5fffff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 0048e99f  c6818e00000000         -mov byte ptr [ecx + 0x8e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
    // 0048e9a6  89b994000000           -mov dword ptr [ecx + 0x94], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 0048e9ac  89a990000000           -mov dword ptr [ecx + 0x90], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.ebp;
    // 0048e9b2  837e7c00               +cmp dword ptr [esi + 0x7c], 0
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
    // 0048e9b6  7456                   -je 0x48ea0e
    if (cpu.flags.zf)
    {
        goto L_0x0048ea0e;
    }
    // 0048e9b8  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 0048e9bb  898898000000           -mov dword ptr [eax + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0048e9c1  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
L_0x0048e9c4:
    // 0048e9c4  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 0048e9c9  740d                   -je 0x48e9d8
    if (cpu.flags.zf)
    {
        goto L_0x0048e9d8;
    }
    // 0048e9cb  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 0048e9cf  7507                   -jne 0x48e9d8
    if (!cpu.flags.zf)
    {
        goto L_0x0048e9d8;
    }
    // 0048e9d1  c746240f000000         -mov dword ptr [esi + 0x24], 0xf
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 15 /*0xf*/;
L_0x0048e9d8:
    // 0048e9d8  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 0048e9de  e8ed99ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048e9e3  8b96a8000000           -mov edx, dword ptr [esi + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0048e9e9  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0048e9ef  e89c98ffff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0048e9f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048e9f9:
    // 0048e9f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9fc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e9ff:
    // 0048e9ff  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 0048ea05  e8c699ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ea0a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048ea0c  ebeb                   -jmp 0x48e9f9
    goto L_0x0048e9f9;
L_0x0048ea0e:
    // 0048ea0e  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 0048ea11  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 0048ea14  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0048ea17  ebab                   -jmp 0x48e9c4
    goto L_0x0048e9c4;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ea1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ea1c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ea1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ea1e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ea1f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ea22  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048ea24  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048ea26  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048ea28  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048ea2b  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048ea2f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048ea35  e87e99ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048ea3a  837e7800               +cmp dword ptr [esi + 0x78], 0
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
    // 0048ea3e  7418                   -je 0x48ea58
    if (cpu.flags.zf)
    {
        goto L_0x0048ea58;
    }
L_0x0048ea40:
    // 0048ea40  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0048ea43  8b9098000000           -mov edx, dword ptr [eax + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 0048ea49  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0048ea4c  e8231b0000             -call 0x490574
    cpu.esp -= 4;
    sub_490574(app, cpu);
    if (cpu.terminate) return;
    // 0048ea51  837e7800               +cmp dword ptr [esi + 0x78], 0
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
    // 0048ea55  75e9                   -jne 0x48ea40
    if (!cpu.flags.zf)
    {
        goto L_0x0048ea40;
    }
    // 0048ea57  90                     -nop 
    ;
L_0x0048ea58:
    // 0048ea58  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ea5a  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 0048ea5f  e8f01b0000             -call 0x490654
    cpu.esp -= 4;
    sub_490654(app, cpu);
    if (cpu.terminate) return;
    // 0048ea64  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048ea66  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ea68  e8df5effff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 0048ea6d  c6818e00000000         -mov byte ptr [ecx + 0x8e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
    // 0048ea74  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ea77  89b994000000           -mov dword ptr [ecx + 0x94], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 0048ea7d  898190000000           -mov dword ptr [ecx + 0x90], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0048ea83  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 0048ea86  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 0048ea89  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0048ea8c  837e1c00               +cmp dword ptr [esi + 0x1c], 0
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
    // 0048ea90  740d                   -je 0x48ea9f
    if (cpu.flags.zf)
    {
        goto L_0x0048ea9f;
    }
    // 0048ea92  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 0048ea96  7507                   -jne 0x48ea9f
    if (!cpu.flags.zf)
    {
        goto L_0x0048ea9f;
    }
    // 0048ea98  c746240f000000         -mov dword ptr [esi + 0x24], 0xf
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 15 /*0xf*/;
L_0x0048ea9f:
    // 0048ea9f  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 0048eaa5  e82699ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048eaaa  8b96a8000000           -mov edx, dword ptr [esi + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0048eab0  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0048eab6  e8d597ffff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0048eabb  83ff0b                 +cmp edi, 0xb
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
    // 0048eabe  7418                   -je 0x48ead8
    if (cpu.flags.zf)
    {
        goto L_0x0048ead8;
    }
    // 0048eac0  83ff0d                 +cmp edi, 0xd
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
    // 0048eac3  7413                   -je 0x48ead8
    if (cpu.flags.zf)
    {
        goto L_0x0048ead8;
    }
    // 0048eac5  83ff14                 +cmp edi, 0x14
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
    // 0048eac8  740e                   -je 0x48ead8
    if (cpu.flags.zf)
    {
        goto L_0x0048ead8;
    }
    // 0048eaca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048eacf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ead2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ead3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ead4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ead5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048ead8:
    // 0048ead8  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0048eade  e8e997ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048eae3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048eae8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048eaeb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eaec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eaed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eaee  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48eaf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eaf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eaf5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eaf6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048eaf8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048eafd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eaff  e818ffffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048eb04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48eb08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eb08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eb0a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048eb0c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048eb11  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb13  e804ffffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048eb18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48eb1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eb1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eb1e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048eb20  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048eb22  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 0048eb27  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb29  e842feffff             -call 0x48e970
    cpu.esp -= 4;
    sub_48e970(app, cpu);
    if (cpu.terminate) return;
    // 0048eb2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48eb34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eb34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eb36  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048eb38  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048eb3a  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 0048eb3f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb41  e82afeffff             -call 0x48e970
    cpu.esp -= 4;
    sub_48e970(app, cpu);
    if (cpu.terminate) return;
    // 0048eb46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48eb4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eb4c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb4d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eb4e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048eb50  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 0048eb55  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb57  e8c0feffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048eb5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb5d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48eb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eb60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eb62  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048eb64  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 0048eb69  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb6b  e8acfeffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048eb70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48eb74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eb74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eb76  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048eb78  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 0048eb7d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb7f  e898feffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048eb84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48eb88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eb88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eb8a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048eb8c  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 0048eb91  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb93  e884feffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048eb98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48eb9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eb9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eb9e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048eba0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048eba2  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 0048eba7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eba9  e8c2fdffff             -call 0x48e970
    cpu.esp -= 4;
    sub_48e970(app, cpu);
    if (cpu.terminate) return;
    // 0048ebae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ebb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ebb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ebb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ebb6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ebb8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ebba  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 0048ebbf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ebc1  e8aafdffff             -call 0x48e970
    cpu.esp -= 4;
    sub_48e970(app, cpu);
    if (cpu.terminate) return;
    // 0048ebc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ebcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ebcc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ebcd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ebce  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048ebd0  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0048ebd5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ebd7  e840feffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048ebdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ebe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ebe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ebe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ebe2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ebe4  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0048ebe9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ebeb  e82cfeffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048ebf0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebf1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ebf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ebf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ebf5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ebf6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048ebf8  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048ebfd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048ebff  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048ec01  ba7ce54c00             -mov edx, 0x4ce57c
    cpu.edx = 5039484 /*0x4ce57c*/;
    // 0048ec06  e865fdffff             -call 0x48e970
    cpu.esp -= 4;
    sub_48e970(app, cpu);
    if (cpu.terminate) return;
    // 0048ec0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec0c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ec10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ec11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ec12  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ec14  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048ec19  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048ec1b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048ec1d  ba7ce54c00             -mov edx, 0x4ce57c
    cpu.edx = 5039484 /*0x4ce57c*/;
    // 0048ec22  e849fdffff             -call 0x48e970
    cpu.esp -= 4;
    sub_48e970(app, cpu);
    if (cpu.terminate) return;
    // 0048ec27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ec2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ec2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ec2e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048ec30  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048ec35  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ec37  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048ec39  ba7ce54c00             -mov edx, 0x4ce57c
    cpu.edx = 5039484 /*0x4ce57c*/;
    // 0048ec3e  e82dfdffff             -call 0x48e970
    cpu.esp -= 4;
    sub_48e970(app, cpu);
    if (cpu.terminate) return;
    // 0048ec43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ec48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ec49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ec4a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ec4c  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048ec51  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ec53  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048ec55  ba7ce54c00             -mov edx, 0x4ce57c
    cpu.edx = 5039484 /*0x4ce57c*/;
    // 0048ec5a  e811fdffff             -call 0x48e970
    cpu.esp -= 4;
    sub_48e970(app, cpu);
    if (cpu.terminate) return;
    // 0048ec5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ec64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ec65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ec66  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048ec68  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 0048ec6d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048ec6f  ba7ce54c00             -mov edx, 0x4ce57c
    cpu.edx = 5039484 /*0x4ce57c*/;
    // 0048ec74  e8a3fdffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048ec79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ec7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ec7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ec7e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ec80  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 0048ec85  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048ec87  ba7ce54c00             -mov edx, 0x4ce57c
    cpu.edx = 5039484 /*0x4ce57c*/;
    // 0048ec8c  e88bfdffff             -call 0x48ea1c
    cpu.esp -= 4;
    sub_48ea1c(app, cpu);
    if (cpu.terminate) return;
    // 0048ec91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ec94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ec95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ec96  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ec97  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ec99  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ec9b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048eca1  e81297ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048eca6  837a7800               +cmp dword ptr [edx + 0x78], 0
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
    // 0048ecaa  7418                   -je 0x48ecc4
    if (cpu.flags.zf)
    {
        goto L_0x0048ecc4;
    }
L_0x0048ecac:
    // 0048ecac  41                     -inc ecx
    (cpu.ecx)++;
    // 0048ecad  8b4278                 -mov eax, dword ptr [edx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 0048ecb0  8b9898000000           -mov ebx, dword ptr [eax + 0x98]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 0048ecb6  895a78                 -mov dword ptr [edx + 0x78], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = cpu.ebx;
    // 0048ecb9  e8b6180000             -call 0x490574
    cpu.esp -= 4;
    sub_490574(app, cpu);
    if (cpu.terminate) return;
    // 0048ecbe  837a7800               +cmp dword ptr [edx + 0x78], 0
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
    // 0048ecc2  75e8                   -jne 0x48ecac
    if (!cpu.flags.zf)
    {
        goto L_0x0048ecac;
    }
L_0x0048ecc4:
    // 0048ecc4  8b4278                 -mov eax, dword ptr [edx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 0048ecc7  89427c                 -mov dword ptr [edx + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 0048ecca  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048ecd0  e8fb96ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ecd5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ecd7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ecd8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ecd9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ecda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ecdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ecdc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ecdd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ecde  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ece0  8bb084000000           -mov esi, dword ptr [eax + 0x84]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 0048ece6  89703c                 -mov dword ptr [eax + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0048ece9  8bb088000000           -mov esi, dword ptr [eax + 0x88]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 0048ecef  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0048ecf2  8bb088000000           -mov esi, dword ptr [eax + 0x88]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 0048ecf8  8bb884000000           -mov edi, dword ptr [eax + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 0048ecfe  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048ed00  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0048ed03  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ed06  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0048ed09  8b7018                 -mov esi, dword ptr [eax + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048ed0c  897014                 -mov dword ptr [eax + 0x14], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0048ed0f  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048ed12  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0048ed15  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048ed18  897010                 -mov dword ptr [eax + 0x10], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0048ed1b  c780bc00000000000000   -mov dword ptr [eax + 0xbc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 0048ed25  8bb0bc000000           -mov esi, dword ptr [eax + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 0048ed2b  89b0b8000000           -mov dword ptr [eax + 0xb8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.esi;
    // 0048ed31  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0048ed38  c7404000000000         -mov dword ptr [eax + 0x40], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 0048ed3f  c7405c00000000         -mov dword ptr [eax + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 0048ed46  c7405401000000         -mov dword ptr [eax + 0x54], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 1 /*0x1*/;
    // 0048ed4d  89586c                 -mov dword ptr [eax + 0x6c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 0048ed50  895068                 -mov dword ptr [eax + 0x68], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 0048ed53  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ed59  8b9aac000000           -mov ebx, dword ptr [edx + 0xac]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048ed5f  8998ac000000           -mov dword ptr [eax + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 0048ed65  8b9aa8000000           -mov ebx, dword ptr [edx + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 0048ed6b  8998a8000000           -mov dword ptr [eax + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 0048ed71  8db88c000000           -lea edi, [eax + 0x8c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 0048ed77  8db28c000000           -lea esi, [edx + 0x8c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(140) /* 0x8c */);
    // 0048ed7d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ed7e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ed7f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ed80  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ed81  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ed82  8b9aa4000000           -mov ebx, dword ptr [edx + 0xa4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 0048ed88  8998a4000000           -mov dword ptr [eax + 0xa4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = cpu.ebx;
    // 0048ed8e  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048ed94  e81f96ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048ed99  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ed9e  83787000               +cmp dword ptr [eax + 0x70], 0
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
    // 0048eda2  740c                   -je 0x48edb0
    if (cpu.flags.zf)
    {
        goto L_0x0048edb0;
    }
L_0x0048eda4:
    // 0048eda4  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048eda7  83787000               +cmp dword ptr [eax + 0x70], 0
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
    // 0048edab  75f7                   -jne 0x48eda4
    if (!cpu.flags.zf)
    {
        goto L_0x0048eda4;
    }
    // 0048edad  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048edb0:
    // 0048edb0  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 0048edb3  c7417000000000         -mov dword ptr [ecx + 0x70], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 0048edba  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048edbf  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048edc5  e80696ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048edca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048edcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048edcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048edce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48edd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048edd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048edd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048edd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048edd3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048edd6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048edd9  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048eddb  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048eddd  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048eddf  66f7c3ff0f             +test bx, 0xfff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & 4095 /*0xfff*/));
    // 0048ede4  740c                   -je 0x48edf2
    if (cpu.flags.zf)
    {
        goto L_0x0048edf2;
    }
    // 0048ede6  8d8b00100000           -lea ecx, [ebx + 0x1000]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(4096) /* 0x1000 */);
    // 0048edec  81e100f0ff7f           -and ecx, 0x7ffff000
    cpu.ecx &= x86::reg32(x86::sreg32(2147479552 /*0x7ffff000*/));
L_0x0048edf2:
    // 0048edf2  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0048edf7  b8c0e44c00             -mov eax, 0x4ce4c0
    cpu.eax = 5039296 /*0x4ce4c0*/;
    // 0048edfc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048edfe  e81d3bffff             -call 0x482920
    cpu.esp -= 4;
    sub_482920(app, cpu);
    if (cpu.terminate) return;
    // 0048ee03  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 0048ee08  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048ee0a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048ee0c  b880e54c00             -mov eax, 0x4ce580
    cpu.eax = 5039488 /*0x4ce580*/;
    // 0048ee11  e8f23affff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0048ee16  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 0048ee1b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048ee1d  e86a96ffff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048ee22  89be88000000           -mov dword ptr [esi + 0x88], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.edi;
    // 0048ee28  898e84000000           -mov dword ptr [esi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 0048ee2e  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 0048ee33  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048ee35  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048ee37  e8c4890000             -call 0x497800
    cpu.esp -= 4;
    sub_497800(app, cpu);
    if (cpu.terminate) return;
    // 0048ee3c  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 0048ee41  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 0048ee46  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ee48  b9c0000000             -mov ecx, 0xc0
    cpu.ecx = 192 /*0xc0*/;
    // 0048ee4d  e8ae890000             -call 0x497800
    cpu.esp -= 4;
    sub_497800(app, cpu);
    if (cpu.terminate) return;
    // 0048ee52  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ee55  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048ee57  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ee59  e87efeffff             -call 0x48ecdc
    cpu.esp -= 4;
    sub_48ecdc(app, cpu);
    if (cpu.terminate) return;
    // 0048ee5e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ee61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ee62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ee63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ee64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48eeb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0048eeb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eeb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eeba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048eebb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048eebc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048eebd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048eebe  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048eec1  e8b693ffff             -call 0x48827c
    cpu.esp -= 4;
    sub_48827c(app, cpu);
    if (cpu.terminate) return;
    // 0048eec6  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048eecc  8982a8000000           -mov dword ptr [edx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0048eed2  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 0048eed8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048eeda  e8b193ffff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0048eedf  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0048eee4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
  [[fallthrough]];
  case 0x0048eee6:
L_0x0048eee6:
    // 0048eee6  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048eeeb  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048eef1  e8c294ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048eef6  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048eefb  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0048eefe  83fa08                 +cmp edx, 8
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
    // 0048ef01  0f848f000000           -je 0x48ef96
    if (cpu.flags.zf)
    {
        goto L_0x0048ef96;
    }
    // 0048ef07  8378240f               +cmp dword ptr [eax + 0x24], 0xf
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
    // 0048ef0b  7507                   -jne 0x48ef14
    if (!cpu.flags.zf)
    {
        goto L_0x0048ef14;
    }
    // 0048ef0d  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x0048ef14:
    // 0048ef14  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ef19  896824                 -mov dword ptr [eax + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 0048ef1c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048ef22  e8a994ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ef27  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ef2c  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048ef2f  4a                     -dec edx
    (cpu.edx)--;
    // 0048ef30  83fa13                 +cmp edx, 0x13
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
    // 0048ef33  77b1                   -ja 0x48eee6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 0048ef35  ff249568ee4800         -jmp dword ptr [edx*4 + 0x48ee68]
    cpu.ip = app->getMemory<x86::reg32>(4779624 + cpu.edx * 4); goto dynamic_jump;
  case 0x0048ef3c:
    // 0048ef3c  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ef41  3b681c                 +cmp ebp, dword ptr [eax + 0x1c]
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
    // 0048ef44  7408                   -je 0x48ef4e
    if (cpu.flags.zf)
    {
        goto L_0x0048ef4e;
    }
    // 0048ef46  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ef49  e8bea00100             -call 0x4a900c
    cpu.esp -= 4;
    sub_4a900c(app, cpu);
    if (cpu.terminate) return;
L_0x0048ef4e:
    // 0048ef4e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048ef50  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ef51  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ef56  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 0048ef59  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048ef5c  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ef5f  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048ef65  e876a00100             -call 0x4a8fe0
    cpu.esp -= 4;
    sub_4a8fe0(app, cpu);
    if (cpu.terminate) return;
    // 0048ef6a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ef6c  0f8539010000           -jne 0x48f0ab
    if (!cpu.flags.zf)
    {
        goto L_0x0048f0ab;
    }
L_0x0048ef72:
    // 0048ef72  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ef77  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048ef7d  e8f2150000             -call 0x490574
    cpu.esp -= 4;
    sub_490574(app, cpu);
    if (cpu.terminate) return;
    // 0048ef82  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ef87  89681c                 -mov dword ptr [eax + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0048ef8a  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048ef91  e950ffffff             -jmp 0x48eee6
    goto L_0x0048eee6;
L_0x0048ef96:
    // 0048ef96  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0048ef99  e976ffffff             -jmp 0x48ef14
    goto L_0x0048ef14;
  case 0x0048ef9e:
    // 0048ef9e  e8a9120000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048efa3  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048efa8  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
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
    // 0048efab  752e                   -jne 0x48efdb
    if (!cpu.flags.zf)
    {
        goto L_0x0048efdb;
    }
    // 0048efad  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048efb0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048efb2  e8d98ffcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048efb7  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048efbc  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048efc2  e80593ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048efc7  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048efcc  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048efcf  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048efd1  e8ba8ffcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048efd6  e90bffffff             -jmp 0x48eee6
    goto L_0x0048eee6;
L_0x0048efdb:
    // 0048efdb  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048efe1  e8d293ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048efe6  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048efec  8b4178                 -mov eax, dword ptr [ecx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0048efef  8b5178                 -mov edx, dword ptr [ecx + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0048eff2  8b9298000000           -mov edx, dword ptr [edx + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */);
    // 0048eff8  895178                 -mov dword ptr [ecx + 0x78], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0048effb  898180000000           -mov dword ptr [ecx + 0x80], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 0048f001  8b5978                 -mov ebx, dword ptr [ecx + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0048f004  39dd                   +cmp ebp, ebx
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
    // 0048f006  7503                   -jne 0x48f00b
    if (!cpu.flags.zf)
    {
        goto L_0x0048f00b;
    }
    // 0048f008  89597c                 -mov dword ptr [ecx + 0x7c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.ebx;
L_0x0048f00b:
    // 0048f00b  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f011  8b8894000000           -mov ecx, dword ptr [eax + 0x94]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 0048f017  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0048f01a  8b4a50                 -mov ecx, dword ptr [edx + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 0048f01d  8bb090000000           -mov esi, dword ptr [eax + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */);
    // 0048f023  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048f025  894a60                 -mov dword ptr [edx + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 0048f028  8b9094000000           -mov edx, dword ptr [eax + 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 0048f02e  83fa0d                 +cmp edx, 0xd
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
    // 0048f031  7515                   -jne 0x48f048
    if (!cpu.flags.zf)
    {
        goto L_0x0048f048;
    }
L_0x0048f033:
    // 0048f033  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f038  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f03e  e88d93ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f043  e99efeffff             -jmp 0x48eee6
    goto L_0x0048eee6;
L_0x0048f048:
    // 0048f048  83fa14                 +cmp edx, 0x14
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
    // 0048f04b  74e6                   -je 0x48f033
    if (cpu.flags.zf)
    {
        goto L_0x0048f033;
    }
    // 0048f04d  39d7                   +cmp edi, edx
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
    // 0048f04f  74e2                   -je 0x48f033
    if (cpu.flags.zf)
    {
        goto L_0x0048f033;
    }
    // 0048f051  83fa11                 +cmp edx, 0x11
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
    // 0048f054  74dd                   -je 0x48f033
    if (cpu.flags.zf)
    {
        goto L_0x0048f033;
    }
    // 0048f056  83fa12                 +cmp edx, 0x12
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
    // 0048f059  74d8                   -je 0x48f033
    if (cpu.flags.zf)
    {
        goto L_0x0048f033;
    }
    // 0048f05b  83fa13                 +cmp edx, 0x13
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
    // 0048f05e  74d3                   -je 0x48f033
    if (cpu.flags.zf)
    {
        goto L_0x0048f033;
    }
    // 0048f060  e80f150000             -call 0x490574
    cpu.esp -= 4;
    sub_490574(app, cpu);
    if (cpu.terminate) return;
    // 0048f065  ebcc                   -jmp 0x48f033
    goto L_0x0048f033;
  case 0x0048f067:
    // 0048f067  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 0048f06b  7534                   -jne 0x48f0a1
    if (!cpu.flags.zf)
    {
        goto L_0x0048f0a1;
    }
L_0x0048f06d:
    // 0048f06d  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f072  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0048f079  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048f07f  e8d492ffff             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 0048f084  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f08a  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 0048f090  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f092  e8f991ffff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0048f097  83c404                 +add esp, 4
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
    // 0048f09a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f09b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f09c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f09d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f09e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f09f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f0a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f0a1:
    // 0048f0a1  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f0a4  e8639f0100             -call 0x4a900c
    cpu.esp -= 4;
    sub_4a900c(app, cpu);
    if (cpu.terminate) return;
    // 0048f0a9  ebc2                   -jmp 0x48f06d
    goto L_0x0048f06d;
L_0x0048f0ab:
    // 0048f0ab  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f0b0  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048f0b6  e8b9140000             -call 0x490574
    cpu.esp -= 4;
    sub_490574(app, cpu);
    if (cpu.terminate) return;
    // 0048f0bb  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f0c0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f0c6  e8ed92ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f0cb  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f0d1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f0d4  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048f0d7  7e67                   -jle 0x48f140
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f140;
    }
    // 0048f0d9  89b9a0000000           -mov dword ptr [ecx + 0xa0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edi;
L_0x0048f0df:
    // 0048f0df  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0048f0e2  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f0e7  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048f0ea  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0048f0ed  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048f0f0  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 0048f0f3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f0f5  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0048f0f8  3b7820                 +cmp edi, dword ptr [eax + 0x20]
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
    // 0048f0fb  7567                   -jne 0x48f164
    if (!cpu.flags.zf)
    {
        goto L_0x0048f164;
    }
L_0x0048f0fd:
    // 0048f0fd  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f102  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048f105  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048f108  89a8b8000000           -mov dword ptr [eax + 0xb8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
L_0x0048f10e:
    // 0048f10e  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f113  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f116  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048f119  83782013               +cmp dword ptr [eax + 0x20], 0x13
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
    // 0048f11d  754d                   -jne 0x48f16c
    if (!cpu.flags.zf)
    {
        goto L_0x0048f16c;
    }
L_0x0048f11f:
    // 0048f11f  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f124  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x0048f12b:
    // 0048f12b  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f130  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f136  e89592ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f13b  e9a6fdffff             -jmp 0x48eee6
    goto L_0x0048eee6;
L_0x0048f140:
    // 0048f140  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0048f143  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0048f146  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f149  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f14c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f14e  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048f154  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048f156  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0048f15c  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0048f15f  e97bffffff             -jmp 0x48f0df
    goto L_0x0048f0df;
L_0x0048f164:
    // 0048f164  83782012               +cmp dword ptr [eax + 0x20], 0x12
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
    // 0048f168  7493                   -je 0x48f0fd
    if (cpu.flags.zf)
    {
        goto L_0x0048f0fd;
    }
    // 0048f16a  eba2                   -jmp 0x48f10e
    goto L_0x0048f10e;
L_0x0048f16c:
    // 0048f16c  83782012               +cmp dword ptr [eax + 0x20], 0x12
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
    // 0048f170  74ad                   -je 0x48f11f
    if (cpu.flags.zf)
    {
        goto L_0x0048f11f;
    }
    // 0048f172  c7402010000000         -mov dword ptr [eax + 0x20], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 16 /*0x10*/;
    // 0048f179  ebb0                   -jmp 0x48f12b
    goto L_0x0048f12b;
  case 0x0048f17b:
    // 0048f17b  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f180  3b681c                 +cmp ebp, dword ptr [eax + 0x1c]
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
    // 0048f183  7408                   -je 0x48f18d
    if (cpu.flags.zf)
    {
        goto L_0x0048f18d;
    }
    // 0048f185  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f188  e87f9e0100             -call 0x4a900c
    cpu.esp -= 4;
    sub_4a900c(app, cpu);
    if (cpu.terminate) return;
L_0x0048f18d:
    // 0048f18d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f18f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f190  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f195  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 0048f198  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048f19b  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f19e  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048f1a4  e8379e0100             -call 0x4a8fe0
    cpu.esp -= 4;
    sub_4a8fe0(app, cpu);
    if (cpu.terminate) return;
    // 0048f1a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f1ab  0f84c1fdffff           -je 0x48ef72
    if (cpu.flags.zf)
    {
        goto L_0x0048ef72;
    }
    // 0048f1b1  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f1b6  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048f1bc  e8b3130000             -call 0x490574
    cpu.esp -= 4;
    sub_490574(app, cpu);
    if (cpu.terminate) return;
    // 0048f1c1  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f1c6  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f1cc  e8e791ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f1d1  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f1d7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f1da  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048f1dd  0f8eb8010000           -jle 0x48f39b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f39b;
    }
    // 0048f1e3  89b9a0000000           -mov dword ptr [ecx + 0xa0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edi;
L_0x0048f1e9:
    // 0048f1e9  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0048f1ec  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f1f1  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048f1f4  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0048f1f7  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048f1fa  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 0048f1fd  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f1ff  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0048f202  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f208  e8c391ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0048f20d:
    // 0048f20d  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f212  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 0048f217  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f21d  e89691ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f222  3b2d9cab4d00           +cmp ebp, dword ptr [0x4dab9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f228  743b                   -je 0x48f265
    if (cpu.flags.zf)
    {
        goto L_0x0048f265;
    }
L_0x0048f22a:
    // 0048f22a  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f22f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f232  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048f235  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048f238  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048f23b  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048f23e  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048f241  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048f244  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048f247  89a8bc000000           -mov dword ptr [eax + 0xbc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.ebp;
    // 0048f24d  8b90bc000000           -mov edx, dword ptr [eax + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 0048f253  8990b8000000           -mov dword ptr [eax + 0xb8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.edx;
    // 0048f259  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048f25c  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 0048f261  39c5                   +cmp ebp, eax
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
    // 0048f263  75c5                   -jne 0x48f22a
    if (!cpu.flags.zf)
    {
        goto L_0x0048f22a;
    }
L_0x0048f265:
    // 0048f265  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f26a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f270  e85b91ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f275  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f27a  83782014               +cmp dword ptr [eax + 0x20], 0x14
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
    // 0048f27e  0f843b010000           -je 0x48f3bf
    if (cpu.flags.zf)
    {
        goto L_0x0048f3bf;
    }
    // 0048f284  c7402002000000         -mov dword ptr [eax + 0x20], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 0048f28b  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0048f291  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f293  e8f88fffff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0048f298:
    // 0048f298  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f29d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f2a3  e81091ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f2a8  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f2ad  83782002               +cmp dword ptr [eax + 0x20], 2
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
    // 0048f2b1  0f8521010000           -jne 0x48f3d8
    if (!cpu.flags.zf)
    {
        goto L_0x0048f3d8;
    }
    // 0048f2b7  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048f2ba  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048f2bd  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f2c0  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048f2c3  89a8b8000000           -mov dword ptr [eax + 0xb8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
L_0x0048f2c9:
    // 0048f2c9  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f2ce  8b5060                 -mov edx, dword ptr [eax + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 0048f2d1  89505c                 -mov dword ptr [eax + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 0048f2d4  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f2da  e8f190ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f2df  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f2e4  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 0048f2e7  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f2ea  e8ad9d0100             -call 0x4a909c
    cpu.esp -= 4;
    sub_4a909c(app, cpu);
    if (cpu.terminate) return;
    // 0048f2ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f2f1  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f2f6  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f2fc  e8b790ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f301  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f306  8b485c                 -mov ecx, dword ptr [eax + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 0048f309  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f30b  8988b0000000           -mov dword ptr [eax + 0xb0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = cpu.ecx;
    // 0048f311  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048f314  8b88b0000000           -mov ecx, dword ptr [eax + 0xb0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 0048f31a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f31c  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0048f31f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f325  e8a690ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f32a  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f330  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f332  e8150f0000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048f337  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048f33a  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048f33d  3b4240                 +cmp eax, dword ptr [edx + 0x40]
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
    // 0048f340  0f8f4e010000           -jg 0x48f494
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048f494;
    }
L_0x0048f346:
    // 0048f346  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f34c  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
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
    // 0048f34f  0f858e000000           -jne 0x48f3e3
    if (!cpu.flags.zf)
    {
        goto L_0x0048f3e3;
    }
    // 0048f355  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f357  e8f00e0000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048f35c  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048f35f  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048f362  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f364  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f366  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f36b  e8500f0000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f370  39c2                   +cmp edx, eax
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
    // 0048f372  746f                   -je 0x48f3e3
    if (cpu.flags.zf)
    {
        goto L_0x0048f3e3;
    }
    // 0048f374  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f379  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048f37f  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f382  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048f384  e8078cfcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f389  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f38e  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048f394  e8338fffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048f399  ebab                   -jmp 0x48f346
    goto L_0x0048f346;
L_0x0048f39b:
    // 0048f39b  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0048f39e  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0048f3a1  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f3a4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f3a7  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f3a9  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048f3af  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048f3b1  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0048f3b7  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0048f3ba  e92afeffff             -jmp 0x48f1e9
    goto L_0x0048f1e9;
L_0x0048f3bf:
    // 0048f3bf  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048f3c6  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0048f3cc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f3ce  e8bd8effff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0048f3d3  e90efbffff             -jmp 0x48eee6
    goto L_0x0048eee6;
L_0x0048f3d8:
    // 0048f3d8  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f3db  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048f3de  e9e6feffff             -jmp 0x48f2c9
    goto L_0x0048f2c9;
L_0x0048f3e3:
    // 0048f3e3  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f3e8  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048f3ee  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f3f1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048f3f3  e8988bfcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f3f8  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f3fd  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f400  0f85e0faffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
L_0x0048f406:
    // 0048f406  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f40b  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f40e  7531                   -jne 0x48f441
    if (!cpu.flags.zf)
    {
        goto L_0x0048f441;
    }
    // 0048f410  e8eb0e0000             -call 0x490300
    cpu.esp -= 4;
    sub_490300(app, cpu);
    if (cpu.terminate) return;
    // 0048f415  3b0424                 +cmp eax, dword ptr [esp]
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
    // 0048f418  7f27                   -jg 0x48f441
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048f441;
    }
    // 0048f41a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f41f  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048f425  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f428  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048f42a  e8618bfcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f42f  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f434  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048f43a  e88d8effff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048f43f  ebc5                   -jmp 0x48f406
    goto L_0x0048f406;
L_0x0048f441:
    // 0048f441  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f446  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048f44c  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f44f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048f451  e83a8bfcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f456  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f45b  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f45e  0f8582faffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 0048f464  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f46a  e8498fffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f46f  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f474  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f477  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048f47d  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f480  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048f483  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f486  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048f489  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f48f  e83c8fffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x0048f494:
    // 0048f494  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f49a  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
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
    // 0048f49d  7533                   -jne 0x48f4d2
    if (!cpu.flags.zf)
    {
        goto L_0x0048f4d2;
    }
    // 0048f49f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f4a1  e81a0e0000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f4a6  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048f4a9  7f27                   -jg 0x48f4d2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048f4d2;
    }
    // 0048f4ab  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f4b0  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048f4b6  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f4b9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048f4bb  e8d08afcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f4c0  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f4c5  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048f4cb  e8fc8dffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048f4d0  ebc2                   -jmp 0x48f494
    goto L_0x0048f494;
L_0x0048f4d2:
    // 0048f4d2  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f4d7  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048f4dd  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f4e0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048f4e2  e8a98afcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f4e7  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f4ec  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f4ef  0f85f1f9ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
L_0x0048f4f5:
    // 0048f4f5  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f4fa  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 0048f500  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048f503  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f506  e8619b0100             -call 0x4a906c
    cpu.esp -= 4;
    sub_4a906c(app, cpu);
    if (cpu.terminate) return;
    // 0048f50b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f50d  7509                   -jne 0x48f518
    if (!cpu.flags.zf)
    {
        goto L_0x0048f518;
    }
    // 0048f50f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f511  e8f68affff             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 0048f516  ebdd                   -jmp 0x48f4f5
    goto L_0x0048f4f5;
L_0x0048f518:
    // 0048f518  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f51d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f523  e8908effff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f528  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f52d  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048f530  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f533  3ba8b0000000           +cmp ebp, dword ptr [eax + 0xb0]
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
    // 0048f539  7416                   -je 0x48f551
    if (cpu.flags.zf)
    {
        goto L_0x0048f551;
    }
    // 0048f53b  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048f53e  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f541  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f544  8b80b0000000           -mov eax, dword ptr [eax + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 0048f54a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f54c  e8afa5ffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
L_0x0048f551:
    // 0048f551  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f556  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048f559  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f55c  c7402003000000         -mov dword ptr [eax + 0x20], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 0048f563  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f569  e8628effff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0048f56e:
    // 0048f56e  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f574  837a4c08               +cmp dword ptr [edx + 0x4c], 8
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
    // 0048f578  0f83ed010000           -jae 0x48f76b
    if (!cpu.flags.cf)
    {
        goto L_0x0048f76b;
    }
    // 0048f57e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f580  e8c70c0000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048f585  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048f588  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048f58b  3b4240                 +cmp eax, dword ptr [edx + 0x40]
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
    // 0048f58e  0f8f21010000           -jg 0x48f6b5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048f6b5;
    }
L_0x0048f594:
    // 0048f594  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f59a  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
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
    // 0048f59d  7546                   -jne 0x48f5e5
    if (!cpu.flags.zf)
    {
        goto L_0x0048f5e5;
    }
    // 0048f59f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f5a1  e8a60c0000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048f5a6  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048f5a9  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048f5ac  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f5ae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f5b0  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f5b5  e8060d0000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f5ba  39c2                   +cmp edx, eax
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
    // 0048f5bc  7427                   -je 0x48f5e5
    if (cpu.flags.zf)
    {
        goto L_0x0048f5e5;
    }
    // 0048f5be  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f5c3  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048f5c9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f5cc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048f5ce  e8bd89fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f5d3  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f5d8  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048f5de  e8e98cffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048f5e3  ebaf                   -jmp 0x48f594
    goto L_0x0048f594;
L_0x0048f5e5:
    // 0048f5e5  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f5ea  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048f5f0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f5f3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048f5f5  e89689fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f5fa  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f5ff  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f602  0f85def8ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
L_0x0048f608:
    // 0048f608  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f60e  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048f611  7536                   -jne 0x48f649
    if (!cpu.flags.zf)
    {
        goto L_0x0048f649;
    }
    // 0048f613  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f618  e8e30c0000             -call 0x490300
    cpu.esp -= 4;
    sub_490300(app, cpu);
    if (cpu.terminate) return;
    // 0048f61d  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 0048f620  7f27                   -jg 0x48f649
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048f649;
    }
    // 0048f622  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f627  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048f62d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f630  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048f632  e85989fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f637  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f63c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048f642  e8858cffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048f647  ebbf                   -jmp 0x48f608
    goto L_0x0048f608;
L_0x0048f649:
    // 0048f649  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f64e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048f654  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f657  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048f659  e83289fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f65e  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f663  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f666  0f857af8ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 0048f66c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f672  e8418dffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f677  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f67c  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048f67f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f682  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f685  e876a4ffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0048f68a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f68f  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f692  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048f698  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f69b  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048f69e  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f6a1  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048f6a4  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048f6a7  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f6aa  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f6b0  e81b8dffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x0048f6b5:
    // 0048f6b5  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f6bb  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
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
    // 0048f6be  7533                   -jne 0x48f6f3
    if (!cpu.flags.zf)
    {
        goto L_0x0048f6f3;
    }
    // 0048f6c0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f6c2  e8f90b0000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f6c7  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048f6ca  7f27                   -jg 0x48f6f3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048f6f3;
    }
    // 0048f6cc  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f6d1  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048f6d7  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f6da  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048f6dc  e8af88fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f6e1  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f6e6  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048f6ec  e8db8bffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048f6f1  ebc2                   -jmp 0x48f6b5
    goto L_0x0048f6b5;
L_0x0048f6f3:
    // 0048f6f3  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f6f8  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048f6fe  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f701  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048f703  e88888fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f708  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f70d  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f710  0f85d0f7ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
L_0x0048f716:
    // 0048f716  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f71b  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 0048f721  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048f724  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f727  e840990100             -call 0x4a906c
    cpu.esp -= 4;
    sub_4a906c(app, cpu);
    if (cpu.terminate) return;
    // 0048f72c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f72e  7509                   -jne 0x48f739
    if (!cpu.flags.zf)
    {
        goto L_0x0048f739;
    }
    // 0048f730  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f732  e8d588ffff             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 0048f737  ebdd                   -jmp 0x48f716
    goto L_0x0048f716;
L_0x0048f739:
    // 0048f739  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f73e  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f744  e86f8cffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f749  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f74e  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048f751  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f754  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048f757  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f75a  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048f75d  01504c                 -add dword ptr [eax + 0x4c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f760  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f766  e8658cffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x0048f76b:
    // 0048f76b  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f770  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f773  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048f778  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f77a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048f77c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048f77e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048f785  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048f787  3d6c454353             +cmp eax, 0x5343456c
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
    // 0048f78c  7516                   -jne 0x48f7a4
    if (!cpu.flags.zf)
    {
        goto L_0x0048f7a4;
    }
    // 0048f78e  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f793  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
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
    // 0048f796  740c                   -je 0x48f7a4
    if (cpu.flags.zf)
    {
        goto L_0x0048f7a4;
    }
    // 0048f798  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048f79f  e942f7ffff             -jmp 0x48eee6
    goto L_0x0048eee6;
L_0x0048f7a4:
    // 0048f7a4  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f7a9  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f7af  e8048cffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f7b4  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f7b9  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f7bc  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f7bf  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 0048f7c2  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048f7c5  8b484c                 -mov ecx, dword ptr [eax + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048f7c8  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f7ca  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 0048f7cd  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048f7d0  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 0048f7d5  39c5                   +cmp ebp, eax
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
    // 0048f7d7  742f                   -je 0x48f808
    if (cpu.flags.zf)
    {
        goto L_0x0048f808;
    }
L_0x0048f7d9:
    // 0048f7d9  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f7de  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f7e1  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048f7e6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f7e8  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048f7ea  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048f7ec  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048f7f3  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048f7f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f7f7  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f7fc  23506c                 -and edx, dword ptr [eax + 0x6c]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */)));
    // 0048f7ff  3b5068                 +cmp edx, dword ptr [eax + 0x68]
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
    // 0048f802  0f85a3000000           -jne 0x48f8ab
    if (!cpu.flags.zf)
    {
        goto L_0x0048f8ab;
    }
L_0x0048f808:
    // 0048f808  3b2d9cab4d00           +cmp ebp, dword ptr [0x4dab9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f80e  750a                   -jne 0x48f81a
    if (!cpu.flags.zf)
    {
        goto L_0x0048f81a;
    }
    // 0048f810  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f815  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
L_0x0048f81a:
    // 0048f81a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f81f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f825  e8a68bffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f82a  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f830  83794808               +cmp dword ptr [ecx + 0x48], 8
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
    // 0048f834  0f8386000000           -jae 0x48f8c0
    if (!cpu.flags.cf)
    {
        goto L_0x0048f8c0;
    }
L_0x0048f83a:
    // 0048f83a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f83f  3b682c                 +cmp ebp, dword ptr [eax + 0x2c]
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
    // 0048f842  0f8594000000           -jne 0x48f8dc
    if (!cpu.flags.zf)
    {
        goto L_0x0048f8dc;
    }
    // 0048f848  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f84e  e8658bffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048f853  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f858  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
L_0x0048f85d:
    // 0048f85d  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f862  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f865  8b4868                 -mov ecx, dword ptr [eax + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 0048f868  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048f86a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f86d  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 0048f874  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048f878  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048f87b  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048f87e  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048f881  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 0048f886  39c5                   +cmp ebp, eax
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
    // 0048f888  75d3                   -jne 0x48f85d
    if (!cpu.flags.zf)
    {
        goto L_0x0048f85d;
    }
    // 0048f88a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f88f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048f895  e8368bffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f89a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f89f  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048f8a6  e93bf6ffff             -jmp 0x48eee6
    goto L_0x0048eee6;
L_0x0048f8ab:
    // 0048f8ab  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048f8ae  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 0048f8b3  39c5                   +cmp ebp, eax
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
    // 0048f8b5  0f851effffff           -jne 0x48f7d9
    if (!cpu.flags.zf)
    {
        goto L_0x0048f7d9;
    }
    // 0048f8bb  e948ffffff             -jmp 0x48f808
    goto L_0x0048f808;
L_0x0048f8c0:
    // 0048f8c0  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f8c6  8b423c                 -mov eax, dword ptr [edx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 0048f8c9  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 0048f8cc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f8cf  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f8d1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048f8d3  3b4148                 +cmp eax, dword ptr [ecx + 0x48]
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
    // 0048f8d6  0f8c5effffff           -jl 0x48f83a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f83a;
    }
L_0x0048f8dc:
    // 0048f8dc  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f8e1  8b1d98ab4d00           -mov ebx, dword ptr [0x4dab98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f8e7  39d8                   +cmp eax, ebx
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
    // 0048f8e9  0f848e030000           -je 0x48fc7d
    if (cpu.flags.zf)
    {
        goto L_0x0048fc7d;
    }
    // 0048f8ef  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0048f8f1  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 0048f8f4  034340                 -add eax, dword ptr [ebx + 0x40]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */)));
    // 0048f8f7  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f8fd  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048f900  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f902  e845090000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048f907  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048f90a  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048f90d  39c8                   +cmp eax, ecx
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
    // 0048f90f  0f877a010000           -ja 0x48fa8f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048fa8f;
    }
L_0x0048f915:
    // 0048f915  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f91a  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f91d  754a                   -jne 0x48f969
    if (!cpu.flags.zf)
    {
        goto L_0x0048f969;
    }
    // 0048f91f  8b0d9cab4d00           -mov ecx, dword ptr [0x4dab9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f925  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f927  e820090000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048f92c  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048f92f  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048f932  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f937  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f939  e882090000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f93e  39c2                   +cmp edx, eax
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
    // 0048f940  7427                   -je 0x48f969
    if (cpu.flags.zf)
    {
        goto L_0x0048f969;
    }
    // 0048f942  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f947  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048f94d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f950  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048f952  e83986fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f957  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f95c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048f962  e86589ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048f967  ebac                   -jmp 0x48f915
    goto L_0x0048f915;
L_0x0048f969:
    // 0048f969  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f96e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048f974  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f977  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048f979  e81286fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f97e  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f983  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f986  0f855af5ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
L_0x0048f98c:
    // 0048f98c  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f991  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f994  7536                   -jne 0x48f9cc
    if (!cpu.flags.zf)
    {
        goto L_0x0048f9cc;
    }
    // 0048f996  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048f99b  e820090000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f9a0  83f808                 +cmp eax, 8
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
    // 0048f9a3  7727                   -ja 0x48f9cc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048f9cc;
    }
    // 0048f9a5  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f9aa  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048f9b0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f9b3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048f9b5  e8d685fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f9ba  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f9bf  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048f9c5  e80289ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048f9ca  ebc0                   -jmp 0x48f98c
    goto L_0x0048f98c;
L_0x0048f9cc:
    // 0048f9cc  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f9d1  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048f9d7  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048f9da  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048f9dc  e8af85fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048f9e1  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f9e6  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f9e9  0f85f7f4ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
L_0x0048f9ef:
    // 0048f9ef  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048f9f4  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048f9f7  753e                   -jne 0x48fa37
    if (!cpu.flags.zf)
    {
        goto L_0x0048fa37;
    }
    // 0048f9f9  8b4848                 -mov ecx, dword ptr [eax + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048f9fc  034840                 -add ecx, dword ptr [eax + 0x40]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */)));
    // 0048f9ff  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fa04  8d5108                 -lea edx, [ecx + 8]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048fa07  e8f4080000             -call 0x490300
    cpu.esp -= 4;
    sub_490300(app, cpu);
    if (cpu.terminate) return;
    // 0048fa0c  39d0                   +cmp eax, edx
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
    // 0048fa0e  7727                   -ja 0x48fa37
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048fa37;
    }
    // 0048fa10  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fa15  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048fa1b  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fa1e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048fa20  e86b85fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fa25  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fa2a  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048fa30  e89788ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048fa35  ebb8                   -jmp 0x48f9ef
    goto L_0x0048f9ef;
L_0x0048fa37:
    // 0048fa37  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fa3c  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048fa42  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fa45  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048fa47  e84485fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fa4c  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fa51  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048fa54  0f858cf4ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 0048fa5a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048fa60  e85389ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048fa65  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fa6a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048fa6d  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048fa73  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048fa76  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048fa79  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048fa7c  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048fa7f  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fa84  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048fa8a  e84189ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x0048fa8f:
    // 0048fa8f  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fa94  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
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
    // 0048fa97  0f8f17010000           -jg 0x48fbb4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048fbb4;
    }
L_0x0048fa9d:
    // 0048fa9d  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048faa3  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048faa6  7536                   -jne 0x48fade
    if (!cpu.flags.zf)
    {
        goto L_0x0048fade;
    }
    // 0048faa8  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048faad  e80e080000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048fab2  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 0048fab5  7f27                   -jg 0x48fade
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048fade;
    }
    // 0048fab7  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fabc  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048fac2  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fac5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048fac7  e8c484fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048facc  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fad1  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048fad7  e8f087ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048fadc  ebbf                   -jmp 0x48fa9d
    goto L_0x0048fa9d;
L_0x0048fade:
    // 0048fade  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fae3  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048fae9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048faec  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048faee  e89d84fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048faf3  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048faf8  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048fafb  0f85e5f3ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 0048fb01  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048fb07  e8ac88ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048fb0c  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fb11  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048fb14  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fb1a  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048fb1d  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048fb20  e8db9fffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0048fb25  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fb2b  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fb30  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048fb33  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048fb36  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048fb38  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048fb3b  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048fb3e  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048fb41  89684c                 -mov dword ptr [eax + 0x4c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ebp;
L_0x0048fb44:
    // 0048fb44  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048fb4a  e88188ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x0048fb4f:
    // 0048fb4f  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fb54  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
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
    // 0048fb57  0f8c50010000           -jl 0x48fcad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fcad;
    }
L_0x0048fb5d:
    // 0048fb5d  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fb62  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
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
    // 0048fb65  0f8d1f030000           -jge 0x48fe8a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fe8a;
    }
L_0x0048fb6b:
    // 0048fb6b  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fb71  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048fb74  0f858b020000           -jne 0x48fe05
    if (!cpu.flags.zf)
    {
        goto L_0x0048fe05;
    }
    // 0048fb7a  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fb7f  e83c070000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048fb84  3b4240                 +cmp eax, dword ptr [edx + 0x40]
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
    // 0048fb87  0f8f78020000           -jg 0x48fe05
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048fe05;
    }
    // 0048fb8d  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fb92  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048fb98  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fb9b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048fb9d  e8ee83fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fba2  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fba7  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048fbad  e81a87ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048fbb2  ebb7                   -jmp 0x48fb6b
    goto L_0x0048fb6b;
L_0x0048fbb4:
    // 0048fbb4  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fbba  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048fbbd  7536                   -jne 0x48fbf5
    if (!cpu.flags.zf)
    {
        goto L_0x0048fbf5;
    }
    // 0048fbbf  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fbc4  e8f7060000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048fbc9  3b4248                 +cmp eax, dword ptr [edx + 0x48]
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
    // 0048fbcc  7f27                   -jg 0x48fbf5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048fbf5;
    }
    // 0048fbce  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fbd3  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048fbd9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fbdc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048fbde  e8ad83fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fbe3  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fbe8  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048fbee  e8d986ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048fbf3  ebbf                   -jmp 0x48fbb4
    goto L_0x0048fbb4;
L_0x0048fbf5:
    // 0048fbf5  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fbfa  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048fc00  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fc03  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048fc05  e88683fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fc0a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fc0f  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048fc12  0f85cef2ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 0048fc18  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048fc1e  e89587ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048fc23  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fc28  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048fc2b  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fc31  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048fc34  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048fc37  e8c49effff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0048fc3c  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fc42  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fc47  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048fc4a  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048fc4d  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048fc4f  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048fc52  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0048fc55  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0048fc57  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0048fc5a  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048fc5d  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048fc60  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048fc63  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048fc66  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fc68  e8939effff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0048fc6d  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fc72  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048fc75  29500c                 +sub dword ptr [eax + 0xc], edx
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
    // 0048fc78  e9c7feffff             -jmp 0x48fb44
    goto L_0x0048fb44;
L_0x0048fc7d:
    // 0048fc7d  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048fc80  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048fc85  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048fc87  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048fc89  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048fc8b  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048fc92  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048fc94  3d6c454353             +cmp eax, 0x5343456c
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
    // 0048fc99  7509                   -jne 0x48fca4
    if (!cpu.flags.zf)
    {
        goto L_0x0048fca4;
    }
    // 0048fc9b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048fc9d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048fc9f  e9abfeffff             -jmp 0x48fb4f
    goto L_0x0048fb4f;
L_0x0048fca4:
    // 0048fca4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048fca6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048fca8  e9a2feffff             -jmp 0x48fb4f
    goto L_0x0048fb4f;
L_0x0048fcad:
    // 0048fcad  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0048fcb0  035040                 -add edx, dword ptr [eax + 0x40]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */)));
    // 0048fcb3  8d4a08                 -lea ecx, [edx + 8]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048fcb6  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fcbc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048fcbe  e889050000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048fcc3  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048fcc6  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048fcc9  39c8                   +cmp eax, ecx
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
    // 0048fccb  0f878cfeffff           -ja 0x48fb5d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048fb5d;
    }
L_0x0048fcd1:
    // 0048fcd1  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fcd6  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048fcd9  754a                   -jne 0x48fd25
    if (!cpu.flags.zf)
    {
        goto L_0x0048fd25;
    }
    // 0048fcdb  8b0d9cab4d00           -mov ecx, dword ptr [0x4dab9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fce1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048fce3  e864050000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048fce8  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048fceb  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048fcee  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fcf3  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048fcf5  e8c6050000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048fcfa  39c2                   +cmp edx, eax
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
    // 0048fcfc  7427                   -je 0x48fd25
    if (cpu.flags.zf)
    {
        goto L_0x0048fd25;
    }
    // 0048fcfe  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fd03  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048fd09  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fd0c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048fd0e  e87d82fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fd13  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fd18  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048fd1e  e8a985ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048fd23  ebac                   -jmp 0x48fcd1
    goto L_0x0048fcd1;
L_0x0048fd25:
    // 0048fd25  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fd2a  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048fd30  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fd33  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048fd35  e85682fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fd3a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fd3f  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048fd42  0f859ef1ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
L_0x0048fd48:
    // 0048fd48  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fd4e  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048fd51  7536                   -jne 0x48fd89
    if (!cpu.flags.zf)
    {
        goto L_0x0048fd89;
    }
    // 0048fd53  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fd58  e8a3050000             -call 0x490300
    cpu.esp -= 4;
    sub_490300(app, cpu);
    if (cpu.terminate) return;
    // 0048fd5d  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 0048fd60  7f27                   -jg 0x48fd89
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048fd89;
    }
    // 0048fd62  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fd67  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048fd6d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fd70  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048fd72  e81982fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fd77  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fd7c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048fd82  e84585ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048fd87  ebbf                   -jmp 0x48fd48
    goto L_0x0048fd48;
L_0x0048fd89:
    // 0048fd89  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fd8e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048fd94  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fd97  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048fd99  e8f281fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fd9e  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fda3  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048fda6  0f853af1ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 0048fdac  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048fdb2  e80186ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048fdb7  8b1d98ab4d00           -mov ebx, dword ptr [0x4dab98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fdbd  8b5b4c                 -mov ebx, dword ptr [ebx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */);
    // 0048fdc0  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fdc5  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048fdc8  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048fdcb  e8309dffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0048fdd0  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fdd5  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048fdd8  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048fdde  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fde4  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048fde7  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 0048fdea  01d9                   +add ecx, ebx
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
    // 0048fdec  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048fdef  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048fdf2  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0048fdf5  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048fdfb  e8d085ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048fe00  e958fdffff             -jmp 0x48fb5d
    goto L_0x0048fb5d;
L_0x0048fe05:
    // 0048fe05  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fe0a  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048fe10  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fe13  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048fe15  e87681fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fe1a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fe1f  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048fe22  7566                   -jne 0x48fe8a
    if (!cpu.flags.zf)
    {
        goto L_0x0048fe8a;
    }
L_0x0048fe24:
    // 0048fe24  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fe29  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 0048fe2f  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fe35  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048fe38  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048fe3b  e82c920100             -call 0x4a906c
    cpu.esp -= 4;
    sub_4a906c(app, cpu);
    if (cpu.terminate) return;
    // 0048fe40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fe42  7509                   -jne 0x48fe4d
    if (!cpu.flags.zf)
    {
        goto L_0x0048fe4d;
    }
    // 0048fe44  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048fe46  e8c181ffff             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 0048fe4b  ebd7                   -jmp 0x48fe24
    goto L_0x0048fe24;
L_0x0048fe4d:
    // 0048fe4d  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fe52  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048fe58  e85b85ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048fe5d  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fe62  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048fe65  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048fe68  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fe6e  8b4840                 -mov ecx, dword ptr [eax + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048fe71  014a0c                 -add dword ptr [edx + 0xc], ecx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fe74  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048fe77  295044                 +sub dword ptr [eax + 0x44], edx
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
    // 0048fe7a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048fe80  e84b85ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048fe85  e9d3fcffff             -jmp 0x48fb5d
    goto L_0x0048fb5d;
L_0x0048fe8a:
    // 0048fe8a  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fe8f  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048fe92  0f854ef0ffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 0048fe98  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048fe9e  e81585ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048fea3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048fea5  0f85bc000000           -jne 0x48ff67
    if (!cpu.flags.zf)
    {
        goto L_0x0048ff67;
    }
    // 0048feab  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048feb1  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048feb6  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048feb9  014810                 -add dword ptr [eax + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048febc  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048febf  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048fec2  0188b8000000           -add dword ptr [eax + 0xb8], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fec8  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048fece  e8fd84ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048fed3  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048fed8  8b3598ab4d00           -mov esi, dword ptr [0x4dab98]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fede  39f0                   +cmp eax, esi
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
    // 0048fee0  0f849d020000           -je 0x490183
    if (cpu.flags.zf)
    {
        goto L_0x00490183;
    }
    // 0048fee6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048fee8  3b6e4c                 +cmp ebp, dword ptr [esi + 0x4c]
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
    // 0048feeb  0f852a020000           -jne 0x49011b
    if (!cpu.flags.zf)
    {
        goto L_0x0049011b;
    }
    // 0048fef1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048fef3  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048fef6  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048fef9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048fefb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048fefd  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048feff  e848030000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048ff04  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048ff07  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048ff0a  39c8                   +cmp eax, ecx
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
    // 0048ff0c  0f8f45010000           -jg 0x490057
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00490057;
    }
L_0x0048ff12:
    // 0048ff12  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ff18  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048ff1b  0f857a000000           -jne 0x48ff9b
    if (!cpu.flags.zf)
    {
        goto L_0x0048ff9b;
    }
    // 0048ff21  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ff23  e824030000             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 0048ff28  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048ff2b  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048ff2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ff30  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ff35  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ff37  e884030000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 0048ff3c  39c2                   +cmp edx, eax
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
    // 0048ff3e  745b                   -je 0x48ff9b
    if (cpu.flags.zf)
    {
        goto L_0x0048ff9b;
    }
    // 0048ff40  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ff45  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048ff4b  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ff4e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048ff50  e83b80fcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048ff55  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ff5a  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048ff60  e86783ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0048ff65  ebab                   -jmp 0x48ff12
    goto L_0x0048ff12;
L_0x0048ff67:
    // 0048ff67  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ff6d  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048ff72  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048ff75  014810                 -add dword ptr [eax + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ff78  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048ff7b  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ff7e  0188b8000000           +add dword ptr [eax + 0xb8], ecx
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
    // 0048ff84  c7422007000000         -mov dword ptr [edx + 0x20], 7
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048ff8b  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048ff91  e83a84ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ff96  e94befffff             -jmp 0x48eee6
    goto L_0x0048eee6;
L_0x0048ff9b:
    // 0048ff9b  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ffa0  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048ffa6  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ffa9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048ffab  e8e07ffcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048ffb0  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ffb5  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048ffb8  0f8528efffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
L_0x0048ffbe:
    // 0048ffbe  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ffc3  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048ffc6  753c                   -jne 0x490004
    if (!cpu.flags.zf)
    {
        goto L_0x00490004;
    }
    // 0048ffc8  8b0d9cab4d00           -mov ecx, dword ptr [0x4dab9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0048ffce  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048ffd1  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 0048ffd4  e827030000             -call 0x490300
    cpu.esp -= 4;
    sub_490300(app, cpu);
    if (cpu.terminate) return;
    // 0048ffd9  39d0                   +cmp eax, edx
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
    // 0048ffdb  7f27                   -jg 0x490004
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00490004;
    }
    // 0048ffdd  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048ffe2  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048ffe8  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ffeb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048ffed  e89e7ffcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0048fff2  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0048fff7  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048fffd  e8ca82ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 00490002  ebba                   -jmp 0x48ffbe
    goto L_0x0048ffbe;
L_0x00490004:
    // 00490004  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490009  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0049000f  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00490012  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00490014  e8777ffcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 00490019  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0049001e  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 00490021  0f85bfeeffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 00490027  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0049002d  e88683ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00490032  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490037  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049003a  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 00490040  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00490043  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00490046  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00490049  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049004c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00490052  e87983ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x00490057:
    // 00490057  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0049005c  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0049005f  753c                   -jne 0x49009d
    if (!cpu.flags.zf)
    {
        goto L_0x0049009d;
    }
    // 00490061  8b0d9cab4d00           -mov ecx, dword ptr [0x4dab9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 00490067  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049006a  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 0049006d  e84e020000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 00490072  39d0                   +cmp eax, edx
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
    // 00490074  7f27                   -jg 0x49009d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049009d;
    }
    // 00490076  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0049007b  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00490081  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00490084  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00490086  e8057ffcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 0049008b  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490090  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00490096  e83182ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0049009b  ebba                   -jmp 0x490057
    goto L_0x00490057;
L_0x0049009d:
    // 0049009d  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004900a2  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004900a8  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004900ab  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004900ad  e8de7efcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 004900b2  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004900b7  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 004900ba  0f8526eeffff           -jne 0x48eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0048eee6;
    }
    // 004900c0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004900c6  e8ed82ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004900cb  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 004900d1  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004900d4  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004900d7  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004900d9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004900db  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004900e0  89484c                 -mov dword ptr [eax + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ecx;
    // 004900e3  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004900e6  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004900e9  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004900ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004900ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004900f0  e80b9affff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004900f5  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 004900fa  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004900fd  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00490100  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490105  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00490108  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0049010b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049010d  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00490110:
    // 00490110  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00490116  e8b582ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x0049011b:
    // 0049011b  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490120  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 00490123  2b504c                 -sub edx, dword ptr [eax + 0x4c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)));
    // 00490126  3b5054                 +cmp edx, dword ptr [eax + 0x54]
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
    // 00490129  0f8cb7edffff           -jl 0x48eee6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048eee6;
    }
    // 0049012f  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
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
    // 00490132  0f85ec000000           -jne 0x490224
    if (!cpu.flags.zf)
    {
        goto L_0x00490224;
    }
    // 00490138  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
L_0x0049013d:
    // 0049013d  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490142  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 00490145  7564                   -jne 0x4901ab
    if (!cpu.flags.zf)
    {
        goto L_0x004901ab;
    }
    // 00490147  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0049014d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049014f  e86c010000             -call 0x4902c0
    cpu.esp -= 4;
    sub_4902c0(app, cpu);
    if (cpu.terminate) return;
    // 00490154  03424c                 -add eax, dword ptr [edx + 0x4c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
    // 00490157  83f808                 +cmp eax, 8
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
    // 0049015a  774f                   -ja 0x4901ab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004901ab;
    }
    // 0049015c  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490161  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00490167  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049016a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049016c  e81f7efcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 00490171  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490176  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0049017c  e84b81ffff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 00490181  ebba                   -jmp 0x49013d
    goto L_0x0049013d;
L_0x00490183:
    // 00490183  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00490189  e82a82ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049018e  8b159cab4d00           -mov edx, dword ptr [0x4dab9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 00490194  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00490197  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049019a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049019c  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004901a1  29ca                   +sub edx, ecx
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
    // 004901a3  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004901a6  e965ffffff             -jmp 0x490110
    goto L_0x00490110;
L_0x004901ab:
    // 004901ab  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004901b0  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004901b6  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004901b9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004901bb  e8d07dfcff             -call 0x457f90
    cpu.esp -= 4;
    sub_457f90(app, cpu);
    if (cpu.terminate) return;
    // 004901c0  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004901c5  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004901c8  39dd                   +cmp ebp, ebx
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
    // 004901ca  7469                   -je 0x490235
    if (cpu.flags.zf)
    {
        goto L_0x00490235;
    }
L_0x004901cc:
    // 004901cc  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004901d1  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004901d7  e8dc81ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004901dc  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004901e1  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
L_0x004901e6:
    // 004901e6  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 004901eb  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004901ee  c702fdffffff           -mov dword ptr [edx], 0xfffffffd
    app->getMemory<x86::reg32>(cpu.edx) = 4294967293 /*0xfffffffd*/;
    // 004901f4  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004901f7  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 004901fe  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00490202  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00490205  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00490208  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0049020b  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 00490210  39c5                   +cmp ebp, eax
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
    // 00490212  75d2                   -jne 0x4901e6
    if (!cpu.flags.zf)
    {
        goto L_0x004901e6;
    }
    // 00490214  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490219  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0049021f  e8ac81ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x00490224:
    // 00490224  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490229  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00490230  e9b1ecffff             -jmp 0x48eee6
    goto L_0x0048eee6;
L_0x00490235:
    // 00490235  a19cab4d00             -mov eax, dword ptr [0x4dab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */);
    // 0049023a  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0049023d  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 00490242  39c3                   +cmp ebx, eax
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
    // 00490244  0f85f3feffff           -jne 0x49013d
    if (!cpu.flags.zf)
    {
        goto L_0x0049013d;
    }
    // 0049024a  eb80                   -jmp 0x4901cc
    goto L_0x004901cc;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_49024c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049024c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049024d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049024f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00490255  e85e81ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049025a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049025d  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 00490260  7430                   -je 0x490292
    if (cpu.flags.zf)
    {
        goto L_0x00490292;
    }
L_0x00490262:
    // 00490262  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00490265  3b4210                 +cmp eax, dword ptr [edx + 0x10]
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
    // 00490268  7428                   -je 0x490292
    if (cpu.flags.zf)
    {
        goto L_0x00490292;
    }
    // 0049026a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049026d  8338fe                 +cmp dword ptr [eax], -2
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
    // 00490270  752d                   -jne 0x49029f
    if (!cpu.flags.zf)
    {
        goto L_0x0049029f;
    }
    // 00490272  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00490275  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00490278  83e808                 -sub eax, 8
    (cpu.eax) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049027b  2982bc000000           -sub dword ptr [edx + 0xbc], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(188) /* 0xbc */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00490281  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00490284  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00490287  014218                 -add dword ptr [edx + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049028a:
    // 0049028a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049028d  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 00490290  75d0                   -jne 0x490262
    if (!cpu.flags.zf)
    {
        goto L_0x00490262;
    }
L_0x00490292:
    // 00490292  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00490298  e83381ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049029d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049029e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049029f:
    // 0049029f  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004902a2  8338ff                 +cmp dword ptr [eax], -1
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
    // 004902a5  75eb                   -jne 0x490292
    if (!cpu.flags.zf)
    {
        goto L_0x00490292;
    }
    // 004902a7  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004902aa  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 004902ad  7506                   -jne 0x4902b5
    if (!cpu.flags.zf)
    {
        goto L_0x004902b5;
    }
    // 004902af  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004902b2  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x004902b5:
    // 004902b5  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004902b8  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004902bb  ebcd                   -jmp 0x49028a
    goto L_0x0049028a;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4902c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004902c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004902c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004902c3  e884ffffff             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 004902c8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004902cb  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 004902ce  7210                   -jb 0x4902e0
    if (cpu.flags.cf)
    {
        goto L_0x004902e0;
    }
    // 004902d0  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004902d3  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 004902d6  7510                   -jne 0x4902e8
    if (!cpu.flags.zf)
    {
        goto L_0x004902e8;
    }
    // 004902d8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004902db  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 004902de  7508                   -jne 0x4902e8
    if (!cpu.flags.zf)
    {
        goto L_0x004902e8;
    }
L_0x004902e0:
    // 004902e0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004902e3  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004902e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004902e8:
    // 004902e8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004902eb  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004902ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4902f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004902f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004902f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004902f3  e854ffffff             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 004902f8  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004902fb  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004902fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490300  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490301  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490303  e844ffffff             -call 0x49024c
    cpu.esp -= 4;
    sub_49024c(app, cpu);
    if (cpu.terminate) return;
    // 00490308  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049030b  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 0049030e  7708                   -ja 0x490318
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00490318;
    }
    // 00490310  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00490313  2b4204                 -sub eax, dword ptr [edx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00490316  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490317  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490318:
    // 00490318  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049031a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049031b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49031c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049031c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049031d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049031e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049031f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490320  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490322  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490324  7437                   -je 0x49035d
    if (cpu.flags.zf)
    {
        goto L_0x0049035d;
    }
    // 00490326  83787800               +cmp dword ptr [eax + 0x78], 0
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
    // 0049032a  7413                   -je 0x49033f
    if (cpu.flags.zf)
    {
        goto L_0x0049033f;
    }
    // 0049032c  8b4078                 -mov eax, dword ptr [eax + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 0049032f  8b8094000000           -mov eax, dword ptr [eax + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 00490335  83f80d                 +cmp eax, 0xd
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
    // 00490338  7328                   -jae 0x490362
    if (!cpu.flags.cf)
    {
        goto L_0x00490362;
    }
    // 0049033a  83f80b                 +cmp eax, 0xb
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
    // 0049033d  7431                   -je 0x490370
    if (cpu.flags.zf)
    {
        goto L_0x00490370;
    }
L_0x0049033f:
    // 0049033f  83792002               +cmp dword ptr [ecx + 0x20], 2
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
    // 00490343  742b                   -je 0x490370
    if (cpu.flags.zf)
    {
        goto L_0x00490370;
    }
    // 00490345  83792001               +cmp dword ptr [ecx + 0x20], 1
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
    // 00490349  7425                   -je 0x490370
    if (cpu.flags.zf)
    {
        goto L_0x00490370;
    }
    // 0049034b  8379200e               +cmp dword ptr [ecx + 0x20], 0xe
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
    // 0049034f  7426                   -je 0x490377
    if (cpu.flags.zf)
    {
        goto L_0x00490377;
    }
    // 00490351  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00490354  8b6914                 -mov ebp, dword ptr [ecx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00490357  39e8                   +cmp eax, ebp
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
    // 00490359  7526                   -jne 0x490381
    if (!cpu.flags.zf)
    {
        goto L_0x00490381;
    }
    // 0049035b  31e8                   +xor eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebp))));
L_0x0049035d:
    // 0049035d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049035e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049035f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490360  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490361  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490362:
    // 00490362  760c                   -jbe 0x490370
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00490370;
    }
    // 00490364  83f814                 +cmp eax, 0x14
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
    // 00490367  72d6                   -jb 0x49033f
    if (cpu.flags.cf)
    {
        goto L_0x0049033f;
    }
    // 00490369  7605                   -jbe 0x490370
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00490370;
    }
    // 0049036b  83f817                 +cmp eax, 0x17
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
    // 0049036e  75cf                   -jne 0x49033f
    if (!cpu.flags.zf)
    {
        goto L_0x0049033f;
    }
L_0x00490370:
    // 00490370  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490372  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490373  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490374  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490375  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490376  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490377:
    // 00490377  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0049037c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049037d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049037e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049037f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490380  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490381:
    // 00490381  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00490387  e82c80ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049038c  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0049038f  8338ff                 +cmp dword ptr [eax], -1
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
    // 00490392  750e                   -jne 0x4903a2
    if (!cpu.flags.zf)
    {
        goto L_0x004903a2;
    }
    // 00490394  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00490397  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049039a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049039d  3b4114                 +cmp eax, dword ptr [ecx + 0x14]
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
    // 004903a0  7466                   -je 0x490408
    if (cpu.flags.zf)
    {
        goto L_0x00490408;
    }
L_0x004903a2:
    // 004903a2  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004903a5  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004903a8  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004903ab  3b5114                 +cmp edx, dword ptr [ecx + 0x14]
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
    // 004903ae  736a                   -jae 0x49041a
    if (!cpu.flags.cf)
    {
        goto L_0x0049041a;
    }
    // 004903b0  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004903b3  2b5914                 -sub ebx, dword ptr [ecx + 0x14]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004903b6  39c3                   +cmp ebx, eax
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
    // 004903b8  7c4e                   -jl 0x490408
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490408;
    }
L_0x004903ba:
    // 004903ba  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004903bd  8d50f8                 -lea edx, [eax - 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004903c0  2991b8000000           -sub dword ptr [ecx + 0xb8], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(184) /* 0xb8 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004903c6  0191bc000000           -add dword ptr [ecx + 0xbc], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004903cc  014114                 -add dword ptr [ecx + 0x14], eax
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004903cf  833bfd                 +cmp dword ptr [ebx], -3
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
    // 004903d2  7522                   -jne 0x4903f6
    if (!cpu.flags.zf)
    {
        goto L_0x004903f6;
    }
    // 004903d4  3b5918                 +cmp ebx, dword ptr [ecx + 0x18]
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
    // 004903d7  755d                   -jne 0x490436
    if (!cpu.flags.zf)
    {
        goto L_0x00490436;
    }
    // 004903d9  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004903dc  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004903df:
    // 004903df  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004903e4  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004903e9  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004903ee  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004903f1  e89a7effff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
L_0x004903f6:
    // 004903f6  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004903fc  e8cf7fffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00490401  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490403  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490404  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490405  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490406  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490407  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490408:
    // 00490408  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0049040e  e8bd7fffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00490413  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490415  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490416  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490417  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490418  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490419  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049041a:
    // 0049041a  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049041d  2b5914                 -sub ebx, dword ptr [ecx + 0x14]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 00490420  39c3                   +cmp ebx, eax
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
    // 00490422  7d96                   -jge 0x4903ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004903ba;
    }
    // 00490424  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0049042a  e8a17fffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049042f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00490431  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490432  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490433  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490434  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490435  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490436:
    // 00490436  c703feffffff           -mov dword ptr [ebx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.ebx) = 4294967294 /*0xfffffffe*/;
    // 0049043c  eba1                   -jmp 0x4903df
    goto L_0x004903df;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490440  058c000000             +add eax, 0x8c
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
    // 00490445  c702feffffff           -mov dword ptr [edx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.edx) = 4294967294 /*0xfffffffe*/;
    // 0049044b  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049044e  e93d7effff             -jmp 0x488290
    return sub_488290(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_490454(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490454  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490456  7406                   -je 0x49045e
    if (cpu.flags.zf)
    {
        goto L_0x0049045e;
    }
    // 00490458  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
L_0x0049045e:
    // 0049045e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490460  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490462  7406                   -je 0x49046a
    if (cpu.flags.zf)
    {
        goto L_0x0049046a;
    }
    // 00490464  8b80bc000000           -mov eax, dword ptr [eax + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
L_0x0049046a:
    // 0049046a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49046c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049046c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049046d  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490473  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490475  7412                   -je 0x490489
    if (cpu.flags.zf)
    {
        goto L_0x00490489;
    }
    // 00490477  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490479  837a2007               +cmp dword ptr [edx + 0x20], 7
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
    // 0049047d  7506                   -jne 0x490485
    if (!cpu.flags.zf)
    {
        goto L_0x00490485;
    }
    // 0049047f  837a7800               +cmp dword ptr [edx + 0x78], 0
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
    // 00490483  7404                   -je 0x490489
    if (cpu.flags.zf)
    {
        goto L_0x00490489;
    }
L_0x00490485:
    // 00490485  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490487  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490488  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490489:
    // 00490489  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049048e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049048f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490490  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490491  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490497  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0049049d  e8167fffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004904a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004904a4:
    // 004904a4  8982b4000000           -mov dword ptr [edx + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 004904aa  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 004904ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004904af  75f3                   -jne 0x4904a4
    if (!cpu.flags.zf)
    {
        goto L_0x004904a4;
    }
    // 004904b1  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004904b6  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004904bc  e80f7fffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004904c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004904c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4904c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004904c4  8b80b4000000           -mov eax, dword ptr [eax + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */);
    // 004904ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4904cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004904cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004904cd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004904cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004904d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004904d3  83f8ff                 +cmp eax, -1
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
    // 004904d6  7408                   -je 0x4904e0
    if (cpu.flags.zf)
    {
        goto L_0x004904e0;
    }
    // 004904d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004904da  740d                   -je 0x4904e9
    if (cpu.flags.zf)
    {
        goto L_0x004904e9;
    }
L_0x004904dc:
    // 004904dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004904de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004904df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004904e0:
    // 004904e0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004904e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004904e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004904e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004904e9:
    // 004904e9  e87effffff             -call 0x49046c
    cpu.esp -= 4;
    sub_49046c(app, cpu);
    if (cpu.terminate) return;
    // 004904ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004904f0  74ea                   -je 0x4904dc
    if (cpu.flags.zf)
    {
        goto L_0x004904dc;
    }
    // 004904f2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004904f4  e85bffffff             -call 0x490454
    cpu.esp -= 4;
    sub_490454(app, cpu);
    if (cpu.terminate) return;
    // 004904f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004904fb  75df                   -jne 0x4904dc
    if (!cpu.flags.zf)
    {
        goto L_0x004904dc;
    }
    // 004904fd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00490502  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490504  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490505  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490508(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490508  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490509  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0049050f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490511  7502                   -jne 0x490515
    if (!cpu.flags.zf)
    {
        goto L_0x00490515;
    }
    // 00490513  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490514  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490515:
    // 00490515  c7423001000000         -mov dword ptr [edx + 0x30], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 0049051c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049051d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490520  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490521  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490527  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490529  7502                   -jne 0x49052d
    if (!cpu.flags.zf)
    {
        goto L_0x0049052d;
    }
    // 0049052b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049052c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049052d:
    // 0049052d  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00490534  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490535  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490538  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490539  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049053b  8b1598ab4d00           -mov edx, dword ptr [0x4dab98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490541  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490543  742a                   -je 0x49056f
    if (cpu.flags.zf)
    {
        goto L_0x0049056f;
    }
    // 00490545  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490546  894274                 -mov dword ptr [edx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 00490549  49                     -dec ecx
    (cpu.ecx)--;
    // 0049054a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049054c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049054e  7e14                   -jle 0x490564
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490564;
    }
L_0x00490550:
    // 00490550  8d989c000000           -lea ebx, [eax + 0x9c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 00490556  42                     -inc edx
    (cpu.edx)++;
    // 00490557  899898000000           -mov dword ptr [eax + 0x98], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.ebx;
    // 0049055d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049055f  39ca                   +cmp edx, ecx
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
    // 00490561  7ced                   -jl 0x490550
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490550;
    }
    // 00490563  90                     -nop 
    ;
L_0x00490564:
    // 00490564  c7809800000000000000   -mov dword ptr [eax + 0x98], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 0049056e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049056f:
    // 0049056f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490570  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490574(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490574  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490575  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490576  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490578  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0049057e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00490580  7503                   -jne 0x490585
    if (!cpu.flags.zf)
    {
        goto L_0x00490585;
    }
    // 00490582  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490583  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490584  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490585:
    // 00490585  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0049058b  e8287effff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00490590  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490595  8b4874                 -mov ecx, dword ptr [eax + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00490598  898a98000000           -mov dword ptr [edx + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0049059e  895074                 -mov dword ptr [eax + 0x74], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004905a1  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004905a7  e8247effff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004905ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4905b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004905b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004905b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004905b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004905b4  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004905ba  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004905bc  7505                   -jne 0x4905c3
    if (!cpu.flags.zf)
    {
        goto L_0x004905c3;
    }
L_0x004905be:
    // 004905be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004905c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004905c3:
    // 004905c3  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004905c9  e8ea7dffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004905ce  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004905d3  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004905d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004905d8  740d                   -je 0x4905e7
    if (cpu.flags.zf)
    {
        goto L_0x004905e7;
    }
L_0x004905da:
    // 004905da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004905dc  7409                   -je 0x4905e7
    if (cpu.flags.zf)
    {
        goto L_0x004905e7;
    }
    // 004905de  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004905e4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004905e5  75f3                   -jne 0x4905da
    if (!cpu.flags.zf)
    {
        goto L_0x004905da;
    }
L_0x004905e7:
    // 004905e7  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004905ec  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004905f2  e8d97dffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004905f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004905f9  75c3                   -jne 0x4905be
    if (!cpu.flags.zf)
    {
        goto L_0x004905be;
    }
    // 004905fb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00490600  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490601  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490602  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490604(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490604  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490605  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490606  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0049060c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049060e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00490610  7505                   -jne 0x490617
    if (!cpu.flags.zf)
    {
        goto L_0x00490617;
    }
    // 00490612  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490614  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490615  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490616  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490617:
    // 00490617  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0049061d  e8967dffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00490622  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490627  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0049062a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049062c  740e                   -je 0x49063c
    if (cpu.flags.zf)
    {
        goto L_0x0049063c;
    }
L_0x0049062e:
    // 0049062e  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 00490634  42                     -inc edx
    (cpu.edx)++;
    // 00490635  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490637  75f5                   -jne 0x49062e
    if (!cpu.flags.zf)
    {
        goto L_0x0049062e;
    }
    // 00490639  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049063c:
    // 0049063c  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490641  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00490647  e8847dffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049064c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049064e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049064f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490650  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490654(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490654  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490655  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490656  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490658  8b0d98ab4d00           -mov ecx, dword ptr [0x4dab98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0049065e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00490660  7505                   -jne 0x490667
    if (!cpu.flags.zf)
    {
        goto L_0x00490667;
    }
    // 00490662  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490664  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490665  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490666  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490667:
    // 00490667  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0049066d  e8467dffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00490672  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490677  83787400               +cmp dword ptr [eax + 0x74], 0
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
    // 0049067b  7504                   -jne 0x490681
    if (!cpu.flags.zf)
    {
        goto L_0x00490681;
    }
    // 0049067d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049067f  742e                   -je 0x4906af
    if (cpu.flags.zf)
    {
        goto L_0x004906af;
    }
L_0x00490681:
    // 00490681  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 00490686  8b5074                 -mov edx, dword ptr [eax + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00490689  8b4874                 -mov ecx, dword ptr [eax + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0049068c  8b8998000000           -mov ecx, dword ptr [ecx + 0x98]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00490692  894874                 -mov dword ptr [eax + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 00490695  c7829800000000000000   -mov dword ptr [edx + 0x98], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 0049069f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004906a5  e8267dffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004906aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004906ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004906af:
    // 004906af  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004906b5  e8167dffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004906ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004906bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4906c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004906c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004906c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004906c2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004906c4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004906c6  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004906cd  7421                   -je 0x4906f0
    if (cpu.flags.zf)
    {
        goto L_0x004906f0;
    }
    // 004906cf  833d54b84d0000         +cmp dword ptr [0x4db854], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093460) /* 0x4db854 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004906d6  7522                   -jne 0x4906fa
    if (!cpu.flags.zf)
    {
        goto L_0x004906fa;
    }
    // 004906d8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004906da  7e28                   -jle 0x490704
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490704;
    }
    // 004906dc  8a1525ac4d00           -mov dl, byte ptr [0x4dac25]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
    // 004906e2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004906e4  7428                   -je 0x49070e
    if (cpu.flags.zf)
    {
        goto L_0x0049070e;
    }
    // 004906e6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004906eb:
    // 004906eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906ed  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004906f0:
    // 004906f0  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004906f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906f7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004906fa:
    // 004906fa  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 004906ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490700  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490701  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00490704:
    // 00490704  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00490709  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049070a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049070b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049070e:
    // 0049070e  e88d68ffff             -call 0x486fa0
    cpu.esp -= 4;
    sub_486fa0(app, cpu);
    if (cpu.terminate) return;
    // 00490713  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490715  7cd4                   -jl 0x4906eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004906eb;
    }
    // 00490717  e8700e0000             -call 0x49158c
    cpu.esp -= 4;
    sub_49158c(app, cpu);
    if (cpu.terminate) return;
    // 0049071c  881528ac4d00           -mov byte ptr [0x4dac28], dl
    app->getMemory<x86::reg8>(x86::reg32(5090344) /* 0x4dac28 */) = cpu.dl;
    // 00490722  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490726  a226ac4d00             -mov byte ptr [0x4dac26], al
    app->getMemory<x86::reg8>(x86::reg32(5090342) /* 0x4dac26 */) = cpu.al;
    // 0049072b  893da4ab4d00           -mov dword ptr [0x4daba4], edi
    app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */) = cpu.edi;
    // 00490731  881524ac4d00           -mov byte ptr [0x4dac24], dl
    app->getMemory<x86::reg8>(x86::reg32(5090340) /* 0x4dac24 */) = cpu.dl;
    // 00490737  881531ac4d00           -mov byte ptr [0x4dac31], dl
    app->getMemory<x86::reg8>(x86::reg32(5090353) /* 0x4dac31 */) = cpu.dl;
    // 0049073d  881532ac4d00           -mov byte ptr [0x4dac32], dl
    app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */) = cpu.dl;
    // 00490743  89353cac4d00           -mov dword ptr [0x4dac3c], esi
    app->getMemory<x86::reg32>(x86::reg32(5090364) /* 0x4dac3c */) = cpu.esi;
    // 00490749  890db4ab4d00           -mov dword ptr [0x4dabb4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090228) /* 0x4dabb4 */) = cpu.ecx;
    // 0049074f  c60525ac4d0001         -mov byte ptr [0x4dac25], 1
    app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */) = 1 /*0x1*/;
    // 00490756  c60533ac4d00ff         -mov byte ptr [0x4dac33], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */) = 255 /*0xff*/;
    // 0049075d  8b0d48a25900           -mov ecx, dword ptr [0x59a248]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5874248) /* 0x59a248 */);
    // 00490763  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00490765  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00490767:
    // 00490767  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490769  e8b21bffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0049076e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00490770  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490772  e8dd0a0000             -call 0x491254
    cpu.esp -= 4;
    sub_491254(app, cpu);
    if (cpu.terminate) return;
    // 00490777  3b3538ac4d00           +cmp esi, dword ptr [0x4dac38]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049077d  7e08                   -jle 0x490787
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490787;
    }
    // 0049077f  3b0d48a25900           +cmp ecx, dword ptr [0x59a248]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5874248) /* 0x59a248 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490785  77e0                   -ja 0x490767
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00490767;
    }
L_0x00490787:
    // 00490787  a138ac4d00             -mov eax, dword ptr [0x4dac38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */);
    // 0049078c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049078d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049078e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490794(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490794  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049079b  740f                   -je 0x4907ac
    if (cpu.flags.zf)
    {
        goto L_0x004907ac;
    }
    // 0049079d  803d25ac4d0002         +cmp byte ptr [0x4dac25], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004907a4  750c                   -jne 0x4907b2
    if (!cpu.flags.zf)
    {
        goto L_0x004907b2;
    }
    // 004907a6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004907ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004907ac:
    // 004907ac  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004907b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004907b2:
    // 004907b2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004907b3  a227ac4d00             -mov byte ptr [0x4dac27], al
    app->getMemory<x86::reg8>(x86::reg32(5090343) /* 0x4dac27 */) = cpu.al;
    // 004907b8  88152aac4d00           -mov byte ptr [0x4dac2a], dl
    app->getMemory<x86::reg8>(x86::reg32(5090346) /* 0x4dac2a */) = cpu.dl;
    // 004907be  b1ff                   -mov cl, 0xff
    cpu.cl = 255 /*0xff*/;
    // 004907c0  880d2bac4d00           -mov byte ptr [0x4dac2b], cl
    app->getMemory<x86::reg8>(x86::reg32(5090347) /* 0x4dac2b */) = cpu.cl;
    // 004907c6  880d2cac4d00           -mov byte ptr [0x4dac2c], cl
    app->getMemory<x86::reg8>(x86::reg32(5090348) /* 0x4dac2c */) = cpu.cl;
    // 004907cc  880d2dac4d00           -mov byte ptr [0x4dac2d], cl
    app->getMemory<x86::reg8>(x86::reg32(5090349) /* 0x4dac2d */) = cpu.cl;
    // 004907d2  e8690e0000             -call 0x491640
    cpu.esp -= 4;
    sub_491640(app, cpu);
    if (cpu.terminate) return;
    // 004907d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004907d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4907e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004907e0  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004907e7  740f                   -je 0x4907f8
    if (cpu.flags.zf)
    {
        goto L_0x004907f8;
    }
    // 004907e9  803d25ac4d0000         +cmp byte ptr [0x4dac25], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004907f0  750c                   -jne 0x4907fe
    if (!cpu.flags.zf)
    {
        goto L_0x004907fe;
    }
    // 004907f2  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004907f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004907f8:
    // 004907f8  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004907fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004907fe:
    // 004907fe  a1bcab4d00             -mov eax, dword ptr [0x4dabbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */);
    // 00490803  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_490810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490810  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490811  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490812  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00490814  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049081b  7411                   -je 0x49082e
    if (cpu.flags.zf)
    {
        goto L_0x0049082e;
    }
    // 0049081d  833d54b84d0000         +cmp dword ptr [0x4db854], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093460) /* 0x4db854 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490824  7410                   -je 0x490836
    if (cpu.flags.zf)
    {
        goto L_0x00490836;
    }
    // 00490826  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 0049082b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049082c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049082d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049082e:
    // 0049082e  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00490833  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490834  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490835  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490836:
    // 00490836  e895060100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 0049083b  e86067ffff             -call 0x486fa0
    cpu.esp -= 4;
    sub_486fa0(app, cpu);
    if (cpu.terminate) return;
    // 00490840  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490842  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490844  7c7d                   -jl 0x4908c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004908c3;
    }
    // 00490846  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490847  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00490849  a2a8ac4d00             -mov byte ptr [0x4daca8], al
    app->getMemory<x86::reg8>(x86::reg32(5090472) /* 0x4daca8 */) = cpu.al;
    // 0049084e  c60528ac4d0001         -mov byte ptr [0x4dac28], 1
    app->getMemory<x86::reg8>(x86::reg32(5090344) /* 0x4dac28 */) = 1 /*0x1*/;
    // 00490855  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00490857  8935b4ab4d00           -mov dword ptr [0x4dabb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5090228) /* 0x4dabb4 */) = cpu.esi;
    // 0049085d  8a4208                 -mov al, byte ptr [edx + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00490860  a22aac4d00             -mov byte ptr [0x4dac2a], al
    app->getMemory<x86::reg8>(x86::reg32(5090346) /* 0x4dac2a */) = cpu.al;
    // 00490865  8a4207                 -mov al, byte ptr [edx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 00490868  a22bac4d00             -mov byte ptr [0x4dac2b], al
    app->getMemory<x86::reg8>(x86::reg32(5090347) /* 0x4dac2b */) = cpu.al;
    // 0049086d  8a4209                 -mov al, byte ptr [edx + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 00490870  a22cac4d00             -mov byte ptr [0x4dac2c], al
    app->getMemory<x86::reg8>(x86::reg32(5090348) /* 0x4dac2c */) = cpu.al;
    // 00490875  8a420a                 -mov al, byte ptr [edx + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 00490878  a22dac4d00             -mov byte ptr [0x4dac2d], al
    app->getMemory<x86::reg8>(x86::reg32(5090349) /* 0x4dac2d */) = cpu.al;
    // 0049087d  891da4ab4d00           -mov dword ptr [0x4daba4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */) = cpu.ebx;
    // 00490883  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00490885  881524ac4d00           -mov byte ptr [0x4dac24], dl
    app->getMemory<x86::reg8>(x86::reg32(5090340) /* 0x4dac24 */) = cpu.dl;
    // 0049088b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0049088d  883531ac4d00           -mov byte ptr [0x4dac31], dh
    app->getMemory<x86::reg8>(x86::reg32(5090353) /* 0x4dac31 */) = cpu.dh;
    // 00490893  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00490895  881d32ac4d00           -mov byte ptr [0x4dac32], bl
    app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */) = cpu.bl;
    // 0049089b  c7053cac4d000f000000   -mov dword ptr [0x4dac3c], 0xf
    app->getMemory<x86::reg32>(x86::reg32(5090364) /* 0x4dac3c */) = 15 /*0xf*/;
    // 004908a5  c60533ac4d00ff         -mov byte ptr [0x4dac33], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */) = 255 /*0xff*/;
    // 004908ac  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004908ae  a234ac4d00             -mov byte ptr [0x4dac34], al
    app->getMemory<x86::reg8>(x86::reg32(5090356) /* 0x4dac34 */) = cpu.al;
    // 004908b3  e8d40c0000             -call 0x49158c
    cpu.esp -= 4;
    sub_49158c(app, cpu);
    if (cpu.terminate) return;
    // 004908b8  e827060100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004908bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004908bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004908c3:
    // 004908c3  e81c060100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004908c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004908ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4908d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004908d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004908d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004908d3  e8f8020100             -call 0x4a0bd0
    cpu.esp -= 4;
    sub_4a0bd0(app, cpu);
    if (cpu.terminate) return;
    // 004908d8  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004908df  7410                   -je 0x4908f1
    if (cpu.flags.zf)
    {
        goto L_0x004908f1;
    }
    // 004908e1  833d54b84d0000         +cmp dword ptr [0x4db854], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093460) /* 0x4db854 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004908e8  750e                   -jne 0x4908f8
    if (!cpu.flags.zf)
    {
        goto L_0x004908f8;
    }
    // 004908ea  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004908ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004908f1:
    // 004908f1  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004908f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004908f8:
    // 004908f8  e86f010000             -call 0x490a6c
    cpu.esp -= 4;
    sub_490a6c(app, cpu);
    if (cpu.terminate) return;
    // 004908fd  803d30ac4d0000         +cmp byte ptr [0x4dac30], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090352) /* 0x4dac30 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490904  7412                   -je 0x490918
    if (cpu.flags.zf)
    {
        goto L_0x00490918;
    }
    // 00490906  b854124900             -mov eax, 0x491254
    cpu.eax = 4788820 /*0x491254*/;
    // 0049090b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0049090d  e8c219ffff             -call 0x4822d4
    cpu.esp -= 4;
    sub_4822d4(app, cpu);
    if (cpu.terminate) return;
    // 00490912  883530ac4d00           -mov byte ptr [0x4dac30], dh
    app->getMemory<x86::reg8>(x86::reg32(5090352) /* 0x4dac30 */) = cpu.dh;
L_0x00490918:
    // 00490918  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490919  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049091b  890d54b84d00           -mov dword ptr [0x4db854], ecx
    app->getMemory<x86::reg32>(x86::reg32(5093460) /* 0x4db854 */) = cpu.ecx;
    // 00490921  e87a66ffff             -call 0x486fa0
    cpu.esp -= 4;
    sub_486fa0(app, cpu);
    if (cpu.terminate) return;
    // 00490926  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490928  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490929  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049092a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49092c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049092c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049092d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049092e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049092f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490931  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00490933  8a2538b84d00           -mov ah, byte ptr [0x4db838]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
    // 00490939  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049093b  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0049093d  750b                   -jne 0x49094a
    if (!cpu.flags.zf)
    {
        goto L_0x0049094a;
    }
    // 0049093f  bff6ffffff             -mov edi, 0xfffffff6
    cpu.edi = 4294967286 /*0xfffffff6*/;
    // 00490944  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00490946  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490947  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490948  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490949  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049094a:
    // 0049094a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049094b  e880050100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00490950  803d25ac4d0000         +cmp byte ptr [0x4dac25], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490957  7567                   -jne 0x4909c0
    if (!cpu.flags.zf)
    {
        goto L_0x004909c0;
    }
    // 00490959  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049095b  7549                   -jne 0x4909a6
    if (!cpu.flags.zf)
    {
        goto L_0x004909a6;
    }
    // 0049095d  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490962  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00490964  e8e3e1ffff             -call 0x48eb4c
    cpu.esp -= 4;
    sub_48eb4c(app, cpu);
    if (cpu.terminate) return;
L_0x00490969:
    // 00490969  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 0049096b  e81c0c0000             -call 0x49158c
    cpu.esp -= 4;
    sub_49158c(app, cpu);
    if (cpu.terminate) return;
    // 00490970  883525ac4d00           -mov byte ptr [0x4dac25], dh
    app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */) = cpu.dh;
L_0x00490976:
    // 00490976  a031ac4d00             -mov al, byte ptr [0x4dac31]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090353) /* 0x4dac31 */);
    // 0049097b  fe0531ac4d00           -inc byte ptr [0x4dac31]
    (app->getMemory<x86::reg8>(x86::reg32(5090353) /* 0x4dac31 */))++;
    // 00490981  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00490986  b8a8ac4d00             -mov eax, 0x4daca8
    cpu.eax = 5090472 /*0x4daca8*/;
    // 0049098b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049098d  e8ba3fffff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 00490992  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 00490994  883d27ad4d00           -mov byte ptr [0x4dad27], bh
    app->getMemory<x86::reg8>(x86::reg32(5090599) /* 0x4dad27 */) = cpu.bh;
    // 0049099a  e845050100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 0049099f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909a0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004909a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004909a6:
    // 004909a6  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 004909ab  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004909ad  e81ae2ffff             -call 0x48ebcc
    cpu.esp -= 4;
    sub_48ebcc(app, cpu);
    if (cpu.terminate) return;
    // 004909b2  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 004909b7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004909b9  e86ee2ffff             -call 0x48ec2c
    cpu.esp -= 4;
    sub_48ec2c(app, cpu);
    if (cpu.terminate) return;
    // 004909be  eba9                   -jmp 0x490969
    goto L_0x00490969;
L_0x004909c0:
    // 004909c0  0fbe1531ac4d00         -movsx edx, byte ptr [0x4dac31]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090353) /* 0x4dac31 */)));
    // 004909c7  0fbe0532ac4d00         -movsx eax, byte ptr [0x4dac32]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */)));
    // 004909ce  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004909d0  83f813                 +cmp eax, 0x13
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004909d3  7c11                   -jl 0x4909e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004909e6;
    }
    // 004909d5  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 004909da  e805050100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004909df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909e0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004909e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004909e6:
    // 004909e6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004909e8  7530                   -jne 0x490a1a
    if (!cpu.flags.zf)
    {
        goto L_0x00490a1a;
    }
    // 004909ea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004909ef  e8bcfbffff             -call 0x4905b0
    cpu.esp -= 4;
    sub_4905b0(app, cpu);
    if (cpu.terminate) return;
    // 004909f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004909f6  7511                   -jne 0x490a09
    if (!cpu.flags.zf)
    {
        goto L_0x00490a09;
    }
    // 004909f8  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 004909fd  e8e2040100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490a02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a03  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00490a05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490a09:
    // 00490a09  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490a0e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00490a10  e807e1ffff             -call 0x48eb1c
    cpu.esp -= 4;
    sub_48eb1c(app, cpu);
    if (cpu.terminate) return;
    // 00490a15  e95cffffff             -jmp 0x490976
    goto L_0x00490976;
L_0x00490a1a:
    // 00490a1a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00490a1f  e88cfbffff             -call 0x4905b0
    cpu.esp -= 4;
    sub_4905b0(app, cpu);
    if (cpu.terminate) return;
    // 00490a24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490a26  7511                   -jne 0x490a39
    if (!cpu.flags.zf)
    {
        goto L_0x00490a39;
    }
    // 00490a28  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 00490a2d  e8b2040100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490a32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a33  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00490a35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a38  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490a39:
    // 00490a39  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00490a3e  b8a8ac4d00             -mov eax, 0x4daca8
    cpu.eax = 5090472 /*0x4daca8*/;
    // 00490a43  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00490a45  e82d6d0000             -call 0x497777
    cpu.esp -= 4;
    sub_497777(app, cpu);
    if (cpu.terminate) return;
    // 00490a4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490a4c  740c                   -je 0x490a5a
    if (cpu.flags.zf)
    {
        goto L_0x00490a5a;
    }
    // 00490a4e  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490a53  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00490a55  e842e1ffff             -call 0x48eb9c
    cpu.esp -= 4;
    sub_48eb9c(app, cpu);
    if (cpu.terminate) return;
L_0x00490a5a:
    // 00490a5a  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490a5f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00490a61  e8c6e1ffff             -call 0x48ec2c
    cpu.esp -= 4;
    sub_48ec2c(app, cpu);
    if (cpu.terminate) return;
    // 00490a66  e90bffffff             -jmp 0x490976
    goto L_0x00490976;
}

/* align: skip 0x90 */
void Application::sub_490a6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490a6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490a6d  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490a74  7507                   -jne 0x490a7d
    if (!cpu.flags.zf)
    {
        goto L_0x00490a7d;
    }
    // 00490a76  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00490a7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490a7d:
    // 00490a7d  a1b8ab4d00             -mov eax, dword ptr [0x4dabb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 00490a82  e82972ffff             -call 0x487cb0
    cpu.esp -= 4;
    sub_487cb0(app, cpu);
    if (cpu.terminate) return;
    // 00490a87  8b1548a25900           -mov edx, dword ptr [0x59a248]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5874248) /* 0x59a248 */);
    // 00490a8d  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
L_0x00490a93:
    // 00490a93  a1b8ab4d00             -mov eax, dword ptr [0x4dabb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 00490a98  e8133affff             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 00490a9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490a9f  7516                   -jne 0x490ab7
    if (!cpu.flags.zf)
    {
        goto L_0x00490ab7;
    }
    // 00490aa1  3b1548a25900           +cmp edx, dword ptr [0x59a248]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5874248) /* 0x59a248 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490aa7  7207                   -jb 0x490ab0
    if (cpu.flags.cf)
    {
        goto L_0x00490ab0;
    }
    // 00490aa9  e87218ffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 00490aae  ebe3                   -jmp 0x490a93
    goto L_0x00490a93;
L_0x00490ab0:
    // 00490ab0  b8efffffff             -mov eax, 0xffffffef
    cpu.eax = 4294967279 /*0xffffffef*/;
    // 00490ab5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ab6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490ab7:
    // 00490ab7  e814040100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00490abc  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 00490abe  e869020000             -call 0x490d2c
    cpu.esp -= 4;
    sub_490d2c(app, cpu);
    if (cpu.terminate) return;
    // 00490ac3  881533ac4d00           -mov byte ptr [0x4dac33], dl
    app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */) = cpu.dl;
    // 00490ac9  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00490acb  883534ac4d00           -mov byte ptr [0x4dac34], dh
    app->getMemory<x86::reg8>(x86::reg32(5090356) /* 0x4dac34 */) = cpu.dh;
    // 00490ad1  883531ac4d00           -mov byte ptr [0x4dac31], dh
    app->getMemory<x86::reg8>(x86::reg32(5090353) /* 0x4dac31 */) = cpu.dh;
    // 00490ad7  883532ac4d00           -mov byte ptr [0x4dac32], dh
    app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */) = cpu.dh;
    // 00490add  883525ac4d00           -mov byte ptr [0x4dac25], dh
    app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */) = cpu.dh;
    // 00490ae3  8835a8ac4d00           -mov byte ptr [0x4daca8], dh
    app->getMemory<x86::reg8>(x86::reg32(5090472) /* 0x4daca8 */) = cpu.dh;
    // 00490ae9  883524ac4d00           -mov byte ptr [0x4dac24], dh
    app->getMemory<x86::reg8>(x86::reg32(5090340) /* 0x4dac24 */) = cpu.dh;
    // 00490aef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490af1  e8da000100             -call 0x4a0bd0
    cpu.esp -= 4;
    sub_4a0bd0(app, cpu);
    if (cpu.terminate) return;
    // 00490af6  803d30ac4d0000         +cmp byte ptr [0x4dac30], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090352) /* 0x4dac30 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490afd  7410                   -je 0x490b0f
    if (cpu.flags.zf)
    {
        goto L_0x00490b0f;
    }
    // 00490aff  b854124900             -mov eax, 0x491254
    cpu.eax = 4788820 /*0x491254*/;
    // 00490b04  e8cb17ffff             -call 0x4822d4
    cpu.esp -= 4;
    sub_4822d4(app, cpu);
    if (cpu.terminate) return;
    // 00490b09  883530ac4d00           -mov byte ptr [0x4dac30], dh
    app->getMemory<x86::reg8>(x86::reg32(5090352) /* 0x4dac30 */) = cpu.dh;
L_0x00490b0f:
    // 00490b0f  e8d0030100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490b14  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490b16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490b18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b18  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490b19  8a2538b84d00           -mov ah, byte ptr [0x4db838]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
    // 00490b1f  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 00490b24  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00490b26  7509                   -jne 0x490b31
    if (!cpu.flags.zf)
    {
        goto L_0x00490b31;
    }
    // 00490b28  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 00490b2d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490b2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490b31:
    // 00490b31  e89a030100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00490b36  803d25ac4d0000         +cmp byte ptr [0x4dac25], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490b3d  741e                   -je 0x490b5d
    if (cpu.flags.zf)
    {
        goto L_0x00490b5d;
    }
    // 00490b3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490b41  a027ac4d00             -mov al, byte ptr [0x4dac27]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090343) /* 0x4dac27 */);
    // 00490b46  e85564ffff             -call 0x486fa0
    cpu.esp -= 4;
    sub_486fa0(app, cpu);
    if (cpu.terminate) return;
    // 00490b4b  8b15c0ab4d00           -mov edx, dword ptr [0x4dabc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */);
    // 00490b51  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490b53  803d35ac4d0002         +cmp byte ptr [0x4dac35], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490b5a  7501                   -jne 0x490b5d
    if (!cpu.flags.zf)
    {
        goto L_0x00490b5d;
    }
    // 00490b5c  4a                     -dec edx
    (cpu.edx)--;
L_0x00490b5d:
    // 00490b5d  e882030100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490b62  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490b64  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490b68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b68  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490b6f  7506                   -jne 0x490b77
    if (!cpu.flags.zf)
    {
        goto L_0x00490b77;
    }
    // 00490b71  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00490b76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490b77:
    // 00490b77  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490b78  e853030100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00490b7d  803d25ac4d0000         +cmp byte ptr [0x4dac25], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490b84  750e                   -jne 0x490b94
    if (!cpu.flags.zf)
    {
        goto L_0x00490b94;
    }
L_0x00490b86:
    // 00490b86  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 00490b8b  e854030100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490b90  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490b92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490b94:
    // 00490b94  803d25ac4d0001         +cmp byte ptr [0x4dac25], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490b9b  74e9                   -je 0x490b86
    if (cpu.flags.zf)
    {
        goto L_0x00490b86;
    }
    // 00490b9d  803d27ac4d0000         +cmp byte ptr [0x4dac27], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090343) /* 0x4dac27 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490ba4  750e                   -jne 0x490bb4
    if (!cpu.flags.zf)
    {
        goto L_0x00490bb4;
    }
    // 00490ba6  baf9ffffff             -mov edx, 0xfffffff9
    cpu.edx = 4294967289 /*0xfffffff9*/;
    // 00490bab  e834030100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490bb0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490bb2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490bb3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490bb4:
    // 00490bb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490bb5  e85effffff             -call 0x490b18
    cpu.esp -= 4;
    sub_490b18(app, cpu);
    if (cpu.terminate) return;
    // 00490bba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490bbc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00490bbf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00490bc1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00490bc4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490bc6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00490bc9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490bcb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00490bce  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490bd0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490bd2  8a0d27ac4d00           -mov cl, byte ptr [0x4dac27]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5090343) /* 0x4dac27 */);
    // 00490bd8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490bda  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00490bdd  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00490bdf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490be1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490be2  e8fd020100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490be7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490be9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490bea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490bec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490bec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490bed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490bef  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490bf6  7404                   -je 0x490bfc
    if (cpu.flags.zf)
    {
        goto L_0x00490bfc;
    }
    // 00490bf8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490bfa  7f02                   -jg 0x490bfe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00490bfe;
    }
L_0x00490bfc:
    // 00490bfc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490bfd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490bfe:
    // 00490bfe  e8e517ffff             -call 0x4823e8
    cpu.esp -= 4;
    sub_4823e8(app, cpu);
    if (cpu.terminate) return;
    // 00490c03  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490c05  7509                   -jne 0x490c10
    if (!cpu.flags.zf)
    {
        goto L_0x00490c10;
    }
    // 00490c07  e85cffffff             -call 0x490b68
    cpu.esp -= 4;
    sub_490b68(app, cpu);
    if (cpu.terminate) return;
    // 00490c0c  39d0                   +cmp eax, edx
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
    // 00490c0e  7d47                   -jge 0x490c57
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00490c57;
    }
L_0x00490c10:
    // 00490c10  e857f8ffff             -call 0x49046c
    cpu.esp -= 4;
    sub_49046c(app, cpu);
    if (cpu.terminate) return;
    // 00490c15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490c17  753e                   -jne 0x490c57
    if (!cpu.flags.zf)
    {
        goto L_0x00490c57;
    }
    // 00490c19  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490c1e  e8a1f8ffff             -call 0x4904c4
    cpu.esp -= 4;
    sub_4904c4(app, cpu);
    if (cpu.terminate) return;
    // 00490c23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490c25  7417                   -je 0x490c3e
    if (cpu.flags.zf)
    {
        goto L_0x00490c3e;
    }
    // 00490c27  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490c2c  e823f8ffff             -call 0x490454
    cpu.esp -= 4;
    sub_490454(app, cpu);
    if (cpu.terminate) return;
    // 00490c31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490c33  7509                   -jne 0x490c3e
    if (!cpu.flags.zf)
    {
        goto L_0x00490c3e;
    }
    // 00490c35  e8ae17ffff             -call 0x4823e8
    cpu.esp -= 4;
    sub_4823e8(app, cpu);
    if (cpu.terminate) return;
    // 00490c3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490c3c  741e                   -je 0x490c5c
    if (cpu.flags.zf)
    {
        goto L_0x00490c5c;
    }
L_0x00490c3e:
    // 00490c3e  891594ac4d00           -mov dword ptr [0x4dac94], edx
    app->getMemory<x86::reg32>(x86::reg32(5090452) /* 0x4dac94 */) = cpu.edx;
    // 00490c44  833d2cad4d0000         +cmp dword ptr [0x4dad2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090604) /* 0x4dad2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490c4b  74af                   -je 0x490bfc
    if (cpu.flags.zf)
    {
        goto L_0x00490bfc;
    }
    // 00490c4d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490c4f  ff152cad4d00           -call dword ptr [0x4dad2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090604) /* 0x4dad2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490c55  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c56  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490c57:
    // 00490c57  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00490c5c:
    // 00490c5c  e807000100             -call 0x4a0c68
    cpu.esp -= 4;
    sub_4a0c68(app, cpu);
    if (cpu.terminate) return;
    // 00490c61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490c64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490c64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490c65  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490c66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490c68  8a2538b84d00           -mov ah, byte ptr [0x4db838]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
    // 00490c6e  b9f1ffffff             -mov ecx, 0xfffffff1
    cpu.ecx = 4294967281 /*0xfffffff1*/;
    // 00490c73  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00490c75  750a                   -jne 0x490c81
    if (!cpu.flags.zf)
    {
        goto L_0x00490c81;
    }
    // 00490c77  b9f6ffffff             -mov ecx, 0xfffffff6
    cpu.ecx = 4294967286 /*0xfffffff6*/;
    // 00490c7c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490c7e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490c81:
    // 00490c81  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490c82  e849020100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00490c87  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00490c89  81fb5343446c           +cmp ebx, 0x6c444353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816413011 /*0x6c444353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490c8f  7514                   -jne 0x490ca5
    if (!cpu.flags.zf)
    {
        goto L_0x00490ca5;
    }
    // 00490c91  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490c93  e814010000             -call 0x490dac
    cpu.esp -= 4;
    sub_490dac(app, cpu);
    if (cpu.terminate) return;
    // 00490c98  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490c9a  e845020100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490c9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ca0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490ca2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ca3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ca4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490ca5:
    // 00490ca5  81fb5343486c           +cmp ebx, 0x6c484353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816675155 /*0x6c484353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cab  742c                   -je 0x490cd9
    if (cpu.flags.zf)
    {
        goto L_0x00490cd9;
    }
    // 00490cad  81fb5343436c           +cmp ebx, 0x6c434353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816347475 /*0x6c434353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cb3  7438                   -je 0x490ced
    if (cpu.flags.zf)
    {
        goto L_0x00490ced;
    }
    // 00490cb5  81fb53434c6c           +cmp ebx, 0x6c4c4353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816937299 /*0x6c4c4353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cbb  7444                   -je 0x490d01
    if (cpu.flags.zf)
    {
        goto L_0x00490d01;
    }
    // 00490cbd  81fb5343456c           +cmp ebx, 0x6c454353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816478547 /*0x6c454353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cc3  7550                   -jne 0x490d15
    if (!cpu.flags.zf)
    {
        goto L_0x00490d15;
    }
    // 00490cc5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490cc7  e8d0020000             -call 0x490f9c
    cpu.esp -= 4;
    sub_490f9c(app, cpu);
    if (cpu.terminate) return;
    // 00490ccc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490cce  e811020100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490cd3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cd4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490cd6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490cd9:
    // 00490cd9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490cdb  e820010000             -call 0x490e00
    cpu.esp -= 4;
    sub_490e00(app, cpu);
    if (cpu.terminate) return;
    // 00490ce0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490ce2  e8fd010100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490ce7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ce8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490cea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ceb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490ced:
    // 00490ced  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490cef  e814020000             -call 0x490f08
    cpu.esp -= 4;
    sub_490f08(app, cpu);
    if (cpu.terminate) return;
    // 00490cf4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490cf6  e8e9010100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490cfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cfc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490cfe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490d01:
    // 00490d01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490d03  e86c020000             -call 0x490f74
    cpu.esp -= 4;
    sub_490f74(app, cpu);
    if (cpu.terminate) return;
    // 00490d08  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490d0a  e8d5010100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490d0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d10  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490d12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490d15:
    // 00490d15  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490d1a  e821f7ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
    // 00490d1f  e8c0010100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490d24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d25  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490d27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490d2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490d2c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490d2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490d2e  e89d010100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00490d33  833da8ab4d0000         +cmp dword ptr [0x4daba8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490d3a  7454                   -je 0x490d90
    if (cpu.flags.zf)
    {
        goto L_0x00490d90;
    }
L_0x00490d3c:
    // 00490d3c  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00490d41  3b05acab4d00           +cmp eax, dword ptr [0x4dabac]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490d47  741e                   -je 0x490d67
    if (cpu.flags.zf)
    {
        goto L_0x00490d67;
    }
    // 00490d49  8b15a8ab4d00           -mov edx, dword ptr [0x4daba8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00490d4f  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00490d54  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00490d56  a3a8ab4d00             -mov dword ptr [0x4daba8], eax
    app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */) = cpu.eax;
    // 00490d5b  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490d60  e8dbf6ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
    // 00490d65  ebd5                   -jmp 0x490d3c
    goto L_0x00490d3c;
L_0x00490d67:
    // 00490d67  8b15a8ab4d00           -mov edx, dword ptr [0x4daba8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00490d6d  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490d72  e8c9f6ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
    // 00490d77  833db0ab4d0000         +cmp dword ptr [0x4dabb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490d7e  7410                   -je 0x490d90
    if (cpu.flags.zf)
    {
        goto L_0x00490d90;
    }
    // 00490d80  8b15b0ab4d00           -mov edx, dword ptr [0x4dabb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */);
    // 00490d86  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490d8b  e8b0f6ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
L_0x00490d90:
    // 00490d90  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00490d92  8935a8ab4d00           -mov dword ptr [0x4daba8], esi
    app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */) = cpu.esi;
    // 00490d98  8935acab4d00           -mov dword ptr [0x4dabac], esi
    app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */) = cpu.esi;
    // 00490d9e  8935b0ab4d00           -mov dword ptr [0x4dabb0], esi
    app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */) = cpu.esi;
    // 00490da4  e83b010100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00490da9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490daa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490dab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490dac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490dac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490dad  8b15c0ab4d00           -mov edx, dword ptr [0x4dabc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */);
    // 00490db3  ff05c0ab4d00           -inc dword ptr [0x4dabc0]
    (app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */))++;
    // 00490db9  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00490dbc  0115c4ab4d00           -add dword ptr [0x4dabc4], edx
    (app->getMemory<x86::reg32>(x86::reg32(5090244) /* 0x4dabc4 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490dc2  8338ff                 +cmp dword ptr [eax], -1
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
    // 00490dc5  751a                   -jne 0x490de1
    if (!cpu.flags.zf)
    {
        goto L_0x00490de1;
    }
L_0x00490dc7:
    // 00490dc7  833da8ab4d0000         +cmp dword ptr [0x4daba8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490dce  7519                   -jne 0x490de9
    if (!cpu.flags.zf)
    {
        goto L_0x00490de9;
    }
    // 00490dd0  a3a8ab4d00             -mov dword ptr [0x4daba8], eax
    app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */) = cpu.eax;
    // 00490dd5  a3acab4d00             -mov dword ptr [0x4dabac], eax
    app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */) = cpu.eax;
    // 00490dda  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00490ddf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490de0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490de1:
    // 00490de1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00490de7  ebde                   -jmp 0x490dc7
    goto L_0x00490dc7;
L_0x00490de9:
    // 00490de9  8b15acab4d00           -mov edx, dword ptr [0x4dabac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */);
    // 00490def  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00490df1  a3acab4d00             -mov dword ptr [0x4dabac], eax
    app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */) = cpu.eax;
    // 00490df6  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00490dfb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490dfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490e00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490e01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490e02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490e03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490e04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490e05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490e06  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490e09  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00490e0b  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00490e10  803d33ac4d0000         +cmp byte ptr [0x4dac33], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490e17  7e0b                   -jle 0x490e24
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490e24;
    }
    // 00490e19  a033ac4d00             -mov al, byte ptr [0x4dac33]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */);
    // 00490e1e  fe0d33ac4d00           -dec byte ptr [0x4dac33]
    (app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */))--;
L_0x00490e24:
    // 00490e24  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00490e27  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490e29  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00490e2d  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00490e2f  803d28ac4d0000         +cmp byte ptr [0x4dac28], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090344) /* 0x4dac28 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490e36  7551                   -jne 0x490e89
    if (!cpu.flags.zf)
    {
        goto L_0x00490e89;
    }
L_0x00490e38:
    // 00490e38  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490e3c  bfc8ab4d00             -mov edi, 0x4dabc8
    cpu.edi = 5090248 /*0x4dabc8*/;
    // 00490e41  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00490e43  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00490e48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490e49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490e4b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00490e4e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00490e50  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00490e52  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00490e55  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00490e57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e58  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00490e5a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00490e5d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00490e5f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490e61  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 00490e63  e828f90000             -call 0x4a0790
    cpu.esp -= 4;
    sub_4a0790(app, cpu);
    if (cpu.terminate) return;
    // 00490e68  882d24ac4d00           -mov byte ptr [0x4dac24], ch
    app->getMemory<x86::reg8>(x86::reg32(5090340) /* 0x4dac24 */) = cpu.ch;
    // 00490e6e  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490e73  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00490e75  e8c6f5ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
    // 00490e7a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00490e7f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490e82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e85  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490e89:
    // 00490e89  a032ac4d00             -mov al, byte ptr [0x4dac32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */);
    // 00490e8e  fe0532ac4d00           -inc byte ptr [0x4dac32]
    (app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */))++;
    // 00490e94  a031ac4d00             -mov al, byte ptr [0x4dac31]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090353) /* 0x4dac31 */);
    // 00490e99  fe0d31ac4d00           -dec byte ptr [0x4dac31]
    (app->getMemory<x86::reg8>(x86::reg32(5090353) /* 0x4dac31 */))--;
    // 00490e9f  bf98ac4d00             -mov edi, 0x4dac98
    cpu.edi = 5090456 /*0x4dac98*/;
    // 00490ea4  bea0ac4d00             -mov esi, 0x4daca0
    cpu.esi = 5090464 /*0x4daca0*/;
    // 00490ea9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00490eaa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00490eab  baa0ac4d00             -mov edx, 0x4daca0
    cpu.edx = 5090464 /*0x4daca0*/;
    // 00490eb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490eb2  e849820100             -call 0x4a9100
    cpu.esp -= 4;
    sub_4a9100(app, cpu);
    if (cpu.terminate) return;
    // 00490eb7  803d34ac4d0000         +cmp byte ptr [0x4dac34], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090356) /* 0x4dac34 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490ebe  743c                   -je 0x490efc
    if (cpu.flags.zf)
    {
        goto L_0x00490efc;
    }
    // 00490ec0  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00490ec5  bf98ac4d00             -mov edi, 0x4dac98
    cpu.edi = 5090456 /*0x4dac98*/;
    // 00490eca  bea0ac4d00             -mov esi, 0x4daca0
    cpu.esi = 5090464 /*0x4daca0*/;
    // 00490ecf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00490ed1  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 00490ed3  7405                   -je 0x490eda
    if (cpu.flags.zf)
    {
        goto L_0x00490eda;
    }
    // 00490ed5  19c0                   +sbb eax, eax
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
    // 00490ed7  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00490eda:
    // 00490eda  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490edc  741e                   -je 0x490efc
    if (cpu.flags.zf)
    {
        goto L_0x00490efc;
    }
    // 00490ede  803d25ac4d0002         +cmp byte ptr [0x4dac25], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490ee5  740e                   -je 0x490ef5
    if (cpu.flags.zf)
    {
        goto L_0x00490ef5;
    }
    // 00490ee7  803d25ac4d0003         +cmp byte ptr [0x4dac25], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490eee  7405                   -je 0x490ef5
    if (cpu.flags.zf)
    {
        goto L_0x00490ef5;
    }
    // 00490ef0  e84b070000             -call 0x491640
    cpu.esp -= 4;
    sub_491640(app, cpu);
    if (cpu.terminate) return;
L_0x00490ef5:
    // 00490ef5  c60525ac4d0003         -mov byte ptr [0x4dac25], 3
    app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */) = 3 /*0x3*/;
L_0x00490efc:
    // 00490efc  c60534ac4d0001         -mov byte ptr [0x4dac34], 1
    app->getMemory<x86::reg8>(x86::reg32(5090356) /* 0x4dac34 */) = 1 /*0x1*/;
    // 00490f03  e930ffffff             -jmp 0x490e38
    goto L_0x00490e38;
}

/* align: skip  */
void Application::sub_490f08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490f08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490f09  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490f0a  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00490f0d  8a0d36ac4d00           -mov cl, byte ptr [0x4dac36]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */);
    // 00490f13  3a0d37ac4d00           +cmp cl, byte ptr [0x4dac37]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490f19  7511                   -jne 0x490f2c
    if (!cpu.flags.zf)
    {
        goto L_0x00490f2c;
    }
    // 00490f1b  0fbe0d36ac4d00         -movsx ecx, byte ptr [0x4dac36]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */)));
    // 00490f22  833c8d44ac4d0000       +cmp dword ptr [ecx*4 + 0x4dac44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */ + cpu.ecx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490f2a  7e0c                   -jle 0x490f38
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490f38;
    }
L_0x00490f2c:
    // 00490f2c  8a0d37ac4d00           -mov cl, byte ptr [0x4dac37]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */);
    // 00490f32  fe0537ac4d00           -inc byte ptr [0x4dac37]
    (app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */))++;
L_0x00490f38:
    // 00490f38  803d37ac4d0014         +cmp byte ptr [0x4dac37], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490f3f  7c0a                   -jl 0x490f4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490f4b;
    }
    // 00490f41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490f42  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00490f44  881d37ac4d00           -mov byte ptr [0x4dac37], bl
    app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */) = cpu.bl;
    // 00490f4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00490f4b:
    // 00490f4b  0fbe0d37ac4d00         -movsx ecx, byte ptr [0x4dac37]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */)));
    // 00490f52  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00490f54  89148d44ac4d00         -mov dword ptr [ecx*4 + 0x4dac44], edx
    app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */ + cpu.ecx * 4) = cpu.edx;
    // 00490f5b  8b0da4ab4d00           -mov ecx, dword ptr [0x4daba4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490f61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490f63  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490f65  e8d6f4ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
    // 00490f6a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00490f6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490f74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490f74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490f75  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490f76  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490f78  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00490f7b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00490f7d  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490f82  e86ddcffff             -call 0x48ebf4
    cpu.esp -= 4;
    sub_48ebf4(app, cpu);
    if (cpu.terminate) return;
    // 00490f87  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490f8c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00490f8e  e8adf4ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
    // 00490f93  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00490f98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490f9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490f9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490f9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490f9e  ff05a0ab4d00           -inc dword ptr [0x4daba0]
    (app->getMemory<x86::reg32>(x86::reg32(5090208) /* 0x4daba0 */))++;
    // 00490fa4  803d26ac4d0000         +cmp byte ptr [0x4dac26], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090342) /* 0x4dac26 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490fab  750c                   -jne 0x490fb9
    if (!cpu.flags.zf)
    {
        goto L_0x00490fb9;
    }
    // 00490fad  8b0dacab4d00           -mov ecx, dword ptr [0x4dabac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */);
    // 00490fb3  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
L_0x00490fb9:
    // 00490fb9  8b0da4ab4d00           -mov ecx, dword ptr [0x4daba4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00490fbf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490fc1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490fc3  e878f4ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
    // 00490fc8  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00490fcd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490fce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490fcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490fd0  a1a0ab4d00             -mov eax, dword ptr [0x4daba0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090208) /* 0x4daba0 */);
    // 00490fd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490fd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490fd8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490fd9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490fda  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490fdb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490fdc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490fdd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00490fdf  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00490fe1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00490fe3  803d35ac4d0002         +cmp byte ptr [0x4dac35], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490fea  0f850e010000           -jne 0x4910fe
    if (!cpu.flags.zf)
    {
        goto L_0x004910fe;
    }
L_0x00490ff0:
    // 00490ff0  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00490ff5  3b05acab4d00           +cmp eax, dword ptr [0x4dabac]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ffb  0f8482000000           -je 0x491083
    if (cpu.flags.zf)
    {
        goto L_0x00491083;
    }
    // 00491001  8b3da8ab4d00           -mov edi, dword ptr [0x4daba8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00491007  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 0049100c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049100e  a3a8ab4d00             -mov dword ptr [0x4daba8], eax
    app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */) = cpu.eax;
    // 00491013  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00491016  833db0ab4d0000         +cmp dword ptr [0x4dabb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049101d  7410                   -je 0x49102f
    if (cpu.flags.zf)
    {
        goto L_0x0049102f;
    }
    // 0049101f  8b15b0ab4d00           -mov edx, dword ptr [0x4dabb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */);
    // 00491025  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 0049102a  e811f4ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
L_0x0049102f:
    // 0049102f  893db0ab4d00           -mov dword ptr [0x4dabb0], edi
    app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */) = cpu.edi;
    // 00491035  a1c0ab4d00             -mov eax, dword ptr [0x4dabc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */);
    // 0049103a  ff0dc0ab4d00           -dec dword ptr [0x4dabc0]
    (app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */))--;
    // 00491040  292dc4ab4d00           -sub dword ptr [0x4dabc4], ebp
    (app->getMemory<x86::reg32>(x86::reg32(5090244) /* 0x4dabc4 */)) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00491046  a1bcab4d00             -mov eax, dword ptr [0x4dabbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */);
    // 0049104b  ff05bcab4d00           -inc dword ptr [0x4dabbc]
    (app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */))++;
    // 00491051  0fbe0536ac4d00         -movsx eax, byte ptr [0x4dac36]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */)));
    // 00491058  8b148544ac4d00         -mov edx, dword ptr [eax*4 + 0x4dac44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */ + cpu.eax * 4);
    // 0049105f  ff0c8544ac4d00         -dec dword ptr [eax*4 + 0x4dac44]
    (app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */ + cpu.eax * 4))--;
    // 00491066  0fbe0536ac4d00         -movsx eax, byte ptr [0x4dac36]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */)));
    // 0049106d  833c8544ac4d0000       +cmp dword ptr [eax*4 + 0x4dac44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491075  0f8e95000000           -jle 0x491110
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491110;
    }
L_0x0049107b:
    // 0049107b  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049107d  882535ac4d00           -mov byte ptr [0x4dac35], ah
    app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */) = cpu.ah;
L_0x00491083:
    // 00491083  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00491088  3b05acab4d00           +cmp eax, dword ptr [0x4dabac]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049108e  0f85e0000000           -jne 0x491174
    if (!cpu.flags.zf)
    {
        goto L_0x00491174;
    }
    // 00491094  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00491099  8338ff                 +cmp dword ptr [eax], -1
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
    // 0049109c  0f84ae000000           -je 0x491150
    if (cpu.flags.zf)
    {
        goto L_0x00491150;
    }
    // 004910a2  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 004910a7  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004910aa  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004910ac  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 004910b1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004910b4  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004910b6  803d35ac4d0001         +cmp byte ptr [0x4dac35], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004910bd  7519                   -jne 0x4910d8
    if (!cpu.flags.zf)
    {
        goto L_0x004910d8;
    }
    // 004910bf  0fbe3d29ac4d00         -movsx edi, byte ptr [0x4dac29]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090345) /* 0x4dac29 */)));
    // 004910c6  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004910c8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004910ca  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004910cc  e87f6affff             -call 0x487b50
    cpu.esp -= 4;
    sub_487b50(app, cpu);
    if (cpu.terminate) return;
    // 004910d1  c60535ac4d0002         -mov byte ptr [0x4dac35], 2
    app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */) = 2 /*0x2*/;
L_0x004910d8:
    // 004910d8  803d35ac4d0000         +cmp byte ptr [0x4dac35], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004910df  7507                   -jne 0x4910e8
    if (!cpu.flags.zf)
    {
        goto L_0x004910e8;
    }
    // 004910e1  c60535ac4d0001         -mov byte ptr [0x4dac35], 1
    app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */) = 1 /*0x1*/;
L_0x004910e8:
    // 004910e8  803d35ac4d0002         +cmp byte ptr [0x4dac35], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004910ef  7505                   -jne 0x4910f6
    if (!cpu.flags.zf)
    {
        goto L_0x004910f6;
    }
    // 004910f1  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004910f6:
    // 004910f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004910f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004910fe:
    // 004910fe  803d35ac4d0001         +cmp byte ptr [0x4dac35], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491105  0f84e5feffff           -je 0x490ff0
    if (cpu.flags.zf)
    {
        goto L_0x00490ff0;
    }
    // 0049110b  e973ffffff             -jmp 0x491083
    goto L_0x00491083;
L_0x00491110:
    // 00491110  a032ac4d00             -mov al, byte ptr [0x4dac32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */);
    // 00491115  fe0d32ac4d00           -dec byte ptr [0x4dac32]
    (app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */))--;
    // 0049111b  a036ac4d00             -mov al, byte ptr [0x4dac36]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */);
    // 00491120  3a0537ac4d00           +cmp al, byte ptr [0x4dac37]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491126  0f844fffffff           -je 0x49107b
    if (cpu.flags.zf)
    {
        goto L_0x0049107b;
    }
    // 0049112c  a036ac4d00             -mov al, byte ptr [0x4dac36]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */);
    // 00491131  fe0536ac4d00           -inc byte ptr [0x4dac36]
    (app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */))++;
    // 00491137  803d36ac4d0014         +cmp byte ptr [0x4dac36], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049113e  0f8c37ffffff           -jl 0x49107b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049107b;
    }
    // 00491144  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00491146  a236ac4d00             -mov byte ptr [0x4dac36], al
    app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */) = cpu.al;
    // 0049114b  e92bffffff             -jmp 0x49107b
    goto L_0x0049107b;
L_0x00491150:
    // 00491150  8b15a8ab4d00           -mov edx, dword ptr [0x4daba8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00491156  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 0049115b  e8e0f2ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
    // 00491160  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00491166  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0049116c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049116e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049116f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491170  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491171  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491172  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491173  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491174:
    // 00491174  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00491179  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049117c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049117e  8b1da8ab4d00           -mov ebx, dword ptr [0x4daba8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00491184  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00491187  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00491189  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049118b  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00491190  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00491192  a3a8ab4d00             -mov dword ptr [0x4daba8], eax
    app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */) = cpu.eax;
    // 00491197  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049119a  833db0ab4d0000         +cmp dword ptr [0x4dabb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004911a1  7410                   -je 0x4911b3
    if (cpu.flags.zf)
    {
        goto L_0x004911b3;
    }
    // 004911a3  8b15b0ab4d00           -mov edx, dword ptr [0x4dabb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */);
    // 004911a9  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 004911ae  e88df2ffff             -call 0x490440
    cpu.esp -= 4;
    sub_490440(app, cpu);
    if (cpu.terminate) return;
L_0x004911b3:
    // 004911b3  891db0ab4d00           -mov dword ptr [0x4dabb0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */) = cpu.ebx;
    // 004911b9  a1c0ab4d00             -mov eax, dword ptr [0x4dabc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */);
    // 004911be  ff0dc0ab4d00           -dec dword ptr [0x4dabc0]
    (app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */))--;
    // 004911c4  290dc4ab4d00           -sub dword ptr [0x4dabc4], ecx
    (app->getMemory<x86::reg32>(x86::reg32(5090244) /* 0x4dabc4 */)) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004911ca  a1bcab4d00             -mov eax, dword ptr [0x4dabbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */);
    // 004911cf  ff05bcab4d00           -inc dword ptr [0x4dabbc]
    (app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */))++;
    // 004911d5  0fbe0536ac4d00         -movsx eax, byte ptr [0x4dac36]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */)));
    // 004911dc  8b148544ac4d00         -mov edx, dword ptr [eax*4 + 0x4dac44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */ + cpu.eax * 4);
    // 004911e3  ff0c8544ac4d00         -dec dword ptr [eax*4 + 0x4dac44]
    (app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */ + cpu.eax * 4))--;
    // 004911ea  0fbe0536ac4d00         -movsx eax, byte ptr [0x4dac36]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */)));
    // 004911f1  833c8544ac4d0000       +cmp dword ptr [eax*4 + 0x4dac44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004911f9  0f8ff7feffff           -jg 0x4910f6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004910f6;
    }
    // 004911ff  a032ac4d00             -mov al, byte ptr [0x4dac32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */);
    // 00491204  fe0d32ac4d00           -dec byte ptr [0x4dac32]
    (app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */))--;
    // 0049120a  a036ac4d00             -mov al, byte ptr [0x4dac36]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */);
    // 0049120f  3a0537ac4d00           +cmp al, byte ptr [0x4dac37]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491215  0f84dbfeffff           -je 0x4910f6
    if (cpu.flags.zf)
    {
        goto L_0x004910f6;
    }
    // 0049121b  a036ac4d00             -mov al, byte ptr [0x4dac36]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */);
    // 00491220  fe0536ac4d00           -inc byte ptr [0x4dac36]
    (app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */))++;
    // 00491226  803d36ac4d0014         +cmp byte ptr [0x4dac36], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049122d  0f8cc3feffff           -jl 0x4910f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004910f6;
    }
    // 00491233  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00491235  880d36ac4d00           -mov byte ptr [0x4dac36], cl
    app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */) = cpu.cl;
    // 0049123b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049123d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049123e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049123f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491240  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491241  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491242  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491254(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00491254  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491255  e88e11ffff             -call 0x4823e8
    cpu.esp -= 4;
    sub_4823e8(app, cpu);
    if (cpu.terminate) return;
    // 0049125a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049125c  7404                   -je 0x491262
    if (cpu.flags.zf)
    {
        goto L_0x00491262;
    }
    // 0049125e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491260  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491261  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491262:
    // 00491262  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491263  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491264  e867fc0000             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00491269  a025ac4d00             -mov al, byte ptr [0x4dac25]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
    // 0049126e  3c03                   +cmp al, 3
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
    // 00491270  770c                   -ja 0x49127e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 00491272  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00491277  ff248544124900         -jmp dword ptr [eax*4 + 0x491244]
    cpu.ip = app->getMemory<x86::reg32>(4788804 + cpu.eax * 4); goto dynamic_jump;
  case 0x0049127e:
L_0x0049127e:
    // 0049127e  e861fc0000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00491283  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491285  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491286  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491287  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491288  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00491289:
    // 00491289  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049128b:
    // 0049128b  3a0d28ac4d00           +cmp cl, byte ptr [0x4dac28]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5090344) /* 0x4dac28 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491291  750d                   -jne 0x4912a0
    if (!cpu.flags.zf)
    {
        goto L_0x004912a0;
    }
    // 00491293  a138ac4d00             -mov eax, dword ptr [0x4dac38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */);
    // 00491298  3b053cac4d00           +cmp eax, dword ptr [0x4dac3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090364) /* 0x4dac3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049129e  7dde                   -jge 0x49127e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049127e;
    }
L_0x004912a0:
    // 004912a0  3a0d33ac4d00           +cmp cl, byte ptr [0x4dac33]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004912a6  7526                   -jne 0x4912ce
    if (!cpu.flags.zf)
    {
        goto L_0x004912ce;
    }
    // 004912a8  833d40ac4d00ff         +cmp dword ptr [0x4dac40], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090368) /* 0x4dac40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004912af  74cd                   -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 004912b1  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 004912b6  e899f1ffff             -call 0x490454
    cpu.esp -= 4;
    sub_490454(app, cpu);
    if (cpu.terminate) return;
    // 004912bb  3b0540ac4d00           +cmp eax, dword ptr [0x4dac40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090368) /* 0x4dac40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004912c1  0f8c8f000000           -jl 0x491356
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491356;
    }
L_0x004912c7:
    // 004912c7  c60533ac4d00ff         -mov byte ptr [0x4dac33], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */) = 255 /*0xff*/;
L_0x004912ce:
    // 004912ce  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 004912d3  e844f0ffff             -call 0x49031c
    cpu.esp -= 4;
    sub_49031c(app, cpu);
    if (cpu.terminate) return;
    // 004912d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004912da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004912dc  0f8e91000000           -jle 0x491373
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491373;
    }
L_0x004912e2:
    // 004912e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004912e4  e87bf9ffff             -call 0x490c64
    cpu.esp -= 4;
    sub_490c64(app, cpu);
    if (cpu.terminate) return;
    // 004912e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004912eb  7c0f                   -jl 0x4912fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004912fc;
    }
    // 004912ed  83f803                 +cmp eax, 3
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
    // 004912f0  0f85b8000000           -jne 0x4913ae
    if (!cpu.flags.zf)
    {
        goto L_0x004913ae;
    }
    // 004912f6  ff0538ac4d00           -inc dword ptr [0x4dac38]
    (app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */))++;
L_0x004912fc:
    // 004912fc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004912fe  7f8b                   -jg 0x49128b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049128b;
    }
    // 00491300  83faf6                 +cmp edx, -0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491303  7e86                   -jle 0x49128b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049128b;
    }
    // 00491305  803d28ac4d0000         +cmp byte ptr [0x4dac28], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090344) /* 0x4dac28 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049130c  0f846cffffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 00491312  a138ac4d00             -mov eax, dword ptr [0x4dac38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */);
    // 00491317  3b053cac4d00           +cmp eax, dword ptr [0x4dac3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090364) /* 0x4dac3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049131d  7d27                   -jge 0x491346
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491346;
    }
    // 0049131f  833d38ac4d0000         +cmp dword ptr [0x4dac38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491326  0f859d000000           -jne 0x4913c9
    if (!cpu.flags.zf)
    {
        goto L_0x004913c9;
    }
L_0x0049132c:
    // 0049132c  833d38ac4d0000         +cmp dword ptr [0x4dac38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491333  0f8445ffffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 00491339  e82ef1ffff             -call 0x49046c
    cpu.esp -= 4;
    sub_49046c(app, cpu);
    if (cpu.terminate) return;
    // 0049133e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491340  0f8438ffffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
L_0x00491346:
    // 00491346  e8f5020000             -call 0x491640
    cpu.esp -= 4;
    sub_491640(app, cpu);
    if (cpu.terminate) return;
    // 0049134b  e894fb0000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00491350  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491352  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491353  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491354  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491355  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491356:
    // 00491356  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 0049135b  e864f1ffff             -call 0x4904c4
    cpu.esp -= 4;
    sub_4904c4(app, cpu);
    if (cpu.terminate) return;
    // 00491360  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491362  0f855fffffff           -jne 0x4912c7
    if (!cpu.flags.zf)
    {
        goto L_0x004912c7;
    }
    // 00491368  e877fb0000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 0049136d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049136f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491370  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491371  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491372  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491373:
    // 00491373  83f8f6                 +cmp eax, -0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491376  0f8e66ffffff           -jle 0x4912e2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004912e2;
    }
    // 0049137c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049137e  0f8478ffffff           -je 0x4912fc
    if (cpu.flags.zf)
    {
        goto L_0x004912fc;
    }
    // 00491384  833d38ac4d0000         +cmp dword ptr [0x4dac38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049138b  0f84edfeffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 00491391  803d28ac4d0000         +cmp byte ptr [0x4dac28], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090344) /* 0x4dac28 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491398  0f84e0feffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 0049139e  e89d020000             -call 0x491640
    cpu.esp -= 4;
    sub_491640(app, cpu);
    if (cpu.terminate) return;
    // 004913a3  e83cfb0000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004913a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004913aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004913ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004913ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004913ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004913ae:
    // 004913ae  83f801                 +cmp eax, 1
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
    // 004913b1  0f8545ffffff           -jne 0x4912fc
    if (!cpu.flags.zf)
    {
        goto L_0x004912fc;
    }
    // 004913b7  803d25ac4d0001         +cmp byte ptr [0x4dac25], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004913be  0f85bafeffff           -jne 0x49127e
    if (!cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 004913c4  e933ffffff             -jmp 0x4912fc
    goto L_0x004912fc;
L_0x004913c9:
    // 004913c9  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 004913ce  e8f1f0ffff             -call 0x4904c4
    cpu.esp -= 4;
    sub_4904c4(app, cpu);
    if (cpu.terminate) return;
    // 004913d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004913d5  0f856bffffff           -jne 0x491346
    if (!cpu.flags.zf)
    {
        goto L_0x00491346;
    }
    // 004913db  e94cffffff             -jmp 0x49132c
    goto L_0x0049132c;
  case 0x004913e0:
    // 004913e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004913e2:
    // 004913e2  3a0d33ac4d00           +cmp cl, byte ptr [0x4dac33]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004913e8  7526                   -jne 0x491410
    if (!cpu.flags.zf)
    {
        goto L_0x00491410;
    }
    // 004913ea  833d40ac4d00ff         +cmp dword ptr [0x4dac40], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090368) /* 0x4dac40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004913f1  0f8487feffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 004913f7  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 004913fc  e853f0ffff             -call 0x490454
    cpu.esp -= 4;
    sub_490454(app, cpu);
    if (cpu.terminate) return;
    // 00491401  3b0540ac4d00           +cmp eax, dword ptr [0x4dac40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090368) /* 0x4dac40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491407  7c6f                   -jl 0x491478
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491478;
    }
L_0x00491409:
    // 00491409  c60533ac4d00ff         -mov byte ptr [0x4dac33], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5090355) /* 0x4dac33 */) = 255 /*0xff*/;
L_0x00491410:
    // 00491410  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 00491415  e802efffff             -call 0x49031c
    cpu.esp -= 4;
    sub_49031c(app, cpu);
    if (cpu.terminate) return;
    // 0049141a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049141c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049141e  7e71                   -jle 0x491491
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491491;
    }
L_0x00491420:
    // 00491420  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491422  e83df8ffff             -call 0x490c64
    cpu.esp -= 4;
    sub_490c64(app, cpu);
    if (cpu.terminate) return;
    // 00491427  83f801                 +cmp eax, 1
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
    // 0049142a  756a                   -jne 0x491496
    if (!cpu.flags.zf)
    {
        goto L_0x00491496;
    }
L_0x0049142c:
    // 0049142c  833d94ac4d0000         +cmp dword ptr [0x4dac94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090452) /* 0x4dac94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491433  0f8445feffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 00491439  e82af7ffff             -call 0x490b68
    cpu.esp -= 4;
    sub_490b68(app, cpu);
    if (cpu.terminate) return;
    // 0049143e  3b0594ac4d00           +cmp eax, dword ptr [0x4dac94]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5090452) /* 0x4dac94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491444  7c63                   -jl 0x4914a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004914a9;
    }
    // 00491446  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491448  891d94ac4d00           -mov dword ptr [0x4dac94], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090452) /* 0x4dac94 */) = cpu.ebx;
    // 0049144e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491453  e810f80000             -call 0x4a0c68
    cpu.esp -= 4;
    sub_4a0c68(app, cpu);
    if (cpu.terminate) return;
    // 00491458  833d2cad4d0000         +cmp dword ptr [0x4dad2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090604) /* 0x4dad2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049145f  0f8419feffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 00491465  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491467  ff152cad4d00           -call dword ptr [0x4dad2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090604) /* 0x4dad2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049146d  e872fa0000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00491472  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491474  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491475  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491476  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491477  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491478:
    // 00491478  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 0049147d  e842f0ffff             -call 0x4904c4
    cpu.esp -= 4;
    sub_4904c4(app, cpu);
    if (cpu.terminate) return;
    // 00491482  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491484  7583                   -jne 0x491409
    if (!cpu.flags.zf)
    {
        goto L_0x00491409;
    }
    // 00491486  e859fa0000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 0049148b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049148d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049148e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049148f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491490  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491491:
    // 00491491  83f8f6                 +cmp eax, -0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491494  7e8a                   -jle 0x491420
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491420;
    }
L_0x00491496:
    // 00491496  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491498  0f8f44ffffff           -jg 0x4913e2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004913e2;
    }
    // 0049149e  83faf6                 +cmp edx, -0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004914a1  0f8e3bffffff           -jle 0x4913e2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004913e2;
    }
    // 004914a7  eb83                   -jmp 0x49142c
    goto L_0x0049142c;
L_0x004914a9:
    // 004914a9  a1a4ab4d00             -mov eax, dword ptr [0x4daba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
    // 004914ae  e811f0ffff             -call 0x4904c4
    cpu.esp -= 4;
    sub_4904c4(app, cpu);
    if (cpu.terminate) return;
    // 004914b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004914b5  7444                   -je 0x4914fb
    if (cpu.flags.zf)
    {
        goto L_0x004914fb;
    }
    // 004914b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004914b9  a027ac4d00             -mov al, byte ptr [0x4dac27]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090343) /* 0x4dac27 */);
    // 004914be  e8dd5affff             -call 0x486fa0
    cpu.esp -= 4;
    sub_486fa0(app, cpu);
    if (cpu.terminate) return;
    // 004914c3  83f801                 +cmp eax, 1
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
    // 004914c6  0f8fb2fdffff           -jg 0x49127e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049127e;
    }
    // 004914cc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004914ce  891594ac4d00           -mov dword ptr [0x4dac94], edx
    app->getMemory<x86::reg32>(x86::reg32(5090452) /* 0x4dac94 */) = cpu.edx;
    // 004914d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004914d6  e88df70000             -call 0x4a0c68
    cpu.esp -= 4;
    sub_4a0c68(app, cpu);
    if (cpu.terminate) return;
    // 004914db  833d2cad4d0000         +cmp dword ptr [0x4dad2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090604) /* 0x4dad2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004914e2  0f8496fdffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 004914e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004914ea  ff152cad4d00           -call dword ptr [0x4dad2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090604) /* 0x4dad2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004914f0  e8eff90000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004914f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004914f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004914fb:
    // 004914fb  e86cefffff             -call 0x49046c
    cpu.esp -= 4;
    sub_49046c(app, cpu);
    if (cpu.terminate) return;
    // 00491500  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491502  0f8476fdffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 00491508  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049150a  892d94ac4d00           -mov dword ptr [0x4dac94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090452) /* 0x4dac94 */) = cpu.ebp;
    // 00491510  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491515  e84ef70000             -call 0x4a0c68
    cpu.esp -= 4;
    sub_4a0c68(app, cpu);
    if (cpu.terminate) return;
    // 0049151a  833d2cad4d0000         +cmp dword ptr [0x4dad2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090604) /* 0x4dad2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491521  0f8457fdffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 00491527  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491529  ff152cad4d00           -call dword ptr [0x4dad2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090604) /* 0x4dad2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049152f  e8b0f90000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00491534  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491536  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491537  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491538  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491539  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049153a:
    // 0049153a  e8d9f5ffff             -call 0x490b18
    cpu.esp -= 4;
    sub_490b18(app, cpu);
    if (cpu.terminate) return;
    // 0049153f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491541  0f8f37fdffff           -jg 0x49127e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049127e;
    }
    // 00491547  a1b8ab4d00             -mov eax, dword ptr [0x4dabb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 0049154c  e85f67ffff             -call 0x487cb0
    cpu.esp -= 4;
    sub_487cb0(app, cpu);
    if (cpu.terminate) return;
    // 00491551  a1b8ab4d00             -mov eax, dword ptr [0x4dabb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 00491556  e8552fffff             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 0049155b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049155d  0f841bfdffff           -je 0x49127e
    if (cpu.flags.zf)
    {
        goto L_0x0049127e;
    }
    // 00491563  a032ac4d00             -mov al, byte ptr [0x4dac32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */);
    // 00491568  fe0d32ac4d00           -dec byte ptr [0x4dac32]
    (app->getMemory<x86::reg8>(x86::reg32(5090354) /* 0x4dac32 */))--;
    // 0049156e  e8b9f7ffff             -call 0x490d2c
    cpu.esp -= 4;
    sub_490d2c(app, cpu);
    if (cpu.terminate) return;
    // 00491573  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00491575  e812000000             -call 0x49158c
    cpu.esp -= 4;
    sub_49158c(app, cpu);
    if (cpu.terminate) return;
    // 0049157a  881525ac4d00           -mov byte ptr [0x4dac25], dl
    app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */) = cpu.dl;
    // 00491580  e85ff90000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00491585  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491587  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491588  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491589  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049158a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x90 */
void Application::sub_49158c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049158c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049158d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049158e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049158f  bad80f4900             -mov edx, 0x490fd8
    cpu.edx = 4788184 /*0x490fd8*/;
    // 00491594  b9d0084900             -mov ecx, 0x4908d0
    cpu.ecx = 4786384 /*0x4908d0*/;
    // 00491599  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049159b  891528ad4d00           -mov dword ptr [0x4dad28], edx
    app->getMemory<x86::reg32>(x86::reg32(5090600) /* 0x4dad28 */) = cpu.edx;
    // 004915a1  890d54b84d00           -mov dword ptr [0x4db854], ecx
    app->getMemory<x86::reg32>(x86::reg32(5093460) /* 0x4db854 */) = cpu.ecx;
    // 004915a7  891d38ac4d00           -mov dword ptr [0x4dac38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090360) /* 0x4dac38 */) = cpu.ebx;
    // 004915ad  891dbcab4d00           -mov dword ptr [0x4dabbc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */) = cpu.ebx;
    // 004915b3  891dc0ab4d00           -mov dword ptr [0x4dabc0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */) = cpu.ebx;
    // 004915b9  891dc4ab4d00           -mov dword ptr [0x4dabc4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090244) /* 0x4dabc4 */) = cpu.ebx;
    // 004915bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004915c1  891da8ab4d00           -mov dword ptr [0x4daba8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */) = cpu.ebx;
    // 004915c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004915c9  891dacab4d00           -mov dword ptr [0x4dabac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */) = cpu.ebx;
    // 004915cf  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004915d4  890db8ab4d00           -mov dword ptr [0x4dabb8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */) = cpu.ecx;
    // 004915da  30fc                   -xor ah, bh
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004915dc  882525ac4d00           -mov byte ptr [0x4dac25], ah
    app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */) = cpu.ah;
    // 004915e2  30da                   -xor dl, bl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004915e4  881536ac4d00           -mov byte ptr [0x4dac36], dl
    app->getMemory<x86::reg8>(x86::reg32(5090358) /* 0x4dac36 */) = cpu.dl;
    // 004915ea  30fe                   -xor dh, bh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004915ec  883537ac4d00           -mov byte ptr [0x4dac37], dh
    app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */) = cpu.dh;
    // 004915f2  0fbe0537ac4d00         -movsx eax, byte ptr [0x4dac37]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090359) /* 0x4dac37 */)));
    // 004915f9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004915fb  890c8544ac4d00         -mov dword ptr [eax*4 + 0x4dac44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */ + cpu.eax * 4) = cpu.ecx;
    // 00491602  c60526ac4d0001         -mov byte ptr [0x4dac26], 1
    app->getMemory<x86::reg8>(x86::reg32(5090342) /* 0x4dac26 */) = 1 /*0x1*/;
    // 00491609  30ef                   -xor bh, ch
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ch));
    // 0049160b  883d35ac4d00           -mov byte ptr [0x4dac35], bh
    app->getMemory<x86::reg8>(x86::reg32(5090357) /* 0x4dac35 */) = cpu.bh;
    // 00491611  803d30ac4d0000         +cmp byte ptr [0x4dac30], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5090352) /* 0x4dac30 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491618  7406                   -je 0x491620
    if (cpu.flags.zf)
    {
        goto L_0x00491620;
    }
    // 0049161a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049161c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049161d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049161e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049161f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491620:
    // 00491620  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00491625  b854124900             -mov eax, 0x491254
    cpu.eax = 4788820 /*0x491254*/;
    // 0049162a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049162c  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 0049162e  e80d0cffff             -call 0x482240
    cpu.esp -= 4;
    sub_482240(app, cpu);
    if (cpu.terminate) return;
    // 00491633  882d30ac4d00           -mov byte ptr [0x4dac30], ch
    app->getMemory<x86::reg8>(x86::reg32(5090352) /* 0x4dac30 */) = cpu.ch;
    // 00491639  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049163b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049163c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049163d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049163e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491640  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00491643  a1b8ab4d00             -mov eax, dword ptr [0x4dabb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 00491648  e8632effff             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 0049164d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049164f  7509                   -jne 0x49165a
    if (!cpu.flags.zf)
    {
        goto L_0x0049165a;
    }
    // 00491651  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00491656  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00491659  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049165a:
    // 0049165a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049165b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049165f  e88c21ffff             -call 0x4837f0
    cpu.esp -= 4;
    sub_4837f0(app, cpu);
    if (cpu.terminate) return;
    // 00491664  a02aac4d00             -mov al, byte ptr [0x4dac2a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090346) /* 0x4dac2a */);
    // 00491669  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0049166d  a02bac4d00             -mov al, byte ptr [0x4dac2b]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090347) /* 0x4dac2b */);
    // 00491672  8844240b               -mov byte ptr [esp + 0xb], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) = cpu.al;
    // 00491676  a02cac4d00             -mov al, byte ptr [0x4dac2c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090348) /* 0x4dac2c */);
    // 0049167b  8844240d               -mov byte ptr [esp + 0xd], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0049167f  a02dac4d00             -mov al, byte ptr [0x4dac2d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090349) /* 0x4dac2d */);
    // 00491684  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491688  8844240e               -mov byte ptr [esp + 0xe], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(14) /* 0xe */) = cpu.al;
    // 0049168c  b8c8ab4d00             -mov eax, 0x4dabc8
    cpu.eax = 5090248 /*0x4dabc8*/;
    // 00491691  e8daf40000             -call 0x4a0b70
    cpu.esp -= 4;
    sub_4a0b70(app, cpu);
    if (cpu.terminate) return;
    // 00491696  a3b8ab4d00             -mov dword ptr [0x4dabb8], eax
    app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */) = cpu.eax;
    // 0049169b  833db8ab4d0000         +cmp dword ptr [0x4dabb8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004916a2  7c5b                   -jl 0x4916ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004916ff;
    }
    // 004916a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004916a5  a1b8ab4d00             -mov eax, dword ptr [0x4dabb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 004916aa  e82dfc0000             -call 0x4a12dc
    cpu.esp -= 4;
    sub_4a12dc(app, cpu);
    if (cpu.terminate) return;
    // 004916af  a229ac4d00             -mov byte ptr [0x4dac29], al
    app->getMemory<x86::reg8>(x86::reg32(5090345) /* 0x4dac29 */) = cpu.al;
    // 004916b4  0fbe1529ac4d00         -movsx edx, byte ptr [0x4dac29]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090345) /* 0x4dac29 */)));
    // 004916bb  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004916c2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004916c4  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004916c7  8a80fb9b5900           -mov al, byte ptr [eax + 0x599bfb]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5872635) /* 0x599bfb */);
    // 004916cd  a227ac4d00             -mov byte ptr [0x4dac27], al
    app->getMemory<x86::reg8>(x86::reg32(5090343) /* 0x4dac27 */) = cpu.al;
    // 004916d2  c60525ac4d0002         -mov byte ptr [0x4dac25], 2
    app->getMemory<x86::reg8>(x86::reg32(5090341) /* 0x4dac25 */) = 2 /*0x2*/;
    // 004916d9  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004916db  881524ac4d00           -mov byte ptr [0x4dac24], dl
    app->getMemory<x86::reg8>(x86::reg32(5090340) /* 0x4dac24 */) = cpu.dl;
    // 004916e1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004916e3  66891d2eac4d00         -mov word ptr [0x4dac2e], bx
    app->getMemory<x86::reg16>(x86::reg32(5090350) /* 0x4dac2e */) = cpu.bx;
    // 004916ea  b8ec0b4900             -mov eax, 0x490bec
    cpu.eax = 4787180 /*0x490bec*/;
    // 004916ef  e8dcf40000             -call 0x4a0bd0
    cpu.esp -= 4;
    sub_4a0bd0(app, cpu);
    if (cpu.terminate) return;
    // 004916f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916f5  a1b8ab4d00             -mov eax, dword ptr [0x4dabb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 004916fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916fb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004916fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004916ff:
    // 004916ff  66a12eac4d00           -mov ax, word ptr [0x4dac2e]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5090350) /* 0x4dac2e */);
    // 00491705  66ff052eac4d00         -inc word ptr [0x4dac2e]
    (app->getMemory<x86::reg16>(x86::reg32(5090350) /* 0x4dac2e */))++;
    // 0049170c  a1b8ab4d00             -mov eax, dword ptr [0x4dabb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 00491711  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491712  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00491715  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_491720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491720  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491721  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491722  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491723  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00491726  8b7c2438               -mov edi, dword ptr [esp + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049172a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049172d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00491731  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00491735  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00491739  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049173d  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00491741  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491745  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00491747  bdd0070000             -mov ebp, 0x7d0
    cpu.ebp = 2000 /*0x7d0*/;
    // 0049174c  e8ff7a0100             -call 0x4a9250
    cpu.esp -= 4;
    sub_4a9250(app, cpu);
    if (cpu.terminate) return;
    // 00491751  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491753  0f8494000000           -je 0x4917ed
    if (cpu.flags.zf)
    {
        goto L_0x004917ed;
    }
    // 00491759  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049175d  2b1424                 -sub edx, dword ptr [esp]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00491760  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491762  0f8c8e000000           -jl 0x4917f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004917f6;
    }
    // 00491768  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0049176a:
    // 0049176a  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049176e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491770  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00491774  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00491776  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491778  0f8c81000000           -jl 0x4917ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004917ff;
    }
    // 0049177e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00491780:
    // 00491780  39cb                   +cmp ebx, ecx
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
    // 00491782  0f8e9c010000           -jle 0x491924
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491924;
    }
    // 00491788  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049178a  0f8c78000000           -jl 0x491808
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491808;
    }
L_0x00491790:
    // 00491790  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00491794  2b0424                 -sub eax, dword ptr [esp]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00491797  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491799  0f8c8c000000           -jl 0x49182b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049182b;
    }
L_0x0049179f:
    // 0049179f  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004917a3  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004917a7  2b4c2404               -sub ecx, dword ptr [esp + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004917ab  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004917ad  0f8c7f000000           -jl 0x491832
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491832;
    }
    // 004917b3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004917b5:
    // 004917b5  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004917b9  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004917bd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004917bf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004917c2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004917c4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004917c6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004917c8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004917ca  7c6f                   -jl 0x49183b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049183b;
    }
    // 004917cc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004917d1:
    // 004917d1  8a1d78904d00           -mov bl, byte ptr [0x4d9078]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 004917d7  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004917db  80fb08                 +cmp bl, 8
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004917de  0f85a3000000           -jne 0x491887
    if (!cpu.flags.zf)
    {
        goto L_0x00491887;
    }
L_0x004917e4:
    // 004917e4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004917e7  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004917eb  7e55                   -jle 0x491842
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491842;
    }
L_0x004917ed:
    // 004917ed  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004917f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004917f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004917f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004917f3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004917f6:
    // 004917f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004917f8  f7d8                   +neg eax
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
    // 004917fa  e96bffffff             -jmp 0x49176a
    goto L_0x0049176a;
L_0x004917ff:
    // 004917ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491801  f7d9                   +neg ecx
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
    // 00491803  e978ffffff             -jmp 0x491780
    goto L_0x00491780;
L_0x00491808:
    // 00491808  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049180c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049180f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00491812  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00491816  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049181a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049181e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00491822  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00491826  e965ffffff             -jmp 0x491790
    goto L_0x00491790;
L_0x0049182b:
    // 0049182b  f7d8                   +neg eax
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
    // 0049182d  e96dffffff             -jmp 0x49179f
    goto L_0x0049179f;
L_0x00491832:
    // 00491832  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00491834  f7d8                   +neg eax
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
    // 00491836  e97affffff             -jmp 0x4917b5
    goto L_0x004917b5;
L_0x0049183b:
    // 0049183b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00491840  eb8f                   -jmp 0x4917d1
    goto L_0x004917d1;
L_0x00491842:
    // 00491842  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491846  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491848  8b0d88904d00           -mov ecx, dword ptr [0x4d9088]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0049184e  030491                 -add eax, dword ptr [ecx + edx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4)));
    // 00491851  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 00491857  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00491859  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049185c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00491860  40                     -inc eax
    (cpu.eax)++;
    // 00491861  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00491863  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00491866  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491868  0f8d76ffffff           -jge 0x4917e4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004917e4;
    }
    // 0049186e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00491872  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491876  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049187a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049187c  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049187e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00491882  e95dffffff             -jmp 0x4917e4
    goto L_0x004917e4;
L_0x00491887:
    // 00491887  80fb0f                 +cmp bl, 0xf
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049188a  754d                   -jne 0x4918d9
    if (!cpu.flags.zf)
    {
        goto L_0x004918d9;
    }
L_0x0049188c:
    // 0049188c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049188f  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491893  0f8f54ffffff           -jg 0x4917ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004917ed;
    }
    // 00491899  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049189d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049189f  8b0d88904d00           -mov ecx, dword ptr [0x4d9088]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004918a5  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 004918a8  03157c904d00           -add edx, dword ptr [0x4d907c]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004918ae  66891c42               -mov word ptr [edx + eax*2], bx
    app->getMemory<x86::reg16>(cpu.edx + cpu.eax * 2) = cpu.bx;
    // 004918b2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004918b5  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004918b9  40                     -inc eax
    (cpu.eax)++;
    // 004918ba  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004918bc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004918bf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004918c1  7dc9                   -jge 0x49188c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049188c;
    }
    // 004918c3  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004918c7  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004918cb  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004918cf  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004918d1  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004918d3  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004918d7  ebb3                   -jmp 0x49188c
    goto L_0x0049188c;
L_0x004918d9:
    // 004918d9  80fb10                 +cmp bl, 0x10
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004918dc  74ae                   -je 0x49188c
    if (cpu.flags.zf)
    {
        goto L_0x0049188c;
    }
L_0x004918de:
    // 004918de  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004918e1  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f8f02ffffff           -jg 0x4917ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004917ed;
    }
    // 004918eb  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004918ec  0f84fbfeffff           -je 0x4917ed
    if (cpu.flags.zf)
    {
        goto L_0x004917ed;
    }
    // 004918f2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004918f6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004918f8  e8337b0100             -call 0x4a9430
    cpu.esp -= 4;
    sub_4a9430(app, cpu);
    if (cpu.terminate) return;
    // 004918fd  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00491900  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00491904  43                     -inc ebx
    (cpu.ebx)++;
    // 00491905  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00491907  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049190a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049190c  7dd0                   -jge 0x4918de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004918de;
    }
    // 0049190e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00491912  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491916  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049191a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049191c  01d6                   +add esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049191e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00491922  ebba                   -jmp 0x4918de
    goto L_0x004918de;
L_0x00491924:
    // 00491924  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491926  0f8ca1000000           -jl 0x4919cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004919cd;
    }
L_0x0049192c:
    // 0049192c  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00491930  2b0c24                 -sub ecx, dword ptr [esp]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00491933  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00491935  0f8cb5000000           -jl 0x4919f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004919f0;
    }
    // 0049193b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049193d:
    // 0049193d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00491941  2b542404               -sub edx, dword ptr [esp + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00491945  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00491949  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049194b  0f8ca8000000           -jl 0x4919f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004919f9;
    }
L_0x00491951:
    // 00491951  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00491955  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491957  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049195a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049195c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0049195e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00491960  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00491962  0f8c98000000           -jl 0x491a00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491a00;
    }
    // 00491968  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049196d:
    // 0049196d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00491971  8a2578904d00           -mov ah, byte ptr [0x4d9078]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 00491977  80fc08                 +cmp ah, 8
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
    // 0049197a  0f858a000000           -jne 0x491a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00491a0a;
    }
L_0x00491980:
    // 00491980  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491984  3b44240c               +cmp eax, dword ptr [esp + 0xc]
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
    // 00491988  0f8f5ffeffff           -jg 0x4917ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004917ed;
    }
    // 0049198e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491990  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491992  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00491995  8b0d88904d00           -mov ecx, dword ptr [0x4d9088]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0049199b  030491                 -add eax, dword ptr [ecx + edx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4)));
    // 0049199e  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004919a4  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004919a6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004919aa  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004919ae  40                     -inc eax
    (cpu.eax)++;
    // 004919af  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004919b1  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004919b5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004919b7  7dc7                   -jge 0x491980
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491980;
    }
    // 004919b9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004919bd  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004919c0  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004919c4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004919c6  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004919c8  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004919cb  ebb3                   -jmp 0x491980
    goto L_0x00491980;
L_0x004919cd:
    // 004919cd  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004919d1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004919d5  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004919d9  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004919dd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004919e1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004919e4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004919e7  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004919eb  e93cffffff             -jmp 0x49192c
    goto L_0x0049192c;
L_0x004919f0:
    // 004919f0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004919f2  f7d8                   +neg eax
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
    // 004919f4  e944ffffff             -jmp 0x49193d
    goto L_0x0049193d;
L_0x004919f9:
    // 004919f9  f7da                   +neg edx
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
    // 004919fb  e951ffffff             -jmp 0x491951
    goto L_0x00491951;
L_0x00491a00:
    // 00491a00  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00491a05  e963ffffff             -jmp 0x49196d
    goto L_0x0049196d;
L_0x00491a0a:
    // 00491a0a  80fc0f                 +cmp ah, 0xf
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
    // 00491a0d  754f                   -jne 0x491a5e
    if (!cpu.flags.zf)
    {
        goto L_0x00491a5e;
    }
L_0x00491a0f:
    // 00491a0f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491a13  3b44240c               +cmp eax, dword ptr [esp + 0xc]
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
    // 00491a17  0f8fd0fdffff           -jg 0x4917ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004917ed;
    }
    // 00491a1d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491a1f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491a21  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00491a24  8b0d88904d00           -mov ecx, dword ptr [0x4d9088]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 00491a2a  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00491a2d  03157c904d00           -add edx, dword ptr [0x4d907c]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 00491a33  66891c42               -mov word ptr [edx + eax*2], bx
    app->getMemory<x86::reg16>(cpu.edx + cpu.eax * 2) = cpu.bx;
    // 00491a37  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491a3b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00491a3f  40                     -inc eax
    (cpu.eax)++;
    // 00491a40  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00491a42  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00491a46  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491a48  7dc5                   -jge 0x491a0f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491a0f;
    }
    // 00491a4a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00491a4e  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00491a51  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00491a55  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491a57  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491a59  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00491a5c  ebb1                   -jmp 0x491a0f
    goto L_0x00491a0f;
L_0x00491a5e:
    // 00491a5e  80fc10                 +cmp ah, 0x10
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
    // 00491a61  74ac                   -je 0x491a0f
    if (cpu.flags.zf)
    {
        goto L_0x00491a0f;
    }
L_0x00491a63:
    // 00491a63  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491a67  3b44240c               +cmp eax, dword ptr [esp + 0xc]
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
    // 00491a6b  0f8f7cfdffff           -jg 0x4917ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004917ed;
    }
    // 00491a71  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00491a72  0f8475fdffff           -je 0x4917ed
    if (cpu.flags.zf)
    {
        goto L_0x004917ed;
    }
    // 00491a78  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491a7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491a7c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00491a7f  e8ac790100             -call 0x4a9430
    cpu.esp -= 4;
    sub_4a9430(app, cpu);
    if (cpu.terminate) return;
    // 00491a84  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491a88  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00491a8c  43                     -inc ebx
    (cpu.ebx)++;
    // 00491a8d  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00491a8f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00491a93  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491a95  7dcc                   -jge 0x491a63
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491a63;
    }
    // 00491a97  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00491a9b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00491a9e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00491aa2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491aa4  01d6                   +add esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491aa6  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00491aa9  ebb8                   -jmp 0x491a63
    goto L_0x00491a63;
}

/* align: skip  */
void Application::sub_491aab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491aab  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491aac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491aad  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00491ab0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491ab2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491ab4  7514                   -jne 0x491aca
    if (!cpu.flags.zf)
    {
        goto L_0x00491aca;
    }
    // 00491ab6  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491abc  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00491abf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491ac1  7507                   -jne 0x491aca
    if (!cpu.flags.zf)
    {
        goto L_0x00491aca;
    }
L_0x00491ac3:
    // 00491ac3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00491ac5  e97f000000             -jmp 0x491b49
    goto L_0x00491b49;
L_0x00491aca:
    // 00491aca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00491acc  e8167a0100             -call 0x4a94e7
    cpu.esp -= 4;
    sub_4a94e7(app, cpu);
    if (cpu.terminate) return;
    // 00491ad1  eb1f                   -jmp 0x491af2
    goto L_0x00491af2;
L_0x00491ad3:
    // 00491ad3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491ad5  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00491ad8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491ada  8a0c04                 -mov cl, byte ptr [esp + eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00491add  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491adf  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00491ae2  8a80b0fe4c00           -mov al, byte ptr [eax + 0x4cfeb0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5045936) /* 0x4cfeb0 */);
    // 00491ae8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491aed  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00491aef  7409                   -je 0x491afa
    if (cpu.flags.zf)
    {
        goto L_0x00491afa;
    }
    // 00491af1  43                     -inc ebx
    (cpu.ebx)++;
L_0x00491af2:
    // 00491af2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491af4  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00491af6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491af8  75d9                   -jne 0x491ad3
    if (!cpu.flags.zf)
    {
        goto L_0x00491ad3;
    }
L_0x00491afa:
    // 00491afa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00491afc  74c5                   -je 0x491ac3
    if (cpu.flags.zf)
    {
        goto L_0x00491ac3;
    }
    // 00491afe  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491b00  eb30                   -jmp 0x491b32
    goto L_0x00491b32;
L_0x00491b02:
    // 00491b02  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491b04  c1e903                 -shr ecx, 3
    cpu.ecx >>= 3 /*0x3*/ % 32;
    // 00491b07  8a0c0c                 -mov cl, byte ptr [esp + ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + cpu.ecx * 1);
    // 00491b0a  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00491b0d  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491b13  8a80b0fe4c00           -mov al, byte ptr [eax + 0x4cfeb0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5045936) /* 0x4cfeb0 */);
    // 00491b19  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491b1e  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00491b20  740f                   -je 0x491b31
    if (cpu.flags.zf)
    {
        goto L_0x00491b31;
    }
    // 00491b22  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00491b25  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00491b26  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491b2c  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00491b2f  eb16                   -jmp 0x491b47
    goto L_0x00491b47;
L_0x00491b31:
    // 00491b31  42                     -inc edx
    (cpu.edx)++;
L_0x00491b32:
    // 00491b32  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491b34  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00491b36  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491b38  75c8                   -jne 0x491b02
    if (!cpu.flags.zf)
    {
        goto L_0x00491b02;
    }
    // 00491b3a  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491b40  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x00491b47:
    // 00491b47  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00491b49:
    // 00491b49  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00491b4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491b4f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491b4f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491b50  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00491b52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491b53  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491b54  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491b55  83ec08                 +sub esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491b58  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00491b5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491b5c  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00491b5f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491b60  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00491b63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491b64  e8bd790100             -call 0x4a9526
    cpu.esp -= 4;
    sub_4a9526(app, cpu);
    if (cpu.terminate) return;
    // 00491b69  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00491b6b  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00491b6d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00491b6f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00491b70  760c                   -jbe 0x491b7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00491b7e;
    }
    // 00491b72  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00491b75  dc0558e64c00           -fadd qword ptr [0x4ce658]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5039704) /* 0x4ce658 */));
    // 00491b7b  dd5dec                 -fstp qword ptr [ebp - 0x14]
    app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00491b7e:
    // 00491b7e  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00491b81  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00491b84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b86  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b88  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_491b8b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491b8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491b8c  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00491b8e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491b8f  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00491b92  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00491b95  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00491b97  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00491b9a  e8b0ffffff             -call 0x491b4f
    cpu.esp -= 4;
    sub_491b4f(app, cpu);
    if (cpu.terminate) return;
    // 00491b9f  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00491ba1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ba2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ba3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_491bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491bb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491bb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491bb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491bb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491bb4  6860e64c00             -push 0x4ce660
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039712 /*0x4ce660*/;
    cpu.esp -= 4;
    // 00491bb9  2eff1518454c00         -call dword ptr cs:[0x4c4518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998424) /* 0x4c4518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491bc0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491bc2  a348ad4d00             -mov dword ptr [0x4dad48], eax
    app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */) = cpu.eax;
    // 00491bc7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491bc9  7507                   -jne 0x491bd2
    if (!cpu.flags.zf)
    {
        goto L_0x00491bd2;
    }
    // 00491bcb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491bcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bd0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491bd2:
    // 00491bd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491bd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491bd4  686ce64c00             -push 0x4ce66c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039724 /*0x4ce66c*/;
    cpu.esp -= 4;
    // 00491bd9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491bda  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491be1  687ce64c00             -push 0x4ce67c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039740 /*0x4ce67c*/;
    cpu.esp -= 4;
    // 00491be6  8b1548ad4d00           -mov edx, dword ptr [0x4dad48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491bec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491bed  a3c0c95600             -mov dword ptr [0x56c9c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5687744) /* 0x56c9c0 */) = cpu.eax;
    // 00491bf2  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491bf9  6894e64c00             -push 0x4ce694
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039764 /*0x4ce694*/;
    cpu.esp -= 4;
    // 00491bfe  8b0d48ad4d00           -mov ecx, dword ptr [0x4dad48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491c04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491c05  a3c4c95600             -mov dword ptr [0x56c9c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5687748) /* 0x56c9c4 */) = cpu.eax;
    // 00491c0a  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491c11  68a8e64c00             -push 0x4ce6a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039784 /*0x4ce6a8*/;
    cpu.esp -= 4;
    // 00491c16  8b1d48ad4d00           -mov ebx, dword ptr [0x4dad48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491c1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491c1d  a3c8c95600             -mov dword ptr [0x56c9c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5687752) /* 0x56c9c8 */) = cpu.eax;
    // 00491c22  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491c29  68b8e64c00             -push 0x4ce6b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039800 /*0x4ce6b8*/;
    cpu.esp -= 4;
    // 00491c2e  8b3548ad4d00           -mov esi, dword ptr [0x4dad48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491c34  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491c35  a3ccc95600             -mov dword ptr [0x56c9cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5687756) /* 0x56c9cc */) = cpu.eax;
    // 00491c3a  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491c41  68cce64c00             -push 0x4ce6cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039820 /*0x4ce6cc*/;
    cpu.esp -= 4;
    // 00491c46  8b3d48ad4d00           -mov edi, dword ptr [0x4dad48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491c4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491c4d  a3d0c95600             -mov dword ptr [0x56c9d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5687760) /* 0x56c9d0 */) = cpu.eax;
    // 00491c52  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491c59  68e0e64c00             -push 0x4ce6e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039840 /*0x4ce6e0*/;
    cpu.esp -= 4;
    // 00491c5e  8b2d48ad4d00           -mov ebp, dword ptr [0x4dad48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491c64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491c65  a3d4c95600             -mov dword ptr [0x56c9d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5687764) /* 0x56c9d4 */) = cpu.eax;
    // 00491c6a  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491c71  68f8e64c00             -push 0x4ce6f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039864 /*0x4ce6f8*/;
    cpu.esp -= 4;
    // 00491c76  a3d8c95600             -mov dword ptr [0x56c9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5687768) /* 0x56c9d8 */) = cpu.eax;
    // 00491c7b  a148ad4d00             -mov eax, dword ptr [0x4dad48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491c80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491c81  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491c88  680ce74c00             -push 0x4ce70c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039884 /*0x4ce70c*/;
    cpu.esp -= 4;
    // 00491c8d  8b1548ad4d00           -mov edx, dword ptr [0x4dad48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491c93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491c94  a3dcc95600             -mov dword ptr [0x56c9dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5687772) /* 0x56c9dc */) = cpu.eax;
    // 00491c99  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491ca0  682ce74c00             -push 0x4ce72c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039916 /*0x4ce72c*/;
    cpu.esp -= 4;
    // 00491ca5  8b0d48ad4d00           -mov ecx, dword ptr [0x4dad48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491cab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491cac  a3e0c95600             -mov dword ptr [0x56c9e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5687776) /* 0x56c9e0 */) = cpu.eax;
    // 00491cb1  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491cb8  6844e74c00             -push 0x4ce744
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039940 /*0x4ce744*/;
    cpu.esp -= 4;
    // 00491cbd  8b1d48ad4d00           -mov ebx, dword ptr [0x4dad48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491cc3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491cc4  a3e4c95600             -mov dword ptr [0x56c9e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5687780) /* 0x56c9e4 */) = cpu.eax;
    // 00491cc9  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491cd0  6858e74c00             -push 0x4ce758
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039960 /*0x4ce758*/;
    cpu.esp -= 4;
    // 00491cd5  8b3548ad4d00           -mov esi, dword ptr [0x4dad48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491cdb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491cdc  a3e8c95600             -mov dword ptr [0x56c9e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5687784) /* 0x56c9e8 */) = cpu.eax;
    // 00491ce1  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491ce8  686ce74c00             -push 0x4ce76c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039980 /*0x4ce76c*/;
    cpu.esp -= 4;
    // 00491ced  8b3d48ad4d00           -mov edi, dword ptr [0x4dad48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491cf3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491cf4  a3ecc95600             -mov dword ptr [0x56c9ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5687788) /* 0x56c9ec */) = cpu.eax;
    // 00491cf9  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491d00  a3f0c95600             -mov dword ptr [0x56c9f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5687792) /* 0x56c9f0 */) = cpu.eax;
    // 00491d05  687ce74c00             -push 0x4ce77c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039996 /*0x4ce77c*/;
    cpu.esp -= 4;
    // 00491d0a  8b2d48ad4d00           -mov ebp, dword ptr [0x4dad48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491d10  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491d11  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491d18  688ce74c00             -push 0x4ce78c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040012 /*0x4ce78c*/;
    cpu.esp -= 4;
    // 00491d1d  a3f4c95600             -mov dword ptr [0x56c9f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5687796) /* 0x56c9f4 */) = cpu.eax;
    // 00491d22  a148ad4d00             -mov eax, dword ptr [0x4dad48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491d27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491d28  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491d2f  689ce74c00             -push 0x4ce79c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040028 /*0x4ce79c*/;
    cpu.esp -= 4;
    // 00491d34  8b1548ad4d00           -mov edx, dword ptr [0x4dad48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491d3a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491d3b  a3f8c95600             -mov dword ptr [0x56c9f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5687800) /* 0x56c9f8 */) = cpu.eax;
    // 00491d40  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491d47  68ace74c00             -push 0x4ce7ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040044 /*0x4ce7ac*/;
    cpu.esp -= 4;
    // 00491d4c  8b0d48ad4d00           -mov ecx, dword ptr [0x4dad48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491d52  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491d53  a3fcc95600             -mov dword ptr [0x56c9fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5687804) /* 0x56c9fc */) = cpu.eax;
    // 00491d58  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491d5f  68c0e74c00             -push 0x4ce7c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040064 /*0x4ce7c0*/;
    cpu.esp -= 4;
    // 00491d64  8b1d48ad4d00           -mov ebx, dword ptr [0x4dad48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491d6a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491d6b  a300ca5600             -mov dword ptr [0x56ca00], eax
    app->getMemory<x86::reg32>(x86::reg32(5687808) /* 0x56ca00 */) = cpu.eax;
    // 00491d70  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491d77  68d4e74c00             -push 0x4ce7d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040084 /*0x4ce7d4*/;
    cpu.esp -= 4;
    // 00491d7c  8b3548ad4d00           -mov esi, dword ptr [0x4dad48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491d82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491d83  a304ca5600             -mov dword ptr [0x56ca04], eax
    app->getMemory<x86::reg32>(x86::reg32(5687812) /* 0x56ca04 */) = cpu.eax;
    // 00491d88  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491d8f  68e8e74c00             -push 0x4ce7e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040104 /*0x4ce7e8*/;
    cpu.esp -= 4;
    // 00491d94  8b3d48ad4d00           -mov edi, dword ptr [0x4dad48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491d9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491d9b  a308ca5600             -mov dword ptr [0x56ca08], eax
    app->getMemory<x86::reg32>(x86::reg32(5687816) /* 0x56ca08 */) = cpu.eax;
    // 00491da0  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491da7  6804e84c00             -push 0x4ce804
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040132 /*0x4ce804*/;
    cpu.esp -= 4;
    // 00491dac  8b2d48ad4d00           -mov ebp, dword ptr [0x4dad48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491db2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491db3  a30cca5600             -mov dword ptr [0x56ca0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5687820) /* 0x56ca0c */) = cpu.eax;
    // 00491db8  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491dbf  6814e84c00             -push 0x4ce814
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040148 /*0x4ce814*/;
    cpu.esp -= 4;
    // 00491dc4  a310ca5600             -mov dword ptr [0x56ca10], eax
    app->getMemory<x86::reg32>(x86::reg32(5687824) /* 0x56ca10 */) = cpu.eax;
    // 00491dc9  a148ad4d00             -mov eax, dword ptr [0x4dad48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491dce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491dcf  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491dd6  6828e84c00             -push 0x4ce828
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040168 /*0x4ce828*/;
    cpu.esp -= 4;
    // 00491ddb  8b1548ad4d00           -mov edx, dword ptr [0x4dad48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491de1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491de2  a314ca5600             -mov dword ptr [0x56ca14], eax
    app->getMemory<x86::reg32>(x86::reg32(5687828) /* 0x56ca14 */) = cpu.eax;
    // 00491de7  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491dee  6838e84c00             -push 0x4ce838
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040184 /*0x4ce838*/;
    cpu.esp -= 4;
    // 00491df3  8b0d48ad4d00           -mov ecx, dword ptr [0x4dad48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491df9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491dfa  a318ca5600             -mov dword ptr [0x56ca18], eax
    app->getMemory<x86::reg32>(x86::reg32(5687832) /* 0x56ca18 */) = cpu.eax;
    // 00491dff  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e06  684ce84c00             -push 0x4ce84c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040204 /*0x4ce84c*/;
    cpu.esp -= 4;
    // 00491e0b  8b1d48ad4d00           -mov ebx, dword ptr [0x4dad48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491e11  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491e12  a31cca5600             -mov dword ptr [0x56ca1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5687836) /* 0x56ca1c */) = cpu.eax;
    // 00491e17  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e1e  6864e84c00             -push 0x4ce864
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040228 /*0x4ce864*/;
    cpu.esp -= 4;
    // 00491e23  8b3548ad4d00           -mov esi, dword ptr [0x4dad48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491e29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491e2a  a320ca5600             -mov dword ptr [0x56ca20], eax
    app->getMemory<x86::reg32>(x86::reg32(5687840) /* 0x56ca20 */) = cpu.eax;
    // 00491e2f  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e36  a324ca5600             -mov dword ptr [0x56ca24], eax
    app->getMemory<x86::reg32>(x86::reg32(5687844) /* 0x56ca24 */) = cpu.eax;
    // 00491e3b  687ce84c00             -push 0x4ce87c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040252 /*0x4ce87c*/;
    cpu.esp -= 4;
    // 00491e40  8b3d48ad4d00           -mov edi, dword ptr [0x4dad48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491e46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491e47  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e4e  6898e84c00             -push 0x4ce898
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040280 /*0x4ce898*/;
    cpu.esp -= 4;
    // 00491e53  8b2d48ad4d00           -mov ebp, dword ptr [0x4dad48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491e59  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491e5a  a328ca5600             -mov dword ptr [0x56ca28], eax
    app->getMemory<x86::reg32>(x86::reg32(5687848) /* 0x56ca28 */) = cpu.eax;
    // 00491e5f  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e66  68a8e84c00             -push 0x4ce8a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040296 /*0x4ce8a8*/;
    cpu.esp -= 4;
    // 00491e6b  a32cca5600             -mov dword ptr [0x56ca2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5687852) /* 0x56ca2c */) = cpu.eax;
    // 00491e70  a148ad4d00             -mov eax, dword ptr [0x4dad48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491e75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491e76  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e7d  68bce84c00             -push 0x4ce8bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040316 /*0x4ce8bc*/;
    cpu.esp -= 4;
    // 00491e82  8b1548ad4d00           -mov edx, dword ptr [0x4dad48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491e88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491e89  a330ca5600             -mov dword ptr [0x56ca30], eax
    app->getMemory<x86::reg32>(x86::reg32(5687856) /* 0x56ca30 */) = cpu.eax;
    // 00491e8e  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491e95  68cce84c00             -push 0x4ce8cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040332 /*0x4ce8cc*/;
    cpu.esp -= 4;
    // 00491e9a  8b0d48ad4d00           -mov ecx, dword ptr [0x4dad48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491ea0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491ea1  a334ca5600             -mov dword ptr [0x56ca34], eax
    app->getMemory<x86::reg32>(x86::reg32(5687860) /* 0x56ca34 */) = cpu.eax;
    // 00491ea6  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491ead  68dce84c00             -push 0x4ce8dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040348 /*0x4ce8dc*/;
    cpu.esp -= 4;
    // 00491eb2  8b1d48ad4d00           -mov ebx, dword ptr [0x4dad48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491eb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491eb9  a338ca5600             -mov dword ptr [0x56ca38], eax
    app->getMemory<x86::reg32>(x86::reg32(5687864) /* 0x56ca38 */) = cpu.eax;
    // 00491ebe  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491ec5  68ece84c00             -push 0x4ce8ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040364 /*0x4ce8ec*/;
    cpu.esp -= 4;
    // 00491eca  8b3548ad4d00           -mov esi, dword ptr [0x4dad48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491ed0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491ed1  a33cca5600             -mov dword ptr [0x56ca3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5687868) /* 0x56ca3c */) = cpu.eax;
    // 00491ed6  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491edd  68fce84c00             -push 0x4ce8fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040380 /*0x4ce8fc*/;
    cpu.esp -= 4;
    // 00491ee2  8b3d48ad4d00           -mov edi, dword ptr [0x4dad48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491ee8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491ee9  a340ca5600             -mov dword ptr [0x56ca40], eax
    app->getMemory<x86::reg32>(x86::reg32(5687872) /* 0x56ca40 */) = cpu.eax;
    // 00491eee  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491ef5  6814e94c00             -push 0x4ce914
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040404 /*0x4ce914*/;
    cpu.esp -= 4;
    // 00491efa  8b2d48ad4d00           -mov ebp, dword ptr [0x4dad48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491f00  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491f01  a344ca5600             -mov dword ptr [0x56ca44], eax
    app->getMemory<x86::reg32>(x86::reg32(5687876) /* 0x56ca44 */) = cpu.eax;
    // 00491f06  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491f0d  6828e94c00             -push 0x4ce928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040424 /*0x4ce928*/;
    cpu.esp -= 4;
    // 00491f12  a348ca5600             -mov dword ptr [0x56ca48], eax
    app->getMemory<x86::reg32>(x86::reg32(5687880) /* 0x56ca48 */) = cpu.eax;
    // 00491f17  a148ad4d00             -mov eax, dword ptr [0x4dad48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491f1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491f1d  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491f24  683ce94c00             -push 0x4ce93c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040444 /*0x4ce93c*/;
    cpu.esp -= 4;
    // 00491f29  8b1548ad4d00           -mov edx, dword ptr [0x4dad48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491f2f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491f30  a34cca5600             -mov dword ptr [0x56ca4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5687884) /* 0x56ca4c */) = cpu.eax;
    // 00491f35  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491f3c  684ce94c00             -push 0x4ce94c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040460 /*0x4ce94c*/;
    cpu.esp -= 4;
    // 00491f41  8b0d48ad4d00           -mov ecx, dword ptr [0x4dad48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491f47  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491f48  a350ca5600             -mov dword ptr [0x56ca50], eax
    app->getMemory<x86::reg32>(x86::reg32(5687888) /* 0x56ca50 */) = cpu.eax;
    // 00491f4d  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491f54  685ce94c00             -push 0x4ce95c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040476 /*0x4ce95c*/;
    cpu.esp -= 4;
    // 00491f59  8b1d48ad4d00           -mov ebx, dword ptr [0x4dad48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491f5f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491f60  a354ca5600             -mov dword ptr [0x56ca54], eax
    app->getMemory<x86::reg32>(x86::reg32(5687892) /* 0x56ca54 */) = cpu.eax;
    // 00491f65  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491f6c  a358ca5600             -mov dword ptr [0x56ca58], eax
    app->getMemory<x86::reg32>(x86::reg32(5687896) /* 0x56ca58 */) = cpu.eax;
    // 00491f71  6878e94c00             -push 0x4ce978
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040504 /*0x4ce978*/;
    cpu.esp -= 4;
    // 00491f76  8b3548ad4d00           -mov esi, dword ptr [0x4dad48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491f7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491f7d  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491f84  688ce94c00             -push 0x4ce98c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040524 /*0x4ce98c*/;
    cpu.esp -= 4;
    // 00491f89  8b3d48ad4d00           -mov edi, dword ptr [0x4dad48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491f8f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491f90  a35cca5600             -mov dword ptr [0x56ca5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5687900) /* 0x56ca5c */) = cpu.eax;
    // 00491f95  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491f9c  68a0e94c00             -push 0x4ce9a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040544 /*0x4ce9a0*/;
    cpu.esp -= 4;
    // 00491fa1  8b2d48ad4d00           -mov ebp, dword ptr [0x4dad48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491fa7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491fa8  a360ca5600             -mov dword ptr [0x56ca60], eax
    app->getMemory<x86::reg32>(x86::reg32(5687904) /* 0x56ca60 */) = cpu.eax;
    // 00491fad  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491fb4  68b4e94c00             -push 0x4ce9b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040564 /*0x4ce9b4*/;
    cpu.esp -= 4;
    // 00491fb9  a364ca5600             -mov dword ptr [0x56ca64], eax
    app->getMemory<x86::reg32>(x86::reg32(5687908) /* 0x56ca64 */) = cpu.eax;
    // 00491fbe  a148ad4d00             -mov eax, dword ptr [0x4dad48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491fc3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00491fc4  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491fcb  68d0e94c00             -push 0x4ce9d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040592 /*0x4ce9d0*/;
    cpu.esp -= 4;
    // 00491fd0  8b1548ad4d00           -mov edx, dword ptr [0x4dad48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491fd6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491fd7  a368ca5600             -mov dword ptr [0x56ca68], eax
    app->getMemory<x86::reg32>(x86::reg32(5687912) /* 0x56ca68 */) = cpu.eax;
    // 00491fdc  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491fe3  68e8e94c00             -push 0x4ce9e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040616 /*0x4ce9e8*/;
    cpu.esp -= 4;
    // 00491fe8  8b0d48ad4d00           -mov ecx, dword ptr [0x4dad48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00491fee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491fef  a36cca5600             -mov dword ptr [0x56ca6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5687916) /* 0x56ca6c */) = cpu.eax;
    // 00491ff4  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491ffb  68fce94c00             -push 0x4ce9fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040636 /*0x4ce9fc*/;
    cpu.esp -= 4;
    // 00492000  8b1d48ad4d00           -mov ebx, dword ptr [0x4dad48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00492006  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492007  a370ca5600             -mov dword ptr [0x56ca70], eax
    app->getMemory<x86::reg32>(x86::reg32(5687920) /* 0x56ca70 */) = cpu.eax;
    // 0049200c  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492013  6810ea4c00             -push 0x4cea10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040656 /*0x4cea10*/;
    cpu.esp -= 4;
    // 00492018  8b3548ad4d00           -mov esi, dword ptr [0x4dad48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 0049201e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049201f  a374ca5600             -mov dword ptr [0x56ca74], eax
    app->getMemory<x86::reg32>(x86::reg32(5687924) /* 0x56ca74 */) = cpu.eax;
    // 00492024  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049202b  6820ea4c00             -push 0x4cea20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040672 /*0x4cea20*/;
    cpu.esp -= 4;
    // 00492030  8b3d48ad4d00           -mov edi, dword ptr [0x4dad48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00492036  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492037  a378ca5600             -mov dword ptr [0x56ca78], eax
    app->getMemory<x86::reg32>(x86::reg32(5687928) /* 0x56ca78 */) = cpu.eax;
    // 0049203c  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492043  6834ea4c00             -push 0x4cea34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5040692 /*0x4cea34*/;
    cpu.esp -= 4;
    // 00492048  8b2d48ad4d00           -mov ebp, dword ptr [0x4dad48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 0049204e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049204f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00492054  a37cca5600             -mov dword ptr [0x56ca7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5687932) /* 0x56ca7c */) = cpu.eax;
    // 00492059  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492060  a380ca5600             -mov dword ptr [0x56ca80], eax
    app->getMemory<x86::reg32>(x86::reg32(5687936) /* 0x56ca80 */) = cpu.eax;
    // 00492065  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492066  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492067  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00492069  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049206a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049206b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049206c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049206d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492072  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492073  8b1548ad4d00           -mov edx, dword ptr [0x4dad48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00492079  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049207b  750c                   -jne 0x492089
    if (!cpu.flags.zf)
    {
        goto L_0x00492089;
    }
    // 0049207d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049207f  891d48ad4d00           -mov dword ptr [0x4dad48], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */) = cpu.ebx;
    // 00492085  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492086  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492087  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492088  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492089:
    // 00492089  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049208a  2eff1570444c00         -call dword ptr cs:[0x4c4470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998256) /* 0x4c4470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492091  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492093  891d48ad4d00           -mov dword ptr [0x4dad48], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */) = cpu.ebx;
    // 00492099  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049209a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049209b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049209c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4920a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004920a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004920a1  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004920a4  e807fbffff             -call 0x491bb0
    cpu.esp -= 4;
    sub_491bb0(app, cpu);
    if (cpu.terminate) return;
    // 004920a9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004920ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004920ad  7507                   -jne 0x4920b6
    if (!cpu.flags.zf)
    {
        goto L_0x004920b6;
    }
    // 004920af  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004920b1  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004920b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004920b6:
    // 004920b6  ff15c0c95600           -call dword ptr [0x56c9c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687744) /* 0x56c9c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004920bc  6884ca5600             -push 0x56ca84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687940 /*0x56ca84*/;
    cpu.esp -= 4;
    // 004920c1  ff15c4c95600           -call dword ptr [0x56c9c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687748) /* 0x56c9c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004920c7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004920c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004920cb  744f                   -je 0x49211c
    if (cpu.flags.zf)
    {
        goto L_0x0049211c;
    }
    // 004920cd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004920cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004920d0  ff1580ca5600           -call dword ptr [0x56ca80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687936) /* 0x56ca80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004920d6  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 004920d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004920db  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004920dd  7414                   -je 0x4920f3
    if (cpu.flags.zf)
    {
        goto L_0x004920f3;
    }
L_0x004920df:
    // 004920df  8a1404                 -mov dl, byte ptr [esp + eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 004920e2  fec2                   -inc dl
    (cpu.dl)++;
    // 004920e4  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004920ea  f68228cd4d0020         +test byte ptr [edx + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004920f1  7452                   -je 0x492145
    if (cpu.flags.zf)
    {
        goto L_0x00492145;
    }
L_0x004920f3:
    // 004920f3  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004920f5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004920f7  ba4cea4c00             -mov edx, 0x4cea4c
    cpu.edx = 5040716 /*0x4cea4c*/;
    // 004920fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004920fe  e88dfafeff             -call 0x481b90
    cpu.esp -= 4;
    sub_481b90(app, cpu);
    if (cpu.terminate) return;
    // 00492103  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492105  7c49                   -jl 0x492150
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492150;
    }
    // 00492107  ba4cea4c00             -mov edx, 0x4cea4c
    cpu.edx = 5040716 /*0x4cea4c*/;
    // 0049210c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049210e  e87dfafeff             -call 0x481b90
    cpu.esp -= 4;
    sub_481b90(app, cpu);
    if (cpu.terminate) return;
    // 00492113  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492115  7e40                   -jle 0x492157
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492157;
    }
    // 00492117  bb5f000000             -mov ebx, 0x5f
    cpu.ebx = 95 /*0x5f*/;
L_0x0049211c:
    // 0049211c  ff15c8c95600           -call dword ptr [0x56c9c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687752) /* 0x56c9c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492122  8b1548ad4d00           -mov edx, dword ptr [0x4dad48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 00492128  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049212a  7408                   -je 0x492134
    if (cpu.flags.zf)
    {
        goto L_0x00492134;
    }
    // 0049212c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049212d  2eff1570444c00         -call dword ptr cs:[0x4c4470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998256) /* 0x4c4470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00492134:
    // 00492134  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492135  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00492137  893548ad4d00           -mov dword ptr [0x4dad48], esi
    app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */) = cpu.esi;
    // 0049213d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049213e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00492140  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00492143  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492144  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492145:
    // 00492145  8a740401               -mov dh, byte ptr [esp + eax + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 00492149  40                     -inc eax
    (cpu.eax)++;
    // 0049214a  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0049214c  7591                   -jne 0x4920df
    if (!cpu.flags.zf)
    {
        goto L_0x004920df;
    }
    // 0049214e  eba3                   -jmp 0x4920f3
    goto L_0x004920f3;
L_0x00492150:
    // 00492150  bb5a000000             -mov ebx, 0x5a
    cpu.ebx = 90 /*0x5a*/;
    // 00492155  ebc5                   -jmp 0x49211c
    goto L_0x0049211c;
L_0x00492157:
    // 00492157  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0049215c  ebbe                   -jmp 0x49211c
    goto L_0x0049211c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492160  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00492164  8b1584ca5600           -mov edx, dword ptr [0x56ca84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5687940) /* 0x56ca84 */);
    // 0049216a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049216c  39d1                   +cmp ecx, edx
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
    // 0049216e  7c03                   -jl 0x492173
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492173;
    }
    // 00492170  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00492173:
    // 00492173  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492174  ff15ccc95600           -call dword ptr [0x56c9cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687756) /* 0x56c9cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049217a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049217f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492184(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492184  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492187  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00492189  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049218b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049218d:
    // 0049218d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00492190  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492193  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00492196  40                     -inc eax
    (cpu.eax)++;
    // 00492197  d99abcc55600           -fstp dword ptr [edx + 0x56c5bc]
    app->getMemory<float>(cpu.edx + x86::reg32(5686716) /* 0x56c5bc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049219d  3d00010000             +cmp eax, 0x100
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
    // 004921a2  7ce9                   -jl 0x49218d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049218d;
    }
    // 004921a4  e807faffff             -call 0x491bb0
    cpu.esp -= 4;
    sub_491bb0(app, cpu);
    if (cpu.terminate) return;
    // 004921a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004921ab  7506                   -jne 0x4921b3
    if (!cpu.flags.zf)
    {
        goto L_0x004921b3;
    }
L_0x004921ad:
    // 004921ad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004921af  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004921b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004921b3:
    // 004921b3  ff15c0c95600           -call dword ptr [0x56c9c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687744) /* 0x56c9c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004921b9  6884ca5600             -push 0x56ca84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687940 /*0x56ca84*/;
    cpu.esp -= 4;
    // 004921be  ff15c4c95600           -call dword ptr [0x56c9c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687748) /* 0x56c9c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004921c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004921c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004921c8  74e3                   -je 0x4921ad
    if (cpu.flags.zf)
    {
        goto L_0x004921ad;
    }
    // 004921ca  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004921cc  e88fffffff             -call 0x492160
    cpu.esp -= 4;
    sub_492160(app, cpu);
    if (cpu.terminate) return;
    // 004921d1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004921d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004921d5  74d6                   -je 0x4921ad
    if (cpu.flags.zf)
    {
        goto L_0x004921ad;
    }
    // 004921d7  8b0d84ca5600           -mov ecx, dword ptr [0x56ca84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5687940) /* 0x56ca84 */);
    // 004921dd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004921df  74cc                   -je 0x4921ad
    if (cpu.flags.zf)
    {
        goto L_0x004921ad;
    }
    // 004921e1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004921e6  b8fc214900             -mov eax, 0x4921fc
    cpu.eax = 4792828 /*0x4921fc*/;
    // 004921eb  891530ad4d00           -mov dword ptr [0x4dad30], edx
    app->getMemory<x86::reg32>(x86::reg32(5090608) /* 0x4dad30 */) = cpu.edx;
    // 004921f1  e849730100             -call 0x4a953f
    cpu.esp -= 4;
    sub_4a953f(app, cpu);
    if (cpu.terminate) return;
    // 004921f6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004921f8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004921fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4921fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004921fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004921fd  8b1530ad4d00           -mov edx, dword ptr [0x4dad30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090608) /* 0x4dad30 */);
    // 00492203  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00492208  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049220a  7504                   -jne 0x492210
    if (!cpu.flags.zf)
    {
        goto L_0x00492210;
    }
    // 0049220c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049220e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049220f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492210:
    // 00492210  ff15c8c95600           -call dword ptr [0x56c9c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687752) /* 0x56c9c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492216  8b0d48ad4d00           -mov ecx, dword ptr [0x4dad48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */);
    // 0049221c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049221e  7408                   -je 0x492228
    if (cpu.flags.zf)
    {
        goto L_0x00492228;
    }
    // 00492220  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492221  2eff1570444c00         -call dword ptr cs:[0x4c4470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998256) /* 0x4c4470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00492228:
    // 00492228  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492229  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049222b  893d48ad4d00           -mov dword ptr [0x4dad48], edi
    app->getMemory<x86::reg32>(x86::reg32(5090632) /* 0x4dad48 */) = cpu.edi;
    // 00492231  893d30ad4d00           -mov dword ptr [0x4dad30], edi
    app->getMemory<x86::reg32>(x86::reg32(5090608) /* 0x4dad30 */) = cpu.edi;
    // 00492237  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492238  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049223a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049223b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49223c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049223c  f60530ad4d0002         +test byte ptr [0x4dad30], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5090608) /* 0x4dad30 */) & 2 /*0x2*/));
    // 00492243  7501                   -jne 0x492246
    if (!cpu.flags.zf)
    {
        goto L_0x00492246;
    }
    // 00492245  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492246:
    // 00492246  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492247  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492248  ff15d0c95600           -call dword ptr [0x56c9d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5687760) /* 0x56c9d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049224e  802530ad4d00fd         -and byte ptr [0x4dad30], 0xfd
    app->getMemory<x86::reg8>(x86::reg32(5090608) /* 0x4dad30 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 00492255  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492256  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492257  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_492258(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
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

}
