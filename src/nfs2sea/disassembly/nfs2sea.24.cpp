#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x90 */
void Application::sub_49a94c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049a94c);
    // 0049a94c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a94d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a94e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049a950  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049a952  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a956  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049a958  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a959  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a95b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a95d  e8defeffff             -call 0x49a840
    cpu.esp -= 4;
    sub_49a840(app, cpu);
    if (cpu.terminate) return;
    // 0049a962  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a963  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a964  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49a968(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049a968);
    // 0049a968  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a969  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049a96b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049a96d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a96f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a971  e896ffffff             -call 0x49a90c
    cpu.esp -= 4;
    sub_49a90c(app, cpu);
    if (cpu.terminate) return;
    // 0049a976  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a977  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a978(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049a978);
    // 0049a978  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a979  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a97a  891d88d24d00           -mov dword ptr [0x4dd288], ebx
    app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */) = cpu.ebx;
    // 0049a980  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a982  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a983  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0049a984:
    // 0049a984  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049a986  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a988  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0049a98a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049a98c  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 0049a98f  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0049a994  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0049a997  8b2c9dc8e75600         -mov ebp, dword ptr [ebx*4 + 0x56e7c8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695432) /* 0x56e7c8 */ + cpu.ebx * 4);
    // 0049a99e  8b3cbdc8e35600         -mov edi, dword ptr [edi*4 + 0x56e3c8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5694408) /* 0x56e3c8 */ + cpu.edi * 4);
    // 0049a9a5  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a9a8  8b0485c8e55600         -mov eax, dword ptr [eax*4 + 0x56e5c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5694920) /* 0x56e5c8 */ + cpu.eax * 4);
    // 0049a9af  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a9b1  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a9b3  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049a9b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a9b7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049a9b9  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0049a9bc  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 0049a9c2  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 0049a9c5  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049a9cb  8b048500df5600         -mov eax, dword ptr [eax*4 + 0x56df00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5693184) /* 0x56df00 */ + cpu.eax * 4);
    // 0049a9d2  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0049a9d5  8b0c8de8da5600         -mov ecx, dword ptr [ecx*4 + 0x56dae8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5692136) /* 0x56dae8 */ + cpu.ecx * 4);
    // 0049a9dc  8b3cbd60d55600         -mov edi, dword ptr [edi*4 + 0x56d560]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5690720) /* 0x56d560 */ + cpu.edi * 4);
    // 0049a9e3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a9e5  8b1c9dc8e35600         -mov ebx, dword ptr [ebx*4 + 0x56e3c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5694408) /* 0x56e3c8 */ + cpu.ebx * 4);
    // 0049a9ec  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049a9ee  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a9f0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049a9f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a9f4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049a9f6  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 0049a9fc  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0049a9ff  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049aa05  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 0049aa08  8b0d88d24d00           -mov ecx, dword ptr [0x4dd288]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */);
    // 0049aa0e  8b048500df5600         -mov eax, dword ptr [eax*4 + 0x56df00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5693184) /* 0x56df00 */ + cpu.eax * 4);
    // 0049aa15  8b3cbd60d55600         -mov edi, dword ptr [edi*4 + 0x56d560]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5690720) /* 0x56d560 */ + cpu.edi * 4);
    // 0049aa1c  8b1c9de8da5600         -mov ebx, dword ptr [ebx*4 + 0x56dae8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5692136) /* 0x56dae8 */ + cpu.ebx * 4);
    // 0049aa23  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049aa25  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049aa27  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049aa2d  250000ffff             -and eax, 0xffff0000
    cpu.eax &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0049aa32  09e8                   +or eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0049aa34  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049aa35  890d88d24d00           -mov dword ptr [0x4dd288], ecx
    app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */) = cpu.ecx;
    // 0049aa3b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049aa3d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049aa40  0f853effffff           -jne 0x49a984
    if (!cpu.flags.zf)
    {
        goto L_0x0049a984;
    }
    // 0049aa46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49aa4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049aa4b);
    // 0049aa4b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049aa4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049aa4d  891d88d24d00           -mov dword ptr [0x4dd288], ebx
    app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */) = cpu.ebx;
    // 0049aa53  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049aa55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049aa56  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0049aa57:
    // 0049aa57  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049aa59  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049aa5b  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0049aa5d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049aa5f  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 0049aa62  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0049aa67  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0049aa6a  8b2c9dc8e75600         -mov ebp, dword ptr [ebx*4 + 0x56e7c8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695432) /* 0x56e7c8 */ + cpu.ebx * 4);
    // 0049aa71  8b3cbdc8e35600         -mov edi, dword ptr [edi*4 + 0x56e3c8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5694408) /* 0x56e3c8 */ + cpu.edi * 4);
    // 0049aa78  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049aa7b  8b0485c8e55600         -mov eax, dword ptr [eax*4 + 0x56e5c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5694920) /* 0x56e5c8 */ + cpu.eax * 4);
    // 0049aa82  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049aa84  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049aa86  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049aa88  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049aa8a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049aa8c  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0049aa8f  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 0049aa95  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 0049aa98  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049aa9e  8b048500df5600         -mov eax, dword ptr [eax*4 + 0x56df00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5693184) /* 0x56df00 */ + cpu.eax * 4);
    // 0049aaa5  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0049aaa8  8b0c8de8da5600         -mov ecx, dword ptr [ecx*4 + 0x56dae8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5692136) /* 0x56dae8 */ + cpu.ecx * 4);
    // 0049aaaf  8b3cbd60d55600         -mov edi, dword ptr [edi*4 + 0x56d560]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5690720) /* 0x56d560 */ + cpu.edi * 4);
    // 0049aab6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aab8  8b1c9dc8e35600         -mov ebx, dword ptr [ebx*4 + 0x56e3c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5694408) /* 0x56e3c8 */ + cpu.ebx * 4);
    // 0049aabf  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049aac1  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049aac3  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049aac5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049aac7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049aac9  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 0049aacf  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0049aad2  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049aad8  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 0049aadb  8b0d88d24d00           -mov ecx, dword ptr [0x4dd288]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */);
    // 0049aae1  8b048500df5600         -mov eax, dword ptr [eax*4 + 0x56df00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5693184) /* 0x56df00 */ + cpu.eax * 4);
    // 0049aae8  8b3cbd60d55600         -mov edi, dword ptr [edi*4 + 0x56d560]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5690720) /* 0x56d560 */ + cpu.edi * 4);
    // 0049aaef  8b1c9de8da5600         -mov ebx, dword ptr [ebx*4 + 0x56dae8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5692136) /* 0x56dae8 */ + cpu.ebx * 4);
    // 0049aaf6  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049aaf8  01d8                   +add eax, ebx
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
    // 0049aafa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049aafb  890d88d24d00           -mov dword ptr [0x4dd288], ecx
    app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */) = cpu.ecx;
    // 0049ab01  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049ab04  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049ab07  0f854affffff           -jne 0x49aa57
    if (!cpu.flags.zf)
    {
        goto L_0x0049aa57;
    }
    // 0049ab0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ab12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ab12);
    // 0049ab12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ab13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ab14  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ab16  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049ab18  890d88d24d00           -mov dword ptr [0x4dd288], ecx
    app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */) = cpu.ecx;
    // 0049ab1e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0049ab1f:
    // 0049ab1f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049ab21  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049ab23  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049ab25  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ab28  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 0049ab2a  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ab2d  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 0049ab32  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ab34  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ab36  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049ab38  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0049ab3b  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049ab3d  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 0049ab40  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ab46  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0049ab49  8b1495c8e75600         -mov edx, dword ptr [edx*4 + 0x56e7c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695432) /* 0x56e7c8 */ + cpu.edx * 4);
    // 0049ab50  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ab56  8b0c8dc8e55600         -mov ecx, dword ptr [ecx*4 + 0x56e5c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5694920) /* 0x56e5c8 */ + cpu.ecx * 4);
    // 0049ab5d  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ab5f  8b0485c8e35600         -mov eax, dword ptr [eax*4 + 0x56e3c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5694408) /* 0x56e3c8 */ + cpu.eax * 4);
    // 0049ab66  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049ab68  8b2cadc8e35600         -mov ebp, dword ptr [ebp*4 + 0x56e3c8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5694408) /* 0x56e3c8 */ + cpu.ebp * 4);
    // 0049ab6f  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049ab71  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ab73  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 0049ab76  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ab78  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 0049ab7b  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049ab80  8b149500df5600         -mov edx, dword ptr [edx*4 + 0x56df00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5693184) /* 0x56df00 */ + cpu.edx * 4);
    // 0049ab87  81e1ff010000           -and ecx, 0x1ff
    cpu.ecx &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049ab8d  8b048560d55600         -mov eax, dword ptr [eax*4 + 0x56d560]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5690720) /* 0x56d560 */ + cpu.eax * 4);
    // 0049ab94  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ab97  8b0c8de8da5600         -mov ecx, dword ptr [ecx*4 + 0x56dae8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5692136) /* 0x56dae8 */ + cpu.ecx * 4);
    // 0049ab9e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049aba0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aba2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049aba4  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 0049aba7  8943f8                 -mov dword ptr [ebx - 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0049abaa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049abac  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049abb2  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0049abb5  8b149500df5600         -mov edx, dword ptr [edx*4 + 0x56df00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5693184) /* 0x56df00 */ + cpu.edx * 4);
    // 0049abbc  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049abc1  8b2cad60d55600         -mov ebp, dword ptr [ebp*4 + 0x56d560]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5690720) /* 0x56d560 */ + cpu.ebp * 4);
    // 0049abc8  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049abca  8b0d88d24d00           -mov ecx, dword ptr [0x4dd288]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */);
    // 0049abd0  8b0485e8da5600         -mov eax, dword ptr [eax*4 + 0x56dae8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5692136) /* 0x56dae8 */ + cpu.eax * 4);
    // 0049abd7  01d0                   +add eax, edx
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
    // 0049abd9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049abda  890d88d24d00           -mov dword ptr [0x4dd288], ecx
    app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */) = cpu.ecx;
    // 0049abe0  90                     -nop 
    ;
    // 0049abe1  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049abe4  0f8535ffffff           -jne 0x49ab1f
    if (!cpu.flags.zf)
    {
        goto L_0x0049ab1f;
    }
    // 0049abea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049abeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049abec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049abed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49abee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049abee);
    // 0049abee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049abef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049abf0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049abf1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0049abf2:
    // 0049abf2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049abf4  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049abf7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049abf9  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0049abfb  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049abfe  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 0049ac04  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0049ac07  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 0049ac0d  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 0049ac13  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ac15  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ac17  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ac1a  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049ac1c  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ac1f  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0049ac21  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 0049ac27  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0049ac29  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 0049ac2f  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0049ac32  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ac34  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 0049ac3a  897afc                 -mov dword ptr [edx - 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0049ac3d  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0049ac3f  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049ac40  8972f8                 -mov dword ptr [edx - 8], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0049ac43  75ad                   -jne 0x49abf2
    if (!cpu.flags.zf)
    {
        goto L_0x0049abf2;
    }
    // 0049ac45  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac46  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ac4a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ac4a);
    // 0049ac4a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ac4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ac4c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ac4d  890d88d24d00           -mov dword ptr [0x4dd288], ecx
    app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */) = cpu.ecx;
    // 0049ac53  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ac55  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049ac57  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049ac59  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ac5c  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0049ac5e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ac61  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 0049ac67  893d8cd24d00           -mov dword ptr [0x4dd28c], edi
    app->getMemory<x86::reg32>(x86::reg32(5100172) /* 0x4dd28c */) = cpu.edi;
L_0x0049ac6d:
    // 0049ac6d  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ac6f  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049ac71  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049ac73  8b358cd24d00           -mov esi, dword ptr [0x4dd28c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100172) /* 0x4dd28c */);
    // 0049ac79  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0049ac7b  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ac7e  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 0049ac84  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049ac86  893d8cd24d00           -mov dword ptr [0x4dd28c], edi
    app->getMemory<x86::reg32>(x86::reg32(5100172) /* 0x4dd28c */) = cpu.edi;
    // 0049ac8c  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0049ac8e  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049ac91  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 0049ac97  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0049ac9a  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 0049aca0  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 0049aca6  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aca8  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049acaa  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049acad  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049acaf  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049acb2  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0049acb4  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 0049acba  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0049acbc  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 0049acc2  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0049acc5  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049acc7  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 0049accd  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0049acd0  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0049acd2  8b0d88d24d00           -mov ecx, dword ptr [0x4dd288]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */);
    // 0049acd8  8973f8                 -mov dword ptr [ebx - 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0049acdb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049acdc  890d88d24d00           -mov dword ptr [0x4dd288], ecx
    app->getMemory<x86::reg32>(x86::reg32(5100168) /* 0x4dd288 */) = cpu.ecx;
    // 0049ace2  7589                   -jne 0x49ac6d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ac6d;
    }
    // 0049ace4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ace5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ace6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ace7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ace8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ace8);
    // 0049ace8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ace9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049acea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049aceb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049acec  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049acee  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049acf0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049acf2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049acf4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049acf6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049acf8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049acfa:
    // 0049acfa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049acfc  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049acff  8a4e02                 -mov cl, byte ptr [esi + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0049ad02  8a5603                 -mov dl, byte ptr [esi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0049ad05  8a8090d24d00           -mov al, byte ptr [eax + 0x4dd290]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5100176) /* 0x4dd290 */);
    // 0049ad0b  8a9b90d24d00           -mov bl, byte ptr [ebx + 0x4dd290]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5100176) /* 0x4dd290 */);
    // 0049ad11  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049ad14  8a8990d24d00           -mov cl, byte ptr [ecx + 0x4dd290]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5100176) /* 0x4dd290 */);
    // 0049ad1a  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049ad1d  8a9290d24d00           -mov dl, byte ptr [edx + 0x4dd290]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5100176) /* 0x4dd290 */);
    // 0049ad23  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ad25  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ad27  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049ad2a  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ad2d  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ad2f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ad31  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049ad33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ad35  8a4efc                 -mov cl, byte ptr [esi - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0049ad38  8a56fd                 -mov dl, byte ptr [esi - 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */);
    // 0049ad3b  8a46fe                 -mov al, byte ptr [esi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0049ad3e  8a5eff                 -mov bl, byte ptr [esi - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0049ad41  8a8990d24d00           -mov cl, byte ptr [ecx + 0x4dd290]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5100176) /* 0x4dd290 */);
    // 0049ad47  8a9290d24d00           -mov dl, byte ptr [edx + 0x4dd290]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5100176) /* 0x4dd290 */);
    // 0049ad4d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049ad50  8a8090d24d00           -mov al, byte ptr [eax + 0x4dd290]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5100176) /* 0x4dd290 */);
    // 0049ad56  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049ad59  8a9b90d24d00           -mov bl, byte ptr [ebx + 0x4dd290]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5100176) /* 0x4dd290 */);
    // 0049ad5f  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ad61  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ad63  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049ad66  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ad69  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ad6b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ad6d  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0049ad70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ad72  83ed02                 +sub ebp, 2
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
    // 0049ad75  7f83                   -jg 0x49acfa
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049acfa;
    }
    // 0049ad77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ad7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ad7c);
    // 0049ad7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ad7d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ad7e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ad81  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049ad85  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049ad87  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049ad8b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049ad8e  b85eeb4d00             -mov eax, 0x4deb5e
    cpu.eax = 5106526 /*0x4deb5e*/;
    // 0049ad93  e81c2f0100             -call 0x4adcb4
    cpu.esp -= 4;
    sub_4adcb4(app, cpu);
    if (cpu.terminate) return;
    // 0049ad98  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ad9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_49ada0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ada0);
    // 0049ada0  e9da2b0100             -jmp 0x4ad97f
    return sub_4ad97f(app, cpu);
}

/* align: skip  */
void Application::sub_49ada5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ada5);
    // 0049ada5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ada7  e88c1a0000             -call 0x49c838
    cpu.esp -= 4;
    sub_49c838(app, cpu);
    if (cpu.terminate) return;
    // 0049adac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049adae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049adb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049adb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049adb2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049adb4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049adb5  ff1544375600           -call dword ptr [0x563744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650244) /* 0x563744 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049adbb  ff1560375600           -call dword ptr [0x563760]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650272) /* 0x563760 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049adc1  a340f35600             -mov dword ptr [0x56f340], eax
    app->getMemory<x86::reg32>(x86::reg32(5698368) /* 0x56f340 */) = cpu.eax;
    // 0049adc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049adc8  7419                   -je 0x49ade3
    if (cpu.flags.zf)
    {
        goto L_0x0049ade3;
    }
    // 0049adca  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049adcc  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049adcf  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049add2  891d44f35600           -mov dword ptr [0x56f344], ebx
    app->getMemory<x86::reg32>(x86::reg32(5698372) /* 0x56f344 */) = cpu.ebx;
    // 0049add8  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049addb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ade0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ade1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ade2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ade3:
    // 0049ade3  a344f35600             -mov dword ptr [0x56f344], eax
    app->getMemory<x86::reg32>(x86::reg32(5698372) /* 0x56f344 */) = cpu.eax;
    // 0049ade8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ade9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49adb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049adb0);
    goto L_entry_0x0049adb0;
    // 0049ada5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ada7  e88c1a0000             -call 0x49c838
    cpu.esp -= 4;
    sub_49c838(app, cpu);
    if (cpu.terminate) return;
    // 0049adac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049adae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x0049adb0:
    // 0049adb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049adb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049adb2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049adb4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049adb5  ff1544375600           -call dword ptr [0x563744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650244) /* 0x563744 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049adbb  ff1560375600           -call dword ptr [0x563760]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650272) /* 0x563760 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049adc1  a340f35600             -mov dword ptr [0x56f340], eax
    app->getMemory<x86::reg32>(x86::reg32(5698368) /* 0x56f340 */) = cpu.eax;
    // 0049adc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049adc8  7419                   -je 0x49ade3
    if (cpu.flags.zf)
    {
        goto L_0x0049ade3;
    }
    // 0049adca  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049adcc  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049adcf  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049add2  891d44f35600           -mov dword ptr [0x56f344], ebx
    app->getMemory<x86::reg32>(x86::reg32(5698372) /* 0x56f344 */) = cpu.ebx;
    // 0049add8  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049addb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ade0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ade1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ade2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ade3:
    // 0049ade3  a344f35600             -mov dword ptr [0x56f344], eax
    app->getMemory<x86::reg32>(x86::reg32(5698372) /* 0x56f344 */) = cpu.eax;
    // 0049ade8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ade9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49adec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049adec);
    // 0049adec  833d44f3560000         +cmp dword ptr [0x56f344], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698372) /* 0x56f344 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049adf3  0f84c3020000           -je 0x49b0bc
    if (cpu.flags.zf)
    {
        return sub_49b0bc(app, cpu);
    }
    // 0049adf9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049adfa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049adfb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049adfc  8b0d40f35600           -mov ecx, dword ptr [0x56f340]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5698368) /* 0x56f340 */);
    // 0049ae02  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ae03  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ae05  ff151c375600           -call dword ptr [0x56371c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650204) /* 0x56371c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ae0b  891d40f35600           -mov dword ptr [0x56f340], ebx
    app->getMemory<x86::reg32>(x86::reg32(5698368) /* 0x56f340 */) = cpu.ebx;
    // 0049ae11  891d44f35600           -mov dword ptr [0x56f344], ebx
    app->getMemory<x86::reg32>(x86::reg32(5698372) /* 0x56f344 */) = cpu.ebx;
    // 0049ae17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49ae1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ae1c);
    // 0049ae1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ae1d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ae1e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ae1f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ae21  833d40f3560000         +cmp dword ptr [0x56f340], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698368) /* 0x56f340 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ae28  7533                   -jne 0x49ae5d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ae5d;
    }
L_0x0049ae2a:
    // 0049ae2a  833d3c3d560000         +cmp dword ptr [0x563d3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5651772) /* 0x563d3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ae31  740a                   -je 0x49ae3d
    if (cpu.flags.zf)
    {
        goto L_0x0049ae3d;
    }
    // 0049ae33  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 0049ae38  e81f6fffff             -call 0x491d5c
    cpu.esp -= 4;
    sub_491d5c(app, cpu);
    if (cpu.terminate) return;
L_0x0049ae3d:
    // 0049ae3d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049ae3f  7413                   -je 0x49ae54
    if (cpu.flags.zf)
    {
        goto L_0x0049ae54;
    }
    // 0049ae41  8a631e                 -mov ah, byte ptr [ebx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 0049ae44  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0049ae46  7405                   -je 0x49ae4d
    if (cpu.flags.zf)
    {
        goto L_0x0049ae4d;
    }
    // 0049ae48  80fcff                 +cmp ah, 0xff
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
    // 0049ae4b  7517                   -jne 0x49ae64
    if (!cpu.flags.zf)
    {
        goto L_0x0049ae64;
    }
L_0x0049ae4d:
    // 0049ae4d  8b7334                 -mov esi, dword ptr [ebx + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 0049ae50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ae52  751f                   -jne 0x49ae73
    if (!cpu.flags.zf)
    {
        goto L_0x0049ae73;
    }
L_0x0049ae54:
    // 0049ae54  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ae59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ae5d:
    // 0049ae5d  e88affffff             -call 0x49adec
    cpu.esp -= 4;
    sub_49adec(app, cpu);
    if (cpu.terminate) return;
    // 0049ae62  ebc6                   -jmp 0x49ae2a
    goto L_0x0049ae2a;
L_0x0049ae64:
    // 0049ae64  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ae66  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0049ae68  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ae6a  e841ffffff             -call 0x49adb0
    cpu.esp -= 4;
    sub_49adb0(app, cpu);
    if (cpu.terminate) return;
    // 0049ae6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae70  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ae73:
    // 0049ae73  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 0049ae78  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049ae7a  e8896dffff             -call 0x491c08
    cpu.esp -= 4;
    sub_491c08(app, cpu);
    if (cpu.terminate) return;
    // 0049ae7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae81  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae82  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49ae84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ae84);
    // 0049ae84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ae85  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ae86  ff154c375600           -call dword ptr [0x56374c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650252) /* 0x56374c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ae8c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49ae90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ae90);
    // 0049ae90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ae91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ae92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ae93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ae94  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049ae97  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049ae9b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049ae9d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049ae9f  3dff000000             +cmp eax, 0xff
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
    // 0049aea4  740c                   -je 0x49aeb2
    if (cpu.flags.zf)
    {
        goto L_0x0049aeb2;
    }
    // 0049aea6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049aea8  7545                   -jne 0x49aeef
    if (!cpu.flags.zf)
    {
        goto L_0x0049aeef;
    }
L_0x0049aeaa:
    // 0049aeaa  83c418                 +add esp, 0x18
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
    // 0049aead  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aeae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aeaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aeb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aeb1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049aeb2:
    // 0049aeb2  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049aeb6  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049aeba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049aebb  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049aebf  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049aec3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049aec4  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049aec8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049aeca  e80173ffff             -call 0x4921d0
    cpu.esp -= 4;
    sub_4921d0(app, cpu);
    if (cpu.terminate) return;
    // 0049aecf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049aed0  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049aed4  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049aed8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049aed9  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049aedd  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049aee1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049aee2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049aee6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049aee8  e823190100             -call 0x4ac810
    cpu.esp -= 4;
    sub_4ac810(app, cpu);
    if (cpu.terminate) return;
    // 0049aeed  ebbb                   -jmp 0x49aeaa
    goto L_0x0049aeaa;
L_0x0049aeef:
    // 0049aeef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049aef0  ff1544375600           -call dword ptr [0x563744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650244) /* 0x563744 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049aef6  ff1560375600           -call dword ptr [0x563760]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650272) /* 0x563760 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049aefc  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049aefe  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049af01  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049af04  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049af05  895328                 -mov dword ptr [ebx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049af08  ff151c375600           -call dword ptr [0x56371c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650204) /* 0x56371c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049af0e  c703444e4957           -mov dword ptr [ebx], 0x57494e44
    app->getMemory<x86::reg32>(cpu.ebx) = 1464421956 /*0x57494e44*/;
    // 0049af14  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 0049af19  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0049af20  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049af23  a180ab4d00             -mov eax, dword ptr [0x4dab80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 0049af28  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049af2b  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 0049af30  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049af33  a180ab4d00             -mov eax, dword ptr [0x4dab80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 0049af38  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049af3b  a084ab4d00             -mov al, byte ptr [0x4dab84]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0049af40  88431c                 -mov byte ptr [ebx + 0x1c], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.al;
    // 0049af43  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049af47  88431e                 -mov byte ptr [ebx + 0x1e], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.al;
    // 0049af4a  a184ab4d00             -mov eax, dword ptr [0x4dab84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0049af4f  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0049af56  e8251c0100             -call 0x4acb80
    cpu.esp -= 4;
    sub_4acb80(app, cpu);
    if (cpu.terminate) return;
    // 0049af5b  88431d                 -mov byte ptr [ebx + 0x1d], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 0049af5e  8b0d80ab4d00           -mov ecx, dword ptr [0x4dab80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 0049af64  8b5328                 -mov edx, dword ptr [ebx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0049af67  897b34                 -mov dword ptr [ebx + 0x34], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 0049af6a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049af6c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049af6e  e801020000             -call 0x49b174
    cpu.esp -= 4;
    sub_49b174(app, cpu);
    if (cpu.terminate) return;
    // 0049af73  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0049af78  8b0d7cab4d00           -mov ecx, dword ptr [0x4dab7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 0049af7e  8b1584ab4d00           -mov edx, dword ptr [0x4dab84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0049af84  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049af87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049af89  e8e6010000             -call 0x49b174
    cpu.esp -= 4;
    sub_49b174(app, cpu);
    if (cpu.terminate) return;
    // 0049af8e  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0049af91  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049af94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49afa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049afa0);
    // 0049afa0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049afa2  7505                   -jne 0x49afa9
    if (!cpu.flags.zf)
    {
        goto L_0x0049afa9;
    }
    // 0049afa4  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
