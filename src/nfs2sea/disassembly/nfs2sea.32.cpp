#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x90 */
void Application::sub_4b7794(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7794  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b7798  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b779e  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b77a5  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b77a9  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004b77ad  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b77b1  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004b77b5  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b77b8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b77bc  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b77bf  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b77c3  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b77c6  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b77c9  c700f0764b00           -mov dword ptr [eax], 0x4b76f0
    app->getMemory<x86::reg32>(cpu.eax) = 4945648 /*0x4b76f0*/;
    // 004b77cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b77d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b77d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b77d4  0f77                   -emms 
    cpu.mmx.init();
    // 004b77d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b77e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b77e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b77e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b77e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b77e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b77e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b77e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b77e6  833dacab4d0000         +cmp dword ptr [0x4dabac], 0
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
    // 004b77ed  744b                   -je 0x4b783a
    if (cpu.flags.zf)
    {
        goto L_0x004b783a;
    }
    // 004b77ef  ba70c14b00             -mov edx, 0x4bc170
    cpu.edx = 4964720 /*0x4bc170*/;
    // 004b77f4  b990c14b00             -mov ecx, 0x4bc190
    cpu.ecx = 4964752 /*0x4bc190*/;
    // 004b77f9  bbc0c14b00             -mov ebx, 0x4bc1c0
    cpu.ebx = 4964800 /*0x4bc1c0*/;
    // 004b77fe  bee0c14b00             -mov esi, 0x4bc1e0
    cpu.esi = 4964832 /*0x4bc1e0*/;
    // 004b7803  bf00c24b00             -mov edi, 0x4bc200
    cpu.edi = 4964864 /*0x4bc200*/;
    // 004b7808  bd30c24b00             -mov ebp, 0x4bc230
    cpu.ebp = 4964912 /*0x4bc230*/;
    // 004b780d  891514de4d00           -mov dword ptr [0x4dde14], edx
    app->getMemory<x86::reg32>(x86::reg32(5103124) /* 0x4dde14 */) = cpu.edx;
    // 004b7813  890d18de4d00           -mov dword ptr [0x4dde18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5103128) /* 0x4dde18 */) = cpu.ecx;
    // 004b7819  891d1cde4d00           -mov dword ptr [0x4dde1c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103132) /* 0x4dde1c */) = cpu.ebx;
    // 004b781f  893520de4d00           -mov dword ptr [0x4dde20], esi
    app->getMemory<x86::reg32>(x86::reg32(5103136) /* 0x4dde20 */) = cpu.esi;
    // 004b7825  893d24de4d00           -mov dword ptr [0x4dde24], edi
    app->getMemory<x86::reg32>(x86::reg32(5103140) /* 0x4dde24 */) = cpu.edi;
    // 004b782b  892d28de4d00           -mov dword ptr [0x4dde28], ebp
    app->getMemory<x86::reg32>(x86::reg32(5103144) /* 0x4dde28 */) = cpu.ebp;
    // 004b7831  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7833  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7834  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7835  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7836  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7837  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7838  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7839  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b783a:
    // 004b783a  e8114a0000             -call 0x4bc250
    cpu.esp -= 4;
    sub_4bc250(app, cpu);
    if (cpu.terminate) return;
    // 004b783f  b980c24b00             -mov ecx, 0x4bc280
    cpu.ecx = 4964992 /*0x4bc280*/;
    // 004b7844  bba0c24b00             -mov ebx, 0x4bc2a0
    cpu.ebx = 4965024 /*0x4bc2a0*/;
    // 004b7849  bed0c24b00             -mov esi, 0x4bc2d0
    cpu.esi = 4965072 /*0x4bc2d0*/;
    // 004b784e  bff0c24b00             -mov edi, 0x4bc2f0
    cpu.edi = 4965104 /*0x4bc2f0*/;
    // 004b7853  bd10c34b00             -mov ebp, 0x4bc310
    cpu.ebp = 4965136 /*0x4bc310*/;
    // 004b7858  b840c34b00             -mov eax, 0x4bc340
    cpu.eax = 4965184 /*0x4bc340*/;
    // 004b785d  890d14de4d00           -mov dword ptr [0x4dde14], ecx
    app->getMemory<x86::reg32>(x86::reg32(5103124) /* 0x4dde14 */) = cpu.ecx;
    // 004b7863  891d18de4d00           -mov dword ptr [0x4dde18], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103128) /* 0x4dde18 */) = cpu.ebx;
    // 004b7869  89351cde4d00           -mov dword ptr [0x4dde1c], esi
    app->getMemory<x86::reg32>(x86::reg32(5103132) /* 0x4dde1c */) = cpu.esi;
    // 004b786f  893d20de4d00           -mov dword ptr [0x4dde20], edi
    app->getMemory<x86::reg32>(x86::reg32(5103136) /* 0x4dde20 */) = cpu.edi;
    // 004b7875  892d24de4d00           -mov dword ptr [0x4dde24], ebp
    app->getMemory<x86::reg32>(x86::reg32(5103140) /* 0x4dde24 */) = cpu.ebp;
    // 004b787b  a328de4d00             -mov dword ptr [0x4dde28], eax
    app->getMemory<x86::reg32>(x86::reg32(5103144) /* 0x4dde28 */) = cpu.eax;
    // 004b7880  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7882  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7883  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7884  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7885  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7886  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7887  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7888  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b7890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7892  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7893  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7894  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b7895  833dacab4d0000         +cmp dword ptr [0x4dabac], 0
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
    // 004b789c  744c                   -je 0x4b78ea
    if (cpu.flags.zf)
    {
        goto L_0x004b78ea;
    }
    // 004b789e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b789f  ba60c34b00             -mov edx, 0x4bc360
    cpu.edx = 4965216 /*0x4bc360*/;
    // 004b78a4  b980c34b00             -mov ecx, 0x4bc380
    cpu.ecx = 4965248 /*0x4bc380*/;
    // 004b78a9  bbb0c34b00             -mov ebx, 0x4bc3b0
    cpu.ebx = 4965296 /*0x4bc3b0*/;
    // 004b78ae  bed0c34b00             -mov esi, 0x4bc3d0
    cpu.esi = 4965328 /*0x4bc3d0*/;
    // 004b78b3  bff0c34b00             -mov edi, 0x4bc3f0
    cpu.edi = 4965360 /*0x4bc3f0*/;
    // 004b78b8  bd20c44b00             -mov ebp, 0x4bc420
    cpu.ebp = 4965408 /*0x4bc420*/;
    // 004b78bd  89152cde4d00           -mov dword ptr [0x4dde2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5103148) /* 0x4dde2c */) = cpu.edx;
    // 004b78c3  890d30de4d00           -mov dword ptr [0x4dde30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5103152) /* 0x4dde30 */) = cpu.ecx;
    // 004b78c9  891d34de4d00           -mov dword ptr [0x4dde34], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103156) /* 0x4dde34 */) = cpu.ebx;
    // 004b78cf  893538de4d00           -mov dword ptr [0x4dde38], esi
    app->getMemory<x86::reg32>(x86::reg32(5103160) /* 0x4dde38 */) = cpu.esi;
    // 004b78d5  893d3cde4d00           -mov dword ptr [0x4dde3c], edi
    app->getMemory<x86::reg32>(x86::reg32(5103164) /* 0x4dde3c */) = cpu.edi;
    // 004b78db  892d40de4d00           -mov dword ptr [0x4dde40], ebp
    app->getMemory<x86::reg32>(x86::reg32(5103168) /* 0x4dde40 */) = cpu.ebp;
    // 004b78e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b78e2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b78e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b78e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b78e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b78e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b78e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b78e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b78ea:
    // 004b78ea  b940c44b00             -mov ecx, 0x4bc440
    cpu.ecx = 4965440 /*0x4bc440*/;
    // 004b78ef  bb60c44b00             -mov ebx, 0x4bc460
    cpu.ebx = 4965472 /*0x4bc460*/;
    // 004b78f4  be90c44b00             -mov esi, 0x4bc490
    cpu.esi = 4965520 /*0x4bc490*/;
    // 004b78f9  bfb0c44b00             -mov edi, 0x4bc4b0
    cpu.edi = 4965552 /*0x4bc4b0*/;
    // 004b78fe  bdd0c44b00             -mov ebp, 0x4bc4d0
    cpu.ebp = 4965584 /*0x4bc4d0*/;
    // 004b7903  b800c54b00             -mov eax, 0x4bc500
    cpu.eax = 4965632 /*0x4bc500*/;
    // 004b7908  890d2cde4d00           -mov dword ptr [0x4dde2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5103148) /* 0x4dde2c */) = cpu.ecx;
    // 004b790e  891d30de4d00           -mov dword ptr [0x4dde30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103152) /* 0x4dde30 */) = cpu.ebx;
    // 004b7914  893534de4d00           -mov dword ptr [0x4dde34], esi
    app->getMemory<x86::reg32>(x86::reg32(5103156) /* 0x4dde34 */) = cpu.esi;
    // 004b791a  893d38de4d00           -mov dword ptr [0x4dde38], edi
    app->getMemory<x86::reg32>(x86::reg32(5103160) /* 0x4dde38 */) = cpu.edi;
    // 004b7920  892d3cde4d00           -mov dword ptr [0x4dde3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5103164) /* 0x4dde3c */) = cpu.ebp;
    // 004b7926  a340de4d00             -mov dword ptr [0x4dde40], eax
    app->getMemory<x86::reg32>(x86::reg32(5103168) /* 0x4dde40 */) = cpu.eax;
    // 004b792b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b792d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b792e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b792f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7930  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7931  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7932  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b7940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7941  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7942  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7943  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b7944  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7947  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 004b794c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b794e:
    // 004b794e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b7950  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b7952  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004b7954  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b7956  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004b7959:
    // 004b7959  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b795b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004b795e  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004b7960  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7963  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004b7966  81c200000010           -add edx, 0x10000000
    (cpu.edx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 004b796c  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b796f  d99860945b00           -fstp dword ptr [eax + 0x5b9460]
    app->getMemory<float>(cpu.eax + x86::reg32(6001760) /* 0x5b9460 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7975  39f8                   +cmp eax, edi
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
    // 004b7977  75e0                   -jne 0x4b7959
    if (!cpu.flags.zf)
    {
        goto L_0x004b7959;
    }
    // 004b7979  43                     -inc ebx
    (cpu.ebx)++;
    // 004b797a  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b797d  83fb0d                 +cmp ebx, 0xd
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
    // 004b7980  7ccc                   -jl 0x4b794e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b794e;
    }
    // 004b7982  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7985  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7986  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7987  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7988  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7989  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b798c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b798c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b798d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b798e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b798f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b7990  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 004b7995  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b7997:
    // 004b7997  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b7999  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b799b  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004b799d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b799f  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004b79a2:
    // 004b79a2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b79a4  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004b79a7  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004b79a9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b79ac  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004b79af  81c200000010           -add edx, 0x10000000
    (cpu.edx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 004b79b5  89b060985b00           -mov dword ptr [eax + 0x5b9860], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6002784) /* 0x5b9860 */) = cpu.esi;
    // 004b79bb  39f8                   +cmp eax, edi
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
    // 004b79bd  75e3                   -jne 0x4b79a2
    if (!cpu.flags.zf)
    {
        goto L_0x004b79a2;
    }
    // 004b79bf  43                     -inc ebx
    (cpu.ebx)++;
    // 004b79c0  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b79c3  83fb0d                 +cmp ebx, 0xd
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
    // 004b79c6  7ccf                   -jl 0x4b7997
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7997;
    }
    // 004b79c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b79c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b79ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b79cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b79cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b79d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b79d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b79d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b79d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b79d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b79d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b79d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b79d6  833dacab4d0000         +cmp dword ptr [0x4dabac], 0
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
    // 004b79dd  7450                   -je 0x4b7a2f
    if (cpu.flags.zf)
    {
        goto L_0x004b7a2f;
    }
    // 004b79df  e8a8ffffff             -call 0x4b798c
    cpu.esp -= 4;
    sub_4b798c(app, cpu);
    if (cpu.terminate) return;
    // 004b79e4  baa8c64b00             -mov edx, 0x4bc6a8
    cpu.edx = 4966056 /*0x4bc6a8*/;
    // 004b79e9  b9f8ca4b00             -mov ecx, 0x4bcaf8
    cpu.ecx = 4967160 /*0x4bcaf8*/;
    // 004b79ee  bb40cd4b00             -mov ebx, 0x4bcd40
    cpu.ebx = 4967744 /*0x4bcd40*/;
    // 004b79f3  be54cf4b00             -mov esi, 0x4bcf54
    cpu.esi = 4968276 /*0x4bcf54*/;
    // 004b79f8  bf58d44b00             -mov edi, 0x4bd458
    cpu.edi = 4969560 /*0x4bd458*/;
    // 004b79fd  bd6cd64b00             -mov ebp, 0x4bd66c
    cpu.ebp = 4970092 /*0x4bd66c*/;
    // 004b7a02  891544de4d00           -mov dword ptr [0x4dde44], edx
    app->getMemory<x86::reg32>(x86::reg32(5103172) /* 0x4dde44 */) = cpu.edx;
    // 004b7a08  890d48de4d00           -mov dword ptr [0x4dde48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5103176) /* 0x4dde48 */) = cpu.ecx;
    // 004b7a0e  891d4cde4d00           -mov dword ptr [0x4dde4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103180) /* 0x4dde4c */) = cpu.ebx;
    // 004b7a14  893550de4d00           -mov dword ptr [0x4dde50], esi
    app->getMemory<x86::reg32>(x86::reg32(5103184) /* 0x4dde50 */) = cpu.esi;
    // 004b7a1a  893d54de4d00           -mov dword ptr [0x4dde54], edi
    app->getMemory<x86::reg32>(x86::reg32(5103188) /* 0x4dde54 */) = cpu.edi;
    // 004b7a20  892d58de4d00           -mov dword ptr [0x4dde58], ebp
    app->getMemory<x86::reg32>(x86::reg32(5103192) /* 0x4dde58 */) = cpu.ebp;
    // 004b7a26  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7a28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a2b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b7a2f:
    // 004b7a2f  e80cffffff             -call 0x4b7940
    cpu.esp -= 4;
    sub_4b7940(app, cpu);
    if (cpu.terminate) return;
    // 004b7a34  b948d84b00             -mov ecx, 0x4bd848
    cpu.ecx = 4970568 /*0x4bd848*/;
    // 004b7a39  bb7cdc4b00             -mov ebx, 0x4bdc7c
    cpu.ebx = 4971644 /*0x4bdc7c*/;
    // 004b7a3e  be94de4b00             -mov esi, 0x4bde94
    cpu.esi = 4972180 /*0x4bde94*/;
    // 004b7a43  bf88e04b00             -mov edi, 0x4be088
    cpu.edi = 4972680 /*0x4be088*/;
    // 004b7a48  bd64e54b00             -mov ebp, 0x4be564
    cpu.ebp = 4973924 /*0x4be564*/;
    // 004b7a4d  b870e74b00             -mov eax, 0x4be770
    cpu.eax = 4974448 /*0x4be770*/;
    // 004b7a52  890d44de4d00           -mov dword ptr [0x4dde44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5103172) /* 0x4dde44 */) = cpu.ecx;
    // 004b7a58  891d48de4d00           -mov dword ptr [0x4dde48], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103176) /* 0x4dde48 */) = cpu.ebx;
    // 004b7a5e  89354cde4d00           -mov dword ptr [0x4dde4c], esi
    app->getMemory<x86::reg32>(x86::reg32(5103180) /* 0x4dde4c */) = cpu.esi;
    // 004b7a64  893d50de4d00           -mov dword ptr [0x4dde50], edi
    app->getMemory<x86::reg32>(x86::reg32(5103184) /* 0x4dde50 */) = cpu.edi;
    // 004b7a6a  892d54de4d00           -mov dword ptr [0x4dde54], ebp
    app->getMemory<x86::reg32>(x86::reg32(5103188) /* 0x4dde54 */) = cpu.ebp;
    // 004b7a70  a358de4d00             -mov dword ptr [0x4dde58], eax
    app->getMemory<x86::reg32>(x86::reg32(5103192) /* 0x4dde58 */) = cpu.eax;
    // 004b7a75  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7a77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7a7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b7a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7a80  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7a81  833dacab4d0000         +cmp dword ptr [0x4dabac], 0
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
    // 004b7a88  741f                   -je 0x4b7aa9
    if (cpu.flags.zf)
    {
        goto L_0x004b7aa9;
    }
    // 004b7a8a  bf44e94b00             -mov edi, 0x4be944
    cpu.edi = 4974916 /*0x4be944*/;
    // 004b7a8f  b818eb4b00             -mov eax, 0x4beb18
    cpu.eax = 4975384 /*0x4beb18*/;
    // 004b7a94  893d74de4d00           -mov dword ptr [0x4dde74], edi
    app->getMemory<x86::reg32>(x86::reg32(5103220) /* 0x4dde74 */) = cpu.edi;
    // 004b7a9a  893d80de4d00           -mov dword ptr [0x4dde80], edi
    app->getMemory<x86::reg32>(x86::reg32(5103232) /* 0x4dde80 */) = cpu.edi;
    // 004b7aa0  a388de4d00             -mov dword ptr [0x4dde88], eax
    app->getMemory<x86::reg32>(x86::reg32(5103240) /* 0x4dde88 */) = cpu.eax;
    // 004b7aa5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7aa7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7aa8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b7aa9:
    // 004b7aa9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7aaa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7aab  b9b8ec4b00             -mov ecx, 0x4becb8
    cpu.ecx = 4975800 /*0x4becb8*/;
    // 004b7ab0  bec0ee4b00             -mov esi, 0x4beec0
    cpu.esi = 4976320 /*0x4beec0*/;
    // 004b7ab5  890d74de4d00           -mov dword ptr [0x4dde74], ecx
    app->getMemory<x86::reg32>(x86::reg32(5103220) /* 0x4dde74 */) = cpu.ecx;
    // 004b7abb  890d80de4d00           -mov dword ptr [0x4dde80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5103232) /* 0x4dde80 */) = cpu.ecx;
    // 004b7ac1  893588de4d00           -mov dword ptr [0x4dde88], esi
    app->getMemory<x86::reg32>(x86::reg32(5103240) /* 0x4dde88 */) = cpu.esi;
    // 004b7ac7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7ac8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7ac9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7acb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7acc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b7ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7ad0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b7ad1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b7ad3  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b7ad4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b7ad7  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b7ada  8b15504f5b00           -mov edx, dword ptr [0x5b4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5984080) /* 0x5b4f50 */);
    // 004b7ae0  a1f0f55a00             -mov eax, dword ptr [0x5af5f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5961200) /* 0x5af5f0 */);
    // 004b7ae5  8b1d104f5b00           -mov ebx, dword ptr [0x5b4f10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5984016) /* 0x5b4f10 */);
    // 004b7aeb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7aee  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b7af1:
    // 004b7af1  3bc2                   +cmp eax, edx
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
    // 004b7af3  7c05                   -jl 0x4b7afa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7afa;
    }
    // 004b7af5  a1204f5b00             -mov eax, dword ptr [0x5b4f20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5984032) /* 0x5b4f20 */);
