#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_49f92c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f92c);
    // 0049f92c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f92d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f92e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f92f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f930  e84789feff             -call 0x48827c
    cpu.esp -= 4;
    sub_48827c(app, cpu);
    if (cpu.terminate) return;
    // 0049f935  8b15d49b5900           -mov edx, dword ptr [0x599bd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049f93b  a334b84d00             -mov dword ptr [0x4db834], eax
    app->getMemory<x86::reg32>(x86::reg32(5093428) /* 0x4db834 */) = cpu.eax;
    // 0049f940  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f942  7453                   -je 0x49f997
    if (cpu.flags.zf)
    {
        goto L_0x0049f997;
    }
L_0x0049f944:
    // 0049f944  a134b84d00             -mov eax, dword ptr [0x4db834]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093428) /* 0x4db834 */);
    // 0049f949  e87e89feff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0049f94e  8b1dd49b5900           -mov ebx, dword ptr [0x599bd4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049f954  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049f956  7436                   -je 0x49f98e
    if (cpu.flags.zf)
    {
        goto L_0x0049f98e;
    }
    // 0049f958  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049f95a  e8598afeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049f95f  8b35a09b5900           -mov esi, dword ptr [0x599ba0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5872544) /* 0x599ba0 */);
    // 0049f965  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f967  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f969  7419                   -je 0x49f984
    if (cpu.flags.zf)
    {
        goto L_0x0049f984;
    }
L_0x0049f96b:
    // 0049f96b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f96d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f970  ff90a09b5900           -call dword ptr [eax + 0x599ba0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872544) /* 0x599ba0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f976  83fa20                 +cmp edx, 0x20
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
    // 0049f979  7d09                   -jge 0x49f984
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f984;
    }
    // 0049f97b  83baa09b590000         +cmp dword ptr [edx + 0x599ba0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5872544) /* 0x599ba0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f982  75e7                   -jne 0x49f96b
    if (!cpu.flags.zf)
    {
        goto L_0x0049f96b;
    }
L_0x0049f984:
    // 0049f984  a1d49b5900             -mov eax, dword ptr [0x599bd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049f989  e8428afeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x0049f98e:
    // 0049f98e  833dd49b590000         +cmp dword ptr [0x599bd4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f995  75ad                   -jne 0x49f944
    if (!cpu.flags.zf)
    {
        goto L_0x0049f944;
    }
L_0x0049f997:
    // 0049f997  a134b84d00             -mov eax, dword ptr [0x4db834]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093428) /* 0x4db834 */);
    // 0049f99c  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049f99e  e8b589feff             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 0049f9a3  892d34b84d00           -mov dword ptr [0x4db834], ebp
    app->getMemory<x86::reg32>(x86::reg32(5093428) /* 0x4db834 */) = cpu.ebp;
    // 0049f9a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49f9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f9b0);
    // 0049f9b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f9b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f9b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f9b3  8b15d49b5900           -mov edx, dword ptr [0x599bd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049f9b9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f9bb  7504                   -jne 0x49f9c1
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9c1;
    }
L_0x0049f9bd:
    // 0049f9bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f9c1:
    // 0049f9c1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f9c3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049f9c5  e8ee89feff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049f9ca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f9cc  b8c09b5900             -mov eax, 0x599bc0
    cpu.eax = 5872576 /*0x599bc0*/;
    // 0049f9d1  8b1534b84d00           -mov edx, dword ptr [0x4db834]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093428) /* 0x4db834 */);
    // 0049f9d7  891dd49b5900           -mov dword ptr [0x599bd4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */) = cpu.ebx;
    // 0049f9dd  e8ae88feff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0049f9e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f9e4  e8e789feff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049f9e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f9eb  e8f489feff             -call 0x4883e4
    cpu.esp -= 4;
    sub_4883e4(app, cpu);
    if (cpu.terminate) return;
    // 0049f9f0  b8c09b5900             -mov eax, 0x599bc0
    cpu.eax = 5872576 /*0x599bc0*/;
    // 0049f9f5  e85e86feff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 0049f9fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f9fc  75bf                   -jne 0x49f9bd
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9bd;
    }
    // 0049f9fe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049fa00:
    // 0049fa00  3b1534b84d00           +cmp edx, dword ptr [0x4db834]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5093428) /* 0x4db834 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fa06  74b5                   -je 0x49f9bd
    if (cpu.flags.zf)
    {
        goto L_0x0049f9bd;
    }
    // 0049fa08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fa0a  e8fd85feff             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 0049fa0f  ebef                   -jmp 0x49fa00
    goto L_0x0049fa00;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49fa14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fa14);
    // 0049fa14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fa15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fa16  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fa17  b8b0f94900             -mov eax, 0x49f9b0
    cpu.eax = 4848048 /*0x49f9b0*/;
    // 0049fa1c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0049fa21  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049fa26  e8b562ffff             -call 0x495ce0
    cpu.esp -= 4;
    sub_495ce0(app, cpu);
    if (cpu.terminate) return;
    // 0049fa2b  e83889feff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0049fa30  a3d49b5900             -mov dword ptr [0x599bd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */) = cpu.eax;
    // 0049fa35  e87e89feff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049fa3a  68c09b5900             -push 0x599bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5872576 /*0x599bc0*/;
    cpu.esp -= 4;
    // 0049fa3f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fa41  b82cf94900             -mov eax, 0x49f92c
    cpu.eax = 4847916 /*0x49f92c*/;
    // 0049fa46  e80585feff             -call 0x487f50
    cpu.esp -= 4;
    sub_487f50(app, cpu);
    if (cpu.terminate) return;
    // 0049fa4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fa4d  7516                   -jne 0x49fa65
    if (!cpu.flags.zf)
    {
        goto L_0x0049fa65;
    }
    // 0049fa4f  a1d49b5900             -mov eax, dword ptr [0x599bd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049fa54  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fa56  e88989feff             -call 0x4883e4
    cpu.esp -= 4;
    sub_4883e4(app, cpu);
    if (cpu.terminate) return;
    // 0049fa5b  8915d49b5900           -mov dword ptr [0x599bd4], edx
    app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */) = cpu.edx;
    // 0049fa61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fa65:
    // 0049fa65  a1d49b5900             -mov eax, dword ptr [0x599bd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049fa6a  e86189feff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049fa6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49fa74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fa74);
    // 0049fa74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fa75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fa76  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fa77  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049fa79  8b15d49b5900           -mov edx, dword ptr [0x599bd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049fa7f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0049fa84  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049fa86  7446                   -je 0x49face
    if (cpu.flags.zf)
    {
        goto L_0x0049face;
    }
L_0x0049fa88:
    // 0049fa88  a1d49b5900             -mov eax, dword ptr [0x599bd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049fa8d  e82689feff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049fa92  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fa94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049fa96:
    // 0049fa96  83baa09b590000         +cmp dword ptr [edx + 0x599ba0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5872544) /* 0x599ba0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fa9d  7504                   -jne 0x49faa3
    if (!cpu.flags.zf)
    {
        goto L_0x0049faa3;
    }
    // 0049fa9f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049faa1  7c32                   -jl 0x49fad5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049fad5;
    }
L_0x0049faa3:
    // 0049faa3  3b9aa09b5900           +cmp ebx, dword ptr [edx + 0x599ba0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5872544) /* 0x599ba0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049faa9  7415                   -je 0x49fac0
    if (cpu.flags.zf)
    {
        goto L_0x0049fac0;
    }
L_0x0049faab:
    // 0049faab  40                     -inc eax
    (cpu.eax)++;
    // 0049faac  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049faaf  83f808                 +cmp eax, 8
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
    // 0049fab2  7ce2                   -jl 0x49fa96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049fa96;
    }
    // 0049fab4  83f9ff                 +cmp ecx, -1
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
    // 0049fab7  7407                   -je 0x49fac0
    if (cpu.flags.zf)
    {
        goto L_0x0049fac0;
    }
    // 0049fab9  891c8da09b5900         -mov dword ptr [ecx*4 + 0x599ba0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5872544) /* 0x599ba0 */ + cpu.ecx * 4) = cpu.ebx;
L_0x0049fac0:
    // 0049fac0  a1d49b5900             -mov eax, dword ptr [0x599bd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049fac5  e80689feff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049faca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049facb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049facc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049facd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049face:
    // 0049face  e841ffffff             -call 0x49fa14
    cpu.esp -= 4;
    sub_49fa14(app, cpu);
    if (cpu.terminate) return;
    // 0049fad3  ebb3                   -jmp 0x49fa88
    goto L_0x0049fa88;
L_0x0049fad5:
    // 0049fad5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fad7  ebd2                   -jmp 0x49faab
    goto L_0x0049faab;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49fadc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fadc);
    // 0049fadc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fadd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fade  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fadf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fae0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fae2  8b15d49b5900           -mov edx, dword ptr [0x599bd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049fae8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049faea  7505                   -jne 0x49faf1
    if (!cpu.flags.zf)
    {
        goto L_0x0049faf1;
    }
L_0x0049faec:
    // 0049faec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049faed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049faee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049faef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049faf0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049faf1:
    // 0049faf1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049faf3  e8c088feff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049faf8  8b1da09b5900           -mov ebx, dword ptr [0x599ba0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5872544) /* 0x599ba0 */);
    // 0049fafe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fb00  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fb02  39d9                   +cmp ecx, ebx
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
    // 0049fb04  7411                   -je 0x49fb17
    if (cpu.flags.zf)
    {
        goto L_0x0049fb17;
    }
L_0x0049fb06:
    // 0049fb06  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049fb09  42                     -inc edx
    (cpu.edx)++;
    // 0049fb0a  83f820                 +cmp eax, 0x20
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
    // 0049fb0d  7d08                   -jge 0x49fb17
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049fb17;
    }
    // 0049fb0f  3b88a09b5900           +cmp ecx, dword ptr [eax + 0x599ba0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872544) /* 0x599ba0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb15  75ef                   -jne 0x49fb06
    if (!cpu.flags.zf)
    {
        goto L_0x0049fb06;
    }
L_0x0049fb17:
    // 0049fb17  83fa08                 +cmp edx, 8
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
    // 0049fb1a  7d30                   -jge 0x49fb4c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049fb4c;
    }
    // 0049fb1c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049fb23  3b88a09b5900           +cmp ecx, dword ptr [eax + 0x599ba0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872544) /* 0x599ba0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb29  7521                   -jne 0x49fb4c
    if (!cpu.flags.zf)
    {
        goto L_0x0049fb4c;
    }
    // 0049fb2b  83fa07                 +cmp edx, 7
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
    // 0049fb2e  7d14                   -jge 0x49fb44
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049fb44;
    }
L_0x0049fb30:
    // 0049fb30  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049fb33  8b90a09b5900           -mov edx, dword ptr [eax + 0x599ba0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872544) /* 0x599ba0 */);
    // 0049fb39  89909c9b5900           -mov dword ptr [eax + 0x599b9c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872540) /* 0x599b9c */) = cpu.edx;
    // 0049fb3f  83f81c                 +cmp eax, 0x1c
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
    // 0049fb42  7cec                   -jl 0x49fb30
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049fb30;
    }
L_0x0049fb44:
    // 0049fb44  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fb46  892dbc9b5900           -mov dword ptr [0x599bbc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5872572) /* 0x599bbc */) = cpu.ebp;
L_0x0049fb4c:
    // 0049fb4c  a1d49b5900             -mov eax, dword ptr [0x599bd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872596) /* 0x599bd4 */);
    // 0049fb51  e87a88feff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049fb56  8b15a09b5900           -mov edx, dword ptr [0x599ba0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872544) /* 0x599ba0 */);
    // 0049fb5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fb5e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
L_0x0049fb60:
    // 0049fb60  758a                   -jne 0x49faec
    if (!cpu.flags.zf)
    {
        goto L_0x0049faec;
    }
    // 0049fb62  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049fb65  83f820                 +cmp eax, 0x20
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
    // 0049fb68  7d09                   -jge 0x49fb73
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049fb73;
    }
    // 0049fb6a  83b8a09b590000         +cmp dword ptr [eax + 0x599ba0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872544) /* 0x599ba0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb71  ebed                   -jmp 0x49fb60
    goto L_0x0049fb60;
L_0x0049fb73:
    // 0049fb73  e838feffff             -call 0x49f9b0
    cpu.esp -= 4;
    sub_49f9b0(app, cpu);
    if (cpu.terminate) return;
    // 0049fb78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49fb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fb80);
    // 0049fb80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fb81  8b1534b84d00           -mov edx, dword ptr [0x4db834]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093428) /* 0x4db834 */);
    // 0049fb87  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049fb89  7502                   -jne 0x49fb8d
    if (!cpu.flags.zf)
    {
        goto L_0x0049fb8d;
    }
    // 0049fb8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fb8d:
    // 0049fb8d  b8c09b5900             -mov eax, 0x599bc0
    cpu.eax = 5872576 /*0x599bc0*/;
    // 0049fb92  e8f986feff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0049fb97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49fba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fba0);
    // 0049fba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fba1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fba2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fba3  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0049fba8  be5c904d00             -mov esi, 0x4d905c
    cpu.esi = 5083228 /*0x4d905c*/;
    // 0049fbad  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049fbaf  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049fbb1  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0049fbb6  be94904d00             -mov esi, 0x4d9094
    cpu.esi = 5083284 /*0x4d9094*/;
    // 0049fbbb  8d7838                 -lea edi, [eax + 0x38]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0049fbbe  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049fbc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49fbc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fbc4);
    // 0049fbc4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fbc5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fbc6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fbc7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fbc9  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0049fbce  bf94904d00             -mov edi, 0x4d9094
    cpu.edi = 5083284 /*0x4d9094*/;
    // 0049fbd3  e8340efeff             -call 0x480a0c
    cpu.esp -= 4;
    sub_480a0c(app, cpu);
    if (cpu.terminate) return;
    // 0049fbd8  8d7638                 -lea esi, [esi + 0x38]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0049fbdb  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049fbdd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbe0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49fbe1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fbe1);
    // 0049fbe1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fbe2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fbe3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049fbe5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049fbe7  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049fbea  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049fbec  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0049fbee  ff4010                 -inc dword ptr [eax + 0x10]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
    // 0049fbf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbf2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fbf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49fbf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fbf4);
    // 0049fbf4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fbf5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fbf6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fbf8  b9e1fb4900             -mov ecx, 0x49fbe1
    cpu.ecx = 4848609 /*0x49fbe1*/;
    // 0049fbfd  e855160100             -call 0x4b1257
    cpu.esp -= 4;
    sub_4b1257(app, cpu);
    if (cpu.terminate) return;
    // 0049fc02  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 0049fc06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49fc10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc10);
    // 0049fc10  833dd89b590000         +cmp dword ptr [0x599bd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872600) /* 0x599bd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fc17  7406                   -je 0x49fc1f
    if (cpu.flags.zf)
    {
        goto L_0x0049fc1f;
    }
    // 0049fc19  b8d89b5900             -mov eax, 0x599bd8
    cpu.eax = 5872600 /*0x599bd8*/;
    // 0049fc1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fc1f:
    // 0049fc1f  e84487feff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0049fc24  a3d89b5900             -mov dword ptr [0x599bd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5872600) /* 0x599bd8 */) = cpu.eax;
    // 0049fc29  b8d89b5900             -mov eax, 0x599bd8
    cpu.eax = 5872600 /*0x599bd8*/;
    // 0049fc2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49fc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc30);
    // 0049fc30  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049fc32  e98187feff             -jmp 0x4883b8
    return sub_4883b8(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_49fc38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc38);
    // 0049fc38  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049fc3a  e99187feff             -jmp 0x4883d0
    return sub_4883d0(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_49fc40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc40);
    // 0049fc40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fc41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fc42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fc43  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049fc45  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fc47  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0049fc49  7412                   -je 0x49fc5d
    if (cpu.flags.zf)
    {
        goto L_0x0049fc5d;
    }
L_0x0049fc4b:
    // 0049fc4b  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049fc4d  80f95c                 +cmp cl, 0x5c
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049fc50  7511                   -jne 0x49fc63
    if (!cpu.flags.zf)
    {
        goto L_0x0049fc63;
    }
L_0x0049fc52:
    // 0049fc52  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049fc55  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049fc58  40                     -inc eax
    (cpu.eax)++;
    // 0049fc59  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 0049fc5b  75ee                   -jne 0x49fc4b
    if (!cpu.flags.zf)
    {
        goto L_0x0049fc4b;
    }
L_0x0049fc5d:
    // 0049fc5d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fc5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fc63:
    // 0049fc63  80f93a                 +cmp cl, 0x3a
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049fc66  74ea                   -je 0x49fc52
    if (cpu.flags.zf)
    {
        goto L_0x0049fc52;
    }
    // 0049fc68  80f92f                 +cmp cl, 0x2f
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049fc6b  74e5                   -je 0x49fc52
    if (cpu.flags.zf)
    {
        goto L_0x0049fc52;
    }
    // 0049fc6d  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049fc70  40                     -inc eax
    (cpu.eax)++;
    // 0049fc71  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 0049fc73  75d6                   -jne 0x49fc4b
    if (!cpu.flags.zf)
    {
        goto L_0x0049fc4b;
    }
    // 0049fc75  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fc77  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49fc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fc80);
    // 0049fc80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fc81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fc82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fc83  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fc85  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fc8a  e8a1ffffff             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0049fc8f  804a1940               -or byte ptr [edx + 0x19], 0x40
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(25) /* 0x19 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0049fc93  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0049fc98  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0049fc9b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049fc9d  ba444e4542             -mov edx, 0x42454e44
    cpu.edx = 1111838276 /*0x42454e44*/;
    // 0049fca2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049fca4  e877280000             -call 0x4a2520
    cpu.esp -= 4;
    sub_4a2520(app, cpu);
    if (cpu.terminate) return;
    // 0049fca9  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fcae  e885ffffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0049fcb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fcb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fcb5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fcb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49fcb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fcb8);
    // 0049fcb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fcb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fcba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fcbb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fcbd  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fcc2  e869ffffff             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0049fcc7  8a6219                 -mov ah, byte ptr [edx + 0x19]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(25) /* 0x19 */);
    // 0049fcca  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049fccf  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 0049fcd2  7510                   -jne 0x49fce4
    if (!cpu.flags.zf)
    {
        goto L_0x0049fce4;
    }
L_0x0049fcd4:
    // 0049fcd4  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fcd9  e85affffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0049fcde  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049fce0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fce1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fce2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fce3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fce4:
    // 0049fce4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049fce6  034214                 -add eax, dword ptr [edx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
    // 0049fce9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049fcee  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049fcf0  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049fcf2  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049fcf4  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049fcfb  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049fcfd  3d444e4542             +cmp eax, 0x42454e44
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1111838276 /*0x42454e44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd02  74d0                   -je 0x49fcd4
    if (cpu.flags.zf)
    {
        goto L_0x0049fcd4;
    }
    // 0049fd04  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049fd06  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fd0b  e828ffffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0049fd10  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049fd12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49fd18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fd18);
    // 0049fd18  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049fd1d  eb05                   -jmp 0x49fd24
    return sub_49fd24(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_49fd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fd20);
    // 0049fd20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fd22  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049fd24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fd25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fd26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fd27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fd28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fd29  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fd2e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049fd33  e8f8feffff             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0049fd38  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049fd3a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049fd3c:
    // 0049fd3c  3bbe541b5600           +cmp edi, dword ptr [esi + 0x561b54]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5643092) /* 0x561b54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd42  7420                   -je 0x49fd64
    if (cpu.flags.zf)
    {
        goto L_0x0049fd64;
    }
    // 0049fd44  8b96501b5600           -mov edx, dword ptr [esi + 0x561b50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5643088) /* 0x561b50 */);
    // 0049fd4a  8b9e541b5600           -mov ebx, dword ptr [esi + 0x561b54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5643092) /* 0x561b54 */);
L_0x0049fd50:
    // 0049fd50  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049fd53  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fd55  e85effffff             -call 0x49fcb8
    cpu.esp -= 4;
    sub_49fcb8(app, cpu);
    if (cpu.terminate) return;
    // 0049fd5a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fd5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fd5e  7404                   -je 0x49fd64
    if (cpu.flags.zf)
    {
        goto L_0x0049fd64;
    }
    // 0049fd60  39da                   +cmp edx, ebx
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
    // 0049fd62  75ec                   -jne 0x49fd50
    if (!cpu.flags.zf)
    {
        goto L_0x0049fd50;
    }
L_0x0049fd64:
    // 0049fd64  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049fd67  81fe80010000           +cmp esi, 0x180
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd6d  7d04                   -jge 0x49fd73
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049fd73;
    }
    // 0049fd6f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049fd71  75c9                   -jne 0x49fd3c
    if (!cpu.flags.zf)
    {
        goto L_0x0049fd3c;
    }
L_0x0049fd73:
    // 0049fd73  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fd78  e8bbfeffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0049fd7d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049fd7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49fd24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fd24);
    goto L_entry_0x0049fd24;
    // 0049fd20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fd22  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x0049fd24:
    // 0049fd24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fd25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fd26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fd27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fd28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fd29  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fd2e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049fd33  e8f8feffff             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0049fd38  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049fd3a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049fd3c:
    // 0049fd3c  3bbe541b5600           +cmp edi, dword ptr [esi + 0x561b54]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5643092) /* 0x561b54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd42  7420                   -je 0x49fd64
    if (cpu.flags.zf)
    {
        goto L_0x0049fd64;
    }
    // 0049fd44  8b96501b5600           -mov edx, dword ptr [esi + 0x561b50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5643088) /* 0x561b50 */);
    // 0049fd4a  8b9e541b5600           -mov ebx, dword ptr [esi + 0x561b54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5643092) /* 0x561b54 */);
L_0x0049fd50:
    // 0049fd50  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049fd53  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049fd55  e85effffff             -call 0x49fcb8
    cpu.esp -= 4;
    sub_49fcb8(app, cpu);
    if (cpu.terminate) return;
    // 0049fd5a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fd5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fd5e  7404                   -je 0x49fd64
    if (cpu.flags.zf)
    {
        goto L_0x0049fd64;
    }
    // 0049fd60  39da                   +cmp edx, ebx
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
    // 0049fd62  75ec                   -jne 0x49fd50
    if (!cpu.flags.zf)
    {
        goto L_0x0049fd50;
    }
L_0x0049fd64:
    // 0049fd64  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049fd67  81fe80010000           +cmp esi, 0x180
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd6d  7d04                   -jge 0x49fd73
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049fd73;
    }
    // 0049fd6f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049fd71  75c9                   -jne 0x49fd3c
    if (!cpu.flags.zf)
    {
        goto L_0x0049fd3c;
    }
L_0x0049fd73:
    // 0049fd73  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fd78  e8bbfeffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0049fd7d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049fd7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49fd90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fd90);
    // 0049fd90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fd91  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fd96  e895feffff             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0049fd9b  a108904d00             -mov eax, dword ptr [0x4d9008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */);
    // 0049fda0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049fda2  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049fda5  e80e000000             -call 0x49fdb8
    cpu.esp -= 4;
    sub_49fdb8(app, cpu);
    if (cpu.terminate) return;
    // 0049fdaa  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fdaf  e884feffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0049fdb4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fdb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49fdb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fdb8);
    // 0049fdb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fdb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fdba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fdbb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fdbc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fdbd  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049fdc0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fdc2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049fdc4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fdc6  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0049fdc9  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049fdcd  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049fdcf  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
L_0x0049fdd1:
    // 0049fdd1  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0049fdd3:
    // 0049fdd3  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049fdd5  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049fdd8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049fdda  39d3                   +cmp ebx, edx
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
    // 0049fddc  731b                   -jae 0x49fdf9
    if (!cpu.flags.cf)
    {
        goto L_0x0049fdf9;
    }
    // 0049fdde  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049fde0  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049fde2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049fde4  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049fde6:
    // 0049fde6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049fde8  741a                   -je 0x49fe04
    if (cpu.flags.zf)
    {
        goto L_0x0049fe04;
    }
L_0x0049fdea:
    // 0049fdea  39fe                   +cmp esi, edi
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
    // 0049fdec  7416                   -je 0x49fe04
    if (cpu.flags.zf)
    {
        goto L_0x0049fe04;
    }
    // 0049fdee  f6461818               +test byte ptr [esi + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 0049fdf2  751d                   -jne 0x49fe11
    if (!cpu.flags.zf)
    {
        goto L_0x0049fe11;
    }
    // 0049fdf4  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049fdf7  ebf1                   -jmp 0x49fdea
    goto L_0x0049fdea;