L_0x0049afa9:
    // 0049afa9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049afab  7505                   -jne 0x49afb2
    if (!cpu.flags.zf)
    {
        goto L_0x0049afb2;
    }
    // 0049afad  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
L_0x0049afb2:
    // 0049afb2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049afb4  7505                   -jne 0x49afbb
    if (!cpu.flags.zf)
    {
        goto L_0x0049afbb;
    }
    // 0049afb6  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0049afbb:
    // 0049afbb  891d84ab4d00           -mov dword ptr [0x4dab84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */) = cpu.ebx;
    // 0049afc1  8b1d94ab4d00           -mov ebx, dword ptr [0x4dab94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090196) /* 0x4dab94 */);
    // 0049afc7  a37cab4d00             -mov dword ptr [0x4dab7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */) = cpu.eax;
    // 0049afcc  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049afce  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 0049afd3  a198ab4d00             -mov eax, dword ptr [0x4dab98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 0049afd8  891580ab4d00           -mov dword ptr [0x4dab80], edx
    app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */) = cpu.edx;
    // 0049afde  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049afe0  8915a0ab4d00           -mov dword ptr [0x4daba0], edx
    app->getMemory<x86::reg32>(x86::reg32(5090208) /* 0x4daba0 */) = cpu.edx;
    // 0049afe6  833d5cab4d0000         +cmp dword ptr [0x4dab5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049afed  0f84fd000000           -je 0x49b0f0
    if (cpu.flags.zf)
    {
        return sub_49b0f0(app, cpu);
    }
    // 0049aff3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49aff4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049aff4);
    // 0049aff4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049aff5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049aff6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049aff7  ff1560375600           -call dword ptr [0x563760]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650272) /* 0x563760 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049affd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049afff  a340f35600             -mov dword ptr [0x56f340], eax
    app->getMemory<x86::reg32>(x86::reg32(5698368) /* 0x56f340 */) = cpu.eax;
    // 0049b004  891544f35600           -mov dword ptr [0x56f344], edx
    app->getMemory<x86::reg32>(x86::reg32(5698372) /* 0x56f344 */) = cpu.edx;
    // 0049b00a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b00c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b00f  a368b24d00             -mov dword ptr [0x4db268], eax
    app->getMemory<x86::reg32>(x86::reg32(5091944) /* 0x4db268 */) = cpu.eax;
    // 0049b014  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 0049b019  a344b24d00             -mov dword ptr [0x4db244], eax
    app->getMemory<x86::reg32>(x86::reg32(5091908) /* 0x4db244 */) = cpu.eax;
    // 0049b01e  a180ab4d00             -mov eax, dword ptr [0x4dab80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 0049b023  b9444e4957             -mov ecx, 0x57494e44
    cpu.ecx = 1464421956 /*0x57494e44*/;
    // 0049b028  a348b24d00             -mov dword ptr [0x4db248], eax
    app->getMemory<x86::reg32>(x86::reg32(5091912) /* 0x4db248 */) = cpu.eax;
    // 0049b02d  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 0049b032  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b034  a354b24d00             -mov dword ptr [0x4db254], eax
    app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */) = cpu.eax;
    // 0049b039  a180ab4d00             -mov eax, dword ptr [0x4dab80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 0049b03e  890d40b24d00           -mov dword ptr [0x4db240], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091904) /* 0x4db240 */) = cpu.ecx;
    // 0049b044  a358b24d00             -mov dword ptr [0x4db258], eax
    app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */) = cpu.eax;
    // 0049b049  a084ab4d00             -mov al, byte ptr [0x4dab84]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0049b04e  891d4cb24d00           -mov dword ptr [0x4db24c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */) = cpu.ebx;
    // 0049b054  a25cb24d00             -mov byte ptr [0x4db25c], al
    app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */) = cpu.al;
    // 0049b059  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 0049b05b  891d50b24d00           -mov dword ptr [0x4db250], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */) = cpu.ebx;
    // 0049b061  88255eb24d00           -mov byte ptr [0x4db25e], ah
    app->getMemory<x86::reg8>(x86::reg32(5091934) /* 0x4db25e */) = cpu.ah;
    // 0049b067  a184ab4d00             -mov eax, dword ptr [0x4dab84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0049b06c  891560b24d00           -mov dword ptr [0x4db260], edx
    app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */) = cpu.edx;
    // 0049b072  e8091b0100             -call 0x4acb80
    cpu.esp -= 4;
    sub_4acb80(app, cpu);
    if (cpu.terminate) return;
    // 0049b077  8b0d80ab4d00           -mov ecx, dword ptr [0x4dab80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 0049b07d  8b1568b24d00           -mov edx, dword ptr [0x4db268]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091944) /* 0x4db268 */);
    // 0049b083  a25db24d00             -mov byte ptr [0x4db25d], al
    app->getMemory<x86::reg8>(x86::reg32(5091933) /* 0x4db25d */) = cpu.al;
    // 0049b088  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b08a  891d74b24d00           -mov dword ptr [0x4db274], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091956) /* 0x4db274 */) = cpu.ebx;
    // 0049b090  e8df000000             -call 0x49b174
    cpu.esp -= 4;
    sub_49b174(app, cpu);
    if (cpu.terminate) return;
    // 0049b095  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0049b09a  8b0d7cab4d00           -mov ecx, dword ptr [0x4dab7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 0049b0a0  8b1584ab4d00           -mov edx, dword ptr [0x4dab84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0049b0a6  a36cb24d00             -mov dword ptr [0x4db26c], eax
    app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */) = cpu.eax;
    // 0049b0ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b0ad  e8c2000000             -call 0x49b174
    cpu.esp -= 4;
    sub_49b174(app, cpu);
    if (cpu.terminate) return;
    // 0049b0b2  a370b24d00             -mov dword ptr [0x4db270], eax
    app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */) = cpu.eax;
    // 0049b0b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b0bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b0bc);
    // 0049b0bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b0bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b0be  8b1540f35600           -mov edx, dword ptr [0x56f340]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5698368) /* 0x56f340 */);
    // 0049b0c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b0c5  ff151c375600           -call dword ptr [0x56371c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650204) /* 0x56371c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b0cb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b0cd  a16cb24d00             -mov eax, dword ptr [0x4db26c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 0049b0d2  890d40f35600           -mov dword ptr [0x56f340], ecx
    app->getMemory<x86::reg32>(x86::reg32(5698368) /* 0x56f340 */) = cpu.ecx;
    // 0049b0d8  e86f010000             -call 0x49b24c
    cpu.esp -= 4;
    sub_49b24c(app, cpu);
    if (cpu.terminate) return;
    // 0049b0dd  a170b24d00             -mov eax, dword ptr [0x4db270]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 0049b0e2  e865010000             -call 0x49b24c
    cpu.esp -= 4;
    sub_49b24c(app, cpu);
    if (cpu.terminate) return;
    // 0049b0e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49b0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b0f0);
    // 0049b0f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b0f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b0f2  833d14d34d0000         +cmp dword ptr [0x4dd314], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b0f9  742c                   -je 0x49b127
    if (cpu.flags.zf)
    {
        goto L_0x0049b127;
    }
L_0x0049b0fb:
    // 0049b0fb  8b1510d34d00           -mov edx, dword ptr [0x4dd310]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100304) /* 0x4dd310 */);
    // 0049b101  a114d34d00             -mov eax, dword ptr [0x4dd314]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */);
    // 0049b106  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049b109  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0049b10c  8b1510d34d00           -mov edx, dword ptr [0x4dd310]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100304) /* 0x4dd310 */);
    // 0049b112  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049b119  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049b11c  891d48f35600           -mov dword ptr [0x56f348], ebx
    app->getMemory<x86::reg32>(x86::reg32(5698376) /* 0x56f348 */) = cpu.ebx;
    // 0049b122  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b124  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b125  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b126  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b127:
    // 0049b127  b8580d4d00             -mov eax, 0x4d0d58
    cpu.eax = 5049688 /*0x4d0d58*/;
    // 0049b12c  8b1510d34d00           -mov edx, dword ptr [0x4dd310]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100304) /* 0x4dd310 */);
    // 0049b132  8b1de8ab4d00           -mov ebx, dword ptr [0x4dabe8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 0049b138  c1e202                 +shl edx, 2
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
    // 0049b13b  e85893feff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 0049b140  a314d34d00             -mov dword ptr [0x4dd314], eax
    app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */) = cpu.eax;
    // 0049b145  ebb4                   -jmp 0x49b0fb
    goto L_0x0049b0fb;
}

/* align: skip 0x90 */
void Application::sub_49b148(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b148);
    // 0049b148  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b149  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b14a  8b1514d34d00           -mov edx, dword ptr [0x4dd314]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */);
    // 0049b150  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b152  750b                   -jne 0x49b15f
    if (!cpu.flags.zf)
    {
        goto L_0x0049b15f;
    }
    // 0049b154  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b156  890d14d34d00           -mov dword ptr [0x4dd314], ecx
    app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */) = cpu.ecx;
    // 0049b15c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b15d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b15e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b15f:
    // 0049b15f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b161  e89697feff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0049b166  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b168  890d14d34d00           -mov dword ptr [0x4dd314], ecx
    app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */) = cpu.ecx;
    // 0049b16e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b16f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b170  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b174(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b174);
    // 0049b174  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b175  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b176  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b177  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b17a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b17c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049b17f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049b183  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049b185  a114d34d00             -mov eax, dword ptr [0x4dd314]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */);
    // 0049b18a  8b1548f35600           -mov edx, dword ptr [0x56f348]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5698376) /* 0x56f348 */);
    // 0049b190  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b192  39d0                   +cmp eax, edx
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
    // 0049b194  7335                   -jae 0x49b1cb
    if (!cpu.flags.cf)
    {
        goto L_0x0049b1cb;
    }
    // 0049b196  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b19a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049b19d  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 0049b19f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0049b1a1:
    // 0049b1a1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b1a3  39f9                   +cmp ecx, edi
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
    // 0049b1a5  7c14                   -jl 0x49b1bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b1bb;
    }
    // 0049b1a7  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0049b1ab  0f8674000000           -jbe 0x49b225
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049b225;
    }
    // 0049b1b1  3b7008                 +cmp esi, dword ptr [eax + 8]
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
    // 0049b1b4  7505                   -jne 0x49b1bb
    if (!cpu.flags.zf)
    {
        goto L_0x0049b1bb;
    }
    // 0049b1b6  3b500c                 +cmp edx, dword ptr [eax + 0xc]
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
    // 0049b1b9  745e                   -je 0x49b219
    if (cpu.flags.zf)
    {
        goto L_0x0049b219;
    }
L_0x0049b1bb:
    // 0049b1bb  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0049b1be  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b1c1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b1c3  3b0548f35600           +cmp eax, dword ptr [0x56f348]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5698376) /* 0x56f348 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b1c9  72d6                   -jb 0x49b1a1
    if (cpu.flags.cf)
    {
        goto L_0x0049b1a1;
    }
L_0x0049b1cb:
    // 0049b1cb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049b1cd  0f846f000000           -je 0x49b242
    if (cpu.flags.zf)
    {
        goto L_0x0049b242;
    }
    // 0049b1d3  8d5708                 -lea edx, [edi + 8]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049b1d6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049b1d8  39d0                   +cmp eax, edx
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
    // 0049b1da  7d51                   -jge 0x49b22d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b22d;
    }
    // 0049b1dc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0049b1de:
    // 0049b1de  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b1e1  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0049b1e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b1e6  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 0049b1ec  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b1ef  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049b1f1  7e1d                   -jle 0x49b210
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b210;
    }
    // 0049b1f3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0049b1f5:
    // 0049b1f5  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b1f9  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049b1fb  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b1fe  40                     -inc eax
    (cpu.eax)++;
    // 0049b1ff  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 0049b201  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049b204  896afc                 -mov dword ptr [edx - 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 0049b207  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b209  39f8                   +cmp eax, edi
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
    // 0049b20b  7ce8                   -jl 0x49b1f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b1f5;
    }
    // 0049b20d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049b210:
    // 0049b210  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049b212:
    // 0049b212  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b215  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b216  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b217  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b218  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b219:
    // 0049b219  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b21c  83c008                 +add eax, 8
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
    // 0049b21f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049b220  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0049b223  ebed                   -jmp 0x49b212
    goto L_0x0049b212;
L_0x0049b225:
    // 0049b225  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049b227  7592                   -jne 0x49b1bb
    if (!cpu.flags.zf)
    {
        goto L_0x0049b1bb;
    }
    // 0049b229  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049b22b  eb8e                   -jmp 0x49b1bb
    goto L_0x0049b1bb;
L_0x0049b22d:
    // 0049b22d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049b22f  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049b231  c744bb0c00000000       -mov dword ptr [ebx + edi*4 + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.edi * 4) = 0 /*0x0*/;
    // 0049b239  83ea02                 +sub edx, 2
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
    // 0049b23c  8954bb08               -mov dword ptr [ebx + edi*4 + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edi * 4) = cpu.edx;
    // 0049b240  eb9c                   -jmp 0x49b1de
    goto L_0x0049b1de;
L_0x0049b242:
    // 0049b242  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b244  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b247  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b248  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b249  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b24a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b24c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b24c);
    // 0049b24c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b24d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b24e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b24f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b250  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b251  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b253  8d48f8                 -lea ecx, [eax - 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 0049b256  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049b259  4a                     -dec edx
    (cpu.edx)--;
    // 0049b25a  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049b25d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b25f  7606                   -jbe 0x49b267
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049b267;
    }
L_0x0049b261:
    // 0049b261  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b262  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b263  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b264  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b265  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b266  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b267:
    // 0049b267  a114d34d00             -mov eax, dword ptr [0x4dd314]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */);
    // 0049b26c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b26e  39c8                   +cmp eax, ecx
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
    // 0049b270  7312                   -jae 0x49b284
    if (!cpu.flags.cf)
    {
        goto L_0x0049b284;
    }
L_0x0049b272:
    // 0049b272  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b274  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049b277  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049b27a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049b27c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b27e  39c8                   +cmp eax, ecx
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
    // 0049b280  72f0                   -jb 0x49b272
    if (cpu.flags.cf)
    {
        goto L_0x0049b272;
    }
    // 0049b282  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049b284:
    // 0049b284  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b286  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049b289  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049b28c  8b3548f35600           -mov esi, dword ptr [0x56f348]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5698376) /* 0x56f348 */);
    // 0049b292  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b294  39f2                   +cmp edx, esi
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
    // 0049b296  7306                   -jae 0x49b29e
    if (!cpu.flags.cf)
    {
        goto L_0x0049b29e;
    }
    // 0049b298  837a0400               +cmp dword ptr [edx + 4], 0
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
    // 0049b29c  761b                   -jbe 0x49b2b9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049b2b9;
    }
L_0x0049b29e:
    // 0049b29e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049b2a0  74bf                   -je 0x49b261
    if (cpu.flags.zf)
    {
        goto L_0x0049b261;
    }
    // 0049b2a2  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 0049b2a6  77b9                   -ja 0x49b261
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049b261;
    }
    // 0049b2a8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b2aa  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049b2ac  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049b2af  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b2b1  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 0049b2b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b2b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b2b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b2b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b2b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b2b8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b2b9:
    // 0049b2b9  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b2bb  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b2bd  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049b2c0  01d5                   +add ebp, edx
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
    // 0049b2c2  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 0049b2c4  ebd8                   -jmp 0x49b29e
    goto L_0x0049b29e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b2c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b2c8);
    // 0049b2c8  a314d34d00             -mov dword ptr [0x4dd314], eax
    app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */) = cpu.eax;
    // 0049b2cd  891510d34d00           -mov dword ptr [0x4dd310], edx
    app->getMemory<x86::reg32>(x86::reg32(5100304) /* 0x4dd310 */) = cpu.edx;
    // 0049b2d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49b2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b2e0);
    // 0049b2e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b2e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b2e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b2e3  8a155cb24d00           -mov dl, byte ptr [0x4db25c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 0049b2e9  80fa0f                 +cmp dl, 0xf
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
    // 0049b2ec  0f8288000000           -jb 0x49b37a
    if (cpu.flags.cf)
    {
        goto L_0x0049b37a;
    }
    // 0049b2f2  7737                   -ja 0x49b32b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049b32b;
    }
    // 0049b2f4  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 0049b2f7  0f8475000000           -je 0x49b372
    if (cpu.flags.zf)
    {
        goto L_0x0049b372;
    }
    // 0049b2fd  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
L_0x0049b302:
    // 0049b302  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049b304  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b306  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0049b309  c1fb0a                 -sar ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (10 /*0xa*/ % 32));
    // 0049b30c  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0049b30f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049b312  83e31f                 -and ebx, 0x1f
    cpu.ebx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049b315  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049b318  c1e313                 -shl ebx, 0x13
    cpu.ebx <<= 19 /*0x13*/ % 32;
    // 0049b31b  c1e10b                 -shl ecx, 0xb
    cpu.ecx <<= 11 /*0xb*/ % 32;
    // 0049b31e  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b320  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049b323  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b325  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049b327:
    // 0049b327  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b328  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b329  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b32a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b32b:
    // 0049b32b  80fa18                 +cmp dl, 0x18
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
    // 0049b32e  7337                   -jae 0x49b367
    if (!cpu.flags.cf)
    {
        goto L_0x0049b367;
    }
    // 0049b330  80fa10                 +cmp dl, 0x10
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
    // 0049b333  7545                   -jne 0x49b37a
    if (!cpu.flags.zf)
    {
        goto L_0x0049b37a;
    }
    // 0049b335  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b337  743d                   -je 0x49b376
    if (cpu.flags.zf)
    {
        goto L_0x0049b376;
    }
    // 0049b339  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
L_0x0049b33e:
    // 0049b33e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b340  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049b342  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0049b345  c1f90b                 -sar ecx, 0xb
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (11 /*0xb*/ % 32));
    // 0049b348  c1fb05                 -sar ebx, 5
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (5 /*0x5*/ % 32));
    // 0049b34b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049b34e  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049b351  83e33f                 -and ebx, 0x3f
    cpu.ebx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049b354  c1e113                 -shl ecx, 0x13
    cpu.ecx <<= 19 /*0x13*/ % 32;
    // 0049b357  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 0049b35a  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b35c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049b35f  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b361  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049b363  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b364  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b365  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b366  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b367:
    // 0049b367  76be                   -jbe 0x49b327
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049b327;
    }
    // 0049b369  80fa20                 +cmp dl, 0x20
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
    // 0049b36c  750c                   -jne 0x49b37a
    if (!cpu.flags.zf)
    {
        goto L_0x0049b37a;
    }
    // 0049b36e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b36f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b370  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b371  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b372:
    // 0049b372  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049b374  eb8c                   -jmp 0x49b302
    goto L_0x0049b302;
L_0x0049b376:
    // 0049b376  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049b378  ebc4                   -jmp 0x49b33e
    goto L_0x0049b33e;
L_0x0049b37a:
    // 0049b37a  8b0485600e5700         -mov eax, dword ptr [eax*4 + 0x570e60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705312) /* 0x570e60 */ + cpu.eax * 4);
    // 0049b381  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b382  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b383  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b384  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49b390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b390);
    // 0049b390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b392  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b393  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b394  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b395  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b396  ba282c4e00             -mov edx, 0x4e2c28
    cpu.edx = 5123112 /*0x4e2c28*/;
    // 0049b39b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b39d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049b39f:
    // 0049b39f  83bf24d34d0000         +cmp dword ptr [edi + 0x4dd324], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5100324) /* 0x4dd324 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b3a6  743a                   -je 0x49b3e2
    if (cpu.flags.zf)
    {
        goto L_0x0049b3e2;
    }
L_0x0049b3a8:
    // 0049b3a8  43                     -inc ebx
    (cpu.ebx)++;
    // 0049b3a9  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b3ac  83fb0a                 +cmp ebx, 0xa
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
    // 0049b3af  7cee                   -jl 0x49b39f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b39f;
    }
    // 0049b3b1  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b3b4  2d282c4e00             -sub eax, 0x4e2c28
    (cpu.eax) -= x86::reg32(x86::sreg32(5123112 /*0x4e2c28*/));
    // 0049b3b9  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0049b3bc  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049b3bf  a34cd34d00             -mov dword ptr [0x4dd34c], eax
    app->getMemory<x86::reg32>(x86::reg32(5100364) /* 0x4dd34c */) = cpu.eax;
    // 0049b3c4  b86ff35600             -mov eax, 0x56f36f
    cpu.eax = 5698415 /*0x56f36f*/;
    // 0049b3c9  24e0                   -and al, 0xe0
    cpu.al &= x86::reg8(x86::sreg8(224 /*0xe0*/));
    // 0049b3cb  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0049b3d1  a318d34d00             -mov dword ptr [0x4dd318], eax
    app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */) = cpu.eax;
    // 0049b3d6  e8c5390100             -call 0x4aeda0
    cpu.esp -= 4;
    sub_4aeda0(app, cpu);
    if (cpu.terminate) return;
    // 0049b3db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b3e2:
    // 0049b3e2  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0049b3e8  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b3eb  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049b3f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b3f2  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0049b3f4  2d282c4e00             -sub eax, 0x4e2c28
    (cpu.eax) -= x86::reg32(x86::sreg32(5123112 /*0x4e2c28*/));
    // 0049b3f9  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049b3fb  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0049b3fe  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0049b401  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049b404  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049b407  898724d34d00           -mov dword ptr [edi + 0x4dd324], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5100324) /* 0x4dd324 */) = cpu.eax;
    // 0049b40d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b40f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049b411  7e95                   -jle 0x49b3a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b3a8;
    }
    // 0049b413  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
L_0x0049b415:
    // 0049b415  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049b417  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b41a  d3e5                   -shl ebp, cl
    cpu.ebp <<= cpu.cl % 32;
    // 0049b41c  40                     -inc eax
    (cpu.eax)++;
    // 0049b41d  896afc                 -mov dword ptr [edx - 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 0049b420  39f0                   +cmp eax, esi
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
    // 0049b422  7d84                   -jge 0x49b3a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b3a8;
    }
    // 0049b424  ebef                   -jmp 0x49b415
    goto L_0x0049b415;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b428(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b428);
    // 0049b428  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b429  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b42a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b42b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b42c  8b2d78fd5600           -mov ebp, dword ptr [0x56fd78]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5700984) /* 0x56fd78 */);
    // 0049b432  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049b434  8b0d7cfd5600           -mov ecx, dword ptr [0x56fd7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5700988) /* 0x56fd7c */);
    // 0049b43a  42                     -inc edx
    (cpu.edx)++;
    // 0049b43b  39c8                   +cmp eax, ecx
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
    // 0049b43d  751c                   -jne 0x49b45b
    if (!cpu.flags.zf)
    {
        goto L_0x0049b45b;
    }
    // 0049b43f  39ea                   +cmp edx, ebp
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
    // 0049b441  7e0d                   -jle 0x49b450
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b450;
    }
    // 0049b443  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049b445  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049b448  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049b44a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049b44c  39e8                   +cmp eax, ebp
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
    // 0049b44e  7c26                   -jl 0x49b476
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b476;
    }
L_0x0049b450:
    // 0049b450  892d78fd5600           -mov dword ptr [0x56fd78], ebp
    app->getMemory<x86::reg32>(x86::reg32(5700984) /* 0x56fd78 */) = cpu.ebp;
    // 0049b456  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b457  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b458  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b459  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b45a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b45b:
    // 0049b45b  891d7cfd5600           -mov dword ptr [0x56fd7c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5700988) /* 0x56fd7c */) = cpu.ebx;
    // 0049b461  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049b463  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b465  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b467  39e8                   +cmp eax, ebp
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
    // 0049b469  7c0b                   -jl 0x49b476
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b476;
    }
    // 0049b46b  892d78fd5600           -mov dword ptr [0x56fd78], ebp
    app->getMemory<x86::reg32>(x86::reg32(5700984) /* 0x56fd78 */) = cpu.ebp;
    // 0049b471  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b472  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b473  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b474  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b475  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b476:
    // 0049b476  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b477  8b154cd34d00           -mov edx, dword ptr [0x4dd34c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100364) /* 0x4dd34c */);
    // 0049b47d  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 0049b484  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049b487  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049b489  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049b48c  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b48e  81c2282c4e00           -add edx, 0x4e2c28
    (cpu.edx) += x86::reg32(x86::sreg32(5123112 /*0x4e2c28*/));
    // 0049b494  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b496  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b498  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049b49a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049b49c  892d78fd5600           -mov dword ptr [0x56fd78], ebp
    app->getMemory<x86::reg32>(x86::reg32(5700984) /* 0x56fd78 */) = cpu.ebp;