L_0x004b7afa:
    // 004b7afa  3bda                   +cmp ebx, edx
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
    // 004b7afc  7c06                   -jl 0x4b7b04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7b04;
    }
    // 004b7afe  8b1d204f5b00           -mov ebx, dword ptr [0x5b4f20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5984032) /* 0x5b4f20 */);
L_0x004b7b04:
    // 004b7b04  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b7b06  d805404f5b00           -fadd dword ptr [0x5b4f40]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5984064) /* 0x5b4f40 */));
    // 004b7b0c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004b7b0e  a3f0f55a00             -mov dword ptr [0x5af5f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5961200) /* 0x5af5f0 */) = cpu.eax;
    // 004b7b13  891d104f5b00           -mov dword ptr [0x5b4f10], ebx
    app->getMemory<x86::reg32>(x86::reg32(5984016) /* 0x5b4f10 */) = cpu.ebx;
    // 004b7b19  d80d18eb4d00           -fmul dword ptr [0x4deb18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106456) /* 0x4deb18 */));
    // 004b7b1f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7b21  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004b7b23  d80d18eb4d00           -fmul dword ptr [0x4deb18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106456) /* 0x4deb18 */));
    // 004b7b29  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7b2b  d91d404f5b00           -fstp dword ptr [0x5b4f40]
    app->getMemory<float>(x86::reg32(5984064) /* 0x5b4f40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7b31  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004b7b33  8b15544f5b00           -mov edx, dword ptr [0x5b4f54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5984084) /* 0x5b4f54 */);
    // 004b7b39  a1f4f55a00             -mov eax, dword ptr [0x5af5f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5961204) /* 0x5af5f4 */);
    // 004b7b3e  8b1d144f5b00           -mov ebx, dword ptr [0x5b4f14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5984020) /* 0x5b4f14 */);
    // 004b7b44  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7b47  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7b4a  3bc2                   +cmp eax, edx
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
    // 004b7b4c  7c05                   -jl 0x4b7b53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7b53;
    }
    // 004b7b4e  a1244f5b00             -mov eax, dword ptr [0x5b4f24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5984036) /* 0x5b4f24 */);
L_0x004b7b53:
    // 004b7b53  3bda                   +cmp ebx, edx
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
    // 004b7b55  7c06                   -jl 0x4b7b5d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7b5d;
    }
    // 004b7b57  8b1d244f5b00           -mov ebx, dword ptr [0x5b4f24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5984036) /* 0x5b4f24 */);
L_0x004b7b5d:
    // 004b7b5d  d805444f5b00           -fadd dword ptr [0x5b4f44]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5984068) /* 0x5b4f44 */));
    // 004b7b63  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004b7b65  a3f4f55a00             -mov dword ptr [0x5af5f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5961204) /* 0x5af5f4 */) = cpu.eax;
    // 004b7b6a  891d144f5b00           -mov dword ptr [0x5b4f14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5984020) /* 0x5b4f14 */) = cpu.ebx;
    // 004b7b70  d80d1ceb4d00           -fmul dword ptr [0x4deb1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106460) /* 0x4deb1c */));
    // 004b7b76  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7b78  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004b7b7a  d80d1ceb4d00           -fmul dword ptr [0x4deb1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106460) /* 0x4deb1c */));
    // 004b7b80  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7b82  d91d444f5b00           -fstp dword ptr [0x5b4f44]
    app->getMemory<float>(x86::reg32(5984068) /* 0x5b4f44 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7b88  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004b7b8a  d905ecea4d00           -fld dword ptr [0x4deaec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5106412) /* 0x4deaec */)));
    // 004b7b90  d80dfcea4d00           -fmul dword ptr [0x4deafc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106428) /* 0x4deafc */));
    // 004b7b96  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7b98  d80d0ceb4d00           -fmul dword ptr [0x4deb0c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106444) /* 0x4deb0c */));
    // 004b7b9e  a1f8f55a00             -mov eax, dword ptr [0x5af5f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5961208) /* 0x5af5f8 */);
    // 004b7ba3  8b1d184f5b00           -mov ebx, dword ptr [0x5b4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5984024) /* 0x5b4f18 */);
    // 004b7ba9  8b15584f5b00           -mov edx, dword ptr [0x5b4f58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5984088) /* 0x5b4f58 */);
    // 004b7baf  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b7bb1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7bb4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7bb7  3bc2                   +cmp eax, edx
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
    // 004b7bb9  7c05                   -jl 0x4b7bc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7bc0;
    }
    // 004b7bbb  a1284f5b00             -mov eax, dword ptr [0x5b4f28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5984040) /* 0x5b4f28 */);
L_0x004b7bc0:
    // 004b7bc0  3bda                   +cmp ebx, edx
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
    // 004b7bc2  7c06                   -jl 0x4b7bca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7bca;
    }
    // 004b7bc4  8b1d284f5b00           -mov ebx, dword ptr [0x5b4f28]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5984040) /* 0x5b4f28 */);
L_0x004b7bca:
    // 004b7bca  d915ecea4d00           -fst dword ptr [0x4deaec]
    app->getMemory<float>(x86::reg32(5106412) /* 0x4deaec */) = float(cpu.fpu.st(0));
    // 004b7bd0  d805484f5b00           -fadd dword ptr [0x5b4f48]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5984072) /* 0x5b4f48 */));
    // 004b7bd6  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004b7bd8  a3f8f55a00             -mov dword ptr [0x5af5f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5961208) /* 0x5af5f8 */) = cpu.eax;
    // 004b7bdd  891d184f5b00           -mov dword ptr [0x5b4f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(5984024) /* 0x5b4f18 */) = cpu.ebx;
    // 004b7be3  d80d20eb4d00           -fmul dword ptr [0x4deb20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106464) /* 0x4deb20 */));
    // 004b7be9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7beb  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004b7bed  d80d20eb4d00           -fmul dword ptr [0x4deb20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106464) /* 0x4deb20 */));
    // 004b7bf3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7bf5  d91d484f5b00           -fstp dword ptr [0x5b4f48]
    app->getMemory<float>(x86::reg32(5984072) /* 0x5b4f48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7bfb  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004b7bfd  8b155c4f5b00           -mov edx, dword ptr [0x5b4f5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5984092) /* 0x5b4f5c */);
    // 004b7c03  a1fcf55a00             -mov eax, dword ptr [0x5af5fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5961212) /* 0x5af5fc */);
    // 004b7c08  8b1d1c4f5b00           -mov ebx, dword ptr [0x5b4f1c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5984028) /* 0x5b4f1c */);
    // 004b7c0e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7c11  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7c14  3bc2                   +cmp eax, edx
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
    // 004b7c16  7c05                   -jl 0x4b7c1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7c1d;
    }
    // 004b7c18  a12c4f5b00             -mov eax, dword ptr [0x5b4f2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5984044) /* 0x5b4f2c */);
L_0x004b7c1d:
    // 004b7c1d  3bda                   +cmp ebx, edx
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
    // 004b7c1f  7c06                   -jl 0x4b7c27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7c27;
    }
    // 004b7c21  8b1d2c4f5b00           -mov ebx, dword ptr [0x5b4f2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5984044) /* 0x5b4f2c */);
L_0x004b7c27:
    // 004b7c27  d8054c4f5b00           -fadd dword ptr [0x5b4f4c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5984076) /* 0x5b4f4c */));
    // 004b7c2d  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004b7c2f  a3fcf55a00             -mov dword ptr [0x5af5fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5961212) /* 0x5af5fc */) = cpu.eax;
    // 004b7c34  891d1c4f5b00           -mov dword ptr [0x5b4f1c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5984028) /* 0x5b4f1c */) = cpu.ebx;
    // 004b7c3a  d80d24eb4d00           -fmul dword ptr [0x4deb24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106468) /* 0x4deb24 */));
    // 004b7c40  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7c42  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004b7c44  d80d24eb4d00           -fmul dword ptr [0x4deb24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106468) /* 0x4deb24 */));
    // 004b7c4a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7c4c  d91d4c4f5b00           -fstp dword ptr [0x5b4f4c]
    app->getMemory<float>(x86::reg32(5984076) /* 0x5b4f4c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7c52  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004b7c54  d905f4ea4d00           -fld dword ptr [0x4deaf4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5106420) /* 0x4deaf4 */)));
    // 004b7c5a  d80d04eb4d00           -fmul dword ptr [0x4deb04]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106436) /* 0x4deb04 */));
    // 004b7c60  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b7c62  d80d14eb4d00           -fmul dword ptr [0x4deb14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5106452) /* 0x4deb14 */));
    // 004b7c68  8b15504f5b00           -mov edx, dword ptr [0x5b4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5984080) /* 0x5b4f50 */);
    // 004b7c6e  a1f0f55a00             -mov eax, dword ptr [0x5af5f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5961200) /* 0x5af5f0 */);
    // 004b7c73  8b1d104f5b00           -mov ebx, dword ptr [0x5b4f10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5984016) /* 0x5b4f10 */);
    // 004b7c79  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b7c7b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7c7e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7c81  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7c84  d915f4ea4d00           -fst dword ptr [0x4deaf4]
    app->getMemory<float>(x86::reg32(5106420) /* 0x4deaf4 */) = float(cpu.fpu.st(0));
    // 004b7c8a  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7c8d  83e901                 +sub ecx, 1
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
    // 004b7c90  0f8f5bfeffff           -jg 0x4b7af1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b7af1;
    }
    // 004b7c96  61                     -popal 
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
    // 004b7c97  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7c98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b7ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7ca0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b7ca4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b7ca8  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b7cac  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b7caf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b7cb1  39c8                   +cmp eax, ecx
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
    // 004b7cb3  7313                   -jae 0x4b7cc8
    if (!cpu.flags.cf)
    {
        goto L_0x004b7cc8;
    }
L_0x004b7cb5:
    // 004b7cb5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004b7cb7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7cba  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004b7cbd  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b7cc0  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7cc3  39c8                   +cmp eax, ecx
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
    // 004b7cc5  72ee                   -jb 0x4b7cb5
    if (cpu.flags.cf)
    {
        goto L_0x004b7cb5;
    }
    // 004b7cc7  90                     -nop 
    ;
L_0x004b7cc8:
    // 004b7cc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b7cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7cd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7cd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b7cd2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7cd5  c704240000803f         -mov dword ptr [esp], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp) = 1065353216 /*0x3f800000*/;
    // 004b7cdc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b7cde  7e2f                   -jle 0x4b7d0f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b7d0f;
    }
    // 004b7ce0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b7ce5  39d0                   +cmp eax, edx
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
    // 004b7ce7  7c0f                   -jl 0x4b7cf8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7cf8;
    }
    // 004b7ce9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004b7ceb:
    // 004b7ceb  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 004b7ced  7512                   -jne 0x4b7d01
    if (!cpu.flags.zf)
    {
        goto L_0x004b7d01;
    }
L_0x004b7cef:
    // 004b7cef  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7cf1  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7cf4  39c2                   +cmp edx, eax
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
    // 004b7cf6  7ef3                   -jle 0x4b7ceb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b7ceb;
    }
L_0x004b7cf8:
    // 004b7cf8  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b7cfb  83c404                 +add esp, 4
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
    // 004b7cfe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7cff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7d00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b7d01:
    // 004b7d01  d90424                 +fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b7d04  d88978054e00           +fmul dword ptr [ecx + 0x4e0578]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(5113208) /* 0x4e0578 */));
    // 004b7d0a  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7d0d  ebe0                   -jmp 0x4b7cef
    goto L_0x004b7cef;
L_0x004b7d0f:
    // 004b7d0f  6bc0ff                 -imul eax, eax, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004b7d12  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b7d17  39d0                   +cmp eax, edx
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
    // 004b7d19  7cdd                   -jl 0x4b7cf8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7cf8;
    }
    // 004b7d1b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004b7d1d:
    // 004b7d1d  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 004b7d1f  750b                   -jne 0x4b7d2c
    if (!cpu.flags.zf)
    {
        goto L_0x004b7d2c;
    }
    // 004b7d21  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7d23  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7d26  39c2                   +cmp edx, eax
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
    // 004b7d28  7fce                   -jg 0x4b7cf8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b7cf8;
    }
    // 004b7d2a  ebf1                   -jmp 0x4b7d1d
    goto L_0x004b7d1d;
L_0x004b7d2c:
    // 004b7d2c  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b7d2f  d8b178054e00           -fdiv dword ptr [ecx + 0x4e0578]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(5113208) /* 0x4e0578 */));
    // 004b7d35  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7d38  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7d3a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7d3d  39c2                   +cmp edx, eax
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
    // 004b7d3f  7fb7                   -jg 0x4b7cf8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b7cf8;
    }
    // 004b7d41  ebda                   -jmp 0x4b7d1d
    goto L_0x004b7d1d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b7d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7d50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7d51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7d52  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b7d54  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b7d56  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004b7d59  c0e407                 +shl ah, 7
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
    // 004b7d5c  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b7d5e  00e4                   +add ah, ah
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
    // 004b7d60  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004b7d62  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b7d64  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b7d69  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b7d6b  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 004b7d72  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b7d74  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b7d76  b900000100             -mov ecx, 0x10000
    cpu.ecx = 65536 /*0x10000*/;
    // 004b7d7b  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7d7d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b7d7f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b7d81  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b7d84  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7d87  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b7d89  83f87f                 +cmp eax, 0x7f
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
    // 004b7d8c  7f16                   -jg 0x4b7da4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b7da4;
    }
L_0x004b7d8e:
    // 004b7d8e  81c200000100           -add edx, 0x10000
    (cpu.edx) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 004b7d94  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b7d97  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b7d9a  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004b7d9c  83ff7f                 +cmp edi, 0x7f
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
    // 004b7d9f  7f0b                   -jg 0x4b7dac
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b7dac;
    }
    // 004b7da1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7da2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7da3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b7da4:
    // 004b7da4  c7037f000000           -mov dword ptr [ebx], 0x7f
    app->getMemory<x86::reg32>(cpu.ebx) = 127 /*0x7f*/;
    // 004b7daa  ebe2                   -jmp 0x4b7d8e
    goto L_0x004b7d8e;
L_0x004b7dac:
    // 004b7dac  c7067f000000           -mov dword ptr [esi], 0x7f
    app->getMemory<x86::reg32>(cpu.esi) = 127 /*0x7f*/;
    // 004b7db2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7db3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7db4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7db5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7db5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7db6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7db7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b7db8  8a2585eb4d00           -mov ah, byte ptr [0x4deb85]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5106565) /* 0x4deb85 */);
    // 004b7dbe  80e4f8                 -and ah, 0xf8
    cpu.ah &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004b7dc1  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004b7dc3  882585eb4d00           -mov byte ptr [0x4deb85], ah
    app->getMemory<x86::reg8>(x86::reg32(5106565) /* 0x4deb85 */) = cpu.ah;
    // 004b7dc9  80ca04                 +or dl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004b7dcc  bb44eb4d00             -mov ebx, 0x4deb44
    cpu.ebx = 5106500 /*0x4deb44*/;
    // 004b7dd1  881585eb4d00           -mov byte ptr [0x4deb85], dl
    app->getMemory<x86::reg8>(x86::reg32(5106565) /* 0x4deb85 */) = cpu.dl;
    // 004b7dd7  eb5d                   -jmp 0x4b7e36
    goto L_0x004b7e36;
L_0x004b7dd9:
    // 004b7dd9  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004b7dde  e8e0e7feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b7de3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b7de5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b7de7  751f                   -jne 0x4b7e08
    if (!cpu.flags.zf)
    {
        goto L_0x004b7e08;
    }
    // 004b7de9  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004b7dee  e8d0e7feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b7df3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b7df5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b7df7  750f                   -jne 0x4b7e08
    if (!cpu.flags.zf)
    {
        goto L_0x004b7e08;
    }
    // 004b7df9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b7dfe  b868184d00             -mov eax, 0x4d1868
    cpu.eax = 5052520 /*0x4d1868*/;
    // 004b7e03  e8f9390000             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
L_0x004b7e08:
    // 004b7e08  a1a4675b00             -mov eax, dword ptr [0x5b67a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */);
    // 004b7e0d  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b7e10  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b7e12  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004b7e15  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b7e1c  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b7e1f  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b7e23  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b7e26  890da4675b00           -mov dword ptr [0x5b67a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */) = cpu.ecx;
    // 004b7e2c  83c31a                 -add ebx, 0x1a
    (cpu.ebx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 004b7e2f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x004b7e36:
    // 004b7e36  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b7e39  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b7e3b  759c                   -jne 0x4b7dd9
    if (!cpu.flags.zf)
    {
        goto L_0x004b7dd9;
    }
    // 004b7e3d  8915a8675b00           -mov dword ptr [0x5b67a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5990312) /* 0x5b67a8 */) = cpu.edx;
    // 004b7e43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7e44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7e45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7e46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7e47(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7e47  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b7e49  e80a000000             -call 0x4b7e58
    cpu.esp -= 4;
    sub_4b7e58(app, cpu);
    if (cpu.terminate) return;
    // 004b7e4e  e9dd1cffff             -jmp 0x4a9b30
    return sub_4a9b30(app, cpu);
}