L_0x0049fdf9:
    // 0049fdf9  39f9                   +cmp ecx, edi
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
    // 0049fdfb  74e9                   -je 0x49fde6
    if (cpu.flags.zf)
    {
        goto L_0x0049fde6;
    }
    // 0049fdfd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fdff  8b4924                 -mov ecx, dword ptr [ecx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0049fe02  ebcf                   -jmp 0x49fdd3
    goto L_0x0049fdd3;
L_0x0049fe04:
    // 0049fe04  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049fe08  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049fe0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fe11:
    // 0049fe11  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049fe13  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049fe16  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049fe18  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049fe1b  8d1c2a                 -lea ebx, [edx + ebp]
    cpu.ebx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0049fe1e  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049fe22  3b1424                 +cmp edx, dword ptr [esp]
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
    // 0049fe25  7412                   -je 0x49fe39
    if (cpu.flags.zf)
    {
        goto L_0x0049fe39;
    }
    // 0049fe27  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049fe2a  39d5                   +cmp ebp, edx
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
    // 0049fe2c  7d2f                   -jge 0x49fe5d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049fe5d;
    }
    // 0049fe2e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049fe30  39f9                   +cmp ecx, edi
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
    // 0049fe32  74d0                   -je 0x49fe04
    if (cpu.flags.zf)
    {
        goto L_0x0049fe04;
    }
    // 0049fe34  8b4924                 -mov ecx, dword ptr [ecx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0049fe37  eb98                   -jmp 0x49fdd1
    goto L_0x0049fdd1;
L_0x0049fe39:
    // 0049fe39  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049fe3d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049fe40  29d5                   +sub ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049fe42  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049fe44  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049fe46  e8b59cfeff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049fe4b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049fe50  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049fe52  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 0049fe54  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049fe58  e974ffffff             -jmp 0x49fdd1
    goto L_0x0049fdd1;
L_0x0049fe5d:
    // 0049fe5d  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049fe61  29d5                   +sub ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049fe63  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049fe65  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049fe67  e8949cfeff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049fe6c  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049fe6f  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0049fe72  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 0049fe74  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049fe77  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049fe7a  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049fe7d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0049fe80  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049fe83  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0049fe86  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0049fe89  897024                 -mov dword ptr [eax + 0x24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0049fe8c  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049fe91  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0049fe94  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0049fe98  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049fe9a  e932ffffff             -jmp 0x49fdd1
    goto L_0x0049fdd1;
}

/* align: skip 0x90 */
void Application::sub_49fea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fea0);
    // 0049fea0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fea1  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049fea6  e885fdffff             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0049feab  a108904d00             -mov eax, dword ptr [0x4d9008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */);
    // 0049feb0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049feb3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049feb5  e80e000000             -call 0x49fec8
    cpu.esp -= 4;
    sub_49fec8(app, cpu);
    if (cpu.terminate) return;
    // 0049feba  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049febf  e874fdffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0049fec4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fec5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49fec8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049fec8);
    // 0049fec8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fec9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049feca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fecb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fecc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fecd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fecf  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049fed1  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049fed3  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049fed6  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049fed9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049fedb  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0049fedd:
    // 0049fedd  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0049fedf:
    // 0049fedf  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049fee1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fee3  39d7                   +cmp edi, edx
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
L_0x0049fee5:
    // 0049fee5  7217                   -jb 0x49fefe
    if (cpu.flags.cf)
    {
        goto L_0x0049fefe;
    }
    // 0049fee7  39e9                   +cmp ecx, ebp
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
    // 0049fee9  751b                   -jne 0x49ff06
    if (!cpu.flags.zf)
    {
        goto L_0x0049ff06;
    }
L_0x0049feeb:
    // 0049feeb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049feed  7425                   -je 0x49ff14
    if (cpu.flags.zf)
    {
        goto L_0x0049ff14;
    }
L_0x0049feef:
    // 0049feef  39ee                   +cmp esi, ebp
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
    // 0049fef1  7421                   -je 0x49ff14
    if (cpu.flags.zf)
    {
        goto L_0x0049ff14;
    }
    // 0049fef3  f6461818               +test byte ptr [esi + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 0049fef7  7523                   -jne 0x49ff1c
    if (!cpu.flags.zf)
    {
        goto L_0x0049ff1c;
    }
    // 0049fef9  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0049fefc  ebf1                   -jmp 0x49feef
    goto L_0x0049feef;
L_0x0049fefe:
    // 0049fefe  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ff00  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049ff02  29f8                   +sub eax, edi
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
    // 0049ff04  ebe5                   -jmp 0x49feeb
    goto L_0x0049feeb;
L_0x0049ff06:
    // 0049ff06  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ff08  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ff0b  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0049ff0e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049ff10  3b39                   +cmp edi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ff12  ebd1                   -jmp 0x49fee5
    goto L_0x0049fee5;
L_0x0049ff14:
    // 0049ff14  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ff16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff17  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ff1c:
    // 0049ff1c  39ce                   +cmp esi, ecx
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
    // 0049ff1e  7415                   -je 0x49ff35
    if (cpu.flags.zf)
    {
        goto L_0x0049ff35;
    }
    // 0049ff20  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049ff23  39d0                   +cmp eax, edx
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
    // 0049ff25  7d28                   -jge 0x49ff4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ff4f;
    }
    // 0049ff27  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ff29  037910                 -add edi, dword ptr [ecx + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 0049ff2c  39e9                   +cmp ecx, ebp
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
    // 0049ff2e  74e4                   -je 0x49ff14
    if (cpu.flags.zf)
    {
        goto L_0x0049ff14;
    }
    // 0049ff30  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0049ff33  ebaa                   -jmp 0x49fedf
    goto L_0x0049fedf;
L_0x0049ff35:
    // 0049ff35  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049ff37  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ff39  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ff3c  e8bf9bfeff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049ff41  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ff44  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 0049ff46  01df                   +add edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049ff48  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049ff4d  eb90                   -jmp 0x49fedf
    goto L_0x0049fedf;
L_0x0049ff4f:
    // 0049ff4f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049ff51  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049ff53  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049ff55  e8a69bfeff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049ff5a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049ff5d  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0049ff60  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0049ff62  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049ff65  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049ff68  894324                 -mov dword ptr [ebx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049ff6b  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049ff6e  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0049ff71  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049ff74  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0049ff77  897124                 -mov dword ptr [ecx + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0049ff7a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049ff7d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049ff82  e956ffffff             -jmp 0x49fedd
    goto L_0x0049fedd;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49ff90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ff90);
    // 0049ff90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ff91  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049ff96  e8c12dfeff             -call 0x482d5c
    cpu.esp -= 4;
    sub_482d5c(app, cpu);
    if (cpu.terminate) return;
    // 0049ff9b  e81c000000             -call 0x49ffbc
    cpu.esp -= 4;
    sub_49ffbc(app, cpu);
    if (cpu.terminate) return;
    // 0049ffa0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffa1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49ffa4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ffa4);
    // 0049ffa4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ffa5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049ffaa  e80d000000             -call 0x49ffbc
    cpu.esp -= 4;
    sub_49ffbc(app, cpu);
    if (cpu.terminate) return;
    // 0049ffaf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49ffb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ffb4);
    // 0049ffb4  e8a32dfeff             -call 0x482d5c
    cpu.esp -= 4;
    sub_482d5c(app, cpu);
    if (cpu.terminate) return;
    // 0049ffb9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0049ffbc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ffbd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ffbf  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049ffc4  e867fcffff             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0049ffc9  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0049ffcc  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0049ffce  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0049ffd0  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ffd2  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049ffd5  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049ffda  e859fcffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0049ffdf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ffe1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffe2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ffbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ffbc);
    goto L_entry_0x0049ffbc;
    // 0049ffb4  e8a32dfeff             -call 0x482d5c
    cpu.esp -= 4;
    sub_482d5c(app, cpu);
    if (cpu.terminate) return;
    // 0049ffb9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x0049ffbc:
    // 0049ffbc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ffbd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ffbf  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049ffc4  e867fcffff             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0049ffc9  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0049ffcc  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0049ffce  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0049ffd0  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ffd2  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049ffd5  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 0049ffda  e859fcffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0049ffdf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ffe1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffe2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49ffe4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ffe4);
    // 0049ffe4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ffe5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ffe6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ffe7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ffe8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ffea  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0049fff0  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0049fff3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049fffa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fffc  bf501b5600             -mov edi, 0x561b50
    cpu.edi = 5643088 /*0x561b50*/;
    // 004a0001  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a0004  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a0006  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0008  e833fcffff             -call 0x49fc40
    cpu.esp -= 4;
    sub_49fc40(app, cpu);
    if (cpu.terminate) return;
    // 004a000d  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a000f  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a0012  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0014  39d1                   +cmp ecx, edx
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
    // 004a0016  7421                   -je 0x4a0039
    if (cpu.flags.zf)
    {
        goto L_0x004a0039;
    }
L_0x004a0018:
    // 004a0018  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004a001d  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a0020  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0022  e85077ffff             -call 0x497777
    cpu.esp -= 4;
    sub_497777(app, cpu);
    if (cpu.terminate) return;
    // 004a0027  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0029  7506                   -jne 0x4a0031
    if (!cpu.flags.zf)
    {
        goto L_0x004a0031;
    }
    // 004a002b  f6411808               +test byte ptr [ecx + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 004a002f  750f                   -jne 0x4a0040
    if (!cpu.flags.zf)
    {
        goto L_0x004a0040;
    }
L_0x004a0031:
    // 004a0031  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a0034  3b4f04                 +cmp ecx, dword ptr [edi + 4]
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
    // 004a0037  75df                   -jne 0x4a0018
    if (!cpu.flags.zf)
    {
        goto L_0x004a0018;
    }
L_0x004a0039:
    // 004a0039  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a003b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a003c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a003d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a003e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a003f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0040:
    // 004a0040  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0042  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0043  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0044  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0045  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0046  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0048(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0048);
    // 004a0048  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0049  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a004b  e894ffffff             -call 0x49ffe4
    cpu.esp -= 4;
    sub_49ffe4(app, cpu);
    if (cpu.terminate) return;
    // 004a0050  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0051  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0054(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0054);
    // 004a0054  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0055  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a0057  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 004a005c  e8cffbffff             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 004a0061  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0063  e810000000             -call 0x4a0078
    cpu.esp -= 4;
    sub_4a0078(app, cpu);
    if (cpu.terminate) return;
    // 004a0068  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a006a  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 004a006f  e8c4fbffff             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 004a0074  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0076  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0077  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0078(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0078);
    // 004a0078  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0079  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a007a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a007b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a007c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a007d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a007e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0081  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a0083  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0085  81e3000f0000           -and ebx, 0xf00
    cpu.ebx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004a008b  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 004a008e  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a0095  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0097  bb501b5600             -mov ebx, 0x561b50
    cpu.ebx = 5643088 /*0x561b50*/;
    // 004a009c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a009f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a00a1  837b1000               +cmp dword ptr [ebx + 0x10], 0
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
    // 004a00a5  0f8484000000           -je 0x4a012f
    if (cpu.flags.zf)
    {
        goto L_0x004a012f;
    }
    // 004a00ab  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a00ad  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a00af  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a00b1  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a00b4  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a00b7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a00b9:
    // 004a00b9  f6461808               +test byte ptr [esi + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 004a00bd  7422                   -je 0x4a00e1
    if (cpu.flags.zf)
    {
        goto L_0x004a00e1;
    }
    // 004a00bf  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a00c2  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a00c5  39f8                   +cmp eax, edi
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
    // 004a00c7  0f866b000000           -jbe 0x4a0138
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0138;
    }
L_0x004a00cd:
    // 004a00cd  a11c904d00             -mov eax, dword ptr [0x4d901c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */);
    // 004a00d2  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004a00d4  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a00d7  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a00da  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a00dc  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a00df  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a00e1:
    // 004a00e1  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a00e4  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a00e7  39ce                   +cmp esi, ecx
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
    // 004a00e9  75ce                   -jne 0x4a00b9
    if (!cpu.flags.zf)
    {
        goto L_0x004a00b9;
    }
    // 004a00eb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a00ed  7434                   -je 0x4a0123
    if (cpu.flags.zf)
    {
        goto L_0x004a0123;
    }
    // 004a00ef  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a00f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a00f3:
    // 004a00f3  40                     -inc eax
    (cpu.eax)++;
    // 004a00f4  8a5a04                 -mov bl, byte ptr [edx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a00f7  42                     -inc edx
    (cpu.edx)++;
    // 004a00f8  885c04ff               -mov byte ptr [esp + eax - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.eax * 1) = cpu.bl;
    // 004a00fc  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a00ff  7cf2                   -jl 0x4a00f3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a00f3;
    }
    // 004a0101  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004a0103  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
L_0x004a0107:
    // 004a0107  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a0109  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a010c  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a010f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0111  80cb08                 -or bl, 8
    cpu.bl |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004a0114  e86728feff             -call 0x482980
    cpu.esp -= 4;
    sub_482980(app, cpu);
    if (cpu.terminate) return;
    // 004a0119  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a011b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a011d  7429                   -je 0x4a0148
    if (cpu.flags.zf)
    {
        goto L_0x004a0148;
    }
    // 004a011f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0121  7540                   -jne 0x4a0163
    if (!cpu.flags.zf)
    {
        goto L_0x004a0163;
    }
L_0x004a0123:
    // 004a0123  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a0125:
    // 004a0125  83c410                 +add esp, 0x10
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
    // 004a0128  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0129  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a012a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a012b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a012c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a012d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a012e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a012f:
    // 004a012f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0131  e83a2dfeff             -call 0x482e70
    cpu.esp -= 4;
    sub_482e70(app, cpu);
    if (cpu.terminate) return;
    // 004a0136  ebed                   -jmp 0x4a0125
    goto L_0x004a0125;
L_0x004a0138:
    // 004a0138  75a7                   -jne 0x4a00e1
    if (!cpu.flags.zf)
    {
        goto L_0x004a00e1;
    }
    // 004a013a  a11c904d00             -mov eax, dword ptr [0x4d901c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083164) /* 0x4d901c */);
    // 004a013f  2b461c                 -sub eax, dword ptr [esi + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 004a0142  39d0                   +cmp eax, edx
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
    // 004a0144  7387                   -jae 0x4a00cd
    if (!cpu.flags.cf)
    {
        goto L_0x004a00cd;
    }
    // 004a0146  eb99                   -jmp 0x4a00e1
    goto L_0x004a00e1;
L_0x004a0148:
    // 004a0148  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a014a  e829ffffff             -call 0x4a0078
    cpu.esp -= 4;
    sub_4a0078(app, cpu);
    if (cpu.terminate) return;
    // 004a014f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0151  75b4                   -jne 0x4a0107
    if (!cpu.flags.zf)
    {
        goto L_0x004a0107;
    }
    // 004a0153  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0155  750c                   -jne 0x4a0163
    if (!cpu.flags.zf)
    {
        goto L_0x004a0163;
    }
    // 004a0157  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0159  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a015c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a015d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a015e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a015f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0160  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0161  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0162  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0163:
    // 004a0163  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a0166  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a0168  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a016b  e89099feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004a0170  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a0172  e8412cfeff             -call 0x482db8
    cpu.esp -= 4;
    sub_482db8(app, cpu);
    if (cpu.terminate) return;
    // 004a0177  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a017c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a017f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0180  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0181  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0182  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0183  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0184  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0185  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0188);
    // 004a0188  e807000000             -call 0x4a0194
    cpu.esp -= 4;
    sub_4a0194(app, cpu);
    if (cpu.terminate) return;
    // 004a018d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a018f  7402                   -je 0x4a0193
    if (cpu.flags.zf)
    {
        goto L_0x004a0193;
    }
    // 004a0191  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004a0193:
    // 004a0193  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0194(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0194);
    // 004a0194  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0195  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0196  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0197  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0198  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0199  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a019b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a019d  e842feffff             -call 0x49ffe4
    cpu.esp -= 4;
    sub_49ffe4(app, cpu);
    if (cpu.terminate) return;
    // 004a01a2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a01a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a01a6  7537                   -jne 0x4a01df
    if (!cpu.flags.zf)
    {
        goto L_0x004a01df;
    }
    // 004a01a8  8b1d08904d00           -mov ebx, dword ptr [0x4d9008]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */);
    // 004a01ae  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
L_0x004a01b1:
    // 004a01b1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a01b3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a01b5  e82afeffff             -call 0x49ffe4
    cpu.esp -= 4;
    sub_49ffe4(app, cpu);
    if (cpu.terminate) return;
    // 004a01ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a01bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a01be  7561                   -jne 0x4a0221
    if (!cpu.flags.zf)
    {
        goto L_0x004a0221;
    }
    // 004a01c0  81e3000f0000           -and ebx, 0xf00
    cpu.ebx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004a01c6  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 004a01c9  6bdb18                 -imul ebx, ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(24 /*0x18*/)));
    // 004a01cc  81c3501b5600           -add ebx, 0x561b50
    (cpu.ebx) += x86::reg32(x86::sreg32(5643088 /*0x561b50*/));
    // 004a01d2  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a01d5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a01d7  75d8                   -jne 0x4a01b1
    if (!cpu.flags.zf)
    {
        goto L_0x004a01b1;
    }
L_0x004a01d9:
    // 004a01d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a01da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a01db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a01dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a01dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a01de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a01df:
    // 004a01df  8a6018                 -mov ah, byte ptr [eax + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a01e2  80e4f7                 -and ah, 0xf7
    cpu.ah &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a01e5  886618                 -mov byte ptr [esi + 0x18], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ah;
    // 004a01e8  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004a01eb  7404                   -je 0x4a01f1
    if (cpu.flags.zf)
    {
        goto L_0x004a01f1;
    }
    // 004a01ed  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a01ef  ebe8                   -jmp 0x4a01d9
    goto L_0x004a01d9;
L_0x004a01f1:
    // 004a01f1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a01f3  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a01f6  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a01f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a01fb  e88027feff             -call 0x482980
    cpu.esp -= 4;
    sub_482980(app, cpu);
    if (cpu.terminate) return;
    // 004a0200  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a0202  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0204  7504                   -jne 0x4a020a
    if (!cpu.flags.zf)
    {
        goto L_0x004a020a;
    }
    // 004a0206  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0208  ebcf                   -jmp 0x4a01d9
    goto L_0x004a01d9;
L_0x004a020a:
    // 004a020a  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a020d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a020f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a0211  e8ea98feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004a0216  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0218  e87b2bfeff             -call 0x482d98
    cpu.esp -= 4;
    sub_482d98(app, cpu);
    if (cpu.terminate) return;
    // 004a021d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a021f  ebb8                   -jmp 0x4a01d9
    goto L_0x004a01d9;
L_0x004a0221:
    // 004a0221  806018f7               -and byte ptr [eax + 0x18], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a0225  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0227  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a022a  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a022d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a022f  e84c27feff             -call 0x482980
    cpu.esp -= 4;
    sub_482980(app, cpu);
    if (cpu.terminate) return;
    // 004a0234  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a0236  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a0239  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a023b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a023d  e8be98feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004a0242  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0244  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0245  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0246  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0247  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0248  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0249  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a024c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a024c);
    // 004a024c  e807000000             -call 0x4a0258
    cpu.esp -= 4;
    sub_4a0258(app, cpu);
    if (cpu.terminate) return;
    // 004a0251  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0253  7402                   -je 0x4a0257
    if (cpu.flags.zf)
    {
        goto L_0x004a0257;
    }
    // 004a0255  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004a0257:
    // 004a0257  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0258(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0258);
    // 004a0258  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0259  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a025a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a025b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a025c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a025e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a0260  e87ffdffff             -call 0x49ffe4
    cpu.esp -= 4;
    sub_49ffe4(app, cpu);
    if (cpu.terminate) return;
    // 004a0265  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0267  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0269  7528                   -jne 0x4a0293
    if (!cpu.flags.zf)
    {
        goto L_0x004a0293;
    }
    // 004a026b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a026d  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004a0273  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004a0276  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004a027d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a027f  ba501b5600             -mov edx, 0x561b50
    cpu.edx = 5643088 /*0x561b50*/;
    // 004a0284  8b54c210               -mov edx, dword ptr [edx + eax*8 + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */ + cpu.eax * 8);
    // 004a0288  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a028a  754b                   -jne 0x4a02d7
    if (!cpu.flags.zf)
    {
        goto L_0x004a02d7;
    }
    // 004a028c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a028e:
    // 004a028e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a028f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0290  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0291  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0292  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0293:
    // 004a0293  8a5018                 -mov dl, byte ptr [eax + 0x18]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a0296  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a0299  885018                 -mov byte ptr [eax + 0x18], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.dl;
    // 004a029c  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 004a029f  75ed                   -jne 0x4a028e
    if (!cpu.flags.zf)
    {
        goto L_0x004a028e;
    }
    // 004a02a1  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a02a4  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a02a7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a02a9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a02ab  e8d026feff             -call 0x482980
    cpu.esp -= 4;
    sub_482980(app, cpu);
    if (cpu.terminate) return;
    // 004a02b0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a02b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a02b4  7507                   -jne 0x4a02bd
    if (!cpu.flags.zf)
    {
        goto L_0x004a02bd;
    }
    // 004a02b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a02b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a02bd:
    // 004a02bd  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a02c0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a02c2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a02c4  e83798feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004a02c9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a02cb  e8c82afeff             -call 0x482d98
    cpu.esp -= 4;
    sub_482d98(app, cpu);
    if (cpu.terminate) return;
    // 004a02d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a02d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a02d7:
    // 004a02d7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a02d9  e806fdffff             -call 0x49ffe4
    cpu.esp -= 4;
    sub_49ffe4(app, cpu);
    if (cpu.terminate) return;
    // 004a02de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a02e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a02e2  74aa                   -je 0x4a028e
    if (cpu.flags.zf)
    {
        goto L_0x004a028e;
    }
    // 004a02e4  8a6018                 -mov ah, byte ptr [eax + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a02e7  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a02ea  80e4f7                 -and ah, 0xf7
    cpu.ah &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a02ed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a02ef  886618                 -mov byte ptr [esi + 0x18], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ah;
    // 004a02f2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a02f4  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a02f7  e88426feff             -call 0x482980
    cpu.esp -= 4;
    sub_482980(app, cpu);
    if (cpu.terminate) return;
    // 004a02fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a02fe  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a0301  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a0303  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a0305  e8f697feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004a030a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a030c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a030d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a030e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a030f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0310  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0320);
    // 004a0320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0321  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0322  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0325  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a0327  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004a032c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a032d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a0331  2eff150c454c00         -call dword ptr cs:[0x4c450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998412) /* 0x4c450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0338  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a033c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a033f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0340  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0341  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0344(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0344);
    // 004a0344  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0345  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0346  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0349  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a034b  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004a0350  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0351  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a0355  2eff150c454c00         -call dword ptr cs:[0x4c450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998412) /* 0x4c450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a035c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0360  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0363  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0364  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0365  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0368(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0368);
    // 004a0368  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0369  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a036a  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a036d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a036f  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004a0374  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0375  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a0379  2eff150c454c00         -call dword ptr cs:[0x4c450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998412) /* 0x4c450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0380  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a0384  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0387  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0388  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0389  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a038c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a038c);
    // 004a038c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a038d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a038e  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a0391  ba00006000             -mov edx, 0x600000
    cpu.edx = 6291456 /*0x600000*/;
    // 004a0396  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a0398  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a039d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a039e  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004a03a2  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a03a6  2eff150c454c00         -call dword ptr cs:[0x4c450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998412) /* 0x4c450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a03ad  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a03b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a03b2  683f000f00             -push 0xf003f
    app->getMemory<x86::reg32>(cpu.esp-4) = 983103 /*0xf003f*/;
    cpu.esp -= 4;
    // 004a03b7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a03b9  68c0f24c00             -push 0x4cf2c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042880 /*0x4cf2c0*/;
    cpu.esp -= 4;
    // 004a03be  6806000080             -push 0x80000006
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483654 /*0x80000006*/;
    cpu.esp -= 4;
    // 004a03c3  2eff1574434c00         -call dword ptr cs:[0x4c4374]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998004) /* 0x4c4374 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a03ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a03cc  740e                   -je 0x4a03dc
    if (cpu.flags.zf)
    {
        goto L_0x004a03dc;
    }
    // 004a03ce  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a03d2  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004a03d6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a03d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a03dc:
    // 004a03dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a03dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a03de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a03df  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a03e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a03e4  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a03e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a03e9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a03eb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a03ed  68d4f24c00             -push 0x4cf2d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042900 /*0x4cf2d4*/;
    cpu.esp -= 4;
    // 004a03f2  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a03f6  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004a03fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a03fc  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 004a0400  2eff1578434c00         -call dword ptr cs:[0x4c4378]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998008) /* 0x4c4378 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0407  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a040b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a040c  2eff156c434c00         -call dword ptr cs:[0x4c436c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4997996) /* 0x4c436c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0413  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0414  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0415  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0416  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a041a  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004a041e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a0421  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0422  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0423  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0430);
    // 004a0430  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0431  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0432  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0433  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0434  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a0436  8b0cc5f0a15900         -mov ecx, dword ptr [eax*8 + 0x59a1f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.eax * 8);
    // 004a043d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004a0442  bf80000000             -mov edi, 0x80
    cpu.edi = 128 /*0x80*/;
    // 004a0447  80790401               +cmp byte ptr [ecx + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a044b  7206                   -jb 0x4a0453
    if (cpu.flags.cf)
    {
        goto L_0x004a0453;
    }
    // 004a044d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a044f  668b7906               -mov di, word ptr [ecx + 6]
    cpu.di = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
