#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x90 */
void Application::sub_497934(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497934  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497935  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497936  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497937  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00497939  8b15b4a75200           -mov edx, dword ptr [0x52a7b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 0049793f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00497944  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497946  7446                   -je 0x49798e
    if (cpu.flags.zf)
    {
        goto L_0x0049798e;
    }
L_0x00497948:
    // 00497948  a1b4a75200             -mov eax, dword ptr [0x52a7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 0049794d  e87692feff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00497952  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00497954  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00497956:
    // 00497956  83ba80a7520000         +cmp dword ptr [edx + 0x52a780], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5416832) /* 0x52a780 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049795d  7504                   -jne 0x497963
    if (!cpu.flags.zf)
    {
        goto L_0x00497963;
    }
    // 0049795f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00497961  7c32                   -jl 0x497995
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497995;
    }
L_0x00497963:
    // 00497963  3b9a80a75200           +cmp ebx, dword ptr [edx + 0x52a780]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5416832) /* 0x52a780 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497969  7415                   -je 0x497980
    if (cpu.flags.zf)
    {
        goto L_0x00497980;
    }
L_0x0049796b:
    // 0049796b  40                     -inc eax
    (cpu.eax)++;
    // 0049796c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049796f  83f808                 +cmp eax, 8
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
    // 00497972  7ce2                   -jl 0x497956
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497956;
    }
    // 00497974  83f9ff                 +cmp ecx, -1
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
    // 00497977  7407                   -je 0x497980
    if (cpu.flags.zf)
    {
        goto L_0x00497980;
    }
    // 00497979  891c8d80a75200         -mov dword ptr [ecx*4 + 0x52a780], ebx
    app->getMemory<x86::reg32>(x86::reg32(5416832) /* 0x52a780 */ + cpu.ecx * 4) = cpu.ebx;
L_0x00497980:
    // 00497980  a1b4a75200             -mov eax, dword ptr [0x52a7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 00497985  e85692feff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0049798a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049798b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049798c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049798d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049798e:
    // 0049798e  e841ffffff             -call 0x4978d4
    cpu.esp -= 4;
    sub_4978d4(app, cpu);
    if (cpu.terminate) return;
    // 00497993  ebb3                   -jmp 0x497948
    goto L_0x00497948;
L_0x00497995:
    // 00497995  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00497997  ebd2                   -jmp 0x49796b
    goto L_0x0049796b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49799c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049799c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049799d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049799e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049799f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004979a0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004979a2  8b15b4a75200           -mov edx, dword ptr [0x52a7b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 004979a8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004979aa  7505                   -jne 0x4979b1
    if (!cpu.flags.zf)
    {
        goto L_0x004979b1;
    }
L_0x004979ac:
    // 004979ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004979b1:
    // 004979b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004979b3  e81092feff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004979b8  8b1d80a75200           -mov ebx, dword ptr [0x52a780]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5416832) /* 0x52a780 */);
    // 004979be  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004979c0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004979c2  39d9                   +cmp ecx, ebx
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
    // 004979c4  7411                   -je 0x4979d7
    if (cpu.flags.zf)
    {
        goto L_0x004979d7;
    }
L_0x004979c6:
    // 004979c6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004979c9  42                     -inc edx
    (cpu.edx)++;
    // 004979ca  83f820                 +cmp eax, 0x20
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
    // 004979cd  7d08                   -jge 0x4979d7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004979d7;
    }
    // 004979cf  3b8880a75200           +cmp ecx, dword ptr [eax + 0x52a780]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416832) /* 0x52a780 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004979d5  75ef                   -jne 0x4979c6
    if (!cpu.flags.zf)
    {
        goto L_0x004979c6;
    }
L_0x004979d7:
    // 004979d7  83fa08                 +cmp edx, 8
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
    // 004979da  7d30                   -jge 0x497a0c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497a0c;
    }
    // 004979dc  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004979e3  3b8880a75200           +cmp ecx, dword ptr [eax + 0x52a780]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416832) /* 0x52a780 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004979e9  7521                   -jne 0x497a0c
    if (!cpu.flags.zf)
    {
        goto L_0x00497a0c;
    }
    // 004979eb  83fa07                 +cmp edx, 7
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
    // 004979ee  7d14                   -jge 0x497a04
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497a04;
    }
L_0x004979f0:
    // 004979f0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004979f3  8b9080a75200           -mov edx, dword ptr [eax + 0x52a780]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416832) /* 0x52a780 */);
    // 004979f9  89907ca75200           -mov dword ptr [eax + 0x52a77c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416828) /* 0x52a77c */) = cpu.edx;
    // 004979ff  83f81c                 +cmp eax, 0x1c
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
    // 00497a02  7cec                   -jl 0x4979f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004979f0;
    }
L_0x00497a04:
    // 00497a04  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00497a06  892d9ca75200           -mov dword ptr [0x52a79c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5416860) /* 0x52a79c */) = cpu.ebp;
L_0x00497a0c:
    // 00497a0c  a1b4a75200             -mov eax, dword ptr [0x52a7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 00497a11  e8ca91feff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00497a16  8b1580a75200           -mov edx, dword ptr [0x52a780]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5416832) /* 0x52a780 */);
    // 00497a1c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497a1e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
L_0x00497a20:
    // 00497a20  758a                   -jne 0x4979ac
    if (!cpu.flags.zf)
    {
        goto L_0x004979ac;
    }
    // 00497a22  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497a25  83f820                 +cmp eax, 0x20
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
    // 00497a28  7d09                   -jge 0x497a33
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497a33;
    }
    // 00497a2a  83b880a7520000         +cmp dword ptr [eax + 0x52a780], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416832) /* 0x52a780 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497a31  ebed                   -jmp 0x497a20
    goto L_0x00497a20;
L_0x00497a33:
    // 00497a33  e838feffff             -call 0x497870
    cpu.esp -= 4;
    sub_497870(app, cpu);
    if (cpu.terminate) return;
    // 00497a38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497a40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497a41  8b15accd4c00           -mov edx, dword ptr [0x4ccdac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033388) /* 0x4ccdac */);
    // 00497a47  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497a49  7502                   -jne 0x497a4d
    if (!cpu.flags.zf)
    {
        goto L_0x00497a4d;
    }
    // 00497a4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497a4d:
    // 00497a4d  b8a0a75200             -mov eax, 0x52a7a0
    cpu.eax = 5416864 /*0x52a7a0*/;
    // 00497a52  e84990feff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 00497a57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_497a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497a60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497a61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497a62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497a63  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 00497a68  bebca64c00             -mov esi, 0x4ca6bc
    cpu.esi = 5023420 /*0x4ca6bc*/;
    // 00497a6d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00497a6f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00497a71  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 00497a76  bef4a64c00             -mov esi, 0x4ca6f4
    cpu.esi = 5023476 /*0x4ca6f4*/;
    // 00497a7b  8d7838                 -lea edi, [eax + 0x38]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 00497a7e  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00497a80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497a84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497a84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497a85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497a86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497a87  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00497a89  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 00497a8e  bff4a64c00             -mov edi, 0x4ca6f4
    cpu.edi = 5023476 /*0x4ca6f4*/;
    // 00497a93  e86405feff             -call 0x477ffc
    cpu.esp -= 4;
    sub_477ffc(app, cpu);
    if (cpu.terminate) return;
    // 00497a98  8d7638                 -lea esi, [esi + 0x38]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00497a9b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00497a9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497aa0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497aa1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497aa1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497aa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497aa3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497aa6  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00497aaa  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00497aac  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00497ab0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00497ab3  b88ee14c00             -mov eax, 0x4ce18e
    cpu.eax = 5038478 /*0x4ce18e*/;
    // 00497ab8  e8dab80000             -call 0x4a3397
    cpu.esp -= 4;
    sub_4a3397(app, cpu);
    if (cpu.terminate) return;
    // 00497abd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497ac0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ac1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ac2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497ac3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497ac3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497ac4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497ac5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00497ac7  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00497ac9  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00497acc  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00497ace  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00497ad0  ff4010                 -inc dword ptr [eax + 0x10]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
    // 00497ad3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ad4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ad5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497ad6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497ad6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497ad7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497ad8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00497ada  b9c37a4900             -mov ecx, 0x497ac3
    cpu.ecx = 4815555 /*0x497ac3*/;
    // 00497adf  e833e40000             -call 0x4a5f17
    cpu.esp -= 4;
    sub_4a5f17(app, cpu);
    if (cpu.terminate) return;
    // 00497ae4  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 00497ae8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ae9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497aea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_497af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497af0  833db8a7520000         +cmp dword ptr [0x52a7b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5416888) /* 0x52a7b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497af7  7406                   -je 0x497aff
    if (cpu.flags.zf)
    {
        goto L_0x00497aff;
    }
    // 00497af9  b8b8a75200             -mov eax, 0x52a7b8
    cpu.eax = 5416888 /*0x52a7b8*/;
    // 00497afe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497aff:
    // 00497aff  e87490feff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00497b04  a3b8a75200             -mov dword ptr [0x52a7b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5416888) /* 0x52a7b8 */) = cpu.eax;
    // 00497b09  b8b8a75200             -mov eax, 0x52a7b8
    cpu.eax = 5416888 /*0x52a7b8*/;
    // 00497b0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_497b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497b10  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00497b12  e9b190feff             -jmp 0x480bc8
    return sub_480bc8(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_497b18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497b18  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00497b1a  e9c190feff             -jmp 0x480be0
    return sub_480be0(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_497b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497b20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497b21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497b22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497b23  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00497b25  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497b27  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00497b29  7412                   -je 0x497b3d
    if (cpu.flags.zf)
    {
        goto L_0x00497b3d;
    }
L_0x00497b2b:
    // 00497b2b  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00497b2d  80f95c                 +cmp cl, 0x5c
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
    // 00497b30  7511                   -jne 0x497b43
    if (!cpu.flags.zf)
    {
        goto L_0x00497b43;
    }
L_0x00497b32:
    // 00497b32  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00497b35  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00497b38  40                     -inc eax
    (cpu.eax)++;
    // 00497b39  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00497b3b  75ee                   -jne 0x497b2b
    if (!cpu.flags.zf)
    {
        goto L_0x00497b2b;
    }
L_0x00497b3d:
    // 00497b3d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00497b3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497b43:
    // 00497b43  80f93a                 +cmp cl, 0x3a
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
    // 00497b46  74ea                   -je 0x497b32
    if (cpu.flags.zf)
    {
        goto L_0x00497b32;
    }
    // 00497b48  80f92f                 +cmp cl, 0x2f
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
    // 00497b4b  74e5                   -je 0x497b32
    if (cpu.flags.zf)
    {
        goto L_0x00497b32;
    }
    // 00497b4d  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00497b50  40                     -inc eax
    (cpu.eax)++;
    // 00497b51  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00497b53  75d6                   -jne 0x497b2b
    if (!cpu.flags.zf)
    {
        goto L_0x00497b2b;
    }
    // 00497b55  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00497b57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_497b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497b60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497b61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497b62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497b63  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497b65  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497b6a  e8a1ffffff             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 00497b6f  804a1940               -or byte ptr [edx + 0x19], 0x40
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(25) /* 0x19 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00497b73  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00497b78  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00497b7b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00497b7d  ba444e4542             -mov edx, 0x42454e44
    cpu.edx = 1111838276 /*0x42454e44*/;
    // 00497b82  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00497b84  e84bb1feff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00497b89  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497b8e  e885ffffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497b93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_497b98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497b98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497b99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497b9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497b9b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497b9d  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497ba2  e869ffffff             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 00497ba7  8a6219                 -mov ah, byte ptr [edx + 0x19]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(25) /* 0x19 */);
    // 00497baa  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00497baf  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 00497bb2  7510                   -jne 0x497bc4
    if (!cpu.flags.zf)
    {
        goto L_0x00497bc4;
    }
L_0x00497bb4:
    // 00497bb4  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497bb9  e85affffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497bbe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497bc0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497bc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497bc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497bc3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497bc4:
    // 00497bc4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00497bc6  034214                 -add eax, dword ptr [edx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
    // 00497bc9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00497bce  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00497bd0  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00497bd2  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00497bd4  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00497bdb  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00497bdd  3d444e4542             +cmp eax, 0x42454e44
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
    // 00497be2  74d0                   -je 0x497bb4
    if (cpu.flags.zf)
    {
        goto L_0x00497bb4;
    }
    // 00497be4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497be6  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497beb  e828ffffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497bf0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497bf2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497bf3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497bf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497bf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497bf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497bf8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497bfd  eb05                   -jmp 0x497c04
    return sub_497c04(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_497c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497c00  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497c02  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00497c04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497c05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497c06  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497c07  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497c08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497c09  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497c0e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00497c13  e8f8feffff             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 00497c18  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00497c1a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00497c1c:
    // 00497c1c  3bbef4d75100           +cmp edi, dword ptr [esi + 0x51d7f4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5363700) /* 0x51d7f4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497c22  7420                   -je 0x497c44
    if (cpu.flags.zf)
    {
        goto L_0x00497c44;
    }
    // 00497c24  8b96f0d75100           -mov edx, dword ptr [esi + 0x51d7f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5363696) /* 0x51d7f0 */);
    // 00497c2a  8b9ef4d75100           -mov ebx, dword ptr [esi + 0x51d7f4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5363700) /* 0x51d7f4 */);
L_0x00497c30:
    // 00497c30  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00497c33  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00497c35  e85effffff             -call 0x497b98
    cpu.esp -= 4;
    sub_497b98(app, cpu);
    if (cpu.terminate) return;
    // 00497c3a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00497c3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497c3e  7404                   -je 0x497c44
    if (cpu.flags.zf)
    {
        goto L_0x00497c44;
    }
    // 00497c40  39da                   +cmp edx, ebx
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
    // 00497c42  75ec                   -jne 0x497c30
    if (!cpu.flags.zf)
    {
        goto L_0x00497c30;
    }
L_0x00497c44:
    // 00497c44  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00497c47  81fe80010000           +cmp esi, 0x180
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
    // 00497c4d  7d04                   -jge 0x497c53
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497c53;
    }
    // 00497c4f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00497c51  75c9                   -jne 0x497c1c
    if (!cpu.flags.zf)
    {
        goto L_0x00497c1c;
    }
L_0x00497c53:
    // 00497c53  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497c58  e8bbfeffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497c5d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497c5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497c04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00497c04;
    // 00497c00  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497c02  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00497c04:
    // 00497c04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497c05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497c06  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497c07  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497c08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497c09  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497c0e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00497c13  e8f8feffff             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 00497c18  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00497c1a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00497c1c:
    // 00497c1c  3bbef4d75100           +cmp edi, dword ptr [esi + 0x51d7f4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5363700) /* 0x51d7f4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497c22  7420                   -je 0x497c44
    if (cpu.flags.zf)
    {
        goto L_0x00497c44;
    }
    // 00497c24  8b96f0d75100           -mov edx, dword ptr [esi + 0x51d7f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5363696) /* 0x51d7f0 */);
    // 00497c2a  8b9ef4d75100           -mov ebx, dword ptr [esi + 0x51d7f4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5363700) /* 0x51d7f4 */);
L_0x00497c30:
    // 00497c30  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00497c33  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00497c35  e85effffff             -call 0x497b98
    cpu.esp -= 4;
    sub_497b98(app, cpu);
    if (cpu.terminate) return;
    // 00497c3a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00497c3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497c3e  7404                   -je 0x497c44
    if (cpu.flags.zf)
    {
        goto L_0x00497c44;
    }
    // 00497c40  39da                   +cmp edx, ebx
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
    // 00497c42  75ec                   -jne 0x497c30
    if (!cpu.flags.zf)
    {
        goto L_0x00497c30;
    }
L_0x00497c44:
    // 00497c44  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00497c47  81fe80010000           +cmp esi, 0x180
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
    // 00497c4d  7d04                   -jge 0x497c53
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497c53;
    }
    // 00497c4f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00497c51  75c9                   -jne 0x497c1c
    if (!cpu.flags.zf)
    {
        goto L_0x00497c1c;
    }
L_0x00497c53:
    // 00497c53  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497c58  e8bbfeffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497c5d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497c5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_497c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497c70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497c71  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497c76  e895feffff             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 00497c7b  a18ca64c00             -mov eax, dword ptr [0x4ca68c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */);
    // 00497c80  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00497c82  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00497c85  e80e000000             -call 0x497c98
    cpu.esp -= 4;
    sub_497c98(app, cpu);
    if (cpu.terminate) return;
    // 00497c8a  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497c8f  e884feffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497c94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497c95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497c98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497c98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497c99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497c9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497c9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497c9c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497c9d  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497ca0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00497ca2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00497ca4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00497ca6  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00497ca9  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00497cad  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00497caf  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
L_0x00497cb1:
    // 00497cb1  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00497cb3:
    // 00497cb3  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00497cb5  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00497cb8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00497cba  39d3                   +cmp ebx, edx
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
    // 00497cbc  731b                   -jae 0x497cd9
    if (!cpu.flags.cf)
    {
        goto L_0x00497cd9;
    }
    // 00497cbe  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00497cc0  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00497cc2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00497cc4  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00497cc6:
    // 00497cc6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00497cc8  741a                   -je 0x497ce4
    if (cpu.flags.zf)
    {
        goto L_0x00497ce4;
    }
L_0x00497cca:
    // 00497cca  39fe                   +cmp esi, edi
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
    // 00497ccc  7416                   -je 0x497ce4
    if (cpu.flags.zf)
    {
        goto L_0x00497ce4;
    }
    // 00497cce  f6461818               +test byte ptr [esi + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 00497cd2  751d                   -jne 0x497cf1
    if (!cpu.flags.zf)
    {
        goto L_0x00497cf1;
    }
    // 00497cd4  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00497cd7  ebf1                   -jmp 0x497cca
    goto L_0x00497cca;
L_0x00497cd9:
    // 00497cd9  39f9                   +cmp ecx, edi
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
    // 00497cdb  74e9                   -je 0x497cc6
    if (cpu.flags.zf)
    {
        goto L_0x00497cc6;
    }
    // 00497cdd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497cdf  8b4924                 -mov ecx, dword ptr [ecx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00497ce2  ebcf                   -jmp 0x497cb3
    goto L_0x00497cb3;
L_0x00497ce4:
    // 00497ce4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497ce8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497ceb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497cec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ced  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497cee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497cef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497cf0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497cf1:
    // 00497cf1  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00497cf3  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00497cf6  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00497cf8  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00497cfb  8d1c2a                 -lea ebx, [edx + ebp]
    cpu.ebx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 00497cfe  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00497d02  3b1424                 +cmp edx, dword ptr [esp]
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
    // 00497d05  7412                   -je 0x497d19
    if (cpu.flags.zf)
    {
        goto L_0x00497d19;
    }
    // 00497d07  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00497d0a  39d5                   +cmp ebp, edx
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
    // 00497d0c  7d2f                   -jge 0x497d3d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497d3d;
    }
    // 00497d0e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00497d10  39f9                   +cmp ecx, edi
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
    // 00497d12  74d0                   -je 0x497ce4
    if (cpu.flags.zf)
    {
        goto L_0x00497ce4;
    }
    // 00497d14  8b4924                 -mov ecx, dword ptr [ecx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00497d17  eb98                   -jmp 0x497cb1
    goto L_0x00497cb1;
L_0x00497d19:
    // 00497d19  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00497d1d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00497d20  29d5                   +sub ebp, edx
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
    // 00497d22  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00497d24  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00497d26  e8d598feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00497d2b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00497d30  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00497d32  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00497d34  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00497d38  e974ffffff             -jmp 0x497cb1
    goto L_0x00497cb1;
L_0x00497d3d:
    // 00497d3d  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00497d41  29d5                   +sub ebp, edx
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
    // 00497d43  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00497d45  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00497d47  e8b498feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00497d4c  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00497d4f  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00497d52  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00497d54  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00497d57  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00497d5a  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00497d5d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00497d60  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00497d63  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00497d66  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00497d69  897024                 -mov dword ptr [eax + 0x24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 00497d6c  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00497d71  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00497d74  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00497d78  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00497d7a  e932ffffff             -jmp 0x497cb1
    goto L_0x00497cb1;
}

/* align: skip 0x90 */
void Application::sub_497d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497d80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497d81  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497d86  e885fdffff             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 00497d8b  a18ca64c00             -mov eax, dword ptr [0x4ca68c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */);
    // 00497d90  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00497d93  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00497d95  e80e000000             -call 0x497da8
    cpu.esp -= 4;
    sub_497da8(app, cpu);
    if (cpu.terminate) return;
    // 00497d9a  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497d9f  e874fdffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497da4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497da5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497da8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497da8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497da9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497daa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497dab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497dac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497dad  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00497daf  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00497db1  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00497db3  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00497db6  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00497db9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497dbb  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00497dbd:
    // 00497dbd  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00497dbf:
    // 00497dbf  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00497dc1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497dc3  39d7                   +cmp edi, edx
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
L_0x00497dc5:
    // 00497dc5  7217                   -jb 0x497dde
    if (cpu.flags.cf)
    {
        goto L_0x00497dde;
    }
    // 00497dc7  39e9                   +cmp ecx, ebp
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
    // 00497dc9  751b                   -jne 0x497de6
    if (!cpu.flags.zf)
    {
        goto L_0x00497de6;
    }
L_0x00497dcb:
    // 00497dcb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497dcd  7425                   -je 0x497df4
    if (cpu.flags.zf)
    {
        goto L_0x00497df4;
    }
L_0x00497dcf:
    // 00497dcf  39ee                   +cmp esi, ebp
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
    // 00497dd1  7421                   -je 0x497df4
    if (cpu.flags.zf)
    {
        goto L_0x00497df4;
    }
    // 00497dd3  f6461818               +test byte ptr [esi + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 00497dd7  7523                   -jne 0x497dfc
    if (!cpu.flags.zf)
    {
        goto L_0x00497dfc;
    }
    // 00497dd9  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00497ddc  ebf1                   -jmp 0x497dcf
    goto L_0x00497dcf;
L_0x00497dde:
    // 00497dde  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00497de0  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00497de2  29f8                   +sub eax, edi
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
    // 00497de4  ebe5                   -jmp 0x497dcb
    goto L_0x00497dcb;
L_0x00497de6:
    // 00497de6  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00497de8  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00497deb  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00497dee  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00497df0  3b39                   +cmp edi, dword ptr [ecx]
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
    // 00497df2  ebd1                   -jmp 0x497dc5
    goto L_0x00497dc5;
L_0x00497df4:
    // 00497df4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497df6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497df7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497df8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497df9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497dfa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497dfb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497dfc:
    // 00497dfc  39ce                   +cmp esi, ecx
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
    // 00497dfe  7415                   -je 0x497e15
    if (cpu.flags.zf)
    {
        goto L_0x00497e15;
    }
    // 00497e00  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00497e03  39d0                   +cmp eax, edx
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
    // 00497e05  7d28                   -jge 0x497e2f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497e2f;
    }
    // 00497e07  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00497e09  037910                 -add edi, dword ptr [ecx + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 00497e0c  39e9                   +cmp ecx, ebp
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
    // 00497e0e  74e4                   -je 0x497df4
    if (cpu.flags.zf)
    {
        goto L_0x00497df4;
    }
    // 00497e10  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00497e13  ebaa                   -jmp 0x497dbf
    goto L_0x00497dbf;
L_0x00497e15:
    // 00497e15  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00497e17  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00497e19  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00497e1c  e8df97feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00497e21  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00497e24  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 00497e26  01df                   +add edi, ebx
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
    // 00497e28  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00497e2d  eb90                   -jmp 0x497dbf
    goto L_0x00497dbf;