/* align: skip  */
void Application::sub_4b7e53(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7e53  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004b7e58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7e59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7e5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b7e5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7e5c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b7e5e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b7e61  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b7e63  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b7e66  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7e68  be44eb4d00             -mov esi, 0x4deb44
    cpu.esi = 5106500 /*0x4deb44*/;
    // 004b7e6d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b7e6f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7e71  01c6                   +add esi, eax
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
    // 004b7e73  a1a4675b00             -mov eax, dword ptr [0x5b67a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */);
    // 004b7e78  eb2b                   -jmp 0x4b7ea5
    goto L_0x004b7ea5;
L_0x004b7e7a:
    // 004b7e7a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b7e7c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b7e7f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b7e84  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 004b7e88  7513                   -jne 0x4b7e9d
    if (!cpu.flags.zf)
    {
        goto L_0x004b7e9d;
    }
    // 004b7e8a  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004b7e8e  750d                   -jne 0x4b7e9d
    if (!cpu.flags.zf)
    {
        goto L_0x004b7e9d;
    }
    // 004b7e90  39f0                   +cmp eax, esi
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
    // 004b7e92  720f                   -jb 0x4b7ea3
    if (cpu.flags.cf)
    {
        goto L_0x004b7ea3;
    }
    // 004b7e94  3d92eb4d00             +cmp eax, 0x4deb92
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5106578 /*0x4deb92*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b7e99  7302                   -jae 0x4b7e9d
    if (!cpu.flags.cf)
    {
        goto L_0x004b7e9d;
    }
    // 004b7e9b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b7e9d:
    // 004b7e9d  e85429fdff             -call 0x48a7f6
    cpu.esp -= 4;
    sub_48a7f6(app, cpu);
    if (cpu.terminate) return;
    // 004b7ea2  43                     -inc ebx
    (cpu.ebx)++;
L_0x004b7ea3:
    // 004b7ea3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004b7ea5:
    // 004b7ea5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b7ea7  75d1                   -jne 0x4b7e7a
    if (!cpu.flags.zf)
    {
        goto L_0x004b7e7a;
    }
    // 004b7ea9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b7eab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7eac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7ead  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7eae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7eaf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7e58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b7e58;
    // 004b7e53  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_entry_0x004b7e58:
    // 004b7e58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7e59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7e5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b7e5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7e5c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b7e5e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b7e61  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b7e63  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b7e66  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7e68  be44eb4d00             -mov esi, 0x4deb44
    cpu.esi = 5106500 /*0x4deb44*/;
    // 004b7e6d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b7e6f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7e71  01c6                   +add esi, eax
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
    // 004b7e73  a1a4675b00             -mov eax, dword ptr [0x5b67a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */);
    // 004b7e78  eb2b                   -jmp 0x4b7ea5
    goto L_0x004b7ea5;
L_0x004b7e7a:
    // 004b7e7a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b7e7c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b7e7f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b7e84  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 004b7e88  7513                   -jne 0x4b7e9d
    if (!cpu.flags.zf)
    {
        goto L_0x004b7e9d;
    }
    // 004b7e8a  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004b7e8e  750d                   -jne 0x4b7e9d
    if (!cpu.flags.zf)
    {
        goto L_0x004b7e9d;
    }
    // 004b7e90  39f0                   +cmp eax, esi
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
    // 004b7e92  720f                   -jb 0x4b7ea3
    if (cpu.flags.cf)
    {
        goto L_0x004b7ea3;
    }
    // 004b7e94  3d92eb4d00             +cmp eax, 0x4deb92
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5106578 /*0x4deb92*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b7e99  7302                   -jae 0x4b7e9d
    if (!cpu.flags.cf)
    {
        goto L_0x004b7e9d;
    }
    // 004b7e9b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b7e9d:
    // 004b7e9d  e85429fdff             -call 0x48a7f6
    cpu.esp -= 4;
    sub_48a7f6(app, cpu);
    if (cpu.terminate) return;
    // 004b7ea2  43                     -inc ebx
    (cpu.ebx)++;
L_0x004b7ea3:
    // 004b7ea3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004b7ea5:
    // 004b7ea5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b7ea7  75d1                   -jne 0x4b7e7a
    if (!cpu.flags.zf)
    {
        goto L_0x004b7e7a;
    }
    // 004b7ea9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b7eab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7eac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7ead  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7eae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7eaf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7eb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7eb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7eb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b7eb3  8b0dac064e00           -mov ecx, dword ptr [0x4e06ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b7eb9  a1b0064e00             -mov eax, dword ptr [0x4e06b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */);
    // 004b7ebe  3b05bc064e00           +cmp eax, dword ptr [0x4e06bc]
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
    // 004b7ec4  7304                   -jae 0x4b7eca
    if (!cpu.flags.cf)
    {
        goto L_0x004b7eca;
    }
L_0x004b7ec6:
    // 004b7ec6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b7ec8  eb21                   -jmp 0x4b7eeb
    goto L_0x004b7eeb;
L_0x004b7eca:
    // 004b7eca  8b1db0064e00           -mov ebx, dword ptr [0x4e06b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */);
    // 004b7ed0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b7ed2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7ed4  c1e302                 +shl ebx, 2
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
    // 004b7ed7  eb09                   -jmp 0x4b7ee2
    goto L_0x004b7ee2;
L_0x004b7ed9:
    // 004b7ed9  833c0200               +cmp dword ptr [edx + eax], 0
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
    // 004b7edd  74e7                   -je 0x4b7ec6
    if (cpu.flags.zf)
    {
        goto L_0x004b7ec6;
    }
    // 004b7edf  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b7ee2:
    // 004b7ee2  39d8                   +cmp eax, ebx
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
    // 004b7ee4  7cf3                   -jl 0x4b7ed9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7ed9;
    }
    // 004b7ee6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b7eeb:
    // 004b7eeb  890dac064e00           -mov dword ptr [0x4e06ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */) = cpu.ecx;
    // 004b7ef1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7ef2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7ef3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7ef4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7ef5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7ef5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7ef6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7ef7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b7ef8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7ef9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b7efb  ff158ced4d00           -call dword ptr [0x4ded8c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107084) /* 0x4ded8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b7f01  8b0db0064e00           -mov ecx, dword ptr [0x4e06b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */);
    // 004b7f07  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7f09  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7f0b  c1e102                 +shl ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b7f0e  eb20                   -jmp 0x4b7f30
    goto L_0x004b7f30;
L_0x004b7f10:
    // 004b7f10  8b15ac064e00           -mov edx, dword ptr [0x4e06ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b7f16  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b7f18  833a00                 +cmp dword ptr [edx], 0
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
    // 004b7f1b  750f                   -jne 0x4b7f2c
    if (!cpu.flags.zf)
    {
        goto L_0x004b7f2c;
    }
    // 004b7f1d  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004b7f1f  ff1590ed4d00           -call dword ptr [0x4ded90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107088) /* 0x4ded90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b7f25  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b7f27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7f28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7f29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7f2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7f2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b7f2c:
    // 004b7f2c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7f2f  43                     -inc ebx
    (cpu.ebx)++;
L_0x004b7f30:
    // 004b7f30  39c8                   +cmp eax, ecx
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
    // 004b7f32  7cdc                   -jl 0x4b7f10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7f10;
    }
    // 004b7f34  8b15b0064e00           -mov edx, dword ptr [0x4e06b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */);
    // 004b7f3a  42                     -inc edx
    (cpu.edx)++;
    // 004b7f3b  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b7f40  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004b7f43  e8a389ffff             -call 0x4b08eb
    cpu.esp -= 4;
    sub_4b08eb(app, cpu);
    if (cpu.terminate) return;
    // 004b7f48  8b15b0064e00           -mov edx, dword ptr [0x4e06b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */);
    // 004b7f4e  a3ac064e00             -mov dword ptr [0x4e06ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */) = cpu.eax;
    // 004b7f53  893490                 -mov dword ptr [eax + edx*4], esi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 004b7f56  42                     -inc edx
    (cpu.edx)++;
    // 004b7f57  8915b0064e00           -mov dword ptr [0x4e06b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */) = cpu.edx;
    // 004b7f5d  ff1590ed4d00           -call dword ptr [0x4ded90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107088) /* 0x4ded90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b7f63  a1b0064e00             -mov eax, dword ptr [0x4e06b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */);
    // 004b7f68  48                     -dec eax
    (cpu.eax)--;
    // 004b7f69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7f6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7f6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7f6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7f6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7f6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b7f6e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7f6f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7f70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7f71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7f72  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b7f74  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b7f76  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b7f78  0f8c90000000           -jl 0x4b800e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b800e;
    }
    // 004b7f7e  ff158ced4d00           -call dword ptr [0x4ded8c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107084) /* 0x4ded8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b7f84  83fa01                 +cmp edx, 1
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
    // 004b7f87  7209                   -jb 0x4b7f92
    if (cpu.flags.cf)
    {
        goto L_0x004b7f92;
    }
    // 004b7f89  7610                   -jbe 0x4b7f9b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b7f9b;
    }
    // 004b7f8b  83fa02                 +cmp edx, 2
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
    // 004b7f8e  7410                   -je 0x4b7fa0
    if (cpu.flags.zf)
    {
        goto L_0x004b7fa0;
    }
    // 004b7f90  eb18                   -jmp 0x4b7faa
    goto L_0x004b7faa;
L_0x004b7f92:
    // 004b7f92  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b7f94  7514                   -jne 0x4b7faa
    if (!cpu.flags.zf)
    {
        goto L_0x004b7faa;
    }
    // 004b7f96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7f97  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 004b7f99  eb08                   -jmp 0x4b7fa3
    goto L_0x004b7fa3;
L_0x004b7f9b:
    // 004b7f9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7f9c  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 004b7f9e  eb03                   -jmp 0x4b7fa3
    goto L_0x004b7fa3;
L_0x004b7fa0:
    // 004b7fa0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7fa1  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x004b7fa3:
    // 004b7fa3  2eff1598654c00         -call dword ptr cs:[0x4c6598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006744) /* 0x4c6598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b7faa:
    // 004b7faa  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b7fac  8b15b0064e00           -mov edx, dword ptr [0x4e06b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */);
    // 004b7fb2  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b7fb5  39d6                   +cmp esi, edx
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
    // 004b7fb7  7d0a                   -jge 0x4b7fc3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b7fc3;
    }
    // 004b7fb9  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b7fbe  893c01                 -mov dword ptr [ecx + eax], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.edi;
    // 004b7fc1  eb45                   -jmp 0x4b8008
    goto L_0x004b8008;
L_0x004b7fc3:
    // 004b7fc3  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b7fc8  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004b7fcb  e81b89ffff             -call 0x4b08eb
    cpu.esp -= 4;
    sub_4b08eb(app, cpu);
    if (cpu.terminate) return;
    // 004b7fd0  8b1db0064e00           -mov ebx, dword ptr [0x4e06b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */);
    // 004b7fd6  a3ac064e00             -mov dword ptr [0x4e06ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */) = cpu.eax;
    // 004b7fdb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b7fdd  c1e002                 +shl eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b7fe0  eb11                   -jmp 0x4b7ff3
    goto L_0x004b7ff3;
L_0x004b7fe2:
    // 004b7fe2  8b15ac064e00           -mov edx, dword ptr [0x4e06ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b7fe8  43                     -inc ebx
    (cpu.ebx)++;
    // 004b7fe9  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004b7ff0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b7ff3:
    // 004b7ff3  39c8                   +cmp eax, ecx
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
    // 004b7ff5  7ceb                   -jl 0x4b7fe2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b7fe2;
    }
    // 004b7ff7  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b7ffc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b7ffe  46                     -inc esi
    (cpu.esi)++;
    // 004b7fff  893c90                 -mov dword ptr [eax + edx*4], edi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.edi;
    // 004b8002  8935b0064e00           -mov dword ptr [0x4e06b0], esi
    app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */) = cpu.esi;
L_0x004b8008:
    // 004b8008  ff1590ed4d00           -call dword ptr [0x4ded90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107088) /* 0x4ded90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b800e:
    // 004b800e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b800f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8010  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8011  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8012  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8013(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8013  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8014  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b8016  ff158ced4d00           -call dword ptr [0x4ded8c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107084) /* 0x4ded8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b801c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b801e  7e17                   -jle 0x4b8037
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b8037;
    }
    // 004b8020  3b15b0064e00           +cmp edx, dword ptr [0x4e06b0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113520) /* 0x4e06b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8026  7d0f                   -jge 0x4b8037
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b8037;
    }
    // 004b8028  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b802a  8b15ac064e00           -mov edx, dword ptr [0x4e06ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b8030  c7048200000000         -mov dword ptr [edx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = 0 /*0x0*/;
L_0x004b8037:
    // 004b8037  ff1590ed4d00           -call dword ptr [0x4ded90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107088) /* 0x4ded90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b803d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b803e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b803f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b803f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8040  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8041  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 004b8043  2eff1518654c00         -call dword ptr cs:[0x4c6518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006616) /* 0x4c6518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b804a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b804c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b804e  7405                   -je 0x4b8055
    if (cpu.flags.zf)
    {
        goto L_0x004b8055;
    }
    // 004b8050  83f8ff                 +cmp eax, -1
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
    // 004b8053  7505                   -jne 0x4b805a
    if (!cpu.flags.zf)
    {
        goto L_0x004b805a;
    }
L_0x004b8055:
    // 004b8055  e844000000             -call 0x4b809e
    cpu.esp -= 4;
    sub_4b809e(app, cpu);
    if (cpu.terminate) return;
L_0x004b805a:
    // 004b805a  e896feffff             -call 0x4b7ef5
    cpu.esp -= 4;
    sub_4b7ef5(app, cpu);
    if (cpu.terminate) return;
    // 004b805f  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 004b8061  2eff1518654c00         -call dword ptr cs:[0x4c6518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006616) /* 0x4c6518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8068  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b806a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b806c  7405                   -je 0x4b8073
    if (cpu.flags.zf)
    {
        goto L_0x004b8073;
    }
    // 004b806e  83f8ff                 +cmp eax, -1
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
    // 004b8071  7505                   -jne 0x4b8078
    if (!cpu.flags.zf)
    {
        goto L_0x004b8078;
    }
L_0x004b8073:
    // 004b8073  e826000000             -call 0x4b809e
    cpu.esp -= 4;
    sub_4b809e(app, cpu);
    if (cpu.terminate) return;
L_0x004b8078:
    // 004b8078  e878feffff             -call 0x4b7ef5
    cpu.esp -= 4;
    sub_4b7ef5(app, cpu);
    if (cpu.terminate) return;
    // 004b807d  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 004b807f  2eff1518654c00         -call dword ptr cs:[0x4c6518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006616) /* 0x4c6518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8086  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b8088  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b808a  7405                   -je 0x4b8091
    if (cpu.flags.zf)
    {
        goto L_0x004b8091;
    }
    // 004b808c  83f8ff                 +cmp eax, -1
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
    // 004b808f  7505                   -jne 0x4b8096
    if (!cpu.flags.zf)
    {
        goto L_0x004b8096;
    }
L_0x004b8091:
    // 004b8091  e808000000             -call 0x4b809e
    cpu.esp -= 4;
    sub_4b809e(app, cpu);
    if (cpu.terminate) return;
L_0x004b8096:
    // 004b8096  e85afeffff             -call 0x4b7ef5
    cpu.esp -= 4;
    sub_4b7ef5(app, cpu);
    if (cpu.terminate) return;
    // 004b809b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b809c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b809d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b809e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b809e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b809f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b80a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b80a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b80a4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b80a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b80a8  2eff1558644c00         -call dword ptr cs:[0x4c6458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006424) /* 0x4c6458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b80af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b80b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b80b3  750d                   -jne 0x4b80c2
    if (!cpu.flags.zf)
    {
        goto L_0x004b80c2;
    }
    // 004b80b5  8b15b4064e00           -mov edx, dword ptr [0x4e06b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113524) /* 0x4e06b4 */);
    // 004b80bb  42                     -inc edx
    (cpu.edx)++;
    // 004b80bc  8915b4064e00           -mov dword ptr [0x4e06b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5113524) /* 0x4e06b4 */) = cpu.edx;
L_0x004b80c2:
    // 004b80c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b80c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b80c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b80c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b80c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b80c7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004b80c9  740e                   -je 0x4b80d9
    if (cpu.flags.zf)
    {
        goto L_0x004b80d9;
    }
    // 004b80cb  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 004b80d1  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 004b80d7  eb0c                   -jmp 0x4b80e5
    goto L_0x004b80e5;
L_0x004b80d9:
    // 004b80d9  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 004b80df  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
L_0x004b80e5:
    // 004b80e5  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004b80e7  7403                   -je 0x4b80ec
    if (cpu.flags.zf)
    {
        goto L_0x004b80ec;
    }
    // 004b80e9  800b02                 -or byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004b80ec:
    // 004b80ec  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004b80ee  7403                   -je 0x4b80f3
    if (cpu.flags.zf)
    {
        goto L_0x004b80f3;
    }
    // 004b80f0  800b04                 -or byte ptr [ebx], 4
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004b80f3:
    // 004b80f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b80f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b80f4  83f802                 +cmp eax, 2
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
    // 004b80f7  750d                   -jne 0x4b8106
    if (!cpu.flags.zf)
    {
        goto L_0x004b8106;
    }
    // 004b80f9  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