L_0x004a0453:
    // 004a0453  e82c43feff             -call 0x484784
    cpu.esp -= 4;
    sub_484784(app, cpu);
    if (cpu.terminate) return;
    // 004a0458  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a045a  754d                   -jne 0x4a04a9
    if (!cpu.flags.zf)
    {
        goto L_0x004a04a9;
    }
    // 004a045c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a045e  7c49                   -jl 0x4a04a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a04a9;
    }
    // 004a0460  39fe                   +cmp esi, edi
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
    // 004a0462  7d45                   -jge 0x4a04a9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a04a9;
    }
    // 004a0464  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004a046b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a046d  80790402               +cmp byte ptr [ecx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a0471  7240                   -jb 0x4a04b3
    if (cpu.flags.cf)
    {
        goto L_0x004a04b3;
    }
    // 004a0473  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a0475  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
L_0x004a0478:
    // 004a0478  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a047a  742d                   -je 0x4a04a9
    if (cpu.flags.zf)
    {
        goto L_0x004a04a9;
    }
    // 004a047c  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0482  7534                   -jne 0x4a04b8
    if (!cpu.flags.zf)
    {
        goto L_0x004a04b8;
    }
    // 004a0484  e84f000000             -call 0x4a04d8
    cpu.esp -= 4;
    sub_4a04d8(app, cpu);
    if (cpu.terminate) return;
L_0x004a0489:
    // 004a0489  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a048b:
    // 004a048b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a048d  7c13                   -jl 0x4a04a2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a04a2;
    }
    // 004a048f  8a6104                 -mov ah, byte ptr [ecx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a0492  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004a0495  80fc02                 +cmp ah, 2
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
    // 004a0498  722e                   -jb 0x4a04c8
    if (cpu.flags.cf)
    {
        goto L_0x004a04c8;
    }
    // 004a049a  c7442e0c00000000       -mov dword ptr [esi + ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ebp * 1) = 0 /*0x0*/;
L_0x004a04a2:
    // 004a04a2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a04a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a04a9:
    // 004a04a9  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a04ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a04b3:
    // 004a04b3  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a04b6  ebc0                   -jmp 0x4a0478
    goto L_0x004a0478;
L_0x004a04b8:
    // 004a04b8  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a04bd  75cc                   -jne 0x4a048b
    if (!cpu.flags.zf)
    {
        goto L_0x004a048b;
    }
    // 004a04bf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a04c1  e8aa400000             -call 0x4a4570
    cpu.esp -= 4;
    sub_4a4570(app, cpu);
    if (cpu.terminate) return;
    // 004a04c6  ebc1                   -jmp 0x4a0489
    goto L_0x004a0489;
L_0x004a04c8:
    // 004a04c8  c744310800000000       -mov dword ptr [ecx + esi + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.esi * 1) = 0 /*0x0*/;
    // 004a04d0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a04d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a04d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a04d8);
    // 004a04d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a04d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a04da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a04db  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a04dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a04df  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a04e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a04e3  8a4307                 -mov al, byte ptr [ebx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 004a04e6  39c2                   +cmp edx, eax
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
    // 004a04e8  7c06                   -jl 0x4a04f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a04f0;
    }
    // 004a04ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a04ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a04f0:
    // 004a04f0  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a04f3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a04f5  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a04f8  42                     -inc edx
    (cpu.edx)++;
    // 004a04f9  e8a26afeff             -call 0x486fa0
    cpu.esp -= 4;
    sub_486fa0(app, cpu);
    if (cpu.terminate) return;
    // 004a04fe  83c144                 -add ecx, 0x44
    (cpu.ecx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004a0501  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0503  8a4307                 -mov al, byte ptr [ebx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 004a0506  39c2                   +cmp edx, eax
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
    // 004a0508  7ce6                   -jl 0x4a04f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a04f0;
    }
    // 004a050a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a050c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a050d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a050e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a050f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0510);
    // 004a0510  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0511  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0512  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0513  81ec080c0000           -sub esp, 0xc08
    (cpu.esp) -= x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a0519  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a051b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a051d  899c24000c0000         -mov dword ptr [esp + 0xc00], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = cpu.ebx;
    // 004a0524  898c24040c0000         -mov dword ptr [esp + 0xc04], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */) = cpu.ecx;
    // 004a052b  8a2538b84d00           -mov ah, byte ptr [0x4db838]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
    // 004a0531  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004a0536  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a0538  750f                   -jne 0x4a0549
    if (!cpu.flags.zf)
    {
        goto L_0x004a0549;
    }
    // 004a053a  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004a053f  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a0545  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0546  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0547  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0549:
    // 004a0549  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a054b  e83442feff             -call 0x484784
    cpu.esp -= 4;
    sub_484784(app, cpu);
    if (cpu.terminate) return;
    // 004a0550  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0552  0f8562000000           -jne 0x4a05ba
    if (!cpu.flags.zf)
    {
        goto L_0x004a05ba;
    }
    // 004a0558  83bc24000c000000       +cmp dword ptr [esp + 0xc00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0560  7458                   -je 0x4a05ba
    if (cpu.flags.zf)
    {
        goto L_0x004a05ba;
    }
    // 004a0562  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a0564  7454                   -je 0x4a05ba
    if (cpu.flags.zf)
    {
        goto L_0x004a05ba;
    }
    // 004a0566  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x004a056b:
    // 004a056b  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a056e  895404f4               -mov dword ptr [esp + eax - 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.eax * 1) = cpu.edx;
    // 004a0572  3d000c0000             +cmp eax, 0xc00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0577  75f2                   -jne 0x4a056b
    if (!cpu.flags.zf)
    {
        goto L_0x004a056b;
    }
    // 004a0579  8b34f5f0a15900         -mov esi, dword ptr [esi*8 + 0x59a1f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.esi * 8);
    // 004a0580  807e0401               +cmp byte ptr [esi + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a0584  7206                   -jb 0x4a058c
    if (cpu.flags.cf)
    {
        goto L_0x004a058c;
    }
    // 004a0586  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0588  668b5e06               -mov bx, word ptr [esi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
L_0x004a058c:
    // 004a058c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a058e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0590  7e19                   -jle 0x4a05ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a05ab;
    }
    // 004a0592  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0594:
    // 004a0594  807e0402               +cmp byte ptr [esi + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a0598  722f                   -jb 0x4a05c9
    if (cpu.flags.cf)
    {
        goto L_0x004a05c9;
    }
    // 004a059a  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004a059c  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
L_0x004a059f:
    // 004a059f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a05a1  742b                   -je 0x4a05ce
    if (cpu.flags.zf)
    {
        goto L_0x004a05ce;
    }
    // 004a05a3  41                     -inc ecx
    (cpu.ecx)++;
    // 004a05a4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a05a7  39d9                   +cmp ecx, ebx
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
    // 004a05a9  7ce9                   -jl 0x4a0594
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0594;
    }
L_0x004a05ab:
    // 004a05ab  b8f7ffffff             -mov eax, 0xfffffff7
    cpu.eax = 4294967287 /*0xfffffff7*/;
    // 004a05b0  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a05b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a05b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a05b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a05b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a05ba:
    // 004a05ba  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a05bf  81c4080c0000           +add esp, 0xc08
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3080 /*0xc08*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a05c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a05c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a05c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a05c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a05c9:
    // 004a05c9  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a05cc  ebd1                   -jmp 0x4a059f
    goto L_0x004a059f;
L_0x004a05ce:
    // 004a05ce  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a05d0  8b9424040c0000         -mov edx, dword ptr [esp + 0xc04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */);
    // 004a05d7  8b8424000c0000         -mov eax, dword ptr [esp + 0xc00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 004a05de  e8ad010000             -call 0x4a0790
    cpu.esp -= 4;
    sub_4a0790(app, cpu);
    if (cpu.terminate) return;
    // 004a05e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a05e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a05e7  7c29                   -jl 0x4a0612
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0612;
    }
    // 004a05e9  8a5e04                 -mov bl, byte ptr [esi + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a05ec  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004a05f3  80fb02                 +cmp bl, 2
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a05f6  722b                   -jb 0x4a0623
    if (cpu.flags.cf)
    {
        goto L_0x004a0623;
    }
    // 004a05f8  8b9c24000c0000         -mov ebx, dword ptr [esp + 0xc00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 004a05ff  895c070c               -mov dword ptr [edi + eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.ebx;
    // 004a0603  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0605  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 004a0608  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a060e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a060f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0610  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0611  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0612:
    // 004a0612  c74500ffffffff         -mov dword ptr [ebp], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp) = 4294967295 /*0xffffffff*/;
    // 004a0619  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a061f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0620  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0621  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0622  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0623:
    // 004a0623  8b9c24000c0000         -mov ebx, dword ptr [esp + 0xc00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 004a062a  895c0608               -mov dword ptr [esi + eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.ebx;
    // 004a062e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0630  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 004a0633  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a0639  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a063a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a063b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a063c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0640);
    // 004a0640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0642  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0643  81ec000c0000           -sub esp, 0xc00
    (cpu.esp) -= x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 004a0649  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a064b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a064d  baf09b5900             -mov edx, 0x599bf0
    cpu.edx = 5872624 /*0x599bf0*/;
    // 004a0652  8d9a00060000           -lea ebx, [edx + 0x600]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1536) /* 0x600 */);
L_0x004a0658:
    // 004a0658  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 004a065b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a065e  39f0                   +cmp eax, esi
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
    // 004a0660  7511                   -jne 0x4a0673
    if (!cpu.flags.zf)
    {
        goto L_0x004a0673;
    }
    // 004a0662  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a0664  668b4208               -mov ax, word ptr [edx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a0668  39c8                   +cmp eax, ecx
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
    // 004a066a  7507                   -jne 0x4a0673
    if (!cpu.flags.zf)
    {
        goto L_0x004a0673;
    }
    // 004a066c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a066e  e83d76feff             -call 0x487cb0
    cpu.esp -= 4;
    sub_487cb0(app, cpu);
    if (cpu.terminate) return;
L_0x004a0673:
    // 004a0673  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004a0676  39da                   +cmp edx, ebx
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
    // 004a0678  75de                   -jne 0x4a0658
    if (!cpu.flags.zf)
    {
        goto L_0x004a0658;
    }
    // 004a067a  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a067c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x004a0681:
    // 004a0681  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a0684  895c14f4               -mov dword ptr [esp + edx - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.edx * 1) = cpu.ebx;
    // 004a0688  81fa000c0000           +cmp edx, 0xc00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a068e  75f1                   -jne 0x4a0681
    if (!cpu.flags.zf)
    {
        goto L_0x004a0681;
    }
    // 004a0690  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a0692  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0694  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0696  e895fdffff             -call 0x4a0430
    cpu.esp -= 4;
    sub_4a0430(app, cpu);
    if (cpu.terminate) return;
    // 004a069b  81c4000c0000           -add esp, 0xc00
    (cpu.esp) += x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 004a06a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a06b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a06b0);
    // 004a06b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a06b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a06b2  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a06b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a06b7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a06b9  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a06bd  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004a06c2  8a6005                 -mov ah, byte ptr [eax + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004a06c5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a06c8  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a06ca  0f856a000000           -jne 0x4a073a
    if (!cpu.flags.zf)
    {
        goto L_0x004a073a;
    }
    // 004a06d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a06d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a06d2  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a06d5  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a06d8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a06da  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a06dc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a06de  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004a06e1:
    // 004a06e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a06e3  8a4107                 -mov al, byte ptr [ecx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 004a06e6  39c6                   +cmp esi, eax
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
    // 004a06e8  7d5d                   -jge 0x4a0747
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0747;
    }
    // 004a06ea  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a06ed  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a06ef  83781800               +cmp dword ptr [eax + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a06f3  7406                   -je 0x4a06fb
    if (cpu.flags.zf)
    {
        goto L_0x004a06fb;
    }
    // 004a06f5  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a06f8  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004a06fb:
    // 004a06fb  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 004a06ff  7406                   -je 0x4a0707
    if (cpu.flags.zf)
    {
        goto L_0x004a0707;
    }
    // 004a0701  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a0704  01501c                 -add dword ptr [eax + 0x1c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004a0707:
    // 004a0707  83782000               +cmp dword ptr [eax + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a070b  7406                   -je 0x4a0713
    if (cpu.flags.zf)
    {
        goto L_0x004a0713;
    }
    // 004a070d  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a0710  015020                 -add dword ptr [eax + 0x20], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004a0713:
    // 004a0713  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a0716  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a0719  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a071c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a071e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a0720  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004a0723  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a0727  e8246afeff             -call 0x487150
    cpu.esp -= 4;
    sub_487150(app, cpu);
    if (cpu.terminate) return;
    // 004a072c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a0730  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0732  7c0e                   -jl 0x4a0742
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0742;
    }
    // 004a0734  83c744                 +add edi, 0x44
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0737  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a0738  eba7                   -jmp 0x4a06e1
    goto L_0x004a06e1;
L_0x004a073a:
    // 004a073a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a073c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a073f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0740  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0741  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0742:
    // 004a0742  4e                     -dec esi
    (cpu.esi)--;
    // 004a0743  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004a0747:
    // 004a0747  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a074b  83feff                 +cmp esi, -1
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
    // 004a074e  7e30                   -jle 0x4a0780
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0780;
    }
    // 004a0750  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0752  7c20                   -jl 0x4a0774
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0774;
    }
    // 004a0754  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0756  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004a0759  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a075b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a075d  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
L_0x004a0760:
    // 004a0760  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a0763  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0765  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a0768  83c244                 -add edx, 0x44
    (cpu.edx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004a076b  e83068feff             -call 0x486fa0
    cpu.esp -= 4;
    sub_486fa0(app, cpu);
    if (cpu.terminate) return;
    // 004a0770  39f2                   +cmp edx, esi
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
    // 004a0772  7eec                   -jle 0x4a0760
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0760;
    }
L_0x004a0774:
    // 004a0774  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a0778  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0779  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a077a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a077d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a077e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a077f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0780:
    // 004a0780  c6410501               -mov byte ptr [ecx + 5], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 1 /*0x1*/;
    // 004a0784  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a0788  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0789  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a078a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a078d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a078e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a078f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0790);
    // 004a0790  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0796  0f8414ffffff           -je 0x4a06b0
    if (cpu.flags.zf)
    {
        return sub_4a06b0(app, cpu);
    }
    // 004a079c  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a07a1  0f841d3d0000           -je 0x4a44c4
    if (cpu.flags.zf)
    {
        return sub_4a44c4(app, cpu);
    }
    // 004a07a7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a07ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a07b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a07b0);
    // 004a07b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a07b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a07b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a07b3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a07b6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a07b8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a07bb  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a07bd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a07bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a07c1  7446                   -je 0x4a0809
    if (cpu.flags.zf)
    {
        goto L_0x004a0809;
    }
    // 004a07c3  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a07c9  754c                   -jne 0x4a0817
    if (!cpu.flags.zf)
    {
        goto L_0x004a0817;
    }
    // 004a07cb  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a07cf  754d                   -jne 0x4a081e
    if (!cpu.flags.zf)
    {
        goto L_0x004a081e;
    }
    // 004a07d1  83f9ff                 +cmp ecx, -1
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
    // 004a07d4  754f                   -jne 0x4a0825
    if (!cpu.flags.zf)
    {
        goto L_0x004a0825;
    }
    // 004a07d6  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
L_0x004a07db:
    // 004a07db  83fbff                 +cmp ebx, -1
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
    // 004a07de  7550                   -jne 0x4a0830
    if (!cpu.flags.zf)
    {
        goto L_0x004a0830;
    }
    // 004a07e0  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
L_0x004a07e5:
    // 004a07e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a07e7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a07e9:
    // 004a07e9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a07eb  8a4f07                 -mov cl, byte ptr [edi + 7]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 004a07ee  39c8                   +cmp eax, ecx
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
    // 004a07f0  0f8d60000000           -jge 0x4a0856
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0856;
    }
    // 004a07f6  8b770c                 -mov esi, dword ptr [edi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a07f9  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a07fb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a07fd  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a07ff  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0801  7d38                   -jge 0x4a083b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a083b;
    }
L_0x004a0803:
    // 004a0803  83c244                 +add edx, 0x44
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0806  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a0807  ebe0                   -jmp 0x4a07e9
    goto L_0x004a07e9;
L_0x004a0809:
    // 004a0809  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004a080e:
    // 004a080e  83c410                 +add esp, 0x10
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
    // 004a0811  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0812  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0813  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0814  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0817:
    // 004a0817  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004a081c  ebf0                   -jmp 0x4a080e
    goto L_0x004a080e;
L_0x004a081e:
    // 004a081e  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 004a0823  ebe9                   -jmp 0x4a080e
    goto L_0x004a080e;
L_0x004a0825:
    // 004a0825  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a0827  7ce0                   -jl 0x4a0809
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0809;
    }
    // 004a0829  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a082c  7ead                   -jle 0x4a07db
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a07db;
    }
    // 004a082e  ebd9                   -jmp 0x4a0809
    goto L_0x004a0809;
L_0x004a0830:
    // 004a0830  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0832  7cd5                   -jl 0x4a0809
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0809;
    }
    // 004a0834  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0837  7eac                   -jle 0x4a07e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a07e5;
    }
    // 004a0839  ebce                   -jmp 0x4a0809
    goto L_0x004a0809;
L_0x004a083b:
    // 004a083b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a083d  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a0840  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0842  7fbf                   -jg 0x4a0803
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a0803;
    }
    // 004a0844  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0846  8a4e02                 -mov cl, byte ptr [esi + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a0849  39cb                   +cmp ebx, ecx
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
    // 004a084b  7cb6                   -jl 0x4a0803
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0803;
    }
    // 004a084d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a084f  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a0852  39cb                   +cmp ebx, ecx
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
    // 004a0854  7fad                   -jg 0x4a0803
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a0803;
    }
L_0x004a0856:
    // 004a0856  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0858  8a5707                 -mov dl, byte ptr [edi + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 004a085b  39d0                   +cmp eax, edx
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
    // 004a085d  0f8482020000           -je 0x4a0ae5
    if (cpu.flags.zf)
    {
        goto L_0x004a0ae5;
    }
    // 004a0863  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0867  83f8ff                 +cmp eax, -1
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
    // 004a086a  0f8583020000           -jne 0x4a0af3
    if (!cpu.flags.zf)
    {
        goto L_0x004a0af3;
    }
    // 004a0870  c74424247f000000       -mov dword ptr [esp + 0x24], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 127 /*0x7f*/;
L_0x004a0878:
    // 004a0878  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a087c  83faff                 +cmp edx, -1
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
    // 004a087f  0f858d020000           -jne 0x4a0b12
    if (!cpu.flags.zf)
    {
        goto L_0x004a0b12;
    }
    // 004a0885  c744242040000000       -mov dword ptr [esp + 0x20], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 64 /*0x40*/;
L_0x004a088d:
    // 004a088d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a088f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0891  8a570a                 -mov dl, byte ptr [edi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 004a0894  8a4610                 -mov al, byte ptr [esi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a0897  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0899  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a089c  8a5611                 -mov dl, byte ptr [esi + 0x11]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(17) /* 0x11 */);
    // 004a089f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a08a3  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a08a5  7415                   -je 0x4a08bc
    if (cpu.flags.zf)
    {
        goto L_0x004a08bc;
    }
    // 004a08a7  8b460e                 -mov eax, dword ptr [esi + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004a08aa  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a08ad  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a08b1  e82a160100             -call 0x4b1ee0
    cpu.esp -= 4;
    sub_4b1ee0(app, cpu);
    if (cpu.terminate) return;
    // 004a08b6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a08b8  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004a08bc:
    // 004a08bc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a08c0  83f87f                 +cmp eax, 0x7f
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
    // 004a08c3  0f8e68020000           -jle 0x4a0b31
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0b31;
    }
    // 004a08c9  c744240c7f000000       -mov dword ptr [esp + 0xc], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 127 /*0x7f*/;
L_0x004a08d1:
    // 004a08d1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a08d5  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004a08d9  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a08dc  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a08e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a08e2  0f8c5c020000           -jl 0x4a0b44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0b44;
    }
    // 004a08e8  83f87f                 +cmp eax, 0x7f
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
    // 004a08eb  7e08                   -jle 0x4a08f5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a08f5;
    }
    // 004a08ed  c74424207f000000       -mov dword ptr [esp + 0x20], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 127 /*0x7f*/;
