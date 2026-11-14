#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_480be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480be0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480be1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480be3  3b05b8145600           +cmp eax, dword ptr [0x5614b8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641400) /* 0x5614b8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480be9  7428                   -je 0x480c13
    if (cpu.flags.zf)
    {
        goto L_0x00480c13;
    }
    // 00480beb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480bec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480bed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bee  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00480bf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480bf2  6bd600                 -imul edx, esi, 0
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
L_0x00480bf5:
    // 00480bf5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00480bf7  40                     -inc eax
    (cpu.eax)++;
    // 00480bf8  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00480bfb  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00480bfd  8888b3135600           -mov byte ptr [eax + 0x5613b3], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5641139) /* 0x5613b3 */) = cpu.cl;
    // 00480c03  3d00010000             +cmp eax, 0x100
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
    // 00480c08  7ceb                   -jl 0x480bf5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480bf5;
    }
    // 00480c0a  8935b8145600           -mov dword ptr [0x5614b8], esi
    app->getMemory<x86::reg32>(x86::reg32(5641400) /* 0x5614b8 */) = cpu.esi;
    // 00480c10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00480c13:
    // 00480c13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480c18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480c19  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480c1b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00480c1d  8a9bb4135600           -mov bl, byte ptr [ebx + 0x5613b4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5641140) /* 0x5613b4 */);
    // 00480c23  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00480c25  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480c27  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00480c2a  8a9bb4135600           -mov bl, byte ptr [ebx + 0x5613b4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5641140) /* 0x5613b4 */);
    // 00480c30  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00480c33  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480c35  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00480c38  8a9bb4135600           -mov bl, byte ptr [ebx + 0x5613b4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5641140) /* 0x5613b4 */);
    // 00480c3e  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00480c41  8a4003                 -mov al, byte ptr [eax + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00480c44  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480c49  8a80b4135600           -mov al, byte ptr [eax + 0x5613b4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5641140) /* 0x5613b4 */);
    // 00480c4f  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00480c52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480c54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480c55  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480c58  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480c5a  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00480c5c  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00480c5f  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00480c62  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00480c65  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00480c68  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00480c6a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480c6c  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00480c6f  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00480c72  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00480c75  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00480c78  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00480c7b  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00480c7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480c80  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00480c83  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00480c86  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00480c89  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00480c8c  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00480c8f  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 00480c92  8a4003                 -mov al, byte ptr [eax + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00480c95  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480c9a  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00480c9d  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00480ca0  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00480ca3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480ca6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ca7  90                     -nop 
    ;
    // 00480ca8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480cac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480cad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480cae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480caf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480cb0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00480cb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480cb5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00480cb7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00480cb9:
    // 00480cb9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480cbb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480cbd  e856ffffff             -call 0x480c18
    cpu.esp -= 4;
    sub_480c18(app, cpu);
    if (cpu.terminate) return;
    // 00480cc2  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00480cc4  8a742402               -mov dh, byte ptr [esp + 2]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00480cc8  8a642403               -mov ah, byte ptr [esp + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 00480ccc  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 00480ccf  28e0                   -sub al, ah
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.ah));
    // 00480cd1  8a542401               -mov dl, byte ptr [esp + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00480cd5  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 00480cd9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00480cdb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480ce0  e83b550100             -call 0x496220
    cpu.esp -= 4;
    sub_496220(app, cpu);
    if (cpu.terminate) return;
    // 00480ce5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00480ce7  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 00480cea  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480cf0  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00480cf4  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00480cf8  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480cfc  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 00480cff  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480d05  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480d09  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00480d0d  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 00480d11  8a7c2408               -mov bh, byte ptr [esp + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480d15  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00480d17  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480d1c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00480d20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480d22  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480d26  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00480d2a  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00480d2d  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00480d30  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00480d34  0fb6ee                 -movzx ebp, dh
    cpu.ebp = x86::reg32(cpu.dh);
    // 00480d37  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00480d3b  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00480d3f  0fb6ef                 -movzx ebp, bh
    cpu.ebp = x86::reg32(cpu.bh);
    // 00480d42  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00480d45  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00480d48  8a742408               -mov dh, byte ptr [esp + 8]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480d4c  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00480d50  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 00480d53  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00480d57  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00480d5b  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00480d60  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00480d63  8a542408               -mov dl, byte ptr [esp + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480d67  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00480d6a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480d70  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480d72  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480d74  88f0                   -mov al, dh
    cpu.al = cpu.dh;
    // 00480d76  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00480d79  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480d7f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00480d82  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00480d84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480d86  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00480d88  46                     -inc esi
    (cpu.esi)++;
    // 00480d89  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00480d8b  83c104                 +add ecx, 4
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
    // 00480d8e  e849fdffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 00480d93  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00480d96  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480d97  0f851cffffff           -jne 0x480cb9
    if (!cpu.flags.zf)
    {
        goto L_0x00480cb9;
    }
    // 00480d9d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00480da0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480da1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480da2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480da3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480da4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480da8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480da8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480da9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480daa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480dab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480dac  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480daf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00480db1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00480db3  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00480db5:
    // 00480db5  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480db7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00480db9  e85afeffff             -call 0x480c18
    cpu.esp -= 4;
    sub_480c18(app, cpu);
    if (cpu.terminate) return;
    // 00480dbe  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00480dc1  81fb00000010           +cmp ebx, 0x10000000
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
    // 00480dc7  7273                   -jb 0x480e3c
    if (cpu.flags.cf)
    {
        goto L_0x00480e3c;
    }
    // 00480dc9  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00480dcf  7348                   -jae 0x480e19
    if (!cpu.flags.cf)
    {
        goto L_0x00480e19;
    }
    // 00480dd1  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00480dd4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480dd6  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 00480ddb  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 00480dde  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00480de0  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00480de6  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00480de9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480deb  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00480dee  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00480df0  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00480df2  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00480df5  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480dfb  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00480dfd  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00480e00  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480e02  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480e04  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00480e07  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480e0d  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480e0f  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00480e12  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00480e17  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00480e19:
    // 00480e19  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480e1b  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00480e21  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00480e24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480e26  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00480e29  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00480e2f  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00480e32  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00480e35  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480e37  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480e39  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00480e3c:
    // 00480e3c  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00480e3f  83c704                 +add edi, 4
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
    // 00480e42  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480e43  0f856cffffff           -jne 0x480db5
    if (!cpu.flags.zf)
    {
        goto L_0x00480db5;
    }
    // 00480e49  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480e4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480e54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480e54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480e55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480e56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480e57  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480e58  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480e5b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00480e5d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00480e5f  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00480e61:
    // 00480e61  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480e63  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00480e65  e8aefdffff             -call 0x480c18
    cpu.esp -= 4;
    sub_480c18(app, cpu);
    if (cpu.terminate) return;
    // 00480e6a  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00480e6d  81fb00000010           +cmp ebx, 0x10000000
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
    // 00480e73  726b                   -jb 0x480ee0
    if (cpu.flags.cf)
    {
        goto L_0x00480ee0;
    }
    // 00480e75  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00480e7b  7340                   -jae 0x480ebd
    if (!cpu.flags.cf)
    {
        goto L_0x00480ebd;
    }
    // 00480e7d  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00480e80  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00480e82  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480e84  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00480e87  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00480e8a  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00480e8c  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00480e92  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00480e95  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00480e9a  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00480e9d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480e9f  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00480ea1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00480ea4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480ea6  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00480ea9  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480eab  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00480eae  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480eb4  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00480eb9  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00480ebb  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00480ebd:
    // 00480ebd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480ebf  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00480ec5  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00480ec8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480eca  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00480ecd  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00480ed3  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00480ed6  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00480ed9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480edb  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480edd  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00480ee0:
    // 00480ee0  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00480ee3  83c704                 +add edi, 4
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
    // 00480ee6  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480ee7  0f8574ffffff           -jne 0x480e61
    if (!cpu.flags.zf)
    {
        goto L_0x00480e61;
    }
    // 00480eed  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480ef0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ef1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ef2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ef3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ef4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480ef8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480ef8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480ef9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480efa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480efb  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00480efe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480f00  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x00480f02:
    // 00480f02  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480f04  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480f06  e80dfdffff             -call 0x480c18
    cpu.esp -= 4;
    sub_480c18(app, cpu);
    if (cpu.terminate) return;
    // 00480f0b  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00480f0d  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00480f10  8a642403               -mov ah, byte ptr [esp + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 00480f14  88542410               -mov byte ptr [esp + 0x10], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 00480f18  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00480f1a  28e0                   -sub al, ah
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.ah));
    // 00480f1c  88542414               -mov byte ptr [esp + 0x14], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dl;
    // 00480f20  8a6102                 -mov ah, byte ptr [ecx + 2]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00480f23  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480f25  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00480f27  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480f2c  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00480f2f  0fb67c2402             -movzx edi, byte ptr [esp + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */));
    // 00480f34  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00480f37  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480f39  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00480f3d  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480f41  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00480f45  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480f47  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00480f4b  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00480f4e  0fb67c2401             -movzx edi, byte ptr [esp + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */));
    // 00480f53  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00480f56  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480f58  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00480f5c  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480f60  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00480f64  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480f66  8a542414               -mov dl, byte ptr [esp + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00480f6a  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00480f6d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480f6f  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00480f72  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00480f75  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480f77  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00480f7a  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480f7e  8861ff                 -mov byte ptr [ecx - 1], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 00480f81  8a64240c               -mov ah, byte ptr [esp + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00480f85  8861fe                 -mov byte ptr [ecx - 2], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ah;
    // 00480f88  83c604                 +add esi, 4
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
    // 00480f8b  8841fd                 -mov byte ptr [ecx - 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 00480f8e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480f8f  0f856dffffff           -jne 0x480f02
    if (!cpu.flags.zf)
    {
        goto L_0x00480f02;
    }
    // 00480f95  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00480f98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480f9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480f9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480f9d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480f9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480f9f  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00480fa2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480fa4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x00480fa6:
    // 00480fa6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480fa8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480faa  e869fcffff             -call 0x480c18
    cpu.esp -= 4;
    sub_480c18(app, cpu);
    if (cpu.terminate) return;
    // 00480faf  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 00480fb1  2a642403               -sub ah, byte ptr [esp + 3]
    (cpu.ah) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */)));
    // 00480fb5  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00480fb8  88542410               -mov byte ptr [esp + 0x10], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 00480fbc  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00480fbe  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00480fc1  88542414               -mov byte ptr [esp + 0x14], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dl;
    // 00480fc5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480fc7  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00480fc9  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00480fcb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480fd0  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00480fd3  0fb67c2402             -movzx edi, byte ptr [esp + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */));
    // 00480fd8  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00480fdb  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480fdd  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00480fe1  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480fe5  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00480fe9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480feb  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00480fef  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00480ff2  0fb67c2401             -movzx edi, byte ptr [esp + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */));
    // 00480ff7  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00480ffa  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480ffc  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00481000  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481004  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00481008  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048100a  8a542414               -mov dl, byte ptr [esp + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048100e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00481011  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481013  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00481016  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00481019  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048101c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048101e  c641ffff               -mov byte ptr [ecx - 1], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = 255 /*0xff*/;
    // 00481022  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481026  8861fe                 -mov byte ptr [ecx - 2], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ah;
    // 00481029  8a64240c               -mov ah, byte ptr [esp + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048102d  8861fd                 -mov byte ptr [ecx - 3], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-3) /* -0x3 */) = cpu.ah;
    // 00481030  83c604                 +add esi, 4
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
    // 00481033  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 00481036  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481037  0f8569ffffff           -jne 0x480fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00480fa6;
    }
    // 0048103d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00481040  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481041  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481042  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481043  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481044(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481044  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481045  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481046  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481047  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481048  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048104a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048104c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0048104e:
    // 0048104e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481050  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00481053  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048105a  8b1db4145600           -mov ebx, dword ptr [0x5614b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641396) /* 0x5614b4 */);
    // 00481060  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00481063  45                     -inc ebp
    (cpu.ebp)++;
    // 00481064  81fb00000010           +cmp ebx, 0x10000000
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
    // 0048106a  726b                   -jb 0x4810d7
    if (cpu.flags.cf)
    {
        goto L_0x004810d7;
    }
    // 0048106c  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00481072  7340                   -jae 0x4810b4
    if (!cpu.flags.cf)
    {
        goto L_0x004810b4;
    }
    // 00481074  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00481077  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00481079  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048107b  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0048107e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00481081  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00481083  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00481089  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0048108c  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00481091  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00481094  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481096  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00481098  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048109b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048109d  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004810a0  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004810a2  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004810a5  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004810ab  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004810b0  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004810b2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004810b4:
    // 004810b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004810b6  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004810bc  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004810bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004810c1  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004810c4  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004810ca  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004810cd  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004810d0  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004810d2  01d3                   +add ebx, edx
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
    // 004810d4  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004810d7:
    // 004810d7  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004810da  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004810db  0f856dffffff           -jne 0x48104e
    if (!cpu.flags.zf)
    {
        goto L_0x0048104e;
    }
    // 004810e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4810e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004810e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004810e9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004810ea  81ec08040000           -sub esp, 0x408
    (cpu.esp) -= x86::reg32(x86::sreg32(1032 /*0x408*/));
    // 004810f0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004810f2  89942400040000         -mov dword ptr [esp + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.edx;
    // 004810f9  899c2404040000         -mov dword ptr [esp + 0x404], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */) = cpu.ebx;
    // 00481100  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00481102  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00481104  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00481107  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 0048110d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048110f  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 00481114  8915988b4d00           -mov dword ptr [0x4d8b98], edx
    app->getMemory<x86::reg32>(x86::reg32(5082008) /* 0x4d8b98 */) = cpu.edx;
    // 0048111a  890da08b4d00           -mov dword ptr [0x4d8ba0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5082016) /* 0x4d8ba0 */) = cpu.ecx;
    // 00481120  83f808                 +cmp eax, 8
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
    // 00481123  0f8593000000           -jne 0x4811bc
    if (!cpu.flags.zf)
    {
        goto L_0x004811bc;
    }
    // 00481129  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
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
    // 00481130  0f8586000000           -jne 0x4811bc
    if (!cpu.flags.zf)
    {
        goto L_0x004811bc;
    }
    // 00481136  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481137  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048113b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048113d  e8f63a0100             -call 0x494c38
    cpu.esp -= 4;
    sub_494c38(app, cpu);
    if (cpu.terminate) return;
    // 00481142  a3b4145600             -mov dword ptr [0x5614b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5641396) /* 0x5614b4 */) = cpu.eax;
    // 00481147  81ffff000000           +cmp edi, 0xff
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
    // 0048114d  7d33                   -jge 0x481182
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481182;
    }
    // 0048114f  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481153  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00481155:
    // 00481155  8b15b4145600           -mov edx, dword ptr [0x5614b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641396) /* 0x5614b4 */);
    // 0048115b  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00481162  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00481164  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481166  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00481168  41                     -inc ecx
    (cpu.ecx)++;
    // 00481169  e8e6faffff             -call 0x480c54
    cpu.esp -= 4;
    sub_480c54(app, cpu);
    if (cpu.terminate) return;
    // 0048116e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481171  81f900010000           +cmp ecx, 0x100
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
    // 00481177  7cdc                   -jl 0x481155
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481155;
    }
    // 00481179  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048117d  a3b4145600             -mov dword ptr [0x5614b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5641396) /* 0x5614b4 */) = cpu.eax;
L_0x00481182:
    // 00481182  bb44104800             -mov ebx, 0x481044
    cpu.ebx = 4722756 /*0x481044*/;
    // 00481187  be7b000000             -mov esi, 0x7b
    cpu.esi = 123 /*0x7b*/;
    // 0048118c  891d988b4d00           -mov dword ptr [0x4d8b98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5082008) /* 0x4d8b98 */) = cpu.ebx;
    // 00481192  8935a08b4d00           -mov dword ptr [0x4d8ba0], esi
    app->getMemory<x86::reg32>(x86::reg32(5082016) /* 0x4d8ba0 */) = cpu.esi;
    // 00481198  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481199:
    // 00481199  b9808b4d00             -mov ecx, 0x4d8b80
    cpu.ecx = 5081984 /*0x4d8b80*/;
    // 0048119e  8b9c2404040000         -mov ebx, dword ptr [esp + 0x404]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */);
    // 004811a5  8b942400040000         -mov edx, dword ptr [esp + 0x400]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 004811ac  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004811ae  e879ba0100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 004811b3  81c408040000           +add esp, 0x408
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
    // 004811b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004811bc:
    // 004811bc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004811be  e81dfaffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004811c3  ebd4                   -jmp 0x481199
    goto L_0x00481199;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4811c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004811c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004811c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004811ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004811cb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004811cd  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004811d0  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004811d3  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 004811d6  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004811d9  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 004811dc  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004811df  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004811e1  e802ffffff             -call 0x4810e8
    cpu.esp -= 4;
    sub_4810e8(app, cpu);
    if (cpu.terminate) return;
    // 004811e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4811ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004811ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004811ed  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004811f0  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004811f3  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004811f5  8b7006                 -mov esi, dword ptr [eax + 6]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004811f8  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004811fb  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004811fd  e8e6feffff             -call 0x4810e8
    cpu.esp -= 4;
    sub_4810e8(app, cpu);
    if (cpu.terminate) return;
    // 00481202  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481203  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481210  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481212  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481213  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481214  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481216  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00481219  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048121b  7527                   -jne 0x481244
    if (!cpu.flags.zf)
    {
        goto L_0x00481244;
    }
L_0x0048121d:
    // 0048121d  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00481220  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481222  7407                   -je 0x48122b
    if (cpu.flags.zf)
    {
        goto L_0x0048122b;
    }
    // 00481224  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481226  e8614f0100             -call 0x49618c
    cpu.esp -= 4;
    sub_49618c(app, cpu);
    if (cpu.terminate) return;
L_0x0048122b:
    // 0048122b  8b7130                 -mov esi, dword ptr [ecx + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0048122e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00481230  751e                   -jne 0x481250
    if (!cpu.flags.zf)
    {
        goto L_0x00481250;
    }
    // 00481232  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481234  c7016b4e4957           -mov dword ptr [ecx], 0x57494e6b
    app->getMemory<x86::reg32>(cpu.ecx) = 1464421995 /*0x57494e6b*/;
    // 0048123a  e82d1b0000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0048123f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481240  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481241  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481243  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481244:
    // 00481244  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 00481249  e8eabd0000             -call 0x48d038
    cpu.esp -= 4;
    sub_48d038(app, cpu);
    if (cpu.terminate) return;
    // 0048124e  ebcd                   -jmp 0x48121d
    goto L_0x0048121d;