L_0x00497e2f:
    // 00497e2f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00497e31  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00497e33  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00497e35  e8c697feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00497e3a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00497e3d  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00497e40  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00497e42  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00497e45  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00497e48  894324                 -mov dword ptr [ebx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00497e4b  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00497e4e  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00497e51  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00497e54  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00497e57  897124                 -mov dword ptr [ecx + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 00497e5a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00497e5d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00497e62  e956ffffff             -jmp 0x497dbd
    goto L_0x00497dbd;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_497e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497e70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497e71  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00497e76  e80128feff             -call 0x47a67c
    cpu.esp -= 4;
    sub_47a67c(app, cpu);
    if (cpu.terminate) return;
    // 00497e7b  e81c000000             -call 0x497e9c
    cpu.esp -= 4;
    sub_497e9c(app, cpu);
    if (cpu.terminate) return;
    // 00497e80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497e81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497e84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497e84  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497e85  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00497e8a  e80d000000             -call 0x497e9c
    cpu.esp -= 4;
    sub_497e9c(app, cpu);
    if (cpu.terminate) return;
    // 00497e8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497e90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497e94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497e94  e8e327feff             -call 0x47a67c
    cpu.esp -= 4;
    sub_47a67c(app, cpu);
    if (cpu.terminate) return;
    // 00497e99  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00497e9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497e9d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00497e9f  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497ea4  e867fcffff             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 00497ea9  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00497eac  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00497eae  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00497eb0  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00497eb2  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00497eb5  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497eba  e859fcffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497ebf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497ec1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ec2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497e9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00497e9c;
    // 00497e94  e8e327feff             -call 0x47a67c
    cpu.esp -= 4;
    sub_47a67c(app, cpu);
    if (cpu.terminate) return;
    // 00497e99  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00497e9c:
    // 00497e9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497e9d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00497e9f  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497ea4  e867fcffff             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 00497ea9  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00497eac  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00497eae  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00497eb0  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00497eb2  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00497eb5  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497eba  e859fcffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497ebf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497ec1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ec2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_497ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497ec4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497ec5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497ec6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497ec7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497ec8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00497eca  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00497ed0  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00497ed3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00497eda  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497edc  bff0d75100             -mov edi, 0x51d7f0
    cpu.edi = 5363696 /*0x51d7f0*/;
    // 00497ee1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00497ee4  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00497ee6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497ee8  e833fcffff             -call 0x497b20
    cpu.esp -= 4;
    sub_497b20(app, cpu);
    if (cpu.terminate) return;
    // 00497eed  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00497eef  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00497ef2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00497ef4  39d1                   +cmp ecx, edx
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
    // 00497ef6  7421                   -je 0x497f19
    if (cpu.flags.zf)
    {
        goto L_0x00497f19;
    }
L_0x00497ef8:
    // 00497ef8  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00497efd  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00497f00  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00497f02  e8b9a6feff             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 00497f07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497f09  7506                   -jne 0x497f11
    if (!cpu.flags.zf)
    {
        goto L_0x00497f11;
    }
    // 00497f0b  f6411808               +test byte ptr [ecx + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 00497f0f  750f                   -jne 0x497f20
    if (!cpu.flags.zf)
    {
        goto L_0x00497f20;
    }
L_0x00497f11:
    // 00497f11  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00497f14  3b4f04                 +cmp ecx, dword ptr [edi + 4]
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
    // 00497f17  75df                   -jne 0x497ef8
    if (!cpu.flags.zf)
    {
        goto L_0x00497ef8;
    }
L_0x00497f19:
    // 00497f19  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497f1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497f20:
    // 00497f20  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497f22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_497f28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497f28  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497f29  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00497f2b  e894ffffff             -call 0x497ec4
    cpu.esp -= 4;
    sub_497ec4(app, cpu);
    if (cpu.terminate) return;
    // 00497f30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497f34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497f34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497f35  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497f37  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497f3c  e8cffbffff             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 00497f41  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00497f43  e810000000             -call 0x497f58
    cpu.esp -= 4;
    sub_497f58(app, cpu);
    if (cpu.terminate) return;
    // 00497f48  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497f4a  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 00497f4f  e8c4fbffff             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 00497f54  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00497f56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497f58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497f58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497f59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497f5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497f5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497f5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497f5d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497f5e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00497f61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497f63  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00497f65  81e3000f0000           -and ebx, 0xf00
    cpu.ebx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00497f6b  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 00497f6e  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00497f75  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497f77  bbf0d75100             -mov ebx, 0x51d7f0
    cpu.ebx = 5363696 /*0x51d7f0*/;
    // 00497f7c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00497f7f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00497f81  837b1000               +cmp dword ptr [ebx + 0x10], 0
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
    // 00497f85  0f8484000000           -je 0x49800f
    if (cpu.flags.zf)
    {
        goto L_0x0049800f;
    }
    // 00497f8b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00497f8d  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00497f8f  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00497f91  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00497f94  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00497f97  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00497f99:
    // 00497f99  f6461808               +test byte ptr [esi + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 00497f9d  7422                   -je 0x497fc1
    if (cpu.flags.zf)
    {
        goto L_0x00497fc1;
    }
    // 00497f9f  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00497fa2  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00497fa5  39f8                   +cmp eax, edi
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
    // 00497fa7  0f866b000000           -jbe 0x498018
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00498018;
    }
L_0x00497fad:
    // 00497fad  a1a0a64c00             -mov eax, dword ptr [0x4ca6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
    // 00497fb2  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00497fb4  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00497fb7  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00497fba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497fbc  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00497fbf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00497fc1:
    // 00497fc1  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00497fc4  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00497fc7  39ce                   +cmp esi, ecx
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
    // 00497fc9  75ce                   -jne 0x497f99
    if (!cpu.flags.zf)
    {
        goto L_0x00497f99;
    }
    // 00497fcb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00497fcd  7434                   -je 0x498003
    if (cpu.flags.zf)
    {
        goto L_0x00498003;
    }
    // 00497fcf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00497fd1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00497fd3:
    // 00497fd3  40                     -inc eax
    (cpu.eax)++;
    // 00497fd4  8a5a04                 -mov bl, byte ptr [edx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00497fd7  42                     -inc edx
    (cpu.edx)++;
    // 00497fd8  885c04ff               -mov byte ptr [esp + eax - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.eax * 1) = cpu.bl;
    // 00497fdc  83f80c                 +cmp eax, 0xc
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
    // 00497fdf  7cf2                   -jl 0x497fd3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497fd3;
    }
    // 00497fe1  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00497fe3  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
L_0x00497fe7:
    // 00497fe7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00497fe9  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00497fec  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00497fef  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00497ff1  80cb08                 -or bl, 8
    cpu.bl |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00497ff4  e8a722feff             -call 0x47a2a0
    cpu.esp -= 4;
    sub_47a2a0(app, cpu);
    if (cpu.terminate) return;
    // 00497ff9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497ffb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497ffd  7429                   -je 0x498028
    if (cpu.flags.zf)
    {
        goto L_0x00498028;
    }
    // 00497fff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498001  7540                   -jne 0x498043
    if (!cpu.flags.zf)
    {
        goto L_0x00498043;
    }
L_0x00498003:
    // 00498003  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00498005:
    // 00498005  83c410                 +add esp, 0x10
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
    // 00498008  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498009  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049800a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049800b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049800c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049800d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049800e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049800f:
    // 0049800f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498011  e87a27feff             -call 0x47a790
    cpu.esp -= 4;
    sub_47a790(app, cpu);
    if (cpu.terminate) return;
    // 00498016  ebed                   -jmp 0x498005
    goto L_0x00498005;
L_0x00498018:
    // 00498018  75a7                   -jne 0x497fc1
    if (!cpu.flags.zf)
    {
        goto L_0x00497fc1;
    }
    // 0049801a  a1a0a64c00             -mov eax, dword ptr [0x4ca6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
    // 0049801f  2b461c                 -sub eax, dword ptr [esi + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 00498022  39d0                   +cmp eax, edx
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
    // 00498024  7387                   -jae 0x497fad
    if (!cpu.flags.cf)
    {
        goto L_0x00497fad;
    }
    // 00498026  eb99                   -jmp 0x497fc1
    goto L_0x00497fc1;
L_0x00498028:
    // 00498028  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049802a  e829ffffff             -call 0x497f58
    cpu.esp -= 4;
    sub_497f58(app, cpu);
    if (cpu.terminate) return;
    // 0049802f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498031  75b4                   -jne 0x497fe7
    if (!cpu.flags.zf)
    {
        goto L_0x00497fe7;
    }
    // 00498033  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498035  750c                   -jne 0x498043
    if (!cpu.flags.zf)
    {
        goto L_0x00498043;
    }
    // 00498037  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498039  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049803c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049803d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049803e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049803f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498040  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498041  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498042  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498043:
    // 00498043  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00498046  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00498048  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049804b  e8b095feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00498050  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00498052  e88126feff             -call 0x47a6d8
    cpu.esp -= 4;
    sub_47a6d8(app, cpu);
    if (cpu.terminate) return;
    // 00498057  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049805c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049805f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498060  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498061  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498062  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498063  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498064  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498065  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_498068(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498068  e807000000             -call 0x498074
    cpu.esp -= 4;
    sub_498074(app, cpu);
    if (cpu.terminate) return;
    // 0049806d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049806f  7402                   -je 0x498073
    if (cpu.flags.zf)
    {
        goto L_0x00498073;
    }
    // 00498071  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00498073:
    // 00498073  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498074(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498074  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498075  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498076  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498077  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498078  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498079  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049807b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049807d  e842feffff             -call 0x497ec4
    cpu.esp -= 4;
    sub_497ec4(app, cpu);
    if (cpu.terminate) return;
    // 00498082  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00498084  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498086  7537                   -jne 0x4980bf
    if (!cpu.flags.zf)
    {
        goto L_0x004980bf;
    }
    // 00498088  8b1d8ca64c00           -mov ebx, dword ptr [0x4ca68c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */);
    // 0049808e  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
L_0x00498091:
    // 00498091  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00498093  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00498095  e82afeffff             -call 0x497ec4
    cpu.esp -= 4;
    sub_497ec4(app, cpu);
    if (cpu.terminate) return;
    // 0049809a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049809c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049809e  7561                   -jne 0x498101
    if (!cpu.flags.zf)
    {
        goto L_0x00498101;
    }
    // 004980a0  81e3000f0000           -and ebx, 0xf00
    cpu.ebx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004980a6  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 004980a9  6bdb18                 -imul ebx, ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(24 /*0x18*/)));
    // 004980ac  81c3f0d75100           -add ebx, 0x51d7f0
    (cpu.ebx) += x86::reg32(x86::sreg32(5363696 /*0x51d7f0*/));
    // 004980b2  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004980b5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004980b7  75d8                   -jne 0x498091
    if (!cpu.flags.zf)
    {
        goto L_0x00498091;
    }
L_0x004980b9:
    // 004980b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004980bf:
    // 004980bf  8a6018                 -mov ah, byte ptr [eax + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004980c2  80e4f7                 -and ah, 0xf7
    cpu.ah &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004980c5  886618                 -mov byte ptr [esi + 0x18], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ah;
    // 004980c8  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004980cb  7404                   -je 0x4980d1
    if (cpu.flags.zf)
    {
        goto L_0x004980d1;
    }
    // 004980cd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004980cf  ebe8                   -jmp 0x4980b9
    goto L_0x004980b9;
L_0x004980d1:
    // 004980d1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004980d3  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004980d6  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004980d9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004980db  e8c021feff             -call 0x47a2a0
    cpu.esp -= 4;
    sub_47a2a0(app, cpu);
    if (cpu.terminate) return;
    // 004980e0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004980e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004980e4  7504                   -jne 0x4980ea
    if (!cpu.flags.zf)
    {
        goto L_0x004980ea;
    }
    // 004980e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004980e8  ebcf                   -jmp 0x4980b9
    goto L_0x004980b9;
L_0x004980ea:
    // 004980ea  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004980ed  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004980ef  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004980f1  e80a95feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 004980f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004980f8  e8bb25feff             -call 0x47a6b8
    cpu.esp -= 4;
    sub_47a6b8(app, cpu);
    if (cpu.terminate) return;
    // 004980fd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004980ff  ebb8                   -jmp 0x4980b9
    goto L_0x004980b9;
L_0x00498101:
    // 00498101  806018f7               -and byte ptr [eax + 0x18], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00498105  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00498107  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0049810a  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049810d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049810f  e88c21feff             -call 0x47a2a0
    cpu.esp -= 4;
    sub_47a2a0(app, cpu);
    if (cpu.terminate) return;
    // 00498114  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00498116  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00498119  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049811b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049811d  e8de94feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00498122  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00498124  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498125  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498126  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498127  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498128  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498129  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49812c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049812c  e807000000             -call 0x498138
    cpu.esp -= 4;
    sub_498138(app, cpu);
    if (cpu.terminate) return;
    // 00498131  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498133  7402                   -je 0x498137
    if (cpu.flags.zf)
    {
        goto L_0x00498137;
    }
    // 00498135  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00498137:
    // 00498137  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498138(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498138  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498139  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049813a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049813b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049813c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049813e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00498140  e87ffdffff             -call 0x497ec4
    cpu.esp -= 4;
    sub_497ec4(app, cpu);
    if (cpu.terminate) return;
    // 00498145  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00498147  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498149  7528                   -jne 0x498173
    if (!cpu.flags.zf)
    {
        goto L_0x00498173;
    }
    // 0049814b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049814d  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00498153  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00498156  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049815d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049815f  baf0d75100             -mov edx, 0x51d7f0
    cpu.edx = 5363696 /*0x51d7f0*/;
    // 00498164  8b54c210               -mov edx, dword ptr [edx + eax*8 + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */ + cpu.eax * 8);
    // 00498168  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049816a  754b                   -jne 0x4981b7
    if (!cpu.flags.zf)
    {
        goto L_0x004981b7;
    }
    // 0049816c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049816e:
    // 0049816e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049816f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498170  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498171  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498172  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498173:
    // 00498173  8a5018                 -mov dl, byte ptr [eax + 0x18]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00498176  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00498179  885018                 -mov byte ptr [eax + 0x18], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.dl;
    // 0049817c  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 0049817f  75ed                   -jne 0x49816e
    if (!cpu.flags.zf)
    {
        goto L_0x0049816e;
    }
    // 00498181  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00498184  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00498187  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00498189  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049818b  e81021feff             -call 0x47a2a0
    cpu.esp -= 4;
    sub_47a2a0(app, cpu);
    if (cpu.terminate) return;
    // 00498190  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00498192  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498194  7507                   -jne 0x49819d
    if (!cpu.flags.zf)
    {
        goto L_0x0049819d;
    }
    // 00498196  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00498198  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498199  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049819a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049819b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049819c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049819d:
    // 0049819d  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004981a0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004981a2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004981a4  e85794feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 004981a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004981ab  e80825feff             -call 0x47a6b8
    cpu.esp -= 4;
    sub_47a6b8(app, cpu);
    if (cpu.terminate) return;
    // 004981b0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004981b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004981b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004981b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004981b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004981b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004981b7:
    // 004981b7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004981b9  e806fdffff             -call 0x497ec4
    cpu.esp -= 4;
    sub_497ec4(app, cpu);
    if (cpu.terminate) return;
    // 004981be  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004981c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004981c2  74aa                   -je 0x49816e
    if (cpu.flags.zf)
    {
        goto L_0x0049816e;
    }
    // 004981c4  8a6018                 -mov ah, byte ptr [eax + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004981c7  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004981ca  80e4f7                 -and ah, 0xf7
    cpu.ah &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004981cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004981cf  886618                 -mov byte ptr [esi + 0x18], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ah;
    // 004981d2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004981d4  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004981d7  e8c420feff             -call 0x47a2a0
    cpu.esp -= 4;
    sub_47a2a0(app, cpu);
    if (cpu.terminate) return;
    // 004981dc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004981de  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004981e1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004981e3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004981e5  e81694feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 004981ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004981ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004981ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004981ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004981ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004981f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_498200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498200  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498201  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498202  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00498205  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498207  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0049820c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049820d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00498211  2eff1534754b00         -call dword ptr cs:[0x4b7534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945204) /* 0x4b7534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498218  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049821c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049821f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498220  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498221  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_498224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498224  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498225  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498226  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00498229  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049822b  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00498230  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498231  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00498235  2eff1534754b00         -call dword ptr cs:[0x4b7534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945204) /* 0x4b7534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049823c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498240  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00498243  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498244  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498245  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_498248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498248  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498249  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049824a  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049824d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049824f  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00498254  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498255  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00498259  2eff1534754b00         -call dword ptr cs:[0x4b7534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945204) /* 0x4b7534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498260  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00498264  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00498267  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498268  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498269  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49826c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049826c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049826d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049826e  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00498271  ba00006000             -mov edx, 0x600000
    cpu.edx = 6291456 /*0x600000*/;
    // 00498276  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498278  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049827d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049827e  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00498282  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00498286  2eff1534754b00         -call dword ptr cs:[0x4b7534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945204) /* 0x4b7534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049828d  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00498291  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498292  683f000f00             -push 0xf003f
    app->getMemory<x86::reg32>(cpu.esp-4) = 983103 /*0xf003f*/;
    cpu.esp -= 4;
    // 00498297  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00498299  68ac134c00             -push 0x4c13ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4985772 /*0x4c13ac*/;
    cpu.esp -= 4;
    // 0049829e  6806000080             -push 0x80000006
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483654 /*0x80000006*/;
    cpu.esp -= 4;
    // 004982a3  2eff159c734b00         -call dword ptr cs:[0x4b739c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944796) /* 0x4b739c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004982aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004982ac  740e                   -je 0x4982bc
    if (cpu.flags.zf)
    {
        goto L_0x004982bc;
    }
    // 004982ae  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004982b2  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004982b6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004982b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004982ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004982bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004982bc:
    // 004982bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004982bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004982be  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004982bf  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004982c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004982c4  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004982c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004982c9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004982cb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004982cd  68c0134c00             -push 0x4c13c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4985792 /*0x4c13c0*/;
    cpu.esp -= 4;
    // 004982d2  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004982d6  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004982db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004982dc  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 004982e0  2eff15a0734b00         -call dword ptr cs:[0x4b73a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944800) /* 0x4b73a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004982e7  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004982eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004982ec  2eff1594734b00         -call dword ptr cs:[0x4b7394]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944788) /* 0x4b7394 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004982f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004982f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004982f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004982f6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004982fa  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004982fe  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00498301  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498302  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498303  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_498310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498310  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498311  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498312  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498313  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498314  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00498316  8b0cc5d0ad5200         -mov ecx, dword ptr [eax*8 + 0x52add0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.eax * 8);
    // 0049831d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00498322  bf80000000             -mov edi, 0x80
    cpu.edi = 128 /*0x80*/;
    // 00498327  80790401               +cmp byte ptr [ecx + 4], 1
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
    // 0049832b  7206                   -jb 0x498333
    if (cpu.flags.cf)
    {
        goto L_0x00498333;
    }
    // 0049832d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049832f  668b7906               -mov di, word ptr [ecx + 6]
    cpu.di = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
L_0x00498333:
    // 00498333  e8bc3afeff             -call 0x47bdf4
    cpu.esp -= 4;
    sub_47bdf4(app, cpu);
    if (cpu.terminate) return;
    // 00498338  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049833a  754d                   -jne 0x498389
    if (!cpu.flags.zf)
    {
        goto L_0x00498389;
    }
    // 0049833c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049833e  7c49                   -jl 0x498389
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498389;
    }
    // 00498340  39fe                   +cmp esi, edi
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
    // 00498342  7d45                   -jge 0x498389
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498389;
    }
    // 00498344  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0049834b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049834d  80790402               +cmp byte ptr [ecx + 4], 2
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
    // 00498351  7240                   -jb 0x498393
    if (cpu.flags.cf)
    {
        goto L_0x00498393;
    }
    // 00498353  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00498355  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
L_0x00498358:
    // 00498358  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049835a  742d                   -je 0x498389
    if (cpu.flags.zf)
    {
        goto L_0x00498389;
    }
    // 0049835c  81385041546c           +cmp dword ptr [eax], 0x6c544150
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
    // 00498362  7534                   -jne 0x498398
    if (!cpu.flags.zf)
    {
        goto L_0x00498398;
    }
    // 00498364  e84f000000             -call 0x4983b8
    cpu.esp -= 4;
    sub_4983b8(app, cpu);
    if (cpu.terminate) return;
L_0x00498369:
    // 00498369  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049836b:
    // 0049836b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049836d  7c13                   -jl 0x498382
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498382;
    }
    // 0049836f  8a6104                 -mov ah, byte ptr [ecx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00498372  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00498375  80fc02                 +cmp ah, 2
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
    // 00498378  722e                   -jb 0x4983a8
    if (cpu.flags.cf)
    {
        goto L_0x004983a8;
    }
    // 0049837a  c7442e0c00000000       -mov dword ptr [esi + ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ebp * 1) = 0 /*0x0*/;
L_0x00498382:
    // 00498382  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00498384  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498385  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498386  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498387  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498388  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498389:
    // 00498389  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049838e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049838f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498390  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498391  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498392  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498393:
    // 00498393  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00498396  ebc0                   -jmp 0x498358
    goto L_0x00498358;
L_0x00498398:
    // 00498398  6681385054             +cmp word ptr [eax], 0x5450
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
    // 0049839d  75cc                   -jne 0x49836b
    if (!cpu.flags.zf)
    {
        goto L_0x0049836b;
    }
    // 0049839f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004983a1  e80a4d0000             -call 0x49d0b0
    cpu.esp -= 4;
    sub_49d0b0(app, cpu);
    if (cpu.terminate) return;
    // 004983a6  ebc1                   -jmp 0x498369
    goto L_0x00498369;
L_0x004983a8:
    // 004983a8  c744310800000000       -mov dword ptr [ecx + esi + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.esi * 1) = 0 /*0x0*/;
    // 004983b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004983b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4983b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004983b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004983b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004983ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004983bb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004983bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004983bf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004983c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004983c3  8a4307                 -mov al, byte ptr [ebx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 004983c6  39c2                   +cmp edx, eax
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
    // 004983c8  7c06                   -jl 0x4983d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004983d0;
    }
    // 004983ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004983cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004983d0:
    // 004983d0  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004983d3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004983d5  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004983d8  42                     -inc edx
    (cpu.edx)++;
    // 004983d9  e8d273feff             -call 0x47f7b0
    cpu.esp -= 4;
    sub_47f7b0(app, cpu);
    if (cpu.terminate) return;
    // 004983de  83c144                 -add ecx, 0x44
    (cpu.ecx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004983e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004983e3  8a4307                 -mov al, byte ptr [ebx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 004983e6  39c2                   +cmp edx, eax
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
    // 004983e8  7ce6                   -jl 0x4983d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004983d0;
    }
    // 004983ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004983ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4983f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004983f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004983f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004983f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004983f3  81ec080c0000           -sub esp, 0xc08
    (cpu.esp) -= x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004983f9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004983fb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004983fd  899c24000c0000         -mov dword ptr [esp + 0xc00], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = cpu.ebx;
    // 00498404  898c24040c0000         -mov dword ptr [esp + 0xc04], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */) = cpu.ecx;
    // 0049840b  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 00498411  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00498416  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00498418  750f                   -jne 0x498429
    if (!cpu.flags.zf)
    {
        goto L_0x00498429;
    }
    // 0049841a  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049841f  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 00498425  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498426  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498427  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498428  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498429:
    // 00498429  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049842b  e8c439feff             -call 0x47bdf4
    cpu.esp -= 4;
    sub_47bdf4(app, cpu);
    if (cpu.terminate) return;
    // 00498430  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498432  0f8562000000           -jne 0x49849a
    if (!cpu.flags.zf)
    {
        goto L_0x0049849a;
    }
    // 00498438  83bc24000c000000       +cmp dword ptr [esp + 0xc00], 0
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
    // 00498440  7458                   -je 0x49849a
    if (cpu.flags.zf)
    {
        goto L_0x0049849a;
    }
    // 00498442  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00498444  7454                   -je 0x49849a
    if (cpu.flags.zf)
    {
        goto L_0x0049849a;
    }
    // 00498446  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0049844b:
    // 0049844b  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049844e  895404f4               -mov dword ptr [esp + eax - 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.eax * 1) = cpu.edx;
    // 00498452  3d000c0000             +cmp eax, 0xc00
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
    // 00498457  75f2                   -jne 0x49844b
    if (!cpu.flags.zf)
    {
        goto L_0x0049844b;
    }
    // 00498459  8b34f5d0ad5200         -mov esi, dword ptr [esi*8 + 0x52add0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.esi * 8);
    // 00498460  807e0401               +cmp byte ptr [esi + 4], 1
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
    // 00498464  7206                   -jb 0x49846c
    if (cpu.flags.cf)
    {
        goto L_0x0049846c;
    }
    // 00498466  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498468  668b5e06               -mov bx, word ptr [esi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
L_0x0049846c:
    // 0049846c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049846e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498470  7e19                   -jle 0x49848b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049848b;
    }
    // 00498472  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00498474:
    // 00498474  807e0402               +cmp byte ptr [esi + 4], 2
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
    // 00498478  722f                   -jb 0x4984a9
    if (cpu.flags.cf)
    {
        goto L_0x004984a9;
    }
    // 0049847a  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049847c  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