L_0x004a08f5:
    // 004a08f5  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a08f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a08fa  740b                   -je 0x4a0907
    if (cpu.flags.zf)
    {
        goto L_0x004a0907;
    }
    // 004a08fc  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004a0900  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a0903  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x004a0907:
    // 004a0907  837c2428ff             +cmp dword ptr [esp + 0x28], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a090c  7509                   -jne 0x4a0917
    if (!cpu.flags.zf)
    {
        goto L_0x004a0917;
    }
    // 004a090e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0910  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a0913  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x004a0917:
    // 004a0917  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004a091a  8b5612                 -mov edx, dword ptr [esi + 0x12]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 004a091d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a0920  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a0923  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0925  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0927  8a5609                 -mov dl, byte ptr [esi + 9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 004a092a  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a092c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a0930  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004a0937  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0939  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a093c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a093e  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0942  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a0945  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0947  668b5616               -mov dx, word ptr [esi + 0x16]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 004a094b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a094f  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004a0952  7412                   -je 0x4a0966
    if (cpu.flags.zf)
    {
        goto L_0x004a0966;
    }
    // 004a0954  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a0957  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a095a  e881150100             -call 0x4b1ee0
    cpu.esp -= 4;
    sub_4b1ee0(app, cpu);
    if (cpu.terminate) return;
    // 004a095f  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a0962  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x004a0966:
    // 004a0966  e865050000             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 004a096b  b950a25900             -mov ecx, 0x59a250
    cpu.ecx = 5874256 /*0x59a250*/;
    // 004a0970  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a0973  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0975  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0977  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a097a  8a560f                 -mov dl, byte ptr [esi + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */);
    // 004a097d  e8aa050000             -call 0x4a0f2c
    cpu.esp -= 4;
    sub_4a0f2c(app, cpu);
    if (cpu.terminate) return;
    // 004a0982  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a0984  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a0988  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a098a  0f8cbf010000           -jl 0x4a0b4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0b4f;
    }
    // 004a0990  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a0993  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0995  bbf09b5900             -mov ebx, 0x599bf0
    cpu.ebx = 5872624 /*0x599bf0*/;
    // 004a099a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a099d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a099f  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a09a2  89434c                 -mov dword ptr [ebx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004a09a5  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a09a8  894350                 -mov dword ptr [ebx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004a09ab  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a09ae  894354                 -mov dword ptr [ebx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 004a09b1  8a4706                 -mov al, byte ptr [edi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004a09b4  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a09b7  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a09bb  c7431800000000         -mov dword ptr [ebx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a09c2  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a09c5  894320                 -mov dword ptr [ebx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a09c8  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a09cb  8b560f                 -mov edx, dword ptr [esi + 0xf]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(15) /* 0xf */);
    // 004a09ce  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a09d1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a09d4  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a09d7  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004a09dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a09de  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a09e1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a09e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a09e5  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a09e8  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a09eb  e8f0140100             -call 0x4b1ee0
    cpu.esp -= 4;
    sub_4b1ee0(app, cpu);
    if (cpu.terminate) return;
    // 004a09f0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a09f2  39ca                   +cmp edx, ecx
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
    // 004a09f4  0f8e65010000           -jle 0x4a0b5f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0b5f;
    }
    // 004a09fa  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004a09fc:
    // 004a09fc  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a09ff  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
    // 004a0a04  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0a06  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0a09  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0a0b  884330                 -mov byte ptr [ebx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 004a0a0e  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a0a12  884332                 -mov byte ptr [ebx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 004a0a15  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a0a19  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004a0a1c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0a20  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004a0a24  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0a26  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004a0a29  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 004a0a2c  66894342               -mov word ptr [ebx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 004a0a30  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a0a34  884333                 -mov byte ptr [ebx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 004a0a37  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0a3b  e8b0be0000             -call 0x4ac8f0
    cpu.esp -= 4;
    sub_4ac8f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0a40  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004a0a43  894348                 -mov dword ptr [ebx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004a0a46  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004a0a49  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004a0a50  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a0a52  89432c                 -mov dword ptr [ebx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a0a55  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004a0a58  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a0a5b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a0a5e  c6433500               -mov byte ptr [ebx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 004a0a62  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a0a65  8a460a                 -mov al, byte ptr [esi + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004a0a68  884334                 -mov byte ptr [ebx + 0x34], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(52) /* 0x34 */) = cpu.al;
    // 004a0a6b  8a460b                 -mov al, byte ptr [esi + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(11) /* 0xb */);
    // 004a0a6e  884336                 -mov byte ptr [ebx + 0x36], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(54) /* 0x36 */) = cpu.al;
    // 004a0a71  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004a0a74  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0a76  88430a                 -mov byte ptr [ebx + 0xa], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.al;
    // 004a0a79  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0a7d  c6430b0f               -mov byte ptr [ebx + 0xb], 0xf
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = 15 /*0xf*/;
    // 004a0a81  e82a3d0000             -call 0x4a47b0
    cpu.esp -= 4;
    sub_4a47b0(app, cpu);
    if (cpu.terminate) return;
    // 004a0a86  8b0de49b5900           -mov ecx, dword ptr [0x599be4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5872612) /* 0x599be4 */);
    // 004a0a8c  8a560e                 -mov dl, byte ptr [esi + 0xe]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004a0a8f  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a0a92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0a94  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0a97  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0a99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0a9a  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a0a9d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a0aa0  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0aa4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0aa5  8b432e                 -mov eax, dword ptr [ebx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(46) /* 0x2e */);
    // 004a0aa8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0aaa  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a0aad  8a5706                 -mov dl, byte ptr [edi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004a0ab0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0ab1  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a0ab5  8d4628                 -lea eax, [esi + 0x28]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004a0ab8  e8af66feff             -call 0x48716c
    cpu.esp -= 4;
    sub_48716c(app, cpu);
    if (cpu.terminate) return;
    // 004a0abd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a0abf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0ac1  7d0f                   -jge 0x4a0ad2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0ad2;
    }
    // 004a0ac3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0ac7  e81c070000             -call 0x4a11e8
    cpu.esp -= 4;
    sub_4a11e8(app, cpu);
    if (cpu.terminate) return;
    // 004a0acc  891550a25900           -mov dword ptr [0x59a250], edx
    app->getMemory<x86::reg32>(x86::reg32(5874256) /* 0x59a250 */) = cpu.edx;
L_0x004a0ad2:
    // 004a0ad2  e80d040000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004a0ad7  a150a25900             -mov eax, dword ptr [0x59a250]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874256) /* 0x59a250 */);
    // 004a0adc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0adf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ae0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ae1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ae2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0ae5:
    // 004a0ae5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a0aea  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0aed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0aee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0aef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0af0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0af3:
    // 004a0af3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0af5  0f8c0efdffff           -jl 0x4a0809
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0809;
    }
    // 004a0afb  83f87f                 +cmp eax, 0x7f
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
    // 004a0afe  0f8e74fdffff           -jle 0x4a0878
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0878;
    }
    // 004a0b04  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a0b09  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0b0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b0f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0b12:
    // 004a0b12  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0b14  0f8ceffcffff           -jl 0x4a0809
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0809;
    }
    // 004a0b1a  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0b1d  0f8e6afdffff           -jle 0x4a088d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a088d;
    }
    // 004a0b23  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a0b28  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0b2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b2e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0b31:
    // 004a0b31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0b33  0f8d98fdffff           -jge 0x4a08d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a08d1;
    }
    // 004a0b39  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a0b3b  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a0b3f  e98dfdffff             -jmp 0x4a08d1
    goto L_0x004a08d1;
L_0x004a0b44:
    // 004a0b44  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a0b46  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004a0b4a  e9a6fdffff             -jmp 0x4a08f5
    goto L_0x004a08f5;
L_0x004a0b4f:
    // 004a0b4f  e890030000             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004a0b54  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0b56  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0b59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b5c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0b5f:
    // 004a0b5f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0b61  0f8d95feffff           -jge 0x4a09fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a09fc;
    }
    // 004a0b67  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a0b69  e98efeffff             -jmp 0x4a09fc
    goto L_0x004a09fc;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0b70);
    // 004a0b70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0b72  7419                   -je 0x4a0b8d
    if (cpu.flags.zf)
    {
        goto L_0x004a0b8d;
    }
    // 004a0b74  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0b7a  7417                   -je 0x4a0b93
    if (cpu.flags.zf)
    {
        goto L_0x004a0b93;
    }
    // 004a0b7c  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a0b81  0f845d350000           -je 0x4a40e4
    if (cpu.flags.zf)
    {
        return sub_4a40e4(app, cpu);
    }
    // 004a0b87  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004a0b8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0b8d:
    // 004a0b8d  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a0b92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0b93:
    // 004a0b93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0b94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0b95  8b4a06                 -mov ecx, dword ptr [edx + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004a0b98  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a0b9b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0b9c  8b4a05                 -mov ecx, dword ptr [edx + 5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a0b9f  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a0ba2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0ba3  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a0ba6  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a0ba9  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a0bac  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a0baf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0bb0  8b4a03                 -mov ecx, dword ptr [edx + 3]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a0bb3  8b5201                 -mov edx, dword ptr [edx + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a0bb6  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a0bb9  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0bbc  e8effbffff             -call 0x4a07b0
    cpu.esp -= 4;
    sub_4a07b0(app, cpu);
    if (cpu.terminate) return;
    // 004a0bc1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0bc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0bc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0bd0);
    // 004a0bd0  a354a25900             -mov dword ptr [0x59a254], eax
    app->getMemory<x86::reg32>(x86::reg32(5874260) /* 0x59a254 */) = cpu.eax;
    // 004a0bd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0bd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0bd8);
    // 004a0bd8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0bd9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0bda  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a0bdc  833d6cb84d0000         +cmp dword ptr [0x4db86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093484) /* 0x4db86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0be3  741c                   -je 0x4a0c01
    if (cpu.flags.zf)
    {
        goto L_0x004a0c01;
    }
L_0x004a0be5:
    // 004a0be5  833d54a2590000         +cmp dword ptr [0x59a254], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5874260) /* 0x59a254 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0bec  741f                   -je 0x4a0c0d
    if (cpu.flags.zf)
    {
        goto L_0x004a0c0d;
    }
    // 004a0bee  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a0bf0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0bf2  893d68b84d00           -mov dword ptr [0x4db868], edi
    app->getMemory<x86::reg32>(x86::reg32(5093480) /* 0x4db868 */) = cpu.edi;
    // 004a0bf8  ff1554a25900           -call dword ptr [0x59a254]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5874260) /* 0x59a254 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0bfe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0bff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0c01:
    // 004a0c01  e87676feff             -call 0x48827c
    cpu.esp -= 4;
    sub_48827c(app, cpu);
    if (cpu.terminate) return;
    // 004a0c06  a36cb84d00             -mov dword ptr [0x4db86c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093484) /* 0x4db86c */) = cpu.eax;
    // 004a0c0b  ebd8                   -jmp 0x4a0be5
    goto L_0x004a0be5;
L_0x004a0c0d:
    // 004a0c0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0c0e  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a0c13  8b156cb84d00           -mov edx, dword ptr [0x4db86c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093484) /* 0x4db86c */);
    // 004a0c19  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0c1b  893568b84d00           -mov dword ptr [0x4db868], esi
    app->getMemory<x86::reg32>(x86::reg32(5093480) /* 0x4db868 */) = cpu.esi;
    // 004a0c21  e86a76feff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 004a0c26  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0c2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0c2a);
    // 004a0c2a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0c2c  e8ef16feff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 004a0c31  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0c33  8b2de8894d00           -mov ebp, dword ptr [0x4d89e8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004a0c39  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0c3b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0c3e  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0c40  e8c773feff             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 004a0c45  e979000000             -jmp 0x4a0cc3
    return sub_4a0cc3(app, cpu);
}

/* align: skip  */
void Application::sub_4a0c4a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0c4a);
    // 004a0c4a  8b156cb84d00           -mov edx, dword ptr [0x4db86c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093484) /* 0x4db86c */);
    // 004a0c50  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0c52  0f8481000000           -je 0x4a0cd9
    if (cpu.flags.zf)
    {
        return sub_4a0cd9(app, cpu);
    }
    // 004a0c58  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0c5a  e86d76feff             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 004a0c5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0c68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0c68);
    // 004a0c68  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0c69  8b156cb84d00           -mov edx, dword ptr [0x4db86c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093484) /* 0x4db86c */);
    // 004a0c6f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0c71  7502                   -jne 0x4a0c75
    if (!cpu.flags.zf)
    {
        goto L_0x004a0c75;
    }
    // 004a0c73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0c75:
    // 004a0c75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0c76  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a0c7b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0c7d  890d68b84d00           -mov dword ptr [0x4db868], ecx
    app->getMemory<x86::reg32>(x86::reg32(5093480) /* 0x4db868 */) = cpu.ecx;
    // 004a0c83  e80876feff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 004a0c88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c89  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0c8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0c8c);
    // 004a0c8c  a168b84d00             -mov eax, dword ptr [0x4db868]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093480) /* 0x4db868 */);
    // 004a0c91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0c94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0c94);
    // 004a0c94  833d54a2590000         +cmp dword ptr [0x59a254], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5874260) /* 0x59a254 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0c9b  7409                   -je 0x4a0ca6
    if (cpu.flags.zf)
    {
        goto L_0x004a0ca6;
    }
    // 004a0c9d  833de8894d0000         +cmp dword ptr [0x4d89e8], 0
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
    // 004a0ca4  7501                   -jne 0x4a0ca7
    if (!cpu.flags.zf)
    {
        goto L_0x004a0ca7;
    }
L_0x004a0ca6:
    // 004a0ca6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0ca7:
    // 004a0ca7  e82cffffff             -call 0x4a0bd8
    cpu.esp -= 4;
    sub_4a0bd8(app, cpu);
    if (cpu.terminate) return;
    // 004a0cac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0cad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0cae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0caf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0cb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0cb1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0cb3  e8a073feff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 004a0cb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0cba  748e                   -je 0x4a0c4a
    if (cpu.flags.zf)
    {
        return sub_4a0c4a(app, cpu);
    }
    // 004a0cbc  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004a0cc1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0cc3  3b0d6cb84d00           +cmp ecx, dword ptr [0x4db86c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5093484) /* 0x4db86c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0cc9  740e                   -je 0x4a0cd9
    if (cpu.flags.zf)
    {
        goto L_0x004a0cd9;
    }
    // 004a0ccb  8b3d68b84d00           -mov edi, dword ptr [0x4db868]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093480) /* 0x4db868 */);
    // 004a0cd1  39f9                   +cmp ecx, edi
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
    // 004a0cd3  0f8451ffffff           -je 0x4a0c2a
    if (cpu.flags.zf)
    {
        return sub_4a0c2a(app, cpu);
    }
L_0x004a0cd9:
    // 004a0cd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0cd9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0cd9);
    goto L_entry_0x004a0cd9;
    // 004a0c94  833d54a2590000         +cmp dword ptr [0x59a254], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5874260) /* 0x59a254 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0c9b  7409                   -je 0x4a0ca6
    if (cpu.flags.zf)
    {
        goto L_0x004a0ca6;
    }
    // 004a0c9d  833de8894d0000         +cmp dword ptr [0x4d89e8], 0
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
    // 004a0ca4  7501                   -jne 0x4a0ca7
    if (!cpu.flags.zf)
    {
        goto L_0x004a0ca7;
    }
L_0x004a0ca6:
    // 004a0ca6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0ca7:
    // 004a0ca7  e82cffffff             -call 0x4a0bd8
    cpu.esp -= 4;
    sub_4a0bd8(app, cpu);
    if (cpu.terminate) return;
    // 004a0cac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0cad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0cae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0caf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0cb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0cb1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0cb3  e8a073feff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 004a0cb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0cba  748e                   -je 0x4a0c4a
    if (cpu.flags.zf)
    {
        return sub_4a0c4a(app, cpu);
    }
    // 004a0cbc  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004a0cc1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0cc3  3b0d6cb84d00           +cmp ecx, dword ptr [0x4db86c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5093484) /* 0x4db86c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0cc9  740e                   -je 0x4a0cd9
    if (cpu.flags.zf)
    {
        goto L_0x004a0cd9;
    }
    // 004a0ccb  8b3d68b84d00           -mov edi, dword ptr [0x4db868]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093480) /* 0x4db868 */);
    // 004a0cd1  39f9                   +cmp ecx, edi
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
    // 004a0cd3  0f8451ffffff           -je 0x4a0c2a
    if (cpu.flags.zf)
    {
        return sub_4a0c2a(app, cpu);
    }
L_0x004a0cd9:
L_entry_0x004a0cd9:
    // 004a0cd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0cc3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0cc3);
    goto L_entry_0x004a0cc3;
    // 004a0c94  833d54a2590000         +cmp dword ptr [0x59a254], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5874260) /* 0x59a254 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0c9b  7409                   -je 0x4a0ca6
    if (cpu.flags.zf)
    {
        goto L_0x004a0ca6;
    }
    // 004a0c9d  833de8894d0000         +cmp dword ptr [0x4d89e8], 0
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
    // 004a0ca4  7501                   -jne 0x4a0ca7
    if (!cpu.flags.zf)
    {
        goto L_0x004a0ca7;
    }
L_0x004a0ca6:
    // 004a0ca6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0ca7:
    // 004a0ca7  e82cffffff             -call 0x4a0bd8
    cpu.esp -= 4;
    sub_4a0bd8(app, cpu);
    if (cpu.terminate) return;
    // 004a0cac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0cad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0cae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0caf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0cb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0cb1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0cb3  e8a073feff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 004a0cb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0cba  748e                   -je 0x4a0c4a
    if (cpu.flags.zf)
    {
        return sub_4a0c4a(app, cpu);
    }
    // 004a0cbc  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004a0cc1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x004a0cc3:
    // 004a0cc3  3b0d6cb84d00           +cmp ecx, dword ptr [0x4db86c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5093484) /* 0x4db86c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0cc9  740e                   -je 0x4a0cd9
    if (cpu.flags.zf)
    {
        goto L_0x004a0cd9;
    }
    // 004a0ccb  8b3d68b84d00           -mov edi, dword ptr [0x4db868]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093480) /* 0x4db868 */);
    // 004a0cd1  39f9                   +cmp ecx, edi
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
    // 004a0cd3  0f8451ffffff           -je 0x4a0c2a
    if (cpu.flags.zf)
    {
        return sub_4a0c2a(app, cpu);
    }
L_0x004a0cd9:
    // 004a0cd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0cac);
    goto L_entry_0x004a0cac;
    // 004a0c94  833d54a2590000         +cmp dword ptr [0x59a254], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5874260) /* 0x59a254 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0c9b  7409                   -je 0x4a0ca6
    if (cpu.flags.zf)
    {
        goto L_0x004a0ca6;
    }
    // 004a0c9d  833de8894d0000         +cmp dword ptr [0x4d89e8], 0
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
    // 004a0ca4  7501                   -jne 0x4a0ca7
    if (!cpu.flags.zf)
    {
        goto L_0x004a0ca7;
    }
L_0x004a0ca6:
    // 004a0ca6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0ca7:
    // 004a0ca7  e82cffffff             -call 0x4a0bd8
    cpu.esp -= 4;
    sub_4a0bd8(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004a0cac:
    // 004a0cac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0cad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0cae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0caf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0cb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0cb1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0cb3  e8a073feff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 004a0cb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0cba  748e                   -je 0x4a0c4a
    if (cpu.flags.zf)
    {
        return sub_4a0c4a(app, cpu);
    }
    // 004a0cbc  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004a0cc1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0cc3  3b0d6cb84d00           +cmp ecx, dword ptr [0x4db86c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5093484) /* 0x4db86c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0cc9  740e                   -je 0x4a0cd9
    if (cpu.flags.zf)
    {
        goto L_0x004a0cd9;
    }
    // 004a0ccb  8b3d68b84d00           -mov edi, dword ptr [0x4db868]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093480) /* 0x4db868 */);
    // 004a0cd1  39f9                   +cmp ecx, edi
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
    // 004a0cd3  0f8451ffffff           -je 0x4a0c2a
    if (cpu.flags.zf)
    {
        return sub_4a0c2a(app, cpu);
    }
L_0x004a0cd9:
    // 004a0cd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a0ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0ce0);
    // 004a0ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0ce2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0ce3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0ce4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0ce5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0ce6  ff0578b84d00           -inc dword ptr [0x4db878]
    (app->getMemory<x86::reg32>(x86::reg32(5093496) /* 0x4db878 */))++;
    // 004a0cec  ff0548a25900           -inc dword ptr [0x59a248]
    (app->getMemory<x86::reg32>(x86::reg32(5874248) /* 0x59a248 */))++;
    // 004a0cf2  e8756afeff             -call 0x48776c
    cpu.esp -= 4;
    sub_48776c(app, cpu);
    if (cpu.terminate) return;
    // 004a0cf7  833d48b84d0000         +cmp dword ptr [0x4db848], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093448) /* 0x4db848 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0cfe  0f8524010000           -jne 0x4a0e28
    if (!cpu.flags.zf)
    {
        goto L_0x004a0e28;
    }
L_0x004a0d04:
    // 004a0d04  833d3cb84d0000         +cmp dword ptr [0x4db83c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093436) /* 0x4db83c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d0b  7406                   -je 0x4a0d13
    if (cpu.flags.zf)
    {
        goto L_0x004a0d13;
    }
    // 004a0d0d  ff153cb84d00           -call dword ptr [0x4db83c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093436) /* 0x4db83c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a0d13:
    // 004a0d13  833d40b84d0000         +cmp dword ptr [0x4db840], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093440) /* 0x4db840 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d1a  0f8513010000           -jne 0x4a0e33
    if (!cpu.flags.zf)
    {
        goto L_0x004a0e33;
    }
L_0x004a0d20:
    // 004a0d20  bef09b5900             -mov esi, 0x599bf0
    cpu.esi = 5872624 /*0x599bf0*/;
    // 004a0d25  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a0d27:
    // 004a0d27  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a0d2a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a0d2c  80fc01                 +cmp ah, 1
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
    // 004a0d2f  0f85ba000000           -jne 0x4a0def
    if (!cpu.flags.zf)
    {
        goto L_0x004a0def;
    }
    // 004a0d35  833e00                 +cmp dword ptr [esi], 0
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
    // 004a0d38  0f8cb1000000           -jl 0x4a0def
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0def;
    }
    // 004a0d3e  837e5c00               +cmp dword ptr [esi + 0x5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d42  7425                   -je 0x4a0d69
    if (cpu.flags.zf)
    {
        goto L_0x004a0d69;
    }
    // 004a0d44  8a563f                 -mov dl, byte ptr [esi + 0x3f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */);
    // 004a0d47  fec2                   -inc dl
    (cpu.dl)++;
    // 004a0d49  88563f                 -mov byte ptr [esi + 0x3f], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */) = cpu.dl;
    // 004a0d4c  3a563d                 +cmp dl, byte ptr [esi + 0x3d]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(61) /* 0x3d */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a0d4f  7204                   -jb 0x4a0d55
    if (cpu.flags.cf)
    {
        goto L_0x004a0d55;
    }
    // 004a0d51  c6463f00               -mov byte ptr [esi + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
L_0x004a0d55:
    // 004a0d55  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0d57  e894bb0000             -call 0x4ac8f0
    cpu.esp -= 4;
    sub_4ac8f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0d5c  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a0d5f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0d61  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a0d64  e8976dfeff             -call 0x487b00
    cpu.esp -= 4;
    sub_487b00(app, cpu);
    if (cpu.terminate) return;
L_0x004a0d69:
    // 004a0d69  8b5158                 -mov edx, dword ptr [ecx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 004a0d6c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a0d6e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0d70  7418                   -je 0x4a0d8a
    if (cpu.flags.zf)
    {
        goto L_0x004a0d8a;
    }
    // 004a0d72  8a413e                 -mov al, byte ptr [ecx + 0x3e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 004a0d75  fec0                   -inc al
    (cpu.al)++;
    // 004a0d77  88413e                 -mov byte ptr [ecx + 0x3e], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.al;
    // 004a0d7a  8a613c                 -mov ah, byte ptr [ecx + 0x3c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 004a0d7d  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a0d82  38e0                   +cmp al, ah
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a0d84  7204                   -jb 0x4a0d8a
    if (cpu.flags.cf)
    {
        goto L_0x004a0d8a;
    }
    // 004a0d86  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
L_0x004a0d8a:
    // 004a0d8a  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a0d8d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a0d8f  7431                   -je 0x4a0dc2
    if (cpu.flags.zf)
    {
        goto L_0x004a0dc2;
    }
    // 004a0d91  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a0d94  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a0d99  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a0d9b  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a0d9e  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a0da1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a0da3  0f8c95000000           -jl 0x4a0e3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0e3e;
    }
    // 004a0da9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dab  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a0dae  39d0                   +cmp eax, edx
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
    // 004a0db0  7c0a                   -jl 0x4a0dbc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0dbc;
    }
    // 004a0db2  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a0db9  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x004a0dbc:
    // 004a0dbc  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0dc0  7c26                   -jl 0x4a0de8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0de8;
    }
L_0x004a0dc2:
    // 004a0dc2  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004a0dc5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0dc7  7408                   -je 0x4a0dd1
    if (cpu.flags.zf)
    {
        goto L_0x004a0dd1;
    }
    // 004a0dc9  015128                 -add dword ptr [ecx + 0x28], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0dcc  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x004a0dd1:
    // 004a0dd1  83792c00               +cmp dword ptr [ecx + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0dd5  0f85ac000000           -jne 0x4a0e87
    if (!cpu.flags.zf)
    {
        goto L_0x004a0e87;
    }
    // 004a0ddb  8a5135                 -mov dl, byte ptr [ecx + 0x35]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 004a0dde  fec2                   -inc dl
    (cpu.dl)++;
    // 004a0de0  885135                 -mov byte ptr [ecx + 0x35], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = cpu.dl;
    // 004a0de3  3a5134                 +cmp dl, byte ptr [ecx + 0x34]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a0de6  7c70                   -jl 0x4a0e58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0e58;
    }
L_0x004a0de8:
    // 004a0de8  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a0dea  e8c16efeff             -call 0x487cb0
    cpu.esp -= 4;
    sub_487cb0(app, cpu);
    if (cpu.terminate) return;
L_0x004a0def:
    // 004a0def  43                     -inc ebx
    (cpu.ebx)++;
    // 004a0df0  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004a0df3  83fb10                 +cmp ebx, 0x10
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
    // 004a0df6  0f8c2bffffff           -jl 0x4a0d27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0d27;
    }
    // 004a0dfc  833d44b84d0000         +cmp dword ptr [0x4db844], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093444) /* 0x4db844 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e03  7416                   -je 0x4a0e1b
    if (cpu.flags.zf)
    {
        goto L_0x004a0e1b;
    }
    // 004a0e05  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004a0e0a  a148a25900             -mov eax, dword ptr [0x59a248]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874248) /* 0x59a248 */);
    // 004a0e0f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0e11  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a0e13  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0e15  0f84a2000000           -je 0x4a0ebd
    if (cpu.flags.zf)
    {
        goto L_0x004a0ebd;
    }
L_0x004a0e1b:
    // 004a0e1b  ff0d78b84d00           +dec dword ptr [0x4db878]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5093496) /* 0x4db878 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a0e21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0e28:
    // 004a0e28  ff1548b84d00           -call dword ptr [0x4db848]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093448) /* 0x4db848 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0e2e  e9d1feffff             -jmp 0x4a0d04
    goto L_0x004a0d04;
L_0x004a0e33:
    // 004a0e33  ff1540b84d00           -call dword ptr [0x4db840]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093440) /* 0x4db840 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0e39  e9e2feffff             -jmp 0x4a0d20
    goto L_0x004a0d20;