L_0x00481250:
    // 00481250  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481252  e8354f0100             -call 0x49618c
    cpu.esp -= 4;
    sub_49618c(app, cpu);
    if (cpu.terminate) return;
    // 00481257  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481259  c7016b4e4957           -mov dword ptr [ecx], 0x57494e6b
    app->getMemory<x86::reg32>(cpu.ecx) = 1464421995 /*0x57494e6b*/;
    // 0048125f  e8081b0000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00481264  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481265  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481266  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481267  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481268  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481270  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481271  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481273  7c49                   -jl 0x4812be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004812be;
    }
L_0x00481275:
    // 00481275  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481277  7c49                   -jl 0x4812c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004812c2;
    }
L_0x00481279:
    // 00481279  8b3560904d00           -mov esi, dword ptr [0x4d9060]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083232) /* 0x4d9060 */);
    // 0048127f  39f0                   +cmp eax, esi
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
    // 00481281  7e02                   -jle 0x481285
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481285;
    }
    // 00481283  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00481285:
    // 00481285  39f3                   +cmp ebx, esi
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
    // 00481287  7e02                   -jle 0x48128b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048128b;
    }
    // 00481289  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x0048128b:
    // 0048128b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048128d  7c37                   -jl 0x4812c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004812c6;
    }
L_0x0048128f:
    // 0048128f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481291  7c37                   -jl 0x4812ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004812ca;
    }
L_0x00481293:
    // 00481293  8b3564904d00           -mov esi, dword ptr [0x4d9064]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083236) /* 0x4d9064 */);
    // 00481299  39f2                   +cmp edx, esi
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
    // 0048129b  7e02                   -jle 0x48129f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048129f;
    }
    // 0048129d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0048129f:
    // 0048129f  39f1                   +cmp ecx, esi
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
    // 004812a1  7e02                   -jle 0x4812a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004812a5;
    }
    // 004812a3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004812a5:
    // 004812a5  a368904d00             -mov dword ptr [0x4d9068], eax
    app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */) = cpu.eax;
    // 004812aa  891d70904d00           -mov dword ptr [0x4d9070], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */) = cpu.ebx;
    // 004812b0  89156c904d00           -mov dword ptr [0x4d906c], edx
    app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */) = cpu.edx;
    // 004812b6  890d74904d00           -mov dword ptr [0x4d9074], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */) = cpu.ecx;
    // 004812bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004812bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004812be:
    // 004812be  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004812c0  ebb3                   -jmp 0x481275
    goto L_0x00481275;
L_0x004812c2:
    // 004812c2  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004812c4  ebb3                   -jmp 0x481279
    goto L_0x00481279;
L_0x004812c6:
    // 004812c6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004812c8  ebc5                   -jmp 0x48128f
    goto L_0x0048128f;
L_0x004812ca:
    // 004812ca  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004812cc  ebc5                   -jmp 0x481293
    goto L_0x00481293;
}

/* align: skip 0x00 0x00 */
void Application::sub_4812d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004812d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004812d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004812d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004812d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004812d4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004812d6  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004812d8  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004812da  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004812dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004812df  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004812e1  7e10                   -jle 0x4812f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004812f3;
    }
L_0x004812e3:
    // 004812e3  3b5810                 +cmp ebx, dword ptr [eax + 0x10]
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
    // 004812e6  7416                   -je 0x4812fe
    if (cpu.flags.zf)
    {
        goto L_0x004812fe;
    }
    // 004812e8  42                     -inc edx
    (cpu.edx)++;
    // 004812e9  8b6908                 -mov ebp, dword ptr [ecx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004812ec  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004812ef  39ea                   +cmp edx, ebp
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
    // 004812f1  7cf0                   -jl 0x4812e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004812e3;
    }
L_0x004812f3:
    // 004812f3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004812f5  7511                   -jne 0x481308
    if (!cpu.flags.zf)
    {
        goto L_0x00481308;
    }
    // 004812f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004812f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004812fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004812fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004812fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004812fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004812fe:
    // 004812fe  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00481301  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00481303  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481304  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481305  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481306  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481307  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481308:
    // 00481308  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048130a  e801200000             -call 0x483310
    cpu.esp -= 4;
    sub_483310(app, cpu);
    if (cpu.terminate) return;
    // 0048130f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481311  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481312  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481313  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481314  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481315  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481318(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481318  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481319  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048131b  e8b0ffffff             -call 0x4812d0
    cpu.esp -= 4;
    sub_4812d0(app, cpu);
    if (cpu.terminate) return;
    // 00481320  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481321  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481324(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481324  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481325  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048132a  e8a1ffffff             -call 0x4812d0
    cpu.esp -= 4;
    sub_4812d0(app, cpu);
    if (cpu.terminate) return;
    // 0048132f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481330  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481340  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481344(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481344  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481345  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481346  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481347  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481348  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048134b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048134d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048134f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00481351:
    // 00481351  80790300               +cmp byte ptr [ecx + 3], 0
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
    // 00481355  750f                   -jne 0x481366
    if (!cpu.flags.zf)
    {
        goto L_0x00481366;
    }
    // 00481357  83c104                 +add ecx, 4
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
    // 0048135a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048135b  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048135c  75f3                   -jne 0x481351
    if (!cpu.flags.zf)
    {
        goto L_0x00481351;
    }
    // 0048135e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481361  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481362  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481363  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481364  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481365  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481366:
    // 00481366  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00481368  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048136d  e8ae4e0100             -call 0x496220
    cpu.esp -= 4;
    sub_496220(app, cpu);
    if (cpu.terminate) return;
    // 00481372  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481374  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 00481379  0f84a8000000           -je 0x481427
    if (cpu.flags.zf)
    {
        goto L_0x00481427;
    }
    // 0048137f  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 00481381  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00481383  8a5903                 -mov bl, byte ptr [ecx + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 00481386  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 00481389  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0048138c  28de                   -sub dh, bl
    (cpu.dh) -= x86::reg8(x86::sreg8(cpu.bl));
    // 0048138e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00481393  8a5902                 -mov bl, byte ptr [ecx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00481396  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048139c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048139f  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004813a1  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004813a4  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004813a7  887c240c               -mov byte ptr [esp + 0xc], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bh;
    // 004813ab  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 004813ae  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 004813b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004813b4  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 004813b6  88742404               -mov byte ptr [esp + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dh;
    // 004813ba  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004813bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004813bf  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004813c2  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004813c6  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004813c9  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004813cc  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 004813cf  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 004813d3  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004813d9  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004813db  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004813e0  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004813e3  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 004813e6  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004813e8  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004813ee  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004813f0  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004813f5  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004813f8  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004813fb  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004813fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481400  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00481403  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00481407  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00481409  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0048140d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048140f  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00481411  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481413  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481415  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00481418  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0048141a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048141c  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0048141f  8a54240c               -mov dl, byte ptr [esp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00481423  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481425  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00481427:
    // 00481427  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481429  e8aef6ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048142e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00481430  83c104                 +add ecx, 4
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
    // 00481433  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00481434  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481435  0f8516ffffff           -jne 0x481351
    if (!cpu.flags.zf)
    {
        goto L_0x00481351;
    }
    // 0048143b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048143e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048143f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481440  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481441  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481442  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481444(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481444  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481445  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481446  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481447  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481448  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048144a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048144c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0048144e:
    // 0048144e  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00481450  81fb00000010           +cmp ebx, 0x10000000
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
    // 00481456  7273                   -jb 0x4814cb
    if (cpu.flags.cf)
    {
        goto L_0x004814cb;
    }
    // 00481458  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0048145e  7348                   -jae 0x4814a8
    if (!cpu.flags.cf)
    {
        goto L_0x004814a8;
    }
    // 00481460  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00481463  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481465  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0048146a  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0048146d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048146f  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00481475  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00481478  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048147a  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0048147d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048147f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00481481  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00481484  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048148a  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0048148c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048148f  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481491  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481493  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00481496  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048149c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048149e  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004814a1  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004814a6  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004814a8:
    // 004814a8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004814aa  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004814b0  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004814b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004814b5  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004814b8  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004814be  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004814c1  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004814c4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004814c6  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004814c8  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004814cb:
    // 004814cb  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004814ce  83c704                 +add edi, 4
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
    // 004814d1  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004814d2  0f8576ffffff           -jne 0x48144e
    if (!cpu.flags.zf)
    {
        goto L_0x0048144e;
    }
    // 004814d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4814e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004814e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004814e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004814e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004814e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004814e4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004814e6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004814e8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x004814ea:
    // 004814ea  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004814ec  81fb00000010           +cmp ebx, 0x10000000
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
    // 004814f2  726b                   -jb 0x48155f
    if (cpu.flags.cf)
    {
        goto L_0x0048155f;
    }
    // 004814f4  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004814fa  7340                   -jae 0x48153c
    if (!cpu.flags.cf)
    {
        goto L_0x0048153c;
    }
    // 004814fc  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004814ff  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00481501  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481503  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00481506  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00481509  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0048150b  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00481511  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00481514  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00481519  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0048151c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048151e  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00481520  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00481523  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481525  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00481528  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048152a  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0048152d  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00481533  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00481538  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048153a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0048153c:
    // 0048153c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048153e  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00481544  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00481547  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481549  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0048154c  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00481552  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00481555  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00481558  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048155a  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048155c  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0048155f:
    // 0048155f  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00481562  83c704                 +add edi, 4
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
    // 00481565  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481566  7582                   -jne 0x4814ea
    if (!cpu.flags.zf)
    {
        goto L_0x004814ea;
    }
    // 00481568  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481569  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048156a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048156b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048156c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481570  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481571  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481572  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481573  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481574  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481577  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00481579:
    // 00481579  80780300               +cmp byte ptr [eax + 3], 0
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
    // 0048157d  7511                   -jne 0x481590
    if (!cpu.flags.zf)
    {
        goto L_0x00481590;
    }
L_0x0048157f:
    // 0048157f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481582  83c203                 +add edx, 3
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
    // 00481585  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481586  75f1                   -jne 0x481579
    if (!cpu.flags.zf)
    {
        goto L_0x00481579;
    }
    // 00481588  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048158b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048158c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048158d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048158e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048158f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481590:
    // 00481590  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00481593  b3ff                   -mov bl, 0xff
    cpu.bl = 255 /*0xff*/;
    // 00481595  8a6a02                 -mov ch, byte ptr [edx + 2]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00481598  8a7803                 -mov bh, byte ptr [eax + 3]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0048159b  886c2410               -mov byte ptr [esp + 0x10], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ch;
    // 0048159f  28fb                   -sub bl, bh
    (cpu.bl) -= x86::reg8(x86::sreg8(cpu.bh));
    // 004815a1  0fb6742410             -movzx esi, byte ptr [esp + 0x10]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004815a6  885c240c               -mov byte ptr [esp + 0xc], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 004815aa  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004815ad  0fb674240c             -movzx esi, byte ptr [esp + 0xc]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004815b2  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004815b5  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004815b8  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004815bb  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 004815be  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004815c0  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004815c3  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 004815c6  8a6a01                 -mov ch, byte ptr [edx + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004815c9  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004815cc  886c2408               -mov byte ptr [esp + 8], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ch;
    // 004815d0  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004815d3  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004815d8  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004815db  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 004815dd  886c2404               -mov byte ptr [esp + 4], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ch;
    // 004815e1  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 004815e4  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 004815e7  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004815ed  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004815ef  0fb66c2404             -movzx ebp, byte ptr [esp + 4]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 004815f4  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004815f7  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 004815fa  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004815fd  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00481600  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 00481603  01f5                   +add ebp, esi
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
    // 00481605  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00481608  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0048160b  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 0048160e  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00481611  883a                   -mov byte ptr [edx], bh
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
    // 00481613  e967ffffff             -jmp 0x48157f
    goto L_0x0048157f;
}

/* align: skip  */
void Application::sub_481618(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481618  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481619  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048161a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048161b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048161c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048161f  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x00481621:
    // 00481621  80780300               +cmp byte ptr [eax + 3], 0
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
    // 00481625  7511                   -jne 0x481638
    if (!cpu.flags.zf)
    {
        goto L_0x00481638;
    }
L_0x00481627:
    // 00481627  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048162a  83c204                 +add edx, 4
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
    // 0048162d  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048162e  75f1                   -jne 0x481621
    if (!cpu.flags.zf)
    {
        goto L_0x00481621;
    }
    // 00481630  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00481633  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481634  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481635  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481636  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481637  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481638:
    // 00481638  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048163b  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048163e  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 00481642  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 00481644  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
    // 00481648  807a0300               +cmp byte ptr [edx + 3], 0
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
    // 0048164c  0f84a1000000           -je 0x4816f3
    if (cpu.flags.zf)
    {
        goto L_0x004816f3;
    }
    // 00481652  b7ff                   -mov bh, 0xff
    cpu.bh = 255 /*0xff*/;
    // 00481654  2a7803                 -sub bh, byte ptr [eax + 3]
    (cpu.bh) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */)));
    // 00481657  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0048165a  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 0048165c  887c2408               -mov byte ptr [esp + 8], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.bh;
    // 00481660  886c240c               -mov byte ptr [esp + 0xc], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ch;
    // 00481664  0fb6f9                 -movzx edi, cl
    cpu.edi = x86::reg32(cpu.cl);
    // 00481667  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481669  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048166d  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00481670  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00481673  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 00481676  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 00481679  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048167b  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0048167f  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481683  0fb6ff                 -movzx edi, bh
    cpu.edi = x86::reg32(cpu.bh);
    // 00481686  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00481689  0fb66c2414             -movzx ebp, byte ptr [esp + 0x14]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0048168e  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 00481691  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00481693  0fb67c240c             -movzx edi, byte ptr [esp + 0xc]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00481698  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048169b  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 0048169e  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004816a2  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004816a5  0fb67c2410             -movzx edi, byte ptr [esp + 0x10]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004816aa  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004816ad  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004816af  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004816b2  0fb67a03               -movzx edi, byte ptr [edx + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */));
    // 004816b6  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004816bb  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004816bd  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004816c0  8a7c2404               -mov bh, byte ptr [esp + 4]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004816c4  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
    // 004816c9  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004816cc  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 004816d0  29cf                   +sub edi, ecx
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
    // 004816d2  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 004816d5  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004816d7  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
L_0x004816db:
    // 004816db  884a03                 -mov byte ptr [edx + 3], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 004816de  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004816e1  8a5c2414               -mov bl, byte ptr [esp + 0x14]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004816e5  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004816e8  8a5c2410               -mov bl, byte ptr [esp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004816ec  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004816ee  e934ffffff             -jmp 0x481627
    goto L_0x00481627;
L_0x004816f3:
    // 004816f3  8a4803                 -mov cl, byte ptr [eax + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004816f6  ebe3                   -jmp 0x4816db
    goto L_0x004816db;
}

/* align: skip  */
void Application::sub_4816f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004816f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004816f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004816fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004816fb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004816fc  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004816fe  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00481700  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00481702:
    // 00481702  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481704  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00481707  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048170e  8b1dbc145600           -mov ebx, dword ptr [0x5614bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641404) /* 0x5614bc */);
    // 00481714  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00481717  45                     -inc ebp
    (cpu.ebp)++;
    // 00481718  81fb00000010           +cmp ebx, 0x10000000
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
    // 0048171e  7250                   -jb 0x481770
    if (cpu.flags.cf)
    {
        goto L_0x00481770;
    }
    // 00481720  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00481726  7345                   -jae 0x48176d
    if (!cpu.flags.cf)
    {
        goto L_0x0048176d;
    }
    // 00481728  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048172a  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0048172d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048172f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481731  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00481734  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00481737  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00481739  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0048173f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00481742  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00481747  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0048174a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048174c  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0048174e  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00481751  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481753  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00481756  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0048175c  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0048175f  25e0070000             -and eax, 0x7e0
    cpu.eax &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00481764  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481766  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00481769  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048176b  01cb                   +add ebx, ecx
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
L_0x0048176d:
    // 0048176d  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00481770:
    // 00481770  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00481773  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481774  758c                   -jne 0x481702
    if (!cpu.flags.zf)
    {
        goto L_0x00481702;
    }
    // 00481776  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481777  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481778  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481779  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048177a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48177c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048177c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048177d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048177e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048177f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481780  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00481786  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481788  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048178a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048178c  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048178f  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 00481795  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481797  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 0048179c  8915bc8b4d00           -mov dword ptr [0x4d8bbc], edx
    app->getMemory<x86::reg32>(x86::reg32(5082044) /* 0x4d8bbc */) = cpu.edx;
    // 004817a2  890dc48b4d00           -mov dword ptr [0x4d8bc4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5082052) /* 0x4d8bc4 */) = cpu.ecx;
    // 004817a8  83f808                 +cmp eax, 8
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
    // 004817ab  752c                   -jne 0x4817d9
    if (!cpu.flags.zf)
    {
        goto L_0x004817d9;
    }
    // 004817ad  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
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
    // 004817b4  7523                   -jne 0x4817d9
    if (!cpu.flags.zf)
    {
        goto L_0x004817d9;
    }
    // 004817b6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004817b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004817ba  bdf8164800             -mov ebp, 0x4816f8
    cpu.ebp = 4724472 /*0x4816f8*/;
    // 004817bf  e83c360100             -call 0x494e00
    cpu.esp -= 4;
    sub_494e00(app, cpu);
    if (cpu.terminate) return;
    // 004817c4  a3bc145600             -mov dword ptr [0x5614bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5641404) /* 0x5614bc */) = cpu.eax;
    // 004817c9  b87b000000             -mov eax, 0x7b
    cpu.eax = 123 /*0x7b*/;
    // 004817ce  892dbc8b4d00           -mov dword ptr [0x4d8bbc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5082044) /* 0x4d8bbc */) = cpu.ebp;
    // 004817d4  a3c48b4d00             -mov dword ptr [0x4d8bc4], eax
    app->getMemory<x86::reg32>(x86::reg32(5082052) /* 0x4d8bc4 */) = cpu.eax;