L_0x0049847f:
    // 0049847f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498481  742b                   -je 0x4984ae
    if (cpu.flags.zf)
    {
        goto L_0x004984ae;
    }
    // 00498483  41                     -inc ecx
    (cpu.ecx)++;
    // 00498484  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498487  39d9                   +cmp ecx, ebx
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
    // 00498489  7ce9                   -jl 0x498474
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498474;
    }
L_0x0049848b:
    // 0049848b  b8f7ffffff             -mov eax, 0xfffffff7
    cpu.eax = 4294967287 /*0xfffffff7*/;
    // 00498490  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 00498496  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498497  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498498  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498499  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049849a:
    // 0049849a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049849f  81c4080c0000           +add esp, 0xc08
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
    // 004984a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004984a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004984a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004984a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004984a9:
    // 004984a9  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004984ac  ebd1                   -jmp 0x49847f
    goto L_0x0049847f;
L_0x004984ae:
    // 004984ae  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004984b0  8b9424040c0000         -mov edx, dword ptr [esp + 0xc04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */);
    // 004984b7  8b8424000c0000         -mov eax, dword ptr [esp + 0xc00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 004984be  e8ad010000             -call 0x498670
    cpu.esp -= 4;
    sub_498670(app, cpu);
    if (cpu.terminate) return;
    // 004984c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004984c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004984c7  7c29                   -jl 0x4984f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004984f2;
    }
    // 004984c9  8a5e04                 -mov bl, byte ptr [esi + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004984cc  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004984d3  80fb02                 +cmp bl, 2
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
    // 004984d6  722b                   -jb 0x498503
    if (cpu.flags.cf)
    {
        goto L_0x00498503;
    }
    // 004984d8  8b9c24000c0000         -mov ebx, dword ptr [esp + 0xc00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 004984df  895c070c               -mov dword ptr [edi + eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.ebx;
    // 004984e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004984e5  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 004984e8  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004984ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004984ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004984f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004984f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004984f2:
    // 004984f2  c74500ffffffff         -mov dword ptr [ebp], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp) = 4294967295 /*0xffffffff*/;
    // 004984f9  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004984ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498500  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498501  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498502  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498503:
    // 00498503  8b9c24000c0000         -mov ebx, dword ptr [esp + 0xc00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 0049850a  895c0608               -mov dword ptr [esi + eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.ebx;
    // 0049850e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498510  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 00498513  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 00498519  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049851a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049851b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049851c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498520  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498521  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498522  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498523  81ec000c0000           -sub esp, 0xc00
    (cpu.esp) -= x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 00498529  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049852b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049852d  bad0a75200             -mov edx, 0x52a7d0
    cpu.edx = 5416912 /*0x52a7d0*/;
    // 00498532  8d9a00060000           -lea ebx, [edx + 0x600]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1536) /* 0x600 */);
L_0x00498538:
    // 00498538  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 0049853b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049853e  39f0                   +cmp eax, esi
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
    // 00498540  7511                   -jne 0x498553
    if (!cpu.flags.zf)
    {
        goto L_0x00498553;
    }
    // 00498542  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00498544  668b4208               -mov ax, word ptr [edx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00498548  39c8                   +cmp eax, ecx
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
    // 0049854a  7507                   -jne 0x498553
    if (!cpu.flags.zf)
    {
        goto L_0x00498553;
    }
    // 0049854c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049854e  e86d7ffeff             -call 0x4804c0
    cpu.esp -= 4;
    sub_4804c0(app, cpu);
    if (cpu.terminate) return;
L_0x00498553:
    // 00498553  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00498556  39da                   +cmp edx, ebx
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
    // 00498558  75de                   -jne 0x498538
    if (!cpu.flags.zf)
    {
        goto L_0x00498538;
    }
    // 0049855a  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049855c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x00498561:
    // 00498561  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00498564  895c14f4               -mov dword ptr [esp + edx - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.edx * 1) = cpu.ebx;
    // 00498568  81fa000c0000           +cmp edx, 0xc00
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
    // 0049856e  75f1                   -jne 0x498561
    if (!cpu.flags.zf)
    {
        goto L_0x00498561;
    }
    // 00498570  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00498572  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00498574  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00498576  e895fdffff             -call 0x498310
    cpu.esp -= 4;
    sub_498310(app, cpu);
    if (cpu.terminate) return;
    // 0049857b  81c4000c0000           -add esp, 0xc00
    (cpu.esp) += x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 00498581  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498582  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498583  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498584  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_498590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498590  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498591  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498592  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00498595  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00498597  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00498599  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049859d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004985a2  8a6005                 -mov ah, byte ptr [eax + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004985a5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004985a8  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004985aa  0f856a000000           -jne 0x49861a
    if (!cpu.flags.zf)
    {
        goto L_0x0049861a;
    }
    // 004985b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004985b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004985b2  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004985b5  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004985b8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004985ba  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004985bc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004985be  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004985c1:
    // 004985c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004985c3  8a4107                 -mov al, byte ptr [ecx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 004985c6  39c6                   +cmp esi, eax
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
    // 004985c8  7d5d                   -jge 0x498627
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498627;
    }
    // 004985ca  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004985cd  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004985cf  83781800               +cmp dword ptr [eax + 0x18], 0
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
    // 004985d3  7406                   -je 0x4985db
    if (cpu.flags.zf)
    {
        goto L_0x004985db;
    }
    // 004985d5  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004985d8  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004985db:
    // 004985db  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 004985df  7406                   -je 0x4985e7
    if (cpu.flags.zf)
    {
        goto L_0x004985e7;
    }
    // 004985e1  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004985e4  01501c                 -add dword ptr [eax + 0x1c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004985e7:
    // 004985e7  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 004985eb  7406                   -je 0x4985f3
    if (cpu.flags.zf)
    {
        goto L_0x004985f3;
    }
    // 004985ed  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004985f0  015020                 -add dword ptr [eax + 0x20], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004985f3:
    // 004985f3  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004985f6  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004985f9  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004985fc  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004985fe  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00498600  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00498603  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00498607  e85473feff             -call 0x47f960
    cpu.esp -= 4;
    sub_47f960(app, cpu);
    if (cpu.terminate) return;
    // 0049860c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00498610  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498612  7c0e                   -jl 0x498622
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498622;
    }
    // 00498614  83c744                 +add edi, 0x44
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
    // 00498617  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00498618  eba7                   -jmp 0x4985c1
    goto L_0x004985c1;
L_0x0049861a:
    // 0049861a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049861c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049861f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498620  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498621  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498622:
    // 00498622  4e                     -dec esi
    (cpu.esi)--;
    // 00498623  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00498627:
    // 00498627  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049862b  83feff                 +cmp esi, -1
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
    // 0049862e  7e30                   -jle 0x498660
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498660;
    }
    // 00498630  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00498632  7c20                   -jl 0x498654
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498654;
    }
    // 00498634  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00498636  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00498639  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049863b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049863d  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
L_0x00498640:
    // 00498640  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00498643  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00498645  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00498648  83c244                 -add edx, 0x44
    (cpu.edx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0049864b  e86071feff             -call 0x47f7b0
    cpu.esp -= 4;
    sub_47f7b0(app, cpu);
    if (cpu.terminate) return;
    // 00498650  39f2                   +cmp edx, esi
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
    // 00498652  7eec                   -jle 0x498640
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498640;
    }
L_0x00498654:
    // 00498654  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00498658  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498659  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049865a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049865d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049865e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049865f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498660:
    // 00498660  c6410501               -mov byte ptr [ecx + 5], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 1 /*0x1*/;
    // 00498664  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00498668  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498669  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049866a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049866d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049866e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049866f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498670  81385041546c           +cmp dword ptr [eax], 0x6c544150
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
    // 00498676  0f8414ffffff           -je 0x498590
    if (cpu.flags.zf)
    {
        return sub_498590(app, cpu);
    }
    // 0049867c  6681385054             +cmp word ptr [eax], 0x5450
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
    // 00498681  0f847d490000           -je 0x49d004
    if (cpu.flags.zf)
    {
        return sub_49d004(app, cpu);
    }
    // 00498687  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049868c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498691  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498692  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498693  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00498696  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00498698  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049869b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049869d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049869f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004986a1  7446                   -je 0x4986e9
    if (cpu.flags.zf)
    {
        goto L_0x004986e9;
    }
    // 004986a3  81385041546c           +cmp dword ptr [eax], 0x6c544150
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
    // 004986a9  754c                   -jne 0x4986f7
    if (!cpu.flags.zf)
    {
        goto L_0x004986f7;
    }
    // 004986ab  80780401               +cmp byte ptr [eax + 4], 1
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
    // 004986af  754d                   -jne 0x4986fe
    if (!cpu.flags.zf)
    {
        goto L_0x004986fe;
    }
    // 004986b1  83f9ff                 +cmp ecx, -1
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
    // 004986b4  754f                   -jne 0x498705
    if (!cpu.flags.zf)
    {
        goto L_0x00498705;
    }
    // 004986b6  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
L_0x004986bb:
    // 004986bb  83fbff                 +cmp ebx, -1
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
    // 004986be  7550                   -jne 0x498710
    if (!cpu.flags.zf)
    {
        goto L_0x00498710;
    }
    // 004986c0  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
L_0x004986c5:
    // 004986c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004986c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004986c9:
    // 004986c9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004986cb  8a4f07                 -mov cl, byte ptr [edi + 7]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 004986ce  39c8                   +cmp eax, ecx
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
    // 004986d0  0f8d60000000           -jge 0x498736
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498736;
    }
    // 004986d6  8b770c                 -mov esi, dword ptr [edi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004986d9  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004986db  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004986dd  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004986df  39cd                   +cmp ebp, ecx
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
    // 004986e1  7d38                   -jge 0x49871b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049871b;
    }
L_0x004986e3:
    // 004986e3  83c244                 +add edx, 0x44
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
    // 004986e6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004986e7  ebe0                   -jmp 0x4986c9
    goto L_0x004986c9;
L_0x004986e9:
    // 004986e9  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004986ee:
    // 004986ee  83c410                 +add esp, 0x10
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
    // 004986f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004986f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004986f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004986f4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004986f7:
    // 004986f7  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004986fc  ebf0                   -jmp 0x4986ee
    goto L_0x004986ee;
L_0x004986fe:
    // 004986fe  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 00498703  ebe9                   -jmp 0x4986ee
    goto L_0x004986ee;
L_0x00498705:
    // 00498705  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00498707  7ce0                   -jl 0x4986e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004986e9;
    }
    // 00498709  83f97f                 +cmp ecx, 0x7f
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
    // 0049870c  7ead                   -jle 0x4986bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004986bb;
    }
    // 0049870e  ebd9                   -jmp 0x4986e9
    goto L_0x004986e9;
L_0x00498710:
    // 00498710  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498712  7cd5                   -jl 0x4986e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004986e9;
    }
    // 00498714  83fb7f                 +cmp ebx, 0x7f
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
    // 00498717  7eac                   -jle 0x4986c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004986c5;
    }
    // 00498719  ebce                   -jmp 0x4986e9
    goto L_0x004986e9;
L_0x0049871b:
    // 0049871b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049871d  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00498720  39cd                   +cmp ebp, ecx
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
    // 00498722  7fbf                   -jg 0x4986e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004986e3;
    }
    // 00498724  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00498726  8a4e02                 -mov cl, byte ptr [esi + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00498729  39cb                   +cmp ebx, ecx
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
    // 0049872b  7cb6                   -jl 0x4986e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004986e3;
    }
    // 0049872d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049872f  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00498732  39cb                   +cmp ebx, ecx
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
    // 00498734  7fad                   -jg 0x4986e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004986e3;
    }
L_0x00498736:
    // 00498736  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00498738  8a5707                 -mov dl, byte ptr [edi + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 0049873b  39d0                   +cmp eax, edx
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
    // 0049873d  0f8482020000           -je 0x4989c5
    if (cpu.flags.zf)
    {
        goto L_0x004989c5;
    }
    // 00498743  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00498747  83f8ff                 +cmp eax, -1
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
    // 0049874a  0f8583020000           -jne 0x4989d3
    if (!cpu.flags.zf)
    {
        goto L_0x004989d3;
    }
    // 00498750  c74424247f000000       -mov dword ptr [esp + 0x24], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 127 /*0x7f*/;
L_0x00498758:
    // 00498758  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049875c  83faff                 +cmp edx, -1
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
    // 0049875f  0f858d020000           -jne 0x4989f2
    if (!cpu.flags.zf)
    {
        goto L_0x004989f2;
    }
    // 00498765  c744242040000000       -mov dword ptr [esp + 0x20], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 64 /*0x40*/;
L_0x0049876d:
    // 0049876d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049876f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498771  8a570a                 -mov dl, byte ptr [edi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 00498774  8a4610                 -mov al, byte ptr [esi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00498777  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00498779  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049877c  8a5611                 -mov dl, byte ptr [esi + 0x11]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(17) /* 0x11 */);
    // 0049877f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00498783  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00498785  7415                   -je 0x49879c
    if (cpu.flags.zf)
    {
        goto L_0x0049879c;
    }
    // 00498787  8b460e                 -mov eax, dword ptr [esi + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 0049878a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049878d  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00498791  e80ae40000             -call 0x4a6ba0
    cpu.esp -= 4;
    sub_4a6ba0(app, cpu);
    if (cpu.terminate) return;
    // 00498796  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00498798  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x0049879c:
    // 0049879c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004987a0  83f87f                 +cmp eax, 0x7f
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
    // 004987a3  0f8e68020000           -jle 0x498a11
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498a11;
    }
    // 004987a9  c744240c7f000000       -mov dword ptr [esp + 0xc], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 127 /*0x7f*/;
L_0x004987b1:
    // 004987b1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004987b5  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004987b9  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004987bc  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004987c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004987c2  0f8c5c020000           -jl 0x498a24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498a24;
    }
    // 004987c8  83f87f                 +cmp eax, 0x7f
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
    // 004987cb  7e08                   -jle 0x4987d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004987d5;
    }
    // 004987cd  c74424207f000000       -mov dword ptr [esp + 0x20], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 127 /*0x7f*/;
L_0x004987d5:
    // 004987d5  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004987d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004987da  740b                   -je 0x4987e7
    if (cpu.flags.zf)
    {
        goto L_0x004987e7;
    }
    // 004987dc  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004987e0  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 004987e3  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x004987e7:
    // 004987e7  837c2428ff             +cmp dword ptr [esp + 0x28], -1
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
    // 004987ec  7509                   -jne 0x4987f7
    if (!cpu.flags.zf)
    {
        goto L_0x004987f7;
    }
    // 004987ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004987f0  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004987f3  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x004987f7:
    // 004987f7  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004987fa  8b5612                 -mov edx, dword ptr [esi + 0x12]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 004987fd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00498800  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00498803  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00498805  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00498807  8a5609                 -mov dl, byte ptr [esi + 9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0049880a  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049880c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00498810  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00498817  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00498819  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049881c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049881e  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498822  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00498825  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00498827  668b5616               -mov dx, word ptr [esi + 0x16]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 0049882b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049882f  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00498832  7412                   -je 0x498846
    if (cpu.flags.zf)
    {
        goto L_0x00498846;
    }
    // 00498834  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00498837  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049883a  e861e30000             -call 0x4a6ba0
    cpu.esp -= 4;
    sub_4a6ba0(app, cpu);
    if (cpu.terminate) return;
    // 0049883f  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00498842  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00498846:
    // 00498846  e865050000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0049884b  b930ae5200             -mov ecx, 0x52ae30
    cpu.ecx = 5418544 /*0x52ae30*/;
    // 00498850  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00498853  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498855  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00498857  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049885a  8a560f                 -mov dl, byte ptr [esi + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */);
    // 0049885d  e8aa050000             -call 0x498e0c
    cpu.esp -= 4;
    sub_498e0c(app, cpu);
    if (cpu.terminate) return;
    // 00498862  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00498864  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00498868  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049886a  0f8cbf010000           -jl 0x498a2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498a2f;
    }
    // 00498870  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00498873  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00498875  bbd0a75200             -mov ebx, 0x52a7d0
    cpu.ebx = 5416912 /*0x52a7d0*/;
    // 0049887a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049887d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049887f  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00498882  89434c                 -mov dword ptr [ebx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00498885  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00498888  894350                 -mov dword ptr [ebx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0049888b  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0049888e  894354                 -mov dword ptr [ebx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00498891  8a4706                 -mov al, byte ptr [edi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 00498894  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 00498897  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049889b  c7431800000000         -mov dword ptr [ebx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004988a2  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004988a5  894320                 -mov dword ptr [ebx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004988a8  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004988ab  8b560f                 -mov edx, dword ptr [esi + 0xf]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(15) /* 0xf */);
    // 004988ae  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004988b1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004988b4  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004988b7  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004988bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004988be  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004988c1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004988c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004988c5  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004988c8  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004988cb  e8d0e20000             -call 0x4a6ba0
    cpu.esp -= 4;
    sub_4a6ba0(app, cpu);
    if (cpu.terminate) return;
    // 004988d0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004988d2  39ca                   +cmp edx, ecx
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
    // 004988d4  0f8e65010000           -jle 0x498a3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498a3f;
    }
    // 004988da  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004988dc:
    // 004988dc  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004988df  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
    // 004988e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004988e6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004988e9  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004988eb  884330                 -mov byte ptr [ebx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 004988ee  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004988f2  884332                 -mov byte ptr [ebx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 004988f5  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004988f9  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004988fc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498900  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 00498904  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498906  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00498909  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 0049890c  66894342               -mov word ptr [ebx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 00498910  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00498914  884333                 -mov byte ptr [ebx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 00498917  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049891b  e8a0800000             -call 0x4a09c0
    cpu.esp -= 4;
    sub_4a09c0(app, cpu);
    if (cpu.terminate) return;
    // 00498920  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00498923  894348                 -mov dword ptr [ebx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00498926  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 00498929  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00498930  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00498932  89432c                 -mov dword ptr [ebx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00498935  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 00498938  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049893b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049893e  c6433500               -mov byte ptr [ebx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 00498942  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00498945  8a460a                 -mov al, byte ptr [esi + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 00498948  884334                 -mov byte ptr [ebx + 0x34], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(52) /* 0x34 */) = cpu.al;
    // 0049894b  8a460b                 -mov al, byte ptr [esi + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(11) /* 0xb */);
    // 0049894e  884336                 -mov byte ptr [ebx + 0x36], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(54) /* 0x36 */) = cpu.al;
    // 00498951  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00498954  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00498956  88430a                 -mov byte ptr [ebx + 0xa], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.al;
    // 00498959  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049895d  c6430b0f               -mov byte ptr [ebx + 0xb], 0xf
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = 15 /*0xf*/;
    // 00498961  e88a490000             -call 0x49d2f0
    cpu.esp -= 4;
    sub_49d2f0(app, cpu);
    if (cpu.terminate) return;
    // 00498966  8b0dc4a75200           -mov ecx, dword ptr [0x52a7c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5416900) /* 0x52a7c4 */);
    // 0049896c  8a560e                 -mov dl, byte ptr [esi + 0xe]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 0049896f  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00498972  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498974  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00498977  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00498979  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049897a  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049897d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00498980  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00498984  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498985  8b432e                 -mov eax, dword ptr [ebx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(46) /* 0x2e */);
    // 00498988  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049898a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049898d  8a5706                 -mov dl, byte ptr [edi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 00498990  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498991  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00498995  8d4628                 -lea eax, [esi + 0x28]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00498998  e8df6ffeff             -call 0x47f97c
    cpu.esp -= 4;
    sub_47f97c(app, cpu);
    if (cpu.terminate) return;
    // 0049899d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049899f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004989a1  7d0f                   -jge 0x4989b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004989b2;
    }
    // 004989a3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004989a7  e81c070000             -call 0x4990c8
    cpu.esp -= 4;
    sub_4990c8(app, cpu);
    if (cpu.terminate) return;
    // 004989ac  891530ae5200           -mov dword ptr [0x52ae30], edx
    app->getMemory<x86::reg32>(x86::reg32(5418544) /* 0x52ae30 */) = cpu.edx;
L_0x004989b2:
    // 004989b2  e80d040000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 004989b7  a130ae5200             -mov eax, dword ptr [0x52ae30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418544) /* 0x52ae30 */);
    // 004989bc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004989bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004989c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004989c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004989c2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004989c5:
    // 004989c5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004989ca  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004989cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004989ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004989cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004989d0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004989d3:
    // 004989d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004989d5  0f8c0efdffff           -jl 0x4986e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004986e9;
    }
    // 004989db  83f87f                 +cmp eax, 0x7f
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
    // 004989de  0f8e74fdffff           -jle 0x498758
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498758;
    }
    // 004989e4  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004989e9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004989ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004989ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004989ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004989ef  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004989f2:
    // 004989f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004989f4  0f8ceffcffff           -jl 0x4986e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004986e9;
    }
    // 004989fa  83fa7f                 +cmp edx, 0x7f
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
    // 004989fd  0f8e6afdffff           -jle 0x49876d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049876d;
    }
    // 00498a03  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00498a08  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00498a0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498a0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498a0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498a0e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00498a11:
    // 00498a11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498a13  0f8d98fdffff           -jge 0x4987b1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004987b1;
    }
    // 00498a19  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00498a1b  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498a1f  e98dfdffff             -jmp 0x4987b1
    goto L_0x004987b1;
L_0x00498a24:
    // 00498a24  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00498a26  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498a2a  e9a6fdffff             -jmp 0x4987d5
    goto L_0x004987d5;
L_0x00498a2f:
    // 00498a2f  e890030000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 00498a34  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498a36  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00498a39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498a3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498a3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498a3c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00498a3f:
    // 00498a3f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498a41  0f8d95feffff           -jge 0x4988dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004988dc;
    }
    // 00498a47  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00498a49  e98efeffff             -jmp 0x4988dc
    goto L_0x004988dc;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_498a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498a50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498a52  7419                   -je 0x498a6d
    if (cpu.flags.zf)
    {
        goto L_0x00498a6d;
    }
    // 00498a54  81385041546c           +cmp dword ptr [eax], 0x6c544150
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
    // 00498a5a  7417                   -je 0x498a73
    if (cpu.flags.zf)
    {
        goto L_0x00498a73;
    }
    // 00498a5c  6681385054             +cmp word ptr [eax], 0x5450
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
    // 00498a61  0f84bd410000           -je 0x49cc24
    if (cpu.flags.zf)
    {
        return sub_49cc24(app, cpu);
    }
    // 00498a67  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00498a6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498a6d:
    // 00498a6d  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00498a72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498a73:
    // 00498a73  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498a74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498a75  8b4a06                 -mov ecx, dword ptr [edx + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00498a78  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00498a7b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498a7c  8b4a05                 -mov ecx, dword ptr [edx + 5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 00498a7f  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00498a82  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498a83  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00498a86  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00498a89  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00498a8c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00498a8f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498a90  8b4a03                 -mov ecx, dword ptr [edx + 3]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 00498a93  8b5201                 -mov edx, dword ptr [edx + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00498a96  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00498a99  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00498a9c  e8effbffff             -call 0x498690
    cpu.esp -= 4;
    sub_498690(app, cpu);
    if (cpu.terminate) return;
    // 00498aa1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498aa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498aa3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_498ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498ab0  a334ae5200             -mov dword ptr [0x52ae34], eax
    app->getMemory<x86::reg32>(x86::reg32(5418548) /* 0x52ae34 */) = cpu.eax;
    // 00498ab5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_498ab8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498ab8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498ab9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498aba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00498abc  833de4cd4c0000         +cmp dword ptr [0x4ccde4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033444) /* 0x4ccde4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498ac3  741c                   -je 0x498ae1
    if (cpu.flags.zf)
    {
        goto L_0x00498ae1;
    }
L_0x00498ac5:
    // 00498ac5  833d34ae520000         +cmp dword ptr [0x52ae34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5418548) /* 0x52ae34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498acc  741f                   -je 0x498aed
    if (cpu.flags.zf)
    {
        goto L_0x00498aed;
    }
    // 00498ace  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00498ad0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498ad2  893de0cd4c00           -mov dword ptr [0x4ccde0], edi
    app->getMemory<x86::reg32>(x86::reg32(5033440) /* 0x4ccde0 */) = cpu.edi;
    // 00498ad8  ff1534ae5200           -call dword ptr [0x52ae34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5418548) /* 0x52ae34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498ade  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498adf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ae0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498ae1:
    // 00498ae1  e8a67ffeff             -call 0x480a8c
    cpu.esp -= 4;
    sub_480a8c(app, cpu);
    if (cpu.terminate) return;
    // 00498ae6  a3e4cd4c00             -mov dword ptr [0x4ccde4], eax
    app->getMemory<x86::reg32>(x86::reg32(5033444) /* 0x4ccde4 */) = cpu.eax;
    // 00498aeb  ebd8                   -jmp 0x498ac5
    goto L_0x00498ac5;