L_0x0049b4a2:
    // 0049b4a2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049b4a4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b4a6  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049b4a9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b4ab  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049b4ae  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b4b0  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049b4b3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b4b5  8d5b10                 -lea ebx, [ebx + 0x10]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049b4b8  83e904                 +sub ecx, 4
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
    // 0049b4bb  7fe5                   -jg 0x49b4a2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049b4a2;
    }
    // 0049b4bd  8b2d78fd5600           -mov ebp, dword ptr [0x56fd78]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5700984) /* 0x56fd78 */);
    // 0049b4c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4c4  892d78fd5600           -mov dword ptr [0x56fd78], ebp
    app->getMemory<x86::reg32>(x86::reg32(5700984) /* 0x56fd78 */) = cpu.ebp;
    // 0049b4ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b4d0);
    // 0049b4d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b4d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b4d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b4d3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b4d6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049b4d8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049b4da  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049b4de  a160b24d00             -mov eax, dword ptr [0x4db260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */);
    // 0049b4e3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049b4e5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049b4e8  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b4eb  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b4ed  8b0d68b24d00           -mov ecx, dword ptr [0x4db268]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091944) /* 0x4db268 */);
    // 0049b4f3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b4f5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b4f7  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049b4f9  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 0049b4ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b501  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049b504  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b506  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049b509  0310                   -add edx, dword ptr [eax]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 0049b50b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b50d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049b50f  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 0049b515  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b517  8a255cb24d00           -mov ah, byte ptr [0x4db25c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 0049b51d  83ee10                 -sub esi, 0x10
    (cpu.esi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b520  80fc10                 +cmp ah, 0x10
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
    // 0049b523  7733                   -ja 0x49b558
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049b558;
    }
    // 0049b525  80fc08                 +cmp ah, 8
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
    // 0049b528  7602                   -jbe 0x49b52c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049b52c;
    }
    // 0049b52a  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
L_0x0049b52c:
    // 0049b52c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b52e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b532  e8b9380100             -call 0x4aedf0
    cpu.esp -= 4;
    sub_4aedf0(app, cpu);
    if (cpu.terminate) return;
    // 0049b537  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b538  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b539  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 0049b53e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b53f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049b541  8b0d102c4e00           -mov ecx, dword ptr [0x4e2c10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 0049b547  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b548  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049b54a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b54c  e8df3a0100             -call 0x4af030
    cpu.esp -= 4;
    sub_4af030(app, cpu);
    if (cpu.terminate) return;
    // 0049b551  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b554  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b555  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b556  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b557  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b558:
    // 0049b558  c1fa02                 +sar edx, 2
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
    // 0049b55b  ebcf                   -jmp 0x49b52c
    goto L_0x0049b52c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b560);
    // 0049b560  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b561  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b562  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b563  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b566  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049b56a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049b56c  8d1ccd00000000         -lea ebx, [ecx*8]
    cpu.ebx = x86::reg32(cpu.ecx * 8);
    // 0049b573  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0049b576  8d1ced00000000         -lea ebx, [ebp*8]
    cpu.ebx = x86::reg32(cpu.ebp * 8);
    // 0049b57d  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0049b581  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0049b584  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b588  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049b58b  3b5f04                 +cmp ebx, dword ptr [edi + 4]
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
    // 0049b58e  7e06                   -jle 0x49b596
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b596;
    }
    // 0049b590  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049b592  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049b594  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0049b596:
    // 0049b596  c1e503                 -shl ebp, 3
    cpu.ebp <<= 3 /*0x3*/ % 32;
    // 0049b599  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0049b59c  8d3c2a                 -lea edi, [edx + ebp]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0049b59f  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b5a1  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049b5a5  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049b5a8  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b5ab  29d9                   +sub ecx, ebx
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
    // 0049b5ad  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0049b5b0  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b5b3  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049b5b6  7509                   -jne 0x49b5c1
    if (!cpu.flags.zf)
    {
        goto L_0x0049b5c1;
    }
    // 0049b5b8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b5bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5be  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049b5c1:
    // 0049b5c1  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b5c3  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0049b5c6  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049b5c9  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049b5cb  2b1a                   -sub ebx, dword ptr [edx]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049b5cd  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0049b5d0  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049b5d4  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0049b5d8  d80c8d50685b00         -fmul dword ptr [ecx*4 + 0x5b6850]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5990480) /* 0x5b6850 */ + cpu.ecx * 4));
    // 0049b5df  d90520d34d00           -fld dword ptr [0x4dd320]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5100320) /* 0x4dd320 */)));
    // 0049b5e5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b5e7  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049b5e9  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b5eb  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b5ed  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049b5f0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b5f4  8b1c2e                 -mov ebx, dword ptr [esi + ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 1);
    // 0049b5f7  8b3c32                 -mov edi, dword ptr [edx + esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1);
    // 0049b5fa  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049b5fc  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049b600  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0049b604  d80c8d50685b00         -fmul dword ptr [ecx*4 + 0x5b6850]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5990480) /* 0x5b6850 */ + cpu.ecx * 4));
    // 0049b60b  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b60e  8b5c2e04               -mov ebx, dword ptr [esi + ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 0049b612  8b6c3204               -mov ebp, dword ptr [edx + esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 0049b616  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b618  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049b61c  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0049b620  d80c8d50685b00         -fmul dword ptr [ecx*4 + 0x5b6850]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5990480) /* 0x5b6850 */ + cpu.ecx * 4));
    // 0049b627  d95814                 -fstp dword ptr [eax + 0x14]
    app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b62a  db0432                 -fild dword ptr [edx + esi]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1))));
    // 0049b62d  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049b62f  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b631  db443204               -fild dword ptr [edx + esi + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1))));
    // 0049b635  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049b637  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b63a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b63d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b63e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b63f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b640  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b644(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b644);
    // 0049b644  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b645  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b646  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b647  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049b64a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049b64e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049b650  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0049b654  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049b658  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0049b65f  a16cb24d00             -mov eax, dword ptr [0x4db26c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 0049b664  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b666  8b1560b24d00           -mov edx, dword ptr [0x4db260]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */);
    // 0049b66c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b66e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b670  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049b674  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049b67b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b67d  8b3d18d34d00           -mov edi, dword ptr [0x4dd318]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049b683  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049b686  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049b688  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0049b68b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049b692  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b694  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049b697  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b699  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0049b69c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0049b6a0:
    // 0049b6a0  837f2400               +cmp dword ptr [edi + 0x24], 0
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
    // 0049b6a4  0f8ead000000           -jle 0x49b757
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b757;
    }
    // 0049b6aa  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0049b6ae:
    // 0049b6ae  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049b6b1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b6b3  0f8ee2000000           -jle 0x49b79b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b79b;
    }
    // 0049b6b9  8b4724                 -mov eax, dword ptr [edi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0049b6bc  39c8                   +cmp eax, ecx
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
    // 0049b6be  0f8d0e010000           -jge 0x49b7d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b7d2;
    }
L_0x0049b6c4:
    // 0049b6c4  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0049b6c7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b6c9  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b6cd  895724                 -mov dword ptr [edi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049b6d0  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049b6d4  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049b6d7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b6d9  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b6db  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0049b6df  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0049b6e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0049b6e4:
    // 0049b6e4  74ba                   -je 0x49b6a0
    if (cpu.flags.zf)
    {
        goto L_0x0049b6a0;
    }
    // 0049b6e6  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049b6e9  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049b6ec  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049b6ee  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0049b6f4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b6f6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b6f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b6fb  0f8fd8000000           -jg 0x49b7d9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049b7d9;
    }
    // 0049b701  0f8c29010000           -jl 0x49b830
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b830;
    }
L_0x0049b707:
    // 0049b707  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0049b70a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049b70e  a168b24d00             -mov eax, dword ptr [0x4db268]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091944) /* 0x4db268 */);
    // 0049b713  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049b716  dc06                   -fadd qword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi));
    // 0049b718  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b71a  dd1e                   -fstp qword ptr [esi]
    app->getMemory<double>(cpu.esi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b71c  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049b71f  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 0049b722  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b724  dc4608                 -fadd qword ptr [esi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0049b727  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049b72a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049b72e  dd5e08                 -fstp qword ptr [esi + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b731  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 0049b734  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0049b737  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049b73a  dc07                   -fadd qword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi));
    // 0049b73c  01c3                   +add ebx, eax
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
    // 0049b73e  dd1f                   +fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b740  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049b743  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b747  d94714                 +fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 0049b74a  dc4708                 +fadd qword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0049b74d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b74e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049b752  dd5f08                 +fstp qword ptr [edi + 8]
    app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b755  eb8d                   -jmp 0x49b6e4
    goto L_0x0049b6e4;
L_0x0049b757:
    // 0049b757  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049b758  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049b75a  7c22                   -jl 0x49b77e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b77e;
    }
    // 0049b75c  83ef28                 -sub edi, 0x28
    (cpu.edi) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0049b75f:
    // 0049b75f  3b6c241c               +cmp ebp, dword ptr [esp + 0x1c]
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
    // 0049b763  742a                   -je 0x49b78f
    if (cpu.flags.zf)
    {
        goto L_0x0049b78f;
    }
    // 0049b765  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b769  3b4720                 +cmp eax, dword ptr [edi + 0x20]
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
    // 0049b76c  0f8e2effffff           -jle 0x49b6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b6a0;
    }
    // 0049b772  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049b777  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049b77a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b77b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b77c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b77d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b77e:
    // 0049b77e  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b782  6bc528                 -imul eax, ebp, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 0049b785  8b3d18d34d00           -mov edi, dword ptr [0x4dd318]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049b78b  01c7                   +add edi, eax
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
    // 0049b78d  ebd0                   -jmp 0x49b75f
    goto L_0x0049b75f;
L_0x0049b78f:
    // 0049b78f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b794  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049b797  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b798  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b799  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b79a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b79b:
    // 0049b79b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049b79f  40                     -inc eax
    (cpu.eax)++;
    // 0049b7a0  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0049b7a4  39d0                   +cmp eax, edx
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
    // 0049b7a6  7c25                   -jl 0x49b7cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b7cd;
    }
    // 0049b7a8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b7aa  8b3518d34d00           -mov esi, dword ptr [0x4dd318]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049b7b0  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x0049b7b4:
    // 0049b7b4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b7b8  3b4620                 +cmp eax, dword ptr [esi + 0x20]
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
    // 0049b7bb  0f8eedfeffff           -jle 0x49b6ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b6ae;
    }
    // 0049b7c1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049b7c6  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049b7c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b7ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b7cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b7cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b7cd:
    // 0049b7cd  83c628                 +add esi, 0x28
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
    // 0049b7d0  ebe2                   -jmp 0x49b7b4
    goto L_0x0049b7b4;
L_0x0049b7d2:
    // 0049b7d2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049b7d4  e9ebfeffff             -jmp 0x49b6c4
    goto L_0x0049b6c4;
L_0x0049b7d9:
    // 0049b7d9  d9048550685b00         -fld dword ptr [eax*4 + 0x5b6850]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5990480) /* 0x5b6850 */ + cpu.eax * 4)));
    // 0049b7e0  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 0049b7e2  dc26                   -fsub qword ptr [esi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi));
    // 0049b7e4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049b7e6  d90520d34d00           -fld dword ptr [0x4dd320]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5100320) /* 0x4dd320 */)));
    // 0049b7ec  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b7ee  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049b7f0  dd1d102c4e00           -fstp qword ptr [0x4e2c10]
    app->getMemory<double>(x86::reg32(5123088) /* 0x4e2c10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b7f6  dd4708                 -fld qword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 0049b7f9  dc6608                 -fsub qword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0049b7fc  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049b7fe  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049b802  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 0049b808  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049b80a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049b80d  dd1d182c4e00           -fstp qword ptr [0x4e2c18]
    app->getMemory<double>(x86::reg32(5123096) /* 0x4e2c18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b813  031c8a                 +add ebx, dword ptr [edx + ecx*4]
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
    // 0049b816  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049b818  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b81b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049b81f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b821  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049b825  ff1550d34d00           -call dword ptr [0x4dd350]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5100368) /* 0x4dd350 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b82b  e9d7feffff             -jmp 0x49b707
    goto L_0x0049b707;
L_0x0049b830:
    // 0049b830  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049b833  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049b836  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049b838  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0049b83e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b840  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b843  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b845  83f801                 +cmp eax, 1
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
    // 0049b848  7d05                   -jge 0x49b84f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b84f;
    }
    // 0049b84a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0049b84f:
    // 0049b84f  d9048d50685b00         -fld dword ptr [ecx*4 + 0x5b6850]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5990480) /* 0x5b6850 */ + cpu.ecx * 4)));
    // 0049b856  dd06                   -fld qword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi)));
    // 0049b858  dc27                   -fsub qword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi));
    // 0049b85a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049b85c  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 0049b862  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b864  d90520d34d00           -fld dword ptr [0x4dd320]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5100320) /* 0x4dd320 */)));
    // 0049b86a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b86c  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049b86e  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049b872  dd1d102c4e00           -fstp qword ptr [0x4e2c10]
    app->getMemory<double>(x86::reg32(5123088) /* 0x4e2c10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b878  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0049b87b  dc6708                 -fsub qword ptr [edi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0049b87e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b881  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049b883  031c82                 +add ebx, dword ptr [edx + eax*4]
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
    // 0049b886  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049b889  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049b88b  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049b88d  dd1d182c4e00           +fstp qword ptr [0x4e2c18]
    app->getMemory<double>(x86::reg32(5123096) /* 0x4e2c18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b893  ff1550d34d00           -call dword ptr [0x4dd350]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5100368) /* 0x4dd350 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b899  e969feffff             -jmp 0x49b707
    goto L_0x0049b707;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049b8a0);
    // 0049b8a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b8a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b8a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b8a3  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049b8a6  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049b8aa  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049b8ac  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0049b8b0  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049b8b4  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0049b8bb  a16cb24d00             -mov eax, dword ptr [0x4db26c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 0049b8c0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b8c2  8b1560b24d00           -mov edx, dword ptr [0x4db260]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */);
    // 0049b8c8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b8ca  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b8cc  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049b8ce  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049b8d2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049b8d9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b8db  8b3d18d34d00           -mov edi, dword ptr [0x4dd318]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049b8e1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049b8e4  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0049b8e7  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049b8ee  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b8f0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049b8f3  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b8f5  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0049b8f8  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0049b8fc:
    // 0049b8fc  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 0049b900  0f8efe000000           -jle 0x49ba04
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ba04;
    }
    // 0049b906  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0049b90a:
    // 0049b90a  8b4f24                 -mov ecx, dword ptr [edi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0049b90d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b90f  0f8433010000           -je 0x49ba48
    if (cpu.flags.zf)
    {
        goto L_0x0049ba48;
    }
    // 0049b915  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049b918  39d9                   +cmp ecx, ebx
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
    // 0049b91a  0f8d5d010000           -jge 0x49ba7d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ba7d;
    }
    // 0049b920  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049b922:
    // 0049b922  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0049b925  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b927  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b92b  895724                 -mov dword ptr [edi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049b92e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049b932  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049b935  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b937  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b939  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0049b93d  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0049b940  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0049b942:
    // 0049b942  74b8                   -je 0x49b8fc
    if (cpu.flags.zf)
    {
        goto L_0x0049b8fc;
    }
    // 0049b944  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049b947  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049b94a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049b94c  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0049b952  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b954  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b957  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b959  0f8e25010000           -jle 0x49ba84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ba84;
    }
    // 0049b95f  d9048550685b00         -fld dword ptr [eax*4 + 0x5b6850]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5990480) /* 0x5b6850 */ + cpu.eax * 4)));
    // 0049b966  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 0049b968  dc26                   -fsub qword ptr [esi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi));
    // 0049b96a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049b96c  d90520d34d00           -fld dword ptr [0x4dd320]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5100320) /* 0x4dd320 */)));
    // 0049b972  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b974  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049b976  dd1d102c4e00           -fstp qword ptr [0x4e2c10]
    app->getMemory<double>(x86::reg32(5123088) /* 0x4e2c10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b97c  dd4708                 -fld qword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 0049b97f  dc6608                 -fsub qword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0049b982  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049b984  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049b988  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 0049b98e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049b990  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049b993  dd1d182c4e00           -fstp qword ptr [0x4e2c18]
    app->getMemory<double>(x86::reg32(5123096) /* 0x4e2c18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b999  031c8a                 -add ebx, dword ptr [edx + ecx*4]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4)));
    // 0049b99c  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049b99e  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b9a1  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049b9a5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b9a7  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x0049b9ab:
    // 0049b9ab  ff1550d34d00           -call dword ptr [0x4dd350]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5100368) /* 0x4dd350 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049b9b1:
    // 0049b9b1  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0049b9b4  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049b9b8  a168b24d00             -mov eax, dword ptr [0x4db268]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091944) /* 0x4db268 */);
    // 0049b9bd  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049b9c0  dc06                   -fadd qword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi));
    // 0049b9c2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b9c4  dd1e                   -fstp qword ptr [esi]
    app->getMemory<double>(cpu.esi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b9c6  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049b9c9  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 0049b9cc  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b9ce  dc4608                 -fadd qword ptr [esi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0049b9d1  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049b9d4  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049b9d8  dd5e08                 -fstp qword ptr [esi + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b9db  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 0049b9de  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0049b9e1  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049b9e4  dc07                   -fadd qword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi));
    // 0049b9e6  01c3                   +add ebx, eax
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
    // 0049b9e8  dd1f                   +fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b9ea  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049b9ed  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b9f1  d94714                 +fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 0049b9f4  dc4708                 +fadd qword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0049b9f7  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b9f8  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049b9fc  dd5f08                 +fstp qword ptr [edi + 8]
    app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b9ff  e93effffff             -jmp 0x49b942
    goto L_0x0049b942;
L_0x0049ba04:
    // 0049ba04  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049ba05  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049ba07  7c22                   -jl 0x49ba2b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ba2b;
    }
    // 0049ba09  83ee28                 -sub esi, 0x28
    (cpu.esi) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0049ba0c:
    // 0049ba0c  3b6c241c               +cmp ebp, dword ptr [esp + 0x1c]
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
    // 0049ba10  742a                   -je 0x49ba3c
    if (cpu.flags.zf)
    {
        goto L_0x0049ba3c;
    }
    // 0049ba12  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049ba16  3b4620                 +cmp eax, dword ptr [esi + 0x20]
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
    // 0049ba19  0f8eddfeffff           -jle 0x49b8fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b8fc;
    }
    // 0049ba1f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049ba24  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049ba27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ba2b:
    // 0049ba2b  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049ba2f  6bc528                 -imul eax, ebp, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 0049ba32  8b3518d34d00           -mov esi, dword ptr [0x4dd318]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049ba38  01c6                   +add esi, eax
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
    // 0049ba3a  ebd0                   -jmp 0x49ba0c
    goto L_0x0049ba0c;
L_0x0049ba3c:
    // 0049ba3c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ba41  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049ba44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ba48:
    // 0049ba48  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049ba4c  40                     -inc eax
    (cpu.eax)++;
    // 0049ba4d  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0049ba51  39d0                   +cmp eax, edx
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
    // 0049ba53  7c23                   -jl 0x49ba78
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ba78;
    }
    // 0049ba55  8b3d18d34d00           -mov edi, dword ptr [0x4dd318]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049ba5b  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x0049ba5f:
    // 0049ba5f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049ba63  3b4720                 +cmp eax, dword ptr [edi + 0x20]
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
    // 0049ba66  0f8e9efeffff           -jle 0x49b90a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b90a;
    }
    // 0049ba6c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049ba71  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049ba74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba77  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ba78:
    // 0049ba78  83c728                 +add edi, 0x28
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
    // 0049ba7b  ebe2                   -jmp 0x49ba5f
    goto L_0x0049ba5f;
L_0x0049ba7d:
    // 0049ba7d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ba7f  e99efeffff             -jmp 0x49b922
    goto L_0x0049b922;
L_0x0049ba84:
    // 0049ba84  0f8d27ffffff           -jge 0x49b9b1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b9b1;
    }
    // 0049ba8a  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049ba8d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049ba90  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049ba92  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0049ba98  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ba9a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049ba9d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ba9f  83f801                 +cmp eax, 1
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
    // 0049baa2  7d05                   -jge 0x49baa9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049baa9;
    }
    // 0049baa4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0049baa9:
    // 0049baa9  d9048d50685b00         -fld dword ptr [ecx*4 + 0x5b6850]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5990480) /* 0x5b6850 */ + cpu.ecx * 4)));
    // 0049bab0  dd06                   -fld qword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi)));
    // 0049bab2  dc27                   -fsub qword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi));
    // 0049bab4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049bab6  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 0049babc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049babe  d90520d34d00           -fld dword ptr [0x4dd320]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5100320) /* 0x4dd320 */)));
    // 0049bac4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049bac6  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049bac8  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049bacc  dd1d102c4e00           -fstp qword ptr [0x4e2c10]
    app->getMemory<double>(x86::reg32(5123088) /* 0x4e2c10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049bad2  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0049bad5  dc6708                 -fsub qword ptr [edi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0049bad8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049badb  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049badd  031c82                 +add ebx, dword ptr [edx + eax*4]
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
    // 0049bae0  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049bae3  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049bae5  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049bae7  dd1d182c4e00           +fstp qword ptr [0x4e2c18]
    app->getMemory<double>(x86::reg32(5123096) /* 0x4e2c18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049baed  e9b9feffff             -jmp 0x49b9ab
    goto L_0x0049b9ab;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49baf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049baf4);
    // 0049baf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049baf5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049baf6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049baf7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049baf8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049baf9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049bafa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049bafc  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0049bb01  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049bb04  e897db0000             -call 0x4a96a0
    cpu.esp -= 4;
    sub_4a96a0(app, cpu);
    if (cpu.terminate) return;
    // 0049bb09  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0049bb0c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bb0e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049bb10  0fbdc0                 -bsr eax, eax
    if (cpu.eax == 0)
    {
        cpu.flags.zf = 1;
    }
    else
    {
        cpu.flags.zf = 0;
        cpu.eax = x86::reg32(31 - __builtin_clz(cpu.eax));
    }
    // 0049bb13  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049bb15  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049bb1c  892d242c4e00           -mov dword ptr [0x4e2c24], ebp
    app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */) = cpu.ebp;
    // 0049bb22  39c6                   +cmp esi, eax
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
    // 0049bb24  7e19                   -jle 0x49bb3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bb3f;
    }
L_0x0049bb26:
    // 0049bb26  833d242c4e0000         +cmp dword ptr [0x4e2c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bb2d  7c27                   -jl 0x49bb56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bb56;
    }
    // 0049bb2f  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049bb32  890d202c4e00           -mov dword ptr [0x4e2c20], ecx
    app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */) = cpu.ecx;
    // 0049bb38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb3e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bb3f:
    // 0049bb3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049bb41  0fbcc0                 -bsf eax, eax
    if (cpu.eax == 0)
    {
        cpu.flags.zf = 1;
    }
    else
    {
        cpu.flags.zf = 0;
        cpu.eax = x86::reg32(__builtin_ctz(cpu.eax));
    }
    // 0049bb44  39c3                   +cmp ebx, eax
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
    // 0049bb46  75de                   -jne 0x49bb26
    if (!cpu.flags.zf)
    {
        goto L_0x0049bb26;
    }
    // 0049bb48  8b048524d34d00         -mov eax, dword ptr [eax*4 + 0x4dd324]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100324) /* 0x4dd324 */ + cpu.eax * 4);
    // 0049bb4f  a3242c4e00             -mov dword ptr [0x4e2c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */) = cpu.eax;
    // 0049bb54  ebd0                   -jmp 0x49bb26
    goto L_0x0049bb26;
L_0x0049bb56:
    // 0049bb56  a14cd34d00             -mov eax, dword ptr [0x4dd34c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100364) /* 0x4dd34c */);
    // 0049bb5b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049bb5d  a3242c4e00             -mov dword ptr [0x4e2c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */) = cpu.eax;
    // 0049bb62  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049bb64  e8bff8ffff             -call 0x49b428
    cpu.esp -= 4;
    sub_49b428(app, cpu);
    if (cpu.terminate) return;
    // 0049bb69  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049bb6c  890d202c4e00           -mov dword ptr [0x4e2c20], ecx
    app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */) = cpu.ecx;
    // 0049bb72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49bb7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049bb7c);
    // 0049bb7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bb7d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bb7e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049bb7f  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0049bb82  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049bb86  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0049bb8a  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049bb8e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049bb92  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049bb96  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bb98  8b3518d34d00           -mov esi, dword ptr [0x4dd318]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049bb9e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049bba2  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049bba6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049bba8  0f8498020000           -je 0x49be46
    if (cpu.flags.zf)
    {
        goto L_0x0049be46;
    }