L_0x004817d9:
    // 004817d9  b9a48b4d00             -mov ecx, 0x4d8ba4
    cpu.ecx = 5082020 /*0x4d8ba4*/;
    // 004817de  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004817e0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004817e2  e845b40100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 004817e7  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004817ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4817f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004817f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004817f5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004817f6  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004817f9  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004817fc  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004817ff  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00481802  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00481805  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00481808  e86fffffff             -call 0x48177c
    cpu.esp -= 4;
    sub_48177c(app, cpu);
    if (cpu.terminate) return;
    // 0048180d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048180e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048180f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481810  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481811  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00481814  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00481817  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481819  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0048181c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048181f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481821  e856ffffff             -call 0x48177c
    cpu.esp -= 4;
    sub_48177c(app, cpu);
    if (cpu.terminate) return;
    // 00481826  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481827  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481828(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481828  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0048182d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48182e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048182e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00481830  0305c4155600           -add eax, dword ptr [0x5615c4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */)));
    // 00481836  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481837(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481837  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481838  8b15cc8b4d00           -mov edx, dword ptr [0x4d8bcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082060) /* 0x4d8bcc */);
    // 0048183e  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 00481843  a3cc8b4d00             -mov dword ptr [0x4d8bcc], eax
    app->getMemory<x86::reg32>(x86::reg32(5082060) /* 0x4d8bcc */) = cpu.eax;
    // 00481848  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048184a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048184b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48184c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048184c  c705c415560000000000   -mov dword ptr [0x5615c4], 0
    app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */) = 0 /*0x0*/;
    // 00481856  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481857(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481857  0305c4155600           -add eax, dword ptr [0x5615c4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */)));
    // 0048185d  a3c88b4d00             -mov dword ptr [0x4d8bc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5082056) /* 0x4d8bc8 */) = cpu.eax;
    // 00481862  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481863(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00481863:
    // 00481863  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 00481868  2b05c88b4d00           +sub eax, dword ptr [0x4d8bc8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5082056) /* 0x4d8bc8 */)));
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
    // 0048186e  78f3                   -js 0x481863
    if (cpu.flags.sf)
    {
        goto L_0x00481863;
    }
    // 00481870  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481871(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481871  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 00481876  2b05c88b4d00           +sub eax, dword ptr [0x4d8bc8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5082056) /* 0x4d8bc8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048187c  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0048187e  40                     -inc eax
    (cpu.eax)++;
    // 0048187f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481880  0305c4155600           -add eax, dword ptr [0x5615c4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */)));
    // 00481886  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
L_0x00481887:
    // 00481887  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481889  e8920a0000             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0048188e  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 00481893  2b0424                 +sub eax, dword ptr [esp]
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
    // 00481896  78ef                   -js 0x481887
    if (cpu.flags.sf)
    {
        goto L_0x00481887;
    }
    // 00481898  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048189b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4818a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818a0  d1fb                   +sar ebx, 1
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
    // 004818a2  e99db70100             -jmp 0x49d044
    return sub_49d044(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4818a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818a8  01db                   +add ebx, ebx
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
    // 004818aa  e995b70100             -jmp 0x49d044
    return sub_49d044(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4818b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004818b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004818b3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004818ba  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004818bc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004818be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004818c0  e87fb70100             -call 0x49d044
    cpu.esp -= 4;
    sub_49d044(app, cpu);
    if (cpu.terminate) return;
    // 004818c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4818c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818c8  c1e302                 +shl ebx, 2
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
    // 004818cb  e974b70100             -jmp 0x49d044
    return sub_49d044(app, cpu);
}

/* align: skip  */
void Application::sub_4818d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004818d1  b9d08b4d00             -mov ecx, 0x4d8bd0
    cpu.ecx = 5082064 /*0x4d8bd0*/;
    // 004818d6  e851b30100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 004818db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4818e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004818e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004818e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004818e3  b9d08b4d00             -mov ecx, 0x4d8bd0
    cpu.ecx = 5082064 /*0x4d8bd0*/;
    // 004818e8  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004818eb  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004818ee  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004818f1  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004818f4  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004818f7  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004818fa  e82db30100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 004818ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481900  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481901  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481902  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481904  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481905  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00481908  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048190b  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048190d  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00481910  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00481913  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481915  b9d08b4d00             -mov ecx, 0x4d8bd0
    cpu.ecx = 5082064 /*0x4d8bd0*/;
    // 0048191a  e80db30100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 0048191f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481920  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481924(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481924  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481925  b9d08b4d00             -mov ecx, 0x4d8bd0
    cpu.ecx = 5082064 /*0x4d8bd0*/;
    // 0048192a  e8fdb20100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 0048192f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481930  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481934(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481934  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481935  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481936  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481937  b9d08b4d00             -mov ecx, 0x4d8bd0
    cpu.ecx = 5082064 /*0x4d8bd0*/;
    // 0048193c  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048193f  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00481942  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00481945  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00481948  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0048194b  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0048194e  e8d9b20100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 00481953  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481954  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481955  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481956  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481958(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481958  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481959  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048195c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048195f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481961  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00481964  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00481967  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481969  b9d08b4d00             -mov ecx, 0x4d8bd0
    cpu.ecx = 5082064 /*0x4d8bd0*/;
    // 0048196e  e8b9b20100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 00481973  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481974  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481980  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481981  83f807                 +cmp eax, 7
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
    // 00481984  0f8de1010000           -jge 0x481b6b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481b6b;
    }
    // 0048198a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048198c  0f8cd9010000           -jl 0x481b6b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481b6b;
    }
L_0x00481992:
    // 00481992  a3c88f4d00             -mov dword ptr [0x4d8fc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5083080) /* 0x4d8fc8 */) = cpu.eax;
    // 00481997  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481999  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048199c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048199e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004819a1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004819a3  8b1485f48b4d00         -mov edx, dword ptr [eax*4 + 0x4d8bf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082100) /* 0x4d8bf4 */ + cpu.eax * 4);
    // 004819aa  891528155600           -mov dword ptr [0x561528], edx
    app->getMemory<x86::reg32>(x86::reg32(5641512) /* 0x561528 */) = cpu.edx;
    // 004819b0  8b1485f88b4d00         -mov edx, dword ptr [eax*4 + 0x4d8bf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082104) /* 0x4d8bf8 */ + cpu.eax * 4);
    // 004819b7  891534155600           -mov dword ptr [0x561534], edx
    app->getMemory<x86::reg32>(x86::reg32(5641524) /* 0x561534 */) = cpu.edx;
    // 004819bd  8b1485fc8b4d00         -mov edx, dword ptr [eax*4 + 0x4d8bfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082108) /* 0x4d8bfc */ + cpu.eax * 4);
    // 004819c4  891508155600           -mov dword ptr [0x561508], edx
    app->getMemory<x86::reg32>(x86::reg32(5641480) /* 0x561508 */) = cpu.edx;
    // 004819ca  8b1485008c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082112) /* 0x4d8c00 */ + cpu.eax * 4);
    // 004819d1  89150c155600           -mov dword ptr [0x56150c], edx
    app->getMemory<x86::reg32>(x86::reg32(5641484) /* 0x56150c */) = cpu.edx;
    // 004819d7  8b1485048c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082116) /* 0x4d8c04 */ + cpu.eax * 4);
    // 004819de  891520155600           -mov dword ptr [0x561520], edx
    app->getMemory<x86::reg32>(x86::reg32(5641504) /* 0x561520 */) = cpu.edx;
    // 004819e4  8b1485088c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082120) /* 0x4d8c08 */ + cpu.eax * 4);
    // 004819eb  891538155600           -mov dword ptr [0x561538], edx
    app->getMemory<x86::reg32>(x86::reg32(5641528) /* 0x561538 */) = cpu.edx;
    // 004819f1  8b14850c8c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082124) /* 0x4d8c0c */ + cpu.eax * 4);
    // 004819f8  891540155600           -mov dword ptr [0x561540], edx
    app->getMemory<x86::reg32>(x86::reg32(5641536) /* 0x561540 */) = cpu.edx;
    // 004819fe  8b1485108c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082128) /* 0x4d8c10 */ + cpu.eax * 4);
    // 00481a05  89153c155600           -mov dword ptr [0x56153c], edx
    app->getMemory<x86::reg32>(x86::reg32(5641532) /* 0x56153c */) = cpu.edx;
    // 00481a0b  8b1485148c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082132) /* 0x4d8c14 */ + cpu.eax * 4);
    // 00481a12  891500155600           -mov dword ptr [0x561500], edx
    app->getMemory<x86::reg32>(x86::reg32(5641472) /* 0x561500 */) = cpu.edx;
    // 00481a18  8b1485188c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082136) /* 0x4d8c18 */ + cpu.eax * 4);
    // 00481a1f  891514155600           -mov dword ptr [0x561514], edx
    app->getMemory<x86::reg32>(x86::reg32(5641492) /* 0x561514 */) = cpu.edx;
    // 00481a25  8b14851c8c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082140) /* 0x4d8c1c */ + cpu.eax * 4);
    // 00481a2c  891548155600           -mov dword ptr [0x561548], edx
    app->getMemory<x86::reg32>(x86::reg32(5641544) /* 0x561548 */) = cpu.edx;
    // 00481a32  8b1485208c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082144) /* 0x4d8c20 */ + cpu.eax * 4);
    // 00481a39  89152c155600           -mov dword ptr [0x56152c], edx
    app->getMemory<x86::reg32>(x86::reg32(5641516) /* 0x56152c */) = cpu.edx;
    // 00481a3f  8b1485248c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082148) /* 0x4d8c24 */ + cpu.eax * 4);
    // 00481a46  89151c155600           -mov dword ptr [0x56151c], edx
    app->getMemory<x86::reg32>(x86::reg32(5641500) /* 0x56151c */) = cpu.edx;
    // 00481a4c  8b1485288c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082152) /* 0x4d8c28 */ + cpu.eax * 4);
    // 00481a53  891518155600           -mov dword ptr [0x561518], edx
    app->getMemory<x86::reg32>(x86::reg32(5641496) /* 0x561518 */) = cpu.edx;
    // 00481a59  8b14852c8c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082156) /* 0x4d8c2c */ + cpu.eax * 4);
    // 00481a60  891524155600           -mov dword ptr [0x561524], edx
    app->getMemory<x86::reg32>(x86::reg32(5641508) /* 0x561524 */) = cpu.edx;
    // 00481a66  8b1485308c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082160) /* 0x4d8c30 */ + cpu.eax * 4);
    // 00481a6d  891504155600           -mov dword ptr [0x561504], edx
    app->getMemory<x86::reg32>(x86::reg32(5641476) /* 0x561504 */) = cpu.edx;
    // 00481a73  8b1485348c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082164) /* 0x4d8c34 */ + cpu.eax * 4);
    // 00481a7a  891544155600           -mov dword ptr [0x561544], edx
    app->getMemory<x86::reg32>(x86::reg32(5641540) /* 0x561544 */) = cpu.edx;
    // 00481a80  8b1485388c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082168) /* 0x4d8c38 */ + cpu.eax * 4);
    // 00481a87  891510155600           -mov dword ptr [0x561510], edx
    app->getMemory<x86::reg32>(x86::reg32(5641488) /* 0x561510 */) = cpu.edx;
    // 00481a8d  8b14853c8c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082172) /* 0x4d8c3c */ + cpu.eax * 4);
    // 00481a94  891530155600           -mov dword ptr [0x561530], edx
    app->getMemory<x86::reg32>(x86::reg32(5641520) /* 0x561530 */) = cpu.edx;
    // 00481a9a  8b1485408c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082176) /* 0x4d8c40 */ + cpu.eax * 4);
    // 00481aa1  8915ec145600           -mov dword ptr [0x5614ec], edx
    app->getMemory<x86::reg32>(x86::reg32(5641452) /* 0x5614ec */) = cpu.edx;
    // 00481aa7  8b1485448c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082180) /* 0x4d8c44 */ + cpu.eax * 4);
    // 00481aae  8915c8145600           -mov dword ptr [0x5614c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5641416) /* 0x5614c8 */) = cpu.edx;
    // 00481ab4  8b1485488c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082184) /* 0x4d8c48 */ + cpu.eax * 4);
    // 00481abb  8915c0145600           -mov dword ptr [0x5614c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5641408) /* 0x5614c0 */) = cpu.edx;
    // 00481ac1  8b14854c8c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082188) /* 0x4d8c4c */ + cpu.eax * 4);
    // 00481ac8  8915e8145600           -mov dword ptr [0x5614e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5641448) /* 0x5614e8 */) = cpu.edx;
    // 00481ace  8b1485508c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082192) /* 0x4d8c50 */ + cpu.eax * 4);
    // 00481ad5  8915d8145600           -mov dword ptr [0x5614d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5641432) /* 0x5614d8 */) = cpu.edx;
    // 00481adb  8b1485548c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082196) /* 0x4d8c54 */ + cpu.eax * 4);
    // 00481ae2  8915e0145600           -mov dword ptr [0x5614e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5641440) /* 0x5614e0 */) = cpu.edx;
    // 00481ae8  8b1485588c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082200) /* 0x4d8c58 */ + cpu.eax * 4);
    // 00481aef  8915fc145600           -mov dword ptr [0x5614fc], edx
    app->getMemory<x86::reg32>(x86::reg32(5641468) /* 0x5614fc */) = cpu.edx;
    // 00481af5  8b14855c8c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082204) /* 0x4d8c5c */ + cpu.eax * 4);
    // 00481afc  8915d0145600           -mov dword ptr [0x5614d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5641424) /* 0x5614d0 */) = cpu.edx;
    // 00481b02  8b1485608c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082208) /* 0x4d8c60 */ + cpu.eax * 4);
    // 00481b09  8915c4145600           -mov dword ptr [0x5614c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5641412) /* 0x5614c4 */) = cpu.edx;
    // 00481b0f  8b1485648c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082212) /* 0x4d8c64 */ + cpu.eax * 4);
    // 00481b16  8915f0145600           -mov dword ptr [0x5614f0], edx
    app->getMemory<x86::reg32>(x86::reg32(5641456) /* 0x5614f0 */) = cpu.edx;
    // 00481b1c  8b1485688c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082216) /* 0x4d8c68 */ + cpu.eax * 4);
    // 00481b23  8915d4145600           -mov dword ptr [0x5614d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5641428) /* 0x5614d4 */) = cpu.edx;
    // 00481b29  8b14856c8c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082220) /* 0x4d8c6c */ + cpu.eax * 4);
    // 00481b30  8915f4145600           -mov dword ptr [0x5614f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5641460) /* 0x5614f4 */) = cpu.edx;
    // 00481b36  8b1485708c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082224) /* 0x4d8c70 */ + cpu.eax * 4);
    // 00481b3d  8915e4145600           -mov dword ptr [0x5614e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5641444) /* 0x5614e4 */) = cpu.edx;
    // 00481b43  8b1485748c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082228) /* 0x4d8c74 */ + cpu.eax * 4);
    // 00481b4a  8915f8145600           -mov dword ptr [0x5614f8], edx
    app->getMemory<x86::reg32>(x86::reg32(5641464) /* 0x5614f8 */) = cpu.edx;
    // 00481b50  8b1485788c4d00         -mov edx, dword ptr [eax*4 + 0x4d8c78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5082232) /* 0x4d8c78 */ + cpu.eax * 4);
    // 00481b57  8b04857c8c4d00         -mov eax, dword ptr [eax*4 + 0x4d8c7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5082236) /* 0x4d8c7c */ + cpu.eax * 4);
    // 00481b5e  8915dc145600           -mov dword ptr [0x5614dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5641436) /* 0x5614dc */) = cpu.edx;
    // 00481b64  a3cc145600             -mov dword ptr [0x5614cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5641420) /* 0x5614cc */) = cpu.eax;
    // 00481b69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b6a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481b6b:
    // 00481b6b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00481b6d  e920feffff             -jmp 0x481992
    goto L_0x00481992;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481b74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481b74  a1c88f4d00             -mov eax, dword ptr [0x4d8fc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083080) /* 0x4d8fc8 */);
    // 00481b79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481b7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481b7c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00481b81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481b91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481b92  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481b94  39d0                   +cmp eax, edx
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
    // 00481b96  746c                   -je 0x481c04
    if (cpu.flags.zf)
    {
        goto L_0x00481c04;
    }
L_0x00481b98:
    // 00481b98  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00481b9a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00481b9c  39c1                   +cmp ecx, eax
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
    // 00481b9e  7569                   -jne 0x481c09
    if (!cpu.flags.zf)
    {
        goto L_0x00481c09;
    }
    // 00481ba0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00481ba2  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00481ba7  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481ba9  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00481bae  7554                   -jne 0x481c04
    if (!cpu.flags.zf)
    {
        goto L_0x00481c04;
    }
    // 00481bb0  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00481bb3  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00481bb6  39c1                   +cmp ecx, eax
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
    // 00481bb8  754f                   -jne 0x481c09
    if (!cpu.flags.zf)
    {
        goto L_0x00481c09;
    }
    // 00481bba  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00481bbc  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00481bc1  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481bc3  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00481bc8  753a                   -jne 0x481c04
    if (!cpu.flags.zf)
    {
        goto L_0x00481c04;
    }
    // 00481bca  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00481bcd  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00481bd0  39c1                   +cmp ecx, eax
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
    // 00481bd2  7535                   -jne 0x481c09
    if (!cpu.flags.zf)
    {
        goto L_0x00481c09;
    }
    // 00481bd4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00481bd6  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00481bdb  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481bdd  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00481be2  7520                   -jne 0x481c04
    if (!cpu.flags.zf)
    {
        goto L_0x00481c04;
    }
    // 00481be4  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00481be7  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00481bea  39c1                   +cmp ecx, eax
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
    // 00481bec  751b                   -jne 0x481c09
    if (!cpu.flags.zf)
    {
        goto L_0x00481c09;
    }
    // 00481bee  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481bf1  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481bf4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00481bf6  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00481bfb  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481bfd  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00481c02  7494                   -je 0x481b98
    if (cpu.flags.zf)
    {
        goto L_0x00481b98;
    }