L_0x00498aed:
    // 00498aed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498aee  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00498af3  8b15e4cd4c00           -mov edx, dword ptr [0x4ccde4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033444) /* 0x4ccde4 */);
    // 00498af9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498afb  8935e0cd4c00           -mov dword ptr [0x4ccde0], esi
    app->getMemory<x86::reg32>(x86::reg32(5033440) /* 0x4ccde0 */) = cpu.esi;
    // 00498b01  e89a7ffeff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 00498b06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b07  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498b0a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498b0a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00498b0c  e82f11feff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00498b11  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00498b13  8b2d20a44c00           -mov ebp, dword ptr [0x4ca420]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00498b19  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498b1b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00498b1e  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00498b20  e8f77cfeff             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00498b25  e979000000             -jmp 0x498ba3
    return sub_498ba3(app, cpu);
}

/* align: skip  */
void Application::sub_498b2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498b2a  8b15e4cd4c00           -mov edx, dword ptr [0x4ccde4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033444) /* 0x4ccde4 */);
    // 00498b30  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498b32  0f8481000000           -je 0x498bb9
    if (cpu.flags.zf)
    {
        return sub_498bb9(app, cpu);
    }
    // 00498b38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498b3a  e89d7ffeff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 00498b3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498b48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498b48  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498b49  8b15e4cd4c00           -mov edx, dword ptr [0x4ccde4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033444) /* 0x4ccde4 */);
    // 00498b4f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498b51  7502                   -jne 0x498b55
    if (!cpu.flags.zf)
    {
        goto L_0x00498b55;
    }
    // 00498b53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498b55:
    // 00498b55  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498b56  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00498b5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498b5d  890de0cd4c00           -mov dword ptr [0x4ccde0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5033440) /* 0x4ccde0 */) = cpu.ecx;
    // 00498b63  e8387ffeff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 00498b68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_498b6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498b6c  a1e0cd4c00             -mov eax, dword ptr [0x4ccde0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033440) /* 0x4ccde0 */);
    // 00498b71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_498b74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498b74  833d34ae520000         +cmp dword ptr [0x52ae34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5418548) /* 0x52ae34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498b7b  7409                   -je 0x498b86
    if (cpu.flags.zf)
    {
        goto L_0x00498b86;
    }
    // 00498b7d  833d20a44c0000         +cmp dword ptr [0x4ca420], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498b84  7501                   -jne 0x498b87
    if (!cpu.flags.zf)
    {
        goto L_0x00498b87;
    }
L_0x00498b86:
    // 00498b86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498b87:
    // 00498b87  e82cffffff             -call 0x498ab8
    cpu.esp -= 4;
    sub_498ab8(app, cpu);
    if (cpu.terminate) return;
    // 00498b8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498b8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498b8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498b8f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498b90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498b91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498b93  e8d07cfeff             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 00498b98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498b9a  748e                   -je 0x498b2a
    if (cpu.flags.zf)
    {
        return sub_498b2a(app, cpu);
    }
    // 00498b9c  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 00498ba1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00498ba3  3b0de4cd4c00           +cmp ecx, dword ptr [0x4ccde4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5033444) /* 0x4ccde4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498ba9  740e                   -je 0x498bb9
    if (cpu.flags.zf)
    {
        goto L_0x00498bb9;
    }
    // 00498bab  8b3de0cd4c00           -mov edi, dword ptr [0x4ccde0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5033440) /* 0x4ccde0 */);
    // 00498bb1  39f9                   +cmp ecx, edi
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
    // 00498bb3  0f8451ffffff           -je 0x498b0a
    if (cpu.flags.zf)
    {
        return sub_498b0a(app, cpu);
    }
L_0x00498bb9:
    // 00498bb9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498bb9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00498bb9;
    // 00498b74  833d34ae520000         +cmp dword ptr [0x52ae34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5418548) /* 0x52ae34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498b7b  7409                   -je 0x498b86
    if (cpu.flags.zf)
    {
        goto L_0x00498b86;
    }
    // 00498b7d  833d20a44c0000         +cmp dword ptr [0x4ca420], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498b84  7501                   -jne 0x498b87
    if (!cpu.flags.zf)
    {
        goto L_0x00498b87;
    }
L_0x00498b86:
    // 00498b86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498b87:
    // 00498b87  e82cffffff             -call 0x498ab8
    cpu.esp -= 4;
    sub_498ab8(app, cpu);
    if (cpu.terminate) return;
    // 00498b8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498b8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498b8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498b8f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498b90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498b91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498b93  e8d07cfeff             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 00498b98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498b9a  748e                   -je 0x498b2a
    if (cpu.flags.zf)
    {
        return sub_498b2a(app, cpu);
    }
    // 00498b9c  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 00498ba1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00498ba3  3b0de4cd4c00           +cmp ecx, dword ptr [0x4ccde4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5033444) /* 0x4ccde4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498ba9  740e                   -je 0x498bb9
    if (cpu.flags.zf)
    {
        goto L_0x00498bb9;
    }
    // 00498bab  8b3de0cd4c00           -mov edi, dword ptr [0x4ccde0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5033440) /* 0x4ccde0 */);
    // 00498bb1  39f9                   +cmp ecx, edi
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
    // 00498bb3  0f8451ffffff           -je 0x498b0a
    if (cpu.flags.zf)
    {
        return sub_498b0a(app, cpu);
    }
L_0x00498bb9:
L_entry_0x00498bb9:
    // 00498bb9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498ba3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00498ba3;
    // 00498b74  833d34ae520000         +cmp dword ptr [0x52ae34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5418548) /* 0x52ae34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498b7b  7409                   -je 0x498b86
    if (cpu.flags.zf)
    {
        goto L_0x00498b86;
    }
    // 00498b7d  833d20a44c0000         +cmp dword ptr [0x4ca420], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498b84  7501                   -jne 0x498b87
    if (!cpu.flags.zf)
    {
        goto L_0x00498b87;
    }
L_0x00498b86:
    // 00498b86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498b87:
    // 00498b87  e82cffffff             -call 0x498ab8
    cpu.esp -= 4;
    sub_498ab8(app, cpu);
    if (cpu.terminate) return;
    // 00498b8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498b8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498b8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498b8f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498b90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498b91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498b93  e8d07cfeff             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 00498b98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498b9a  748e                   -je 0x498b2a
    if (cpu.flags.zf)
    {
        return sub_498b2a(app, cpu);
    }
    // 00498b9c  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 00498ba1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x00498ba3:
    // 00498ba3  3b0de4cd4c00           +cmp ecx, dword ptr [0x4ccde4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5033444) /* 0x4ccde4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498ba9  740e                   -je 0x498bb9
    if (cpu.flags.zf)
    {
        goto L_0x00498bb9;
    }
    // 00498bab  8b3de0cd4c00           -mov edi, dword ptr [0x4ccde0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5033440) /* 0x4ccde0 */);
    // 00498bb1  39f9                   +cmp ecx, edi
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
    // 00498bb3  0f8451ffffff           -je 0x498b0a
    if (cpu.flags.zf)
    {
        return sub_498b0a(app, cpu);
    }
L_0x00498bb9:
    // 00498bb9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498b8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00498b8c;
    // 00498b74  833d34ae520000         +cmp dword ptr [0x52ae34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5418548) /* 0x52ae34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498b7b  7409                   -je 0x498b86
    if (cpu.flags.zf)
    {
        goto L_0x00498b86;
    }
    // 00498b7d  833d20a44c0000         +cmp dword ptr [0x4ca420], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498b84  7501                   -jne 0x498b87
    if (!cpu.flags.zf)
    {
        goto L_0x00498b87;
    }
L_0x00498b86:
    // 00498b86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498b87:
    // 00498b87  e82cffffff             -call 0x498ab8
    cpu.esp -= 4;
    sub_498ab8(app, cpu);
    if (cpu.terminate) return;
L_entry_0x00498b8c:
    // 00498b8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498b8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498b8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498b8f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498b90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498b91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498b93  e8d07cfeff             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 00498b98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498b9a  748e                   -je 0x498b2a
    if (cpu.flags.zf)
    {
        return sub_498b2a(app, cpu);
    }
    // 00498b9c  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 00498ba1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00498ba3  3b0de4cd4c00           +cmp ecx, dword ptr [0x4ccde4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5033444) /* 0x4ccde4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498ba9  740e                   -je 0x498bb9
    if (cpu.flags.zf)
    {
        goto L_0x00498bb9;
    }
    // 00498bab  8b3de0cd4c00           -mov edi, dword ptr [0x4ccde0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5033440) /* 0x4ccde0 */);
    // 00498bb1  39f9                   +cmp ecx, edi
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
    // 00498bb3  0f8451ffffff           -je 0x498b0a
    if (cpu.flags.zf)
    {
        return sub_498b0a(app, cpu);
    }
L_0x00498bb9:
    // 00498bb9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498bbe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_498bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498bc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498bc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498bc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498bc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498bc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498bc5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498bc6  ff05f0cd4c00           -inc dword ptr [0x4ccdf0]
    (app->getMemory<x86::reg32>(x86::reg32(5033456) /* 0x4ccdf0 */))++;
    // 00498bcc  ff0528ae5200           -inc dword ptr [0x52ae28]
    (app->getMemory<x86::reg32>(x86::reg32(5418536) /* 0x52ae28 */))++;
    // 00498bd2  e8a573feff             -call 0x47ff7c
    cpu.esp -= 4;
    sub_47ff7c(app, cpu);
    if (cpu.terminate) return;
    // 00498bd7  833dc0cd4c0000         +cmp dword ptr [0x4ccdc0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033408) /* 0x4ccdc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498bde  0f8524010000           -jne 0x498d08
    if (!cpu.flags.zf)
    {
        goto L_0x00498d08;
    }
L_0x00498be4:
    // 00498be4  833db4cd4c0000         +cmp dword ptr [0x4ccdb4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033396) /* 0x4ccdb4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498beb  7406                   -je 0x498bf3
    if (cpu.flags.zf)
    {
        goto L_0x00498bf3;
    }
    // 00498bed  ff15b4cd4c00           -call dword ptr [0x4ccdb4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033396) /* 0x4ccdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00498bf3:
    // 00498bf3  833db8cd4c0000         +cmp dword ptr [0x4ccdb8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033400) /* 0x4ccdb8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498bfa  0f8513010000           -jne 0x498d13
    if (!cpu.flags.zf)
    {
        goto L_0x00498d13;
    }
L_0x00498c00:
    // 00498c00  bed0a75200             -mov esi, 0x52a7d0
    cpu.esi = 5416912 /*0x52a7d0*/;
    // 00498c05  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00498c07:
    // 00498c07  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00498c0a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00498c0c  80fc01                 +cmp ah, 1
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
    // 00498c0f  0f85ba000000           -jne 0x498ccf
    if (!cpu.flags.zf)
    {
        goto L_0x00498ccf;
    }
    // 00498c15  833e00                 +cmp dword ptr [esi], 0
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
    // 00498c18  0f8cb1000000           -jl 0x498ccf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498ccf;
    }
    // 00498c1e  837e5c00               +cmp dword ptr [esi + 0x5c], 0
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
    // 00498c22  7425                   -je 0x498c49
    if (cpu.flags.zf)
    {
        goto L_0x00498c49;
    }
    // 00498c24  8a563f                 -mov dl, byte ptr [esi + 0x3f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */);
    // 00498c27  fec2                   -inc dl
    (cpu.dl)++;
    // 00498c29  88563f                 -mov byte ptr [esi + 0x3f], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */) = cpu.dl;
    // 00498c2c  3a563d                 +cmp dl, byte ptr [esi + 0x3d]
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
    // 00498c2f  7204                   -jb 0x498c35
    if (cpu.flags.cf)
    {
        goto L_0x00498c35;
    }
    // 00498c31  c6463f00               -mov byte ptr [esi + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
L_0x00498c35:
    // 00498c35  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498c37  e8847d0000             -call 0x4a09c0
    cpu.esp -= 4;
    sub_4a09c0(app, cpu);
    if (cpu.terminate) return;
    // 00498c3c  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00498c3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498c41  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00498c44  e8c776feff             -call 0x480310
    cpu.esp -= 4;
    sub_480310(app, cpu);
    if (cpu.terminate) return;
L_0x00498c49:
    // 00498c49  8b5158                 -mov edx, dword ptr [ecx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 00498c4c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00498c4e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498c50  7418                   -je 0x498c6a
    if (cpu.flags.zf)
    {
        goto L_0x00498c6a;
    }
    // 00498c52  8a413e                 -mov al, byte ptr [ecx + 0x3e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 00498c55  fec0                   -inc al
    (cpu.al)++;
    // 00498c57  88413e                 -mov byte ptr [ecx + 0x3e], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.al;
    // 00498c5a  8a613c                 -mov ah, byte ptr [ecx + 0x3c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 00498c5d  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00498c62  38e0                   +cmp al, ah
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
    // 00498c64  7204                   -jb 0x498c6a
    if (cpu.flags.cf)
    {
        goto L_0x00498c6a;
    }
    // 00498c66  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
L_0x00498c6a:
    // 00498c6a  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00498c6d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00498c6f  7431                   -je 0x498ca2
    if (cpu.flags.zf)
    {
        goto L_0x00498ca2;
    }
    // 00498c71  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00498c74  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00498c79  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498c7b  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00498c7e  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00498c81  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00498c83  0f8c95000000           -jl 0x498d1e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498d1e;
    }
    // 00498c89  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498c8b  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00498c8e  39d0                   +cmp eax, edx
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
    // 00498c90  7c0a                   -jl 0x498c9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498c9c;
    }
    // 00498c92  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00498c99  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x00498c9c:
    // 00498c9c  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 00498ca0  7c26                   -jl 0x498cc8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498cc8;
    }
L_0x00498ca2:
    // 00498ca2  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00498ca5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498ca7  7408                   -je 0x498cb1
    if (cpu.flags.zf)
    {
        goto L_0x00498cb1;
    }
    // 00498ca9  015128                 -add dword ptr [ecx + 0x28], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00498cac  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00498cb1:
    // 00498cb1  83792c00               +cmp dword ptr [ecx + 0x2c], 0
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
    // 00498cb5  0f85ac000000           -jne 0x498d67
    if (!cpu.flags.zf)
    {
        goto L_0x00498d67;
    }
    // 00498cbb  8a5135                 -mov dl, byte ptr [ecx + 0x35]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 00498cbe  fec2                   -inc dl
    (cpu.dl)++;
    // 00498cc0  885135                 -mov byte ptr [ecx + 0x35], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = cpu.dl;
    // 00498cc3  3a5134                 +cmp dl, byte ptr [ecx + 0x34]
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
    // 00498cc6  7c70                   -jl 0x498d38
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498d38;
    }
L_0x00498cc8:
    // 00498cc8  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00498cca  e8f177feff             -call 0x4804c0
    cpu.esp -= 4;
    sub_4804c0(app, cpu);
    if (cpu.terminate) return;
L_0x00498ccf:
    // 00498ccf  43                     -inc ebx
    (cpu.ebx)++;
    // 00498cd0  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00498cd3  83fb10                 +cmp ebx, 0x10
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
    // 00498cd6  0f8c2bffffff           -jl 0x498c07
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498c07;
    }
    // 00498cdc  833dbccd4c0000         +cmp dword ptr [0x4ccdbc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033404) /* 0x4ccdbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498ce3  7416                   -je 0x498cfb
    if (cpu.flags.zf)
    {
        goto L_0x00498cfb;
    }
    // 00498ce5  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00498cea  a128ae5200             -mov eax, dword ptr [0x52ae28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418536) /* 0x52ae28 */);
    // 00498cef  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00498cf1  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00498cf3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498cf5  0f84a2000000           -je 0x498d9d
    if (cpu.flags.zf)
    {
        goto L_0x00498d9d;
    }
L_0x00498cfb:
    // 00498cfb  ff0df0cd4c00           +dec dword ptr [0x4ccdf0]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5033456) /* 0x4ccdf0 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00498d01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498d02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498d03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498d04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498d05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498d06  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498d07  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498d08:
    // 00498d08  ff15c0cd4c00           -call dword ptr [0x4ccdc0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033408) /* 0x4ccdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498d0e  e9d1feffff             -jmp 0x498be4
    goto L_0x00498be4;
L_0x00498d13:
    // 00498d13  ff15b8cd4c00           -call dword ptr [0x4ccdb8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033400) /* 0x4ccdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498d19  e9e2feffff             -jmp 0x498c00
    goto L_0x00498c00;
L_0x00498d1e:
    // 00498d1e  8b691c                 -mov ebp, dword ptr [ecx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00498d21  39ea                   +cmp edx, ebp
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
    // 00498d23  0f8f73ffffff           -jg 0x498c9c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498c9c;
    }
    // 00498d29  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00498d30  896920                 -mov dword ptr [ecx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00498d33  e964ffffff             -jmp 0x498c9c
    goto L_0x00498c9c;
L_0x00498d38:
    // 00498d38  8b4132                 -mov eax, dword ptr [ecx + 0x32]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(50) /* 0x32 */);
    // 00498d3b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00498d3e  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00498d41  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00498d44  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00498d46  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00498d48  89512c                 -mov dword ptr [ecx + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00498d4b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498d4d  7c45                   -jl 0x498d94
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498d94;
    }
L_0x00498d4f:
    // 00498d4f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00498d52  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00498d55  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00498d58  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00498d5a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498d5c  8b692c                 -mov ebp, dword ptr [ecx + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00498d5f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00498d62  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00498d64  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00498d67:
    // 00498d67  ff492c                 -dec dword ptr [ecx + 0x2c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */))--;
    // 00498d6a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00498d6c  0f845dffffff           -je 0x498ccf
    if (cpu.flags.zf)
    {
        goto L_0x00498ccf;
    }
    // 00498d72  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498d74  e877450000             -call 0x49d2f0
    cpu.esp -= 4;
    sub_49d2f0(app, cpu);
    if (cpu.terminate) return;
    // 00498d79  833900                 +cmp dword ptr [ecx], 0
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
    // 00498d7c  0f8c4dffffff           -jl 0x498ccf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498ccf;
    }
    // 00498d82  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 00498d85  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498d87  c1fa18                 +sar edx, 0x18
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
    // 00498d8a  e89573feff             -call 0x480124
    cpu.esp -= 4;
    sub_480124(app, cpu);
    if (cpu.terminate) return;
    // 00498d8f  e93bffffff             -jmp 0x498ccf
    goto L_0x00498ccf;
L_0x00498d94:
    // 00498d94  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 00498d9b  ebb2                   -jmp 0x498d4f
    goto L_0x00498d4f;
L_0x00498d9d:
    // 00498d9d  ff15bccd4c00           -call dword ptr [0x4ccdbc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033404) /* 0x4ccdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498da3  ff0df0cd4c00           -dec dword ptr [0x4ccdf0]
    (app->getMemory<x86::reg32>(x86::reg32(5033456) /* 0x4ccdf0 */))--;
    // 00498da9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498daa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498dab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498dac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498dad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498dae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498daf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498db0  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 00498db5  e80e7efeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00498dba  ff05f4cd4c00           -inc dword ptr [0x4ccdf4]
    (app->getMemory<x86::reg32>(x86::reg32(5033460) /* 0x4ccdf4 */))++;
    // 00498dc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498dc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498dc4  ff0df4cd4c00           +dec dword ptr [0x4ccdf4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5033460) /* 0x4ccdf4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00498dca  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 00498dcf  e90c7efeff             -jmp 0x480be0
    return sub_480be0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_498de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498de0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498de1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498de2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00498de4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00498de6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498de8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498dea  7e12                   -jle 0x498dfe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498dfe;
    }
L_0x00498dec:
    // 00498dec  8b9035ae5200           -mov edx, dword ptr [eax + 0x52ae35]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5418549) /* 0x52ae35 */);
    // 00498df2  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00498df5  39da                   +cmp edx, ebx
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
    // 00498df7  740a                   -je 0x498e03
    if (cpu.flags.zf)
    {
        goto L_0x00498e03;
    }
    // 00498df9  40                     -inc eax
    (cpu.eax)++;
    // 00498dfa  39c8                   +cmp eax, ecx
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
    // 00498dfc  7cee                   -jl 0x498dec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498dec;
    }
L_0x00498dfe:
    // 00498dfe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498e00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498e03:
    // 00498e03  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00498e08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_498e0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498e0c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498e0d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498e0e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498e0f  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00498e12  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00498e16  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00498e1a  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00498e1e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00498e22  baf7ffffff             -mov edx, 0xfffffff7
    cpu.edx = 4294967287 /*0xfffffff7*/;
    // 00498e27  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498e2b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00498e2d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498e2f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00498e33  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00498e36  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498e38  7e12                   -jle 0x498e4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498e4c;
    }
    // 00498e3a  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 00498e3c  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x00498e40:
    // 00498e40  40                     -inc eax
    (cpu.eax)++;
    // 00498e41  889037ae5200           -mov byte ptr [eax + 0x52ae37], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5418551) /* 0x52ae37 */) = cpu.dl;
    // 00498e47  39f0                   +cmp eax, esi
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
    // 00498e49  7cf5                   -jl 0x498e40
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498e40;
    }
    // 00498e4b  90                     -nop 
    ;
L_0x00498e4c:
    // 00498e4c  8b3df8cd4c00           -mov edi, dword ptr [0x4ccdf8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5033464) /* 0x4ccdf8 */);
    // 00498e52  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00498e55  893df8cd4c00           -mov dword ptr [0x4ccdf8], edi
    app->getMemory<x86::reg32>(x86::reg32(5033464) /* 0x4ccdf8 */) = cpu.edi;
    // 00498e5b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00498e5d  7c2b                   -jl 0x498e8a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498e8a;
    }
L_0x00498e5f:
    // 00498e5f  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498e63  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498e65  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00498e67:
    // 00498e67  a1aecd4c00             -mov eax, dword ptr [0x4ccdae]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033390) /* 0x4ccdae */);
    // 00498e6c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00498e6f  39c3                   +cmp ebx, eax
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
    // 00498e71  7d4a                   -jge 0x498ebd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498ebd;
    }
    // 00498e73  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00498e78  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00498e7a  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00498e7e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00498e80  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 00498e82  750f                   -jne 0x498e93
    if (!cpu.flags.zf)
    {
        goto L_0x00498e93;
    }
L_0x00498e84:
    // 00498e84  83c660                 +add esi, 0x60
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
    // 00498e87  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00498e88  ebdd                   -jmp 0x498e67
    goto L_0x00498e67;
L_0x00498e8a:
    // 00498e8a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00498e8c  a3f8cd4c00             -mov dword ptr [0x4ccdf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5033464) /* 0x4ccdf8 */) = cpu.eax;
    // 00498e91  ebcc                   -jmp 0x498e5f
    goto L_0x00498e5f;
L_0x00498e93:
    // 00498e93  80bedca7520000         +cmp byte ptr [esi + 0x52a7dc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5416924) /* 0x52a7dc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00498e9a  75e8                   -jne 0x498e84
    if (!cpu.flags.zf)
    {
        goto L_0x00498e84;
    }
    // 00498e9c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00498e9f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498ea1  e83affffff             -call 0x498de0
    cpu.esp -= 4;
    sub_498de0(app, cpu);
    if (cpu.terminate) return;
    // 00498ea6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498ea8  75da                   -jne 0x498e84
    if (!cpu.flags.zf)
    {
        goto L_0x00498e84;
    }
    // 00498eaa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00498ead  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00498eb0  889838ae5200           -mov byte ptr [eax + 0x52ae38], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5418552) /* 0x52ae38 */) = cpu.bl;
    // 00498eb6  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00498eb9  39f9                   +cmp ecx, edi
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
    // 00498ebb  7cc7                   -jl 0x498e84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498e84;
    }
L_0x00498ebd:
    // 00498ebd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00498ec0  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498ec4  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00498ec8  39e8                   +cmp eax, ebp
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
    // 00498eca  0f8d94000000           -jge 0x498f64
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498f64;
    }