L_0x004b80ff:
    // 004b80ff  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 004b8105  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8106:
    // 004b8106  83f801                 +cmp eax, 1
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
    // 004b8109  7508                   -jne 0x4b8113
    if (!cpu.flags.zf)
    {
        goto L_0x004b8113;
    }
    // 004b810b  c70200000040           -mov dword ptr [edx], 0x40000000
    app->getMemory<x86::reg32>(cpu.edx) = 1073741824 /*0x40000000*/;
    // 004b8111  ebec                   -jmp 0x4b80ff
    goto L_0x004b80ff;
L_0x004b8113:
    // 004b8113  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 004b8119  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 004b811f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8121  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b8123  83e070                 -and eax, 0x70
    cpu.eax &= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b8126  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b8129  83f820                 +cmp eax, 0x20
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
    // 004b812c  7210                   -jb 0x4b813e
    if (cpu.flags.cf)
    {
        goto L_0x004b813e;
    }
    // 004b812e  7638                   -jbe 0x4b8168
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8168;
    }
    // 004b8130  83f830                 +cmp eax, 0x30
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
    // 004b8133  7241                   -jb 0x4b8176
    if (cpu.flags.cf)
    {
        goto L_0x004b8176;
    }
    // 004b8135  7629                   -jbe 0x4b8160
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8160;
    }
    // 004b8137  83f840                 +cmp eax, 0x40
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
    // 004b813a  7434                   -je 0x4b8170
    if (cpu.flags.zf)
    {
        goto L_0x004b8170;
    }
    // 004b813c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b813d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b813e:
    // 004b813e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8140  7607                   -jbe 0x4b8149
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8149;
    }
    // 004b8142  83f810                 +cmp eax, 0x10
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
    // 004b8145  7411                   -je 0x4b8158
    if (cpu.flags.zf)
    {
        goto L_0x004b8158;
    }
    // 004b8147  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8148  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8149:
    // 004b8149  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 004b814f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b8151  7523                   -jne 0x4b8176
    if (!cpu.flags.zf)
    {
        goto L_0x004b8176;
    }
    // 004b8153  800a02                 -or byte ptr [edx], 2
    app->getMemory<x86::reg8>(cpu.edx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004b8156  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8157  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8158:
    // 004b8158  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004b815e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b815f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8160:
    // 004b8160  c70202000000           -mov dword ptr [edx], 2
    app->getMemory<x86::reg32>(cpu.edx) = 2 /*0x2*/;
    // 004b8166  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8167  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8168:
    // 004b8168  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 004b816e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b816f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8170:
    // 004b8170  c70203000000           -mov dword ptr [edx], 3
    app->getMemory<x86::reg32>(cpu.edx) = 3 /*0x3*/;
L_0x004b8176:
    // 004b8176  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8177  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8178(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8178  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8179  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b817a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b817b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b817d  3b05bc064e00           +cmp eax, dword ptr [0x4e06bc]
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
    // 004b8183  7206                   -jb 0x4b818b
    if (cpu.flags.cf)
    {
        goto L_0x004b818b;
    }
    // 004b8185  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b8187  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8188  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8189  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b818a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b818b:
    // 004b818b  83f803                 +cmp eax, 3
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
    // 004b818e  7d31                   -jge 0x4b81c1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b81c1;
    }
    // 004b8190  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b8192  a110074e00             -mov eax, dword ptr [0x4e0710]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113616) /* 0x4e0710 */);
    // 004b8197  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004b819a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b819c  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b819f  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 004b81a2  751d                   -jne 0x4b81c1
    if (!cpu.flags.zf)
    {
        goto L_0x004b81c1;
    }
    // 004b81a4  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 004b81a6  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004b81a9  886801                 -mov byte ptr [eax + 1], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 004b81ac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b81ae  e83b000000             -call 0x4b81ee
    cpu.esp -= 4;
    sub_4b81ee(app, cpu);
    if (cpu.terminate) return;
    // 004b81b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b81b5  740a                   -je 0x4b81c1
    if (cpu.flags.zf)
    {
        goto L_0x004b81c1;
    }
    // 004b81b7  a110074e00             -mov eax, dword ptr [0x4e0710]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113616) /* 0x4e0710 */);
    // 004b81bc  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004b81c1:
    // 004b81c1  a110074e00             -mov eax, dword ptr [0x4e0710]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113616) /* 0x4e0710 */);
    // 004b81c6  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004b81c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b81ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b81cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b81cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b81cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b81cd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b81ce  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b81d1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b81d3  740e                   -je 0x4b81e3
    if (cpu.flags.zf)
    {
        goto L_0x004b81e3;
    }
    // 004b81d5  8b1d10074e00           -mov ebx, dword ptr [0x4e0710]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113616) /* 0x4e0710 */);
    // 004b81db  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004b81de  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 004b81e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b81e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b81e3:
    // 004b81e3  8b1d10074e00           -mov ebx, dword ptr [0x4e0710]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113616) /* 0x4e0710 */);
    // 004b81e9  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 004b81ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b81ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b81ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b81ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b81ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b81f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b81f1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b81f3  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b81f9  833da4ed4d0000         +cmp dword ptr [0x4deda4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107108) /* 0x4deda4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8200  741d                   -je 0x4b821f
    if (cpu.flags.zf)
    {
        goto L_0x004b821f;
    }
    // 004b8202  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8204  ff15a4ed4d00           -call dword ptr [0x4deda4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107108) /* 0x4deda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b820a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b820c  7411                   -je 0x4b821f
    if (cpu.flags.zf)
    {
        goto L_0x004b821f;
    }
L_0x004b820e:
    // 004b820e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8210  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8216  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b821b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b821c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b821d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b821e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b821f:
    // 004b821f  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b8224  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b8226  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004b8229  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b822a  2eff15e8644c00         -call dword ptr cs:[0x4c64e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006568) /* 0x4c64e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8231  83f802                 +cmp eax, 2
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
    // 004b8234  74d8                   -je 0x4b820e
    if (cpu.flags.zf)
    {
        goto L_0x004b820e;
    }
    // 004b8236  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8238  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b823e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b8240  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8241  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8243  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8244(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8244  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8245  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8246  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8247  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b8249  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b824b  7c08                   -jl 0x4b8255
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b8255;
    }
    // 004b824d  3b05bc064e00           +cmp eax, dword ptr [0x4e06bc]
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
    // 004b8253  7613                   -jbe 0x4b8268
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8268;
    }
L_0x004b8255:
    // 004b8255  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b825a  e851e4feff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004b825f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b8264  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8265  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8266  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8267  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8268:
    // 004b8268  8b15ac064e00           -mov edx, dword ptr [0x4e06ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b826e  8b1482                 -mov edx, dword ptr [edx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004b8271  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8277  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b8279  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b827b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b827d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b827e  2eff1590654c00         -call dword ptr cs:[0x4c6590]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006736) /* 0x4c6590 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8285  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b8287  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8289  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b828f  83faff                 +cmp edx, -1
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
    // 004b8292  7505                   -jne 0x4b8299
    if (!cpu.flags.zf)
    {
        goto L_0x004b8299;
    }
    // 004b8294  e819e3feff             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
L_0x004b8299:
    // 004b8299  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b829b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b829c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b829d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b829e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b829f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b829f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b82a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b82a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b82a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b82a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b82a3  8b15c49d5b00           -mov edx, dword ptr [0x5b9dc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6004164) /* 0x5b9dc4 */);
    // 004b82a9  83fa40                 +cmp edx, 0x40
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b82ac  7d1c                   -jge 0x4b82ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b82ca;
    }
    // 004b82ae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b82b0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b82b3  bbc89d5b00             -mov ebx, 0x5b9dc8
    cpu.ebx = 6004168 /*0x5b9dc8*/;
    // 004b82b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b82ba  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b82bd  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b82c0  890dc49d5b00           -mov dword ptr [0x5b9dc4], ecx
    app->getMemory<x86::reg32>(x86::reg32(6004164) /* 0x5b9dc4 */) = cpu.ecx;
    // 004b82c6  01c3                   +add ebx, eax
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
    // 004b82c8  eb24                   -jmp 0x4b82ee
    goto L_0x004b82ee;
L_0x004b82ca:
    // 004b82ca  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004b82cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b82d4  e82b6c0000             -call 0x4bef04
    cpu.esp -= 4;
    sub_4bef04(app, cpu);
    if (cpu.terminate) return;
    // 004b82d9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b82db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b82dd  750f                   -jne 0x4b82ee
    if (!cpu.flags.zf)
    {
        goto L_0x004b82ee;
    }
    // 004b82df  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b82e4  b898184d00             -mov eax, 0x4d1898
    cpu.eax = 5052568 /*0x4d1898*/;
    // 004b82e9  e813350000             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
L_0x004b82ee:
    // 004b82ee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b82f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b82f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b82f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b82f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b82f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b82f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b82f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b82f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b82f7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b82f9  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004b82fd  740a                   -je 0x4b8309
    if (cpu.flags.zf)
    {
        goto L_0x004b8309;
    }
    // 004b82ff  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b8301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8302  2eff1570644c00         -call dword ptr cs:[0x4c6470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006448) /* 0x4c6470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b8309:
    // 004b8309  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b8310  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b8317  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004b831e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b831f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8320  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8321  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8322(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8322  b8649c5b00             -mov eax, 0x5b9c64
    cpu.eax = 6003812 /*0x5b9c64*/;
    // 004b8327  e97d000000             -jmp 0x4b83a9
    return sub_4b83a9(app, cpu);
}

/* align: skip  */
void Application::sub_4b832c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b832c  b8649c5b00             -mov eax, 0x5b9c64
    cpu.eax = 6003812 /*0x5b9c64*/;
    // 004b8331  e9d9000000             -jmp 0x4b840f
    return sub_4b840f(app, cpu);
}

/* align: skip  */
void Application::sub_4b8336(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8336  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b8339  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b833c  05849c5b00             +add eax, 0x5b9c84
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6003844 /*0x5b9c84*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b8341  eb66                   -jmp 0x4b83a9
    return sub_4b83a9(app, cpu);
}

/* align: skip  */
void Application::sub_4b8343(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8343  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b8346  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b8349  05849c5b00             +add eax, 0x5b9c84
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6003844 /*0x5b9c84*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b834e  e9bc000000             -jmp 0x4b840f
    return sub_4b840f(app, cpu);
}

/* align: skip  */
void Application::sub_4b8353(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8353  e99dfbffff             -jmp 0x4b7ef5
    return sub_4b7ef5(app, cpu);
}

/* align: skip  */
void Application::sub_4b8358(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8358  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8359  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b835b  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b835e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b8361  05849c5b00             -add eax, 0x5b9c84
    (cpu.eax) += x86::reg32(x86::sreg32(6003844 /*0x5b9c84*/));
    // 004b8366  e889ffffff             -call 0x4b82f4
    cpu.esp -= 4;
    sub_4b82f4(app, cpu);
    if (cpu.terminate) return;
    // 004b836b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b836d  e8a1fcffff             -call 0x4b8013
    cpu.esp -= 4;
    sub_4b8013(app, cpu);
    if (cpu.terminate) return;
    // 004b8372  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8373  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8374(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8374  b8849d5b00             -mov eax, 0x5b9d84
    cpu.eax = 6004100 /*0x5b9d84*/;
    // 004b8379  eb2e                   -jmp 0x4b83a9
    return sub_4b83a9(app, cpu);
}

/* align: skip  */
void Application::sub_4b837b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b837b  b8849d5b00             -mov eax, 0x5b9d84
    cpu.eax = 6004100 /*0x5b9d84*/;
    // 004b8380  e98a000000             -jmp 0x4b840f
    return sub_4b840f(app, cpu);
}

/* align: skip  */
void Application::sub_4b8385(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8385  b8749c5b00             -mov eax, 0x5b9c74
    cpu.eax = 6003828 /*0x5b9c74*/;
    // 004b838a  eb1d                   -jmp 0x4b83a9
    return sub_4b83a9(app, cpu);
}

/* align: skip  */
void Application::sub_4b838c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b838c  b8749c5b00             -mov eax, 0x5b9c74
    cpu.eax = 6003828 /*0x5b9c74*/;
    // 004b8391  e979000000             -jmp 0x4b840f
    return sub_4b840f(app, cpu);
}

/* align: skip  */
void Application::sub_4b8396(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8396  b8a49d5b00             -mov eax, 0x5b9da4
    cpu.eax = 6004132 /*0x5b9da4*/;
    // 004b839b  eb0c                   -jmp 0x4b83a9
    return sub_4b83a9(app, cpu);
}

/* align: skip  */
void Application::sub_4b839d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b839d  b8a49d5b00             -mov eax, 0x5b9da4
    cpu.eax = 6004132 /*0x5b9da4*/;
    // 004b83a2  eb6b                   -jmp 0x4b840f
    return sub_4b840f(app, cpu);
}

/* align: skip  */
void Application::sub_4b83a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b83a4  b8b49d5b00             -mov eax, 0x5b9db4
    cpu.eax = 6004148 /*0x5b9db4*/;
    // 004b83a9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b83aa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b83ab  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b83ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b83ad  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b83af  2eff15cc644c00         -call dword ptr cs:[0x4c64cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006540) /* 0x4c64cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b83b6  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b83b9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b83bb  39d0                   +cmp eax, edx
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
    // 004b83bd  7443                   -je 0x4b8402
    if (cpu.flags.zf)
    {
        goto L_0x004b8402;
    }
    // 004b83bf  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 004b83c3  7530                   -jne 0x4b83f5
    if (!cpu.flags.zf)
    {
        goto L_0x004b83f5;
    }
    // 004b83c5  b8949d5b00             -mov eax, 0x5b9d94
    cpu.eax = 6004116 /*0x5b9d94*/;
    // 004b83ca  e8daffffff             -call 0x4b83a9
    cpu.esp -= 4;
    sub_4b83a9(app, cpu);
    if (cpu.terminate) return;
    // 004b83cf  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 004b83d3  7516                   -jne 0x4b83eb
    if (!cpu.flags.zf)
    {
        goto L_0x004b83eb;
    }
    // 004b83d5  e8c6feffff             -call 0x4b82a0
    cpu.esp -= 4;
    sub_4b82a0(app, cpu);
    if (cpu.terminate) return;
    // 004b83da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b83db  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b83dd  2eff153c654c00         -call dword ptr cs:[0x4c653c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006652) /* 0x4c653c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b83e4  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x004b83eb:
    // 004b83eb  b8949d5b00             -mov eax, 0x5b9d94
    cpu.eax = 6004116 /*0x5b9d94*/;
    // 004b83f0  e81a000000             -call 0x4b840f
    cpu.esp -= 4;
    sub_4b840f(app, cpu);
    if (cpu.terminate) return;
L_0x004b83f5:
    // 004b83f5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b83f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b83f8  2eff157c644c00         -call dword ptr cs:[0x4c647c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006460) /* 0x4c647c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b83ff  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004b8402:
    // 004b8402  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 004b8405  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8406  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8407  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8408  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8409  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b83a9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b83a9;
    // 004b83a4  b8b49d5b00             -mov eax, 0x5b9db4
    cpu.eax = 6004148 /*0x5b9db4*/;
L_entry_0x004b83a9:
    // 004b83a9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b83aa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b83ab  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b83ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b83ad  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b83af  2eff15cc644c00         -call dword ptr cs:[0x4c64cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006540) /* 0x4c64cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b83b6  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b83b9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b83bb  39d0                   +cmp eax, edx
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
    // 004b83bd  7443                   -je 0x4b8402
    if (cpu.flags.zf)
    {
        goto L_0x004b8402;
    }
    // 004b83bf  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 004b83c3  7530                   -jne 0x4b83f5
    if (!cpu.flags.zf)
    {
        goto L_0x004b83f5;
    }
    // 004b83c5  b8949d5b00             -mov eax, 0x5b9d94
    cpu.eax = 6004116 /*0x5b9d94*/;
    // 004b83ca  e8daffffff             -call 0x4b83a9
    cpu.esp -= 4;
    sub_4b83a9(app, cpu);
    if (cpu.terminate) return;
    // 004b83cf  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 004b83d3  7516                   -jne 0x4b83eb
    if (!cpu.flags.zf)
    {
        goto L_0x004b83eb;
    }
    // 004b83d5  e8c6feffff             -call 0x4b82a0
    cpu.esp -= 4;
    sub_4b82a0(app, cpu);
    if (cpu.terminate) return;
    // 004b83da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b83db  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b83dd  2eff153c654c00         -call dword ptr cs:[0x4c653c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006652) /* 0x4c653c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b83e4  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x004b83eb:
    // 004b83eb  b8949d5b00             -mov eax, 0x5b9d94
    cpu.eax = 6004116 /*0x5b9d94*/;
    // 004b83f0  e81a000000             -call 0x4b840f
    cpu.esp -= 4;
    sub_4b840f(app, cpu);
    if (cpu.terminate) return;
L_0x004b83f5:
    // 004b83f5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b83f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b83f8  2eff157c644c00         -call dword ptr cs:[0x4c647c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006460) /* 0x4c647c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b83ff  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004b8402:
    // 004b8402  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 004b8405  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8406  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8407  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8408  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8409  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b840a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b840a  b8b49d5b00             -mov eax, 0x5b9db4
    cpu.eax = 6004148 /*0x5b9db4*/;
    // 004b840f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8410  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8411  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8412  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8413  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b8416  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b8418  7617                   -jbe 0x4b8431
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8431;
    }
    // 004b841a  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b841d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b8420  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b8422  750d                   -jne 0x4b8431
    if (!cpu.flags.zf)
    {
        goto L_0x004b8431;
    }
    // 004b8424  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b8426  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8427  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b842a  2eff1540654c00         -call dword ptr cs:[0x4c6540]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006656) /* 0x4c6540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b8431:
    // 004b8431  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8432  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8433  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8434  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8435  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b840f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b840f;
    // 004b840a  b8b49d5b00             -mov eax, 0x5b9db4
    cpu.eax = 6004148 /*0x5b9db4*/;