L_0x00481c04:
    // 00481c04  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00481c06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481c09:
    // 00481c09  38c8                   +cmp al, cl
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
    // 00481c0b  751d                   -jne 0x481c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00481c2a;
    }
    // 00481c0d  3c00                   +cmp al, 0
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
    // 00481c0f  74f3                   -je 0x481c04
    if (cpu.flags.zf)
    {
        goto L_0x00481c04;
    }
    // 00481c11  38ec                   +cmp ah, ch
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
    // 00481c13  7515                   -jne 0x481c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00481c2a;
    }
    // 00481c15  80fc00                 +cmp ah, 0
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
    // 00481c18  74ea                   -je 0x481c04
    if (cpu.flags.zf)
    {
        goto L_0x00481c04;
    }
    // 00481c1a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00481c1d  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00481c20  38c8                   +cmp al, cl
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
    // 00481c22  7506                   -jne 0x481c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00481c2a;
    }
    // 00481c24  3c00                   +cmp al, 0
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
    // 00481c26  74dc                   -je 0x481c04
    if (cpu.flags.zf)
    {
        goto L_0x00481c04;
    }
    // 00481c28  38ec                   +cmp ah, ch
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
L_0x00481c2a:
    // 00481c2a  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00481c2c  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00481c2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_481c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481c41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481c42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481c43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481c44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481c45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481c46  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481c4d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481c4f  e828660000             -call 0x48827c
    cpu.esp -= 4;
    sub_48827c(app, cpu);
    if (cpu.terminate) return;
    // 00481c54  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481c56  a3a8155600             -mov dword ptr [0x5615a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5641640) /* 0x5615a8 */) = cpu.eax;
    // 00481c5b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00481c5d:
    // 00481c5d  a1a8155600             -mov eax, dword ptr [0x5615a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641640) /* 0x5615a8 */);
    // 00481c62  e865660000             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 00481c67  3b3da0155600           +cmp edi, dword ptr [0x5615a0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641632) /* 0x5615a0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481c6d  7463                   -je 0x481cd2
    if (cpu.flags.zf)
    {
        goto L_0x00481cd2;
    }
    // 00481c6f  ff05c4155600           -inc dword ptr [0x5615c4]
    (app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */))++;
    // 00481c75  ff05c0155600           -inc dword ptr [0x5615c0]
    (app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */))++;
    // 00481c7b  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481c82  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481c84  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00481c86  69d2a9040000           -imul edx, edx, 0x4a9
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(1193 /*0x4a9*/)));
    // 00481c8c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481c8e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481c90  81fbffff0000           +cmp ebx, 0xffff
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
    // 00481c96  7e11                   -jle 0x481ca9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481ca9;
    }
    // 00481c98  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481c9a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00481c9d  0105a4155600           -add dword ptr [0x5615a4], eax
    (app->getMemory<x86::reg32>(x86::reg32(5641636) /* 0x5615a4 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00481ca3  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x00481ca9:
    // 00481ca9  8b2d50155600           -mov ebp, dword ptr [0x561550]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5641552) /* 0x561550 */);
    // 00481caf  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00481cb1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00481cb3  39ef                   +cmp edi, ebp
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
    // 00481cb5  74a6                   -je 0x481c5d
    if (cpu.flags.zf)
    {
        goto L_0x00481c5d;
    }
L_0x00481cb7:
    // 00481cb7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481cb9  41                     -inc ecx
    (cpu.ecx)++;
    // 00481cba  ff9050155600           -call dword ptr [eax + 0x561550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641552) /* 0x561550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481cc0  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481cc3  83f908                 +cmp ecx, 8
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
    // 00481cc6  7395                   -jae 0x481c5d
    if (!cpu.flags.cf)
    {
        goto L_0x00481c5d;
    }
    // 00481cc8  3bba50155600           +cmp edi, dword ptr [edx + 0x561550]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5641552) /* 0x561550 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481cce  75e7                   -jne 0x481cb7
    if (!cpu.flags.zf)
    {
        goto L_0x00481cb7;
    }
    // 00481cd0  eb8b                   -jmp 0x481c5d
    goto L_0x00481c5d;
L_0x00481cd2:
    // 00481cd2  a1a8155600             -mov eax, dword ptr [0x5615a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641640) /* 0x5615a8 */);
    // 00481cd7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481cd9  e87a660000             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 00481cde  8915a8155600           -mov dword ptr [0x5615a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5641640) /* 0x5615a8 */) = cpu.edx;
    // 00481ce4  8915e8894d00           -mov dword ptr [0x4d89e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */) = cpu.edx;
    // 00481cea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ceb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481cec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ced  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481cee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481cef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481cf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481cf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481cf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481cf5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481cf6  e881650000             -call 0x48827c
    cpu.esp -= 4;
    sub_48827c(app, cpu);
    if (cpu.terminate) return;
    // 00481cfb  8b157c155600           -mov edx, dword ptr [0x56157c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641596) /* 0x56157c */);
    // 00481d01  a39c155600             -mov dword ptr [0x56159c], eax
    app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */) = cpu.eax;
    // 00481d06  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481d08  741a                   -je 0x481d24
    if (cpu.flags.zf)
    {
        goto L_0x00481d24;
    }
L_0x00481d0a:
    // 00481d0a  ff157c155600           -call dword ptr [0x56157c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641596) /* 0x56157c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481d10  a19c155600             -mov eax, dword ptr [0x56159c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */);
    // 00481d15  e8b2650000             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 00481d1a  833d7c15560000         +cmp dword ptr [0x56157c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641596) /* 0x56157c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481d21  75e7                   -jne 0x481d0a
    if (!cpu.flags.zf)
    {
        goto L_0x00481d0a;
    }
    // 00481d23  90                     -nop 
    ;
L_0x00481d24:
    // 00481d24  a19c155600             -mov eax, dword ptr [0x56159c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */);
    // 00481d29  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481d2b  e828660000             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 00481d30  891d9c155600           -mov dword ptr [0x56159c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */) = cpu.ebx;
    // 00481d36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481d3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481d3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481d3d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481d3e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481d3f  a37c155600             -mov dword ptr [0x56157c], eax
    app->getMemory<x86::reg32>(x86::reg32(5641596) /* 0x56157c */) = cpu.eax;
    // 00481d44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481d46  740a                   -je 0x481d52
    if (cpu.flags.zf)
    {
        goto L_0x00481d52;
    }
    // 00481d48  8b159c155600           -mov edx, dword ptr [0x56159c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */);
    // 00481d4e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481d50  741a                   -je 0x481d6c
    if (cpu.flags.zf)
    {
        goto L_0x00481d6c;
    }
L_0x00481d52:
    // 00481d52  833d7c15560000         +cmp dword ptr [0x56157c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641596) /* 0x56157c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481d59  750d                   -jne 0x481d68
    if (!cpu.flags.zf)
    {
        goto L_0x00481d68;
    }
    // 00481d5b  8b1d9c155600           -mov ebx, dword ptr [0x56159c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */);
    // 00481d61  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481d63  753e                   -jne 0x481da3
    if (!cpu.flags.zf)
    {
        goto L_0x00481da3;
    }
    // 00481d65  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00481d68:
    // 00481d68  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d6a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481d6c:
    // 00481d6c  6880155600             -push 0x561580
    app->getMemory<x86::reg32>(cpu.esp-4) = 5641600 /*0x561580*/;
    cpu.esp -= 4;
    // 00481d71  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00481d76  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00481d7b  b8f41c4800             -mov eax, 0x481cf4
    cpu.eax = 4726004 /*0x481cf4*/;
    // 00481d80  e8cb610000             -call 0x487f50
    cpu.esp -= 4;
    sub_487f50(app, cpu);
    if (cpu.terminate) return;
    // 00481d85  833d9c15560000         +cmp dword ptr [0x56159c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481d8c  75da                   -jne 0x481d68
    if (!cpu.flags.zf)
    {
        goto L_0x00481d68;
    }
    // 00481d8e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00481d90:
    // 00481d90  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481d92  e875620000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 00481d97  3b159c155600           +cmp edx, dword ptr [0x56159c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481d9d  74f1                   -je 0x481d90
    if (cpu.flags.zf)
    {
        goto L_0x00481d90;
    }
    // 00481d9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481da0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481da1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481da2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481da3:
    // 00481da3  b880155600             -mov eax, 0x561580
    cpu.eax = 5641600 /*0x561580*/;
    // 00481da8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00481daa  e8e1640000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 00481daf  833d9c15560000         +cmp dword ptr [0x56159c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481db6  74b0                   -je 0x481d68
    if (cpu.flags.zf)
    {
        goto L_0x00481d68;
    }
    // 00481db8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00481dba:
    // 00481dba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481dbc  e84b620000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 00481dc1  3b159c155600           +cmp edx, dword ptr [0x56159c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481dc7  75f1                   -jne 0x481dba
    if (!cpu.flags.zf)
    {
        goto L_0x00481dba;
    }
    // 00481dc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481dca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481dcb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481dcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481dd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481dd1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00481dd3:
    // 00481dd3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481dd6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481dd8  89904c155600           -mov dword ptr [eax + 0x56154c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641548) /* 0x56154c */) = cpu.edx;
    // 00481dde  83f820                 +cmp eax, 0x20
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
    // 00481de1  75f0                   -jne 0x481dd3
    if (!cpu.flags.zf)
    {
        goto L_0x00481dd3;
    }
    // 00481de3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481de4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481de8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481de9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481dea  a170155600             -mov eax, dword ptr [0x561570]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641584) /* 0x561570 */);
    // 00481def  8b1598155600           -mov edx, dword ptr [0x561598]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641624) /* 0x561598 */);
    // 00481df5  8b0d78155600           -mov ecx, dword ptr [0x561578]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5641592) /* 0x561578 */);
    // 00481dfb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481dfd  8b1da0155600           -mov ebx, dword ptr [0x5615a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641632) /* 0x5615a0 */);
    // 00481e03  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481e05  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00481e08  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00481e0e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00481e10  891598155600           -mov dword ptr [0x561598], edx
    app->getMemory<x86::reg32>(x86::reg32(5641624) /* 0x561598 */) = cpu.edx;
    // 00481e16  890d78155600           -mov dword ptr [0x561578], ecx
    app->getMemory<x86::reg32>(x86::reg32(5641592) /* 0x561578 */) = cpu.ecx;
    // 00481e1c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481e1e  753f                   -jne 0x481e5f
    if (!cpu.flags.zf)
    {
        goto L_0x00481e5f;
    }
L_0x00481e20:
    // 00481e20  8b0d9c155600           -mov ecx, dword ptr [0x56159c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5641628) /* 0x56159c */);
    // 00481e26  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481e28  740c                   -je 0x481e36
    if (cpu.flags.zf)
    {
        goto L_0x00481e36;
    }
    // 00481e2a  b880155600             -mov eax, 0x561580
    cpu.eax = 5641600 /*0x561580*/;
    // 00481e2f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00481e31  e85a640000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
L_0x00481e36:
    // 00481e36  8b1da8155600           -mov ebx, dword ptr [0x5615a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641640) /* 0x5615a8 */);
    // 00481e3c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481e3e  7415                   -je 0x481e55
    if (cpu.flags.zf)
    {
        goto L_0x00481e55;
    }
    // 00481e40  833dcc8f4d0000         +cmp dword ptr [0x4d8fcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083084) /* 0x4d8fcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e47  750c                   -jne 0x481e55
    if (!cpu.flags.zf)
    {
        goto L_0x00481e55;
    }
    // 00481e49  b8ac155600             -mov eax, 0x5615ac
    cpu.eax = 5641644 /*0x5615ac*/;
    // 00481e4e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00481e50  e83b640000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
L_0x00481e55:
    // 00481e55  e826dd0100             -call 0x49fb80
    cpu.esp -= 4;
    sub_49fb80(app, cpu);
    if (cpu.terminate) return;
    // 00481e5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e5c  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00481e5f:
    // 00481e5f  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481e66  8b1578155600           -mov edx, dword ptr [0x561578]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641592) /* 0x561578 */);
    // 00481e6c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00481e6e  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00481e71  83f801                 +cmp eax, 1
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
    // 00481e74  7d28                   -jge 0x481e9e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481e9e;
    }
    // 00481e76  3d18fcffff             +cmp eax, 0xfffffc18
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
    // 00481e7b  7d1c                   -jge 0x481e99
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481e99;
    }
    // 00481e7d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481e7e  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481e85  8b35d88f4d00           -mov esi, dword ptr [0x4d8fd8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083096) /* 0x4d8fd8 */);
    // 00481e8b  40                     -inc eax
    (cpu.eax)++;
    // 00481e8c  46                     -inc esi
    (cpu.esi)++;
    // 00481e8d  a378155600             -mov dword ptr [0x561578], eax
    app->getMemory<x86::reg32>(x86::reg32(5641592) /* 0x561578 */) = cpu.eax;
    // 00481e92  8935d88f4d00           -mov dword ptr [0x4d8fd8], esi
    app->getMemory<x86::reg32>(x86::reg32(5083096) /* 0x4d8fd8 */) = cpu.esi;
    // 00481e98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481e99:
    // 00481e99  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00481e9e:
    // 00481e9e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481ea0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481ea2  68e81d4800             -push 0x481de8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4726248 /*0x481de8*/;
    cpu.esp -= 4;
    // 00481ea7  8b3d74155600           -mov edi, dword ptr [0x561574]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5641588) /* 0x561574 */);
    // 00481ead  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481eae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481eaf  2eff1508464c00         -call dword ptr cs:[0x4c4608]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998664) /* 0x4c4608 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481eb6  a394155600             -mov dword ptr [0x561594], eax
    app->getMemory<x86::reg32>(x86::reg32(5641620) /* 0x561594 */) = cpu.eax;
    // 00481ebb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481ebd  0f855dffffff           -jne 0x481e20
    if (!cpu.flags.zf)
    {
        goto L_0x00481e20;
    }
    // 00481ec3  8b1574155600           -mov edx, dword ptr [0x561574]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641588) /* 0x561574 */);
    // 00481ec9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481eca  a3e8894d00             -mov dword ptr [0x4d89e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */) = cpu.eax;
    // 00481ecf  a3a0155600             -mov dword ptr [0x5615a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5641632) /* 0x5615a0 */) = cpu.eax;
    // 00481ed4  2eff15fc454c00         -call dword ptr cs:[0x4c45fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998652) /* 0x4c45fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481edb  e940ffffff             -jmp 0x481e20
    goto L_0x00481e20;
}

/* align: skip  */
void Application::sub_481ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481ee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481ee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481ee3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481ee4  8b35cc8f4d00           -mov esi, dword ptr [0x4d8fcc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083084) /* 0x4d8fcc */);
    // 00481eea  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481eec  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00481ef1  46                     -inc esi
    (cpu.esi)++;
    // 00481ef2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481ef4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00481ef6:
    // 00481ef6  83b85015560000         +cmp dword ptr [eax + 0x561550], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641552) /* 0x561550 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481efd  7504                   -jne 0x481f03
    if (!cpu.flags.zf)
    {
        goto L_0x00481f03;
    }
    // 00481eff  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481f01  7c29                   -jl 0x481f2c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481f2c;
    }
L_0x00481f03:
    // 00481f03  3b9850155600           +cmp ebx, dword ptr [eax + 0x561550]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641552) /* 0x561550 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481f09  7415                   -je 0x481f20
    if (cpu.flags.zf)
    {
        goto L_0x00481f20;
    }
L_0x00481f0b:
    // 00481f0b  42                     -inc edx
    (cpu.edx)++;
    // 00481f0c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481f0f  83fa08                 +cmp edx, 8
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
    // 00481f12  7ce2                   -jl 0x481ef6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481ef6;
    }
    // 00481f14  83f9ff                 +cmp ecx, -1
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
    // 00481f17  7407                   -je 0x481f20
    if (cpu.flags.zf)
    {
        goto L_0x00481f20;
    }
    // 00481f19  891c8d50155600         -mov dword ptr [ecx*4 + 0x561550], ebx
    app->getMemory<x86::reg32>(x86::reg32(5641552) /* 0x561550 */ + cpu.ecx * 4) = cpu.ebx;
L_0x00481f20:
    // 00481f20  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481f21  8935cc8f4d00           -mov dword ptr [0x4d8fcc], esi
    app->getMemory<x86::reg32>(x86::reg32(5083084) /* 0x4d8fcc */) = cpu.esi;
    // 00481f27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f2c:
    // 00481f2c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00481f2e  ebdb                   -jmp 0x481f0b
    goto L_0x00481f0b;
}

/* align: skip  */
void Application::sub_481f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481f32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481f33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481f34  8b1dcc8f4d00           -mov ebx, dword ptr [0x4d8fcc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083084) /* 0x4d8fcc */);
    // 00481f3a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481f3c  8b3550155600           -mov esi, dword ptr [0x561550]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641552) /* 0x561550 */);
    // 00481f42  43                     -inc ebx
    (cpu.ebx)++;
    // 00481f43  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481f45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481f47  39f1                   +cmp ecx, esi
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
    // 00481f49  7411                   -je 0x481f5c
    if (cpu.flags.zf)
    {
        goto L_0x00481f5c;
    }
L_0x00481f4b:
    // 00481f4b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481f4e  42                     -inc edx
    (cpu.edx)++;
    // 00481f4f  83f820                 +cmp eax, 0x20
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
    // 00481f52  7d08                   -jge 0x481f5c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481f5c;
    }
    // 00481f54  3b8850155600           +cmp ecx, dword ptr [eax + 0x561550]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641552) /* 0x561550 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481f5a  75ef                   -jne 0x481f4b
    if (!cpu.flags.zf)
    {
        goto L_0x00481f4b;
    }
L_0x00481f5c:
    // 00481f5c  83fa08                 +cmp edx, 8
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
    // 00481f5f  7d32                   -jge 0x481f93
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481f93;
    }
    // 00481f61  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00481f68  3b8850155600           +cmp ecx, dword ptr [eax + 0x561550]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641552) /* 0x561550 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481f6e  7523                   -jne 0x481f93
    if (!cpu.flags.zf)
    {
        goto L_0x00481f93;
    }
    // 00481f70  83fa07                 +cmp edx, 7
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
    // 00481f73  7d17                   -jge 0x481f8c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481f8c;
    }