L_0x00498ed0:
    // 00498ed0  bf66000000             -mov edi, 0x66
    cpu.edi = 102 /*0x66*/;
    // 00498ed5  bdffffff7f             -mov ebp, 0x7fffffff
    cpu.ebp = 2147483647 /*0x7fffffff*/;
    // 00498eda  bed0a75200             -mov esi, 0x52a7d0
    cpu.esi = 5416912 /*0x52a7d0*/;
    // 00498edf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00498ee1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498ee3  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
L_0x00498ee7:
    // 00498ee7  a1aecd4c00             -mov eax, dword ptr [0x4ccdae]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033390) /* 0x4ccdae */);
    // 00498eec  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00498eef  39c3                   +cmp ebx, eax
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
    // 00498ef1  7d48                   -jge 0x498f3b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498f3b;
    }
    // 00498ef3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00498ef8  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00498efa  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00498efe  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00498f00  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 00498f02  7506                   -jne 0x498f0a
    if (!cpu.flags.zf)
    {
        goto L_0x00498f0a;
    }
L_0x00498f04:
    // 00498f04  83c660                 +add esi, 0x60
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
    // 00498f07  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00498f08  ebdd                   -jmp 0x498ee7
    goto L_0x00498ee7;
L_0x00498f0a:
    // 00498f0a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00498f0d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498f0f  e8ccfeffff             -call 0x498de0
    cpu.esp -= 4;
    sub_498de0(app, cpu);
    if (cpu.terminate) return;
    // 00498f14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498f16  75ec                   -jne 0x498f04
    if (!cpu.flags.zf)
    {
        goto L_0x00498f04;
    }
    // 00498f18  8a460e                 -mov al, byte ptr [esi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 00498f1b  39f8                   +cmp eax, edi
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
    // 00498f1d  7d0b                   -jge 0x498f2a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498f2a;
    }
    // 00498f1f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00498f21  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00498f25  8b6e14                 -mov ebp, dword ptr [esi + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00498f28  ebda                   -jmp 0x498f04
    goto L_0x00498f04;
L_0x00498f2a:
    // 00498f2a  75d8                   -jne 0x498f04
    if (!cpu.flags.zf)
    {
        goto L_0x00498f04;
    }
    // 00498f2c  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00498f2f  39cd                   +cmp ebp, ecx
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
    // 00498f31  7ed1                   -jle 0x498f04
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498f04;
    }
    // 00498f33  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00498f35  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00498f39  ebc9                   -jmp 0x498f04
    goto L_0x00498f04;
L_0x00498f3b:
    // 00498f3b  3b7c2410               +cmp edi, dword ptr [esp + 0x10]
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
    // 00498f3f  0f8fe2000000           -jg 0x499027
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00499027;
    }
    // 00498f45  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00498f49  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00498f4c  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498f50  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00498f53  888338ae5200           -mov byte ptr [ebx + 0x52ae38], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5418552) /* 0x52ae38 */) = cpu.al;
    // 00498f59  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00498f5c  39fe                   +cmp esi, edi
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
    // 00498f5e  0f8cc3000000           -jl 0x499027
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499027;
    }
L_0x00498f64:
    // 00498f64  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00498f67  3b442418               +cmp eax, dword ptr [esp + 0x18]
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
    // 00498f6b  0f85ab000000           -jne 0x49901c
    if (!cpu.flags.zf)
    {
        goto L_0x0049901c;
    }
    // 00498f71  8b1d35ae5200           -mov ebx, dword ptr [0x52ae35]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5418549) /* 0x52ae35 */);
    // 00498f77  a1f8cd4c00             -mov eax, dword ptr [0x4ccdf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033464) /* 0x4ccdf8 */);
    // 00498f7c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00498f7f  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498f81  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498f85  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00498f87  8b1d35ae5200           -mov ebx, dword ptr [0x52ae35]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5418549) /* 0x52ae35 */);
    // 00498f8d  8b3df8cd4c00           -mov edi, dword ptr [0x4ccdf8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5033464) /* 0x4ccdf8 */);
    // 00498f93  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00498f96  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498f98  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00498f9f  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00498fa2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498fa4  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00498fa8  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00498fab  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498fad  89b8d0a75200           -mov dword ptr [eax + 0x52a7d0], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416912) /* 0x52a7d0 */) = cpu.edi;
    // 00498fb3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00498fb5  0f8eb4000000           -jle 0x49906f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049906f;
    }
L_0x00498fbb:
    // 00498fbb  8b8335ae5200           -mov eax, dword ptr [ebx + 0x52ae35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5418549) /* 0x52ae35 */);
    // 00498fc1  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00498fc4  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 00498fc7  bfd0a75200             -mov edi, 0x52a7d0
    cpu.edi = 5416912 /*0x52a7d0*/;
    // 00498fcc  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00498fce  8a4f0c                 -mov cl, byte ptr [edi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00498fd1  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 00498fd3  80f901                 +cmp cl, 1
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
    // 00498fd6  0f8576000000           -jne 0x499052
    if (!cpu.flags.zf)
    {
        goto L_0x00499052;
    }
    // 00498fdc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00498fde  7c61                   -jl 0x499041
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499041;
    }
L_0x00498fe0:
    // 00498fe0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00498fe2  e8d974feff             -call 0x4804c0
    cpu.esp -= 4;
    sub_4804c0(app, cpu);
    if (cpu.terminate) return;
    // 00498fe7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00498fe9  e8322bfeff             -call 0x47bb20
    cpu.esp -= 4;
    sub_47bb20(app, cpu);
    if (cpu.terminate) return;
    // 00498fee  83f801                 +cmp eax, 1
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
    // 00498ff1  745f                   -je 0x499052
    if (cpu.flags.zf)
    {
        goto L_0x00499052;
    }
    // 00498ff3  4b                     -dec ebx
    (cpu.ebx)--;
    // 00498ff4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498ff6  7c1c                   -jl 0x499014
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499014;
    }
    // 00498ff8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00498ffa:
    // 00498ffa  8b8335ae5200           -mov eax, dword ptr [ebx + 0x52ae35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5418549) /* 0x52ae35 */);
    // 00499000  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00499003  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 00499006  05d0a75200             -add eax, 0x52a7d0
    (cpu.eax) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 0049900b  4b                     -dec ebx
    (cpu.ebx)--;
    // 0049900c  88500c                 -mov byte ptr [eax + 0xc], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 0049900f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499011  7de7                   -jge 0x498ffa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498ffa;
    }
    // 00499013  90                     -nop 
    ;
L_0x00499014:
    // 00499014  c744240cf7ffffff       -mov dword ptr [esp + 0xc], 0xfffffff7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 4294967287 /*0xfffffff7*/;
L_0x0049901c:
    // 0049901c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00499020  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00499023  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499024  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499025  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499026  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499027:
    // 00499027  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049902b  40                     -inc eax
    (cpu.eax)++;
    // 0049902c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00499030  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00499034  39d0                   +cmp eax, edx
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
    // 00499036  0f8c94feffff           -jl 0x498ed0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498ed0;
    }
    // 0049903c  e923ffffff             -jmp 0x498f64
    goto L_0x00498f64;
L_0x00499041:
    // 00499041  8b4741                 -mov eax, dword ptr [edi + 0x41]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(65) /* 0x41 */);
    // 00499044  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00499047  6bc060                 +imul eax, eax, 0x60
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0049904a  8bb0d0a75200           -mov esi, dword ptr [eax + 0x52a7d0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416912) /* 0x52a7d0 */);
    // 00499050  eb8e                   -jmp 0x498fe0
    goto L_0x00498fe0;
L_0x00499052:
    // 00499052  a128ae5200             -mov eax, dword ptr [0x52ae28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418536) /* 0x52ae28 */);
    // 00499057  c6470c01               -mov byte ptr [edi + 0xc], 1
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 0049905b  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049905e  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00499062  43                     -inc ebx
    (cpu.ebx)++;
    // 00499063  88470e                 -mov byte ptr [edi + 0xe], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */) = cpu.al;
    // 00499066  3b1c24                 +cmp ebx, dword ptr [esp]
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
    // 00499069  0f8c4cffffff           -jl 0x498fbb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498fbb;
    }
L_0x0049906f:
    // 0049906f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00499074  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00499077  7da3                   -jge 0x49901c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049901c;
    }
    // 00499079  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x0049907c:
    // 0049907c  8b1d35ae5200           -mov ebx, dword ptr [0x52ae35]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5418549) /* 0x52ae35 */);
    // 00499082  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00499085  6bdb60                 -imul ebx, ebx, 0x60
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 00499088  8a9038ae5200           -mov dl, byte ptr [eax + 0x52ae38]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5418552) /* 0x52ae38 */);
    // 0049908e  889403d3a75200         -mov byte ptr [ebx + eax + 0x52a7d3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5416915) /* 0x52a7d3 */ + cpu.eax * 1) = cpu.dl;
    // 00499095  8b9835ae5200           -mov ebx, dword ptr [eax + 0x52ae35]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5418549) /* 0x52ae35 */);
    // 0049909b  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0049909e  6bdb60                 -imul ebx, ebx, 0x60
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004990a1  c783d0a75200ffffffff   -mov dword ptr [ebx + 0x52a7d0], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5416912) /* 0x52a7d0 */) = 4294967295 /*0xffffffff*/;
    // 004990ab  8a1538ae5200           -mov dl, byte ptr [0x52ae38]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5418552) /* 0x52ae38 */);
    // 004990b1  40                     -inc eax
    (cpu.eax)++;
    // 004990b2  889314a85200           -mov byte ptr [ebx + 0x52a814], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5416980) /* 0x52a814 */) = cpu.dl;
    // 004990b8  39c8                   +cmp eax, ecx
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
    // 004990ba  7cc0                   -jl 0x49907c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049907c;
    }
    // 004990bc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004990c0  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004990c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004990c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004990c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004990c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4990c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004990c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004990c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004990ca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004990cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004990cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004990cd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004990ce  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004990d0  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004990d7  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004990dc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004990de  b8d0a75200             -mov eax, 0x52a7d0
    cpu.eax = 5416912 /*0x52a7d0*/;
    // 004990e3  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004990e6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004990e8  8a5c023b               -mov bl, byte ptr [edx + eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */ + cpu.eax * 1);
    // 004990ec  0fb67c023b             -movzx edi, byte ptr [edx + eax + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */ + cpu.eax * 1));
    // 004990f1  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004990f3  0f84b4000000           -je 0x4991ad
    if (cpu.flags.zf)
    {
        goto L_0x004991ad;
    }
    // 004990f9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004990fb:
    // 004990fb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004990fd  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 00499100  39fb                   +cmp ebx, edi
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
    // 00499102  7515                   -jne 0x499119
    if (!cpu.flags.zf)
    {
        goto L_0x00499119;
    }
    // 00499104  833800                 +cmp dword ptr [eax], 0
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
    // 00499107  7c10                   -jl 0x499119
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499119;
    }
    // 00499109  80780c00               +cmp byte ptr [eax + 0xc], 0
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
    // 0049910d  740a                   -je 0x499119
    if (cpu.flags.zf)
    {
        goto L_0x00499119;
    }
    // 0049910f  8a783a                 -mov bh, byte ptr [eax + 0x3a]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 00499112  41                     -inc ecx
    (cpu.ecx)++;
    // 00499113  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00499115  7402                   -je 0x499119
    if (cpu.flags.zf)
    {
        goto L_0x00499119;
    }
    // 00499117  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x00499119:
    // 00499119  42                     -inc edx
    (cpu.edx)++;
    // 0049911a  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049911d  83fa10                 +cmp edx, 0x10
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
    // 00499120  7cd9                   -jl 0x4990fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004990fb;
    }
    // 00499122  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 00499129  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049912b  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 0049912e  83f901                 +cmp ecx, 1
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
    // 00499131  7445                   -je 0x499178
    if (cpu.flags.zf)
    {
        goto L_0x00499178;
    }
    // 00499133  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0049913a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049913c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049913f  80b8dca7520002         +cmp byte ptr [eax + 0x52a7dc], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5416924) /* 0x52a7dc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499146  7509                   -jne 0x499151
    if (!cpu.flags.zf)
    {
        goto L_0x00499151;
    }
    // 00499148  39f5                   +cmp ebp, esi
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
    // 0049914a  7405                   -je 0x499151
    if (cpu.flags.zf)
    {
        goto L_0x00499151;
    }
    // 0049914c  83f902                 +cmp ecx, 2
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
    // 0049914f  7431                   -je 0x499182
    if (cpu.flags.zf)
    {
        goto L_0x00499182;
    }
L_0x00499151:
    // 00499151  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00499158  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049915a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049915d  80b8dca7520001         +cmp byte ptr [eax + 0x52a7dc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5416924) /* 0x52a7dc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499164  752c                   -jne 0x499192
    if (!cpu.flags.zf)
    {
        goto L_0x00499192;
    }
    // 00499166  39f5                   +cmp ebp, esi
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
    // 00499168  7528                   -jne 0x499192
    if (!cpu.flags.zf)
    {
        goto L_0x00499192;
    }
    // 0049916a  c680dca7520002         -mov byte ptr [eax + 0x52a7dc], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5416924) /* 0x52a7dc */) = 2 /*0x2*/;
L_0x00499171:
    // 00499171  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499172  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499173  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499174  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499175  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499176  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499177  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499178:
    // 00499178  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0049917a  8883dca75200           -mov byte ptr [ebx + 0x52a7dc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5416924) /* 0x52a7dc */) = cpu.al;
    // 00499180  ebef                   -jmp 0x499171
    goto L_0x00499171;
L_0x00499182:
    // 00499182  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00499184  888bdca75200           -mov byte ptr [ebx + 0x52a7dc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5416924) /* 0x52a7dc */) = cpu.cl;
    // 0049918a  8888dca75200           -mov byte ptr [eax + 0x52a7dc], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5416924) /* 0x52a7dc */) = cpu.cl;
    // 00499190  ebdf                   -jmp 0x499171
    goto L_0x00499171;
L_0x00499192:
    // 00499192  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00499199  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049919b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049919e  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004991a0  8898dca75200           -mov byte ptr [eax + 0x52a7dc], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5416924) /* 0x52a7dc */) = cpu.bl;
    // 004991a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004991ad:
    // 004991ad  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004991af  88badca75200           -mov byte ptr [edx + 0x52a7dc], bh
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5416924) /* 0x52a7dc */) = cpu.bh;
    // 004991b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4991bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004991bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004991bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004991be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004991c0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004991c2  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004991c5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004991cc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004991ce  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004991d1  05d0a75200             -add eax, 0x52a7d0
    (cpu.eax) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 004991d6  80780c00               +cmp byte ptr [eax + 0xc], 0
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
    // 004991da  7404                   -je 0x4991e0
    if (cpu.flags.zf)
    {
        goto L_0x004991e0;
    }
    // 004991dc  3b08                   +cmp ecx, dword ptr [eax]
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
    // 004991de  7405                   -je 0x4991e5
    if (cpu.flags.zf)
    {
        goto L_0x004991e5;
    }
L_0x004991e0:
    // 004991e0  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x004991e5:
    // 004991e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004991e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004991e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4991ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004991ea  9b                     -wait 
    /*nothing*/;
    // 004991eb  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 004991ed  9b                     -wait 
    /*nothing*/;
    // 004991ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4991ef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004991ef  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 004991f1  9b                     -wait 
    /*nothing*/;
    // 004991f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4991f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004991f3:
    // 004991f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004991f4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004991f5  803db9a94c0000         +cmp byte ptr [0x4ca9b9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024185) /* 0x4ca9b9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004991fc  7416                   -je 0x499214
    if (cpu.flags.zf)
    {
        goto L_0x00499214;
    }
    // 004991fe  baea914900             -mov edx, 0x4991ea
    cpu.edx = 4821482 /*0x4991ea*/;
    // 00499203  bbef914900             -mov ebx, 0x4991ef
    cpu.ebx = 4821487 /*0x4991ef*/;
    // 00499208  8915d0f54c00           -mov dword ptr [0x4cf5d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5043664) /* 0x4cf5d0 */) = cpu.edx;
    // 0049920e  891dd4f54c00           -mov dword ptr [0x4cf5d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5043668) /* 0x4cf5d4 */) = cpu.ebx;
L_0x00499214:
    // 00499214  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499216  66a1d8f54c00           -mov ax, word ptr [0x4cf5d8]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5043672) /* 0x4cf5d8 */);
    // 0049921c  e8b1d90000             -call 0x4a6bd2
    cpu.esp -= 4;
    sub_4a6bd2(app, cpu);
    if (cpu.terminate) return;
    // 00499221  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499222  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499223  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00499224  803db9a94c0000         +cmp byte ptr [0x4ca9b9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024185) /* 0x4ca9b9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049922b  75c6                   -jne 0x4991f3
    if (!cpu.flags.zf)
    {
        goto L_0x004991f3;
    }
    // 0049922d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49922e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049922e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049922f  8a25b8a94c00           -mov ah, byte ptr [0x4ca9b8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024184) /* 0x4ca9b8 */);
    // 00499235  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00499237  7537                   -jne 0x499270
    if (!cpu.flags.zf)
    {
        goto L_0x00499270;
    }
    // 00499239  8825b9a94c00           -mov byte ptr [0x4ca9b9], ah
    app->getMemory<x86::reg8>(x86::reg32(5024185) /* 0x4ca9b9 */) = cpu.ah;
    // 0049923f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00499241  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00499243  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499244  dbe3                   -fninit 
    cpu.fpu.init();
    // 00499246  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00499249  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049924a  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 0049924c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0049924e  3c03                   +cmp al, 3
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
    // 00499250  7509                   -jne 0x49925b
    if (!cpu.flags.zf)
    {
        goto L_0x0049925b;
    }
    // 00499252  e89cffffff             -call 0x4991f3
    cpu.esp -= 4;
    sub_4991f3(app, cpu);
    if (cpu.terminate) return;
    // 00499257  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 00499259  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x0049925b:
    // 0049925b  803d3cce4c0000         +cmp byte ptr [0x4cce3c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033532) /* 0x4cce3c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499262  750c                   -jne 0x499270
    if (!cpu.flags.zf)
    {
        goto L_0x00499270;
    }
    // 00499264  8835b8a94c00           -mov byte ptr [0x4ca9b8], dh
    app->getMemory<x86::reg8>(x86::reg32(5024184) /* 0x4ca9b8 */) = cpu.dh;
    // 0049926a  8815b9a94c00           -mov byte ptr [0x4ca9b9], dl
    app->getMemory<x86::reg8>(x86::reg32(5024185) /* 0x4ca9b9 */) = cpu.dl;
L_0x00499270:
    // 00499270  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499271  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499272(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499272  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_499280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499280  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499281  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499282  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499283  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00499286  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049928a  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049928e  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00499292  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00499296  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00499299  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049929b  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049929e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004992a1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004992a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004992a5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004992a7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004992a9  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004992ac  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004992b0  40                     -inc eax
    (cpu.eax)++;
    // 004992b1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004992b3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004992b7  8a25daa64c00           -mov ah, byte ptr [0x4ca6da]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5023450) /* 0x4ca6da */);
    // 004992bd  8b2d98ca4c00           -mov ebp, dword ptr [0x4cca98]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5032600) /* 0x4cca98 */);
    // 004992c3  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004992c5  0f8585030000           -jne 0x499650
    if (!cpu.flags.zf)
    {
        goto L_0x00499650;
    }
    // 004992cb  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004992cf  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004992d5  0f8c75030000           -jl 0x499650
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499650;
    }
    // 004992db  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004992e1  0f8d69030000           -jge 0x499650
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00499650;
    }
    // 004992e7  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004992eb  3b05cca64c00           +cmp eax, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004992f1  0f8c59030000           -jl 0x499650
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499650;
    }
    // 004992f7  3b05d4a64c00           +cmp eax, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004992fd  0f8d4d030000           -jge 0x499650
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00499650;
    }
    // 00499303  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00499307  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049930b  8b1dc8a64c00           -mov ebx, dword ptr [0x4ca6c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 00499311  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00499313  39d8                   +cmp eax, ebx
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
    // 00499315  0f8c35030000           -jl 0x499650
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499650;
    }
    // 0049931b  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499321  0f8d29030000           -jge 0x499650
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00499650;
    }
    // 00499327  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049932b  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049932f  8b1dcca64c00           -mov ebx, dword ptr [0x4ca6cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 00499335  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00499337  39d8                   +cmp eax, ebx
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
    // 00499339  0f8c11030000           -jl 0x499650
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499650;
    }
    // 0049933f  3b05d4a64c00           +cmp eax, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499345  0f8d05030000           -jge 0x499650
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00499650;
    }
    // 0049934b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049934f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499351  8a15d8a64c00           -mov dl, byte ptr [0x4ca6d8]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 00499357  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499359  80fa10                 +cmp dl, 0x10
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
    // 0049935c  0f8565010000           -jne 0x4994c7
    if (!cpu.flags.zf)
    {
        goto L_0x004994c7;
    }
    // 00499362  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00499365:
    // 00499365  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00499369  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049936d  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00499373  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00499376  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049937c  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0049937f  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 00499385  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499387  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049938b  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0049938f:
    // 0049938f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499391  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00499393  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00499396  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0049939a  81fb00000010           +cmp ebx, 0x10000000
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
    // 004993a0  726b                   -jb 0x49940d
    if (cpu.flags.cf)
    {
        goto L_0x0049940d;
    }
    // 004993a2  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004993a8  7340                   -jae 0x4993ea
    if (!cpu.flags.cf)
    {
        goto L_0x004993ea;
    }
    // 004993aa  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004993ad  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004993af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004993b1  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004993b4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004993b7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004993b9  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004993bf  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004993c2  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004993c7  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004993ca  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004993cc  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004993ce  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004993d1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004993d3  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004993d6  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004993d8  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004993db  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004993e1  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004993e6  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004993e8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004993ea:
    // 004993ea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004993ec  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004993f2  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004993f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004993f7  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004993fa  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00499400  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00499403  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499406  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499408  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049940a  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0049940d:
    // 0049940d  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00499410  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499412  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00499414  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00499417  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0049941b  81fb00000010           +cmp ebx, 0x10000000
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
    // 00499421  726b                   -jb 0x49948e
    if (cpu.flags.cf)
    {
        goto L_0x0049948e;
    }
    // 00499423  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00499429  7340                   -jae 0x49946b
    if (!cpu.flags.cf)
    {
        goto L_0x0049946b;
    }
    // 0049942b  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0049942e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00499430  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499432  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00499435  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00499438  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0049943a  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00499440  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00499443  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00499448  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0049944b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049944d  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0049944f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499452  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499454  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00499457  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00499459  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0049945c  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499462  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00499467  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00499469  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049946b:
    // 0049946b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049946d  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00499473  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00499476  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499478  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0049947b  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00499481  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00499484  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499487  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499489  01d3                   +add ebx, edx
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
    // 0049948b  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0049948e:
    // 0049948e  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00499491  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00499495  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499496  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00499497  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 0049949b  0f85eefeffff           -jne 0x49938f
    if (!cpu.flags.zf)
    {
        goto L_0x0049938f;
    }
    // 004994a1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004994a4  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004994a8  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004994ac  41                     -inc ecx
    (cpu.ecx)++;
    // 004994ad  01d7                   +add edi, edx
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
    // 004994af  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004994b3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004994b4  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 004994b8  0f85a7feffff           -jne 0x499365
    if (!cpu.flags.zf)
    {
        goto L_0x00499365;
    }