L_0x004a0e3e:
    // 004a0e3e  8b691c                 -mov ebp, dword ptr [ecx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a0e41  39ea                   +cmp edx, ebp
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
    // 004a0e43  0f8f73ffffff           -jg 0x4a0dbc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a0dbc;
    }
    // 004a0e49  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a0e50  896920                 -mov dword ptr [ecx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004a0e53  e964ffffff             -jmp 0x4a0dbc
    goto L_0x004a0dbc;
L_0x004a0e58:
    // 004a0e58  8b4132                 -mov eax, dword ptr [ecx + 0x32]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(50) /* 0x32 */);
    // 004a0e5b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a0e5e  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004a0e61  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a0e64  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0e66  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a0e68  89512c                 -mov dword ptr [ecx + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 004a0e6b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0e6d  7c45                   -jl 0x4a0eb4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0eb4;
    }
L_0x004a0e6f:
    // 004a0e6f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a0e72  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004a0e75  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a0e78  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a0e7a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0e7c  8b692c                 -mov ebp, dword ptr [ecx + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 004a0e7f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0e82  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0e84  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004a0e87:
    // 004a0e87  ff492c                 -dec dword ptr [ecx + 0x2c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */))--;
    // 004a0e8a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a0e8c  0f845dffffff           -je 0x4a0def
    if (cpu.flags.zf)
    {
        goto L_0x004a0def;
    }
    // 004a0e92  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0e94  e817390000             -call 0x4a47b0
    cpu.esp -= 4;
    sub_4a47b0(app, cpu);
    if (cpu.terminate) return;
    // 004a0e99  833900                 +cmp dword ptr [ecx], 0
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
    // 004a0e9c  0f8c4dffffff           -jl 0x4a0def
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0def;
    }
    // 004a0ea2  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004a0ea5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0ea7  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004a0eaa  e8656afeff             -call 0x487914
    cpu.esp -= 4;
    sub_487914(app, cpu);
    if (cpu.terminate) return;
    // 004a0eaf  e93bffffff             -jmp 0x4a0def
    goto L_0x004a0def;
L_0x004a0eb4:
    // 004a0eb4  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 004a0ebb  ebb2                   -jmp 0x4a0e6f
    goto L_0x004a0e6f;
L_0x004a0ebd:
    // 004a0ebd  ff1544b84d00           -call dword ptr [0x4db844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093444) /* 0x4db844 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0ec3  ff0d78b84d00           -dec dword ptr [0x4db878]
    (app->getMemory<x86::reg32>(x86::reg32(5093496) /* 0x4db878 */))--;
    // 004a0ec9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0eca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ecb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ecc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ecd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ece  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ecf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0ed0);
    // 004a0ed0  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 004a0ed5  e8de74feff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004a0eda  ff057cb84d00           -inc dword ptr [0x4db87c]
    (app->getMemory<x86::reg32>(x86::reg32(5093500) /* 0x4db87c */))++;
    // 004a0ee0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0ee4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0ee4);
    // 004a0ee4  ff0d7cb84d00           +dec dword ptr [0x4db87c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5093500) /* 0x4db87c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a0eea  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 004a0eef  e9dc74feff             -jmp 0x4883d0
    return sub_4883d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0f00);
    // 004a0f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0f02  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0f04  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a0f06  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0f08  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0f0a  7e12                   -jle 0x4a0f1e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0f1e;
    }
L_0x004a0f0c:
    // 004a0f0c  8b9055a25900           -mov edx, dword ptr [eax + 0x59a255]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5874261) /* 0x59a255 */);
    // 004a0f12  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0f15  39da                   +cmp edx, ebx
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
    // 004a0f17  740a                   -je 0x4a0f23
    if (cpu.flags.zf)
    {
        goto L_0x004a0f23;
    }
    // 004a0f19  40                     -inc eax
    (cpu.eax)++;
    // 004a0f1a  39c8                   +cmp eax, ecx
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
    // 004a0f1c  7cee                   -jl 0x4a0f0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0f0c;
    }
L_0x004a0f1e:
    // 004a0f1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0f20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0f23:
    // 004a0f23  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a0f28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0f2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a0f2c);
    // 004a0f2c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0f2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0f2e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0f2f  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0f32  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a0f36  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a0f3a  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004a0f3e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004a0f42  baf7ffffff             -mov edx, 0xfffffff7
    cpu.edx = 4294967287 /*0xfffffff7*/;
    // 004a0f47  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0f4b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0f4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0f4f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a0f53  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0f56  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0f58  7e12                   -jle 0x4a0f6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0f6c;
    }
    // 004a0f5a  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 004a0f5c  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x004a0f60:
    // 004a0f60  40                     -inc eax
    (cpu.eax)++;
    // 004a0f61  889057a25900           -mov byte ptr [eax + 0x59a257], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5874263) /* 0x59a257 */) = cpu.dl;
    // 004a0f67  39f0                   +cmp eax, esi
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
    // 004a0f69  7cf5                   -jl 0x4a0f60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0f60;
    }
    // 004a0f6b  90                     -nop 
    ;
L_0x004a0f6c:
    // 004a0f6c  8b3d80b84d00           -mov edi, dword ptr [0x4db880]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093504) /* 0x4db880 */);
    // 004a0f72  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0f75  893d80b84d00           -mov dword ptr [0x4db880], edi
    app->getMemory<x86::reg32>(x86::reg32(5093504) /* 0x4db880 */) = cpu.edi;
    // 004a0f7b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a0f7d  7c2b                   -jl 0x4a0faa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0faa;
    }
L_0x004a0f7f:
    // 004a0f7f  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0f83  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0f85  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a0f87:
    // 004a0f87  a136b84d00             -mov eax, dword ptr [0x4db836]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093430) /* 0x4db836 */);
    // 004a0f8c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a0f8f  39c3                   +cmp ebx, eax
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
    // 004a0f91  7d4a                   -jge 0x4a0fdd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0fdd;
    }
    // 004a0f93  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a0f98  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a0f9a  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a0f9e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a0fa0  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 004a0fa2  750f                   -jne 0x4a0fb3
    if (!cpu.flags.zf)
    {
        goto L_0x004a0fb3;
    }
L_0x004a0fa4:
    // 004a0fa4  83c660                 +add esi, 0x60
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0fa7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a0fa8  ebdd                   -jmp 0x4a0f87
    goto L_0x004a0f87;
L_0x004a0faa:
    // 004a0faa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a0fac  a380b84d00             -mov dword ptr [0x4db880], eax
    app->getMemory<x86::reg32>(x86::reg32(5093504) /* 0x4db880 */) = cpu.eax;
    // 004a0fb1  ebcc                   -jmp 0x4a0f7f
    goto L_0x004a0f7f;
L_0x004a0fb3:
    // 004a0fb3  80befc9b590000         +cmp byte ptr [esi + 0x599bfc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5872636) /* 0x599bfc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a0fba  75e8                   -jne 0x4a0fa4
    if (!cpu.flags.zf)
    {
        goto L_0x004a0fa4;
    }
    // 004a0fbc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0fbf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0fc1  e83affffff             -call 0x4a0f00
    cpu.esp -= 4;
    sub_4a0f00(app, cpu);
    if (cpu.terminate) return;
    // 004a0fc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0fc8  75da                   -jne 0x4a0fa4
    if (!cpu.flags.zf)
    {
        goto L_0x004a0fa4;
    }
    // 004a0fca  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0fcd  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a0fd0  889858a25900           -mov byte ptr [eax + 0x59a258], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5874264) /* 0x59a258 */) = cpu.bl;
    // 004a0fd6  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0fd9  39f9                   +cmp ecx, edi
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
    // 004a0fdb  7cc7                   -jl 0x4a0fa4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0fa4;
    }
L_0x004a0fdd:
    // 004a0fdd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0fe0  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0fe4  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a0fe8  39e8                   +cmp eax, ebp
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
    // 004a0fea  0f8d94000000           -jge 0x4a1084
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1084;
    }
L_0x004a0ff0:
    // 004a0ff0  bf66000000             -mov edi, 0x66
    cpu.edi = 102 /*0x66*/;
    // 004a0ff5  bdffffff7f             -mov ebp, 0x7fffffff
    cpu.ebp = 2147483647 /*0x7fffffff*/;
    // 004a0ffa  bef09b5900             -mov esi, 0x599bf0
    cpu.esi = 5872624 /*0x599bf0*/;
    // 004a0fff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1001  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1003  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
L_0x004a1007:
    // 004a1007  a136b84d00             -mov eax, dword ptr [0x4db836]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093430) /* 0x4db836 */);
    // 004a100c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a100f  39c3                   +cmp ebx, eax
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
    // 004a1011  7d48                   -jge 0x4a105b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a105b;
    }
    // 004a1013  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1018  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a101a  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a101e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a1020  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 004a1022  7506                   -jne 0x4a102a
    if (!cpu.flags.zf)
    {
        goto L_0x004a102a;
    }
L_0x004a1024:
    // 004a1024  83c660                 +add esi, 0x60
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1027  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a1028  ebdd                   -jmp 0x4a1007
    goto L_0x004a1007;
L_0x004a102a:
    // 004a102a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a102d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a102f  e8ccfeffff             -call 0x4a0f00
    cpu.esp -= 4;
    sub_4a0f00(app, cpu);
    if (cpu.terminate) return;
    // 004a1034  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1036  75ec                   -jne 0x4a1024
    if (!cpu.flags.zf)
    {
        goto L_0x004a1024;
    }
    // 004a1038  8a460e                 -mov al, byte ptr [esi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004a103b  39f8                   +cmp eax, edi
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
    // 004a103d  7d0b                   -jge 0x4a104a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a104a;
    }
    // 004a103f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a1041  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a1045  8b6e14                 -mov ebp, dword ptr [esi + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a1048  ebda                   -jmp 0x4a1024
    goto L_0x004a1024;
L_0x004a104a:
    // 004a104a  75d8                   -jne 0x4a1024
    if (!cpu.flags.zf)
    {
        goto L_0x004a1024;
    }
    // 004a104c  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a104f  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1051  7ed1                   -jle 0x4a1024
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1024;
    }
    // 004a1053  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a1055  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a1059  ebc9                   -jmp 0x4a1024
    goto L_0x004a1024;
L_0x004a105b:
    // 004a105b  3b7c2410               +cmp edi, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a105f  0f8fe2000000           -jg 0x4a1147
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a1147;
    }
    // 004a1065  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a1069  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a106c  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1070  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a1073  888358a25900           -mov byte ptr [ebx + 0x59a258], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5874264) /* 0x59a258 */) = cpu.al;
    // 004a1079  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a107c  39fe                   +cmp esi, edi
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
    // 004a107e  0f8cc3000000           -jl 0x4a1147
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1147;
    }
L_0x004a1084:
    // 004a1084  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a1087  3b442418               +cmp eax, dword ptr [esp + 0x18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a108b  0f85ab000000           -jne 0x4a113c
    if (!cpu.flags.zf)
    {
        goto L_0x004a113c;
    }
    // 004a1091  8b1d55a25900           -mov ebx, dword ptr [0x59a255]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5874261) /* 0x59a255 */);
    // 004a1097  a180b84d00             -mov eax, dword ptr [0x4db880]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093504) /* 0x4db880 */);
    // 004a109c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a109f  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a10a1  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a10a5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a10a7  8b1d55a25900           -mov ebx, dword ptr [0x59a255]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5874261) /* 0x59a255 */);
    // 004a10ad  8b3d80b84d00           -mov edi, dword ptr [0x4db880]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093504) /* 0x4db880 */);
    // 004a10b3  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a10b6  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a10b8  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a10bf  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a10c2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a10c4  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a10c8  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a10cb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a10cd  89b8f09b5900           -mov dword ptr [eax + 0x599bf0], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872624) /* 0x599bf0 */) = cpu.edi;
    // 004a10d3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a10d5  0f8eb4000000           -jle 0x4a118f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a118f;
    }
L_0x004a10db:
    // 004a10db  8b8355a25900           -mov eax, dword ptr [ebx + 0x59a255]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5874261) /* 0x59a255 */);
    // 004a10e1  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a10e4  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a10e7  bff09b5900             -mov edi, 0x599bf0
    cpu.edi = 5872624 /*0x599bf0*/;
    // 004a10ec  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a10ee  8a4f0c                 -mov cl, byte ptr [edi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a10f1  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 004a10f3  80f901                 +cmp cl, 1
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a10f6  0f8576000000           -jne 0x4a1172
    if (!cpu.flags.zf)
    {
        goto L_0x004a1172;
    }
    // 004a10fc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a10fe  7c61                   -jl 0x4a1161
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1161;
    }
L_0x004a1100:
    // 004a1100  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a1102  e8a96bfeff             -call 0x487cb0
    cpu.esp -= 4;
    sub_487cb0(app, cpu);
    if (cpu.terminate) return;
    // 004a1107  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a1109  e8a233feff             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 004a110e  83f801                 +cmp eax, 1
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
    // 004a1111  745f                   -je 0x4a1172
    if (cpu.flags.zf)
    {
        goto L_0x004a1172;
    }
    // 004a1113  4b                     -dec ebx
    (cpu.ebx)--;
    // 004a1114  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a1116  7c1c                   -jl 0x4a1134
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1134;
    }
    // 004a1118  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a111a:
    // 004a111a  8b8355a25900           -mov eax, dword ptr [ebx + 0x59a255]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5874261) /* 0x59a255 */);
    // 004a1120  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a1123  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a1126  05f09b5900             -add eax, 0x599bf0
    (cpu.eax) += x86::reg32(x86::sreg32(5872624 /*0x599bf0*/));
    // 004a112b  4b                     -dec ebx
    (cpu.ebx)--;
    // 004a112c  88500c                 -mov byte ptr [eax + 0xc], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004a112f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a1131  7de7                   -jge 0x4a111a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a111a;
    }
    // 004a1133  90                     -nop 
    ;
L_0x004a1134:
    // 004a1134  c744240cf7ffffff       -mov dword ptr [esp + 0xc], 0xfffffff7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 4294967287 /*0xfffffff7*/;
L_0x004a113c:
    // 004a113c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1140  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a1143  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1144  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1145  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1146  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1147:
    // 004a1147  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a114b  40                     -inc eax
    (cpu.eax)++;
    // 004a114c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1150  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a1154  39d0                   +cmp eax, edx
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
    // 004a1156  0f8c94feffff           -jl 0x4a0ff0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0ff0;
    }
    // 004a115c  e923ffffff             -jmp 0x4a1084
    goto L_0x004a1084;
L_0x004a1161:
    // 004a1161  8b4741                 -mov eax, dword ptr [edi + 0x41]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(65) /* 0x41 */);
    // 004a1164  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a1167  6bc060                 +imul eax, eax, 0x60
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004a116a  8bb0f09b5900           -mov esi, dword ptr [eax + 0x599bf0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872624) /* 0x599bf0 */);
    // 004a1170  eb8e                   -jmp 0x4a1100
    goto L_0x004a1100;
L_0x004a1172:
    // 004a1172  a148a25900             -mov eax, dword ptr [0x59a248]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874248) /* 0x59a248 */);
    // 004a1177  c6470c01               -mov byte ptr [edi + 0xc], 1
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004a117b  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a117e  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a1182  43                     -inc ebx
    (cpu.ebx)++;
    // 004a1183  88470e                 -mov byte ptr [edi + 0xe], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004a1186  3b1c24                 +cmp ebx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1189  0f8c4cffffff           -jl 0x4a10db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a10db;
    }
L_0x004a118f:
    // 004a118f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1194  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004a1197  7da3                   -jge 0x4a113c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a113c;
    }
    // 004a1199  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004a119c:
    // 004a119c  8b1d55a25900           -mov ebx, dword ptr [0x59a255]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5874261) /* 0x59a255 */);
    // 004a11a2  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a11a5  6bdb60                 -imul ebx, ebx, 0x60
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a11a8  8a9058a25900           -mov dl, byte ptr [eax + 0x59a258]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5874264) /* 0x59a258 */);
    // 004a11ae  889403f39b5900         -mov byte ptr [ebx + eax + 0x599bf3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5872627) /* 0x599bf3 */ + cpu.eax * 1) = cpu.dl;
    // 004a11b5  8b9855a25900           -mov ebx, dword ptr [eax + 0x59a255]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5874261) /* 0x59a255 */);
    // 004a11bb  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a11be  6bdb60                 -imul ebx, ebx, 0x60
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a11c1  c783f09b5900ffffffff   -mov dword ptr [ebx + 0x599bf0], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5872624) /* 0x599bf0 */) = 4294967295 /*0xffffffff*/;
    // 004a11cb  8a1558a25900           -mov dl, byte ptr [0x59a258]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5874264) /* 0x59a258 */);
    // 004a11d1  40                     -inc eax
    (cpu.eax)++;
    // 004a11d2  8893349c5900           -mov byte ptr [ebx + 0x599c34], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5872692) /* 0x599c34 */) = cpu.dl;
    // 004a11d8  39c8                   +cmp eax, ecx
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
    // 004a11da  7cc0                   -jl 0x4a119c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a119c;
    }
    // 004a11dc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a11e0  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a11e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a11e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a11e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a11e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a11e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a11e8);
    // 004a11e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a11e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a11ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a11eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a11ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a11ed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a11ee  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a11f0  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004a11f7  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004a11fc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a11fe  b8f09b5900             -mov eax, 0x599bf0
    cpu.eax = 5872624 /*0x599bf0*/;
    // 004a1203  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004a1206  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1208  8a5c023b               -mov bl, byte ptr [edx + eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */ + cpu.eax * 1);
    // 004a120c  0fb67c023b             -movzx edi, byte ptr [edx + eax + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */ + cpu.eax * 1));
    // 004a1211  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a1213  0f84b4000000           -je 0x4a12cd
    if (cpu.flags.zf)
    {
        goto L_0x004a12cd;
    }
    // 004a1219  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a121b:
    // 004a121b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a121d  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 004a1220  39fb                   +cmp ebx, edi
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
    // 004a1222  7515                   -jne 0x4a1239
    if (!cpu.flags.zf)
    {
        goto L_0x004a1239;
    }
    // 004a1224  833800                 +cmp dword ptr [eax], 0
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
    // 004a1227  7c10                   -jl 0x4a1239
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1239;
    }
    // 004a1229  80780c00               +cmp byte ptr [eax + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a122d  740a                   -je 0x4a1239
    if (cpu.flags.zf)
    {
        goto L_0x004a1239;
    }
    // 004a122f  8a783a                 -mov bh, byte ptr [eax + 0x3a]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 004a1232  41                     -inc ecx
    (cpu.ecx)++;
    // 004a1233  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004a1235  7402                   -je 0x4a1239
    if (cpu.flags.zf)
    {
        goto L_0x004a1239;
    }
    // 004a1237  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x004a1239:
    // 004a1239  42                     -inc edx
    (cpu.edx)++;
    // 004a123a  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004a123d  83fa10                 +cmp edx, 0x10
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
    // 004a1240  7cd9                   -jl 0x4a121b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a121b;
    }
    // 004a1242  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 004a1249  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a124b  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004a124e  83f901                 +cmp ecx, 1
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
    // 004a1251  7445                   -je 0x4a1298
    if (cpu.flags.zf)
    {
        goto L_0x004a1298;
    }
    // 004a1253  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004a125a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a125c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a125f  80b8fc9b590002         +cmp byte ptr [eax + 0x599bfc], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5872636) /* 0x599bfc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1266  7509                   -jne 0x4a1271
    if (!cpu.flags.zf)
    {
        goto L_0x004a1271;
    }
    // 004a1268  39f5                   +cmp ebp, esi
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
    // 004a126a  7405                   -je 0x4a1271
    if (cpu.flags.zf)
    {
        goto L_0x004a1271;
    }
    // 004a126c  83f902                 +cmp ecx, 2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a126f  7431                   -je 0x4a12a2
    if (cpu.flags.zf)
    {
        goto L_0x004a12a2;
    }
L_0x004a1271:
    // 004a1271  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004a1278  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a127a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a127d  80b8fc9b590001         +cmp byte ptr [eax + 0x599bfc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5872636) /* 0x599bfc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1284  752c                   -jne 0x4a12b2
    if (!cpu.flags.zf)
    {
        goto L_0x004a12b2;
    }
    // 004a1286  39f5                   +cmp ebp, esi
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
    // 004a1288  7528                   -jne 0x4a12b2
    if (!cpu.flags.zf)
    {
        goto L_0x004a12b2;
    }
    // 004a128a  c680fc9b590002         -mov byte ptr [eax + 0x599bfc], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5872636) /* 0x599bfc */) = 2 /*0x2*/;
L_0x004a1291:
    // 004a1291  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1292  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1293  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1294  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1295  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1296  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1297  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1298:
    // 004a1298  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004a129a  8883fc9b5900           -mov byte ptr [ebx + 0x599bfc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5872636) /* 0x599bfc */) = cpu.al;
    // 004a12a0  ebef                   -jmp 0x4a1291
    goto L_0x004a1291;
L_0x004a12a2:
    // 004a12a2  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 004a12a4  888bfc9b5900           -mov byte ptr [ebx + 0x599bfc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5872636) /* 0x599bfc */) = cpu.cl;
    // 004a12aa  8888fc9b5900           -mov byte ptr [eax + 0x599bfc], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5872636) /* 0x599bfc */) = cpu.cl;
    // 004a12b0  ebdf                   -jmp 0x4a1291
    goto L_0x004a1291;
L_0x004a12b2:
    // 004a12b2  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004a12b9  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a12bb  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a12be  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004a12c0  8898fc9b5900           -mov byte ptr [eax + 0x599bfc], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5872636) /* 0x599bfc */) = cpu.bl;
    // 004a12c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a12cd:
    // 004a12cd  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004a12cf  88bafc9b5900           -mov byte ptr [edx + 0x599bfc], bh
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5872636) /* 0x599bfc */) = cpu.bh;
    // 004a12d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a12db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a12dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a12dc);
    // 004a12dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a12dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a12de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a12e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a12e2  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a12e5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004a12ec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a12ee  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a12f1  05f09b5900             -add eax, 0x599bf0
    (cpu.eax) += x86::reg32(x86::sreg32(5872624 /*0x599bf0*/));
    // 004a12f6  80780c00               +cmp byte ptr [eax + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a12fa  7404                   -je 0x4a1300
    if (cpu.flags.zf)
    {
        goto L_0x004a1300;
    }
    // 004a12fc  3b08                   +cmp ecx, dword ptr [eax]
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
    // 004a12fe  7405                   -je 0x4a1305
    if (cpu.flags.zf)
    {
        goto L_0x004a1305;
    }
L_0x004a1300:
    // 004a1300  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x004a1305:
    // 004a1305  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a1307  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1308  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1309  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a130a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a130a);
    // 004a130a  9b                     -wait 
    /*nothing*/;
    // 004a130b  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 004a130d  9b                     -wait 
    /*nothing*/;
    // 004a130e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a130f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a130f);
    // 004a130f  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 004a1311  9b                     -wait 
    /*nothing*/;
    // 004a1312  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a1313(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1313);
L_0x004a1313:
    // 004a1313  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1314  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1315  803d59934d0000         +cmp byte ptr [0x4d9359], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083993) /* 0x4d9359 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a131c  7416                   -je 0x4a1334
    if (cpu.flags.zf)
    {
        goto L_0x004a1334;
    }
    // 004a131e  ba0a134a00             -mov edx, 0x4a130a
    cpu.edx = 4854538 /*0x4a130a*/;
    // 004a1323  bb0f134a00             -mov ebx, 0x4a130f
    cpu.ebx = 4854543 /*0x4a130f*/;
    // 004a1328  8915d4e14d00           -mov dword ptr [0x4de1d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5104084) /* 0x4de1d4 */) = cpu.edx;
    // 004a132e  891dd8e14d00           -mov dword ptr [0x4de1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5104088) /* 0x4de1d8 */) = cpu.ebx;