L_0x00481f75:
    // 00481f75  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481f78  8b9050155600           -mov edx, dword ptr [eax + 0x561550]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641552) /* 0x561550 */);
    // 00481f7e  89904c155600           -mov dword ptr [eax + 0x56154c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641548) /* 0x56154c */) = cpu.edx;
    // 00481f84  83f81c                 +cmp eax, 0x1c
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
    // 00481f87  7cec                   -jl 0x481f75
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481f75;
    }
    // 00481f89  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00481f8c:
    // 00481f8c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481f8e  a36c155600             -mov dword ptr [0x56156c], eax
    app->getMemory<x86::reg32>(x86::reg32(5641580) /* 0x56156c */) = cpu.eax;
L_0x00481f93:
    // 00481f93  4b                     -dec ebx
    (cpu.ebx)--;
    // 00481f94  891dcc8f4d00           -mov dword ptr [0x4d8fcc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083084) /* 0x4d8fcc */) = cpu.ebx;
    // 00481f9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481fa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481fa1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481fa2  8b0d50155600           -mov ecx, dword ptr [0x561550]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5641552) /* 0x561550 */);
    // 00481fa8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481faa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481fac  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481fae  7412                   -je 0x481fc2
    if (cpu.flags.zf)
    {
        goto L_0x00481fc2;
    }
L_0x00481fb0:
    // 00481fb0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481fb3  42                     -inc edx
    (cpu.edx)++;
    // 00481fb4  83f820                 +cmp eax, 0x20
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
    // 00481fb7  7d09                   -jge 0x481fc2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481fc2;
    }
    // 00481fb9  83b85015560000         +cmp dword ptr [eax + 0x561550], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641552) /* 0x561550 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481fc0  75ee                   -jne 0x481fb0
    if (!cpu.flags.zf)
    {
        goto L_0x00481fb0;
    }
L_0x00481fc2:
    // 00481fc2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481fc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481fc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481fc8  ff05cc8f4d00           -inc dword ptr [0x4d8fcc]
    (app->getMemory<x86::reg32>(x86::reg32(5083084) /* 0x4d8fcc */))++;
    // 00481fce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481fd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481fd1  8b15cc8f4d00           -mov edx, dword ptr [0x4d8fcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083084) /* 0x4d8fcc */);
    // 00481fd7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481fd9  7502                   -jne 0x481fdd
    if (!cpu.flags.zf)
    {
        goto L_0x00481fdd;
    }
    // 00481fdb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fdc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481fdd:
    // 00481fdd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481fde  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00481fe1  890dcc8f4d00           -mov dword ptr [0x4d8fcc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083084) /* 0x4d8fcc */) = cpu.ecx;
    // 00481fe7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fe8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fe9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481fec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481fec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481fed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481fee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481fef  833da015560000         +cmp dword ptr [0x5615a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641632) /* 0x5615a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481ff6  7448                   -je 0x482040
    if (cpu.flags.zf)
    {
        goto L_0x00482040;
    }
    // 00481ff8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481ff9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481ffb  8b3594155600           -mov esi, dword ptr [0x561594]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641620) /* 0x561594 */);
    // 00482001  890de8894d00           -mov dword ptr [0x4d89e8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */) = cpu.ecx;
    // 00482007  890da0155600           -mov dword ptr [0x5615a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5641632) /* 0x5615a0 */) = cpu.ecx;
    // 0048200d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048200f  7553                   -jne 0x482064
    if (!cpu.flags.zf)
    {
        goto L_0x00482064;
    }
L_0x00482011:
    // 00482011  8b2d74155600           -mov ebp, dword ptr [0x561574]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5641588) /* 0x561574 */);
    // 00482017  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482018  2eff15fc454c00         -call dword ptr cs:[0x4c45fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998652) /* 0x4c45fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048201f  a1a8155600             -mov eax, dword ptr [0x5615a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641640) /* 0x5615a8 */);
    // 00482024  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482026  7546                   -jne 0x48206e
    if (!cpu.flags.zf)
    {
        goto L_0x0048206e;
    }
L_0x00482028:
    // 00482028  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048202d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048202e:
    // 0048202e  833d9415560000         +cmp dword ptr [0x561594], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641620) /* 0x561594 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482035  7409                   -je 0x482040
    if (cpu.flags.zf)
    {
        goto L_0x00482040;
    }
    // 00482037  833da815560000         +cmp dword ptr [0x5615a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641640) /* 0x5615a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048203e  753c                   -jne 0x48207c
    if (!cpu.flags.zf)
    {
        goto L_0x0048207c;
    }
L_0x00482040:
    // 00482040  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00482042  893598155600           -mov dword ptr [0x561598], esi
    app->getMemory<x86::reg32>(x86::reg32(5641624) /* 0x561598 */) = cpu.esi;
    // 00482048  8935cc8f4d00           -mov dword ptr [0x4d8fcc], esi
    app->getMemory<x86::reg32>(x86::reg32(5083084) /* 0x4d8fcc */) = cpu.esi;
    // 0048204e  893574155600           -mov dword ptr [0x561574], esi
    app->getMemory<x86::reg32>(x86::reg32(5641588) /* 0x561574 */) = cpu.esi;
    // 00482054  893594155600           -mov dword ptr [0x561594], esi
    app->getMemory<x86::reg32>(x86::reg32(5641620) /* 0x561594 */) = cpu.esi;
    // 0048205a  8935248a4d00           -mov dword ptr [0x4d8a24], esi
    app->getMemory<x86::reg32>(x86::reg32(5081636) /* 0x4d8a24 */) = cpu.esi;
    // 00482060  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482061  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482062  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482063  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482064:
    // 00482064  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482065  2eff1504464c00         -call dword ptr cs:[0x4c4604]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998660) /* 0x4c4604 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048206c  eba3                   -jmp 0x482011
    goto L_0x00482011;
L_0x0048206e:
    // 0048206e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482070  b8ac155600             -mov eax, 0x5615ac
    cpu.eax = 5641644 /*0x5615ac*/;
    // 00482075  e816620000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0048207a  ebac                   -jmp 0x482028
    goto L_0x00482028;
L_0x0048207c:
    // 0048207c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048207e  e8895f0000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 00482083  eba9                   -jmp 0x48202e
    goto L_0x0048202e;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482088(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482088  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482089  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048208a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048208b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048208c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048208d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048208e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00482091  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482093  e854ffffff             -call 0x481fec
    cpu.esp -= 4;
    sub_481fec(app, cpu);
    if (cpu.terminate) return;
    // 00482098  83fe01                 +cmp esi, 1
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
    // 0048209b  7d70                   -jge 0x48210d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048210d;
    }
L_0x0048209d:
    // 0048209d  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
L_0x004820a2:
    // 004820a2  b80000e803             -mov eax, 0x3e80000
    cpu.eax = 65536000 /*0x3e80000*/;
    // 004820a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004820a9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004820ac  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004820ae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004820b0  a370155600             -mov dword ptr [0x561570], eax
    app->getMemory<x86::reg32>(x86::reg32(5641584) /* 0x561570 */) = cpu.eax;
    // 004820b5  891598155600           -mov dword ptr [0x561598], edx
    app->getMemory<x86::reg32>(x86::reg32(5641624) /* 0x561598 */) = cpu.edx;
    // 004820bb  8915c4155600           -mov dword ptr [0x5615c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */) = cpu.edx;
    // 004820c1  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004820c3  8915a4155600           -mov dword ptr [0x5615a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5641636) /* 0x5615a4 */) = cpu.edx;
    // 004820c9  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004820cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004820ce  2eff1500464c00         -call dword ptr cs:[0x4c4600]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998656) /* 0x4c4600 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004820d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004820d7  753e                   -jne 0x482117
    if (!cpu.flags.zf)
    {
        goto L_0x00482117;
    }
    // 004820d9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004820de  8b1570155600           -mov edx, dword ptr [0x561570]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641584) /* 0x561570 */);
    // 004820e4  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004820e7  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004820eb  893d74155600           -mov dword ptr [0x561574], edi
    app->getMemory<x86::reg32>(x86::reg32(5641588) /* 0x561574 */) = cpu.edi;
    // 004820f1  81fa00000100           +cmp edx, 0x10000
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
    // 004820f7  732e                   -jae 0x482127
    if (!cpu.flags.cf)
    {
        goto L_0x00482127;
    }
L_0x004820f9:
    // 004820f9  a3e8894d00             -mov dword ptr [0x4d89e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */) = cpu.eax;
    // 004820fe  a3a0155600             -mov dword ptr [0x5615a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5641632) /* 0x5615a0 */) = cpu.eax;
L_0x00482103:
    // 00482103  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00482106  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482107  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482108  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482109  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048210a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048210b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048210c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048210d:
    // 0048210d  81fe10270000           +cmp esi, 0x2710
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
    // 00482113  7f88                   -jg 0x48209d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048209d;
    }
    // 00482115  eb8b                   -jmp 0x4820a2
    goto L_0x004820a2;
L_0x00482117:
    // 00482117  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00482119  893de8894d00           -mov dword ptr [0x4d89e8], edi
    app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */) = cpu.edi;
    // 0048211f  893da0155600           -mov dword ptr [0x5615a0], edi
    app->getMemory<x86::reg32>(x86::reg32(5641632) /* 0x5615a0 */) = cpu.edi;
    // 00482125  ebdc                   -jmp 0x482103
    goto L_0x00482103;
L_0x00482127:
    // 00482127  68ac155600             -push 0x5615ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5641644 /*0x5615ac*/;
    cpu.esp -= 4;
    // 0048212c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00482131  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00482136  b8401c4800             -mov eax, 0x481c40
    cpu.eax = 4725824 /*0x481c40*/;
    // 0048213b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048213d  e80e5e0000             -call 0x487f50
    cpu.esp -= 4;
    sub_487f50(app, cpu);
    if (cpu.terminate) return;
    // 00482142  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482144  74b3                   -je 0x4820f9
    if (cpu.flags.zf)
    {
        goto L_0x004820f9;
    }
    // 00482146  8b0d74155600           -mov ecx, dword ptr [0x561574]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5641588) /* 0x561574 */);
    // 0048214c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048214d  2eff15f8454c00         -call dword ptr cs:[0x4c45f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998648) /* 0x4c45f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482154  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482156  755e                   -jne 0x4821b6
    if (!cpu.flags.zf)
    {
        goto L_0x004821b6;
    }
    // 00482158  b8ec1f4800             -mov eax, 0x481fec
    cpu.eax = 4726764 /*0x481fec*/;
    // 0048215d  e87e3b0100             -call 0x495ce0
    cpu.esp -= 4;
    sub_495ce0(app, cpu);
    if (cpu.terminate) return;
    // 00482162  8935e8894d00           -mov dword ptr [0x4d89e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */) = cpu.esi;
    // 00482168  8935a0155600           -mov dword ptr [0x5615a0], esi
    app->getMemory<x86::reg32>(x86::reg32(5641632) /* 0x5615a0 */) = cpu.esi;
    // 0048216e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482170  756c                   -jne 0x4821de
    if (!cpu.flags.zf)
    {
        goto L_0x004821de;
    }
L_0x00482172:
    // 00482172  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 00482177  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482179  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482180  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482182  b810270000             -mov eax, 0x2710
    cpu.eax = 10000 /*0x2710*/;
    // 00482187  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482189  8b3de8894d00           -mov edi, dword ptr [0x4d89e8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048218f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00482192  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00482194  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00482196:
    // 00482196  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048219d  39f0                   +cmp eax, esi
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
    // 0048219f  7362                   -jae 0x482203
    if (!cpu.flags.cf)
    {
        goto L_0x00482203;
    }
    // 004821a1  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 004821a6  39c3                   +cmp ebx, eax
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
    // 004821a8  7559                   -jne 0x482203
    if (!cpu.flags.zf)
    {
        goto L_0x00482203;
    }
    // 004821aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004821af  e8585e0000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 004821b4  ebe0                   -jmp 0x482196
    goto L_0x00482196;
L_0x004821b6:
    // 004821b6  b8ac155600             -mov eax, 0x5615ac
    cpu.eax = 5641644 /*0x5615ac*/;
    // 004821bb  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004821bd  8b15a8155600           -mov edx, dword ptr [0x5615a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641640) /* 0x5615a8 */);
    // 004821c3  892de8894d00           -mov dword ptr [0x4d89e8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */) = cpu.ebp;
    // 004821c9  892da0155600           -mov dword ptr [0x5615a0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5641632) /* 0x5615a0 */) = cpu.ebp;
    // 004821cf  e8bc600000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 004821d4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004821d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004821de:
    // 004821de  8b1d94155600           -mov ebx, dword ptr [0x561594]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641620) /* 0x561594 */);
    // 004821e4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004821e6  758a                   -jne 0x482172
    if (!cpu.flags.zf)
    {
        goto L_0x00482172;
    }
    // 004821e8  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004821ef  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004821f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004821f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004821f2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004821f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004821f4  a378155600             -mov dword ptr [0x561578], eax
    app->getMemory<x86::reg32>(x86::reg32(5641592) /* 0x561578 */) = cpu.eax;
    // 004821f9  e8eafbffff             -call 0x481de8
    cpu.esp -= 4;
    sub_481de8(app, cpu);
    if (cpu.terminate) return;
    // 004821fe  e96fffffff             -jmp 0x482172
    goto L_0x00482172;
L_0x00482203:
    // 00482203  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 00482208  39c3                   +cmp ebx, eax
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
    // 0048220a  7505                   -jne 0x482211
    if (!cpu.flags.zf)
    {
        goto L_0x00482211;
    }
    // 0048220c  e8dbfdffff             -call 0x481fec
    cpu.esp -= 4;
    sub_481fec(app, cpu);
    if (cpu.terminate) return;
L_0x00482211:
    // 00482211  833de8894d0000         +cmp dword ptr [0x4d89e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482218  0f84e5feffff           -je 0x482103
    if (cpu.flags.zf)
    {
        goto L_0x00482103;
    }
    // 0048221e  c705248a4d00d01d4800   -mov dword ptr [0x4d8a24], 0x481dd0
    app->getMemory<x86::reg32>(x86::reg32(5081636) /* 0x4d8a24 */) = 4726224 /*0x481dd0*/;
    // 00482228  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048222b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048222c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048222d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048222e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048222f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482230  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482231  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482240  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482241  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482242  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482243  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482244  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482247  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482249  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048224c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048224e  8b1ddc8f4d00           -mov ebx, dword ptr [0x4d8fdc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083100) /* 0x4d8fdc */);
    // 00482254  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00482259  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0048225c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048225e  8915dc8f4d00           -mov dword ptr [0x4d8fdc], edx
    app->getMemory<x86::reg32>(x86::reg32(5083100) /* 0x4d8fdc */) = cpu.edx;
    // 00482264  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00482266:
    // 00482266  8baac8155600           -mov ebp, dword ptr [edx + 0x5615c8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5641672) /* 0x5615c8 */);
    // 0048226c  39ee                   +cmp esi, ebp
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
    // 0048226e  751e                   -jne 0x48228e
    if (!cpu.flags.zf)
    {
        goto L_0x0048228e;
    }
L_0x00482270:
    // 00482270  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00482272:
    // 00482272  40                     -inc eax
    (cpu.eax)++;
    // 00482273  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00482276  83f810                 +cmp eax, 0x10
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
    // 00482279  7ceb                   -jl 0x482266
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482266;
    }
    // 0048227b  83f9ff                 +cmp ecx, -1
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
    // 0048227e  751e                   -jne 0x48229e
    if (!cpu.flags.zf)
    {
        goto L_0x0048229e;
    }
    // 00482280  ff0ddc8f4d00           -dec dword ptr [0x4d8fdc]
    (app->getMemory<x86::reg32>(x86::reg32(5083100) /* 0x4d8fdc */))--;
    // 00482286  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482289  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048228a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048228b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048228c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048228d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048228e:
    // 0048228e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00482290  75e0                   -jne 0x482272
    if (!cpu.flags.zf)
    {
        goto L_0x00482272;
    }
    // 00482292  83f9ff                 +cmp ecx, -1
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
    // 00482295  75db                   -jne 0x482272
    if (!cpu.flags.zf)
    {
        goto L_0x00482272;
    }
    // 00482297  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482299  74d5                   -je 0x482270
    if (cpu.flags.zf)
    {
        goto L_0x00482270;
    }
    // 0048229b  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048229c  ebd4                   -jmp 0x482272
    goto L_0x00482272;
L_0x0048229e:
    // 0048229e  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004822a1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004822a4  89b1c8155600           -mov dword ptr [ecx + 0x5615c8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641672) /* 0x5615c8 */) = cpu.esi;
    // 004822aa  8981cc155600           -mov dword ptr [ecx + 0x5615cc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641676) /* 0x5615cc */) = cpu.eax;
    // 004822b0  033dc0155600           -add edi, dword ptr [0x5615c0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */)));
    // 004822b6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004822b8  89b9d0155600           -mov dword ptr [ecx + 0x5615d0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641680) /* 0x5615d0 */) = cpu.edi;
    // 004822be  8991d4155600           -mov dword ptr [ecx + 0x5615d4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641684) /* 0x5615d4 */) = cpu.edx;
    // 004822c4  ff0ddc8f4d00           -dec dword ptr [0x4d8fdc]
    (app->getMemory<x86::reg32>(x86::reg32(5083100) /* 0x4d8fdc */))--;
    // 004822ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004822cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4822d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004822d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004822d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004822d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004822d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004822d8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004822da  8b1dc8155600           -mov ebx, dword ptr [0x5615c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641672) /* 0x5615c8 */);
    // 004822e0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004822e2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004822e4  39d9                   +cmp ecx, ebx
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
    // 004822e6  7413                   -je 0x4822fb
    if (cpu.flags.zf)
    {
        goto L_0x004822fb;
    }
L_0x004822e8:
    // 004822e8  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004822eb  42                     -inc edx
    (cpu.edx)++;
    // 004822ec  3d00010000             +cmp eax, 0x100
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
    // 004822f1  7d08                   -jge 0x4822fb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004822fb;
    }
    // 004822f3  3b88c8155600           +cmp ecx, dword ptr [eax + 0x5615c8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5641672) /* 0x5615c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004822f9  75ed                   -jne 0x4822e8
    if (!cpu.flags.zf)
    {
        goto L_0x004822e8;
    }
L_0x004822fb:
    // 004822fb  83fa10                 +cmp edx, 0x10
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
    // 004822fe  7d0b                   -jge 0x48230b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048230b;
    }
    // 00482300  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00482303  3b8ac8155600           +cmp ecx, dword ptr [edx + 0x5615c8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5641672) /* 0x5615c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482309  7405                   -je 0x482310
    if (cpu.flags.zf)
    {
        goto L_0x00482310;
    }