L_0x004994be:
    // 004994be  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004994c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004994c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004994c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004994c4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004994c7:
    // 004994c7  80fa0f                 +cmp dl, 0xf
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
    // 004994ca  0f8577010000           -jne 0x499647
    if (!cpu.flags.zf)
    {
        goto L_0x00499647;
    }
    // 004994d0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004994d4:
    // 004994d4  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004994d8  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004994dc  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 004994e2  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004994e5  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 004994eb  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004994ee  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 004994f4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004994f6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004994fa  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x004994fe:
    // 004994fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499500  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00499502  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00499505  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00499508  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0049950b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049950d  81fb00000010           +cmp ebx, 0x10000000
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
    // 00499513  7273                   -jb 0x499588
    if (cpu.flags.cf)
    {
        goto L_0x00499588;
    }
    // 00499515  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0049951b  7348                   -jae 0x499565
    if (!cpu.flags.cf)
    {
        goto L_0x00499565;
    }
    // 0049951d  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00499520  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499522  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 00499527  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0049952a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049952c  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00499532  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00499535  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00499537  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049953a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049953c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049953e  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00499541  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499547  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00499549  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049954c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049954e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499550  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00499553  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499559  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049955b  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0049955e  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00499563  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00499565:
    // 00499565  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499567  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0049956d  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00499570  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499572  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00499575  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0049957b  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0049957e  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499581  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499583  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00499585  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00499588:
    // 00499588  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0049958b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049958d  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049958f  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00499592  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 00499596  81fb00000010           +cmp ebx, 0x10000000
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
    // 0049959c  7273                   -jb 0x499611
    if (cpu.flags.cf)
    {
        goto L_0x00499611;
    }
    // 0049959e  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004995a4  7348                   -jae 0x4995ee
    if (!cpu.flags.cf)
    {
        goto L_0x004995ee;
    }
    // 004995a6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004995a9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004995ab  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004995b0  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004995b3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004995b5  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004995bb  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004995be  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004995c0  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004995c3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004995c5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004995c7  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004995ca  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004995d0  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004995d2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004995d5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004995d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004995d9  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004995dc  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004995e2  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004995e4  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004995e7  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004995ec  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004995ee:
    // 004995ee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004995f0  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004995f6  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004995f9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004995fb  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004995fe  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00499604  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00499607  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049960a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049960c  01d3                   +add ebx, edx
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
    // 0049960e  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00499611:
    // 00499611  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00499614  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00499618  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499619  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049961a  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0049961e  0f85dafeffff           -jne 0x4994fe
    if (!cpu.flags.zf)
    {
        goto L_0x004994fe;
    }
    // 00499624  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499628  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049962c  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00499630  40                     -inc eax
    (cpu.eax)++;
    // 00499631  01f7                   +add edi, esi
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
    // 00499633  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00499637  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00499638  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0049963c  0f847cfeffff           -je 0x4994be
    if (cpu.flags.zf)
    {
        goto L_0x004994be;
    }
    // 00499642  e98dfeffff             -jmp 0x4994d4
    goto L_0x004994d4;
L_0x00499647:
    // 00499647  80fa08                 +cmp dl, 8
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
    // 0049964a  0f849c000000           -je 0x4996ec
    if (cpu.flags.zf)
    {
        goto L_0x004996ec;
    }
L_0x00499650:
    // 00499650  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00499654  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499656  0f8e62feffff           -jle 0x4994be
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004994be;
    }
    // 0049965c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00499660  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00499664  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00499668  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049966a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049966c  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00499670  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00499674:
    // 00499674  8b742448               -mov esi, dword ptr [esp + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00499678  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049967a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049967c  7e51                   -jle 0x4996cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004996cf;
    }
    // 0049967e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00499682  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00499686  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049968a  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0049968e  46                     -inc esi
    (cpu.esi)++;
L_0x0049968f:
    // 0049968f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499691  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00499693  47                     -inc edi
    (cpu.edi)++;
    // 00499694  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499696  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00499699  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0049969c  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004996a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004996a2  0f858f000000           -jne 0x499737
    if (!cpu.flags.zf)
    {
        goto L_0x00499737;
    }
L_0x004996a8:
    // 004996a8  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004996ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004996ae  7411                   -je 0x4996c1
    if (cpu.flags.zf)
    {
        goto L_0x004996c1;
    }
    // 004996b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004996b2  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004996b6  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004996ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004996bc  e83fd50000             -call 0x4a6c00
    cpu.esp -= 4;
    sub_4a6c00(app, cpu);
    if (cpu.terminate) return;
L_0x004996c1:
    // 004996c1  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004996c5  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004996c8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004996cb  39c1                   +cmp ecx, eax
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
    // 004996cd  7cc0                   -jl 0x49968f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049968f;
    }
L_0x004996cf:
    // 004996cf  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004996d3  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004996d7  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004996db  46                     -inc esi
    (cpu.esi)++;
    // 004996dc  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004996de  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004996e2  39d6                   +cmp esi, edx
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
    // 004996e4  0f8dd4fdffff           -jge 0x4994be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004994be;
    }
    // 004996ea  eb88                   -jmp 0x499674
    goto L_0x00499674;
L_0x004996ec:
    // 004996ec  8b1de4a64c00           -mov ebx, dword ptr [0x4ca6e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023460) /* 0x4ca6e4 */);
    // 004996f2  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004996f4  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004996f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004996f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004996f8  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004996fc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004996fd  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00499701  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499702  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00499706  8b0de8a64c00           -mov ecx, dword ptr [0x4ca6e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049970c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049970f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499711  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00499716  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00499718  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049971c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049971e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00499720  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499721  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499722  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00499725  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499726  e861d70000             -call 0x4a6e8c
    cpu.esp -= 4;
    sub_4a6e8c(app, cpu);
    if (cpu.terminate) return;
    // 0049972b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049972e  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00499731  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499732  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499733  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499734  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00499737:
    // 00499737  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0049973b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049973f  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00499743  01c8                   +add eax, ecx
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
    // 00499745  e8b6d40000             -call 0x4a6c00
    cpu.esp -= 4;
    sub_4a6c00(app, cpu);
    if (cpu.terminate) return;
    // 0049974a  e959ffffff             -jmp 0x4996a8
    goto L_0x004996a8;
}

/* align: skip 0x90 */
void Application::sub_499750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499750  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499751  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499752  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499753  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00499756  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049975a  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049975e  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00499762  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499764  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00499766  0f8eae000000           -jle 0x49981a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049981a;
    }
    // 0049976c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049976e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499770  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00499773  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00499775  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00499777  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0049977b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049977e  6bc700                 -imul eax, edi, 0
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 00499781  0faf7c2430             -imul edi, dword ptr [esp + 0x30]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */))));
    // 00499786  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00499789  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0049978d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049978f  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00499791  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00499793  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00499797  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0049979b:
    // 0049979b  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049979f  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004997a2  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004997a6  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004997a8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004997aa  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004997ac  7e4d                   -jle 0x4997fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004997fb;
    }
    // 004997ae  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004997b2  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004997b6  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004997ba  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004997be  46                     -inc esi
    (cpu.esi)++;
L_0x004997bf:
    // 004997bf  0fb62f                 -movzx ebp, byte ptr [edi]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 004997c2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004997c4  47                     -inc edi
    (cpu.edi)++;
    // 004997c5  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 004997c8  83e50f                 -and ebp, 0xf
    cpu.ebp &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004997cb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004997cd  7554                   -jne 0x499823
    if (!cpu.flags.zf)
    {
        goto L_0x00499823;
    }
L_0x004997cf:
    // 004997cf  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004997d1  741a                   -je 0x4997ed
    if (cpu.flags.zf)
    {
        goto L_0x004997ed;
    }
    // 004997d3  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 004997da  81c340ca4c00           -add ebx, 0x4cca40
    (cpu.ebx) += x86::reg32(x86::sreg32(5032512 /*0x4cca40*/));
    // 004997e0  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004997e4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004997e6  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004997e8  e8e36e0000             -call 0x4a06d0
    cpu.esp -= 4;
    sub_4a06d0(app, cpu);
    if (cpu.terminate) return;
L_0x004997ed:
    // 004997ed  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004997f1  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004997f4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004997f7  39e9                   +cmp ecx, ebp
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
    // 004997f9  7cc4                   -jl 0x4997bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004997bf;
    }
L_0x004997fb:
    // 004997fb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004997ff  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00499803  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00499807  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049980b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049980d  41                     -inc ecx
    (cpu.ecx)++;
    // 0049980e  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00499812  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00499816  39d9                   +cmp ecx, ebx
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
    // 00499818  7c81                   -jl 0x49979b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049979b;
    }
L_0x0049981a:
    // 0049981a  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049981d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049981e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049981f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499820  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00499823:
    // 00499823  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00499826  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049982a  81c340ca4c00           -add ebx, 0x4cca40
    (cpu.ebx) += x86::reg32(x86::sreg32(5032512 /*0x4cca40*/));
    // 00499830  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00499834  01c8                   +add eax, ecx
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
    // 00499836  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00499838  e8936e0000             -call 0x4a06d0
    cpu.esp -= 4;
    sub_4a06d0(app, cpu);
    if (cpu.terminate) return;
    // 0049983d  eb90                   -jmp 0x4997cf
    goto L_0x004997cf;
}

/* align: skip 0x90 */
void Application::sub_499840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499840  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499841  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499842  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499843  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00499846  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499848  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049984c  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00499850  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00499854  a0d8a64c00             -mov al, byte ptr [0x4ca6d8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 00499859  3c10                   +cmp al, 0x10
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
    // 0049985b  0f837c010000           -jae 0x4999dd
    if (!cpu.flags.cf)
    {
        goto L_0x004999dd;
    }
    // 00499861  3c08                   +cmp al, 8
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
    // 00499863  0f82ac010000           -jb 0x499a15
    if (cpu.flags.cf)
    {
        goto L_0x00499a15;
    }
    // 00499869  0f8798010000           -ja 0x499a07
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00499a07;
    }
    // 0049986f  bf3c9e4900             -mov edi, 0x499e3c
    cpu.edi = 4824636 /*0x499e3c*/;
L_0x00499874:
    // 00499874  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00499876  0f8499010000           -je 0x499a15
    if (cpu.flags.zf)
    {
        goto L_0x00499a15;
    }
    // 0049987c  8b2dc8a64c00           -mov ebp, dword ptr [0x4ca6c8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 00499882  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499884  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499886  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049988a  39ee                   +cmp esi, ebp
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
    // 0049988c  7d04                   -jge 0x499892
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00499892;
    }
    // 0049988e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499890  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00499892:
    // 00499892  8b0dcca64c00           -mov ecx, dword ptr [0x4ca6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 00499898  39ca                   +cmp edx, ecx
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
    // 0049989a  7d06                   -jge 0x4998a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004998a2;
    }
    // 0049989c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049989e  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004998a2:
    // 004998a2  8b2dd0a64c00           -mov ebp, dword ptr [0x4ca6d0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 004998a8  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004998ab  39e9                   +cmp ecx, ebp
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
    // 004998ad  7e04                   -jle 0x4998b3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004998b3;
    }
    // 004998af  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004998b1  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004998b3:
    // 004998b3  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004998b7  8b2dd4a64c00           -mov ebp, dword ptr [0x4ca6d4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 004998bd  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004998bf  39e9                   +cmp ecx, ebp
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
    // 004998c1  7e08                   -jle 0x4998cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004998cb;
    }
    // 004998c3  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004998c5  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004998c7  894c2444               -mov dword ptr [esp + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ecx;
L_0x004998cb:
    // 004998cb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004998cd  0f8c42010000           -jl 0x499a15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499a15;
    }
    // 004998d3  837c244400             +cmp dword ptr [esp + 0x44], 0
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
    // 004998d8  0f8c37010000           -jl 0x499a15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499a15;
    }
    // 004998de  39d8                   +cmp eax, ebx
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
    // 004998e0  0f8d2f010000           -jge 0x499a15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00499a15;
    }
    // 004998e6  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004998ea  3b4c2444               +cmp ecx, dword ptr [esp + 0x44]
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
    // 004998ee  0f8d21010000           -jge 0x499a15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00499a15;
    }
    // 004998f4  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004998f8  036c2418               -add ebp, dword ptr [esp + 0x18]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004998fc  0faf6c2448             -imul ebp, dword ptr [esp + 0x48]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */))));
    // 00499901  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00499904  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499908  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049990b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049990d  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00499910  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00499913  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00499916  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049991a  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049991c  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 0049991f  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00499923  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00499926  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0049992a  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0049992e  03542418               -add edx, dword ptr [esp + 0x18]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00499932  8b2de8a64c00           -mov ebp, dword ptr [0x4ca6e8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00499938  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049993b  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049993d  8b2ddca64c00           -mov ebp, dword ptr [0x4ca6dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00499943  032a                   -add ebp, dword ptr [edx]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00499945  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0049994b  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049994d  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00499950  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00499953  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499955  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00499957  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00499959  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0049995c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049995e  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00499962  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00499965  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00499969  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049996b  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0049996e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00499972  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00499974  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00499979  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049997b  b108                   -mov cl, 8
    cpu.cl = 8 /*0x8*/;
    // 0049997d  88442424               -mov byte ptr [esp + 0x24], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.al;
    // 00499981  2a4c2410               -sub cl, byte ptr [esp + 0x10]
    (cpu.cl) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00499985  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00499987  d2e0                   -shl al, cl
    cpu.al <<= cpu.cl % 32;
    // 00499989  88442420               -mov byte ptr [esp + 0x20], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.al;
L_0x0049998d:
    // 0049998d  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00499991  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00499994  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00499998  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049999c  39f0                   +cmp eax, esi
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
    // 0049999e  0f8d71000000           -jge 0x499a15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00499a15;
    }
    // 004999a4  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004999a8  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004999ac  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004999b0  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004999b2  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
    // 004999b6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004999b8  7564                   -jne 0x499a1e
    if (!cpu.flags.zf)
    {
        goto L_0x00499a1e;
    }
L_0x004999ba:
    // 004999ba  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 004999bf  0f8591000000           -jne 0x499a56
    if (!cpu.flags.zf)
    {
        goto L_0x00499a56;
    }
L_0x004999c5:
    // 004999c5  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004999c9  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004999cd  8b1de4a64c00           -mov ebx, dword ptr [0x4ca6e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023460) /* 0x4ca6e4 */);
    // 004999d3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004999d5  01dd                   +add ebp, ebx
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
    // 004999d7  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004999db  ebb0                   -jmp 0x49998d
    goto L_0x0049998d;
L_0x004999dd:
    // 004999dd  770a                   -ja 0x4999e9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004999e9;
    }
    // 004999df  bf809e4900             -mov edi, 0x499e80
    cpu.edi = 4824704 /*0x499e80*/;
    // 004999e4  e98bfeffff             -jmp 0x499874
    goto L_0x00499874;
L_0x004999e9:
    // 004999e9  3c18                   +cmp al, 0x18
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
    // 004999eb  7228                   -jb 0x499a15
    if (cpu.flags.cf)
    {
        goto L_0x00499a15;
    }
    // 004999ed  770a                   -ja 0x4999f9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004999f9;
    }
    // 004999ef  bfd09e4900             -mov edi, 0x499ed0
    cpu.edi = 4824784 /*0x499ed0*/;
    // 004999f4  e97bfeffff             -jmp 0x499874
    goto L_0x00499874;
L_0x004999f9:
    // 004999f9  3c20                   +cmp al, 0x20
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
    // 004999fb  7518                   -jne 0x499a15
    if (!cpu.flags.zf)
    {
        goto L_0x00499a15;
    }
    // 004999fd  bf609f4900             -mov edi, 0x499f60
    cpu.edi = 4824928 /*0x499f60*/;
    // 00499a02  e96dfeffff             -jmp 0x499874
    goto L_0x00499874;
L_0x00499a07:
    // 00499a07  3c0f                   +cmp al, 0xf
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
    // 00499a09  750a                   -jne 0x499a15
    if (!cpu.flags.zf)
    {
        goto L_0x00499a15;
    }
    // 00499a0b  bf809e4900             -mov edi, 0x499e80
    cpu.edi = 4824704 /*0x499e80*/;
    // 00499a10  e95ffeffff             -jmp 0x499874
    goto L_0x00499874;
L_0x00499a15:
    // 00499a15  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00499a18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a1b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00499a1e:
    // 00499a1e  8a5c2424               -mov bl, byte ptr [esp + 0x24]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00499a22  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00499a24  8b1538ca4c00           -mov edx, dword ptr [0x4cca38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032504) /* 0x4cca38 */);
    // 00499a2a  20d8                   -and al, bl
    cpu.al &= x86::reg8(x86::sreg8(cpu.bl));
    // 00499a2c  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00499a31  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00499a33  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499a35  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499a37  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00499a39  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499a3a  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
L_0x00499a3e:
    // 00499a3e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00499a3f  0f8475ffffff           -je 0x4999ba
    if (cpu.flags.zf)
    {
        goto L_0x004999ba;
    }
    // 00499a45  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00499a47  8b1538ca4c00           -mov edx, dword ptr [0x4cca38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032504) /* 0x4cca38 */);
    // 00499a4d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00499a4f  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499a50  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499a52  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499a54  ebe8                   -jmp 0x499a3e
    goto L_0x00499a3e;
L_0x00499a56:
    // 00499a56  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00499a58  8a642428               -mov ah, byte ptr [esp + 0x28]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00499a5c  8a4c2420               -mov cl, byte ptr [esp + 0x20]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00499a60  20e0                   -and al, ah
    cpu.al &= x86::reg8(x86::sreg8(cpu.ah));
    // 00499a62  8b1538ca4c00           -mov edx, dword ptr [0x4cca38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032504) /* 0x4cca38 */);
    // 00499a68  20c8                   -and al, cl
    cpu.al &= x86::reg8(x86::sreg8(cpu.cl));
    // 00499a6a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00499a6f  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499a71  e94fffffff             -jmp 0x4999c5
    goto L_0x004999c5;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_499a78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499a78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499a79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499a7a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499a7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499a7c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499a7d  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 00499a83  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 00499a8a  8994240c030000         -mov dword ptr [esp + 0x30c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */) = cpu.edx;
    // 00499a91  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00499a93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00499a95:
    // 00499a95  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00499a98  8b88709f5200           -mov ecx, dword ptr [eax + 0x529f70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5414768) /* 0x529f70 */);
    // 00499a9e  8b98709f5200           -mov ebx, dword ptr [eax + 0x529f70]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5414768) /* 0x529f70 */);
    // 00499aa4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00499aa7  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00499aaa  884c14fd               -mov byte ptr [esp + edx - 3], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-3) /* -0x3 */ + cpu.edx * 1) = cpu.cl;
    // 00499aae  885c14fe               -mov byte ptr [esp + edx - 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.edx * 1) = cpu.bl;
    // 00499ab2  8a98709f5200           -mov bl, byte ptr [eax + 0x529f70]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5414768) /* 0x529f70 */);
    // 00499ab8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499abb  885c14ff               -mov byte ptr [esp + edx - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1) = cpu.bl;
    // 00499abf  3d00040000             +cmp eax, 0x400
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
    // 00499ac4  75cf                   -jne 0x499a95
    if (!cpu.flags.zf)
    {
        goto L_0x00499a95;
    }
    // 00499ac6  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00499acd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00499acf  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00499ad2  89bc2404030000         -mov dword ptr [esp + 0x304], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.edi;
    // 00499ad9  89842408030000         -mov dword ptr [esp + 0x308], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */) = cpu.eax;
L_0x00499ae0:
    // 00499ae0  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 00499ae7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499ae9  8a0414                 -mov al, byte ptr [esp + edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 00499aec  89842418030000         -mov dword ptr [esp + 0x318], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.eax;
    // 00499af3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499af5  8a441401               -mov al, byte ptr [esp + edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.edx * 1);
    // 00499af9  89842410030000         -mov dword ptr [esp + 0x310], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */) = cpu.eax;
    // 00499b00  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499b02  8b8c2400030000         -mov ecx, dword ptr [esp + 0x300]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00499b09  8a441402               -mov al, byte ptr [esp + edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.edx * 1);
    // 00499b0d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00499b0f  89842414030000         -mov dword ptr [esp + 0x314], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */) = cpu.eax;
L_0x00499b16:
    // 00499b16  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00499b18  8a5103                 -mov dl, byte ptr [ecx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 00499b1b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499b1d  754b                   -jne 0x499b6a
    if (!cpu.flags.zf)
    {
        goto L_0x00499b6a;
    }
    // 00499b1f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00499b21:
    // 00499b21  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499b23  8b9c240c030000         -mov ebx, dword ptr [esp + 0x30c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 00499b2a  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00499b2c  8bac2408030000         -mov ebp, dword ptr [esp + 0x308]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 00499b33  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00499b35  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499b38  81c600010000           -add esi, 0x100
    (cpu.esi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00499b3e  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00499b40  39e9                   +cmp ecx, ebp
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
    // 00499b42  75d2                   -jne 0x499b16
    if (!cpu.flags.zf)
    {
        goto L_0x00499b16;
    }
    // 00499b44  8b842404030000         -mov eax, dword ptr [esp + 0x304]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 00499b4b  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00499b4e  47                     -inc edi
    (cpu.edi)++;
    // 00499b4f  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 00499b56  81ff00010000           +cmp edi, 0x100
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
    // 00499b5c  7c82                   -jl 0x499ae0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499ae0;
    }
    // 00499b5e  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 00499b64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499b6a:
    // 00499b6a  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 00499b6f  89942424030000         -mov dword ptr [esp + 0x324], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.edx;
    // 00499b76  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00499b78  8b942418030000         -mov edx, dword ptr [esp + 0x318]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */);
    // 00499b7f  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00499b82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499b84  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00499b87  8984241c030000         -mov dword ptr [esp + 0x31c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */) = cpu.eax;
    // 00499b8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499b90  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00499b92  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 00499b9d  89842420030000         -mov dword ptr [esp + 0x320], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */) = cpu.eax;
    // 00499ba4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499ba6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00499ba9  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00499bb0  0384241c030000         -add eax, dword ptr [esp + 0x31c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */)));
    // 00499bb7  0fb66901               -movzx ebp, byte ptr [ecx + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */));
    // 00499bbb  3dff000000             +cmp eax, 0xff
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
    // 00499bc0  7e05                   -jle 0x499bc7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499bc7;
    }
    // 00499bc2  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00499bc7:
    // 00499bc7  8b942410030000         -mov edx, dword ptr [esp + 0x310]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 00499bce  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00499bd1  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 00499bdc  89842428030000         -mov dword ptr [esp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 00499be3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499be5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00499be8  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00499bef  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00499bf1  3dff000000             +cmp eax, 0xff
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
    // 00499bf6  7e05                   -jle 0x499bfd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499bfd;
    }
    // 00499bf8  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00499bfd:
    // 00499bfd  8b942414030000         -mov edx, dword ptr [esp + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 00499c04  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00499c07  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00499c09  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 00499c0e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499c10  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00499c13  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00499c15  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 00499c1c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499c1e  39da                   +cmp edx, ebx
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
    // 00499c20  7e02                   -jle 0x499c24
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499c24;
    }
    // 00499c22  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00499c24:
    // 00499c24  8b842424030000         -mov eax, dword ptr [esp + 0x324]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 00499c2b  8b9c2428030000         -mov ebx, dword ptr [esp + 0x328]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */);
    // 00499c32  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00499c35  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00499c38  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 00499c3b  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499c3d  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00499c3f  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00499c41  e8d6e4fdff             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00499c46  e9d6feffff             -jmp 0x499b21
    goto L_0x00499b21;
}