L_0x0049bbae:
    // 0049bbae  8b049554d34d00         -mov eax, dword ptr [edx*4 + 0x4dd354]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100372) /* 0x4dd354 */ + cpu.edx * 4);
    // 0049bbb5  a350d34d00             -mov dword ptr [0x4dd350], eax
    app->getMemory<x86::reg32>(x86::reg32(5100368) /* 0x4dd350 */) = cpu.eax;
    // 0049bbba  8a255cb24d00           -mov ah, byte ptr [0x4db25c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 0049bbc0  80fc0f                 +cmp ah, 0xf
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
    // 0049bbc3  0f8587020000           -jne 0x49be50
    if (!cpu.flags.zf)
    {
        goto L_0x0049be50;
    }
L_0x0049bbc9:
    // 0049bbc9  8b049574d34d00         -mov eax, dword ptr [edx*4 + 0x4dd374]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100404) /* 0x4dd374 */ + cpu.edx * 4);
    // 0049bbd0  a350d34d00             -mov dword ptr [0x4dd350], eax
    app->getMemory<x86::reg32>(x86::reg32(5100368) /* 0x4dd350 */) = cpu.eax;
L_0x0049bbd5:
    // 0049bbd5  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bbd9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bbdd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049bbe2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049bbe4  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bbe8  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0049bbec  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0049bbf0  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0049bbf4  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049bbf7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049bbf9  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0049bbfb  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049bbff  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0049bc03  39d1                   +cmp ecx, edx
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
    // 0049bc05  7e3a                   -jle 0x49bc41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bc41;
    }
    // 0049bc07  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bc0b  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0049bc0e:
    // 0049bc0e  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049bc11  39f7                   +cmp edi, esi
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
    // 0049bc13  0f8e45020000           -jle 0x49be5e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049be5e;
    }
    // 0049bc19  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049bc1b  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x0049bc1f:
    // 0049bc1f  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049bc23  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049bc25  39f3                   +cmp ebx, esi
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
    // 0049bc27  0f8d40020000           -jge 0x49be6d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049be6d;
    }
    // 0049bc2d  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 0049bc31  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x0049bc35:
    // 0049bc35  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bc39  42                     -inc edx
    (cpu.edx)++;
    // 0049bc3a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049bc3d  39da                   +cmp edx, ebx
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
    // 0049bc3f  7ccd                   -jl 0x49bc0e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bc0e;
    }
L_0x0049bc41:
    // 0049bc41  3b3d58b24d00           +cmp edi, dword ptr [0x4db258]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bc47  0f8d37020000           -jge 0x49be84
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049be84;
    }
    // 0049bc4d  3b2d50b24d00           +cmp ebp, dword ptr [0x4db250]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bc53  0f8c2b020000           -jl 0x49be84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049be84;
    }
    // 0049bc59  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049bc5d  3b0554b24d00           +cmp eax, dword ptr [0x4db254]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bc63  0f8d1b020000           -jge 0x49be84
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049be84;
    }
    // 0049bc69  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049bc6d  3b054cb24d00           +cmp eax, dword ptr [0x4db24c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bc73  0f8c0b020000           -jl 0x49be84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049be84;
    }
    // 0049bc79  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049bc7d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049bc7f  7554                   -jne 0x49bcd5
    if (!cpu.flags.zf)
    {
        goto L_0x0049bcd5;
    }
    // 0049bc81  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bc85  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049bc88  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049bc8b  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0049bc8f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x0049bc93:
    // 0049bc93  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049bc97  3b44241c               +cmp eax, dword ptr [esp + 0x1c]
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
    // 0049bc9b  7d38                   -jge 0x49bcd5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bcd5;
    }
    // 0049bc9d  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049bca1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bca5  8d5e08                 -lea ebx, [esi + 8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049bca8  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049bcaa  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0049bcae  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049bcb1  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049bcb4  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049bcb6  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049bcb9  2b4608                 -sub eax, dword ptr [esi + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0049bcbc  2b5e0c                 -sub ebx, dword ptr [esi + 0xc]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 0049bcbf  2b4e08                 -sub ecx, dword ptr [esi + 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0049bcc2  2b560c                 -sub edx, dword ptr [esi + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 0049bcc5  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049bcc8  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049bccb  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bccd  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0049bcd1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049bcd3  74be                   -je 0x49bc93
    if (cpu.flags.zf)
    {
        goto L_0x0049bc93;
    }
L_0x0049bcd5:
    // 0049bcd5  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049bcd9  3b054cb24d00           +cmp eax, dword ptr [0x4db24c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bcdf  0f8caa010000           -jl 0x49be8f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049be8f;
    }
L_0x0049bce5:
    // 0049bce5  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049bce9  3b0554b24d00           +cmp eax, dword ptr [0x4db254]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bcef  0f8dc1010000           -jge 0x49beb6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049beb6;
    }
L_0x0049bcf5:
    // 0049bcf5  3b3d50b24d00           +cmp edi, dword ptr [0x4db250]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bcfb  0f8cdc010000           -jl 0x49bedd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bedd;
    }
L_0x0049bd01:
    // 0049bd01  3b2d58b24d00           +cmp ebp, dword ptr [0x4db258]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bd07  0f8df7010000           -jge 0x49bf04
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bf04;
    }
    // 0049bd0d  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 0049bd12  746c                   -je 0x49bd80
    if (cpu.flags.zf)
    {
        goto L_0x0049bd80;
    }
L_0x0049bd14:
    // 0049bd14  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bd18  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bd1c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bd1e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049bd23  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0049bd27  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 0049bd2b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049bd2f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049bd31  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049bd34  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049bd38  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0049bd3c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bd40  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0049bd42  39d0                   +cmp eax, edx
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
    // 0049bd44  7e3a                   -jle 0x49bd80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bd80;
    }
    // 0049bd46  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bd4a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0049bd4d:
    // 0049bd4d  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049bd50  39df                   +cmp edi, ebx
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
    // 0049bd52  0f8ed5010000           -jle 0x49bf2d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bf2d;
    }
    // 0049bd58  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049bd5a  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x0049bd5e:
    // 0049bd5e  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049bd62  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049bd64  39cb                   +cmp ebx, ecx
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
    // 0049bd66  0f8dd0010000           -jge 0x49bf3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bf3c;
    }
    // 0049bd6c  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 0049bd70  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x0049bd74:
    // 0049bd74  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bd78  42                     -inc edx
    (cpu.edx)++;
    // 0049bd79  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049bd7c  39ca                   +cmp edx, ecx
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
    // 0049bd7e  7ccd                   -jl 0x49bd4d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bd4d;
    }
L_0x0049bd80:
    // 0049bd80  39ef                   +cmp edi, ebp
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
    // 0049bd82  0f8dcb010000           -jge 0x49bf53
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bf53;
    }
    // 0049bd88  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bd8c  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bd90  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049bd92  48                     -dec eax
    (cpu.eax)--;
    // 0049bd93  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049bd95  7e29                   -jle 0x49bdc0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bdc0;
    }
    // 0049bd97  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0049bd99:
    // 0049bd99  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049bd9d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bda1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bda2  a118d34d00             -mov eax, dword ptr [0x4dd318]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049bda7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049bda9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049bdab  e8b0f7ffff             -call 0x49b560
    cpu.esp -= 4;
    sub_49b560(app, cpu);
    if (cpu.terminate) return;
    // 0049bdb0  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bdb4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049bdb6  46                     -inc esi
    (cpu.esi)++;
    // 0049bdb7  83c528                 -add ebp, 0x28
    (cpu.ebp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0049bdba  39ce                   +cmp esi, ecx
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
    // 0049bdbc  7cdb                   -jl 0x49bd99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bd99;
    }
    // 0049bdbe  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049bdc0:
    // 0049bdc0  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049bdc4  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049bdc7  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bdcb  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049bdcf  39d8                   +cmp eax, ebx
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
    // 0049bdd1  7c06                   -jl 0x49bdd9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bdd9;
    }
    // 0049bdd3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049bdd5  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
L_0x0049bdd9:
    // 0049bdd9  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049bddd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bddf  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049bde1  a05db24d00             -mov al, byte ptr [0x4db25d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091933) /* 0x4db25d */);
    // 0049bde6  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049bdec  39c2                   +cmp edx, eax
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
    // 0049bdee  7415                   -je 0x49be05
    if (cpu.flags.zf)
    {
        goto L_0x0049be05;
    }
    // 0049bdf0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bdf2  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049bdf4  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049bdf8  e86be6ffff             -call 0x49a468
    cpu.esp -= 4;
    sub_49a468(app, cpu);
    if (cpu.terminate) return;
    // 0049bdfd  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049be01  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0049be05:
    // 0049be05  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049be09  e8e6fcffff             -call 0x49baf4
    cpu.esp -= 4;
    sub_49baf4(app, cpu);
    if (cpu.terminate) return;
    // 0049be0e  837c244c00             +cmp dword ptr [esp + 0x4c], 0
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
    // 0049be13  0f8c16020000           -jl 0x49c02f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c02f;
    }
    // 0049be19  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049be1d  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049be21  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049be23  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049be25  e81af8ffff             -call 0x49b644
    cpu.esp -= 4;
    sub_49b644(app, cpu);
    if (cpu.terminate) return;
L_0x0049be2a:
    // 0049be2a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049be2c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049be30  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049be32  7407                   -je 0x49be3b
    if (cpu.flags.zf)
    {
        goto L_0x0049be3b;
    }
    // 0049be34  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049be36  e8c18afeff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x0049be3b:
    // 0049be3b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049be3d  83c43c                 +add esp, 0x3c
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
    // 0049be40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be43  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049be46:
    // 0049be46  e845f5ffff             -call 0x49b390
    cpu.esp -= 4;
    sub_49b390(app, cpu);
    if (cpu.terminate) return;
    // 0049be4b  e95efdffff             -jmp 0x49bbae
    goto L_0x0049bbae;
L_0x0049be50:
    // 0049be50  80fc10                 +cmp ah, 0x10
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
    // 0049be53  0f8470fdffff           -je 0x49bbc9
    if (cpu.flags.zf)
    {
        goto L_0x0049bbc9;
    }
    // 0049be59  e977fdffff             -jmp 0x49bbd5
    goto L_0x0049bbd5;
L_0x0049be5e:
    // 0049be5e  39f5                   +cmp ebp, esi
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
    // 0049be60  0f8db9fdffff           -jge 0x49bc1f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bc1f;
    }
    // 0049be66  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049be68  e9b2fdffff             -jmp 0x49bc1f
    goto L_0x0049bc1f;
L_0x0049be6d:
    // 0049be6d  3b5c2438               +cmp ebx, dword ptr [esp + 0x38]
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
    // 0049be71  0f8ebefdffff           -jle 0x49bc35
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bc35;
    }
    // 0049be77  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0049be7b  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049be7f  e9b1fdffff             -jmp 0x49bc35
    goto L_0x0049bc35;
L_0x0049be84:
    // 0049be84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049be86  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0049be89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be8c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049be8f:
    // 0049be8f  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049be93  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049be97  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049be9b  e8783c0100             -call 0x4afb18
    cpu.esp -= 4;
    sub_4afb18(app, cpu);
    if (cpu.terminate) return;
    // 0049bea0  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049bea4  83f803                 +cmp eax, 3
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
    // 0049bea7  7cdb                   -jl 0x49be84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049be84;
    }
    // 0049bea9  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 0049beb1  e92ffeffff             -jmp 0x49bce5
    goto L_0x0049bce5;
L_0x0049beb6:
    // 0049beb6  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049beba  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bebe  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bec2  e8b93d0100             -call 0x4afc80
    cpu.esp -= 4;
    sub_4afc80(app, cpu);
    if (cpu.terminate) return;
    // 0049bec7  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049becb  83f803                 +cmp eax, 3
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
    // 0049bece  7cb4                   -jl 0x49be84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049be84;
    }
    // 0049bed0  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 0049bed8  e918feffff             -jmp 0x49bcf5
    goto L_0x0049bcf5;
L_0x0049bedd:
    // 0049bedd  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049bee1  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bee5  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bee9  e8ea3e0100             -call 0x4afdd8
    cpu.esp -= 4;
    sub_4afdd8(app, cpu);
    if (cpu.terminate) return;
    // 0049beee  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049bef2  83f803                 +cmp eax, 3
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
    // 0049bef5  7c8d                   -jl 0x49be84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049be84;
    }
    // 0049bef7  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 0049beff  e9fdfdffff             -jmp 0x49bd01
    goto L_0x0049bd01;
L_0x0049bf04:
    // 0049bf04  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049bf08  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bf0c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bf10  e823400100             -call 0x4aff38
    cpu.esp -= 4;
    sub_4aff38(app, cpu);
    if (cpu.terminate) return;
    // 0049bf15  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049bf19  83f803                 +cmp eax, 3
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
    // 0049bf1c  0f8df2fdffff           -jge 0x49bd14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bd14;
    }
L_0x0049bf22:
    // 0049bf22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bf24  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0049bf27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf2a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049bf2d:
    // 0049bf2d  39dd                   +cmp ebp, ebx
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
    // 0049bf2f  0f8d29feffff           -jge 0x49bd5e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bd5e;
    }
    // 0049bf35  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049bf37  e922feffff             -jmp 0x49bd5e
    goto L_0x0049bd5e;
L_0x0049bf3c:
    // 0049bf3c  3b5c2438               +cmp ebx, dword ptr [esp + 0x38]
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
    // 0049bf40  0f8e2efeffff           -jle 0x49bd74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bd74;
    }
    // 0049bf46  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0049bf4a  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049bf4e  e921feffff             -jmp 0x49bd74
    goto L_0x0049bd74;
L_0x0049bf53:
    // 0049bf53  75cd                   -jne 0x49bf22
    if (!cpu.flags.zf)
    {
        goto L_0x0049bf22;
    }
    // 0049bf55  837c244c00             +cmp dword ptr [esp + 0x4c], 0
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
    // 0049bf5a  0f8cc1000000           -jl 0x49c021
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c021;
    }
    // 0049bf60  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049bf62:
    // 0049bf62  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049bf66  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049bf6a  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 0049bf6d  8b3518d34d00           -mov esi, dword ptr [0x4dd318]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049bf73  db0403                 -fild dword ptr [ebx + eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1))));
    // 0049bf76  d90520d34d00           -fld dword ptr [0x4dd320]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5100320) /* 0x4dd320 */)));
    // 0049bf7c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049bf83  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049bf85  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049bf87  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049bf89  dd1cc6                 -fstp qword ptr [esi + eax*8]
    app->getMemory<double>(cpu.esi + cpu.eax * 8) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049bf8c  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0049bf90  db4304                 -fild dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 0049bf93  c744c62401000000       -mov dword ptr [esi + eax*8 + 0x24], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 8) = 1 /*0x1*/;
    // 0049bf9b  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049bf9f  897cc620               -mov dword ptr [esi + eax*8 + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */ + cpu.eax * 8) = cpu.edi;
    // 0049bfa3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049bfa5  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0049bfa8  dd5cc608               -fstp qword ptr [esi + eax*8 + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049bfac  895cc618               -mov dword ptr [esi + eax*8 + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.eax * 8) = cpu.ebx;
    // 0049bfb0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049bfb2  7577                   -jne 0x49c02b
    if (!cpu.flags.zf)
    {
        goto L_0x0049c02b;
    }
    // 0049bfb4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0049bfb9:
    // 0049bfb9  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049bfbd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049bfc1  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 0049bfc4  db0403                 -fild dword ptr [ebx + eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1))));
    // 0049bfc7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049bfce  d90520d34d00           -fld dword ptr [0x4dd320]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5100320) /* 0x4dd320 */)));
    // 0049bfd4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049bfd6  a118d34d00             -mov eax, dword ptr [0x4dd318]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100312) /* 0x4dd318 */);
    // 0049bfdb  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0049bfde  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049bfe0  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049bfe2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049bfe4  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049bfe6  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049bfea  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049bfee  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049bff0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049bff3  db4304                 -fild dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 0049bff6  c7402401000000         -mov dword ptr [eax + 0x24], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 0049bffd  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049c000  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049c005  897820                 -mov dword ptr [eax + 0x20], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0049c008  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c00a  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 0049c00e  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c011  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049c016  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0049c018  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049c01c  e9b8fdffff             -jmp 0x49bdd9
    goto L_0x0049bdd9;
L_0x0049c021:
    // 0049c021  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049c026  e937ffffff             -jmp 0x49bf62
    goto L_0x0049bf62;
L_0x0049c02b:
    // 0049c02b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049c02d  eb8a                   -jmp 0x49bfb9
    goto L_0x0049bfb9;
L_0x0049c02f:
    // 0049c02f  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049c033  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c037  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c039  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c03b  e860f8ffff             -call 0x49b8a0
    cpu.esp -= 4;
    sub_49b8a0(app, cpu);
    if (cpu.terminate) return;
    // 0049c040  e9e5fdffff             -jmp 0x49be2a
    goto L_0x0049be2a;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c048(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c048);
    // 0049c048  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c049  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c04a  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0049c050  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c052  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049c054  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0049c058  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0049c05c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049c060  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0049c063  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049c066  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049c069  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049c06c  48                     -dec eax
    (cpu.eax)--;
    // 0049c06d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049c071  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049c075  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c076  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049c079  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c07a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049c07d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049c07f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049c082  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c086  48                     -dec eax
    (cpu.eax)--;
    // 0049c087  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0049c08c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049c090  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0049c094  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c096  e8e1faffff             -call 0x49bb7c
    cpu.esp -= 4;
    sub_49bb7c(app, cpu);
    if (cpu.terminate) return;
    // 0049c09b  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0049c0a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c0a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c0a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c0a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c0a4);
    // 0049c0a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c0a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c0a6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c0a7  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0049c0ad  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 0049c0b4  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049c0b6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c0b8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049c0ba  7e1c                   -jle 0x49c0d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c0d8;
    }
    // 0049c0bc  8d0ced00000000         -lea ecx, [ebp*8]
    cpu.ecx = x86::reg32(cpu.ebp * 8);
    // 0049c0c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c0c5:
    // 0049c0c5  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049c0c7  8d3c04                 -lea edi, [esp + eax]
    cpu.edi = x86::reg32(cpu.esp + cpu.eax * 1);
    // 0049c0ca  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c0cd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c0d0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c0d1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c0d2  39c8                   +cmp eax, ecx
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
    // 0049c0d4  7cef                   -jl 0x49c0c5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c0c5;
    }
    // 0049c0d6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049c0d8:
    // 0049c0d8  8b942418020000         -mov edx, dword ptr [esp + 0x218]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0049c0df  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c0e0  8b8c2418020000         -mov ecx, dword ptr [esp + 0x218]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0049c0e7  8b842404020000         -mov eax, dword ptr [esp + 0x204]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 0049c0ee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c0ef  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049c0f1  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c0f5  e882faffff             -call 0x49bb7c
    cpu.esp -= 4;
    sub_49bb7c(app, cpu);
    if (cpu.terminate) return;
    // 0049c0fa  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0049c100  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c101  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c102  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c103  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c110);
    // 0049c110  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c111  8b1594d34d00           -mov edx, dword ptr [0x4dd394]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100436) /* 0x4dd394 */);
    // 0049c117  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c119  7532                   -jne 0x49c14d
    if (!cpu.flags.zf)
    {
        goto L_0x0049c14d;
    }
    // 0049c11b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c11c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c11d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049c122  891580fd5600           -mov dword ptr [0x56fd80], edx
    app->getMemory<x86::reg32>(x86::reg32(5700992) /* 0x56fd80 */) = cpu.edx;
L_0x0049c128:
    // 0049c128  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049c12d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049c12f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c132  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c134  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049c136  40                     -inc eax
    (cpu.eax)++;
    // 0049c137  89817cfd5600           -mov dword ptr [ecx + 0x56fd7c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5700988) /* 0x56fd7c */) = cpu.eax;
    // 0049c13d  81f900100000           +cmp ecx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c143  75e3                   -jne 0x49c128
    if (!cpu.flags.zf)
    {
        goto L_0x0049c128;
    }
    // 0049c145  ff0594d34d00           -inc dword ptr [0x4dd394]
    (app->getMemory<x86::reg32>(x86::reg32(5100436) /* 0x4dd394 */))++;
    // 0049c14b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c14c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049c14d:
    // 0049c14d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c14e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49c150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c150);
    // 0049c150  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c151  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c152  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c153  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c154  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c155  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c157  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049c15a  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 0049c160  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0049c163  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c165  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0049c168  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c16a  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c16c  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049c16e  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c170  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c175  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c177  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049c17e  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c180  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c182  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c184  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c186  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0049c18c  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0049c18f  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c191  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c193  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049c195  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c197  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c19c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c19e  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049c1a5  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c1a7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c1a9  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0049c1ac  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 0049c1af  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049c1b2  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 0049c1b5  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049c1b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c1b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c1b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c1ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c1bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c1bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c1c0);
    // 0049c1c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c1c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c1c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c1c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c1c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c1c5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c1c7  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049c1ca  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 0049c1d0  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0049c1d3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c1d5  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0049c1db  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0049c1de  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c1e0  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c1e2  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049c1e4  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1e6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c1eb  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1ed  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049c1f4  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c1f6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c1f8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c1fa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c1fc  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0049c1ff  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c201  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c203  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049c205  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c207  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c20c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c20e  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0049c215  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c217  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c219  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049c21b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0049c21e  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 0049c221  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049c224  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 0049c227  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049c229  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c22a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c22b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c22c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c22d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c22e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49c230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c230);
    // 0049c230  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c231  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049c234  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049c236  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c23a  e8e53e0100             -call 0x4b0124
    cpu.esp -= 4;
    sub_4b0124(app, cpu);
    if (cpu.terminate) return;
    // 0049c23f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049c241  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c243  e8dc3e0100             -call 0x4b0124
    cpu.esp -= 4;
    sub_4b0124(app, cpu);
    if (cpu.terminate) return;
    // 0049c248  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049c24a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c24e  e8f93e0100             -call 0x4b014c
    cpu.esp -= 4;
    sub_4b014c(app, cpu);
    if (cpu.terminate) return;
    // 0049c253  e86a3f0100             -call 0x4b01c2
    cpu.esp -= 4;
    sub_4b01c2(app, cpu);
    if (cpu.terminate) return;
    // 0049c258  dc0d840d4d00           -fmul qword ptr [0x4d0d84]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5049732) /* 0x4d0d84 */));
    // 0049c25e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049c261  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c262  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c264(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c264);
    // 0049c264  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c267  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c269  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0049c26b  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c26e  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0049c270  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c272  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c275  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0049c277  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c279  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0049c27b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c27e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49c280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c280);
    // 0049c280  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0049c284  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0049c288  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c28c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c28c);
    // 0049c28c  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0049c290  d8742408               -fdiv dword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0049c294  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c298(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c298);
    // 0049c298  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0049c29a  d8742404               -fdiv dword ptr [esp + 4]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0049c29e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c2a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c2a4);
    // 0049c2a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c2a5  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0049c2a9  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0049c2ab  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2ac  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c2b0);
    // 0049c2b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c2b1  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0049c2b5  dc0d8c0d4d00           -fmul qword ptr [0x4d0d8c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5049740) /* 0x4d0d8c */));
    // 0049c2bb  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0049c2bd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2be  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c2c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c2c4);
    // 0049c2c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c2c5  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0049c2c9  dc0d940d4d00           -fmul qword ptr [0x4d0d94]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5049748) /* 0x4d0d94 */));
    // 0049c2cf  d9ff                   -fcos 
    cpu.fpu.st(0) = cpu.fpu.cos(cpu.fpu.st(0));
    // 0049c2d1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2d2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c2d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c2d8);
    // 0049c2d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c2d9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c2db  dd059c0d4d00           -fld qword ptr [0x4d0d9c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5049756) /* 0x4d0d9c */)));
    // 0049c2e1  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c2e3  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049c2e5  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0049c2e7  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c2e9  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0049c2eb  d9ff                   -fcos 
    cpu.fpu.st(0) = cpu.fpu.cos(cpu.fpu.st(0));
    // 0049c2ed  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c2ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c2f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c2f4);
    // 0049c2f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c2f5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c2f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c2f7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c2fa  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c2fe  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049c300  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c304  e8cfffffff             -call 0x49c2d8
    cpu.esp -= 4;
    sub_49c2d8(app, cpu);
    if (cpu.terminate) return;
    // 0049c309  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0049c30c  d8742404               -fdiv dword ptr [esp + 4]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0049c310  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c313  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c314  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c315  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c316  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c31c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c31c);
    // 0049c31c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c31d  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0049c321  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0049c325  e8113e0000             -call 0x4a013b
    cpu.esp -= 4;
    sub_4a013b(app, cpu);
    if (cpu.terminate) return;
    // 0049c32a  dc0da40d4d00           -fmul qword ptr [0x4d0da4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5049764) /* 0x4d0da4 */));
    // 0049c330  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c331  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c340);
    // 0049c340  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c341  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c342  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c343  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c344  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0049c347  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049c34b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049c34d  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0049c351  39d8                   +cmp eax, ebx
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
    // 0049c353  0f84fd000000           -je 0x49c456
    if (cpu.flags.zf)
    {
        goto L_0x0049c456;
    }
