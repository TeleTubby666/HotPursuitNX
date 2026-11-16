#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4a7028(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7028  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7029  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a702a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a702b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a702c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a702d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7030  8b1dd4de4d00           -mov ebx, dword ptr [0x4dded4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a7036  8b35dcde4d00           -mov esi, dword ptr [0x4ddedc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5103324) /* 0x4ddedc */);
    // 004a703c  8b3dd8de4d00           -mov edi, dword ptr [0x4dded8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103320) /* 0x4dded8 */);
    // 004a7042  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a7044  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a7046  e895070100             -call 0x4b77e0
    cpu.esp -= 4;
    sub_4b77e0(app, cpu);
    if (cpu.terminate) return;
    // 004a704b  e840080100             -call 0x4b7890
    cpu.esp -= 4;
    sub_4b7890(app, cpu);
    if (cpu.terminate) return;
    // 004a7050  e87b090100             -call 0x4b79d0
    cpu.esp -= 4;
    sub_4b79d0(app, cpu);
    if (cpu.terminate) return;
    // 004a7055  e8260a0100             -call 0x4b7a80
    cpu.esp -= 4;
    sub_4b7a80(app, cpu);
    if (cpu.terminate) return;
    // 004a705a  8b3dd8de4d00           -mov edi, dword ptr [0x4dded8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103320) /* 0x4dded8 */);
    // 004a7060  8b35dcde4d00           -mov esi, dword ptr [0x4ddedc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5103324) /* 0x4ddedc */);
L_0x004a7066:
    // 004a7066  8b1dd4de4d00           -mov ebx, dword ptr [0x4dded4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a706c  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 004a7073  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a7075  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a7077  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a707a  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a707d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a707f  7518                   -jne 0x4a7099
    if (!cpu.flags.zf)
    {
        goto L_0x004a7099;
    }
L_0x004a7081:
    // 004a7081  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 004a7088  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a708a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a708c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a708f  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a7092  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a7094  740c                   -je 0x4a70a2
    if (cpu.flags.zf)
    {
        goto L_0x004a70a2;
    }
    // 004a7096  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a7097  ebe8                   -jmp 0x4a7081
    goto L_0x004a7081;
L_0x004a7099:
    // 004a7099  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a709a  891dd4de4d00           -mov dword ptr [0x4dded4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */) = cpu.ebx;
    // 004a70a0  ebc4                   -jmp 0x4a7066
    goto L_0x004a7066;
L_0x004a70a2:
    // 004a70a2  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 004a70a9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a70ab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a70ad  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a70b0  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a70b3  891dd4de4d00           -mov dword ptr [0x4dded4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */) = cpu.ebx;
    // 004a70b9  8935dcde4d00           -mov dword ptr [0x4ddedc], esi
    app->getMemory<x86::reg32>(x86::reg32(5103324) /* 0x4ddedc */) = cpu.esi;
    // 004a70bf  893dd8de4d00           -mov dword ptr [0x4dded8], edi
    app->getMemory<x86::reg32>(x86::reg32(5103320) /* 0x4dded8 */) = cpu.edi;
    // 004a70c5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a70c7  7403                   -je 0x4a70cc
    if (cpu.flags.zf)
    {
        goto L_0x004a70cc;
    }
    // 004a70c9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a70ca  ebd6                   -jmp 0x4a70a2
    goto L_0x004a70a2;
L_0x004a70cc:
    // 004a70cc  e883feffff             -call 0x4a6f54
    cpu.esp -= 4;
    sub_4a6f54(app, cpu);
    if (cpu.terminate) return;
    // 004a70d1  892de0f55a00           -mov dword ptr [0x5af5e0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5961184) /* 0x5af5e0 */) = cpu.ebp;
    // 004a70d7  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004a70da  0f84a5000000           -je 0x4a7185
    if (cpu.flags.zf)
    {
        goto L_0x004a7185;
    }
    // 004a70e0  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 004a70e5  8b3dd8de4d00           -mov edi, dword ptr [0x4dded8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103320) /* 0x4dded8 */);
    // 004a70eb  8b35dcde4d00           -mov esi, dword ptr [0x4ddedc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5103324) /* 0x4ddedc */);
    // 004a70f1  a1c8de4d00             -mov eax, dword ptr [0x4ddec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103304) /* 0x4ddec8 */);
    // 004a70f6  8b1dd4de4d00           -mov ebx, dword ptr [0x4dded4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
L_0x004a70fc:
    // 004a70fc  a3e4f55a00             -mov dword ptr [0x5af5e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5961188) /* 0x5af5e4 */) = cpu.eax;
    // 004a7101  8915e8f55a00           -mov dword ptr [0x5af5e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5961192) /* 0x5af5e8 */) = cpu.edx;
L_0x004a7107:
    // 004a7107  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 004a710a  0f84ec000000           -je 0x4a71fc
    if (cpu.flags.zf)
    {
        goto L_0x004a71fc;
    }
    // 004a7110  c705ecf55a0044ac0000   -mov dword ptr [0x5af5ec], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5961196) /* 0x5af5ec */) = 44100 /*0xac44*/;
L_0x004a711a:
    // 004a711a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a711c  8935dcde4d00           -mov dword ptr [0x4ddedc], esi
    app->getMemory<x86::reg32>(x86::reg32(5103324) /* 0x4ddedc */) = cpu.esi;
    // 004a7122  893dd8de4d00           -mov dword ptr [0x4dded8], edi
    app->getMemory<x86::reg32>(x86::reg32(5103320) /* 0x4dded8 */) = cpu.edi;
L_0x004a7128:
    // 004a7128  05e40d0000             -add eax, 0xde4
    (cpu.eax) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 004a712d  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004a712f  8890b8095a00           -mov byte ptr [eax + 0x5a09b8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5900728) /* 0x5a09b8 */) = cpu.dl;
    // 004a7135  3d40de0000             +cmp eax, 0xde40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56896 /*0xde40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a713a  75ec                   -jne 0x4a7128
    if (!cpu.flags.zf)
    {
        goto L_0x004a7128;
    }
    // 004a713c  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004a7141  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7142  891dd4de4d00           -mov dword ptr [0x4dded4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */) = cpu.ebx;
    // 004a7148  ff15ccde4d00           -call dword ptr [0x4ddecc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103308) /* 0x4ddecc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a714e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7151  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004a7156  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004a715b  68e8e24d00             -push 0x4de2e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5104360 /*0x4de2e8*/;
    cpu.esp -= 4;
    // 004a7160  a3dcf55a00             -mov dword ptr [0x5af5dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5961180) /* 0x5af5dc */) = cpu.eax;
    // 004a7165  ff15ccde4d00           -call dword ptr [0x4ddecc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103308) /* 0x4ddecc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a716b  8b1dd4de4d00           -mov ebx, dword ptr [0x4dded4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a7171  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7174  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7176  891dd4de4d00           -mov dword ptr [0x4dded4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */) = cpu.ebx;
    // 004a717c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a717f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7180  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7181  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7182  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7183  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7184  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7185:
    // 004a7185  8b3dd8de4d00           -mov edi, dword ptr [0x4dded8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103320) /* 0x4dded8 */);
    // 004a718b  8b35dcde4d00           -mov esi, dword ptr [0x4ddedc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5103324) /* 0x4ddedc */);
    // 004a7191  8b1dd4de4d00           -mov ebx, dword ptr [0x4dded4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a7197  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004a719a  7419                   -je 0x4a71b5
    if (cpu.flags.zf)
    {
        goto L_0x004a71b5;
    }
    // 004a719c  a1c0de4d00             -mov eax, dword ptr [0x4ddec0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103296) /* 0x4ddec0 */);
    // 004a71a1  a3e4f55a00             -mov dword ptr [0x5af5e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5961188) /* 0x5af5e4 */) = cpu.eax;
    // 004a71a6  c705e8f55a0000020000   -mov dword ptr [0x5af5e8], 0x200
    app->getMemory<x86::reg32>(x86::reg32(5961192) /* 0x5af5e8 */) = 512 /*0x200*/;
    // 004a71b0  e952ffffff             -jmp 0x4a7107
    goto L_0x004a7107;
L_0x004a71b5:
    // 004a71b5  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004a71b8  741a                   -je 0x4a71d4
    if (cpu.flags.zf)
    {
        goto L_0x004a71d4;
    }
    // 004a71ba  a1c4de4d00             -mov eax, dword ptr [0x4ddec4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103300) /* 0x4ddec4 */);
    // 004a71bf  bd00020000             -mov ebp, 0x200
    cpu.ebp = 512 /*0x200*/;
    // 004a71c4  a3e4f55a00             -mov dword ptr [0x5af5e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5961188) /* 0x5af5e4 */) = cpu.eax;
    // 004a71c9  892de8f55a00           -mov dword ptr [0x5af5e8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5961192) /* 0x5af5e8 */) = cpu.ebp;
    // 004a71cf  e933ffffff             -jmp 0x4a7107
    goto L_0x004a7107;
L_0x004a71d4:
    // 004a71d4  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 004a71d7  740f                   -je 0x4a71e8
    if (cpu.flags.zf)
    {
        goto L_0x004a71e8;
    }
    // 004a71d9  a1bcde4d00             -mov eax, dword ptr [0x4ddebc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103292) /* 0x4ddebc */);
    // 004a71de  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004a71e3  e914ffffff             -jmp 0x4a70fc
    goto L_0x004a70fc;
L_0x004a71e8:
    // 004a71e8  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a71ed  891dd4de4d00           -mov dword ptr [0x4dded4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */) = cpu.ebx;
    // 004a71f3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a71f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a71fc:
    // 004a71fc  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004a71ff  740f                   -je 0x4a7210
    if (cpu.flags.zf)
    {
        goto L_0x004a7210;
    }
    // 004a7201  c705ecf55a00007d0000   -mov dword ptr [0x5af5ec], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5961196) /* 0x5af5ec */) = 32000 /*0x7d00*/;
    // 004a720b  e90affffff             -jmp 0x4a711a
    goto L_0x004a711a;
L_0x004a7210:
    // 004a7210  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004a7213  740f                   -je 0x4a7224
    if (cpu.flags.zf)
    {
        goto L_0x004a7224;
    }
    // 004a7215  c705ecf55a0022560000   -mov dword ptr [0x5af5ec], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5961196) /* 0x5af5ec */) = 22050 /*0x5622*/;
    // 004a721f  e9f6feffff             -jmp 0x4a711a
    goto L_0x004a711a;
L_0x004a7224:
    // 004a7224  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 004a7227  740f                   -je 0x4a7238
    if (cpu.flags.zf)
    {
        goto L_0x004a7238;
    }
    // 004a7229  c705ecf55a00803e0000   -mov dword ptr [0x5af5ec], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5961196) /* 0x5af5ec */) = 16000 /*0x3e80*/;
    // 004a7233  e9e2feffff             -jmp 0x4a711a
    goto L_0x004a711a;
L_0x004a7238:
    // 004a7238  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 004a723b  740f                   -je 0x4a724c
    if (cpu.flags.zf)
    {
        goto L_0x004a724c;
    }
    // 004a723d  c705ecf55a00112b0000   -mov dword ptr [0x5af5ec], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5961196) /* 0x5af5ec */) = 11025 /*0x2b11*/;
    // 004a7247  e9cefeffff             -jmp 0x4a711a
    goto L_0x004a711a;
L_0x004a724c:
    // 004a724c  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 004a724f  740f                   -je 0x4a7260
    if (cpu.flags.zf)
    {
        goto L_0x004a7260;
    }
    // 004a7251  c705ecf55a00401f0000   -mov dword ptr [0x5af5ec], 0x1f40
    app->getMemory<x86::reg32>(x86::reg32(5961196) /* 0x5af5ec */) = 8000 /*0x1f40*/;
    // 004a725b  e9bafeffff             -jmp 0x4a711a
    goto L_0x004a711a;
L_0x004a7260:
    // 004a7260  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a7265  8935dcde4d00           -mov dword ptr [0x4ddedc], esi
    app->getMemory<x86::reg32>(x86::reg32(5103324) /* 0x4ddedc */) = cpu.esi;
    // 004a726b  893dd8de4d00           -mov dword ptr [0x4dded8], edi
    app->getMemory<x86::reg32>(x86::reg32(5103320) /* 0x4dded8 */) = cpu.edi;
    // 004a7271  891dd4de4d00           -mov dword ptr [0x4dded4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */) = cpu.ebx;
    // 004a7277  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a727a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a727b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a727c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a727d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a727e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a727f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7282  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7283  8b15ecf55a00           -mov edx, dword ptr [0x5af5ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5961196) /* 0x5af5ec */);
    // 004a7289  8b0de4f55a00           -mov ecx, dword ptr [0x5af5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5961188) /* 0x5af5e4 */);
    // 004a728f  8b1de8f55a00           -mov ebx, dword ptr [0x5af5e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5961192) /* 0x5af5e8 */);
    // 004a7295  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a7297  7435                   -je 0x4a72ce
    if (cpu.flags.zf)
    {
        goto L_0x004a72ce;
    }
    // 004a7299  bb00040000             -mov ebx, 0x400
    cpu.ebx = 1024 /*0x400*/;
    // 004a729e  8b0dc8de4d00           -mov ecx, dword ptr [0x4ddec8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103304) /* 0x4ddec8 */);
L_0x004a72a4:
    // 004a72a4  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 004a72a7  745f                   -je 0x4a7308
    if (cpu.flags.zf)
    {
        goto L_0x004a7308;
    }
    // 004a72a9  ba44ac0000             -mov edx, 0xac44
    cpu.edx = 44100 /*0xac44*/;
L_0x004a72ae:
    // 004a72ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a72b0:
    // 004a72b0  40                     -inc eax
    (cpu.eax)++;
    // 004a72b1  83f810                 +cmp eax, 0x10
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
    // 004a72b4  7cfa                   -jl 0x4a72b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a72b0;
    }
    // 004a72b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a72b8:
    // 004a72b8  891de8f55a00           -mov dword ptr [0x5af5e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5961192) /* 0x5af5e8 */) = cpu.ebx;
    // 004a72be  890de4f55a00           -mov dword ptr [0x5af5e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5961188) /* 0x5af5e4 */) = cpu.ecx;
    // 004a72c4  8915ecf55a00           -mov dword ptr [0x5af5ec], edx
    app->getMemory<x86::reg32>(x86::reg32(5961196) /* 0x5af5ec */) = cpu.edx;
    // 004a72ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a72ce:
    // 004a72ce  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a72d0  740d                   -je 0x4a72df
    if (cpu.flags.zf)
    {
        goto L_0x004a72df;
    }
    // 004a72d2  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 004a72d7  8b0dc0de4d00           -mov ecx, dword ptr [0x4ddec0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103296) /* 0x4ddec0 */);
    // 004a72dd  ebc5                   -jmp 0x4a72a4
    goto L_0x004a72a4;
L_0x004a72df:
    // 004a72df  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a72e1  740d                   -je 0x4a72f0
    if (cpu.flags.zf)
    {
        goto L_0x004a72f0;
    }
    // 004a72e3  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 004a72e8  8b0dc4de4d00           -mov ecx, dword ptr [0x4ddec4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103300) /* 0x4ddec4 */);
    // 004a72ee  ebb4                   -jmp 0x4a72a4
    goto L_0x004a72a4;
L_0x004a72f0:
    // 004a72f0  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a72f2  740d                   -je 0x4a7301
    if (cpu.flags.zf)
    {
        goto L_0x004a7301;
    }
    // 004a72f4  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 004a72f9  8b0dbcde4d00           -mov ecx, dword ptr [0x4ddebc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103292) /* 0x4ddebc */);
    // 004a72ff  eba3                   -jmp 0x4a72a4
    goto L_0x004a72a4;
L_0x004a7301:
    // 004a7301  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a7306  ebb0                   -jmp 0x4a72b8
    goto L_0x004a72b8;
L_0x004a7308:
    // 004a7308  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004a730b  7407                   -je 0x4a7314
    if (cpu.flags.zf)
    {
        goto L_0x004a7314;
    }
    // 004a730d  ba007d0000             -mov edx, 0x7d00
    cpu.edx = 32000 /*0x7d00*/;
    // 004a7312  eb9a                   -jmp 0x4a72ae
    goto L_0x004a72ae;
L_0x004a7314:
    // 004a7314  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 004a7317  7407                   -je 0x4a7320
    if (cpu.flags.zf)
    {
        goto L_0x004a7320;
    }
    // 004a7319  ba22560000             -mov edx, 0x5622
    cpu.edx = 22050 /*0x5622*/;
    // 004a731e  eb8e                   -jmp 0x4a72ae
    goto L_0x004a72ae;
L_0x004a7320:
    // 004a7320  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004a7323  7407                   -je 0x4a732c
    if (cpu.flags.zf)
    {
        goto L_0x004a732c;
    }
    // 004a7325  ba803e0000             -mov edx, 0x3e80
    cpu.edx = 16000 /*0x3e80*/;
    // 004a732a  eb82                   -jmp 0x4a72ae
    goto L_0x004a72ae;
L_0x004a732c:
    // 004a732c  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004a732f  740a                   -je 0x4a733b
    if (cpu.flags.zf)
    {
        goto L_0x004a733b;
    }
    // 004a7331  ba112b0000             -mov edx, 0x2b11
    cpu.edx = 11025 /*0x2b11*/;
    // 004a7336  e973ffffff             -jmp 0x4a72ae
    goto L_0x004a72ae;
L_0x004a733b:
    // 004a733b  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004a733e  74c1                   -je 0x4a7301
    if (cpu.flags.zf)
    {
        goto L_0x004a7301;
    }
    // 004a7340  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004a7345  e964ffffff             -jmp 0x4a72ae
    goto L_0x004a72ae;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a734c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a734c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a734d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a734e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a734f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7352  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a7356  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7359  8d34c500000000         -lea esi, [eax*8]
    cpu.esi = x86::reg32(cpu.eax * 8);
    // 004a7360  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7362  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7364  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 004a7367  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7369  81c69c175a00           -add esi, 0x5a179c
    (cpu.esi) += x86::reg32(x86::sreg32(5904284 /*0x5a179c*/));
    // 004a736f  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 004a7372  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a7375  c64609ff               -mov byte ptr [esi + 9], 0xff
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = 255 /*0xff*/;
    // 004a7379  8986600d0000           -mov dword ptr [esi + 0xd60], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */) = cpu.eax;
    // 004a737f  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004a7382  7559                   -jne 0x4a73dd
    if (!cpu.flags.zf)
    {
        goto L_0x004a73dd;
    }
    // 004a7384  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004a7387  0f847a000000           -je 0x4a7407
    if (cpu.flags.zf)
    {
        goto L_0x004a7407;
    }
    // 004a738d  a198de4d00             -mov eax, dword ptr [0x4dde98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103256) /* 0x4dde98 */);
    // 004a7392  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a7395  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a739a  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a739d  7f60                   -jg 0x4a73ff
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a73ff;
    }
    // 004a739f  8b3da8de4d00           -mov edi, dword ptr [0x4ddea8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103272) /* 0x4ddea8 */);
L_0x004a73a5:
    // 004a73a5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a73a7  0f85bc000000           -jne 0x4a7469
    if (!cpu.flags.zf)
    {
        goto L_0x004a7469;
    }
L_0x004a73ad:
    // 004a73ad  83f901                 +cmp ecx, 1
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
    // 004a73b0  0f8520010000           -jne 0x4a74d6
    if (!cpu.flags.zf)
    {
        goto L_0x004a74d6;
    }
    // 004a73b6  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a73bb  7e02                   -jle 0x4a73bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a73bf;
    }
L_0x004a73bd:
    // 004a73bd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a73bf:
    // 004a73bf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a73c2  83b814de4d0000         +cmp dword ptr [eax + 0x4dde14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5103124) /* 0x4dde14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a73c9  0f851e010000           -jne 0x4a74ed
    if (!cpu.flags.zf)
    {
        goto L_0x004a74ed;
    }
L_0x004a73cf:
    // 004a73cf  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004a73d4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a73d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73da  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x004a73dd:
    // 004a73dd  a194de4d00             -mov eax, dword ptr [0x4dde94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103252) /* 0x4dde94 */);
    // 004a73e2  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a73e5  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004a73ea  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a73ed  7f08                   -jg 0x4a73f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a73f7;
    }
    // 004a73ef  8b3da4de4d00           -mov edi, dword ptr [0x4ddea4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103268) /* 0x4ddea4 */);
    // 004a73f5  ebae                   -jmp 0x4a73a5
    goto L_0x004a73a5;
L_0x004a73f7:
    // 004a73f7  8b3db4de4d00           -mov edi, dword ptr [0x4ddeb4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103284) /* 0x4ddeb4 */);
    // 004a73fd  eba6                   -jmp 0x4a73a5
    goto L_0x004a73a5;
L_0x004a73ff:
    // 004a73ff  8b3db8de4d00           -mov edi, dword ptr [0x4ddeb8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103288) /* 0x4ddeb8 */);
    // 004a7405  eb9e                   -jmp 0x4a73a5
    goto L_0x004a73a5;
L_0x004a7407:
    // 004a7407  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004a740a  7422                   -je 0x4a742e
    if (cpu.flags.zf)
    {
        goto L_0x004a742e;
    }
    // 004a740c  a18cde4d00             -mov eax, dword ptr [0x4dde8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103244) /* 0x4dde8c */);
    // 004a7411  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a7414  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7416  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7419  7f08                   -jg 0x4a7423
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7423;
    }
    // 004a741b  8b3d9cde4d00           -mov edi, dword ptr [0x4dde9c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103260) /* 0x4dde9c */);
    // 004a7421  eb82                   -jmp 0x4a73a5
    goto L_0x004a73a5;
L_0x004a7423:
    // 004a7423  8b3dacde4d00           -mov edi, dword ptr [0x4ddeac]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103276) /* 0x4ddeac */);
    // 004a7429  e977ffffff             -jmp 0x4a73a5
    goto L_0x004a73a5;
L_0x004a742e:
    // 004a742e  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004a7431  7428                   -je 0x4a745b
    if (cpu.flags.zf)
    {
        goto L_0x004a745b;
    }
    // 004a7433  a190de4d00             -mov eax, dword ptr [0x4dde90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103248) /* 0x4dde90 */);
    // 004a7438  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a743b  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004a7440  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7443  7f0b                   -jg 0x4a7450
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7450;
    }
    // 004a7445  8b3da0de4d00           -mov edi, dword ptr [0x4ddea0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103264) /* 0x4ddea0 */);
    // 004a744b  e955ffffff             -jmp 0x4a73a5
    goto L_0x004a73a5;
L_0x004a7450:
    // 004a7450  8b3db0de4d00           -mov edi, dword ptr [0x4ddeb0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103280) /* 0x4ddeb0 */);
    // 004a7456  e94affffff             -jmp 0x4a73a5
    goto L_0x004a73a5;
L_0x004a745b:
    // 004a745b  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 004a7460  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7463  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7464  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7465  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7466  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x004a7469:
    // 004a7469  83fb07                 +cmp ebx, 7
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a746c  752c                   -jne 0x4a749a
    if (!cpu.flags.zf)
    {
        goto L_0x004a749a;
    }
    // 004a746e  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004a7471  740a                   -je 0x4a747d
    if (cpu.flags.zf)
    {
        goto L_0x004a747d;
    }
    // 004a7473  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 004a7478  e930ffffff             -jmp 0x4a73ad
    goto L_0x004a73ad;
L_0x004a747d:
    // 004a747d  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004a7480  740a                   -je 0x4a748c
    if (cpu.flags.zf)
    {
        goto L_0x004a748c;
    }
    // 004a7482  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004a7487  e921ffffff             -jmp 0x4a73ad
    goto L_0x004a73ad;
L_0x004a748c:
    // 004a748c  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004a7491  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7494  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7495  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7496  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7497  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x004a749a:
    // 004a749a  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a749d  750f                   -jne 0x4a74ae
    if (!cpu.flags.zf)
    {
        goto L_0x004a74ae;
    }
L_0x004a749f:
    // 004a749f  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004a74a2  74e8                   -je 0x4a748c
    if (cpu.flags.zf)
    {
        goto L_0x004a748c;
    }
    // 004a74a4  b81b000000             -mov eax, 0x1b
    cpu.eax = 27 /*0x1b*/;
    // 004a74a9  e9fffeffff             -jmp 0x4a73ad
    goto L_0x004a73ad;
L_0x004a74ae:
    // 004a74ae  83fb08                 +cmp ebx, 8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a74b1  74ec                   -je 0x4a749f
    if (cpu.flags.zf)
    {
        goto L_0x004a749f;
    }
    // 004a74b3  83fb02                 +cmp ebx, 2
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
    // 004a74b6  75a3                   -jne 0x4a745b
    if (!cpu.flags.zf)
    {
        goto L_0x004a745b;
    }
    // 004a74b8  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004a74bb  740a                   -je 0x4a74c7
    if (cpu.flags.zf)
    {
        goto L_0x004a74c7;
    }
    // 004a74bd  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 004a74c2  e9e6feffff             -jmp 0x4a73ad
    goto L_0x004a73ad;
L_0x004a74c7:
    // 004a74c7  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004a74ca  74c0                   -je 0x4a748c
    if (cpu.flags.zf)
    {
        goto L_0x004a748c;
    }
    // 004a74cc  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 004a74d1  e9d7feffff             -jmp 0x4a73ad
    goto L_0x004a73ad;
L_0x004a74d6:
    // 004a74d6  83f902                 +cmp ecx, 2
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
    // 004a74d9  0f84defeffff           -je 0x4a73bd
    if (cpu.flags.zf)
    {
        goto L_0x004a73bd;
    }
    // 004a74df  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004a74e4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a74e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74ea  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x004a74ed:
    // 004a74ed  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a74ef  8d86ac0d0000           -lea eax, [esi + 0xdac]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3500) /* 0xdac */);
    // 004a74f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a74f6  8d86a80d0000           -lea eax, [esi + 0xda8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    // 004a74fc  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a7500  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7501  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a7505  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a7509  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a750a  8b86600d0000           -mov eax, dword ptr [esi + 0xd60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 004a7510  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a7514  ff9514de4d00           -call dword ptr [ebp + 0x4dde14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5103124) /* 0x4dde14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a751a  833c2400               +cmp dword ptr [esp], 0
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
    // 004a751e  0f84abfeffff           -je 0x4a73cf
    if (cpu.flags.zf)
    {
        goto L_0x004a73cf;
    }
    // 004a7524  8d86bc0d0000           -lea eax, [esi + 0xdbc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    // 004a752a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a752b  8d86c00d0000           -lea eax, [esi + 0xdc0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    // 004a7531  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7532  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 004a7538  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7539  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a753d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7540  8d86dc0d0000           -lea eax, [esi + 0xddc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3548) /* 0xddc */);
    // 004a7546  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7547  8d86e00d0000           -lea eax, [esi + 0xde0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3552) /* 0xde0 */);
    // 004a754d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a754e  8d86c40d0000           -lea eax, [esi + 0xdc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3524) /* 0xdc4 */);
    // 004a7554  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7555  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7559  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a755c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a755e  0f846bfeffff           -je 0x4a73cf
    if (cpu.flags.zf)
    {
        goto L_0x004a73cf;
    }
    // 004a7564  8d86b80d0000           -lea eax, [esi + 0xdb8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    // 004a756a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a756b  8d86b40d0000           -lea eax, [esi + 0xdb4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    // 004a7571  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7572  8d86b00d0000           -lea eax, [esi + 0xdb0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    // 004a7578  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7579  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 004a757f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7580  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7582  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a7585  817c242c00000800       +cmp dword ptr [esp + 0x2c], 0x80000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a758d  7608                   -jbe 0x4a7597
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a7597;
    }
    // 004a758f  c744242c00000800       -mov dword ptr [esp + 0x2c], 0x80000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 524288 /*0x80000*/;
L_0x004a7597:
    // 004a7597  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a759b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a759c  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 004a75a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a75a3  ff96b00d0000           -call dword ptr [esi + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a75a9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a75ac  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a75b0  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a75b3  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a75b7  884602                 -mov byte ptr [esi + 2], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a75ba  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a75be  884604                 -mov byte ptr [esi + 4], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 004a75c1  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a75c5  884605                 -mov byte ptr [esi + 5], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 004a75c8  8a442434               -mov al, byte ptr [esp + 0x34]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a75cc  884603                 -mov byte ptr [esi + 3], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004a75cf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a75d1  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a75d5  e826020000             -call 0x4a7800
    cpu.esp -= 4;
    sub_4a7800(app, cpu);
    if (cpu.terminate) return;
    // 004a75da  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a75db  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a75df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a75e0  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 004a75e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a75e7  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a75ed  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a75f0  c60601                 -mov byte ptr [esi], 1
    app->getMemory<x86::reg8>(cpu.esi) = 1 /*0x1*/;
    // 004a75f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a75f5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a75f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a75f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a75fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a75fb  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a7600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7600  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7601  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7602  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7603  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7604  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7605  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a7608  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a760a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a760c  05c40d0000             -add eax, 0xdc4
    (cpu.eax) += x86::reg32(x86::sreg32(3524 /*0xdc4*/));
    // 004a7611  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a7614  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7616  05900d0000             -add eax, 0xd90
    (cpu.eax) += x86::reg32(x86::sreg32(3472 /*0xd90*/));
    // 004a761b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a761f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7621  05640d0000             -add eax, 0xd64
    (cpu.eax) += x86::reg32(x86::sreg32(3428 /*0xd64*/));
    // 004a7626  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a7628  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004a762c:
    // 004a762c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a762f  3a4604                 +cmp al, byte ptr [esi + 4]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a7632  0f84cd000000           -je 0x4a7705
    if (cpu.flags.zf)
    {
        goto L_0x004a7705;
    }
L_0x004a7638:
    // 004a7638  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a763a  0f84d1000000           -je 0x4a7711
    if (cpu.flags.zf)
    {
        goto L_0x004a7711;
    }
    // 004a7640  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a7643  8a7604                 -mov dh, byte ptr [esi + 4]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a7646  4d                     -dec ebp
    (cpu.ebp)--;
    // 004a7647  38f0                   +cmp al, dh
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a7649  0f85cd000000           -jne 0x4a771c
    if (!cpu.flags.zf)
    {
        goto L_0x004a771c;
    }
L_0x004a764f:
    // 004a764f  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a7652  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a7655  7406                   -je 0x4a765d
    if (cpu.flags.zf)
    {
        goto L_0x004a765d;
    }
    // 004a7657  8a4607                 -mov al, byte ptr [esi + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 004a765a  004602                 -add byte ptr [esi + 2], al
    (app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)) += x86::reg8(x86::sreg8(cpu.al));
L_0x004a765d:
    // 004a765d  0fbe4602               -movsx eax, byte ptr [esi + 2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)));
    // 004a7661  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7662  0fbe4601               -movsx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */)));
    // 004a7666  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7667  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a766b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a766c  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7672  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7675  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a7677  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a767b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a767c  ff96b40d0000           -call dword ptr [esi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7682  8b0dd8de4d00           -mov ecx, dword ptr [0x4dded8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103320) /* 0x4dded8 */);
    // 004a7688  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a768b  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a768e  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a7692  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a7696  8b8e600d0000           -mov ecx, dword ptr [esi + 0xd60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 004a769c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a769e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a76a0  ff96a80d0000           -call dword ptr [esi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a76a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a76a8  7c67                   -jl 0x4a7711
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a7711;
    }
    // 004a76aa  a1dcde4d00             -mov eax, dword ptr [0x4ddedc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103324) /* 0x4ddedc */);
    // 004a76af  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a76b3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a76b7  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a76bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a76bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a76bd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a76bf  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a76c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a76c4  ff96b80d0000           -call dword ptr [esi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a76ca  8a0de0de4d00           -mov cl, byte ptr [0x4ddee0]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5103328) /* 0x4ddee0 */);
    // 004a76d0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a76d2  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a76d4  8b0dd4de4d00           -mov ecx, dword ptr [0x4dded4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a76da  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a76dd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a76e0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a76e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a76e3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a76e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a76e8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a76ea  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a76ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a76ef  ff96c00d0000           -call dword ptr [esi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a76f5  8a6e08                 -mov ch, byte ptr [esi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a76f8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a76fb  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 004a76fd  7528                   -jne 0x4a7727
    if (!cpu.flags.zf)
    {
        goto L_0x004a7727;
    }
    // 004a76ff  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a7700  e927ffffff             -jmp 0x4a762c
    goto L_0x004a762c;
L_0x004a7705:
    // 004a7705  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a7708  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a770b  0f8527ffffff           -jne 0x4a7638
    if (!cpu.flags.zf)
    {
        goto L_0x004a7638;
    }
L_0x004a7711:
    // 004a7711  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a7713  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a7716  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7717  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7718  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7719  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a771a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a771b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a771c:
    // 004a771c  8a4606                 -mov al, byte ptr [esi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004a771f  004601                 +add byte ptr [esi + 1], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7722  e928ffffff             -jmp 0x4a764f
    goto L_0x004a764f;
L_0x004a7727:
    // 004a7727  8a0de0de4d00           -mov cl, byte ptr [0x4ddee0]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5103328) /* 0x4ddee0 */);
    // 004a772d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a772f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a7731  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7734  05e8e24d00             -add eax, 0x4de2e8
    (cpu.eax) += x86::reg32(x86::sreg32(5104360 /*0x4de2e8*/));
    // 004a7739  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a773a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a773e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a773f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a7741  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a7745  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7746  ff96e00d0000           -call dword ptr [esi + 0xde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3552) /* 0xde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a774c  83c410                 +add esp, 0x10
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
    // 004a774f  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a7750  e9d7feffff             -jmp 0x4a762c
    goto L_0x004a762c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7758(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7758  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7759  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a775a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a775b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a775d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7760  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a7762  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a7765  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7767  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a7769  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a776c  bf9c175a00             -mov edi, 0x5a179c
    cpu.edi = 5904284 /*0x5a179c*/;
    // 004a7771  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7773  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7775  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a7778  7509                   -jne 0x4a7783
    if (!cpu.flags.zf)
    {
        goto L_0x004a7783;
    }
    // 004a777a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a777f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7780  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7781  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7782  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7783:
    // 004a7783  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7784  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7785  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7787  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7789  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a778b  e8c0000000             -call 0x4a7850
    cpu.esp -= 4;
    sub_4a7850(app, cpu);
    if (cpu.terminate) return;
    // 004a7790  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004a7795  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a7797  e864feffff             -call 0x4a7600
    cpu.esp -= 4;
    sub_4a7600(app, cpu);
    if (cpu.terminate) return;
    // 004a779c  ff15d0de4d00           -call dword ptr [0x4dded0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103312) /* 0x4dded0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a77a2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a77a4  c60700                 -mov byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) = 0 /*0x0*/;
    // 004a77a7  ff15e0f55a00           -call dword ptr [0x5af5e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5961184) /* 0x5af5e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a77ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a77af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a77b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a77b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a77b9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a77bb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a77be  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a77c0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a77c3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a77c5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a77c7  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a77ca  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a77cc  059c175a00             -add eax, 0x5a179c
    (cpu.eax) += x86::reg32(x86::sreg32(5904284 /*0x5a179c*/));
    // 004a77d1  803800                 +cmp byte ptr [eax], 0
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
    // 004a77d4  7422                   -je 0x4a77f8
    if (cpu.flags.zf)
    {
        goto L_0x004a77f8;
    }
    // 004a77d6  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a77dc  7605                   -jbe 0x4a77e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a77e3;
    }
    // 004a77de  b900000800             -mov ecx, 0x80000
    cpu.ecx = 524288 /*0x80000*/;
L_0x004a77e3:
    // 004a77e3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a77e4  8d90640d0000           -lea edx, [eax + 0xd64]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3428) /* 0xd64 */);
    // 004a77ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a77eb  ff90b00d0000           -call dword ptr [eax + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a77f1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a77f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a77f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a77f8:
    // 004a77f8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a77fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7800  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7801  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004a7804  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a7806  7505                   -jne 0x4a780d
    if (!cpu.flags.zf)
    {
        goto L_0x004a780d;
    }
    // 004a7808  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 004a780b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a780c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a780d:
    // 004a780d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a780e  8b5001                 -mov edx, dword ptr [eax + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a7811  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a7814  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a7817  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a781a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a781c  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004a781e  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 004a7821  8b4805                 -mov ecx, dword ptr [eax + 5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004a7824  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a7826  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a7829  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a782c  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a782f  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 004a7832  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 004a7835  8b5005                 -mov edx, dword ptr [eax + 5]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004a7838  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a783b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a783c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a783d  8d90c40d0000           -lea edx, [eax + 0xdc4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3524) /* 0xdc4 */);
    // 004a7843  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7844  ff90dc0d0000           -call dword ptr [eax + 0xddc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3548) /* 0xddc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a784a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a784d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a784e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a784f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7850  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7851  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a7853  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7856  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a7858  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a785b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a785d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a785f  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a7862  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7864  059c175a00             -add eax, 0x5a179c
    (cpu.eax) += x86::reg32(x86::sreg32(5904284 /*0x5a179c*/));
    // 004a7869  803800                 +cmp byte ptr [eax], 0
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
    // 004a786c  7427                   -je 0x4a7895
    if (cpu.flags.zf)
    {
        goto L_0x004a7895;
    }
    // 004a786e  884804                 -mov byte ptr [eax + 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.cl;
    // 004a7871  0fbe5001               -movsx edx, byte ptr [eax + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */)));
    // 004a7875  885805                 -mov byte ptr [eax + 5], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = cpu.bl;
    // 004a7878  39ca                   +cmp edx, ecx
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
    // 004a787a  7c20                   -jl 0x4a789c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a789c;
    }
    // 004a787c  c64006ff               -mov byte ptr [eax + 6], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 255 /*0xff*/;
L_0x004a7880:
    // 004a7880  0fbe5002               -movsx edx, byte ptr [eax + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */)));
    // 004a7884  39da                   +cmp edx, ebx
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
    // 004a7886  7d1a                   -jge 0x4a78a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a78a2;
    }
    // 004a7888  c6400701               -mov byte ptr [eax + 7], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 1 /*0x1*/;
    // 004a788c  e86fffffff             -call 0x4a7800
    cpu.esp -= 4;
    sub_4a7800(app, cpu);
    if (cpu.terminate) return;
    // 004a7891  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a7893  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7894  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7895:
    // 004a7895  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a789a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a789b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a789c:
    // 004a789c  c6400601               -mov byte ptr [eax + 6], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 004a78a0  ebde                   -jmp 0x4a7880
    goto L_0x004a7880;
L_0x004a78a2:
    // 004a78a2  c64007ff               -mov byte ptr [eax + 7], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 255 /*0xff*/;
    // 004a78a6  e855ffffff             -call 0x4a7800
    cpu.esp -= 4;
    sub_4a7800(app, cpu);
    if (cpu.terminate) return;
    // 004a78ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a78ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a78b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a78b0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a78b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a78b5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a78b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a78ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a78bc  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a78bf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a78c1  059c175a00             -add eax, 0x5a179c
    (cpu.eax) += x86::reg32(x86::sreg32(5904284 /*0x5a179c*/));
    // 004a78c6  803800                 +cmp byte ptr [eax], 0
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
    // 004a78c9  7506                   -jne 0x4a78d1
    if (!cpu.flags.zf)
    {
        goto L_0x004a78d1;
    }
    // 004a78cb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a78d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a78d1:
    // 004a78d1  885803                 -mov byte ptr [eax + 3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 004a78d4  e827ffffff             -call 0x4a7800
    cpu.esp -= 4;
    sub_4a7800(app, cpu);
    if (cpu.terminate) return;
    // 004a78d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a78db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a78dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a78dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a78dd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a78e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a78e2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a78e5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a78e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a78e9  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a78ec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a78ee  ba9c175a00             -mov edx, 0x5a179c
    cpu.edx = 5904284 /*0x5a179c*/;
    // 004a78f3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a78f5  83baac0d000000         +cmp dword ptr [edx + 0xdac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3500) /* 0xdac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a78fc  7507                   -jne 0x4a7905
    if (!cpu.flags.zf)
    {
        goto L_0x004a7905;
    }
    // 004a78fe  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a7903  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7904  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7905:
    // 004a7905  8b82600d0000           -mov eax, dword ptr [edx + 0xd60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3424) /* 0xd60 */);
    // 004a790b  ff92ac0d0000           -call dword ptr [edx + 0xdac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3500) /* 0xdac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7911  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7912  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7914  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7915  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7916  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7919  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a791d  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a7921  ff15d0de4d00           -call dword ptr [0x4dded0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103312) /* 0x4dded0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7927  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a792b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a792e  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7930  39cb                   +cmp ebx, ecx
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
    // 004a7932  7320                   -jae 0x4a7954
    if (!cpu.flags.cf)
    {
        goto L_0x004a7954;
    }
L_0x004a7934:
    // 004a7934  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a7936  0fbf16                 -movsx edx, word ptr [esi]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi)));
    // 004a7939  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a793c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a793e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7941  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a7944  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7947  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004a794a  d95bfc                 -fstp dword ptr [ebx - 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a794d  39cb                   +cmp ebx, ecx
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
    // 004a794f  72e3                   -jb 0x4a7934
    if (cpu.flags.cf)
    {
        goto L_0x004a7934;
    }
    // 004a7951  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a7954:
    // 004a7954  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7957  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7958  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7959  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a795c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a795c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a795d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a795e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a7961  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a7965  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a7969  ff15d0de4d00           -call dword ptr [0x4dded0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103312) /* 0x4dded0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a796f  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a7973  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a7976  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a7978  39ce                   +cmp esi, ecx
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
    // 004a797a  0f8390000000           -jae 0x4a7a10
    if (!cpu.flags.cf)
    {
        goto L_0x004a7a10;
    }
L_0x004a7980:
    // 004a7980  df03                   -fild word ptr [ebx]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx))));
    // 004a7982  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 004a7984  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a7988  df4302                 -fild word ptr [ebx + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */))));
    // 004a798b  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 004a798d  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a7991  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004a7995  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a7997  dd0584144d00           -fld qword ptr [0x4d1484]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5051524) /* 0x4d1484 */)));
    // 004a799d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a799f  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004a79a1  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a79a4  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a79a6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a79a8  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a79ac  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004a79b0  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004a79b2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a79b6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a79b8  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a79ba  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a79be  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a79c2  25ffff0f00             -and eax, 0xfffff
    cpu.eax &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a79c7  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a79cd  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a79d2  7649                   -jbe 0x4a7a1d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a7a1d;
    }
    // 004a79d4  3d00800f00             +cmp eax, 0xf8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a79d9  7342                   -jae 0x4a7a1d
    if (!cpu.flags.cf)
    {
        goto L_0x004a7a1d;
    }
    // 004a79db  3d00000800             +cmp eax, 0x80000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a79e0  7334                   -jae 0x4a7a16
    if (!cpu.flags.cf)
    {
        goto L_0x004a7a16;
    }
    // 004a79e2  66c703ff7f             -mov word ptr [ebx], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx) = 32767 /*0x7fff*/;
L_0x004a79e7:
    // 004a79e7  81faff7f0000           +cmp edx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a79ed  763b                   -jbe 0x4a7a2a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a7a2a;
    }
    // 004a79ef  81fa00800f00           +cmp edx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a79f5  7333                   -jae 0x4a7a2a
    if (!cpu.flags.cf)
    {
        goto L_0x004a7a2a;
    }
    // 004a79f7  81fa00000800           +cmp edx, 0x80000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a79fd  7323                   -jae 0x4a7a22
    if (!cpu.flags.cf)
    {
        goto L_0x004a7a22;
    }
    // 004a79ff  66c74302ff7f           -mov word ptr [ebx + 2], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32767 /*0x7fff*/;
L_0x004a7a05:
    // 004a7a05  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7a08  39ce                   +cmp esi, ecx
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
    // 004a7a0a  0f8270ffffff           -jb 0x4a7980
    if (cpu.flags.cf)
    {
        goto L_0x004a7980;
    }
L_0x004a7a10:
    // 004a7a10  83c410                 +add esp, 0x10
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
    // 004a7a13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a15  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7a16:
    // 004a7a16  66c7030080             -mov word ptr [ebx], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx) = 32768 /*0x8000*/;
    // 004a7a1b  ebca                   -jmp 0x4a79e7
    goto L_0x004a79e7;
L_0x004a7a1d:
    // 004a7a1d  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004a7a20  ebc5                   -jmp 0x4a79e7
    goto L_0x004a79e7;
L_0x004a7a22:
    // 004a7a22  66c743020080           -mov word ptr [ebx + 2], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32768 /*0x8000*/;
    // 004a7a28  ebdb                   -jmp 0x4a7a05
    goto L_0x004a7a05;
L_0x004a7a2a:
    // 004a7a2a  66895302               -mov word ptr [ebx + 2], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 004a7a2e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7a31  39ce                   +cmp esi, ecx
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
    // 004a7a33  0f8247ffffff           -jb 0x4a7980
    if (cpu.flags.cf)
    {
        goto L_0x004a7980;
    }
    // 004a7a39  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a7a3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7a40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7a41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7a42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7a43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7a44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7a45  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 004a7a48  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004a7a4c  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004a7a50  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7a52  be9c175a00             -mov esi, 0x5a179c
    cpu.esi = 5904284 /*0x5a179c*/;
    // 004a7a57  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 004a7a5b  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x004a7a5f:
    // 004a7a5f  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 004a7a61  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004a7a63  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a7a65  0f85bb000000           -jne 0x4a7b26
    if (!cpu.flags.zf)
    {
        goto L_0x004a7b26;
    }
L_0x004a7a6b:
    // 004a7a6b  8b6c2460               -mov ebp, dword ptr [esp + 0x60]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a7a6f  45                     -inc ebp
    (cpu.ebp)++;
    // 004a7a70  81c6e40d0000           -add esi, 0xde4
    (cpu.esi) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 004a7a76  896c2460               -mov dword ptr [esp + 0x60], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ebp;
    // 004a7a7a  83fd10                 +cmp ebp, 0x10
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
    // 004a7a7d  7ce0                   -jl 0x4a7a5f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a7a5f;
    }
L_0x004a7a7f:
    // 004a7a7f  837c245000             +cmp dword ptr [esp + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7a84  0f8498010000           -je 0x4a7c22
    if (cpu.flags.zf)
    {
        goto L_0x004a7c22;
    }
    // 004a7a8a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a7a8c  8935dcf55a00           -mov dword ptr [0x5af5dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5961180) /* 0x5af5dc */) = cpu.esi;
L_0x004a7a92:
    // 004a7a92  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a7a96  8b3de4de4d00           -mov edi, dword ptr [0x4ddee4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5103332) /* 0x4ddee4 */);
    // 004a7a9c  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7a9e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a7aa0  0f849a010000           -je 0x4a7c40
    if (cpu.flags.zf)
    {
        goto L_0x004a7c40;
    }
    // 004a7aa6  68e8de4d00             -push 0x4ddee8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5103336 /*0x4ddee8*/;
    cpu.esp -= 4;
    // 004a7aab  68e8e24d00             -push 0x4de2e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5104360 /*0x4de2e8*/;
    cpu.esp -= 4;
    // 004a7ab0  8b74245c               -mov esi, dword ptr [esp + 0x5c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a7ab4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7ab5  e85afeffff             -call 0x4a7914
    cpu.esp -= 4;
    sub_4a7914(app, cpu);
    if (cpu.terminate) return;
    // 004a7aba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7abd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7abe  68e8e24d00             -push 0x4de2e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5104360 /*0x4de2e8*/;
    cpu.esp -= 4;
    // 004a7ac3  ff15ccde4d00           -call dword ptr [0x4ddecc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103308) /* 0x4ddecc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7ac9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7acc  68e8de4d00             -push 0x4ddee8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5103336 /*0x4ddee8*/;
    cpu.esp -= 4;
    // 004a7ad1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7ad2  e8f9ff0000             -call 0x4b7ad0
    cpu.esp -= 4;
    sub_4b7ad0(app, cpu);
    if (cpu.terminate) return;
    // 004a7ad7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7ada  8b2dd4de4d00           -mov ebp, dword ptr [0x4dded4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a7ae0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7ae1  68e8de4d00             -push 0x4ddee8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5103336 /*0x4ddee8*/;
    cpu.esp -= 4;
    // 004a7ae6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7ae7  e870feffff             -call 0x4a795c
    cpu.esp -= 4;
    sub_4a795c(app, cpu);
    if (cpu.terminate) return;
    // 004a7aec  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004a7aef:
    // 004a7aef  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a7af3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7af4  8b0dd4de4d00           -mov ecx, dword ptr [0x4dded4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a7afa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7afb  8b5c245c               -mov ebx, dword ptr [esp + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a7aff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7b00  ff15e4f55a00           -call dword ptr [0x5af5e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5961188) /* 0x5af5e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7b06  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7b09  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004a7b0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7b0d  8b35d4de4d00           -mov esi, dword ptr [0x4dded4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a7b13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7b14  ff15ccde4d00           -call dword ptr [0x4ddecc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103308) /* 0x4ddecc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7b1a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7b1d  83c464                 -add esp, 0x64
    (cpu.esp) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 004a7b20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7b21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7b22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7b23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7b24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7b25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7b26:
    // 004a7b26  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a7b2a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7b2c  8b6c2454               -mov ebp, dword ptr [esp + 0x54]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a7b30  e8cbfaffff             -call 0x4a7600
    cpu.esp -= 4;
    sub_4a7600(app, cpu);
    if (cpu.terminate) return;
    // 004a7b35  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 004a7b39  29c5                   +sub ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7b3b  0f843effffff           -je 0x4a7a7f
    if (cpu.flags.zf)
    {
        goto L_0x004a7a7f;
    }
    // 004a7b41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7b42  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 004a7b48  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7b49  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004a7b4d  ff97b40d0000           -call dword ptr [edi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7b53  8b0dd8de4d00           -mov ecx, dword ptr [0x4dded8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103320) /* 0x4dded8 */);
    // 004a7b59  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7b5c  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a7b5f  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 004a7b63  8d5c2440               -lea ebx, [esp + 0x40]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004a7b67  8b8e600d0000           -mov ecx, dword ptr [esi + 0xd60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 004a7b6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a7b6f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7b71  ff97a80d0000           -call dword ptr [edi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7b77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7b79  0f8c95000000           -jl 0x4a7c14
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a7c14;
    }
    // 004a7b7f  8b0ddcde4d00           -mov ecx, dword ptr [0x4ddedc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103324) /* 0x4ddedc */);
    // 004a7b85  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004a7b89  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 004a7b8d  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004a7b91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7b92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7b93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7b94  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004a7b98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7b99  ff97b80d0000           -call dword ptr [edi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7b9f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a7ba2  8a0de0de4d00           -mov cl, byte ptr [0x4ddee0]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5103328) /* 0x4ddee0 */);
    // 004a7ba8  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a7bac  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a7bae  8b0dd4de4d00           -mov ecx, dword ptr [0x4dded4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a7bb4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7bb7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7bb9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7bba  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a7bbe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7bbf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7bc0  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 004a7bc6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7bc7  ff97c00d0000           -call dword ptr [edi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7bcd  8a5608                 -mov dl, byte ptr [esi + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a7bd0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a7bd3  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a7bd5  0f8490feffff           -je 0x4a7a6b
    if (cpu.flags.zf)
    {
        goto L_0x004a7a6b;
    }
    // 004a7bdb  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a7bdf  8a0de0de4d00           -mov cl, byte ptr [0x4ddee0]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5103328) /* 0x4ddee0 */);
    // 004a7be5  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a7be7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7bea  05e8e24d00             -add eax, 0x4de2e8
    (cpu.eax) += x86::reg32(x86::sreg32(5104360 /*0x4de2e8*/));
    // 004a7bef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7bf0  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a7bf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7bf5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7bf6  8d86c40d0000           -lea eax, [esi + 0xdc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3524) /* 0xdc4 */);
    // 004a7bfc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7bfd  ff97e00d0000           -call dword ptr [edi + 0xde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3552) /* 0xde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7c03  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a7c08  83c410                 +add esp, 0x10
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
    // 004a7c0b  897c2450               -mov dword ptr [esp + 0x50], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 004a7c0f  e957feffff             -jmp 0x4a7a6b
    goto L_0x004a7a6b;
L_0x004a7c14:
    // 004a7c14  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a7c18  e83bfbffff             -call 0x4a7758
    cpu.esp -= 4;
    sub_4a7758(app, cpu);
    if (cpu.terminate) return;
    // 004a7c1d  e949feffff             -jmp 0x4a7a6b
    goto L_0x004a7a6b;
L_0x004a7c22:
    // 004a7c22  8b0ddcf55a00           -mov ecx, dword ptr [0x5af5dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5961180) /* 0x5af5dc */);
    // 004a7c28  41                     -inc ecx
    (cpu.ecx)++;
    // 004a7c29  890ddcf55a00           -mov dword ptr [0x5af5dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5961180) /* 0x5af5dc */) = cpu.ecx;
    // 004a7c2f  81f9f4010000           +cmp ecx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7c35  0f8c57feffff           -jl 0x4a7a92
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a7a92;
    }
    // 004a7c3b  e9affeffff             -jmp 0x4a7aef
    goto L_0x004a7aef;
L_0x004a7c40:
    // 004a7c40  68e8de4d00             -push 0x4ddee8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5103336 /*0x4ddee8*/;
    cpu.esp -= 4;
    // 004a7c45  68e8e24d00             -push 0x4de2e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5104360 /*0x4de2e8*/;
    cpu.esp -= 4;
    // 004a7c4a  8b6c245c               -mov ebp, dword ptr [esp + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a7c4e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7c4f  e84c000100             -call 0x4b7ca0
    cpu.esp -= 4;
    sub_4b7ca0(app, cpu);
    if (cpu.terminate) return;
    // 004a7c54  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7c57  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7c58  68e8e24d00             -push 0x4de2e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5104360 /*0x4de2e8*/;
    cpu.esp -= 4;
    // 004a7c5d  ff15ccde4d00           -call dword ptr [0x4ddecc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103308) /* 0x4ddecc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7c63  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7c66  68e8de4d00             -push 0x4ddee8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5103336 /*0x4ddee8*/;
    cpu.esp -= 4;
    // 004a7c6b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7c6c  e85ffe0000             -call 0x4b7ad0
    cpu.esp -= 4;
    sub_4b7ad0(app, cpu);
    if (cpu.terminate) return;
    // 004a7c71  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7c74  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a7c78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7c79  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a7c7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7c7e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7c82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7c83  e830d30000             -call 0x4b4fb8
    cpu.esp -= 4;
    sub_4b4fb8(app, cpu);
    if (cpu.terminate) return;
    // 004a7c88  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7c8b  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 004a7c8d  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 004a7c8f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7c93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7c94  ff542450               -call dword ptr [esp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7c98  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7c9b  8b15d4de4d00           -mov edx, dword ptr [0x4dded4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5103316) /* 0x4dded4 */);
    // 004a7ca1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7ca2  68e8de4d00             -push 0x4ddee8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5103336 /*0x4ddee8*/;
    cpu.esp -= 4;
    // 004a7ca7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7ca8  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a7cac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7cad  ff542458               -call dword ptr [esp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7cb1  83c410                 +add esp, 0x10
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
    // 004a7cb4  e936feffff             -jmp 0x4a7aef
    goto L_0x004a7aef;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7cbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7cbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7cbd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7cbe  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a7cc0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7cc2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a7cc4  7e28                   -jle 0x4a7cee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7cee;
    }
L_0x004a7cc6:
    // 004a7cc6  81f900010000           +cmp ecx, 0x100
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
    // 004a7ccc  7e23                   -jle 0x4a7cf1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7cf1;
    }
    // 004a7cce  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
L_0x004a7cd3:
    // 004a7cd3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a7cd5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a7cd7  e864fdffff             -call 0x4a7a40
    cpu.esp -= 4;
    sub_4a7a40(app, cpu);
    if (cpu.terminate) return;
    // 004a7cdc  8b15e8f55a00           -mov edx, dword ptr [0x5af5e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5961192) /* 0x5af5e8 */);
    // 004a7ce2  81e900010000           -sub ecx, 0x100
    (cpu.ecx) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004a7ce8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a7cea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a7cec  7fd8                   -jg 0x4a7cc6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7cc6;
    }
L_0x004a7cee:
    // 004a7cee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cf0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7cf1:
    // 004a7cf1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7cf3  ebde                   -jmp 0x4a7cd3
    goto L_0x004a7cd3;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a7d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7d00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7d01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7d02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7d03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7d04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7d05  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7d08  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7d0c  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004a7d10  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 004a7d14  e817e8fdff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 004a7d19  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x004a7d1c:
    // 004a7d1c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004a7d21  3b0c24                 +cmp ecx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d24  7f11                   -jg 0x4a7d37
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7d37;
    }
    // 004a7d26  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
L_0x004a7d29:
    // 004a7d29  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a7d2c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a7d2e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a7d31  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a7d33  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a7d35  750f                   -jne 0x4a7d46
    if (!cpu.flags.zf)
    {
        goto L_0x004a7d46;
    }
L_0x004a7d37:
    // 004a7d37  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a7d3a  39f9                   +cmp ecx, edi
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
    // 004a7d3c  740f                   -je 0x4a7d4d
    if (cpu.flags.zf)
    {
        goto L_0x004a7d4d;
    }
    // 004a7d3e  8d6f01                 -lea ebp, [edi + 1]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a7d41  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004a7d44  ebd6                   -jmp 0x4a7d1c
    goto L_0x004a7d1c;
L_0x004a7d46:
    // 004a7d46  41                     -inc ecx
    (cpu.ecx)++;
    // 004a7d47  39f1                   +cmp ecx, esi
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
    // 004a7d49  7ede                   -jle 0x4a7d29
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7d29;
    }
    // 004a7d4b  ebea                   -jmp 0x4a7d37
    goto L_0x004a7d37;
L_0x004a7d4d:
    // 004a7d4d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a7d4f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7d52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d55  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d57  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a7d5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7d5c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7d5d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7d5e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7d5f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7d62  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a7d64  c7442408cdcccc3d       -mov dword ptr [esp + 8], 0x3dcccccd
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1036831949 /*0x3dcccccd*/;
    // 004a7d6c  3d22560000             +cmp eax, 0x5622
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22050 /*0x5622*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d71  0f8f96000000           -jg 0x4a7e0d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7e0d;
    }
    // 004a7d77  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a7d79:
    // 004a7d79  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7d7c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7d7e  898afcf55a00           -mov dword ptr [edx + 0x5af5fc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5961212) /* 0x5af5fc */) = cpu.ecx;
    // 004a7d84  81fa10590000           +cmp edx, 0x5910
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22800 /*0x5910*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d8a  75ed                   -jne 0x4a7d79
    if (!cpu.flags.zf)
    {
        goto L_0x004a7d79;
    }
    // 004a7d8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7d8d  b900f65a00             -mov ecx, 0x5af600
    cpu.ecx = 5961216 /*0x5af600*/;
    // 004a7d92  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a7d94:
    // 004a7d94  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7d97  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004a7d9b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7d9d  898a2c4f5b00           -mov dword ptr [edx + 0x5b4f2c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5984044) /* 0x5b4f2c */) = cpu.ecx;
    // 004a7da3  e858ffffff             -call 0x4a7d00
    cpu.esp -= 4;
    sub_4a7d00(app, cpu);
    if (cpu.terminate) return;
    // 004a7da8  d982f4ea4d00           -fld dword ptr [edx + 0x4deaf4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(5106420) /* 0x4deaf4 */)));
    // 004a7dae  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a7db0  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a7db2  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 004a7db9  d99a04eb4d00           -fstp dword ptr [edx + 0x4deb04]
    app->getMemory<float>(cpu.edx + x86::reg32(5106436) /* 0x4deb04 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a7dbf  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004a7dc3  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a7dc5  dc0d8c144d00           -fmul qword ptr [0x4d148c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5051532) /* 0x4d148c */));
    // 004a7dcb  8b822c4f5b00           -mov eax, dword ptr [edx + 0x5b4f2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5984044) /* 0x5b4f2c */);
    // 004a7dd1  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7dd3  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7dd6  89820c4f5b00           -mov dword ptr [edx + 0x5b4f0c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5984012) /* 0x5b4f0c */) = cpu.eax;
    // 004a7ddc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7dde  89821c4f5b00           -mov dword ptr [edx + 0x5b4f1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5984028) /* 0x5b4f1c */) = cpu.eax;
    // 004a7de4  899a4c4f5b00           -mov dword ptr [edx + 0x5b4f4c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5984076) /* 0x5b4f4c */) = cpu.ebx;
    // 004a7dea  899aecf55a00           -mov dword ptr [edx + 0x5af5ec], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5961196) /* 0x5af5ec */) = cpu.ebx;
    // 004a7df0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7df2  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a7df4  899a3c4f5b00           -mov dword ptr [edx + 0x5b4f3c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5984060) /* 0x5b4f3c */) = cpu.ebx;
    // 004a7dfa  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a7dfe  83fa10                 +cmp edx, 0x10
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
    // 004a7e01  7591                   -jne 0x4a7d94
    if (!cpu.flags.zf)
    {
        goto L_0x004a7d94;
    }
    // 004a7e03  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7e05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e06  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7e09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e0a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7e0d:
    // 004a7e0d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a7e12  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7e15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a7e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7e20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7e21  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7e24  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a7e26  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a7e28  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a7e2c  e89ffe0000             -call 0x4b7cd0
    cpu.esp -= 4;
    sub_4b7cd0(app, cpu);
    if (cpu.terminate) return;
    // 004a7e31  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004a7e35  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a7e37  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a7e3b  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004a7e3f  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a7e41  d80d94144d00           -fmul dword ptr [0x4d1494]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5051540) /* 0x4d1494 */));
    // 004a7e47  e8e4e6fdff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 004a7e4c  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a7e4f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a7e52  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7e55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a7e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7e60  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a7e62  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a7e64  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7e67  740a                   -je 0x4a7e73
    if (cpu.flags.zf)
    {
        goto L_0x004a7e73;
    }
    // 004a7e69  7d09                   -jge 0x4a7e74
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a7e74;
    }
    // 004a7e6b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a7e6e  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004a7e71  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x004a7e73:
    // 004a7e73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7e74:
    // 004a7e74  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004a7e79  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7e7b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7e7d  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a7e80  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004a7e83  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a7e85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a7e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7e90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7e92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7e93  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a7e95  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a7e97:
    // 004a7e97  4a                     -dec edx
    (cpu.edx)--;
    // 004a7e98  83faff                 +cmp edx, -1
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
    // 004a7e9b  740c                   -je 0x4a7ea9
    if (cpu.flags.zf)
    {
        goto L_0x004a7ea9;
    }
    // 004a7e9d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7e9f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a7ea2  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a7ea4  40                     -inc eax
    (cpu.eax)++;
    // 004a7ea5  01d9                   +add ecx, ebx
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
    // 004a7ea7  ebee                   -jmp 0x4a7e97
    goto L_0x004a7e97;
L_0x004a7ea9:
    // 004a7ea9  83fe01                 +cmp esi, 1
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
    // 004a7eac  7505                   -jne 0x4a7eb3
    if (!cpu.flags.zf)
    {
        goto L_0x004a7eb3;
    }
    // 004a7eae  83f97f                 +cmp ecx, 0x7f
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
    // 004a7eb1  7f26                   -jg 0x4a7ed9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7ed9;
    }
L_0x004a7eb3:
    // 004a7eb3  83fe02                 +cmp esi, 2
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
    // 004a7eb6  7508                   -jne 0x4a7ec0
    if (!cpu.flags.zf)
    {
        goto L_0x004a7ec0;
    }
    // 004a7eb8  81f9ff7f0000           +cmp ecx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7ebe  7f21                   -jg 0x4a7ee1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7ee1;
    }
L_0x004a7ec0:
    // 004a7ec0  83fe03                 +cmp esi, 3
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
    // 004a7ec3  750e                   -jne 0x4a7ed3
    if (!cpu.flags.zf)
    {
        goto L_0x004a7ed3;
    }
    // 004a7ec5  81f9ffff7f00           +cmp ecx, 0x7fffff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388607 /*0x7fffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7ecb  7e06                   -jle 0x4a7ed3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7ed3;
    }
    // 004a7ecd  81e900000001           -sub ecx, 0x1000000
    (cpu.ecx) -= x86::reg32(x86::sreg32(16777216 /*0x1000000*/));
L_0x004a7ed3:
    // 004a7ed3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7ed5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7ed6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7ed7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7ed8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7ed9:
    // 004a7ed9  81e900010000           +sub ecx, 0x100
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7edf  ebf2                   -jmp 0x4a7ed3
    goto L_0x004a7ed3;
L_0x004a7ee1:
    // 004a7ee1  81e900000100           -sub ecx, 0x10000
    (cpu.ecx) -= x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 004a7ee7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7ee9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7eea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7eeb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7eec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7ef0  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 004a7ef6  c7809000000000000000   -mov dword ptr [eax + 0x90], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
    // 004a7f00  c7406c0f000000         -mov dword ptr [eax + 0x6c], 0xf
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 15 /*0xf*/;
    // 004a7f07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7f08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7f08  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a7f0f  c740087f000000         -mov dword ptr [eax + 8], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 004a7f16  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004a7f1d  c740107f000000         -mov dword ptr [eax + 0x10], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 127 /*0x7f*/;
    // 004a7f24  c74014ffffffff         -mov dword ptr [eax + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
    // 004a7f2b  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a7f32  c7401c3c000000         -mov dword ptr [eax + 0x1c], 0x3c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 60 /*0x3c*/;
    // 004a7f39  c74020ffffffff         -mov dword ptr [eax + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 004a7f40  c7402401000000         -mov dword ptr [eax + 0x24], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 004a7f47  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004a7f4e  c7402c01000000         -mov dword ptr [eax + 0x2c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 1 /*0x1*/;
    // 004a7f55  c7403040000000         -mov dword ptr [eax + 0x30], 0x40
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 64 /*0x40*/;
    // 004a7f5c  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004a7f63  c740387f000000         -mov dword ptr [eax + 0x38], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 127 /*0x7f*/;
    // 004a7f6a  c7403c00000000         -mov dword ptr [eax + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 004a7f71  c7404000000000         -mov dword ptr [eax + 0x40], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 004a7f78  c7404400000000         -mov dword ptr [eax + 0x44], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 004a7f7f  c7404800000000         -mov dword ptr [eax + 0x48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004a7f86  c7404c00000000         -mov dword ptr [eax + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 004a7f8d  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 004a7f94  c7405c00000000         -mov dword ptr [eax + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 004a7f9b  c7406428eb4d00         -mov dword ptr [eax + 0x64], 0x4deb28
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 5106472 /*0x4deb28*/;
    // 004a7fa2  c740707f000000         -mov dword ptr [eax + 0x70], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = 127 /*0x7f*/;
    // 004a7fa9  c7407400000000         -mov dword ptr [eax + 0x74], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 004a7fb0  c7407800000000         -mov dword ptr [eax + 0x78], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 004a7fb7  c7407c00000000         -mov dword ptr [eax + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
    // 004a7fbe  c7808000000000000000   -mov dword ptr [eax + 0x80], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */) = 0 /*0x0*/;
    // 004a7fc8  c7808400000000000000   -mov dword ptr [eax + 0x84], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 004a7fd2  c7808c00000000000000   -mov dword ptr [eax + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 004a7fdc  c7808800000000000000   -mov dword ptr [eax + 0x88], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 004a7fe6  c7809400000001000000   -mov dword ptr [eax + 0x94], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
    // 004a7ff0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a7ff2  81c298000000           -add edx, 0x98
    (cpu.edx) += x86::reg32(x86::sreg32(152 /*0x98*/));
L_0x004a7ff8:
    // 004a7ff8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a7ffe  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8001  39d0                   +cmp eax, edx
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
    // 004a8003  75f3                   -jne 0x4a7ff8
    if (!cpu.flags.zf)
    {
        goto L_0x004a7ff8;
    }
    // 004a8005  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a8008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8008  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8009  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a800a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a800b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a800c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a800d  83784800               +cmp dword ptr [eax + 0x48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8011  7552                   -jne 0x4a8065
    if (!cpu.flags.zf)
    {
        goto L_0x004a8065;
    }
L_0x004a8013:
    // 004a8013  8b7054                 -mov esi, dword ptr [eax + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004a8016  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a8018  7409                   -je 0x4a8023
    if (cpu.flags.zf)
    {
        goto L_0x004a8023;
    }
    // 004a801a  8b4a54                 -mov ecx, dword ptr [edx + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 004a801d  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004a8020  897854                 -mov dword ptr [eax + 0x54], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edi;
L_0x004a8023:
    // 004a8023  8b685c                 -mov ebp, dword ptr [eax + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004a8026  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a8028  7409                   -je 0x4a8033
    if (cpu.flags.zf)
    {
        goto L_0x004a8033;
    }
    // 004a802a  8b4a5c                 -mov ecx, dword ptr [edx + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 004a802d  8d1c29                 -lea ebx, [ecx + ebp]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004a8030  89585c                 -mov dword ptr [eax + 0x5c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.ebx;
L_0x004a8033:
    // 004a8033  8b7064                 -mov esi, dword ptr [eax + 0x64]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    // 004a8036  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a8038  7409                   -je 0x4a8043
    if (cpu.flags.zf)
    {
        goto L_0x004a8043;
    }
    // 004a803a  8b4a64                 -mov ecx, dword ptr [edx + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    // 004a803d  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004a8040  897864                 -mov dword ptr [eax + 0x64], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = cpu.edi;
L_0x004a8043:
    // 004a8043  8b6874                 -mov ebp, dword ptr [eax + 0x74]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004a8046  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a8048  7409                   -je 0x4a8053
    if (cpu.flags.zf)
    {
        goto L_0x004a8053;
    }
    // 004a804a  8b4a74                 -mov ecx, dword ptr [edx + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 004a804d  8d1c29                 -lea ebx, [ecx + ebp]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004a8050  895874                 -mov dword ptr [eax + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ebx;
L_0x004a8053:
    // 004a8053  8bb080000000           -mov esi, dword ptr [eax + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004a8059  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a805b  7510                   -jne 0x4a806d
    if (!cpu.flags.zf)
    {
        goto L_0x004a806d;
    }
    // 004a805d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a805f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8060  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8061  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8062  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8063  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8064  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8065:
    // 004a8065  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004a8068  014848                 +add dword ptr [eax + 0x48], ecx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a806b  eba6                   -jmp 0x4a8013
    goto L_0x004a8013;
L_0x004a806d:
    // 004a806d  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 004a8073  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004a8076  89b880000000           -mov dword ptr [eax + 0x80], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */) = cpu.edi;
    // 004a807c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a807e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a807f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8080  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8081  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8082  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8083  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8084(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8084  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8085  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8086  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8087  8a3d30eb4d00           -mov bh, byte ptr [0x4deb30]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(5106480) /* 0x4deb30 */);
    // 004a808d  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
L_0x004a808f:
    // 004a808f  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 004a8091  742a                   -je 0x4a80bd
    if (cpu.flags.zf)
    {
        goto L_0x004a80bd;
    }
L_0x004a8093:
    // 004a8093  b8b0bf5900             -mov eax, 0x59bfb0
    cpu.eax = 5881776 /*0x59bfb0*/;
    // 004a8098  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004a809a:
    // 004a809a  3a480c                 +cmp cl, byte ptr [eax + 0xc]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a809d  7407                   -je 0x4a80a6
    if (cpu.flags.zf)
    {
        goto L_0x004a80a6;
    }
    // 004a809f  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 004a80a2  38fb                   +cmp bl, bh
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
    // 004a80a4  74e9                   -je 0x4a808f
    if (cpu.flags.zf)
    {
        goto L_0x004a808f;
    }
L_0x004a80a6:
    // 004a80a6  42                     -inc edx
    (cpu.edx)++;
    // 004a80a7  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004a80aa  83fa10                 +cmp edx, 0x10
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
    // 004a80ad  7ceb                   -jl 0x4a809a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a809a;
    }
    // 004a80af  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a80b1  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 004a80b3  883d30eb4d00           -mov byte ptr [0x4deb30], bh
    app->getMemory<x86::reg8>(x86::reg32(5106480) /* 0x4deb30 */) = cpu.bh;
    // 004a80b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a80ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a80bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a80bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a80bd:
    // 004a80bd  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 004a80bf  ebd2                   -jmp 0x4a8093
    goto L_0x004a8093;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a80c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a80c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a80c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a80c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a80c7  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a80ca  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a80cd  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a80d1  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a80d3  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a80d5  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a80d9  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a80dc  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a80df  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a80e3  8b4305                 -mov eax, dword ptr [ebx + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5) /* 0x5 */);
    // 004a80e6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a80e9  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a80ed  8b4306                 -mov eax, dword ptr [ebx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004a80f0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a80f3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a80f7  8b4307                 -mov eax, dword ptr [ebx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 004a80fa  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a80fd  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a8101  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8103  e800ffffff             -call 0x4a8008
    cpu.esp -= 4;
    sub_4a8008(app, cpu);
    if (cpu.terminate) return;
    // 004a8108  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a810c  83faff                 +cmp edx, -1
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
    // 004a810f  0f8429030000           -je 0x4a843e
    if (cpu.flags.zf)
    {
        goto L_0x004a843e;
    }
    // 004a8115  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8117  0f8c2e030000           -jl 0x4a844b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a844b;
    }
    // 004a811d  83fa7f                 +cmp edx, 0x7f
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
    // 004a8120  0f8f25030000           -jg 0x4a844b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a844b;
    }
L_0x004a8126:
    // 004a8126  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a812a  83f8ff                 +cmp eax, -1
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
    // 004a812d  0f8526030000           -jne 0x4a8459
    if (!cpu.flags.zf)
    {
        goto L_0x004a8459;
    }
    // 004a8133  c744241840000000       -mov dword ptr [esp + 0x18], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 64 /*0x40*/;
L_0x004a813b:
    // 004a813b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a813f  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8142  0f852c030000           -jne 0x4a8474
    if (!cpu.flags.zf)
    {
        goto L_0x004a8474;
    }
    // 004a8148  c74424087f000000       -mov dword ptr [esp + 8], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
L_0x004a8150:
    // 004a8150  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004a8153  8b5e34                 -mov ebx, dword ptr [esi + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004a8156  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a815a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a815c  7411                   -je 0x4a816f
    if (cpu.flags.zf)
    {
        goto L_0x004a816f;
    }
    // 004a815e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8160  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8164  e817bd0000             -call 0x4b3e80
    cpu.esp -= 4;
    sub_4b3e80(app, cpu);
    if (cpu.terminate) return;
    // 004a8169  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a816b  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
L_0x004a816f:
    // 004a816f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8173  83f87f                 +cmp eax, 0x7f
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
    // 004a8176  0f8e13030000           -jle 0x4a848f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a848f;
    }
    // 004a817c  c74424147f000000       -mov dword ptr [esp + 0x14], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 127 /*0x7f*/;
L_0x004a8184:
    // 004a8184  8bae94000000           -mov ebp, dword ptr [esi + 0x94]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 004a818a  83fd01                 +cmp ebp, 1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a818d  7411                   -je 0x4a81a0
    if (cpu.flags.zf)
    {
        goto L_0x004a81a0;
    }
    // 004a818f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8193  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a8196  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a8199  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a819c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004a81a0:
    // 004a81a0  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a81a4  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004a81a8  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a81ab  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a81af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a81b1  0f8ceb020000           -jl 0x4a84a2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a84a2;
    }
    // 004a81b7  83f87f                 +cmp eax, 0x7f
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
    // 004a81ba  7e08                   -jle 0x4a81c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a81c4;
    }
    // 004a81bc  c74424187f000000       -mov dword ptr [esp + 0x18], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 127 /*0x7f*/;
L_0x004a81c4:
    // 004a81c4  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a81c8  83f9ff                 +cmp ecx, -1
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
    // 004a81cb  0f85dc020000           -jne 0x4a84ad
    if (!cpu.flags.zf)
    {
        goto L_0x004a84ad;
    }
    // 004a81d1  c744241040000000       -mov dword ptr [esp + 0x10], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 64 /*0x40*/;
L_0x004a81d9:
    // 004a81d9  b9604f5b00             -mov ecx, 0x5b4f60
    cpu.ecx = 5984096 /*0x5b4f60*/;
    // 004a81de  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a81e1  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004a81e4  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a81e7  e8d0d1ffff             -call 0x4a53bc
    cpu.esp -= 4;
    sub_4a53bc(app, cpu);
    if (cpu.terminate) return;
    // 004a81ec  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a81ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a81f0  0f8c3f020000           -jl 0x4a8435
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8435;
    }
    // 004a81f6  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004a81fd  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a81ff  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 004a8202  81c1b0bf5900           -add ecx, 0x59bfb0
    (cpu.ecx) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 004a8208  8a8694000000           -mov al, byte ptr [esi + 0x94]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 004a820e  884137                 -mov byte ptr [ecx + 0x37], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */) = cpu.al;
    // 004a8211  668b4640               -mov ax, word ptr [esi + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 004a8215  66894110               -mov word ptr [ecx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004a8219  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a821d  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a8221  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8223  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 004a8226  668b5910               -mov bx, word ptr [ecx + 0x10]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a822a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a822c  66895910               -mov word ptr [ecx + 0x10], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.bx;
    // 004a8230  83be9000000000         +cmp dword ptr [esi + 0x90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8237  740c                   -je 0x4a8245
    if (cpu.flags.zf)
    {
        goto L_0x004a8245;
    }
    // 004a8239  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004a823d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a823f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8241  66895110               -mov word ptr [ecx + 0x10], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dx;
L_0x004a8245:
    // 004a8245  8b5e44                 -mov ebx, dword ptr [esi + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004a8248  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a824a  740b                   -je 0x4a8257
    if (cpu.flags.zf)
    {
        goto L_0x004a8257;
    }
    // 004a824c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a824e  e82dbc0000             -call 0x4b3e80
    cpu.esp -= 4;
    sub_4b3e80(app, cpu);
    if (cpu.terminate) return;
    // 004a8253  66014110               -add word ptr [ecx + 0x10], ax
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.ax));
L_0x004a8257:
    // 004a8257  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004a825a  89414c                 -mov dword ptr [ecx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004a825d  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 004a8260  894150                 -mov dword ptr [ecx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004a8263  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 004a8266  894154                 -mov dword ptr [ecx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 004a8269  8b4150                 -mov eax, dword ptr [ecx + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 004a826c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a826e  740b                   -je 0x4a827b
    if (cpu.flags.zf)
    {
        goto L_0x004a827b;
    }
    // 004a8270  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004a8274  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a8277  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004a827b:
    // 004a827b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a827d  88410d                 -mov byte ptr [ecx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a8280  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8284  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a828b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a828e  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a8291  8b5e3c                 -mov ebx, dword ptr [esi + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 004a8294  8b5638                 -mov edx, dword ptr [esi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004a8297  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8299  7409                   -je 0x4a82a4
    if (cpu.flags.zf)
    {
        goto L_0x004a82a4;
    }
    // 004a829b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a829d  e8debb0000             -call 0x4b3e80
    cpu.esp -= 4;
    sub_4b3e80(app, cpu);
    if (cpu.terminate) return;
    // 004a82a2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a82a4:
    // 004a82a4  83fa7f                 +cmp edx, 0x7f
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
    // 004a82a7  0f8e1b020000           -jle 0x4a84c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a84c8;
    }
    // 004a82ad  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
L_0x004a82b2:
    // 004a82b2  0faf542434             -imul edx, dword ptr [esp + 0x34]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))));
    // 004a82b7  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 004a82bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a82be  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a82c1  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a82c3  884130                 -mov byte ptr [ecx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 004a82c6  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a82ca  884132                 -mov byte ptr [ecx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 004a82cd  8a442418               -mov al, byte ptr [esp + 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a82d1  88410f                 -mov byte ptr [ecx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004a82d4  668b4628               -mov ax, word ptr [esi + 0x28]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004a82d8  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 004a82db  66894142               -mov word ptr [ecx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 004a82df  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a82e3  884133                 -mov byte ptr [ecx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 004a82e6  8b4664                 -mov eax, dword ptr [esi + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 004a82e9  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004a82ec  8b4670                 -mov eax, dword ptr [esi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 004a82ef  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a82f2  c6413500               -mov byte ptr [ecx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 004a82f6  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a82f9  8a4624                 -mov al, byte ptr [esi + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004a82fc  884134                 -mov byte ptr [ecx + 0x34], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.al;
    // 004a82ff  8a4620                 -mov al, byte ptr [esi + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a8302  884136                 -mov byte ptr [ecx + 0x36], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(54) /* 0x36 */) = cpu.al;
    // 004a8305  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004a8308  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a830a  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a830d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a830f  0f8cc6010000           -jl 0x4a84db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a84db;
    }
L_0x004a8315:
    // 004a8315  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004a8318  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a831b  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004a831e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a8321  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8323  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a8325  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 004a8328  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a832b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a832d  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a8330  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 004a8333  894158                 -mov dword ptr [ecx + 0x58], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 004a8336  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 004a833c  89415c                 -mov dword ptr [ecx + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 004a833f  8a4678                 -mov al, byte ptr [esi + 0x78]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004a8342  88413c                 -mov byte ptr [ecx + 0x3c], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.al;
    // 004a8345  8a8684000000           -mov al, byte ptr [esi + 0x84]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004a834b  88413d                 -mov byte ptr [ecx + 0x3d], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(61) /* 0x3d */) = cpu.al;
    // 004a834e  668b8688000000         -mov ax, word ptr [esi + 0x88]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004a8355  66894140               -mov word ptr [ecx + 0x40], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.ax;
    // 004a8359  837e7c00               +cmp dword ptr [esi + 0x7c], 0
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
    // 004a835d  0f8484010000           -je 0x4a84e7
    if (cpu.flags.zf)
    {
        goto L_0x004a84e7;
    }
    // 004a8363  e80cfdfdff             -call 0x488074
    cpu.esp -= 4;
    sub_488074(app, cpu);
    if (cpu.terminate) return;
    // 004a8368  8b5e78                 -mov ebx, dword ptr [esi + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004a836b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a836d  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a836f  88513e                 -mov byte ptr [ecx + 0x3e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.dl;
L_0x004a8372:
    // 004a8372  83be8c00000000         +cmp dword ptr [esi + 0x8c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8379  0f8471010000           -je 0x4a84f0
    if (cpu.flags.zf)
    {
        goto L_0x004a84f0;
    }
    // 004a837f  e8f0fcfdff             -call 0x488074
    cpu.esp -= 4;
    sub_488074(app, cpu);
    if (cpu.terminate) return;
    // 004a8384  8b9e84000000           -mov ebx, dword ptr [esi + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004a838a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a838c  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a838e  88513f                 -mov byte ptr [ecx + 0x3f], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = cpu.dl;
L_0x004a8391:
    // 004a8391  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a8393  e898890000             -call 0x4b0d30
    cpu.esp -= 4;
    sub_4b0d30(app, cpu);
    if (cpu.terminate) return;
    // 004a8398  8a466c                 -mov al, byte ptr [esi + 0x6c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 004a839b  88410b                 -mov byte ptr [ecx + 0xb], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = cpu.al;
    // 004a839e  8a464c                 -mov al, byte ptr [esi + 0x4c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004a83a1  884138                 -mov byte ptr [ecx + 0x38], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.al;
    // 004a83a4  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a83a8  884139                 -mov byte ptr [ecx + 0x39], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(57) /* 0x39 */) = cpu.al;
    // 004a83ab  8a4704                 -mov al, byte ptr [edi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a83ae  88410a                 -mov byte ptr [ecx + 0xa], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.al;
    // 004a83b1  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 004a83b4  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004a83b8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a83ba  e831080000             -call 0x4a8bf0
    cpu.esp -= 4;
    sub_4a8bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a83bf  807f0b00               +cmp byte ptr [edi + 0xb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a83c3  0f8430010000           -je 0x4a84f9
    if (cpu.flags.zf)
    {
        goto L_0x004a84f9;
    }
    // 004a83c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a83cb:
    // 004a83cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a83cc  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a83cf  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a83d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a83d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a83d5  668b470c               -mov ax, word ptr [edi + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a83d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a83da  8b4135                 -mov eax, dword ptr [ecx + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 004a83dd  8b3da4bf5900           -mov edi, dword ptr [0x59bfa4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5881764) /* 0x59bfa4 */);
    // 004a83e3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a83e6  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a83e9  8b5136                 -mov edx, dword ptr [ecx + 0x36]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(54) /* 0x36 */);
    // 004a83ec  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a83ef  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a83f2  bb013f0000             -mov ebx, 0x3f01
    cpu.ebx = 16129 /*0x3f01*/;
    // 004a83f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a83f9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a83fc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a83fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a83ff  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a8402  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a8405  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8406  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004a8409  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a840c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8410  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8411  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a8415  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a8417  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8418  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a841a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a841c  8a4202                 -mov al, byte ptr [edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a841f  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a8423  e8100bfeff             -call 0x488f38
    cpu.esp -= 4;
    sub_488f38(app, cpu);
    if (cpu.terminate) return;
    // 004a8428  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a842a  0f8cd3000000           -jl 0x4a8503
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8503;
    }
    // 004a8430  a1604f5b00             -mov eax, dword ptr [0x5b4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5984096) /* 0x5b4f60 */);
L_0x004a8435:
    // 004a8435  83c41c                 +add esp, 0x1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8438  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8439  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a843a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a843b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a843e:
    // 004a843e  c744240c7f000000       -mov dword ptr [esp + 0xc], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 127 /*0x7f*/;
    // 004a8446  e9dbfcffff             -jmp 0x4a8126
    goto L_0x004a8126;
L_0x004a844b:
    // 004a844b  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a8450  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a8453  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8454  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8455  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8456  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a8459:
    // 004a8459  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a845b  7c09                   -jl 0x4a8466
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8466;
    }
    // 004a845d  83f87f                 +cmp eax, 0x7f
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
    // 004a8460  0f8ed5fcffff           -jle 0x4a813b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a813b;
    }
L_0x004a8466:
    // 004a8466  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a846b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a846e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a846f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8470  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8471  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a8474:
    // 004a8474  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a8476  7c09                   -jl 0x4a8481
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8481;
    }
    // 004a8478  83fd7f                 +cmp ebp, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a847b  0f8ecffcffff           -jle 0x4a8150
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8150;
    }
L_0x004a8481:
    // 004a8481  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a8486  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a8489  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a848a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a848b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a848c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a848f:
    // 004a848f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8491  0f8dedfcffff           -jge 0x4a8184
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8184;
    }
    // 004a8497  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a8499  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004a849d  e9e2fcffff             -jmp 0x4a8184
    goto L_0x004a8184;
L_0x004a84a2:
    // 004a84a2  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a84a4  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a84a8  e917fdffff             -jmp 0x4a81c4
    goto L_0x004a81c4;
L_0x004a84ad:
    // 004a84ad  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a84af  7c09                   -jl 0x4a84ba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a84ba;
    }
    // 004a84b1  83f97f                 +cmp ecx, 0x7f
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
    // 004a84b4  0f8e1ffdffff           -jle 0x4a81d9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a81d9;
    }
L_0x004a84ba:
    // 004a84ba  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a84bf  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a84c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84c5  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a84c8:
    // 004a84c8  83fa80                 +cmp edx, -0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-128 /*-0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a84cb  0f8de1fdffff           -jge 0x4a82b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a82b2;
    }
    // 004a84d1  ba80ffffff             -mov edx, 0xffffff80
    cpu.edx = 4294967168 /*0xffffff80*/;
    // 004a84d6  e9d7fdffff             -jmp 0x4a82b2
    goto L_0x004a82b2;
L_0x004a84db:
    // 004a84db  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 004a84e2  e92efeffff             -jmp 0x4a8315
    goto L_0x004a8315;
L_0x004a84e7:
    // 004a84e7  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
    // 004a84eb  e982feffff             -jmp 0x4a8372
    goto L_0x004a8372;
L_0x004a84f0:
    // 004a84f0  c6413f00               -mov byte ptr [ecx + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
    // 004a84f4  e998feffff             -jmp 0x4a8391
    goto L_0x004a8391;
L_0x004a84f9:
    // 004a84f9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a84fe  e9c8feffff             -jmp 0x4a83cb
    goto L_0x004a83cb;
L_0x004a8503:
    // 004a8503  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a8505  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004a850a  e869d1ffff             -call 0x4a5678
    cpu.esp -= 4;
    sub_4a5678(app, cpu);
    if (cpu.terminate) return;
    // 004a850f  8915604f5b00           -mov dword ptr [0x5b4f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5984096) /* 0x5b4f60 */) = cpu.edx;
    // 004a8515  a1604f5b00             -mov eax, dword ptr [0x5b4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5984096) /* 0x5b4f60 */);
    // 004a851a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a851d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a851e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a851f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8520  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a8524(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8524  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8525  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8526  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8527  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8528  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8529  81ec98010000           -sub esp, 0x198
    (cpu.esp) -= x86::reg32(x86::sreg32(408 /*0x198*/));
    // 004a852f  89842480010000         -mov dword ptr [esp + 0x180], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */) = cpu.eax;
    // 004a8536  8994247c010000         -mov dword ptr [esp + 0x17c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */) = cpu.edx;
    // 004a853d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a853f  b9f7ffffff             -mov ecx, 0xfffffff7
    cpu.ecx = 4294967287 /*0xfffffff7*/;
    // 004a8544  89942488010000         -mov dword ptr [esp + 0x188], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.edx;
    // 004a854b  898c2470010000         -mov dword ptr [esp + 0x170], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.ecx;
    // 004a8552  8994248c010000         -mov dword ptr [esp + 0x18c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.edx;
    // 004a8559  89942490010000         -mov dword ptr [esp + 0x190], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */) = cpu.edx;
    // 004a8560  89942474010000         -mov dword ptr [esp + 0x174], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */) = cpu.edx;
    // 004a8567  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8569  0f84e8000000           -je 0x4a8657
    if (cpu.flags.zf)
    {
        goto L_0x004a8657;
    }
    // 004a856f  6681385054             +cmp word ptr [eax], 0x5450
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
    // 004a8574  0f85ba000000           -jne 0x4a8634
    if (!cpu.flags.zf)
    {
        goto L_0x004a8634;
    }
    // 004a857a  8bac247c010000         -mov ebp, dword ptr [esp + 0x17c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 004a8581  8bbc247c010000         -mov edi, dword ptr [esp + 0x17c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 004a8588  8b6d03                 -mov ebp, dword ptr [ebp + 3]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 004a858b  8b7f02                 -mov edi, dword ptr [edi + 2]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a858e  c1fd18                 -sar ebp, 0x18
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (24 /*0x18*/ % 32));
    // 004a8591  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 004a8594  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8597  0f859e000000           -jne 0x4a863b
    if (!cpu.flags.zf)
    {
        goto L_0x004a863b;
    }
    // 004a859d  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
L_0x004a85a2:
    // 004a85a2  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a85a5  0f859f000000           -jne 0x4a864a
    if (!cpu.flags.zf)
    {
        goto L_0x004a864a;
    }
    // 004a85ab  bf3c000000             -mov edi, 0x3c
    cpu.edi = 60 /*0x3c*/;
L_0x004a85b0:
    // 004a85b0  8b842480010000         -mov eax, dword ptr [esp + 0x180]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 004a85b7  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 004a85bb  0f84a7000000           -je 0x4a8668
    if (cpu.flags.zf)
    {
        goto L_0x004a8668;
    }
    // 004a85c1  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004a85c4:
    // 004a85c4  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004a85cb  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a85cd  e81ef9ffff             -call 0x4a7ef0
    cpu.esp -= 4;
    sub_4a7ef0(app, cpu);
    if (cpu.terminate) return;
    // 004a85d2  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004a85d9  e82af9ffff             -call 0x4a7f08
    cpu.esp -= 4;
    sub_4a7f08(app, cpu);
    if (cpu.terminate) return;
    // 004a85de  e87dcdffff             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 004a85e3  e89cfaffff             -call 0x4a8084
    cpu.esp -= 4;
    sub_4a8084(app, cpu);
    if (cpu.terminate) return;
    // 004a85e8  89842478010000         -mov dword ptr [esp + 0x178], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(376) /* 0x178 */) = cpu.eax;
    // 004a85ef  8b84248c010000         -mov eax, dword ptr [esp + 0x18c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 004a85f6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a85f9  89842494010000         -mov dword ptr [esp + 0x194], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.eax;
L_0x004a8600:
    // 004a8600  8b84248c010000         -mov eax, dword ptr [esp + 0x18c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 004a8607  40                     -inc eax
    (cpu.eax)++;
    // 004a8608  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 004a860a  89842484010000         -mov dword ptr [esp + 0x184], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.eax;
    // 004a8611  80feff                 +cmp dh, 0xff
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8614  0f8489010000           -je 0x4a87a3
    if (cpu.flags.zf)
    {
        goto L_0x004a87a3;
    }
    // 004a861a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a861c  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 004a861e  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a8621  81fbfd000000           +cmp ebx, 0xfd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8627  7547                   -jne 0x4a8670
    if (!cpu.flags.zf)
    {
        goto L_0x004a8670;
    }
    // 004a8629  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a862b  89842488010000         -mov dword ptr [esp + 0x188], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.eax;
    // 004a8632  ebcc                   -jmp 0x4a8600
    goto L_0x004a8600;
L_0x004a8634:
    // 004a8634  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004a8639  eb21                   -jmp 0x4a865c
    goto L_0x004a865c;
L_0x004a863b:
    // 004a863b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a863d  7c18                   -jl 0x4a8657
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8657;
    }
    // 004a863f  83fd7f                 +cmp ebp, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8642  0f8e5affffff           -jle 0x4a85a2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a85a2;
    }
    // 004a8648  eb0d                   -jmp 0x4a8657
    goto L_0x004a8657;
L_0x004a864a:
    // 004a864a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a864c  7c09                   -jl 0x4a8657
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8657;
    }
    // 004a864e  83ff7f                 +cmp edi, 0x7f
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8651  0f8e59ffffff           -jle 0x4a85b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a85b0;
    }
L_0x004a8657:
    // 004a8657  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004a865c:
    // 004a865c  81c498010000           +add esp, 0x198
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(408 /*0x198*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8662  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8663  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8664  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8665  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8666  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8667  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8668:
    // 004a8668  8d7004                 -lea esi, [eax + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a866b  e954ffffff             -jmp 0x4a85c4
    goto L_0x004a85c4;
L_0x004a8670:
    // 004a8670  81fbfe000000           +cmp ebx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8676  0f85b1000000           -jne 0x4a872d
    if (!cpu.flags.zf)
    {
        goto L_0x004a872d;
    }
    // 004a867c  3bac249c000000         +cmp ebp, dword ptr [esp + 0x9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8683  7d14                   -jge 0x4a8699
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8699;
    }
L_0x004a8685:
    // 004a8685  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a8687  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004a868e  e875f8ffff             -call 0x4a7f08
    cpu.esp -= 4;
    sub_4a7f08(app, cpu);
    if (cpu.terminate) return;
    // 004a8693  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a8694  e967ffffff             -jmp 0x4a8600
    goto L_0x004a8600;
L_0x004a8699:
    // 004a8699  3bac24a0000000         +cmp ebp, dword ptr [esp + 0xa0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a86a0  7fe3                   -jg 0x4a8685
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8685;
    }
    // 004a86a2  3bbc24a4000000         +cmp edi, dword ptr [esp + 0xa4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a86a9  7cda                   -jl 0x4a8685
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8685;
    }
    // 004a86ab  3bbc24a8000000         +cmp edi, dword ptr [esp + 0xa8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a86b2  7fd1                   -jg 0x4a8685
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8685;
    }
    // 004a86b4  8b942474010000         -mov edx, dword ptr [esp + 0x174]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 004a86bb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a86bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a86bd  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a86c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a86c2  8d8c24a4000000         -lea ecx, [esp + 0xa4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004a86c9  8b9c2488010000         -mov ebx, dword ptr [esp + 0x188]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 004a86d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a86d1  8b942498010000         -mov edx, dword ptr [esp + 0x198]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 004a86d8  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 004a86df  e8e0f9ffff             -call 0x4a80c4
    cpu.esp -= 4;
    sub_4a80c4(app, cpu);
    if (cpu.terminate) return;
    // 004a86e4  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 004a86eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a86ed  0f8c3a010000           -jl 0x4a882d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a882d;
    }
    // 004a86f3  8b942494010000         -mov edx, dword ptr [esp + 0x194]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 004a86fa  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a86fd  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 004a8704  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 004a870b  898c2494010000         -mov dword ptr [esp + 0x194], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.ecx;
    // 004a8712  8984248c010000         -mov dword ptr [esp + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.eax;
    // 004a8719  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a871b  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004a8722  e8e1f7ffff             -call 0x4a7f08
    cpu.esp -= 4;
    sub_4a7f08(app, cpu);
    if (cpu.terminate) return;
    // 004a8727  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a8728  e9d3feffff             -jmp 0x4a8600
    goto L_0x004a8600;
L_0x004a872d:
    // 004a872d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a872f  81fbfc000000           +cmp ebx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8735  0f84c5feffff           -je 0x4a8600
    if (cpu.flags.zf)
    {
        goto L_0x004a8600;
    }
    // 004a873b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a873d  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a873f  81f9ff000000           +cmp ecx, 0xff
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
    // 004a8745  7514                   -jne 0x4a875b
    if (!cpu.flags.zf)
    {
        goto L_0x004a875b;
    }
    // 004a8747  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a874a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004a874f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a8751  e83af7ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004a8756  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a8758  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a875b:
    // 004a875b  46                     -inc esi
    (cpu.esi)++;
    // 004a875c  83fb26                 +cmp ebx, 0x26
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a875f  7c07                   -jl 0x4a8768
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8768;
    }
L_0x004a8761:
    // 004a8761  01ce                   +add esi, ecx
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
    // 004a8763  e998feffff             -jmp 0x4a8600
    goto L_0x004a8600;
L_0x004a8768:
    // 004a8768  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a876a  7cf5                   -jl 0x4a8761
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8761;
    }
    // 004a876c  83f904                 +cmp ecx, 4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a876f  7ff0                   -jg 0x4a8761
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8761;
    }
    // 004a8771  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a8773  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a8775  e816f7ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004a877a  89849c98000000         -mov dword ptr [esp + ebx*4 + 0x98], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */ + cpu.ebx * 4) = cpu.eax;
    // 004a8781  89349c                 -mov dword ptr [esp + ebx*4], esi
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 4) = cpu.esi;
    // 004a8784  83fb24                 +cmp ebx, 0x24
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8787  75d8                   -jne 0x4a8761
    if (!cpu.flags.zf)
    {
        goto L_0x004a8761;
    }
    // 004a8789  8b842428010000         -mov eax, dword ptr [esp + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004a8790  e8ebb60000             -call 0x4b3e80
    cpu.esp -= 4;
    sub_4b3e80(app, cpu);
    if (cpu.terminate) return;
    // 004a8795  89842474010000         -mov dword ptr [esp + 0x174], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */) = cpu.eax;
    // 004a879c  01ce                   +add esi, ecx
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
    // 004a879e  e95dfeffff             -jmp 0x4a8600
    goto L_0x004a8600;
L_0x004a87a3:
    // 004a87a3  3bac249c000000         +cmp ebp, dword ptr [esp + 0x9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a87aa  0f8c72000000           -jl 0x4a8822
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8822;
    }
    // 004a87b0  3bac24a0000000         +cmp ebp, dword ptr [esp + 0xa0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a87b7  7f69                   -jg 0x4a8822
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8822;
    }
    // 004a87b9  3bbc24a4000000         +cmp edi, dword ptr [esp + 0xa4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a87c0  7c60                   -jl 0x4a8822
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8822;
    }
    // 004a87c2  3bbc24a8000000         +cmp edi, dword ptr [esp + 0xa8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a87c9  7f57                   -jg 0x4a8822
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8822;
    }
    // 004a87cb  8bb42474010000         -mov esi, dword ptr [esp + 0x174]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 004a87d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a87d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a87d4  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a87d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a87d9  8d8c24a4000000         -lea ecx, [esp + 0xa4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004a87e0  8b9c2488010000         -mov ebx, dword ptr [esp + 0x188]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 004a87e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a87e8  8b942498010000         -mov edx, dword ptr [esp + 0x198]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 004a87ef  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 004a87f6  e8c9f8ffff             -call 0x4a80c4
    cpu.esp -= 4;
    sub_4a80c4(app, cpu);
    if (cpu.terminate) return;
    // 004a87fb  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 004a8802  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8804  7c27                   -jl 0x4a882d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a882d;
    }
    // 004a8806  8b942494010000         -mov edx, dword ptr [esp + 0x194]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 004a880d  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 004a8814  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 004a881b  8984248c010000         -mov dword ptr [esp + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.eax;
L_0x004a8822:
    // 004a8822  8bbc248c010000         -mov edi, dword ptr [esp + 0x18c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 004a8829  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a882b  7542                   -jne 0x4a886f
    if (!cpu.flags.zf)
    {
        goto L_0x004a886f;
    }
L_0x004a882d:
    // 004a882d  8b9c248c010000         -mov ebx, dword ptr [esp + 0x18c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 004a8834  e83bcbffff             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004a8839  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a883b  7e1f                   -jle 0x4a885c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a885c;
    }
    // 004a883d  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 004a8844  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a8846:
    // 004a8846  8b840c30010000         -mov eax, dword ptr [esp + ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.ecx * 1);
    // 004a884d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8850  e8eb0ffeff             -call 0x489840
    cpu.esp -= 4;
    sub_489840(app, cpu);
    if (cpu.terminate) return;
    // 004a8855  39d1                   +cmp ecx, edx
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
    // 004a8857  7ced                   -jl 0x4a8846
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8846;
    }
    // 004a8859  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a885c:
    // 004a885c  8b842470010000         -mov eax, dword ptr [esp + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004a8863  81c498010000           -add esp, 0x198
    (cpu.esp) += x86::reg32(x86::sreg32(408 /*0x198*/));
    // 004a8869  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a886a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a886b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a886c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a886d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a886e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a886f:
    // 004a886f  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8872  753f                   -jne 0x4a88b3
    if (!cpu.flags.zf)
    {
        goto L_0x004a88b3;
    }
    // 004a8874  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004a887b  e8ecceffff             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 004a8880  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8882  7c17                   -jl 0x4a889b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a889b;
    }
    // 004a8884  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8886  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a8889  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a888b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a888e  05b0bf5900             -add eax, 0x59bfb0
    (cpu.eax) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 004a8893  c6403b00               -mov byte ptr [eax + 0x3b], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */) = 0 /*0x0*/;
    // 004a8897  c6403a00               -mov byte ptr [eax + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
L_0x004a889b:
    // 004a889b  e8d4caffff             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004a88a0  8b842470010000         -mov eax, dword ptr [esp + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004a88a7  81c498010000           -add esp, 0x198
    (cpu.esp) += x86::reg32(x86::sreg32(408 /*0x198*/));
    // 004a88ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a88ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a88af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a88b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a88b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a88b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a88b3:
    // 004a88b3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a88b5  7e3f                   -jle 0x4a88f6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a88f6;
    }
    // 004a88b7  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 004a88be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a88c0:
    // 004a88c0  8b840c30010000         -mov eax, dword ptr [esp + ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.ecx * 1);
    // 004a88c7  e8a0ceffff             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 004a88cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a88ce  7c1f                   -jl 0x4a88ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a88ef;
    }
    // 004a88d0  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a88d3  bbb0bf5900             -mov ebx, 0x59bfb0
    cpu.ebx = 5881776 /*0x59bfb0*/;
    // 004a88d8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a88da  8a842478010000         -mov al, byte ptr [esp + 0x178]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(376) /* 0x178 */);
    // 004a88e1  c6433a00               -mov byte ptr [ebx + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
    // 004a88e5  899c2490010000         -mov dword ptr [esp + 0x190], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */) = cpu.ebx;
    // 004a88ec  88433b                 -mov byte ptr [ebx + 0x3b], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(59) /* 0x3b */) = cpu.al;
L_0x004a88ef:
    // 004a88ef  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a88f2  39d1                   +cmp ecx, edx
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
    // 004a88f4  7cca                   -jl 0x4a88c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a88c0;
    }
L_0x004a88f6:
    // 004a88f6  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 004a88fd  c6403a01               -mov byte ptr [eax + 0x3a], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 1 /*0x1*/;
    // 004a8901  eb98                   -jmp 0x4a889b
    goto L_0x004a889b;
}

/* align: skip 0x90 */
void Application::sub_4a8904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8904  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8905  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8906  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8909  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a890c  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a890e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a8910  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a8913  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a8918  6681fa5054             +cmp dx, 0x5450
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a891d  7552                   -jne 0x4a8971
    if (!cpu.flags.zf)
    {
        goto L_0x004a8971;
    }
    // 004a891f  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004a8922  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004a8925  7555                   -jne 0x4a897c
    if (!cpu.flags.zf)
    {
        goto L_0x004a897c;
    }
    // 004a8927  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8928  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8929  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004a892c  7452                   -je 0x4a8980
    if (cpu.flags.zf)
    {
        goto L_0x004a8980;
    }
    // 004a892e  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004a8931:
    // 004a8931  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a8933  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8935  7460                   -je 0x4a8997
    if (cpu.flags.zf)
    {
        goto L_0x004a8997;
    }
    // 004a8937  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 004a893a  81fefd000000           +cmp esi, 0xfd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8940  750e                   -jne 0x4a8950
    if (!cpu.flags.zf)
    {
        goto L_0x004a8950;
    }
    // 004a8942  41                     -inc ecx
    (cpu.ecx)++;
    // 004a8943  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a8945  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a8947  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8949  e86209feff             -call 0x4892b0
    cpu.esp -= 4;
    sub_4892b0(app, cpu);
    if (cpu.terminate) return;
    // 004a894e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004a8950:
    // 004a8950  41                     -inc ecx
    (cpu.ecx)++;
    // 004a8951  81fefe000000           +cmp esi, 0xfe
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8957  74d8                   -je 0x4a8931
    if (cpu.flags.zf)
    {
        goto L_0x004a8931;
    }
    // 004a8959  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a895f  74d0                   -je 0x4a8931
    if (cpu.flags.zf)
    {
        goto L_0x004a8931;
    }
    // 004a8961  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8963  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a8965  3dff000000             +cmp eax, 0xff
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
    // 004a896a  7419                   -je 0x4a8985
    if (cpu.flags.zf)
    {
        goto L_0x004a8985;
    }
L_0x004a896c:
    // 004a896c  41                     -inc ecx
    (cpu.ecx)++;
    // 004a896d  01c1                   +add ecx, eax
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
    // 004a896f  ebc0                   -jmp 0x4a8931
    goto L_0x004a8931;
L_0x004a8971:
    // 004a8971  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
L_0x004a8976:
    // 004a8976  83c404                 +add esp, 4
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
    // 004a8979  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a897a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a897b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a897c:
    // 004a897c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a897e  ebf6                   -jmp 0x4a8976
    goto L_0x004a8976;
L_0x004a8980:
    // 004a8980  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a8983  ebac                   -jmp 0x4a8931
    goto L_0x004a8931;
L_0x004a8985:
    // 004a8985  41                     -inc ecx
    (cpu.ecx)++;
    // 004a8986  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004a898b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a898d  e8fef4ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004a8992  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8995  ebd5                   -jmp 0x4a896c
    goto L_0x004a896c;
L_0x004a8997:
    // 004a8997  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8999  7c08                   -jl 0x4a89a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a89a3;
    }
    // 004a899b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a899f  80480301               -or byte ptr [eax + 3], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004a89a3:
    // 004a89a3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a89a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89a7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a89aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a89b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a89b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a89b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a89b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a89b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a89b4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a89b6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a89b8  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 004a89bc  7437                   -je 0x4a89f5
    if (cpu.flags.zf)
    {
        goto L_0x004a89f5;
    }
    // 004a89be  8d4f08                 -lea ecx, [edi + 8]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
L_0x004a89c1:
    // 004a89c1  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a89c3  80faff                 +cmp dl, 0xff
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a89c6  7450                   -je 0x4a8a18
    if (cpu.flags.zf)
    {
        goto L_0x004a8a18;
    }
    // 004a89c8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a89ca  88d3                   -mov bl, dl
    cpu.bl = cpu.dl;
    // 004a89cc  81fbfd000000           +cmp ebx, 0xfd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a89d2  7426                   -je 0x4a89fa
    if (cpu.flags.zf)
    {
        goto L_0x004a89fa;
    }
L_0x004a89d4:
    // 004a89d4  41                     -inc ecx
    (cpu.ecx)++;
    // 004a89d5  81fbfe000000           +cmp ebx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a89db  74e4                   -je 0x4a89c1
    if (cpu.flags.zf)
    {
        goto L_0x004a89c1;
    }
    // 004a89dd  81fbfc000000           +cmp ebx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a89e3  74dc                   -je 0x4a89c1
    if (cpu.flags.zf)
    {
        goto L_0x004a89c1;
    }
    // 004a89e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a89e7  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a89e9  3dff000000             +cmp eax, 0xff
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
    // 004a89ee  7416                   -je 0x4a8a06
    if (cpu.flags.zf)
    {
        goto L_0x004a8a06;
    }
L_0x004a89f0:
    // 004a89f0  41                     -inc ecx
    (cpu.ecx)++;
    // 004a89f1  01c1                   +add ecx, eax
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
    // 004a89f3  ebcc                   -jmp 0x4a89c1
    goto L_0x004a89c1;
L_0x004a89f5:
    // 004a89f5  8d4f04                 -lea ecx, [edi + 4]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a89f8  ebc7                   -jmp 0x4a89c1
    goto L_0x004a89c1;
L_0x004a89fa:
    // 004a89fa  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a89fb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a89fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a89ff  e82c01feff             -call 0x488b30
    cpu.esp -= 4;
    sub_488b30(app, cpu);
    if (cpu.terminate) return;
    // 004a8a04  ebce                   -jmp 0x4a89d4
    goto L_0x004a89d4;
L_0x004a8a06:
    // 004a8a06  41                     -inc ecx
    (cpu.ecx)++;
    // 004a8a07  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004a8a0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8a0e  e87df4ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004a8a13  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8a16  ebd8                   -jmp 0x4a89f0
    goto L_0x004a89f0;
L_0x004a8a18:
    // 004a8a18  8a7703                 -mov dh, byte ptr [edi + 3]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004a8a1b  80e6fe                 -and dh, 0xfe
    cpu.dh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a8a1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8a20  887703                 -mov byte ptr [edi + 3], dh
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.dh;
    // 004a8a23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8a30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8a31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8a32  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a8a34  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a8a36  e815f30000             -call 0x4b7d50
    cpu.esp -= 4;
    sub_4b7d50(app, cpu);
    if (cpu.terminate) return;
    // 004a8a3b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a8a3d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8a3f  7c09                   -jl 0x4a8a4a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8a4a;
    }
    // 004a8a41  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a8a43  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8a45  7c11                   -jl 0x4a8a58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8a58;
    }
    // 004a8a47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8a4a:
    // 004a8a4a  6bc2ff                 -imul eax, edx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004a8a4d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a8a4f  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a8a51  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8a53  7c03                   -jl 0x4a8a58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8a58;
    }
    // 004a8a55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8a58:
    // 004a8a58  6bc3ff                 -imul eax, ebx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004a8a5b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a8a5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8a60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8a61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8a62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8a63  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8a66  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8a6a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a8a6d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a8a6f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a8a71  e8daf20000             -call 0x4b7d50
    cpu.esp -= 4;
    sub_4b7d50(app, cpu);
    if (cpu.terminate) return;
    // 004a8a76  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8a7a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8a7c  0f8c93000000           -jl 0x4a8b15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8b15;
    }
L_0x004a8a82:
    // 004a8a82  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8a86  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a8a88  0f8ca1000000           -jl 0x4a8b2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8b2f;
    }
    // 004a8a8e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a8a90  0f8c99000000           -jl 0x4a8b2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8b2f;
    }
    // 004a8a96  39cd                   +cmp ebp, ecx
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
    // 004a8a98  0f8e87000000           -jle 0x4a8b25
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8b25;
    }
L_0x004a8a9e:
    // 004a8a9e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004a8aa3:
    // 004a8aa3  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a8aa6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8aa8  81f900400000           +cmp ecx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8aae  0f8cc5000000           -jl 0x4a8b79
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8b79;
    }
    // 004a8ab4  81f900c00000           +cmp ecx, 0xc000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49152 /*0xc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8aba  0f8db9000000           -jge 0x4a8b79
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8b79;
    }
    // 004a8ac0  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a8ac2  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8ac4  0f8da5000000           -jge 0x4a8b6f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8b6f;
    }
    // 004a8aca  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
L_0x004a8acf:
    // 004a8acf  83f802                 +cmp eax, 2
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
    // 004a8ad2  7f13                   -jg 0x4a8ae7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8ae7;
    }
    // 004a8ad4  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004a8ad9  83f903                 +cmp ecx, 3
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
    // 004a8adc  7509                   -jne 0x4a8ae7
    if (!cpu.flags.zf)
    {
        goto L_0x004a8ae7;
    }
    // 004a8ade  39d0                   +cmp eax, edx
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
L_0x004a8ae0:
    // 004a8ae0  7505                   -jne 0x4a8ae7
    if (!cpu.flags.zf)
    {
        goto L_0x004a8ae7;
    }
    // 004a8ae2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a8ae7:
    // 004a8ae7  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 004a8aec  0f8cb7000000           -jl 0x4a8ba9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8ba9;
    }
L_0x004a8af2:
    // 004a8af2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a8af4  0f8cbb000000           -jl 0x4a8bb5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8bb5;
    }
L_0x004a8afa:
    // 004a8afa  83fa01                 +cmp edx, 1
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
    // 004a8afd  0f84be000000           -je 0x4a8bc1
    if (cpu.flags.zf)
    {
        goto L_0x004a8bc1;
    }
    // 004a8b03  83fa02                 +cmp edx, 2
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
    // 004a8b06  0f84c5000000           -je 0x4a8bd1
    if (cpu.flags.zf)
    {
        goto L_0x004a8bd1;
    }
    // 004a8b0c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8b0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b12  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a8b15:
    // 004a8b15  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a8b17  0f8d65ffffff           -jge 0x4a8a82
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8a82;
    }
    // 004a8b1d  39d5                   +cmp ebp, edx
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
    // 004a8b1f  0f8e79ffffff           -jle 0x4a8a9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8a9e;
    }
L_0x004a8b25:
    // 004a8b25  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a8b2a  e974ffffff             -jmp 0x4a8aa3
    goto L_0x004a8aa3;
L_0x004a8b2f:
    // 004a8b2f  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8b33  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8b35  7e16                   -jle 0x4a8b4d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8b4d;
    }
    // 004a8b37  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a8b39:
    // 004a8b39  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a8b3b  7e16                   -jle 0x4a8b53
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8b53;
    }
    // 004a8b3d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a8b3f  39d0                   +cmp eax, edx
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
    // 004a8b41  7e22                   -jle 0x4a8b65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8b65;
    }
    // 004a8b43  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a8b48  e956ffffff             -jmp 0x4a8aa3
    goto L_0x004a8aa3;
L_0x004a8b4d:
    // 004a8b4d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8b4f  f7d8                   +neg eax
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
    // 004a8b51  ebe6                   -jmp 0x4a8b39
    goto L_0x004a8b39;
L_0x004a8b53:
    // 004a8b53  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a8b55  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004a8b57  39d0                   +cmp eax, edx
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
    // 004a8b59  7e0a                   -jle 0x4a8b65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8b65;
    }
    // 004a8b5b  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a8b60  e93effffff             -jmp 0x4a8aa3
    goto L_0x004a8aa3;
L_0x004a8b65:
    // 004a8b65  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004a8b6a  e934ffffff             -jmp 0x4a8aa3
    goto L_0x004a8aa3;
L_0x004a8b6f:
    // 004a8b6f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004a8b74  e956ffffff             -jmp 0x4a8acf
    goto L_0x004a8acf;
L_0x004a8b79:
    // 004a8b79  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a8b7b  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8b7d  7d23                   -jge 0x4a8ba2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8ba2;
    }
    // 004a8b7f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x004a8b84:
    // 004a8b84  83f803                 +cmp eax, 3
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
    // 004a8b87  0f8c5affffff           -jl 0x4a8ae7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8ae7;
    }
    // 004a8b8d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004a8b92  39d1                   +cmp ecx, edx
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
    // 004a8b94  0f854dffffff           -jne 0x4a8ae7
    if (!cpu.flags.zf)
    {
        goto L_0x004a8ae7;
    }
    // 004a8b9a  83f803                 +cmp eax, 3
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
    // 004a8b9d  e93effffff             -jmp 0x4a8ae0
    goto L_0x004a8ae0;
L_0x004a8ba2:
    // 004a8ba2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a8ba7  ebdb                   -jmp 0x4a8b84
    goto L_0x004a8b84;
L_0x004a8ba9:
    // 004a8ba9  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a8bab  6bc1ff                 +imul eax, ecx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004a8bae  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a8bb0  e93dffffff             -jmp 0x4a8af2
    goto L_0x004a8af2;
L_0x004a8bb5:
    // 004a8bb5  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a8bb7  6bc3ff                 +imul eax, ebx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004a8bba  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a8bbc  e939ffffff             -jmp 0x4a8afa
    goto L_0x004a8afa;
L_0x004a8bc1:
    // 004a8bc1  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 004a8bc3  6bc5ff                 -imul eax, ebp, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004a8bc6  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a8bc8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8bcb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bce  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a8bd1:
    // 004a8bd1  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004a8bd3  6bc7ff                 -imul eax, edi, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004a8bd6  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a8bd8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8bdb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bdd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bde  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8bf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8bf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8bf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8bf3  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004a8bfa  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8bfc  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 004a8bff  81c1b0bf5900           -add ecx, 0x59bfb0
    (cpu.ecx) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 004a8c05  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a8c08  8b512d                 -mov edx, dword ptr [ecx + 0x2d]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(45) /* 0x2d */);
    // 004a8c0b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a8c0e  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a8c11  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a8c14  8b5128                 -mov edx, dword ptr [ecx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004a8c17  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a8c1a  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a8c1d  8b150ac65900           -mov edx, dword ptr [0x59c60a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5883402) /* 0x59c60a */);
    // 004a8c23  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a8c26  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a8c29  bb7f411f00             -mov ebx, 0x1f417f
    cpu.ebx = 2048383 /*0x1f417f*/;
    // 004a8c2e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a8c30  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a8c33  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a8c35  8b5158                 -mov edx, dword ptr [ecx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 004a8c38  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 004a8c3b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8c3d  750b                   -jne 0x4a8c4a
    if (!cpu.flags.zf)
    {
        goto L_0x004a8c4a;
    }
    // 004a8c3f  8b594c                 -mov ebx, dword ptr [ecx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 004a8c42  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8c44  7533                   -jne 0x4a8c79
    if (!cpu.flags.zf)
    {
        goto L_0x004a8c79;
    }
    // 004a8c46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8c4a:
    // 004a8c4a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8c4c  8b4158                 -mov eax, dword ptr [ecx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 004a8c4f  8a513e                 -mov dl, byte ptr [ecx + 0x3e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 004a8c52  0fbe1402               -movsx edx, byte ptr [edx + eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1)));
    // 004a8c56  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004a8c59  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a8c5c  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a8c5f  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 004a8c64  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a8c66  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a8c69  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a8c6b  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 004a8c6e  8b594c                 -mov ebx, dword ptr [ecx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 004a8c71  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8c73  7504                   -jne 0x4a8c79
    if (!cpu.flags.zf)
    {
        goto L_0x004a8c79;
    }
    // 004a8c75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8c79:
    // 004a8c79  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004a8c7c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a8c7e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a8c81  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004a8c84  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 004a8c87  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a8c8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8c8c  a33ceb4d00             -mov dword ptr [0x4deb3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */) = cpu.eax;
    // 004a8c91  891538eb4d00           -mov dword ptr [0x4deb38], edx
    app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */) = cpu.edx;
    // 004a8c97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8c98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8c98  a334eb4d00             -mov dword ptr [0x4deb34], eax
    app->getMemory<x86::reg32>(x86::reg32(5106484) /* 0x4deb34 */) = cpu.eax;
    // 004a8c9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8c9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8c9e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8c9f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8ca0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8ca1  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8ca5  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8ca9  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8cad  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a8cb3  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a8cb9  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a8cbf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8cc1  803d5cb24d0008         +cmp byte ptr [0x4db25c], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8cc8  7f61                   -jg 0x4a8d2b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8d2b;
    }
    // 004a8cca  83e904                 +sub ecx, 4
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
    // 004a8ccd  783d                   -js 0x4a8d0c
    if (cpu.flags.sf)
    {
        goto L_0x004a8d0c;
    }
L_0x004a8ccf:
    // 004a8ccf  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8cd1  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8cd4  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8cd7  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8cd9  7402                   -je 0x4a8cdd
    if (cpu.flags.zf)
    {
        goto L_0x004a8cdd;
    }
    // 004a8cdb  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a8cdd:
    // 004a8cdd  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8ce0  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a8ce3  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8ce5  7403                   -je 0x4a8cea
    if (cpu.flags.zf)
    {
        goto L_0x004a8cea;
    }
    // 004a8ce7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
L_0x004a8cea:
    // 004a8cea  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8ced  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a8cf0  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8cf2  7403                   -je 0x4a8cf7
    if (cpu.flags.zf)
    {
        goto L_0x004a8cf7;
    }
    // 004a8cf4  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
L_0x004a8cf7:
    // 004a8cf7  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8cfa  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8cfc  7403                   -je 0x4a8d01
    if (cpu.flags.zf)
    {
        goto L_0x004a8d01;
    }
    // 004a8cfe  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
L_0x004a8d01:
    // 004a8d01  83e904                 +sub ecx, 4
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
    // 004a8d04  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a8d07  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a8d0a  79c3                   -jns 0x4a8ccf
    if (!cpu.flags.sf)
    {
        goto L_0x004a8ccf;
    }
L_0x004a8d0c:
    // 004a8d0c  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8d0f  7816                   -js 0x4a8d27
    if (cpu.flags.sf)
    {
        goto L_0x004a8d27;
    }
L_0x004a8d11:
    // 004a8d11  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8d13  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8d16  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8d18  7402                   -je 0x4a8d1c
    if (cpu.flags.zf)
    {
        goto L_0x004a8d1c;
    }
    // 004a8d1a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a8d1c:
    // 004a8d1c  83e901                 +sub ecx, 1
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
    // 004a8d1f  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8d22  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a8d25  79ea                   -jns 0x4a8d11
    if (!cpu.flags.sf)
    {
        goto L_0x004a8d11;
    }
L_0x004a8d27:
    // 004a8d27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8d2b:
    // 004a8d2b  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8d2d  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8d34  7f21                   -jg 0x4a8d57
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8d57;
    }
    // 004a8d36  83e901                 +sub ecx, 1
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
    // 004a8d39  78ec                   -js 0x4a8d27
    if (cpu.flags.sf)
    {
        goto L_0x004a8d27;
    }
L_0x004a8d3b:
    // 004a8d3b  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a8d3f  6609c0                 +or ax, ax
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(cpu.ax))));
    // 004a8d42  7403                   -je 0x4a8d47
    if (cpu.flags.zf)
    {
        goto L_0x004a8d47;
    }
    // 004a8d44  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
L_0x004a8d47:
    // 004a8d47  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8d4a  83e901                 +sub ecx, 1
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
    // 004a8d4d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8d50  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a8d53  79e6                   -jns 0x4a8d3b
    if (!cpu.flags.sf)
    {
        goto L_0x004a8d3b;
    }
    // 004a8d55  ebd0                   -jmp 0x4a8d27
    goto L_0x004a8d27;
L_0x004a8d57:
    // 004a8d57  83e901                 +sub ecx, 1
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
    // 004a8d5a  78cb                   -js 0x4a8d27
    if (cpu.flags.sf)
    {
        goto L_0x004a8d27;
    }
L_0x004a8d5c:
    // 004a8d5c  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a8d5f  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a8d61  7402                   -je 0x4a8d65
    if (cpu.flags.zf)
    {
        goto L_0x004a8d65;
    }
    // 004a8d63  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x004a8d65:
    // 004a8d65  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8d68  83e901                 +sub ecx, 1
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
    // 004a8d6b  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8d6e  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a8d71  79e9                   -jns 0x4a8d5c
    if (!cpu.flags.sf)
    {
        goto L_0x004a8d5c;
    }
    // 004a8d73  ebb2                   -jmp 0x4a8d27
    goto L_0x004a8d27;
}

/* align: skip  */
void Application::sub_4a8d75(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8d75  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8d76  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8d77  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8d78  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8d7c  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8d80  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8d84  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a8d8a  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a8d90  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a8d96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8d98  83e904                 +sub ecx, 4
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
    // 004a8d9b  7855                   -js 0x4a8df2
    if (cpu.flags.sf)
    {
        goto L_0x004a8df2;
    }
L_0x004a8d9d:
    // 004a8d9d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8d9f  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8da2  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8da5  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004a8dab  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8dad  7402                   -je 0x4a8db1
    if (cpu.flags.zf)
    {
        goto L_0x004a8db1;
    }
    // 004a8daf  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a8db1:
    // 004a8db1  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8db4  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a8db7  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004a8dbd  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8dbf  7403                   -je 0x4a8dc4
    if (cpu.flags.zf)
    {
        goto L_0x004a8dc4;
    }
    // 004a8dc1  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
L_0x004a8dc4:
    // 004a8dc4  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8dc7  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a8dca  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004a8dd0  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8dd2  7403                   -je 0x4a8dd7
    if (cpu.flags.zf)
    {
        goto L_0x004a8dd7;
    }
    // 004a8dd4  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
L_0x004a8dd7:
    // 004a8dd7  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8dda  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004a8de0  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8de2  7403                   -je 0x4a8de7
    if (cpu.flags.zf)
    {
        goto L_0x004a8de7;
    }
    // 004a8de4  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
L_0x004a8de7:
    // 004a8de7  83e904                 +sub ecx, 4
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
    // 004a8dea  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a8ded  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a8df0  79ab                   -jns 0x4a8d9d
    if (!cpu.flags.sf)
    {
        goto L_0x004a8d9d;
    }
L_0x004a8df2:
    // 004a8df2  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8df5  781c                   -js 0x4a8e13
    if (cpu.flags.sf)
    {
        goto L_0x004a8e13;
    }
L_0x004a8df7:
    // 004a8df7  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8df9  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8dfc  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004a8e02  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8e04  7402                   -je 0x4a8e08
    if (cpu.flags.zf)
    {
        goto L_0x004a8e08;
    }
    // 004a8e06  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a8e08:
    // 004a8e08  83e901                 +sub ecx, 1
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
    // 004a8e0b  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8e0e  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a8e11  79e4                   -jns 0x4a8df7
    if (!cpu.flags.sf)
    {
        goto L_0x004a8df7;
    }
L_0x004a8e13:
    // 004a8e13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e15  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8e17(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8e17  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8e18  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a8e1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8e1b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8e1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8e1d  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8e20  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8e23  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a8e26  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a8e2c  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a8e32  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a8e38  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a8e3a:
    // 004a8e3a  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8e3c  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8e3f  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004a8e45  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8e48  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a8e4a  83e901                 +sub ecx, 1
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
    // 004a8e4d  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a8e50  75e8                   -jne 0x4a8e3a
    if (!cpu.flags.zf)
    {
        goto L_0x004a8e3a;
    }
    // 004a8e52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e54  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8e57(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8e57  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8e58  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a8e5a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8e5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8e5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8e5d  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8e60  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8e63  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a8e66  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a8e6c  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a8e72  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a8e78  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a8e7a:
    // 004a8e7a  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8e7c  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8e7f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8e82  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8e84  720a                   -jb 0x4a8e90
    if (cpu.flags.cf)
    {
        goto L_0x004a8e90;
    }
    // 004a8e86  750a                   -jne 0x4a8e92
    if (!cpu.flags.zf)
    {
        goto L_0x004a8e92;
    }
    // 004a8e88  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a8e8a  8a80ac054e00           -mov al, byte ptr [eax + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004a8e90:
    // 004a8e90  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a8e92:
    // 004a8e92  83e901                 +sub ecx, 1
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
    // 004a8e95  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a8e98  75e0                   -jne 0x4a8e7a
    if (!cpu.flags.zf)
    {
        goto L_0x004a8e7a;
    }
    // 004a8e9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8e9f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8e9f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8ea0  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a8ea2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8ea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8ea4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8ea5  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8ea8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8eab  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a8eae  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a8eb4  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a8eba  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a8ec0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a8ec2:
    // 004a8ec2  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8ec4  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8ec7  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004a8ecd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8ed0  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8ed2  720a                   -jb 0x4a8ede
    if (cpu.flags.cf)
    {
        goto L_0x004a8ede;
    }
    // 004a8ed4  750a                   -jne 0x4a8ee0
    if (!cpu.flags.zf)
    {
        goto L_0x004a8ee0;
    }
    // 004a8ed6  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a8ed8  8a80ac054e00           -mov al, byte ptr [eax + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004a8ede:
    // 004a8ede  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a8ee0:
    // 004a8ee0  83e901                 +sub ecx, 1
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
    // 004a8ee3  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a8ee6  75da                   -jne 0x4a8ec2
    if (!cpu.flags.zf)
    {
        goto L_0x004a8ec2;
    }
    // 004a8ee8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ee9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8eea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8eeb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8eec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8eed(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8eed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8eee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8eef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8ef0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8ef1  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8ef5  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8ef9  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a8efd  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a8f03  032d60b24d00           -add ebp, dword ptr [0x4db260]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a8f09  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a8f0f  8b3d34eb4d00           -mov edi, dword ptr [0x4deb34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5106484) /* 0x4deb34 */);
    // 004a8f15  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8f17  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8f1a  782e                   -js 0x4a8f4a
    if (cpu.flags.sf)
    {
        goto L_0x004a8f4a;
    }
L_0x004a8f1c:
    // 004a8f1c  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8f1e  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8f21  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004a8f24  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004a8f27  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 004a8f2a  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004a8f2d  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8f30  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8f33  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004a8f36  8a4501                 -mov al, byte ptr [ebp + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004a8f39  8a0418                 -mov al, byte ptr [eax + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 004a8f3c  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a8f3f  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8f42  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a8f45  8d6d02                 -lea ebp, [ebp + 2]
    cpu.ebp = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004a8f48  79d2                   -jns 0x4a8f1c
    if (!cpu.flags.sf)
    {
        goto L_0x004a8f1c;
    }
L_0x004a8f4a:
    // 004a8f4a  83c101                 +add ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8f4d  7811                   -js 0x4a8f60
    if (cpu.flags.sf)
    {
        goto L_0x004a8f60;
    }
    // 004a8f4f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8f51  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a8f54  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004a8f57  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004a8f5a  8a0418                 -mov al, byte ptr [eax + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 004a8f5d  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
L_0x004a8f60:
    // 004a8f60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8f65(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8f65  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8f66  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8f67  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8f68  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8f69  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8f6d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8f71  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a8f75  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a8f7b  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a8f81  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a8f87  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a8f8a  803d5cb24d0008         +cmp byte ptr [0x4db25c], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8f91  0f8f26010000           -jg 0x4a90bd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a90bd;
    }
    // 004a8f97  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8f9a  0f8c99000000           -jl 0x4a9039
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9039;
    }
    // 004a8fa0  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a8fa6  0f85e2000000           -jne 0x4a908e
    if (!cpu.flags.zf)
    {
        goto L_0x004a908e;
    }
L_0x004a8fac:
    // 004a8fac  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a8faf  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a8fb2  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a8fb5  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a8fb9  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8fbc  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a8fbe  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a8fc1  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a8fc4  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a8fc8  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a8fcb  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a8fcd  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a8fd0  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a8fd3  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a8fd7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8fda  8b6a10                 -mov ebp, dword ptr [edx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a8fdd  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a8fe0  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004a8fe3  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a8fe7  8b6a28                 -mov ebp, dword ptr [edx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 004a8fea  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a8fed  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a8ff0  8b5a24                 -mov ebx, dword ptr [edx + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004a8ff3  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a8ff7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8ffa  8b6a20                 -mov ebp, dword ptr [edx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a8ffd  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9000  8b5a3c                 -mov ebx, dword ptr [edx + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 004a9003  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a9007  8b6a38                 -mov ebp, dword ptr [edx + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 004a900a  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a900d  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9010  8b5a34                 -mov ebx, dword ptr [edx + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 004a9013  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a9017  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a901a  8b6a30                 -mov ebp, dword ptr [edx + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004a901d  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9020  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 004a9023  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a9027  8d5240                 -lea edx, [edx + 0x40]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004a902a  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a902d  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9030  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a9033  0f8973ffffff           -jns 0x4a8fac
    if (!cpu.flags.sf)
    {
        goto L_0x004a8fac;
    }
L_0x004a9039:
    // 004a9039  83c10c                 +add ecx, 0xc
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
    // 004a903c  7831                   -js 0x4a906f
    if (cpu.flags.sf)
    {
        goto L_0x004a906f;
    }
    // 004a903e  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a9044  7529                   -jne 0x4a906f
    if (!cpu.flags.zf)
    {
        goto L_0x004a906f;
    }
L_0x004a9046:
    // 004a9046  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9049  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a904c  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a904f  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a9053  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a9056  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a9058  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a905b  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a905e  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a9062  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a9065  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a9067  83e904                 +sub ecx, 4
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
    // 004a906a  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a906d  79d7                   -jns 0x4a9046
    if (!cpu.flags.sf)
    {
        goto L_0x004a9046;
    }
L_0x004a906f:
    // 004a906f  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9072  7815                   -js 0x4a9089
    if (cpu.flags.sf)
    {
        goto L_0x004a9089;
    }
    // 004a9074  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004a9076:
    // 004a9076  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9079  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a907c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a907e  83e901                 +sub ecx, 1
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
    // 004a9081  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9084  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a9087  79ed                   -jns 0x4a9076
    if (!cpu.flags.sf)
    {
        goto L_0x004a9076;
    }
L_0x004a9089:
    // 004a9089  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a908a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a908b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a908c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a908d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a908e:
    // 004a908e  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a9091  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004a9093:
    // 004a9093  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9096  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9099  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a909b  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a909e  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a90a1  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a90a7  8d49ff                 -lea ecx, [ecx - 1]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004a90aa  75e7                   -jne 0x4a9093
    if (!cpu.flags.zf)
    {
        goto L_0x004a9093;
    }
    // 004a90ac  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a90af  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a90b2  0f89f4feffff           -jns 0x4a8fac
    if (!cpu.flags.sf)
    {
        goto L_0x004a8fac;
    }
    // 004a90b8  e97cffffff             -jmp 0x4a9039
    goto L_0x004a9039;
L_0x004a90bd:
    // 004a90bd  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a90bf  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a90c6  7f1c                   -jg 0x4a90e4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a90e4;
    }
    // 004a90c8  83e901                 +sub ecx, 1
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
    // 004a90cb  78bc                   -js 0x4a9089
    if (cpu.flags.sf)
    {
        goto L_0x004a9089;
    }
L_0x004a90cd:
    // 004a90cd  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a90d1  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a90d4  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a90d7  83e901                 +sub ecx, 1
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
    // 004a90da  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a90dd  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a90e0  79eb                   -jns 0x4a90cd
    if (!cpu.flags.sf)
    {
        goto L_0x004a90cd;
    }
    // 004a90e2  eba5                   -jmp 0x4a9089
    goto L_0x004a9089;
L_0x004a90e4:
    // 004a90e4  83e901                 +sub ecx, 1
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
    // 004a90e7  78a0                   -js 0x4a9089
    if (cpu.flags.sf)
    {
        goto L_0x004a9089;
    }
L_0x004a90e9:
    // 004a90e9  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a90ec  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a90ef  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a90f1  83e901                 +sub ecx, 1
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
    // 004a90f4  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a90f7  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a90fa  79ed                   -jns 0x4a90e9
    if (!cpu.flags.sf)
    {
        goto L_0x004a90e9;
    }
    // 004a90fc  eb8b                   -jmp 0x4a9089
    goto L_0x004a9089;
}

/* align: skip  */
void Application::sub_4a90fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a90fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a90ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9100  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9101  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9102  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9106  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a910a  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a910e  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a9114  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a911a  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a9120  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a9122  83ed01                 +sub ebp, 1
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
    // 004a9125  7820                   -js 0x4a9147
    if (cpu.flags.sf)
    {
        goto L_0x004a9147;
    }
    // 004a9127  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9129  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a912b:
    // 004a912b  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a912e  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9131  668b0c453cef5600       -mov cx, word ptr [eax*2 + 0x56ef3c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.eax * 2);
    // 004a9139  83ed01                 +sub ebp, 1
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
    // 004a913c  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004a913f  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9142  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a9145  79e4                   -jns 0x4a912b
    if (!cpu.flags.sf)
    {
        goto L_0x004a912b;
    }
L_0x004a9147:
    // 004a9147  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9148  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9149  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a914a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a914b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a914c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a914c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a914d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a914e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a914f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9150  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9154  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a9158  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a915c  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a9162  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a9168  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a916e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a9170  83ed01                 +sub ebp, 1
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
    // 004a9173  7822                   -js 0x4a9197
    if (cpu.flags.sf)
    {
        goto L_0x004a9197;
    }
    // 004a9175  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a9177:
    // 004a9177  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a917a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a917d  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a917f  740b                   -je 0x4a918c
    if (cpu.flags.zf)
    {
        goto L_0x004a918c;
    }
    // 004a9181  668b0c453cef5600       -mov cx, word ptr [eax*2 + 0x56ef3c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.eax * 2);
    // 004a9189  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
L_0x004a918c:
    // 004a918c  83ed01                 +sub ebp, 1
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
    // 004a918f  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9192  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a9195  79e0                   -jns 0x4a9177
    if (!cpu.flags.sf)
    {
        goto L_0x004a9177;
    }
L_0x004a9197:
    // 004a9197  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9198  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9199  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a919a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a919b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a919c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a919c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a919d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a919e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a919f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a91a0  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a91a4  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a91a8  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a91ac  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a91b2  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a91b8  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a91be  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a91c0  83ed01                 +sub ebp, 1
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
    // 004a91c3  7822                   -js 0x4a91e7
    if (cpu.flags.sf)
    {
        goto L_0x004a91e7;
    }
    // 004a91c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a91c7:
    // 004a91c7  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a91ca  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a91cd  3cfd                   +cmp al, 0xfd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(253 /*0xfd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a91cf  731b                   -jae 0x4a91ec
    if (!cpu.flags.cf)
    {
        goto L_0x004a91ec;
    }
    // 004a91d1  668b0c453cef5600       -mov cx, word ptr [eax*2 + 0x56ef3c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.eax * 2);
    // 004a91d9  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004a91dc  83ed01                 +sub ebp, 1
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
    // 004a91df  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a91e2  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a91e5  79e0                   -jns 0x4a91c7
    if (!cpu.flags.sf)
    {
        goto L_0x004a91c7;
    }
L_0x004a91e7:
    // 004a91e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a91ec:
    // 004a91ec  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a91ee  7435                   -je 0x4a9225
    if (cpu.flags.zf)
    {
        goto L_0x004a9225;
    }
    // 004a91f0  3cfd                   +cmp al, 0xfd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(253 /*0xfd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a91f2  740d                   -je 0x4a9201
    if (cpu.flags.zf)
    {
        goto L_0x004a9201;
    }
    // 004a91f4  83ed01                 +sub ebp, 1
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
    // 004a91f7  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a91fa  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a91fd  79c8                   -jns 0x4a91c7
    if (!cpu.flags.sf)
    {
        goto L_0x004a91c7;
    }
    // 004a91ff  ebe6                   -jmp 0x4a91e7
    goto L_0x004a91e7;
L_0x004a9201:
    // 004a9201  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 004a9204  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 004a9207  66c1e902               -shr cx, 2
    cpu.cx >>= 2 /*0x2*/ % 32;
    // 004a920b  6681e1e739             -and cx, 0x39e7
    cpu.cx &= x86::reg16(x86::sreg16(14823 /*0x39e7*/));
    // 004a9210  6629c8                 -sub ax, cx
    (cpu.ax) -= x86::reg16(x86::sreg16(cpu.cx));
    // 004a9213  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a9216  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9218  83ed01                 +sub ebp, 1
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
    // 004a921b  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a921e  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a9221  79a4                   -jns 0x4a91c7
    if (!cpu.flags.sf)
    {
        goto L_0x004a91c7;
    }
    // 004a9223  ebc2                   -jmp 0x4a91e7
    goto L_0x004a91e7;
L_0x004a9225:
    // 004a9225  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 004a9228  66d1e9                 -shr cx, 1
    cpu.cx >>= 1 /*0x1*/ % 32;
    // 004a922b  6681e1ef7b             -and cx, 0x7bef
    cpu.cx &= x86::reg16(x86::sreg16(31727 /*0x7bef*/));
    // 004a9230  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004a9233  83ed01                 +sub ebp, 1
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
    // 004a9236  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9239  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a923c  7989                   -jns 0x4a91c7
    if (!cpu.flags.sf)
    {
        goto L_0x004a91c7;
    }
    // 004a923e  eba7                   -jmp 0x4a91e7
    goto L_0x004a91e7;
}

/* align: skip  */
void Application::sub_4a9240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9241  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9242  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9243  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9244  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9248  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a924c  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a9252  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a9258  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a925e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a9260  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9262  803d5cb24d0008         +cmp byte ptr [0x4db25c], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9269  0f8f32010000           -jg 0x4a93a1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a93a1;
    }
    // 004a926f  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004a9275  7421                   -je 0x4a9298
    if (cpu.flags.zf)
    {
        goto L_0x004a9298;
    }
L_0x004a9277:
    // 004a9277  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a927a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a927d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a927f  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9284  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9287  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a928a  0f880c010000           -js 0x4a939c
    if (cpu.flags.sf)
    {
        goto L_0x004a939c;
    }
    // 004a9290  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004a9296  75df                   -jne 0x4a9277
    if (!cpu.flags.zf)
    {
        goto L_0x004a9277;
    }
L_0x004a9298:
    // 004a9298  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a929d  0f8c8d000000           -jl 0x4a9330
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9330;
    }
L_0x004a92a3:
    // 004a92a3  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a92a6  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a92a9  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a92ac  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a92af  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a92b2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a92b5  0f73f008               -psllq mm0, 8
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 8 /*0x8*/) };
    // 004a92b9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a92bc  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a92bf  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a92c2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a92c5  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a92c9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a92cc  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a92cf  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a92d2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a92d5  0f73f018               -psllq mm0, 0x18
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 24 /*0x18*/) };
    // 004a92d9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a92dc  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a92df  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a92e2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a92e5  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 004a92e9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a92ec  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a92ef  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a92f2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a92f5  0f73f028               -psllq mm0, 0x28
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 40 /*0x28*/) };
    // 004a92f9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a92fc  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a92ff  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a9302  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9305  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 004a9309  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a930c  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a930f  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a9312  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9315  0f73f038               -psllq mm0, 0x38
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 56 /*0x38*/) };
    // 004a9319  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a931c  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 004a931f  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9324  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a9327  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a932a  0f8973ffffff           -jns 0x4a92a3
    if (!cpu.flags.sf)
    {
        goto L_0x004a92a3;
    }
L_0x004a9330:
    // 004a9330  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9335  7849                   -js 0x4a9380
    if (cpu.flags.sf)
    {
        goto L_0x004a9380;
    }
L_0x004a9337:
    // 004a9337  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a933a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a933d  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9340  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9343  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9346  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9349  0f73f008               -psllq mm0, 8
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 8 /*0x8*/) };
    // 004a934d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a9350  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9353  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a9356  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9359  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a935d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a9360  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9363  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a9366  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9369  0f73f018               -psllq mm0, 0x18
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 24 /*0x18*/) };
    // 004a936d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a9370  0f7e0f                 -movd dword ptr [edi], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm1);
    // 004a9373  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9378  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a937b  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a937e  79b7                   -jns 0x4a9337
    if (!cpu.flags.sf)
    {
        goto L_0x004a9337;
    }
L_0x004a9380:
    // 004a9380  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9385  7815                   -js 0x4a939c
    if (cpu.flags.sf)
    {
        goto L_0x004a939c;
    }
L_0x004a9387:
    // 004a9387  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a938a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a938d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a938f  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9394  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9397  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a939a  79eb                   -jns 0x4a9387
    if (!cpu.flags.sf)
    {
        goto L_0x004a9387;
    }
L_0x004a939c:
    // 004a939c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a939d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a939e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a939f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a93a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a93a1:
    // 004a93a1  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a93a8  0f8f47010000           -jg 0x4a94f5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a94f5;
    }
    // 004a93ae  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004a93b4  741f                   -je 0x4a93d5
    if (cpu.flags.zf)
    {
        goto L_0x004a93d5;
    }
L_0x004a93b6:
    // 004a93b6  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a93ba  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a93bd  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a93c0  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a93c5  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a93c8  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a93cb  78cf                   -js 0x4a939c
    if (cpu.flags.sf)
    {
        goto L_0x004a939c;
    }
    // 004a93cd  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004a93d3  75e1                   -jne 0x4a93b6
    if (!cpu.flags.zf)
    {
        goto L_0x004a93b6;
    }
L_0x004a93d5:
    // 004a93d5  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a93da  0f8c92000000           -jl 0x4a9472
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9472;
    }
L_0x004a93e0:
    // 004a93e0  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a93e4  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a93e7  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a93ea  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a93ee  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a93f1  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a93f4  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a93f8  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a93fb  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a93ff  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a9402  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9405  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 004a9409  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a940c  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a9410  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a9413  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9416  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 004a941a  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a941d  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 004a9420  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a9424  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a9427  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a942a  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a942e  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a9431  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9434  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a9438  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a943b  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a943f  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a9442  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9445  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 004a9449  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a944c  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a9450  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a9453  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9456  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 004a945a  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a945d  0f7f4f08               -movq qword ptr [edi + 8], mm1
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 004a9461  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9466  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a9469  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a946c  0f896effffff           -jns 0x4a93e0
    if (!cpu.flags.sf)
    {
        goto L_0x004a93e0;
    }
L_0x004a9472:
    // 004a9472  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9477  7855                   -js 0x4a94ce
    if (cpu.flags.sf)
    {
        goto L_0x004a94ce;
    }
    // 004a9479  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a947f  754d                   -jne 0x4a94ce
    if (!cpu.flags.zf)
    {
        goto L_0x004a94ce;
    }
L_0x004a9481:
    // 004a9481  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a9485  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9488  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a948b  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a948f  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9492  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9495  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a9499  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a949c  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a94a0  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a94a3  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a94a6  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 004a94aa  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a94ad  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a94b1  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a94b4  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a94b7  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 004a94bb  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a94be  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 004a94c1  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a94c6  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a94c9  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a94cc  79b3                   -jns 0x4a9481
    if (!cpu.flags.sf)
    {
        goto L_0x004a9481;
    }
L_0x004a94ce:
    // 004a94ce  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a94d3  0f88c3feffff           -js 0x4a939c
    if (cpu.flags.sf)
    {
        goto L_0x004a939c;
    }
L_0x004a94d9:
    // 004a94d9  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a94dd  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a94e0  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a94e3  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a94e8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a94eb  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a94ee  79e9                   -jns 0x4a94d9
    if (!cpu.flags.sf)
    {
        goto L_0x004a94d9;
    }
    // 004a94f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a94f5:
    // 004a94f5  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a94fa  0f889cfeffff           -js 0x4a939c
    if (cpu.flags.sf)
    {
        goto L_0x004a939c;
    }
L_0x004a9500:
    // 004a9500  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a9503  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9506  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a9508  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a950d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9510  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a9513  79eb                   -jns 0x4a9500
    if (!cpu.flags.sf)
    {
        goto L_0x004a9500;
    }
    // 004a9515  e982feffff             -jmp 0x4a939c
    goto L_0x004a939c;
}

/* align: skip  */
void Application::sub_4a951a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a951a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a951b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a951c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a951d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a951e  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9522  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a9526  8b1538eb4d00           -mov edx, dword ptr [0x4deb38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106488) /* 0x4deb38 */);
    // 004a952c  03353ceb4d00           -add esi, dword ptr [0x4deb3c]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5106492) /* 0x4deb3c */)));
    // 004a9532  033d60b24d00           -add edi, dword ptr [0x4db260]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a9538  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a953a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a953c  803d5cb24d0008         +cmp byte ptr [0x4db25c], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9543  0f8ffd000000           -jg 0x4a9646
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a9646;
    }
    // 004a9549  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a954f  7421                   -je 0x4a9572
    if (cpu.flags.zf)
    {
        goto L_0x004a9572;
    }
L_0x004a9551:
    // 004a9551  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9554  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9557  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a9559  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a955e  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9561  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a9564  0f88d7000000           -js 0x4a9641
    if (cpu.flags.sf)
    {
        goto L_0x004a9641;
    }
    // 004a956a  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a9570  75df                   -jne 0x4a9551
    if (!cpu.flags.zf)
    {
        goto L_0x004a9551;
    }
L_0x004a9572:
    // 004a9572  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a9575  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a957a  7c67                   -jl 0x4a95e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a95e3;
    }
L_0x004a957c:
    // 004a957c  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a957f  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9582  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9585  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a9587  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a958a  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a958e  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a9590  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9592  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a9595  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9598  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a959b  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a959d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a95a0  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a95a4  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a95a6  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a95a9  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a95ac  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a95af  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004a95b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a95b3  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a95b6  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a95ba  8b6a10                 -mov ebp, dword ptr [edx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a95bd  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a95bf  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a95c2  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a95c5  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004a95c8  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a95ca  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a95cd  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a95d1  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a95d3  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a95d8  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a95db  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a95de  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a95e1  7999                   -jns 0x4a957c
    if (!cpu.flags.sf)
    {
        goto L_0x004a957c;
    }
L_0x004a95e3:
    // 004a95e3  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a95e8  7839                   -js 0x4a9623
    if (cpu.flags.sf)
    {
        goto L_0x004a9623;
    }
L_0x004a95ea:
    // 004a95ea  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a95ed  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a95f0  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a95f3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a95f5  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a95f8  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a95fc  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a95fe  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9600  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a9603  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a9606  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a9609  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a960b  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a960e  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a9612  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9614  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004a9616  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a961b  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a961e  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a9621  79c7                   -jns 0x4a95ea
    if (!cpu.flags.sf)
    {
        goto L_0x004a95ea;
    }
L_0x004a9623:
    // 004a9623  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9628  7817                   -js 0x4a9641
    if (cpu.flags.sf)
    {
        goto L_0x004a9641;
    }
    // 004a962a  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004a962c:
    // 004a962c  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a962f  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9632  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a9634  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9639  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a963c  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a963f  79eb                   -jns 0x4a962c
    if (!cpu.flags.sf)
    {
        goto L_0x004a962c;
    }
L_0x004a9641:
    // 004a9641  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9642  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9643  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9644  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9645  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9646:
    // 004a9646  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9648  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a964a  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9651  7f20                   -jg 0x4a9673
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a9673;
    }
    // 004a9653  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9658  78e7                   -js 0x4a9641
    if (cpu.flags.sf)
    {
        goto L_0x004a9641;
    }
L_0x004a965a:
    // 004a965a  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a965e  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9661  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a9664  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9669  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a966c  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a966f  79e9                   -jns 0x4a965a
    if (!cpu.flags.sf)
    {
        goto L_0x004a965a;
    }
    // 004a9671  ebce                   -jmp 0x4a9641
    goto L_0x004a9641;
L_0x004a9673:
    // 004a9673  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9678  78c7                   -js 0x4a9641
    if (cpu.flags.sf)
    {
        goto L_0x004a9641;
    }
L_0x004a967a:
    // 004a967a  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a967d  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9680  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a9682  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9687  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a968a  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a968d  79eb                   -jns 0x4a967a
    if (!cpu.flags.sf)
    {
        goto L_0x004a967a;
    }
    // 004a968f  ebb0                   -jmp 0x4a9641
    goto L_0x004a9641;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a96a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a96a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a96a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a96a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a96a4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a96a6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a96ab  83f87b                 +cmp eax, 0x7b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a96ae  7509                   -jne 0x4a96b9
    if (!cpu.flags.zf)
    {
        goto L_0x004a96b9;
    }
    // 004a96b0  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a96b3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a96b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96b8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a96b9:
    // 004a96b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a96bb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a96bd  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004a96c0  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 004a96c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a96c8  83f80f                 +cmp eax, 0xf
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
    // 004a96cb  7505                   -jne 0x4a96d2
    if (!cpu.flags.zf)
    {
        goto L_0x004a96d2;
    }
    // 004a96cd  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x004a96d2:
    // 004a96d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a96d3  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a96d6  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004a96d9  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a96dc  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a96de  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004a96e3  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a96e6  750c                   -jne 0x4a96f4
    if (!cpu.flags.zf)
    {
        goto L_0x004a96f4;
    }
    // 004a96e8  8d410f                 -lea eax, [ecx + 0xf]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(15) /* 0xf */);
    // 004a96eb  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004a96ed  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004a96f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a96f4:
    // 004a96f4  8d4107                 -lea eax, [ecx + 7]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 004a96f7  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004a96f9  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004a96fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9700  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9701  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9702  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9703  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a9706  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a970a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a970c  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a970e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a9712  47                     -inc edi
    (cpu.edi)++;
    // 004a9713  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 004a9715  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a9717  7e5b                   -jle 0x4a9774
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a9774;
    }
    // 004a9719  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a971c  85c8                   +test eax, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ecx));
    // 004a971e  745d                   -je 0x4a977d
    if (cpu.flags.zf)
    {
        goto L_0x004a977d;
    }
L_0x004a9720:
    // 004a9720  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a9722  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a9725  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a9728  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a972c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a972e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a9731  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a9734  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a9738  030c24                 -add ecx, dword ptr [esp]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004a973b  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004a973d  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a9741  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9743  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a9745  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a9748  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a974b  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a974d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a9750  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a9752  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a9755  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a9759  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a975c  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a975f  034c2404               -add ecx, dword ptr [esp + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004a9763  894efc                 -mov dword ptr [esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a9766  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a976a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a976c  01cb                   +add ebx, ecx
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
    // 004a976e  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a976f  75af                   -jne 0x4a9720
    if (!cpu.flags.zf)
    {
        goto L_0x004a9720;
    }
    // 004a9771  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a9774:
    // 004a9774  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a9777  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9778  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9779  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a977a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a977d:
    // 004a977d  e86e420000             -call 0x4ad9f0
    cpu.esp -= 4;
    sub_4ad9f0(app, cpu);
    if (cpu.terminate) return;
    // 004a9782  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004a9786:
    // 004a9786  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9788  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a978b  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a978f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a9791  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a9794  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9796  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a9799  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a979c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a979e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a97a2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a97a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a97a6  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004a97a8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a97ab  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a97af  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a97b1  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a97b3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a97b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a97b8  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a97bb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a97be  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a97c1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a97c3  894efc                 -mov dword ptr [esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a97c6  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a97ca  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a97cc  01cb                   +add ebx, ecx
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
    // 004a97ce  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a97cf  75b5                   -jne 0x4a9786
    if (!cpu.flags.zf)
    {
        goto L_0x004a9786;
    }
    // 004a97d1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a97d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a97d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a97d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a97d7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4a97da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a97da  83f841                 +cmp eax, 0x41
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a97dd  7c08                   -jl 0x4a97e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a97e7;
    }
    // 004a97df  83f85a                 +cmp eax, 0x5a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a97e2  7f03                   -jg 0x4a97e7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a97e7;
    }
    // 004a97e4  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004a97e7:
    // 004a97e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a97e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a97e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a97e9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a97ea  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a97ee  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a97f1  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004a97f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a97f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a97f7  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a97fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a97fc  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9801  e806000000             -call 0x4a980c
    cpu.esp -= 4;
    sub_4a980c(app, cpu);
    if (cpu.terminate) return;
    // 004a9806  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a9809  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a980a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a980b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a980c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a980c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a980d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a980e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a980f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9812  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a9816  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004a9818  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a981c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9820  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a9823  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a9827  e807000000             -call 0x4a9833
    cpu.esp -= 4;
    sub_4a9833(app, cpu);
    if (cpu.terminate) return;
    // 004a982c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a982f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9830  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9831  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9833(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9833  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9834  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9835  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9836  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a9839  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a983b  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a983f  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004a9843  e868e60000             -call 0x4b7eb0
    cpu.esp -= 4;
    sub_4b7eb0(app, cpu);
    if (cpu.terminate) return;
    // 004a9848  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a984a  7414                   -je 0x4a9860
    if (cpu.flags.zf)
    {
        goto L_0x004a9860;
    }
    // 004a984c  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
L_0x004a9851:
    // 004a9851  e85aceffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004a9856  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a985b  e9d5010000             -jmp 0x4a9a35
    goto L_0x004a9a35;
L_0x004a9860:
    // 004a9860  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a9862  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a9866  83e607                 -and esi, 7
    cpu.esi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a9869  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a986d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a986f  e880e80000             -call 0x4b80f4
    cpu.esp -= 4;
    sub_4b80f4(app, cpu);
    if (cpu.terminate) return;
    // 004a9874  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9878  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a987c  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a987e  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004a9883  e898e80000             -call 0x4b8120
    cpu.esp -= 4;
    sub_4b8120(app, cpu);
    if (cpu.terminate) return;
    // 004a9888  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a988a  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 004a988f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a9893  8a64241c               -mov ah, byte ptr [esp + 0x1c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a9897  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a989a  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 004a989d  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004a98a0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a98a5  8b15aced4d00           -mov edx, dword ptr [0x4dedac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107116) /* 0x4dedac */);
    // 004a98ab  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a98af  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a98b1  7435                   -je 0x4a98e8
    if (cpu.flags.zf)
    {
        goto L_0x004a98e8;
    }
    // 004a98b3  bad4144d00             -mov edx, 0x4d14d4
    cpu.edx = 5051604 /*0x4d14d4*/;
    // 004a98b8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a98ba  e87458ffff             -call 0x49f133
    cpu.esp -= 4;
    sub_49f133(app, cpu);
    if (cpu.terminate) return;
    // 004a98bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a98c1  7525                   -jne 0x4a98e8
    if (!cpu.flags.zf)
    {
        goto L_0x004a98e8;
    }
    // 004a98c3  e8d6e70000             -call 0x4b809e
    cpu.esp -= 4;
    sub_4b809e(app, cpu);
    if (cpu.terminate) return;
    // 004a98c8  ff1564ed4d00           -call dword ptr [0x4ded64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107044) /* 0x4ded64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a98ce  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004a98d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a98d1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a98d3  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 004a98d8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a98da  ff15aced4d00           -call dword ptr [0x4dedac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107116) /* 0x4dedac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a98e0  83c40c                 +add esp, 0xc
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
    // 004a98e3  e9fd000000             -jmp 0x4a99e5
    goto L_0x004a99e5;
L_0x004a98e8:
    // 004a98e8  8a54241c               -mov dl, byte ptr [esp + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a98ec  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004a98ef  7462                   -je 0x4a9953
    if (cpu.flags.zf)
    {
        goto L_0x004a9953;
    }
    // 004a98f1  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a98f3  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a98f6  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 004a98f8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a98fb  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a98ff  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 004a9905  a1b8064e00             -mov eax, dword ptr [0x4e06b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113528) /* 0x4e06b8 */);
    // 004a990a  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a990e  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004a9910  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9912  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a9916  f644241501             +test byte ptr [esp + 0x15], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) & 1 /*0x1*/));
    // 004a991b  740c                   -je 0x4a9929
    if (cpu.flags.zf)
    {
        goto L_0x004a9929;
    }
    // 004a991d  f644241480             +test byte ptr [esp + 0x14], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 128 /*0x80*/));
    // 004a9922  7505                   -jne 0x4a9929
    if (!cpu.flags.zf)
    {
        goto L_0x004a9929;
    }
    // 004a9924  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004a9929:
    // 004a9929  f644241d04             +test byte ptr [esp + 0x1d], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) & 4 /*0x4*/));
    // 004a992e  7409                   -je 0x4a9939
    if (cpu.flags.zf)
    {
        goto L_0x004a9939;
    }
    // 004a9930  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004a9935  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a9937  eb24                   -jmp 0x4a995d
    goto L_0x004a995d;
L_0x004a9939:
    // 004a9939  f644241c40             +test byte ptr [esp + 0x1c], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 64 /*0x40*/));
    // 004a993e  740c                   -je 0x4a994c
    if (cpu.flags.zf)
    {
        goto L_0x004a994c;
    }
    // 004a9940  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
L_0x004a9945:
    // 004a9945  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a994a  eb11                   -jmp 0x4a995d
    goto L_0x004a995d;
L_0x004a994c:
    // 004a994c  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 004a9951  eb05                   -jmp 0x4a9958
    goto L_0x004a9958;
L_0x004a9953:
    // 004a9953  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 004a9956  75ed                   -jne 0x4a9945
    if (!cpu.flags.zf)
    {
        goto L_0x004a9945;
    }
L_0x004a9958:
    // 004a9958  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x004a995d:
    // 004a995d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a995f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9960  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9961  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a9965  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9966  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a996a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a996b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a996f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9970  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9971  2eff155c644c00         -call dword ptr cs:[0x4c645c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006428) /* 0x4c645c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9978  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a997a  83f8ff                 +cmp eax, -1
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
    // 004a997d  7530                   -jne 0x4a99af
    if (!cpu.flags.zf)
    {
        goto L_0x004a99af;
    }
    // 004a997f  f644241c20             +test byte ptr [esp + 0x1c], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 32 /*0x20*/));
    // 004a9984  741a                   -je 0x4a99a0
    if (cpu.flags.zf)
    {
        goto L_0x004a99a0;
    }
    // 004a9986  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a9988  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9989  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a998a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a998c  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a9990  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9991  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a9995  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9996  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9997  2eff155c644c00         -call dword ptr cs:[0x4c645c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006428) /* 0x4c645c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a999e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a99a0:
    // 004a99a0  83f9ff                 +cmp ecx, -1
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
    // 004a99a3  750a                   -jne 0x4a99af
    if (!cpu.flags.zf)
    {
        goto L_0x004a99af;
    }
    // 004a99a5  e808ccffff             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 004a99aa  e986000000             -jmp 0x4a9a35
    goto L_0x004a9a35;
L_0x004a99af:
    // 004a99af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a99b1  ff1564ed4d00           -call dword ptr [0x4ded64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107044) /* 0x4ded64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a99b7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a99b9  8b2dbc064e00           -mov ebp, dword ptr [0x4e06bc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113532) /* 0x4e06bc */);
    // 004a99bf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a99c1  39e8                   +cmp eax, ebp
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
    // 004a99c3  7212                   -jb 0x4a99d7
    if (cpu.flags.cf)
    {
        goto L_0x004a99d7;
    }
    // 004a99c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a99c6  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a99cd  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a99d2  e97afeffff             -jmp 0x4a9851
    goto L_0x004a9851;
L_0x004a99d7:
    // 004a99d7  e812e80000             -call 0x4b81ee
    cpu.esp -= 4;
    sub_4b81ee(app, cpu);
    if (cpu.terminate) return;
    // 004a99dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a99de  7405                   -je 0x4a99e5
    if (cpu.flags.zf)
    {
        goto L_0x004a99e5;
    }
    // 004a99e0  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x004a99e5:
    // 004a99e5  83fe02                 +cmp esi, 2
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
    // 004a99e8  7505                   -jne 0x4a99ef
    if (!cpu.flags.zf)
    {
        goto L_0x004a99ef;
    }
    // 004a99ea  80ca03                 +or dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a99ed  eb11                   -jmp 0x4a9a00
    goto L_0x004a9a00;
L_0x004a99ef:
    // 004a99ef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a99f1  7505                   -jne 0x4a99f8
    if (!cpu.flags.zf)
    {
        goto L_0x004a99f8;
    }
    // 004a99f3  80ca01                 +or dl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004a99f6  eb08                   -jmp 0x4a9a00
    goto L_0x004a9a00;
L_0x004a99f8:
    // 004a99f8  83fe01                 +cmp esi, 1
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
    // 004a99fb  7503                   -jne 0x4a9a00
    if (!cpu.flags.zf)
    {
        goto L_0x004a9a00;
    }
    // 004a99fd  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004a9a00:
    // 004a9a00  f644241c10             +test byte ptr [esp + 0x1c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 16 /*0x10*/));
    // 004a9a05  7403                   -je 0x4a9a0a
    if (cpu.flags.zf)
    {
        goto L_0x004a9a0a;
    }
    // 004a9a07  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004a9a0a:
    // 004a9a0a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9a0c  8a7c241d               -mov bh, byte ptr [esp + 0x1d]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */);
    // 004a9a10  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004a9a12  f6c703                 +test bh, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 3 /*0x3*/));
    // 004a9a15  7407                   -je 0x4a9a1e
    if (cpu.flags.zf)
    {
        goto L_0x004a9a1e;
    }
    // 004a9a17  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 004a9a1a  7410                   -je 0x4a9a2c
    if (cpu.flags.zf)
    {
        goto L_0x004a9a2c;
    }
    // 004a9a1c  eb0c                   -jmp 0x4a9a2a
    goto L_0x004a9a2a;
L_0x004a9a1e:
    // 004a9a1e  813d4ded4d0000020000   +cmp dword ptr [0x4ded4d], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107021) /* 0x4ded4d */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9a28  7502                   -jne 0x4a9a2c
    if (!cpu.flags.zf)
    {
        goto L_0x004a9a2c;
    }
L_0x004a9a2a:
    // 004a9a2a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a9a2c:
    // 004a9a2c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a9a2e  e89ae70000             -call 0x4b81cd
    cpu.esp -= 4;
    sub_4b81cd(app, cpu);
    if (cpu.terminate) return;
    // 004a9a33  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a9a35:
    // 004a9a35  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a9a38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9a39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9a3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9a3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9a3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9a3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9a3d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9a3e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9a3f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9a40  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9a41  ff156ced4d00           -call dword ptr [0x4ded6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107052) /* 0x4ded6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9a47  8b35a8675b00           -mov esi, dword ptr [0x5b67a8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5990312) /* 0x5b67a8 */);
    // 004a9a4d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a9a4f  7419                   -je 0x4a9a6a
    if (cpu.flags.zf)
    {
        goto L_0x004a9a6a;
    }
    // 004a9a51  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a9a54  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a9a57  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a9a59  81e703400000           -and edi, 0x4003
    cpu.edi &= x86::reg32(x86::sreg32(16387 /*0x4003*/));
    // 004a9a5f  a3a8675b00             -mov dword ptr [0x5b67a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5990312) /* 0x5b67a8 */) = cpu.eax;
    // 004a9a64  6683cf03               +or di, 3
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(3 /*0x3*/))));
    // 004a9a68  eb47                   -jmp 0x4a9ab1
    goto L_0x004a9ab1;
L_0x004a9a6a:
    // 004a9a6a  b944eb4d00             -mov ecx, 0x4deb44
    cpu.ecx = 5106500 /*0x4deb44*/;
    // 004a9a6f  eb20                   -jmp 0x4a9a91
    goto L_0x004a9a91;
L_0x004a9a71:
    // 004a9a71  f6410c03               +test byte ptr [ecx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 004a9a75  7517                   -jne 0x4a9a8e
    if (!cpu.flags.zf)
    {
        goto L_0x004a9a8e;
    }
    // 004a9a77  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004a9a7c  e842cbffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004a9a81  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9a83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9a85  7458                   -je 0x4a9adf
    if (cpu.flags.zf)
    {
        goto L_0x004a9adf;
    }
    // 004a9a87  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 004a9a8c  eb23                   -jmp 0x4a9ab1
    goto L_0x004a9ab1;
L_0x004a9a8e:
    // 004a9a8e  83c11a                 -add ecx, 0x1a
    (cpu.ecx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
L_0x004a9a91:
    // 004a9a91  81f94ced4d00           +cmp ecx, 0x4ded4c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5107020 /*0x4ded4c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9a97  72d8                   -jb 0x4a9a71
    if (cpu.flags.cf)
    {
        goto L_0x004a9a71;
    }
    // 004a9a99  b837000000             -mov eax, 0x37
    cpu.eax = 55 /*0x37*/;
    // 004a9a9e  bf03400000             -mov edi, 0x4003
    cpu.edi = 16387 /*0x4003*/;
    // 004a9aa3  e81bcbffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004a9aa8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9aaa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9aac  7431                   -je 0x4a9adf
    if (cpu.flags.zf)
    {
        goto L_0x004a9adf;
    }
    // 004a9aae  8d481d                 -lea ecx, [eax + 0x1d]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(29) /* 0x1d */);
L_0x004a9ab1:
    // 004a9ab1  bb1a000000             -mov ebx, 0x1a
    cpu.ebx = 26 /*0x1a*/;
    // 004a9ab6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9ab8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a9aba  e8708bfeff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004a9abf  89790c                 -mov dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004a9ac2  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a9ac5  a1a4675b00             -mov eax, dword ptr [0x5b67a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */);
    // 004a9aca  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004a9acd  8935a4675b00           -mov dword ptr [0x5b67a4], esi
    app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */) = cpu.esi;
    // 004a9ad3  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a9ad5  ff1570ed4d00           -call dword ptr [0x4ded70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107056) /* 0x4ded70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9adb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9add  eb12                   -jmp 0x4a9af1
    goto L_0x004a9af1;
L_0x004a9adf:
    // 004a9adf  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a9ae4  e8c7cbffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004a9ae9  ff1570ed4d00           -call dword ptr [0x4ded70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107056) /* 0x4ded70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9aef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a9af1:
    // 004a9af1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9af2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9af3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9af4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9af5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9af6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9af7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9af7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9af8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9af9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9afa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9afc  baa4675b00             -mov edx, 0x5b67a4
    cpu.edx = 5990308 /*0x5b67a4*/;
L_0x004a9b01:
    // 004a9b01  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a9b03  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9b05  7425                   -je 0x4a9b2c
    if (cpu.flags.zf)
    {
        goto L_0x004a9b2c;
    }
    // 004a9b07  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a9b0a  39cb                   +cmp ebx, ecx
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
    // 004a9b0c  7404                   -je 0x4a9b12
    if (cpu.flags.zf)
    {
        goto L_0x004a9b12;
    }
    // 004a9b0e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9b10  ebef                   -jmp 0x4a9b01
    goto L_0x004a9b01;
L_0x004a9b12:
    // 004a9b12  8a490c                 -mov cl, byte ptr [ecx + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a9b15  80c903                 -or cl, 3
    cpu.cl |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004a9b18  884b0c                 -mov byte ptr [ebx + 0xc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.cl;
    // 004a9b1b  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a9b1d  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a9b1f  8b15a8675b00           -mov edx, dword ptr [0x5b67a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5990312) /* 0x5b67a8 */);
    // 004a9b25  a3a8675b00             -mov dword ptr [0x5b67a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5990312) /* 0x5b67a8 */) = cpu.eax;
    // 004a9b2a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x004a9b2c:
    // 004a9b2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x004a9b31:
    // 004a9b31  8b15a8675b00           -mov edx, dword ptr [0x5b67a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5990312) /* 0x5b67a8 */);
    // 004a9b37  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a9b39  7411                   -je 0x4a9b4c
    if (cpu.flags.zf)
    {
        goto L_0x004a9b4c;
    }
    // 004a9b3b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9b3d  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a9b3f  e8b4190000             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004a9b44  8915a8675b00           -mov dword ptr [0x5b67a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5990312) /* 0x5b67a8 */) = cpu.edx;
    // 004a9b4a  ebe5                   -jmp 0x4a9b31
    goto L_0x004a9b31;
L_0x004a9b4c:
    // 004a9b4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9b4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b4e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9b4f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9b50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9b51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9b52  3b4204                 +cmp eax, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9b55  7f2c                   -jg 0x4a9b83
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a9b83;
    }
    // 004a9b57  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9b5a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a9b5c  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9b5f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9b61  39d8                   +cmp eax, ebx
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
    // 004a9b63  7c1e                   -jl 0x4a9b83
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9b83;
    }
    // 004a9b65  8a5a0c                 -mov bl, byte ptr [edx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a9b68  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a9b6a  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9b6d  80e3ef                 -and bl, 0xef
    cpu.bl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004a9b70  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9b72  885a0c                 -mov byte ptr [edx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 004a9b75  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9b77  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004a9b79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9b7b  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a9b7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b80  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b81  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9b83:
    // 004a9b83  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a9b88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9b8d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b8d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9b8e  80600cef               -and byte ptr [eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004a9b92  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a9b95  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9b98  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a9b9f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a9ba1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ba2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9ba3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9ba3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9ba4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9ba5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9ba6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a9ba8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a9baa  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a9bad  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9bb3  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a9bb6  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 004a9bb9  7465                   -je 0x4a9c20
    if (cpu.flags.zf)
    {
        goto L_0x004a9c20;
    }
    // 004a9bbb  f6410d10               +test byte ptr [ecx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004a9bbf  741f                   -je 0x4a9be0
    if (cpu.flags.zf)
    {
        goto L_0x004a9be0;
    }
    // 004a9bc1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9bc3  e8c7160000             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
    // 004a9bc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9bca  742b                   -je 0x4a9bf7
    if (cpu.flags.zf)
    {
        goto L_0x004a9bf7;
    }
    // 004a9bcc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a9bce  753e                   -jne 0x4a9c0e
    if (!cpu.flags.zf)
    {
        goto L_0x004a9c0e;
    }
    // 004a9bd0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a9bd2  7d3a                   -jge 0x4a9c0e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9c0e;
    }
L_0x004a9bd4:
    // 004a9bd4  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a9bd9  e8d2caffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004a9bde  eb2e                   -jmp 0x4a9c0e
    goto L_0x004a9c0e;
L_0x004a9be0:
    // 004a9be0  83fb01                 +cmp ebx, 1
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
    // 004a9be3  7503                   -jne 0x4a9be8
    if (!cpu.flags.zf)
    {
        goto L_0x004a9be8;
    }
    // 004a9be5  2b7104                 -sub esi, dword ptr [ecx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
L_0x004a9be8:
    // 004a9be8  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a9beb  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a9bee  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a9bf5  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x004a9bf7:
    // 004a9bf7  80610ceb               -and byte ptr [ecx + 0xc], 0xeb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(235 /*0xeb*/));
    // 004a9bfb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a9bfd  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
L_0x004a9c00:
    // 004a9c00  e8f2170000             -call 0x4ab3f7
    cpu.esp -= 4;
    sub_4ab3f7(app, cpu);
    if (cpu.terminate) return;
    // 004a9c05  83f8ff                 +cmp eax, -1
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
    // 004a9c08  0f8596000000           -jne 0x4a9ca4
    if (!cpu.flags.zf)
    {
        goto L_0x004a9ca4;
    }
L_0x004a9c0e:
    // 004a9c0e  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a9c11  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9c17  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a9c1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9c20:
    // 004a9c20  83fb01                 +cmp ebx, 1
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
    // 004a9c23  7209                   -jb 0x4a9c2e
    if (cpu.flags.cf)
    {
        goto L_0x004a9c2e;
    }
    // 004a9c25  760d                   -jbe 0x4a9c34
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9c34;
    }
    // 004a9c27  83fb02                 +cmp ebx, 2
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
    // 004a9c2a  7457                   -je 0x4a9c83
    if (cpu.flags.zf)
    {
        goto L_0x004a9c83;
    }
    // 004a9c2c  eba6                   -jmp 0x4a9bd4
    goto L_0x004a9bd4;
L_0x004a9c2e:
    // 004a9c2e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a9c30  742c                   -je 0x4a9c5e
    if (cpu.flags.zf)
    {
        goto L_0x004a9c5e;
    }
    // 004a9c32  eba0                   -jmp 0x4a9bd4
    goto L_0x004a9bd4;
L_0x004a9c34:
    // 004a9c34  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a9c36  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a9c38  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a9c3b  e80effffff             -call 0x4a9b4e
    cpu.esp -= 4;
    sub_4a9b4e(app, cpu);
    if (cpu.terminate) return;
    // 004a9c40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9c42  7460                   -je 0x4a9ca4
    if (cpu.flags.zf)
    {
        goto L_0x004a9ca4;
    }
    // 004a9c44  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a9c46  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a9c49  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a9c4b:
    // 004a9c4b  e8a7170000             -call 0x4ab3f7
    cpu.esp -= 4;
    sub_4ab3f7(app, cpu);
    if (cpu.terminate) return;
    // 004a9c50  83f8ff                 +cmp eax, -1
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
    // 004a9c53  74b9                   -je 0x4a9c0e
    if (cpu.flags.zf)
    {
        goto L_0x004a9c0e;
    }
    // 004a9c55  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9c57  e831ffffff             -call 0x4a9b8d
    cpu.esp -= 4;
    sub_4a9b8d(app, cpu);
    if (cpu.terminate) return;
    // 004a9c5c  eb46                   -jmp 0x4a9ca4
    goto L_0x004a9ca4;
L_0x004a9c5e:
    // 004a9c5e  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a9c61  e8dee50000             -call 0x4b8244
    cpu.esp -= 4;
    sub_4b8244(app, cpu);
    if (cpu.terminate) return;
    // 004a9c66  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a9c69  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004a9c6b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9c6d  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9c6f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a9c71  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a9c73  e8d6feffff             -call 0x4a9b4e
    cpu.esp -= 4;
    sub_4a9b4e(app, cpu);
    if (cpu.terminate) return;
    // 004a9c78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9c7a  7428                   -je 0x4a9ca4
    if (cpu.flags.zf)
    {
        goto L_0x004a9ca4;
    }
    // 004a9c7c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a9c7e  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a9c81  ebc8                   -jmp 0x4a9c4b
    goto L_0x004a9c4b;
L_0x004a9c83:
    // 004a9c83  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004a9c85  80e2ef                 +and dl, 0xef
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 004a9c88  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a9c8b  88510c                 -mov byte ptr [ecx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004a9c8e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a9c91  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a9c93  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a9c95  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a9c98  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a9c9f  e95cffffff             -jmp 0x4a9c00
    goto L_0x004a9c00;
L_0x004a9ca4:
    // 004a9ca4  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a9ca7  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9cad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9caf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cb1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9cb3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9cb3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9cb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9cb5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9cb6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9cb8  f6400d20               +test byte ptr [eax + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 004a9cbc  7522                   -jne 0x4a9ce0
    if (!cpu.flags.zf)
    {
        goto L_0x004a9ce0;
    }
    // 004a9cbe  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a9cc1  e828e50000             -call 0x4b81ee
    cpu.esp -= 4;
    sub_4b81ee(app, cpu);
    if (cpu.terminate) return;
    // 004a9cc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9cc8  7416                   -je 0x4a9ce0
    if (cpu.flags.zf)
    {
        goto L_0x004a9ce0;
    }
    // 004a9cca  8a5a0d                 -mov bl, byte ptr [edx + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004a9ccd  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004a9cd0  885a0d                 -mov byte ptr [edx + 0xd], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 004a9cd3  f6c307                 +test bl, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 7 /*0x7*/));
    // 004a9cd6  7508                   -jne 0x4a9ce0
    if (!cpu.flags.zf)
    {
        goto L_0x004a9ce0;
    }
    // 004a9cd8  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a9cda  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004a9cdd  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
L_0x004a9ce0:
    // 004a9ce0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ce1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ce2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ce3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9ce4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9ce4  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9cea  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 004a9cef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9cf0  a1b0675b00             -mov eax, dword ptr [0x5b67b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5990320) /* 0x5b67b0 */);
    // 004a9cf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9cf5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a9cf5;
    // 004a9cf0  a1b0675b00             -mov eax, dword ptr [0x5b67b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5990320) /* 0x5b67b0 */);
L_entry_0x004a9cf5:
    // 004a9cf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9cf6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9cf6  e9fae10000             -jmp 0x4b7ef5
    return sub_4b7ef5(app, cpu);
}

/* align: skip  */
void Application::sub_4a9cfb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9cfb  e913e30000             -jmp 0x4b8013
    return sub_4b8013(app, cpu);
}

/* align: skip  */
void Application::sub_4a9d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9d00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9d01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9d02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9d03  81ec18060000           -sub esp, 0x618
    (cpu.esp) -= x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 004a9d09  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a9d0b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a9d0d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9d0f  893dac675b00           -mov dword ptr [0x5b67ac], edi
    app->getMemory<x86::reg32>(x86::reg32(5990316) /* 0x5b67ac */) = cpu.edi;
    // 004a9d15  e860e70000             -call 0x4b847a
    cpu.esp -= 4;
    sub_4b847a(app, cpu);
    if (cpu.terminate) return;
    // 004a9d1a  a3b0675b00             -mov dword ptr [0x5b67b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5990320) /* 0x5b67b0 */) = cpu.eax;
    // 004a9d1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9d21  7511                   -jne 0x4a9d34
    if (!cpu.flags.zf)
    {
        goto L_0x004a9d34;
    }
    // 004a9d23  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a9d25  0f85f6010000           -jne 0x4a9f21
    if (!cpu.flags.zf)
    {
        goto L_0x004a9f21;
    }
    // 004a9d2b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a9d2d  2eff1584644c00         -call dword ptr cs:[0x4c6484]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006468) /* 0x4c6484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a9d34:
    // 004a9d34  e806e30000             -call 0x4b803f
    cpu.esp -= 4;
    sub_4b803f(app, cpu);
    if (cpu.terminate) return;
    // 004a9d39  2eff15dc644c00         -call dword ptr cs:[0x4c64dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006556) /* 0x4c64dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9d40  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9d42  a305db4d00             -mov dword ptr [0x4ddb05], eax
    app->getMemory<x86::reg32>(x86::reg32(5102341) /* 0x4ddb05 */) = cpu.eax;
    // 004a9d47  891534945b00           -mov dword ptr [0x5b9434], edx
    app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */) = cpu.edx;
    // 004a9d4d  2eff152c654c00         -call dword ptr cs:[0x4c652c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006636) /* 0x4c652c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9d54  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9d56  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9d58  a20bdb4d00             -mov byte ptr [0x4ddb0b], al
    app->getMemory<x86::reg8>(x86::reg32(5102347) /* 0x4ddb0b */) = cpu.al;
    // 004a9d5d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9d60  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a9d65  66a30ddb4d00           -mov word ptr [0x4ddb0d], ax
    app->getMemory<x86::reg16>(x86::reg32(5102349) /* 0x4ddb0d */) = cpu.ax;
    // 004a9d6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9d6d  66a10ddb4d00           -mov ax, word ptr [0x4ddb0d]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5102349) /* 0x4ddb0d */);
    // 004a9d73  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a9d79  a30fdb4d00             -mov dword ptr [0x4ddb0f], eax
    app->getMemory<x86::reg32>(x86::reg32(5102351) /* 0x4ddb0f */) = cpu.eax;
    // 004a9d7e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9d80  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004a9d83  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004a9d85  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a9d8b  a313db4d00             -mov dword ptr [0x4ddb13], eax
    app->getMemory<x86::reg32>(x86::reg32(5102355) /* 0x4ddb13 */) = cpu.eax;
    // 004a9d90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9d92  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a9d94  88150cdb4d00           -mov byte ptr [0x4ddb0c], dl
    app->getMemory<x86::reg8>(x86::reg32(5102348) /* 0x4ddb0c */) = cpu.dl;
    // 004a9d9a  a317db4d00             -mov dword ptr [0x4ddb17], eax
    app->getMemory<x86::reg32>(x86::reg32(5102359) /* 0x4ddb17 */) = cpu.eax;
    // 004a9d9f  a113db4d00             -mov eax, dword ptr [0x4ddb13]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102355) /* 0x4ddb13 */);
    // 004a9da4  8b1517db4d00           -mov edx, dword ptr [0x4ddb17]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102359) /* 0x4ddb17 */);
    // 004a9daa  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a9dad  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9daf  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004a9db4  a31bdb4d00             -mov dword ptr [0x4ddb1b], eax
    app->getMemory<x86::reg32>(x86::reg32(5102363) /* 0x4ddb1b */) = cpu.eax;
    // 004a9db9  8d842414040000         -lea eax, [esp + 0x414]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 004a9dc0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9dc1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a9dc3  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 004a9dc8  2eff1500654c00         -call dword ptr cs:[0x4c6500]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006592) /* 0x4c6500 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9dcf  8d842410040000         -lea eax, [esp + 0x410]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1040) /* 0x410 */);
    // 004a9dd6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a9dd8  e883e90000             -call 0x4b8760
    cpu.esp -= 4;
    sub_4b8760(app, cpu);
    if (cpu.terminate) return;
    // 004a9ddd  a3ccda4d00             -mov dword ptr [0x4ddacc], eax
    app->getMemory<x86::reg32>(x86::reg32(5102284) /* 0x4ddacc */) = cpu.eax;
    // 004a9de2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9de4  e8bce90000             -call 0x4b87a5
    cpu.esp -= 4;
    sub_4b87a5(app, cpu);
    if (cpu.terminate) return;
    // 004a9de9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a9deb  e845ea0000             -call 0x4b8835
    cpu.esp -= 4;
    sub_4b8835(app, cpu);
    if (cpu.terminate) return;
    // 004a9df0  a3d8da4d00             -mov dword ptr [0x4ddad8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102296) /* 0x4ddad8 */) = cpu.eax;
    // 004a9df5  2eff15b4644c00         -call dword ptr cs:[0x4c64b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006516) /* 0x4c64b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9dfc  e85fe90000             -call 0x4b8760
    cpu.esp -= 4;
    sub_4b8760(app, cpu);
    if (cpu.terminate) return;
    // 004a9e01  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a9e03  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9e05  80fb22                 +cmp bl, 0x22
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9e08  7514                   -jne 0x4a9e1e
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e1e;
    }
L_0x004a9e0a:
    // 004a9e0a  40                     -inc eax
    (cpu.eax)++;
    // 004a9e0b  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 004a9e0d  80fd22                 +cmp ch, 0x22
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9e10  7404                   -je 0x4a9e16
    if (cpu.flags.zf)
    {
        goto L_0x004a9e16;
    }
    // 004a9e12  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 004a9e14  75f4                   -jne 0x4a9e0a
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e0a;
    }
L_0x004a9e16:
    // 004a9e16  803800                 +cmp byte ptr [eax], 0
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
    // 004a9e19  741e                   -je 0x4a9e39
    if (cpu.flags.zf)
    {
        goto L_0x004a9e39;
    }
L_0x004a9e1b:
    // 004a9e1b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a9e1c  eb1b                   -jmp 0x4a9e39
    goto L_0x004a9e39;
L_0x004a9e1e:
    // 004a9e1e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a9e20  fec2                   -inc dl
    (cpu.dl)++;
    // 004a9e22  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a9e28  f68264ef4d0002         +test byte ptr [edx + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004a9e2f  7508                   -jne 0x4a9e39
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e39;
    }
    // 004a9e31  803800                 +cmp byte ptr [eax], 0
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
    // 004a9e34  7403                   -je 0x4a9e39
    if (cpu.flags.zf)
    {
        goto L_0x004a9e39;
    }
    // 004a9e36  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a9e37  ebe5                   -jmp 0x4a9e1e
    goto L_0x004a9e1e;
L_0x004a9e39:
    // 004a9e39  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a9e3b  fec2                   -inc dl
    (cpu.dl)++;
    // 004a9e3d  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a9e43  f68264ef4d0002         +test byte ptr [edx + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004a9e4a  75cf                   -jne 0x4a9e1b
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e1b;
    }
    // 004a9e4c  a3c8da4d00             -mov dword ptr [0x4ddac8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102280) /* 0x4ddac8 */) = cpu.eax;
    // 004a9e51  2eff15b8644c00         -call dword ptr cs:[0x4c64b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006520) /* 0x4c64b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9e58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9e5a  0f845f000000           -je 0x4a9ebf
    if (cpu.flags.zf)
    {
        goto L_0x004a9ebf;
    }
    // 004a9e60  e8d0e90000             -call 0x4b8835
    cpu.esp -= 4;
    sub_4b8835(app, cpu);
    if (cpu.terminate) return;
    // 004a9e65  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a9e68  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9e6a  6683fb22               +cmp bx, 0x22
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a9e6e  751c                   -jne 0x4a9e8c
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e8c;
    }
L_0x004a9e70:
    // 004a9e70  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a9e73  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a9e76  6683fa22               +cmp dx, 0x22
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a9e7a  7405                   -je 0x4a9e81
    if (cpu.flags.zf)
    {
        goto L_0x004a9e81;
    }
    // 004a9e7c  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004a9e7f  75ef                   -jne 0x4a9e70
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e70;
    }
L_0x004a9e81:
    // 004a9e81  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a9e85  7423                   -je 0x4a9eaa
    if (cpu.flags.zf)
    {
        goto L_0x004a9eaa;
    }
L_0x004a9e87:
    // 004a9e87  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9e8a  eb1e                   -jmp 0x4a9eaa
    goto L_0x004a9eaa;
L_0x004a9e8c:
    // 004a9e8c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a9e8e  fec2                   -inc dl
    (cpu.dl)++;
    // 004a9e90  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a9e96  f68264ef4d0002         +test byte ptr [edx + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004a9e9d  750b                   -jne 0x4a9eaa
    if (!cpu.flags.zf)
    {
        goto L_0x004a9eaa;
    }
    // 004a9e9f  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a9ea3  7405                   -je 0x4a9eaa
    if (cpu.flags.zf)
    {
        goto L_0x004a9eaa;
    }
    // 004a9ea5  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9ea8  ebe2                   -jmp 0x4a9e8c
    goto L_0x004a9e8c;
L_0x004a9eaa:
    // 004a9eaa  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a9eac  fec2                   -inc dl
    (cpu.dl)++;
    // 004a9eae  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a9eb4  f68264ef4d0002         +test byte ptr [edx + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004a9ebb  740c                   -je 0x4a9ec9
    if (cpu.flags.zf)
    {
        goto L_0x004a9ec9;
    }
    // 004a9ebd  ebc8                   -jmp 0x4a9e87
    goto L_0x004a9e87;
L_0x004a9ebf:
    // 004a9ebf  b8d8144d00             -mov eax, 0x4d14d8
    cpu.eax = 5051608 /*0x4d14d8*/;
    // 004a9ec4  e86ce90000             -call 0x4b8835
    cpu.esp -= 4;
    sub_4b8835(app, cpu);
    if (cpu.terminate) return;
L_0x004a9ec9:
    // 004a9ec9  a3d4da4d00             -mov dword ptr [0x4ddad4], eax
    app->getMemory<x86::reg32>(x86::reg32(5102292) /* 0x4ddad4 */) = cpu.eax;
    // 004a9ece  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a9ed0  744a                   -je 0x4a9f1c
    if (cpu.flags.zf)
    {
        goto L_0x004a9f1c;
    }
    // 004a9ed2  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004a9ed7  8d842418050000         -lea eax, [esp + 0x518]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 004a9ede  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9edf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9ee0  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 004a9ee5  2eff1500654c00         -call dword ptr cs:[0x4c6500]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006592) /* 0x4c6500 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9eec  8d842414050000         -lea eax, [esp + 0x514]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 004a9ef3  8d942408020000         -lea edx, [esp + 0x208]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 004a9efa  e861e80000             -call 0x4b8760
    cpu.esp -= 4;
    sub_4b8760(app, cpu);
    if (cpu.terminate) return;
    // 004a9eff  a3d0da4d00             -mov dword ptr [0x4ddad0], eax
    app->getMemory<x86::reg32>(x86::reg32(5102288) /* 0x4ddad0 */) = cpu.eax;
    // 004a9f04  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a9f06  e89ae80000             -call 0x4b87a5
    cpu.esp -= 4;
    sub_4b87a5(app, cpu);
    if (cpu.terminate) return;
    // 004a9f0b  8d842408020000         -lea eax, [esp + 0x208]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 004a9f12  e81ee90000             -call 0x4b8835
    cpu.esp -= 4;
    sub_4b8835(app, cpu);
    if (cpu.terminate) return;
    // 004a9f17  a3dcda4d00             -mov dword ptr [0x4ddadc], eax
    app->getMemory<x86::reg32>(x86::reg32(5102300) /* 0x4ddadc */) = cpu.eax;
L_0x004a9f1c:
    // 004a9f1c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a9f21:
    // 004a9f21  81c418060000           -add esp, 0x618
    (cpu.esp) += x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 004a9f27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9f2b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9f2b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9f2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9f2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9f2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9f2f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9f31  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a9f33  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a9f35  2eff1508654c00         -call dword ptr cs:[0x4c6508]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006600) /* 0x4c6508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9f3c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9f3e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a9f40  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9f42  e8b9fdffff             -call 0x4a9d00
    cpu.esp -= 4;
    sub_4a9d00(app, cpu);
    if (cpu.terminate) return;
    // 004a9f47  bae8da4d00             -mov edx, 0x4ddae8
    cpu.edx = 5102312 /*0x4ddae8*/;
    // 004a9f4c  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9f52  e805e90000             -call 0x4b885c
    cpu.esp -= 4;
    sub_4b885c(app, cpu);
    if (cpu.terminate) return;
    // 004a9f57  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a9f59  e885ed0000             -call 0x4b8ce3
    cpu.esp -= 4;
    sub_4b8ce3(app, cpu);
    if (cpu.terminate) return;
    // 004a9f5e  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 004a9f63  e8c8630000             -call 0x4b0330
    cpu.esp -= 4;
    sub_4b0330(app, cpu);
    if (cpu.terminate) return;
    // 004a9f68  ff1598ed4d00           -call dword ptr [0x4ded98]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107096) /* 0x4ded98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9f6e  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004a9f73  e8b8630000             -call 0x4b0330
    cpu.esp -= 4;
    sub_4b0330(app, cpu);
    if (cpu.terminate) return;
    // 004a9f78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9f7d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9f7d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9f7f  833dac675b0000         +cmp dword ptr [0x5b67ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5990316) /* 0x5b67ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9f86  7418                   -je 0x4a9fa0
    if (cpu.flags.zf)
    {
        goto L_0x004a9fa0;
    }
    // 004a9f88  833da0ed4d0000         +cmp dword ptr [0x4deda0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107104) /* 0x4deda0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9f8f  7426                   -je 0x4a9fb7
    if (cpu.flags.zf)
    {
        goto L_0x004a9fb7;
    }
    // 004a9f91  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004a9f96  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9f98  ff15a0ed4d00           -call dword ptr [0x4deda0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107104) /* 0x4deda0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9f9e  eb17                   -jmp 0x4a9fb7
    goto L_0x004a9fb7;
L_0x004a9fa0:
    // 004a9fa0  e88aed0000             -call 0x4b8d2f
    cpu.esp -= 4;
    sub_4b8d2f(app, cpu);
    if (cpu.terminate) return;
    // 004a9fa5  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004a9faa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9fac  e8cb630000             -call 0x4b037c
    cpu.esp -= 4;
    sub_4b037c(app, cpu);
    if (cpu.terminate) return;
    // 004a9fb1  ff1594ed4d00           -call dword ptr [0x4ded94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107092) /* 0x4ded94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a9fb7:
    // 004a9fb7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9fb8  2eff1584644c00         -call dword ptr cs:[0x4c6484]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006468) /* 0x4c6484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9fbf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9fc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9fc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9fc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9fc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9fc4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9fc6  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a9fc9  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9fcf  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9fd2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a9fd5  83fb01                 +cmp ebx, 1
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
    // 004a9fd8  741e                   -je 0x4a9ff8
    if (cpu.flags.zf)
    {
        goto L_0x004a9ff8;
    }
    // 004a9fda  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a9fdc  7413                   -je 0x4a9ff1
    if (cpu.flags.zf)
    {
        goto L_0x004a9ff1;
    }
    // 004a9fde  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a9fe1  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9fe7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a9fec  e98d000000             -jmp 0x4aa07e
    goto L_0x004aa07e;
L_0x004a9ff1:
    // 004a9ff1  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004a9ff8:
    // 004a9ff8  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004a9ffc  7515                   -jne 0x4aa013
    if (!cpu.flags.zf)
    {
        goto L_0x004aa013;
    }
    // 004a9ffe  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004aa003  e8a8c6ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004aa008  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004aa00c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004aa011  eb1f                   -jmp 0x4aa032
    goto L_0x004aa032;
L_0x004aa013:
    // 004aa013  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aa016  4e                     -dec esi
    (cpu.esi)--;
    // 004aa017  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004aa01a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004aa01c  7d0b                   -jge 0x4aa029
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aa029;
    }
    // 004aa01e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa020  e85f000000             -call 0x4aa084
    cpu.esp -= 4;
    sub_4aa084(app, cpu);
    if (cpu.terminate) return;
    // 004aa025  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa027  eb09                   -jmp 0x4aa032
    goto L_0x004aa032;
L_0x004aa029:
    // 004aa029  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa02b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa02d  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004aa02f  40                     -inc eax
    (cpu.eax)++;
    // 004aa030  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004aa032:
    // 004aa032  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 004aa036  753b                   -jne 0x4aa073
    if (!cpu.flags.zf)
    {
        goto L_0x004aa073;
    }
    // 004aa038  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa03b  7523                   -jne 0x4aa060
    if (!cpu.flags.zf)
    {
        goto L_0x004aa060;
    }
    // 004aa03d  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aa040  4d                     -dec ebp
    (cpu.ebp)--;
    // 004aa041  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004aa044  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004aa046  7d0b                   -jge 0x4aa053
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aa053;
    }
    // 004aa048  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa04a  e835000000             -call 0x4aa084
    cpu.esp -= 4;
    sub_4aa084(app, cpu);
    if (cpu.terminate) return;
    // 004aa04f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa051  eb0d                   -jmp 0x4aa060
    goto L_0x004aa060;
L_0x004aa053:
    // 004aa053  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa055  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004aa057  40                     -inc eax
    (cpu.eax)++;
    // 004aa058  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa05e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004aa060:
    // 004aa060  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa063  750e                   -jne 0x4aa073
    if (!cpu.flags.zf)
    {
        goto L_0x004aa073;
    }
    // 004aa065  8a6a0c                 -mov ch, byte ptr [edx + 0xc]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004aa068  80cd10                 -or ch, 0x10
    cpu.ch |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004aa06b  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004aa070  886a0c                 -mov byte ptr [edx + 0xc], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ch;
L_0x004aa073:
    // 004aa073  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004aa076  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aa07c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004aa07e:
    // 004aa07e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa07f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa081  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa082  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa083  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9fbf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a9fbf;
    // 004a9f7d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9f7f  833dac675b0000         +cmp dword ptr [0x5b67ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5990316) /* 0x5b67ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9f86  7418                   -je 0x4a9fa0
    if (cpu.flags.zf)
    {
        goto L_0x004a9fa0;
    }
    // 004a9f88  833da0ed4d0000         +cmp dword ptr [0x4deda0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107104) /* 0x4deda0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9f8f  7426                   -je 0x4a9fb7
    if (cpu.flags.zf)
    {
        goto L_0x004a9fb7;
    }
    // 004a9f91  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004a9f96  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9f98  ff15a0ed4d00           -call dword ptr [0x4deda0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107104) /* 0x4deda0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9f9e  eb17                   -jmp 0x4a9fb7
    goto L_0x004a9fb7;
L_0x004a9fa0:
    // 004a9fa0  e88aed0000             -call 0x4b8d2f
    cpu.esp -= 4;
    sub_4b8d2f(app, cpu);
    if (cpu.terminate) return;
    // 004a9fa5  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004a9faa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9fac  e8cb630000             -call 0x4b037c
    cpu.esp -= 4;
    sub_4b037c(app, cpu);
    if (cpu.terminate) return;
    // 004a9fb1  ff1594ed4d00           -call dword ptr [0x4ded94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107092) /* 0x4ded94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a9fb7:
    // 004a9fb7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9fb8  2eff1584644c00         -call dword ptr cs:[0x4c6484]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006468) /* 0x4c6484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x004a9fbf:
    // 004a9fbf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9fc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9fc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9fc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9fc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9fc4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9fc6  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a9fc9  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9fcf  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9fd2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a9fd5  83fb01                 +cmp ebx, 1
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
    // 004a9fd8  741e                   -je 0x4a9ff8
    if (cpu.flags.zf)
    {
        goto L_0x004a9ff8;
    }
    // 004a9fda  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a9fdc  7413                   -je 0x4a9ff1
    if (cpu.flags.zf)
    {
        goto L_0x004a9ff1;
    }
    // 004a9fde  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a9fe1  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9fe7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a9fec  e98d000000             -jmp 0x4aa07e
    goto L_0x004aa07e;
L_0x004a9ff1:
    // 004a9ff1  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004a9ff8:
    // 004a9ff8  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004a9ffc  7515                   -jne 0x4aa013
    if (!cpu.flags.zf)
    {
        goto L_0x004aa013;
    }
    // 004a9ffe  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004aa003  e8a8c6ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004aa008  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004aa00c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004aa011  eb1f                   -jmp 0x4aa032
    goto L_0x004aa032;
L_0x004aa013:
    // 004aa013  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aa016  4e                     -dec esi
    (cpu.esi)--;
    // 004aa017  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004aa01a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004aa01c  7d0b                   -jge 0x4aa029
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aa029;
    }
    // 004aa01e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa020  e85f000000             -call 0x4aa084
    cpu.esp -= 4;
    sub_4aa084(app, cpu);
    if (cpu.terminate) return;
    // 004aa025  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa027  eb09                   -jmp 0x4aa032
    goto L_0x004aa032;
L_0x004aa029:
    // 004aa029  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa02b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa02d  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004aa02f  40                     -inc eax
    (cpu.eax)++;
    // 004aa030  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004aa032:
    // 004aa032  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 004aa036  753b                   -jne 0x4aa073
    if (!cpu.flags.zf)
    {
        goto L_0x004aa073;
    }
    // 004aa038  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa03b  7523                   -jne 0x4aa060
    if (!cpu.flags.zf)
    {
        goto L_0x004aa060;
    }
    // 004aa03d  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aa040  4d                     -dec ebp
    (cpu.ebp)--;
    // 004aa041  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004aa044  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004aa046  7d0b                   -jge 0x4aa053
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aa053;
    }
    // 004aa048  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa04a  e835000000             -call 0x4aa084
    cpu.esp -= 4;
    sub_4aa084(app, cpu);
    if (cpu.terminate) return;
    // 004aa04f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa051  eb0d                   -jmp 0x4aa060
    goto L_0x004aa060;
L_0x004aa053:
    // 004aa053  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa055  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004aa057  40                     -inc eax
    (cpu.eax)++;
    // 004aa058  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa05e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004aa060:
    // 004aa060  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa063  750e                   -jne 0x4aa073
    if (!cpu.flags.zf)
    {
        goto L_0x004aa073;
    }
    // 004aa065  8a6a0c                 -mov ch, byte ptr [edx + 0xc]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004aa068  80cd10                 -or ch, 0x10
    cpu.ch |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004aa06b  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004aa070  886a0c                 -mov byte ptr [edx + 0xc], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ch;
L_0x004aa073:
    // 004aa073  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004aa076  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aa07c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004aa07e:
    // 004aa07e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa07f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa081  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa082  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa083  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa084(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa084  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa085  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa086  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa087  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aa089  e825000000             -call 0x4aa0b3
    cpu.esp -= 4;
    sub_4aa0b3(app, cpu);
    if (cpu.terminate) return;
    // 004aa08e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aa090  7509                   -jne 0x4aa09b
    if (!cpu.flags.zf)
    {
        goto L_0x004aa09b;
    }
    // 004aa092  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004aa097  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa098  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa099  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa09a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa09b:
    // 004aa09b  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aa09e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa0a0  4b                     -dec ebx
    (cpu.ebx)--;
    // 004aa0a1  41                     -inc ecx
    (cpu.ecx)++;
    // 004aa0a2  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004aa0a5  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004aa0a7  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004aa0aa  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa0af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa0b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa0b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa0b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa0b3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa0b3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa0b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa0b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa0b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa0b7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aa0b9  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004aa0bc  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004aa0c0  7507                   -jne 0x4aa0c9
    if (!cpu.flags.zf)
    {
        goto L_0x004aa0c9;
    }
    // 004aa0c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa0c4  e842610000             -call 0x4b020b
    cpu.esp -= 4;
    sub_4b020b(app, cpu);
    if (cpu.terminate) return;
L_0x004aa0c9:
    // 004aa0c9  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004aa0cc  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 004aa0cf  740f                   -je 0x4aa0e0
    if (cpu.flags.zf)
    {
        goto L_0x004aa0e0;
    }
    // 004aa0d1  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 004aa0d4  740a                   -je 0x4aa0e0
    if (cpu.flags.zf)
    {
        goto L_0x004aa0e0;
    }
    // 004aa0d6  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 004aa0db  e878ec0000             -call 0x4b8d58
    cpu.esp -= 4;
    sub_4b8d58(app, cpu);
    if (cpu.terminate) return;
L_0x004aa0e0:
    // 004aa0e0  8a710c                 -mov dh, byte ptr [ecx + 0xc]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004aa0e3  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004aa0e6  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004aa0e9  88710c                 -mov byte ptr [ecx + 0xc], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dh;
    // 004aa0ec  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004aa0ef  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004aa0f1  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004aa0f4  2500240000             -and eax, 0x2400
    cpu.eax &= x86::reg32(x86::sreg32(9216 /*0x2400*/));
    // 004aa0f9  3d00240000             +cmp eax, 0x2400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9216 /*0x2400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa0fe  7523                   -jne 0x4aa123
    if (!cpu.flags.zf)
    {
        goto L_0x004aa123;
    }
    // 004aa100  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa103  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aa105  751c                   -jne 0x4aa123
    if (!cpu.flags.zf)
    {
        goto L_0x004aa123;
    }
    // 004aa107  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004aa10a  e884ec0000             -call 0x4b8d93
    cpu.esp -= 4;
    sub_4b8d93(app, cpu);
    if (cpu.terminate) return;
    // 004aa10f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aa111  83f8ff                 +cmp eax, -1
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
    // 004aa114  742a                   -je 0x4aa140
    if (cpu.flags.zf)
    {
        goto L_0x004aa140;
    }
    // 004aa116  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004aa118  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004aa11a  c7410401000000         -mov dword ptr [ecx + 4], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004aa121  eb3c                   -jmp 0x4aa15f
    goto L_0x004aa15f;
L_0x004aa123:
    // 004aa123  f6410d04               +test byte ptr [ecx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004aa127  7407                   -je 0x4aa130
    if (cpu.flags.zf)
    {
        goto L_0x004aa130;
    }
    // 004aa129  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004aa12e  eb03                   -jmp 0x4aa133
    goto L_0x004aa133;
L_0x004aa130:
    // 004aa130  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
L_0x004aa133:
    // 004aa133  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004aa135  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa138  e855610000             -call 0x4b0292
    cpu.esp -= 4;
    sub_4b0292(app, cpu);
    if (cpu.terminate) return;
    // 004aa13d  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004aa140:
    // 004aa140  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004aa143  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004aa145  7f18                   -jg 0x4aa15f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aa15f;
    }
    // 004aa147  7506                   -jne 0x4aa14f
    if (!cpu.flags.zf)
    {
        goto L_0x004aa14f;
    }
    // 004aa149  80490c10               +or byte ptr [ecx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004aa14d  eb10                   -jmp 0x4aa15f
    goto L_0x004aa15f;
L_0x004aa14f:
    // 004aa14f  8a790c                 -mov bh, byte ptr [ecx + 0xc]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004aa152  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004aa159  80cf20                 -or bh, 0x20
    cpu.bh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004aa15c  88790c                 -mov byte ptr [ecx + 0xc], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bh;
L_0x004aa15f:
    // 004aa15f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004aa162  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa163  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa164  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa165  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa166  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa167(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa167  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa168  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa169  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa16a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa16b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa16d  83f8ff                 +cmp eax, -1
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
    // 004aa170  0f84a6000000           -je 0x4aa21c
    if (cpu.flags.zf)
    {
        goto L_0x004aa21c;
    }
    // 004aa176  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004aa179  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aa17f  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004aa182  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004aa185  83f901                 +cmp ecx, 1
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
    // 004aa188  741e                   -je 0x4aa1a8
    if (cpu.flags.zf)
    {
        goto L_0x004aa1a8;
    }
    // 004aa18a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004aa18c  7413                   -je 0x4aa1a1
    if (cpu.flags.zf)
    {
        goto L_0x004aa1a1;
    }
L_0x004aa18e:
    // 004aa18e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004aa191  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aa197  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004aa19c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa19d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa19e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa19f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa1a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa1a1:
    // 004aa1a1  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004aa1a8:
    // 004aa1a8  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004aa1ac  75e0                   -jne 0x4aa18e
    if (!cpu.flags.zf)
    {
        goto L_0x004aa18e;
    }
    // 004aa1ae  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004aa1b2  74da                   -je 0x4aa18e
    if (cpu.flags.zf)
    {
        goto L_0x004aa18e;
    }
    // 004aa1b4  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004aa1b7  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004aa1bb  7507                   -jne 0x4aa1c4
    if (!cpu.flags.zf)
    {
        goto L_0x004aa1c4;
    }
    // 004aa1bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa1bf  e847600000             -call 0x4b020b
    cpu.esp -= 4;
    sub_4b020b(app, cpu);
    if (cpu.terminate) return;
L_0x004aa1c4:
    // 004aa1c4  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aa1c7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004aa1c9  7517                   -jne 0x4aa1e2
    if (!cpu.flags.zf)
    {
        goto L_0x004aa1e2;
    }
    // 004aa1cb  c7420401000000         -mov dword ptr [edx + 4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004aa1d2  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004aa1d5  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004aa1d8  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004aa1db  01c8                   +add eax, ecx
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
    // 004aa1dd  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa1de  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004aa1e0  eb21                   -jmp 0x4aa203
    goto L_0x004aa203;
L_0x004aa1e2:
    // 004aa1e2  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004aa1e5  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa1e7  3b4808                 +cmp ecx, dword ptr [eax + 8]
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
    // 004aa1ea  74a2                   -je 0x4aa18e
    if (cpu.flags.zf)
    {
        goto L_0x004aa18e;
    }
    // 004aa1ec  8d7d01                 -lea edi, [ebp + 1]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004aa1ef  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa1f1  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004aa1f4  4d                     -dec ebp
    (cpu.ebp)--;
    // 004aa1f5  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004aa1f7  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004aa1fa  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa1ff  39d8                   +cmp eax, ebx
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
    // 004aa201  7404                   -je 0x4aa207
    if (cpu.flags.zf)
    {
        goto L_0x004aa207;
    }
L_0x004aa203:
    // 004aa203  804a0c04               -or byte ptr [edx + 0xc], 4
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004aa207:
    // 004aa207  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa209  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004aa20b  80620cef               -and byte ptr [edx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004aa20f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004aa212  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aa218  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa21a  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x004aa21c:
    // 004aa21c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa21d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa21e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa21f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa220  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa221(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa221  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa222  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aa224  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aa226  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa227  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa228(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa228  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa229  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004aa22b  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aa22e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa22f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa230  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa231  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa232  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa233  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa234  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aa237  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aa239  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004aa23c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa23e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004aa242  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004aa245  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004aa247  80e4fd                 -and ah, 0xfd
    cpu.ah &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004aa24a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004aa24c  886610                 -mov byte ptr [esi + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ah;
L_0x004aa24f:
    // 004aa24f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004aa252  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004aa255  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004aa258  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004aa25a  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004aa260  0f8423020000           -je 0x4aa489
    if (cpu.flags.zf)
    {
        goto L_0x004aa489;
    }
    // 004aa266  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004aa268  fec0                   -inc al
    (cpu.al)++;
    // 004aa26a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa26f  f68064ef4d0002         +test byte ptr [eax + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004aa276  740e                   -je 0x4aa286
    if (cpu.flags.zf)
    {
        goto L_0x004aa286;
    }
    // 004aa278  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa27a  e81c030000             -call 0x4aa59b
    cpu.esp -= 4;
    sub_4aa59b(app, cpu);
    if (cpu.terminate) return;
    // 004aa27f  01c7                   +add edi, eax
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
    // 004aa281  e9cd010000             -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa286:
    // 004aa286  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa289  7425                   -je 0x4aa2b0
    if (cpu.flags.zf)
    {
        goto L_0x004aa2b0;
    }
    // 004aa28b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa28d  e88fffffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa292  39d8                   +cmp eax, ebx
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
    // 004aa294  0f84b8010000           -je 0x4aa452
    if (cpu.flags.zf)
    {
        goto L_0x004aa452;
    }
L_0x004aa29a:
    // 004aa29a  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004aa29e  0f85e5010000           -jne 0x4aa489
    if (!cpu.flags.zf)
    {
        goto L_0x004aa489;
    }
    // 004aa2a4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004aa2a6  e87dffffff             -call 0x4aa228
    cpu.esp -= 4;
    sub_4aa228(app, cpu);
    if (cpu.terminate) return;
    // 004aa2ab  e9d9010000             -jmp 0x4aa489
    goto L_0x004aa489;
L_0x004aa2b0:
    // 004aa2b0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aa2b3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004aa2b5  e8ea010000             -call 0x4aa4a4
    cpu.esp -= 4;
    sub_4aa4a4(app, cpu);
    if (cpu.terminate) return;
    // 004aa2ba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa2bc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004aa2bf  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004aa2c1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aa2c3  7404                   -je 0x4aa2c9
    if (cpu.flags.zf)
    {
        goto L_0x004aa2c9;
    }
    // 004aa2c5  40                     -inc eax
    (cpu.eax)++;
    // 004aa2c6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004aa2c9:
    // 004aa2c9  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa2cc  7265                   -jb 0x4aa333
    if (cpu.flags.cf)
    {
        goto L_0x004aa333;
    }
    // 004aa2ce  0f86c3000000           -jbe 0x4aa397
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa397;
    }
    // 004aa2d4  83fb6f                 +cmp ebx, 0x6f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa2d7  7233                   -jb 0x4aa30c
    if (cpu.flags.cf)
    {
        goto L_0x004aa30c;
    }
    // 004aa2d9  0f86e1000000           -jbe 0x4aa3c0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa3c0;
    }
    // 004aa2df  83fb73                 +cmp ebx, 0x73
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa2e2  7223                   -jb 0x4aa307
    if (cpu.flags.cf)
    {
        goto L_0x004aa307;
    }
    // 004aa2e4  0f860e010000           -jbe 0x4aa3f8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa3f8;
    }
    // 004aa2ea  83fb75                 +cmp ebx, 0x75
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa2ed  0f8260010000           -jb 0x4aa453
    if (cpu.flags.cf)
    {
        goto L_0x004aa453;
    }
    // 004aa2f3  0f86d3000000           -jbe 0x4aa3cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa3cc;
    }
    // 004aa2f9  83fb78                 +cmp ebx, 0x78
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x004aa2fc:
    // 004aa2fc  0f84d9000000           -je 0x4aa3db
    if (cpu.flags.zf)
    {
        goto L_0x004aa3db;
    }
    // 004aa302  e94c010000             -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa307:
    // 004aa307  83fb70                 +cmp ebx, 0x70
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa30a  ebf0                   -jmp 0x4aa2fc
    goto L_0x004aa2fc;
L_0x004aa30c:
    // 004aa30c  83fb69                 +cmp ebx, 0x69
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa30f  7214                   -jb 0x4aa325
    if (cpu.flags.cf)
    {
        goto L_0x004aa325;
    }
    // 004aa311  0f869a000000           -jbe 0x4aa3b1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa3b1;
    }
    // 004aa317  83fb6e                 +cmp ebx, 0x6e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa31a  0f8414010000           -je 0x4aa434
    if (cpu.flags.zf)
    {
        goto L_0x004aa434;
    }
    // 004aa320  e92e010000             -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa325:
    // 004aa325  83fb67                 +cmp ebx, 0x67
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa328  0f86b9000000           -jbe 0x4aa3e7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa3e7;
    }
    // 004aa32e  e920010000             -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa333:
    // 004aa333  83fb47                 +cmp ebx, 0x47
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa336  723c                   -jb 0x4aa374
    if (cpu.flags.cf)
    {
        goto L_0x004aa374;
    }
    // 004aa338  0f86a9000000           -jbe 0x4aa3e7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa3e7;
    }
    // 004aa33e  83fb58                 +cmp ebx, 0x58
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa341  7223                   -jb 0x4aa366
    if (cpu.flags.cf)
    {
        goto L_0x004aa366;
    }
    // 004aa343  0f8692000000           -jbe 0x4aa3db
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa3db;
    }
    // 004aa349  83fb5b                 +cmp ebx, 0x5b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa34c  0f8201010000           -jb 0x4aa453
    if (cpu.flags.cf)
    {
        goto L_0x004aa453;
    }
    // 004aa352  0f86ad000000           -jbe 0x4aa405
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa405;
    }
    // 004aa358  83fb63                 +cmp ebx, 0x63
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa35b  0f84b7000000           -je 0x4aa418
    if (cpu.flags.zf)
    {
        goto L_0x004aa418;
    }
    // 004aa361  e9ed000000             -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa366:
    // 004aa366  83fb53                 +cmp ebx, 0x53
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(83 /*0x53*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa369  0f8485000000           -je 0x4aa3f4
    if (cpu.flags.zf)
    {
        goto L_0x004aa3f4;
    }
    // 004aa36f  e9df000000             -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa374:
    // 004aa374  83fb43                 +cmp ebx, 0x43
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa377  7210                   -jb 0x4aa389
    if (cpu.flags.cf)
    {
        goto L_0x004aa389;
    }
    // 004aa379  0f8695000000           -jbe 0x4aa414
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa414;
    }
    // 004aa37f  83fb45                 +cmp ebx, 0x45
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa382  7463                   -je 0x4aa3e7
    if (cpu.flags.zf)
    {
        goto L_0x004aa3e7;
    }
    // 004aa384  e9ca000000             -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa389:
    // 004aa389  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa38c  0f84b1000000           -je 0x4aa443
    if (cpu.flags.zf)
    {
        goto L_0x004aa443;
    }
    // 004aa392  e9bc000000             -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa397:
    // 004aa397  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004aa39c  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
L_0x004aa3a1:
    // 004aa3a1  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa3a5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004aa3a7:
    // 004aa3a7  e8c8080000             -call 0x4aac74
    cpu.esp -= 4;
    sub_4aac74(app, cpu);
    if (cpu.terminate) return;
    // 004aa3ac  e972000000             -jmp 0x4aa423
    goto L_0x004aa423;
L_0x004aa3b1:
    // 004aa3b1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004aa3b6  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa3ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa3bc  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004aa3be  ebe7                   -jmp 0x4aa3a7
    goto L_0x004aa3a7;
L_0x004aa3c0:
    // 004aa3c0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004aa3c5  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004aa3ca  ebd5                   -jmp 0x4aa3a1
    goto L_0x004aa3a1;
L_0x004aa3cc:
    // 004aa3cc  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004aa3d1  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa3d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa3d7  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004aa3d9  ebcc                   -jmp 0x4aa3a7
    goto L_0x004aa3a7;
L_0x004aa3db:
    // 004aa3db  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004aa3e0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004aa3e5  ebba                   -jmp 0x4aa3a1
    goto L_0x004aa3a1;
L_0x004aa3e7:
    // 004aa3e7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa3eb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa3ed  e8ac050000             -call 0x4aa99e
    cpu.esp -= 4;
    sub_4aa99e(app, cpu);
    if (cpu.terminate) return;
    // 004aa3f2  eb2f                   -jmp 0x4aa423
    goto L_0x004aa423;
L_0x004aa3f4:
    // 004aa3f4  804e1020               +or byte ptr [esi + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
L_0x004aa3f8:
    // 004aa3f8  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa3fc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa3fe  e8b1020000             -call 0x4aa6b4
    cpu.esp -= 4;
    sub_4aa6b4(app, cpu);
    if (cpu.terminate) return;
    // 004aa403  eb1e                   -jmp 0x4aa423
    goto L_0x004aa423;
L_0x004aa405:
    // 004aa405  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004aa407  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa40b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa40d  e896040000             -call 0x4aa8a8
    cpu.esp -= 4;
    sub_4aa8a8(app, cpu);
    if (cpu.terminate) return;
    // 004aa412  eb0f                   -jmp 0x4aa423
    goto L_0x004aa423;
L_0x004aa414:
    // 004aa414  804e1020               -or byte ptr [esi + 0x10], 0x20
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004aa418:
    // 004aa418  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa41c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa41e  e8af010000             -call 0x4aa5d2
    cpu.esp -= 4;
    sub_4aa5d2(app, cpu);
    if (cpu.terminate) return;
L_0x004aa423:
    // 004aa423  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa425  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aa427  7e60                   -jle 0x4aa489
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aa489;
    }
    // 004aa429  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa42b  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004aa42f  7422                   -je 0x4aa453
    if (cpu.flags.zf)
    {
        goto L_0x004aa453;
    }
    // 004aa431  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aa432  eb1f                   -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa434:
    // 004aa434  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa438  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004aa43a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa43c  e8c6030000             -call 0x4aa807
    cpu.esp -= 4;
    sub_4aa807(app, cpu);
    if (cpu.terminate) return;
    // 004aa441  eb10                   -jmp 0x4aa453
    goto L_0x004aa453;
L_0x004aa443:
    // 004aa443  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa445  e8d7fdffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa44a  39d8                   +cmp eax, ebx
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
    // 004aa44c  0f8548feffff           -jne 0x4aa29a
    if (!cpu.flags.zf)
    {
        goto L_0x004aa29a;
    }
L_0x004aa452:
    // 004aa452  47                     -inc edi
    (cpu.edi)++;
L_0x004aa453:
    // 004aa453  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004aa457  0f84f2fdffff           -je 0x4aa24f
    if (cpu.flags.zf)
    {
        goto L_0x004aa24f;
    }
    // 004aa45d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aa460  803825                 +cmp byte ptr [eax], 0x25
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa463  7524                   -jne 0x4aa489
    if (!cpu.flags.zf)
    {
        goto L_0x004aa489;
    }
    // 004aa465  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004aa468  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004aa46a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aa46c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004aa46f  e830000000             -call 0x4aa4a4
    cpu.esp -= 4;
    sub_4aa4a4(app, cpu);
    if (cpu.terminate) return;
    // 004aa474  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004aa477  80386e                 +cmp byte ptr [eax], 0x6e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa47a  750d                   -jne 0x4aa489
    if (!cpu.flags.zf)
    {
        goto L_0x004aa489;
    }
    // 004aa47c  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa480  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004aa482  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa484  e87e030000             -call 0x4aa807
    cpu.esp -= 4;
    sub_4aa807(app, cpu);
    if (cpu.terminate) return;
L_0x004aa489:
    // 004aa489  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004aa48b  750d                   -jne 0x4aa49a
    if (!cpu.flags.zf)
    {
        goto L_0x004aa49a;
    }
    // 004aa48d  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004aa491  7407                   -je 0x4aa49a
    if (cpu.flags.zf)
    {
        goto L_0x004aa49a;
    }
    // 004aa493  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004aa498  eb02                   -jmp 0x4aa49c
    goto L_0x004aa49c;
L_0x004aa49a:
    // 004aa49a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004aa49c:
    // 004aa49c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aa49f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa4a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa4a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa4a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa4a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa4a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa4a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa4a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa4a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa4a7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa4aa  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004aa4ac  8a5210                 -mov dl, byte ptr [edx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004aa4af  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004aa4b2  885310                 -mov byte ptr [ebx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004aa4b5  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004aa4b7  c7430cffffffff         -mov dword ptr [ebx + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 004aa4be  80e603                 -and dh, 3
    cpu.dh &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004aa4c1  887310                 -mov byte ptr [ebx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 004aa4c4  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa4c7  750a                   -jne 0x4aa4d3
    if (!cpu.flags.zf)
    {
        goto L_0x004aa4d3;
    }
    // 004aa4c9  8a6b10                 -mov ch, byte ptr [ebx + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004aa4cc  80e5fe                 -and ch, 0xfe
    cpu.ch &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004aa4cf  40                     -inc eax
    (cpu.eax)++;
    // 004aa4d0  886b10                 -mov byte ptr [ebx + 0x10], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ch;
L_0x004aa4d3:
    // 004aa4d3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aa4d5  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004aa4d7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004aa4da  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 004aa4dd  fec2                   -inc dl
    (cpu.dl)++;
    // 004aa4df  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa4e5  f68264ef4d0020         +test byte ptr [edx + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004aa4ec  7428                   -je 0x4aa516
    if (cpu.flags.zf)
    {
        goto L_0x004aa516;
    }
    // 004aa4ee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004aa4f0:
    // 004aa4f0  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004aa4f3  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004aa4f6  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004aa4f9  40                     -inc eax
    (cpu.eax)++;
    // 004aa4fa  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aa4fc  0fb630                 -movzx esi, byte ptr [eax]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 004aa4ff  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004aa502  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004aa505  fec1                   -inc cl
    (cpu.cl)++;
    // 004aa507  0fb6f1                 -movzx esi, cl
    cpu.esi = x86::reg32(cpu.cl);
    // 004aa50a  f68664ef4d0020         +test byte ptr [esi + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004aa511  75dd                   -jne 0x4aa4f0
    if (!cpu.flags.zf)
    {
        goto L_0x004aa4f0;
    }
    // 004aa513  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004aa516:
    // 004aa516  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004aa518  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004aa51b  80f94e                 +cmp cl, 0x4e
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa51e  7506                   -jne 0x4aa526
    if (!cpu.flags.zf)
    {
        goto L_0x004aa526;
    }
    // 004aa520  804b1008               +or byte ptr [ebx + 0x10], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004aa524  eb09                   -jmp 0x4aa52f
    goto L_0x004aa52f;
L_0x004aa526:
    // 004aa526  80f946                 +cmp cl, 0x46
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa529  7506                   -jne 0x4aa531
    if (!cpu.flags.zf)
    {
        goto L_0x004aa531;
    }
    // 004aa52b  804b1004               -or byte ptr [ebx + 0x10], 4
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004aa52f:
    // 004aa52f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004aa531:
    // 004aa531  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004aa533  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004aa536  80fa68                 +cmp dl, 0x68
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa539  7210                   -jb 0x4aa54b
    if (cpu.flags.cf)
    {
        goto L_0x004aa54b;
    }
    // 004aa53b  761c                   -jbe 0x4aa559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa559;
    }
    // 004aa53d  80fa6c                 +cmp dl, 0x6c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa540  7252                   -jb 0x4aa594
    if (cpu.flags.cf)
    {
        goto L_0x004aa594;
    }
    // 004aa542  761f                   -jbe 0x4aa563
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa563;
    }
    // 004aa544  80fa77                 +cmp dl, 0x77
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa547  741a                   -je 0x4aa563
    if (cpu.flags.zf)
    {
        goto L_0x004aa563;
    }
    // 004aa549  eb49                   -jmp 0x4aa594
    goto L_0x004aa594;
L_0x004aa54b:
    // 004aa54b  80fa49                 +cmp dl, 0x49
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa54e  7244                   -jb 0x4aa594
    if (cpu.flags.cf)
    {
        goto L_0x004aa594;
    }
    // 004aa550  762a                   -jbe 0x4aa57c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa57c;
    }
    // 004aa552  80fa4c                 +cmp dl, 0x4c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(76 /*0x4c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa555  7418                   -je 0x4aa56f
    if (cpu.flags.zf)
    {
        goto L_0x004aa56f;
    }
    // 004aa557  eb3b                   -jmp 0x4aa594
    goto L_0x004aa594;
L_0x004aa559:
    // 004aa559  8a7310                 -mov dh, byte ptr [ebx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004aa55c  80ce10                 +or dh, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dh |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004aa55f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa561  eb2e                   -jmp 0x4aa591
    goto L_0x004aa591;
L_0x004aa563:
    // 004aa563  8a5310                 -mov dl, byte ptr [ebx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004aa566  80ca20                 +or dl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004aa569  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aa56a  885310                 -mov byte ptr [ebx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004aa56d  eb25                   -jmp 0x4aa594
    goto L_0x004aa594;
L_0x004aa56f:
    // 004aa56f  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004aa572  80c940                 +or cl, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 004aa575  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa577  884b10                 -mov byte ptr [ebx + 0x10], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.cl;
    // 004aa57a  eb18                   -jmp 0x4aa594
    goto L_0x004aa594;
L_0x004aa57c:
    // 004aa57c  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa580  7512                   -jne 0x4aa594
    if (!cpu.flags.zf)
    {
        goto L_0x004aa594;
    }
    // 004aa582  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa586  750c                   -jne 0x4aa594
    if (!cpu.flags.zf)
    {
        goto L_0x004aa594;
    }
    // 004aa588  8a7310                 -mov dh, byte ptr [ebx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004aa58b  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004aa58e  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004aa591:
    // 004aa591  887310                 -mov byte ptr [ebx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dh;
L_0x004aa594:
    // 004aa594  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa597  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa598  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa599  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa59a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa59b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa59b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa59c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa59d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa59e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa5a0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004aa5a2:
    // 004aa5a2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aa5a4  e878fcffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa5a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aa5ab  fec2                   -inc dl
    (cpu.dl)++;
    // 004aa5ad  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa5b3  f68264ef4d0002         +test byte ptr [edx + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004aa5ba  7403                   -je 0x4aa5bf
    if (cpu.flags.zf)
    {
        goto L_0x004aa5bf;
    }
    // 004aa5bc  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aa5bd  ebe3                   -jmp 0x4aa5a2
    goto L_0x004aa5a2;
L_0x004aa5bf:
    // 004aa5bf  f6431002               +test byte ptr [ebx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004aa5c3  7507                   -jne 0x4aa5cc
    if (!cpu.flags.zf)
    {
        goto L_0x004aa5cc;
    }
    // 004aa5c5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa5c7  e85cfcffff             -call 0x4aa228
    cpu.esp -= 4;
    sub_4aa228(app, cpu);
    if (cpu.terminate) return;
L_0x004aa5cc:
    // 004aa5cc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa5ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa5cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa5d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa5d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa5d2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa5d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa5d3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa5d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa5d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa5d6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004aa5d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa5d8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aa5db  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aa5dd  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004aa5e1  7437                   -je 0x4aa61a
    if (cpu.flags.zf)
    {
        goto L_0x004aa61a;
    }
    // 004aa5e3  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa5e6  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004aa5e9  740c                   -je 0x4aa5f7
    if (cpu.flags.zf)
    {
        goto L_0x004aa5f7;
    }
    // 004aa5eb  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa5ed  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa5f0  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004aa5f2  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 004aa5f5  eb23                   -jmp 0x4aa61a
    goto L_0x004aa61a;
L_0x004aa5f7:
    // 004aa5f7  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004aa5fa  7410                   -je 0x4aa60c
    if (cpu.flags.zf)
    {
        goto L_0x004aa60c;
    }
    // 004aa5fc  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa5fe  83c604                 +add esi, 4
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
    // 004aa601  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aa603  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004aa605  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aa607  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004aa60a  eb0e                   -jmp 0x4aa61a
    goto L_0x004aa61a;
L_0x004aa60c:
    // 004aa60c  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa60e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa611  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aa613  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004aa615  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aa617  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x004aa61a:
    // 004aa61a  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004aa61d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004aa61f  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa622  7505                   -jne 0x4aa629
    if (!cpu.flags.zf)
    {
        goto L_0x004aa629;
    }
    // 004aa624  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x004aa629:
    // 004aa629  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aa62b  0f8e77000000           -jle 0x4aa6a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aa6a8;
    }
    // 004aa631  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa633  e8e9fbffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa638  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa63b  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004aa63e  0f8564000000           -jne 0x4aa6a8
    if (!cpu.flags.zf)
    {
        goto L_0x004aa6a8;
    }
    // 004aa644  45                     -inc ebp
    (cpu.ebp)++;
    // 004aa645  4f                     -dec edi
    (cpu.edi)--;
    // 004aa646  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004aa649  74de                   -je 0x4aa629
    if (cpu.flags.zf)
    {
        goto L_0x004aa629;
    }
    // 004aa64b  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004aa64e  7452                   -je 0x4aa6a2
    if (cpu.flags.zf)
    {
        goto L_0x004aa6a2;
    }
    // 004aa650  8b15d0a35b00           -mov edx, dword ptr [0x5ba3d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
    // 004aa656  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 004aa65a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aa65c  741f                   -je 0x4aa67d
    if (cpu.flags.zf)
    {
        goto L_0x004aa67d;
    }
    // 004aa65e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa663  8a80d5a35b00           -mov al, byte ptr [eax + 0x5ba3d5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004aa669  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004aa66b  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004aa670  740b                   -je 0x4aa67d
    if (cpu.flags.zf)
    {
        goto L_0x004aa67d;
    }
    // 004aa672  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa674  e8a8fbffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa679  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x004aa67d:
    // 004aa67d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004aa682  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa686  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004aa688  e83de70000             -call 0x4b8dca
    cpu.esp -= 4;
    sub_4b8dca(app, cpu);
    if (cpu.terminate) return;
    // 004aa68d  83f8ff                 +cmp eax, -1
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
    // 004aa690  7504                   -jne 0x4aa696
    if (!cpu.flags.zf)
    {
        goto L_0x004aa696;
    }
    // 004aa692  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004aa694  eb14                   -jmp 0x4aa6aa
    goto L_0x004aa6aa;
L_0x004aa696:
    // 004aa696  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aa699  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
    // 004aa69d  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa6a0  eb87                   -jmp 0x4aa629
    goto L_0x004aa629;
L_0x004aa6a2:
    // 004aa6a2  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 004aa6a5  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aa6a6  eb81                   -jmp 0x4aa629
    goto L_0x004aa629;
L_0x004aa6a8:
    // 004aa6a8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004aa6aa:
    // 004aa6aa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aa6ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6ae  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004aa6af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa6ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004aa6ad;
    // 004aa5d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa5d3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa5d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa5d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa5d6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004aa5d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa5d8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aa5db  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aa5dd  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004aa5e1  7437                   -je 0x4aa61a
    if (cpu.flags.zf)
    {
        goto L_0x004aa61a;
    }
    // 004aa5e3  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa5e6  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004aa5e9  740c                   -je 0x4aa5f7
    if (cpu.flags.zf)
    {
        goto L_0x004aa5f7;
    }
    // 004aa5eb  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa5ed  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa5f0  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004aa5f2  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 004aa5f5  eb23                   -jmp 0x4aa61a
    goto L_0x004aa61a;
L_0x004aa5f7:
    // 004aa5f7  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004aa5fa  7410                   -je 0x4aa60c
    if (cpu.flags.zf)
    {
        goto L_0x004aa60c;
    }
    // 004aa5fc  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa5fe  83c604                 +add esi, 4
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
    // 004aa601  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aa603  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004aa605  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aa607  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004aa60a  eb0e                   -jmp 0x4aa61a
    goto L_0x004aa61a;
L_0x004aa60c:
    // 004aa60c  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa60e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa611  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aa613  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004aa615  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aa617  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x004aa61a:
    // 004aa61a  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004aa61d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004aa61f  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa622  7505                   -jne 0x4aa629
    if (!cpu.flags.zf)
    {
        goto L_0x004aa629;
    }
    // 004aa624  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x004aa629:
    // 004aa629  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aa62b  0f8e77000000           -jle 0x4aa6a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aa6a8;
    }
    // 004aa631  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa633  e8e9fbffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa638  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa63b  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004aa63e  0f8564000000           -jne 0x4aa6a8
    if (!cpu.flags.zf)
    {
        goto L_0x004aa6a8;
    }
    // 004aa644  45                     -inc ebp
    (cpu.ebp)++;
    // 004aa645  4f                     -dec edi
    (cpu.edi)--;
    // 004aa646  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004aa649  74de                   -je 0x4aa629
    if (cpu.flags.zf)
    {
        goto L_0x004aa629;
    }
    // 004aa64b  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004aa64e  7452                   -je 0x4aa6a2
    if (cpu.flags.zf)
    {
        goto L_0x004aa6a2;
    }
    // 004aa650  8b15d0a35b00           -mov edx, dword ptr [0x5ba3d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
    // 004aa656  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 004aa65a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aa65c  741f                   -je 0x4aa67d
    if (cpu.flags.zf)
    {
        goto L_0x004aa67d;
    }
    // 004aa65e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa663  8a80d5a35b00           -mov al, byte ptr [eax + 0x5ba3d5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004aa669  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004aa66b  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004aa670  740b                   -je 0x4aa67d
    if (cpu.flags.zf)
    {
        goto L_0x004aa67d;
    }
    // 004aa672  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa674  e8a8fbffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa679  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x004aa67d:
    // 004aa67d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004aa682  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa686  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004aa688  e83de70000             -call 0x4b8dca
    cpu.esp -= 4;
    sub_4b8dca(app, cpu);
    if (cpu.terminate) return;
    // 004aa68d  83f8ff                 +cmp eax, -1
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
    // 004aa690  7504                   -jne 0x4aa696
    if (!cpu.flags.zf)
    {
        goto L_0x004aa696;
    }
    // 004aa692  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004aa694  eb14                   -jmp 0x4aa6aa
    goto L_0x004aa6aa;
L_0x004aa696:
    // 004aa696  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aa699  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
    // 004aa69d  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa6a0  eb87                   -jmp 0x4aa629
    goto L_0x004aa629;
L_0x004aa6a2:
    // 004aa6a2  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 004aa6a5  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aa6a6  eb81                   -jmp 0x4aa629
    goto L_0x004aa629;
L_0x004aa6a8:
    // 004aa6a8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004aa6aa:
    // 004aa6aa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_entry_0x004aa6ad:
    // 004aa6ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6ae  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004aa6af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa6b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa6b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa6b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa6b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa6b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa6b8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004aa6b9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa6ba  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aa6bd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aa6bf  f6401020               +test byte ptr [eax + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 004aa6c3  7407                   -je 0x4aa6cc
    if (cpu.flags.zf)
    {
        goto L_0x004aa6cc;
    }
    // 004aa6c5  c644240802             -mov byte ptr [esp + 8], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 2 /*0x2*/;
    // 004aa6ca  eb09                   -jmp 0x4aa6d5
    goto L_0x004aa6d5;
L_0x004aa6cc:
    // 004aa6cc  f6411010               -test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004aa6d0  c644240801             -mov byte ptr [esp + 8], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x004aa6d5:
    // 004aa6d5  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa6d8  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004aa6db  7434                   -je 0x4aa711
    if (cpu.flags.zf)
    {
        goto L_0x004aa711;
    }
    // 004aa6dd  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004aa6e0  740c                   -je 0x4aa6ee
    if (cpu.flags.zf)
    {
        goto L_0x004aa6ee;
    }
    // 004aa6e2  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa6e4  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa6e7  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004aa6e9  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 004aa6ec  eb23                   -jmp 0x4aa711
    goto L_0x004aa711;
L_0x004aa6ee:
    // 004aa6ee  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004aa6f1  7410                   -je 0x4aa703
    if (cpu.flags.zf)
    {
        goto L_0x004aa703;
    }
    // 004aa6f3  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa6f5  83c604                 +add esi, 4
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
    // 004aa6f8  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aa6fa  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004aa6fc  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aa6fe  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004aa701  eb0e                   -jmp 0x4aa711
    goto L_0x004aa711;
L_0x004aa703:
    // 004aa703  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa705  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa708  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aa70a  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004aa70c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aa70e  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x004aa711:
    // 004aa711  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004aa713:
    // 004aa713  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa715  e807fbffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa71a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa71c  fec0                   -inc al
    (cpu.al)++;
    // 004aa71e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa723  f68064ef4d0002         +test byte ptr [eax + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004aa72a  7403                   -je 0x4aa72f
    if (cpu.flags.zf)
    {
        goto L_0x004aa72f;
    }
    // 004aa72c  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aa72d  ebe4                   -jmp 0x4aa713
    goto L_0x004aa713;
L_0x004aa72f:
    // 004aa72f  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004aa733  7407                   -je 0x4aa73c
    if (cpu.flags.zf)
    {
        goto L_0x004aa73c;
    }
    // 004aa735  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004aa737  e9a4000000             -jmp 0x4aa7e0
    goto L_0x004aa7e0;
L_0x004aa73c:
    // 004aa73c  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004aa73f  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004aa742  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004aa745  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aa747  0f848a000000           -je 0x4aa7d7
    if (cpu.flags.zf)
    {
        goto L_0x004aa7d7;
    }
L_0x004aa74d:
    // 004aa74d  8a4110                 -mov al, byte ptr [ecx + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa750  47                     -inc edi
    (cpu.edi)++;
    // 004aa751  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004aa753  7460                   -je 0x4aa7b5
    if (cpu.flags.zf)
    {
        goto L_0x004aa7b5;
    }
    // 004aa755  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa75a  7505                   -jne 0x4aa761
    if (!cpu.flags.zf)
    {
        goto L_0x004aa761;
    }
    // 004aa75c  26881e                 -mov byte ptr es:[esi], bl
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.bl;
    // 004aa75f  eb4c                   -jmp 0x4aa7ad
    goto L_0x004aa7ad;
L_0x004aa761:
    // 004aa761  8b2dd0a35b00           -mov ebp, dword ptr [0x5ba3d0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
    // 004aa767  885c2404               -mov byte ptr [esp + 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 004aa76b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004aa76d  741e                   -je 0x4aa78d
    if (cpu.flags.zf)
    {
        goto L_0x004aa78d;
    }
    // 004aa76f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa771  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004aa773  8a80d5a35b00           -mov al, byte ptr [eax + 0x5ba3d5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004aa779  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004aa77b  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004aa780  740b                   -je 0x4aa78d
    if (cpu.flags.zf)
    {
        goto L_0x004aa78d;
    }
    // 004aa782  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa784  e898faffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa789  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x004aa78d:
    // 004aa78d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004aa792  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa796  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004aa798  e82de60000             -call 0x4b8dca
    cpu.esp -= 4;
    sub_4b8dca(app, cpu);
    if (cpu.terminate) return;
    // 004aa79d  83f8ff                 +cmp eax, -1
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
    // 004aa7a0  7504                   -jne 0x4aa7a6
    if (!cpu.flags.zf)
    {
        goto L_0x004aa7a6;
    }
    // 004aa7a2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004aa7a4  eb59                   -jmp 0x4aa7ff
    goto L_0x004aa7ff;
L_0x004aa7a6:
    // 004aa7a6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aa7a9  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
L_0x004aa7ad:
    // 004aa7ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa7af  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aa7b3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004aa7b5:
    // 004aa7b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa7b7  e8e4080000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aa7bc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa7be  83f8ff                 +cmp eax, -1
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
    // 004aa7c1  741d                   -je 0x4aa7e0
    if (cpu.flags.zf)
    {
        goto L_0x004aa7e0;
    }
    // 004aa7c3  fec0                   -inc al
    (cpu.al)++;
    // 004aa7c5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa7ca  f68064ef4d0002         +test byte ptr [eax + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004aa7d1  0f8476ffffff           -je 0x4aa74d
    if (cpu.flags.zf)
    {
        goto L_0x004aa74d;
    }
L_0x004aa7d7:
    // 004aa7d7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aa7d9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aa7db  e848faffff             -call 0x4aa228
    cpu.esp -= 4;
    sub_4aa228(app, cpu);
    if (cpu.terminate) return;
L_0x004aa7e0:
    // 004aa7e0  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004aa7e4  7417                   -je 0x4aa7fd
    if (cpu.flags.zf)
    {
        goto L_0x004aa7fd;
    }
    // 004aa7e6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aa7e8  7e13                   -jle 0x4aa7fd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aa7fd;
    }
    // 004aa7ea  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa7ef  7506                   -jne 0x4aa7f7
    if (!cpu.flags.zf)
    {
        goto L_0x004aa7f7;
    }
    // 004aa7f1  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
    // 004aa7f5  eb06                   -jmp 0x4aa7fd
    goto L_0x004aa7fd;
L_0x004aa7f7:
    // 004aa7f7  6626c7060000           -mov word ptr es:[esi], 0
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x004aa7fd:
    // 004aa7fd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004aa7ff:
    // 004aa7ff  83c40c                 +add esp, 0xc
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
    // 004aa802  e9a6feffff             -jmp 0x4aa6ad
    return sub_4aa6ad(app, cpu);
}

/* align: skip  */
void Application::sub_4aa807(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa807  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa808  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa809  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa80a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004aa80b  8a4810                 -mov cl, byte ptr [eax + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004aa80e  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 004aa811  744d                   -je 0x4aa860
    if (cpu.flags.zf)
    {
        goto L_0x004aa860;
    }
    // 004aa813  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004aa816  740c                   -je 0x4aa824
    if (cpu.flags.zf)
    {
        goto L_0x004aa824;
    }
    // 004aa818  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa81a  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa81d  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004aa81f  c457f8                 -les edx, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 004aa822  eb25                   -jmp 0x4aa849
    goto L_0x004aa849;
L_0x004aa824:
    // 004aa824  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004aa827  7410                   -je 0x4aa839
    if (cpu.flags.zf)
    {
        goto L_0x004aa839;
    }
    // 004aa829  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa82b  83c604                 +add esi, 4
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
    // 004aa82e  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 004aa830  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004aa832  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 004aa834  8b56fc                 -mov edx, dword ptr [esi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004aa837  eb10                   -jmp 0x4aa849
    goto L_0x004aa849;
L_0x004aa839:
    // 004aa839  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004aa83b  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa83e  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004aa840  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aa842  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 004aa844  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 004aa846  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x004aa849:
    // 004aa849  8a6810                 -mov ch, byte ptr [eax + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004aa84c  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004aa84f  7409                   -je 0x4aa85a
    if (cpu.flags.zf)
    {
        goto L_0x004aa85a;
    }
    // 004aa851  6626891a               -mov word ptr es:[edx], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.bx;
    // 004aa855  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004aa856  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa857  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa858  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa859  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa85a:
    // 004aa85a  f6c520                 -test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 004aa85d  26891a                 -mov dword ptr es:[edx], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.ebx;
L_0x004aa860:
    // 004aa860  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004aa861  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa862  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa863  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa864  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa865(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa865  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa866  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa867  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa868  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aa86a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004aa86c  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004aa871  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa873  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aa875  e8b57dfeff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004aa87a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa87c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004aa87e  41                     -inc ecx
    (cpu.ecx)++;
    // 004aa87f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aa881  741f                   -je 0x4aa8a2
    if (cpu.flags.zf)
    {
        goto L_0x004aa8a2;
    }
L_0x004aa883:
    // 004aa883  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aa885  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004aa888  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 004aa88b  8a80e8ed4d00           -mov al, byte ptr [eax + 0x4dede8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107176) /* 0x4dede8 */);
    // 004aa891  080432                 -or byte ptr [edx + esi], al
    app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) |= x86::reg8(x86::sreg8(cpu.al));
    // 004aa894  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa896  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004aa898  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aa89a  7406                   -je 0x4aa8a2
    if (cpu.flags.zf)
    {
        goto L_0x004aa8a2;
    }
    // 004aa89c  41                     -inc ecx
    (cpu.ecx)++;
    // 004aa89d  83f85d                 +cmp eax, 0x5d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa8a0  75e1                   -jne 0x4aa883
    if (!cpu.flags.zf)
    {
        goto L_0x004aa883;
    }
L_0x004aa8a2:
    // 004aa8a2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa8a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa8a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa8a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa8a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa8a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa8a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa8a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa8aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa8ab  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004aa8ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa8ad  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004aa8b0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aa8b2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004aa8b4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa8b6  80385e                 +cmp byte ptr [eax], 0x5e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(94 /*0x5e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa8b9  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 004aa8bc  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004aa8c2  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004aa8c6  7403                   -je 0x4aa8cb
    if (cpu.flags.zf)
    {
        goto L_0x004aa8cb;
    }
    // 004aa8c8  40                     -inc eax
    (cpu.eax)++;
    // 004aa8c9  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004aa8cb:
    // 004aa8cb  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004aa8cd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa8cf  e891ffffff             -call 0x4aa865
    cpu.esp -= 4;
    sub_4aa865(app, cpu);
    if (cpu.terminate) return;
    // 004aa8d4  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004aa8d6  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa8d9  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004aa8dc  7434                   -je 0x4aa912
    if (cpu.flags.zf)
    {
        goto L_0x004aa912;
    }
    // 004aa8de  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004aa8e1  740c                   -je 0x4aa8ef
    if (cpu.flags.zf)
    {
        goto L_0x004aa8ef;
    }
    // 004aa8e3  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 004aa8e5  83c608                 +add esi, 8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa8e8  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 004aa8ea  c476f8                 -les esi, ptr [esi - 8]
    NFS2_ASSERT(false);
    // 004aa8ed  eb23                   -jmp 0x4aa912
    goto L_0x004aa912;
L_0x004aa8ef:
    // 004aa8ef  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004aa8f2  7410                   -je 0x4aa904
    if (cpu.flags.zf)
    {
        goto L_0x004aa904;
    }
    // 004aa8f4  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004aa8f6  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa8f9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aa8fb  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004aa8fd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aa8ff  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004aa902  eb0e                   -jmp 0x4aa912
    goto L_0x004aa912;
L_0x004aa904:
    // 004aa904  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004aa906  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa909  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aa90b  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 004aa90d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aa90f  8b72fc                 -mov esi, dword ptr [edx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x004aa912:
    // 004aa912  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004aa915  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004aa917:
    // 004aa917  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aa919  766a                   -jbe 0x4aa985
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa985;
    }
    // 004aa91b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa91d  e8fff8ffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa922  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa925  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004aa929  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004aa92c  7557                   -jne 0x4aa985
    if (!cpu.flags.zf)
    {
        goto L_0x004aa985;
    }
    // 004aa92e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa930  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 004aa933  8a1c1c                 -mov bl, byte ptr [esp + ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.ebx * 1);
    // 004aa936  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa93c  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004aa940  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa942  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004aa945  8a9be8ed4d00           -mov bl, byte ptr [ebx + 0x4dede8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5107176) /* 0x4dede8 */);
    // 004aa94b  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004aa94f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa955  85eb                   +test ebx, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebp));
    // 004aa957  0f94c3                 -sete bl
    cpu.bl = cpu.flags.zf;
    // 004aa95a  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004aa95e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aa964  39eb                   +cmp ebx, ebp
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
    // 004aa966  7409                   -je 0x4aa971
    if (cpu.flags.zf)
    {
        goto L_0x004aa971;
    }
    // 004aa968  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aa96a  e8b9f8ffff             -call 0x4aa228
    cpu.esp -= 4;
    sub_4aa228(app, cpu);
    if (cpu.terminate) return;
    // 004aa96f  eb14                   -jmp 0x4aa985
    goto L_0x004aa985;
L_0x004aa971:
    // 004aa971  47                     -inc edi
    (cpu.edi)++;
    // 004aa972  8a7910                 -mov bh, byte ptr [ecx + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aa975  4a                     -dec edx
    (cpu.edx)--;
    // 004aa976  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004aa979  749c                   -je 0x4aa917
    if (cpu.flags.zf)
    {
        goto L_0x004aa917;
    }
    // 004aa97b  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004aa97f  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 004aa982  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aa983  eb92                   -jmp 0x4aa917
    goto L_0x004aa917;
L_0x004aa985:
    // 004aa985  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004aa989  7408                   -je 0x4aa993
    if (cpu.flags.zf)
    {
        goto L_0x004aa993;
    }
    // 004aa98b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aa98d  7e04                   -jle 0x4aa993
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aa993;
    }
    // 004aa98f  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x004aa993:
    // 004aa993  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aa995  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004aa998  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa999  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004aa99a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa99b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa99c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa99d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa99e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa99e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa99f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa9a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa9a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa9a2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004aa9a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa9a4  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004aa9a7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aa9a9  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 004aa9ad  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004aa9af  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004aa9b1  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
L_0x004aa9b5:
    // 004aa9b5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa9b7  e865f8ffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aa9bc  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004aa9be  fec2                   -inc dl
    (cpu.dl)++;
    // 004aa9c0  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 004aa9c3  8a9564ef4d00           -mov dl, byte ptr [ebp + 0x4def64]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5107556) /* 0x4def64 */);
    // 004aa9c9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aa9cb  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004aa9ce  7406                   -je 0x4aa9d6
    if (cpu.flags.zf)
    {
        goto L_0x004aa9d6;
    }
    // 004aa9d0  ff442468               +inc dword ptr [esp + 0x68]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aa9d4  ebdf                   -jmp 0x4aa9b5
    goto L_0x004aa9b5;
L_0x004aa9d6:
    // 004aa9d6  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004aa9da  0f85d7010000           -jne 0x4aabb7
    if (!cpu.flags.zf)
    {
        goto L_0x004aabb7;
    }
    // 004aa9e0  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004aa9e3  8d6aff                 -lea ebp, [edx - 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004aa9e6  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004aa9e9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aa9eb  0f84bd010000           -je 0x4aabae
    if (cpu.flags.zf)
    {
        goto L_0x004aabae;
    }
    // 004aa9f1  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa9f4  7405                   -je 0x4aa9fb
    if (cpu.flags.zf)
    {
        goto L_0x004aa9fb;
    }
    // 004aa9f6  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa9f9  751e                   -jne 0x4aaa19
    if (!cpu.flags.zf)
    {
        goto L_0x004aaa19;
    }
L_0x004aa9fb:
    // 004aa9fb  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004aa9ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aaa01  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004aaa03  e898060000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aaa08  43                     -inc ebx
    (cpu.ebx)++;
    // 004aaa09  45                     -inc ebp
    (cpu.ebp)++;
    // 004aaa0a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aaa0c  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 004aaa10  83f8ff                 +cmp eax, -1
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
    // 004aaa13  0f849e010000           -je 0x4aabb7
    if (cpu.flags.zf)
    {
        goto L_0x004aabb7;
    }
L_0x004aaa19:
    // 004aaa19  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 004aaa1b  fec0                   -inc al
    (cpu.al)++;
    // 004aaa1d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaa22  f68064ef4d0020         +test byte ptr [eax + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004aaa29  7509                   -jne 0x4aaa34
    if (!cpu.flags.zf)
    {
        goto L_0x004aaa34;
    }
    // 004aaa2b  83f92e                 +cmp ecx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaa2e  0f857a010000           -jne 0x4aabae
    if (!cpu.flags.zf)
    {
        goto L_0x004aabae;
    }
L_0x004aaa34:
    // 004aaa34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aaa36  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 004aaa3a  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 004aaa3c  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004aaa3e  fec0                   -inc al
    (cpu.al)++;
    // 004aaa40  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaa45  f68064ef4d0020         +test byte ptr [eax + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004aaa4c  7441                   -je 0x4aaa8f
    if (cpu.flags.zf)
    {
        goto L_0x004aaa8f;
    }
    // 004aaa4e  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x004aaa53:
    // 004aaa53  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004aaa55  8a4610                 -mov al, byte ptr [esi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004aaa58  43                     -inc ebx
    (cpu.ebx)++;
    // 004aaa59  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004aaa5b  740f                   -je 0x4aaa6c
    if (cpu.flags.zf)
    {
        goto L_0x004aaa6c;
    }
    // 004aaa5d  6b4424660a             -imul eax, dword ptr [esp + 0x66], 0xa
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(102) /* 0x66 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004aaa62  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aaa64  83e930                 -sub ecx, 0x30
    (cpu.ecx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004aaa67  66894c2466             -mov word ptr [esp + 0x66], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(102) /* 0x66 */) = cpu.cx;
L_0x004aaa6c:
    // 004aaa6c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aaa6e  47                     -inc edi
    (cpu.edi)++;
    // 004aaa6f  e82c060000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aaa74  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aaa76  83f8ff                 +cmp eax, -1
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
    // 004aaa79  0f8438010000           -je 0x4aabb7
    if (cpu.flags.zf)
    {
        goto L_0x004aabb7;
    }
    // 004aaa7f  fec0                   -inc al
    (cpu.al)++;
    // 004aaa81  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaa86  f68064ef4d0020         +test byte ptr [eax + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004aaa8d  75c4                   -jne 0x4aaa53
    if (!cpu.flags.zf)
    {
        goto L_0x004aaa53;
    }
L_0x004aaa8f:
    // 004aaa8f  83f92e                 +cmp ecx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaa92  0f8598000000           -jne 0x4aab30
    if (!cpu.flags.zf)
    {
        goto L_0x004aab30;
    }
    // 004aaa98  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aaa9a  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004aaa9c  e8ff050000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aaaa1  43                     -inc ebx
    (cpu.ebx)++;
    // 004aaaa2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aaaa4  83f8ff                 +cmp eax, -1
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
    // 004aaaa7  0f840a010000           -je 0x4aabb7
    if (cpu.flags.zf)
    {
        goto L_0x004aabb7;
    }
    // 004aaaad  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004aaaaf  7514                   -jne 0x4aaac5
    if (!cpu.flags.zf)
    {
        goto L_0x004aaac5;
    }
    // 004aaab1  fec0                   -inc al
    (cpu.al)++;
    // 004aaab3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaab8  f68064ef4d0020         +test byte ptr [eax + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004aaabf  0f84e9000000           -je 0x4aabae
    if (cpu.flags.zf)
    {
        goto L_0x004aabae;
    }
L_0x004aaac5:
    // 004aaac5  47                     -inc edi
    (cpu.edi)++;
L_0x004aaac6:
    // 004aaac6  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 004aaac8  fec0                   -inc al
    (cpu.al)++;
    // 004aaaca  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaacf  f68064ef4d0020         +test byte ptr [eax + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004aaad6  7412                   -je 0x4aaaea
    if (cpu.flags.zf)
    {
        goto L_0x004aaaea;
    }
    // 004aaad8  47                     -inc edi
    (cpu.edi)++;
    // 004aaad9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aaadb  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004aaadd  e8be050000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aaae2  43                     -inc ebx
    (cpu.ebx)++;
    // 004aaae3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aaae5  83f8ff                 +cmp eax, -1
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
    // 004aaae8  75dc                   -jne 0x4aaac6
    if (!cpu.flags.zf)
    {
        goto L_0x004aaac6;
    }
L_0x004aaaea:
    // 004aaaea  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004aaaee  7437                   -je 0x4aab27
    if (cpu.flags.zf)
    {
        goto L_0x004aab27;
    }
    // 004aaaf0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aaaf2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004aaaf4  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x004aaaf8:
    // 004aaaf8  4d                     -dec ebp
    (cpu.ebp)--;
    // 004aaaf9  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004aaafc  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aaafe  741e                   -je 0x4aab1e
    if (cpu.flags.zf)
    {
        goto L_0x004aab1e;
    }
    // 004aab00  2c30                   -sub al, 0x30
    (cpu.al) -= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004aab02  c744245c0a000000       -mov dword ptr [esp + 0x5c], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 10 /*0xa*/;
    // 004aab0a  88442462               -mov byte ptr [esp + 0x62], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(98) /* 0x62 */) = cpu.al;
    // 004aab0e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aab10  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004aab14  f774245c               +div dword ptr [esp + 0x5c]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004aab18  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004aab1c  ebda                   -jmp 0x4aaaf8
    goto L_0x004aaaf8;
L_0x004aab1e:
    // 004aab1e  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004aab22  6689442464             -mov word ptr [esp + 0x64], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ax;
L_0x004aab27:
    // 004aab27  83f9ff                 +cmp ecx, -1
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
    // 004aab2a  0f8487000000           -je 0x4aabb7
    if (cpu.flags.zf)
    {
        goto L_0x004aabb7;
    }
L_0x004aab30:
    // 004aab30  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004aab34  0f8574000000           -jne 0x4aabae
    if (!cpu.flags.zf)
    {
        goto L_0x004aabae;
    }
    // 004aab3a  83f965                 +cmp ecx, 0x65
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aab3d  7409                   -je 0x4aab48
    if (cpu.flags.zf)
    {
        goto L_0x004aab48;
    }
    // 004aab3f  83f945                 +cmp ecx, 0x45
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aab42  0f8566000000           -jne 0x4aabae
    if (!cpu.flags.zf)
    {
        goto L_0x004aabae;
    }
L_0x004aab48:
    // 004aab48  47                     -inc edi
    (cpu.edi)++;
    // 004aab49  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aab4b  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004aab4d  e84e050000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aab52  43                     -inc ebx
    (cpu.ebx)++;
    // 004aab53  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aab55  83f8ff                 +cmp eax, -1
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
    // 004aab58  745d                   -je 0x4aabb7
    if (cpu.flags.zf)
    {
        goto L_0x004aabb7;
    }
    // 004aab5a  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aab5d  7405                   -je 0x4aab64
    if (cpu.flags.zf)
    {
        goto L_0x004aab64;
    }
    // 004aab5f  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aab62  7512                   -jne 0x4aab76
    if (!cpu.flags.zf)
    {
        goto L_0x004aab76;
    }
L_0x004aab64:
    // 004aab64  47                     -inc edi
    (cpu.edi)++;
    // 004aab65  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aab67  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004aab69  e832050000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aab6e  43                     -inc ebx
    (cpu.ebx)++;
    // 004aab6f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aab71  83f8ff                 +cmp eax, -1
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
    // 004aab74  7441                   -je 0x4aabb7
    if (cpu.flags.zf)
    {
        goto L_0x004aabb7;
    }
L_0x004aab76:
    // 004aab76  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 004aab78  fec0                   -inc al
    (cpu.al)++;
    // 004aab7a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aab7f  f68064ef4d0020         +test byte ptr [eax + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004aab86  7504                   -jne 0x4aab8c
    if (!cpu.flags.zf)
    {
        goto L_0x004aab8c;
    }
    // 004aab88  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004aab8a  eb22                   -jmp 0x4aabae
    goto L_0x004aabae;
L_0x004aab8c:
    // 004aab8c  47                     -inc edi
    (cpu.edi)++;
    // 004aab8d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aab8f  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004aab91  e80a050000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aab96  43                     -inc ebx
    (cpu.ebx)++;
    // 004aab97  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aab99  83f8ff                 +cmp eax, -1
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
    // 004aab9c  7419                   -je 0x4aabb7
    if (cpu.flags.zf)
    {
        goto L_0x004aabb7;
    }
    // 004aab9e  fec0                   -inc al
    (cpu.al)++;
    // 004aaba0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaba5  f68064ef4d0020         +test byte ptr [eax + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004aabac  75de                   -jne 0x4aab8c
    if (!cpu.flags.zf)
    {
        goto L_0x004aab8c;
    }
L_0x004aabae:
    // 004aabae  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004aabb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aabb2  e871f6ffff             -call 0x4aa228
    cpu.esp -= 4;
    sub_4aa228(app, cpu);
    if (cpu.terminate) return;
L_0x004aabb7:
    // 004aabb7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aabb9  0f8eab000000           -jle 0x4aac6a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aac6a;
    }
    // 004aabbf  037c2468               -add edi, dword ptr [esp + 0x68]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 004aabc3  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004aabc7  0f849d000000           -je 0x4aac6a
    if (cpu.flags.zf)
    {
        goto L_0x004aac6a;
    }
    // 004aabcd  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004aabd0  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004aabd4  740c                   -je 0x4aabe2
    if (cpu.flags.zf)
    {
        goto L_0x004aabe2;
    }
    // 004aabd6  803c242d               +cmp byte ptr [esp], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aabda  7512                   -jne 0x4aabee
    if (!cpu.flags.zf)
    {
        goto L_0x004aabee;
    }
    // 004aabdc  f75c2464               +neg dword ptr [esp + 0x64]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004aabe0  eb0c                   -jmp 0x4aabee
    goto L_0x004aabee;
L_0x004aabe2:
    // 004aabe2  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004aabe6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004aabe8  ff1540074e00           -call dword ptr [0x4e0740]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113664) /* 0x4e0740 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004aabee:
    // 004aabee  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004aabf1  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004aabf4  7410                   -je 0x4aac06
    if (cpu.flags.zf)
    {
        goto L_0x004aac06;
    }
    // 004aabf6  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004aabfa  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004aabfc  83c108                 +add ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aabff  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004aac01  c459f8                 -les ebx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 004aac04  eb2b                   -jmp 0x4aac31
    goto L_0x004aac31;
L_0x004aac06:
    // 004aac06  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 004aac09  7414                   -je 0x4aac1f
    if (cpu.flags.zf)
    {
        goto L_0x004aac1f;
    }
    // 004aac0b  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004aac0f  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004aac11  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aac14  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004aac16  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aac18  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aac1a  8b5bfc                 -mov ebx, dword ptr [ebx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004aac1d  eb12                   -jmp 0x4aac31
    goto L_0x004aac31;
L_0x004aac1f:
    // 004aac1f  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004aac23  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004aac25  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aac28  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004aac2a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aac2c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aac2e  8b5afc                 -mov ebx, dword ptr [edx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x004aac31:
    // 004aac31  8a7610                 -mov dh, byte ptr [esi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004aac34  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 004aac37  7406                   -je 0x4aac3f
    if (cpu.flags.zf)
    {
        goto L_0x004aac3f;
    }
    // 004aac39  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004aac3d  eb28                   -jmp 0x4aac67
    goto L_0x004aac67;
L_0x004aac3f:
    // 004aac3f  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 004aac42  7505                   -jne 0x4aac49
    if (!cpu.flags.zf)
    {
        goto L_0x004aac49;
    }
    // 004aac44  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004aac47  7411                   -je 0x4aac5a
    if (cpu.flags.zf)
    {
        goto L_0x004aac5a;
    }
L_0x004aac49:
    // 004aac49  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004aac4d  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
    // 004aac50  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004aac54  26894304               -mov dword ptr es:[ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004aac58  eb10                   -jmp 0x4aac6a
    goto L_0x004aac6a;
L_0x004aac5a:
    // 004aac5a  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004aac5e  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004aac62  e809e20000             -call 0x4b8e70
    cpu.esp -= 4;
    sub_4b8e70(app, cpu);
    if (cpu.terminate) return;
L_0x004aac67:
    // 004aac67  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
L_0x004aac6a:
    // 004aac6a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aac6c  83c46c                 +add esp, 0x6c
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
    // 004aac6f  e939faffff             -jmp 0x4aa6ad
    return sub_4aa6ad(app, cpu);
}

/* align: skip  */
void Application::sub_4aac74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aac74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aac75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aac76  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004aac77  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aac78  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004aac7b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004aac7d  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004aac81  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004aac85  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aac87  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004aac89  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004aac8d  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004aac91  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004aac95  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x004aac99:
    // 004aac99  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aac9b  e881f5ffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004aaca0  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aaca4  8a5c242c               -mov bl, byte ptr [esp + 0x2c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004aaca8  fec3                   -inc bl
    (cpu.bl)++;
    // 004aacaa  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aacb0  f68364ef4d0002         +test byte ptr [ebx + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004aacb7  7406                   -je 0x4aacbf
    if (cpu.flags.zf)
    {
        goto L_0x004aacbf;
    }
    // 004aacb9  ff442420               +inc dword ptr [esp + 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aacbd  ebda                   -jmp 0x4aac99
    goto L_0x004aac99;
L_0x004aacbf:
    // 004aacbf  f6471002               +test byte ptr [edi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004aacc3  0f8590020000           -jne 0x4aaf59
    if (!cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
    // 004aacc9  8b5f0c                 -mov ebx, dword ptr [edi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004aaccc  8d73ff                 -lea esi, [ebx - 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aaccf  89770c                 -mov dword ptr [edi + 0xc], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004aacd2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aacd4  0f8474020000           -je 0x4aaf4e
    if (cpu.flags.zf)
    {
        goto L_0x004aaf4e;
    }
    // 004aacda  bb2b000000             -mov ebx, 0x2b
    cpu.ebx = 43 /*0x2b*/;
    // 004aacdf  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004aace3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004aace5  742e                   -je 0x4aad15
    if (cpu.flags.zf)
    {
        goto L_0x004aad15;
    }
    // 004aace7  39d8                   +cmp eax, ebx
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
    // 004aace9  7405                   -je 0x4aacf0
    if (cpu.flags.zf)
    {
        goto L_0x004aacf0;
    }
    // 004aaceb  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aacee  7525                   -jne 0x4aad15
    if (!cpu.flags.zf)
    {
        goto L_0x004aad15;
    }
L_0x004aacf0:
    // 004aacf0  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004aacf4  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004aacf8  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004aacfc  41                     -inc ecx
    (cpu.ecx)++;
    // 004aacfd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aacff  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004aad03  e898030000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aad08  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aad0c  83f8ff                 +cmp eax, -1
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
    // 004aad0f  0f8444020000           -je 0x4aaf59
    if (cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
L_0x004aad15:
    // 004aad15  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004aad19  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004aad1b  0f8569000000           -jne 0x4aad8a
    if (!cpu.flags.zf)
    {
        goto L_0x004aad8a;
    }
    // 004aad21  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aad26  7558                   -jne 0x4aad80
    if (!cpu.flags.zf)
    {
        goto L_0x004aad80;
    }
    // 004aad28  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aad2a  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004aad2f  e86c030000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aad34  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aad38  83f8ff                 +cmp eax, -1
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
    // 004aad3b  0f8418020000           -je 0x4aaf59
    if (cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
    // 004aad41  83f878                 +cmp eax, 0x78
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aad44  7405                   -je 0x4aad4b
    if (cpu.flags.zf)
    {
        goto L_0x004aad4b;
    }
    // 004aad46  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aad49  752b                   -jne 0x4aad76
    if (!cpu.flags.zf)
    {
        goto L_0x004aad76;
    }
L_0x004aad4b:
    // 004aad4b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aad4d  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004aad51  e84a030000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aad56  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004aad58  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004aad5b  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aad5f  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004aad63  83f8ff                 +cmp eax, -1
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
    // 004aad66  0f84ed010000           -je 0x4aaf59
    if (cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
    // 004aad6c  c744242810000000       -mov dword ptr [esp + 0x28], 0x10
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 16 /*0x10*/;
    // 004aad74  eb64                   -jmp 0x4aadda
    goto L_0x004aadda;
L_0x004aad76:
    // 004aad76  c744242808000000       -mov dword ptr [esp + 0x28], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 8 /*0x8*/;
    // 004aad7e  eb5a                   -jmp 0x4aadda
    goto L_0x004aadda;
L_0x004aad80:
    // 004aad80  c74424280a000000       -mov dword ptr [esp + 0x28], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 10 /*0xa*/;
    // 004aad88  eb50                   -jmp 0x4aadda
    goto L_0x004aadda;
L_0x004aad8a:
    // 004aad8a  83fe10                 +cmp esi, 0x10
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
    // 004aad8d  754b                   -jne 0x4aadda
    if (!cpu.flags.zf)
    {
        goto L_0x004aadda;
    }
    // 004aad8f  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aad94  7544                   -jne 0x4aadda
    if (!cpu.flags.zf)
    {
        goto L_0x004aadda;
    }
    // 004aad96  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aad98  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004aad9d  e8fe020000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aada2  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aada6  83f8ff                 +cmp eax, -1
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
    // 004aada9  0f84aa010000           -je 0x4aaf59
    if (cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
    // 004aadaf  83f878                 +cmp eax, 0x78
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aadb2  7405                   -je 0x4aadb9
    if (cpu.flags.zf)
    {
        goto L_0x004aadb9;
    }
    // 004aadb4  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aadb7  7521                   -jne 0x4aadda
    if (!cpu.flags.zf)
    {
        goto L_0x004aadda;
    }
L_0x004aadb9:
    // 004aadb9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aadbb  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004aadbf  e8dc020000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aadc4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004aadc6  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004aadc9  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aadcd  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004aadd1  83f8ff                 +cmp eax, -1
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
    // 004aadd4  0f847f010000           -je 0x4aaf59
    if (cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
L_0x004aadda:
    // 004aadda  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 004aadde  0f84ff000000           -je 0x4aaee3
    if (cpu.flags.zf)
    {
        goto L_0x004aaee3;
    }
    // 004aade4  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004aade8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aadea  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004aadee  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004aadf2:
    // 004aadf2  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004aadf6  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004aadfa  e87a020000             -call 0x4ab079
    cpu.esp -= 4;
    sub_4ab079(app, cpu);
    if (cpu.terminate) return;
    // 004aadff  39d0                   +cmp eax, edx
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
    // 004aae01  7d5d                   -jge 0x4aae60
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aae60;
    }
    // 004aae03  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aae07  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004aae0a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aae0c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aae10  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004aae14  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aae18  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004aae1b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aae1d  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aae20  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aae22  e895e00000             -call 0x4b8ebc
    cpu.esp -= 4;
    sub_4b8ebc(app, cpu);
    if (cpu.terminate) return;
    // 004aae27  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004aae2a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004aae2c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aae30  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004aae32  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aae36  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004aae39  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aae3b  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aae3e  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aae40  01d8                   +add eax, ebx
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
    // 004aae42  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004aae44  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004aae47  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004aae49  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aae4b  45                     -inc ebp
    (cpu.ebp)++;
    // 004aae4c  e84f020000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aae51  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aae55  83f8ff                 +cmp eax, -1
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
    // 004aae58  0f84fb000000           -je 0x4aaf59
    if (cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
    // 004aae5e  eb92                   -jmp 0x4aadf2
    goto L_0x004aadf2;
L_0x004aae60:
    // 004aae60  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aae65  0f85e3000000           -jne 0x4aaf4e
    if (!cpu.flags.zf)
    {
        goto L_0x004aaf4e;
    }
    // 004aae6b  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 004aae6f  0f84d9000000           -je 0x4aaf4e
    if (cpu.flags.zf)
    {
        goto L_0x004aaf4e;
    }
L_0x004aae75:
    // 004aae75  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aae77  45                     -inc ebp
    (cpu.ebp)++;
    // 004aae78  e823020000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aae7d  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aae81  83f8ff                 +cmp eax, -1
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
    // 004aae84  0f84cf000000           -je 0x4aaf59
    if (cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
    // 004aae8a  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004aae8e  e8e6010000             -call 0x4ab079
    cpu.esp -= 4;
    sub_4ab079(app, cpu);
    if (cpu.terminate) return;
    // 004aae93  39f0                   +cmp eax, esi
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
    // 004aae95  0f8db3000000           -jge 0x4aaf4e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aaf4e;
    }
    // 004aae9b  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aae9f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004aaea2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aaea4  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aaea8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004aaeac  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aaeb0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004aaeb3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aaeb5  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aaeb8  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aaeba  e8fddf0000             -call 0x4b8ebc
    cpu.esp -= 4;
    sub_4b8ebc(app, cpu);
    if (cpu.terminate) return;
    // 004aaebf  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004aaec2  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004aaec4  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aaec8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004aaeca  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aaece  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004aaed1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aaed3  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aaed6  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aaed8  01d8                   +add eax, ebx
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
    // 004aaeda  11ca                   +adc edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aaedc  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004aaedf  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004aaee1  eb92                   -jmp 0x4aae75
    goto L_0x004aae75;
L_0x004aaee3:
    // 004aaee3  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x004aaee7:
    // 004aaee7  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004aaeeb  e889010000             -call 0x4ab079
    cpu.esp -= 4;
    sub_4ab079(app, cpu);
    if (cpu.terminate) return;
    // 004aaef0  39f0                   +cmp eax, esi
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
    // 004aaef2  7d20                   -jge 0x4aaf14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aaf14;
    }
    // 004aaef4  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004aaef8  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004aaefb  45                     -inc ebp
    (cpu.ebp)++;
    // 004aaefc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aaefe  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aaf00  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004aaf04  e897010000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aaf09  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aaf0d  83f8ff                 +cmp eax, -1
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
    // 004aaf10  7447                   -je 0x4aaf59
    if (cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
    // 004aaf12  ebd3                   -jmp 0x4aaee7
    goto L_0x004aaee7;
L_0x004aaf14:
    // 004aaf14  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaf19  7533                   -jne 0x4aaf4e
    if (!cpu.flags.zf)
    {
        goto L_0x004aaf4e;
    }
    // 004aaf1b  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 004aaf1f  742d                   -je 0x4aaf4e
    if (cpu.flags.zf)
    {
        goto L_0x004aaf4e;
    }
    // 004aaf21  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x004aaf25:
    // 004aaf25  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aaf27  45                     -inc ebp
    (cpu.ebp)++;
    // 004aaf28  e873010000             -call 0x4ab0a0
    cpu.esp -= 4;
    sub_4ab0a0(app, cpu);
    if (cpu.terminate) return;
    // 004aaf2d  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004aaf31  83f8ff                 +cmp eax, -1
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
    // 004aaf34  7423                   -je 0x4aaf59
    if (cpu.flags.zf)
    {
        goto L_0x004aaf59;
    }
    // 004aaf36  e83e010000             -call 0x4ab079
    cpu.esp -= 4;
    sub_4ab079(app, cpu);
    if (cpu.terminate) return;
    // 004aaf3b  39c8                   +cmp eax, ecx
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
    // 004aaf3d  7d0f                   -jge 0x4aaf4e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aaf4e;
    }
    // 004aaf3f  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004aaf43  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004aaf46  01c3                   +add ebx, eax
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
    // 004aaf48  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004aaf4c  ebd7                   -jmp 0x4aaf25
    goto L_0x004aaf25;
L_0x004aaf4e:
    // 004aaf4e  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004aaf52  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004aaf54  e8cff2ffff             -call 0x4aa228
    cpu.esp -= 4;
    sub_4aa228(app, cpu);
    if (cpu.terminate) return;
L_0x004aaf59:
    // 004aaf59  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 004aaf5d  0f8492000000           -je 0x4aaff5
    if (cpu.flags.zf)
    {
        goto L_0x004aaff5;
    }
    // 004aaf63  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaf68  7524                   -jne 0x4aaf8e
    if (!cpu.flags.zf)
    {
        goto L_0x004aaf8e;
    }
    // 004aaf6a  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aaf6e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aaf72  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 004aaf74  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004aaf76  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004aaf7a  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aaf7d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004aaf81  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004aaf85  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aaf87  7501                   -jne 0x4aaf8a
    if (!cpu.flags.zf)
    {
        goto L_0x004aaf8a;
    }
    // 004aaf89  40                     -inc eax
    (cpu.eax)++;
L_0x004aaf8a:
    // 004aaf8a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004aaf8e:
    // 004aaf8e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004aaf90  0f8ed9000000           -jle 0x4ab06f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab06f;
    }
    // 004aaf96  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004aaf9a  8a7f10                 -mov bh, byte ptr [edi + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004aaf9d  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaf9f  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004aafa2  0f84c7000000           -je 0x4ab06f
    if (cpu.flags.zf)
    {
        goto L_0x004ab06f;
    }
    // 004aafa8  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004aafab  7414                   -je 0x4aafc1
    if (cpu.flags.zf)
    {
        goto L_0x004aafc1;
    }
    // 004aafad  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aafb1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004aafb3  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aafb6  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004aafb8  668b42fc               -mov ax, word ptr [edx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004aafbc  8b7af8                 -mov edi, dword ptr [edx - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 004aafbf  eb27                   -jmp 0x4aafe8
    goto L_0x004aafe8;
L_0x004aafc1:
    // 004aafc1  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 004aafc4  7412                   -je 0x4aafd8
    if (cpu.flags.zf)
    {
        goto L_0x004aafd8;
    }
    // 004aafc6  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aafca  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004aafcc  83c704                 +add edi, 4
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
    // 004aafcf  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004aafd1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aafd3  8b7ffc                 -mov edi, dword ptr [edi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004aafd6  eb10                   -jmp 0x4aafe8
    goto L_0x004aafe8;
L_0x004aafd8:
    // 004aafd8  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aafdc  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004aafde  83c604                 +add esi, 4
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
    // 004aafe1  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004aafe3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004aafe5  8b7efc                 -mov edi, dword ptr [esi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x004aafe8:
    // 004aafe8  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aafec  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004aafee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004aafef  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004aaff0  e97a000000             -jmp 0x4ab06f
    goto L_0x004ab06f;
L_0x004aaff5:
    // 004aaff5  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaffa  7504                   -jne 0x4ab000
    if (!cpu.flags.zf)
    {
        goto L_0x004ab000;
    }
    // 004aaffc  f75c2424               -neg dword ptr [esp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = ~app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) + 1;
L_0x004ab000:
    // 004ab000  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ab002  0f8e67000000           -jle 0x4ab06f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab06f;
    }
    // 004ab008  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab00c  8a4710                 -mov al, byte ptr [edi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004ab00f  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab011  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004ab013  745a                   -je 0x4ab06f
    if (cpu.flags.zf)
    {
        goto L_0x004ab06f;
    }
    // 004ab015  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004ab017  7410                   -je 0x4ab029
    if (cpu.flags.zf)
    {
        goto L_0x004ab029;
    }
    // 004ab019  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab01d  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab01f  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab022  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004ab024  c443f8                 -les eax, ptr [ebx - 8]
    NFS2_ASSERT(false);
    // 004ab027  eb2a                   -jmp 0x4ab053
    goto L_0x004ab053;
L_0x004ab029:
    // 004ab029  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004ab02b  7414                   -je 0x4ab041
    if (cpu.flags.zf)
    {
        goto L_0x004ab041;
    }
    // 004ab02d  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab031  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab033  83c204                 +add edx, 4
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
    // 004ab036  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 004ab038  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ab03a  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 004ab03c  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004ab03f  eb12                   -jmp 0x4ab053
    goto L_0x004ab053;
L_0x004ab041:
    // 004ab041  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab045  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab047  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ab04a  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 004ab04c  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004ab04e  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 004ab050  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x004ab053:
    // 004ab053  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004ab056  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 004ab059  740a                   -je 0x4ab065
    if (cpu.flags.zf)
    {
        goto L_0x004ab065;
    }
    // 004ab05b  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ab05f  66268918               -mov word ptr es:[eax], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.eax) = cpu.bx;
    // 004ab063  eb0a                   -jmp 0x4ab06f
    goto L_0x004ab06f;
L_0x004ab065:
    // 004ab065  f6c620                 -test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 004ab068  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ab06c  268918                 -mov dword ptr es:[eax], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.eax) = cpu.ebx;
L_0x004ab06f:
    // 004ab06f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ab071  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004ab074  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab075  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ab076  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab077  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab078  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab079(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab079  83f830                 +cmp eax, 0x30
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab07c  7c09                   -jl 0x4ab087
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab087;
    }
    // 004ab07e  83f839                 +cmp eax, 0x39
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
    // 004ab081  7f04                   -jg 0x4ab087
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ab087;
    }
    // 004ab083  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004ab086  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab087:
    // 004ab087  e84ee7ffff             -call 0x4a97da
    cpu.esp -= 4;
    sub_4a97da(app, cpu);
    if (cpu.terminate) return;
    // 004ab08c  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab08f  7c09                   -jl 0x4ab09a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab09a;
    }
    // 004ab091  83f866                 +cmp eax, 0x66
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab094  7f04                   -jg 0x4ab09a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ab09a;
    }
    // 004ab096  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004ab099  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab09a:
    // 004ab09a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004ab09f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab0a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab0a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab0a4  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ab0a7  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004ab0aa  895a0c                 -mov dword ptr [edx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004ab0ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab0af  740d                   -je 0x4ab0be
    if (cpu.flags.zf)
    {
        goto L_0x004ab0be;
    }
    // 004ab0b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab0b3  e869f1ffff             -call 0x4aa221
    cpu.esp -= 4;
    sub_4aa221(app, cpu);
    if (cpu.terminate) return;
    // 004ab0b8  f6421002               +test byte ptr [edx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004ab0bc  7405                   -je 0x4ab0c3
    if (cpu.flags.zf)
    {
        goto L_0x004ab0c3;
    }
L_0x004ab0be:
    // 004ab0be  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004ab0c3:
    // 004ab0c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab0c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab0c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab0c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0c6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab0c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab0c8  2eff15c8644c00         -call dword ptr cs:[0x4c64c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006536) /* 0x4c64c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab0cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab0d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab0d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab0d2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab0d3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab0d4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab0d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab0d6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab0d7  81ec28020000           -sub esp, 0x228
    (cpu.esp) -= x86::reg32(x86::sreg32(552 /*0x228*/));
    // 004ab0dd  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab0e3  bdf5144d00             -mov ebp, 0x4d14f5
    cpu.ebp = 5051637 /*0x4d14f5*/;
    // 004ab0e8  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab0eb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004ab0ed:
    // 004ab0ed  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004ab0f4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004ab0f6  e81cf7fdff             -call 0x48a817
    cpu.esp -= 4;
    sub_48a817(app, cpu);
    if (cpu.terminate) return;
    // 004ab0fb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004ab100  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004ab107  41                     -inc ecx
    (cpu.ecx)++;
    // 004ab108  e8cbdd0000             -call 0x4b8ed8
    cpu.esp -= 4;
    sub_4b8ed8(app, cpu);
    if (cpu.terminate) return;
    // 004ab10d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab10f  74dc                   -je 0x4ab0ed
    if (cpu.flags.zf)
    {
        goto L_0x004ab0ed;
    }
    // 004ab111  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004ab118  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ab11a  e87ff4fdff             -call 0x48a59e
    cpu.esp -= 4;
    sub_48a59e(app, cpu);
    if (cpu.terminate) return;
    // 004ab11f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab121  751b                   -jne 0x4ab13e
    if (!cpu.flags.zf)
    {
        goto L_0x004ab13e;
    }
    // 004ab123  e8e4dd0000             -call 0x4b8f0c
    cpu.esp -= 4;
    sub_4b8f0c(app, cpu);
    if (cpu.terminate) return;
    // 004ab128  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab12b  740a                   -je 0x4ab137
    if (cpu.flags.zf)
    {
        goto L_0x004ab137;
    }
    // 004ab12d  e8dadd0000             -call 0x4b8f0c
    cpu.esp -= 4;
    sub_4b8f0c(app, cpu);
    if (cpu.terminate) return;
    // 004ab132  833806                 +cmp dword ptr [eax], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab135  75b6                   -jne 0x4ab0ed
    if (!cpu.flags.zf)
    {
        goto L_0x004ab0ed;
    }
L_0x004ab137:
    // 004ab137  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ab139  e97d000000             -jmp 0x4ab1bb
    goto L_0x004ab1bb;
L_0x004ab13e:
    // 004ab13e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab140  e872f6fdff             -call 0x48a7b7
    cpu.esp -= 4;
    sub_48a7b7(app, cpu);
    if (cpu.terminate) return;
    // 004ab145  8a1d4ced4d00           -mov bl, byte ptr [0x4ded4c]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5107020) /* 0x4ded4c */);
L_0x004ab14b:
    // 004ab14b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ab14d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab14f  e8c3f6fdff             -call 0x48a817
    cpu.esp -= 4;
    sub_48a817(app, cpu);
    if (cpu.terminate) return;
    // 004ab154  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ab156  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004ab15d  e8bedd0000             -call 0x4b8f20
    cpu.esp -= 4;
    sub_4b8f20(app, cpu);
    if (cpu.terminate) return;
    // 004ab162  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab164  7539                   -jne 0x4ab19f
    if (!cpu.flags.zf)
    {
        goto L_0x004ab19f;
    }
    // 004ab166  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ab168  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ab16a  e82ff4fdff             -call 0x48a59e
    cpu.esp -= 4;
    sub_48a59e(app, cpu);
    if (cpu.terminate) return;
    // 004ab16f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab171  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab173  7420                   -je 0x4ab195
    if (cpu.flags.zf)
    {
        goto L_0x004ab195;
    }
    // 004ab175  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004ab178  80cc08                 +or ah, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004ab17b  88620d                 -mov byte ptr [edx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004ab17e  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004ab181  885814                 -mov byte ptr [eax + 0x14], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.bl;
    // 004ab184  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab186  881d4ced4d00           -mov byte ptr [0x4ded4c], bl
    app->getMemory<x86::reg8>(x86::reg32(5107020) /* 0x4ded4c */) = cpu.bl;
    // 004ab18c  e81fb5ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004ab191  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab193  eb26                   -jmp 0x4ab1bb
    goto L_0x004ab1bb;
L_0x004ab195:
    // 004ab195  e872dd0000             -call 0x4b8f0c
    cpu.esp -= 4;
    sub_4b8f0c(app, cpu);
    if (cpu.terminate) return;
    // 004ab19a  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab19d  7498                   -je 0x4ab137
    if (cpu.flags.zf)
    {
        goto L_0x004ab137;
    }
L_0x004ab19f:
    // 004ab19f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004ab1a4  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004ab1ab  43                     -inc ebx
    (cpu.ebx)++;
    // 004ab1ac  e827dd0000             -call 0x4b8ed8
    cpu.esp -= 4;
    sub_4b8ed8(app, cpu);
    if (cpu.terminate) return;
    // 004ab1b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab1b3  0f8534ffffff           -jne 0x4ab0ed
    if (!cpu.flags.zf)
    {
        goto L_0x004ab0ed;
    }
    // 004ab1b9  eb90                   -jmp 0x4ab14b
    goto L_0x004ab14b;
L_0x004ab1bb:
    // 004ab1bb  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 004ab1c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab1c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab1c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab1c7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab1c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab1c9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab1ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab1cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab1cc  803d04ee4d0000         +cmp byte ptr [0x4dee04], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5107204) /* 0x4dee04 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab1d3  0f85ab000000           -jne 0x4ab284
    if (!cpu.flags.zf)
    {
        goto L_0x004ab284;
    }
    // 004ab1d9  bbf0ed4d00             -mov ebx, 0x4dedf0
    cpu.ebx = 5107184 /*0x4dedf0*/;
    // 004ab1de  eb39                   -jmp 0x4ab219
    goto L_0x004ab219;
L_0x004ab1e0:
    // 004ab1e0  e8e8510000             -call 0x4b03cd
    cpu.esp -= 4;
    sub_4b03cd(app, cpu);
    if (cpu.terminate) return;
    // 004ab1e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab1e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab1e9  742b                   -je 0x4ab216
    if (cpu.flags.zf)
    {
        goto L_0x004ab216;
    }
    // 004ab1eb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ab1ed  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ab1ee  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004ab1f0  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004ab1f2  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab1f4  49                     -dec ecx
    (cpu.ecx)--;
    // 004ab1f5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ab1f7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004ab1f9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ab1fb  49                     -dec ecx
    (cpu.ecx)--;
    // 004ab1fc  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ab1fd  81f903010000           +cmp ecx, 0x103
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(259 /*0x103*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab203  7711                   -ja 0x4ab216
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab216;
    }
    // 004ab205  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 004ab20a  b804ee4d00             -mov eax, 0x4dee04
    cpu.eax = 5107204 /*0x4dee04*/;
    // 004ab20f  e825dd0000             -call 0x4b8f39
    cpu.esp -= 4;
    sub_4b8f39(app, cpu);
    if (cpu.terminate) return;
    // 004ab214  eb0a                   -jmp 0x4ab220
    goto L_0x004ab220;
L_0x004ab216:
    // 004ab216  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004ab219:
    // 004ab219  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ab21b  803800                 +cmp byte ptr [eax], 0
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
    // 004ab21e  75c0                   -jne 0x4ab1e0
    if (!cpu.flags.zf)
    {
        goto L_0x004ab1e0;
    }
L_0x004ab220:
    // 004ab220  803d04ee4d0000         +cmp byte ptr [0x4dee04], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5107204) /* 0x4dee04 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab227  752a                   -jne 0x4ab253
    if (!cpu.flags.zf)
    {
        goto L_0x004ab253;
    }
    // 004ab229  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab22b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab22d  bf04ee4d00             -mov edi, 0x4dee04
    cpu.edi = 5107204 /*0x4dee04*/;
    // 004ab232  e80eb8fdff             -call 0x486a45
    cpu.esp -= 4;
    sub_486a45(app, cpu);
    if (cpu.terminate) return;
    // 004ab237  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab239  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004ab23a:
    // 004ab23a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ab23c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004ab23e  3c00                   +cmp al, 0
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
    // 004ab240  7410                   -je 0x4ab252
    if (cpu.flags.zf)
    {
        goto L_0x004ab252;
    }
    // 004ab242  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab245  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ab248  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004ab24b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ab24e  3c00                   +cmp al, 0
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
    // 004ab250  75e8                   -jne 0x4ab23a
    if (!cpu.flags.zf)
    {
        goto L_0x004ab23a;
    }
L_0x004ab252:
    // 004ab252  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004ab253:
    // 004ab253  bf04ee4d00             -mov edi, 0x4dee04
    cpu.edi = 5107204 /*0x4dee04*/;
    // 004ab258  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ab259  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004ab25b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004ab25d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab25f  49                     -dec ecx
    (cpu.ecx)--;
    // 004ab260  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ab262  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004ab264  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ab266  49                     -dec ecx
    (cpu.ecx)--;
    // 004ab267  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ab268  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004ab26b  0504ee4d00             -add eax, 0x4dee04
    (cpu.eax) += x86::reg32(x86::sreg32(5107204 /*0x4dee04*/));
    // 004ab270  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004ab272  80fb5c                 +cmp bl, 0x5c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab275  740d                   -je 0x4ab284
    if (cpu.flags.zf)
    {
        goto L_0x004ab284;
    }
    // 004ab277  80fb2f                 +cmp bl, 0x2f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ab27a  7408                   -je 0x4ab284
    if (cpu.flags.zf)
    {
        goto L_0x004ab284;
    }
    // 004ab27c  40                     -inc eax
    (cpu.eax)++;
    // 004ab27d  c6005c                 -mov byte ptr [eax], 0x5c
    app->getMemory<x86::reg8>(cpu.eax) = 92 /*0x5c*/;
    // 004ab280  40                     -inc eax
    (cpu.eax)++;
    // 004ab281  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x004ab284:
    // 004ab284  b804ee4d00             -mov eax, 0x4dee04
    cpu.eax = 5107204 /*0x4dee04*/;
    // 004ab289  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab28a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab28b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab28c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab28d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab28e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab28f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab28f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab290  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab291  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab292  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab293  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab294  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab295  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab297  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004ab29a  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab2a0  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004ab2a3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ab2a5  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004ab2a8  0f8478000000           -je 0x4ab326
    if (cpu.flags.zf)
    {
        goto L_0x004ab326;
    }
    // 004ab2ae  88e7                   -mov bh, ah
    cpu.bh = cpu.ah;
    // 004ab2b0  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004ab2b3  8a410c                 -mov al, byte ptr [ecx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004ab2b6  88790d                 -mov byte ptr [ecx + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 004ab2b9  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004ab2bb  0f84a0000000           -je 0x4ab361
    if (cpu.flags.zf)
    {
        goto L_0x004ab361;
    }
    // 004ab2c1  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004ab2c4  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004ab2c7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab2c9  0f8492000000           -je 0x4ab361
    if (cpu.flags.zf)
    {
        goto L_0x004ab361;
    }
    // 004ab2cf  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ab2d1  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
L_0x004ab2d4:
    // 004ab2d4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ab2d6  0f8485000000           -je 0x4ab361
    if (cpu.flags.zf)
    {
        goto L_0x004ab361;
    }
    // 004ab2dc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ab2de  0f857d000000           -jne 0x4ab361
    if (!cpu.flags.zf)
    {
        goto L_0x004ab361;
    }
    // 004ab2e4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ab2e6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ab2e8  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ab2eb  e82b7d0000             -call 0x4b301b
    cpu.esp -= 4;
    sub_4b301b(app, cpu);
    if (cpu.terminate) return;
    // 004ab2f0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab2f2  83f8ff                 +cmp eax, -1
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
    // 004ab2f5  750d                   -jne 0x4ab304
    if (!cpu.flags.zf)
    {
        goto L_0x004ab304;
    }
    // 004ab2f7  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004ab2fa  80cb20                 +or bl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004ab2fd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ab2ff  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 004ab302  eb1c                   -jmp 0x4ab320
    goto L_0x004ab320;
L_0x004ab304:
    // 004ab304  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab306  7518                   -jne 0x4ab320
    if (!cpu.flags.zf)
    {
        goto L_0x004ab320;
    }
    // 004ab308  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 004ab30d  e89eb3ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004ab312  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004ab315  80cc20                 -or ah, 0x20
    cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004ab318  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 004ab31d  88610c                 -mov byte ptr [ecx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x004ab320:
    // 004ab320  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab322  29d6                   +sub esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab324  ebae                   -jmp 0x4ab2d4
    goto L_0x004ab2d4;
L_0x004ab326:
    // 004ab326  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004ab329  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004ab32d  7432                   -je 0x4ab361
    if (cpu.flags.zf)
    {
        goto L_0x004ab361;
    }
    // 004ab32f  80610cef               -and byte ptr [ecx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004ab333  f6410d20               +test byte ptr [ecx + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 004ab337  7528                   -jne 0x4ab361
    if (!cpu.flags.zf)
    {
        goto L_0x004ab361;
    }
    // 004ab339  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004ab33c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab33e  7411                   -je 0x4ab351
    if (cpu.flags.zf)
    {
        goto L_0x004ab351;
    }
    // 004ab340  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab342  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004ab347  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004ab349  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ab34c  e8a6000000             -call 0x4ab3f7
    cpu.esp -= 4;
    sub_4ab3f7(app, cpu);
    if (cpu.terminate) return;
L_0x004ab351:
    // 004ab351  83f8ff                 +cmp eax, -1
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
    // 004ab354  750b                   -jne 0x4ab361
    if (!cpu.flags.zf)
    {
        goto L_0x004ab361;
    }
    // 004ab356  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004ab359  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004ab35c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ab35e  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
L_0x004ab361:
    // 004ab361  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004ab364  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab367  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ab36e  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004ab370  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ab372  7518                   -jne 0x4ab38c
    if (!cpu.flags.zf)
    {
        goto L_0x004ab38c;
    }
    // 004ab374  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004ab377  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004ab37b  740f                   -je 0x4ab38c
    if (cpu.flags.zf)
    {
        goto L_0x004ab38c;
    }
    // 004ab37d  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ab380  e845dc0000             -call 0x4b8fca
    cpu.esp -= 4;
    sub_4b8fca(app, cpu);
    if (cpu.terminate) return;
    // 004ab385  83f8ff                 +cmp eax, -1
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
    // 004ab388  7502                   -jne 0x4ab38c
    if (!cpu.flags.zf)
    {
        goto L_0x004ab38c;
    }
    // 004ab38a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004ab38c:
    // 004ab38c  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ab38f  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab395  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ab397  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab398  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab399  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab39a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab39b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab39c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab39d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab39e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab39e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab39f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab3a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab3a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab3a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab3a4  f6400c80               +test byte ptr [eax + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 004ab3a8  740d                   -je 0x4ab3b7
    if (cpu.flags.zf)
    {
        goto L_0x004ab3b7;
    }
    // 004ab3aa  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004ab3ae  7407                   -je 0x4ab3b7
    if (cpu.flags.zf)
    {
        goto L_0x004ab3b7;
    }
    // 004ab3b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab3b2  e8d1790000             -call 0x4b2d88
    cpu.esp -= 4;
    sub_4b2d88(app, cpu);
    if (cpu.terminate) return;
L_0x004ab3b7:
    // 004ab3b7  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004ab3ba  e885ce0000             -call 0x4b8244
    cpu.esp -= 4;
    sub_4b8244(app, cpu);
    if (cpu.terminate) return;
    // 004ab3bf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab3c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab3c3  83f8ff                 +cmp eax, -1
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
    // 004ab3c6  742a                   -je 0x4ab3f2
    if (cpu.flags.zf)
    {
        goto L_0x004ab3f2;
    }
    // 004ab3c8  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004ab3cb  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab3d1  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab3d4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ab3d6  740f                   -je 0x4ab3e7
    if (cpu.flags.zf)
    {
        goto L_0x004ab3e7;
    }
    // 004ab3d8  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004ab3dc  7405                   -je 0x4ab3e3
    if (cpu.flags.zf)
    {
        goto L_0x004ab3e3;
    }
    // 004ab3de  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004ab3e1  eb04                   -jmp 0x4ab3e7
    goto L_0x004ab3e7;
L_0x004ab3e3:
    // 004ab3e3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ab3e5  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004ab3e7:
    // 004ab3e7  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004ab3ea  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab3f0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004ab3f2:
    // 004ab3f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab3f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab3f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab3f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab3f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab3f7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab3f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab3f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab3f9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab3fb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ab3fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab3ff  7c08                   -jl 0x4ab409
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab409;
    }
    // 004ab401  3b05bc064e00           +cmp eax, dword ptr [0x4e06bc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113532) /* 0x4e06bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab407  7612                   -jbe 0x4ab41b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab41b;
    }
L_0x004ab409:
    // 004ab409  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004ab40e  e89db2ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004ab413  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ab418  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab419  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab41a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab41b:
    // 004ab41b  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab421  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab423  e850cd0000             -call 0x4b8178
    cpu.esp -= 4;
    sub_4b8178(app, cpu);
    if (cpu.terminate) return;
    // 004ab428  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab42a  7e10                   -jle 0x4ab43c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab43c;
    }
    // 004ab42c  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004ab42e  750c                   -jne 0x4ab43c
    if (!cpu.flags.zf)
    {
        goto L_0x004ab43c;
    }
    // 004ab430  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004ab433  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab435  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab437  e891cd0000             -call 0x4b81cd
    cpu.esp -= 4;
    sub_4b81cd(app, cpu);
    if (cpu.terminate) return;
L_0x004ab43c:
    // 004ab43c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab43d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ab43f  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004ab444  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ab446  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab447  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004ab44a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab44b  2eff1590654c00         -call dword ptr cs:[0x4c6590]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006736) /* 0x4c6590 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab452  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab454  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab456  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab45c  83f9ff                 +cmp ecx, -1
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
    // 004ab45f  7505                   -jne 0x4ab466
    if (!cpu.flags.zf)
    {
        goto L_0x004ab466;
    }
    // 004ab461  e84cb1ffff             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
L_0x004ab466:
    // 004ab466  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab468  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab469  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab46a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab46b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab46b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab46c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab46d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab46e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab46f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab470  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab471  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab473  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab475  7c08                   -jl 0x4ab47f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab47f;
    }
    // 004ab477  3b05bc064e00           +cmp eax, dword ptr [0x4e06bc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113532) /* 0x4e06bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab47d  7611                   -jbe 0x4ab490
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab490;
    }
L_0x004ab47f:
    // 004ab47f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004ab484  e827b2ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004ab489  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ab48e  eb61                   -jmp 0x4ab4f1
    goto L_0x004ab4f1;
L_0x004ab490:
    // 004ab490  8b15ac064e00           -mov edx, dword ptr [0x4e06ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004ab496  8b2db0ed4d00           -mov ebp, dword ptr [0x4dedb0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5107120) /* 0x4dedb0 */);
    // 004ab49c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ab49e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ab4a0  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004ab4a3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ab4a5  741e                   -je 0x4ab4c5
    if (cpu.flags.zf)
    {
        goto L_0x004ab4c5;
    }
    // 004ab4a7  ff15a4ed4d00           -call dword ptr [0x4deda4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107108) /* 0x4deda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab4ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab4af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab4b1  7412                   -je 0x4ab4c5
    if (cpu.flags.zf)
    {
        goto L_0x004ab4c5;
    }
    // 004ab4b3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab4b5  ff15a8ed4d00           -call dword ptr [0x4deda8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107112) /* 0x4deda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab4bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab4bd  ff15b0ed4d00           -call dword ptr [0x4dedb0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107120) /* 0x4dedb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab4c3  eb21                   -jmp 0x4ab4e6
    goto L_0x004ab4e6;
L_0x004ab4c5:
    // 004ab4c5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ab4c7  751d                   -jne 0x4ab4e6
    if (!cpu.flags.zf)
    {
        goto L_0x004ab4e6;
    }
    // 004ab4c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab4ca  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab4d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab4d3  7511                   -jne 0x4ab4e6
    if (!cpu.flags.zf)
    {
        goto L_0x004ab4e6;
    }
    // 004ab4d5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004ab4da  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004ab4df  e8ccb1ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004ab4e4  eb09                   -jmp 0x4ab4ef
    goto L_0x004ab4ef;
L_0x004ab4e6:
    // 004ab4e6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab4e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab4ea  e8decc0000             -call 0x4b81cd
    cpu.esp -= 4;
    sub_4b81cd(app, cpu);
    if (cpu.terminate) return;
L_0x004ab4ef:
    // 004ab4ef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004ab4f1:
    // 004ab4f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab4f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab4f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab4f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab4fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab4fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab4fc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab4fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab500  0f84f1000000           -je 0x4ab5f7
    if (cpu.flags.zf)
    {
        goto L_0x004ab5f7;
    }
    // 004ab506  ff1574ed4d00           -call dword ptr [0x4ded74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107060) /* 0x4ded74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab50c  8b0db4675b00           -mov ecx, dword ptr [0x5b67b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5990324) /* 0x5b67b4 */);
    // 004ab512  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab514  7440                   -je 0x4ab556
    if (cpu.flags.zf)
    {
        goto L_0x004ab556;
    }
    // 004ab516  39f1                   +cmp ecx, esi
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
    // 004ab518  770c                   -ja 0x4ab526
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab526;
    }
    // 004ab51a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab51c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab51e  39f0                   +cmp eax, esi
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
    // 004ab520  0f878b000000           -ja 0x4ab5b1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab5b1;
    }
L_0x004ab526:
    // 004ab526  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab528  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004ab52b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab52d  7410                   -je 0x4ab53f
    if (cpu.flags.zf)
    {
        goto L_0x004ab53f;
    }
    // 004ab52f  39f1                   +cmp ecx, esi
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
    // 004ab531  770c                   -ja 0x4ab53f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab53f;
    }
    // 004ab533  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab535  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab537  39f2                   +cmp edx, esi
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
    // 004ab539  0f8772000000           -ja 0x4ab5b1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab5b1;
    }
L_0x004ab53f:
    // 004ab53f  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab542  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab544  7410                   -je 0x4ab556
    if (cpu.flags.zf)
    {
        goto L_0x004ab556;
    }
    // 004ab546  39f1                   +cmp ecx, esi
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
    // 004ab548  770c                   -ja 0x4ab556
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab556;
    }
    // 004ab54a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab54c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab54e  39f0                   +cmp eax, esi
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
    // 004ab550  0f875b000000           -ja 0x4ab5b1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab5b1;
    }
L_0x004ab556:
    // 004ab556  8b0d3cdb4d00           -mov ecx, dword ptr [0x4ddb3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102396) /* 0x4ddb3c */);
    // 004ab55c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab55e  7434                   -je 0x4ab594
    if (cpu.flags.zf)
    {
        goto L_0x004ab594;
    }
    // 004ab560  39f1                   +cmp ecx, esi
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
    // 004ab562  7708                   -ja 0x4ab56c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab56c;
    }
    // 004ab564  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab566  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab568  39f0                   +cmp eax, esi
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
    // 004ab56a  7745                   -ja 0x4ab5b1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab5b1;
    }
L_0x004ab56c:
    // 004ab56c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab56e  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004ab571  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab573  740c                   -je 0x4ab581
    if (cpu.flags.zf)
    {
        goto L_0x004ab581;
    }
    // 004ab575  39f1                   +cmp ecx, esi
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
    // 004ab577  7708                   -ja 0x4ab581
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab581;
    }
    // 004ab579  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab57b  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab57d  39f2                   +cmp edx, esi
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
    // 004ab57f  7730                   -ja 0x4ab5b1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab5b1;
    }
L_0x004ab581:
    // 004ab581  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab584  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab586  740c                   -je 0x4ab594
    if (cpu.flags.zf)
    {
        goto L_0x004ab594;
    }
    // 004ab588  39f1                   +cmp ecx, esi
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
    // 004ab58a  7708                   -ja 0x4ab594
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab594;
    }
    // 004ab58c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab58e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab590  39f0                   +cmp eax, esi
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
    // 004ab592  771d                   -ja 0x4ab5b1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab5b1;
    }
L_0x004ab594:
    // 004ab594  8b0d38db4d00           -mov ecx, dword ptr [0x4ddb38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102392) /* 0x4ddb38 */);
    // 004ab59a  eb0f                   -jmp 0x4ab5ab
    goto L_0x004ab5ab;
L_0x004ab59c:
    // 004ab59c  39f1                   +cmp ecx, esi
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
    // 004ab59e  7708                   -ja 0x4ab5a8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab5a8;
    }
    // 004ab5a0  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab5a2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab5a4  39f0                   +cmp eax, esi
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
    // 004ab5a6  7709                   -ja 0x4ab5b1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ab5b1;
    }
L_0x004ab5a8:
    // 004ab5a8  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x004ab5ab:
    // 004ab5ab  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab5ad  75ed                   -jne 0x4ab59c
    if (!cpu.flags.zf)
    {
        goto L_0x004ab59c;
    }
    // 004ab5af  eb40                   -jmp 0x4ab5f1
    goto L_0x004ab5f1;
L_0x004ab5b1:
    // 004ab5b1  b838db4d00             -mov eax, 0x4ddb38
    cpu.eax = 5102392 /*0x4ddb38*/;
    // 004ab5b6  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004ab5b8  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ab5be  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ab5c0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab5c2  e8698d0000             -call 0x4b4330
    cpu.esp -= 4;
    sub_4b4330(app, cpu);
    if (cpu.terminate) return;
    // 004ab5c7  8b153cdb4d00           -mov edx, dword ptr [0x4ddb3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102396) /* 0x4ddb3c */);
    // 004ab5cd  890db4675b00           -mov dword ptr [0x5b67b4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5990324) /* 0x5b67b4 */) = cpu.ecx;
    // 004ab5d3  39d1                   +cmp ecx, edx
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
    // 004ab5d5  7312                   -jae 0x4ab5e9
    if (!cpu.flags.cf)
    {
        goto L_0x004ab5e9;
    }
    // 004ab5d7  8b1d40db4d00           -mov ebx, dword ptr [0x4ddb40]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102400) /* 0x4ddb40 */);
    // 004ab5dd  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004ab5e0  39d8                   +cmp eax, ebx
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
    // 004ab5e2  7605                   -jbe 0x4ab5e9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ab5e9;
    }
    // 004ab5e4  a340db4d00             -mov dword ptr [0x4ddb40], eax
    app->getMemory<x86::reg32>(x86::reg32(5102400) /* 0x4ddb40 */) = cpu.eax;
L_0x004ab5e9:
    // 004ab5e9  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004ab5eb  882560945b00           -mov byte ptr [0x5b9460], ah
    app->getMemory<x86::reg8>(x86::reg32(6001760) /* 0x5b9460 */) = cpu.ah;
L_0x004ab5f1:
    // 004ab5f1  ff157ced4d00           -call dword ptr [0x4ded7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107068) /* 0x4ded7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ab5f7:
    // 004ab5f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab5fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab5fc  e9adc3fdff             -jmp 0x4879ae
    return sub_4879ae(app, cpu);
}

/* align: skip  */
void Application::sub_4ab601(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab601  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab602  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab603  ba27904b00             -mov edx, 0x4b9027
    cpu.edx = 4952103 /*0x4b9027*/;
    // 004ab608  bb3b914b00             -mov ebx, 0x4b913b
    cpu.ebx = 4952379 /*0x4b913b*/;
    // 004ab60d  89153c074e00           -mov dword ptr [0x4e073c], edx
    app->getMemory<x86::reg32>(x86::reg32(5113660) /* 0x4e073c */) = cpu.edx;
    // 004ab613  891d40074e00           -mov dword ptr [0x4e0740], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113664) /* 0x4e0740 */) = cpu.ebx;
    // 004ab619  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab61a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab61b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab61c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab61c  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004ab61d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab61e  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004ab623  757f                   -jne 0x4ab6a4
    if (!cpu.flags.zf)
    {
        goto L_0x004ab6a4;
    }
L_0x004ab625:
    // 004ab625  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab628  7825                   -js 0x4ab64f
    if (cpu.flags.sf)
    {
        goto L_0x004ab64f;
    }
L_0x004ab62a:
    // 004ab62a  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 004ab62c  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 004ab62f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ab631  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab633  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab636  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 004ab639  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 004ab63c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ab63e  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab641  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab644  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004ab647  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004ab64a  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab64d  79db                   -jns 0x4ab62a
    if (!cpu.flags.sf)
    {
        goto L_0x004ab62a;
    }
L_0x004ab64f:
    // 004ab64f  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab652  780f                   -js 0x4ab663
    if (cpu.flags.sf)
    {
        goto L_0x004ab663;
    }
L_0x004ab654:
    // 004ab654  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 004ab656  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab658  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004ab65b  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab65e  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab661  79f1                   -jns 0x4ab654
    if (!cpu.flags.sf)
    {
        goto L_0x004ab654;
    }
L_0x004ab663:
    // 004ab663  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab666  7502                   -jne 0x4ab66a
    if (!cpu.flags.zf)
    {
        goto L_0x004ab66a;
    }
    // 004ab668  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab669  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab66a:
    // 004ab66a  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab66d  720d                   -jb 0x4ab67c
    if (cpu.flags.cf)
    {
        goto L_0x004ab67c;
    }
    // 004ab66f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab671  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab674  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ab676  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab679  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004ab67c:
    // 004ab67c  83fb02                 +cmp ebx, 2
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
    // 004ab67f  720f                   -jb 0x4ab690
    if (cpu.flags.cf)
    {
        goto L_0x004ab690;
    }
    // 004ab681  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004ab684  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004ab687  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004ab68a  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ab68d  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004ab690:
    // 004ab690  83fb01                 +cmp ebx, 1
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
    // 004ab693  720d                   -jb 0x4ab6a2
    if (cpu.flags.cf)
    {
        goto L_0x004ab6a2;
    }
    // 004ab695  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004ab697  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004ab69a  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004ab69c  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab69f  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ab6a2:
    // 004ab6a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab6a4:
    // 004ab6a4  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004ab6a9  7412                   -je 0x4ab6bd
    if (cpu.flags.zf)
    {
        goto L_0x004ab6bd;
    }
    // 004ab6ab  83fb01                 +cmp ebx, 1
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
    // 004ab6ae  7c0d                   -jl 0x4ab6bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab6bd;
    }
    // 004ab6b0  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004ab6b2  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004ab6b5  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004ab6b7  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab6ba  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ab6bd:
    // 004ab6bd  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004ab6c2  7414                   -je 0x4ab6d8
    if (cpu.flags.zf)
    {
        goto L_0x004ab6d8;
    }
    // 004ab6c4  83fb02                 +cmp ebx, 2
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
    // 004ab6c7  7c0f                   -jl 0x4ab6d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab6d8;
    }
    // 004ab6c9  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004ab6cc  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004ab6cf  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004ab6d2  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ab6d5  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004ab6d8:
    // 004ab6d8  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004ab6dd  7412                   -je 0x4ab6f1
    if (cpu.flags.zf)
    {
        goto L_0x004ab6f1;
    }
    // 004ab6df  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab6e2  7c0d                   -jl 0x4ab6f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab6f1;
    }
    // 004ab6e4  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab6e6  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab6e9  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ab6eb  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab6ee  83eb04                 +sub ebx, 4
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
L_0x004ab6f1:
    // 004ab6f1  e92fffffff             -jmp 0x4ab625
    goto L_0x004ab625;
}

/* align: skip  */
void Application::sub_4ab61d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ab61d;
    // 004ab61c  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x004ab61d:
    // 004ab61d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab61e  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004ab623  757f                   -jne 0x4ab6a4
    if (!cpu.flags.zf)
    {
        goto L_0x004ab6a4;
    }
L_0x004ab625:
    // 004ab625  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab628  7825                   -js 0x4ab64f
    if (cpu.flags.sf)
    {
        goto L_0x004ab64f;
    }
L_0x004ab62a:
    // 004ab62a  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 004ab62c  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 004ab62f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ab631  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab633  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab636  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 004ab639  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 004ab63c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ab63e  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab641  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab644  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004ab647  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004ab64a  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab64d  79db                   -jns 0x4ab62a
    if (!cpu.flags.sf)
    {
        goto L_0x004ab62a;
    }
L_0x004ab64f:
    // 004ab64f  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab652  780f                   -js 0x4ab663
    if (cpu.flags.sf)
    {
        goto L_0x004ab663;
    }
L_0x004ab654:
    // 004ab654  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 004ab656  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ab658  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004ab65b  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab65e  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab661  79f1                   -jns 0x4ab654
    if (!cpu.flags.sf)
    {
        goto L_0x004ab654;
    }
L_0x004ab663:
    // 004ab663  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab666  7502                   -jne 0x4ab66a
    if (!cpu.flags.zf)
    {
        goto L_0x004ab66a;
    }
    // 004ab668  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab669  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab66a:
    // 004ab66a  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab66d  720d                   -jb 0x4ab67c
    if (cpu.flags.cf)
    {
        goto L_0x004ab67c;
    }
    // 004ab66f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab671  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab674  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ab676  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab679  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004ab67c:
    // 004ab67c  83fb02                 +cmp ebx, 2
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
    // 004ab67f  720f                   -jb 0x4ab690
    if (cpu.flags.cf)
    {
        goto L_0x004ab690;
    }
    // 004ab681  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004ab684  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004ab687  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004ab68a  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ab68d  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004ab690:
    // 004ab690  83fb01                 +cmp ebx, 1
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
    // 004ab693  720d                   -jb 0x4ab6a2
    if (cpu.flags.cf)
    {
        goto L_0x004ab6a2;
    }
    // 004ab695  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004ab697  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004ab69a  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004ab69c  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab69f  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ab6a2:
    // 004ab6a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab6a4:
    // 004ab6a4  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004ab6a9  7412                   -je 0x4ab6bd
    if (cpu.flags.zf)
    {
        goto L_0x004ab6bd;
    }
    // 004ab6ab  83fb01                 +cmp ebx, 1
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
    // 004ab6ae  7c0d                   -jl 0x4ab6bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab6bd;
    }
    // 004ab6b0  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004ab6b2  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004ab6b5  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004ab6b7  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab6ba  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ab6bd:
    // 004ab6bd  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004ab6c2  7414                   -je 0x4ab6d8
    if (cpu.flags.zf)
    {
        goto L_0x004ab6d8;
    }
    // 004ab6c4  83fb02                 +cmp ebx, 2
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
    // 004ab6c7  7c0f                   -jl 0x4ab6d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab6d8;
    }
    // 004ab6c9  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004ab6cc  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004ab6cf  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004ab6d2  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ab6d5  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004ab6d8:
    // 004ab6d8  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004ab6dd  7412                   -je 0x4ab6f1
    if (cpu.flags.zf)
    {
        goto L_0x004ab6f1;
    }
    // 004ab6df  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab6e2  7c0d                   -jl 0x4ab6f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab6f1;
    }
    // 004ab6e4  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab6e6  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab6e9  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ab6eb  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab6ee  83eb04                 +sub ebx, 4
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
L_0x004ab6f1:
    // 004ab6f1  e92fffffff             -jmp 0x4ab625
    goto L_0x004ab625;
}

/* align: skip 0x00 0x00 */
void Application::sub_4ab6f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab6f8  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004ab6f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab6fa  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004ab6ff  0f8585000000           -jne 0x4ab78a
    if (!cpu.flags.zf)
    {
        goto L_0x004ab78a;
    }
L_0x004ab705:
    // 004ab705  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab708  7829                   -js 0x4ab733
    if (cpu.flags.sf)
    {
        goto L_0x004ab733;
    }
L_0x004ab70a:
    // 004ab70a  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 004ab70d  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004ab711  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004ab715  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004ab719  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 004ab71c  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 004ab720  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 004ab724  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 004ab728  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004ab72b  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004ab72e  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab731  79d7                   -jns 0x4ab70a
    if (!cpu.flags.sf)
    {
        goto L_0x004ab70a;
    }
L_0x004ab733:
    // 004ab733  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab736  7811                   -js 0x4ab749
    if (cpu.flags.sf)
    {
        goto L_0x004ab749;
    }
L_0x004ab738:
    // 004ab738  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 004ab73b  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 004ab73e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004ab741  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab744  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab747  79ef                   -jns 0x4ab738
    if (!cpu.flags.sf)
    {
        goto L_0x004ab738;
    }
L_0x004ab749:
    // 004ab749  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab74c  7502                   -jne 0x4ab750
    if (!cpu.flags.zf)
    {
        goto L_0x004ab750;
    }
    // 004ab74e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab74f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab750:
    // 004ab750  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab753  720d                   -jb 0x4ab762
    if (cpu.flags.cf)
    {
        goto L_0x004ab762;
    }
    // 004ab755  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab757  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab75a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ab75c  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab75f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004ab762:
    // 004ab762  83fb02                 +cmp ebx, 2
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
    // 004ab765  720f                   -jb 0x4ab776
    if (cpu.flags.cf)
    {
        goto L_0x004ab776;
    }
    // 004ab767  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004ab76a  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004ab76d  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004ab770  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ab773  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004ab776:
    // 004ab776  83fb01                 +cmp ebx, 1
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
    // 004ab779  720d                   -jb 0x4ab788
    if (cpu.flags.cf)
    {
        goto L_0x004ab788;
    }
    // 004ab77b  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004ab77d  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004ab780  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004ab782  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab785  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ab788:
    // 004ab788  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab789  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab78a:
    // 004ab78a  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004ab78f  7412                   -je 0x4ab7a3
    if (cpu.flags.zf)
    {
        goto L_0x004ab7a3;
    }
    // 004ab791  83fb01                 +cmp ebx, 1
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
    // 004ab794  7c0d                   -jl 0x4ab7a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab7a3;
    }
    // 004ab796  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004ab798  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004ab79b  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004ab79d  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab7a0  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ab7a3:
    // 004ab7a3  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004ab7a8  7414                   -je 0x4ab7be
    if (cpu.flags.zf)
    {
        goto L_0x004ab7be;
    }
    // 004ab7aa  83fb02                 +cmp ebx, 2
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
    // 004ab7ad  7c0f                   -jl 0x4ab7be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab7be;
    }
    // 004ab7af  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004ab7b2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004ab7b5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004ab7b8  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ab7bb  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004ab7be:
    // 004ab7be  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004ab7c3  7412                   -je 0x4ab7d7
    if (cpu.flags.zf)
    {
        goto L_0x004ab7d7;
    }
    // 004ab7c5  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab7c8  7c0d                   -jl 0x4ab7d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab7d7;
    }
    // 004ab7ca  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab7cc  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab7cf  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ab7d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab7d4  83eb04                 +sub ebx, 4
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
L_0x004ab7d7:
    // 004ab7d7  e929ffffff             -jmp 0x4ab705
    goto L_0x004ab705;
}

/* align: skip  */
void Application::sub_4ab6f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ab6f9;
    // 004ab6f8  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x004ab6f9:
    // 004ab6f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab6fa  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004ab6ff  0f8585000000           -jne 0x4ab78a
    if (!cpu.flags.zf)
    {
        goto L_0x004ab78a;
    }
L_0x004ab705:
    // 004ab705  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab708  7829                   -js 0x4ab733
    if (cpu.flags.sf)
    {
        goto L_0x004ab733;
    }
L_0x004ab70a:
    // 004ab70a  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 004ab70d  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004ab711  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004ab715  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004ab719  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 004ab71c  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 004ab720  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 004ab724  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 004ab728  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004ab72b  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004ab72e  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab731  79d7                   -jns 0x4ab70a
    if (!cpu.flags.sf)
    {
        goto L_0x004ab70a;
    }
L_0x004ab733:
    // 004ab733  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab736  7811                   -js 0x4ab749
    if (cpu.flags.sf)
    {
        goto L_0x004ab749;
    }
L_0x004ab738:
    // 004ab738  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 004ab73b  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 004ab73e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004ab741  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab744  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab747  79ef                   -jns 0x4ab738
    if (!cpu.flags.sf)
    {
        goto L_0x004ab738;
    }
L_0x004ab749:
    // 004ab749  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab74c  7502                   -jne 0x4ab750
    if (!cpu.flags.zf)
    {
        goto L_0x004ab750;
    }
    // 004ab74e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab74f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab750:
    // 004ab750  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab753  720d                   -jb 0x4ab762
    if (cpu.flags.cf)
    {
        goto L_0x004ab762;
    }
    // 004ab755  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab757  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab75a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ab75c  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab75f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004ab762:
    // 004ab762  83fb02                 +cmp ebx, 2
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
    // 004ab765  720f                   -jb 0x4ab776
    if (cpu.flags.cf)
    {
        goto L_0x004ab776;
    }
    // 004ab767  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004ab76a  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004ab76d  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004ab770  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ab773  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004ab776:
    // 004ab776  83fb01                 +cmp ebx, 1
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
    // 004ab779  720d                   -jb 0x4ab788
    if (cpu.flags.cf)
    {
        goto L_0x004ab788;
    }
    // 004ab77b  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004ab77d  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004ab780  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004ab782  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab785  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ab788:
    // 004ab788  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab789  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab78a:
    // 004ab78a  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004ab78f  7412                   -je 0x4ab7a3
    if (cpu.flags.zf)
    {
        goto L_0x004ab7a3;
    }
    // 004ab791  83fb01                 +cmp ebx, 1
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
    // 004ab794  7c0d                   -jl 0x4ab7a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab7a3;
    }
    // 004ab796  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004ab798  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004ab79b  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004ab79d  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ab7a0  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ab7a3:
    // 004ab7a3  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004ab7a8  7414                   -je 0x4ab7be
    if (cpu.flags.zf)
    {
        goto L_0x004ab7be;
    }
    // 004ab7aa  83fb02                 +cmp ebx, 2
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
    // 004ab7ad  7c0f                   -jl 0x4ab7be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab7be;
    }
    // 004ab7af  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004ab7b2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004ab7b5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004ab7b8  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ab7bb  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004ab7be:
    // 004ab7be  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004ab7c3  7412                   -je 0x4ab7d7
    if (cpu.flags.zf)
    {
        goto L_0x004ab7d7;
    }
    // 004ab7c5  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab7c8  7c0d                   -jl 0x4ab7d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab7d7;
    }
    // 004ab7ca  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab7cc  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab7cf  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ab7d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab7d4  83eb04                 +sub ebx, 4
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
L_0x004ab7d7:
    // 004ab7d7  e929ffffff             -jmp 0x4ab705
    goto L_0x004ab705;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4ab7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab7e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab7e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab7e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab7e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab7e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab7e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab7e6  bafc144d00             -mov edx, 0x4d14fc
    cpu.edx = 5051644 /*0x4d14fc*/;
    // 004ab7eb  e8aeedfdff             -call 0x48a59e
    cpu.esp -= 4;
    sub_48a59e(app, cpu);
    if (cpu.terminate) return;
    // 004ab7f0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ab7f2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ab7f4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab7f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab7f8  7509                   -jne 0x4ab803
    if (!cpu.flags.zf)
    {
        goto L_0x004ab803;
    }
L_0x004ab7fa:
    // 004ab7fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab7fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab7fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab7fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab7ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab800  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab801  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab802  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab803:
    // 004ab803  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004ab808  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab80a  e894e3ffff             -call 0x4a9ba3
    cpu.esp -= 4;
    sub_4a9ba3(app, cpu);
    if (cpu.terminate) return;
    // 004ab80f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab811  75e7                   -jne 0x4ab7fa
    if (!cpu.flags.zf)
    {
        goto L_0x004ab7fa;
    }
    // 004ab813  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab815  e884fbffff             -call 0x4ab39e
    cpu.esp -= 4;
    sub_4ab39e(app, cpu);
    if (cpu.terminate) return;
    // 004ab81a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ab81c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab81e  7eda                   -jle 0x4ab7fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab7fa;
    }
    // 004ab820  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab822  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab824  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab826  e878e3ffff             -call 0x4a9ba3
    cpu.esp -= 4;
    sub_4a9ba3(app, cpu);
    if (cpu.terminate) return;
    // 004ab82b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab82d  75cb                   -jne 0x4ab7fa
    if (!cpu.flags.zf)
    {
        goto L_0x004ab7fa;
    }
    // 004ab82f  b81c100000             -mov eax, 0x101c
    cpu.eax = 4124 /*0x101c*/;
    // 004ab834  e8a72bffff             -call 0x49e3e0
    cpu.esp -= 4;
    sub_49e3e0(app, cpu);
    if (cpu.terminate) return;
    // 004ab839  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab83b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab83d  74bb                   -je 0x4ab7fa
    if (cpu.flags.zf)
    {
        goto L_0x004ab7fa;
    }
    // 004ab83f  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ab841  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004ab844  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004ab847  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004ab84a  89b814100000           -mov dword ptr [eax + 0x1014], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = cpu.edi;
    // 004ab850  89b818100000           -mov dword ptr [eax + 0x1018], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4120) /* 0x1018 */) = cpu.edi;
    // 004ab856  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004ab859  898810100000           -mov dword ptr [eax + 0x1010], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.ecx;
    // 004ab85f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab861  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab862  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab863  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab864  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab865  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab866  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab867  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab868(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab868  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab869  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab86a  ba00154d00             -mov edx, 0x4d1500
    cpu.edx = 5051648 /*0x4d1500*/;
    // 004ab86f  e82aedfdff             -call 0x48a59e
    cpu.esp -= 4;
    sub_48a59e(app, cpu);
    if (cpu.terminate) return;
    // 004ab874  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab876  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab878  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab87a  7505                   -jne 0x4ab881
    if (!cpu.flags.zf)
    {
        goto L_0x004ab881;
    }
L_0x004ab87c:
    // 004ab87c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab87e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab87f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab880  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab881:
    // 004ab881  b81c100000             -mov eax, 0x101c
    cpu.eax = 4124 /*0x101c*/;
    // 004ab886  e8552bffff             -call 0x49e3e0
    cpu.esp -= 4;
    sub_49e3e0(app, cpu);
    if (cpu.terminate) return;
    // 004ab88b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab88d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab88f  74eb                   -je 0x4ab87c
    if (cpu.flags.zf)
    {
        goto L_0x004ab87c;
    }
    // 004ab891  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ab898  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004ab89f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004ab8a6  c7801410000000000000   -mov dword ptr [eax + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 004ab8b0  c7801810000001000000   -mov dword ptr [eax + 0x1018], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4120) /* 0x1018 */) = 1 /*0x1*/;
    // 004ab8ba  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ab8bc  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004ab8bf  899010100000           -mov dword ptr [eax + 0x1010], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.edx;
    // 004ab8c5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab8c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab8c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab8c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