/* align: skip 0x90 */
void Application::sub_499c4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499c4c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499c4d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499c4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499c4f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499c50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499c51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499c52  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00499c55  8b1598ca4c00           -mov edx, dword ptr [0x4cca98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032600) /* 0x4cca98 */);
    // 00499c5b  e840c4ffff             -call 0x4960a0
    cpu.esp -= 4;
    sub_4960a0(app, cpu);
    if (cpu.terminate) return;
    // 00499c60  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499c62  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499c64  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499c69  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00499c6c  6be800                 -imul ebp, eax, 0
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 00499c6f  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00499c72  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499c78  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00499c7c  6bdb00                 -imul ebx, ebx, 0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 00499c7f  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 00499c82  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499c88  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00499c8c  6bff00                 -imul edi, edi, 0
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 00499c8f  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00499c93  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00499c95  8d4240                 -lea eax, [edx + 0x40]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 00499c98  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00499c9a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00499c9e:
    // 00499c9e  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 00499ca6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499ca8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499caa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00499cad  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00499cb1  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 00499cb9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00499cbb  884103                 -mov byte ptr [ecx + 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00499cbe  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499cc0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00499cc3  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00499cc7  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 00499ccf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00499cd1  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00499cd4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499cd6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00499cd9  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00499cdd  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 00499ce5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00499ce7  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00499cea  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499cec  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00499cef  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00499cf3  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499cf6  81c6ff000000           -add esi, 0xff
    (cpu.esi) += x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499cfc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00499cff  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 00499d02  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00499d06  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00499d08  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00499d0c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499d0e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499d12  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00499d14  39c1                   +cmp ecx, eax
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
    // 00499d16  7586                   -jne 0x499c9e
    if (!cpu.flags.zf)
    {
        goto L_0x00499c9e;
    }
    // 00499d18  803dd8a64c0008         +cmp byte ptr [0x4ca6d8], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499d1f  760a                   -jbe 0x499d2b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499d2b;
    }
    // 00499d21  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00499d24  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d25  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d26  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499d2b:
    // 00499d2b  8b1598ca4c00           -mov edx, dword ptr [0x4cca98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032600) /* 0x4cca98 */);
    // 00499d31  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499d35  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00499d38  e83bfdffff             -call 0x499a78
    cpu.esp -= 4;
    sub_499a78(app, cpu);
    if (cpu.terminate) return;
    // 00499d3d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00499d40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_499d48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499d48  833d98ca4c0000         +cmp dword ptr [0x4cca98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032600) /* 0x4cca98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d4f  7519                   -jne 0x499d6a
    if (!cpu.flags.zf)
    {
        goto L_0x00499d6a;
    }
    // 00499d51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499d52  b940100000             -mov ecx, 0x1040
    cpu.ecx = 4160 /*0x1040*/;
    // 00499d57  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499d59  890d9cca4c00           -mov dword ptr [0x4cca9c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5032604) /* 0x4cca9c */) = cpu.ecx;
    // 00499d5f  e85c4fffff             -call 0x48ecc0
    cpu.esp -= 4;
    sub_48ecc0(app, cpu);
    if (cpu.terminate) return;
    // 00499d64  a398ca4c00             -mov dword ptr [0x4cca98], eax
    app->getMemory<x86::reg32>(x86::reg32(5032600) /* 0x4cca98 */) = cpu.eax;
    // 00499d69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00499d6a:
    // 00499d6a  e835000000             -call 0x499da4
    cpu.esp -= 4;
    sub_499da4(app, cpu);
    if (cpu.terminate) return;
    // 00499d6f  833d20ca4c0001         +cmp dword ptr [0x4cca20], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032480) /* 0x4cca20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d76  7414                   -je 0x499d8c
    if (cpu.flags.zf)
    {
        goto L_0x00499d8c;
    }
    // 00499d78  833d24ca4c0000         +cmp dword ptr [0x4cca24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032484) /* 0x4cca24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d7f  7416                   -je 0x499d97
    if (cpu.flags.zf)
    {
        goto L_0x00499d97;
    }
    // 00499d81  c705a0ca4c0080924900   -mov dword ptr [0x4ccaa0], 0x499280
    app->getMemory<x86::reg32>(x86::reg32(5032608) /* 0x4ccaa0 */) = 4821632 /*0x499280*/;
    // 00499d8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499d8c:
    // 00499d8c  c705a0ca4c0040984900   -mov dword ptr [0x4ccaa0], 0x499840
    app->getMemory<x86::reg32>(x86::reg32(5032608) /* 0x4ccaa0 */) = 4823104 /*0x499840*/;
    // 00499d96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499d97:
    // 00499d97  c705a0ca4c0050974900   -mov dword ptr [0x4ccaa0], 0x499750
    app->getMemory<x86::reg32>(x86::reg32(5032608) /* 0x4ccaa0 */) = 4822864 /*0x499750*/;
    // 00499da1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_499da4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499da4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499da5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499da6  833dbcca4c0000         +cmp dword ptr [0x4ccabc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032636) /* 0x4ccabc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499dad  7515                   -jne 0x499dc4
    if (!cpu.flags.zf)
    {
        goto L_0x00499dc4;
    }
    // 00499daf  833d24ca4c0000         +cmp dword ptr [0x4cca24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032484) /* 0x4cca24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499db6  7409                   -je 0x499dc1
    if (cpu.flags.zf)
    {
        goto L_0x00499dc1;
    }
    // 00499db8  833d20ca4c0004         +cmp dword ptr [0x4cca20], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032480) /* 0x4cca20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499dbf  7431                   -je 0x499df2
    if (cpu.flags.zf)
    {
        goto L_0x00499df2;
    }
L_0x00499dc1:
    // 00499dc1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dc3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499dc4:
    // 00499dc4  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00499dc9  b840ca4c00             -mov eax, 0x4cca40
    cpu.eax = 5032512 /*0x4cca40*/;
    // 00499dce  8b1598ca4c00           -mov edx, dword ptr [0x4cca98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032600) /* 0x4cca98 */);
    // 00499dd4  e82778feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00499dd9  803dd8a64c0008         +cmp byte ptr [0x4ca6d8], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499de0  77df                   -ja 0x499dc1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00499dc1;
    }
    // 00499de2  a198ca4c00             -mov eax, dword ptr [0x4cca98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032600) /* 0x4cca98 */);
    // 00499de7  8d5040                 -lea edx, [eax + 0x40]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00499dea  e889fcffff             -call 0x499a78
    cpu.esp -= 4;
    sub_499a78(app, cpu);
    if (cpu.terminate) return;
    // 00499def  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499df0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499df1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499df2:
    // 00499df2  a138ca4c00             -mov eax, dword ptr [0x4cca38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032504) /* 0x4cca38 */);
    // 00499df7  e850feffff             -call 0x499c4c
    cpu.esp -= 4;
    sub_499c4c(app, cpu);
    if (cpu.terminate) return;
    // 00499dfc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_499e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499e00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499e01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499e02  8b1598ca4c00           -mov edx, dword ptr [0x4cca98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032600) /* 0x4cca98 */);
    // 00499e08  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499e0a  750b                   -jne 0x499e17
    if (!cpu.flags.zf)
    {
        goto L_0x00499e17;
    }
    // 00499e0c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00499e0e  8935a0ca4c00           -mov dword ptr [0x4ccaa0], esi
    app->getMemory<x86::reg32>(x86::reg32(5032608) /* 0x4ccaa0 */) = cpu.esi;
    // 00499e14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499e17:
    // 00499e17  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499e18  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499e1a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499e1c  e8074fffff             -call 0x48ed28
    cpu.esp -= 4;
    sub_48ed28(app, cpu);
    if (cpu.terminate) return;
    // 00499e21  890d98ca4c00           -mov dword ptr [0x4cca98], ecx
    app->getMemory<x86::reg32>(x86::reg32(5032600) /* 0x4cca98 */) = cpu.ecx;
    // 00499e27  890d9cca4c00           -mov dword ptr [0x4cca9c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5032604) /* 0x4cca9c */) = cpu.ecx;
    // 00499e2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e2e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00499e30  8935a0ca4c00           -mov dword ptr [0x4ccaa0], esi
    app->getMemory<x86::reg32>(x86::reg32(5032608) /* 0x4ccaa0 */) = cpu.esi;
    // 00499e36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e37  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499e3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499e3c  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00499e3e  7532                   -jne 0x499e72
    if (!cpu.flags.zf)
    {
        goto L_0x00499e72;
    }
L_0x00499e40:
    // 00499e40  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00499e42  7403                   -je 0x499e47
    if (cpu.flags.zf)
    {
        goto L_0x00499e47;
    }
    // 00499e44  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
L_0x00499e47:
    // 00499e47  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00499e49  7403                   -je 0x499e4e
    if (cpu.flags.zf)
    {
        goto L_0x00499e4e;
    }
    // 00499e4b  885302                 -mov byte ptr [ebx + 2], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x00499e4e:
    // 00499e4e  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00499e50  7403                   -je 0x499e55
    if (cpu.flags.zf)
    {
        goto L_0x00499e55;
    }
    // 00499e52  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
L_0x00499e55:
    // 00499e55  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00499e57  7403                   -je 0x499e5c
    if (cpu.flags.zf)
    {
        goto L_0x00499e5c;
    }
    // 00499e59  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
L_0x00499e5c:
    // 00499e5c  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00499e5e  7403                   -je 0x499e63
    if (cpu.flags.zf)
    {
        goto L_0x00499e63;
    }
    // 00499e60  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
L_0x00499e63:
    // 00499e63  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00499e65  7403                   -je 0x499e6a
    if (cpu.flags.zf)
    {
        goto L_0x00499e6a;
    }
    // 00499e67  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
L_0x00499e6a:
    // 00499e6a  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00499e6c  7508                   -jne 0x499e76
    if (!cpu.flags.zf)
    {
        goto L_0x00499e76;
    }
    // 00499e6e  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00499e71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499e72:
    // 00499e72  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 00499e74  ebca                   -jmp 0x499e40
    goto L_0x00499e40;
L_0x00499e76:
    // 00499e76  885307                 -mov byte ptr [ebx + 7], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.dl;
    // 00499e79  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00499e7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499e80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499e81  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00499e83  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00499e85  7539                   -jne 0x499ec0
    if (!cpu.flags.zf)
    {
        goto L_0x00499ec0;
    }
L_0x00499e87:
    // 00499e87  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00499e89  7404                   -je 0x499e8f
    if (cpu.flags.zf)
    {
        goto L_0x00499e8f;
    }
    // 00499e8b  66895102               -mov word ptr [ecx + 2], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
L_0x00499e8f:
    // 00499e8f  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00499e91  7404                   -je 0x499e97
    if (cpu.flags.zf)
    {
        goto L_0x00499e97;
    }
    // 00499e93  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x00499e97:
    // 00499e97  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00499e99  7404                   -je 0x499e9f
    if (cpu.flags.zf)
    {
        goto L_0x00499e9f;
    }
    // 00499e9b  66895106               -mov word ptr [ecx + 6], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.dx;
L_0x00499e9f:
    // 00499e9f  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00499ea1  7404                   -je 0x499ea7
    if (cpu.flags.zf)
    {
        goto L_0x00499ea7;
    }
    // 00499ea3  66895108               -mov word ptr [ecx + 8], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.dx;
L_0x00499ea7:
    // 00499ea7  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00499ea9  7404                   -je 0x499eaf
    if (cpu.flags.zf)
    {
        goto L_0x00499eaf;
    }
    // 00499eab  6689510a               -mov word ptr [ecx + 0xa], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.dx;
L_0x00499eaf:
    // 00499eaf  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00499eb1  7404                   -je 0x499eb7
    if (cpu.flags.zf)
    {
        goto L_0x00499eb7;
    }
    // 00499eb3  6689510c               -mov word ptr [ecx + 0xc], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
L_0x00499eb7:
    // 00499eb7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00499eb9  750a                   -jne 0x499ec5
    if (!cpu.flags.zf)
    {
        goto L_0x00499ec5;
    }
    // 00499ebb  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499ebe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ebf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499ec0:
    // 00499ec0  668913                 -mov word ptr [ebx], dx
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.dx;
    // 00499ec3  ebc2                   -jmp 0x499e87
    goto L_0x00499e87;
L_0x00499ec5:
    // 00499ec5  6689510e               -mov word ptr [ecx + 0xe], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 00499ec9  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499ecc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ecd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_499ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499ed0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499ed1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499ed4  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00499ed7  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00499eda  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00499edd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00499ee0  88cc                   -mov ah, cl
    cpu.ah = cpu.cl;
    // 00499ee2  8a3424                 -mov dh, byte ptr [esp]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp);
    // 00499ee5  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00499ee7  755a                   -jne 0x499f43
    if (!cpu.flags.zf)
    {
        goto L_0x00499f43;
    }
L_0x00499ee9:
    // 00499ee9  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00499eeb  7409                   -je 0x499ef6
    if (cpu.flags.zf)
    {
        goto L_0x00499ef6;
    }
    // 00499eed  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
    // 00499ef0  886304                 -mov byte ptr [ebx + 4], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 00499ef3  887305                 -mov byte ptr [ebx + 5], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dh;
L_0x00499ef6:
    // 00499ef6  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00499ef8  7409                   -je 0x499f03
    if (cpu.flags.zf)
    {
        goto L_0x00499f03;
    }
    // 00499efa  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00499efd  886307                 -mov byte ptr [ebx + 7], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.ah;
    // 00499f00  887308                 -mov byte ptr [ebx + 8], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.dh;
L_0x00499f03:
    // 00499f03  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00499f05  7409                   -je 0x499f10
    if (cpu.flags.zf)
    {
        goto L_0x00499f10;
    }
    // 00499f07  885309                 -mov byte ptr [ebx + 9], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = cpu.dl;
    // 00499f0a  88630a                 -mov byte ptr [ebx + 0xa], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.ah;
    // 00499f0d  88730b                 -mov byte ptr [ebx + 0xb], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = cpu.dh;
L_0x00499f10:
    // 00499f10  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00499f12  7409                   -je 0x499f1d
    if (cpu.flags.zf)
    {
        goto L_0x00499f1d;
    }
    // 00499f14  88530c                 -mov byte ptr [ebx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00499f17  88630d                 -mov byte ptr [ebx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00499f1a  88730e                 -mov byte ptr [ebx + 0xe], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.dh;
L_0x00499f1d:
    // 00499f1d  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00499f1f  7409                   -je 0x499f2a
    if (cpu.flags.zf)
    {
        goto L_0x00499f2a;
    }
    // 00499f21  88530f                 -mov byte ptr [ebx + 0xf], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 00499f24  886310                 -mov byte ptr [ebx + 0x10], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 00499f27  887311                 -mov byte ptr [ebx + 0x11], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = cpu.dh;
L_0x00499f2a:
    // 00499f2a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00499f2c  7409                   -je 0x499f37
    if (cpu.flags.zf)
    {
        goto L_0x00499f37;
    }
    // 00499f2e  885312                 -mov byte ptr [ebx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 00499f31  886313                 -mov byte ptr [ebx + 0x13], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(19) /* 0x13 */) = cpu.ah;
    // 00499f34  887314                 -mov byte ptr [ebx + 0x14], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.dh;
L_0x00499f37:
    // 00499f37  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00499f39  7512                   -jne 0x499f4d
    if (!cpu.flags.zf)
    {
        goto L_0x00499f4d;
    }
    // 00499f3b  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00499f3e  83c404                 +add esp, 4
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
    // 00499f41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499f42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499f43:
    // 00499f43  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 00499f45  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00499f48  887302                 -mov byte ptr [ebx + 2], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dh;
    // 00499f4b  eb9c                   -jmp 0x499ee9
    goto L_0x00499ee9;
L_0x00499f4d:
    // 00499f4d  885315                 -mov byte ptr [ebx + 0x15], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = cpu.dl;
    // 00499f50  886316                 -mov byte ptr [ebx + 0x16], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = cpu.ah;
    // 00499f53  887317                 -mov byte ptr [ebx + 0x17], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */) = cpu.dh;
    // 00499f56  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00499f59  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499f5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499f5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_499f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499f60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499f61  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00499f63  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00499f65  7533                   -jne 0x499f9a
    if (!cpu.flags.zf)
    {
        goto L_0x00499f9a;
    }
L_0x00499f67:
    // 00499f67  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00499f69  7403                   -je 0x499f6e
    if (cpu.flags.zf)
    {
        goto L_0x00499f6e;
    }
    // 00499f6b  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00499f6e:
    // 00499f6e  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00499f70  7403                   -je 0x499f75
    if (cpu.flags.zf)
    {
        goto L_0x00499f75;
    }
    // 00499f72  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00499f75:
    // 00499f75  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00499f77  7403                   -je 0x499f7c
    if (cpu.flags.zf)
    {
        goto L_0x00499f7c;
    }
    // 00499f79  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00499f7c:
    // 00499f7c  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00499f7e  7403                   -je 0x499f83
    if (cpu.flags.zf)
    {
        goto L_0x00499f83;
    }
    // 00499f80  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x00499f83:
    // 00499f83  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00499f85  7403                   -je 0x499f8a
    if (cpu.flags.zf)
    {
        goto L_0x00499f8a;
    }
    // 00499f87  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00499f8a:
    // 00499f8a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00499f8c  7403                   -je 0x499f91
    if (cpu.flags.zf)
    {
        goto L_0x00499f91;
    }
    // 00499f8e  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x00499f91:
    // 00499f91  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00499f93  7509                   -jne 0x499f9e
    if (!cpu.flags.zf)
    {
        goto L_0x00499f9e;
    }
    // 00499f95  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00499f98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499f99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499f9a:
    // 00499f9a  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00499f9c  ebc9                   -jmp 0x499f67
    goto L_0x00499f67;
L_0x00499f9e:
    // 00499f9e  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00499fa1  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00499fa4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fa5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499fa6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499fa6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499fa8  7503                   -jne 0x499fad
    if (!cpu.flags.zf)
    {
        goto L_0x00499fad;
    }
    // 00499faa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00499fac:
    // 00499fac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499fad:
    // 00499fad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499faf  74fb                   -je 0x499fac
    if (cpu.flags.zf)
    {
        goto L_0x00499fac;
    }
    // 00499fb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499fb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499fb4  e873010000             -call 0x49a12c
    cpu.esp -= 4;
    sub_49a12c(app, cpu);
    if (cpu.terminate) return;
    // 00499fb9  83fa7b                 +cmp edx, 0x7b
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
    // 00499fbc  7507                   -jne 0x499fc5
    if (!cpu.flags.zf)
    {
        goto L_0x00499fc5;
    }
    // 00499fbe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00499fc3  eb31                   -jmp 0x499ff6
    goto L_0x00499ff6;
L_0x00499fc5:
    // 00499fc5  81face000000           +cmp edx, 0xce
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
    // 00499fcb  7507                   -jne 0x499fd4
    if (!cpu.flags.zf)
    {
        goto L_0x00499fd4;
    }
    // 00499fcd  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00499fd2  eb22                   -jmp 0x499ff6
    goto L_0x00499ff6;
L_0x00499fd4:
    // 00499fd4  81fab7000000           +cmp edx, 0xb7
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
    // 00499fda  7507                   -jne 0x499fe3
    if (!cpu.flags.zf)
    {
        goto L_0x00499fe3;
    }
    // 00499fdc  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00499fe1  eb13                   -jmp 0x499ff6
    goto L_0x00499ff6;
L_0x00499fe3:
    // 00499fe3  83fa13                 +cmp edx, 0x13
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
    // 00499fe6  7605                   -jbe 0x499fed
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499fed;
    }
    // 00499fe8  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00499fed:
    // 00499fed  8b825dce4c00           -mov eax, dword ptr [edx + 0x4cce5d]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5033565) /* 0x4cce5d */);
    // 00499ff3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00499ff6:
    // 00499ff6  e805010000             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 00499ffb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049a000  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a001  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499fb1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00499fb1;
    // 00499fa6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499fa8  7503                   -jne 0x499fad
    if (!cpu.flags.zf)
    {
        goto L_0x00499fad;
    }
    // 00499faa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00499fac:
    // 00499fac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499fad:
    // 00499fad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499faf  74fb                   -je 0x499fac
    if (cpu.flags.zf)
    {
        goto L_0x00499fac;
    }
L_entry_0x00499fb1:
    // 00499fb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499fb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499fb4  e873010000             -call 0x49a12c
    cpu.esp -= 4;
    sub_49a12c(app, cpu);
    if (cpu.terminate) return;
    // 00499fb9  83fa7b                 +cmp edx, 0x7b
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
    // 00499fbc  7507                   -jne 0x499fc5
    if (!cpu.flags.zf)
    {
        goto L_0x00499fc5;
    }
    // 00499fbe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00499fc3  eb31                   -jmp 0x499ff6
    goto L_0x00499ff6;
L_0x00499fc5:
    // 00499fc5  81face000000           +cmp edx, 0xce
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
    // 00499fcb  7507                   -jne 0x499fd4
    if (!cpu.flags.zf)
    {
        goto L_0x00499fd4;
    }
    // 00499fcd  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00499fd2  eb22                   -jmp 0x499ff6
    goto L_0x00499ff6;
L_0x00499fd4:
    // 00499fd4  81fab7000000           +cmp edx, 0xb7
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
    // 00499fda  7507                   -jne 0x499fe3
    if (!cpu.flags.zf)
    {
        goto L_0x00499fe3;
    }
    // 00499fdc  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00499fe1  eb13                   -jmp 0x499ff6
    goto L_0x00499ff6;
L_0x00499fe3:
    // 00499fe3  83fa13                 +cmp edx, 0x13
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
    // 00499fe6  7605                   -jbe 0x499fed
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499fed;
    }
    // 00499fe8  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00499fed:
    // 00499fed  8b825dce4c00           -mov eax, dword ptr [edx + 0x4cce5d]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5033565) /* 0x4cce5d */);
    // 00499ff3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00499ff6:
    // 00499ff6  e805010000             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 00499ffb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049a000  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a001  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a002(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a002  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a003  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a004  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a00b  e8a1ffffff             -call 0x499fb1
    cpu.esp -= 4;
    sub_499fb1(app, cpu);
    if (cpu.terminate) return;
    // 0049a010  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a011  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a012  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::malloc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a013  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a014  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a015  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a016  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a017  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a018  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049a019  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049a01b  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049a01d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a01e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a021  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049a023  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a025  7405                   -je 0x49a02c
    if (cpu.flags.zf)
    {
        goto L_0x0049a02c;
    }
    // 0049a027  83f8d4                 +cmp eax, -0x2c
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
    // 0049a02a  7607                   -jbe 0x49a033
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a033;
    }
L_0x0049a02c:
    // 0049a02c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049a02e  e9be000000             -jmp 0x49a0f1
    goto L_0x0049a0f1;
L_0x0049a033:
    // 0049a033  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 0049a036  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0049a039  83fd10                 +cmp ebp, 0x10
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
    // 0049a03c  7305                   -jae 0x49a043
    if (!cpu.flags.cf)
    {
        goto L_0x0049a043;
    }
    // 0049a03e  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x0049a043:
    // 0049a043  ff15a4e34c00           -call dword ptr [0x4ce3a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039012) /* 0x4ce3a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a049  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049a04b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a04d  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x0049a050:
    // 0049a050  3b2d7cce4c00           +cmp ebp, dword ptr [0x4cce7c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5033596) /* 0x4cce7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a056  760c                   -jbe 0x49a064
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a064;
    }
    // 0049a058  8b0d78ce4c00           -mov ecx, dword ptr [0x4cce78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5033592) /* 0x4cce78 */);
    // 0049a05e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a060  7510                   -jne 0x49a072
    if (!cpu.flags.zf)
    {
        goto L_0x0049a072;
    }
    // 0049a062  eb02                   -jmp 0x49a066
    goto L_0x0049a066;
L_0x0049a064:
    // 0049a064  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049a066:
    // 0049a066  890d7cce4c00           -mov dword ptr [0x4cce7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5033596) /* 0x4cce7c */) = cpu.ecx;
    // 0049a06c  8b0d74ce4c00           -mov ecx, dword ptr [0x4cce74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5033588) /* 0x4cce74 */);
L_0x0049a072:
    // 0049a072  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a074  743c                   -je 0x49a0b2
    if (cpu.flags.zf)
    {
        goto L_0x0049a0b2;
    }
    // 0049a076  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0049a079  890d78ce4c00           -mov dword ptr [0x4cce78], ecx
    app->getMemory<x86::reg32>(x86::reg32(5033592) /* 0x4cce78 */) = cpu.ecx;
    // 0049a07f  39fe                   +cmp esi, edi
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
    // 0049a081  721c                   -jb 0x49a09f
    if (cpu.flags.cf)
    {
        goto L_0x0049a09f;
    }
    // 0049a083  b874ce4c00             -mov eax, 0x4cce74
    cpu.eax = 5033588 /*0x4cce74*/;
    // 0049a088  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0049a08a  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049a090  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049a092  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a094  e807cf0000             -call 0x4a6fa0
    cpu.esp -= 4;
    sub_4a6fa0(app, cpu);
    if (cpu.terminate) return;
    // 0049a099  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a09b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a09d  7542                   -jne 0x49a0e1
    if (!cpu.flags.zf)
    {
        goto L_0x0049a0e1;
    }
L_0x0049a09f:
    // 0049a09f  3b357cce4c00           +cmp esi, dword ptr [0x4cce7c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5033596) /* 0x4cce7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a0a5  7606                   -jbe 0x49a0ad
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a0ad;
    }
    // 0049a0a7  89357cce4c00           -mov dword ptr [0x4cce7c], esi
    app->getMemory<x86::reg32>(x86::reg32(5033596) /* 0x4cce7c */) = cpu.esi;
L_0x0049a0ad:
    // 0049a0ad  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049a0b0  ebc0                   -jmp 0x49a072
    goto L_0x0049a072;
L_0x0049a0b2:
    // 0049a0b2  803c2400               +cmp byte ptr [esp], 0
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
    // 0049a0b6  750b                   -jne 0x49a0c3
    if (!cpu.flags.zf)
    {
        goto L_0x0049a0c3;
    }
    // 0049a0b8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a0ba  e8c7d10000             -call 0x4a7286
    cpu.esp -= 4;
    sub_4a7286(app, cpu);
    if (cpu.terminate) return;
    // 0049a0bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a0c1  7515                   -jne 0x49a0d8
    if (!cpu.flags.zf)
    {
        goto L_0x0049a0d8;
    }