L_entry_0x004b840f:
    // 004b840f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8410  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8411  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8412  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8413  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b8416  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b8418  7617                   -jbe 0x4b8431
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8431;
    }
    // 004b841a  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b841d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b8420  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b8422  750d                   -jne 0x4b8431
    if (!cpu.flags.zf)
    {
        goto L_0x004b8431;
    }
    // 004b8424  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b8426  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8427  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b842a  2eff1540654c00         -call dword ptr cs:[0x4c6540]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006656) /* 0x4c6540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b8431:
    // 004b8431  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8432  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8433  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8434  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8435  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8436(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8436  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8437  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8438  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8439  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b843a  2eff15f0644c00         -call dword ptr cs:[0x4c64f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006576) /* 0x4c64f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8441  8b1554ed4d00           -mov edx, dword ptr [0x4ded54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b8447  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8448  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b844a  2eff15b4654c00         -call dword ptr cs:[0x4c65b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006772) /* 0x4c65b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8451  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b8453  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8455  7507                   -jne 0x4b845e
    if (!cpu.flags.zf)
    {
        goto L_0x004b845e;
    }
    // 004b8457  e8c06a0000             -call 0x4bef1c
    cpu.esp -= 4;
    sub_4bef1c(app, cpu);
    if (cpu.terminate) return;
    // 004b845c  eb0b                   -jmp 0x4b8469
    goto L_0x004b8469;
L_0x004b845e:
    // 004b845e  80785300               +cmp byte ptr [eax + 0x53], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(83) /* 0x53 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b8462  7407                   -je 0x4b846b
    if (cpu.flags.zf)
    {
        goto L_0x004b846b;
    }
    // 004b8464  e8ec6a0000             -call 0x4bef55
    cpu.esp -= 4;
    sub_4bef55(app, cpu);
    if (cpu.terminate) return;
L_0x004b8469:
    // 004b8469  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004b846b:
    // 004b846b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b846c  2eff1594654c00         -call dword ptr cs:[0x4c6594]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006740) /* 0x4c6594 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8473  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8475  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8476  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8477  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8478  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8479  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b847a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b847a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b847b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b847c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b847e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8480  7526                   -jne 0x4b84a8
    if (!cpu.flags.zf)
    {
        goto L_0x004b84a8;
    }
    // 004b8482  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b8487  8b1550094e00           -mov edx, dword ptr [0x4e0950]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004b848d  e8726a0000             -call 0x4bef04
    cpu.esp -= 4;
    sub_4bef04(app, cpu);
    if (cpu.terminate) return;
    // 004b8492  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b8494  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8496  7410                   -je 0x4b84a8
    if (cpu.flags.zf)
    {
        goto L_0x004b84a8;
    }
    // 004b8498  8b1d50094e00           -mov ebx, dword ptr [0x4e0950]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004b849e  c6405201               -mov byte ptr [eax + 0x52], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 004b84a2  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x004b84a8:
    // 004b84a8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b84aa  e8716c0000             -call 0x4bf120
    cpu.esp -= 4;
    sub_4bf120(app, cpu);
    if (cpu.terminate) return;
    // 004b84af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b84b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b84b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b84b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b84b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b84b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b84b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b84b6  2eff15ac654c00         -call dword ptr cs:[0x4c65ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006764) /* 0x4c65ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b84bd  668b150ddb4d00         -mov dx, word ptr [0x4ddb0d]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5102349) /* 0x4ddb0d */);
    // 004b84c4  a354ed4d00             -mov dword ptr [0x4ded54], eax
    app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */) = cpu.eax;
    // 004b84c9  6681fa0080             +cmp dx, 0x8000
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b84ce  7227                   -jb 0x4b84f7
    if (cpu.flags.cf)
    {
        goto L_0x004b84f7;
    }
    // 004b84d0  803d0bdb4d0004         +cmp byte ptr [0x4ddb0b], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102347) /* 0x4ddb0b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b84d7  731e                   -jae 0x4b84f7
    if (!cpu.flags.cf)
    {
        goto L_0x004b84f7;
    }
L_0x004b84d9:
    // 004b84d9  8b1554ed4d00           -mov edx, dword ptr [0x4ded54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b84df  83faff                 +cmp edx, -1
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
    // 004b84e2  7413                   -je 0x4b84f7
    if (cpu.flags.zf)
    {
        goto L_0x004b84f7;
    }
    // 004b84e4  83fa02                 +cmp edx, 2
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
    // 004b84e7  770e                   -ja 0x4b84f7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b84f7;
    }
    // 004b84e9  2eff15ac654c00         -call dword ptr cs:[0x4c65ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006764) /* 0x4c65ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b84f0  a354ed4d00             -mov dword ptr [0x4ded54], eax
    app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */) = cpu.eax;
    // 004b84f5  ebe2                   -jmp 0x4b84d9
    goto L_0x004b84d9;
L_0x004b84f7:
    // 004b84f7  833d54ed4d00ff         +cmp dword ptr [0x4ded54], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b84fe  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004b8501  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b8506  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8507  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8508  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8509(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8509  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b850a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b850b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b850c  833d54ed4d00ff         +cmp dword ptr [0x4ded54], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8513  7506                   -jne 0x4b851b
    if (!cpu.flags.zf)
    {
        goto L_0x004b851b;
    }
L_0x004b8515:
    // 004b8515  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b8517  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8518  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8519  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b851a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b851b:
    // 004b851b  e85affffff             -call 0x4b847a
    cpu.esp -= 4;
    sub_4b847a(app, cpu);
    if (cpu.terminate) return;
    // 004b8520  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b8522  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8524  742e                   -je 0x4b8554
    if (cpu.flags.zf)
    {
        goto L_0x004b8554;
    }
    // 004b8526  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b8528  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004b852e  e8f66a0000             -call 0x4bf029
    cpu.esp -= 4;
    sub_4bf029(app, cpu);
    if (cpu.terminate) return;
    // 004b8533  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8535  7509                   -jne 0x4b8540
    if (!cpu.flags.zf)
    {
        goto L_0x004b8540;
    }
    // 004b8537  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8539  e8ba2fffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004b853e  ebd5                   -jmp 0x4b8515
    goto L_0x004b8515;
L_0x004b8540:
    // 004b8540  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8541  8b1d54ed4d00           -mov ebx, dword ptr [0x4ded54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b8547  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8548  2eff15b8654c00         -call dword ptr cs:[0x4c65b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006776) /* 0x4c65b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b854f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b8554:
    // 004b8554  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8555  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8556  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8557  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8558(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8558  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8559  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b855a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b855b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b855c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b855d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b855f  8b1554ed4d00           -mov edx, dword ptr [0x4ded54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b8565  83faff                 +cmp edx, -1
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
    // 004b8568  743d                   -je 0x4b85a7
    if (cpu.flags.zf)
    {
        goto L_0x004b85a7;
    }
    // 004b856a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b856b  2eff15b4654c00         -call dword ptr cs:[0x4c65b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006772) /* 0x4c65b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8572  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8574  7431                   -je 0x4b85a7
    if (cpu.flags.zf)
    {
        goto L_0x004b85a7;
    }
    // 004b8576  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 004b857c  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004b8582  e8036b0000             -call 0x4bf08a
    cpu.esp -= 4;
    sub_4bf08a(app, cpu);
    if (cpu.terminate) return;
    // 004b8587  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b8589  8b3d54ed4d00           -mov edi, dword ptr [0x4ded54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b858f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b8590  2eff15b8654c00         -call dword ptr cs:[0x4c65b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006776) /* 0x4c65b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8597  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b8599  740c                   -je 0x4b85a7
    if (cpu.flags.zf)
    {
        goto L_0x004b85a7;
    }
    // 004b859b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b859d  7408                   -je 0x4b85a7
    if (cpu.flags.zf)
    {
        goto L_0x004b85a7;
    }
    // 004b859f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b85a0  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b85a7:
    // 004b85a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b85a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b85a7;
    // 004b8558  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8559  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b855a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b855b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b855c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b855d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b855f  8b1554ed4d00           -mov edx, dword ptr [0x4ded54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b8565  83faff                 +cmp edx, -1
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
    // 004b8568  743d                   -je 0x4b85a7
    if (cpu.flags.zf)
    {
        goto L_0x004b85a7;
    }
    // 004b856a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b856b  2eff15b4654c00         -call dword ptr cs:[0x4c65b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006772) /* 0x4c65b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8572  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8574  7431                   -je 0x4b85a7
    if (cpu.flags.zf)
    {
        goto L_0x004b85a7;
    }
    // 004b8576  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 004b857c  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004b8582  e8036b0000             -call 0x4bf08a
    cpu.esp -= 4;
    sub_4bf08a(app, cpu);
    if (cpu.terminate) return;
    // 004b8587  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b8589  8b3d54ed4d00           -mov edi, dword ptr [0x4ded54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b858f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b8590  2eff15b8654c00         -call dword ptr cs:[0x4c65b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006776) /* 0x4c65b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8597  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b8599  740c                   -je 0x4b85a7
    if (cpu.flags.zf)
    {
        goto L_0x004b85a7;
    }
    // 004b859b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b859d  7408                   -je 0x4b85a7
    if (cpu.flags.zf)
    {
        goto L_0x004b85a7;
    }
    // 004b859f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b85a0  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b85a7:
L_entry_0x004b85a7:
    // 004b85a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b85ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b85ad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b85b2  e8a1ffffff             -call 0x4b8558
    cpu.esp -= 4;
    sub_4b8558(app, cpu);
    if (cpu.terminate) return;
    // 004b85b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b85b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b85b9  8b1554ed4d00           -mov edx, dword ptr [0x4ded54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b85bf  83faff                 +cmp edx, -1
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
    // 004b85c2  7412                   -je 0x4b85d6
    if (cpu.flags.zf)
    {
        goto L_0x004b85d6;
    }
    // 004b85c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b85c5  2eff15b0654c00         -call dword ptr cs:[0x4c65b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006768) /* 0x4c65b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b85cc  c70554ed4d00ffffffff   -mov dword ptr [0x4ded54], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */) = 4294967295 /*0xffffffff*/;
L_0x004b85d6:
    // 004b85d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b85b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b85b7;
    // 004b85ad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b85b2  e8a1ffffff             -call 0x4b8558
    cpu.esp -= 4;
    sub_4b8558(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004b85b7:
    // 004b85b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b85b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b85b9  8b1554ed4d00           -mov edx, dword ptr [0x4ded54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b85bf  83faff                 +cmp edx, -1
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
    // 004b85c2  7412                   -je 0x4b85d6
    if (cpu.flags.zf)
    {
        goto L_0x004b85d6;
    }
    // 004b85c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b85c5  2eff15b0654c00         -call dword ptr cs:[0x4c65b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006768) /* 0x4c65b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b85cc  c70554ed4d00ffffffff   -mov dword ptr [0x4ded54], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */) = 4294967295 /*0xffffffff*/;
L_0x004b85d6:
    // 004b85d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b85d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b85d9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b85d9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b85da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b85db  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b85dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b85dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b85de  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b85df  ba36834b00             -mov edx, 0x4b8336
    cpu.edx = 4948790 /*0x4b8336*/;
    // 004b85e4  bb43834b00             -mov ebx, 0x4b8343
    cpu.ebx = 4948803 /*0x4b8343*/;
    // 004b85e9  b953834b00             -mov ecx, 0x4b8353
    cpu.ecx = 4948819 /*0x4b8353*/;
    // 004b85ee  be58834b00             -mov esi, 0x4b8358
    cpu.esi = 4948824 /*0x4b8358*/;
    // 004b85f3  bf22834b00             -mov edi, 0x4b8322
    cpu.edi = 4948770 /*0x4b8322*/;
    // 004b85f8  bd2c834b00             -mov ebp, 0x4b832c
    cpu.ebp = 4948780 /*0x4b832c*/;
    // 004b85fd  b896834b00             -mov eax, 0x4b8396
    cpu.eax = 4948886 /*0x4b8396*/;
    // 004b8602  89155ced4d00           -mov dword ptr [0x4ded5c], edx
    app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */) = cpu.edx;
    // 004b8608  891d60ed4d00           -mov dword ptr [0x4ded60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */) = cpu.ebx;
    // 004b860e  890d64ed4d00           -mov dword ptr [0x4ded64], ecx
    app->getMemory<x86::reg32>(x86::reg32(5107044) /* 0x4ded64 */) = cpu.ecx;
    // 004b8614  893568ed4d00           -mov dword ptr [0x4ded68], esi
    app->getMemory<x86::reg32>(x86::reg32(5107048) /* 0x4ded68 */) = cpu.esi;
    // 004b861a  893d6ced4d00           -mov dword ptr [0x4ded6c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107052) /* 0x4ded6c */) = cpu.edi;
    // 004b8620  892d70ed4d00           -mov dword ptr [0x4ded70], ebp
    app->getMemory<x86::reg32>(x86::reg32(5107056) /* 0x4ded70 */) = cpu.ebp;
    // 004b8626  a384ed4d00             -mov dword ptr [0x4ded84], eax
    app->getMemory<x86::reg32>(x86::reg32(5107076) /* 0x4ded84 */) = cpu.eax;
    // 004b862b  ba9d834b00             -mov edx, 0x4b839d
    cpu.edx = 4948893 /*0x4b839d*/;
    // 004b8630  bba9834b00             -mov ebx, 0x4b83a9
    cpu.ebx = 4948905 /*0x4b83a9*/;
    // 004b8635  b90f844b00             -mov ecx, 0x4b840f
    cpu.ecx = 4949007 /*0x4b840f*/;
    // 004b863a  bef4824b00             -mov esi, 0x4b82f4
    cpu.esi = 4948724 /*0x4b82f4*/;
    // 004b863f  bf74834b00             -mov edi, 0x4b8374
    cpu.edi = 4948852 /*0x4b8374*/;
    // 004b8644  bd85834b00             -mov ebp, 0x4b8385
    cpu.ebp = 4948869 /*0x4b8385*/;
    // 004b8649  b87b834b00             -mov eax, 0x4b837b
    cpu.eax = 4948859 /*0x4b837b*/;
    // 004b864e  891588ed4d00           -mov dword ptr [0x4ded88], edx
    app->getMemory<x86::reg32>(x86::reg32(5107080) /* 0x4ded88 */) = cpu.edx;
    // 004b8654  891d14074e00           -mov dword ptr [0x4e0714], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113620) /* 0x4e0714 */) = cpu.ebx;
    // 004b865a  890d18074e00           -mov dword ptr [0x4e0718], ecx
    app->getMemory<x86::reg32>(x86::reg32(5113624) /* 0x4e0718 */) = cpu.ecx;
    // 004b8660  89351c074e00           -mov dword ptr [0x4e071c], esi
    app->getMemory<x86::reg32>(x86::reg32(5113628) /* 0x4e071c */) = cpu.esi;
    // 004b8666  893d74ed4d00           -mov dword ptr [0x4ded74], edi
    app->getMemory<x86::reg32>(x86::reg32(5107060) /* 0x4ded74 */) = cpu.edi;
    // 004b866c  892d78ed4d00           -mov dword ptr [0x4ded78], ebp
    app->getMemory<x86::reg32>(x86::reg32(5107064) /* 0x4ded78 */) = cpu.ebp;
    // 004b8672  a37ced4d00             -mov dword ptr [0x4ded7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107068) /* 0x4ded7c */) = cpu.eax;
    // 004b8677  ba8c834b00             -mov edx, 0x4b838c
    cpu.edx = 4948876 /*0x4b838c*/;
    // 004b867c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b8681  be0a844b00             -mov esi, 0x4b840a
    cpu.esi = 4949002 /*0x4b840a*/;
    // 004b8686  891580ed4d00           -mov dword ptr [0x4ded80], edx
    app->getMemory<x86::reg32>(x86::reg32(5107072) /* 0x4ded80 */) = cpu.edx;
    // 004b868c  e80ffcffff             -call 0x4b82a0
    cpu.esp -= 4;
    sub_4b82a0(app, cpu);
    if (cpu.terminate) return;
    // 004b8691  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8692  bfad854b00             -mov edi, 0x4b85ad
    cpu.edi = 4949421 /*0x4b85ad*/;
    // 004b8697  a3949d5b00             -mov dword ptr [0x5b9d94], eax
    app->getMemory<x86::reg32>(x86::reg32(6004116) /* 0x5b9d94 */) = cpu.eax;
    // 004b869c  2eff153c654c00         -call dword ptr cs:[0x4c653c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006652) /* 0x4c653c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b86a3  b9a4834b00             -mov ecx, 0x4b83a4
    cpu.ecx = 4948900 /*0x4b83a4*/;
    // 004b86a8  8b15b0675b00           -mov edx, dword ptr [0x5b67b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5990320) /* 0x5b67b0 */);
    // 004b86ae  891d989d5b00           -mov dword ptr [0x5b9d98], ebx
    app->getMemory<x86::reg32>(x86::reg32(6004120) /* 0x5b9d98 */) = cpu.ebx;
    // 004b86b4  893590ed4d00           -mov dword ptr [0x4ded90], esi
    app->getMemory<x86::reg32>(x86::reg32(5107088) /* 0x4ded90 */) = cpu.esi;
    // 004b86ba  893d94ed4d00           -mov dword ptr [0x4ded94], edi
    app->getMemory<x86::reg32>(x86::reg32(5107092) /* 0x4ded94 */) = cpu.edi;
    // 004b86c0  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 004b86c6  890d8ced4d00           -mov dword ptr [0x4ded8c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5107084) /* 0x4ded8c */) = cpu.ecx;
    // 004b86cc  e858690000             -call 0x4bf029
    cpu.esp -= 4;
    sub_4bf029(app, cpu);
    if (cpu.terminate) return;
    // 004b86d1  8b2db0675b00           -mov ebp, dword ptr [0x5b67b0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5990320) /* 0x5b67b0 */);
    // 004b86d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b86d8  a154ed4d00             -mov eax, dword ptr [0x4ded54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004b86dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b86de  2eff15b8654c00         -call dword ptr cs:[0x4c65b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006776) /* 0x4c65b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b86e5  c70558ed4d0036844b00   -mov dword ptr [0x4ded58], 0x4b8436
    app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */) = 4949046 /*0x4b8436*/;
    // 004b86ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b86f0  e9b2feffff             -jmp 0x4b85a7
    return sub_4b85a7(app, cpu);
}