L_0x004a1334:
    // 004a1334  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1336  66a1dce14d00           -mov ax, word ptr [0x4de1dc]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5104092) /* 0x4de1dc */);
    // 004a133c  e8d10b0100             -call 0x4b1f12
    cpu.esp -= 4;
    sub_4b1f12(app, cpu);
    if (cpu.terminate) return;
    // 004a1341  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1342  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1343  c3                     -ret 
    cpu.esp += 4;
    return;
    // 004a1344  803d59934d0000         +cmp byte ptr [0x4d9359], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083993) /* 0x4d9359 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a134b  75c6                   -jne 0x4a1313
    if (!cpu.flags.zf)
    {
        goto L_0x004a1313;
    }
    // 004a134d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a134e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a134e);
    // 004a134e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a134f  8a2558934d00           -mov ah, byte ptr [0x4d9358]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5083992) /* 0x4d9358 */);
    // 004a1355  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a1357  7537                   -jne 0x4a1390
    if (!cpu.flags.zf)
    {
        goto L_0x004a1390;
    }
    // 004a1359  882559934d00           -mov byte ptr [0x4d9359], ah
    app->getMemory<x86::reg8>(x86::reg32(5083993) /* 0x4d9359 */) = cpu.ah;
    // 004a135f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004a1361  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1363  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1364  dbe3                   -fninit 
    cpu.fpu.init();
    // 004a1366  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004a1369  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a136a  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 004a136c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004a136e  3c03                   +cmp al, 3
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
    // 004a1370  7509                   -jne 0x4a137b
    if (!cpu.flags.zf)
    {
        goto L_0x004a137b;
    }
    // 004a1372  e89cffffff             -call 0x4a1313
    cpu.esp -= 4;
    sub_4a1313(app, cpu);
    if (cpu.terminate) return;
    // 004a1377  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 004a1379  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x004a137b:
    // 004a137b  803dc4b84d0000         +cmp byte ptr [0x4db8c4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093572) /* 0x4db8c4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1382  750c                   -jne 0x4a1390
    if (!cpu.flags.zf)
    {
        goto L_0x004a1390;
    }
    // 004a1384  883558934d00           -mov byte ptr [0x4d9358], dh
    app->getMemory<x86::reg8>(x86::reg32(5083992) /* 0x4d9358 */) = cpu.dh;
    // 004a138a  881559934d00           -mov byte ptr [0x4d9359], dl
    app->getMemory<x86::reg8>(x86::reg32(5083993) /* 0x4d9359 */) = cpu.dl;
L_0x004a1390:
    // 004a1390  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1391  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a1392(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1392);
    // 004a1392  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a13a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a13a0);
    // 004a13a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a13a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a13a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a13a3  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004a13a6  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004a13aa  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a13ae  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a13b2  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a13b6  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a13b9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a13bb  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a13be  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a13c1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a13c3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a13c5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a13c7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004a13c9  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a13cc  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a13d0  40                     -inc eax
    (cpu.eax)++;
    // 004a13d1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004a13d3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a13d7  8a257a904d00           -mov ah, byte ptr [0x4d907a]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5083258) /* 0x4d907a */);
    // 004a13dd  8b2d38b54d00           -mov ebp, dword ptr [0x4db538]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5092664) /* 0x4db538 */);
    // 004a13e3  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a13e5  0f8585030000           -jne 0x4a1770
    if (!cpu.flags.zf)
    {
        goto L_0x004a1770;
    }
    // 004a13eb  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a13ef  3b0568904d00           +cmp eax, dword ptr [0x4d9068]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a13f5  0f8c75030000           -jl 0x4a1770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1770;
    }
    // 004a13fb  3b0570904d00           +cmp eax, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1401  0f8d69030000           -jge 0x4a1770
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1770;
    }
    // 004a1407  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a140b  3b056c904d00           +cmp eax, dword ptr [0x4d906c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1411  0f8c59030000           -jl 0x4a1770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1770;
    }
    // 004a1417  3b0574904d00           +cmp eax, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a141d  0f8d4d030000           -jge 0x4a1770
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1770;
    }
    // 004a1423  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a1427  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a142b  8b1d68904d00           -mov ebx, dword ptr [0x4d9068]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004a1431  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1433  39d8                   +cmp eax, ebx
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
    // 004a1435  0f8c35030000           -jl 0x4a1770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1770;
    }
    // 004a143b  3b0570904d00           +cmp eax, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1441  0f8d29030000           -jge 0x4a1770
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1770;
    }
    // 004a1447  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a144b  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a144f  8b1d6c904d00           -mov ebx, dword ptr [0x4d906c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 004a1455  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1457  39d8                   +cmp eax, ebx
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
    // 004a1459  0f8c11030000           -jl 0x4a1770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1770;
    }
    // 004a145f  3b0574904d00           +cmp eax, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1465  0f8d05030000           -jge 0x4a1770
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1770;
    }
    // 004a146b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a146f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a1471  8a1578904d00           -mov dl, byte ptr [0x4d9078]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 004a1477  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1479  80fa10                 +cmp dl, 0x10
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
    // 004a147c  0f8565010000           -jne 0x4a15e7
    if (!cpu.flags.zf)
    {
        goto L_0x004a15e7;
    }
    // 004a1482  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004a1485:
    // 004a1485  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1489  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a148d  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004a1493  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004a1496  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004a149c  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004a149f  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a14a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a14a7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a14ab  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x004a14af:
    // 004a14af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a14b1  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a14b3  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004a14b6  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a14ba  81fb00000010           +cmp ebx, 0x10000000
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
    // 004a14c0  726b                   -jb 0x4a152d
    if (cpu.flags.cf)
    {
        goto L_0x004a152d;
    }
    // 004a14c2  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004a14c8  7340                   -jae 0x4a150a
    if (!cpu.flags.cf)
    {
        goto L_0x004a150a;
    }
    // 004a14ca  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a14cd  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a14cf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a14d1  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004a14d4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a14d7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a14d9  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004a14df  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a14e2  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004a14e7  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004a14ea  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a14ec  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a14ee  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a14f1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a14f3  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004a14f6  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a14f8  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004a14fb  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1501  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004a1506  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1508  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a150a:
    // 004a150a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a150c  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004a1512  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a1515  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a1517  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a151a  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004a1520  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004a1523  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a1526  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1528  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a152a  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004a152d:
    // 004a152d  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a1530  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1532  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a1534  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a1537  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a153b  81fb00000010           +cmp ebx, 0x10000000
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
    // 004a1541  726b                   -jb 0x4a15ae
    if (cpu.flags.cf)
    {
        goto L_0x004a15ae;
    }
    // 004a1543  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004a1549  7340                   -jae 0x4a158b
    if (!cpu.flags.cf)
    {
        goto L_0x004a158b;
    }
    // 004a154b  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a154e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a1550  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a1552  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004a1555  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a1558  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a155a  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004a1560  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1563  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004a1568  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004a156b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a156d  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a156f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a1572  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a1574  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004a1577  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a1579  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004a157c  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1582  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004a1587  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1589  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a158b:
    // 004a158b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a158d  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004a1593  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a1596  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a1598  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a159b  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004a15a1  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004a15a4  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a15a7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a15a9  01d3                   +add ebx, edx
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
    // 004a15ab  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004a15ae:
    // 004a15ae  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a15b1  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a15b5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a15b6  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a15b7  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 004a15bb  0f85eefeffff           -jne 0x4a14af
    if (!cpu.flags.zf)
    {
        goto L_0x004a14af;
    }
    // 004a15c1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a15c4  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a15c8  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a15cc  41                     -inc ecx
    (cpu.ecx)++;
    // 004a15cd  01d7                   +add edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a15cf  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004a15d3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a15d4  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 004a15d8  0f85a7feffff           -jne 0x4a1485
    if (!cpu.flags.zf)
    {
        goto L_0x004a1485;
    }
L_0x004a15de:
    // 004a15de  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004a15e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a15e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a15e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a15e4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a15e7:
    // 004a15e7  80fa0f                 +cmp dl, 0xf
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
    // 004a15ea  0f8577010000           -jne 0x4a1767
    if (!cpu.flags.zf)
    {
        goto L_0x004a1767;
    }
    // 004a15f0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004a15f4:
    // 004a15f4  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a15f8  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a15fc  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004a1602  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004a1605  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004a160b  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004a160e  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a1614  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a1616  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a161a  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x004a161e:
    // 004a161e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1620  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a1622  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004a1625  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a1628  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004a162b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a162d  81fb00000010           +cmp ebx, 0x10000000
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
    // 004a1633  7273                   -jb 0x4a16a8
    if (cpu.flags.cf)
    {
        goto L_0x004a16a8;
    }
    // 004a1635  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004a163b  7348                   -jae 0x4a1685
    if (!cpu.flags.cf)
    {
        goto L_0x004a1685;
    }
    // 004a163d  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a1640  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a1642  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004a1647  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004a164a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a164c  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004a1652  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a1655  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a1657  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a165a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a165c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a165e  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004a1661  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1667  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a1669  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a166c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a166e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a1670  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004a1673  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1679  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a167b  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004a167e  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004a1683  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a1685:
    // 004a1685  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a1687  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004a168d  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004a1690  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a1692  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a1695  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004a169b  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004a169e  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a16a1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a16a3  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a16a5  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004a16a8:
    // 004a16a8  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a16ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a16ad  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a16af  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a16b2  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a16b6  81fb00000010           +cmp ebx, 0x10000000
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
    // 004a16bc  7273                   -jb 0x4a1731
    if (cpu.flags.cf)
    {
        goto L_0x004a1731;
    }
    // 004a16be  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004a16c4  7348                   -jae 0x4a170e
    if (!cpu.flags.cf)
    {
        goto L_0x004a170e;
    }
    // 004a16c6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a16c9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a16cb  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004a16d0  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004a16d3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a16d5  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004a16db  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a16de  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a16e0  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a16e3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a16e5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a16e7  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004a16ea  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a16f0  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a16f2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a16f5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a16f7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a16f9  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004a16fc  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1702  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a1704  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004a1707  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004a170c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a170e:
    // 004a170e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a1710  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004a1716  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004a1719  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a171b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a171e  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004a1724  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004a1727  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a172a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a172c  01d3                   +add ebx, edx
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
    // 004a172e  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004a1731:
    // 004a1731  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a1734  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a1738  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a1739  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a173a  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004a173e  0f85dafeffff           -jne 0x4a161e
    if (!cpu.flags.zf)
    {
        goto L_0x004a161e;
    }
    // 004a1744  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a1748  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a174c  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a1750  40                     -inc eax
    (cpu.eax)++;
    // 004a1751  01f7                   +add edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1753  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a1757  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a1758  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004a175c  0f847cfeffff           -je 0x4a15de
    if (cpu.flags.zf)
    {
        goto L_0x004a15de;
    }
    // 004a1762  e98dfeffff             -jmp 0x4a15f4
    goto L_0x004a15f4;
L_0x004a1767:
    // 004a1767  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a176a  0f849c000000           -je 0x4a180c
    if (cpu.flags.zf)
    {
        goto L_0x004a180c;
    }
L_0x004a1770:
    // 004a1770  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a1774  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a1776  0f8e62feffff           -jle 0x4a15de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a15de;
    }
    // 004a177c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1780  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a1784  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a1788  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a178a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a178c  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a1790  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004a1794:
    // 004a1794  8b742448               -mov esi, dword ptr [esp + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a1798  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a179a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a179c  7e51                   -jle 0x4a17ef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a17ef;
    }
    // 004a179e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a17a2  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a17a6  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a17aa  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a17ae  46                     -inc esi
    (cpu.esi)++;
L_0x004a17af:
    // 004a17af  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a17b1  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004a17b3  47                     -inc edi
    (cpu.edi)++;
    // 004a17b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a17b6  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a17b9  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004a17bc  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004a17c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a17c2  0f858f000000           -jne 0x4a1857
    if (!cpu.flags.zf)
    {
        goto L_0x004a1857;
    }
L_0x004a17c8:
    // 004a17c8  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a17cc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a17ce  7411                   -je 0x4a17e1
    if (cpu.flags.zf)
    {
        goto L_0x004a17e1;
    }
    // 004a17d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a17d2  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a17d6  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a17da  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a17dc  e85f070100             -call 0x4b1f40
    cpu.esp -= 4;
    sub_4b1f40(app, cpu);
    if (cpu.terminate) return;
L_0x004a17e1:
    // 004a17e1  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a17e5  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a17e8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a17eb  39c1                   +cmp ecx, eax
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
    // 004a17ed  7cc0                   -jl 0x4a17af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a17af;
    }
L_0x004a17ef:
    // 004a17ef  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a17f3  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a17f7  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a17fb  46                     -inc esi
    (cpu.esi)++;
    // 004a17fc  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a17fe  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004a1802  39d6                   +cmp esi, edx
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
    // 004a1804  0f8dd4fdffff           -jge 0x4a15de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a15de;
    }
    // 004a180a  eb88                   -jmp 0x4a1794
    goto L_0x004a1794;
L_0x004a180c:
    // 004a180c  8b1d84904d00           -mov ebx, dword ptr [0x4d9084]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083268) /* 0x4d9084 */);
    // 004a1812  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1814  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1816  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1817  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1818  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a181c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a181d  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a1821  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1822  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a1826  8b0d88904d00           -mov ecx, dword ptr [0x4d9088]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004a182c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a182f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1831  a17c904d00             -mov eax, dword ptr [0x4d907c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */);
    // 004a1836  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a1838  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a183c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a183e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1840  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1841  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1842  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a1845  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1846  e881090100             -call 0x4b21cc
    cpu.esp -= 4;
    sub_4b21cc(app, cpu);
    if (cpu.terminate) return;
    // 004a184b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a184e  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004a1851  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1852  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1853  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1854  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a1857:
    // 004a1857  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a185b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a185f  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a1863  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1865  e8d6060100             -call 0x4b1f40
    cpu.esp -= 4;
    sub_4b1f40(app, cpu);
    if (cpu.terminate) return;
    // 004a186a  e959ffffff             -jmp 0x4a17c8
    goto L_0x004a17c8;
}

/* align: skip 0x90 */
void Application::sub_4a1870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1870);
    // 004a1870  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1871  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1872  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1873  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a1876  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004a187a  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a187e  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a1882  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a1884  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a1886  0f8eae000000           -jle 0x4a193a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a193a;
    }
    // 004a188c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a188e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a1890  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a1893  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1895  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004a1897  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004a189b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a189e  6bc700                 -imul eax, edi, 0
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004a18a1  0faf7c2430             -imul edi, dword ptr [esp + 0x30]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */))));
    // 004a18a6  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a18a9  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004a18ad  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a18af  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a18b1  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a18b3  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a18b7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004a18bb:
    // 004a18bb  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a18bf  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a18c2  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a18c6  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a18c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a18ca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a18cc  7e4d                   -jle 0x4a191b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a191b;
    }
    // 004a18ce  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a18d2  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a18d6  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a18da  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a18de  46                     -inc esi
    (cpu.esi)++;
L_0x004a18df:
    // 004a18df  0fb62f                 -movzx ebp, byte ptr [edi]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 004a18e2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a18e4  47                     -inc edi
    (cpu.edi)++;
    // 004a18e5  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 004a18e8  83e50f                 -and ebp, 0xf
    cpu.ebp &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a18eb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a18ed  7554                   -jne 0x4a1943
    if (!cpu.flags.zf)
    {
        goto L_0x004a1943;
    }
L_0x004a18ef:
    // 004a18ef  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a18f1  741a                   -je 0x4a190d
    if (cpu.flags.zf)
    {
        goto L_0x004a190d;
    }
    // 004a18f3  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 004a18fa  81c3e0b44d00           -add ebx, 0x4db4e0
    (cpu.ebx) += x86::reg32(x86::sreg32(5092576 /*0x4db4e0*/));
    // 004a1900  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1904  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a1906  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a1908  e8237b0000             -call 0x4a9430
    cpu.esp -= 4;
    sub_4a9430(app, cpu);
    if (cpu.terminate) return;
L_0x004a190d:
    // 004a190d  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a1911  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1914  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1917  39e9                   +cmp ecx, ebp
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
    // 004a1919  7cc4                   -jl 0x4a18df
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a18df;
    }
L_0x004a191b:
    // 004a191b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a191f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1923  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a1927  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a192b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a192d  41                     -inc ecx
    (cpu.ecx)++;
    // 004a192e  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a1932  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004a1936  39d9                   +cmp ecx, ebx
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
    // 004a1938  7c81                   -jl 0x4a18bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a18bb;
    }
L_0x004a193a:
    // 004a193a  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a193d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a193e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a193f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1940  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a1943:
    // 004a1943  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004a1946  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a194a  81c3e0b44d00           -add ebx, 0x4db4e0
    (cpu.ebx) += x86::reg32(x86::sreg32(5092576 /*0x4db4e0*/));
    // 004a1950  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a1954  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1956  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a1958  e8d37a0000             -call 0x4a9430
    cpu.esp -= 4;
    sub_4a9430(app, cpu);
    if (cpu.terminate) return;
    // 004a195d  eb90                   -jmp 0x4a18ef
    goto L_0x004a18ef;
}

/* align: skip 0x90 */
void Application::sub_4a1960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1960);
    // 004a1960  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1961  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1962  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1963  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a1966  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a1968  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a196c  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a1970  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004a1974  a078904d00             -mov al, byte ptr [0x4d9078]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 004a1979  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a197b  0f837c010000           -jae 0x4a1afd
    if (!cpu.flags.cf)
    {
        goto L_0x004a1afd;
    }
    // 004a1981  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1983  0f82ac010000           -jb 0x4a1b35
    if (cpu.flags.cf)
    {
        goto L_0x004a1b35;
    }
    // 004a1989  0f8798010000           -ja 0x4a1b27
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a1b27;
    }
    // 004a198f  bf5c1f4a00             -mov edi, 0x4a1f5c
    cpu.edi = 4857692 /*0x4a1f5c*/;
L_0x004a1994:
    // 004a1994  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1996  0f8499010000           -je 0x4a1b35
    if (cpu.flags.zf)
    {
        goto L_0x004a1b35;
    }
    // 004a199c  8b2d68904d00           -mov ebp, dword ptr [0x4d9068]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004a19a2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a19a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a19a6  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004a19aa  39ee                   +cmp esi, ebp
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
    // 004a19ac  7d04                   -jge 0x4a19b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a19b2;
    }
    // 004a19ae  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a19b0  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a19b2:
    // 004a19b2  8b0d6c904d00           -mov ecx, dword ptr [0x4d906c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 004a19b8  39ca                   +cmp edx, ecx
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
    // 004a19ba  7d06                   -jge 0x4a19c2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a19c2;
    }
    // 004a19bc  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a19be  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004a19c2:
    // 004a19c2  8b2d70904d00           -mov ebp, dword ptr [0x4d9070]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 004a19c8  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004a19cb  39e9                   +cmp ecx, ebp
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
    // 004a19cd  7e04                   -jle 0x4a19d3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a19d3;
    }
    // 004a19cf  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a19d1  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a19d3:
    // 004a19d3  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a19d7  8b2d74904d00           -mov ebp, dword ptr [0x4d9074]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 004a19dd  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a19df  39e9                   +cmp ecx, ebp
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
    // 004a19e1  7e08                   -jle 0x4a19eb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a19eb;
    }
    // 004a19e3  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a19e5  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a19e7  894c2444               -mov dword ptr [esp + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ecx;
L_0x004a19eb:
    // 004a19eb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a19ed  0f8c42010000           -jl 0x4a1b35
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1b35;
    }
    // 004a19f3  837c244400             +cmp dword ptr [esp + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a19f8  0f8c37010000           -jl 0x4a1b35
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1b35;
    }
    // 004a19fe  39d8                   +cmp eax, ebx
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
    // 004a1a00  0f8d2f010000           -jge 0x4a1b35
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1b35;
    }
    // 004a1a06  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1a0a  3b4c2444               +cmp ecx, dword ptr [esp + 0x44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1a0e  0f8d21010000           -jge 0x4a1b35
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1b35;
    }
    // 004a1a14  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a1a18  036c2418               -add ebp, dword ptr [esp + 0x18]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004a1a1c  0faf6c2448             -imul ebp, dword ptr [esp + 0x48]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */))));
    // 004a1a21  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004a1a24  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a1a28  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1a2b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a1a2d  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004a1a30  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004a1a33  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004a1a36  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1a3a  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1a3c  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 004a1a3f  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a1a43  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004a1a46  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004a1a4a  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 004a1a4e  03542418               -add edx, dword ptr [esp + 0x18]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004a1a52  8b2d88904d00           -mov ebp, dword ptr [0x4d9088]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004a1a58  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a1a5b  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a1a5d  8b2d7c904d00           -mov ebp, dword ptr [0x4d907c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */);
    // 004a1a63  032a                   -add ebp, dword ptr [edx]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004a1a65  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004a1a6b  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1a6d  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a1a70  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a1a73  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1a75  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a1a77  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a1a79  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 004a1a7c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a1a7e  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a1a82  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004a1a85  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004a1a89  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1a8b  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a1a8e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004a1a92  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a1a94  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004a1a99  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004a1a9b  b108                   -mov cl, 8
    cpu.cl = 8 /*0x8*/;
    // 004a1a9d  88442424               -mov byte ptr [esp + 0x24], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.al;
    // 004a1aa1  2a4c2410               -sub cl, byte ptr [esp + 0x10]
    (cpu.cl) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004a1aa5  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 004a1aa7  d2e0                   -shl al, cl
    cpu.al <<= cpu.cl % 32;
    // 004a1aa9  88442420               -mov byte ptr [esp + 0x20], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.al;
L_0x004a1aad:
    // 004a1aad  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1ab1  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a1ab4  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a1ab8  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004a1abc  39f0                   +cmp eax, esi
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
    // 004a1abe  0f8d71000000           -jge 0x4a1b35
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1b35;
    }
    // 004a1ac4  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a1ac8  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a1acc  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a1ad0  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a1ad2  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
    // 004a1ad6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a1ad8  7564                   -jne 0x4a1b3e
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b3e;
    }
L_0x004a1ada:
    // 004a1ada  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 004a1adf  0f8591000000           -jne 0x4a1b76
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b76;
    }
L_0x004a1ae5:
    // 004a1ae5  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a1ae9  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a1aed  8b1d84904d00           -mov ebx, dword ptr [0x4d9084]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083268) /* 0x4d9084 */);
    // 004a1af3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1af5  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1af7  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004a1afb  ebb0                   -jmp 0x4a1aad
    goto L_0x004a1aad;
L_0x004a1afd:
    // 004a1afd  770a                   -ja 0x4a1b09
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a1b09;
    }
    // 004a1aff  bfa01f4a00             -mov edi, 0x4a1fa0
    cpu.edi = 4857760 /*0x4a1fa0*/;
    // 004a1b04  e98bfeffff             -jmp 0x4a1994
    goto L_0x004a1994;
L_0x004a1b09:
    // 004a1b09  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1b0b  7228                   -jb 0x4a1b35
    if (cpu.flags.cf)
    {
        goto L_0x004a1b35;
    }
    // 004a1b0d  770a                   -ja 0x4a1b19
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a1b19;
    }
    // 004a1b0f  bff01f4a00             -mov edi, 0x4a1ff0
    cpu.edi = 4857840 /*0x4a1ff0*/;
    // 004a1b14  e97bfeffff             -jmp 0x4a1994
    goto L_0x004a1994;
L_0x004a1b19:
    // 004a1b19  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1b1b  7518                   -jne 0x4a1b35
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b35;
    }
    // 004a1b1d  bf80204a00             -mov edi, 0x4a2080
    cpu.edi = 4857984 /*0x4a2080*/;
    // 004a1b22  e96dfeffff             -jmp 0x4a1994
    goto L_0x004a1994;
L_0x004a1b27:
    // 004a1b27  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1b29  750a                   -jne 0x4a1b35
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b35;
    }
    // 004a1b2b  bfa01f4a00             -mov edi, 0x4a1fa0
    cpu.edi = 4857760 /*0x4a1fa0*/;
    // 004a1b30  e95ffeffff             -jmp 0x4a1994
    goto L_0x004a1994;
L_0x004a1b35:
    // 004a1b35  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a1b38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1b39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1b3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1b3b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a1b3e:
    // 004a1b3e  8a5c2424               -mov bl, byte ptr [esp + 0x24]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a1b42  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a1b44  8b15d8b44d00           -mov edx, dword ptr [0x4db4d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092568) /* 0x4db4d8 */);
    // 004a1b4a  20d8                   -and al, bl
    cpu.al &= x86::reg8(x86::sreg8(cpu.bl));
    // 004a1b4c  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a1b51  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a1b53  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1b55  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a1b57  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 004a1b59  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a1b5a  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
L_0x004a1b5e:
    // 004a1b5e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a1b5f  0f8475ffffff           -je 0x4a1ada
    if (cpu.flags.zf)
    {
        goto L_0x004a1ada;
    }
    // 004a1b65  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a1b67  8b15d8b44d00           -mov edx, dword ptr [0x4db4d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092568) /* 0x4db4d8 */);
    // 004a1b6d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a1b6f  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a1b70  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1b72  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a1b74  ebe8                   -jmp 0x4a1b5e
    goto L_0x004a1b5e;