L_0x0049c359:
    // 0049c359  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c35d  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c35f  7513                   -jne 0x49c374
    if (!cpu.flags.zf)
    {
        goto L_0x0049c374;
    }
    // 0049c361  3b7c2424               +cmp edi, dword ptr [esp + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c365  740b                   -je 0x49c372
    if (cpu.flags.zf)
    {
        goto L_0x0049c372;
    }
    // 0049c367  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0049c36c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049c36e  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0049c370  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0049c372:
    // 0049c372  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
L_0x0049c374:
    // 0049c374  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c377  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 0049c37a  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c37c  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 0049c37e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c380  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c383  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 0049c386  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c388  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c38a  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c38d  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 0049c390  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c392  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0049c395  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c397  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c39a  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049c39d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c39f  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c3a2  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c3a5  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 0049c3a8  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c3aa  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049c3ad  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c3af  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c3b2  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 0049c3b5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c3b7  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c3ba  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 0049c3bd  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 0049c3c0  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 0049c3c3  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 0049c3c5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c3c7  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 0049c3ca  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 0049c3cd  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c3cf  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c3d2  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 0049c3d5  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0049c3d8  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 0049c3db  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 0049c3de  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c3e0  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 0049c3e3  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049c3e6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c3e8  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c3eb  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 0049c3ee  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049c3f1  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 0049c3f4  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 0049c3f7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c3f9  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 0049c3fc  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 0049c3ff  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c401  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c404  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 0049c407  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 0049c40a  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 0049c40d  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 0049c40f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c411  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 0049c414  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 0049c417  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c419  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c41c  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 0049c41f  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0049c422  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 0049c425  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 0049c428  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c42a  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 0049c42d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049c430  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c432  d95b1c                 -fstp dword ptr [ebx + 0x1c]
    app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c435  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 0049c438  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049c43b  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 0049c43e  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 0049c441  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c443  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 0049c446  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 0049c449  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c44b  d95b20                 -fstp dword ptr [ebx + 0x20]
    app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c44e  83c42c                 +add esp, 0x2c
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
    // 0049c451  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c452  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c453  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c454  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c455  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c456:
    // 0049c456  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0049c45b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049c45d  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c461  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049c463  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c465  e9effeffff             -jmp 0x49c359
    goto L_0x0049c359;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49c46c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c46c);
    // 0049c46c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c46d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c46e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c470  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c472  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c474  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c476  7e5c                   -jle 0x49c4d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c4d4;
    }
L_0x0049c478:
    // 0049c478  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049c47a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049c47c  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c47e  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 0049c480  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c482  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0049c485  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c487  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049c48a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049c48c  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c48f  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 0049c492  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c495  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 0049c498  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c49b  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 0049c49e  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049c4a0  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c4a2  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c4a4  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c4a6  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c4a9  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 0049c4ac  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c4af  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049c4b2  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c4b5  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 0049c4b8  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049c4ba  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c4bc  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c4be  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c4c0  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049c4c3  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c4c5  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c4c8  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c4cb  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c4ce  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c4cf  75a7                   -jne 0x49c478
    if (!cpu.flags.zf)
    {
        goto L_0x0049c478;
    }
    // 0049c4d1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049c4d4:
    // 0049c4d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c4d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c4d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c4d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c4d8);
    // 0049c4d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c4d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c4da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c4db  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c4de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c4e0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c4e2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c4e4  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c4e7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c4eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c4ed  0f8e81000000           -jle 0x49c574
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c574;
    }
L_0x0049c4f3:
    // 0049c4f3  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049c4f5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049c4f7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c4f9  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c4fb  d80a                   +fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 0049c4fd  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c4ff  d84a04                 +fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0049c502  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c504  d84a08                 +fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049c507  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049c509  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c50c  d84a0c                 +fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 0049c50f  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c512  d84a10                 +fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 0049c515  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c518  d84a14                 +fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 0049c51b  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049c51d  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c51f  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c521  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c523  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c526  d84a18                 +fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 0049c529  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c52c  d84a1c                 +fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049c52f  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c532  d84a20                 +fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 0049c535  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049c537  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c539  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c53b  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c53d  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049c540  d91b                   +fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c542  d95b04                 +fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c545  d95b08                 +fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c548  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c54b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c54d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049c54f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c551  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0049c553  d802                   +fadd dword ptr [edx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx));
    // 0049c555  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0049c558  d84204                 +fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0049c55b  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0049c55e  d84208                 +fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049c561  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049c563  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049c566  d91b                   +fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c568  d95b04                 +fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c56b  d95b08                 +fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c56e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c570  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c571  7580                   -jne 0x49c4f3
    if (!cpu.flags.zf)
    {
        goto L_0x0049c4f3;
    }
    // 0049c573  90                     -nop 
    ;
L_0x0049c574:
    // 0049c574  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c577  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c578  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c579  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c57a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49c580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c580);
    // 0049c580  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c581  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c582  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c583  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c586  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c588  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049c58a  e889800000             -call 0x4a4618
    cpu.esp -= 4;
    sub_4a4618(app, cpu);
    if (cpu.terminate) return;
    // 0049c58f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c591  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c593  752c                   -jne 0x49c5c1
    if (!cpu.flags.zf)
    {
        goto L_0x0049c5c1;
    }
    // 0049c595  b890010000             -mov eax, 0x190
    cpu.eax = 400 /*0x190*/;
    // 0049c59a  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0049c59c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c5a0  e87f8b0000             -call 0x4a5124
    cpu.esp -= 4;
    sub_4a5124(app, cpu);
    if (cpu.terminate) return;
    // 0049c5a5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c5a6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c5a8  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c5ac  e8b7b0feff             -call 0x487668
    cpu.esp -= 4;
    sub_487668(app, cpu);
    if (cpu.terminate) return;
    // 0049c5b1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c5b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c5b6  7522                   -jne 0x49c5da
    if (!cpu.flags.zf)
    {
        goto L_0x0049c5da;
    }
    // 0049c5b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c5ba:
    // 0049c5ba  83c40c                 +add esp, 0xc
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
    // 0049c5bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c5c1:
    // 0049c5c1  e8ce87feff             -call 0x484d94
    cpu.esp -= 4;
    sub_484d94(app, cpu);
    if (cpu.terminate) return;
    // 0049c5c6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c5c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c5ca  e8b1e3feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0049c5cf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c5d1  e82683feff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0049c5d6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c5d8  ebe0                   -jmp 0x49c5ba
    goto L_0x0049c5ba;
L_0x0049c5da:
    // 0049c5da  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 0049c5df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c5e1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c5e4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c5e6  0590010000             -add eax, 0x190
    (cpu.eax) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0049c5eb  e8348b0000             -call 0x4a5124
    cpu.esp -= 4;
    sub_4a5124(app, cpu);
    if (cpu.terminate) return;
    // 0049c5f0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c5f2  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c5f5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c5f9  e85ab3feff             -call 0x487958
    cpu.esp -= 4;
    sub_487958(app, cpu);
    if (cpu.terminate) return;
    // 0049c5fe  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c601  a3ecab4d00             -mov dword ptr [0x4dabec], eax
    app->getMemory<x86::reg32>(x86::reg32(5090284) /* 0x4dabec */) = cpu.eax;
    // 0049c606  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c60a  e841b3feff             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 0049c60f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c611  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c614  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c615  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c616  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c617  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c618(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c618);
    // 0049c618  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c619  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049c61e  e85dffffff             -call 0x49c580
    cpu.esp -= 4;
    sub_49c580(app, cpu);
    if (cpu.terminate) return;
    // 0049c623  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c624  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c628(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c628);
    // 0049c628  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c629  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c62b  e850ffffff             -call 0x49c580
    cpu.esp -= 4;
    sub_49c580(app, cpu);
    if (cpu.terminate) return;
    // 0049c630  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c631  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c632(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c632);
    // 0049c632  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c633  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c634  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c635  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c638  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c639  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c63a  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049c63c  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049c63f  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c645  f6410c01               +test byte ptr [ecx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 0049c649  7523                   -jne 0x49c66e
    if (!cpu.flags.zf)
    {
        goto L_0x0049c66e;
    }
    // 0049c64b  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049c650  e85ba00000             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 0049c655  8a710c                 -mov dh, byte ptr [ecx + 0xc]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049c658  80ce20                 -or dh, 0x20
    cpu.dh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049c65b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049c65e  88710c                 -mov byte ptr [ecx + 0xc], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dh;
    // 0049c661  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c667  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049c669  e9c2010000             -jmp 0x49c830
    goto L_0x0049c830;
L_0x0049c66e:
    // 0049c66e  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049c671  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c673  7510                   -jne 0x49c685
    if (!cpu.flags.zf)
    {
        goto L_0x0049c685;
    }
    // 0049c675  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049c678  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c67e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c680  e9ab010000             -jmp 0x49c830
    goto L_0x0049c830;
L_0x0049c685:
    // 0049c685  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049c688  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0049c68c  7507                   -jne 0x49c695
    if (!cpu.flags.zf)
    {
        goto L_0x0049c695;
    }
    // 0049c68e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049c690  e8763b0100             -call 0x4b020b
    cpu.esp -= 4;
    sub_4b020b(app, cpu);
    if (cpu.terminate) return;
L_0x0049c695:
    // 0049c695  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049c697  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0049c69a  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049c69e  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 0049c6a1  0f8401010000           -je 0x49c7a8
    if (cpu.flags.zf)
    {
        goto L_0x0049c7a8;
    }
    // 0049c6a7  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x0049c6ab:
    // 0049c6ab  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049c6ae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c6b0  7454                   -je 0x49c706
    if (cpu.flags.zf)
    {
        goto L_0x0049c706;
    }
    // 0049c6b2  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c6b6  39da                   +cmp edx, ebx
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
    // 0049c6b8  7602                   -jbe 0x49c6bc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c6bc;
    }
    // 0049c6ba  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0049c6bc:
    // 0049c6bc  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c6c0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049c6c2  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049c6c5  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c6c9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049c6ca  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049c6cc  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049c6ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c6cf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c6d1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049c6d4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c6d6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049c6d8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049c6db  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049c6dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6de  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c6df  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c6e3  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049c6e6  8d3417                 -lea esi, [edi + edx]
    cpu.esi = x86::reg32(cpu.edi + cpu.edx * 1);
    // 0049c6e9  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c6eb  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0049c6ef  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049c6f3  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049c6f6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c6f8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c6fa  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c6fc  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0049c6ff  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049c703  897d04                 -mov dword ptr [ebp + 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edi;
L_0x0049c706:
    // 0049c706  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c70a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049c70c  0f840a010000           -je 0x49c81c
    if (cpu.flags.zf)
    {
        goto L_0x0049c81c;
    }
    // 0049c712  3b4d14                 +cmp ecx, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c715  730a                   -jae 0x49c721
    if (!cpu.flags.cf)
    {
        goto L_0x0049c721;
    }
    // 0049c717  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0049c71b  0f8473000000           -je 0x49c794
    if (cpu.flags.zf)
    {
        goto L_0x0049c794;
    }
L_0x0049c721:
    // 0049c721  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0049c724  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049c727  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049c72e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c732  8a4d0d                 -mov cl, byte ptr [ebp + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 0049c735  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0049c738  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0049c73b  750d                   -jne 0x49c74a
    if (!cpu.flags.zf)
    {
        goto L_0x0049c74a;
    }
    // 0049c73d  81fb00020000           +cmp ebx, 0x200
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c743  7605                   -jbe 0x49c74a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c74a;
    }
    // 0049c745  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0049c747  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x0049c74a:
    // 0049c74a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c74e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049c751  e83c3b0100             -call 0x4b0292
    cpu.esp -= 4;
    sub_4b0292(app, cpu);
    if (cpu.terminate) return;
    // 0049c756  83f8ff                 +cmp eax, -1
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
    // 0049c759  7509                   -jne 0x49c764
    if (!cpu.flags.zf)
    {
        goto L_0x0049c764;
    }
    // 0049c75b  804d0c20               +or byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049c75f  e9b8000000             -jmp 0x49c81c
    goto L_0x0049c81c;
L_0x0049c764:
    // 0049c764  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c766  7509                   -jne 0x49c771
    if (!cpu.flags.zf)
    {
        goto L_0x0049c771;
    }
L_0x0049c768:
    // 0049c768  804d0c10               +or byte ptr [ebp + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0049c76c  e9ab000000             -jmp 0x49c81c
    goto L_0x0049c81c;
L_0x0049c771:
    // 0049c771  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c775  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c779  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c77d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c77f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c781  01c1                   +add ecx, eax
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
    // 0049c783  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049c787  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049c78b  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049c78f  e917ffffff             -jmp 0x49c6ab
    goto L_0x0049c6ab;
L_0x0049c794:
    // 0049c794  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049c796  e818d90000             -call 0x4aa0b3
    cpu.esp -= 4;
    sub_4aa0b3(app, cpu);
    if (cpu.terminate) return;
    // 0049c79b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c79d  0f8479000000           -je 0x49c81c
    if (cpu.flags.zf)
    {
        goto L_0x0049c81c;
    }
    // 0049c7a3  e903ffffff             -jmp 0x49c6ab
    goto L_0x0049c6ab;
L_0x0049c7a8:
    // 0049c7a8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c7ac  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0049c7ae:
    // 0049c7ae  837d0400               +cmp dword ptr [ebp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c7b2  750b                   -jne 0x49c7bf
    if (!cpu.flags.zf)
    {
        goto L_0x0049c7bf;
    }
    // 0049c7b4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049c7b6  e8f8d80000             -call 0x4aa0b3
    cpu.esp -= 4;
    sub_4aa0b3(app, cpu);
    if (cpu.terminate) return;
    // 0049c7bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c7bd  745d                   -je 0x49c81c
    if (cpu.flags.zf)
    {
        goto L_0x0049c81c;
    }
L_0x0049c7bf:
    // 0049c7bf  8b4d04                 -mov ecx, dword ptr [ebp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049c7c2  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049c7c5  49                     -dec ecx
    (cpu.ecx)--;
    // 0049c7c6  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049c7c9  894d04                 -mov dword ptr [ebp + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049c7cc  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 0049c7cf  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0049c7d1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c7d6  83f80d                 +cmp eax, 0xd
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
    // 0049c7d9  7528                   -jne 0x49c803
    if (!cpu.flags.zf)
    {
        goto L_0x0049c803;
    }
    // 0049c7db  837d0400               +cmp dword ptr [ebp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c7df  750b                   -jne 0x49c7ec
    if (!cpu.flags.zf)
    {
        goto L_0x0049c7ec;
    }
    // 0049c7e1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049c7e3  e8cbd80000             -call 0x4aa0b3
    cpu.esp -= 4;
    sub_4aa0b3(app, cpu);
    if (cpu.terminate) return;
    // 0049c7e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c7ea  7430                   -je 0x49c81c
    if (cpu.flags.zf)
    {
        goto L_0x0049c81c;
    }
L_0x0049c7ec:
    // 0049c7ec  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049c7ef  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049c7f2  4f                     -dec edi
    (cpu.edi)--;
    // 0049c7f3  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049c7f6  897d04                 -mov dword ptr [ebp + 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049c7f9  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 0049c7fc  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0049c7fe  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x0049c803:
    // 0049c803  83f81a                 +cmp eax, 0x1a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c806  0f845cffffff           -je 0x49c768
    if (cpu.flags.zf)
    {
        goto L_0x0049c768;
    }
    // 0049c80c  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0049c80e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c812  40                     -inc eax
    (cpu.eax)++;
    // 0049c813  42                     -inc edx
    (cpu.edx)++;
    // 0049c814  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049c818  39da                   +cmp edx, ebx
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
    // 0049c81a  7592                   -jne 0x49c7ae
    if (!cpu.flags.zf)
    {
        goto L_0x0049c7ae;
    }
L_0x0049c81c:
    // 0049c81c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049c81f  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c822  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c828  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c82a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c82e  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x0049c830:
    // 0049c830  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c833  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c834  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c835  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c836  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c837(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c837);
    // 0049c837  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c838(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c838);
    // 0049c838  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c839  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c83a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c83c  ff1598d34d00           -call dword ptr [0x4dd398]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5100440) /* 0x4dd398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c842  803dac675b0000         +cmp byte ptr [0x5b67ac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5990316) /* 0x5b67ac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c849  750f                   -jne 0x49c85a
    if (!cpu.flags.zf)
    {
        goto L_0x0049c85a;
    }
    // 0049c84b  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0049c850  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0049c855  e8223b0100             -call 0x4b037c
    cpu.esp -= 4;
    sub_4b037c(app, cpu);
    if (cpu.terminate) return;
L_0x0049c85a:
    // 0049c85a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c85c  e803000000             -call 0x49c864
    cpu.esp -= 4;
    sub_49c864(app, cpu);
    if (cpu.terminate) return;
    // 0049c861  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c862  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c863  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c864(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c864);
    // 0049c864  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c865  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c867  ff1598d34d00           -call dword ptr [0x4dd398]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5100440) /* 0x4dd398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c86d  ff159cd34d00           -call dword ptr [0x4dd39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5100444) /* 0x4dd39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c873  833de4ed4d0000         +cmp dword ptr [0x4dede4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107172) /* 0x4dede4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c87a  7406                   -je 0x49c882
    if (cpu.flags.zf)
    {
        goto L_0x0049c882;
    }
    // 0049c87c  ff15e4ed4d00           -call dword ptr [0x4dede4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107172) /* 0x4dede4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049c882:
    // 0049c882  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c884  e9f4d60000             -jmp 0x4a9f7d
    return sub_4a9f7d(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c890);
    // 0049c890  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c891  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c892  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c893  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c896  8b35a8d34d00           -mov esi, dword ptr [0x4dd3a8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100456) /* 0x4dd3a8 */);
    // 0049c89c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c89e  833dacd34d0000         +cmp dword ptr [0x4dd3ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100460) /* 0x4dd3ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8a5  0f8466000000           -je 0x49c911
    if (cpu.flags.zf)
    {
        goto L_0x0049c911;
    }
L_0x0049c8ab:
    // 0049c8ab  8b3dacd34d00           -mov edi, dword ptr [0x4dd3ac]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5100460) /* 0x4dd3ac */);
    // 0049c8b1  8b35a8d34d00           -mov esi, dword ptr [0x4dd3a8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100456) /* 0x4dd3a8 */);
    // 0049c8b7  39fa                   +cmp edx, edi
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
    // 0049c8b9  7e02                   -jle 0x49c8bd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c8bd;
    }
    // 0049c8bb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0049c8bd:
    // 0049c8bd  39f2                   +cmp edx, esi
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
    // 0049c8bf  7c43                   -jl 0x49c904
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c904;
    }
    // 0049c8c1  8d1c31                 -lea ebx, [ecx + esi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 0049c8c4  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0049c8c7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c8c9  4b                     -dec ebx
    (cpu.ebx)--;
    // 0049c8ca  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 0049c8cc  21fb                   -and ebx, edi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.edi));
    // 0049c8ce  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c8d0  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8d2  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049c8d4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c8d6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c8d8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c8db  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c8dd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049c8df  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049c8e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c8e4  7e1e                   -jle 0x49c904
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c904;
    }
L_0x0049c8e6:
    // 0049c8e6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c8e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c8ea  39cb                   +cmp ebx, ecx
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
    // 0049c8ec  720c                   -jb 0x49c8fa
    if (cpu.flags.cf)
    {
        goto L_0x0049c8fa;
    }
L_0x0049c8ee:
    // 0049c8ee  40                     -inc eax
    (cpu.eax)++;
    // 0049c8ef  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049c8f1  83f820                 +cmp eax, 0x20
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
    // 0049c8f4  7d04                   -jge 0x49c8fa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c8fa;
    }
    // 0049c8f6  39ca                   +cmp edx, ecx
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
    // 0049c8f8  73f4                   -jae 0x49c8ee
    if (!cpu.flags.cf)
    {
        goto L_0x0049c8ee;
    }
L_0x0049c8fa:
    // 0049c8fa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c8fd  47                     -inc edi
    (cpu.edi)++;
    // 0049c8fe  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049c900  39c7                   +cmp edi, eax
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
    // 0049c902  7ce2                   -jl 0x49c8e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c8e6;
    }
L_0x0049c904:
    // 0049c904  8935a8d34d00           -mov dword ptr [0x4dd3a8], esi
    app->getMemory<x86::reg32>(x86::reg32(5100456) /* 0x4dd3a8 */) = cpu.esi;
    // 0049c90a  83c404                 +add esp, 4
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
    // 0049c90d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c90e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c90f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c910  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c911:
    // 0049c911  e8be7e0000             -call 0x4a47d4
    cpu.esp -= 4;
    sub_4a47d4(app, cpu);
    if (cpu.terminate) return;
    // 0049c916  a3acd34d00             -mov dword ptr [0x4dd3ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5100460) /* 0x4dd3ac */) = cpu.eax;
    // 0049c91b  eb8e                   -jmp 0x49c8ab
    goto L_0x0049c8ab;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c920);
    // 0049c920  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c921  8b15f8b14d00           -mov edx, dword ptr [0x4db1f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */);
    // 0049c927  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c929  7502                   -jne 0x49c92d
    if (!cpu.flags.zf)
    {
        goto L_0x0049c92d;
    }
    // 0049c92b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c92c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c92d:
    // 0049c92d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c92e  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 0049c933  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049c935  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c936  2eff15c8654c00         -call dword ptr cs:[0x4c65c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006792) /* 0x4c65c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c93d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c93f  890df8b14d00           -mov dword ptr [0x4db1f8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */) = cpu.ecx;
    // 0049c945  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c946  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c947  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c948(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c948);
    // 0049c948  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c949  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c94a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c94b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c94c  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0049c94f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c951  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049c953  e848770000             -call 0x4a40a0
    cpu.esp -= 4;
    sub_4a40a0(app, cpu);
    if (cpu.terminate) return;
    // 0049c958  a3003f5600             -mov dword ptr [0x563f00], eax
    app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */) = cpu.eax;
    // 0049c95d  e85e770000             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c962  833da8d34d0000         +cmp dword ptr [0x4dd3a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100456) /* 0x4dd3a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c969  0f84db000000           -je 0x49ca4a
    if (cpu.flags.zf)
    {
        goto L_0x0049ca4a;
    }
L_0x0049c96f:
    // 0049c96f  e83c7e0000             -call 0x4a47b0
    cpu.esp -= 4;
    sub_4a47b0(app, cpu);
    if (cpu.terminate) return;
    // 0049c974  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c976  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0049c978  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049c97c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c97e  0f85de000000           -jne 0x49ca62
    if (!cpu.flags.zf)
    {
        goto L_0x0049ca62;
    }
L_0x0049c984:
    // 0049c984  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c986  891df8b14d00           -mov dword ptr [0x4db1f8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */) = cpu.ebx;
    // 0049c98c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049c98e:
    // 0049c98e  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c992  e83d010000             -call 0x49cad4
    cpu.esp -= 4;
    sub_49cad4(app, cpu);
    if (cpu.terminate) return;
    // 0049c997  a3f8b14d00             -mov dword ptr [0x4db1f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */) = cpu.eax;
    // 0049c99c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c99e  751a                   -jne 0x49c9ba
    if (!cpu.flags.zf)
    {
        goto L_0x0049c9ba;
    }
    // 0049c9a0  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c9a4  81fe00000800           +cmp esi, 0x80000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9aa  0f8c92000000           -jl 0x49ca42
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ca42;
    }
    // 0049c9b0  8dae0000f8ff           -lea ebp, [esi - 0x80000]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(-524288) /* -0x80000 */);
    // 0049c9b6  896c2424               -mov dword ptr [esp + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebp;