/* align: skip  */
void Application::sub_4b86f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b86f5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b86f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b86f7  b8649c5b00             -mov eax, 0x5b9c64
    cpu.eax = 6003812 /*0x5b9c64*/;
    // 004b86fc  ba849c5b00             -mov edx, 0x5b9c84
    cpu.edx = 6003844 /*0x5b9c84*/;
    // 004b8701  ff151c074e00           -call dword ptr [0x4e071c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113628) /* 0x4e071c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8707  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x004b870d:
    // 004b870d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b870f  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b8712  ff151c074e00           -call dword ptr [0x4e071c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113628) /* 0x4e071c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8718  39da                   +cmp edx, ebx
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
    // 004b871a  75f1                   -jne 0x4b870d
    if (!cpu.flags.zf)
    {
        goto L_0x004b870d;
    }
    // 004b871c  b8b49d5b00             -mov eax, 0x5b9db4
    cpu.eax = 6004148 /*0x5b9db4*/;
    // 004b8721  ff151c074e00           -call dword ptr [0x4e071c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113628) /* 0x4e071c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8727  e81c6a0000             -call 0x4bf148
    cpu.esp -= 4;
    sub_4bf148(app, cpu);
    if (cpu.terminate) return;
    // 004b872c  b8849d5b00             -mov eax, 0x5b9d84
    cpu.eax = 6004100 /*0x5b9d84*/;
    // 004b8731  ff151c074e00           -call dword ptr [0x4e071c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113628) /* 0x4e071c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8737  b8749c5b00             -mov eax, 0x5b9c74
    cpu.eax = 6003828 /*0x5b9c74*/;
    // 004b873c  ff151c074e00           -call dword ptr [0x4e071c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113628) /* 0x4e071c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8742  b8a49d5b00             -mov eax, 0x5b9da4
    cpu.eax = 6004132 /*0x5b9da4*/;
    // 004b8747  ff151c074e00           -call dword ptr [0x4e071c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113628) /* 0x4e071c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b874d  b8949d5b00             -mov eax, 0x5b9d94
    cpu.eax = 6004116 /*0x5b9d94*/;
    // 004b8752  ff151c074e00           -call dword ptr [0x4e071c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113628) /* 0x4e071c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8758  e85afeffff             -call 0x4b85b7
    cpu.esp -= 4;
    sub_4b85b7(app, cpu);
    if (cpu.terminate) return;
    // 004b875d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b875e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b875f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8761  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8762  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8763  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b8764  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b8766  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b8768  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b8769  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b876b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b876d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b876f  49                     -dec ecx
    (cpu.ecx)--;
    // 004b8770  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b8772  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004b8774  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004b8776  49                     -dec ecx
    (cpu.ecx)--;
    // 004b8777  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b8778  41                     -inc ecx
    (cpu.ecx)++;
    // 004b8779  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b877b  e843defeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b8780  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b8782  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8784  7418                   -je 0x4b879e
    if (cpu.flags.zf)
    {
        goto L_0x004b879e;
    }
    // 004b8786  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b8788  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b8789  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b878b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b878d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b878e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b8790  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b8793  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b8795  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b8797  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b879a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b879c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b879d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004b879e:
    // 004b879e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b87a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b87a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b87a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b87a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b87a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b87a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b87a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b87a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b87a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b87a8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b87a9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b87ab  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b87ad  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b87af  2eff152c654c00         -call dword ptr cs:[0x4c652c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006636) /* 0x4c652c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b87b6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b87b9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b87be  663d0080               +cmp ax, 0x8000
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b87c2  730f                   -jae 0x4b87d3
    if (!cpu.flags.cf)
    {
        goto L_0x004b87d3;
    }
    // 004b87c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b87c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b87c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b87c7  2eff1504654c00         -call dword ptr cs:[0x4c6504]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006596) /* 0x4c6504 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b87ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b87cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b87d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b87d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b87d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b87d3:
    // 004b87d3  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 004b87d8  e8e6ddfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b87dd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b87df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b87e1  744d                   -je 0x4b8830
    if (cpu.flags.zf)
    {
        goto L_0x004b8830;
    }
    // 004b87e3  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 004b87e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b87e9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b87ea  2eff1500654c00         -call dword ptr cs:[0x4c6500]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006592) /* 0x4c6500 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b87f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b87f3  750e                   -jne 0x4b8803
    if (!cpu.flags.zf)
    {
        goto L_0x004b8803;
    }
    // 004b87f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b87f7  e8fc2cffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004b87fc:
    // 004b87fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b87fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b87ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8800  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8801  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8802  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8803:
    // 004b8803  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b8804  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8805  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004b8807  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8808  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b880a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b880c  2eff1550654c00         -call dword ptr cs:[0x4c6550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006672) /* 0x4c6550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8813  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b8815  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8817  e8dc2cffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004b881c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b881e  74dc                   -je 0x4b87fc
    if (cpu.flags.zf)
    {
        goto L_0x004b87fc;
    }
    // 004b8820  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b8822  66c74446fe0000         -mov word ptr [esi + eax*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.eax * 2) = 0 /*0x0*/;
    // 004b8829  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b882b  e884270000             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
L_0x004b8830:
    // 004b8830  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8831  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8832  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8833  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8834  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8835(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8835  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8836  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8837  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8838  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b883a  e875270000             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004b883f  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b8842  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b8844  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8846  e878ddfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b884b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b884d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b884f  7405                   -je 0x4b8856
    if (cpu.flags.zf)
    {
        goto L_0x004b8856;
    }
    // 004b8851  e827280000             -call 0x4bb07d
    cpu.esp -= 4;
    sub_4bb07d(app, cpu);
    if (cpu.terminate) return;
L_0x004b8856:
    // 004b8856  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b8858  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8859  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b885a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b885b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b885c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b885c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b885d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b885e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b885f  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b8862  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b8864  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b8866  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 004b8868  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b886c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b886d  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b8871  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8872  2eff15d0654c00         -call dword ptr cs:[0x4c65d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006800) /* 0x4c65d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8879  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b887c  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b8880  668b0d0ddb4d00         -mov cx, word ptr [0x4ddb0d]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5102349) /* 0x4ddb0d */);
    // 004b8887  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b888b  6681f90080             +cmp cx, 0x8000
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b8890  7307                   -jae 0x4b8899
    if (!cpu.flags.cf)
    {
        goto L_0x004b8899;
    }
    // 004b8892  0500300000             +add eax, 0x3000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12288 /*0x3000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b8897  eb17                   -jmp 0x4b88b0
    goto L_0x004b88b0;
L_0x004b8899:
    // 004b8899  7210                   -jb 0x4b88ab
    if (cpu.flags.cf)
    {
        goto L_0x004b88ab;
    }
    // 004b889b  803d0bdb4d0004         +cmp byte ptr [0x4ddb0b], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102347) /* 0x4ddb0b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b88a2  7307                   -jae 0x4b88ab
    if (!cpu.flags.cf)
    {
        goto L_0x004b88ab;
    }
    // 004b88a4  0500200100             +add eax, 0x12000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(73728 /*0x12000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b88a9  eb05                   -jmp 0x4b88b0
    goto L_0x004b88b0;
L_0x004b88ab:
    // 004b88ab  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x004b88b0:
    // 004b88b0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b88b2  7402                   -je 0x4b88b6
    if (cpu.flags.zf)
    {
        goto L_0x004b88b6;
    }
    // 004b88b4  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004b88b6:
    // 004b88b6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b88b8  7402                   -je 0x4b88bc
    if (cpu.flags.zf)
    {
        goto L_0x004b88bc;
    }
    // 004b88ba  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x004b88bc:
    // 004b88bc  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b88bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b88c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b88c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b88c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b88c3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b88c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b88c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b88c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b88c6  68bc184d00             -push 0x4d18bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5052604 /*0x4d18bc*/;
    cpu.esp -= 4;
    // 004b88cb  2eff1544654c00         -call dword ptr cs:[0x4c6544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006660) /* 0x4c6544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b88d2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b88d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b88d6  7417                   -je 0x4b88ef
    if (cpu.flags.zf)
    {
        goto L_0x004b88ef;
    }
    // 004b88d8  68c7184d00             -push 0x4d18c7
    app->getMemory<x86::reg32>(cpu.esp-4) = 5052615 /*0x4d18c7*/;
    cpu.esp -= 4;
    // 004b88dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b88de  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b88e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b88e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b88e9  7404                   -je 0x4b88ef
    if (cpu.flags.zf)
    {
        goto L_0x004b88ef;
    }
    // 004b88eb  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b88ed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004b88ef:
    // 004b88ef  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b88f1  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004b88f4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b88f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b88fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b88fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b88fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b88fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b88fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b88fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b88ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b8900  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b8902  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b8904:
    // 004b8904  803800                 +cmp byte ptr [eax], 0
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
    // 004b8907  7403                   -je 0x4b890c
    if (cpu.flags.zf)
    {
        goto L_0x004b890c;
    }
    // 004b8909  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b890a  ebf8                   -jmp 0x4b8904
    goto L_0x004b8904;
L_0x004b890c:
    // 004b890c  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x004b890f:
    // 004b890f  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b8911  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004b8913  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b8915  7412                   -je 0x4b8929
    if (cpu.flags.zf)
    {
        goto L_0x004b8929;
    }
    // 004b8917  80f930                 +cmp cl, 0x30
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b891a  7508                   -jne 0x4b8924
    if (!cpu.flags.zf)
    {
        goto L_0x004b8924;
    }
    // 004b891c  807a0178               +cmp byte ptr [edx + 1], 0x78
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b8920  7502                   -jne 0x4b8924
    if (!cpu.flags.zf)
    {
        goto L_0x004b8924;
    }
    // 004b8922  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x004b8924:
    // 004b8924  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b8925  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b8926  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b8927  ebe6                   -jmp 0x4b890f
    goto L_0x004b890f;
L_0x004b8929:
    // 004b8929  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b892b  7419                   -je 0x4b8946
    if (cpu.flags.zf)
    {
        goto L_0x004b8946;
    }
    // 004b892d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004b892f:
    // 004b892f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8931  7413                   -je 0x4b8946
    if (cpu.flags.zf)
    {
        goto L_0x004b8946;
    }
    // 004b8933  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b8935  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b8938  8a9228074e00           -mov dl, byte ptr [edx + 0x4e0728]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113640) /* 0x4e0728 */);
    // 004b893e  c1e804                 +shr eax, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004b8941  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004b8943  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b8944  ebe9                   -jmp 0x4b892f
    goto L_0x004b892f;
L_0x004b8946:
    // 004b8946  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8947  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8948  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8949  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b894a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b894a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b894b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b894c  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004b8952  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004b8959  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b895b  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b895e  e860ffffff             -call 0x4b88c3
    cpu.esp -= 4;
    sub_4b88c3(app, cpu);
    if (cpu.terminate) return;
    // 004b8963  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8965  750a                   -jne 0x4b8971
    if (!cpu.flags.zf)
    {
        goto L_0x004b8971;
    }
    // 004b8967  e87e680000             -call 0x4bf1ea
    cpu.esp -= 4;
    sub_4bf1ea(app, cpu);
    if (cpu.terminate) return;
    // 004b896c  83f8ff                 +cmp eax, -1
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
    // 004b896f  7507                   -jne 0x4b8978
    if (!cpu.flags.zf)
    {
        goto L_0x004b8978;
    }
L_0x004b8971:
    // 004b8971  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b8973  e97e010000             -jmp 0x4b8af6
    goto L_0x004b8af6;
L_0x004b8978:
    // 004b8978  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004b897a  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004b897d  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004b897f  3d900000c0             +cmp eax, 0xc0000090
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225616 /*0xc0000090*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8984  724d                   -jb 0x4b89d3
    if (cpu.flags.cf)
    {
        goto L_0x004b89d3;
    }
    // 004b8986  0f86b5000000           -jbe 0x4b8a41
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8a41;
    }
    // 004b898c  3d930000c0             +cmp eax, 0xc0000093
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225619 /*0xc0000093*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8991  7233                   -jb 0x4b89c6
    if (cpu.flags.cf)
    {
        goto L_0x004b89c6;
    }
    // 004b8993  0f86a1000000           -jbe 0x4b8a3a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8a3a;
    }
    // 004b8999  3d960000c0             +cmp eax, 0xc0000096
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225622 /*0xc0000096*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b899e  7216                   -jb 0x4b89b6
    if (cpu.flags.cf)
    {
        goto L_0x004b89b6;
    }
    // 004b89a0  0f86d8000000           -jbe 0x4b8a7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8a7e;
    }
    // 004b89a6  3dfd0000c0             +cmp eax, 0xc00000fd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225725 /*0xc00000fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b89ab  0f84e5000000           -je 0x4b8a96
    if (cpu.flags.zf)
    {
        goto L_0x004b8a96;
    }
    // 004b89b1  e9ea000000             -jmp 0x4b8aa0
    goto L_0x004b8aa0;
L_0x004b89b6:
    // 004b89b6  3d940000c0             +cmp eax, 0xc0000094
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225620 /*0xc0000094*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b89bb  0f84cb000000           -je 0x4b8a8c
    if (cpu.flags.zf)
    {
        goto L_0x004b8a8c;
    }
    // 004b89c1  e9da000000             -jmp 0x4b8aa0
    goto L_0x004b8aa0;
L_0x004b89c6:
    // 004b89c6  3d910000c0             +cmp eax, 0xc0000091
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225617 /*0xc0000091*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b89cb  0f8662000000           -jbe 0x4b8a33
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8a33;
    }
    // 004b89d1  eb2f                   -jmp 0x4b8a02
    goto L_0x004b8a02;
L_0x004b89d3:
    // 004b89d3  3d8d0000c0             +cmp eax, 0xc000008d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225613 /*0xc000008d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b89d8  720b                   -jb 0x4b89e5
    if (cpu.flags.cf)
    {
        goto L_0x004b89e5;
    }
    // 004b89da  7642                   -jbe 0x4b8a1e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8a1e;
    }
    // 004b89dc  3d8e0000c0             +cmp eax, 0xc000008e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225614 /*0xc000008e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b89e1  7642                   -jbe 0x4b8a25
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8a25;
    }
    // 004b89e3  eb47                   -jmp 0x4b8a2c
    goto L_0x004b8a2c;
L_0x004b89e5:
    // 004b89e5  3d050000c0             +cmp eax, 0xc0000005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225477 /*0xc0000005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b89ea  0f82b0000000           -jb 0x4b8aa0
    if (cpu.flags.cf)
    {
        goto L_0x004b8aa0;
    }
    // 004b89f0  7656                   -jbe 0x4b8a48
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8a48;
    }
    // 004b89f2  3d1d0000c0             +cmp eax, 0xc000001d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225501 /*0xc000001d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b89f7  0f8488000000           -je 0x4b8a85
    if (cpu.flags.zf)
    {
        goto L_0x004b8a85;
    }
    // 004b89fd  e99e000000             -jmp 0x4b8aa0
    goto L_0x004b8aa0;
L_0x004b8a02:
    // 004b8a02  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 004b8a06  740f                   -je 0x4b8a17
    if (cpu.flags.zf)
    {
        goto L_0x004b8a17;
    }
    // 004b8a08  bad7184d00             -mov edx, 0x4d18d7
    cpu.edx = 5052631 /*0x4d18d7*/;
L_0x004b8a0d:
    // 004b8a0d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b8a0f  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b8a12  e9a1000000             -jmp 0x4b8ab8
    goto L_0x004b8ab8;
L_0x004b8a17:
    // 004b8a17  ba28194d00             -mov edx, 0x4d1928
    cpu.edx = 5052712 /*0x4d1928*/;
    // 004b8a1c  ebef                   -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a1e:
    // 004b8a1e  ba7a194d00             -mov edx, 0x4d197a
    cpu.edx = 5052794 /*0x4d197a*/;
    // 004b8a23  ebe8                   -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a25:
    // 004b8a25  bacd194d00             -mov edx, 0x4d19cd
    cpu.edx = 5052877 /*0x4d19cd*/;
    // 004b8a2a  ebe1                   -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a2c:
    // 004b8a2c  ba201a4d00             -mov edx, 0x4d1a20
    cpu.edx = 5052960 /*0x4d1a20*/;
    // 004b8a31  ebda                   -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a33:
    // 004b8a33  ba711a4d00             -mov edx, 0x4d1a71
    cpu.edx = 5053041 /*0x4d1a71*/;
    // 004b8a38  ebd3                   -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a3a:
    // 004b8a3a  babd1a4d00             -mov edx, 0x4d1abd
    cpu.edx = 5053117 /*0x4d1abd*/;
    // 004b8a3f  ebcc                   -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a41:
    // 004b8a41  ba0a1b4d00             -mov edx, 0x4d1b0a
    cpu.edx = 5053194 /*0x4d1b0a*/;
    // 004b8a46  ebc5                   -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a48:
    // 004b8a48  ba5f1b4d00             -mov edx, 0x4d1b5f
    cpu.edx = 5053279 /*0x4d1b5f*/;
    // 004b8a4d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b8a4f  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b8a52  e8a6feffff             -call 0x4b88fd
    cpu.esp -= 4;
    sub_4b88fd(app, cpu);
    if (cpu.terminate) return;
    // 004b8a57  ba901b4d00             -mov edx, 0x4d1b90
    cpu.edx = 5053328 /*0x4d1b90*/;
    // 004b8a5c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b8a5e  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b8a61  e897feffff             -call 0x4b88fd
    cpu.esp -= 4;
    sub_4b88fd(app, cpu);
    if (cpu.terminate) return;
    // 004b8a66  83791400               +cmp dword ptr [ecx + 0x14], 0
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
    // 004b8a6a  750b                   -jne 0x4b8a77
    if (!cpu.flags.zf)
    {
        goto L_0x004b8a77;
    }
    // 004b8a6c  bab81b4d00             -mov edx, 0x4d1bb8
    cpu.edx = 5053368 /*0x4d1bb8*/;