L_0x004a1b76:
    // 004a1b76  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a1b78  8a642428               -mov ah, byte ptr [esp + 0x28]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a1b7c  8a4c2420               -mov cl, byte ptr [esp + 0x20]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a1b80  20e0                   -and al, ah
    cpu.al &= x86::reg8(x86::sreg8(cpu.ah));
    // 004a1b82  8b15d8b44d00           -mov edx, dword ptr [0x4db4d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092568) /* 0x4db4d8 */);
    // 004a1b88  20c8                   -and al, cl
    cpu.al &= x86::reg8(x86::sreg8(cpu.cl));
    // 004a1b8a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a1b8f  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1b91  e94fffffff             -jmp 0x4a1ae5
    goto L_0x004a1ae5;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a1b98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1b98);
    // 004a1b98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1b99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1b9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1b9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1b9c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1b9d  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 004a1ba3  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 004a1baa  8994240c030000         -mov dword ptr [esp + 0x30c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */) = cpu.edx;
    // 004a1bb1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1bb3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a1bb5:
    // 004a1bb5  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a1bb8  8b88a0ea5600           -mov ecx, dword ptr [eax + 0x56eaa0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5696160) /* 0x56eaa0 */);
    // 004a1bbe  8b98a0ea5600           -mov ebx, dword ptr [eax + 0x56eaa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5696160) /* 0x56eaa0 */);
    // 004a1bc4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a1bc7  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a1bca  884c14fd               -mov byte ptr [esp + edx - 3], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-3) /* -0x3 */ + cpu.edx * 1) = cpu.cl;
    // 004a1bce  885c14fe               -mov byte ptr [esp + edx - 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.edx * 1) = cpu.bl;
    // 004a1bd2  8a98a0ea5600           -mov bl, byte ptr [eax + 0x56eaa0]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5696160) /* 0x56eaa0 */);
    // 004a1bd8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1bdb  885c14ff               -mov byte ptr [esp + edx - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1) = cpu.bl;
    // 004a1bdf  3d00040000             +cmp eax, 0x400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1be4  75cf                   -jne 0x4a1bb5
    if (!cpu.flags.zf)
    {
        goto L_0x004a1bb5;
    }
    // 004a1be6  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004a1bed  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a1bef  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a1bf2  89bc2404030000         -mov dword ptr [esp + 0x304], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.edi;
    // 004a1bf9  89842408030000         -mov dword ptr [esp + 0x308], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */) = cpu.eax;
L_0x004a1c00:
    // 004a1c00  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 004a1c07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1c09  8a0414                 -mov al, byte ptr [esp + edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 004a1c0c  89842418030000         -mov dword ptr [esp + 0x318], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.eax;
    // 004a1c13  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1c15  8a441401               -mov al, byte ptr [esp + edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.edx * 1);
    // 004a1c19  89842410030000         -mov dword ptr [esp + 0x310], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */) = cpu.eax;
    // 004a1c20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1c22  8b8c2400030000         -mov ecx, dword ptr [esp + 0x300]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004a1c29  8a441402               -mov al, byte ptr [esp + edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.edx * 1);
    // 004a1c2d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a1c2f  89842414030000         -mov dword ptr [esp + 0x314], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */) = cpu.eax;
L_0x004a1c36:
    // 004a1c36  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1c38  8a5103                 -mov dl, byte ptr [ecx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 004a1c3b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1c3d  754b                   -jne 0x4a1c8a
    if (!cpu.flags.zf)
    {
        goto L_0x004a1c8a;
    }
    // 004a1c3f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a1c41:
    // 004a1c41  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a1c43  8b9c240c030000         -mov ebx, dword ptr [esp + 0x30c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 004a1c4a  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 004a1c4c  8bac2408030000         -mov ebp, dword ptr [esp + 0x308]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 004a1c53  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1c55  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1c58  81c600010000           -add esi, 0x100
    (cpu.esi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004a1c5e  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004a1c60  39e9                   +cmp ecx, ebp
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
    // 004a1c62  75d2                   -jne 0x4a1c36
    if (!cpu.flags.zf)
    {
        goto L_0x004a1c36;
    }
    // 004a1c64  8b842404030000         -mov eax, dword ptr [esp + 0x304]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 004a1c6b  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a1c6e  47                     -inc edi
    (cpu.edi)++;
    // 004a1c6f  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 004a1c76  81ff00010000           +cmp edi, 0x100
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1c7c  7c82                   -jl 0x4a1c00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1c00;
    }
    // 004a1c7e  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 004a1c84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1c85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1c86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1c87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1c88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1c89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1c8a:
    // 004a1c8a  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004a1c8f  89942424030000         -mov dword ptr [esp + 0x324], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.edx;
    // 004a1c96  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1c98  8b942418030000         -mov edx, dword ptr [esp + 0x318]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */);
    // 004a1c9f  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a1ca2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1ca4  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004a1ca7  8984241c030000         -mov dword ptr [esp + 0x31c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */) = cpu.eax;
    // 004a1cae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1cb0  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a1cb2  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 004a1cbd  89842420030000         -mov dword ptr [esp + 0x320], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */) = cpu.eax;
    // 004a1cc4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a1cc6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a1cc9  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a1cd0  0384241c030000         -add eax, dword ptr [esp + 0x31c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */)));
    // 004a1cd7  0fb66901               -movzx ebp, byte ptr [ecx + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */));
    // 004a1cdb  3dff000000             +cmp eax, 0xff
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
    // 004a1ce0  7e05                   -jle 0x4a1ce7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1ce7;
    }
    // 004a1ce2  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004a1ce7:
    // 004a1ce7  8b942410030000         -mov edx, dword ptr [esp + 0x310]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 004a1cee  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a1cf1  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 004a1cfc  89842428030000         -mov dword ptr [esp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 004a1d03  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a1d05  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a1d08  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a1d0f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a1d11  3dff000000             +cmp eax, 0xff
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
    // 004a1d16  7e05                   -jle 0x4a1d1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1d1d;
    }
    // 004a1d18  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004a1d1d:
    // 004a1d1d  8b942414030000         -mov edx, dword ptr [esp + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 004a1d24  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a1d27  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a1d29  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004a1d2e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a1d30  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a1d33  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a1d35  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 004a1d3c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1d3e  39da                   +cmp edx, ebx
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
    // 004a1d40  7e02                   -jle 0x4a1d44
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1d44;
    }
    // 004a1d42  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004a1d44:
    // 004a1d44  8b842424030000         -mov eax, dword ptr [esp + 0x324]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 004a1d4b  8b9c2428030000         -mov ebx, dword ptr [esp + 0x328]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */);
    // 004a1d52  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a1d55  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004a1d58  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 004a1d5b  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1d5d  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a1d5f  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a1d61  e876edfdff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 004a1d66  e9d6feffff             -jmp 0x4a1c41
    goto L_0x004a1c41;
}

/* align: skip 0x90 */
void Application::sub_4a1d6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1d6c);
    // 004a1d6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1d6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1d6e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1d6f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1d70  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1d71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1d72  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a1d75  8b1538b54d00           -mov edx, dword ptr [0x4db538]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092664) /* 0x4db538 */);
    // 004a1d7b  e8a044ffff             -call 0x496220
    cpu.esp -= 4;
    sub_496220(app, cpu);
    if (cpu.terminate) return;
    // 004a1d80  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a1d82  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a1d84  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1d89  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a1d8c  6be800                 -imul ebp, eax, 0
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004a1d8f  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a1d92  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1d98  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004a1d9c  6bdb00                 -imul ebx, ebx, 0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004a1d9f  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a1da2  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1da8  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004a1dac  6bff00                 -imul edi, edi, 0
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004a1daf  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a1db3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a1db5  8d4240                 -lea eax, [edx + 0x40]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004a1db8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a1dba  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a1dbe:
    // 004a1dbe  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004a1dc6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a1dc8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a1dca  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a1dcd  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a1dd1  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004a1dd9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a1ddb  884103                 -mov byte ptr [ecx + 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004a1dde  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a1de0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a1de3  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a1de7  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004a1def  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a1df1  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a1df4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a1df6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a1df9  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a1dfd  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004a1e05  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a1e07  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a1e0a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a1e0c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a1e0f  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a1e13  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1e16  81c6ff000000           -add esi, 0xff
    (cpu.esi) += x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1e1c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a1e1f  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 004a1e22  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a1e26  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a1e28  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1e2c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1e2e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a1e32  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a1e34  39c1                   +cmp ecx, eax
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
    // 004a1e36  7586                   -jne 0x4a1dbe
    if (!cpu.flags.zf)
    {
        goto L_0x004a1dbe;
    }
    // 004a1e38  803d78904d0008         +cmp byte ptr [0x4d9078], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1e3f  760a                   -jbe 0x4a1e4b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a1e4b;
    }
    // 004a1e41  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a1e44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e47  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1e4b:
    // 004a1e4b  8b1538b54d00           -mov edx, dword ptr [0x4db538]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092664) /* 0x4db538 */);
    // 004a1e51  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a1e55  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a1e58  e83bfdffff             -call 0x4a1b98
    cpu.esp -= 4;
    sub_4a1b98(app, cpu);
    if (cpu.terminate) return;
    // 004a1e5d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a1e60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a1e68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1e68);
    // 004a1e68  833d38b54d0000         +cmp dword ptr [0x4db538], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092664) /* 0x4db538 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1e6f  7519                   -jne 0x4a1e8a
    if (!cpu.flags.zf)
    {
        goto L_0x004a1e8a;
    }
    // 004a1e71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1e72  b940100000             -mov ecx, 0x1040
    cpu.ecx = 4160 /*0x1040*/;
    // 004a1e77  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a1e79  890d3cb54d00           -mov dword ptr [0x4db53c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092668) /* 0x4db53c */) = cpu.ecx;
    // 004a1e7f  e8cc74ffff             -call 0x499350
    cpu.esp -= 4;
    sub_499350(app, cpu);
    if (cpu.terminate) return;
    // 004a1e84  a338b54d00             -mov dword ptr [0x4db538], eax
    app->getMemory<x86::reg32>(x86::reg32(5092664) /* 0x4db538 */) = cpu.eax;
    // 004a1e89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a1e8a:
    // 004a1e8a  e835000000             -call 0x4a1ec4
    cpu.esp -= 4;
    sub_4a1ec4(app, cpu);
    if (cpu.terminate) return;
    // 004a1e8f  833dc0b44d0001         +cmp dword ptr [0x4db4c0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092544) /* 0x4db4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1e96  7414                   -je 0x4a1eac
    if (cpu.flags.zf)
    {
        goto L_0x004a1eac;
    }
    // 004a1e98  833dc4b44d0000         +cmp dword ptr [0x4db4c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092548) /* 0x4db4c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1e9f  7416                   -je 0x4a1eb7
    if (cpu.flags.zf)
    {
        goto L_0x004a1eb7;
    }
    // 004a1ea1  c70540b54d00a0134a00   -mov dword ptr [0x4db540], 0x4a13a0
    app->getMemory<x86::reg32>(x86::reg32(5092672) /* 0x4db540 */) = 4854688 /*0x4a13a0*/;
    // 004a1eab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1eac:
    // 004a1eac  c70540b54d0060194a00   -mov dword ptr [0x4db540], 0x4a1960
    app->getMemory<x86::reg32>(x86::reg32(5092672) /* 0x4db540 */) = 4856160 /*0x4a1960*/;
    // 004a1eb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1eb7:
    // 004a1eb7  c70540b54d0070184a00   -mov dword ptr [0x4db540], 0x4a1870
    app->getMemory<x86::reg32>(x86::reg32(5092672) /* 0x4db540 */) = 4855920 /*0x4a1870*/;
    // 004a1ec1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a1ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1ec4);
    // 004a1ec4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1ec5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1ec6  833d5cb54d0000         +cmp dword ptr [0x4db55c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092700) /* 0x4db55c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1ecd  7515                   -jne 0x4a1ee4
    if (!cpu.flags.zf)
    {
        goto L_0x004a1ee4;
    }
    // 004a1ecf  833dc4b44d0000         +cmp dword ptr [0x4db4c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092548) /* 0x4db4c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1ed6  7409                   -je 0x4a1ee1
    if (cpu.flags.zf)
    {
        goto L_0x004a1ee1;
    }
    // 004a1ed8  833dc0b44d0004         +cmp dword ptr [0x4db4c0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092544) /* 0x4db4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1edf  7431                   -je 0x4a1f12
    if (cpu.flags.zf)
    {
        goto L_0x004a1f12;
    }
L_0x004a1ee1:
    // 004a1ee1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1ee2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1ee3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1ee4:
    // 004a1ee4  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 004a1ee9  b8e0b44d00             -mov eax, 0x4db4e0
    cpu.eax = 5092576 /*0x4db4e0*/;
    // 004a1eee  8b1538b54d00           -mov edx, dword ptr [0x4db538]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092664) /* 0x4db538 */);
    // 004a1ef4  e8077cfeff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004a1ef9  803d78904d0008         +cmp byte ptr [0x4d9078], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1f00  77df                   -ja 0x4a1ee1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a1ee1;
    }
    // 004a1f02  a138b54d00             -mov eax, dword ptr [0x4db538]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092664) /* 0x4db538 */);
    // 004a1f07  8d5040                 -lea edx, [eax + 0x40]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004a1f0a  e889fcffff             -call 0x4a1b98
    cpu.esp -= 4;
    sub_4a1b98(app, cpu);
    if (cpu.terminate) return;
    // 004a1f0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1f12:
    // 004a1f12  a1d8b44d00             -mov eax, dword ptr [0x4db4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092568) /* 0x4db4d8 */);
    // 004a1f17  e850feffff             -call 0x4a1d6c
    cpu.esp -= 4;
    sub_4a1d6c(app, cpu);
    if (cpu.terminate) return;
    // 004a1f1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a1f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1f20);
    // 004a1f20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1f21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1f22  8b1538b54d00           -mov edx, dword ptr [0x4db538]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092664) /* 0x4db538 */);
    // 004a1f28  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1f2a  750b                   -jne 0x4a1f37
    if (!cpu.flags.zf)
    {
        goto L_0x004a1f37;
    }
    // 004a1f2c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a1f2e  893540b54d00           -mov dword ptr [0x4db540], esi
    app->getMemory<x86::reg32>(x86::reg32(5092672) /* 0x4db540 */) = cpu.esi;
    // 004a1f34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f35  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1f37:
    // 004a1f37  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1f38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a1f3a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1f3c  e87774ffff             -call 0x4993b8
    cpu.esp -= 4;
    sub_4993b8(app, cpu);
    if (cpu.terminate) return;
    // 004a1f41  890d38b54d00           -mov dword ptr [0x4db538], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092664) /* 0x4db538 */) = cpu.ecx;
    // 004a1f47  890d3cb54d00           -mov dword ptr [0x4db53c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092668) /* 0x4db53c */) = cpu.ecx;
    // 004a1f4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f4e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a1f50  893540b54d00           -mov dword ptr [0x4db540], esi
    app->getMemory<x86::reg32>(x86::reg32(5092672) /* 0x4db540 */) = cpu.esi;
    // 004a1f56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a1f5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1f5c);
    // 004a1f5c  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a1f5e  7532                   -jne 0x4a1f92
    if (!cpu.flags.zf)
    {
        goto L_0x004a1f92;
    }
L_0x004a1f60:
    // 004a1f60  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a1f62  7403                   -je 0x4a1f67
    if (cpu.flags.zf)
    {
        goto L_0x004a1f67;
    }
    // 004a1f64  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
L_0x004a1f67:
    // 004a1f67  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 004a1f69  7403                   -je 0x4a1f6e
    if (cpu.flags.zf)
    {
        goto L_0x004a1f6e;
    }
    // 004a1f6b  885302                 -mov byte ptr [ebx + 2], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x004a1f6e:
    // 004a1f6e  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004a1f70  7403                   -je 0x4a1f75
    if (cpu.flags.zf)
    {
        goto L_0x004a1f75;
    }
    // 004a1f72  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
L_0x004a1f75:
    // 004a1f75  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a1f77  7403                   -je 0x4a1f7c
    if (cpu.flags.zf)
    {
        goto L_0x004a1f7c;
    }
    // 004a1f79  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
L_0x004a1f7c:
    // 004a1f7c  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a1f7e  7403                   -je 0x4a1f83
    if (cpu.flags.zf)
    {
        goto L_0x004a1f83;
    }
    // 004a1f80  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
L_0x004a1f83:
    // 004a1f83  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a1f85  7403                   -je 0x4a1f8a
    if (cpu.flags.zf)
    {
        goto L_0x004a1f8a;
    }
    // 004a1f87  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
L_0x004a1f8a:
    // 004a1f8a  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a1f8c  7508                   -jne 0x4a1f96
    if (!cpu.flags.zf)
    {
        goto L_0x004a1f96;
    }
    // 004a1f8e  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a1f91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1f92:
    // 004a1f92  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004a1f94  ebca                   -jmp 0x4a1f60
    goto L_0x004a1f60;
L_0x004a1f96:
    // 004a1f96  885307                 -mov byte ptr [ebx + 7], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.dl;
    // 004a1f99  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a1f9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a1fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1fa0);
    // 004a1fa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1fa1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a1fa3  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a1fa5  7539                   -jne 0x4a1fe0
    if (!cpu.flags.zf)
    {
        goto L_0x004a1fe0;
    }
L_0x004a1fa7:
    // 004a1fa7  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a1fa9  7404                   -je 0x4a1faf
    if (cpu.flags.zf)
    {
        goto L_0x004a1faf;
    }
    // 004a1fab  66895102               -mov word ptr [ecx + 2], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
L_0x004a1faf:
    // 004a1faf  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 004a1fb1  7404                   -je 0x4a1fb7
    if (cpu.flags.zf)
    {
        goto L_0x004a1fb7;
    }
    // 004a1fb3  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x004a1fb7:
    // 004a1fb7  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004a1fb9  7404                   -je 0x4a1fbf
    if (cpu.flags.zf)
    {
        goto L_0x004a1fbf;
    }
    // 004a1fbb  66895106               -mov word ptr [ecx + 6], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.dx;
L_0x004a1fbf:
    // 004a1fbf  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a1fc1  7404                   -je 0x4a1fc7
    if (cpu.flags.zf)
    {
        goto L_0x004a1fc7;
    }
    // 004a1fc3  66895108               -mov word ptr [ecx + 8], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.dx;
L_0x004a1fc7:
    // 004a1fc7  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a1fc9  7404                   -je 0x4a1fcf
    if (cpu.flags.zf)
    {
        goto L_0x004a1fcf;
    }
    // 004a1fcb  6689510a               -mov word ptr [ecx + 0xa], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.dx;
L_0x004a1fcf:
    // 004a1fcf  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a1fd1  7404                   -je 0x4a1fd7
    if (cpu.flags.zf)
    {
        goto L_0x004a1fd7;
    }
    // 004a1fd3  6689510c               -mov word ptr [ecx + 0xc], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
L_0x004a1fd7:
    // 004a1fd7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a1fd9  750a                   -jne 0x4a1fe5
    if (!cpu.flags.zf)
    {
        goto L_0x004a1fe5;
    }
    // 004a1fdb  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a1fde  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fdf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1fe0:
    // 004a1fe0  668913                 -mov word ptr [ebx], dx
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.dx;
    // 004a1fe3  ebc2                   -jmp 0x4a1fa7
    goto L_0x004a1fa7;
L_0x004a1fe5:
    // 004a1fe5  6689510e               -mov word ptr [ecx + 0xe], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 004a1fe9  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a1fec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a1ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a1ff0);
    // 004a1ff0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1ff1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1ff4  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a1ff7  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a1ffa  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004a1ffd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a2000  88cc                   -mov ah, cl
    cpu.ah = cpu.cl;
    // 004a2002  8a3424                 -mov dh, byte ptr [esp]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp);
    // 004a2005  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a2007  755a                   -jne 0x4a2063
    if (!cpu.flags.zf)
    {
        goto L_0x004a2063;
    }
L_0x004a2009:
    // 004a2009  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a200b  7409                   -je 0x4a2016
    if (cpu.flags.zf)
    {
        goto L_0x004a2016;
    }
    // 004a200d  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
    // 004a2010  886304                 -mov byte ptr [ebx + 4], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 004a2013  887305                 -mov byte ptr [ebx + 5], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dh;
L_0x004a2016:
    // 004a2016  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 004a2018  7409                   -je 0x4a2023
    if (cpu.flags.zf)
    {
        goto L_0x004a2023;
    }
    // 004a201a  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004a201d  886307                 -mov byte ptr [ebx + 7], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.ah;
    // 004a2020  887308                 -mov byte ptr [ebx + 8], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.dh;
L_0x004a2023:
    // 004a2023  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004a2025  7409                   -je 0x4a2030
    if (cpu.flags.zf)
    {
        goto L_0x004a2030;
    }
    // 004a2027  885309                 -mov byte ptr [ebx + 9], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = cpu.dl;
    // 004a202a  88630a                 -mov byte ptr [ebx + 0xa], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.ah;
    // 004a202d  88730b                 -mov byte ptr [ebx + 0xb], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = cpu.dh;
L_0x004a2030:
    // 004a2030  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a2032  7409                   -je 0x4a203d
    if (cpu.flags.zf)
    {
        goto L_0x004a203d;
    }
    // 004a2034  88530c                 -mov byte ptr [ebx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004a2037  88630d                 -mov byte ptr [ebx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004a203a  88730e                 -mov byte ptr [ebx + 0xe], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.dh;
L_0x004a203d:
    // 004a203d  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a203f  7409                   -je 0x4a204a
    if (cpu.flags.zf)
    {
        goto L_0x004a204a;
    }
    // 004a2041  88530f                 -mov byte ptr [ebx + 0xf], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 004a2044  886310                 -mov byte ptr [ebx + 0x10], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 004a2047  887311                 -mov byte ptr [ebx + 0x11], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = cpu.dh;
L_0x004a204a:
    // 004a204a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a204c  7409                   -je 0x4a2057
    if (cpu.flags.zf)
    {
        goto L_0x004a2057;
    }
    // 004a204e  885312                 -mov byte ptr [ebx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004a2051  886313                 -mov byte ptr [ebx + 0x13], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(19) /* 0x13 */) = cpu.ah;
    // 004a2054  887314                 -mov byte ptr [ebx + 0x14], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.dh;
L_0x004a2057:
    // 004a2057  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a2059  7512                   -jne 0x4a206d
    if (!cpu.flags.zf)
    {
        goto L_0x004a206d;
    }
    // 004a205b  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004a205e  83c404                 +add esp, 4
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
    // 004a2061  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2062  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2063:
    // 004a2063  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004a2065  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004a2068  887302                 -mov byte ptr [ebx + 2], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dh;
    // 004a206b  eb9c                   -jmp 0x4a2009
    goto L_0x004a2009;
L_0x004a206d:
    // 004a206d  885315                 -mov byte ptr [ebx + 0x15], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = cpu.dl;
    // 004a2070  886316                 -mov byte ptr [ebx + 0x16], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = cpu.ah;
    // 004a2073  887317                 -mov byte ptr [ebx + 0x17], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */) = cpu.dh;
    // 004a2076  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004a2079  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a207c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a207d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a2080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a2080);
    // 004a2080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2081  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a2083  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a2085  7533                   -jne 0x4a20ba
    if (!cpu.flags.zf)
    {
        goto L_0x004a20ba;
    }
L_0x004a2087:
    // 004a2087  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a2089  7403                   -je 0x4a208e
    if (cpu.flags.zf)
    {
        goto L_0x004a208e;
    }
    // 004a208b  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004a208e:
    // 004a208e  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 004a2090  7403                   -je 0x4a2095
    if (cpu.flags.zf)
    {
        goto L_0x004a2095;
    }
    // 004a2092  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x004a2095:
    // 004a2095  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004a2097  7403                   -je 0x4a209c
    if (cpu.flags.zf)
    {
        goto L_0x004a209c;
    }
    // 004a2099  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004a209c:
    // 004a209c  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a209e  7403                   -je 0x4a20a3
    if (cpu.flags.zf)
    {
        goto L_0x004a20a3;
    }
    // 004a20a0  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x004a20a3:
    // 004a20a3  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a20a5  7403                   -je 0x4a20aa
    if (cpu.flags.zf)
    {
        goto L_0x004a20aa;
    }
    // 004a20a7  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x004a20aa:
    // 004a20aa  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a20ac  7403                   -je 0x4a20b1
    if (cpu.flags.zf)
    {
        goto L_0x004a20b1;
    }
    // 004a20ae  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004a20b1:
    // 004a20b1  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a20b3  7509                   -jne 0x4a20be
    if (!cpu.flags.zf)
    {
        goto L_0x004a20be;
    }
    // 004a20b5  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a20b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a20b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a20ba:
    // 004a20ba  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a20bc  ebc9                   -jmp 0x4a2087
    goto L_0x004a2087;