L_0x0049c9ba:
    // 0049c9ba  a1f8b14d00             -mov eax, dword ptr [0x4db1f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */);
    // 0049c9bf  39c1                   +cmp ecx, eax
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
    // 0049c9c1  74cb                   -je 0x49c98e
    if (cpu.flags.zf)
    {
        goto L_0x0049c98e;
    }
    // 0049c9c3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c9c5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c9c9  8d2cbd00000000         -lea ebp, [edi*4]
    cpu.ebp = x86::reg32(cpu.edi * 4);
    // 0049c9d0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049c9d2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049c9d4  a3f4b14d00             -mov dword ptr [0x4db1f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5091828) /* 0x4db1f4 */) = cpu.eax;
    // 0049c9d9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c9db  e86083feff             -call 0x484d40
    cpu.esp -= 4;
    sub_484d40(app, cpu);
    if (cpu.terminate) return;
    // 0049c9e0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049c9e2  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049c9e4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049c9e6  c1e503                 -shl ebp, 3
    cpu.ebp <<= 3 /*0x3*/ % 32;
    // 0049c9e9  b84c0e4d00             -mov eax, 0x4d0e4c
    cpu.eax = 5049932 /*0x4d0e4c*/;
    // 0049c9ee  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0049c9f0  8b0df4b14d00           -mov ecx, dword ptr [0x4db1f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091828) /* 0x4db1f4 */);
    // 0049c9f6  8b1df8b14d00           -mov ebx, dword ptr [0x4db1f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */);
    // 0049c9fc  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0049c9fe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ca00  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ca02  e88579feff             -call 0x48438c
    cpu.esp -= 4;
    sub_48438c(app, cpu);
    if (cpu.terminate) return;
    // 0049ca07  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049ca09  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049ca0b  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0049ca10  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0049ca15  b8540e4d00             -mov eax, 0x4d0e54
    cpu.eax = 5049940 /*0x4d0e54*/;
    // 0049ca1a  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0049ca1f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ca21  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ca23  e86479feff             -call 0x48438c
    cpu.esp -= 4;
    sub_48438c(app, cpu);
    if (cpu.terminate) return;
    // 0049ca28  8b0df4b14d00           -mov ecx, dword ptr [0x4db1f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091828) /* 0x4db1f4 */);
    // 0049ca2e  8b15f8b14d00           -mov edx, dword ptr [0x4db1f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */);
    // 0049ca34  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 0049ca39  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ca3b  e888760000             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 0049ca40  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049ca42:
    // 0049ca42  83c428                 +add esp, 0x28
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049ca45  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca46  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ca4a:
    // 0049ca4a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049ca4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ca4d  2eff151c654c00         -call dword ptr cs:[0x4c651c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006620) /* 0x4c651c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ca54  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ca58  a3a8d34d00             -mov dword ptr [0x4dd3a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5100456) /* 0x4dd3a8 */) = cpu.eax;
    // 0049ca5d  e90dffffff             -jmp 0x49c96f
    goto L_0x0049c96f;
L_0x0049ca62:
    // 0049ca62  39c6                   +cmp esi, eax
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
    // 0049ca64  0f8d1affffff           -jge 0x49c984
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c984;
    }
    // 0049ca6a  6683e6f0               +and si, 0xfff0
    cpu.clear_co();
    cpu.set_szp((cpu.si &= x86::reg16(x86::sreg16(65520 /*0xfff0*/))));
    // 0049ca6e  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0049ca72  e90dffffff             -jmp 0x49c984
    goto L_0x0049c984;
}

/* align: skip 0x90 */
void Application::sub_49ca78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ca78);
    // 0049ca78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ca79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ca7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ca7b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ca7c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ca7e  e8997d0000             -call 0x4a481c
    cpu.esp -= 4;
    sub_4a481c(app, cpu);
    if (cpu.terminate) return;
    // 0049ca83  8b1da0d34d00           -mov ebx, dword ptr [0x4dd3a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5100448) /* 0x4dd3a0 */);
    // 0049ca89  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ca8b  39d8                   +cmp eax, ebx
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
    // 0049ca8d  771a                   -ja 0x49caa9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049caa9;
    }
    // 0049ca8f  8b35a4d34d00           -mov esi, dword ptr [0x4dd3a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100452) /* 0x4dd3a4 */);
    // 0049ca95  39f0                   +cmp eax, esi
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
    // 0049ca97  7302                   -jae 0x49ca9b
    if (!cpu.flags.cf)
    {
        goto L_0x0049ca9b;
    }
    // 0049ca99  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0049ca9b:
    // 0049ca9b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ca9d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ca9f  e8a4feffff             -call 0x49c948
    cpu.esp -= 4;
    sub_49c948(app, cpu);
    if (cpu.terminate) return;
    // 0049caa4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caa5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caa6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caa7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caa8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049caa9:
    // 0049caa9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049caab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049caad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049caaf  e894feffff             -call 0x49c948
    cpu.esp -= 4;
    sub_49c948(app, cpu);
    if (cpu.terminate) return;
    // 0049cab4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cab5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cab6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cab7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cab8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49cabc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cabc);
    // 0049cabc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049cabd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cabf  e884feffff             -call 0x49c948
    cpu.esp -= 4;
    sub_49c948(app, cpu);
    if (cpu.terminate) return;
    // 0049cac4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cac5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49cac8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cac8);
    // 0049cac8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049cac9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049cacb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cacd  e876feffff             -call 0x49c948
    cpu.esp -= 4;
    sub_49c948(app, cpu);
    if (cpu.terminate) return;
    // 0049cad2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cad3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49cad4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cad4);
    // 0049cad4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049cad5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cad6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cad7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cad8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cad9  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049cadc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049cade  8b15a8d34d00           -mov edx, dword ptr [0x4dd3a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100456) /* 0x4dd3a8 */);
    // 0049cae4  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049cae6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049cae8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049caea  7435                   -je 0x49cb21
    if (cpu.flags.zf)
    {
        goto L_0x0049cb21;
    }
L_0x0049caec:
    // 0049caec  8b0da8d34d00           -mov ecx, dword ptr [0x4dd3a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100456) /* 0x4dd3a8 */);
    // 0049caf2  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049caf4  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049caf6  4a                     -dec edx
    (cpu.edx)--;
    // 0049caf7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049caf9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049cafc  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049cafe  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049cb01  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0049cb03  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 0049cb08  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049cb0a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049cb0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cb0d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049cb0f  2eff15c4654c00         -call dword ptr cs:[0x4c65c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006788) /* 0x4c65c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cb16  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049cb18  83c424                 +add esp, 0x24
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049cb1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049cb21:
    // 0049cb21  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049cb23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cb24  2eff151c654c00         -call dword ptr cs:[0x4c651c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006620) /* 0x4c651c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cb2b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cb2f  a3a8d34d00             -mov dword ptr [0x4dd3a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5100456) /* 0x4dd3a8 */) = cpu.eax;
    // 0049cb34  ebb6                   -jmp 0x49caec
    goto L_0x0049caec;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49cb38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb38);
    // 0049cb38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cb39  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cb3a  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 0049cb3f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049cb41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cb42  2eff15c8654c00         -call dword ptr cs:[0x4c65c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006792) /* 0x4c65c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cb49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49cb4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb4c);
    // 0049cb4c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cb4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cb4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cb4f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cb50  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049cb53  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049cb55  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049cb57  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049cb5b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0049cb60  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049cb65  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049cb69  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049cb6c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049cb6e  7419                   -je 0x49cb89
    if (cpu.flags.zf)
    {
        goto L_0x0049cb89;
    }
    // 0049cb70  803e00                 +cmp byte ptr [esi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cb73  7514                   -jne 0x49cb89
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb89;
    }
    // 0049cb75  837c240c00             +cmp dword ptr [esp + 0xc], 0
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
    // 0049cb7a  750b                   -jne 0x49cb87
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb87;
    }
    // 0049cb7c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cb7e  e84a380100             -call 0x4b03cd
    cpu.esp -= 4;
    sub_4b03cd(app, cpu);
    if (cpu.terminate) return;
    // 0049cb83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cb85  7502                   -jne 0x49cb89
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb89;
    }
L_0x0049cb87:
    // 0049cb87  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049cb89:
    // 0049cb89  837c240c00             +cmp dword ptr [esp + 0xc], 0
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
    // 0049cb8e  750b                   -jne 0x49cb9b
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb9b;
    }
    // 0049cb90  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cb92  e836380100             -call 0x4b03cd
    cpu.esp -= 4;
    sub_4b03cd(app, cpu);
    if (cpu.terminate) return;
    // 0049cb97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cb99  7511                   -jne 0x49cbac
    if (!cpu.flags.zf)
    {
        goto L_0x0049cbac;
    }
L_0x0049cb9b:
    // 0049cb9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cb9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cb9d  2eff1580654c00         -call dword ptr cs:[0x4c6580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006720) /* 0x4c6580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cba4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cba6  0f8499000000           -je 0x49cc45
    if (cpu.flags.zf)
    {
        goto L_0x0049cc45;
    }
L_0x0049cbac:
    // 0049cbac  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cbb0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049cbb2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cbb4  e8d8000000             -call 0x49cc91
    cpu.esp -= 4;
    sub_49cc91(app, cpu);
    if (cpu.terminate) return;
    // 0049cbb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cbbb  0f8584000000           -jne 0x49cc45
    if (!cpu.flags.zf)
    {
        goto L_0x0049cc45;
    }
    // 0049cbc1  a138945b00             -mov eax, dword ptr [0x5b9438]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 0049cbc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cbc8  0f84bb000000           -je 0x49cc89
    if (cpu.flags.zf)
    {
        goto L_0x0049cc89;
    }
    // 0049cbce  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cbd0  e852380100             -call 0x4b0427
    cpu.esp -= 4;
    sub_4b0427(app, cpu);
    if (cpu.terminate) return;
    // 0049cbd5  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049cbd8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cbdc  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049cbdf  e8df990000             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 0049cbe4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049cbe6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049cbe8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cbea  750c                   -jne 0x49cbf8
    if (!cpu.flags.zf)
    {
        goto L_0x0049cbf8;
    }
L_0x0049cbec:
    // 0049cbec  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0049cbf1  e86b990000             -call 0x4a6561
    cpu.esp -= 4;
    sub_4a6561(app, cpu);
    if (cpu.terminate) return;
    // 0049cbf6  eb4d                   -jmp 0x49cc45
    goto L_0x0049cc45;
L_0x0049cbf8:
    // 0049cbf8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049cbfa  7427                   -je 0x49cc23
    if (cpu.flags.zf)
    {
        goto L_0x0049cc23;
    }
    // 0049cbfc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cbfe  e824380100             -call 0x4b0427
    cpu.esp -= 4;
    sub_4b0427(app, cpu);
    if (cpu.terminate) return;
    // 0049cc03  40                     -inc eax
    (cpu.eax)++;
    // 0049cc04  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cc08  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049cc0c  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049cc0f  e8af990000             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 0049cc14  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049cc16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cc18  750b                   -jne 0x49cc25
    if (!cpu.flags.zf)
    {
        goto L_0x0049cc25;
    }
    // 0049cc1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cc1c  e8d7e80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 0049cc21  ebc9                   -jmp 0x49cbec
    goto L_0x0049cbec;
L_0x0049cc23:
    // 0049cc23  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049cc25:
    // 0049cc25  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0049cc29  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049cc2b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc2d  e817380100             -call 0x4b0449
    cpu.esp -= 4;
    sub_4b0449(app, cpu);
    if (cpu.terminate) return;
    // 0049cc32  83f8ff                 +cmp eax, -1
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
    // 0049cc35  7515                   -jne 0x49cc4c
    if (!cpu.flags.zf)
    {
        goto L_0x0049cc4c;
    }
L_0x0049cc37:
    // 0049cc37  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc39  e8bae80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 0049cc3e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cc40  e8b3e80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x0049cc45:
    // 0049cc45  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049cc4a  eb3d                   -jmp 0x49cc89
    goto L_0x0049cc89;
L_0x0049cc4c:
    // 0049cc4c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049cc4e  7416                   -je 0x49cc66
    if (cpu.flags.zf)
    {
        goto L_0x0049cc66;
    }
    // 0049cc50  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cc54  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0049cc58  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cc5a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049cc5c  e8e8370100             -call 0x4b0449
    cpu.esp -= 4;
    sub_4b0449(app, cpu);
    if (cpu.terminate) return;
    // 0049cc61  83f8ff                 +cmp eax, -1
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
    // 0049cc64  74d1                   -je 0x49cc37
    if (cpu.flags.zf)
    {
        goto L_0x0049cc37;
    }
L_0x0049cc66:
    // 0049cc66  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cc6a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049cc6c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc6e  e886390100             -call 0x4b05f9
    cpu.esp -= 4;
    sub_4b05f9(app, cpu);
    if (cpu.terminate) return;
    // 0049cc73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049cc75  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc77  e87ce80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 0049cc7c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049cc7e  7407                   -je 0x49cc87
    if (cpu.flags.zf)
    {
        goto L_0x0049cc87;
    }
    // 0049cc80  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cc82  e871e80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x0049cc87:
    // 0049cc87  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0049cc89:
    // 0049cc89  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049cc8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49cc89(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cc89);
    goto L_entry_0x0049cc89;
    // 0049cb4c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cb4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cb4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cb4f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cb50  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049cb53  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049cb55  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049cb57  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049cb5b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0049cb60  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049cb65  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049cb69  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049cb6c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049cb6e  7419                   -je 0x49cb89
    if (cpu.flags.zf)
    {
        goto L_0x0049cb89;
    }
    // 0049cb70  803e00                 +cmp byte ptr [esi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cb73  7514                   -jne 0x49cb89
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb89;
    }
    // 0049cb75  837c240c00             +cmp dword ptr [esp + 0xc], 0
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
    // 0049cb7a  750b                   -jne 0x49cb87
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb87;
    }
    // 0049cb7c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cb7e  e84a380100             -call 0x4b03cd
    cpu.esp -= 4;
    sub_4b03cd(app, cpu);
    if (cpu.terminate) return;
    // 0049cb83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cb85  7502                   -jne 0x49cb89
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb89;
    }
L_0x0049cb87:
    // 0049cb87  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049cb89:
    // 0049cb89  837c240c00             +cmp dword ptr [esp + 0xc], 0
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
    // 0049cb8e  750b                   -jne 0x49cb9b
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb9b;
    }
    // 0049cb90  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cb92  e836380100             -call 0x4b03cd
    cpu.esp -= 4;
    sub_4b03cd(app, cpu);
    if (cpu.terminate) return;
    // 0049cb97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cb99  7511                   -jne 0x49cbac
    if (!cpu.flags.zf)
    {
        goto L_0x0049cbac;
    }
L_0x0049cb9b:
    // 0049cb9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cb9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cb9d  2eff1580654c00         -call dword ptr cs:[0x4c6580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006720) /* 0x4c6580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cba4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cba6  0f8499000000           -je 0x49cc45
    if (cpu.flags.zf)
    {
        goto L_0x0049cc45;
    }
L_0x0049cbac:
    // 0049cbac  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cbb0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049cbb2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cbb4  e8d8000000             -call 0x49cc91
    cpu.esp -= 4;
    sub_49cc91(app, cpu);
    if (cpu.terminate) return;
    // 0049cbb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cbbb  0f8584000000           -jne 0x49cc45
    if (!cpu.flags.zf)
    {
        goto L_0x0049cc45;
    }
    // 0049cbc1  a138945b00             -mov eax, dword ptr [0x5b9438]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 0049cbc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cbc8  0f84bb000000           -je 0x49cc89
    if (cpu.flags.zf)
    {
        goto L_0x0049cc89;
    }
    // 0049cbce  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cbd0  e852380100             -call 0x4b0427
    cpu.esp -= 4;
    sub_4b0427(app, cpu);
    if (cpu.terminate) return;
    // 0049cbd5  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049cbd8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cbdc  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049cbdf  e8df990000             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 0049cbe4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049cbe6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049cbe8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cbea  750c                   -jne 0x49cbf8
    if (!cpu.flags.zf)
    {
        goto L_0x0049cbf8;
    }
L_0x0049cbec:
    // 0049cbec  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0049cbf1  e86b990000             -call 0x4a6561
    cpu.esp -= 4;
    sub_4a6561(app, cpu);
    if (cpu.terminate) return;
    // 0049cbf6  eb4d                   -jmp 0x49cc45
    goto L_0x0049cc45;
L_0x0049cbf8:
    // 0049cbf8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049cbfa  7427                   -je 0x49cc23
    if (cpu.flags.zf)
    {
        goto L_0x0049cc23;
    }
    // 0049cbfc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cbfe  e824380100             -call 0x4b0427
    cpu.esp -= 4;
    sub_4b0427(app, cpu);
    if (cpu.terminate) return;
    // 0049cc03  40                     -inc eax
    (cpu.eax)++;
    // 0049cc04  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cc08  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049cc0c  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049cc0f  e8af990000             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 0049cc14  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049cc16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cc18  750b                   -jne 0x49cc25
    if (!cpu.flags.zf)
    {
        goto L_0x0049cc25;
    }
    // 0049cc1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cc1c  e8d7e80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 0049cc21  ebc9                   -jmp 0x49cbec
    goto L_0x0049cbec;
L_0x0049cc23:
    // 0049cc23  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049cc25:
    // 0049cc25  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0049cc29  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049cc2b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc2d  e817380100             -call 0x4b0449
    cpu.esp -= 4;
    sub_4b0449(app, cpu);
    if (cpu.terminate) return;
    // 0049cc32  83f8ff                 +cmp eax, -1
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
    // 0049cc35  7515                   -jne 0x49cc4c
    if (!cpu.flags.zf)
    {
        goto L_0x0049cc4c;
    }
L_0x0049cc37:
    // 0049cc37  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc39  e8bae80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 0049cc3e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cc40  e8b3e80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x0049cc45:
    // 0049cc45  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049cc4a  eb3d                   -jmp 0x49cc89
    goto L_0x0049cc89;
L_0x0049cc4c:
    // 0049cc4c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049cc4e  7416                   -je 0x49cc66
    if (cpu.flags.zf)
    {
        goto L_0x0049cc66;
    }
    // 0049cc50  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cc54  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0049cc58  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cc5a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049cc5c  e8e8370100             -call 0x4b0449
    cpu.esp -= 4;
    sub_4b0449(app, cpu);
    if (cpu.terminate) return;
    // 0049cc61  83f8ff                 +cmp eax, -1
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
    // 0049cc64  74d1                   -je 0x49cc37
    if (cpu.flags.zf)
    {
        goto L_0x0049cc37;
    }
L_0x0049cc66:
    // 0049cc66  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cc6a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049cc6c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc6e  e886390100             -call 0x4b05f9
    cpu.esp -= 4;
    sub_4b05f9(app, cpu);
    if (cpu.terminate) return;
    // 0049cc73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049cc75  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc77  e87ce80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 0049cc7c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049cc7e  7407                   -je 0x49cc87
    if (cpu.flags.zf)
    {
        goto L_0x0049cc87;
    }
    // 0049cc80  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cc82  e871e80000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x0049cc87:
    // 0049cc87  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0049cc89:
L_entry_0x0049cc89:
    // 0049cc89  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049cc8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49cc91(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cc91);
    // 0049cc91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cc92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cc93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cc94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cc95  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049cc98  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cc99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cc9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cc9c  7507                   -jne 0x49cca5
    if (!cpu.flags.zf)
    {
        goto L_0x0049cca5;
    }
L_0x0049cc9e:
    // 0049cc9e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049cca3  ebe4                   -jmp 0x49cc89
    return sub_49cc89(app, cpu);
L_0x0049cca5:
    // 0049cca5  803800                 +cmp byte ptr [eax], 0
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
    // 0049cca8  74f4                   -je 0x49cc9e
    if (cpu.flags.zf)
    {
        goto L_0x0049cc9e;
    }
    // 0049ccaa  a134945b00             -mov eax, dword ptr [0x5b9434]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 0049ccaf  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049ccb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ccb5  7539                   -jne 0x49ccf0
    if (!cpu.flags.zf)
    {
        goto L_0x0049ccf0;
    }
    // 0049ccb7  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ccbb  74cc                   -je 0x49cc89
    if (cpu.flags.zf)
    {
        return sub_49cc89(app, cpu);
    }
    // 0049ccbd  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0049ccc2  e8fc980000             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 0049ccc7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049cccb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cccd  74cf                   -je 0x49cc9e
    if (cpu.flags.zf)
    {
        goto L_0x0049cc9e;
    }
    // 0049cccf  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0049ccd5  a334945b00             -mov dword ptr [0x5b9434], eax
    app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */) = cpu.eax;
    // 0049ccda  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049cce1  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049cce4  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0049cce6  a330945b00             -mov dword ptr [0x5b9430], eax
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.eax;
    // 0049cceb  e9e1000000             -jmp 0x49cdd1
    goto L_0x0049cdd1;
L_0x0049ccf0:
    // 0049ccf0  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ccf3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ccf7  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ccfa  e88f010000             -call 0x49ce8e
    cpu.esp -= 4;
    sub_49ce8e(app, cpu);
    if (cpu.terminate) return;
    // 0049ccff  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049cd01  0f8480010000           -je 0x49ce87
    if (cpu.flags.zf)
    {
        goto L_0x0049ce87;
    }
    // 0049cd07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cd09  0f8fb7000000           -jg 0x49cdc6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cdc6;
    }
    // 0049cd0f  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049cd11  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049cd13  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049cd15  8b3d30945b00           -mov edi, dword ptr [0x5b9430]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 0049cd1b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0049cd1e  40                     -inc eax
    (cpu.eax)++;
    // 0049cd1f  8d5908                 -lea ebx, [ecx + 8]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049cd22  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049cd26  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cd28  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cd2a  7548                   -jne 0x49cd74
    if (!cpu.flags.zf)
    {
        goto L_0x0049cd74;
    }
    // 0049cd2c  e892980000             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 0049cd31  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049cd33  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049cd37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cd39  0f845fffffff           -je 0x49cc9e
    if (cpu.flags.zf)
    {
        goto L_0x0049cc9e;
    }
    // 0049cd3f  8b3534945b00           -mov esi, dword ptr [0x5b9434]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 0049cd45  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049cd47  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049cd48  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049cd4a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049cd4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cd4d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cd4f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049cd52  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049cd54  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049cd56  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049cd59  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049cd5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cd5c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049cd5d  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cd5f  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cd63  891530945b00           -mov dword ptr [0x5b9430], edx
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.edx;
    // 0049cd69  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cd6b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049cd6d  e8bd58ffff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 0049cd72  eb2f                   -jmp 0x49cda3
    goto L_0x0049cda3;
L_0x0049cd74:
    // 0049cd74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049cd76  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cd7a  e86c3b0100             -call 0x4b08eb
    cpu.esp -= 4;
    sub_4b08eb(app, cpu);
    if (cpu.terminate) return;
    // 0049cd7f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049cd83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cd85  0f8413ffffff           -je 0x49cc9e
    if (cpu.flags.zf)
    {
        goto L_0x0049cc9e;
    }
    // 0049cd8b  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 0049cd91  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0049cd94  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049cd96  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cd98  e8c83b0100             -call 0x4b0965
    cpu.esp -= 4;
    sub_4b0965(app, cpu);
    if (cpu.terminate) return;
    // 0049cd9d  890d30945b00           -mov dword ptr [0x5b9430], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.ecx;
L_0x0049cda3:
    // 0049cda3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cda5  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cda9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049cdac  01d0                   +add eax, edx
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
    // 0049cdae  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049cdb5  a130945b00             -mov eax, dword ptr [0x5b9430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 0049cdba  891534945b00           -mov dword ptr [0x5b9434], edx
    app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */) = cpu.edx;
    // 0049cdc0  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
    // 0049cdc4  eb0b                   -jmp 0x49cdd1
    goto L_0x0049cdd1;
L_0x0049cdc6:
    // 0049cdc6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049cdc8  0f84b9000000           -je 0x49ce87
    if (cpu.flags.zf)
    {
        goto L_0x0049ce87;
    }
    // 0049cdce  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x0049cdd1:
    // 0049cdd1  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cdd5  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049cdd6  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049cdd8  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049cdda  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049cddc  49                     -dec ecx
    (cpu.ecx)--;
    // 0049cddd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049cddf  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049cde1  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049cde3  49                     -dec ecx
    (cpu.ecx)--;
    // 0049cde4  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049cde5  a130945b00             -mov eax, dword ptr [0x5b9430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 0049cdea  8a3428                 -mov dh, byte ptr [eax + ebp]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1);
    // 0049cded  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049cdef  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0049cdf1  740f                   -je 0x49ce02
    if (cpu.flags.zf)
    {
        goto L_0x0049ce02;
    }
    // 0049cdf3  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0049cdf5  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cdf9  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0049cdfc  01ce                   +add esi, ecx
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
    // 0049cdfe  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049ce00  eb02                   -jmp 0x49ce04
    goto L_0x0049ce04;