L_0x004b8a71:
    // 004b8a71  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b8a73  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b8a75  eb41                   -jmp 0x4b8ab8
    goto L_0x004b8ab8;
L_0x004b8a77:
    // 004b8a77  babf1b4d00             -mov edx, 0x4d1bbf
    cpu.edx = 5053375 /*0x4d1bbf*/;
    // 004b8a7c  ebf3                   -jmp 0x4b8a71
    goto L_0x004b8a71;
L_0x004b8a7e:
    // 004b8a7e  bac91b4d00             -mov edx, 0x4d1bc9
    cpu.edx = 5053385 /*0x4d1bc9*/;
    // 004b8a83  eb88                   -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a85:
    // 004b8a85  ba071c4d00             -mov edx, 0x4d1c07
    cpu.edx = 5053447 /*0x4d1c07*/;
    // 004b8a8a  eb81                   -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a8c:
    // 004b8a8c  ba431c4d00             -mov edx, 0x4d1c43
    cpu.edx = 5053507 /*0x4d1c43*/;
    // 004b8a91  e977ffffff             -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8a96:
    // 004b8a96  ba851c4d00             -mov edx, 0x4d1c85
    cpu.edx = 5053573 /*0x4d1c85*/;
    // 004b8a9b  e96dffffff             -jmp 0x4b8a0d
    goto L_0x004b8a0d;
L_0x004b8aa0:
    // 004b8aa0  babe1c4d00             -mov edx, 0x4d1cbe
    cpu.edx = 5053630 /*0x4d1cbe*/;
    // 004b8aa5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b8aa7  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004b8aa9  e84ffeffff             -call 0x4b88fd
    cpu.esp -= 4;
    sub_4b88fd(app, cpu);
    if (cpu.terminate) return;
    // 004b8aae  baef1c4d00             -mov edx, 0x4d1cef
    cpu.edx = 5053679 /*0x4d1cef*/;
    // 004b8ab3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b8ab5  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x004b8ab8:
    // 004b8ab8  e840feffff             -call 0x4b88fd
    cpu.esp -= 4;
    sub_4b88fd(app, cpu);
    if (cpu.terminate) return;
    // 004b8abd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b8abf  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004b8ac6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8ac7  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b8acb  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b8acc  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b8ace  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b8ad0  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b8ad2  49                     -dec ecx
    (cpu.ecx)--;
    // 004b8ad3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b8ad5  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004b8ad7  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004b8ad9  49                     -dec ecx
    (cpu.ecx)--;
    // 004b8ada  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b8adb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8adc  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b8ae0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8ae1  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b8ae6  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b8ae9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8aea  2eff15e4654c00         -call dword ptr cs:[0x4c65e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006820) /* 0x4c65e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8af1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b8af6:
    // 004b8af6  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004b8afc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8afd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8afe  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b8b01(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004b8b01  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004b8b03  698b4b00738b4b007d8b   -imul ecx, dword ptr [ebx - 0x748cffb5], 0x8b7d004b
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-1955397557) /* -0x748cffb5 */))) * x86::sreg64(x86::sreg32(2340225099 /*0x8b7d004b*/)));
    // 004b8b0d  4b                     -dec ebx
    (cpu.ebx)--;
    // 004b8b0e  009b8b4b0087           -add byte ptr [ebx - 0x78ffb475], bl
    (app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-2030023797) /* -0x78ffb475 */)) += x86::reg8(x86::sreg8(cpu.bl));
    // 004b8b14  8b4b00                 -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b8b17  4f                     -dec edi
    (cpu.edi)--;
    // 004b8b18  8b4b00                 -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b8b1b  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b8b1c  8b4b00                 -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b8b1f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8b20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8b21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b8b22  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b8b25  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b8b29  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b8b2d  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 004b8b31  0f85a0010000           -jne 0x4b8cd7
    if (!cpu.flags.zf)
    {
        goto L_0x004b8cd7;
    }
    // 004b8b37  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b8b39  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 004b8b3e  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8b41  0f8723010000           -ja 0x4b8c6a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b8c6a;
    }
    // 004b8b47  2eff2485038b4b00       -jmp dword ptr cs:[eax*4 + 0x4b8b03]
    cpu.ip = app->getMemory<x86::reg32>(4950787 + cpu.eax * 4); goto dynamic_jump;
  case 0x004b8b4f:
    // 004b8b4f  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 004b8b53  740a                   -je 0x4b8b5f
    if (cpu.flags.zf)
    {
        goto L_0x004b8b5f;
    }
    // 004b8b55  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 004b8b5a  e9ce000000             -jmp 0x4b8c2d
    goto L_0x004b8c2d;
L_0x004b8b5f:
    // 004b8b5f  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 004b8b64  e9c4000000             -jmp 0x4b8c2d
    goto L_0x004b8c2d;
  case 0x004b8b69:
    // 004b8b69  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 004b8b6e  e9ba000000             -jmp 0x4b8c2d
    goto L_0x004b8c2d;
  case 0x004b8b73:
L_0x004b8b73:
    // 004b8b73  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 004b8b78  e9b0000000             -jmp 0x4b8c2d
    goto L_0x004b8c2d;
  case 0x004b8b7d:
    // 004b8b7d  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 004b8b82  e9a6000000             -jmp 0x4b8c2d
    goto L_0x004b8c2d;
  case 0x004b8b87:
    // 004b8b87  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 004b8b8c  e99c000000             -jmp 0x4b8c2d
    goto L_0x004b8c2d;
  case 0x004b8b91:
    // 004b8b91  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 004b8b96  e992000000             -jmp 0x4b8c2d
    goto L_0x004b8c2d;
  case 0x004b8b9b:
    // 004b8b9b  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004b8b9e  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004b8ba1  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 004b8ba6  6681fad9fa             +cmp dx, 0xfad9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(64217 /*0xfad9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b8bab  750a                   -jne 0x4b8bb7
    if (!cpu.flags.zf)
    {
        goto L_0x004b8bb7;
    }
    // 004b8bad  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 004b8bb2  e976000000             -jmp 0x4b8c2d
    goto L_0x004b8c2d;
L_0x004b8bb7:
    // 004b8bb7  6681fad9f1             +cmp dx, 0xf1d9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61913 /*0xf1d9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b8bbc  750a                   -jne 0x4b8bc8
    if (!cpu.flags.zf)
    {
        goto L_0x004b8bc8;
    }
    // 004b8bbe  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 004b8bc3  e965000000             -jmp 0x4b8c2d
    goto L_0x004b8c2d;
L_0x004b8bc8:
    // 004b8bc8  7507                   -jne 0x4b8bd1
    if (!cpu.flags.zf)
    {
        goto L_0x004b8bd1;
    }
    // 004b8bca  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 004b8bcf  eb5c                   -jmp 0x4b8c2d
    goto L_0x004b8c2d;
L_0x004b8bd1:
    // 004b8bd1  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b8bd3  80fedb                 +cmp dh, 0xdb
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(219 /*0xdb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b8bd6  7405                   -je 0x4b8bdd
    if (cpu.flags.zf)
    {
        goto L_0x004b8bdd;
    }
    // 004b8bd8  80fedf                 +cmp dh, 0xdf
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(223 /*0xdf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b8bdb  7510                   -jne 0x4b8bed
    if (!cpu.flags.zf)
    {
        goto L_0x004b8bed;
    }
L_0x004b8bdd:
    // 004b8bdd  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b8be0  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b8be3  80fa10                 +cmp dl, 0x10
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
    // 004b8be6  7505                   -jne 0x4b8bed
    if (!cpu.flags.zf)
    {
        goto L_0x004b8bed;
    }
    // 004b8be8  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x004b8bed:
    // 004b8bed  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 004b8bf0  7536                   -jne 0x4b8c28
    if (!cpu.flags.zf)
    {
        goto L_0x004b8c28;
    }
    // 004b8bf2  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b8bf5  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b8bf7  3c30                   +cmp al, 0x30
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
    // 004b8bf9  752d                   -jne 0x4b8c28
    if (!cpu.flags.zf)
    {
        goto L_0x004b8c28;
    }
    // 004b8bfb  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 004b8bfe  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b8c03  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b8c06  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b8c08  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 004b8c0c  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 004b8c0f  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 004b8c12  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b8c18  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b8c1a  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004b8c1c  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b8c1f  83fa01                 +cmp edx, 1
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
    // 004b8c22  0f844bffffff           -je 0x4b8b73
    if (cpu.flags.zf)
    {
        goto L_0x004b8b73;
    }
L_0x004b8c28:
    // 004b8c28  83fbff                 +cmp ebx, -1
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
    // 004b8c2b  743d                   -je 0x4b8c6a
    if (cpu.flags.zf)
    {
        goto L_0x004b8c6a;
    }
L_0x004b8c2d:
    // 004b8c2d  c605cca35b0001         -mov byte ptr [0x5ba3cc], 1
    app->getMemory<x86::reg8>(x86::reg32(6005708) /* 0x5ba3cc */) = 1 /*0x1*/;
    // 004b8c34  e8bc650000             -call 0x4bf1f5
    cpu.esp -= 4;
    sub_4bf1f5(app, cpu);
    if (cpu.terminate) return;
    // 004b8c39  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8c3b  e882670000             -call 0x4bf3c2
    cpu.esp -= 4;
    sub_4bf3c2(app, cpu);
    if (cpu.terminate) return;
    // 004b8c40  83f8ff                 +cmp eax, -1
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
    // 004b8c43  0f846f000000           -je 0x4b8cb8
    if (cpu.flags.zf)
    {
        goto L_0x004b8cb8;
    }
    // 004b8c49  803dcca35b0000         +cmp byte ptr [0x5ba3cc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6005708) /* 0x5ba3cc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b8c50  0f8462000000           -je 0x4b8cb8
    if (cpu.flags.zf)
    {
        goto L_0x004b8cb8;
    }
    // 004b8c56  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 004b8c5a  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004b8c5c  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004b8c5f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b8c61  66895f20               -mov word ptr [edi + 0x20], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 004b8c65  e972000000             -jmp 0x4b8cdc
    goto L_0x004b8cdc;
L_0x004b8c6a:
    // 004b8c6a  833d24074e0000         +cmp dword ptr [0x4e0724], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5113636) /* 0x4e0724 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8c71  7445                   -je 0x4b8cb8
    if (cpu.flags.zf)
    {
        goto L_0x004b8cb8;
    }
    // 004b8c73  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004b8c78:
    // 004b8c78  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8c7a  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b8c7c  ff1520074e00           -call dword ptr [0x4e0720]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113632) /* 0x4e0720 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8c82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8c84  742c                   -je 0x4b8cb2
    if (cpu.flags.zf)
    {
        goto L_0x004b8cb2;
    }
    // 004b8c86  83f801                 +cmp eax, 1
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
    // 004b8c89  742d                   -je 0x4b8cb8
    if (cpu.flags.zf)
    {
        goto L_0x004b8cb8;
    }
    // 004b8c8b  83f802                 +cmp eax, 2
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
    // 004b8c8e  7428                   -je 0x4b8cb8
    if (cpu.flags.zf)
    {
        goto L_0x004b8cb8;
    }
    // 004b8c90  83f803                 +cmp eax, 3
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
    // 004b8c93  7423                   -je 0x4b8cb8
    if (cpu.flags.zf)
    {
        goto L_0x004b8cb8;
    }
    // 004b8c95  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004b8c97  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8c99  8815cca35b00           -mov byte ptr [0x5ba3cc], dl
    app->getMemory<x86::reg8>(x86::reg32(6005708) /* 0x5ba3cc */) = cpu.dl;
    // 004b8c9f  ff1524074e00           -call dword ptr [0x4e0724]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113636) /* 0x4e0724 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8ca5  803dcca35b0000         +cmp byte ptr [0x5ba3cc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6005708) /* 0x5ba3cc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b8cac  7404                   -je 0x4b8cb2
    if (cpu.flags.zf)
    {
        goto L_0x004b8cb2;
    }
    // 004b8cae  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b8cb0  eb2a                   -jmp 0x4b8cdc
    goto L_0x004b8cdc;
L_0x004b8cb2:
    // 004b8cb2  43                     -inc ebx
    (cpu.ebx)++;
    // 004b8cb3  83fb0c                 +cmp ebx, 0xc
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
    // 004b8cb6  7ec0                   -jle 0x4b8c78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b8c78;
    }
L_0x004b8cb8:
    // 004b8cb8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b8cba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8cbb  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b8cbf  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004b8cc3  2eff15bc654c00         -call dword ptr cs:[0x4c65bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006780) /* 0x4c65bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8cca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8ccc  7409                   -je 0x4b8cd7
    if (cpu.flags.zf)
    {
        goto L_0x004b8cd7;
    }
    // 004b8cce  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004b8cd0  2eff1584644c00         -call dword ptr cs:[0x4c6484]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006468) /* 0x4c6484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b8cd7:
    // 004b8cd7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b8cdc:
    // 004b8cdc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b8cdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8ce0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8ce1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8ce2  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4b8ce3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8ce3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8ce4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8ce5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b8ce7  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8ced  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004b8cf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b8cf2  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 004b8cf5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b8cf7  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8cfd  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b8d00  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b8d02  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8d08  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b8d0b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b8d0d  c740041f8b4b00         -mov dword ptr [eax + 4], 0x4b8b1f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 4950815 /*0x4b8b1f*/;
    // 004b8d14  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8d1a  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b8d1d  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 004b8d20  684a894b00             -push 0x4b894a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4950346 /*0x4b894a*/;
    cpu.esp -= 4;
    // 004b8d25  2eff15a0654c00         -call dword ptr cs:[0x4c65a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006752) /* 0x4c65a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8d2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8d2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8d2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8d2f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8d2f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8d30  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8d36  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b8d39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8d3b  7407                   -je 0x4b8d44
    if (cpu.flags.zf)
    {
        goto L_0x004b8d44;
    }
    // 004b8d3d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b8d3f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b8d41  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x004b8d44:
    // 004b8d44  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8d4a  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 004b8d51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8d52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8d53(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8d53  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b8d58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8d59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8d5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8d5b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b8d5d  ff156ced4d00           -call dword ptr [0x4ded6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107052) /* 0x4ded6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8d63  8b15a4675b00           -mov edx, dword ptr [0x5b67a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */);
    // 004b8d69  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b8d6b  eb16                   -jmp 0x4b8d83
    goto L_0x004b8d83;
L_0x004b8d6d:
    // 004b8d6d  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b8d70  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 004b8d73  740c                   -je 0x4b8d81
    if (cpu.flags.zf)
    {
        goto L_0x004b8d81;
    }
    // 004b8d75  43                     -inc ebx
    (cpu.ebx)++;
    // 004b8d76  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004b8d7a  7405                   -je 0x4b8d81
    if (cpu.flags.zf)
    {
        goto L_0x004b8d81;
    }
    // 004b8d7c  e80e25ffff             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
L_0x004b8d81:
    // 004b8d81  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004b8d83:
    // 004b8d83  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b8d85  75e6                   -jne 0x4b8d6d
    if (!cpu.flags.zf)
    {
        goto L_0x004b8d6d;
    }
    // 004b8d87  ff1570ed4d00           -call dword ptr [0x4ded70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107056) /* 0x4ded70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8d8d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8d8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8d90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8d91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8d92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8d58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b8d58;
    // 004b8d53  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_entry_0x004b8d58:
    // 004b8d58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8d59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8d5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8d5b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b8d5d  ff156ced4d00           -call dword ptr [0x4ded6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107052) /* 0x4ded6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8d63  8b15a4675b00           -mov edx, dword ptr [0x5b67a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5990308) /* 0x5b67a4 */);
    // 004b8d69  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b8d6b  eb16                   -jmp 0x4b8d83
    goto L_0x004b8d83;
L_0x004b8d6d:
    // 004b8d6d  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b8d70  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 004b8d73  740c                   -je 0x4b8d81
    if (cpu.flags.zf)
    {
        goto L_0x004b8d81;
    }
    // 004b8d75  43                     -inc ebx
    (cpu.ebx)++;
    // 004b8d76  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004b8d7a  7405                   -je 0x4b8d81
    if (cpu.flags.zf)
    {
        goto L_0x004b8d81;
    }
    // 004b8d7c  e80e25ffff             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
L_0x004b8d81:
    // 004b8d81  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004b8d83:
    // 004b8d83  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b8d85  75e6                   -jne 0x4b8d6d
    if (!cpu.flags.zf)
    {
        goto L_0x004b8d6d;
    }
    // 004b8d87  ff1570ed4d00           -call dword ptr [0x4ded70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107056) /* 0x4ded70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8d8d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8d8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8d90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8d91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8d92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8d93(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8d93  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8d94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8d95  8b1df4da4d00           -mov ebx, dword ptr [0x4ddaf4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102324) /* 0x4ddaf4 */);
    // 004b8d9b  e8d5680000             -call 0x4bf675
    cpu.esp -= 4;
    sub_4bf675(app, cpu);
    if (cpu.terminate) return;
    // 004b8da0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b8da2  83f8ff                 +cmp eax, -1
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
    // 004b8da5  7409                   -je 0x4b8db0
    if (cpu.flags.zf)
    {
        goto L_0x004b8db0;
    }
    // 004b8da7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b8da9  7505                   -jne 0x4b8db0
    if (!cpu.flags.zf)
    {
        goto L_0x004b8db0;
    }
    // 004b8dab  e841690000             -call 0x4bf6f1
    cpu.esp -= 4;
    sub_4bf6f1(app, cpu);
    if (cpu.terminate) return;