L_0x0048230b:
    // 0048230b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048230c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048230d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048230e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048230f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482310:
    // 00482310  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00482312  89aac8155600           -mov dword ptr [edx + 0x5615c8], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5641672) /* 0x5615c8 */) = cpu.ebp;
    // 00482318  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482319  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048231a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048231b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048231c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482322  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482323  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482324  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482325  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482326  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482328  a1e08f4d00             -mov eax, dword ptr [0x4d8fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083104) /* 0x4d8fe0 */);
    // 0048232d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048232f  3b05c0155600           +cmp eax, dword ptr [0x5615c0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */)));
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
    // 00482335  0f8470000000           -je 0x4823ab
    if (cpu.flags.zf)
    {
        goto L_0x004823ab;
    }
    // 0048233b  a1c0155600             -mov eax, dword ptr [0x5615c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */);
    // 00482340  a3e08f4d00             -mov dword ptr [0x4d8fe0], eax
    app->getMemory<x86::reg32>(x86::reg32(5083104) /* 0x4d8fe0 */) = cpu.eax;
    // 00482345  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00482347:
    // 00482347  8b99c8155600           -mov ebx, dword ptr [ecx + 0x5615c8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641672) /* 0x5615c8 */);
    // 0048234d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048234f  744f                   -je 0x4823a0
    if (cpu.flags.zf)
    {
        goto L_0x004823a0;
    }
    // 00482351  a1c0155600             -mov eax, dword ptr [0x5615c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */);
    // 00482356  3b81d0155600           +cmp eax, dword ptr [ecx + 0x5615d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641680) /* 0x5615d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048235c  7c42                   -jl 0x4823a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004823a0;
    }
    // 0048235e  83b9d415560000         +cmp dword ptr [ecx + 0x5615d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641684) /* 0x5615d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482365  7539                   -jne 0x4823a0
    if (!cpu.flags.zf)
    {
        goto L_0x004823a0;
    }
    // 00482367  c781d415560001000000   -mov dword ptr [ecx + 0x5615d4], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641684) /* 0x5615d4 */) = 1 /*0x1*/;
    // 00482371  8b15c0155600           -mov edx, dword ptr [0x5615c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */);
    // 00482377  8ba9d0155600           -mov ebp, dword ptr [ecx + 0x5615d0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641680) /* 0x5615d0 */);
    // 0048237d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048237f  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00482381  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482383  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00482385  a1c0155600             -mov eax, dword ptr [0x5615c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */);
    // 0048238a  8b91cc155600           -mov edx, dword ptr [ecx + 0x5615cc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641676) /* 0x5615cc */);
    // 00482390  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482392  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482394  8999d4155600           -mov dword ptr [ecx + 0x5615d4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641684) /* 0x5615d4 */) = cpu.ebx;
    // 0048239a  8981d0155600           -mov dword ptr [ecx + 0x5615d0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5641680) /* 0x5615d0 */) = cpu.eax;
L_0x004823a0:
    // 004823a0  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004823a3  81f900010000           +cmp ecx, 0x100
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
    // 004823a9  759c                   -jne 0x482347
    if (!cpu.flags.zf)
    {
        goto L_0x00482347;
    }
L_0x004823ab:
    // 004823ab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004823ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4823b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004823b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004823b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004823b6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004823b8  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 004823bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004823bf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004823c1:
    // 004823c1  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 004823c6  39c8                   +cmp eax, ecx
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
    // 004823c8  7d04                   -jge 0x4823ce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004823ce;
    }
    // 004823ca  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004823cc  7405                   -je 0x4823d3
    if (cpu.flags.zf)
    {
        goto L_0x004823d3;
    }
L_0x004823ce:
    // 004823ce  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004823d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004823d3:
    // 004823d3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004823d5  e846ffffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 004823da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004823dc  ebe3                   -jmp 0x4823c1
    goto L_0x004823c1;
}

/* align: skip 0x00 0x00 */
void Application::sub_4823e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004823e0  ff05e48f4d00           -inc dword ptr [0x4d8fe4]
    (app->getMemory<x86::reg32>(x86::reg32(5083108) /* 0x4d8fe4 */))++;
    // 004823e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4823e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004823e8  833d0c1b560000         +cmp dword ptr [0x561b0c], 0
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
    // 004823ef  7509                   -jne 0x4823fa
    if (!cpu.flags.zf)
    {
        goto L_0x004823fa;
    }
    // 004823f1  833de88f4d0000         +cmp dword ptr [0x4d8fe8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083112) /* 0x4d8fe8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004823f8  7406                   -je 0x482400
    if (cpu.flags.zf)
    {
        goto L_0x00482400;
    }
L_0x004823fa:
    // 004823fa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004823ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482400:
    // 00482400  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482402  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00482400;
    // 004823e8  833d0c1b560000         +cmp dword ptr [0x561b0c], 0
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
    // 004823ef  7509                   -jne 0x4823fa
    if (!cpu.flags.zf)
    {
        goto L_0x004823fa;
    }
    // 004823f1  833de88f4d0000         +cmp dword ptr [0x4d8fe8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083112) /* 0x4d8fe8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004823f8  7406                   -je 0x482400
    if (cpu.flags.zf)
    {
        goto L_0x00482400;
    }
L_0x004823fa:
    // 004823fa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004823ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482400:
L_entry_0x00482400:
    // 00482400  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482402  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482404  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482406  a02f1b5600             -mov al, byte ptr [0x561b2f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643055) /* 0x561b2f */);
    // 0048240b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48240c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048240c  803d301b560000         +cmp byte ptr [0x561b30], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5643056) /* 0x561b30 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482413  74eb                   -je 0x482400
    if (cpu.flags.zf)
    {
        return sub_482400(app, cpu);
    }
    // 00482415  803d051b560000         +cmp byte ptr [0x561b05], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5643013) /* 0x561b05 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048241c  75e2                   -jne 0x482400
    if (!cpu.flags.zf)
    {
        return sub_482400(app, cpu);
    }
    // 0048241e  803d041b560000         +cmp byte ptr [0x561b04], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5643012) /* 0x561b04 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482425  75d9                   -jne 0x482400
    if (!cpu.flags.zf)
    {
        return sub_482400(app, cpu);
    }
    // 00482427  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048242c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482430  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482432  a0321b5600             -mov al, byte ptr [0x561b32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643058) /* 0x561b32 */);
    // 00482437  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482438(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482438  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048243b  833d90904d0000         +cmp dword ptr [0x4d9090], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083280) /* 0x4d9090 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482442  741c                   -je 0x482460
    if (cpu.flags.zf)
    {
        goto L_0x00482460;
    }
    // 00482444  833d68b54d0000         +cmp dword ptr [0x4db568], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092712) /* 0x4db568 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048244b  741c                   -je 0x482469
    if (cpu.flags.zf)
    {
        goto L_0x00482469;
    }
    // 0048244d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048244f  e84cd70100             -call 0x49fba0
    cpu.esp -= 4;
    sub_49fba0(app, cpu);
    if (cpu.terminate) return;
    // 00482454  e8d3e4ffff             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 00482459  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048245b  e864d70100             -call 0x49fbc4
    cpu.esp -= 4;
    sub_49fbc4(app, cpu);
    if (cpu.terminate) return;
L_0x00482460:
    // 00482460  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482465  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00482468  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482469:
    // 00482469  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0048246e  e8b1a80000             -call 0x48cd24
    cpu.esp -= 4;
    sub_48cd24(app, cpu);
    if (cpu.terminate) return;
    // 00482473  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00482476  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482478(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482478  833d441b560000         +cmp dword ptr [0x561b44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643076) /* 0x561b44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048247f  0f847bffffff           -je 0x482400
    if (cpu.flags.zf)
    {
        return sub_482400(app, cpu);
    }
    // 00482485  833d241b560000         +cmp dword ptr [0x561b24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048248c  0f846effffff           -je 0x482400
    if (cpu.flags.zf)
    {
        return sub_482400(app, cpu);
    }
    // 00482492  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00482494  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482499  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48249c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048249c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048249d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048249e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048249f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004824a1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004824a3  2eff15cc434c00         -call dword ptr cs:[0x4c43cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998092) /* 0x4c43cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004824aa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004824ac  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004824ae  2eff15cc434c00         -call dword ptr cs:[0x4c43cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998092) /* 0x4c43cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004824b5  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004824bc  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004824bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004824c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004824c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004824c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4824c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004824c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004824c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004824c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004824c7  833d60894d0000         +cmp dword ptr [0x4d8960], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081440) /* 0x4d8960 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004824ce  750c                   -jne 0x4824dc
    if (!cpu.flags.zf)
    {
        goto L_0x004824dc;
    }
    // 004824d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004824d2  746c                   -je 0x482540
    if (cpu.flags.zf)
    {
        goto L_0x00482540;
    }
    // 004824d4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004824d6:
    // 004824d6  891d60894d00           -mov dword ptr [0x4d8960], ebx
    app->getMemory<x86::reg32>(x86::reg32(5081440) /* 0x4d8960 */) = cpu.ebx;
L_0x004824dc:
    // 004824dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004824de  7505                   -jne 0x4824e5
    if (!cpu.flags.zf)
    {
        goto L_0x004824e5;
    }
    // 004824e0  a160894d00             -mov eax, dword ptr [0x4d8960]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081440) /* 0x4d8960 */);
L_0x004824e5:
    // 004824e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004824e6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004824e8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004824ea  2eff1538444c00         -call dword ptr cs:[0x4c4438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998200) /* 0x4c4438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004824f1  a3481b5600             -mov dword ptr [0x561b48], eax
    app->getMemory<x86::reg32>(x86::reg32(5643080) /* 0x561b48 */) = cpu.eax;
    // 004824f6  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004824fd  3db7000000             +cmp eax, 0xb7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482502  7536                   -jne 0x48253a
    if (!cpu.flags.zf)
    {
        goto L_0x0048253a;
    }
    // 00482504  8b0d60894d00           -mov ecx, dword ptr [0x4d8960]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081440) /* 0x4d8960 */);
    // 0048250a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048250b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048250d  2eff15b4434c00         -call dword ptr cs:[0x4c43b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998068) /* 0x4c43b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482514  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482516  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482518  7412                   -je 0x48252c
    if (cpu.flags.zf)
    {
        goto L_0x0048252c;
    }
    // 0048251a  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0048251c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048251d  2eff150c444c00         -call dword ptr cs:[0x4c440c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998156) /* 0x4c440c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482524  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482525  2eff15fc434c00         -call dword ptr cs:[0x4c43fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998140) /* 0x4c43fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048252c:
    // 0048252c  833df08f4d0000         +cmp dword ptr [0x4d8ff0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083120) /* 0x4d8ff0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482533  7415                   -je 0x48254a
    if (cpu.flags.zf)
    {
        goto L_0x0048254a;
    }
    // 00482535  e8ab370100             -call 0x495ce5
    cpu.esp -= 4;
    sub_495ce5(app, cpu);
    if (cpu.terminate) return;
L_0x0048253a:
    // 0048253a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048253c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048253d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048253e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048253f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482540:
    // 00482540  8b1d0cea5600           -mov ebx, dword ptr [0x56ea0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696012) /* 0x56ea0c */);
    // 00482546  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00482548  eb8c                   -jmp 0x4824d6
    goto L_0x004824d6;
L_0x0048254a:
    // 0048254a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048254f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482550  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482551  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482552  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482562  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482563  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482564  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482565  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482566  81ec04030000           -sub esp, 0x304
    (cpu.esp) -= x86::reg32(x86::sreg32(772 /*0x304*/));
    // 0048256c  8b1504904d00           -mov edx, dword ptr [0x4d9004]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083140) /* 0x4d9004 */);
    // 00482572  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00482574  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482576  0f8582010000           -jne 0x4826fe
    if (!cpu.flags.zf)
    {
        goto L_0x004826fe;
    }
    // 0048257c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00482581  8b9c2420030000         -mov ebx, dword ptr [esp + 0x320]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 00482588  890d04904d00           -mov dword ptr [0x4d9004], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083140) /* 0x4d9004 */) = cpu.ecx;
    // 0048258e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482590  0f8575010000           -jne 0x48270b
    if (!cpu.flags.zf)
    {
        goto L_0x0048270b;
    }
    // 00482596  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00482598  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x0048259b:
    // 0048259b  833d1c8a4d0000         +cmp dword ptr [0x4d8a1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081628) /* 0x4d8a1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004825a2  0f8592010000           -jne 0x48273a
    if (!cpu.flags.zf)
    {
        goto L_0x0048273a;
    }
L_0x004825a8:
    // 004825a8  833d188a4d0000         +cmp dword ptr [0x4d8a18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081624) /* 0x4d8a18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004825af  0f84a4000000           -je 0x482659
    if (cpu.flags.zf)
    {
        goto L_0x00482659;
    }
    // 004825b5  8b15f48f4d00           -mov edx, dword ptr [0x4d8ff4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */);
    // 004825bb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004825bd  7448                   -je 0x482607
    if (cpu.flags.zf)
    {
        goto L_0x00482607;
    }
    // 004825bf  8b0df88f4d00           -mov ecx, dword ptr [0x4d8ff8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */);
    // 004825c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004825c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004825c7  68c0d84c00             -push 0x4cd8c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036224 /*0x4cd8c0*/;
    cpu.esp -= 4;
    // 004825cc  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004825d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004825d4  e898230000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 004825d9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004825dc  8db42400020000         -lea esi, [esp + 0x200]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004825e3  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004825e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004825e6  2bc9                   +sub ecx, ecx
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
    // 004825e8  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004825e9  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004825eb  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004825ed  4f                     -dec edi
    (cpu.edi)--;
L_0x004825ee:
    // 004825ee  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004825f0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004825f2  3c00                   +cmp al, 0
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
    // 004825f4  7410                   -je 0x482606
    if (cpu.flags.zf)
    {
        goto L_0x00482606;
    }
    // 004825f6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004825f9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004825fc  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004825ff  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00482602  3c00                   +cmp al, 0
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
    // 00482604  75e8                   -jne 0x4825ee
    if (!cpu.flags.zf)
    {
        goto L_0x004825ee;
    }
L_0x00482606:
    // 00482606  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482607:
    // 00482607  8b35fc8f4d00           -mov esi, dword ptr [0x4d8ffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083132) /* 0x4d8ffc */);
    // 0048260d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048260f  7448                   -je 0x482659
    if (cpu.flags.zf)
    {
        goto L_0x00482659;
    }
    // 00482611  8b3d00904d00           -mov edi, dword ptr [0x4d9000]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5083136) /* 0x4d9000 */);
    // 00482617  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482618  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482619  68d4d84c00             -push 0x4cd8d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036244 /*0x4cd8d4*/;
    cpu.esp -= 4;
    // 0048261e  8d84248c020000         -lea eax, [esp + 0x28c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(652) /* 0x28c */);
    // 00482625  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482626  e846230000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 0048262b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048262e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00482630  8db42480020000         -lea esi, [esp + 0x280]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 00482637  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482638  2bc9                   +sub ecx, ecx
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
    // 0048263a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048263b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048263d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048263f  4f                     -dec edi
    (cpu.edi)--;
L_0x00482640:
    // 00482640  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00482642  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00482644  3c00                   +cmp al, 0
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
    // 00482646  7410                   -je 0x482658
    if (cpu.flags.zf)
    {
        goto L_0x00482658;
    }
    // 00482648  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048264b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048264e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00482651  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00482654  3c00                   +cmp al, 0
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
    // 00482656  75e8                   -jne 0x482640
    if (!cpu.flags.zf)
    {
        goto L_0x00482640;
    }
L_0x00482658:
    // 00482658  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482659:
    // 00482659  833d0c8a4d0000         +cmp dword ptr [0x4d8a0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081612) /* 0x4d8a0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482660  7411                   -je 0x482673
    if (cpu.flags.zf)
    {
        goto L_0x00482673;
    }
    // 00482662  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00482664  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482665  2eff1528454c00         -call dword ptr cs:[0x4c4528]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998440) /* 0x4c4528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048266c  2eff1540444c00         -call dword ptr cs:[0x4c4440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998208) /* 0x4c4440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00482673:
    // 00482673  833d208a4d0000         +cmp dword ptr [0x4d8a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081632) /* 0x4d8a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048267a  7408                   -je 0x482684
    if (cpu.flags.zf)
    {
        goto L_0x00482684;
    }
    // 0048267c  ff15208a4d00           -call dword ptr [0x4d8a20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5081632) /* 0x4d8a20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482682  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00482684:
    // 00482684  833d248a4d0000         +cmp dword ptr [0x4d8a24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081636) /* 0x4d8a24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048268b  7406                   -je 0x482693
    if (cpu.flags.zf)
    {
        goto L_0x00482693;
    }
    // 0048268d  ff15248a4d00           -call dword ptr [0x4d8a24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5081636) /* 0x4d8a24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00482693:
    // 00482693  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482695  2eff1508444c00         -call dword ptr cs:[0x4c4408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998152) /* 0x4c4408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048269c  6831100100             -push 0x11031
    app->getMemory<x86::reg32>(cpu.esp-4) = 69681 /*0x11031*/;
    cpu.esp -= 4;
    // 004826a1  68f4d84c00             -push 0x4cd8f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036276 /*0x4cd8f4*/;
    cpu.esp -= 4;
    // 004826a6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004826aa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004826ab  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004826ad  2eff15d8434c00         -call dword ptr cs:[0x4c43d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998104) /* 0x4c43d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004826b4  83f801                 +cmp eax, 1
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
    // 004826b7  7528                   -jne 0x4826e1
    if (!cpu.flags.zf)
    {
        goto L_0x004826e1;
    }
    // 004826b9  833d108a4d0000         +cmp dword ptr [0x4d8a10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081616) /* 0x4d8a10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004826c0  741f                   -je 0x4826e1
    if (cpu.flags.zf)
    {
        goto L_0x004826e1;
    }
    // 004826c2  833d148a4d0000         +cmp dword ptr [0x4d8a14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081620) /* 0x4d8a14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004826c9  7416                   -je 0x4826e1
    if (cpu.flags.zf)
    {
        goto L_0x004826e1;
    }
    // 004826cb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004826cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004826ce  6804d94c00             -push 0x4cd904
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036292 /*0x4cd904*/;
    cpu.esp -= 4;
    // 004826d3  e8e4350100             -call 0x495cbc
    cpu.esp -= 4;
    sub_495cbc(app, cpu);
    if (cpu.terminate) return;
    // 004826d8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004826db  ff15148a4d00           -call dword ptr [0x4d8a14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5081620) /* 0x4d8a14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004826e1:
    // 004826e1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004826e3  7407                   -je 0x4826ec
    if (cpu.flags.zf)
    {
        goto L_0x004826ec;
    }
    // 004826e5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004826e7  e8e45c0000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x004826ec:
    // 004826ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004826ee  e865590000             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 004826f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004826f5  745a                   -je 0x482751
    if (cpu.flags.zf)
    {
        goto L_0x00482751;
    }
    // 004826f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004826f9  e8a3500100             -call 0x4977a1
    cpu.esp -= 4;
    sub_4977a1(app, cpu);
    if (cpu.terminate) return;