L_0x0049ce02:
    // 0049ce02  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049ce04:
    // 0049ce04  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ce07  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049ce08  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049ce0a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049ce0c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ce0e  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ce0f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ce11  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049ce13  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049ce15  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ce16  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049ce17  8d140b                 -lea edx, [ebx + ecx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ecx * 1);
    // 0049ce1a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ce1c  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ce1f  e8c73a0100             -call 0x4b08eb
    cpu.esp -= 4;
    sub_4b08eb(app, cpu);
    if (cpu.terminate) return;
    // 0049ce24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ce26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ce28  0f8470feffff           -je 0x49cc9e
    if (cpu.flags.zf)
    {
        goto L_0x0049cc9e;
    }
    // 0049ce2e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ce32  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049ce34  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049ce36  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049ce37  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049ce39  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049ce3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ce3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ce3e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049ce41  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ce43  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049ce45  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049ce48  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049ce4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ce4b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049ce4c  c6041a3d               -mov byte ptr [edx + ebx], 0x3d
    app->getMemory<x86::reg8>(cpu.edx + cpu.ebx * 1) = 61 /*0x3d*/;
    // 0049ce50  43                     -inc ebx
    (cpu.ebx)++;
    // 0049ce51  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ce54  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0049ce57  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049ce58:
    // 0049ce58  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049ce5a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049ce5c  3c00                   +cmp al, 0
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
    // 0049ce5e  7410                   -je 0x49ce70
    if (cpu.flags.zf)
    {
        goto L_0x0049ce70;
    }
    // 0049ce60  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049ce63  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ce66  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049ce69  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ce6c  3c00                   +cmp al, 0
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
    // 0049ce6e  75e8                   -jne 0x49ce58
    if (!cpu.flags.zf)
    {
        goto L_0x0049ce58;
    }
L_0x0049ce70:
    // 0049ce70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ce71  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ce73  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049ce77  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ce7a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049ce7c  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049ce7e  a130945b00             -mov eax, dword ptr [0x5b9430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 0049ce83  c6042801               -mov byte ptr [eax + ebp], 1
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 1 /*0x1*/;
L_0x0049ce87:
    // 0049ce87  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ce89  e9fbfdffff             -jmp 0x49cc89
    return sub_49cc89(app, cpu);
}

/* align: skip  */
void Application::sub_49ce8e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ce8e);
    // 0049ce8e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ce8f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ce90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ce91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ce92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ce93  83ec08                 +sub esp, 8
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
    // 0049ce96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ce97  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ce98  a134945b00             -mov eax, dword ptr [0x5b9434]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 0049ce9d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049cea1  e9d4000000             -jmp 0x49cf7a
    goto L_0x0049cf7a;
L_0x0049cea6:
    // 0049cea6  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0049ceaa:
    // 0049ceaa  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049ceae  80383d                 +cmp byte ptr [eax], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049ceb1  0f858c000000           -jne 0x49cf43
    if (!cpu.flags.zf)
    {
        goto L_0x0049cf43;
    }
    // 0049ceb7  807d0000               +cmp byte ptr [ebp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cebb  0f8582000000           -jne 0x49cf43
    if (!cpu.flags.zf)
    {
        goto L_0x0049cf43;
    }
    // 0049cec1  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cec5  2b3534945b00           -sub esi, dword ptr [0x5b9434]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */)));
    // 0049cecb  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049cece  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 0049ced1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049ced3  0f8565000000           -jne 0x49cf3e
    if (!cpu.flags.zf)
    {
        goto L_0x0049cf3e;
    }
    // 0049ced9  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cedd  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cee1  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 0049cee3  eb08                   -jmp 0x49ceed
    goto L_0x0049ceed;
L_0x0049cee5:
    // 0049cee5  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049cee8  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049ceea  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049ceed:
    // 0049ceed  833900                 +cmp dword ptr [ecx], 0
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
    // 0049cef0  75f3                   -jne 0x49cee5
    if (!cpu.flags.zf)
    {
        goto L_0x0049cee5;
    }
    // 0049cef2  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 0049cef8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049cefa  7447                   -je 0x49cf43
    if (cpu.flags.zf)
    {
        goto L_0x0049cf43;
    }
    // 0049cefc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cefe  803c0600               +cmp byte ptr [esi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cf02  7407                   -je 0x49cf0b
    if (cpu.flags.zf)
    {
        goto L_0x0049cf0b;
    }
    // 0049cf04  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cf06  e8ede50000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x0049cf0b:
    // 0049cf0b  8b1d34945b00           -mov ebx, dword ptr [0x5b9434]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 0049cf11  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049cf13  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cf15  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 0049cf1b  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 0049cf1e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cf20  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049cf22  e83e3a0100             -call 0x4b0965
    cpu.esp -= 4;
    sub_4b0965(app, cpu);
    if (cpu.terminate) return;
    // 0049cf27  890d30945b00           -mov dword ptr [0x5b9430], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.ecx;
    // 0049cf2d  01f1                   +add ecx, esi
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
    // 0049cf2f  eb07                   -jmp 0x49cf38
    goto L_0x0049cf38;
L_0x0049cf31:
    // 0049cf31  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049cf34  46                     -inc esi
    (cpu.esi)++;
    // 0049cf35  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 0049cf37  41                     -inc ecx
    (cpu.ecx)++;
L_0x0049cf38:
    // 0049cf38  39fe                   +cmp esi, edi
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
    // 0049cf3a  7d07                   -jge 0x49cf43
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049cf43;
    }
    // 0049cf3c  ebf3                   -jmp 0x49cf31
    goto L_0x0049cf31;
L_0x0049cf3e:
    // 0049cf3e  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049cf41  eb57                   -jmp 0x49cf9a
    goto L_0x0049cf9a;
L_0x0049cf43:
    // 0049cf43  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cf47  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cf49  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0049cf4b  e8d295feff             -call 0x486522
    cpu.esp -= 4;
    sub_486522(app, cpu);
    if (cpu.terminate) return;
    // 0049cf50  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049cf52  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cf54  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0049cf57  e8c695feff             -call 0x486522
    cpu.esp -= 4;
    sub_486522(app, cpu);
    if (cpu.terminate) return;
    // 0049cf5c  39c2                   +cmp edx, eax
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
    // 0049cf5e  7515                   -jne 0x49cf75
    if (!cpu.flags.zf)
    {
        goto L_0x0049cf75;
    }
    // 0049cf60  807d0000               +cmp byte ptr [ebp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cf64  740f                   -je 0x49cf75
    if (cpu.flags.zf)
    {
        goto L_0x0049cf75;
    }
    // 0049cf66  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cf6a  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049cf6b  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049cf6c  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049cf70  e935ffffff             -jmp 0x49ceaa
    goto L_0x0049ceaa;
L_0x0049cf75:
    // 0049cf75  8344240804             -add dword ptr [esp + 8], 4
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049cf7a:
    // 0049cf7a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cf7e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049cf80  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049cf84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cf86  0f851affffff           -jne 0x49cea6
    if (!cpu.flags.zf)
    {
        goto L_0x0049cea6;
    }
    // 0049cf8c  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cf90  a134945b00             -mov eax, dword ptr [0x5b9434]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 0049cf95  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cf97  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x0049cf9a:
    // 0049cf9a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049cf9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cfa0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cfa1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cfa2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49cfb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cfb0);
    // 0049cfb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049cfb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cfb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cfb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cfb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cfb5  ba608c4200             -mov edx, 0x428c60
    cpu.edx = 4361312 /*0x428c60*/;
    // 0049cfba  b9208e4200             -mov ecx, 0x428e20
    cpu.ecx = 4361760 /*0x428e20*/;
    // 0049cfbf  bb1cae4900             -mov ebx, 0x49ae1c
    cpu.ebx = 4828700 /*0x49ae1c*/;
    // 0049cfc4  be84ae4900             -mov esi, 0x49ae84
    cpu.esi = 4828804 /*0x49ae84*/;
    // 0049cfc9  bf90ae4900             -mov edi, 0x49ae90
    cpu.edi = 4828816 /*0x49ae90*/;
    // 0049cfce  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049cfd3  8915a0d74d00           -mov dword ptr [0x4dd7a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5101472) /* 0x4dd7a0 */) = cpu.edx;
    // 0049cfd9  890d9cd74d00           -mov dword ptr [0x4dd79c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5101468) /* 0x4dd79c */) = cpu.ecx;
    // 0049cfdf  891da4d74d00           -mov dword ptr [0x4dd7a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5101476) /* 0x4dd7a4 */) = cpu.ebx;
    // 0049cfe5  8935a8d74d00           -mov dword ptr [0x4dd7a8], esi
    app->getMemory<x86::reg32>(x86::reg32(5101480) /* 0x4dd7a8 */) = cpu.esi;
    // 0049cfeb  893dacd74d00           -mov dword ptr [0x4dd7ac], edi
    app->getMemory<x86::reg32>(x86::reg32(5101484) /* 0x4dd7ac */) = cpu.edi;
    // 0049cff1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cff2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cff3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cff4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cff5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cff6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49cff8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cff8);
    // 0049cff8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cff9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cffb  8915a0d74d00           -mov dword ptr [0x4dd7a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5101472) /* 0x4dd7a0 */) = cpu.edx;
    // 0049d001  89159cd74d00           -mov dword ptr [0x4dd79c], edx
    app->getMemory<x86::reg32>(x86::reg32(5101468) /* 0x4dd79c */) = cpu.edx;
    // 0049d007  8915a4d74d00           -mov dword ptr [0x4dd7a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5101476) /* 0x4dd7a4 */) = cpu.edx;
    // 0049d00d  8915a8d74d00           -mov dword ptr [0x4dd7a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5101480) /* 0x4dd7a8 */) = cpu.edx;
    // 0049d013  8915acd74d00           -mov dword ptr [0x4dd7ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5101484) /* 0x4dd7ac */) = cpu.edx;
    // 0049d019  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d01a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49d020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d020);
    // 0049d020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d021  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d022  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d024  e85fcafeff             -call 0x489a88
    cpu.esp -= 4;
    sub_489a88(app, cpu);
    if (cpu.terminate) return;
    // 0049d029  833df8b14d0000         +cmp dword ptr [0x4db1f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d030  742b                   -je 0x49d05d
    if (cpu.flags.zf)
    {
        goto L_0x0049d05d;
    }
L_0x0049d032:
    // 0049d032  833d5cab4d0000         +cmp dword ptr [0x4dab5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d039  7516                   -jne 0x49d051
    if (!cpu.flags.zf)
    {
        goto L_0x0049d051;
    }
    // 0049d03b  8b1d84ab4d00           -mov ebx, dword ptr [0x4dab84]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 0049d041  8b1580ab4d00           -mov edx, dword ptr [0x4dab80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 0049d047  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 0049d04c  e863f60000             -call 0x4ac6b4
    cpu.esp -= 4;
    sub_4ac6b4(app, cpu);
    if (cpu.terminate) return;
L_0x0049d051:
    // 0049d051  833d5cab4d0000         +cmp dword ptr [0x4dab5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d058  750f                   -jne 0x49d069
    if (!cpu.flags.zf)
    {
        goto L_0x0049d069;
    }
    // 0049d05a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d05b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d05c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d05d:
    // 0049d05d  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 0049d062  e811faffff             -call 0x49ca78
    cpu.esp -= 4;
    sub_49ca78(app, cpu);
    if (cpu.terminate) return;
    // 0049d067  ebc9                   -jmp 0x49d032
    goto L_0x0049d032;
L_0x0049d069:
    // 0049d069  bb7cf04d00             -mov ebx, 0x4df07c
    cpu.ebx = 5107836 /*0x4df07c*/;
    // 0049d06e  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049d073  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d075  e86e320000             -call 0x4a02e8
    cpu.esp -= 4;
    sub_4a02e8(app, cpu);
    if (cpu.terminate) return;
    // 0049d07a  a1ccab4d00             -mov eax, dword ptr [0x4dabcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0049d07f  e8946bfeff             -call 0x483c18
    cpu.esp -= 4;
    sub_483c18(app, cpu);
    if (cpu.terminate) return;
    // 0049d084  e847a9feff             -call 0x4879d0
    cpu.esp -= 4;
    sub_4879d0(app, cpu);
    if (cpu.terminate) return;
    // 0049d089  e866abfeff             -call 0x487bf4
    cpu.esp -= 4;
    sub_487bf4(app, cpu);
    if (cpu.terminate) return;
    // 0049d08e  e82d390100             -call 0x4b09c0
    cpu.esp -= 4;
    sub_4b09c0(app, cpu);
    if (cpu.terminate) return;
    // 0049d093  b880f34d00             -mov eax, 0x4df380
    cpu.eax = 5108608 /*0x4df380*/;
    // 0049d098  e8c39ffeff             -call 0x487060
    cpu.esp -= 4;
    sub_487060(app, cpu);
    if (cpu.terminate) return;
    // 0049d09d  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0049d0a2  e8c555feff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 0049d0a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d0a9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049d0ae  e8b955feff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 0049d0b3  e8a894feff             -call 0x486560
    cpu.esp -= 4;
    sub_486560(app, cpu);
    if (cpu.terminate) return;
    // 0049d0b8  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090144) /* 0x4dab60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d0bf  7505                   -jne 0x49d0c6
    if (!cpu.flags.zf)
    {
        goto L_0x0049d0c6;
    }
    // 0049d0c1  e8ba5ff8ff             -call 0x423080
    cpu.esp -= 4;
    sub_423080(app, cpu);
    if (cpu.terminate) return;
L_0x0049d0c6:
    // 0049d0c6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d0c7  e8243f0000             -call 0x4a0ff0
    cpu.esp -= 4;
    sub_4a0ff0(app, cpu);
    if (cpu.terminate) return;
    // 0049d0cc  e8179efeff             -call 0x486ee8
    cpu.esp -= 4;
    sub_486ee8(app, cpu);
    if (cpu.terminate) return;
    // 0049d0d1  e84a390100             -call 0x4b0a20
    cpu.esp -= 4;
    sub_4b0a20(app, cpu);
    if (cpu.terminate) return;
    // 0049d0d6  b880104a00             -mov eax, 0x4a1080
    cpu.eax = 4853888 /*0x4a1080*/;
    // 0049d0db  e8a03f0000             -call 0x4a1080
    cpu.esp -= 4;
    sub_4a1080(app, cpu);
    if (cpu.terminate) return;
    // 0049d0e0  b8446e4800             -mov eax, 0x486e44
    cpu.eax = 4746820 /*0x486e44*/;
    // 0049d0e5  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0049d0ea  e8659dfeff             -call 0x486e54
    cpu.esp -= 4;
    sub_486e54(app, cpu);
    if (cpu.terminate) return;
    // 0049d0ef  e87c390100             -call 0x4b0a70
    cpu.esp -= 4;
    sub_4b0a70(app, cpu);
    if (cpu.terminate) return;
    // 0049d0f4  e8d33a0100             -call 0x4b0bcc
    cpu.esp -= 4;
    sub_4b0bcc(app, cpu);
    if (cpu.terminate) return;
    // 0049d0f9  b81e000000             -mov eax, 0x1e
    cpu.eax = 30 /*0x1e*/;
    // 0049d0fe  8b0d80ab4d00           -mov ecx, dword ptr [0x4dab80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 0049d104  8b1d7cab4d00           -mov ebx, dword ptr [0x4dab7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 0049d10a  e8f5350000             -call 0x4a0704
    cpu.esp -= 4;
    sub_4a0704(app, cpu);
    if (cpu.terminate) return;
    // 0049d10f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d111  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d113  e888340000             -call 0x4a05a0
    cpu.esp -= 4;
    sub_4a05a0(app, cpu);
    if (cpu.terminate) return;
    // 0049d118  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d119  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d11a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d11b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_49d120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d120);
    // 0049d120  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d121  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d122  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d123  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049d125  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049d127  e8e4dbfbff             -call 0x45ad10
    cpu.esp -= 4;
    sub_45ad10(app, cpu);
    if (cpu.terminate) return;
    // 0049d12c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d12e  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d12f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049d131  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049d133  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049d135  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d136  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d138  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0049d13a  4b                     -dec ebx
    (cpu.ebx)--;
    // 0049d13b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d13d  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d13e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049d140  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049d142  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049d144  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d145  39d9                   +cmp ecx, ebx
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
    // 0049d147  7606                   -jbe 0x49d14f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d14f;
    }
    // 0049d149  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d14b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d14c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d14d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d14e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d14f:
    // 0049d14f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d150  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049d152  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0049d154  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d155  2bc9                   +sub ecx, ecx
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
    // 0049d157  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049d158  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0049d15a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049d15c  4f                     -dec edi
    (cpu.edi)--;
L_0x0049d15d:
    // 0049d15d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d15f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049d161  3c00                   +cmp al, 0
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
    // 0049d163  7410                   -je 0x49d175
    if (cpu.flags.zf)
    {
        goto L_0x0049d175;
    }
    // 0049d165  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049d168  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d16b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049d16e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d171  3c00                   +cmp al, 0
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
    // 0049d173  75e8                   -jne 0x49d15d
    if (!cpu.flags.zf)
    {
        goto L_0x0049d15d;
    }
L_0x0049d175:
    // 0049d175  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d176  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d17b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d17c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d17d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d17e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d17f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d180);
    // 0049d180  8078013a               +cmp byte ptr [eax + 1], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d184  7406                   -je 0x49d18c
    if (cpu.flags.zf)
    {
        goto L_0x0049d18c;
    }
    // 0049d186  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049d18b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d18c:
    // 0049d18c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d18d  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0049d18f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d194  8d509f                 -lea edx, [eax - 0x61]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-97) /* -0x61 */);
    // 0049d197  83fa1a                 +cmp edx, 0x1a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d19a  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049d19c  83e220                 -and edx, 0x20
    cpu.edx &= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049d19f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d1a1  83e841                 -sub eax, 0x41
    (cpu.eax) -= x86::reg32(x86::sreg32(65 /*0x41*/));
    // 0049d1a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d1a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d1a8);
    // 0049d1a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d1a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d1aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d1ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d1ac  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d1af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d1b1  be5c0e4d00             -mov esi, 0x4d0e5c
    cpu.esi = 5049948 /*0x4d0e5c*/;
    // 0049d1b6  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049d1b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049d1b9:
    // 0049d1b9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d1bb  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049d1bd  3c00                   +cmp al, 0
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
    // 0049d1bf  7410                   -je 0x49d1d1
    if (cpu.flags.zf)
    {
        goto L_0x0049d1d1;
    }
    // 0049d1c1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049d1c4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d1c7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049d1ca  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d1cd  3c00                   +cmp al, 0
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
    // 0049d1cf  75e8                   -jne 0x49d1b9
    if (!cpu.flags.zf)
    {
        goto L_0x0049d1b9;
    }
L_0x0049d1d1:
    // 0049d1d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1d2  001424                 -add byte ptr [esp], dl
    (app->getMemory<x86::reg8>(cpu.esp)) += x86::reg8(x86::sreg8(cpu.dl));
    // 0049d1d5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049d1d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d1d8  2eff15d8644c00         -call dword ptr cs:[0x4c64d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006552) /* 0x4c64d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d1df  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d1e2  750d                   -jne 0x49d1f1
    if (!cpu.flags.zf)
    {
        goto L_0x0049d1f1;
    }
    // 0049d1e4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d1e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d1ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d1f1:
    // 0049d1f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d1f3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d1f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d1fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49d1fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d1fc);
    // 0049d1fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d1fe  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049d200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d201(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d201);
    // 0049d201  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d202  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d203  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d204  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d205  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d206  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d209  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d20b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049d20d  803a00                 +cmp byte ptr [edx], 0
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
    // 0049d210  7507                   -jne 0x49d219
    if (!cpu.flags.zf)
    {
        goto L_0x0049d219;
    }
L_0x0049d212:
    // 0049d212  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d214  e99d000000             -jmp 0x49d2b6
    goto L_0x0049d2b6;
L_0x0049d219:
    // 0049d219  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 0049d21d  751c                   -jne 0x49d23b
    if (!cpu.flags.zf)
    {
        goto L_0x0049d23b;
    }
    // 0049d21f  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
L_0x0049d221:
    // 0049d221  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d223  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d225  7412                   -je 0x49d239
    if (cpu.flags.zf)
    {
        goto L_0x0049d239;
    }
    // 0049d227  3c00                   +cmp al, 0
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
    // 0049d229  740c                   -je 0x49d237
    if (cpu.flags.zf)
    {
        goto L_0x0049d237;
    }
    // 0049d22b  46                     -inc esi
    (cpu.esi)++;
    // 0049d22c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d22e  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d230  7407                   -je 0x49d239
    if (cpu.flags.zf)
    {
        goto L_0x0049d239;
    }
    // 0049d232  46                     -inc esi
    (cpu.esi)++;
    // 0049d233  3c00                   +cmp al, 0
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
    // 0049d235  75ea                   -jne 0x49d221
    if (!cpu.flags.zf)
    {
        goto L_0x0049d221;
    }
L_0x0049d237:
    // 0049d237  2bf6                   +sub esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0049d239:
    // 0049d239  ebd7                   -jmp 0x49d212
    goto L_0x0049d212;
L_0x0049d23b:
    // 0049d23b  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0049d240  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049d242  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0049d244  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049d245  e30b                   -jecxz 0x49d252
    if (cpu.ecx == 0)
    {
        goto L_0x0049d252;
    }
    // 0049d247  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0049d249  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 0049d24b  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0049d24d  7503                   -jne 0x49d252
    if (!cpu.flags.zf)
    {
        goto L_0x0049d252;
    }
    // 0049d24f  4f                     -dec edi
    (cpu.edi)--;
    // 0049d250  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x0049d254;
L_0x0049d252:
    // 0049d252  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0049d254:
    // 0049d254  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049d255  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0049d258  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049d25a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049d25b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049d25d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049d25f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d261  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d262  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049d264  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049d266  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049d268  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d269  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049d26a  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x0049d26c:
    // 0049d26c  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d26f  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049d271  39e9                   +cmp ecx, ebp
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
    // 0049d273  723f                   -jb 0x49d2b4
    if (cpu.flags.cf)
    {
        goto L_0x0049d2b4;
    }
    // 0049d275  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049d277  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049d279  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049d27a  e30b                   -jecxz 0x49d287
    if (cpu.ecx == 0)
    {
        goto L_0x0049d287;
    }
    // 0049d27c  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0049d27e  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 0049d280  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0049d282  7503                   -jne 0x49d287
    if (!cpu.flags.zf)
    {
        goto L_0x0049d287;
    }
    // 0049d284  4f                     -dec edi
    (cpu.edi)--;
    // 0049d285  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x0049d289;
L_0x0049d287:
    // 0049d287  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0049d289:
    // 0049d289  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049d28a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049d28c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d28e  7424                   -je 0x49d2b4
    if (cpu.flags.zf)
    {
        goto L_0x0049d2b4;
    }
    // 0049d290  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049d292  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049d294  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049d296  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049d297  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049d299  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049d29b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049d29d  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 0049d29f  7405                   -je 0x49d2a6
    if (cpu.flags.zf)
    {
        goto L_0x0049d2a6;
    }
    // 0049d2a1  19c0                   +sbb eax, eax
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
    // 0049d2a3  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0049d2a6:
    // 0049d2a6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049d2a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d2a9  7504                   -jne 0x49d2af
    if (!cpu.flags.zf)
    {
        goto L_0x0049d2af;
    }
    // 0049d2ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d2ad  eb07                   -jmp 0x49d2b6
    goto L_0x0049d2b6;
L_0x0049d2af:
    // 0049d2af  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d2b2  ebb8                   -jmp 0x49d26c
    goto L_0x0049d26c;
L_0x0049d2b4:
    // 0049d2b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049d2b6:
    // 0049d2b6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d2b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49d2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d2c0);
    // 0049d2c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d2c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d2c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d2c3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049d2c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d2c8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049d2ca  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049d2cc  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049d2d0  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049d2d2  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0049d2d5  83e13f                 -and ecx, 0x3f
    cpu.ecx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049d2d8  e843170000             -call 0x49ea20
    cpu.esp -= 4;
    sub_49ea20(app, cpu);
    if (cpu.terminate) return;
    // 0049d2dd  69c17e480600           -imul eax, ecx, 0x6487e
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 0049d2e3  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049d2e7  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 0049d2ea  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0049d2ed  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049d2f0  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d2f3  c1f915                 -sar ecx, 0x15
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (21 /*0x15*/ % 32));
    // 0049d2f6  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d2f8  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0049d2fa  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d2fd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d2ff  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0049d302  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049d305  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049d309  c1f915                 -sar ecx, 0x15
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (21 /*0x15*/ % 32));
    // 0049d30c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d30e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049d310  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049d313  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d314  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d315  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d316  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49d320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d320);
    // 0049d320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d322  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049d324  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d326  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d328  7505                   -jne 0x49d32f
    if (!cpu.flags.zf)
    {
        goto L_0x0049d32f;
    }