L_0x004b8db0:
    // 004b8db0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b8db2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8db3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8db4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8db5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8db5  8a80d5a35b00           -mov al, byte ptr [eax + 0x5ba3d5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004b8dbb  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b8dbd  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b8dc2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8dc3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8dc3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b8dc5  e98b690000             -jmp 0x4bf755
    return sub_4bf755(app, cpu);
}

/* align: skip  */
void Application::sub_4b8dca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8dca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8dcb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8dcc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b8dcd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b8dce  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b8dd0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b8dd3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b8dd5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b8dd7  7507                   -jne 0x4b8de0
    if (!cpu.flags.zf)
    {
        goto L_0x004b8de0;
    }
L_0x004b8dd9:
    // 004b8dd9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b8ddb  e977000000             -jmp 0x4b8e57
    goto L_0x004b8e57;
L_0x004b8de0:
    // 004b8de0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b8de2  0f866a000000           -jbe 0x4b8e52
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8e52;
    }
    // 004b8de8  803a00                 +cmp byte ptr [edx], 0
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
    // 004b8deb  750b                   -jne 0x4b8df8
    if (!cpu.flags.zf)
    {
        goto L_0x004b8df8;
    }
    // 004b8ded  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b8def  74e8                   -je 0x4b8dd9
    if (cpu.flags.zf)
    {
        goto L_0x004b8dd9;
    }
    // 004b8df1  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 004b8df6  ebe1                   -jmp 0x4b8dd9
    goto L_0x004b8dd9;
L_0x004b8df8:
    // 004b8df8  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8dff  7419                   -je 0x4b8e1a
    if (cpu.flags.zf)
    {
        goto L_0x004b8e1a;
    }
    // 004b8e01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b8e03  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b8e05  8a80d5a35b00           -mov al, byte ptr [eax + 0x5ba3d5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004b8e0b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b8e0d  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b8e12  7406                   -je 0x4b8e1a
    if (cpu.flags.zf)
    {
        goto L_0x004b8e1a;
    }
    // 004b8e14  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 004b8e18  7438                   -je 0x4b8e52
    if (cpu.flags.zf)
    {
        goto L_0x004b8e52;
    }
L_0x004b8e1a:
    // 004b8e1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b8e1c  e8806a0000             -call 0x4bf8a1
    cpu.esp -= 4;
    sub_4bf8a1(app, cpu);
    if (cpu.terminate) return;
    // 004b8e21  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b8e23  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b8e26  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b8e28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8e29  39c3                   +cmp ebx, eax
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
    // 004b8e2b  7302                   -jae 0x4b8e2f
    if (!cpu.flags.cf)
    {
        goto L_0x004b8e2f;
    }
    // 004b8e2d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004b8e2f:
    // 004b8e2f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8e30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8e31  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004b8e33  a16c0a4e00             -mov eax, dword ptr [0x4e0a6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114476) /* 0x4e0a6c */);
    // 004b8e38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8e39  2eff1550654c00         -call dword ptr cs:[0x4c6550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006672) /* 0x4c6550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8e40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8e42  740e                   -je 0x4b8e52
    if (cpu.flags.zf)
    {
        goto L_0x004b8e52;
    }
    // 004b8e44  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b8e46  7406                   -je 0x4b8e4e
    if (cpu.flags.zf)
    {
        goto L_0x004b8e4e;
    }
    // 004b8e48  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b8e4b  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004b8e4e:
    // 004b8e4e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b8e50  eb05                   -jmp 0x4b8e57
    goto L_0x004b8e57;
L_0x004b8e52:
    // 004b8e52  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004b8e57:
    // 004b8e57  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b8e59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8e5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8e5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8e5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8e5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8e5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8e5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8e5f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b8e64  b8181d4d00             -mov eax, 0x4d1d18
    cpu.eax = 5053720 /*0x4d1d18*/;
    // 004b8e69  e893290000             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
    // 004b8e6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8e6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8e70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8e71  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 004b8e77  743f                   -je 0x4b8eb8
    if (cpu.flags.zf)
    {
        goto L_0x004b8eb8;
    }
    // 004b8e79  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b8e7b  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b8e7d  11d2                   +adc edx, edx
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
    // 004b8e7f  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
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
    // 004b8e81  0500000020             +add eax, 0x20000000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(536870912 /*0x20000000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b8e86  83d200                 +adc edx, 0
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
    // 004b8e89  7424                   -je 0x4b8eaf
    if (cpu.flags.zf)
    {
        goto L_0x004b8eaf;
    }
    // 004b8e8b  81fa0000e08f           +cmp edx, 0x8fe00000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2413821952 /*0x8fe00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8e91  731c                   -jae 0x4b8eaf
    if (!cpu.flags.cf)
    {
        goto L_0x004b8eaf;
    }
    // 004b8e93  81fa00002070           +cmp edx, 0x70200000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1881145344 /*0x70200000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b8e99  721d                   -jb 0x4b8eb8
    if (cpu.flags.cf)
    {
        goto L_0x004b8eb8;
    }
    // 004b8e9b  81ea00000070           -sub edx, 0x70000000
    (cpu.edx) -= x86::reg32(x86::sreg32(1879048192 /*0x70000000*/));
    // 004b8ea1  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b8ea3  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b8ea5  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b8ea7  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b8ea9  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b8eab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b8ead  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8eae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8eaf:
    // 004b8eaf  b80000807f             -mov eax, 0x7f800000
    cpu.eax = 2139095040 /*0x7f800000*/;
    // 004b8eb4  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b8eb6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8eb7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8eb8:
    // 004b8eb8  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b8eba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8ebb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8ebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8ebc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b8ebe  7507                   -jne 0x4b8ec7
    if (!cpu.flags.zf)
    {
        goto L_0x004b8ec7;
    }
    // 004b8ec0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b8ec2  7503                   -jne 0x4b8ec7
    if (!cpu.flags.zf)
    {
        goto L_0x004b8ec7;
    }
    // 004b8ec4  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004b8ec6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8ec7:
    // 004b8ec7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8ec8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8ec9  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004b8ecb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b8ecd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8ece  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004b8ed0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b8ed2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8ed3  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004b8ed5  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b8ed7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8ed8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8ed8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8ed9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8eda  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b8edc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8edd  2eff15e0644c00         -call dword ptr cs:[0x4c64e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006560) /* 0x4c64e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8ee4  83f8ff                 +cmp eax, -1
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
    // 004b8ee7  7508                   -jne 0x4b8ef1
    if (!cpu.flags.zf)
    {
        goto L_0x004b8ef1;
    }
    // 004b8ee9  e8c4d6feff             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 004b8eee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8eef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8ef0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8ef1:
    // 004b8ef1  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004b8ef4  7411                   -je 0x4b8f07
    if (cpu.flags.zf)
    {
        goto L_0x004b8f07;
    }
    // 004b8ef6  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004b8ef8  740d                   -je 0x4b8f07
    if (cpu.flags.zf)
    {
        goto L_0x004b8f07;
    }
    // 004b8efa  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b8eff  e85dd6feff             -call 0x4a6561
    cpu.esp -= 4;
    sub_4a6561(app, cpu);
    if (cpu.terminate) return;
    // 004b8f04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8f05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8f06  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8f07:
    // 004b8f07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b8f09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8f0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8f0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8f0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8f0c  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8f12  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b8f15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8f16(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8f16  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8f1c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b8f1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8f20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8f21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8f22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8f23  2eff154c654c00         -call dword ptr cs:[0x4c654c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006668) /* 0x4c654c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8f2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8f2c  7507                   -jne 0x4b8f35
    if (!cpu.flags.zf)
    {
        goto L_0x004b8f35;
    }
    // 004b8f2e  e87fd6feff             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 004b8f33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8f34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8f35:
    // 004b8f35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b8f37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8f38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8f39(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8f39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8f3a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8f3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b8f3c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b8f3f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b8f41  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b8f43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8f45  7522                   -jne 0x4b8f69
    if (!cpu.flags.zf)
    {
        goto L_0x004b8f69;
    }
    // 004b8f47  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004b8f4c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b8f4e  e870d6feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b8f53  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b8f55  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8f57  750e                   -jne 0x4b8f67
    if (!cpu.flags.zf)
    {
        goto L_0x004b8f67;
    }
    // 004b8f59  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
L_0x004b8f5e:
    // 004b8f5e  e84dd7feff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
L_0x004b8f63:
    // 004b8f63  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b8f65  eb5c                   -jmp 0x4b8fc3
    goto L_0x004b8fc3;
L_0x004b8f67:
    // 004b8f67  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004b8f69:
    // 004b8f69  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b8f6b  7405                   -je 0x4b8f72
    if (cpu.flags.zf)
    {
        goto L_0x004b8f72;
    }
    // 004b8f6d  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b8f70  750b                   -jne 0x4b8f7d
    if (!cpu.flags.zf)
    {
        goto L_0x004b8f7d;
    }
L_0x004b8f72:
    // 004b8f72  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b8f74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b8f76  e8cadafcff             -call 0x486a45
    cpu.esp -= 4;
    sub_486a45(app, cpu);
    if (cpu.terminate) return;
    // 004b8f7b  eb46                   -jmp 0x4b8fc3
    goto L_0x004b8fc3;
L_0x004b8f7d:
    // 004b8f7d  ba3c1d4d00             -mov edx, 0x4d1d3c
    cpu.edx = 5053756 /*0x4d1d3c*/;
    // 004b8f82  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b8f84  e8aa61feff             -call 0x49f133
    cpu.esp -= 4;
    sub_49f133(app, cpu);
    if (cpu.terminate) return;
    // 004b8f89  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8f8b  751c                   -jne 0x4b8fa9
    if (!cpu.flags.zf)
    {
        goto L_0x004b8fa9;
    }
    // 004b8f8d  83fb04                 +cmp ebx, 4
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
    // 004b8f90  730e                   -jae 0x4b8fa0
    if (!cpu.flags.cf)
    {
        goto L_0x004b8fa0;
    }
    // 004b8f92  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b8f94  e85f25ffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004b8f99  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004b8f9e  ebbe                   -jmp 0x4b8f5e
    goto L_0x004b8f5e;
L_0x004b8fa0:
    // 004b8fa0  a13c1d4d00             -mov eax, dword ptr [0x4d1d3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5053756) /* 0x4d1d3c */);
    // 004b8fa5  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b8fa7  eb18                   -jmp 0x4b8fc1
    goto L_0x004b8fc1;
L_0x004b8fa9:
    // 004b8fa9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b8fab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b8fac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8fad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8fae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8faf  2eff15ec644c00         -call dword ptr cs:[0x4c64ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006572) /* 0x4c64ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8fb6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8fb8  7507                   -jne 0x4b8fc1
    if (!cpu.flags.zf)
    {
        goto L_0x004b8fc1;
    }
    // 004b8fba  e8f3d5feff             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 004b8fbf  eba2                   -jmp 0x4b8f63
    goto L_0x004b8f63;
L_0x004b8fc1:
    // 004b8fc1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004b8fc3:
    // 004b8fc3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b8fc6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8fc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8fc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8fc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b8fca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b8fca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b8fcb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b8fcc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b8fcd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b8fce  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b8fd0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b8fd2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b8fd4  7c08                   -jl 0x4b8fde
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b8fde;
    }
    // 004b8fd6  3b05bc064e00           +cmp eax, dword ptr [0x4e06bc]
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
    // 004b8fdc  7614                   -jbe 0x4b8ff2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b8ff2;
    }
L_0x004b8fde:
    // 004b8fde  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b8fe3  e8c8d6feff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004b8fe8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b8fed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8fee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8fef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8ff0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b8ff1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b8ff2:
    // 004b8ff2  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b8ff8  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b8ffd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b8fff  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004b9002  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b9003  2eff1598644c00         -call dword ptr cs:[0x4c6498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006488) /* 0x4c6498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b900a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b900c  750a                   -jne 0x4b9018
    if (!cpu.flags.zf)
    {
        goto L_0x004b9018;
    }
    // 004b900e  e89fd5feff             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 004b9013  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x004b9018:
    // 004b9018  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b901a  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b9020  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b9022  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9023  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9024  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9025  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9026  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9027(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9027  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b9028  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b902a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b902b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b902c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b902d  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b9030  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b9032  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b9034  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9036  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 004b9039  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004b903c  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004b903f  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b9042  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 004b9044  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9049  83f847                 +cmp eax, 0x47
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b904c  7523                   -jne 0x4b9071
    if (!cpu.flags.zf)
    {
        goto L_0x004b9071;
    }
    // 004b904e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b9050  7505                   -jne 0x4b9057
    if (!cpu.flags.zf)
    {
        goto L_0x004b9057;
    }
    // 004b9052  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004b9057:
    // 004b9057  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 004b905e  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b9061  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b9066  83ef02                 +sub edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b9069  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 004b906c  897dc0                 -mov dword ptr [ebp - 0x40], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 004b906f  eb1f                   -jmp 0x4b9090
    goto L_0x004b9090;
L_0x004b9071:
    // 004b9071  83f845                 +cmp eax, 0x45
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b9074  750d                   -jne 0x4b9083
    if (!cpu.flags.zf)
    {
        goto L_0x004b9083;
    }
    // 004b9076  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b907b  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 004b907e  897db8                 -mov dword ptr [ebp - 0x48], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 004b9081  eb0d                   -jmp 0x4b9090
    goto L_0x004b9090;
L_0x004b9083:
    // 004b9083  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004b9088  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b908a  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 004b908d  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x004b9090:
    // 004b9090  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 004b9094  7404                   -je 0x4b909a
    if (cpu.flags.zf)
    {
        goto L_0x004b909a;
    }
    // 004b9096  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x004b909a:
    // 004b909a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b909c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b909f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b90a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b90a3  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004b90a6  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004b90a9  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b90ac  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b90af  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004b90b2  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b90b5  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 004b90b7  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b90b9  83fbff                 +cmp ebx, -1
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
    // 004b90bc  7505                   -jne 0x4b90c3
    if (!cpu.flags.zf)
    {
        goto L_0x004b90c3;
    }
    // 004b90be  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x004b90c3:
    // 004b90c3  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b90c6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b90c8  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 004b90cb  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 004b90ce  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b90d1  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b90d4  e82b690000             -call 0x4bfa04
    cpu.esp -= 4;
    sub_4bfa04(app, cpu);
    if (cpu.terminate) return;
    // 004b90d9  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004b90dc  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b90df  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b90e2  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004b90e5  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004b90e8  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004b90eb  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b90ee  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004b90f1  837dc800               +cmp dword ptr [ebp - 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b90f5  7d0f                   -jge 0x4b9106
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b9106;
    }
    // 004b90f7  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b90fa  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b90fd  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b9100  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 004b9104  eb29                   -jmp 0x4b912f
    goto L_0x004b912f;
L_0x004b9106:
    // 004b9106  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b9109  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004b910c  740f                   -je 0x4b911d
    if (cpu.flags.zf)
    {
        goto L_0x004b911d;
    }
    // 004b910e  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b9111  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b9114  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b9117  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 004b911b  eb12                   -jmp 0x4b912f
    goto L_0x004b912f;
L_0x004b911d:
    // 004b911d  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004b9120  740d                   -je 0x4b912f
    if (cpu.flags.zf)
    {
        goto L_0x004b912f;
    }
    // 004b9122  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b9125  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b9128  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b912b  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x004b912f:
    // 004b912f  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b9131  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b9133  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b9136  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9137  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9138  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9139  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b913a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b913b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b913b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b913c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b913e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b9140  e809740000             -call 0x4c054e
    cpu.esp -= 4;
    sub_4c054e(app, cpu);
    if (cpu.terminate) return;
    // 004b9145  dd1b                   -fstp qword ptr [ebx]
    app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b9147  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9148  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b914c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b914c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b914d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b914d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b914f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9152  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9158  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b915a  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b915d  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9160  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9166  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9168  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9169(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9169  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b916b  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b916d  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9173  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9176  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b917b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b917d  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9180  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9183  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9189  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b918b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b918c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b918c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b918e  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9190  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9196  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9199  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b919e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b91a0  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b91a3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b91a5  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b91a8  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b91ae  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b91b1  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b91b7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b91b9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b91bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b91bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b91bc  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b91be  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b91c3  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b91c6  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b91c8  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b91ce  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b91d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b91d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b91d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b91d3  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b91d6  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b91dc  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b91df  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b91e4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b91e6  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b91e9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b91eb  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b91ed  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b91f3  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b91f6  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b91fc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b91fe  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9201(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9201  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9204  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9209  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b920c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b920e  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9210  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9216  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b9219  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b921f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9221  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9223  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9224  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9227  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b922c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b922f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9231  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9234  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b923a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b923c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b923e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b923f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b923f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9241  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9244  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b924a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b924c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b924f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9252  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9258  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b925a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b925b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b925b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b925d  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b925f  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9265  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9268  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b926d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b926f  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9272  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9275  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b927b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b927d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9280  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9283  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9289  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b928b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b928c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b928c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b928e  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9290  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9296  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9299  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b929e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b92a0  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b92a3  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b92a6  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b92ac  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b92ae  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b92b1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b92b4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b92ba  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b92bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b92bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b92bd  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b92bf  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b92c4  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b92c7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b92c9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b92cc  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b92d2  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b92d5  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b92db  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b92dd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b92df  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b92e2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b92e5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b92eb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b92ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b92ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b92ee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b92f0  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b92f3  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b92f9  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b92fc  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9301  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9303  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9306  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9308  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b930e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9310  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9314  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9317  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b931d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b931f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9320  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9323  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9328  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b932b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b932d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b932f  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9335  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9338  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b933e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9340  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9342  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9346  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9349  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b934f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9351  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9352(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9352  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9355  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b935a  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b935d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b935f  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9361  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9367  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b936a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9370  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9372  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9374  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9378  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b937b  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9381  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9383  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