L_0x004826fe:
    // 004826fe  81c404030000           +add esp, 0x304
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(772 /*0x304*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00482704  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482705  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482706  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482707  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482708  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482709  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048270a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048270b:
    // 0048270b  8d842424030000         -lea eax, [esp + 0x324]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 00482712  8d9c2400030000         -lea ebx, [esp + 0x300]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00482719  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 00482720  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 00482727  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00482729  e8c6d40100             -call 0x49fbf4
    cpu.esp -= 4;
    sub_49fbf4(app, cpu);
    if (cpu.terminate) return;
    // 0048272e  89ac2400030000         -mov dword ptr [esp + 0x300], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.ebp;
    // 00482735  e961feffff             -jmp 0x48259b
    goto L_0x0048259b;
L_0x0048273a:
    // 0048273a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048273c  ff151c8a4d00           -call dword ptr [0x4d8a1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5081628) /* 0x4d8a1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482742  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482744  0f855efeffff           -jne 0x4825a8
    if (!cpu.flags.zf)
    {
        goto L_0x004825a8;
    }
    // 0048274a  a304904d00             -mov dword ptr [0x4d9004], eax
    app->getMemory<x86::reg32>(x86::reg32(5083140) /* 0x4d9004 */) = cpu.eax;
    // 0048274f  ebad                   -jmp 0x4826fe
    goto L_0x004826fe;
L_0x00482751:
    // 00482751  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482752  2eff1558444c00         -call dword ptr cs:[0x4c4458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998232) /* 0x4c4458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482759  81c404030000           -add esp, 0x304
    (cpu.esp) += x86::reg32(x86::sreg32(772 /*0x304*/));
    // 0048275f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482760  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482761  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482762  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482763  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482764  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482765  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_482770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482770  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482771  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482772  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482773  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482775  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482777  e894d40100             -call 0x49fc10
    cpu.esp -= 4;
    sub_49fc10(app, cpu);
    if (cpu.terminate) return;
    // 0048277c  a3d01c5600             -mov dword ptr [0x561cd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */) = cpu.eax;
    // 00482781  e8aad40100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 00482786  b8501b5600             -mov eax, 0x561b50
    cpu.eax = 5643088 /*0x561b50*/;
    // 0048278b  891514904d00           -mov dword ptr [0x4d9014], edx
    app->getMemory<x86::reg32>(x86::reg32(5083156) /* 0x4d9014 */) = cpu.edx;
    // 00482791  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 00482796  e8f15c0000             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048279b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048279d  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048279f  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 004827a6  a114904d00             -mov eax, dword ptr [0x4d9014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083156) /* 0x4d9014 */);
    // 004827ab  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004827ad  e8fe090000             -call 0x4831b0
    cpu.esp -= 4;
    sub_4831b0(app, cpu);
    if (cpu.terminate) return;
    // 004827b2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004827b4  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004827b6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004827b8  b808d94c00             -mov eax, 0x4cd908
    cpu.eax = 5036296 /*0x4cd908*/;
    // 004827bd  8b1d14904d00           -mov ebx, dword ptr [0x4d9014]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083156) /* 0x4d9014 */);
    // 004827c3  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004827c5  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 004827c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004827ca  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004827cc  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004827ce  893510904d00           -mov dword ptr [0x4d9010], esi
    app->getMemory<x86::reg32>(x86::reg32(5083152) /* 0x4d9010 */) = cpu.esi;
    // 004827d4  e823000000             -call 0x4827fc
    cpu.esp -= 4;
    sub_4827fc(app, cpu);
    if (cpu.terminate) return;
    // 004827d9  a110904d00             -mov eax, dword ptr [0x4d9010]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083152) /* 0x4d9010 */);
    // 004827de  8b1514904d00           -mov edx, dword ptr [0x4d9014]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083156) /* 0x4d9014 */);
    // 004827e4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004827e6  a3dc1c5600             -mov dword ptr [0x561cdc], eax
    app->getMemory<x86::reg32>(x86::reg32(5643484) /* 0x561cdc */) = cpu.eax;
    // 004827eb  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 004827f0  e843d40100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 004827f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4827fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004827fc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004827fd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004827fe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004827ff  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482801  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00482803  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00482805  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00482807  81e1000f0000           -and ecx, 0xf00
    cpu.ecx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0048280d  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00482810  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 00482817  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482819  b9501b5600             -mov ecx, 0x561b50
    cpu.ecx = 5643088 /*0x561b50*/;
    // 0048281e  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00482821  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00482825  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482827  48                     -dec eax
    (cpu.eax)--;
    // 00482828  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048282b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048282f  48                     -dec eax
    (cpu.eax)--;
    // 00482830  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00482833  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00482837  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048283b  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048283e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482840  7405                   -je 0x482847
    if (cpu.flags.zf)
    {
        goto L_0x00482847;
    }
    // 00482842  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x00482847:
    // 00482847  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048284a  8b15d41c5600           -mov edx, dword ptr [0x561cd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */);
    // 00482850  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482851  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00482854  6810d94c00             -push 0x4cd910
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036304 /*0x4cd910*/;
    cpu.esp -= 4;
    // 00482859  a3d41c5600             -mov dword ptr [0x561cd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */) = cpu.eax;
    // 0048285e  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00482861  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482862  e80a210000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00482867  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0048286e  c7422400000000         -mov dword ptr [edx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00482875  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00482878  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048287b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048287d  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0048287f  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00482882  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00482885  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00482888  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0048288a  8b15d41c5600           -mov edx, dword ptr [0x561cd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */);
    // 00482890  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482891  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00482894  681cd94c00             -push 0x4cd91c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036316 /*0x4cd91c*/;
    cpu.esp -= 4;
    // 00482899  891dd41c5600           -mov dword ptr [0x561cd4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */) = cpu.ebx;
    // 0048289f  8d5a04                 -lea ebx, [edx + 4]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004828a2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004828a3  e8c9200000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 004828a8  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004828af  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004828b6  6681ce2080             -or si, 0x8020
    cpu.si |= x86::reg16(x86::sreg16(32800 /*0x8020*/));
    // 004828bb  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004828bd  897218                 -mov dword ptr [edx + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004828c0  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004828c3  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004828c6  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004828c8  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004828cb  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004828ce  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004828d1  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004828d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004828d5  895a24                 -mov dword ptr [edx + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004828d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828db  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4828e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004828e0  c70528904d00f0cb4900   -mov dword ptr [0x4d9028], 0x49cbf0
    app->getMemory<x86::reg32>(x86::reg32(5083176) /* 0x4d9028 */) = 4836336 /*0x49cbf0*/;
    // 004828ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4828ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004828ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004828ed  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004828f2  e84d000000             -call 0x482944
    cpu.esp -= 4;
    sub_482944(app, cpu);
    if (cpu.terminate) return;
    // 004828f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4828fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004828fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004828fd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004828ff  e840000000             -call 0x482944
    cpu.esp -= 4;
    sub_482944(app, cpu);
    if (cpu.terminate) return;
    // 00482904  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482905  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482908(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482908  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482909  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048290e  e831000000             -call 0x482944
    cpu.esp -= 4;
    sub_482944(app, cpu);
    if (cpu.terminate) return;
    // 00482913  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482915  7502                   -jne 0x482919
    if (!cpu.flags.zf)
    {
        goto L_0x00482919;
    }
    // 00482917  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482918  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482919:
    // 00482919  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048291b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048291c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482920  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482921  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482923  e81c000000             -call 0x482944
    cpu.esp -= 4;
    sub_482944(app, cpu);
    if (cpu.terminate) return;
    // 00482928  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048292a  7502                   -jne 0x48292e
    if (!cpu.flags.zf)
    {
        goto L_0x0048292e;
    }
    // 0048292c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048292d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048292e:
    // 0048292e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00482930  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482931  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482934(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482934  e80b000000             -call 0x482944
    cpu.esp -= 4;
    sub_482944(app, cpu);
    if (cpu.terminate) return;
    // 00482939  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048293b  7503                   -jne 0x482940
    if (!cpu.flags.zf)
    {
        goto L_0x00482940;
    }
    // 0048293d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0048293e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00482940:
    // 00482940  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00482942  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00482940;
    // 00482934  e80b000000             -call 0x482944
    cpu.esp -= 4;
    sub_482944(app, cpu);
    if (cpu.terminate) return;
    // 00482939  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048293b  7503                   -jne 0x482940
    if (!cpu.flags.zf)
    {
        goto L_0x00482940;
    }
    // 0048293d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0048293e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00482940:
L_entry_0x00482940:
    // 00482940  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00482942  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482944(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482944  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482945  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482946  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482947  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482949  8b3dd01c5600           -mov edi, dword ptr [0x561cd0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0048294f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00482951  7407                   -je 0x48295a
    if (cpu.flags.zf)
    {
        goto L_0x0048295a;
    }
    // 00482953  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482955  e8d6d20100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
L_0x0048295a:
    // 0048295a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048295c  e81f000000             -call 0x482980
    cpu.esp -= 4;
    sub_482980(app, cpu);
    if (cpu.terminate) return;
    // 00482961  8b2dd01c5600           -mov ebp, dword ptr [0x561cd0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482967  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482969  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048296b  7506                   -jne 0x482973
    if (!cpu.flags.zf)
    {
        goto L_0x00482973;
    }
    // 0048296d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048296f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482970  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482971  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482972  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482973:
    // 00482973  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00482975  e8bed20100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0048297a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048297c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482980  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482981  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482982  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482983  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482986  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048298a  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048298e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00482990  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00482996  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00482999  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004829a0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004829a2  b9501b5600             -mov ecx, 0x561b50
    cpu.ecx = 5643088 /*0x561b50*/;
    // 004829a7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004829aa  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004829ac  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004829b0  e88bd20100             -call 0x49fc40
    cpu.esp -= 4;
    sub_49fc40(app, cpu);
    if (cpu.terminate) return;
    // 004829b5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004829b9  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 004829bc  0f850a010000           -jne 0x482acc
    if (!cpu.flags.zf)
    {
        goto L_0x00482acc;
    }
    // 004829c2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004829c6  034114                 -add eax, dword ptr [ecx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004829c9  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004829cc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004829ce  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x004829d1:
    // 004829d1  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004829d3  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 004829d5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004829d8  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 004829da  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004829dc  0f84b6010000           -je 0x482b98
    if (cpu.flags.zf)
    {
        goto L_0x00482b98;
    }
    // 004829e2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004829e4  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004829e9  3d00030000             +cmp eax, 0x300
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004829ee  0f84ee000000           -je 0x482ae2
    if (cpu.flags.zf)
    {
        goto L_0x00482ae2;
    }
    // 004829f4  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004829f7  0f85d2010000           -jne 0x482bcf
    if (!cpu.flags.zf)
    {
        goto L_0x00482bcf;
    }
    // 004829fd  833d20904d0000         +cmp dword ptr [0x4d9020], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083168) /* 0x4d9020 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482a04  0f8542010000           -jne 0x482b4c
    if (!cpu.flags.zf)
    {
        goto L_0x00482b4c;
    }
L_0x00482a0a:
    // 00482a0a  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00482a0c  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00482a0f  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00482a11  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00482a14  0f854a010000           -jne 0x482b64
    if (!cpu.flags.zf)
    {
        goto L_0x00482b64;
    }
L_0x00482a1a:
    // 00482a1a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00482a1c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482a1e  39c7                   +cmp edi, eax
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
L_0x00482a20:
    // 00482a20  0f824f010000           -jb 0x482b75
    if (cpu.flags.cf)
    {
        goto L_0x00482b75;
    }
    // 00482a26  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00482a28  037e10                 -add edi, dword ptr [esi + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00482a2b  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00482a2e  740c                   -je 0x482a3c
    if (cpu.flags.zf)
    {
        goto L_0x00482a3c;
    }
    // 00482a30  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482a33  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00482a35  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482a38  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 00482a3a  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
L_0x00482a3c:
    // 00482a3c  3b7104                 +cmp esi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482a3f  0f8539010000           -jne 0x482b7e
    if (!cpu.flags.zf)
    {
        goto L_0x00482b7e;
    }
L_0x00482a45:
    // 00482a45  3b1424                 +cmp edx, dword ptr [esp]
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
    // 00482a48  0f8c3a010000           -jl 0x482b88
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482b88;
    }
    // 00482a4e  8b2dd41c5600           -mov ebp, dword ptr [0x561cd4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */);
    // 00482a54  8b151c904d00           -mov edx, dword ptr [0x4d901c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */);
    // 00482a5a  895d18                 -mov dword ptr [ebp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00482a5d  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00482a61  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00482a64  89551c                 -mov dword ptr [ebp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00482a67  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00482a6c  a3d41c5600             -mov dword ptr [0x561cd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */) = cpu.eax;
    // 00482a71  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00482a75  42                     -inc edx
    (cpu.edx)++;
    // 00482a76  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00482a79  89151c904d00           -mov dword ptr [0x4d901c], edx
    app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */) = cpu.edx;
    // 00482a7f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00482a82  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00482a86  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00482a89  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00482a8c  e8bb1e0000             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 00482a91  897d00                 -mov dword ptr [ebp], edi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edi;
    // 00482a94  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482a97  894524                 -mov dword ptr [ebp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00482a9a  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00482a9d  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482aa0  896820                 -mov dword ptr [eax + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00482aa3  896e24                 -mov dword ptr [esi + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 00482aa6  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482aaa  7407                   -je 0x482ab3
    if (cpu.flags.zf)
    {
        goto L_0x00482ab3;
    }
    // 00482aac  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00482aae  e8cdd10100             -call 0x49fc80
    cpu.esp -= 4;
    sub_49fc80(app, cpu);
    if (cpu.terminate) return;
L_0x00482ab3:
    // 00482ab3  833d20904d0000         +cmp dword ptr [0x4d9020], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083168) /* 0x4d9020 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482aba  7405                   -je 0x482ac1
    if (cpu.flags.zf)
    {
        goto L_0x00482ac1;
    }
    // 00482abc  e8c3040000             -call 0x482f84
    cpu.esp -= 4;
    sub_482f84(app, cpu);
    if (cpu.terminate) return;
L_0x00482ac1:
    // 00482ac1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x00482ac5:
    // 00482ac5  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482ac8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ac9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482aca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482acb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482acc:
    // 00482acc  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00482ad0  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00482ad3  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482ad6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00482ad8  01c2                   +add edx, eax
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
    // 00482ada  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482add  e9effeffff             -jmp 0x4829d1
    goto L_0x004829d1;
L_0x00482ae2:
    // 00482ae2  8b0dd41c5600           -mov ecx, dword ptr [0x561cd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */);
    // 00482ae8  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00482aeb  a3d41c5600             -mov dword ptr [0x561cd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */) = cpu.eax;
    // 00482af0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00482af2  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00482af5  e84a4f0100             -call 0x497a44
    cpu.esp -= 4;
    sub_497a44(app, cpu);
    if (cpu.terminate) return;
    // 00482afa  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00482afc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482afe  74c5                   -je 0x482ac5
    if (cpu.flags.zf)
    {
        goto L_0x00482ac5;
    }
    // 00482b00  8b151c904d00           -mov edx, dword ptr [0x4d901c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */);
    // 00482b06  895918                 -mov dword ptr [ecx + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00482b09  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00482b0d  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00482b10  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00482b15  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00482b18  42                     -inc edx
    (cpu.edx)++;
    // 00482b19  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00482b1c  89151c904d00           -mov dword ptr [0x4d901c], edx
    app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */) = cpu.edx;
    // 00482b22  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00482b25  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00482b29  8d4104                 -lea eax, [ecx + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00482b2c  e81b1e0000             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 00482b31  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482b34  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00482b37  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00482b3a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482b3d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00482b40  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482b42  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00482b45  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482b48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482b4c:
    // 00482b4c  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00482b4f  0f85b5feffff           -jne 0x482a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00482a0a;
    }
    // 00482b55  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00482b57  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00482b5a  e859d20100             -call 0x49fdb8
    cpu.esp -= 4;
    sub_49fdb8(app, cpu);
    if (cpu.terminate) return;
    // 00482b5f  e9a6feffff             -jmp 0x482a0a
    goto L_0x00482a0a;
L_0x00482b64:
    // 00482b64  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482b67  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00482b69  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482b6c  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 00482b6e  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482b70  e9a5feffff             -jmp 0x482a1a
    goto L_0x00482a1a;
L_0x00482b75:
    // 00482b75  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00482b77  29fa                   +sub edx, edi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00482b79  e9c7feffff             -jmp 0x482a45
    goto L_0x00482a45;
L_0x00482b7e:
    // 00482b7e  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00482b81  3b3e                   +cmp edi, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482b83  e998feffff             -jmp 0x482a20
    goto L_0x00482a20;
L_0x00482b88:
    // 00482b88  3b7104                 +cmp esi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482b8b  7514                   -jne 0x482ba1
    if (!cpu.flags.zf)
    {
        goto L_0x00482ba1;
    }
    // 00482b8d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482b8f  e8e4d40100             -call 0x4a0078
    cpu.esp -= 4;
    sub_4a0078(app, cpu);
    if (cpu.terminate) return;
    // 00482b94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482b96  7528                   -jne 0x482bc0
    if (!cpu.flags.zf)
    {
        goto L_0x00482bc0;
    }