L_0x0049d32a:
    // 0049d32a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d32c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d32d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d32e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d32f:
    // 0049d32f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0049d334  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d336  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d338  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d33a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d341  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049d343  3dfbc00000             +cmp eax, 0xc0fb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49403 /*0xc0fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d348  750a                   -jne 0x49d354
    if (!cpu.flags.zf)
    {
        goto L_0x0049d354;
    }
    // 0049d34a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049d34f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d351  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d352  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d353  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d354:
    // 0049d354  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049d359  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d35b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d35d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d35f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d361  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d368  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049d36a  3d46474942             +cmp eax, 0x42494746
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1112098630 /*0x42494746*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d36f  75b9                   -jne 0x49d32a
    if (!cpu.flags.zf)
    {
        goto L_0x0049d32a;
    }
    // 0049d371  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0049d376  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d378  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d379  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d37a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49d37c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d37c);
    // 0049d37c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d37d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d37f  e89cffffff             -call 0x49d320
    cpu.esp -= 4;
    sub_49d320(app, cpu);
    if (cpu.terminate) return;
    // 0049d384  83f801                 +cmp eax, 1
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
    // 0049d387  7207                   -jb 0x49d390
    if (cpu.flags.cf)
    {
        goto L_0x0049d390;
    }
    // 0049d389  7609                   -jbe 0x49d394
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d394;
    }
    // 0049d38b  83f802                 +cmp eax, 2
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
    // 0049d38e  7420                   -je 0x49d3b0
    if (cpu.flags.zf)
    {
        goto L_0x0049d3b0;
    }
L_0x0049d390:
    // 0049d390  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d392  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d393  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d394:
    // 0049d394  8d4102                 -lea eax, [ecx + 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0049d397  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0049d39c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d39e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d3a0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d3a2  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d3a9  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049d3ab  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d3ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d3b0:
    // 0049d3b0  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049d3b3  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049d3b8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d3ba  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d3bc  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d3be  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d3c5  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049d3c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d3cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d3cc);
    // 0049d3cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d3cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d3ce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d3cf  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d3d2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d3d4  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049d3d6  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049d3da  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049d3dd  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049d3e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d3e3  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049d3e7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049d3e9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049d3eb  e88cffffff             -call 0x49d37c
    cpu.esp -= 4;
    sub_49d37c(app, cpu);
    if (cpu.terminate) return;
    // 0049d3f0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049d3f2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3f4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049d3f6  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049d3fa  e821ffffff             -call 0x49d320
    cpu.esp -= 4;
    sub_49d320(app, cpu);
    if (cpu.terminate) return;
    // 0049d3ff  83f801                 +cmp eax, 1
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
    // 0049d402  7327                   -jae 0x49d42b
    if (!cpu.flags.cf)
    {
        goto L_0x0049d42b;
    }
L_0x0049d404:
    // 0049d404  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d407  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d409  7406                   -je 0x49d411
    if (cpu.flags.zf)
    {
        goto L_0x0049d411;
    }
    // 0049d40b  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x0049d411:
    // 0049d411  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049d415  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d417  7407                   -je 0x49d420
    if (cpu.flags.zf)
    {
        goto L_0x0049d420;
    }
    // 0049d419  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
L_0x0049d420:
    // 0049d420  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d422  83c410                 +add esp, 0x10
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
    // 0049d425  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d426  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d427  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d428  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049d42b:
    // 0049d42b  0f8777000000           -ja 0x49d4a8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049d4a8;
    }
    // 0049d431  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049d435  8d5f06                 -lea ebx, [edi + 6]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0049d438  39f3                   +cmp ebx, esi
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
    // 0049d43a  73c8                   -jae 0x49d404
    if (!cpu.flags.cf)
    {
        goto L_0x0049d404;
    }
L_0x0049d43c:
    // 0049d43c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d43e  0f85e0000000           -jne 0x49d524
    if (!cpu.flags.zf)
    {
        goto L_0x0049d524;
    }
L_0x0049d444:
    // 0049d444  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d446  0f8558010000           -jne 0x49d5a4
    if (!cpu.flags.zf)
    {
        goto L_0x0049d5a4;
    }
    // 0049d44c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d450  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d454  0f854a010000           -jne 0x49d5a4
    if (!cpu.flags.zf)
    {
        goto L_0x0049d5a4;
    }
L_0x0049d45a:
    // 0049d45a  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d45e  741b                   -je 0x49d47b
    if (cpu.flags.zf)
    {
        goto L_0x0049d47b;
    }
    // 0049d460  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049d465  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d467  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d469  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d46b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d46d  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d474  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049d476  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d479  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0049d47b:
    // 0049d47b  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049d47f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d481  7419                   -je 0x49d49c
    if (cpu.flags.zf)
    {
        goto L_0x0049d49c;
    }
    // 0049d483  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049d488  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0049d48b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d48d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d48f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d491  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d498  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049d49a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0049d49c:
    // 0049d49c  8d4306                 -lea eax, [ebx + 6]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0049d49f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d4a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d4a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d4a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d4a5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049d4a8:
    // 0049d4a8  83f802                 +cmp eax, 2
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
    // 0049d4ab  0f8553ffffff           -jne 0x49d404
    if (!cpu.flags.zf)
    {
        goto L_0x0049d404;
    }
    // 0049d4b1  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049d4b5  8d5f10                 -lea ebx, [edi + 0x10]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049d4b8  39cb                   +cmp ebx, ecx
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
    // 0049d4ba  0f8344ffffff           -jae 0x49d404
    if (!cpu.flags.cf)
    {
        goto L_0x0049d404;
    }
L_0x0049d4c0:
    // 0049d4c0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d4c2  0f851e010000           -jne 0x49d5e6
    if (!cpu.flags.zf)
    {
        goto L_0x0049d5e6;
    }
    // 0049d4c8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d4cc  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d4d0  0f8510010000           -jne 0x49d5e6
    if (!cpu.flags.zf)
    {
        goto L_0x0049d5e6;
    }
L_0x0049d4d6:
    // 0049d4d6  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d4da  741b                   -je 0x49d4f7
    if (cpu.flags.zf)
    {
        goto L_0x0049d4f7;
    }
    // 0049d4dc  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049d4e1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d4e3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d4e5  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d4e7  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d4e9  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d4f0  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049d4f2  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d4f5  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0049d4f7:
    // 0049d4f7  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049d4fb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d4fd  7419                   -je 0x49d518
    if (cpu.flags.zf)
    {
        goto L_0x0049d518;
    }
    // 0049d4ff  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049d504  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049d507  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d509  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d50b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d50d  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d514  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049d516  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0049d518:
    // 0049d518  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049d51b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d51e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d51f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d520  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d521  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049d524:
    // 0049d524  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049d528  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0049d52a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049d52c  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d52e  81ce20202020           -or esi, 0x20202020
    cpu.esi |= x86::reg32(x86::sreg32(538976288 /*0x20202020*/));
L_0x0049d534:
    // 0049d534  39d7                   +cmp edi, edx
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
    // 0049d536  7d65                   -jge 0x49d59d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d59d;
    }
    // 0049d538  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0049d53b  0d20202020             -or eax, 0x20202020
    cpu.eax |= x86::reg32(x86::sreg32(538976288 /*0x20202020*/));
    // 0049d540  39f0                   +cmp eax, esi
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
    // 0049d542  7459                   -je 0x49d59d
    if (cpu.flags.zf)
    {
        goto L_0x0049d59d;
    }
    // 0049d544  8b470a                 -mov eax, dword ptr [edi + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0049d547  8d7f0e                 -lea edi, [edi + 0xe]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0049d54a  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 0049d54f  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 0049d554  7522                   -jne 0x49d578
    if (!cpu.flags.zf)
    {
        goto L_0x0049d578;
    }
    // 0049d556  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d558  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049d55b  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 0049d560  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 0049d565  7511                   -jne 0x49d578
    if (!cpu.flags.zf)
    {
        goto L_0x0049d578;
    }
L_0x0049d567:
    // 0049d567  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d569  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049d56c  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 0049d571  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 0049d576  74ef                   -je 0x49d567
    if (cpu.flags.zf)
    {
        goto L_0x0049d567;
    }
L_0x0049d578:
    // 0049d578  8a47fc                 -mov al, byte ptr [edi - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 0049d57b  8d7ffd                 -lea edi, [edi - 3]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(-3) /* -0x3 */);
    // 0049d57e  3c00                   +cmp al, 0
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
    // 0049d580  74b2                   -je 0x49d534
    if (cpu.flags.zf)
    {
        goto L_0x0049d534;
    }
    // 0049d582  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049d584  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0049d587  3c00                   +cmp al, 0
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
    // 0049d589  74a9                   -je 0x49d534
    if (cpu.flags.zf)
    {
        goto L_0x0049d534;
    }
    // 0049d58b  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049d58d  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0049d590  3c00                   +cmp al, 0
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
    // 0049d592  74a0                   -je 0x49d534
    if (cpu.flags.zf)
    {
        goto L_0x0049d534;
    }
    // 0049d594  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049d596  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0049d599  3c00                   +cmp al, 0
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
    // 0049d59b  7497                   -je 0x49d534
    if (cpu.flags.zf)
    {
        goto L_0x0049d534;
    }
L_0x0049d59d:
    // 0049d59d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049d59f  e9a0feffff             -jmp 0x49d444
    goto L_0x0049d444;
L_0x0049d5a4:
    // 0049d5a4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d5a6  7412                   -je 0x49d5ba
    if (cpu.flags.zf)
    {
        goto L_0x0049d5ba;
    }
    // 0049d5a8  8d4306                 -lea eax, [ebx + 6]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0049d5ab  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049d5ad  e8811b0000             -call 0x49f133
    cpu.esp -= 4;
    sub_49f133(app, cpu);
    if (cpu.terminate) return;
    // 0049d5b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d5b4  0f84a0feffff           -je 0x49d45a
    if (cpu.flags.zf)
    {
        goto L_0x0049d45a;
    }
L_0x0049d5ba:
    // 0049d5ba  8d7b06                 -lea edi, [ebx + 6]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0049d5bd  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d5bf  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d5c0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049d5c2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049d5c4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049d5c6  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d5c7  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d5cb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049d5cf  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d5d1  47                     -inc edi
    (cpu.edi)++;
    // 0049d5d2  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0049d5d5  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0049d5d9  39c3                   +cmp ebx, eax
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
    // 0049d5db  0f825bfeffff           -jb 0x49d43c
    if (cpu.flags.cf)
    {
        goto L_0x0049d43c;
    }
    // 0049d5e1  e91efeffff             -jmp 0x49d404
    goto L_0x0049d404;
L_0x0049d5e6:
    // 0049d5e6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d5e8  7412                   -je 0x49d5fc
    if (cpu.flags.zf)
    {
        goto L_0x0049d5fc;
    }
    // 0049d5ea  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049d5ed  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049d5ef  e83f1b0000             -call 0x49f133
    cpu.esp -= 4;
    sub_49f133(app, cpu);
    if (cpu.terminate) return;
    // 0049d5f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d5f6  0f84dafeffff           -je 0x49d4d6
    if (cpu.flags.zf)
    {
        goto L_0x0049d4d6;
    }
L_0x0049d5fc:
    // 0049d5fc  8d7b08                 -lea edi, [ebx + 8]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049d5ff  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d601  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d602  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049d604  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049d606  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049d608  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d609  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d60d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049d611  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d613  47                     -inc edi
    (cpu.edi)++;
    // 0049d614  83c309                 -add ebx, 9
    (cpu.ebx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0049d617  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0049d61b  39c3                   +cmp ebx, eax
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
    // 0049d61d  0f829dfeffff           -jb 0x49d4c0
    if (cpu.flags.cf)
    {
        goto L_0x0049d4c0;
    }
    // 0049d623  e9dcfdffff             -jmp 0x49d404
    goto L_0x0049d404;
}

/* align: skip  */
void Application::sub_49d628(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d628);
    // 0049d628  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d629  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d62c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d62d  68880d5700             -push 0x570d88
    app->getMemory<x86::reg32>(cpu.esp-4) = 5705096 /*0x570d88*/;
    cpu.esp -= 4;
    // 0049d632  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049d636  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d638  e88ffdffff             -call 0x49d3cc
    cpu.esp -= 4;
    sub_49d3cc(app, cpu);
    if (cpu.terminate) return;
    // 0049d63d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d640  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d643  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d644  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d648(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d648);
    // 0049d648  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d649  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049d64e  e8d5ffffff             -call 0x49d628
    cpu.esp -= 4;
    sub_49d628(app, cpu);
    if (cpu.terminate) return;
    // 0049d653  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d654  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d658(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d658);
    // 0049d658  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d659  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d65b  e8c8ffffff             -call 0x49d628
    cpu.esp -= 4;
    sub_49d628(app, cpu);
    if (cpu.terminate) return;
    // 0049d660  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d661  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d664(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d664);
    // 0049d664  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d665  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d666  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d668  e8bbffffff             -call 0x49d628
    cpu.esp -= 4;
    sub_49d628(app, cpu);
    if (cpu.terminate) return;
    // 0049d66d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049d66f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d671  7403                   -je 0x49d676
    if (cpu.flags.zf)
    {
        goto L_0x0049d676;
    }
    // 0049d673  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
L_0x0049d676:
    // 0049d676  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d678  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d679  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d67a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49d67c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d67c);
    // 0049d67c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d67d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049d682  e8ddffffff             -call 0x49d664
    cpu.esp -= 4;
    sub_49d664(app, cpu);
    if (cpu.terminate) return;
    // 0049d687  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d688  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d68c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d68c);
    // 0049d68c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d68d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d68f  e8d0ffffff             -call 0x49d664
    cpu.esp -= 4;
    sub_49d664(app, cpu);
    if (cpu.terminate) return;
    // 0049d694  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d695  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d698(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d698);
    // 0049d698  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d699  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d69a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d69b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d69e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049d6a1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049d6a3  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0049d6a5:
    // 0049d6a5  b22c                   -mov dl, 0x2c
    cpu.dl = 44 /*0x2c*/;
    // 0049d6a7  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0049d6a9:
    // 0049d6a9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d6ab  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d6ad  7412                   -je 0x49d6c1
    if (cpu.flags.zf)
    {
        goto L_0x0049d6c1;
    }
    // 0049d6af  3c00                   +cmp al, 0
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
    // 0049d6b1  740c                   -je 0x49d6bf
    if (cpu.flags.zf)
    {
        goto L_0x0049d6bf;
    }
    // 0049d6b3  46                     -inc esi
    (cpu.esi)++;
    // 0049d6b4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d6b6  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d6b8  7407                   -je 0x49d6c1
    if (cpu.flags.zf)
    {
        goto L_0x0049d6c1;
    }
    // 0049d6ba  46                     -inc esi
    (cpu.esi)++;
    // 0049d6bb  3c00                   +cmp al, 0
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
    // 0049d6bd  75ea                   -jne 0x49d6a9
    if (!cpu.flags.zf)
    {
        goto L_0x0049d6a9;
    }
L_0x0049d6bf:
    // 0049d6bf  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049d6c1:
    // 0049d6c1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049d6c3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d6c5  7403                   -je 0x49d6ca
    if (cpu.flags.zf)
    {
        goto L_0x0049d6ca;
    }
    // 0049d6c7  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
L_0x0049d6ca:
    // 0049d6ca  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d6cd  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049d6cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d6d1  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d6d4  e88bffffff             -call 0x49d664
    cpu.esp -= 4;
    sub_49d664(app, cpu);
    if (cpu.terminate) return;
    // 0049d6d9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049d6dc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049d6de  7406                   -je 0x49d6e6
    if (cpu.flags.zf)
    {
        goto L_0x0049d6e6;
    }
    // 0049d6e0  c6012c                 -mov byte ptr [ecx], 0x2c
    app->getMemory<x86::reg8>(cpu.ecx) = 44 /*0x2c*/;
    // 0049d6e3  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d6e4  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0049d6e6:
    // 0049d6e6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049d6e8  75bb                   -jne 0x49d6a5
    if (!cpu.flags.zf)
    {
        goto L_0x0049d6a5;
    }
    // 0049d6ea  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d6ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d6f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d6f4);
    // 0049d6f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d6f5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049d6fa  e899ffffff             -call 0x49d698
    cpu.esp -= 4;
    sub_49d698(app, cpu);
    if (cpu.terminate) return;
    // 0049d6ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d700  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d704(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d704);
    // 0049d704  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d705  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d707  e88cffffff             -call 0x49d698
    cpu.esp -= 4;
    sub_49d698(app, cpu);
    if (cpu.terminate) return;
    // 0049d70c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d70d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d710);
    // 0049d710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d712  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d713  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d715  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d717  e804fcffff             -call 0x49d320
    cpu.esp -= 4;
    sub_49d320(app, cpu);
    if (cpu.terminate) return;
    // 0049d71c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d71e  83f801                 +cmp eax, 1
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
    // 0049d721  7207                   -jb 0x49d72a
    if (cpu.flags.cf)
    {
        goto L_0x0049d72a;
    }
    // 0049d723  760b                   -jbe 0x49d730
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d730;
    }
    // 0049d725  83f802                 +cmp eax, 2
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
    // 0049d728  7421                   -je 0x49d74b
    if (cpu.flags.zf)
    {
        goto L_0x0049d74b;
    }
L_0x0049d72a:
    // 0049d72a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d72c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d72d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d72e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d72f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d730:
    // 0049d730  8d4104                 -lea eax, [ecx + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049d733  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0049d738  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d73a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d73c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d73e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d745  d3e8                   +shr eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0049d747  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049d749  ebdf                   -jmp 0x49d72a
    goto L_0x0049d72a;
L_0x0049d74b:
    // 0049d74b  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049d74e  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049d753  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d755  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049d757  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d759  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049d760  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049d762  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049d764  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d766  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d767  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d768  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d769  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d76c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d76c);
    // 0049d76c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d76d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d76e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d76f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d772  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d774  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d776  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049d77a  68880d5700             -push 0x570d88
    app->getMemory<x86::reg32>(cpu.esp-4) = 5705096 /*0x570d88*/;
    cpu.esp -= 4;
    // 0049d77f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049d781  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d783  e844fcffff             -call 0x49d3cc
    cpu.esp -= 4;
    sub_49d3cc(app, cpu);
    if (cpu.terminate) return;
    // 0049d788  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d78a  7405                   -je 0x49d791
    if (cpu.flags.zf)
    {
        goto L_0x0049d791;
    }
    // 0049d78c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d78f  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0049d791:
    // 0049d791  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d794  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d795  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d796  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d797  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d798(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d798);
    // 0049d798  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d799  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d79a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049d79c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d79e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049d7a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d7a2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d7a4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d7a6  e821fcffff             -call 0x49d3cc
    cpu.esp -= 4;
    sub_49d3cc(app, cpu);
    if (cpu.terminate) return;
    // 0049d7ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d7ad  7507                   -jne 0x49d7b6
    if (!cpu.flags.zf)
    {
        goto L_0x0049d7b6;
    }
    // 0049d7af  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 0049d7b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d7b6:
    // 0049d7b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d7b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d7b8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d7ba  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0049d7bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049d7bd:
    // 0049d7bd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d7bf  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049d7c1  3c00                   +cmp al, 0
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
    // 0049d7c3  7410                   -je 0x49d7d5
    if (cpu.flags.zf)
    {
        goto L_0x0049d7d5;
    }
    // 0049d7c5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049d7c8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d7cb  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049d7ce  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d7d1  3c00                   +cmp al, 0
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
    // 0049d7d3  75e8                   -jne 0x49d7bd
    if (!cpu.flags.zf)
    {
        goto L_0x0049d7bd;
    }
L_0x0049d7d5:
    // 0049d7d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7d6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049d7d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49d7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d7e0);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0049d7e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d7e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d7e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d7e4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049d7e6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d7e8  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049d7ea  7d05                   -jge 0x49d7f1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d7f1;
    }
    // 0049d7ec  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049d7ef  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x0049d7f1:
    // 0049d7f1  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049d7f3  7d05                   -jge 0x49d7fa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d7fa;
    }
    // 0049d7f5  83cb10                 -or ebx, 0x10
    cpu.ebx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d7f8  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x0049d7fa:
    // 0049d7fa  39ca                   +cmp edx, ecx
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
    // 0049d7fc  7c07                   -jl 0x49d805
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d805;
    }
    // 0049d7fe  741d                   -je 0x49d81d
    if (cpu.flags.zf)
    {
        goto L_0x0049d81d;
    }
    // 0049d800  87d1                   -xchg ecx, edx
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.edx;
        cpu.edx = tmp;
    }
    // 0049d802  83cb04                 -or ebx, 4
    cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049d805:
    // 0049d805  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d807  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049d809  c1e818                 +shr eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0049d80c  83d000                 +adc eax, 0
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
    // 0049d80f  0fb68078fc4d00         -movzx eax, byte ptr [eax + 0x4dfc78]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5110904) /* 0x4dfc78 */));
    // 0049d816  2effa329d84900         -jmp dword ptr cs:[ebx + 0x49d829]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + 4839465); goto dynamic_jump;
L_0x0049d81d:
    // 0049d81d  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 0049d822  2effa329d84900         -jmp dword ptr cs:[ebx + 0x49d829]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + 4839465); goto dynamic_jump;
  case 0x0049d849:
    // 0049d849  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049d84b  0500010000             -add eax, 0x100
    (cpu.eax) += x86::reg32(x86::sreg32(256 /*0x100*/));
  [[fallthrough]];
  case 0x0049d850:
    // 0049d850  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d851  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d852  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049d853:
    // 0049d853  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049d855  0500020000             -add eax, 0x200
    (cpu.eax) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0049d85a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d85b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d85c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049d85d:
    // 0049d85d  0500010000             -add eax, 0x100
    (cpu.eax) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0049d862  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d863  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d864  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049d865:
    // 0049d865  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049d867  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d868  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d869  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049d86a:
    // 0049d86a  2d00010000             -sub eax, 0x100
    (cpu.eax) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0049d86f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d870  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d871  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049d872:
    // 0049d872  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0049d877  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d878  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d879  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0049d87a:
    // 0049d87a  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049d87c  2d00010000             -sub eax, 0x100
    (cpu.eax) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0049d881  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d882  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d883  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49d890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d890);
    // 0049d890  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d891  39d0                   +cmp eax, edx
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
    // 0049d893  7526                   -jne 0x49d8bb
    if (!cpu.flags.zf)
    {
        goto L_0x0049d8bb;
    }
    // 0049d895  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d898  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049d89b  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049d89e  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049d8a1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049d8a4  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0049d8a7  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049d8aa  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049d8ad  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049d8b0  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049d8b3  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049d8b6  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0049d8b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d8bb:
    // 0049d8bb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d8bd  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049d8bf  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049d8c2  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049d8c5  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0049d8c8  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049d8cb  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d8ce  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049d8d1  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049d8d4  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049d8d7  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049d8da  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049d8dd  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049d8e0  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049d8e3  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049d8e6  894a1c                 -mov dword ptr [edx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049d8e9  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049d8ec  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049d8ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49d900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d900);
    // 0049d900  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d901  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d902  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d903  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0049d909  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d90b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049d90d  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049d90f  e854a0feff             -call 0x487968
    cpu.esp -= 4;
    sub_487968(app, cpu);
    if (cpu.terminate) return;
    // 0049d914  8d43f8                 -lea eax, [ebx - 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-8) /* -0x8 */);
    // 0049d917  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d919  3d00010000             +cmp eax, 0x100
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
    // 0049d91e  7d05                   -jge 0x49d925
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d925;
    }
    // 0049d920  83f808                 +cmp eax, 8
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
    // 0049d923  7e35                   -jle 0x49d95a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d95a;
    }
L_0x0049d925:
    // 0049d925  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049d928  3d00010000             +cmp eax, 0x100
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
    // 0049d92d  7d24                   -jge 0x49d953
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d953;
    }
L_0x0049d92f:
    // 0049d92f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0049d931:
    // 0049d931  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049d933  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d935  e81ea0feff             -call 0x487958
    cpu.esp -= 4;
    sub_487958(app, cpu);
    if (cpu.terminate) return;
    // 0049d93a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d93c  7523                   -jne 0x49d961
    if (!cpu.flags.zf)
    {
        goto L_0x0049d961;
    }
L_0x0049d93e:
    // 0049d93e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049d940  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d942  e821a0feff             -call 0x487968
    cpu.esp -= 4;
    sub_487968(app, cpu);
    if (cpu.terminate) return;
    // 0049d947  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d949  81c400010000           +add esp, 0x100
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d94f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d950  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d951  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d952  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d953:
    // 0049d953  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049d958  ebd5                   -jmp 0x49d92f
    goto L_0x0049d92f;
L_0x0049d95a:
    // 0049d95a  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0049d95f  ebd0                   -jmp 0x49d931
    goto L_0x0049d931;
L_0x0049d961:
    // 0049d961  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049d963  e83c100000             -call 0x49e9a4
    cpu.esp -= 4;
    sub_49e9a4(app, cpu);
    if (cpu.terminate) return;
    // 0049d968  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d96a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d96c  75d0                   -jne 0x49d93e
    if (!cpu.flags.zf)
    {
        goto L_0x0049d93e;
    }
    // 0049d96e  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049d970  ebcc                   -jmp 0x49d93e
    goto L_0x0049d93e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d974(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d974);
    // 0049d974  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d975  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049d97a  e811000000             -call 0x49d990
    cpu.esp -= 4;
    sub_49d990(app, cpu);
    if (cpu.terminate) return;
    // 0049d97f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d980  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d984(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d984);
    // 0049d984  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d985  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d987  e804000000             -call 0x49d990
    cpu.esp -= 4;
    sub_49d990(app, cpu);
    if (cpu.terminate) return;
    // 0049d98c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d98d  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