L_0x004a20be:
    // 004a20be  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a20c1  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a20c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a20c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a20c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a20c6);
    // 004a20c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a20c8  7503                   -jne 0x4a20cd
    if (!cpu.flags.zf)
    {
        goto L_0x004a20cd;
    }
    // 004a20ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a20cc:
    // 004a20cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a20cd:
    // 004a20cd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a20cf  74fb                   -je 0x4a20cc
    if (cpu.flags.zf)
    {
        goto L_0x004a20cc;
    }
    // 004a20d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a20d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a20d4  e873010000             -call 0x4a224c
    cpu.esp -= 4;
    sub_4a224c(app, cpu);
    if (cpu.terminate) return;
    // 004a20d9  83fa7b                 +cmp edx, 0x7b
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
    // 004a20dc  7507                   -jne 0x4a20e5
    if (!cpu.flags.zf)
    {
        goto L_0x004a20e5;
    }
    // 004a20de  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a20e3  eb31                   -jmp 0x4a2116
    goto L_0x004a2116;
L_0x004a20e5:
    // 004a20e5  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a20eb  7507                   -jne 0x4a20f4
    if (!cpu.flags.zf)
    {
        goto L_0x004a20f4;
    }
    // 004a20ed  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a20f2  eb22                   -jmp 0x4a2116
    goto L_0x004a2116;
L_0x004a20f4:
    // 004a20f4  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a20fa  7507                   -jne 0x4a2103
    if (!cpu.flags.zf)
    {
        goto L_0x004a2103;
    }
    // 004a20fc  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004a2101  eb13                   -jmp 0x4a2116
    goto L_0x004a2116;
L_0x004a2103:
    // 004a2103  83fa13                 +cmp edx, 0x13
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
    // 004a2106  7605                   -jbe 0x4a210d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a210d;
    }
    // 004a2108  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x004a210d:
    // 004a210d  8b82e5b84d00           -mov eax, dword ptr [edx + 0x4db8e5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5093605) /* 0x4db8e5 */);
    // 004a2113  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x004a2116:
    // 004a2116  e805010000             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a211b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a2120  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2121  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a20d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a20d1);
    goto L_entry_0x004a20d1;
    // 004a20c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a20c8  7503                   -jne 0x4a20cd
    if (!cpu.flags.zf)
    {
        goto L_0x004a20cd;
    }
    // 004a20ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a20cc:
    // 004a20cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a20cd:
    // 004a20cd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a20cf  74fb                   -je 0x4a20cc
    if (cpu.flags.zf)
    {
        goto L_0x004a20cc;
    }
L_entry_0x004a20d1:
    // 004a20d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a20d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a20d4  e873010000             -call 0x4a224c
    cpu.esp -= 4;
    sub_4a224c(app, cpu);
    if (cpu.terminate) return;
    // 004a20d9  83fa7b                 +cmp edx, 0x7b
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
    // 004a20dc  7507                   -jne 0x4a20e5
    if (!cpu.flags.zf)
    {
        goto L_0x004a20e5;
    }
    // 004a20de  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a20e3  eb31                   -jmp 0x4a2116
    goto L_0x004a2116;
L_0x004a20e5:
    // 004a20e5  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a20eb  7507                   -jne 0x4a20f4
    if (!cpu.flags.zf)
    {
        goto L_0x004a20f4;
    }
    // 004a20ed  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a20f2  eb22                   -jmp 0x4a2116
    goto L_0x004a2116;
L_0x004a20f4:
    // 004a20f4  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a20fa  7507                   -jne 0x4a2103
    if (!cpu.flags.zf)
    {
        goto L_0x004a2103;
    }
    // 004a20fc  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004a2101  eb13                   -jmp 0x4a2116
    goto L_0x004a2116;
L_0x004a2103:
    // 004a2103  83fa13                 +cmp edx, 0x13
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
    // 004a2106  7605                   -jbe 0x4a210d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a210d;
    }
    // 004a2108  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x004a210d:
    // 004a210d  8b82e5b84d00           -mov eax, dword ptr [edx + 0x4db8e5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5093605) /* 0x4db8e5 */);
    // 004a2113  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x004a2116:
    // 004a2116  e805010000             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a211b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a2120  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2121  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2122(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a2122);
    // 004a2122  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2123  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2124  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a212b  e8a1ffffff             -call 0x4a20d1
    cpu.esp -= 4;
    sub_4a20d1(app, cpu);
    if (cpu.terminate) return;
    // 004a2130  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2131  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2132  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2133(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a2133);
    // 004a2133  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2134  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2135  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2136  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2137  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2138  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a2139  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004a213b  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004a213d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a213e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2141  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a2143  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2145  7405                   -je 0x4a214c
    if (cpu.flags.zf)
    {
        goto L_0x004a214c;
    }
    // 004a2147  83f8d4                 +cmp eax, -0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-44 /*-0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a214a  7607                   -jbe 0x4a2153
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a2153;
    }
L_0x004a214c:
    // 004a214c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a214e  e9be000000             -jmp 0x4a2211
    goto L_0x004a2211;
L_0x004a2153:
    // 004a2153  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 004a2156  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 004a2159  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a215c  7305                   -jae 0x4a2163
    if (!cpu.flags.cf)
    {
        goto L_0x004a2163;
    }
    // 004a215e  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x004a2163:
    // 004a2163  ff1538cb4d00           -call dword ptr [0x4dcb38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098296) /* 0x4dcb38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2169  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004a216b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a216d  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004a2170:
    // 004a2170  3b2d04b94d00           +cmp ebp, dword ptr [0x4db904]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5093636) /* 0x4db904 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2176  760c                   -jbe 0x4a2184
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a2184;
    }
    // 004a2178  8b0d00b94d00           -mov ecx, dword ptr [0x4db900]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093632) /* 0x4db900 */);
    // 004a217e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a2180  7510                   -jne 0x4a2192
    if (!cpu.flags.zf)
    {
        goto L_0x004a2192;
    }
    // 004a2182  eb02                   -jmp 0x4a2186
    goto L_0x004a2186;
L_0x004a2184:
    // 004a2184  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a2186:
    // 004a2186  890d04b94d00           -mov dword ptr [0x4db904], ecx
    app->getMemory<x86::reg32>(x86::reg32(5093636) /* 0x4db904 */) = cpu.ecx;
    // 004a218c  8b0dfcb84d00           -mov ecx, dword ptr [0x4db8fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093628) /* 0x4db8fc */);
L_0x004a2192:
    // 004a2192  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a2194  743c                   -je 0x4a21d2
    if (cpu.flags.zf)
    {
        goto L_0x004a21d2;
    }
    // 004a2196  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004a2199  890d00b94d00           -mov dword ptr [0x4db900], ecx
    app->getMemory<x86::reg32>(x86::reg32(5093632) /* 0x4db900 */) = cpu.ecx;
    // 004a219f  39fe                   +cmp esi, edi
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
    // 004a21a1  721c                   -jb 0x4a21bf
    if (cpu.flags.cf)
    {
        goto L_0x004a21bf;
    }
    // 004a21a3  b8fcb84d00             -mov eax, 0x4db8fc
    cpu.eax = 5093628 /*0x4db8fc*/;
    // 004a21a8  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004a21aa  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a21b0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a21b2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a21b4  e827010100             -call 0x4b22e0
    cpu.esp -= 4;
    sub_4b22e0(app, cpu);
    if (cpu.terminate) return;
    // 004a21b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a21bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a21bd  7542                   -jne 0x4a2201
    if (!cpu.flags.zf)
    {
        goto L_0x004a2201;
    }
L_0x004a21bf:
    // 004a21bf  3b3504b94d00           +cmp esi, dword ptr [0x4db904]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5093636) /* 0x4db904 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a21c5  7606                   -jbe 0x4a21cd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a21cd;
    }
    // 004a21c7  893504b94d00           -mov dword ptr [0x4db904], esi
    app->getMemory<x86::reg32>(x86::reg32(5093636) /* 0x4db904 */) = cpu.esi;
L_0x004a21cd:
    // 004a21cd  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a21d0  ebc0                   -jmp 0x4a2192
    goto L_0x004a2192;
L_0x004a21d2:
    // 004a21d2  803c2400               +cmp byte ptr [esp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a21d6  750b                   -jne 0x4a21e3
    if (!cpu.flags.zf)
    {
        goto L_0x004a21e3;
    }
    // 004a21d8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a21da  e8e7030100             -call 0x4b25c6
    cpu.esp -= 4;
    sub_4b25c6(app, cpu);
    if (cpu.terminate) return;
    // 004a21df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a21e1  7515                   -jne 0x4a21f8
    if (!cpu.flags.zf)
    {
        goto L_0x004a21f8;
    }
L_0x004a21e3:
    // 004a21e3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a21e5  e837040100             -call 0x4b2621
    cpu.esp -= 4;
    sub_4b2621(app, cpu);
    if (cpu.terminate) return;
    // 004a21ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a21ec  7413                   -je 0x4a2201
    if (cpu.flags.zf)
    {
        goto L_0x004a2201;
    }
    // 004a21ee  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 004a21f0  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 004a21f3  e978ffffff             -jmp 0x4a2170
    goto L_0x004a2170;
L_0x004a21f8:
    // 004a21f8  c6042401               -mov byte ptr [esp], 1
    app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 004a21fc  e96fffffff             -jmp 0x4a2170
    goto L_0x004a2170;
L_0x004a2201:
    // 004a2201  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 004a2203  882d20715b00           -mov byte ptr [0x5b7120], ch
    app->getMemory<x86::reg8>(x86::reg32(5992736) /* 0x5b7120 */) = cpu.ch;
    // 004a2209  ff1540cb4d00           -call dword ptr [0x4dcb40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098304) /* 0x4dcb40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a220f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004a2211:
    // 004a2211  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2214  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2215  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a2217  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a2219  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a221a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a221b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a221c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a221d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a221e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a221f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a2220);
    // 004a2220  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2221  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a2223  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2229  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a222c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a222d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a222e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a222e);
    // 004a222e  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 004a2233  ebeb                   -jmp 0x4a2220
    return sub_4a2220(app, cpu);
}

/* align: skip  */
void Application::sub_4a2235(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a2235);
    // 004a2235  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004a223a  ebe4                   -jmp 0x4a2220
    return sub_4a2220(app, cpu);
}

/* align: skip  */
void Application::sub_4a223c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a223c);
    // 004a223c  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a2241  e8daffffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a2246  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a224b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a224c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a224c);
    // 004a224c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a224d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a224f  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2255  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a2258  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2259  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a225c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a225c);
    // 004a225c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a225d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a225e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a225f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2260  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a2262  8b3df81c5600           -mov edi, dword ptr [0x561cf8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5643512) /* 0x561cf8 */);
    // 004a2268  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a226a  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 004a2270  7420                   -je 0x4a2292
    if (cpu.flags.zf)
    {
        goto L_0x004a2292;
    }
    // 004a2272  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2275  7818                   -js 0x4a228f
    if (cpu.flags.sf)
    {
        goto L_0x004a228f;
    }
L_0x004a2277:
    // 004a2277  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2279  80f9ff                 +cmp cl, 0xff
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
    // 004a227c  7411                   -je 0x4a228f
    if (cpu.flags.zf)
    {
        goto L_0x004a228f;
    }
    // 004a227e  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a2281  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 004a2284  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a2287  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a228a  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a228d  79e8                   -jns 0x4a2277
    if (!cpu.flags.sf)
    {
        goto L_0x004a2277;
    }
L_0x004a228f:
    // 004a228f  83c501                 -add ebp, 1
    (cpu.ebp) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a2292:
    // 004a2292  83ed02                 +sub ebp, 2
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
    // 004a2295  7859                   -js 0x4a22f0
    if (cpu.flags.sf)
    {
        goto L_0x004a22f0;
    }
L_0x004a2297:
    // 004a2297  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2299  80f9ff                 +cmp cl, 0xff
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
    // 004a229c  7428                   -je 0x4a22c6
    if (cpu.flags.zf)
    {
        goto L_0x004a22c6;
    }
    // 004a229e  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a22a1  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a22a4  80f9ff                 +cmp cl, 0xff
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
    // 004a22a7  7439                   -je 0x4a22e2
    if (cpu.flags.zf)
    {
        goto L_0x004a22e2;
    }
    // 004a22a9  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a22ac  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a22b2  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004a22b5  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a22b7  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
L_0x004a22b9:
    // 004a22b9  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a22bc  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a22bf  83ed02                 +sub ebp, 2
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
    // 004a22c2  79d3                   -jns 0x4a2297
    if (!cpu.flags.sf)
    {
        goto L_0x004a2297;
    }
    // 004a22c4  eb2a                   -jmp 0x4a22f0
    goto L_0x004a22f0;
L_0x004a22c6:
    // 004a22c6  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a22c9  80f9ff                 +cmp cl, 0xff
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
    // 004a22cc  74eb                   -je 0x4a22b9
    if (cpu.flags.zf)
    {
        goto L_0x004a22b9;
    }
    // 004a22ce  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a22d1  66895a02               -mov word ptr [edx + 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bx;
    // 004a22d5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a22d8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a22db  83ed02                 +sub ebp, 2
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
    // 004a22de  79b7                   -jns 0x4a2297
    if (!cpu.flags.sf)
    {
        goto L_0x004a2297;
    }
    // 004a22e0  eb0e                   -jmp 0x4a22f0
    goto L_0x004a22f0;
L_0x004a22e2:
    // 004a22e2  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 004a22e5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a22e8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a22eb  83ed02                 +sub ebp, 2
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
    // 004a22ee  79a7                   -jns 0x4a2297
    if (!cpu.flags.sf)
    {
        goto L_0x004a2297;
    }
L_0x004a22f0:
    // 004a22f0  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a22f3  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a22f6  7818                   -js 0x4a2310
    if (cpu.flags.sf)
    {
        goto L_0x004a2310;
    }
L_0x004a22f8:
    // 004a22f8  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a22fa  80f9ff                 +cmp cl, 0xff
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
    // 004a22fd  7411                   -je 0x4a2310
    if (cpu.flags.zf)
    {
        goto L_0x004a2310;
    }
    // 004a22ff  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a2302  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 004a2305  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a2308  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a230b  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a230e  79e8                   -jns 0x4a22f8
    if (!cpu.flags.sf)
    {
        goto L_0x004a22f8;
    }
L_0x004a2310:
    // 004a2310  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2311  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2312  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2313  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2314  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a2318(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a2318);
    // 004a2318  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2319  ff0d0eba4d00           +dec dword ptr [0x4dba0e]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5093902) /* 0x4dba0e */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a231f  753f                   -jne 0x4a2360
    if (!cpu.flags.zf)
    {
        goto L_0x004a2360;
    }
    // 004a2321  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a2323  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 004a2325  7421                   -je 0x4a2348
    if (cpu.flags.zf)
    {
        goto L_0x004a2348;
    }
    // 004a2327  83e27f                 +and edx, 0x7f
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(127 /*0x7f*/))));
    // 004a232a  8a9208b94d00           -mov dl, byte ptr [edx + 0x4db908]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5093640) /* 0x4db908 */);
L_0x004a2330:
    // 004a2330  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a2331  7c2d                   -jl 0x4a2360
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2360;
    }
    // 004a2333  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2334  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2335  ff149512ba4d00         -call dword ptr [edx*4 + 0x4dba12]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093906) /* 0x4dba12 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a233c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a233d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a233e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2340  ff050eba4d00           -inc dword ptr [0x4dba0e]
    (app->getMemory<x86::reg32>(x86::reg32(5093902) /* 0x4dba0e */))++;
    // 004a2346  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2347  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2348:
    // 004a2348  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 004a234b  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2351  7c05                   -jl 0x4a2358
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2358;
    }
    // 004a2353  ba84000000             -mov edx, 0x84
    cpu.edx = 132 /*0x84*/;
L_0x004a2358:
    // 004a2358  8a9288b94d00           -mov dl, byte ptr [edx + 0x4db988]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5093768) /* 0x4db988 */);
    // 004a235e  ebd0                   -jmp 0x4a2330
    goto L_0x004a2330;
L_0x004a2360:
    // 004a2360  ff050eba4d00           -inc dword ptr [0x4dba0e]
    (app->getMemory<x86::reg32>(x86::reg32(5093902) /* 0x4dba0e */))++;
    // 004a2366  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2367  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2368(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a2368);
    // 004a2368  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2369  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a236a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a236b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a236d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a236f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a2371  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 004a2376  ba12ba4d00             -mov edx, 0x4dba12
    cpu.edx = 5093906 /*0x4dba12*/;
L_0x004a237b:
    // 004a237b  3902                   +cmp dword ptr [edx], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a237d  7412                   -je 0x4a2391
    if (cpu.flags.zf)
    {
        goto L_0x004a2391;
    }
    // 004a237f  66833a00               +cmp word ptr [edx], 0
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
    // 004a2383  740a                   -je 0x4a238f
    if (cpu.flags.zf)
    {
        goto L_0x004a238f;
    }
    // 004a2385  83c204                 +add edx, 4
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
    // 004a2388  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a2389  75f0                   -jne 0x4a237b
    if (!cpu.flags.zf)
    {
        goto L_0x004a237b;
    }
    // 004a238b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a238c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a238d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a238e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a238f:
    // 004a238f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004a2391:
    // 004a2391  b841000000             -mov eax, 0x41
    cpu.eax = 65 /*0x41*/;
    // 004a2396  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a2398:
    // 004a2398  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a239a  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 004a239c  740f                   -je 0x4a23ad
    if (cpu.flags.zf)
    {
        goto L_0x004a23ad;
    }
    // 004a239e  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a23a1  7f06                   -jg 0x4a23a9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a23a9;
    }
    // 004a23a3  888208b94d00           -mov byte ptr [edx + 0x4db908], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5093640) /* 0x4db908 */) = cpu.al;
L_0x004a23a9:
    // 004a23a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a23ad:
    // 004a23ad  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 004a23b0  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a23b6  7ff1                   -jg 0x4a23a9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a23a9;
    }
    // 004a23b8  888288b94d00           -mov byte ptr [edx + 0x4db988], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5093768) /* 0x4db988 */) = cpu.al;
    // 004a23be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23c1  c3                     -ret 
    cpu.esp += 4;
    return;
    // 004a23c2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a23c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a23c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a23c5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a23c7  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a23c9  ebcd                   -jmp 0x4a2398
    goto L_0x004a2398;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a23d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a23d0);
    // 004a23d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a23d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a23d2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a23d4  42                     -inc edx
    (cpu.edx)++;
    // 004a23d5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a23d7  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a23da  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a23dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a23de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a23e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a23e4);
    // 004a23e4  83f820                 +cmp eax, 0x20
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
    // 004a23e7  7c12                   -jl 0x4a23fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a23fb;
    }
    // 004a23e9  83f87f                 +cmp eax, 0x7f
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
    // 004a23ec  7f0d                   -jg 0x4a23fb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a23fb;
    }
    // 004a23ee  668b0445d8ba4d00       -mov ax, word ptr [eax*2 + 0x4dbad8]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5094104) /* 0x4dbad8 */ + cpu.eax * 2);
    // 004a23f6  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x004a23fb:
    // 004a23fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a23fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a23fc);
    // 004a23fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a23fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a23fe  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a2400  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2402  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004a2404  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004a2406  42                     -inc edx
    (cpu.edx)++;
    // 004a2407  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a2409  7416                   -je 0x4a2421
    if (cpu.flags.zf)
    {
        goto L_0x004a2421;
    }
    // 004a240b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a240c  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004a240e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a2411  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a2413  42                     -inc edx
    (cpu.edx)++;
    // 004a2414  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a2416  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2417  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a2419  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a241e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a241f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2420  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2421:
    // 004a2421  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a2426  e8b9ffffff             -call 0x4a23e4
    cpu.esp -= 4;
    sub_4a23e4(app, cpu);
    if (cpu.terminate) return;
    // 004a242b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a242d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a2432  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2433  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2434  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a2440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a2440);
    // 004a2440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2442  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2443  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2444  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a2446  8b3568904d00           -mov esi, dword ptr [0x4d9068]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004a244c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a244e  39f0                   +cmp eax, esi
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
    // 004a2450  7c4e                   -jl 0x4a24a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a24a0;
    }
    // 004a2452  3b0570904d00           +cmp eax, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2458  7d46                   -jge 0x4a24a0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a24a0;
    }
    // 004a245a  3b156c904d00           +cmp edx, dword ptr [0x4d906c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2460  7c3e                   -jl 0x4a24a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a24a0;
    }
    // 004a2462  3b1574904d00           +cmp edx, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2468  7d36                   -jge 0x4a24a0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a24a0;
    }
    // 004a246a  a188904d00             -mov eax, dword ptr [0x4d9088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004a246f  8b358c904d00           -mov esi, dword ptr [0x4d908c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004a2475  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004a2478  8b3c9e                 -mov edi, dword ptr [esi + ebx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a247b  a17c904d00             -mov eax, dword ptr [0x4d907c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */);
    // 004a2480  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a2482  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a2484  a078904d00             -mov al, byte ptr [0x4d9078]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 004a2489  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a248b  731a                   -jae 0x4a24a7
    if (!cpu.flags.cf)
    {
        goto L_0x004a24a7;
    }
    // 004a248d  3c04                   +cmp al, 4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a248f  720f                   -jb 0x4a24a0
    if (cpu.flags.cf)
    {
        goto L_0x004a24a0;
    }
    // 004a2491  772f                   -ja 0x4a24c2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a24c2;
    }
    // 004a2493  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004a2496  7432                   -je 0x4a24ca
    if (cpu.flags.zf)
    {
        goto L_0x004a24ca;
    }
    // 004a2498  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a249a  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 004a249d  83e10f                 +and ecx, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/))));
L_0x004a24a0:
    // 004a24a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a24a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a24a7:
    // 004a24a7  7608                   -jbe 0x4a24b1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a24b1;
    }
    // 004a24a9  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a24ab  730b                   -jae 0x4a24b8
    if (!cpu.flags.cf)
    {
        goto L_0x004a24b8;
    }
    // 004a24ad  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a24af  75ef                   -jne 0x4a24a0
    if (!cpu.flags.zf)
    {
        goto L_0x004a24a0;
    }
L_0x004a24b1:
    // 004a24b1  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a24b3  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a24b6  ebe8                   -jmp 0x4a24a0
    goto L_0x004a24a0;
L_0x004a24b8:
    // 004a24b8  761c                   -jbe 0x4a24d6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a24d6;
    }
    // 004a24ba  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a24bc  75e2                   -jne 0x4a24a0
    if (!cpu.flags.zf)
    {
        goto L_0x004a24a0;
    }
    // 004a24be  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a24c0  ebde                   -jmp 0x4a24a0
    goto L_0x004a24a0;
L_0x004a24c2:
    // 004a24c2  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a24c4  75da                   -jne 0x4a24a0
    if (!cpu.flags.zf)
    {
        goto L_0x004a24a0;
    }
    // 004a24c6  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a24c8  ebd6                   -jmp 0x4a24a0
    goto L_0x004a24a0;
L_0x004a24ca:
    // 004a24ca  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a24cc  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a24cf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a24d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a24d6:
    // 004a24d6  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004a24db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a24dd  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004a24e1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a24e3  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004a24ea  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a24ec  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a24ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a24f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a24f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a24f8);
    // 004a24f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a24f9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a24fb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a24fd  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a24ff  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2501  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004a2508  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a250a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a250b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a250c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a250c);
    // 004a250c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a250d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a250f  8b4408fc               -mov eax, dword ptr [eax + ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 1);
    // 004a2513  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2515  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004a251c  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a251e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a251f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004a2520);
    // 004a2520  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2521  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a2523  8d4408ff               -lea eax, [eax + ecx - 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a2527  83e901                 +sub ecx, 1
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
    // 004a252a  7c0d                   -jl 0x4a2539
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2539;
    }
L_0x004a252c:
    // 004a252c  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004a252e  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004a2531  83e901                 +sub ecx, 1
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
    // 004a2534  8d40ff                 -lea eax, [eax - 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a2537  7df3                   -jge 0x4a252c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a252c;
    }
L_0x004a2539:
    // 004a2539  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a253a  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