L_0x0049a0c3:
    // 0049a0c3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a0c5  e817d20000             -call 0x4a72e1
    cpu.esp -= 4;
    sub_4a72e1(app, cpu);
    if (cpu.terminate) return;
    // 0049a0ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a0cc  7413                   -je 0x49a0e1
    if (cpu.flags.zf)
    {
        goto L_0x0049a0e1;
    }
    // 0049a0ce  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 0049a0d0  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 0049a0d3  e978ffffff             -jmp 0x49a050
    goto L_0x0049a050;
L_0x0049a0d8:
    // 0049a0d8  c6042401               -mov byte ptr [esp], 1
    app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 0049a0dc  e96fffffff             -jmp 0x49a050
    goto L_0x0049a050;
L_0x0049a0e1:
    // 0049a0e1  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 0049a0e3  882d60845400           -mov byte ptr [0x548460], ch
    app->getMemory<x86::reg8>(x86::reg32(5538912) /* 0x548460 */) = cpu.ch;
    // 0049a0e9  ff15ace34c00           -call dword ptr [0x4ce3ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039020) /* 0x4ce3ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a0ef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0049a0f1:
    // 0049a0f1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a0f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0f5  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049a0f7  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049a0f9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049a0fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x0049a100:
    // 0049a100  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a101  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a103  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a109  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049a10c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a10d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0049a10e  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0049a113  ebeb                   -jmp 0x49a100
    goto L_0x0049a100;
}

/* align: skip  */
void Application::sub_49a115(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a115  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0049a11a  ebe4                   -jmp 0x49a100
    return sub_49a100(app, cpu);
}

/* align: skip  */
void Application::sub_49a11c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a11c  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0049a121  e8daffffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049a126  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049a12b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a12c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a12c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a12d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a12f  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a135  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049a138  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a139  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_49a13c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a13c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a13d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a13e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a13f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a140  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049a142  8b3d98d95100           -mov edi, dword ptr [0x51d998]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5364120) /* 0x51d998 */);
    // 0049a148  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a14a  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 0049a150  7420                   -je 0x49a172
    if (cpu.flags.zf)
    {
        goto L_0x0049a172;
    }
    // 0049a152  83ed01                 +sub ebp, 1
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
    // 0049a155  7818                   -js 0x49a16f
    if (cpu.flags.sf)
    {
        goto L_0x0049a16f;
    }
L_0x0049a157:
    // 0049a157  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049a159  80f9ff                 +cmp cl, 0xff
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
    // 0049a15c  7411                   -je 0x49a16f
    if (cpu.flags.zf)
    {
        goto L_0x0049a16f;
    }
    // 0049a15e  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0049a161  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 0049a164  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049a167  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049a16a  83ed01                 +sub ebp, 1
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
    // 0049a16d  79e8                   -jns 0x49a157
    if (!cpu.flags.sf)
    {
        goto L_0x0049a157;
    }
L_0x0049a16f:
    // 0049a16f  83c501                 -add ebp, 1
    (cpu.ebp) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049a172:
    // 0049a172  83ed02                 +sub ebp, 2
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
    // 0049a175  7859                   -js 0x49a1d0
    if (cpu.flags.sf)
    {
        goto L_0x0049a1d0;
    }
L_0x0049a177:
    // 0049a177  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049a179  80f9ff                 +cmp cl, 0xff
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
    // 0049a17c  7428                   -je 0x49a1a6
    if (cpu.flags.zf)
    {
        goto L_0x0049a1a6;
    }
    // 0049a17e  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0049a181  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049a184  80f9ff                 +cmp cl, 0xff
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
    // 0049a187  7439                   -je 0x49a1c2
    if (cpu.flags.zf)
    {
        goto L_0x0049a1c2;
    }
    // 0049a189  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0049a18c  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049a192  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0049a195  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a197  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
L_0x0049a199:
    // 0049a199  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a19c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049a19f  83ed02                 +sub ebp, 2
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
    // 0049a1a2  79d3                   -jns 0x49a177
    if (!cpu.flags.sf)
    {
        goto L_0x0049a177;
    }
    // 0049a1a4  eb2a                   -jmp 0x49a1d0
    goto L_0x0049a1d0;
L_0x0049a1a6:
    // 0049a1a6  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049a1a9  80f9ff                 +cmp cl, 0xff
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
    // 0049a1ac  74eb                   -je 0x49a199
    if (cpu.flags.zf)
    {
        goto L_0x0049a199;
    }
    // 0049a1ae  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0049a1b1  66895a02               -mov word ptr [edx + 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bx;
    // 0049a1b5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a1b8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049a1bb  83ed02                 +sub ebp, 2
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
    // 0049a1be  79b7                   -jns 0x49a177
    if (!cpu.flags.sf)
    {
        goto L_0x0049a177;
    }
    // 0049a1c0  eb0e                   -jmp 0x49a1d0
    goto L_0x0049a1d0;
L_0x0049a1c2:
    // 0049a1c2  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 0049a1c5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a1c8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049a1cb  83ed02                 +sub ebp, 2
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
    // 0049a1ce  79a7                   -jns 0x49a177
    if (!cpu.flags.sf)
    {
        goto L_0x0049a177;
    }
L_0x0049a1d0:
    // 0049a1d0  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049a1d3  83ed01                 +sub ebp, 1
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
    // 0049a1d6  7818                   -js 0x49a1f0
    if (cpu.flags.sf)
    {
        goto L_0x0049a1f0;
    }
L_0x0049a1d8:
    // 0049a1d8  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049a1da  80f9ff                 +cmp cl, 0xff
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
    // 0049a1dd  7411                   -je 0x49a1f0
    if (cpu.flags.zf)
    {
        goto L_0x0049a1f0;
    }
    // 0049a1df  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0049a1e2  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 0049a1e5  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049a1e8  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049a1eb  83ed01                 +sub ebp, 1
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
    // 0049a1ee  79e8                   -jns 0x49a1d8
    if (!cpu.flags.sf)
    {
        goto L_0x0049a1d8;
    }
L_0x0049a1f0:
    // 0049a1f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a1f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a1f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a1f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a1f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49a200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a200  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a201  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a202  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a204  42                     -inc edx
    (cpu.edx)++;
    // 0049a205  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a207  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0049a20a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049a20c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a20e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a20f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a210  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49a214(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a214  83f820                 +cmp eax, 0x20
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
    // 0049a217  7c12                   -jl 0x49a22b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a22b;
    }
    // 0049a219  83f87f                 +cmp eax, 0x7f
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
    // 0049a21c  7f0d                   -jg 0x49a22b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a22b;
    }
    // 0049a21e  668b044544ce4c00       -mov ax, word ptr [eax*2 + 0x4cce44]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5033540) /* 0x4cce44 */ + cpu.eax * 2);
    // 0049a226  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x0049a22b:
    // 0049a22b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a22c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a22c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a22d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a22e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a230  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a232  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049a234  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0049a236  42                     -inc edx
    (cpu.edx)++;
    // 0049a237  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0049a239  7416                   -je 0x49a251
    if (cpu.flags.zf)
    {
        goto L_0x0049a251;
    }
    // 0049a23b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a23c  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0049a23e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049a241  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049a243  42                     -inc edx
    (cpu.edx)++;
    // 0049a244  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a246  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a247  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0049a249  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049a24e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a24f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a250  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a251:
    // 0049a251  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049a256  e8b9ffffff             -call 0x49a214
    cpu.esp -= 4;
    sub_49a214(app, cpu);
    if (cpu.terminate) return;
    // 0049a25b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0049a25d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049a262  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a263  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a264  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49a270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a272  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a273  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a274  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049a276  8b35c8a64c00           -mov esi, dword ptr [0x4ca6c8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0049a27c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a27e  39f0                   +cmp eax, esi
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
    // 0049a280  7c4e                   -jl 0x49a2d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a2d0;
    }
    // 0049a282  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a288  7d46                   -jge 0x49a2d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a2d0;
    }
    // 0049a28a  3b15cca64c00           +cmp edx, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a290  7c3e                   -jl 0x49a2d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a2d0;
    }
    // 0049a292  3b15d4a64c00           +cmp edx, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a298  7d36                   -jge 0x49a2d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a2d0;
    }
    // 0049a29a  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049a29f  8b35eca64c00           -mov esi, dword ptr [0x4ca6ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0049a2a5  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0049a2a8  8b3c9e                 -mov edi, dword ptr [esi + ebx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 0049a2ab  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 0049a2b0  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049a2b2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a2b4  a0d8a64c00             -mov al, byte ptr [0x4ca6d8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 0049a2b9  3c0f                   +cmp al, 0xf
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
    // 0049a2bb  731a                   -jae 0x49a2d7
    if (!cpu.flags.cf)
    {
        goto L_0x0049a2d7;
    }
    // 0049a2bd  3c04                   +cmp al, 4
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
    // 0049a2bf  720f                   -jb 0x49a2d0
    if (cpu.flags.cf)
    {
        goto L_0x0049a2d0;
    }
    // 0049a2c1  772f                   -ja 0x49a2f2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049a2f2;
    }
    // 0049a2c3  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0049a2c6  7432                   -je 0x49a2fa
    if (cpu.flags.zf)
    {
        goto L_0x0049a2fa;
    }
    // 0049a2c8  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049a2ca  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0049a2cd  83e10f                 +and ecx, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/))));
L_0x0049a2d0:
    // 0049a2d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a2d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a2d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a2d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a2d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a2d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a2d7:
    // 0049a2d7  7608                   -jbe 0x49a2e1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a2e1;
    }
    // 0049a2d9  3c18                   +cmp al, 0x18
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
    // 0049a2db  730b                   -jae 0x49a2e8
    if (!cpu.flags.cf)
    {
        goto L_0x0049a2e8;
    }
    // 0049a2dd  3c10                   +cmp al, 0x10
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
    // 0049a2df  75ef                   -jne 0x49a2d0
    if (!cpu.flags.zf)
    {
        goto L_0x0049a2d0;
    }
L_0x0049a2e1:
    // 0049a2e1  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049a2e3  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049a2e6  ebe8                   -jmp 0x49a2d0
    goto L_0x0049a2d0;
L_0x0049a2e8:
    // 0049a2e8  761c                   -jbe 0x49a306
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a306;
    }
    // 0049a2ea  3c20                   +cmp al, 0x20
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
    // 0049a2ec  75e2                   -jne 0x49a2d0
    if (!cpu.flags.zf)
    {
        goto L_0x0049a2d0;
    }
    // 0049a2ee  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049a2f0  ebde                   -jmp 0x49a2d0
    goto L_0x0049a2d0;
L_0x0049a2f2:
    // 0049a2f2  3c08                   +cmp al, 8
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
    // 0049a2f4  75da                   -jne 0x49a2d0
    if (!cpu.flags.zf)
    {
        goto L_0x0049a2d0;
    }
    // 0049a2f6  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049a2f8  ebd6                   -jmp 0x49a2d0
    goto L_0x0049a2d0;
L_0x0049a2fa:
    // 0049a2fa  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049a2fc  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0049a2ff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a301  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a302  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a303  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a304  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a305  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a306:
    // 0049a306  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049a30b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a30d  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0049a311  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049a313  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049a31a  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049a31c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a31e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a320  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a321  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a322  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a323  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a324  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49a328(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a328  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a329  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a32a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 0049a330  7423                   -je 0x49a355
    if (cpu.flags.zf)
    {
        goto L_0x0049a355;
    }
    // 0049a332  83fb01                 +cmp ebx, 1
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
    // 0049a335  7c1e                   -jl 0x49a355
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a355;
    }
    // 0049a337  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049a33a  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a33d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049a33f  81e1c0ff0000           -and ecx, 0xffc0
    cpu.ecx &= x86::reg32(x86::sreg32(65472 /*0xffc0*/));
    // 0049a345  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 0049a347  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049a34a  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a34c  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0049a34f  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0049a352  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
L_0x0049a355:
    // 0049a355  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a358  7821                   -js 0x49a37b
    if (cpu.flags.sf)
    {
        goto L_0x0049a37b;
    }
L_0x0049a35a:
    // 0049a35a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a35c  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049a35f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049a361  81e1c0ffc0ff           -and ecx, 0xffc0ffc0
    cpu.ecx &= x86::reg32(x86::sreg32(4290838464 /*0xffc0ffc0*/));
    // 0049a367  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 0049a369  81e61f001f00           -and esi, 0x1f001f
    cpu.esi &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 0049a36f  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a371  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a374  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049a376  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049a379  79df                   -jns 0x49a35a
    if (!cpu.flags.sf)
    {
        goto L_0x0049a35a;
    }
L_0x0049a37b:
    // 0049a37b  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a37e  7820                   -js 0x49a3a0
    if (cpu.flags.sf)
    {
        goto L_0x0049a3a0;
    }
L_0x0049a380:
    // 0049a380  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049a383  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a386  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049a388  81e1c0ff0000           -and ecx, 0xffc0
    cpu.ecx &= x86::reg32(x86::sreg32(65472 /*0xffc0*/));
    // 0049a38e  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 0049a390  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049a393  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a395  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a398  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0049a39b  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049a39e  79e0                   -jns 0x49a380
    if (!cpu.flags.sf)
    {
        goto L_0x0049a380;
    }
L_0x0049a3a0:
    // 0049a3a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a3a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a3a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a3a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a3a5  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 0049a3ab  7423                   -je 0x49a3d0
    if (cpu.flags.zf)
    {
        goto L_0x0049a3d0;
    }
    // 0049a3ad  83fb01                 +cmp ebx, 1
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
    // 0049a3b0  7c1e                   -jl 0x49a3d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a3d0;
    }
    // 0049a3b2  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049a3b5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a3b8  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049a3ba  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 0049a3c0  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a3c2  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049a3c5  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a3c7  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0049a3ca  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0049a3cd  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
L_0x0049a3d0:
    // 0049a3d0  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a3d3  7821                   -js 0x49a3f6
    if (cpu.flags.sf)
    {
        goto L_0x0049a3f6;
    }
L_0x0049a3d5:
    // 0049a3d5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a3d7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049a3da  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049a3dc  81e1e07fe07f           -and ecx, 0x7fe07fe0
    cpu.ecx &= x86::reg32(x86::sreg32(2145419232 /*0x7fe07fe0*/));
    // 0049a3e2  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a3e4  81e61f001f00           -and esi, 0x1f001f
    cpu.esi &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 0049a3ea  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a3ec  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a3ef  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049a3f1  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049a3f4  79df                   -jns 0x49a3d5
    if (!cpu.flags.sf)
    {
        goto L_0x0049a3d5;
    }
L_0x0049a3f6:
    // 0049a3f6  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a3f9  7820                   -js 0x49a41b
    if (cpu.flags.sf)
    {
        goto L_0x0049a41b;
    }
L_0x0049a3fb:
    // 0049a3fb  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049a3fe  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a401  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049a403  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 0049a409  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a40b  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049a40e  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a410  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a413  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0049a416  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049a419  79e0                   -jns 0x49a3fb
    if (!cpu.flags.sf)
    {
        goto L_0x0049a3fb;
    }
L_0x0049a41b:
    // 0049a41b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a41c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a41d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a41e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a41e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a41f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a420  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a421  8b3d60cb4c00           -mov edi, dword ptr [0x4ccb60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */);
    // 0049a427  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049a429:
    // 0049a429  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049a42b  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a42e  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049a431  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049a434  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0049a437  8972fc                 -mov dword ptr [edx - 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0049a43a  7fed                   -jg 0x49a429
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a429;
    }
    // 0049a43c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a43d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a43e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a43f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a441  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a442  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a443  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a444  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a446  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049a448  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049a44a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a44c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a44e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a450  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a452  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a455  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 0049a45b  754e                   -jne 0x49a4ab
    if (!cpu.flags.zf)
    {
        goto L_0x0049a4ab;
    }
    // 0049a45d  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a460  7849                   -js 0x49a4ab
    if (cpu.flags.sf)
    {
        goto L_0x0049a4ab;
    }
    // 0049a462  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049a465  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049a467  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0049a46a  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
L_0x0049a46d:
    // 0049a46d  8b04456ea35200         -mov eax, dword ptr [eax*2 + 0x52a36e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5415790) /* 0x52a36e */ + cpu.eax * 2);
    // 0049a474  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049a477  8b0c4d6ea35200         -mov ecx, dword ptr [ecx*2 + 0x52a36e]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5415790) /* 0x52a36e */ + cpu.ecx * 2);
    // 0049a47e  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049a481  668b045d70a35200       -mov ax, word ptr [ebx*2 + 0x52a370]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.ebx * 2);
    // 0049a489  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049a48b  668b0c5570a35200       -mov cx, word ptr [edx*2 + 0x52a370]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.edx * 2);
    // 0049a493  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0049a496  8947f8                 -mov dword ptr [edi - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0049a499  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0049a49c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a49e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049a4a0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049a4a3  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a4a6  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0049a4a9  79c2                   -jns 0x49a46d
    if (!cpu.flags.sf)
    {
        goto L_0x0049a46d;
    }
L_0x0049a4ab:
    // 0049a4ab  83c503                 +add ebp, 3
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a4ae  7818                   -js 0x49a4c8
    if (cpu.flags.sf)
    {
        goto L_0x0049a4c8;
    }
L_0x0049a4b0:
    // 0049a4b0  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049a4b2  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049a4b5  668b045570a35200       -mov ax, word ptr [edx*2 + 0x52a370]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.edx * 2);
    // 0049a4bd  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0049a4c0  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0049a4c3  83ed01                 +sub ebp, 1
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
    // 0049a4c6  79e8                   -jns 0x49a4b0
    if (!cpu.flags.sf)
    {
        goto L_0x0049a4b0;
    }
L_0x0049a4c8:
    // 0049a4c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a4c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a4ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a4cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a4cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a4cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a4cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a4ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a4cf  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049a4d2  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a4d5  783f                   -js 0x49a516
    if (cpu.flags.sf)
    {
        goto L_0x0049a516;
    }
L_0x0049a4d7:
    // 0049a4d7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049a4d9  8b4e03                 -mov ecx, dword ptr [esi + 3]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0049a4dc  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049a4de  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049a4e0  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049a4e5  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049a4eb  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049a4ed  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049a4f0  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0049a4f3  8b4e09                 -mov ecx, dword ptr [esi + 9]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0049a4f6  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049a4f8  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049a4fa  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049a4ff  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049a505  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049a508  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049a50b  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a50e  8d760c                 -lea esi, [esi + 0xc]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049a511  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049a514  79c1                   -jns 0x49a4d7
    if (!cpu.flags.sf)
    {
        goto L_0x0049a4d7;
    }
L_0x0049a516:
    // 0049a516  83c303                 +add ebx, 3
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a519  7816                   -js 0x49a531
    if (cpu.flags.sf)
    {
        goto L_0x0049a531;
    }
L_0x0049a51b:
    // 0049a51b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049a51d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049a51f  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049a524  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049a526  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a529  8d7603                 -lea esi, [esi + 3]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0049a52c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049a52f  79ea                   -jns 0x49a51b
    if (!cpu.flags.sf)
    {
        goto L_0x0049a51b;
    }
L_0x0049a531:
    // 0049a531  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a532  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a533  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a534(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a534  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a535  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a536  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a537  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a53a  782f                   -js 0x49a56b
    if (cpu.flags.sf)
    {
        goto L_0x0049a56b;
    }
L_0x0049a53c:
    // 0049a53c  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a53e  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049a540  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 0049a546  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 0049a549  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049a54b  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 0049a551  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a553  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 0049a559  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 0049a55c  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a55e  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0049a560  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a563  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049a566  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049a569  79d1                   -jns 0x49a53c
    if (!cpu.flags.sf)
    {
        goto L_0x0049a53c;
    }
L_0x0049a56b:
    // 0049a56b  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a56e  7831                   -js 0x49a5a1
    if (cpu.flags.sf)
    {
        goto L_0x0049a5a1;
    }
L_0x0049a570:
    // 0049a570  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049a573  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049a575  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 0049a57b  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 0049a57e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049a580  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 0049a586  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a588  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 0049a58e  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 0049a591  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a593  66893a                 -mov word ptr [edx], di
    app->getMemory<x86::reg16>(cpu.edx) = cpu.di;
    // 0049a596  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a599  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a59c  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049a59f  79cf                   -jns 0x49a570
    if (!cpu.flags.sf)
    {
        goto L_0x0049a570;
    }
L_0x0049a5a1:
    // 0049a5a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a5a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a5a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a5a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a5a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a5a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a5a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a5a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a5a8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a5a9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a5ab  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049a5ad  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049a5af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a5b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a5b3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a5b5  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a5b8  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 0049a5be  754e                   -jne 0x49a60e
    if (!cpu.flags.zf)
    {
        goto L_0x0049a60e;
    }
    // 0049a5c0  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a5c3  7849                   -js 0x49a60e
    if (cpu.flags.sf)
    {
        goto L_0x0049a60e;
    }
    // 0049a5c5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049a5c7  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
L_0x0049a5ca:
    // 0049a5ca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a5cc  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0049a5cf  8b144d6ea35200         -mov edx, dword ptr [ecx*2 + 0x52a36e]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5415790) /* 0x52a36e */ + cpu.ecx * 2);
    // 0049a5d6  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0049a5d9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049a5db  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0049a5de  8b0c4d6ea35200         -mov ecx, dword ptr [ecx*2 + 0x52a36e]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5415790) /* 0x52a36e */ + cpu.ecx * 2);
    // 0049a5e5  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049a5e8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0049a5eb  668b144570a35200       -mov dx, word ptr [eax*2 + 0x52a370]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.eax * 2);
    // 0049a5f3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049a5f5  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0049a5f8  668b0c5d70a35200       -mov cx, word ptr [ebx*2 + 0x52a370]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.ebx * 2);
    // 0049a600  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049a603  8957f8                 -mov dword ptr [edi - 8], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0049a606  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0049a609  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a60c  79bc                   -jns 0x49a5ca
    if (!cpu.flags.sf)
    {
        goto L_0x0049a5ca;
    }
L_0x0049a60e:
    // 0049a60e  83c502                 +add ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a611  7827                   -js 0x49a63a
    if (cpu.flags.sf)
    {
        goto L_0x0049a63a;
    }
L_0x0049a613:
    // 0049a613  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a615  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0049a618  8b144d6ea35200         -mov edx, dword ptr [ecx*2 + 0x52a36e]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5415790) /* 0x52a36e */ + cpu.ecx * 2);
    // 0049a61f  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049a622  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049a625  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0049a628  668b144570a35200       -mov dx, word ptr [eax*2 + 0x52a370]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.eax * 2);
    // 0049a630  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049a632  8957fc                 -mov dword ptr [edi - 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0049a635  83ed02                 +sub ebp, 2
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
    // 0049a638  79d9                   -jns 0x49a613
    if (!cpu.flags.sf)
    {
        goto L_0x0049a613;
    }
L_0x0049a63a:
    // 0049a63a  83c501                 +add ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a63d  780e                   -js 0x49a64d
    if (cpu.flags.sf)
    {
        goto L_0x0049a64d;
    }
    // 0049a63f  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0049a642  668b144570a35200       -mov dx, word ptr [eax*2 + 0x52a370]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.eax * 2);
    // 0049a64a  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
L_0x0049a64d:
    // 0049a64d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a64e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a64f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a650  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a651  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a652(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a652  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a653  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a654  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a655  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a658  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049a65a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a65c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a65d  2eff15f0744b00         -call dword ptr cs:[0x4b74f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945136) /* 0x4b74f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a664  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a666  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 0049a66a  2d6c070000             -sub eax, 0x76c
    (cpu.eax) -= x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 0049a66f  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049a672  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a674  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 0049a679  48                     -dec eax
    (cpu.eax)--;
    // 0049a67a  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049a67d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a67f  668b442406             -mov ax, word ptr [esp + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 0049a684  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049a687  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a689  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a68e  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049a691  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a693  668b44240a             -mov ax, word ptr [esp + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(10) /* 0xa */);
    // 0049a698  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049a69b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a69d  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a6a2  c74320ffffffff         -mov dword ptr [ebx + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 0049a6a9  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049a6ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a6ad  668b44240e             -mov ax, word ptr [esp + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 0049a6b2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a6b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a6b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a6b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a6b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