L_0x00482b98:
    // 00482b98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482b9a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482b9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ba0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482ba1:
    // 00482ba1  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00482ba3  037e10                 -add edi, dword ptr [esi + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00482ba6  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00482ba9  7508                   -jne 0x482bb3
    if (!cpu.flags.zf)
    {
        goto L_0x00482bb3;
    }
L_0x00482bab:
    // 00482bab  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00482bae  e967feffff             -jmp 0x482a1a
    goto L_0x00482a1a;
L_0x00482bb3:
    // 00482bb3  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482bb6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482bb8  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482bba  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00482bbc  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482bbe  ebeb                   -jmp 0x482bab
    goto L_0x00482bab;
L_0x00482bc0:
    // 00482bc0  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00482bc2  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00482bc5  e8eed10100             -call 0x49fdb8
    cpu.esp -= 4;
    sub_49fdb8(app, cpu);
    if (cpu.terminate) return;
    // 00482bca  e93bfeffff             -jmp 0x482a0a
    goto L_0x00482a0a;
L_0x00482bcf:
    // 00482bcf  833d20904d0000         +cmp dword ptr [0x4d9020], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083168) /* 0x4d9020 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482bd6  0f85c8000000           -jne 0x482ca4
    if (!cpu.flags.zf)
    {
        goto L_0x00482ca4;
    }
L_0x00482bdc:
    // 00482bdc  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00482bdf  8b7724                 -mov esi, dword ptr [edi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00482be2  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00482be4  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00482be7  0f85cf000000           -jne 0x482cbc
    if (!cpu.flags.zf)
    {
        goto L_0x00482cbc;
    }
L_0x00482bed:
    // 00482bed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482bef  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00482bf3:
    // 00482bf3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00482bf5  034610                 -add eax, dword ptr [esi + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00482bf8  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00482bfb  740c                   -je 0x482c09
    if (cpu.flags.zf)
    {
        goto L_0x00482c09;
    }
    // 00482bfd  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482c00  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482c02  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482c05  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00482c07  21d0                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
L_0x00482c09:
    // 00482c09  39f8                   +cmp eax, edi
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
    // 00482c0b  0f83b7000000           -jae 0x482cc8
    if (!cpu.flags.cf)
    {
        goto L_0x00482cc8;
    }
    // 00482c11  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00482c13  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00482c15  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00482c19:
    // 00482c19  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00482c1d  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00482c20  0f8cc0000000           -jl 0x482ce6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482ce6;
    }
    // 00482c26  8b2dd41c5600           -mov ebp, dword ptr [0x561cd4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */);
    // 00482c2c  8b151c904d00           -mov edx, dword ptr [0x4d901c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */);
    // 00482c32  895d18                 -mov dword ptr [ebp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00482c35  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00482c39  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00482c3c  89551c                 -mov dword ptr [ebp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00482c3f  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00482c44  a3d41c5600             -mov dword ptr [0x561cd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */) = cpu.eax;
    // 00482c49  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00482c4d  42                     -inc edx
    (cpu.edx)++;
    // 00482c4e  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00482c51  89151c904d00           -mov dword ptr [0x4d901c], edx
    app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */) = cpu.edx;
    // 00482c57  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00482c5a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00482c5e  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00482c61  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00482c64  e8e31c0000             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 00482c69  2b3c24                 -sub edi, dword ptr [esp]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00482c6c  897524                 -mov dword ptr [ebp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 00482c6f  897d00                 -mov dword ptr [ebp], edi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edi;
    // 00482c72  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00482c75  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00482c78  896824                 -mov dword ptr [eax + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 00482c7b  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00482c7e  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482c82  7407                   -je 0x482c8b
    if (cpu.flags.zf)
    {
        goto L_0x00482c8b;
    }
    // 00482c84  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00482c86  e8f5cf0100             -call 0x49fc80
    cpu.esp -= 4;
    sub_49fc80(app, cpu);
    if (cpu.terminate) return;
L_0x00482c8b:
    // 00482c8b  833d20904d0000         +cmp dword ptr [0x4d9020], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083168) /* 0x4d9020 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482c92  7405                   -je 0x482c99
    if (cpu.flags.zf)
    {
        goto L_0x00482c99;
    }
    // 00482c94  e8eb020000             -call 0x482f84
    cpu.esp -= 4;
    sub_482f84(app, cpu);
    if (cpu.terminate) return;
L_0x00482c99:
    // 00482c99  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482c9d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482ca0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ca1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ca2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ca3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482ca4:
    // 00482ca4  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00482ca7  0f852fffffff           -jne 0x482bdc
    if (!cpu.flags.zf)
    {
        goto L_0x00482bdc;
    }
    // 00482cad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482caf  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00482cb2  e811d20100             -call 0x49fec8
    cpu.esp -= 4;
    sub_49fec8(app, cpu);
    if (cpu.terminate) return;
    // 00482cb7  e920ffffff             -jmp 0x482bdc
    goto L_0x00482bdc;
L_0x00482cbc:
    // 00482cbc  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482cbf  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00482cc1  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482cc3  e925ffffff             -jmp 0x482bed
    goto L_0x00482bed;
L_0x00482cc8:
    // 00482cc8  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00482cca  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00482ccd  7407                   -je 0x482cd6
    if (cpu.flags.zf)
    {
        goto L_0x00482cd6;
    }
    // 00482ccf  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482cd2  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00482cd4  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
L_0x00482cd6:
    // 00482cd6  3b31                   +cmp esi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482cd8  0f843bffffff           -je 0x482c19
    if (cpu.flags.zf)
    {
        goto L_0x00482c19;
    }
    // 00482cde  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482ce1  e90dffffff             -jmp 0x482bf3
    goto L_0x00482bf3;
L_0x00482ce6:
    // 00482ce6  3b31                   +cmp esi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482ce8  7418                   -je 0x482d02
    if (cpu.flags.zf)
    {
        goto L_0x00482d02;
    }
    // 00482cea  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00482cec  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00482cef  7508                   -jne 0x482cf9
    if (!cpu.flags.zf)
    {
        goto L_0x00482cf9;
    }
L_0x00482cf1:
    // 00482cf1  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482cf4  e9f4feffff             -jmp 0x482bed
    goto L_0x00482bed;
L_0x00482cf9:
    // 00482cf9  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00482cfc  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00482cfe  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482d00  ebef                   -jmp 0x482cf1
    goto L_0x00482cf1;
L_0x00482d02:
    // 00482d02  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482d04  e86fd30100             -call 0x4a0078
    cpu.esp -= 4;
    sub_4a0078(app, cpu);
    if (cpu.terminate) return;
    // 00482d09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482d0b  0f8487feffff           -je 0x482b98
    if (cpu.flags.zf)
    {
        goto L_0x00482b98;
    }
    // 00482d11  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00482d14  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00482d16  e8add10100             -call 0x49fec8
    cpu.esp -= 4;
    sub_49fec8(app, cpu);
    if (cpu.terminate) return;
    // 00482d1b  e9bcfeffff             -jmp 0x482bdc
    goto L_0x00482bdc;
}

/* align: skip  */
void Application::sub_482d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482d22  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482d24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482d26  742e                   -je 0x482d56
    if (cpu.flags.zf)
    {
        goto L_0x00482d56;
    }
    // 00482d28  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00482d2a:
    // 00482d2a  8b93541b5600           -mov edx, dword ptr [ebx + 0x561b54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5643092) /* 0x561b54 */);
    // 00482d30  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482d32  7417                   -je 0x482d4b
    if (cpu.flags.zf)
    {
        goto L_0x00482d4b;
    }
    // 00482d34  8b83501b5600           -mov eax, dword ptr [ebx + 0x561b50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5643088) /* 0x561b50 */);
L_0x00482d3a:
    // 00482d3a  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00482d3d  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482d3f  7404                   -je 0x482d45
    if (cpu.flags.zf)
    {
        goto L_0x00482d45;
    }
    // 00482d41  39d0                   +cmp eax, edx
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
    // 00482d43  75f5                   -jne 0x482d3a
    if (!cpu.flags.zf)
    {
        goto L_0x00482d3a;
    }
L_0x00482d45:
    // 00482d45  f6401980               +test byte ptr [eax + 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(25) /* 0x19 */) & 128 /*0x80*/));
    // 00482d49  740d                   -je 0x482d58
    if (cpu.flags.zf)
    {
        goto L_0x00482d58;
    }
L_0x00482d4b:
    // 00482d4b  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00482d4e  81fb80010000           +cmp ebx, 0x180
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482d54  7cd4                   -jl 0x482d2a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482d2a;
    }
L_0x00482d56:
    // 00482d56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00482d58:
    // 00482d58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482d5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482d5c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482d5d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00482d62  e8b9ffffff             -call 0x482d20
    cpu.esp -= 4;
    sub_482d20(app, cpu);
    if (cpu.terminate) return;
    // 00482d67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482d6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482d6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482d6d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00482d72  e8a9ffffff             -call 0x482d20
    cpu.esp -= 4;
    sub_482d20(app, cpu);
    if (cpu.terminate) return;
    // 00482d77  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482d79  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482d7e  e8adce0100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 00482d83  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482d85  e82e000000             -call 0x482db8
    cpu.esp -= 4;
    sub_482db8(app, cpu);
    if (cpu.terminate) return;
    // 00482d8a  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482d8f  e8a4ce0100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 00482d94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482d98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482d98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482d99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482d9b  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482da0  e88bce0100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 00482da5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482da7  e80c000000             -call 0x482db8
    cpu.esp -= 4;
    sub_482db8(app, cpu);
    if (cpu.terminate) return;
    // 00482dac  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482db1  e882ce0100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 00482db6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482db7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482db8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482db8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482db9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482dbb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482dbd  743a                   -je 0x482df9
    if (cpu.flags.zf)
    {
        goto L_0x00482df9;
    }
    // 00482dbf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482dc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482dc1  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00482dc4  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00482dc7  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00482dca  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00482dcc  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00482dcf  894b24                 -mov dword ptr [ebx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00482dd2  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482dd5  81e1000f0000           -and ecx, 0xf00
    cpu.ecx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00482ddb  81f900030000           +cmp ecx, 0x300
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482de1  7418                   -je 0x482dfb
    if (cpu.flags.zf)
    {
        goto L_0x00482dfb;
    }
L_0x00482de3:
    // 00482de3  a1d41c5600             -mov eax, dword ptr [0x561cd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */);
    // 00482de8  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00482dee  8915d41c5600           -mov dword ptr [0x561cd4], edx
    app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */) = cpu.edx;
    // 00482df4  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00482df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482df8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482df9:
    // 00482df9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482dfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482dfb:
    // 00482dfb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00482dfd  e8a64c0100             -call 0x497aa8
    cpu.esp -= 4;
    sub_497aa8(app, cpu);
    if (cpu.terminate) return;
    // 00482e02  ebdf                   -jmp 0x482de3
    goto L_0x00482de3;
}

/* align: skip  */
void Application::sub_482e04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482e04  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482e05  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00482e0a  e811ffffff             -call 0x482d20
    cpu.esp -= 4;
    sub_482d20(app, cpu);
    if (cpu.terminate) return;
    // 00482e0f  e804000000             -call 0x482e18
    cpu.esp -= 4;
    sub_482e18(app, cpu);
    if (cpu.terminate) return;
    // 00482e14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482e18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482e18  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482e19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482e1b  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482e20  e80bce0100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 00482e25  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00482e28  f6421820               +test byte ptr [edx + 0x18], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) & 32 /*0x20*/));
    // 00482e2c  7512                   -jne 0x482e40
    if (!cpu.flags.zf)
    {
        goto L_0x00482e40;
    }
L_0x00482e2e:
    // 00482e2e  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00482e31  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 00482e34  e87fffffff             -call 0x482db8
    cpu.esp -= 4;
    sub_482db8(app, cpu);
    if (cpu.terminate) return;
    // 00482e39  f6421820               +test byte ptr [edx + 0x18], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) & 32 /*0x20*/));
    // 00482e3d  74ef                   -je 0x482e2e
    if (cpu.flags.zf)
    {
        goto L_0x00482e2e;
    }
    // 00482e3f  90                     -nop 
    ;
L_0x00482e40:
    // 00482e40  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482e45  e8eecd0100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 00482e4a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482e4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482e4c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482e4d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482e4f  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482e54  e8d7cd0100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 00482e59  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482e5b  e810000000             -call 0x482e70
    cpu.esp -= 4;
    sub_482e70(app, cpu);
    if (cpu.terminate) return;
    // 00482e60  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482e62  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482e67  e8cccd0100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 00482e6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482e6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482e70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482e71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482e72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482e73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482e74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482e75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482e76  8b351c904d00           -mov esi, dword ptr [0x4d901c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */);
    // 00482e7c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482e7e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482e80  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00482e86  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00482e89  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00482e90  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00482e92  bd501b5600             -mov ebp, 0x561b50
    cpu.ebp = 5643088 /*0x561b50*/;
    // 00482e97  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00482e9a  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482e9c  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00482e9f  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00482ea2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00482ea4  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00482ea7  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00482eaa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482eac  39d0                   +cmp eax, edx
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
    // 00482eae  7429                   -je 0x482ed9
    if (cpu.flags.zf)
    {
        goto L_0x00482ed9;
    }
L_0x00482eb0:
    // 00482eb0  f6401808               +test byte ptr [eax + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 00482eb4  741b                   -je 0x482ed1
    if (cpu.flags.zf)
    {
        goto L_0x00482ed1;
    }
    // 00482eb6  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482eb9  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00482ebc  39ca                   +cmp edx, ecx
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
    // 00482ebe  7632                   -jbe 0x482ef2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482ef2;
    }
L_0x00482ec0:
    // 00482ec0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482ec2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00482ec4  8b581c                 -mov ebx, dword ptr [eax + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00482ec7  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00482eca  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482ecc  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00482ecf  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00482ed1:
    // 00482ed1  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00482ed4  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482ed7  75d7                   -jne 0x482eb0
    if (!cpu.flags.zf)
    {
        goto L_0x00482eb0;
    }
L_0x00482ed9:
    // 00482ed9  89351c904d00           -mov dword ptr [0x4d901c], esi
    app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */) = cpu.esi;
    // 00482edf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00482ee1  751c                   -jne 0x482eff
    if (!cpu.flags.zf)
    {
        goto L_0x00482eff;
    }
    // 00482ee3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482ee5  8b351c904d00           -mov esi, dword ptr [0x4d901c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */);
    // 00482eeb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ef0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ef1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482ef2:
    // 00482ef2  75dd                   -jne 0x482ed1
    if (!cpu.flags.zf)
    {
        goto L_0x00482ed1;
    }
    // 00482ef4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00482ef6  2b501c                 -sub edx, dword ptr [eax + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 00482ef9  39da                   +cmp edx, ebx
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
    // 00482efb  73c3                   -jae 0x482ec0
    if (!cpu.flags.cf)
    {
        goto L_0x00482ec0;
    }
    // 00482efd  ebd2                   -jmp 0x482ed1
    goto L_0x00482ed1;
L_0x00482eff:
    // 00482eff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482f01  e8b2feffff             -call 0x482db8
    cpu.esp -= 4;
    sub_482db8(app, cpu);
    if (cpu.terminate) return;
    // 00482f06  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482f0b  8b351c904d00           -mov esi, dword ptr [0x4d901c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */);
    // 00482f11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482f18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482f18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482f19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f1a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482f1b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482f1c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482f1e  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00482f24  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00482f27  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00482f2e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00482f30  bf501b5600             -mov edi, 0x561b50
    cpu.edi = 5643088 /*0x561b50*/;
    // 00482f35  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00482f38  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482f3a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482f3c  e8ffcc0100             -call 0x49fc40
    cpu.esp -= 4;
    sub_49fc40(app, cpu);
    if (cpu.terminate) return;
    // 00482f41  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00482f43  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00482f46  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482f48  39d1                   +cmp ecx, edx
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
    // 00482f4a  741b                   -je 0x482f67
    if (cpu.flags.zf)
    {
        goto L_0x00482f67;
    }
L_0x00482f4c:
    // 00482f4c  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00482f51  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00482f54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482f56  e81c480100             -call 0x497777
    cpu.esp -= 4;
    sub_497777(app, cpu);
    if (cpu.terminate) return;
    // 00482f5b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482f5d  740f                   -je 0x482f6e
    if (cpu.flags.zf)
    {
        goto L_0x00482f6e;
    }
    // 00482f5f  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00482f62  3b4f04                 +cmp ecx, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482f65  75e5                   -jne 0x482f4c
    if (!cpu.flags.zf)
    {
        goto L_0x00482f4c;
    }
L_0x00482f67:
    // 00482f67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482f69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482f6e:
    // 00482f6e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482f70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f73  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482f78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482f78  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482f79  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482f7b  e898ffffff             -call 0x482f18
    cpu.esp -= 4;
    sub_482f18(app, cpu);
    if (cpu.terminate) return;
    // 00482f80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482f84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482f84  833d24904d0000         +cmp dword ptr [0x4d9024], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083172) /* 0x4d9024 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482f8b  7503                   -jne 0x482f90
    if (!cpu.flags.zf)
    {
        goto L_0x00482f90;
    }
    // 00482f8d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482f8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482f90:
    // 00482f90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482f92  e83d000000             -call 0x482fd4
    cpu.esp -= 4;
    sub_482fd4(app, cpu);
    if (cpu.terminate) return;
    // 00482f97  3b05dc1c5600           +cmp eax, dword ptr [0x561cdc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5643484) /* 0x561cdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482f9d  7d05                   -jge 0x482fa4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00482fa4;
    }
    // 00482f9f  a3dc1c5600             -mov dword ptr [0x561cdc], eax
    app->getMemory<x86::reg32>(x86::reg32(5643484) /* 0x561cdc */) = cpu.eax;
L_0x00482fa4:
    // 00482fa4  a1dc1c5600             -mov eax, dword ptr [0x561cdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643484) /* 0x561cdc */);
    // 00482fa9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482fac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482fac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482fae  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00482fb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482fb1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482fb3  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482fb8  e873cc0100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 00482fbd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482fbf  e810000000             -call 0x482fd4
    cpu.esp -= 4;
    sub_482fd4(app, cpu);
    if (cpu.terminate) return;
    // 00482fc4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482fc6  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482fcb  e868cc0100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 00482fd0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482fd2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482fd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
